// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "IOpenXRExtensionPlugin.h"
#include "IStereoLayers.h"
#include "OculusXRPassthroughLayer.h"

#define LOCTEXT_NAMESPACE "OculusXRPassthrough"

namespace XRPassthrough
{

	class FPassthroughXR : public IOpenXRExtensionPlugin
	{
	public:
		// IOculusXROpenXRHMDPlugin
		virtual void* OnWaitFrame(XrSession InSession, void* InNext) override;
		virtual bool GetRequiredExtensions(TArray<const ANSICHAR*>& OutExtensions) override;
		virtual bool GetOptionalExtensions(TArray<const ANSICHAR*>& OutExtensions) override;
		virtual const void* OnCreateInstance(class IOpenXRHMDModule* InModule, const void* InNext) override;
		virtual const void* OnCreateSession(XrInstance InInstance, XrSystemId InSystem, const void* InNext) override;
		virtual const void* OnEndProjectionLayer(XrSession InSession, int32 InLayerIndex, const void* InNext, XrCompositionLayerFlags& OutFlags) override;

		virtual void OnSetupLayers_RenderThread(XrSession InSession, const TArray<uint32_t>& LayerIds) override;
		virtual void UpdateCompositionLayers(XrSession InSession, TArray<const XrCompositionLayerBaseHeader*>& Headers) override;

	public:
		static bool IsPassthoughLayerDesc(const IStereoLayers::FLayerDesc& LayerDesc);
		FPassthroughXR();
		virtual ~FPassthroughXR();
		void RegisterAsOpenXRExtension();

	private:
		struct FSettings
		{
			bool bPassthroughEnabled;
		};

		FPassthroughLayerPtr CreateStereoLayerFromDesc(const IStereoLayers::FLayerDesc& LayerDesc) const;
		void ShutdownPassthrough(XrSession InSession);
		void InitializePassthrough(XrSession InSession);
		void Update_GameThread(XrSession InSession);
		bool IsPassthroughEnabled(void) const;

		XrCompositionLayerAlphaBlendFB ProjectionLayerAlphaBlend;
		TArray<FPassthroughLayerPtr> Layers_RenderThread;

		XrPassthroughFB PassthroughInstance;
		bool bPassthroughInitialized;
		bool bExtLayerAlphaBlendAvailable;
		bool bExtPassthroughAvailable;

		typedef TSharedPtr<FSettings, ESPMode::ThreadSafe> FSettingsPtr;
		FSettingsPtr Settings;
	};

} // namespace XRPassthrough

#undef LOCTEXT_NAMESPACE
