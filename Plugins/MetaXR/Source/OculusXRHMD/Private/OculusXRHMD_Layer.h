// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OculusXRHMDPrivate.h"
#include "ProceduralMeshComponent.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS
#include "OculusXRHMD_CustomPresent.h"
#include "XRSwapChain.h"
#include "OculusXRPassthroughLayerShapes.h"

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// FOvrpLayer
	//-------------------------------------------------------------------------------------------------
	class FDeferredDeletionQueue;

	class FOvrpLayer : public TSharedFromThis<FOvrpLayer, ESPMode::ThreadSafe>
	{
	public:
		FOvrpLayer(uint32 InOvrpLayerId, FDeferredDeletionQueue* InDeferredDeletion);
		~FOvrpLayer();

	protected:
		uint32 OvrpLayerId;

	private:
		FDeferredDeletionQueue* DeferredDeletion; // necessary for deferred deletion queue of the actual OvrpLayer
	};

	typedef TSharedPtr<FOvrpLayer, ESPMode::ThreadSafe> FOvrpLayerPtr;

	//-------------------------------------------------------------------------------------------------
	// FLayer
	//-------------------------------------------------------------------------------------------------

	class FLayer : public TSharedFromThis<FLayer, ESPMode::ThreadSafe>
	{
	public:
		FLayer(uint32 InId);
		FLayer(const FLayer& InLayer);
		~FLayer();

		uint32 GetId() const { return Id; }
		int GetOvrpId() const { return OvrpLayerId; }
		void SetDesc(const IStereoLayers::FLayerDesc& InDesc);
		void SetDesc(const FSettings* Settings, const IStereoLayers::FLayerDesc& InDesc);
		const IStereoLayers::FLayerDesc& GetDesc() const { return Desc; }
		void SetEyeLayerDesc(const ovrpLayerDesc_EyeFov& InEyeLayerDesc);
		const FXRSwapChainPtr& GetSwapChain() const { return SwapChain; }
		const FXRSwapChainPtr& GetRightSwapChain() const { return RightSwapChain; }
		const FXRSwapChainPtr& GetDepthSwapChain() const { return DepthSwapChain; }
		const FXRSwapChainPtr& GetFoveationSwapChain() const { return FoveationSwapChain; }
		const FXRSwapChainPtr& GetMotionVectorSwapChain() const { return MotionVectorSwapChain; }
		const FXRSwapChainPtr& GetMotionVectorDepthSwapChain() const { return MotionVectorDepthSwapChain; }
		void MarkTextureForUpdate() { bUpdateTexture = true; }
		bool NeedsPokeAHole();
		void HandlePokeAHoleComponent();
		void BuildPokeAHoleMesh(TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector2D>& UV0);
		bool NeedsPassthroughPokeAHole();

		bool ShapeNeedsTextures(ovrpShape shape);

		FTextureRHIRef GetTexture() { return Desc.Texture; }

		TSharedPtr<FLayer, ESPMode::ThreadSafe> Clone() const;

		bool CanReuseResources(const FLayer* InLayer) const;
		bool Initialize_RenderThread(const FSettings* Settings, FCustomPresent* CustomPresent, FDeferredDeletionQueue* DeferredDeletion, FRHICommandListImmediate& RHICmdList, const FLayer* InLayer = nullptr);
		void UpdateTexture_RenderThread(const FSettings* Settings, FCustomPresent* CustomPresent, FRHICommandListImmediate& RHICmdList);
		void UpdatePassthrough_RenderThread(FCustomPresent* CustomPresent, FRHICommandListImmediate& RHICmdList, const FGameFrame* Frame);

		const ovrpLayerSubmit* UpdateLayer_RHIThread(const FSettings* Settings, const FGameFrame* Frame, const int LayerIndex);
		void IncrementSwapChainIndex_RHIThread(FCustomPresent* CustomPresent);
		void ReleaseResources_RHIThread();
		bool IsVisible() { return (Desc.Flags & IStereoLayers::LAYER_FLAG_HIDDEN) == 0; }

		bool bNeedsTexSrgbCreate;

		void AddPassthroughMesh_RenderThread(const TArray<FVector>& Vertices, const TArray<int32>& Triangles, FMatrix Transformation, uint64_t& OutMeshHandle, uint64_t& OutInstanceHandle);
		void UpdatePassthroughMeshTransform_RenderThread(uint64_t InstanceHandle, FMatrix Transformation);
		void RemovePassthroughMesh_RenderThread(uint64_t MeshHandle, uint64_t InstanceHandle);

		void DestroyLayer();

	protected:
		struct FPassthroughMesh
		{
			FPassthroughMesh(uint64_t MeshHandle, uint64_t InstanceHandle)
				: MeshHandle(MeshHandle)
				, InstanceHandle(InstanceHandle)
			{
			}
			uint64_t MeshHandle;
			uint64_t InstanceHandle;
		};

		typedef TSharedPtr<TMap<FString, FPassthroughMesh>, ESPMode::ThreadSafe> FUserDefinedGeometryMapPtr;

		void UpdatePassthroughStyle_RenderThread(const FEdgeStyleParameters& EdgeStyleParameters);

		struct FPassthroughPokeActor
		{
			FPassthroughPokeActor(){};
			FPassthroughPokeActor(UProceduralMeshComponent* PokeAHoleComponentPtr, AActor* PokeAHoleActor)
				: PokeAHoleComponentPtr(PokeAHoleComponentPtr)
				, PokeAHoleActor(PokeAHoleActor){};
			UProceduralMeshComponent* PokeAHoleComponentPtr;
			AActor* PokeAHoleActor;
		};

		typedef TSharedPtr<TMap<FString, FPassthroughPokeActor>, ESPMode::ThreadSafe> FPassthroughPokeActorMapPtr;

		bool BuildPassthroughPokeActor(FOculusPassthroughMeshRef PassthroughMesh, FPassthroughPokeActor& OutPassthroughPokeActor);
		void UpdatePassthroughPokeActors_GameThread();

		uint32 Id;
		IStereoLayers::FLayerDesc Desc;
		int OvrpLayerId;
		ovrpLayerDescUnion OvrpLayerDesc;
		ovrpLayerSubmitUnion OvrpLayerSubmit;
		FOvrpLayerPtr OvrpLayer;
		FXRSwapChainPtr SwapChain;
		FXRSwapChainPtr DepthSwapChain;
		FXRSwapChainPtr FoveationSwapChain;
		FXRSwapChainPtr RightSwapChain;
		FXRSwapChainPtr RightDepthSwapChain;
		FXRSwapChainPtr MotionVectorSwapChain;
		FXRSwapChainPtr MotionVectorDepthSwapChain;
		FTextureRHIRef InvAlphaTexture;
		bool bUpdateTexture;
		bool bInvertY;
		bool bHasDepth;
		bool bSupportDepthComposite;

		UProceduralMeshComponent* PokeAHoleComponentPtr;
		AActor* PokeAHoleActor;

		FUserDefinedGeometryMapPtr UserDefinedGeometryMap;
		FPassthroughPokeActorMapPtr PassthroughPokeActorMap;
	};

	typedef TSharedPtr<FLayer, ESPMode::ThreadSafe> FLayerPtr;

	//-------------------------------------------------------------------------------------------------
	// FLayerPtr_CompareId
	//-------------------------------------------------------------------------------------------------

	struct FLayerPtr_CompareId
	{
		FORCEINLINE bool operator()(const FLayerPtr& A, const FLayerPtr& B) const
		{
			return A->GetId() < B->GetId();
		}
	};

	//-------------------------------------------------------------------------------------------------
	// FLayerPtr_ComparePriority
	//-------------------------------------------------------------------------------------------------

	struct FLayerPtr_ComparePriority
	{
		FORCEINLINE bool operator()(const FLayerPtr& A, const FLayerPtr& B) const
		{
			if (A->GetDesc().Priority < B->GetDesc().Priority)
				return true;
			if (A->GetDesc().Priority > B->GetDesc().Priority)
				return false;

			return A->GetId() < B->GetId();
		}
	};

	struct FLayerPtr_CompareTotal
	{
		FORCEINLINE int32 GetLayerTypePriority(const FLayerPtr& A) const
		{
			// Draw FReconstructedLayer, PoleAHole layers (Android only), EyeFov layer, followed by other layers
			const bool IsEyeFov = (A->GetId() == 0);
			const bool IsPokeAHole = A->NeedsPokeAHole() || A->NeedsPassthroughPokeAHole();
			bool IsUnderlay = false;

			if (A->GetDesc().HasShape<FReconstructedLayer>())
			{
				const FReconstructedLayer& ReconstructedLayerProps = A->GetDesc().GetShape<FReconstructedLayer>();
				IsUnderlay = (ReconstructedLayerProps.PassthroughLayerOrder == PassthroughLayerOrder_Underlay);
			}
			else if (A->GetDesc().HasShape<FUserDefinedLayer>())
			{
				const FUserDefinedLayer& UserDefinedLayerProps = A->GetDesc().GetShape<FUserDefinedLayer>();
				IsUnderlay = (UserDefinedLayerProps.PassthroughLayerOrder == PassthroughLayerOrder_Underlay);
			}

			const int32 Priority = IsUnderlay ? -2 : IsPokeAHole ? -1
				: IsEyeFov										 ? 0
																 : 1;
			return Priority;
		}

		FORCEINLINE bool operator()(const FLayerPtr& A, const FLayerPtr& B) const
		{
			// First order layers by type
			int32 PassA = GetLayerTypePriority(A);
			int32 PassB = GetLayerTypePriority(B);

			if (PassA != PassB)
				return PassA < PassB;

			// Draw non-FaceLocked layers first
			const IStereoLayers::FLayerDesc& DescA = A->GetDesc();
			const IStereoLayers::FLayerDesc& DescB = B->GetDesc();

			bool bFaceLockedA = (DescA.PositionType == IStereoLayers::ELayerType::FaceLocked);
			bool bFaceLockedB = (DescB.PositionType == IStereoLayers::ELayerType::FaceLocked);

			if (bFaceLockedA != bFaceLockedB)
				return !bFaceLockedA;

			// Draw layers by ascending priority
			if (DescA.Priority != DescB.Priority)
				return DescA.Priority < DescB.Priority;

			// Draw layers by ascending id
			return A->GetId() < B->GetId();
		}
	};

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
