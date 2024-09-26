// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OculusXRInputFunctionLibrary.h"
#include "Components/PoseableMeshComponent.h"
#include "OculusXRHandComponent.generated.h"

UENUM(BlueprintType)
enum class EOculusXRConfidenceBehavior : uint8
{
	None,
	HideActor
};

UENUM(BlueprintType)
enum class EOculusXRSystemGestureBehavior : uint8
{
	None,
	SwapMaterial
};

static const FQuat HandRootFixupRotation = FQuat(-0.5f, -0.5f, 0.5f, 0.5f);

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent), ClassGroup = OculusHand)
class OCULUSXRINPUT_API UOculusXRHandComponent : public UPoseableMeshComponent
{
	GENERATED_UCLASS_BODY()

public:
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** The hand skeleton that will be loaded */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HandProperties")
	EOculusXRHandType SkeletonType;

	/** The hand mesh that will be applied to the skeleton */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HandProperties")
	EOculusXRHandType MeshType;

	/** Behavior for when hand tracking loses high confidence tracking */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HandProperties")
	EOculusXRConfidenceBehavior ConfidenceBehavior = EOculusXRConfidenceBehavior::HideActor;

	/** Behavior for when the system gesture is actived */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HandProperties")
	EOculusXRSystemGestureBehavior SystemGestureBehavior = EOculusXRSystemGestureBehavior::SwapMaterial;

	/** Material that gets applied to the hands when the system gesture is active */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HandProperties")
	class UMaterialInterface* SystemGestureMaterial;

	/** Whether or not to initialize physics capsules on the skeletal mesh */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HandProperties")
	bool bInitializePhysics;

	/** Whether or not the hand scale should update based on values from the runtime to match the users hand scale */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HandProperties")
	bool bUpdateHandScale;

	/** Material override for the runtime skeletal mesh */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HandProperties")
	class UMaterialInterface* MaterialOverride;

	/** Bone mapping for custom hand skeletal meshes */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CustomSkeletalMesh")
	TMap<EOculusXRBone, FName> BoneNameMappings;

	/** List of capsule colliders created for the skeletal mesh */
	UPROPERTY(BlueprintReadOnly, Category = "HandProperties")
	TArray<FOculusXRCapsuleCollider> CollisionCapsules;

	/** Whether or not the runtime skeletal mesh has been loaded and initialized */
	UPROPERTY(BlueprintReadOnly, Category = "HandProperties")
	bool bSkeletalMeshInitialized = false;

protected:
	virtual void SystemGesturePressed();
	virtual void SystemGestureReleased();

private:
	/** Whether or not this component has authority within the frame */
	bool bHasAuthority;

	/** Whether or not a custom hand mesh is being used */
	bool bCustomHandMesh = false;

	/** Whether or not the physics capsules have been initialized */
	bool bInitializedPhysics = false;

	USkeletalMesh* RuntimeSkeletalMesh;

	UMaterialInterface* CachedBaseMaterial;

	void InitializeSkeletalMesh();

	void UpdateBonePose();
};
