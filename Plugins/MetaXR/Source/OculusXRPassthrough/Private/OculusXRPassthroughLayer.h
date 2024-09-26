// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "khronos/openxr/openxr.h"
#include "IStereoLayers.h"
#include "OculusXRPassthroughLayerShapes.h"

namespace XRPassthrough
{

	class FPassthroughLayer
	{
	public:
		static bool IsPassthoughLayerDesc(const IStereoLayers::FLayerDesc& LayerDesc);
		FPassthroughLayer(XrPassthroughFB PassthroughInstance);
		virtual ~FPassthroughLayer();
		bool CanReuseResources(const IStereoLayers::FLayerDesc& LayerDesc) const;
		bool Initialize_RenderThread(XrSession InSession, const IStereoLayers::FLayerDesc& LayerDesc);
		const XrCompositionLayerBaseHeader* GetXrCompositionLayerHeader();
		bool IsBackgroundLayer() const;
		const IStereoLayers::FLayerDesc& GetDesc() const { return LayerDesc; };

	private:
		IStereoLayers::FLayerDesc LayerDesc;
		XrPassthroughLayerFB XrPassthroughLayer;
		XrCompositionLayerPassthroughFB XrCompositionLayerHeader;
		XrPassthroughFB XrPassthroughInstance;
	};

	struct FLayerDesc_ComparePriority
	{
		FORCEINLINE int32 GetLayerTypePriority(const IStereoLayers::FLayerDesc& LayerDesc) const
		{
			bool IsUnderlay = false;

			if (LayerDesc.HasShape<FReconstructedLayer>())
			{
				const FReconstructedLayer& ReconstructedLayerProps = LayerDesc.GetShape<FReconstructedLayer>();
				IsUnderlay = (ReconstructedLayerProps.PassthroughLayerOrder == PassthroughLayerOrder_Underlay);
			}
			else if (LayerDesc.HasShape<FUserDefinedLayer>())
			{
				const FUserDefinedLayer& UserDefinedLayerProps = LayerDesc.GetShape<FUserDefinedLayer>();
				IsUnderlay = (UserDefinedLayerProps.PassthroughLayerOrder == PassthroughLayerOrder_Underlay);
			}

			const int32 Priority = IsUnderlay ? -1 : 1;
			return Priority;
		}

		FORCEINLINE bool operator()(const IStereoLayers::FLayerDesc& A, const IStereoLayers::FLayerDesc& B) const
		{
			// First order layers by type
			const int32 PassA = GetLayerTypePriority(A);
			const int32 PassB = GetLayerTypePriority(B);

			if (PassA != PassB)
			{
				return PassA < PassB;
			}

			// Draw layers by ascending priority
			if (A.Priority != B.Priority)
			{
				return A.Priority < B.Priority;
			}

			// Draw layers by ascending id
			return A.Id < B.Id;
		}
	};

	typedef TSharedPtr<FPassthroughLayer, ESPMode::ThreadSafe> FPassthroughLayerPtr;

} // namespace XRPassthrough
