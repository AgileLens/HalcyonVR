// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OculusXRHMDPrivate.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS
#include "OculusXRHMD_Settings.h"
#include "ShowFlags.h"

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// FGameFrame
	//-------------------------------------------------------------------------------------------------

	class FGameFrame : public TSharedFromThis<FGameFrame, ESPMode::ThreadSafe>
	{
	public:
		uint32 FrameNumber;			// current frame number. (StartGameFrame_GameThread)
		float WorldToMetersScale;	// World units (UU) to Meters scale. (OnStartGameFrame)
		FIntPoint WindowSize;		// actual window size (StartGameFrame_GameThread)
		FEngineShowFlags ShowFlags; // (PreRenderViewFamily_RenderThread)

		FQuat HeadOrientation;	 // (CalculateStereoViewOffset)
		FQuat PlayerOrientation; // (CalculateStereoViewOffset)
		FVector PlayerLocation;	 // (CalculateStereoViewOffset)
		float NearClippingPlane; // (GetStereoProjectionMatrix)

		FTransform TrackingToWorld;		// (OnEndGameFrame)
		FTransform LastTrackingToWorld; // (OnEndGameFrame)

		EOculusXRFoveatedRenderingMethod FoveatedRenderingMethod; // OnStartGameFrame
		EOculusXRFoveatedRenderingLevel FoveatedRenderingLevel;	  // OnStartGameFrame
		bool bDynamicFoveatedRendering;							  // OnStartGameFrame

		ovrpFovf Fov[ovrpEye_Count];		  // UpdateStereoRenderingParams
		ovrpFovf SymmetricFov[ovrpEye_Count]; // UpdateStereoRenderingParams, symmetric FOV if frame is using symmetricFOV.

		union
		{
			struct
			{
				/** True, if splash is shown */
				uint64 bSplashIsShown : 1;
				/** True, if spectator screen is active */
				uint64 bSpectatorScreenActive : 1;
				/** True if the frame's positions have been updated on the render thread */
				uint64 bRTLateUpdateDone : 1;
			};
			uint64 Raw;
		} Flags;

	public:
		FGameFrame();

		TSharedPtr<FGameFrame, ESPMode::ThreadSafe> Clone() const;
	};

	typedef TSharedPtr<FGameFrame, ESPMode::ThreadSafe> FGameFramePtr;

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
