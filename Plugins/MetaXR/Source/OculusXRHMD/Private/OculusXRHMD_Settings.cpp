// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRHMD_Settings.h"
#include "Engine/Engine.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// FSettings
	//-------------------------------------------------------------------------------------------------

	FSettings::FSettings()
		: BaseOffset(0, 0, 0)
		, BaseOrientation(FQuat::Identity)
		, PixelDensity(1.0f)
		, PixelDensityMin(0.8f)
		, PixelDensityMax(1.2f)
		, SystemHeadset(ovrpSystemHeadset_None)
		, SuggestedCpuPerfLevel(EOculusXRProcessorPerformanceLevel::SustainedLow)
		, SuggestedGpuPerfLevel(EOculusXRProcessorPerformanceLevel::SustainedHigh)
		, FoveatedRenderingMethod(EOculusXRFoveatedRenderingMethod::FixedFoveatedRendering)
		, FoveatedRenderingLevel(EOculusXRFoveatedRenderingLevel::Off)
		, bDynamicFoveatedRendering(true)
		, bSupportEyeTrackedFoveatedRendering(false)
		, SystemSplashBackground(ESystemSplashBackgroundType::Black)
		, XrApi(EOculusXRXrApi::OVRPluginOpenXR)
		, ColorSpace(EOculusXRColorSpace::P3)
		, ControllerPoseAlignment(EOculusXRControllerPoseAlignment::Default)
		, HandTrackingSupport(EOculusXRHandTrackingSupport::ControllersOnly)
		, HandTrackingFrequency(EOculusXRHandTrackingFrequency::LOW)
		, HandTrackingVersion(EOculusXRHandTrackingVersion::Default)
		, ColorScale(ovrpVector4f{ 1, 1, 1, 1 })
		, ColorOffset(ovrpVector4f{ 0, 0, 0, 0 })
		, bApplyColorScaleAndOffsetToAllLayers(false)
		, CurrentFeatureLevel(GMaxRHIFeatureLevel)
		, bLateLatching(false)
		, bSupportExperimentalFeatures(false)
		, ProcessorFavor(EProcessorFavor::FavorEqually)
		, BodyTrackingFidelity(EOculusXRHMDBodyTrackingFidelity::Low)
		, BodyTrackingJointSet(EOculusXRHMDBodyJointSet::UpperBody)
		, MPPoseRestoreType(EOculusXRMPPoseRestoreType::Disabled)
	{
		Flags.Raw = 0;
		Flags.bHMDEnabled = true;
		Flags.bUpdateOnRT = true;
		Flags.bHQBuffer = false;
		Flags.bCompositeDepth = true;
#if PLATFORM_ANDROID
		Flags.bsRGBEyeBuffer = true;
		// oculus mobile is always-on stereo, no need for enableStereo codepaths
		Flags.bStereoEnabled = true;
#else
		Flags.bsRGBEyeBuffer = false;
		Flags.bStereoEnabled = false;
#endif
		CurrentFeatureLevel = GEngine ? GEngine->GetDefaultWorldFeatureLevel() : GMaxRHIFeatureLevel;
		CurrentShaderPlatform = GShaderPlatformForFeatureLevel[CurrentFeatureLevel];

		Flags.bSupportsDash = true;
		Flags.bFocusAware = true;
		Flags.bRequiresSystemKeyboard = false;
		Flags.bInsightPassthroughEnabled = false;
		Flags.bAnchorSupportEnabled = false;
		Flags.bAnchorSharingEnabled = false;
		Flags.bSceneSupportEnabled = false;
		Flags.bBoundaryVisibilitySupportEnabled = false;
		Flags.bDefaultBoundaryVisibilitySuppressed = false;
		Flags.bBodyTrackingEnabled = false;
		Flags.bEyeTrackingEnabled = false;
		Flags.bFaceTrackingEnabled = false;
		EyeRenderViewport[0] = EyeRenderViewport[1] = FIntRect(0, 0, 0, 0);

		RenderTargetSize = FIntPoint(0, 0);

		Flags.bIterativeCookOnTheFly = false;

#ifdef WITH_OCULUS_BRANCH
		Flags.bTileTurnOffEnabled = false;

		Flags.bSetActivePIEToPrimary = true;
		Flags.bSetCVarPIEToPrimary = true;
		Flags.bUpdateHeadPoseForInactivePlayer = false;
#else
		Flags.bTileTurnOffEnabled = true;

		// Vanilla UE doesn't support MultiPlayerTesting well, disable it for now.
		Flags.bSetActivePIEToPrimary = false;
		Flags.bSetCVarPIEToPrimary = false;
		Flags.bUpdateHeadPoseForInactivePlayer = false;
#endif
	}

	TSharedPtr<FSettings, ESPMode::ThreadSafe> FSettings::Clone() const
	{
		TSharedPtr<FSettings, ESPMode::ThreadSafe> NewSettings = MakeShareable(new FSettings(*this));
		return NewSettings;
	}

	void FSettings::SetPixelDensity(float NewPixelDensity)
	{
		if (Flags.bPixelDensityAdaptive)
		{
			PixelDensity = FMath::Clamp(NewPixelDensity, PixelDensityMin, PixelDensityMax);
		}
		else
		{
			PixelDensity = FMath::Clamp(NewPixelDensity, ClampPixelDensityMin, ClampPixelDensityMax);
		}
	}

	void FSettings::SetPixelDensitySmooth(float NewPixelDensity)
	{
		// Pixel Density changes need to be smooth both for artifacts with FFR/TTO (FFR/tile-turnoff is one frame late so shouldn't change too fast)
		// but also so that if the developer uses the CVar and not the runtime (which is already smooth) there is no jump artifacts.
		constexpr float MaxPerFrameIncrease = 0.010;
		constexpr float MaxPerFrameDecrease = 0.045;

		float NewClampedPixelDensity = FMath::Clamp(NewPixelDensity, PixelDensity - MaxPerFrameDecrease, PixelDensity + MaxPerFrameIncrease);
		if (Flags.bPixelDensityAdaptive)
		{
			PixelDensity = FMath::Clamp(NewClampedPixelDensity, PixelDensityMin, PixelDensityMax);
		}
		else
		{
			PixelDensity = FMath::Clamp(NewClampedPixelDensity, ClampPixelDensityMin, ClampPixelDensityMax);
		}
	}

	void FSettings::SetPixelDensityMin(float NewPixelDensityMin)
	{
		PixelDensityMin = FMath::Clamp(NewPixelDensityMin, ClampPixelDensityMin, ClampPixelDensityMax);
		PixelDensityMax = FMath::Max(PixelDensityMin, PixelDensityMax);
		SetPixelDensity(PixelDensity);
	}

	void FSettings::SetPixelDensityMax(float NewPixelDensityMax)
	{
		PixelDensityMax = FMath::Clamp(NewPixelDensityMax, ClampPixelDensityMin, ClampPixelDensityMax);
		PixelDensityMin = FMath::Min(PixelDensityMin, PixelDensityMax);
		SetPixelDensity(PixelDensity);
	}

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
