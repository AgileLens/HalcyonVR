// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRBodyTrackingComponent.h"

#include "Engine/SkeletalMesh.h"
#include "DrawDebugHelpers.h"
#include "OculusXRHMD.h"
#include "OculusXRPluginWrapper.h"
#include "OculusXRMovementFunctionLibrary.h"
#include "OculusXRMovementLog.h"
#include "OculusXRTelemetryMovementEvents.h"

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
static TAutoConsoleVariable<int32> CVarOVRBodyDebugDraw(
	TEXT("ovr.BodyDebugDraw"),
	0,
	TEXT("Enables or disables debug drawing for body tracking.\n")
		TEXT("<=0: disabled (no drawing)\n")
			TEXT("  1: enabled  (debug drawing)\n"));
#endif

int UOculusXRBodyTrackingComponent::TrackingInstanceCount = 0;

UOculusXRBodyTrackingComponent::UOculusXRBodyTrackingComponent()
	: BodyTrackingMode(EOculusXRBodyTrackingMode::PositionAndRotation)
	, ConfidenceThreshold(0.f)
	, WorldToMeters(100.f)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	// Setup defaults
	BoneNames.Add(EOculusXRBoneID::BodyRoot, "Root");
	BoneNames.Add(EOculusXRBoneID::BodyHips, "Hips");
	BoneNames.Add(EOculusXRBoneID::BodySpineLower, "SpineLower");
	BoneNames.Add(EOculusXRBoneID::BodySpineMiddle, "SpineMiddle");
	BoneNames.Add(EOculusXRBoneID::BodySpineUpper, "SpineUpper");
	BoneNames.Add(EOculusXRBoneID::BodyChest, "Chest");
	BoneNames.Add(EOculusXRBoneID::BodyNeck, "Neck");
	BoneNames.Add(EOculusXRBoneID::BodyHead, "Head");
	BoneNames.Add(EOculusXRBoneID::BodyLeftShoulder, "LeftShoulder");
	BoneNames.Add(EOculusXRBoneID::BodyLeftScapula, "LeftScapula");
	BoneNames.Add(EOculusXRBoneID::BodyLeftArmUpper, "LeftArmUpper");
	BoneNames.Add(EOculusXRBoneID::BodyLeftArmLower, "LeftArmLower");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandWristTwist, "LeftHandWristTwist");
	BoneNames.Add(EOculusXRBoneID::BodyRightShoulder, "RightShoulder");
	BoneNames.Add(EOculusXRBoneID::BodyRightScapula, "RightScapula");
	BoneNames.Add(EOculusXRBoneID::BodyRightArmUpper, "RightArmUpper");
	BoneNames.Add(EOculusXRBoneID::BodyRightArmLower, "RightArmLower");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandWristTwist, "RightHandWristTwist");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandPalm, "LeftHandPalm");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandWrist, "LeftHandWrist");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandThumbMetacarpal, "LeftHandThumbMetacarpal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandThumbProximal, "LeftHandThumbProximal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandThumbDistal, "LeftHandThumbDistal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandThumbTip, "LeftHandThumbTip");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandIndexMetacarpal, "LeftHandIndexMetacarpal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandIndexProximal, "LeftHandIndexProximal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandIndexIntermediate, "LeftHandIndexIntermediate");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandIndexDistal, "LeftHandIndexDistal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandIndexTip, "LeftHandIndexTip");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandMiddleMetacarpal, "LeftHandMiddleMetacarpal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandMiddleProximal, "LeftHandMiddleProximal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandMiddleIntermediate, "LeftHandMiddleIntermediate");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandMiddleDistal, "LeftHandMiddleDistal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandMiddleTip, "LeftHandMiddleTip");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandRingMetacarpal, "LeftHandRingMetacarpal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandRingProximal, "LeftHandRingProximal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandRingIntermediate, "LeftHandRingIntermediate");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandRingDistal, "LeftHandRingDistal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandRingTip, "LeftHandRingTip");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandLittleMetacarpal, "LeftHandLittleMetacarpal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandLittleProximal, "LeftHandLittleProximal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandLittleIntermediate, "LeftHandLittleIntermediate");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandLittleDistal, "LeftHandLittleDistal");
	BoneNames.Add(EOculusXRBoneID::BodyLeftHandLittleTip, "LeftHandLittleTip");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandPalm, "RightHandPalm");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandWrist, "RightHandWrist");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandThumbMetacarpal, "RightHandThumbMetacarpal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandThumbProximal, "RightHandThumbProximal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandThumbDistal, "RightHandThumbDistal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandThumbTip, "RightHandThumbTip");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandIndexMetacarpal, "RightHandIndexMetacarpal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandIndexProximal, "RightHandIndexProximal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandIndexIntermediate, "RightHandIndexIntermediate");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandIndexDistal, "RightHandIndexDistal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandIndexTip, "RightHandIndexTip");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandMiddleMetacarpal, "RightHandMiddleMetacarpal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandMiddleProximal, "RightHandMiddleProximal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandMiddleIntermediate, "RightHandMiddleIntermediate");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandMiddleDistal, "RightHandMiddleDistal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandMiddleTip, "RightHandMiddleTip");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandRingMetacarpal, "RightHandRingMetacarpal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandRingProximal, "RightHandRingProximal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandRingIntermediate, "RightHandRingIntermediate");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandRingDistal, "RightHandRingDistal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandRingTip, "RightHandRingTip");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandLittleMetacarpal, "RightHandLittleMetacarpal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandLittleProximal, "RightHandLittleProximal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandLittleIntermediate, "RightHandLittleIntermediate");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandLittleDistal, "RightHandLittleDistal");
	BoneNames.Add(EOculusXRBoneID::BodyRightHandLittleTip, "RightHandLittleTip");
	BoneNames.Add(EOculusXRBoneID::BodyLeftUpperLeg, "LeftUpperLeg");
	BoneNames.Add(EOculusXRBoneID::BodyLeftLowerLeg, "LeftLowerLeg");
	BoneNames.Add(EOculusXRBoneID::BodyLeftFootAnkleTwist, "LeftFootAnkleTwist");
	BoneNames.Add(EOculusXRBoneID::BodyLeftFootAnkle, "LeftFootAnkle");
	BoneNames.Add(EOculusXRBoneID::BodyLeftFootSubtalar, "LeftFootSubtalar");
	BoneNames.Add(EOculusXRBoneID::BodyLeftFootTransverse, "LeftFootTransverse");
	BoneNames.Add(EOculusXRBoneID::BodyLeftFootBall, "LeftFootBall");
	BoneNames.Add(EOculusXRBoneID::BodyRightUpperLeg, "RightUpperLeg");
	BoneNames.Add(EOculusXRBoneID::BodyRightLowerLeg, "RightLowerLeg");
	BoneNames.Add(EOculusXRBoneID::BodyRightFootAnkleTwist, "RightFootAnkleTwist");
	BoneNames.Add(EOculusXRBoneID::BodyRightFootAnkle, "RightFootAnkle");
	BoneNames.Add(EOculusXRBoneID::BodyRightFootSubtalar, "RightFootSubtalar");
	BoneNames.Add(EOculusXRBoneID::BodyRightFootTransverse, "RightFootTransverse");
	BoneNames.Add(EOculusXRBoneID::BodyRightFootBall, "RightFootBall");

	OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FMovementSDKBodyStart>(static_cast<int>(GetTypeHash(this)));
}

void UOculusXRBodyTrackingComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!UOculusXRMovementFunctionLibrary::IsBodyTrackingSupported())
	{
		// Early exit if body tracking isn't supported
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Body tracking is not supported. (%s:%s)"), *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}

	if (!OculusXRHMD::GetUnitScaleFactorFromSettings(GetWorld(), WorldToMeters))
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Cannot get world settings. (%s:%s)"), *GetOwner()->GetName(), *GetName());
	}

	if (!InitializeBodyBones())
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Failed to initialize body data. (%s: %s)"), *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}

	if (!UOculusXRMovementFunctionLibrary::StartBodyTracking())
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Failed to start body tracking. (%s: %s)"), *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}
	++TrackingInstanceCount;
}

void UOculusXRBodyTrackingComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (IsComponentTickEnabled())
	{
		if (--TrackingInstanceCount == 0)
		{
			if (!UOculusXRMovementFunctionLibrary::StopBodyTracking())
			{
				UE_LOG(LogOculusXRMovement, Warning, TEXT("Failed to stop body tracking. (%s: %s)"), *GetOwner()->GetName(), *GetName());
			}
		}
	}

	Super::EndPlay(EndPlayReason);
}

void UOculusXRBodyTrackingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (UOculusXRMovementFunctionLibrary::TryGetBodyState(BodyState, WorldToMeters))
	{
		if (BodyState.IsActive && BodyState.Confidence > ConfidenceThreshold)
		{
			for (int i = 0; i < BodyState.Joints.Num(); ++i)
			{
				const FOculusXRBodyJoint& Joint = BodyState.Joints[i];
				if (!Joint.bIsValid)
				{
					continue;
				}

				const FVector& Position = Joint.Position;
				const FRotator& Orientation = Joint.Orientation;

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
				if (CVarOVRBodyDebugDraw.GetValueOnGameThread() > 0)
				{
					const FTransform& ParentTransform = GetOwner()->GetActorTransform();

					FVector DebugPosition = ParentTransform.TransformPosition(Position);
					FRotator DebugOrientation = ParentTransform.TransformRotation(Orientation.Quaternion()).Rotator();

					DrawDebugLine(GetWorld(), DebugPosition, DebugPosition + DebugOrientation.Quaternion().GetUpVector(), FColor::Blue);
					DrawDebugLine(GetWorld(), DebugPosition, DebugPosition + DebugOrientation.Quaternion().GetForwardVector(), FColor::Red);
					DrawDebugLine(GetWorld(), DebugPosition, DebugPosition + DebugOrientation.Quaternion().GetRightVector(), FColor::Green);
				}
#endif

				int32* BoneIndex = MappedBoneIndices.Find(static_cast<EOculusXRBoneID>(i));
				if (BoneIndex != nullptr)
				{
					switch (BodyTrackingMode)
					{
						case EOculusXRBodyTrackingMode::PositionAndRotation:
							SetBoneTransformByName(BoneNames[static_cast<EOculusXRBoneID>(i)], FTransform(Orientation, Position), EBoneSpaces::ComponentSpace);
							break;
						case EOculusXRBodyTrackingMode::RotationOnly:
							SetBoneRotationByName(BoneNames[static_cast<EOculusXRBoneID>(i)], Orientation, EBoneSpaces::ComponentSpace);
							break;
						case EOculusXRBodyTrackingMode::NoTracking:
							break;
					}
				}
			}
		}
	}
	else
	{
		UE_LOG(LogOculusXRMovement, Verbose, TEXT("Failed to get body state (%s:%s)."), *GetOwner()->GetName(), *GetName());
	}
}

void UOculusXRBodyTrackingComponent::ResetAllBoneTransforms()
{
	for (int i = 0; i < BodyState.Joints.Num(); ++i)
	{
		int32* BoneIndex = MappedBoneIndices.Find(static_cast<EOculusXRBoneID>(i));
		if (BoneIndex != nullptr)
		{
			ResetBoneTransformByName(BoneNames[static_cast<EOculusXRBoneID>(i)]);
		}
	}
}

bool UOculusXRBodyTrackingComponent::InitializeBodyBones()
{
	USkeletalMesh* BodyMesh = Cast<USkeletalMesh>(GetSkinnedAsset());
	if (BodyMesh == nullptr)
	{
		UE_LOG(LogOculusXRMovement, Display, TEXT("No SkeletalMesh in this component."));
		return false;
	}

	for (const auto& it : BoneNames)
	{
		int32 BoneIndex = GetBoneIndex(it.Value);

		if (BoneIndex == INDEX_NONE)
		{
			UE_LOG(LogOculusXRMovement, Display, TEXT("Could not find bone %s in skeletal mesh %s"), *StaticEnum<EOculusXRBoneID>()->GetValueAsString(it.Key), *BodyMesh->GetName());
		}
		else
		{
			MappedBoneIndices.Add(it.Key, BoneIndex);
		}
	}

	return true;
}
