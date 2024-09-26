// @lint-ignore-every LICENSELINT
// Copyright 1998-2020 Epic Games, Inc. All Rights Reserved.

#include "OculusXRPassthroughLayerComponent.h"

#include "Engine/StaticMesh.h"
#include "Engine/GameEngine.h"
#include "Components/StaticMeshComponent.h"
#include "ProceduralMeshComponent.h"
#include "OculusXRHMD.h"
#include "OculusXRPassthroughLayerShapes.h"
#include "OculusXRPersistentPassthroughInstance.h"
#include "OculusXRPassthroughSubsystem.h"
#include "Curves/CurveLinearColor.h"
#include "StaticMeshResources.h"

DEFINE_LOG_CATEGORY(LogOculusPassthrough);

void UOculusXRStereoLayerShapeReconstructed::ApplyShape(IStereoLayers::FLayerDesc& LayerDesc)
{
	const FEdgeStyleParameters EdgeStyleParameters(
		bEnableEdgeColor,
		bEnableColorMap,
		TextureOpacityFactor,
		Brightness,
		Contrast,
		Posterize,
		Saturation,
		EdgeColor,
		ColorScale,
		ColorOffset,
		ColorMapType,
		GetColorArray(bUseColorMapCurve, ColorMapCurve),
		GenerateColorLutDescription(LutWeight, ColorLUTSource, ColorLUTTarget));
	LayerDesc.SetShape<FReconstructedLayer>(EdgeStyleParameters, LayerOrder);
}

void UOculusXRStereoLayerShapeUserDefined::ApplyShape(IStereoLayers::FLayerDesc& LayerDesc)
{
	// If there is no user geometry, set the layer hidden to avoid unnecessary cost
	if (UserGeometryList.IsEmpty())
		LayerDesc.Flags |= IStereoLayers::LAYER_FLAG_HIDDEN;

	const FEdgeStyleParameters EdgeStyleParameters(
		bEnableEdgeColor,
		bEnableColorMap,
		TextureOpacityFactor,
		Brightness,
		Contrast,
		Posterize,
		Saturation,
		EdgeColor,
		ColorScale,
		ColorOffset,
		ColorMapType,
		GetColorArray(bUseColorMapCurve, ColorMapCurve),
		GenerateColorLutDescription(LutWeight, ColorLUTSource, ColorLUTTarget));
	LayerDesc.SetShape<FUserDefinedLayer>(UserGeometryList, EdgeStyleParameters, LayerOrder);
}

void UOculusXRStereoLayerShapeUserDefined::AddGeometry(const FString& MeshName, OculusXRHMD::FOculusPassthroughMeshRef PassthroughMesh, FTransform Transform, bool bUpdateTransform)
{
	FUserDefinedGeometryDesc UserDefinedGeometryDesc(
		MeshName,
		PassthroughMesh,
		Transform,
		bUpdateTransform);

	UserGeometryList.Add(UserDefinedGeometryDesc);
}

void UOculusXRStereoLayerShapeUserDefined::RemoveGeometry(const FString& MeshName)
{
	UserGeometryList.RemoveAll([MeshName](const FUserDefinedGeometryDesc& Desc) {
		return Desc.MeshName == MeshName;
	});
}

UOculusXRPassthroughLayerComponent::UOculusXRPassthroughLayerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UOculusXRPassthroughLayerComponent::DestroyComponent(bool bPromoteChildren)
{
	Super::DestroyComponent(bPromoteChildren);

	UOculusXRPassthroughSubsystem* ptSubsystem = UOculusXRPassthroughSubsystem::GetPassthroughSubsystem(GetWorld());
	if (ptSubsystem != nullptr)
	{
		ptSubsystem->OnAnyLayerResumed.RemoveDynamic(this, &UOculusXRPassthroughLayerComponent::OnAnyLayerResumedEvent);
	}

#ifdef WITH_OCULUS_BRANCH
	IStereoLayers* StereoLayers;
	if (LayerId && GEngine->StereoRenderingDevice.IsValid() && (StereoLayers = GEngine->StereoRenderingDevice->GetStereoLayers()) != nullptr)
	{
		StereoLayers->DestroyLayer(LayerId);
		LayerId = 0;
	}
#endif
}

void UOculusXRPassthroughLayerComponent::OnRegister()
{
	Super::OnRegister();

	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerComponent::BeginPlay()
{
	UOculusXRPassthroughSubsystem* ptSubsystem = UOculusXRPassthroughSubsystem::GetPassthroughSubsystem(GetWorld());
	if (ptSubsystem != nullptr)
	{
		ptSubsystem->OnAnyLayerResumed.AddDynamic(this, &UOculusXRPassthroughLayerComponent::OnAnyLayerResumedEvent);
	}

	Super::BeginPlay();
}

void UOculusXRPassthroughLayerComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if (Texture == nullptr && !LayerRequiresTexture())
	{
		// UStereoLayerComponent hides components without textures
		Texture = GEngine->DefaultTexture;
	}

	UpdatePassthroughObjects();
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UOculusXRPassthroughLayerComponent::UpdatePassthroughObjects()
{
	UOculusXRStereoLayerShapeUserDefined* UserShape = Cast<UOculusXRStereoLayerShapeUserDefined>(Shape);
	if (UserShape)
	{
		bool bDirty = false;
		for (FUserDefinedGeometryDesc& Entry : UserShape->GetUserGeometryList())
		{
			if (Entry.bUpdateTransform)
			{
				const UMeshComponent** MeshComponent = PassthroughComponentMap.Find(Entry.MeshName);
				if (MeshComponent)
				{
					Entry.Transform = (*MeshComponent)->GetComponentTransform();
					bDirty = true;
				}
			}
		}
		if (bDirty)
		{
			MarkStereoLayerDirty();
		}
	}
}

OculusXRHMD::FOculusPassthroughMeshRef UOculusXRPassthroughLayerComponent::CreatePassthroughMesh(UProceduralMeshComponent* ProceduralMeshComponent)
{
	if (!ProceduralMeshComponent)
	{
		UE_LOG(LogOculusPassthrough, Error, TEXT("Passthrough Procedural Mesh is nullptr"));
		return nullptr;
	}

	TArray<int32> Triangles;
	TArray<FVector> Vertices;
	int32 NumSections = ProceduralMeshComponent->GetNumSections();
	int VertexOffset = 0; // Each section start with vertex IDs of 0, in order to create a single mesh from all sections we need to offset those IDs by the amount of previous vertices
	for (int32 s = 0; s < NumSections; ++s)
	{
		FProcMeshSection* ProcMeshSection = ProceduralMeshComponent->GetProcMeshSection(s);
		for (int32 i = 0; i < ProcMeshSection->ProcIndexBuffer.Num(); ++i)
		{
			Triangles.Add(VertexOffset + ProcMeshSection->ProcIndexBuffer[i]);
		}

		for (int32 i = 0; i < ProcMeshSection->ProcVertexBuffer.Num(); ++i)
		{
			Vertices.Add(ProcMeshSection->ProcVertexBuffer[i].Position);
		}

		VertexOffset += ProcMeshSection->ProcVertexBuffer.Num();
	}

	OculusXRHMD::FOculusPassthroughMeshRef PassthroughMesh = new OculusXRHMD::FOculusPassthroughMesh(Vertices, Triangles);
	return PassthroughMesh;
}

OculusXRHMD::FOculusPassthroughMeshRef UOculusXRPassthroughLayerComponent::CreatePassthroughMesh(UStaticMeshComponent* StaticMeshComponent)
{
	if (!StaticMeshComponent)
	{
		UE_LOG(LogOculusPassthrough, Error, TEXT("Passthrough Static Mesh is nullptr"));
		return nullptr;
	}

	UStaticMesh* Mesh = StaticMeshComponent->GetStaticMesh();

	if (!Mesh || !Mesh->GetRenderData())
	{
		UE_LOG(LogOculusPassthrough, Error, TEXT("Passthrough Static Mesh has no Renderdata"));
		return nullptr;
	}

	if (Mesh->GetNumLODs() == 0)
	{
		UE_LOG(LogOculusPassthrough, Error, TEXT("Passthrough Static Mesh has no LODs"));
		return nullptr;
	}

	if (!Mesh->bAllowCPUAccess)
	{
		UE_LOG(LogOculusPassthrough, Error, TEXT("Passthrough Static Mesh Requires CPU Access"));
		return nullptr;
	}

	const int32 LODIndex = 0;
	FStaticMeshLODResources& LOD = Mesh->GetRenderData()->LODResources[LODIndex];

	TArray<int32> Triangles;
	const int32 NumIndices = LOD.IndexBuffer.GetNumIndices();
	for (int32 i = 0; i < NumIndices; ++i)
	{
		Triangles.Add(LOD.IndexBuffer.GetIndex(i));
	}

	TArray<FVector> Vertices;
	const int32 NumVertices = LOD.VertexBuffers.PositionVertexBuffer.GetNumVertices();
	for (int32 i = 0; i < NumVertices; ++i)
	{
		Vertices.Add((FVector)LOD.VertexBuffers.PositionVertexBuffer.VertexPosition(i));
	}

	OculusXRHMD::FOculusPassthroughMeshRef PassthroughMesh = new OculusXRHMD::FOculusPassthroughMesh(Vertices, Triangles);
	return PassthroughMesh;
}

void UOculusXRPassthroughLayerComponent::AddSurfaceGeometry(AStaticMeshActor* StaticMeshActor, bool updateTransform)
{
	if (StaticMeshActor)
	{
		UStaticMeshComponent* StaticMeshComponent = StaticMeshActor->GetStaticMeshComponent();
		if (StaticMeshComponent)
			AddStaticSurfaceGeometry(StaticMeshComponent, updateTransform);
	}
}

void UOculusXRPassthroughLayerComponent::AddStaticSurfaceGeometry(UStaticMeshComponent* StaticMeshComponent, bool updateTransform)
{
	if (!StaticMeshComponent)
		return;

	UOculusXRStereoLayerShapeUserDefined* UserShape = Cast<UOculusXRStereoLayerShapeUserDefined>(Shape);
	if (!UserShape)
		return;

	OculusXRHMD::FOculusPassthroughMeshRef PassthroughMesh = CreatePassthroughMesh(StaticMeshComponent);
	if (!PassthroughMesh)
		return;

	const FString MeshName = StaticMeshComponent->GetFullName();
	const FTransform Transform = StaticMeshComponent->GetComponentTransform();
	UserShape->AddGeometry(MeshName, PassthroughMesh, Transform, updateTransform);

	PassthroughComponentMap.Add(MeshName, StaticMeshComponent);
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerComponent::AddProceduralSurfaceGeometry(UProceduralMeshComponent* ProceduralMeshComponent, bool updateTransform)
{
	if (!ProceduralMeshComponent)
		return;

	UOculusXRStereoLayerShapeUserDefined* UserShape = Cast<UOculusXRStereoLayerShapeUserDefined>(Shape);
	if (!UserShape)
		return;

	OculusXRHMD::FOculusPassthroughMeshRef PassthroughMesh = CreatePassthroughMesh(ProceduralMeshComponent);
	if (!PassthroughMesh)
		return;

	const FString MeshName = ProceduralMeshComponent->GetFullName();
	const FTransform Transform = ProceduralMeshComponent->GetComponentTransform();
	UserShape->AddGeometry(MeshName, PassthroughMesh, Transform, updateTransform);

	PassthroughComponentMap.Add(MeshName, ProceduralMeshComponent);
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerComponent::RemoveSurfaceGeometry(AStaticMeshActor* StaticMeshActor)
{
	if (StaticMeshActor)
		RemoveSurfaceGeometryComponent(StaticMeshActor->GetStaticMeshComponent());
}

void UOculusXRPassthroughLayerComponent::RemoveStaticSurfaceGeometry(UStaticMeshComponent* StaticMeshComponent)
{
	RemoveSurfaceGeometryComponent(StaticMeshComponent);
}

void UOculusXRPassthroughLayerComponent::RemoveProceduralSurfaceGeometry(UProceduralMeshComponent* ProceduralMeshComponent)
{
	RemoveSurfaceGeometryComponent(ProceduralMeshComponent);
}

void UOculusXRPassthroughLayerComponent::RemoveSurfaceGeometryComponent(UMeshComponent* MeshComponent)
{
	if (!MeshComponent)
		return;

	UOculusXRStereoLayerShapeUserDefined* UserShape = Cast<UOculusXRStereoLayerShapeUserDefined>(Shape);
	if (!UserShape)
		return;

	const FString MeshName = MeshComponent->GetFullName();

	UserShape->RemoveGeometry(MeshName);
	PassthroughComponentMap.Remove(MeshName);

	MarkStereoLayerDirty();
}

bool UOculusXRPassthroughLayerComponent::IsSurfaceGeometry(AStaticMeshActor* StaticMeshActor) const
{
	return StaticMeshActor ? IsSurfaceGeometryComponent(StaticMeshActor->GetStaticMeshComponent()) : false;
}

bool UOculusXRPassthroughLayerComponent::IsSurfaceGeometryComponent(const UMeshComponent* MeshComponent) const
{
	return MeshComponent ? PassthroughComponentMap.Contains(MeshComponent->GetFullName()) : false;
}

void UOculusXRPassthroughLayerComponent::MarkPassthroughStyleForUpdate()
{
	bPassthroughStyleNeedsUpdate = true;
}

#if WITH_EDITOR
bool UOculusXRPassthroughLayerComponent::CanEditChange(const FProperty* InProperty) const
{
	if (!Super::CanEditChange(InProperty))
		return false;

	const FName PropertyName = InProperty->GetFName();
	if (PropertyName == GET_MEMBER_NAME_CHECKED(UOculusXRPassthroughLayerComponent, Texture)
		|| PropertyName == GET_MEMBER_NAME_CHECKED(UOculusXRPassthroughLayerComponent, LeftTexture)
		|| PropertyName == GET_MEMBER_NAME_CHECKED(UOculusXRPassthroughLayerComponent, bLiveTexture)
		|| PropertyName == GET_MEMBER_NAME_CHECKED(UOculusXRPassthroughLayerComponent, bNoAlphaChannel)
		|| PropertyName == GET_MEMBER_NAME_CHECKED(UOculusXRPassthroughLayerComponent, bQuadPreserveTextureRatio)
#ifdef WITH_OCULUS_BRANCH
		|| PropertyName == GET_MEMBER_NAME_CHECKED(UOculusXRPassthroughLayerComponent, bBicubicFiltering)
#endif
		|| PropertyName == GET_MEMBER_NAME_CHECKED(UOculusXRPassthroughLayerComponent, QuadSize)
		|| PropertyName == GET_MEMBER_NAME_CHECKED(UOculusXRPassthroughLayerComponent, UVRect)
		|| PropertyName == GET_MEMBER_NAME_CHECKED(UOculusXRPassthroughLayerComponent, StereoLayerType))
	{
		return false;
	}

	return true;
}
#endif // WITH_EDITOR

void UOculusXRPassthroughLayerComponent::OnAnyLayerResumedEvent(int InLayerId)
{
	if (LayerId == InLayerId)
	{
		OnLayerResumed.Broadcast();
	}
}

bool UOculusXRPassthroughLayerComponent::LayerRequiresTexture()
{
	const bool bIsPassthroughShape = Shape && (Shape->IsA<UOculusXRStereoLayerShapeReconstructed>() || Shape->IsA<UOculusXRStereoLayerShapeUserDefined>());
	return !bIsPassthroughShape;
}

void UOculusXRPassthroughLayerBase::SetTextureOpacity(float InOpacity)
{
	if (TextureOpacityFactor == InOpacity)
	{
		return;
	}

	TextureOpacityFactor = InOpacity;
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::EnableEdgeColor(bool bInEnableEdgeColor)
{
	if (bEnableEdgeColor == bInEnableEdgeColor)
	{
		return;
	}
	bEnableEdgeColor = bInEnableEdgeColor;
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::EnableColorMap(bool bInEnableColorMap)
{
	if (bEnableColorMap == bInEnableColorMap)
	{
		return;
	}
	bEnableColorMap = bInEnableColorMap;
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::SetEdgeRenderingColor(FLinearColor InEdgeColor)
{
	if (EdgeColor == InEdgeColor)
	{
		return;
	}
	EdgeColor = InEdgeColor;
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::EnableColorMapCurve(bool bInEnableColorMapCurve)
{
	if (bUseColorMapCurve == bInEnableColorMapCurve)
	{
		return;
	}
	bUseColorMapCurve = bInEnableColorMapCurve;
	ColorArray = GenerateColorArray(bUseColorMapCurve, ColorMapCurve);
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::SetColorMapCurve(UCurveLinearColor* InColorMapCurve)
{
	if (ColorMapCurve == InColorMapCurve)
	{
		return;
	}
	ColorMapCurve = InColorMapCurve;
	ColorArray = GenerateColorArray(bUseColorMapCurve, ColorMapCurve);
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::SetColorMapType(EOculusXRColorMapType InColorMapType)
{
	if (ColorMapType == InColorMapType)
	{
		return;
	}
	ColorMapType = InColorMapType;
	ColorArray = GenerateColorArray(bUseColorMapCurve, ColorMapCurve);
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::SetColorArray(const TArray<FLinearColor>& InColorArray)
{
	if (InColorArray.Num() == 0)
	{
		return;
	}

	if (ColorMapType != ColorMapType_GrayscaleToColor)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("SetColorArray is ignored for color map types other than Grayscale to Color."));
		return;
	}

	if (bUseColorMapCurve)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("UseColorMapCurve is enabled on the layer. Automatic disable and use the Array for color lookup"));
	}
	bUseColorMapCurve = false;

	ColorArray = InColorArray;
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::ClearColorMap()
{
	ColorArray.Empty();
}

void UOculusXRPassthroughLayerBase::SetColorMapControls(float InContrast, float InBrightness, float InPosterize)
{
	if (ColorMapType != ColorMapType_Grayscale && ColorMapType != ColorMapType_GrayscaleToColor)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("SetColorMapControls is ignored for color map types other than Grayscale and Grayscale to color."));
		return;
	}
	Contrast = FMath::Clamp(InContrast, -1.0f, 1.0f);
	Brightness = FMath::Clamp(InBrightness, -1.0f, 1.0f);
	Posterize = FMath::Clamp(InPosterize, 0.0f, 1.0f);

	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::SetBrightnessContrastSaturation(float InContrast, float InBrightness, float InSaturation)
{
	if (ColorMapType != ColorMapType_ColorAdjustment)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("SetBrightnessContrastSaturation is ignored for color map types other than Color Adjustment."));
		return;
	}
	Contrast = FMath::Clamp(InContrast, -1.0f, 1.0f);
	Brightness = FMath::Clamp(InBrightness, -1.0f, 1.0f);
	Saturation = FMath::Clamp(InSaturation, -1.0f, 1.0f);

	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::SetColorScaleAndOffset(FLinearColor InColorScale, FLinearColor InColorOffset)
{
	if (ColorScale == InColorScale && ColorOffset == InColorOffset)
	{
		return;
	}
	ColorScale = InColorScale;
	ColorOffset = InColorOffset;
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::SetLayerPlacement(EOculusXRPassthroughLayerOrder InLayerOrder)
{
	if (LayerOrder == InLayerOrder)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("Same layer order as before, no change needed"));
		return;
	}

	LayerOrder = InLayerOrder;
	this->MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::SetColorLUTSource(class UOculusXRPassthroughColorLut* InColorLUTSource)
{
	if (ColorMapType != ColorMapType_ColorLut && ColorMapType != ColorMapType_ColorLut_Interpolated)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("SetColorLUT is ignored for color map types other than Color LUT."));
		return;
	}

	if (InColorLUTSource == ColorLUTSource)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("Same color LUT source as before, no change needed"));
		return;
	}

	// Remove reference from the old LUT
	if (ColorLUTSource)
		ColorLUTSource->RemoveReference(this);

	ColorLUTSource = InColorLUTSource;
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::SetColorLUTTarget(class UOculusXRPassthroughColorLut* InColorLUTTarget)
{
	if (ColorMapType != ColorMapType_ColorLut_Interpolated)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("SetColorLUTTarget is ignored for color map types other than Interpolated Color LUT."));
		return;
	}

	if (InColorLUTTarget == ColorLUTTarget)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("Same color LUT source as before, no change needed"));
		return;
	}

	// Remove reference from the old LUT
	if (ColorLUTTarget)
		ColorLUTTarget->RemoveReference(this);

	ColorLUTTarget = InColorLUTTarget;
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::SetColorLUTWeight(float InWeight)
{
	if (ColorMapType != ColorMapType_ColorLut && ColorMapType != ColorMapType_ColorLut_Interpolated)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("SetWeight is ignored for color map types other than Color LUT."));
		return;
	}

	if (LutWeight == InWeight)
	{
		UE_LOG(LogOculusPassthrough, Warning, TEXT("Same lut weight as before, no change needed"));
		return;
	}

	LutWeight = InWeight;
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::RemoveColorLut()
{
	ClearLUTsReferences();

	ColorLUTSource = nullptr;
	ColorLUTTarget = nullptr;
	MarkStereoLayerDirty();
}

void UOculusXRPassthroughLayerBase::ClearLUTsReferences()
{
	// Clear lut references
	if (ColorLUTSource)
		ColorLUTSource->RemoveReference(this);
	if (ColorLUTTarget)
		ColorLUTTarget->RemoveReference(this);
}

void UOculusXRPassthroughLayerBase::BeginDestroy()
{
	ClearLUTsReferences();

	Super::BeginDestroy();
}

TArray<FLinearColor> UOculusXRPassthroughLayerBase::GenerateColorArrayFromColorCurve(const UCurveLinearColor* InColorMapCurve) const
{
	if (InColorMapCurve == nullptr)
	{
		return TArray<FLinearColor>();
	}

	TArray<FLinearColor> NewColorArray;
	constexpr uint32 TotalEntries = 256;
	NewColorArray.Empty();
	NewColorArray.SetNum(TotalEntries);

	for (int32 Index = 0; Index < TotalEntries; ++Index)
	{
		const float Alpha = ((float)Index / TotalEntries);
		NewColorArray[Index] = InColorMapCurve->GetLinearColorValue(Alpha);
	}
	return NewColorArray;
}

TArray<FLinearColor> UOculusXRPassthroughLayerBase::GetOrGenerateNeutralColorArray()
{
	if (NeutralColorArray.Num() == 0)
	{
		const uint32 TotalEntries = 256;
		NeutralColorArray.SetNum(TotalEntries);

		for (int32 Index = 0; Index < TotalEntries; ++Index)
		{
			NeutralColorArray[Index] = FLinearColor((float)Index / TotalEntries, (float)Index / TotalEntries, (float)Index / TotalEntries);
		}
	}

	return NeutralColorArray;
}

TArray<FLinearColor> UOculusXRPassthroughLayerBase::GenerateColorArray(bool bInUseColorMapCurve, const UCurveLinearColor* InColorMapCurve)
{
	TArray<FLinearColor> NewColorArray;
	if (bInUseColorMapCurve)
	{
		NewColorArray = GenerateColorArrayFromColorCurve(InColorMapCurve);
	}

	// Check for existing Array, otherwise generate a neutral one
	if (NewColorArray.Num() == 0)
	{
		NewColorArray = GetOrGenerateNeutralColorArray();
	}

	return NewColorArray;
}

TArray<FLinearColor> UOculusXRPassthroughLayerBase::GetColorArray(bool bInUseColorMapCurve, const UCurveLinearColor* InColorMapCurve)
{
	if (ColorArray.Num() == 0)
	{
		if (bInUseColorMapCurve)
		{
			return GenerateColorArray(bInUseColorMapCurve, InColorMapCurve);
		}
		return GetOrGenerateNeutralColorArray();
	}

	return ColorArray;
}

FColorLutDesc UOculusXRPassthroughLayerBase::GenerateColorLutDescription(float InLutWeight, UOculusXRPassthroughColorLut* InLutSource, UOculusXRPassthroughColorLut* InLutTarget)
{
	TArray<uint64> ColorLuts;
	if (InLutSource != nullptr && InLutSource->ColorLutType != EColorLutType::None)
	{
		uint64 ColorLutHandle = InLutSource->GetHandle(this);
		if (ColorLutHandle != 0)
		{
			ColorLuts.Add(ColorLutHandle);
		}
	}

	if (InLutTarget != nullptr && ColorMapType == EOculusXRColorMapType::ColorMapType_ColorLut_Interpolated && ColorLuts.Num() > 0 && InLutSource->ColorLutType != EColorLutType::None)
	{
		uint64 ColorLutHandle = InLutTarget->GetHandle(this);
		if (ColorLutHandle != 0)
		{
			ColorLuts.Add(ColorLutHandle);
		}
	}

	return FColorLutDesc(ColorLuts, InLutWeight);
}

void UOculusXRPassthroughLayerBase::MarkStereoLayerDirty()
{
	if (UStereoLayerComponent* stereoLayerComponent = Cast<UStereoLayerComponent>(GetOuter()))
	{
		stereoLayerComponent->MarkStereoLayerDirty();
	}
	else if (UOculusXRPersistentPassthroughInstance* pptInstance = Cast<UOculusXRPersistentPassthroughInstance>(GetOuter()))
	{
		pptInstance->UpdateLayer();
	}
}
