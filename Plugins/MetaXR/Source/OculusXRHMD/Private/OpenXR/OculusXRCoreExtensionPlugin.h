// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once
#include "CoreMinimal.h"
#include "Misc/EngineVersionComparison.h"
#include "OpenXR/IOculusXRExtensionPlugin.h"

DECLARE_LOG_CATEGORY_EXTERN(LogOculusOpenXRPlugin, Log, All);

namespace OculusXR
{

	class FOculusXRCoreExtensionPlugin : public IOculusXRExtensionPlugin
	{
	public:
		// IOpenXRExtensionPlugin
		virtual bool IsStandaloneStereoOnlyDevice() override;
		virtual bool GetOptionalExtensions(TArray<const ANSICHAR*>& OutExtensions) override;
		virtual bool GetSpectatorScreenController(FHeadMountedDisplayBase* InHMDBase, TUniquePtr<FDefaultSpectatorScreenController>& OutSpectatorScreenController) override;
		virtual const void* OnCreateSession(XrInstance InInstance, XrSystemId InSystem, const void* InNext) override;
		virtual const void* OnEndProjectionLayer(XrSession InSession, int32 InLayerIndex, const void* InNext, XrCompositionLayerFlags& OutFlags) override;
	};

} // namespace OculusXR
