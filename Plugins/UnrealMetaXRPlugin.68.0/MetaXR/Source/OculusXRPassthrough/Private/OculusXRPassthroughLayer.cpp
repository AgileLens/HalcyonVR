// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRPassthroughLayer.h"

#include "XRThreadUtils.h"

#include "OculusXRHMDPrivate.h"
#include "OculusXRPassthroughXRFunctions.h"

namespace XRPassthrough
{

	FPassthroughLayer::FPassthroughLayer(XrPassthroughFB PassthroughInstance)
		: LayerDesc{}
		, XrPassthroughLayer{ XR_NULL_HANDLE }
		, XrCompositionLayerHeader{}
		, XrPassthroughInstance(PassthroughInstance)
	{
	}

	FPassthroughLayer::~FPassthroughLayer()
	{
		if (IsInGameThread())
		{
			ExecuteOnRenderThread([this]() {
				if (XrPassthroughLayer != XR_NULL_HANDLE)
				{
					xrDestroyPassthroughLayerFB(XrPassthroughLayer);
				}
			});
		}
		else
		{
			if (XrPassthroughLayer != XR_NULL_HANDLE)
			{
				xrDestroyPassthroughLayerFB(XrPassthroughLayer);
			}
		}
	}

	bool FPassthroughLayer::IsPassthoughLayerDesc(const IStereoLayers::FLayerDesc& LayerDesc)
	{
		return LayerDesc.HasShape<FReconstructedLayer>() || LayerDesc.HasShape<FUserDefinedLayer>();
	}

	bool FPassthroughLayer::CanReuseResources(const IStereoLayers::FLayerDesc& InLayerDesc) const
	{
		if (!IsPassthoughLayerDesc(InLayerDesc) || InLayerDesc.HasShape<FReconstructedLayer>() != LayerDesc.HasShape<FReconstructedLayer>() || InLayerDesc.HasShape<FUserDefinedLayer>() != LayerDesc.HasShape<FUserDefinedLayer>())
		{
			return false;
		}
		return true;
	}

	bool FPassthroughLayer::Initialize_RenderThread(XrSession InSession, const IStereoLayers::FLayerDesc& InLayerDesc)
	{
		check(IsPassthoughLayerDesc(InLayerDesc));
		OculusXRHMD::CheckInRenderThread();

		if (!CanReuseResources(InLayerDesc))
		{
			if (XrPassthroughLayer != XR_NULL_HANDLE)
			{
				xrDestroyPassthroughLayerFB(XrPassthroughLayer);
				XrPassthroughLayer = XR_NULL_HANDLE;
			}

			if (InLayerDesc.HasShape<FReconstructedLayer>())
			{
				XrPassthroughLayerCreateInfoFB PassthroughLayerCreateInfo = { XR_TYPE_PASSTHROUGH_LAYER_CREATE_INFO_FB };
				PassthroughLayerCreateInfo.passthrough = XrPassthroughInstance;
				PassthroughLayerCreateInfo.purpose = XR_PASSTHROUGH_LAYER_PURPOSE_RECONSTRUCTION_FB;

				if (!XR_SUCCEEDED(xrCreatePassthroughLayerFB(InSession, &PassthroughLayerCreateInfo, &XrPassthroughLayer)))
				{
					return false;
				}

				if (!XR_SUCCEEDED(xrPassthroughLayerResumeFB(XrPassthroughLayer)))
				{
					return false;
				}
			}
		}
		LayerDesc = InLayerDesc;
		return true;
	}

	const XrCompositionLayerBaseHeader* FPassthroughLayer::GetXrCompositionLayerHeader()
	{
		OculusXRHMD::CheckInRHIThread();
		if (XrPassthroughLayer != nullptr)
		{
			XrCompositionLayerPassthroughFB& CompositionLayer = XrCompositionLayerHeader;
			memset(&CompositionLayer, 0, sizeof(CompositionLayer));
			CompositionLayer.type = XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB;
			CompositionLayer.layerHandle = XrPassthroughLayer;
			CompositionLayer.flags = XR_COMPOSITION_LAYER_BLEND_TEXTURE_SOURCE_ALPHA_BIT;
			CompositionLayer.space = XR_NULL_HANDLE;
			return reinterpret_cast<const XrCompositionLayerBaseHeader*>(&CompositionLayer);
		}
		return nullptr;
	}

	bool FPassthroughLayer::IsBackgroundLayer() const
	{
		return LayerDesc.HasShape<FReconstructedLayer>() && (LayerDesc.GetShape<FReconstructedLayer>().PassthroughLayerOrder == PassthroughLayerOrder_Underlay);
	}

} // namespace XRPassthrough
