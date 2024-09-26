// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRHMD_GameFrame.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS
#include "GameFramework/WorldSettings.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

namespace OculusXRHMD
{

	//-------------------------------------------------------------------------------------------------
	// FGameFrame
	//-------------------------------------------------------------------------------------------------

	FGameFrame::FGameFrame()
		: FrameNumber(0), WorldToMetersScale(100.f), ShowFlags(ESFIM_All0), PlayerOrientation(FQuat::Identity), PlayerLocation(FVector::ZeroVector), FoveatedRenderingMethod(EOculusXRFoveatedRenderingMethod::FixedFoveatedRendering), FoveatedRenderingLevel(EOculusXRFoveatedRenderingLevel::Off), bDynamicFoveatedRendering(false)
	{
		Flags.Raw = 0;
		Fov[0] = Fov[1] = SymmetricFov[0] = SymmetricFov[1] = ovrpFovf{ 0, 0, 0, 0 };
	}

	TSharedPtr<FGameFrame, ESPMode::ThreadSafe> FGameFrame::Clone() const
	{
		TSharedPtr<FGameFrame, ESPMode::ThreadSafe> NewFrame = MakeShareable(new FGameFrame(*this));
		return NewFrame;
	}

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
