// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRPassthroughXR.h"

#include "Engine/GameEngine.h"
#include "IOpenXRHMDModule.h"
#include "OculusXRHMDRuntimeSettings.h"
#include "OculusXRPassthroughXRFunctions.h"
#include "StereoRendering.h"
#include "XRThreadUtils.h"

#define LOCTEXT_NAMESPACE "OculusXRPassthrough"

namespace XRPassthrough
{

	FPassthroughXR::FPassthroughXR()
		: ProjectionLayerAlphaBlend{}
		, Layers_RenderThread{}
		, PassthroughInstance{ XR_NULL_HANDLE }
		, bPassthroughInitialized(false)
		, bExtLayerAlphaBlendAvailable(false)
		, bExtPassthroughAvailable(false)
		, Settings(nullptr)
	{
	}

	FPassthroughXR::~FPassthroughXR()
	{
	}

	void FPassthroughXR::RegisterAsOpenXRExtension()
	{
#if defined(WITH_OCULUS_BRANCH)
		// Feature not enabled on Marketplace build. Currently only for the meta fork
		RegisterOpenXRExtensionModularFeature();
#endif
	}

	bool FPassthroughXR::GetRequiredExtensions(TArray<const ANSICHAR*>& OutExtensions)
	{
		OutExtensions.Add(XR_FB_PASSTHROUGH_EXTENSION_NAME);
		return true;
	}

	bool FPassthroughXR::GetOptionalExtensions(TArray<const ANSICHAR*>& OutExtensions)
	{
		OutExtensions.Add(XR_FB_COMPOSITION_LAYER_ALPHA_BLEND_EXTENSION_NAME);
		return true;
	}

	const void* FPassthroughXR::OnCreateInstance(class IOpenXRHMDModule* InModule, const void* InNext)
	{
		if (InModule != nullptr)
		{
			bExtLayerAlphaBlendAvailable = InModule->IsExtensionEnabled(XR_FB_COMPOSITION_LAYER_ALPHA_BLEND_EXTENSION_NAME);
			bExtPassthroughAvailable = InModule->IsExtensionEnabled(XR_FB_PASSTHROUGH_EXTENSION_NAME);
		}
		return InNext;
	}

	const void* FPassthroughXR::OnCreateSession(XrInstance InInstance, XrSystemId InSystem, const void* InNext)
	{
		InitOpenXRFunctions(InInstance);
		return InNext;
	}

	void* FPassthroughXR::OnWaitFrame(XrSession InSession, void* InNext)
	{
		Update_GameThread(InSession);
		return InNext;
	}

	bool FPassthroughXR::IsPassthroughEnabled(void) const
	{
		return bPassthroughInitialized;
	}

	FPassthroughLayerPtr FPassthroughXR::CreateStereoLayerFromDesc(const IStereoLayers::FLayerDesc& LayerDesc) const
	{
		FPassthroughLayerPtr Layer = nullptr;

		if (FPassthroughLayer::IsPassthoughLayerDesc(LayerDesc))
		{
			check(PassthroughInstance != XR_NULL_HANDLE);
			Layer = MakeShareable(new FPassthroughLayer(PassthroughInstance));
		}
		return Layer;
	}

	void FPassthroughXR::OnSetupLayers_RenderThread(XrSession InSession, const TArray<uint32_t>& LayerIds)
	{
		check(IsInRenderingThread());

		IStereoLayers* StereoLayers;
		if (!GEngine->StereoRenderingDevice.IsValid() || (StereoLayers = GEngine->StereoRenderingDevice->GetStereoLayers()) == nullptr)
		{
			return;
		}

		if (!IsPassthroughEnabled())
		{
			return;
		}

		TArray<IStereoLayers::FLayerDesc> LayerDescList;
		for (uint32_t LayerId : LayerIds)
		{
			IStereoLayers::FLayerDesc LayerDesc;
			if (StereoLayers->GetLayerDesc(LayerId, LayerDesc))
			{
				LayerDescList.Emplace(LayerDesc);
			}
		}
		LayerDescList.Sort(FLayerDesc_ComparePriority());

		TArray<FPassthroughLayerPtr> NewLayers;
		for (int32 LayerIdx = 0; LayerIdx < LayerDescList.Num(); LayerIdx++)
		{
			FPassthroughLayerPtr Layer = LayerIdx < Layers_RenderThread.Num() ? Layers_RenderThread[LayerIdx] : nullptr;
			const IStereoLayers::FLayerDesc& LayerDesc = LayerDescList[LayerIdx];

			if (Layer == nullptr || !Layer->CanReuseResources(LayerDesc))
			{
				Layer = CreateStereoLayerFromDesc(LayerDesc);
			}

			if (Layer != nullptr)
			{
				if (Layer->Initialize_RenderThread(InSession, LayerDesc))
				{
					NewLayers.Add(Layer);
				}
				else
				{
					UE_LOG(LogHMD, Error, TEXT("Failed initializing passthrough layer."));
				}
			}
		}
		Layers_RenderThread = NewLayers;
	}

	void FPassthroughXR::UpdateCompositionLayers(XrSession InSession, TArray<const XrCompositionLayerBaseHeader*>& Headers)
	{
		check(IsInRenderingThread() || IsInRHIThread());

		for (const FPassthroughLayerPtr& Layer : Layers_RenderThread)
		{
			if (Layer->IsBackgroundLayer())
			{
				const XrCompositionLayerBaseHeader* CompositionLayerHeader = Layer->GetXrCompositionLayerHeader();
				if (CompositionLayerHeader != nullptr)
				{
					Headers.Insert(CompositionLayerHeader, 0);
				}
			}
		}
	}

	const void* FPassthroughXR::OnEndProjectionLayer(XrSession InSession, int32 InLayerIndex, const void* InNext, XrCompositionLayerFlags& OutFlags)
	{
		check(IsInRenderingThread() || IsInRHIThread());

		if (bExtLayerAlphaBlendAvailable)
		{
			bool bHasBackgroundLayer = false;
			for (const FPassthroughLayerPtr& Layer : Layers_RenderThread)
			{
				if (Layer->IsBackgroundLayer())
				{
					bHasBackgroundLayer = true;
					break;
				}
			}

			if (bHasBackgroundLayer)
			{
				OutFlags |= XR_COMPOSITION_LAYER_BLEND_TEXTURE_SOURCE_ALPHA_BIT;

				InNext = &ProjectionLayerAlphaBlend;
				ProjectionLayerAlphaBlend.type = XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB;
				ProjectionLayerAlphaBlend.srcFactorColor = XR_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA_FB;
				ProjectionLayerAlphaBlend.srcFactorAlpha = XR_BLEND_FACTOR_ONE_FB;
				ProjectionLayerAlphaBlend.dstFactorColor = XR_BLEND_FACTOR_SRC_ALPHA_FB;
				ProjectionLayerAlphaBlend.dstFactorAlpha = XR_BLEND_FACTOR_ZERO_FB;
				ProjectionLayerAlphaBlend.next = nullptr;
			}
		}
		return InNext;
	}

	void FPassthroughXR::InitializePassthrough(XrSession InSession)
	{
		check(IsInRenderingThread());

		const XrPassthroughCreateInfoFB PassthroughCreateInfo = { XR_TYPE_PASSTHROUGH_CREATE_INFO_FB };

		if (!XR_SUCCEEDED(xrCreatePassthroughFB(InSession, &PassthroughCreateInfo, &PassthroughInstance)))
		{
			UE_LOG(LogHMD, Error, TEXT("xrCreatePassthroughFB failed"));
			return;
		}

		if (!XR_SUCCEEDED(xrPassthroughStartFB(PassthroughInstance)))
		{
			UE_LOG(LogHMD, Error, TEXT("xrPassthroughStartFB failed"));
			return;
		}
	}

	void FPassthroughXR::ShutdownPassthrough(XrSession InSession)
	{
		check(IsInRenderingThread());

		if (PassthroughInstance != XR_NULL_HANDLE)
		{
			if (!XR_SUCCEEDED(xrDestroyPassthroughFB(PassthroughInstance)))
			{
				UE_LOG(LogHMD, Error, TEXT("xrDestroyPassthroughFB failed"));
			}
			PassthroughInstance = nullptr;
		}
	}

	void FPassthroughXR::Update_GameThread(XrSession InSession)
	{
		check(IsInGameThread());

		if (Settings == nullptr)
		{
			const UOculusXRHMDRuntimeSettings* HMDSettings = GetDefault<UOculusXRHMDRuntimeSettings>();
			Settings = MakeShareable(new FSettings());
			Settings->bPassthroughEnabled = HMDSettings->bInsightPassthroughEnabled;
		}

		check(Settings != nullptr);
		const bool bPassthroughEnabled = Settings->bPassthroughEnabled;

		ExecuteOnRenderThread_DoNotWait([this, InSession, bPassthroughEnabled](FRHICommandListImmediate& RHICmdList) {
			if (bPassthroughEnabled && !bPassthroughInitialized)
			{
				InitializePassthrough(InSession);
				bPassthroughInitialized = true;
			}

			if (!bPassthroughEnabled && bPassthroughInitialized)
			{
				ShutdownPassthrough(InSession);
				bPassthroughInitialized = false;
			}
		});
	}

} // namespace XRPassthrough

#undef LOCTEXT_NAMESPACE
