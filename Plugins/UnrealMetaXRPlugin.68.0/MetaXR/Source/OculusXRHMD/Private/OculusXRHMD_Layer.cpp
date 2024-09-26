// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRHMD_Layer.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS
// #include "MediaTexture.h"
// #include "ScreenRendering.h"
// #include "ScenePrivate.h"
// #include "PostProcess/SceneFilterRendering.h"
#include "PostProcess/SceneRenderTargets.h"
#include "HeadMountedDisplayTypes.h" // for LogHMD
#include "OculusXRHMD.h"
#include "XRThreadUtils.h"
#include "Engine/RendererSettings.h"
#include "Engine/Texture2D.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/GameEngine.h"
#include "SceneUtils.h"
#include "OculusXRHMDPrivate.h"
#include "OculusXRHMDModule.h"
#include "OculusXRHMD_DeferredDeletionQueue.h"
#include "OculusXRStereoLayersFlagsSupplier.h"

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// FOvrpLayer
	//-------------------------------------------------------------------------------------------------

	FOvrpLayer::FOvrpLayer(uint32 InOvrpLayerId, FDeferredDeletionQueue* InDeferredDeletion)
		: OvrpLayerId(InOvrpLayerId), DeferredDeletion(InDeferredDeletion)
	{
	}

	FOvrpLayer::~FOvrpLayer()
	{
		if (IsInGameThread())
		{
			ExecuteOnRenderThread([OvrpLayerId = this->OvrpLayerId, DeferredDeletion = this->DeferredDeletion]() {
				DeferredDeletion->AddOVRPLayerToDeferredDeletionQueue(OvrpLayerId);
			});
		}
		else
		{
			DeferredDeletion->AddOVRPLayerToDeferredDeletionQueue(OvrpLayerId);
		}
	}

	//-------------------------------------------------------------------------------------------------
	// FLayer
	//-------------------------------------------------------------------------------------------------

	FLayer::FLayer(uint32 InId)
		: bNeedsTexSrgbCreate(false)
		, Id(InId)
		, OvrpLayerId(0)
		, bUpdateTexture(false)
		, bInvertY(false)
		, bHasDepth(false)
		, bSupportDepthComposite(false)
		, PokeAHoleComponentPtr(nullptr)
		, PokeAHoleActor(nullptr)
	{
		FMemory::Memzero(OvrpLayerDesc);
		FMemory::Memzero(OvrpLayerSubmit);
	}

	FLayer::FLayer(const FLayer& Layer)
		: bNeedsTexSrgbCreate(Layer.bNeedsTexSrgbCreate)
		, Id(Layer.Id)
		, Desc(Layer.Desc)
		, OvrpLayerId(Layer.OvrpLayerId)
		, OvrpLayer(Layer.OvrpLayer)
		, SwapChain(Layer.SwapChain)
		, DepthSwapChain(Layer.DepthSwapChain)
		, FoveationSwapChain(Layer.FoveationSwapChain)
		, RightSwapChain(Layer.RightSwapChain)
		, RightDepthSwapChain(Layer.RightDepthSwapChain)
		, MotionVectorSwapChain(Layer.MotionVectorSwapChain)
		, MotionVectorDepthSwapChain(Layer.MotionVectorDepthSwapChain)
		, InvAlphaTexture(Layer.InvAlphaTexture)
		, bUpdateTexture(Layer.bUpdateTexture)
		, bInvertY(Layer.bInvertY)
		, bHasDepth(Layer.bHasDepth)
		, bSupportDepthComposite(Layer.bSupportDepthComposite)
		, PokeAHoleComponentPtr(Layer.PokeAHoleComponentPtr)
		, PokeAHoleActor(Layer.PokeAHoleActor)
		, UserDefinedGeometryMap(Layer.UserDefinedGeometryMap)
		, PassthroughPokeActorMap(Layer.PassthroughPokeActorMap)
	{
		FMemory::Memcpy(&OvrpLayerDesc, &Layer.OvrpLayerDesc, sizeof(OvrpLayerDesc));
		FMemory::Memcpy(&OvrpLayerSubmit, &Layer.OvrpLayerSubmit, sizeof(OvrpLayerSubmit));
	}

	FLayer::~FLayer()
	{
	}

	void FLayer::SetDesc(const IStereoLayers::FLayerDesc& InDesc)
	{
		if (Desc.Texture != InDesc.Texture || Desc.LeftTexture != InDesc.LeftTexture)
		{
			bUpdateTexture = true;
		}

		Desc = InDesc;

		if (!UserDefinedGeometryMap)
		{
			UserDefinedGeometryMap = MakeShared<TMap<FString, FPassthroughMesh>, ESPMode::ThreadSafe>();
		}

		if (!PassthroughPokeActorMap)
		{
			PassthroughPokeActorMap = MakeShared<TMap<FString, FPassthroughPokeActor>, ESPMode::ThreadSafe>();
		}

		HandlePokeAHoleComponent();

#if !PLATFORM_ANDROID
		if (!(Desc.HasShape<FReconstructedLayer>() || Desc.HasShape<FUserDefinedLayer>())) // If not Passthrough Shape
		{
			// Mark all layers as supporting depth for now, due to artifacts with ovrpLayerSubmitFlag_NoDepth
			Desc.Flags |= IStereoLayers::LAYER_FLAG_SUPPORT_DEPTH;
		}
#endif

		UpdatePassthroughPokeActors_GameThread();
	}

	void FLayer::SetDesc(const FSettings* Settings, const IStereoLayers::FLayerDesc& InDesc)
	{
		bSupportDepthComposite = Settings->Flags.bCompositeDepth;

		SetDesc(InDesc);
	}

	static UWorld* GetWorld()
	{
		UWorld* World = nullptr;
		for (const FWorldContext& Context : GEngine->GetWorldContexts())
		{
			if (Context.WorldType == EWorldType::Game || Context.WorldType == EWorldType::PIE)
			{
				World = Context.World();
			}
		}
		return World;
	}

	bool FLayer::NeedsPassthroughPokeAHole()
	{
		return ((Desc.Flags & IStereoLayers::LAYER_FLAG_SUPPORT_DEPTH) != 0) && Desc.HasShape<FUserDefinedLayer>();
	}

	bool FLayer::NeedsPokeAHole()
	{
#if PLATFORM_ANDROID
		bool bIsPassthroughShape = (Desc.HasShape<FReconstructedLayer>() || Desc.HasShape<FUserDefinedLayer>());
		return !bIsPassthroughShape && !bSupportDepthComposite && ((Desc.Flags & IStereoLayers::LAYER_FLAG_SUPPORT_DEPTH) != 0);
#else
		return false;
#endif
	}

	void FLayer::HandlePokeAHoleComponent()
	{
		if (NeedsPokeAHole())
		{
			const FString BaseComponentName = FString::Printf(TEXT("OculusPokeAHole_%d"), Id);
			const FName ComponentName(*BaseComponentName);

			if (!PokeAHoleComponentPtr)
			{
				UWorld* World = GetWorld();

				if (!World)
				{
					return;
				}

				PokeAHoleActor = World->SpawnActor<AActor>();

				PokeAHoleComponentPtr = NewObject<UProceduralMeshComponent>(PokeAHoleActor, ComponentName);
				PokeAHoleComponentPtr->RegisterComponent();

				TArray<FVector> Vertices;
				TArray<int32> Triangles;
				TArray<FVector> Normals;
				TArray<FVector2D> UV0;
				TArray<FLinearColor> VertexColors;
				TArray<FProcMeshTangent> Tangents;

				BuildPokeAHoleMesh(Vertices, Triangles, UV0);
				PokeAHoleComponentPtr->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UV0, VertexColors, Tangents, false);

				FOculusXRHMD* OculusXRHMD = static_cast<FOculusXRHMD*>(GEngine->XRSystem->GetHMDDevice());
				UMaterial* PokeAHoleMaterial = OculusXRHMD->GetResourceHolder()->PokeAHoleMaterial;
				UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(PokeAHoleMaterial, nullptr);
				PokeAHoleComponentPtr->SetMaterial(0, DynamicMaterial);
			}
			PokeAHoleComponentPtr->SetWorldTransform(Desc.Transform);
		}

		return;
	}

	static void AppendFaceIndices(const int v0, const int v1, const int v2, const int v3, TArray<int32>& Triangles, bool inverse)
	{
		if (inverse)
		{
			Triangles.Add(v0);
			Triangles.Add(v2);
			Triangles.Add(v1);
			Triangles.Add(v0);
			Triangles.Add(v3);
			Triangles.Add(v2);
		}
		else
		{
			Triangles.Add(v0);
			Triangles.Add(v1);
			Triangles.Add(v2);
			Triangles.Add(v0);
			Triangles.Add(v2);
			Triangles.Add(v3);
		}
	}

	void FLayer::BuildPokeAHoleMesh(TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector2D>& UV0)
	{
		if (Desc.HasShape<FQuadLayer>())
		{
			const float QuadScale = 0.99;

			FIntPoint TexSize = Desc.Texture.IsValid() ? Desc.Texture->GetTexture2D()->GetSizeXY() : Desc.LayerSize;
			float AspectRatio = TexSize.X ? (float)TexSize.Y / (float)TexSize.X : 3.0f / 4.0f;

			float QuadSizeX = Desc.QuadSize.X;
			float QuadSizeY = (Desc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) ? Desc.QuadSize.X * AspectRatio : Desc.QuadSize.Y;

			Vertices.Init(FVector::ZeroVector, 4);
			Vertices[0] = FVector(0.0, -QuadSizeX / 2, -QuadSizeY / 2) * QuadScale;
			Vertices[1] = FVector(0.0, QuadSizeX / 2, -QuadSizeY / 2) * QuadScale;
			Vertices[2] = FVector(0.0, QuadSizeX / 2, QuadSizeY / 2) * QuadScale;
			Vertices[3] = FVector(0.0, -QuadSizeX / 2, QuadSizeY / 2) * QuadScale;

			UV0.Init(FVector2D::ZeroVector, 4);
			UV0[0] = FVector2D(1, 0);
			UV0[1] = FVector2D(1, 1);
			UV0[2] = FVector2D(0, 0);
			UV0[3] = FVector2D(0, 1);

			Triangles.Reserve(6);
			AppendFaceIndices(0, 1, 2, 3, Triangles, false);
		}
		else if (Desc.HasShape<FCylinderLayer>())
		{
			const FCylinderLayer& CylinderProps = Desc.GetShape<FCylinderLayer>();
			const float CylinderScale = 0.99;

			FIntPoint TexSize = Desc.Texture.IsValid() ? Desc.Texture->GetTexture2D()->GetSizeXY() : Desc.LayerSize;
			float AspectRatio = TexSize.X ? (float)TexSize.Y / (float)TexSize.X : 3.0f / 4.0f;

			float CylinderHeight = (Desc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) ? CylinderProps.OverlayArc * AspectRatio : CylinderProps.Height;

			const FVector XAxis = FVector(1, 0, 0);
			const FVector YAxis = FVector(0, 1, 0);
			const FVector HalfHeight = FVector(0, 0, CylinderHeight / 2);

			const float ArcAngle = CylinderProps.OverlayArc / CylinderProps.Radius;
			const int Sides = (int)((ArcAngle * 180) / (PI * 5)); // one triangle every 10 degrees of cylinder for a good-cheap approximation
			Vertices.Init(FVector::ZeroVector, 2 * (Sides + 1));
			UV0.Init(FVector2D::ZeroVector, 2 * (Sides + 1));
			Triangles.Init(0, Sides * 6);

			float CurrentAngle = -ArcAngle / 2;
			const float AngleStep = ArcAngle / Sides;

			for (int Side = 0; Side < Sides + 1; Side++)
			{
				FVector MidVertex = CylinderProps.Radius * (FMath::Cos(CurrentAngle) * XAxis + FMath::Sin(CurrentAngle) * YAxis);
				Vertices[2 * Side] = (MidVertex - HalfHeight) * CylinderScale;
				Vertices[(2 * Side) + 1] = (MidVertex + HalfHeight) * CylinderScale;

				UV0[2 * Side] = FVector2D(1 - (Side / (float)Sides), 0);
				UV0[(2 * Side) + 1] = FVector2D(1 - (Side / (float)Sides), 1);

				CurrentAngle += AngleStep;

				if (Side < Sides)
				{
					Triangles[6 * Side + 0] = 2 * Side;
					Triangles[6 * Side + 2] = 2 * Side + 1;
					Triangles[6 * Side + 1] = 2 * (Side + 1) + 1;
					Triangles[6 * Side + 3] = 2 * Side;
					Triangles[6 * Side + 5] = 2 * (Side + 1) + 1;
					Triangles[6 * Side + 4] = 2 * (Side + 1);
				}
			}
		}
		else if (Desc.HasShape<FCubemapLayer>())
		{
			const float CubemapScale = 1000;
			Vertices.Init(FVector::ZeroVector, 8);
			Vertices[0] = FVector(-1.0, -1.0, -1.0) * CubemapScale;
			Vertices[1] = FVector(-1.0, -1.0, 1.0) * CubemapScale;
			Vertices[2] = FVector(-1.0, 1.0, -1.0) * CubemapScale;
			Vertices[3] = FVector(-1.0, 1.0, 1.0) * CubemapScale;
			Vertices[4] = FVector(1.0, -1.0, -1.0) * CubemapScale;
			Vertices[5] = FVector(1.0, -1.0, 1.0) * CubemapScale;
			Vertices[6] = FVector(1.0, 1.0, -1.0) * CubemapScale;
			Vertices[7] = FVector(1.0, 1.0, 1.0) * CubemapScale;

			Triangles.Reserve(24);
			AppendFaceIndices(0, 1, 3, 2, Triangles, false);
			AppendFaceIndices(4, 5, 7, 6, Triangles, true);
			AppendFaceIndices(0, 1, 5, 4, Triangles, true);
			AppendFaceIndices(2, 3, 7, 6, Triangles, false);
			AppendFaceIndices(0, 2, 6, 4, Triangles, false);
			AppendFaceIndices(1, 3, 7, 5, Triangles, true);
		}
	}

	bool FLayer::BuildPassthroughPokeActor(FOculusPassthroughMeshRef PassthroughMesh, FPassthroughPokeActor& OutPassthroughPokeActor)
	{
		UWorld* World = GetWorld();

		if (!World)
		{
			return false;
		}

		const FString BaseComponentName = FString::Printf(TEXT("OculusPassthroughPoke_%d"), Id);
		const FName ComponentName(*BaseComponentName);
		AActor* PassthoughPokeActor = World->SpawnActor<AActor>();
		UProceduralMeshComponent* PassthoughPokeComponentPtr = NewObject<UProceduralMeshComponent>(PassthoughPokeActor, ComponentName);
		PassthoughPokeComponentPtr->RegisterComponent();

		const TArray<int32>& Triangles = PassthroughMesh->GetTriangles();
		const TArray<FVector>& Vertices = PassthroughMesh->GetVertices();
		TArray<FVector> Normals;
		TArray<FVector2D> UV0;
		TArray<FLinearColor> VertexColors;
		TArray<FProcMeshTangent> Tangents;

		PassthoughPokeComponentPtr->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UV0, VertexColors, Tangents, false);

		FOculusXRHMD* OculusXRHMD = static_cast<FOculusXRHMD*>(GEngine->XRSystem->GetHMDDevice());
		UMaterial* PokeAHoleMaterial = OculusXRHMD->GetResourceHolder()->PokeAHoleMaterial;

		UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(PokeAHoleMaterial, nullptr);
		PassthoughPokeComponentPtr->SetMaterial(0, DynamicMaterial);

		OutPassthroughPokeActor.PokeAHoleActor = PassthoughPokeActor;
		OutPassthroughPokeActor.PokeAHoleComponentPtr = PassthoughPokeComponentPtr;

		return true;
	}

	void FLayer::UpdatePassthroughPokeActors_GameThread()
	{
		if (Desc.HasShape<FUserDefinedLayer>())
		{
			const FUserDefinedLayer& UserDefinedLayerProps = Desc.GetShape<FUserDefinedLayer>();
			const TArray<FUserDefinedGeometryDesc>& UserGeometryList = UserDefinedLayerProps.UserGeometryList;
			TSet<FString> UsedSet = {};

			if (NeedsPassthroughPokeAHole())
			{
				for (const FUserDefinedGeometryDesc& GeometryDesc : UserGeometryList)
				{
					const FString MeshName = GeometryDesc.MeshName;
					UsedSet.Add(MeshName);

					FPassthroughPokeActor* FoundPassthroughPokeActor = PassthroughPokeActorMap->Find(MeshName);
					if (!FoundPassthroughPokeActor)
					{
						OculusXRHMD::FOculusPassthroughMeshRef GeomPassthroughMesh = GeometryDesc.PassthroughMesh;
						if (GeomPassthroughMesh)
						{
							FPassthroughPokeActor PassthroughPokeActor;
							if (BuildPassthroughPokeActor(GeomPassthroughMesh, PassthroughPokeActor))
							{
								PassthroughPokeActor.PokeAHoleComponentPtr->SetWorldTransform(GeometryDesc.Transform);
								PassthroughPokeActorMap->Add(MeshName, PassthroughPokeActor);
							}
						}
					}
					else if (GeometryDesc.bUpdateTransform)
					{
						(*FoundPassthroughPokeActor).PokeAHoleComponentPtr->SetWorldTransform(GeometryDesc.Transform);
					}
				}
			}

			// find actors that no longer exist
			TArray<FString> ItemsToRemove;
			for (auto& Entry : *UserDefinedGeometryMap)
			{
				if (!UsedSet.Contains(Entry.Key))
				{
					ItemsToRemove.Add(Entry.Key);
				}
			}

			for (FString Entry : ItemsToRemove)
			{
				FPassthroughPokeActor* PassthroughPokeActor = PassthroughPokeActorMap->Find(Entry);
				if (PassthroughPokeActor)
				{
					UWorld* World = GetWorld();
					if (World)
					{
						World->DestroyActor(PassthroughPokeActor->PokeAHoleActor);
					}
				}
				PassthroughPokeActorMap->Remove(Entry);
			}
		}
	}

	bool FLayer::ShapeNeedsTextures(ovrpShape shape)
	{
		return ((shape != ovrpShape_ReconstructionPassthrough) && (shape != ovrpShape_SurfaceProjectedPassthrough));
	}

	void FLayer::SetEyeLayerDesc(const ovrpLayerDesc_EyeFov& InEyeLayerDesc)
	{
		OvrpLayerDesc.EyeFov = InEyeLayerDesc;

		bHasDepth = InEyeLayerDesc.DepthFormat != ovrpTextureFormat_None;
	}

	TSharedPtr<FLayer, ESPMode::ThreadSafe> FLayer::Clone() const
	{
		return MakeShareable(new FLayer(*this));
	}

	bool FLayer::CanReuseResources(const FLayer* InLayer) const
	{
		if (!InLayer || !InLayer->OvrpLayer.IsValid())
		{
			return false;
		}

		if (OvrpLayerDesc.Shape != InLayer->OvrpLayerDesc.Shape || OvrpLayerDesc.Layout != InLayer->OvrpLayerDesc.Layout || OvrpLayerDesc.TextureSize.w != InLayer->OvrpLayerDesc.TextureSize.w || OvrpLayerDesc.TextureSize.h != InLayer->OvrpLayerDesc.TextureSize.h || OvrpLayerDesc.MipLevels != InLayer->OvrpLayerDesc.MipLevels || OvrpLayerDesc.SampleCount != InLayer->OvrpLayerDesc.SampleCount || OvrpLayerDesc.Format != InLayer->OvrpLayerDesc.Format || OvrpLayerDesc.LayerFlags != InLayer->OvrpLayerDesc.LayerFlags || bNeedsTexSrgbCreate != InLayer->bNeedsTexSrgbCreate)
		{
			return false;
		}

		if (OvrpLayerDesc.Shape == ovrpShape_EyeFov)
		{
			if (OvrpLayerDesc.EyeFov.DepthFormat != InLayer->OvrpLayerDesc.EyeFov.DepthFormat || OvrpLayerDesc.EyeFov.MotionVectorDepthFormat != InLayer->OvrpLayerDesc.EyeFov.MotionVectorDepthFormat || OvrpLayerDesc.EyeFov.MotionVectorFormat != InLayer->OvrpLayerDesc.EyeFov.MotionVectorFormat || OvrpLayerDesc.EyeFov.MotionVectorTextureSize.w != InLayer->OvrpLayerDesc.EyeFov.MotionVectorTextureSize.w || OvrpLayerDesc.EyeFov.MotionVectorTextureSize.h != InLayer->OvrpLayerDesc.EyeFov.MotionVectorTextureSize.h)
			{
				return false;
			}
		}

		return true;
	}

	bool FLayer::Initialize_RenderThread(const FSettings* Settings, FCustomPresent* CustomPresent, FDeferredDeletionQueue* DeferredDeletion, FRHICommandListImmediate& RHICmdList, const FLayer* InLayer)
	{
		CheckInRenderThread();

		if (Id == 0)
		{
			// OvrpLayerDesc and OvrpViewportRects already initialized, as this is the eyeFOV layer. The only necessary modification is to take into account MSAA level, that can only be accurately determined on the RT.
		}
		else
		{
			bInvertY = (CustomPresent->GetLayerFlags() & ovrpLayerFlag_TextureOriginAtBottomLeft) != 0;

			uint32 SizeX = 0, SizeY = 0;

			if (Desc.Texture.IsValid())
			{
				FRHITexture2D* Texture2D = Desc.Texture->GetTexture2D();
				FRHITextureCube* TextureCube = Desc.Texture->GetTextureCube();

				if (Texture2D)
				{
					SizeX = Texture2D->GetSizeX();
					SizeY = Texture2D->GetSizeY();
				}
				else if (TextureCube)
				{
					SizeX = SizeY = TextureCube->GetSize();
				}
			}
			else
			{
				SizeX = Desc.LayerSize.X;
				SizeY = Desc.LayerSize.Y;
			}

			ovrpShape Shape;

			if (Desc.HasShape<FQuadLayer>())
			{
				Shape = ovrpShape_Quad;
			}
			else if (Desc.HasShape<FCylinderLayer>())
			{
				Shape = ovrpShape_Cylinder;
			}
			else if (Desc.HasShape<FCubemapLayer>())
			{
				Shape = ovrpShape_Cubemap;
			}
			else if (Desc.HasShape<FEquirectLayer>())
			{
				Shape = ovrpShape_Equirect;
			}
			else if (Desc.HasShape<FReconstructedLayer>())
			{
				Shape = ovrpShape_ReconstructionPassthrough;
			}
			else if (Desc.HasShape<FUserDefinedLayer>())
			{
				Shape = ovrpShape_SurfaceProjectedPassthrough;
			}
			else
			{
				return false;
			}

			if (ShapeNeedsTextures(Shape) && (SizeX == 0 || SizeY == 0))
			{
				return false;
			}

			EPixelFormat Format = Desc.Texture.IsValid() ? CustomPresent->GetPixelFormat(Desc.Texture->GetFormat()) : CustomPresent->GetDefaultPixelFormat();
#if PLATFORM_ANDROID
			uint32 NumMips = Desc.Texture.IsValid() ? Desc.Texture->GetNumMips() : 1;
#else
			uint32 NumMips = 0;
#endif
			uint32 NumSamples = 1;
			int LayerFlags = CustomPresent->GetLayerFlags();

			if (!(Desc.Flags & IStereoLayers::LAYER_FLAG_TEX_CONTINUOUS_UPDATE))
			{
				LayerFlags |= ovrpLayerFlag_Static;
			}

			// AdditionalFlags introduced in UE5.4
			int TempLayerFlags = FOculusXRStereoLayersFlagsSupplier::Get()->GetOvrpFlag(Desc.Flags, false);

#ifdef WITH_OCULUS_BRANCH
			if (Desc.Flags & IStereoLayers::LAYER_FLAG_BICUBIC_FILTERING)
			{
				TempLayerFlags |= ovrpLayerFlag_BicubicFiltering;
			}
#endif
			if (TempLayerFlags)
			{
				if (ShapeNeedsTextures(OvrpLayerDesc.Shape))
				{
					LayerFlags |= TempLayerFlags;
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Bicubic filter should not be applied to layers without textures, like Passthrough layers."));
				}
			}
			// Calculate layer desc
			FOculusXRHMDModule::GetPluginWrapper().CalculateLayerDesc(
				Shape,
				!Desc.LeftTexture.IsValid() ? ovrpLayout_Mono : ovrpLayout_Stereo,
				ovrpSizei{ (int)SizeX, (int)SizeY },
				NumMips,
				NumSamples,
				CustomPresent->GetOvrpTextureFormat(Format),
				LayerFlags,
				&OvrpLayerDesc);

			// Calculate viewport rect
			for (uint32 EyeIndex = 0; EyeIndex < ovrpEye_Count; EyeIndex++)
			{
				ovrpRecti& ViewportRect = OvrpLayerSubmit.ViewportRect[EyeIndex];
				ViewportRect.Pos.x = (int)(Desc.UVRect.Min.X * SizeX + 0.5f);
				ViewportRect.Pos.y = (int)(Desc.UVRect.Min.Y * SizeY + 0.5f);
				ViewportRect.Size.w = (int)(Desc.UVRect.Max.X * SizeX + 0.5f) - ViewportRect.Pos.x;
				ViewportRect.Size.h = (int)(Desc.UVRect.Max.Y * SizeY + 0.5f) - ViewportRect.Pos.y;
			}
		}

		// Reuse/Create texture set
		if (CanReuseResources(InLayer))
		{
			OvrpLayerId = InLayer->OvrpLayerId;
			OvrpLayer = InLayer->OvrpLayer;
			SwapChain = InLayer->SwapChain;
			DepthSwapChain = InLayer->DepthSwapChain;
			FoveationSwapChain = InLayer->FoveationSwapChain;
			RightSwapChain = InLayer->RightSwapChain;
			RightDepthSwapChain = InLayer->RightDepthSwapChain;
			MotionVectorSwapChain = InLayer->MotionVectorSwapChain;
			MotionVectorDepthSwapChain = InLayer->MotionVectorDepthSwapChain;
			InvAlphaTexture = InLayer->InvAlphaTexture;
			bUpdateTexture = InLayer->bUpdateTexture;
			bNeedsTexSrgbCreate = InLayer->bNeedsTexSrgbCreate;
			UserDefinedGeometryMap = InLayer->UserDefinedGeometryMap;
		}
		else
		{
			bool bLayerCreated = false;
			bool bValidFoveationTextures = true;
			TArray<ovrpTextureHandle> ColorTextures;
			TArray<ovrpTextureHandle> DepthTextures;
			TArray<ovrpTextureHandle> FoveationTextures;
			TArray<ovrpTextureHandle> RightColorTextures;
			TArray<ovrpTextureHandle> RightDepthTextures;
			ovrpSizei FoveationTextureSize;

			bool bValidMotionVectorTextures = false;
			TArray<ovrpTextureHandle> MotionVectorTextures;
			ovrpSizei MotionVectorTextureSize;
			TArray<ovrpTextureHandle> MotionVectorDepthTextures;
			ovrpSizei MotionVectorDepthTextureSize;

			ExecuteOnRHIThread([&]() {
				// UNDONE Do this in RenderThread once OVRPlugin allows FOculusXRHMDModule::GetPluginWrapper().SetupLayer to be called asynchronously
				int32 TextureCount;
				if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().SetupLayer(CustomPresent->GetOvrpDevice(), OvrpLayerDesc.Base, (int*)&OvrpLayerId)) && OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetLayerTextureStageCount(OvrpLayerId, &TextureCount)))
				{
					if (ShapeNeedsTextures(OvrpLayerDesc.Shape))
					{
						// Left
						{
							ColorTextures.SetNum(TextureCount);
							if (bHasDepth)
							{
								DepthTextures.SetNum(TextureCount);
							}

							FoveationTextures.SetNum(TextureCount);
							FoveationTextureSize.w = 0;
							FoveationTextureSize.h = 0;

							MotionVectorTextures.SetNum(TextureCount);
							MotionVectorTextureSize.w = 0;
							MotionVectorTextureSize.h = 0;
							MotionVectorDepthTextures.SetNum(TextureCount);
							MotionVectorDepthTextureSize.w = 0;
							MotionVectorDepthTextureSize.h = 0;

							bValidMotionVectorTextures = ((OvrpLayerDesc.LayerFlags & ovrpLayerFlag_SpaceWarpDataAllocation) > 0) && (OvrpLayerDesc.Shape == ovrpShape_EyeFov);
							for (int32 TextureIndex = 0; TextureIndex < TextureCount; TextureIndex++)
							{
								ovrpTextureHandle* DepthTexHdlPtr = bHasDepth ? &DepthTextures[TextureIndex] : nullptr;
								if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetLayerTexture2(OvrpLayerId, TextureIndex, ovrpEye_Left, &ColorTextures[TextureIndex], DepthTexHdlPtr)))
								{
									UE_LOG(LogHMD, Error, TEXT("Failed to create Oculus layer texture. NOTE: This causes a leak of %d other texture(s), which will go unused."), TextureIndex);
									// skip setting bLayerCreated and allocating any other textures
									return;
								}
								if (bValidFoveationTextures)
								{
									// Call fails on unsupported platforms and returns null textures for no foveation texture
									// Since this texture is not required for rendering, don't return on failure
									if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetLayerTextureFoveation(OvrpLayerId, TextureIndex, ovrpEye_Left, &FoveationTextures[TextureIndex], &FoveationTextureSize)) || FoveationTextures[TextureIndex] == (unsigned long long)nullptr)
									{
										bValidFoveationTextures = false;
									}
								}

								if (bValidMotionVectorTextures)
								{
									// Call fails on unsupported platforms and returns null textures for no motion vector texture
									// Since this texture is not required for rendering, don't return on failure

									if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetLayerTextureSpaceWarp(OvrpLayerId, TextureIndex, ovrpEye_Left, &MotionVectorTextures[TextureIndex], &MotionVectorTextureSize, &MotionVectorDepthTextures[TextureIndex], &MotionVectorDepthTextureSize)) || MotionVectorTextures[TextureIndex] == (unsigned long long)nullptr)
									{
										bValidMotionVectorTextures = false;
										UE_LOG(LogHMD, Error, TEXT("[Mobile SpaceWarp] Space Warpovrp_GetLayerTextureMotionVector failed"));
									}
								}
							}
						}

						// Right
						if (OvrpLayerDesc.Layout == ovrpLayout_Stereo)
						{
							RightColorTextures.SetNum(TextureCount);
							if (bHasDepth)
							{
								RightDepthTextures.SetNum(TextureCount);
							}

							for (int32 TextureIndex = 0; TextureIndex < TextureCount; TextureIndex++)
							{
								ovrpTextureHandle* DepthTexHdlPtr = bHasDepth ? &RightDepthTextures[TextureIndex] : nullptr;
								if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetLayerTexture2(OvrpLayerId, TextureIndex, ovrpEye_Right, &RightColorTextures[TextureIndex], DepthTexHdlPtr)))
								{
									UE_LOG(LogHMD, Error, TEXT("Failed to create Oculus layer texture. NOTE: This causes a leak of %d other texture(s), which will go unused."), TextureCount + TextureIndex);
									// skip setting bLayerCreated and allocating any other textures
									return;
								}
							}
						}
					}
					else
					{
						bValidFoveationTextures = false;
					}

					bLayerCreated = true;
				}
			});

			if (bLayerCreated)
			{
				OvrpLayer = MakeShareable<FOvrpLayer>(new FOvrpLayer(OvrpLayerId, DeferredDeletion));

				if (ShapeNeedsTextures(OvrpLayerDesc.Shape))
				{
					uint32 SizeX = OvrpLayerDesc.TextureSize.w;
					uint32 SizeY = OvrpLayerDesc.TextureSize.h;
					EPixelFormat ColorFormat = CustomPresent->GetPixelFormat(OvrpLayerDesc.Format);
					EPixelFormat DepthFormat = PF_DepthStencil;
					uint32 NumMips = OvrpLayerDesc.MipLevels;
					uint32 NumSamples = OvrpLayerDesc.SampleCount;
					uint32 NumSamplesTileMem = 1;
					if (OvrpLayerDesc.Shape == ovrpShape_EyeFov)
					{
						static const auto CVarMobileMSAA = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.MobileMSAA"));
						NumSamplesTileMem = (CVarMobileMSAA ? CVarMobileMSAA->GetValueOnAnyThread() : 1);
					}

					ERHIResourceType ResourceType;
					if (OvrpLayerDesc.Shape == ovrpShape_Cubemap || OvrpLayerDesc.Shape == ovrpShape_OffcenterCubemap)
					{
						ResourceType = RRT_TextureCube;
					}
					else if (OvrpLayerDesc.Layout == ovrpLayout_Array)
					{
						ResourceType = RRT_Texture2DArray;
					}
					else
					{
						ResourceType = RRT_Texture2D;
					}

					const bool bNeedsSRGBFlag = bNeedsTexSrgbCreate || CustomPresent->IsSRGB(OvrpLayerDesc.Format);

					ETextureCreateFlags ColorTexCreateFlags = TexCreate_ShaderResource | TexCreate_RenderTargetable | TexCreate_ResolveTargetable | (bNeedsSRGBFlag ? TexCreate_SRGB : TexCreate_None);
					ETextureCreateFlags DepthTexCreateFlags = TexCreate_ShaderResource | TexCreate_DepthStencilTargetable | TexCreate_InputAttachmentRead | (bSupportDepthComposite ? TexCreate_ResolveTargetable : TexCreate_None);

					if (Desc.Texture.IsValid())
					{
						ColorTexCreateFlags |= (Desc.Texture->GetFlags() & TexCreate_SRGB);
					}

					FClearValueBinding ColorTextureBinding;
					FClearValueBinding DepthTextureBinding = FClearValueBinding::DepthFar;
					if (OvrpLayerDesc.Shape == ovrpShape_EyeFov)
					{
						ColorTextureBinding = FClearValueBinding::Black;
					}

					SwapChain = CustomPresent->CreateSwapChain_RenderThread(SizeX, SizeY, ColorFormat, ColorTextureBinding, NumMips, NumSamples, NumSamplesTileMem, ResourceType, ColorTextures, ColorTexCreateFlags, *FString::Printf(TEXT("Oculus Color Swapchain %d"), OvrpLayerId));

#if PLATFORM_WINDOWS
					static const auto CVarPropagateAlpha = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.PostProcessing.PropagateAlpha"));
					const EAlphaChannelMode::Type PropagateAlpha = EAlphaChannelMode::FromInt(CVarPropagateAlpha->GetValueOnRenderThread());
					if (PropagateAlpha == EAlphaChannelMode::AllowThroughTonemapper)
					{
						const ETextureCreateFlags InvTextureCreateFlags = TexCreate_ShaderResource | TexCreate_RenderTargetable;
						FRHITextureCreateDesc InvTextureDesc{};
						if (OvrpLayerDesc.Layout == ovrpLayout_Array)
						{
							InvTextureDesc = FRHITextureCreateDesc::Create2DArray(TEXT("InvAlphaTexture"))
												 .SetArraySize(2)
												 .SetExtent(SizeX, SizeY)
												 .SetFormat(ColorFormat)
												 .SetNumMips(NumMips)
												 .SetNumSamples(NumSamples)
												 .SetFlags(InvTextureCreateFlags | TexCreate_TargetArraySlicesIndependently)
												 .SetClearValue(ColorTextureBinding);
						}
						else
						{
							InvTextureDesc = FRHITextureCreateDesc::Create2D(TEXT("InvAlphaTexture"))
												 .SetExtent(SizeX, SizeY)
												 .SetFormat(ColorFormat)
												 .SetNumMips(NumMips)
												 .SetNumSamples(NumSamples)
												 .SetFlags(InvTextureCreateFlags)
												 .SetClearValue(ColorTextureBinding);
						}
						InvAlphaTexture = RHICreateTexture(InvTextureDesc);
					}
#endif

					if (bHasDepth)
					{
						DepthSwapChain = CustomPresent->CreateSwapChain_RenderThread(SizeX, SizeY, DepthFormat, DepthTextureBinding, 1, NumSamples, NumSamplesTileMem, ResourceType, DepthTextures, DepthTexCreateFlags, *FString::Printf(TEXT("Oculus Depth Swapchain %d"), OvrpLayerId));
					}
					if (bValidFoveationTextures)
					{
						FoveationSwapChain = CustomPresent->CreateSwapChain_RenderThread(FoveationTextureSize.w, FoveationTextureSize.h, PF_R8G8, FClearValueBinding::White, 1, 1, 1, ResourceType, FoveationTextures, TexCreate_Foveation, *FString::Printf(TEXT("Oculus Foveation Swapchain %d"), OvrpLayerId));
					}
					else
					{
						FoveationSwapChain.Reset();
					}

					if (bValidMotionVectorTextures)
					{
						EPixelFormat MvPixelFormat = PF_FloatRGBA;
						ETextureCreateFlags MVTexCreateFlags = TexCreate_ShaderResource | TexCreate_RenderTargetable;
						MotionVectorSwapChain = CustomPresent->CreateSwapChain_RenderThread(MotionVectorTextureSize.w, MotionVectorTextureSize.h, MvPixelFormat, FClearValueBinding::Black, 1, 1, 1, ResourceType, MotionVectorTextures, MVTexCreateFlags, *FString::Printf(TEXT("Oculus MV Swapchain %d"), OvrpLayerId));
						if (MotionVectorDepthTextures.Num() && MotionVectorDepthTextures[0] != (unsigned long long)nullptr)
						{
							ETextureCreateFlags MVDepthTexCreateFlags = TexCreate_ShaderResource | TexCreate_DepthStencilTargetable;
							MotionVectorDepthSwapChain = CustomPresent->CreateSwapChain_RenderThread(MotionVectorDepthTextureSize.w, MotionVectorDepthTextureSize.h, PF_DepthStencil, FClearValueBinding::Black, 1, 1, 1, ResourceType, MotionVectorDepthTextures, MVDepthTexCreateFlags, *FString::Printf(TEXT("Oculus MV Depth Swapchain %d"), OvrpLayerId));
						}
						else
						{
							MotionVectorDepthSwapChain = nullptr;
						}
					}
					else
					{
						MotionVectorSwapChain.Reset();
						MotionVectorDepthSwapChain.Reset();
					}

					if (OvrpLayerDesc.Layout == ovrpLayout_Stereo)
					{
						RightSwapChain = CustomPresent->CreateSwapChain_RenderThread(SizeX, SizeY, ColorFormat, ColorTextureBinding, NumMips, NumSamples, NumSamplesTileMem, ResourceType, RightColorTextures, ColorTexCreateFlags, *FString::Printf(TEXT("Oculus Right Color Swapchain %d"), OvrpLayerId));

						if (bHasDepth)
						{
							RightDepthSwapChain = CustomPresent->CreateSwapChain_RenderThread(SizeX, SizeY, DepthFormat, DepthTextureBinding, 1, NumSamples, NumSamplesTileMem, ResourceType, RightDepthTextures, DepthTexCreateFlags, *FString::Printf(TEXT("Oculus Right Depth Swapchain %d"), OvrpLayerId));
						}
					}

					bUpdateTexture = true;
				}
				else
				{
					SwapChain.Reset();
					DepthSwapChain.Reset();
					FoveationSwapChain.Reset();
					RightSwapChain.Reset();
					RightDepthSwapChain.Reset();
					if (UserDefinedGeometryMap)
					{
						UserDefinedGeometryMap->Reset();
					}
				}
			}
			else
			{
				return false;
			}
		}

		if ((Desc.Flags & IStereoLayers::LAYER_FLAG_TEX_CONTINUOUS_UPDATE) && Desc.Texture.IsValid() && IsVisible())
		{
			bUpdateTexture = true;
		}

		return true;
	}

	void FLayer::UpdatePassthroughStyle_RenderThread(const FEdgeStyleParameters& EdgeStyleParameters)
	{
		ovrpInsightPassthroughStyle Style;
		Style.EdgeColor = ovrpColorf{ 0, 0, 0, 0 };
		Style.TextureOpacityFactor = EdgeStyleParameters.TextureOpacityFactor;
		Style.Flags = (ovrpInsightPassthroughStyleFlags)(ovrpInsightPassthroughStyleFlags_HasTextureOpacityFactor
			| ovrpInsightPassthroughStyleFlags_HasEdgeColor
			| ovrpInsightPassthroughStyleFlags_HasTextureColorMap);
		Style.TextureColorMapType = ovrpInsightPassthroughColorMapType_None;
		Style.TextureColorMapData = nullptr;
		Style.TextureColorMapDataSize = 0;
		Style.LutWeight = 0;
		Style.LutSource = 0;
		Style.LutTarget = 0;

		if (EdgeStyleParameters.bEnableEdgeColor)
		{
			Style.EdgeColor = ToOvrpColorf(EdgeStyleParameters.EdgeColor);
		}

		if (EdgeStyleParameters.bEnableColorMap)
		{
			Style.TextureColorMapType = ToOVRPColorMapType(EdgeStyleParameters.ColorMapType);
			Style.TextureColorMapData = (uint8*)EdgeStyleParameters.ColorMapData.GetData();
			Style.TextureColorMapDataSize = EdgeStyleParameters.ColorMapData.Num();
		}

		if (EdgeStyleParameters.bUseColorLuts)
		{
			Style.LutWeight = EdgeStyleParameters.ColorLutDesc.Weight;
			Style.TextureColorMapType = ToOVRPColorMapType(EdgeStyleParameters.ColorMapType);

			if (EdgeStyleParameters.ColorLutDesc.ColorLuts.Num() == 1)
			{
				check(Style.TextureColorMapType == ovrpInsightPassthroughColorMapType_ColorLut);
				Style.LutSource = EdgeStyleParameters.ColorLutDesc.ColorLuts[0];
			}

			if (EdgeStyleParameters.ColorLutDesc.ColorLuts.Num() == 2)
			{
				check(Style.TextureColorMapType == ovrpInsightPassthroughColorMapType_InterpolatedColorLut);
				Style.LutSource = EdgeStyleParameters.ColorLutDesc.ColorLuts[0];
				Style.LutTarget = EdgeStyleParameters.ColorLutDesc.ColorLuts[1];
			}
		}

		if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().SetInsightPassthroughStyle2(OvrpLayerId, &Style)))
		{
			UE_LOG(LogTemp, Error, TEXT("Failed setting passthrough style"));
			return;
		}
	}

	static FMatrix TransformToPassthroughSpace(FTransform Transform, const FGameFrame* Frame)
	{
		const FVector WorldToMetersScaleInv = FVector(Frame->WorldToMetersScale).Reciprocal();
		FTransform TransformWorld = Transform * Frame->TrackingToWorld.Inverse();
		TransformWorld.MultiplyScale3D(WorldToMetersScaleInv);
		TransformWorld.ScaleTranslation(WorldToMetersScaleInv);
		const FMatrix TransformWorldScaled = TransformWorld.ToMatrixWithScale();

		const FMatrix SwapAxisMatrix(
			FPlane(0.0f, 0.0f, -1.0f, 0.0f),
			FPlane(1.0f, 0.0f, 0.0f, 0.0f),
			FPlane(0.0f, 1.0f, 0.0f, 0.0f),
			FPlane(0.0f, 0.0f, 0.0f, 1.0f));

		return TransformWorldScaled * SwapAxisMatrix;
	}

	void FLayer::UpdatePassthrough_RenderThread(FCustomPresent* CustomPresent, FRHICommandListImmediate& RHICmdList, const FGameFrame* Frame)
	{
		CheckInRenderThread();
		if (Desc.HasShape<FReconstructedLayer>())
		{
			const FReconstructedLayer& ReconstructedLayerProps = Desc.GetShape<FReconstructedLayer>();
			UpdatePassthroughStyle_RenderThread(ReconstructedLayerProps.EdgeStyleParameters);
		}
		else if (Desc.HasShape<FUserDefinedLayer>())
		{
			const FUserDefinedLayer& UserDefinedLayerProps = Desc.GetShape<FUserDefinedLayer>();
			UpdatePassthroughStyle_RenderThread(UserDefinedLayerProps.EdgeStyleParameters);
		}

		if (Desc.HasShape<FUserDefinedLayer>())
		{
			const FUserDefinedLayer& UserDefinedLayerProps = Desc.GetShape<FUserDefinedLayer>();
			const TArray<FUserDefinedGeometryDesc>& UserGeometryList = UserDefinedLayerProps.UserGeometryList;
			TSet<FString> UsedSet;

			for (const FUserDefinedGeometryDesc& GeometryDesc : UserGeometryList)
			{
				const FString MeshName = GeometryDesc.MeshName;
				UsedSet.Add(MeshName);

				FPassthroughMesh* LayerPassthroughMesh = UserDefinedGeometryMap->Find(MeshName);
				if (!LayerPassthroughMesh)
				{
					OculusXRHMD::FOculusPassthroughMeshRef GeomPassthroughMesh = GeometryDesc.PassthroughMesh;
					if (GeomPassthroughMesh)
					{
						const FMatrix Transform = TransformToPassthroughSpace(GeometryDesc.Transform, Frame);
						uint64_t MeshHandle = 0;
						uint64_t InstanceHandle = 0;
						AddPassthroughMesh_RenderThread(GeomPassthroughMesh->GetVertices(), GeomPassthroughMesh->GetTriangles(), Transform, MeshHandle, InstanceHandle);
						UserDefinedGeometryMap->Add(MeshName, FPassthroughMesh(MeshHandle, InstanceHandle));
					}
				}
				else
				{
					const FMatrix Transform = TransformToPassthroughSpace(GeometryDesc.Transform, Frame);
					UpdatePassthroughMeshTransform_RenderThread(LayerPassthroughMesh->InstanceHandle, Transform);
				}
			}

			// find meshes that no longer exist
			TArray<FString> ItemsToRemove;
			for (auto& Entry : *UserDefinedGeometryMap)
			{
				if (!UsedSet.Contains(Entry.Key))
				{
					ItemsToRemove.Add(Entry.Key);
				}
			}

			for (FString Entry : ItemsToRemove)
			{
				FPassthroughMesh* PassthroughMesh = UserDefinedGeometryMap->Find(Entry);
				if (PassthroughMesh)
				{
					const uint64_t MeshHandle = PassthroughMesh->MeshHandle;
					const uint64_t InstanceHandle = PassthroughMesh->InstanceHandle;
					RemovePassthroughMesh_RenderThread(MeshHandle, InstanceHandle);
				}
				else
				{
					UE_LOG(LogTemp, Error, TEXT("PassthroughMesh: %s doesn't exist."), *Entry);
					return;
				}

				UserDefinedGeometryMap->Remove(Entry);
			}
		}
	}

	static void InvertTextureAlpha_RenderThread(FCustomPresent* CustomPresent, FRHICommandListImmediate& RHICmdList, FRHITexture* Texture, FRHITexture* TempTexture, const FIntRect& ViewportRect)
	{
		{
			FRHITexture* SrcTexture = Texture;
			FRHITexture* DstTexture = TempTexture;
			const FIntRect SrcRect(ViewportRect);
			const FIntRect DstRect(0, 0, ViewportRect.Size().X, ViewportRect.Size().Y);

			const bool bAlphaPremultiply = false;
			const bool bNoAlphaWrite = false;
			const bool bInvertSrcY = false;
			const bool sRGBSource = false;
			const bool bInvertAlpha = true;

			CustomPresent->CopyTexture_RenderThread(RHICmdList, DstTexture, SrcTexture, DstRect, SrcRect, bAlphaPremultiply, bNoAlphaWrite, bInvertSrcY, sRGBSource, bInvertAlpha);
		}

		{
			FRHICopyTextureInfo CopyInfo;
			CopyInfo.Size = FIntVector(ViewportRect.Size().X, ViewportRect.Size().Y, 1);
			CopyInfo.SourcePosition = FIntVector::ZeroValue;
			CopyInfo.DestPosition = FIntVector(ViewportRect.Min.X, ViewportRect.Min.Y, 0);
			CopyInfo.SourceSliceIndex = 0;
			CopyInfo.DestSliceIndex = 0;

			if (Texture->GetDesc().IsTextureArray() && TempTexture->GetDesc().IsTextureArray())
			{
				CopyInfo.NumSlices = FMath::Min(Texture->GetDesc().ArraySize, TempTexture->GetDesc().ArraySize);
			}

			FRHITexture* SrcTexture = TempTexture;
			FRHITexture* DstTexture = Texture;
			RHICmdList.Transition(FRHITransitionInfo(SrcTexture, ERHIAccess::Unknown, ERHIAccess::CopySrc));
			RHICmdList.Transition(FRHITransitionInfo(DstTexture, ERHIAccess::Unknown, ERHIAccess::CopyDest));
			RHICmdList.CopyTexture(SrcTexture, DstTexture, CopyInfo);
			RHICmdList.Transition(FRHITransitionInfo(DstTexture, ERHIAccess::CopyDest, ERHIAccess::SRVMask));
			RHICmdList.Transition(FRHITransitionInfo(SrcTexture, ERHIAccess::CopySrc, ERHIAccess::SRVMask));
		}
	}

	void FLayer::UpdateTexture_RenderThread(const FSettings* Settings, FCustomPresent* CustomPresent, FRHICommandListImmediate& RHICmdList)
	{
		CheckInRenderThread();

		if (bUpdateTexture && SwapChain.IsValid())
		{
			// Copy textures
			if (Desc.Texture.IsValid())
			{
				bool bAlphaPremultiply = true;
				bool bNoAlphaWrite = (Desc.Flags & IStereoLayers::LAYER_FLAG_TEX_NO_ALPHA_CHANNEL) != 0;

				// Left
				{
					FRHITexture* SrcTexture = Desc.LeftTexture.IsValid() ? Desc.LeftTexture : Desc.Texture;
					FRHITexture* DstTexture = SwapChain->GetTexture();

					const ovrpRecti& OvrpViewportRect = OvrpLayerSubmit.ViewportRect[ovrpEye_Left];
					FIntRect DstRect(OvrpViewportRect.Pos.x, OvrpViewportRect.Pos.y, OvrpViewportRect.Pos.x + OvrpViewportRect.Size.w, OvrpViewportRect.Pos.y + OvrpViewportRect.Size.h);

					CustomPresent->CopyTexture_RenderThread(RHICmdList, DstTexture, SrcTexture, DstRect, FIntRect(), bAlphaPremultiply, bNoAlphaWrite, bInvertY);
				}

				// Right
				if (OvrpLayerDesc.Layout != ovrpLayout_Mono)
				{
					FRHITexture* SrcTexture = Desc.Texture;
					FRHITexture* DstTexture = RightSwapChain.IsValid() ? RightSwapChain->GetTexture() : SwapChain->GetTexture();

					const ovrpRecti& OvrpViewportRect = OvrpLayerSubmit.ViewportRect[ovrpEye_Right];
					FIntRect DstRect(OvrpViewportRect.Pos.x, OvrpViewportRect.Pos.y, OvrpViewportRect.Pos.x + OvrpViewportRect.Size.w, OvrpViewportRect.Pos.y + OvrpViewportRect.Size.h);

					CustomPresent->CopyTexture_RenderThread(RHICmdList, DstTexture, SrcTexture, DstRect, FIntRect(), bAlphaPremultiply, bNoAlphaWrite, bInvertY);
				}

				bUpdateTexture = false;
			}

			// Generate mips
			SwapChain->GenerateMips_RenderThread(RHICmdList);

			if (RightSwapChain.IsValid())
			{
				RightSwapChain->GenerateMips_RenderThread(RHICmdList);
			}
		}

		if (Id == 0 && SwapChain.IsValid() && InvAlphaTexture)
		{
			// Left
			{
				FRHITexture* EyeTexture = SwapChain->GetTexture();
				InvertTextureAlpha_RenderThread(CustomPresent, RHICmdList, EyeTexture, InvAlphaTexture, Settings->EyeRenderViewport[ovrpEye_Left]);
			}

			// Right
			if (OvrpLayerDesc.Layout != ovrpLayout_Mono && OvrpLayerDesc.Layout != ovrpLayout_Array)
			{
				FRHITexture* EyeTexture = RightSwapChain.IsValid() ? RightSwapChain->GetTexture() : SwapChain->GetTexture();
				InvertTextureAlpha_RenderThread(CustomPresent, RHICmdList, EyeTexture, InvAlphaTexture, Settings->EyeRenderViewport[ovrpEye_Right]);
			}
		}
	}

	// Returned how much the tracking space moved from previous frame to current frame.
	// Note: FTransform is following the order of C = A * B,  Apply C means, apply A then Apply B.
	void GetTrackingSpaceDeltaPose(const FSettings* Settings, const FGameFrame* Frame, FTransform& TrackingSpaceDeltaPose)
	{
		// TrackingSpaceDeltaPose: describe the tracking space movement in current tracking space
		TrackingSpaceDeltaPose = Frame->TrackingToWorld * Frame->LastTrackingToWorld.Inverse();

		// However There is a intermediete layer from SettingBasePose, which is acting as a bridge between OVRPlugin Device Space and UE4 Device Space
		// Define: OVRPlugin-Device-FPose: same space with the OvrPlugin returned Pose ( In FPose, not ovrpPose ). FOculusXRHMDModule::GetPluginWrapper().GetNodePoseState3() returned value in this space
		// Define: UE4-Device-FPose:  the space UE4 seeing as device pose space. GetCurrentPose() returned result in this space
		FTransform SettingBasePose = FTransform(Settings->BaseOrientation, Settings->BaseOffset);

		// According context of GetCurrentPose, all OVRPlugin-Device-FPose will be inversed by Settings->BaseOrientation & Settings->BaseOffset
		// before exposing to UE4 as UE4-Device-FPose.  which means  UE4-Device-FPose = OVRPlugin-Device-FPose * FPose(BaseOrientation, BaseOffset ).Inverse()
		// FPose(BaseOrientation, BaseOffset ) is the UE4 device reference frame defined in OVRPlugin Device Space ( In FPose, not ovrpPose ).
		// OVRPlugin-Device-FPose_To_UE4-Device-FPose = FPose(BaseOrientation, BaseOffset ).Inverse()
		// UE4-Device-FPose_To_OVRPlugin-Device-FPose = FPose(BaseOrientation, BaseOffset )

		// Eventually we want a transform in OvrPlugin space (both the input and output data are in OvrPlugin Device Space)
		TrackingSpaceDeltaPose = SettingBasePose.Inverse() * TrackingSpaceDeltaPose * SettingBasePose;
	}

	const ovrpLayerSubmit* FLayer::UpdateLayer_RHIThread(const FSettings* Settings, const FGameFrame* Frame, const int LayerIndex)
	{
		OvrpLayerSubmit.LayerId = OvrpLayerId;
		OvrpLayerSubmit.TextureStage = SwapChain.IsValid() ? SwapChain->GetSwapChainIndex_RHIThread() : 0;

		bool injectColorScale = Id == 0 || Settings->bApplyColorScaleAndOffsetToAllLayers;
		OvrpLayerSubmit.ColorOffset = injectColorScale ? Settings->ColorOffset : ovrpVector4f{ 0, 0, 0, 0 };
		OvrpLayerSubmit.ColorScale = injectColorScale ? Settings->ColorScale : ovrpVector4f{ 1, 1, 1, 1 };

		if (OvrpLayerDesc.Shape == ovrpShape_Equirect)
		{
			const FEquirectLayer& EquirectProps = Desc.GetShape<FEquirectLayer>();

			ovrpTextureRectMatrixf& RectMatrix = OvrpLayerSubmit.TextureRectMatrix;
			ovrpRectf& LeftUVRect = RectMatrix.LeftRect;
			ovrpRectf& RightUVRect = RectMatrix.RightRect;
			LeftUVRect.Pos.x = EquirectProps.LeftUVRect.Min.X;
			LeftUVRect.Pos.y = EquirectProps.LeftUVRect.Min.Y;
			LeftUVRect.Size.w = EquirectProps.LeftUVRect.Max.X - EquirectProps.LeftUVRect.Min.X;
			LeftUVRect.Size.h = EquirectProps.LeftUVRect.Max.Y - EquirectProps.LeftUVRect.Min.Y;
			RightUVRect.Pos.x = EquirectProps.RightUVRect.Min.X;
			RightUVRect.Pos.y = EquirectProps.RightUVRect.Min.Y;
			RightUVRect.Size.w = EquirectProps.RightUVRect.Max.X - EquirectProps.RightUVRect.Min.X;
			RightUVRect.Size.h = EquirectProps.RightUVRect.Max.Y - EquirectProps.RightUVRect.Min.Y;

			ovrpVector4f& LeftScaleBias = RectMatrix.LeftScaleBias;
			LeftScaleBias.x = EquirectProps.LeftScale.X;
			LeftScaleBias.y = EquirectProps.LeftScale.Y;
			LeftScaleBias.z = EquirectProps.LeftBias.X;
			LeftScaleBias.w = EquirectProps.LeftBias.Y;
			ovrpVector4f& RightScaleBias = RectMatrix.RightScaleBias;
			RightScaleBias.x = EquirectProps.RightScale.X;
			RightScaleBias.y = EquirectProps.RightScale.Y;
			RightScaleBias.z = EquirectProps.RightBias.X;
			RightScaleBias.w = EquirectProps.RightBias.Y;

			OvrpLayerSubmit.OverrideTextureRectMatrix = ovrpBool_True;
		}

		if (Id != 0)
		{
			int SizeX = OvrpLayerDesc.TextureSize.w;
			int SizeY = OvrpLayerDesc.TextureSize.h;

			float AspectRatio = SizeX ? (float)SizeY / (float)SizeX : 3.0f / 4.0f;
			FVector LocationScaleInv(Frame->WorldToMetersScale);
			FVector LocationScale = LocationScaleInv.Reciprocal();
			ovrpVector3f Scale = ToOvrpVector3f(Desc.Transform.GetScale3D() * LocationScale);

			switch (OvrpLayerDesc.Shape)
			{
				case ovrpShape_ReconstructionPassthrough:
				{
					float QuadSizeY = (Desc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) ? Desc.QuadSize.X * AspectRatio : Desc.QuadSize.Y;
					OvrpLayerSubmit.Quad.Size = ovrpSizef{ static_cast<float>(Desc.QuadSize.X * Scale.x), static_cast<float>(QuadSizeY * Scale.y) };
				}
				break;

				case ovrpShape_Quad:
				{
					float QuadSizeY = (Desc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) ? Desc.QuadSize.X * AspectRatio : Desc.QuadSize.Y;
					OvrpLayerSubmit.Quad.Size = ovrpSizef{ static_cast<float>(Desc.QuadSize.X * Scale.x), static_cast<float>(QuadSizeY * Scale.y) };
				}
				break;
				case ovrpShape_Cylinder:
				{
					const FCylinderLayer& CylinderProps = Desc.GetShape<FCylinderLayer>();
					float CylinderHeight = (Desc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) ? CylinderProps.OverlayArc * AspectRatio : CylinderProps.Height;
					OvrpLayerSubmit.Cylinder.ArcWidth = CylinderProps.OverlayArc * Scale.x;
					OvrpLayerSubmit.Cylinder.Height = CylinderHeight * Scale.x;
					OvrpLayerSubmit.Cylinder.Radius = CylinderProps.Radius * Scale.x;
				}
				break;
			}

			FQuat BaseOrientation;
			FVector BaseLocation;

			switch (Desc.PositionType)
			{
				case IStereoLayers::WorldLocked:
					BaseOrientation = Frame->TrackingToWorld.GetRotation();
					BaseLocation = Frame->TrackingToWorld.GetTranslation();
					break;

				case IStereoLayers::TrackerLocked:
					BaseOrientation = FQuat::Identity;
					BaseLocation = FVector::ZeroVector;
					break;

				case IStereoLayers::FaceLocked:
					BaseOrientation = FQuat::Identity;
					BaseLocation = FVector::ZeroVector;
					break;
			}

			FTransform PlayerTransform(BaseOrientation, BaseLocation);

			FQuat Orientation = BaseOrientation.Inverse() * Desc.Transform.Rotator().Quaternion();
			FVector Location = PlayerTransform.InverseTransformPosition(Desc.Transform.GetLocation());
			FPose OutLayerPose = FPose(Orientation, Location);
			if (Desc.PositionType != IStereoLayers::FaceLocked)
				ConvertPose_Internal(FPose(Orientation, Location), OutLayerPose, Settings->BaseOrientation.Inverse(), Settings->BaseOrientation.Inverse().RotateVector(-Settings->BaseOffset * LocationScaleInv), 1.0);

			OvrpLayerSubmit.Pose.Orientation = ToOvrpQuatf(OutLayerPose.Orientation);
			OvrpLayerSubmit.Pose.Position = ToOvrpVector3f(OutLayerPose.Position * LocationScale);
			OvrpLayerSubmit.LayerSubmitFlags = 0;

			if (Desc.PositionType == IStereoLayers::FaceLocked)
			{
				OvrpLayerSubmit.LayerSubmitFlags |= ovrpLayerSubmitFlag_HeadLocked;
			}

			if (!(Desc.Flags & IStereoLayers::LAYER_FLAG_SUPPORT_DEPTH))
			{
				OvrpLayerSubmit.LayerSubmitFlags |= ovrpLayerSubmitFlag_NoDepth;
			}

			// AdditionalFlags introduced in UE5.4
			int TempLayerSubmitFlags = FOculusXRStereoLayersFlagsSupplier::Get()->GetOvrpFlag(Desc.Flags);

			// Flags in UE5.3 and below.
			// TODO: This will be deprecated soon (target at UE5.5) and will be removed once it's deprecated.
#ifdef WITH_OCULUS_BRANCH
			if (Desc.Flags & IStereoLayers::LAYER_FLAG_AUTO_FILTERING)
			{
				TempLayerSubmitFlags |= ovrpLayerSubmitFlag_AutoLayerFilter;
			}
			if (Desc.Flags & IStereoLayers::LAYER_FLAG_NORMAL_SUPERSAMPLE)
			{
				TempLayerSubmitFlags |= ovrpLayerSubmitFlag_EfficientSuperSample;
			}
			if (Desc.Flags & IStereoLayers::LAYER_FLAG_QUALITY_SUPERSAMPLE)
			{
				TempLayerSubmitFlags |= ovrpLayerSubmitFlag_ExpensiveSuperSample;
			}
			if (Desc.Flags & IStereoLayers::LAYER_FLAG_NORMAL_SHARPEN)
			{
				TempLayerSubmitFlags |= ovrpLayerSubmitFlag_EfficientSharpen;
			}
			if (Desc.Flags & IStereoLayers::LAYER_FLAG_QUALITY_SHARPEN)
			{
				TempLayerSubmitFlags |= ovrpLayerSubmitFlag_QualitySharpen;
			}
#endif
			if (TempLayerSubmitFlags)
			{
				if (ShapeNeedsTextures(OvrpLayerDesc.Shape))
				{
					OvrpLayerSubmit.LayerSubmitFlags |= TempLayerSubmitFlags;
				}
				else if (Frame->FrameNumber <= 1)
				{
					UE_LOG(LogTemp, Warning, TEXT("Layer filters should not be applied to layers without textures, like Passthrough layers."));
				}
			}
		}
		else
		{
			OvrpLayerSubmit.EyeFov.DepthFar = 0;
			OvrpLayerSubmit.EyeFov.DepthNear = Frame->NearClippingPlane / 100.f; // physical scale is 100UU/meter
			OvrpLayerSubmit.LayerSubmitFlags = ovrpLayerSubmitFlag_ReverseZ;
			OvrpLayerSubmit.ViewportRect[0] = ToOvrpRecti(Settings->EyeRenderViewport[0]);
			OvrpLayerSubmit.ViewportRect[1] = ToOvrpRecti(Settings->EyeRenderViewport[1]);
			OvrpLayerSubmit.EyeFov.Fov[0] = Frame->Fov[0];
			OvrpLayerSubmit.EyeFov.Fov[1] = Frame->Fov[1];

			static const auto CVarOculusEnableSpaceWarpInternal = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.Mobile.Oculus.SpaceWarp.EnableInternal"));
			if (CVarOculusEnableSpaceWarpInternal->GetValueOnAnyThread() != 0)
			{
				OvrpLayerSubmit.LayerSubmitFlags |= ovrpLayerSubmitFlag_SpaceWarp;
				OvrpLayerSubmit.EyeFov.MotionVectorDepthFar = Frame->NearClippingPlane / 100.f;
				OvrpLayerSubmit.EyeFov.MotionVectorDepthNear = INFINITY;
				OvrpLayerSubmit.EyeFov.MotionVectorOffset = ovrpVector4f{ 0.0f, 0.0f, 0.0f, 0.0f };
				OvrpLayerSubmit.EyeFov.MotionVectorScale = ovrpVector4f{ 1.0f, 1.0f, 1.0f, 1.0f };

				FTransform TrackingSpaceDeltaPose;
				GetTrackingSpaceDeltaPose(Settings, Frame, TrackingSpaceDeltaPose);
				OvrpLayerSubmit.EyeFov.AppSpaceDeltaPose.Orientation = ToOvrpQuatf(TrackingSpaceDeltaPose.GetRotation());
				OvrpLayerSubmit.EyeFov.AppSpaceDeltaPose.Position = ToOvrpVector3f(TrackingSpaceDeltaPose.GetLocation() / Frame->WorldToMetersScale);
			}

			ovrpXrApi NativeXrApi;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetNativeXrApiType(&NativeXrApi)) && (NativeXrApi == ovrpXrApi_OpenXR))
			{
				bool bCTXPTEnabled = Settings->SystemSplashBackground == ESystemSplashBackgroundType::Contextual;

#if PLATFORM_WINDOWS
				// Allow CTXPT over Link only if alpha in post processing is enabled
				static const auto CVarPropagateAlpha = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.PostProcessing.PropagateAlpha"));
				const EAlphaChannelMode::Type PropagateAlpha = EAlphaChannelMode::FromInt(CVarPropagateAlpha->GetValueOnRenderThread());
				bCTXPTEnabled &= PropagateAlpha == EAlphaChannelMode::AllowThroughTonemapper;
#endif

				const bool bShouldIgnoreSrcAlpha = (LayerIndex == 0 && !bCTXPTEnabled);

				if (bShouldIgnoreSrcAlpha)
				{
					OvrpLayerSubmit.LayerSubmitFlags |= ovrpLayerSubmitFlag_IgnoreSourceAlpha;
				}
				else if (InvAlphaTexture == nullptr)
				{
					OvrpLayerSubmit.HasBlendFactors = true;
					OvrpLayerSubmit.SrcBlendFactor = ovrpBlendFactorOneMinusSrcAlpha;
					OvrpLayerSubmit.DstBlendFactor = ovrpBlendFactorSrcAlpha;
				}
			}
			else
			{
#if PLATFORM_WINDOWS
				OvrpLayerSubmit.LayerSubmitFlags |= ovrpLayerSubmitFlag_IgnoreSourceAlpha;
#else
				OvrpLayerSubmit.LayerSubmitFlags |= ovrpLayerSubmitFlag_InverseAlpha;
#endif
			}
		}

		return &OvrpLayerSubmit.Base;
	}

	void FLayer::IncrementSwapChainIndex_RHIThread(FCustomPresent* CustomPresent)
	{
		CheckInRHIThread();

		if (SwapChain.IsValid())
		{
			SwapChain->IncrementSwapChainIndex_RHIThread();
		}

		if (DepthSwapChain.IsValid())
		{
			DepthSwapChain->IncrementSwapChainIndex_RHIThread();
		}

		if (FoveationSwapChain.IsValid())
		{
			FoveationSwapChain->IncrementSwapChainIndex_RHIThread();
		}

		if (RightSwapChain.IsValid())
		{
			RightSwapChain->IncrementSwapChainIndex_RHIThread();
		}

		if (RightDepthSwapChain.IsValid())
		{
			RightDepthSwapChain->IncrementSwapChainIndex_RHIThread();
		}

		if (MotionVectorSwapChain.IsValid())
		{
			MotionVectorSwapChain->IncrementSwapChainIndex_RHIThread();
		}

		if (MotionVectorDepthSwapChain.IsValid())
		{
			MotionVectorDepthSwapChain->IncrementSwapChainIndex_RHIThread();
		}
	}

	void FLayer::ReleaseResources_RHIThread()
	{
		CheckInRHIThread();

		OvrpLayerId = 0;
		OvrpLayer.Reset();
		SwapChain.Reset();
		DepthSwapChain.Reset();
		FoveationSwapChain.Reset();
		RightSwapChain.Reset();
		RightDepthSwapChain.Reset();
		MotionVectorSwapChain.Reset();
		MotionVectorDepthSwapChain.Reset();
		bUpdateTexture = false;
	}

	void FLayer::AddPassthroughMesh_RenderThread(const TArray<FVector>& Vertices, const TArray<int32>& Triangles, FMatrix Transformation, uint64_t& OutMeshHandle, uint64_t& OutInstanceHandle)
	{
		CheckInRenderThread();

		uint64_t MeshHandle = 0;
		uint64_t InstanceHandle = 0;

		// Explicit conversion is needed since FVector contains double elements.
		// Converting Vertices.Data() to float* causes issues when memory is parsed.
		TArray<float> VertexData;
		VertexData.SetNumUninitialized(Vertices.Num() * 3);

		size_t i = 0;
		for (const FVector& vertex : Vertices)
		{
			VertexData[i++] = vertex.X;
			VertexData[i++] = vertex.Y;
			VertexData[i++] = vertex.Z;
		}

		if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().CreateInsightTriangleMesh(
				OvrpLayerId,
				VertexData.GetData(),
				Vertices.Num(),
				(int*)Triangles.GetData(),
				Triangles.Num() / 3,
				&MeshHandle)))
		{
			UE_LOG(LogTemp, Error, TEXT("Failed creating passthrough mesh surface."));
			return;
		}

		const ovrpMatrix4f OvrTransformation = ToOvrpMatrix(Transformation);

		if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().AddInsightPassthroughSurfaceGeometry(
				OvrpLayerId,
				MeshHandle,
				OvrTransformation,
				&InstanceHandle)))
		{
			UE_LOG(LogTemp, Error, TEXT("Failed adding passthrough mesh surface to scene."));
			return;
		}
		OutMeshHandle = MeshHandle;
		OutInstanceHandle = InstanceHandle;
	}

	void FLayer::UpdatePassthroughMeshTransform_RenderThread(uint64_t InstanceHandle, FMatrix Transformation)
	{
		CheckInRenderThread();

		const ovrpMatrix4f OvrTransformation = ToOvrpMatrix(Transformation);

		if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().UpdateInsightPassthroughGeometryTransform(
				InstanceHandle,
				OvrTransformation)))
		{
			UE_LOG(LogTemp, Error, TEXT("Failed updating passthrough mesh surface transform."));
			return;
		}
	}

	void FLayer::RemovePassthroughMesh_RenderThread(uint64_t MeshHandle, uint64_t InstanceHandle)
	{
		CheckInRenderThread();

		if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().DestroyInsightPassthroughGeometryInstance(InstanceHandle)))
		{
			UE_LOG(LogTemp, Error, TEXT("Failed removing passthrough surface from scene."));
			return;
		}

		if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().DestroyInsightTriangleMesh(MeshHandle)))
		{
			UE_LOG(LogTemp, Error, TEXT("Failed destroying passthrough surface mesh."));
			return;
		}
	}

	void FLayer::DestroyLayer()
	{
		CheckInGameThread();

		if (PassthroughPokeActorMap)
		{
			UWorld* World = GetWorld();
			if (!World)
			{
				return;
			}

			for (auto& Entry : *PassthroughPokeActorMap)
			{
				World->DestroyActor(Entry.Value.PokeAHoleActor);
			}
			PassthroughPokeActorMap.Reset();
		}
	}

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
