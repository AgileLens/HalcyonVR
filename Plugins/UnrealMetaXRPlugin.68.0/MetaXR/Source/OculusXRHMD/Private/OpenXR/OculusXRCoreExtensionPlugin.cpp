// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRCoreExtensionPlugin.h"

#include "DefaultSpectatorScreenController.h"
#include "OculusXRFunctionLibrary.h"
#include "OculusXRXRFunctions.h"
#include "OculusXROpenXRUtilities.h"
#include "OpenXRCore.h"

#if PLATFORM_ANDROID
// #include <openxr_oculus.h>
#include <dlfcn.h>
#endif // PLATFORM_ANDROID

DEFINE_LOG_CATEGORY(LogOculusOpenXRPlugin);

namespace OculusXR
{

	bool FOculusXRCoreExtensionPlugin::IsStandaloneStereoOnlyDevice()
	{
#if PLATFORM_ANDROID
		const bool bIsStandaloneStereoDevice = FAndroidMisc::GetDeviceMake() == FString("Oculus");
#else
		const bool bIsStandaloneStereoDevice = false;
#endif
		return bIsStandaloneStereoDevice;
	}

	bool FOculusXRCoreExtensionPlugin::GetOptionalExtensions(TArray<const ANSICHAR*>& OutExtensions)
	{
		return true;
	}

	bool FOculusXRCoreExtensionPlugin::GetSpectatorScreenController(FHeadMountedDisplayBase* InHMDBase, TUniquePtr<FDefaultSpectatorScreenController>& OutSpectatorScreenController)
	{
#if PLATFORM_ANDROID
		OutSpectatorScreenController = nullptr;
		return true;
#else  // PLATFORM_ANDROID
		OutSpectatorScreenController = MakeUnique<FDefaultSpectatorScreenController>(InHMDBase);
		return false;
#endif // PLATFORM_ANDROID
	}

	const void* FOculusXRCoreExtensionPlugin::OnCreateSession(XrInstance InInstance, XrSystemId InSystem, const void* InNext)
	{
		InitOpenXRFunctions(InInstance);

#if PLATFORM_ANDROID
		if (GRHISupportsRHIThread && GIsThreadedRendering && GUseRHIThread_InternalUseOnly)
		{
			SetRHIThreadEnabled(false, false);
		}
#endif // PLATFORM_ANDROID
		return InNext;
	}

	const void* FOculusXRCoreExtensionPlugin::OnEndProjectionLayer(XrSession InSession, int32 InLayerIndex, const void* InNext, XrCompositionLayerFlags& OutFlags)
	{
		// XR_COMPOSITION_LAYER_UNPREMULTIPLIED_ALPHA_BIT is required right now because the Oculus mobile runtime blends using alpha otherwise,
		// and we don't have proper inverse alpha support in OpenXR yet (once OpenXR supports inverse alpha, or we change the runtime behavior, remove this)
		OutFlags |= XR_COMPOSITION_LAYER_CORRECT_CHROMATIC_ABERRATION_BIT;
		OutFlags |= XR_COMPOSITION_LAYER_UNPREMULTIPLIED_ALPHA_BIT;

		return InNext;
	}

} // namespace OculusXR
