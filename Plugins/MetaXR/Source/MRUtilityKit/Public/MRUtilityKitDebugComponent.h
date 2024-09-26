// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "GameFramework/Actor.h"
#include "MRUtilityKitDebugComponent.generated.h"

/**
 * Various debugging utilities for the scene.
 * This component can for example attached to the player pawn. The various methods can
 * then be called on input from the pawn.
 */
UCLASS(ClassGroup = MRUtilityKit, meta = (BlueprintSpawnableComponent, DisplayName = "MR Utility Kit Debug Component"))
class MRUTILITYKIT_API UMRUKDebugComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/**
	 * The gizmo to show when visualizing an anchor.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MR Utility Kit")
	TSubclassOf<AActor> GizmoActorClass = nullptr;

	/**
	 * The text to show when visualizing an anchor.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MR Utility Kit")
	TSubclassOf<AActor> TextActorClass = nullptr;

	/**
	 * The scale that should be applied to the gizmo before displaying it.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MR Utility Kit")
	FVector GizmoScale = FVector(0.1);

	/**
	 * The scale that should be applied to the text before displaying it.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MR Utility Kit")
	FVector TextScale = FVector(0.5);

	/**
	 * Shoot a ray and display the anchors coordinate system and labels that was hit by the ray if any.
	 * Call HideAnchor() to get rid of the displayed anchor.
	 * @param Origin The ray origin.
	 * @param Direction The ray direction.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void ShowAnchorAtRayHit(const FVector& Origin, const FVector& Direction);

	/**
	 * Hide the current anchor. This method needs only to be called to hide the anchor
	 * that was displayed by ShowAnchorAtRayHit().
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void HideAnchor();

	/**
	 * Shoot a ray and display the anchors space that was hit by the ray if any.
	 * Call HideAnchorSpace() to get rid of the displayed anchor space.
	 * @param Origin The ray origin.
	 * @param Direction The ray direction.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void ShowAnchorSpaceAtRayHit(const FVector& Origin, const FVector& Direction);

	/**
	 * Hide the current anchor space actor. This method needs only to be called to hide the
	 * anchor space that was displayed by ShowAnchorAtRayHit().
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void HideAnchorSpace();

public:
	UMRUKDebugComponent();

	void BeginPlay() override;
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UPROPERTY()
	TObjectPtr<AActor> ActiveGizmoActor = nullptr;
	UPROPERTY()
	TObjectPtr<AActor> ActiveTextActor = nullptr;
	UPROPERTY()
	TObjectPtr<AActor> ActiveAnchorSpaceActor = nullptr;

	void OrientTextActorToPlayer() const;
};
