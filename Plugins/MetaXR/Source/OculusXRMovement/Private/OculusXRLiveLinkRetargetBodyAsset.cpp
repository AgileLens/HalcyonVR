// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRLiveLinkRetargetBodyAsset.h"

#include "LiveLinkTypes.h"
#include "Algo/Accumulate.h"
#include "Algo/ForEach.h"
#include "Roles/LiveLinkAnimationTypes.h"
#include "BonePose.h"

#include "OculusXRHMDPrivate.h"
#include "OculusXRMovementLog.h"
#include "OculusXRMovement.h"

namespace
{
	// EOculusXRAxis to orientation of that direction
	FTransform DirectionTransform(EOculusXRAxis Direction)
	{
		FVector Dir = FVector::ZeroVector;
		const uint8 IndexOfDir = static_cast<uint8>(Direction);
		const double Sign = IndexOfDir < static_cast<uint8>(EOculusXRAxis::NegativeX) ? 1 : -1;
		Dir[IndexOfDir % 3] = Sign * 1.0;
		return FTransform(Dir.ToOrientationQuat());
	}
} // namespace

UOculusXRLiveLinkRetargetBodyAsset::UOculusXRLiveLinkRetargetBodyAsset(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), RetargetingMode(EOculusXRRetargetingMode::Full), ForwardMesh(EOculusXRAxis::X), Scale(100.f), TrackingSpaceToMeshSpace(FTransform::Identity), BoneNames(InPlace, NAME_None), LastBoneContainerSerialNumber(0)
{
}

void UOculusXRLiveLinkRetargetBodyAsset::Initialize()
{
	TrackingSpaceToMeshSpace = DirectionTransform(ForwardTracking).Inverse() * DirectionTransform(ForwardMesh);
	GlobalBoneCorrection = FTransform(GlobalCorrection.RotationOffset, GlobalCorrection.PositionOffset);

	for (uint8 BoneId = 0; BoneId < static_cast<uint8>(EOculusXRBoneID::COUNT); ++BoneId)
	{
		const FTransform LocalCorrectionCombined = Algo::Accumulate(LocalCorrections, FTransform::Identity, [BoneId](FTransform Correction, const FOculusXRBoneCorrectionSet& BoneCorrectionSet) {
			if (BoneCorrectionSet.Bones.Contains(static_cast<EOculusXRBoneID>(BoneId)))
			{
				Correction *= FTransform(BoneCorrectionSet.BoneCorrection.RotationOffset, BoneCorrectionSet.BoneCorrection.PositionOffset);
			}
			return Correction;
		});
		LocalBoneCorrections[BoneId] = LocalCorrectionCombined;

		const EOculusXRBoneID OculusBoneID = static_cast<EOculusXRBoneID>(BoneId);
		if (const FName* NameMapping = BoneRemapping.Find(OculusBoneID))
		{
			BoneNames[BoneId] = *NameMapping;
		}
		else
		{
			BoneNames[BoneId] = NAME_None;
			UE_LOG(LogOculusXRMovement, Warning, TEXT("Bone: %s isn't mapped."), *StaticEnum<EOculusXRBoneID>()->GetValueAsString(OculusBoneID));
		}
	}

	if (!OculusXRHMD::GetUnitScaleFactorFromSettings(UObject::GetWorld(), Scale))
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Cannot get world settings for body retargetting asset."));
	}

	LastBoneContainerSerialNumber = 0;
	Algo::ForEach(LastSkeletonBoneRemapping, [](FCompactPoseBoneIndex& BoneIndex) { BoneIndex = FCompactPoseBoneIndex(INDEX_NONE); });
}

void UOculusXRLiveLinkRetargetBodyAsset::BuildPoseFromAnimationData(float DeltaTime, const FLiveLinkSkeletonStaticData* InSkeletonData, const FLiveLinkAnimationFrameData* InFrameData, FCompactPose& OutPose)
{
	check(InFrameData);
	if (static_cast<int32>(EOculusXRBoneID::COUNT) != InFrameData->Transforms.Num())
	{
		UE_LOG(LogOculusXRMovement, Error, TEXT("Received wrong data of live link frame. This retargeting asset must be used with Meta MovementSDK Live Link source and Body subject. (received %d bone transforms, expected %d)"), InFrameData->Transforms.Num(), static_cast<int32>(EOculusXRBoneID::COUNT));
		return;
	}

	if ((LastBoneContainerSerialNumber != OutPose.GetBoneContainer().GetSerialNumber()) || (LastBoneContainerSerialNumber == 0))
	{
		OnBoneContainerChanged(OutPose.GetBoneContainer());
	}

	FCSPose<FCompactPose> MeshPoses;
	MeshPoses.InitPose(OutPose);
	for (uint8 BoneId = 0; BoneId < static_cast<uint8>(EOculusXRBoneID::COUNT); ++BoneId)
	{
		if (const FCompactPoseBoneIndex& BoneIndex = LastSkeletonBoneRemapping[BoneId]; BoneIndex != INDEX_NONE)
		{
			FTransform BoneTransform = InFrameData->Transforms[BoneId];
			BoneTransform.ScaleTranslation(Scale);
			BoneTransform *= TrackingSpaceToMeshSpace;
			BoneTransform = GlobalBoneCorrection * BoneTransform;
			BoneTransform = LocalBoneCorrections[BoneId] * BoneTransform;
			check(!BoneTransform.ContainsNaN());

			switch (RetargetingMode)
			{
				case EOculusXRRetargetingMode::Rotations:
					BoneTransform.SetLocation(MeshPoses.GetComponentSpaceTransform(BoneIndex).GetLocation());
					MeshPoses.SetComponentSpaceTransform(BoneIndex, BoneTransform);
					break;

				case EOculusXRRetargetingMode::RotationsPlusRoot:
					if (BoneId != static_cast<uint8>(EOculusXRBoneID::BodyRoot))
					{
						BoneTransform.SetLocation(MeshPoses.GetComponentSpaceTransform(BoneIndex).GetLocation());
					}
					MeshPoses.SetComponentSpaceTransform(BoneIndex, BoneTransform);
					break;

				case EOculusXRRetargetingMode::RotationsPlusHips:
					if (BoneId != static_cast<uint8>(EOculusXRBoneID::BodyHips))
					{
						BoneTransform.SetLocation(MeshPoses.GetComponentSpaceTransform(BoneIndex).GetLocation());
					}
					MeshPoses.SetComponentSpaceTransform(BoneIndex, BoneTransform);
					break;

				case EOculusXRRetargetingMode::Full:
					MeshPoses.SetComponentSpaceTransform(BoneIndex, BoneTransform);
					break;

				case EOculusXRRetargetingMode::None:
				default:
					break;
			}
		}
	}
	FCSPose<FCompactPose>::ConvertComponentPosesToLocalPosesSafe(MeshPoses, OutPose);
}

void UOculusXRLiveLinkRetargetBodyAsset::OnBoneContainerChanged(const FBoneContainer& BoneContainer)
{
	LastBoneContainerSerialNumber = 0;

	for (uint8 BoneId = 0; BoneId < static_cast<uint8>(EOculusXRBoneID::COUNT); ++BoneId)
	{
		const auto& BoneName = BoneNames[BoneId];
		if (BoneName.IsNone())
		{
			LastSkeletonBoneRemapping[BoneId] = FCompactPoseBoneIndex(INDEX_NONE);
			continue;
		}

		if (const int32 MeshIndex = BoneContainer.GetPoseBoneIndexForBoneName(BoneName); MeshIndex != INDEX_NONE)
		{
			LastSkeletonBoneRemapping[BoneId] = BoneContainer.MakeCompactPoseIndex(FMeshPoseBoneIndex(MeshIndex));
			if (LastSkeletonBoneRemapping[BoneId] == INDEX_NONE)
			{
				UE_LOG(LogOculusXRMovement, Warning, TEXT("Bone %s was intentionally mapped to %s. But this target doesn't exist in skeleton."), *StaticEnum<EOculusXRBoneID>()->GetValueAsString(static_cast<EOculusXRBoneID>(BoneId)), *BoneName.ToString());
			}
		}
	}

	LastBoneContainerSerialNumber = BoneContainer.GetSerialNumber();
}
