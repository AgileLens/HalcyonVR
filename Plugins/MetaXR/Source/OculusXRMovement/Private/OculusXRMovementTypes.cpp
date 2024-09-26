// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRMovementTypes.h"
#include "OculusXRHMDPrivate.h"
#include "OculusXRHMD.h"

FOculusXRBodyJoint::FOculusXRBodyJoint()
	: LocationFlags(0)
	, bIsValid(false)
	, Orientation(FRotator::ZeroRotator)
	, Position(FVector::ZeroVector)
{
}

FOculusXRBodyState::FOculusXRBodyState()
	: IsActive(false)
	, Confidence(0)
	, SkeletonChangedCount(0)
	, Time(0.f)
{
	Joints.SetNum(static_cast<int32>(EOculusXRBoneID::COUNT));
}

FOculusXRBodySkeletonBone::FOculusXRBodySkeletonBone()
	: Orientation(FRotator::ZeroRotator)
	, Position(FVector::ZeroVector)
	, BoneId(EOculusXRBoneID::None)
	, ParentBoneIndex(EOculusXRBoneID::None)
{
}

FOculusXRBodySkeleton::FOculusXRBodySkeleton()
	: NumBones(0)
{
	Bones.SetNum(static_cast<int32>(EOculusXRBoneID::COUNT));
}

FOculusXRBodySkeletonState::FOculusXRBodySkeletonState()
	: BodyState()
	, SkeletonState()
{
}

FOculusXRFaceState::FOculusXRFaceState()
	: bIsValid(false)
	, bIsEyeFollowingBlendshapesValid(false)
	, Time(0.f)
{
	ExpressionWeights.SetNum(static_cast<int32>(EOculusXRFaceExpression::COUNT));
	ExpressionWeightConfidences.SetNum(static_cast<int32>(EOculusXRFaceConfidence::COUNT));
}

FOculusXRFaceExpressionModifier::FOculusXRFaceExpressionModifier()
	: MinValue(0.f)
	, MaxValue(1.f)
	, Multiplier(1.f)
{
}

FOculusXREyeGazeState::FOculusXREyeGazeState()
	: Orientation(FRotator::ZeroRotator)
	, Position(FVector::ZeroVector)
	, Confidence(0.f)
	, bIsValid(false)
{
}

FOculusXREyeGazesState::FOculusXREyeGazesState()
	: Time(0.f)
{
	EyeGazes.SetNum(static_cast<int32>(EOculusXREye::COUNT));
}
