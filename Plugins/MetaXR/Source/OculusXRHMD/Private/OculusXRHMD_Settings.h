// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OculusXRHMDPrivate.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS

namespace OculusXRHMD
{

	static const float ClampPixelDensityMin = 0.5f;
	static const float ClampPixelDensityMax = 2.0f;

	//-------------------------------------------------------------------------------------------------
	// FSettings
	//-------------------------------------------------------------------------------------------------

	class FSettings : public TSharedFromThis<FSettings, ESPMode::ThreadSafe>
	{
	public:
		union
		{
			struct
			{
				/** Whether stereo is currently on or off. */
				uint64 bStereoEnabled : 1;

				/** Whether or not switching to stereo is allowed */
				uint64 bHMDEnabled : 1;

				/** Turns on/off updating view's orientation/position on a RenderThread. When it is on,
				latency should be significantly lower.
				See 'HMD UPDATEONRT ON|OFF' console command.
			*/
				uint64 bUpdateOnRT : 1;

				/** Enforces headtracking to work even in non-stereo mode (for debugging or screenshots).
				See 'MOTION ENFORCE' console command. */
				uint64 bHeadTrackingEnforced : 1;

				/** Allocate an high quality OVR_FORMAT_R11G11B10_FLOAT buffer for Rift */
				uint64 bHQBuffer : 1;

				/** Rendering should be (could be) paused */
				uint64 bPauseRendering : 1;

				/** HQ Distortion */
				uint64 bHQDistortion : 1;

				/** Send the depth buffer to the compositor */
				uint64 bCompositeDepth : 1;

				/** Supports Dash in-game compositing */
				uint64 bSupportsDash : 1;
#if !UE_BUILD_SHIPPING
				/** Show status / statistics on screen. See 'hmd stats' cmd */
				uint64 bShowStats : 1;
#endif
				/** Dynamically update pixel density to maintain framerate */
				uint64 bPixelDensityAdaptive : 1;

				/** All future eye buffers will need to be created with TexSRGB_Create flag due to the current feature level (ES31) */
				uint64 bsRGBEyeBuffer : 1;

				/** Supports Focus Aware state on Quest */
				uint64 bFocusAware : 1;

				/** Requires the Oculus system keyboard */
				uint64 bRequiresSystemKeyboard : 1;

				/** Whether passthrough functionality can be used with the app */
				uint64 bInsightPassthroughEnabled : 1;

				/** Whether Anchors can be used with the app */
				uint64 bAnchorSupportEnabled : 1;

				/** Whether Anchor Sharing can be used with the app */
				uint64 bAnchorSharingEnabled : 1;

				/** Whether Scene can be used with the app */
				uint64 bSceneSupportEnabled : 1;


				/** Whether the guardian boundary visibility toggles can be used with the app */
				uint64 bBoundaryVisibilitySupportEnabled : 1;

				/** Whether the guardian boundary visibility should be suppressed by default, this can only be true if passthrough is enabled */
				uint64 bDefaultBoundaryVisibilitySuppressed : 1;

				/** Whether body tracking functionality can be used with the app */
				uint64 bBodyTrackingEnabled : 1;

				/** Whether eye tracking functionality can be used with the app */
				uint64 bEyeTrackingEnabled : 1;

				/** Whether face tracking functionality can be used with the app */
				uint64 bFaceTrackingEnabled : 1;

				/** Whether tile turn off can be used with the app */
				uint64 bTileTurnOffEnabled : 1;

				/** Whether iterative cook-on-the-fly is enabled */
				uint64 bIterativeCookOnTheFly : 1;

				/** When running multiple player windows in a single process with VRPreview, this option determins whether to set the current active PIE to the primary one on the fly.*/
				uint64 bSetActivePIEToPrimary : 1;

				/** When running multiple player windows in a single process with VRPreview, this option determins whether to set the PIE specified by CVar vr.PrimaryPIEIndex to the primary one on the fly.*/
				uint64 bSetCVarPIEToPrimary : 1;

				/* In case of multiple players testing, when the current player is inactive, disabling this setting will make sure the current player does NOT update headpose until it is active again.*/
				uint64 bUpdateHeadPoseForInactivePlayer : 1;
			};
			uint64 Raw;
		} Flags;

		/** HMD base values, specify forward orientation and zero pos offset */
		FVector BaseOffset;	   // base position, in meters, relatively to the sensor //@todo hmd: clients need to stop using oculus space
		FQuat BaseOrientation; // base orientation

		/** Viewports for each eye, in render target texture coordinates */
		FIntRect EyeRenderViewport[ovrpEye_Count];
		/** Viewports for each eye, without DynamicResolution scaling applied */
		FIntRect EyeUnscaledRenderViewport[ovrpEye_Count];

		ovrpMatrix4f EyeProjectionMatrices[ovrpEye_Count]; // 0 - left, 1 - right same as Views
		ovrpMatrix4f MonoProjectionMatrix;

		FIntPoint RenderTargetSize;
		float PixelDensity;
		float PixelDensityMin;
		float PixelDensityMax;

		ovrpSystemHeadset SystemHeadset;

		float VsyncToNextVsync;

		EOculusXRProcessorPerformanceLevel SuggestedCpuPerfLevel;
		EOculusXRProcessorPerformanceLevel SuggestedGpuPerfLevel;

		EOculusXRFoveatedRenderingMethod FoveatedRenderingMethod;
		EOculusXRFoveatedRenderingLevel FoveatedRenderingLevel;
		bool bDynamicFoveatedRendering;
		bool bSupportEyeTrackedFoveatedRendering;

		ESystemSplashBackgroundType SystemSplashBackground;

		EOculusXRXrApi XrApi;
		EOculusXRColorSpace ColorSpace;
		EOculusXRControllerPoseAlignment ControllerPoseAlignment;

		EOculusXRHandTrackingSupport HandTrackingSupport;
		EOculusXRHandTrackingFrequency HandTrackingFrequency;
		EOculusXRHandTrackingVersion HandTrackingVersion;

		ovrpVector4f ColorScale, ColorOffset;
		bool bApplyColorScaleAndOffsetToAllLayers;

		FStaticFeatureLevel CurrentFeatureLevel;
		EShaderPlatform CurrentShaderPlatform;

		bool bLateLatching;
		bool bSupportExperimentalFeatures;

		EProcessorFavor ProcessorFavor;

		EOculusXRHMDBodyTrackingFidelity BodyTrackingFidelity;
		EOculusXRHMDBodyJointSet BodyTrackingJointSet;

		TSet<EFaceTrackingDataSourceConfig> FaceTrackingDataSource;

		bool bIterativeCookOnTheFly;

		EOculusXRMPPoseRestoreType MPPoseRestoreType;

	public:
		FSettings();
		virtual ~FSettings() {}

		bool IsStereoEnabled() const { return Flags.bStereoEnabled && Flags.bHMDEnabled; }

		void SetPixelDensity(float NewPixelDensity);
		void SetPixelDensitySmooth(float NewPixelDensity);
		void SetPixelDensityMin(float NewPixelDensityMin);
		void SetPixelDensityMax(float NewPixelDensityMax);

		TSharedPtr<FSettings, ESPMode::ThreadSafe> Clone() const;
	};

	typedef TSharedPtr<FSettings, ESPMode::ThreadSafe> FSettingsPtr;

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
