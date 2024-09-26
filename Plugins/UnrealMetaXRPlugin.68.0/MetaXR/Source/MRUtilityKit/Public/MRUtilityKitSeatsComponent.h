// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MRUtilityKitSeatsComponent.generated.h"

/**
 * This component gets attached to Anchors which have seats available.
 * Seats can be used for example to spawn avatars in the correct locations.
 */
UCLASS(ClassGroup = MRUtilityKit)
class MRUTILITYKIT_API UMRUKSeatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MR Utility Kit")
	TArray<FTransform> SeatPoses;

	/**
	 * Calculate the seats poses that are available on the actor.
	 * This gets called automatically after the room has been loaded.
	 * However, it's okay to call this function again with a different SeatWidth.
	 * The seat poses will then get recalculated.
	 * @param SeatWidth The width of each seat.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void CalculateSeatPoses(double SeatWidth = 60.0);
};
