// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRControllerTracking.h"
#include "OculusXRHMD.h"
#include "OculusXRInput.h"
#include "Misc/CoreDelegates.h"
#include "IOculusXRInputModule.h"
#include "Haptics/HapticFeedbackEffect_Base.h"

namespace OculusXRInput
{
	void FOculusXRControllerTracking::PlayHapticEffect(
		class UHapticFeedbackEffect_Base* HapticEffect,
		EControllerHand Hand,
		EOculusXRHandHapticsLocation Location,
		bool bAppend,
		float Scale,
		bool bLoop)
	{
#if OCULUS_INPUT_SUPPORTED_PLATFORMS
		TSharedPtr<FOculusXRInput> OculusXRInputModule = StaticCastSharedPtr<FOculusXRInput>(IOculusXRInputModule::Get().GetInputDevice());
		OculusXRInputModule.Get()->PlayHapticEffect(HapticEffect, Hand, Location, bAppend, Scale, bLoop);
#endif
	}

	int FOculusXRControllerTracking::PlayHapticEffect(EControllerHand Hand, TArray<uint8>& Amplitudes, int SampleRate, bool bPCM, bool bAppend)
	{
#if OCULUS_INPUT_SUPPORTED_PLATFORMS
		TSharedPtr<FOculusXRInput> OculusXRInputModule = StaticCastSharedPtr<FOculusXRInput>(IOculusXRInputModule::Get().GetInputDevice());
		return OculusXRInputModule.Get()->PlayHapticEffect(Hand, Amplitudes.Num(), Amplitudes.GetData(), SampleRate, bPCM, bAppend);
#endif
	}

	void FOculusXRControllerTracking::StopHapticEffect(EControllerHand Hand, EOculusXRHandHapticsLocation Location)
	{
#if OCULUS_INPUT_SUPPORTED_PLATFORMS
		SetHapticsByValue(0.f, 0.f, Hand, Location);
#endif
	}

	void FOculusXRControllerTracking::SetHapticsByValue(float Frequency, float Amplitude, EControllerHand Hand, EOculusXRHandHapticsLocation Location)
	{
#if OCULUS_INPUT_SUPPORTED_PLATFORMS
		TSharedPtr<FOculusXRInput> OculusXRInputModule = StaticCastSharedPtr<FOculusXRInput>(IOculusXRInputModule::Get().GetInputDevice());
		OculusXRInputModule.Get()->SetHapticsByValue(Frequency, Amplitude, Hand, Location);
#endif
	}

	float FOculusXRControllerTracking::GetControllerSampleRateHz(EControllerHand Hand)
	{
#if OCULUS_INPUT_SUPPORTED_PLATFORMS
		TSharedPtr<FOculusXRInput> OculusXRInputModule = StaticCastSharedPtr<FOculusXRInput>(IOculusXRInputModule::Get().GetInputDevice());
		return OculusXRInputModule.Get()->GetControllerSampleRateHz(Hand);
#endif
		return 0;
	}

	int FOculusXRControllerTracking::GetMaxHapticDuration(EControllerHand Hand)
	{
#if OCULUS_INPUT_SUPPORTED_PLATFORMS
		TSharedPtr<FOculusXRInput> OculusXRInputModule = StaticCastSharedPtr<FOculusXRInput>(IOculusXRInputModule::Get().GetInputDevice());
		return OculusXRInputModule.Get()->GetMaxHapticDuration(Hand);
#endif
		return 0;
	}
} // namespace OculusXRInput
