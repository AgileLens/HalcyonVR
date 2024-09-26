// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitGridSliceResizer.h"

#include "MRUtilityKit.h"
#include "MRUtilityKitTelemetry.h"
#include "OculusXRTelemetry.h"
#include "Engine/StaticMesh.h"
#include "ProceduralMeshComponent.h"
#include "StaticMeshResources.h"

UMRUKGridSliceResizerComponent::UMRUKGridSliceResizerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	ProcMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProcMesh"));
	ProcMesh->SetupAttachment(this);
}

void UMRUKGridSliceResizerComponent::BeginPlay()
{
	Super::BeginPlay();
#if WITH_EDITOR
	if (OculusXRTelemetry::IsActive())
	{
		MRUKTelemetry::FLoadGridSliceResizerMarker().Start().End(OculusXRTelemetry::EAction::Success);
	}
#endif
	SliceMesh();
}

void UMRUKGridSliceResizerComponent::OnRegister()
{
	Super::OnRegister();
	SliceMesh();
}

void UMRUKGridSliceResizerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const FVector ActorScale = GetOwner() ? GetOwner()->GetActorScale() : FVector::OneVector;
	if (Mesh && ActorScale != ResizerScale)
	{
		ResizerScale = ActorScale;
		SliceMesh();
	}
}

#if WITH_EDITOR
void UMRUKGridSliceResizerComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property->GetOwner<AActor>() == GetOwner())
	{
		return;
	}

	const FName PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	if (PropertyName == GET_MEMBER_NAME_CHECKED(UMRUKGridSliceResizerComponent, BorderXNegative)
		|| PropertyName == GET_MEMBER_NAME_CHECKED(UMRUKGridSliceResizerComponent, BorderXPositive)
		|| PropertyName == GET_MEMBER_NAME_CHECKED(UMRUKGridSliceResizerComponent, BorderYNegative)
		|| PropertyName == GET_MEMBER_NAME_CHECKED(UMRUKGridSliceResizerComponent, BorderYPositive)
		|| PropertyName == GET_MEMBER_NAME_CHECKED(UMRUKGridSliceResizerComponent, BorderZNegative)
		|| PropertyName == GET_MEMBER_NAME_CHECKED(UMRUKGridSliceResizerComponent, BorderZPositive)
		|| PropertyName == GET_MEMBER_NAME_CHECKED(UMRUKGridSliceResizerComponent, SlicerPivotOffset))
	{
		SliceMesh();
	}
}
#endif

void UMRUKGridSliceResizerComponent::SliceMesh()
{
	if (!Mesh)
	{
		return;
	}

	if (!Mesh->bAllowCPUAccess)
	{
		UE_LOG(LogMRUK, Error, TEXT("Can not slice a mesh that has no CPU access. Make sure you enable CPU access on the static mesh asset."));
		return;
	}

	TArray<FVector> Positions;
	TArray<FVector> Normals;
	TArray<FVector2D> UVs;
	TArray<FColor> Colors;
	TArray<int32> Triangles;

	const FStaticMeshLODResources& LODResources = Mesh->GetRenderData()->LODResources[0];
	const FStaticMeshVertexBuffers& VertexBuffers = LODResources.VertexBuffers;
	const FRawStaticIndexBuffer& IndexBuffer = LODResources.IndexBuffer;

	Positions.SetNum(LODResources.GetNumVertices());
	Normals.SetNum(LODResources.GetNumVertices());
	UVs.SetNum(LODResources.GetNumVertices());
	Colors.SetNum(LODResources.GetNumVertices());

	const FVector ActorScale = GetOwner() ? GetOwner()->GetActorScale() : FVector::OneVector;
	const FVector ActorScaleInv = FVector(1.0 / ActorScale.X, 1.0 / ActorScale.Y, 1.0 / ActorScale.Z);
	const FVector Size = ActorScale;

	// Slicing

	FTransform PivotTransform;
	PivotTransform.SetLocation(-SlicerPivotOffset);

	FTransform ScaledInvPivotTransform;
	ScaledInvPivotTransform.SetLocation(Size * SlicerPivotOffset);

	// The bounding box of the mesh to resize
	FBox BBox = Mesh->GetBoundingBox();
	BBox = FBox(PivotTransform.TransformPosition(BBox.Min), PivotTransform.TransformPosition(BBox.Max));

	// The bounding box of the mesh to resize scaled by the size
	const FBox BBoxScaled = FBox(BBox.Min * Size, BBox.Max * Size);

	// The bounding box of the mesh to resize scaled including the pivot point
	// This may be a bigger box as ScaledBBox in case the pivot is outside of the scaled bounding box.
	const FBox BBoxScaledPivot = FBox(
		FVector(FMath::Min(BBox.Min.X, SlicerPivotOffset.X), FMath::Min(BBox.Min.Y, SlicerPivotOffset.Y), FMath::Min(BBox.Min.Z, SlicerPivotOffset.Z)),
		FVector(FMath::Max(BBox.Max.X, SlicerPivotOffset.X), FMath::Max(BBox.Max.Y, SlicerPivotOffset.Y), FMath::Max(BBox.Max.Z, SlicerPivotOffset.Z)));

	// Locations of the border slices between 0 - 1
	FVector BorderPos = FVector(BorderXPositive, BorderYPositive, BorderZPositive);
	FVector BorderNeg = FVector(BorderXNegative, BorderYNegative, BorderZNegative);

	// Locations of the border slices for the X,Y,Z axis in local space
	FVector BorderPosLS;
	FVector BorderNegLS;

	// Distance from the Border[Pos|Neg]LS to the outer maximum/minimum of the BBox
	FVector StubPos;
	FVector StubNeg;

	// The inner bounding box that should be stretched in all directions
	FVector BBoxInnerMax;
	FVector BBoxInnerMin;

	// The expected bounding box of the inner bounding box when its scaled up by the size
	FVector BBoxInnerScaledMax;
	FVector BBoxInnerScaledMin;

	// The ratio between the inner bounding box and the scaled bounding box
	FVector InnerBoxScaleRatioMax;
	FVector InnerBoxScaleRatioMin;

	// The ratio to use for downscaling in case it's needed
	FVector DownscaleMax;
	FVector DownscaleMin;

	for (int32 I = 0; I < 3; ++I)
	{
		// We don't want to have division by zero further down the line
		BorderPos[I] = FMath::Clamp(BorderPos[I], DBL_EPSILON, 1.0);
		BorderNeg[I] = FMath::Clamp(BorderNeg[I], DBL_EPSILON, 1.0);

		BorderPosLS[I] = BBoxScaledPivot.Max[I] - (1.0 - BorderPos[I]) * FMath::Abs(BBoxScaledPivot.Max[I]);
		BorderNegLS[I] = BBoxScaledPivot.Min[I] + (1.0 - BorderNeg[I]) * FMath::Abs(BBoxScaledPivot.Min[I]);

		StubPos[I] = FMath::Abs(BBox.Max[I] - BorderPosLS[I]);
		StubNeg[I] = FMath::Abs(BBox.Min[I] - BorderNegLS[I]);

		BBoxInnerMax[I] = BBox.Max[I] - StubPos[I];
		BBoxInnerMin[I] = BBox.Min[I] + StubNeg[I];

		// Max may be negative and Min may be positive in case the stubs are greater than
		// the scaled down bounding box and therefore don't fit the scaled bounding box.
		// This case gets treated special down below.
		BBoxInnerScaledMax[I] = BBoxScaled.Max[I] - StubPos[I];
		BBoxInnerScaledMin[I] = BBoxScaled.Min[I] + StubNeg[I];

		InnerBoxScaleRatioMax[I] = FMath::Max(0.0, BBoxInnerScaledMax[I] / BBoxInnerMax[I]);
		InnerBoxScaleRatioMin[I] = FMath::Max(0.0, BBoxInnerScaledMin[I] / BBoxInnerMin[I]);

		// When Downscale[Min/Max] needs to be applied the temporary bounding box is
		// Max == StubPos, Min == StubNeg. Therefore get the ratio between it and the
		// expected scaled down bounding box to calculate the scale that needs
		// to be applied
		DownscaleMax[I] = BBoxScaled.Max[I] / StubPos[I];
		DownscaleMin[I] = BBoxScaled.Min[I] / StubNeg[I];
	}

	// Process vertices

	// If the center shouldn't be scaled we need to take care of the case when the original
	// center vertices would be outside of the expected downscaled bounding box. Therefore, iterate
	// through all vertices and check if the center vertices are outside. If they are outside we need
	// to scale down the center part as usually.
	// This unfortunately has to be done in a separate first pass.
	bool ScaleDownCenter[3] = { false, false, false };

	const int32 VertexCount = LODResources.GetNumVertices();
	for (int32 I = 0; I < VertexCount; ++I)
	{
		const FVector3f& Normal = VertexBuffers.StaticMeshVertexBuffer.VertexTangentZ(I);
		Normals[I] = FVector(Normal.X, Normal.Y, Normal.Z);

		const FVector2f& UV = VertexBuffers.StaticMeshVertexBuffer.GetVertexUV(I, 0);
		UVs[I] = FVector2D(UV.X, UV.Y);

		const FVector3f& P = VertexBuffers.PositionVertexBuffer.VertexPosition(I);

		// Apply pivot offset
		Positions[I] = PivotTransform.TransformPosition(FVector(P.X, P.Y, P.Z));
		const FVector& Position = Positions[I];

		for (int32 A = 0; A < 3; ++A)
		{
			if ((0.0 <= Position[A] && Position[A] <= BorderPosLS[A]) && (Position[A] > BBoxInnerScaledMax[A]))
			{
				ScaleDownCenter[A] = true;
			}
			else if ((BorderNegLS[A] <= Position[A] && Position[A] <= 0.0) && (Position[A] < BBoxInnerScaledMin[A]))
			{
				ScaleDownCenter[A] = true;
			}
		}
	}

	bool bScaleCenter[3] = {};
	bScaleCenter[0] = ScaleCenterMode & static_cast<uint8>(EMRUKScaleCenterMode::XAxis) ? true : false;
	bScaleCenter[1] = ScaleCenterMode & static_cast<uint8>(EMRUKScaleCenterMode::YAxis) ? true : false;
	bScaleCenter[2] = ScaleCenterMode & static_cast<uint8>(EMRUKScaleCenterMode::ZAxis) ? true : false;

	for (FVector& Position : Positions)
	{
		// Apply computations on each axis

		for (int32 A = 0; A < 3; ++A)
		{
			if ((bScaleCenter[A] || ScaleDownCenter[A]) && (0.0 <= Position[A] && Position[A] <= BorderPosLS[A]))
			{
				// Vertex is inside the inner distance and should be stretched
				Position[A] *= InnerBoxScaleRatioMax[A];
			}
			else if ((bScaleCenter[A] || ScaleDownCenter[A]) && (BorderNegLS[A] <= Position[A] && Position[A] <= 0.0))
			{
				// Vertex is inside the inner distance and should be stretched
				Position[A] *= InnerBoxScaleRatioMin[A];
			}
			else if (BorderPosLS[A] < Position[A])
			{
				// Vertex is inside the outer stub and should not be stretched
				// Perform linear transform of vertices into their expect position
				Position[A] = BorderPosLS[A] * InnerBoxScaleRatioMax[A] + (Position[A] - BorderPosLS[A]);
				if (BBoxInnerScaledMax[A] < 0.0)
				{
					// The mesh that would result from the linear transform above is still not small enough to
					// fit into the expected scaled down bounding box. This means the stubs need to be scaled down
					// to make them fit.
					Position[A] *= DownscaleMax[A];
				}
			}
			else if (Position[A] < BorderNegLS[A])
			{
				// Vertex is inside the outer stub and should not be stretched
				// Perform linear transform of vertices into their expect position
				Position[A] = BorderNegLS[A] * InnerBoxScaleRatioMin[A] - (BorderNegLS[A] - Position[A]);
				if (BBoxInnerScaledMin[A] > 0.0)
				{
					// The mesh that would result from the linear transform above is still not small enough to
					// fit into the expected scaled down bounding box. This means the stubs need to be scaled down
					// to make them fit.
					Position[A] *= -DownscaleMin[A];
				}
			}
		}

		// Undo pivot offset
		Position = ActorScaleInv * ScaledInvPivotTransform.TransformPosition(Position);
	}

	Triangles.SetNum(IndexBuffer.GetNumIndices());
	for (int32 I = 0; I < IndexBuffer.GetNumIndices(); ++I)
	{
		Triangles[I] = IndexBuffer.GetIndex(I);
	}

	ProcMesh->ClearMeshSection(0);
	ProcMesh->CreateMeshSection(0, Positions, Triangles, Normals, UVs, Colors, {}, bGenerateCollision);
	ProcMesh->SetMaterial(0, Mesh->GetMaterial(0));
}
