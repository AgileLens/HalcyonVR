// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "Components/PoseableMeshComponent.h"

#include "OculusXRMovementTypes.h"

#include "OculusXRBodyTrackingComponent.generated.h"

UENUM(BlueprintType)
enum class EOculusXRBodyTrackingMode : uint8
{
	PositionAndRotation,
	RotationOnly,
	NoTracking
};

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent, DisplayName = "OculusXR Body Tracking Component"), ClassGroup = OculusXRHMD)
class OCULUSXRMOVEMENT_API UOculusXRBodyTrackingComponent : public UPoseableMeshComponent
{
	GENERATED_BODY()
public:
	UOculusXRBodyTrackingComponent();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
	 * Restore all bones to their initial transforms
	 */
	UFUNCTION(BlueprintCallable, Category = "OculusXR|Movement")
	void ResetAllBoneTransforms();

	/**
	 * How are the results of body tracking applied to the mesh.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OculusXR|Movement")
	EOculusXRBodyTrackingMode BodyTrackingMode;

	/**
	 * The bone name associated with each bone ID.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "OculusXR|Movement")
	TMap<EOculusXRBoneID, FName> BoneNames;

	/**
	 * Do not apply body state to bones if confidence is lower than this value. Confidence is in range [0,1].
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OculusXR|Movement", meta = (ClampMin = "0", ClampMax = "1", UIMin = "0", UIMax = "1"))
	float ConfidenceThreshold;

private:
	bool InitializeBodyBones();

	// One meter in unreal world units.
	float WorldToMeters;

	// The index of each mapped bone after the discovery and association of bone names.
	TMap<EOculusXRBoneID, int32> MappedBoneIndices;

	// Saved body state.
	FOculusXRBodyState BodyState;

	// Stop the tracker just once.
	static int TrackingInstanceCount;
};
