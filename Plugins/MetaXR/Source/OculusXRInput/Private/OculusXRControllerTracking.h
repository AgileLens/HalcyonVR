// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OculusXRInputFunctionLibrary.h"

#define LOCTEXT_NAMESPACE "OculusXRControllerTracking"

DEFINE_LOG_CATEGORY_STATIC(LogOcXRControllerTracking, Log, All);

//-------------------------------------------------------------------------------------------------
// FOculusXRControllerTracking
//-------------------------------------------------------------------------------------------------

class UHapticFeedbackEffect_Base;

namespace OculusXRInput
{
	class FOculusXRControllerTracking
	{
	public:
		static void PlayHapticEffect(
			UHapticFeedbackEffect_Base* HapticEffect,
			EControllerHand Hand,
			EOculusXRHandHapticsLocation Location = EOculusXRHandHapticsLocation::Hand,
			bool bAppend = false,
			float Scale = 1.f,
			bool bLoop = false);

		static int PlayHapticEffect(EControllerHand Hand, TArray<uint8>& Amplitudes, int SampleRate, bool bPCM = false, bool bAppend = false);

		static void StopHapticEffect(EControllerHand Hand, EOculusXRHandHapticsLocation Location = EOculusXRHandHapticsLocation::Hand);

		static void SetHapticsByValue(float Frequency, float Amplitude, EControllerHand Hand, EOculusXRHandHapticsLocation Location = EOculusXRHandHapticsLocation::Hand);

		static float GetControllerSampleRateHz(EControllerHand Hand);

		static int GetMaxHapticDuration(EControllerHand Hand);
	};

} // namespace OculusXRInput

#undef LOCTEXT_NAMESPACE
