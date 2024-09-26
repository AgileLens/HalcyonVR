// @lint-ignore-every LICENSELINT
// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OculusXRHMDModule.h"
#include "OculusXRInput.h"
#include "Engine/SkeletalMesh.h"
#include "Components/CapsuleComponent.h"

#include "OculusXRInputFunctionLibrary.h"

#define LOCTEXT_NAMESPACE "OculusHandTracking"

DEFINE_LOG_CATEGORY_STATIC(LogOcHandTracking, Log, All);

//-------------------------------------------------------------------------------------------------
// FOculusHandTracking
//-------------------------------------------------------------------------------------------------
namespace OculusXRInput
{
	class FOculusHandTracking
	{
	public:
		// Oculus Hand Tracking
		static FQuat GetBoneRotation(const int32 ControllerIndex, const EOculusXRHandType DeviceHand, const EOculusXRBone BoneId);
		static float GetHandScale(const int32 ControllerIndex, const EOculusXRHandType DeviceHand);
		static EOculusXRTrackingConfidence GetTrackingConfidence(const int32 ControllerIndex, const EOculusXRHandType DeviceHand);
		static EOculusXRTrackingConfidence GetFingerTrackingConfidence(const int32 ControllerIndex, const EOculusXRHandType DeviceHand, const EOculusHandAxes Finger); // OCULUS STRIKE
		static FTransform GetPointerPose(const int32 ControllerIndex, const EOculusXRHandType DeviceHand, const float WorldToMeters = 100.f);
		static bool IsPointerPoseValid(const int32 ControllerIndex, const EOculusXRHandType DeviceHand);
		static bool GetHandSkeletalMesh(USkeletalMesh* HandSkeletalMesh, const EOculusXRHandType SkeletonType, const EOculusXRHandType MeshType, const float WorldToMeters = 100.f);
		static TArray<FOculusXRCapsuleCollider> InitializeHandPhysics(const EOculusXRHandType SkeletonType, USkinnedMeshComponent* HandComponent, const float WorldToMeters = 100.f);
		static EOculusXRTrackingConfidence ToEOculusXRTrackingConfidence(ovrpTrackingConfidence Confidence);
		static bool IsHandTrackingEnabled();
		static bool IsHandDominant(const int32 ControllerIndex, const EOculusXRHandType DeviceHand);
		static bool IsHandPositionValid(int32 ControllerIndex, EOculusXRHandType DeviceHand);
		static void SetControllerDrivenHandPoses(const EOculusXRControllerDrivenHandPoseTypes Type);

		// Helper functions
		static ovrpBoneId ToOvrBone(EOculusXRBone Bone);
		static FString GetBoneName(uint8 Bone);
		static bool FindBoneDisplayName(FText& DisplayName, uint8 Bone);

		// Converters for converting from ovr bone space (should match up with ovr avatar)
		static FVector OvrBoneVectorToFVector(ovrpVector3f ovrpVector, float WorldToMeters);
		static FQuat OvrBoneQuatToFQuat(ovrpQuatf ovrpQuat);

		static EOculusXRControllerDrivenHandPoseTypes ControllerDrivenHandType;

	private:
		// Initializers for runtime hand assets
		static void InitializeHandMesh(USkeletalMesh* SkeletalMesh, const ovrpMesh* OvrMesh, const float WorldToMeters);
		static void InitializeHandSkeleton(USkeletalMesh* SkeletalMesh, const ovrpSkeleton2* OvrSkeleton, const float WorldToMeters);
	};

} // namespace OculusXRInput

#undef LOCTEXT_NAMESPACE
