// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRInputFunctionLibrary.h"
#include "OculusXRHandTracking.h"
#include "OculusXRControllerTracking.h"
#include "Logging/MessageLog.h"
#include "Haptics/HapticFeedbackEffect_Buffer.h"
#include "Haptics/HapticFeedbackEffect_Curve.h"
#include "Haptics/HapticFeedbackEffect_SoundWave.h"

//-------------------------------------------------------------------------------------------------
// UOculusHandTrackingFunctionLibrary
//-------------------------------------------------------------------------------------------------
UOculusXRInputFunctionLibrary::UOculusXRInputFunctionLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UOculusXRInputFunctionLibrary::FHandMovementFilterDelegate UOculusXRInputFunctionLibrary::HandMovementFilter;

EOculusXRFinger UOculusXRInputFunctionLibrary::ConvertBoneToFinger(const EOculusXRBone Bone)
{
	switch (Bone)
	{
		case EOculusXRBone::Index_1:
		case EOculusXRBone::Index_2:
		case EOculusXRBone::Index_3:
		case EOculusXRBone::Index_Tip:
			return EOculusXRFinger::Index;
		case EOculusXRBone::Middle_1:
		case EOculusXRBone::Middle_2:
		case EOculusXRBone::Middle_3:
		case EOculusXRBone::Middle_Tip:
			return EOculusXRFinger::Middle;
		case EOculusXRBone::Pinky_0:
		case EOculusXRBone::Pinky_1:
		case EOculusXRBone::Pinky_2:
		case EOculusXRBone::Pinky_3:
		case EOculusXRBone::Pinky_Tip:
			return EOculusXRFinger::Pinky;
		case EOculusXRBone::Ring_1:
		case EOculusXRBone::Ring_2:
		case EOculusXRBone::Ring_3:
		case EOculusXRBone::Ring_Tip:
			return EOculusXRFinger::Ring;
		case EOculusXRBone::Thumb_0:
		case EOculusXRBone::Thumb_1:
		case EOculusXRBone::Thumb_2:
		case EOculusXRBone::Thumb_3:
		case EOculusXRBone::Thumb_Tip:
			return EOculusXRFinger::Thumb;
		default:
			return EOculusXRFinger::Invalid;
	}
}

EOculusXRTrackingConfidence UOculusXRInputFunctionLibrary::GetFingerTrackingConfidence(const EOculusXRHandType DeviceHand, const EOculusXRFinger Finger, const int32 ControllerIndex)
{
	return OculusXRInput::FOculusHandTracking::GetFingerTrackingConfidence(ControllerIndex, DeviceHand, (OculusXRInput::EOculusHandAxes)(uint8)Finger);
}

bool UOculusXRInputFunctionLibrary::GetHandSkeletalMesh(USkeletalMesh* HandSkeletalMesh, EOculusXRHandType SkeletonType, EOculusXRHandType MeshType, float WorldToMeters)
{
	return OculusXRInput::FOculusHandTracking::GetHandSkeletalMesh(HandSkeletalMesh, SkeletonType, MeshType, WorldToMeters);
}

TArray<FOculusXRCapsuleCollider> UOculusXRInputFunctionLibrary::InitializeHandPhysics(EOculusXRHandType SkeletonType, USkinnedMeshComponent* HandComponent, const float WorldToMeters)
{
	return OculusXRInput::FOculusHandTracking::InitializeHandPhysics(SkeletonType, HandComponent, WorldToMeters);
}

FQuat UOculusXRInputFunctionLibrary::GetBoneRotation(const EOculusXRHandType DeviceHand, const EOculusXRBone BoneId, const int32 ControllerIndex)
{
	return OculusXRInput::FOculusHandTracking::GetBoneRotation(ControllerIndex, DeviceHand, BoneId);
}

EOculusXRTrackingConfidence UOculusXRInputFunctionLibrary::GetTrackingConfidence(const EOculusXRHandType DeviceHand, const int32 ControllerIndex)
{
	return OculusXRInput::FOculusHandTracking::GetTrackingConfidence(ControllerIndex, DeviceHand);
}

FTransform UOculusXRInputFunctionLibrary::GetPointerPose(const EOculusXRHandType DeviceHand, const int32 ControllerIndex)
{
	return OculusXRInput::FOculusHandTracking::GetPointerPose(ControllerIndex, DeviceHand);
}

bool UOculusXRInputFunctionLibrary::IsPointerPoseValid(const EOculusXRHandType DeviceHand, const int32 ControllerIndex)
{
	return OculusXRInput::FOculusHandTracking::IsPointerPoseValid(ControllerIndex, DeviceHand);
}

float UOculusXRInputFunctionLibrary::GetHandScale(const EOculusXRHandType DeviceHand, const int32 ControllerIndex)
{
	return OculusXRInput::FOculusHandTracking::GetHandScale(ControllerIndex, DeviceHand);
}

EOculusXRHandType UOculusXRInputFunctionLibrary::GetDominantHand(const int32 ControllerIndex)
{
	EOculusXRHandType DominantHand = EOculusXRHandType::None;
	if (OculusXRInput::FOculusHandTracking::IsHandDominant(ControllerIndex, EOculusXRHandType::HandLeft))
	{
		DominantHand = EOculusXRHandType::HandLeft;
	}
	else if (OculusXRInput::FOculusHandTracking::IsHandDominant(ControllerIndex, EOculusXRHandType::HandRight))
	{
		DominantHand = EOculusXRHandType::HandRight;
	}
	return DominantHand;
}

bool UOculusXRInputFunctionLibrary::IsHandTrackingEnabled()
{
	return OculusXRInput::FOculusHandTracking::IsHandTrackingEnabled();
}

bool UOculusXRInputFunctionLibrary::IsHandPositionValid(const EOculusXRHandType DeviceHand, const int32 ControllerIndex)
{
	return OculusXRInput::FOculusHandTracking::IsHandPositionValid(ControllerIndex, DeviceHand);
}

FString UOculusXRInputFunctionLibrary::GetBoneName(EOculusXRBone BoneId)
{
	const auto ovrBoneId = OculusXRInput::FOculusHandTracking::ToOvrBone(BoneId);
	if (ovrBoneId == ovrpBoneId_Invalid)
	{
		return OculusXRInput::FOculusHandTracking::GetBoneName(static_cast<uint8>(EOculusXRBone::Invalid));
	}
	return OculusXRInput::FOculusHandTracking::GetBoneName(static_cast<uint8>(ovrBoneId));
}

void UOculusXRInputFunctionLibrary::PlayCurveHapticEffect(class UHapticFeedbackEffect_Curve* HapticEffect, EControllerHand Hand, EOculusXRHandHapticsLocation Location, float Scale, bool bLoop)
{
	OculusXRInput::FOculusXRControllerTracking::PlayHapticEffect(HapticEffect, Hand, Location, false, Scale, bLoop);
}

void UOculusXRInputFunctionLibrary::PlayBufferHapticEffect(class UHapticFeedbackEffect_Buffer* HapticEffect, EControllerHand Hand, EOculusXRHandHapticsLocation Location, float Scale, bool bLoop)
{
	OculusXRInput::FOculusXRControllerTracking::PlayHapticEffect(HapticEffect, Hand, Location, false, Scale, bLoop);
}

void UOculusXRInputFunctionLibrary::PlayAmplitudeEnvelopeHapticEffect(class UHapticFeedbackEffect_Buffer* HapticEffect, EControllerHand Hand)
{
	OculusXRInput::FOculusXRControllerTracking::PlayHapticEffect(Hand, HapticEffect->Amplitudes, HapticEffect->SampleRate, false, false);
}

void UOculusXRInputFunctionLibrary::PlaySoundWaveHapticEffect(class UHapticFeedbackEffect_SoundWave* HapticEffect, EControllerHand Hand, bool bAppend, float Scale, bool bLoop)
{
	OculusXRInput::FOculusXRControllerTracking::PlayHapticEffect(HapticEffect, Hand, EOculusXRHandHapticsLocation::Hand, bAppend, Scale, bLoop);
}

void UOculusXRInputFunctionLibrary::StopHapticEffect(EControllerHand Hand, EOculusXRHandHapticsLocation Location)
{
	OculusXRInput::FOculusXRControllerTracking::StopHapticEffect(Hand, Location);
}

void UOculusXRInputFunctionLibrary::SetHapticsByValue(const float Frequency, const float Amplitude, EControllerHand Hand, EOculusXRHandHapticsLocation Location)
{
	OculusXRInput::FOculusXRControllerTracking::SetHapticsByValue(Frequency, Amplitude, Hand, Location);
}

float UOculusXRInputFunctionLibrary::GetControllerSampleRateHz(EControllerHand Hand)
{
	return OculusXRInput::FOculusXRControllerTracking::GetControllerSampleRateHz(Hand);
}

int UOculusXRInputFunctionLibrary::GetMaxHapticDuration(EControllerHand Hand)
{
	return OculusXRInput::FOculusXRControllerTracking::GetMaxHapticDuration(Hand);
}

void UOculusXRInputFunctionLibrary::SetControllerDrivenHandPoses(EOculusXRControllerDrivenHandPoseTypes Type)
{
	return OculusXRInput::FOculusHandTracking::SetControllerDrivenHandPoses(Type);
}

EOculusXRControllerDrivenHandPoseTypes UOculusXRInputFunctionLibrary::GetControllerDrivenHandPoses()
{
	return OculusXRInput::FOculusHandTracking::ControllerDrivenHandType;
}
