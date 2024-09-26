// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "MRUtilityKitBlobShadowComponent.generated.h"

/**
 * Adds a blob shadow below the actor.
 * The blob shadow will position and resize itself automatically during runtime.
 */
UCLASS(ClassGroup = MRUtilityKit, Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent, DisplayName = "MR Utility Kit Blob Shadow Component"))
class MRUTILITYKIT_API UMRUKBlobShadowComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	/**
	 * Controls the look of the blob shadow corners (0 = squared corners, 1 = rounded corners).
	 */
	UPROPERTY(Category = "MR Utility Kit|Aspect", EditAnywhere, BlueprintReadWrite, meta = (UIMin = "0", UIMax = "1"))
	float Roundness = 1.0f;

	/**
	 * Controls the look of the blob shadow alpha (0 = fully opaque, 1 = gradient from the center).
	 */
	UPROPERTY(Category = "MR Utility Kit|Aspect", EditAnywhere, BlueprintReadWrite, meta = (UIMin = "0", UIMax = "1"))
	float Gradient = 0.544f;

	/**
	 * Controls the curve of the blob shadow alpha gradient (only available if Gradient > 0).
	 */
	UPROPERTY(Category = "MR Utility Kit|Aspect", EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "Gradient > 0"))
	float GradientPower = 3.0f;

	/**
	 * Increase or decrease the calculated blob shadow size by a fixed amount.
	 */
	UPROPERTY(Category = "MR Utility Kit", EditAnywhere, BlueprintReadWrite)
	float ExtraExtent = -10.0f;

	/**
	 * Maximum distance the actor can be away from the ground until the blob shadow is not shown anymore.
	 */
	UPROPERTY(Category = "MR Utility Kit", EditAnywhere, BlueprintReadWrite)
	float MaxVerticalDistance = 100.f;

	/**
	 * Distance from the ground until the blob shadow starts to fade.
	 */
	UPROPERTY(Category = "MR Utility Kit", EditAnywhere, BlueprintReadWrite)
	float FadeDistance = 20.f;

	/**
	 * Only callable in the editor from the scene, will update the blob shadow size, position and material parameters
	 * to give a preview how the blob shadow would look like.
	 */
	UFUNCTION(Category = "MR Utility Kit", CallInEditor)
	void UpdatePlaneSizeAndPosition();

public:
	UMRUKBlobShadowComponent();

	void BeginPlay() override;
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void ComputeOwner2DBounds(FVector& Origin, FVector2D& Extent, double& Yaw) const;

protected:
	UPROPERTY()
	UMaterialInstanceDynamic* DynMaterial;
};
