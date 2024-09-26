// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "LiveLinkRetargetAsset.h"
#include "OculusXRMovementTypes.h"
#include "Containers/StaticArray.h"
#include "BonePose.h"

#include "OculusXRLiveLinkRetargetBodyAsset.generated.h"

UENUM(BlueprintType, meta = (DisplayName = "Axis"))
enum class EOculusXRAxis : uint8
{
	X = 0 UMETA(DisplayName = "X"),
	Y = 1 UMETA(DisplayName = "Y"),
	Z = 2 UMETA(DisplayName = "Z"),
	NegativeX = 3 UMETA(DisplayName = "-X"),
	NegativeY = 4 UMETA(DisplayName = "-Y"),
	NegativeZ = 5 UMETA(DisplayName = "-Z"),
};

UENUM(BlueprintType, meta = (DisplayName = "Retargeting mode"))
enum class EOculusXRRetargetingMode : uint8
{
	Full UMETA(DisplayName = "Rotations and positions"),
	Rotations UMETA(DisplayName = "Only rotations"),
	RotationsPlusRoot UMETA(DisplayName = "Rotations and root position"),
	RotationsPlusHips UMETA(DisplayName = "Rotations and hips position"),
	None UMETA(DisplayName = "Disabled"),
};

USTRUCT(BlueprintType, meta = (DisplayName = "Bone local correction"))
struct OCULUSXRMOVEMENT_API FOculusXRBoneCorrection
{
	GENERATED_BODY()

	FOculusXRBoneCorrection()
		: PositionOffset(FVector::ZeroVector), RotationOffset(FRotator::ZeroRotator){};

	/**
	 * Position offset in local space.
	 */
	UPROPERTY(EditAnywhere, Category = "OculusXR|Movement")
	FVector PositionOffset;

	/**
	 * Rotation offset in local space.
	 */
	UPROPERTY(EditAnywhere, Category = "OculusXR|Movement")
	FRotator RotationOffset;
};

USTRUCT(BlueprintType, meta = (DisplayName = "Correction applied to set of bones"))
struct OCULUSXRMOVEMENT_API FOculusXRBoneCorrectionSet
{
	GENERATED_BODY()

	FOculusXRBoneCorrectionSet(){};

	/**
	 * Set of bones to which the correction will be applied.
	 */
	UPROPERTY(EditAnywhere, Category = "OculusXR|Movement")
	TSet<EOculusXRBoneID> Bones;

	/**
	 * The correction for this set.
	 */
	UPROPERTY(EditAnywhere, Category = "OculusXR|Movement")
	FOculusXRBoneCorrection BoneCorrection;
};

UCLASS(Blueprintable, meta = (DisplayName = "MetaXR MovementSDK LiveLink retarget body asset"), ClassGroup = OculusXRHMD)
class OCULUSXRMOVEMENT_API UOculusXRLiveLinkRetargetBodyAsset : public ULiveLinkRetargetAsset
{
	GENERATED_UCLASS_BODY()

	virtual void Initialize() override;
	virtual void BuildPoseFromAnimationData(float DeltaTime, const FLiveLinkSkeletonStaticData* InSkeletonData, const FLiveLinkAnimationFrameData* InFrameData, FCompactPose& OutPose) override;

	/**
	 * Remapping from bone ID to target skeleton's bone name.
	 */
	UPROPERTY(EditDefaultsOnly, Category = "OculusXR|Movement")
	TMap<EOculusXRBoneID, FName> BoneRemapping;

	/**
	 * Correction applied to all bones.
	 */
	UPROPERTY(EditDefaultsOnly, Category = "OculusXR|Movement")
	FOculusXRBoneCorrection GlobalCorrection;

	/**
	 * Groups of local bone corrections.
	 *
	 * Order matters. A bone can be corrected multiple times.
	 * Corrections will be applied with the same order as in this array.
	 */
	UPROPERTY(EditDefaultsOnly, Category = "OculusXR|Movement")
	TArray<FOculusXRBoneCorrectionSet> LocalCorrections;

	/**
	 * Switch between retargeting modes.
	 */
	UPROPERTY(EditAnywhere, Category = "OculusXR|Movement")
	EOculusXRRetargetingMode RetargetingMode;

	/**
	 * Forward vector axis is the direction towards which the target mesh is oriented.
	 */
	UPROPERTY(EditDefaultsOnly, Category = "OculusXR|Movement")
	EOculusXRAxis ForwardMesh;

private:
	// Scale the source tracking positions. This will be initialized with WorldToMeters value.
	float Scale;

	// Movement tracking is oriented towards X axis.
	const EOculusXRAxis ForwardTracking{ EOculusXRAxis::X };

	// Transform from tracking to mesh space.
	FTransform TrackingSpaceToMeshSpace;

	// Correction applied to all bones
	FTransform GlobalBoneCorrection;

	// Correction applied per bone
	TStaticArray<FTransform, static_cast<uint8>(EOculusXRBoneID::COUNT)> LocalBoneCorrections;

	// Target skeleton's bone name per bone id
	TStaticArray<FName, static_cast<uint8>(EOculusXRBoneID::COUNT)> BoneNames;

	// Latest bone container serial number
	uint16 LastBoneContainerSerialNumber;

	// Compact pose indices per bone id
	TStaticArray<FCompactPoseBoneIndex, static_cast<uint8>(EOculusXRBoneID::COUNT)> LastSkeletonBoneRemapping{ InPlace, FCompactPoseBoneIndex(INDEX_NONE) };

	// Recalculate skeleton dependent mappings
	void OnBoneContainerChanged(const FBoneContainer& BoneContainer);
};
