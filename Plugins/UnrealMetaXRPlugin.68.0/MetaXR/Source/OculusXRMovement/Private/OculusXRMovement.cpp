// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRMovement.h"
#include "OculusXRMovementLog.h"
#include "OculusXRMovementModule.h"
#include "OculusXRHMDPrivate.h"
#include "OculusXRHMD.h"
#include "OculusXRPluginWrapper.h"
#include "Logging/MessageLog.h"

#define LOCTEXT_NAMESPACE "OculusXRMovement"

bool OculusXRMovement::IsFullBodyTrackingEnabled()
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	bool bResult = false;

	ovrpBool IsEnabled = ovrpBool_False;
	ovrpResult TrackingEnabledResult = FOculusXRHMDModule::GetPluginWrapper().GetFullBodyTrackingEnabled(&IsEnabled);

	if (OVRP_SUCCESS(TrackingEnabledResult))
	{
		bResult = (IsEnabled == ovrpBool_True);
	}

	return bResult;
}

bool OculusXRMovement::GetBodyState(FOculusXRBodyState& outOculusXRBodyState, float WorldToMeters)
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	static_assert(ovrpBoneId_FullBody_End == static_cast<int>(EOculusXRBoneID::COUNT), "The size of the OVRPlugin Bone ID enum should be the same as the EOculusXRBoneID enum.");

	const auto AvailableJoints = IsFullBodyTrackingEnabled() ? ovrpBoneId_FullBody_End : ovrpBoneId_Body_End;
	checkf(outOculusXRBodyState.Joints.Num() >= AvailableJoints, TEXT("Not enough joints in FOculusXRBodyState::Joints array. You must have at least %d joints"), AvailableJoints);

	ovrpBodyState4 OVRBodyState;
	ovrpResult OVRBodyStateResult = FOculusXRHMDModule::GetPluginWrapper().GetBodyState4(ovrpStep_Render, OVRP_CURRENT_FRAMEINDEX, &OVRBodyState);
	ensureMsgf(OVRBodyStateResult != ovrpFailure_NotYetImplemented, TEXT("Body tracking is not implemented on this platform."));

	if (OVRP_SUCCESS(OVRBodyStateResult))
	{
		outOculusXRBodyState.IsActive = (OVRBodyState.IsActive == ovrpBool_True);
		outOculusXRBodyState.Confidence = OVRBodyState.Confidence;
		outOculusXRBodyState.SkeletonChangedCount = OVRBodyState.SkeletonChangedCount;
		outOculusXRBodyState.Time = static_cast<float>(OVRBodyState.Time);

		for (int i = 0; i < AvailableJoints; ++i)
		{
			ovrpBodyJointLocation OVRJointLocation = OVRBodyState.JointLocations[i];
			ovrpPosef OVRJointPose = OVRJointLocation.Pose;

			FOculusXRBodyJoint& OculusXRBodyJoint = outOculusXRBodyState.Joints[i];
			OculusXRBodyJoint.LocationFlags = OVRJointLocation.LocationFlags;
			OculusXRBodyJoint.bIsValid = OVRJointLocation.LocationFlags & (XRSpaceFlags::XR_SPACE_LOCATION_ORIENTATION_VALID_BIT | XRSpaceFlags::XR_SPACE_LOCATION_POSITION_VALID_BIT);
			OculusXRBodyJoint.Orientation = FRotator(OculusXRHMD::ToFQuat(OVRJointPose.Orientation));
			OculusXRBodyJoint.Position = OculusXRHMD::ToFVector(OVRJointPose.Position) * WorldToMeters;
		}
		if (AvailableJoints < outOculusXRBodyState.Joints.Num())
		{
			for (int i = AvailableJoints; i < outOculusXRBodyState.Joints.Num(); ++i)
			{
				outOculusXRBodyState.Joints[i].bIsValid = false;
			}
		}

		return true;
	}

	return false;
}

bool OculusXRMovement::GetBodySkeleton(FOculusXRBodySkeleton& outOculusXRBodyState, float WorldToMeters)
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	ovrpSkeleton3 OVRBodySkeleton = {};
	ovrpResult OVRBodyStateResult =
		FOculusXRHMDModule::GetPluginWrapper().GetSkeleton3(
			(IsFullBodyTrackingEnabled() ? ovrpSkeletonType_FullBody : ovrpSkeletonType_Body),
			&OVRBodySkeleton);
	if (OVRP_SUCCESS(OVRBodyStateResult))
	{
		checkf(outOculusXRBodyState.Bones.Num() >= static_cast<int32>(OVRBodySkeleton.NumBones),
			TEXT("Not enough bones in OVRBosySkeleton::Bones array. You must have at least %d joints"),
			OVRBodySkeleton.NumBones);

		outOculusXRBodyState.NumBones = OVRBodySkeleton.NumBones;
		for (uint32 i = 0; i < OVRBodySkeleton.NumBones; ++i)
		{
			ovrpBone OVRBone = OVRBodySkeleton.Bones[i];
			ovrpPosef OVRBonePose = OVRBone.Pose;

			FOculusXRBodySkeletonBone& OculusXRBone = outOculusXRBodyState.Bones[i];

			OculusXRBone.Orientation = FRotator(OculusXRHMD::ToFQuat(OVRBonePose.Orientation));
			OculusXRBone.Position = OculusXRHMD::ToFVector(OVRBonePose.Position) * WorldToMeters;

			if (OVRBone.ParentBoneIndex == ovrpBoneId_Invalid)
			{
				OculusXRBone.ParentBoneIndex = EOculusXRBoneID::None;
			}
			else
			{
				OculusXRBone.ParentBoneIndex = static_cast<EOculusXRBoneID>(OVRBone.ParentBoneIndex);
			}

			OculusXRBone.BoneId = static_cast<EOculusXRBoneID>(OVRBone.BoneId);
		}

		return true;
	}
	return false;
}

bool OculusXRMovement::IsBodyTrackingEnabled()
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	bool bResult = false;

	ovrpBool IsEnabled = ovrpBool_False;
	ovrpResult TrackingEnabledResult = FOculusXRHMDModule::GetPluginWrapper().GetBodyTrackingEnabled(&IsEnabled);

	if (OVRP_SUCCESS(TrackingEnabledResult))
	{
		bResult = (IsEnabled == ovrpBool_True);
	}

	return bResult;
}

bool OculusXRMovement::IsBodyTrackingSupported()
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	bool bResult = false;

	ovrpBool IsSupported = ovrpBool_False;
	ovrpResult TrackingSupportedResult = FOculusXRHMDModule::GetPluginWrapper().GetBodyTrackingSupported(&IsSupported);

	if (OVRP_SUCCESS(TrackingSupportedResult))
	{
		bResult = (IsSupported == ovrpBool_True);
	}

	return bResult;
}

bool OculusXRMovement::RequestBodyTrackingFidelity(EOculusXRBodyTrackingFidelity fidelity)
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	static_assert(static_cast<int>(EOculusXRBodyTrackingFidelity::Low) == static_cast<int>(ovrpBodyTrackingFidelity2::ovrpBodyTrackingFidelity2_Low), "EOculusXRBodyTrackingFidelity and ovrpBodyTrackingFidelity2 should be sync");
	static_assert(static_cast<int>(EOculusXRBodyTrackingFidelity::High) == static_cast<int>(ovrpBodyTrackingFidelity2::ovrpBodyTrackingFidelity2_High), "EOculusXRBodyTrackingFidelity and ovrpBodyTrackingFidelity2 should be sync");

	auto* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
	if (OculusXRHMD)
	{
		OculusXRHMD->GetSettings()->BodyTrackingFidelity = static_cast<EOculusXRHMDBodyTrackingFidelity>(fidelity);
	}

	return OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().RequestBodyTrackingFidelity(static_cast<ovrpBodyTrackingFidelity2>(fidelity)));
}

bool OculusXRMovement::ResetBodyTrackingCalibration()
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	return OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().ResetBodyTrackingCalibration());
}

bool OculusXRMovement::SuggestBodyTrackingCalibrationOverride(float height)
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	ovrpBodyTrackingCalibrationInfo calibrationInfo{ height };
	return OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().SuggestBodyTrackingCalibrationOverride(calibrationInfo));
}

bool OculusXRMovement::StartBodyTracking()
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	static_assert(static_cast<int>(EOculusXRBodyJointSet::UpperBody) == static_cast<int>(ovrpBodyJointSet::ovrpBodyJointSet_UpperBody), "EOculusXRBodyJointSet and ovrpBodyJointSet should be sync");
	static_assert(static_cast<int>(EOculusXRBodyJointSet::FullBody) == static_cast<int>(ovrpBodyJointSet::ovrpBodyJointSet_FullBody), "EOculusXRBodyJointSet and ovrpBodyJointSet should be sync");

	bool result = false;

	const auto* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
	if (OculusXRHMD)
	{
		const auto JointSet = OculusXRHMD->GetSettings()->BodyTrackingJointSet;
		if (!OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().StartBodyTracking2(static_cast<ovrpBodyJointSet>(JointSet))))
		{
			return false;
		}

		const auto Fidelity = OculusXRHMD->GetSettings()->BodyTrackingFidelity;
		FOculusXRHMDModule::GetPluginWrapper().RequestBodyTrackingFidelity(static_cast<ovrpBodyTrackingFidelity2>(Fidelity));
		return true;
	}
	else
	{
		return OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().StartBodyTracking2(ovrpBodyJointSet::ovrpBodyJointSet_UpperBody));
	}
}

bool OculusXRMovement::StartBodyTrackingByJointSet(EOculusXRBodyJointSet jointSet)
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	bool result = false;

	auto* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
	if (OculusXRHMD)
	{
		OculusXRHMD->GetSettings()->BodyTrackingJointSet = static_cast<EOculusXRHMDBodyJointSet>(jointSet);
		result = StartBodyTracking();
	}
	else
	{
		result = OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().StartBodyTracking2(static_cast<ovrpBodyJointSet>(jointSet)));
	}

	return result;
}

bool OculusXRMovement::StopBodyTracking()
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	FOculusXRHMDModule::GetPluginWrapper().RequestBodyTrackingFidelity(ovrpBodyTrackingFidelity2::ovrpBodyTrackingFidelity2_Low);
	return OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().StopBodyTracking());
}

bool OculusXRMovement::GetFaceState(FOculusXRFaceState& outOculusXRFaceState)
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	const auto blendShapeCount = ovrpFaceExpression2_Max;

	static_assert(blendShapeCount == static_cast<int>(EOculusXRFaceExpression::COUNT), "The size of the OVRPlugin Face Expression enum should be the same as the EOculusXRFaceExpression enum.");

	checkf(outOculusXRFaceState.ExpressionWeightConfidences.Num() >= ovrpFaceConfidence_Max, TEXT("Not enough expression weight confidences in FOculusXRFaceState::ExpressionWeightConfidences. Requires %d available elements in the array."), ovrpFaceConfidence_Max);
	checkf(outOculusXRFaceState.ExpressionWeights.Num() >= blendShapeCount, TEXT("Not enough expression weights in FOculusXRFaceState::ExpressionWeights. Requires %d available elements in the array."), blendShapeCount);

	ovrpFaceState2 OVRFaceState;
	ovrpResult OVRFaceStateResult = FOculusXRHMDModule::GetPluginWrapper().GetFaceState2(ovrpStep_Render, OVRP_CURRENT_FRAMEINDEX, &OVRFaceState);

	ensureMsgf(OVRFaceStateResult != ovrpFailure_NotYetImplemented, TEXT("Face tracking is not implemented on this platform."));

	if (OVRP_SUCCESS(OVRFaceStateResult))
	{
		outOculusXRFaceState.bIsValid = (OVRFaceState.Status.IsValid == ovrpBool_True);
		outOculusXRFaceState.bIsEyeFollowingBlendshapesValid = (OVRFaceState.Status.IsEyeFollowingBlendshapesValid == ovrpBool_True);
		outOculusXRFaceState.Time = static_cast<float>(OVRFaceState.Time);

		for (int i = 0; i < blendShapeCount; ++i)
		{
			outOculusXRFaceState.ExpressionWeights[i] = OVRFaceState.ExpressionWeights[i];
		}

		for (int i = 0; i < ovrpFaceConfidence_Max; ++i)
		{
			outOculusXRFaceState.ExpressionWeightConfidences[i] = OVRFaceState.ExpressionWeightConfidences[i];
		}

		outOculusXRFaceState.DataSource = static_cast<EFaceTrackingDataSource>(OVRFaceState.DataSource);

		return true;
	}

	return false;
}

bool OculusXRMovement::IsFaceTrackingEnabled()
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	bool bResult = false;

	ovrpBool IsEnabled = ovrpBool_False;
	ovrpResult TrackingEnabledResult = FOculusXRHMDModule::GetPluginWrapper().GetFaceTracking2Enabled(&IsEnabled);

	if (OVRP_SUCCESS(TrackingEnabledResult))
	{
		bResult = (IsEnabled == ovrpBool_True);
	}

	return bResult;
}

bool OculusXRMovement::IsFaceTrackingSupported()
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	bool bResult = false;

	ovrpBool IsSupported = ovrpBool_False;
	ovrpResult TrackingSupportedResult = FOculusXRHMDModule::GetPluginWrapper().GetFaceTracking2Supported(&IsSupported);

	if (OVRP_SUCCESS(TrackingSupportedResult))
	{
		bResult = (IsSupported == ovrpBool_True);
	}

	return bResult;
}

bool OculusXRMovement::StartFaceTracking()
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	const auto* OculusXRHMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
	if (OculusXRHMD)
	{
		ovrpFaceTrackingDataSource2 dataSources[ovrpFaceConstants_FaceTrackingDataSourcesCount];
		int count = 0;
		for (auto Iterator = OculusXRHMD->GetSettings()->FaceTrackingDataSource.CreateConstIterator(); Iterator; ++Iterator)
		{
			dataSources[count++] = static_cast<ovrpFaceTrackingDataSource2>(*Iterator);
		}
		return OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().StartFaceTracking2(dataSources, count));
	}
	return false;
}

bool OculusXRMovement::StopFaceTracking()
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	return OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().StopFaceTracking2());
}

bool OculusXRMovement::GetEyeGazesState(FOculusXREyeGazesState& outOculusXREyeGazesState, float WorldToMeters)
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	static_assert(ovrpEye_Count == (int)EOculusXREye::COUNT, "The size of the OVRPlugin Eye enum should be the same as the EOculusXREye enum.");

	checkf(outOculusXREyeGazesState.EyeGazes.Num() >= ovrpEye_Count, TEXT("Not enough eye gaze states in FOculusXREyeGazesState::EyeGazes. Requires %d available elements in the array."), ovrpEye_Count);

	ovrpEyeGazesState OVREyeGazesState;
	ovrpResult OVREyeGazesStateResult = FOculusXRHMDModule::GetPluginWrapper().GetEyeGazesState(ovrpStep_Render, OVRP_CURRENT_FRAMEINDEX, &OVREyeGazesState);
	ensureMsgf(OVREyeGazesStateResult != ovrpFailure_NotYetImplemented, TEXT("Eye tracking is not implemented on this platform."));

	if (OVRP_SUCCESS(OVREyeGazesStateResult))
	{
		outOculusXREyeGazesState.Time = static_cast<float>(OVREyeGazesState.Time);
		for (int i = 0; i < ovrpEye_Count; ++i)
		{
			const auto& EyeGazePose = OVREyeGazesState.EyeGazes[i].Pose;
			outOculusXREyeGazesState.EyeGazes[i].Orientation = FRotator(OculusXRHMD::ToFQuat(EyeGazePose.Orientation));
			outOculusXREyeGazesState.EyeGazes[i].Position = OculusXRHMD::ToFVector(EyeGazePose.Position) * WorldToMeters;
			outOculusXREyeGazesState.EyeGazes[i].bIsValid = (OVREyeGazesState.EyeGazes[i].IsValid == ovrpBool_True);
			outOculusXREyeGazesState.EyeGazes[i].Confidence = OVREyeGazesState.EyeGazes[i].Confidence;
		}

		return true;
	}

	return false;
}

bool OculusXRMovement::IsEyeTrackingEnabled()
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	bool bResult = false;

	ovrpBool IsEnabled = ovrpBool_False;
	ovrpResult TrackingEnabledResult = FOculusXRHMDModule::GetPluginWrapper().GetEyeTrackingEnabled(&IsEnabled);

	if (OVRP_SUCCESS(TrackingEnabledResult))
	{
		bResult = (IsEnabled == ovrpBool_True);
	}

	return bResult;
}

bool OculusXRMovement::IsEyeTrackingSupported()
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	bool bResult = false;

	ovrpBool IsSupported = ovrpBool_False;
	ovrpResult TrackingSupportedResult = FOculusXRHMDModule::GetPluginWrapper().GetEyeTrackingSupported(&IsSupported);

	if (OVRP_SUCCESS(TrackingSupportedResult))
	{
		bResult = (IsSupported == ovrpBool_True);
	}

	return bResult;
}

bool OculusXRMovement::StartEyeTracking()
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	return OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().StartEyeTracking());
}

bool OculusXRMovement::StopEyeTracking()
{
	// Prevent calling plugin functions if the plugin is not available
	if (!FOculusXRHMDModule::Get().IsOVRPluginAvailable())
	{
		return false;
	}

	return OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().StopEyeTracking());
}

#undef LOCTEXT_NAMESPACE
