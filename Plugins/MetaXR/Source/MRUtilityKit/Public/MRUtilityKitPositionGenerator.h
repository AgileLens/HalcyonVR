// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "MRUtilityKitRoom.h"
#include "GameFramework/Actor.h"
#include "MRUtilityKitPositionGenerator.generated.h"

USTRUCT(BlueprintType)
struct FMRUKRandomSpawnSettings
{
	GENERATED_BODY()

	/**
	 * When the scene data is loaded, this controls what room(s) the position generator will be used in.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	EMRUKRoomFilter RoomFilter = EMRUKRoomFilter::CurrentRoomOnly;

	/**
	 * When an actor instance is reference here, this actor will be moved around.
	 * If you'd need to spawn new actors, use ActorClass.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	AActor* ActorInstance;

	/**
	 * Reference the specific actor class for spawning.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	TSubclassOf<AActor> ActorClass;

	/**
	 * How many instances to spawn at the random generated position per room.
	 * Note: If using an ActorInstance this property is ignored
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	int SpawnAmount = 8;

	/**
	 * Maximum number of times to attempt spawning/moving an object before giving up.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	int MaxIterations = 1000;

	/**
	 * The type of surface by which to limit the generation.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	EMRUKSpawnLocation SpawnLocations = EMRUKSpawnLocation::Floating;

	/**
	 * The labels to include or exclude.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	FMRUKLabelFilter Labels;

	/**
	 * If enabled then the spawn position will be checked to make sure there is no overlap with physics colliders including themselves.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	bool CheckOverlaps = true;

	/**
	 * Required free space for the object.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	float OverrideBounds = -1;

	/**
	 * The CollisionChannel to use.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	TEnumAsByte<ECollisionChannel> CollisionChannel = ECC_WorldStatic;

	/**
	 * The clearance distance required in front of the surface in order for it to be considered a valid spawn position.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	float SurfaceClearanceDistance = 0.1f;
};

UCLASS()
class MRUTILITYKIT_API AMRUtilityKitPositionGenerator : public AActor
{
	GENERATED_BODY()

public:
	static bool CanSpawnBox(const UWorld* World, const FBox& Box, const FVector& SpawnPosition, const FQuat& SpawnRotation, const FCollisionQueryParams& QueryParams, ECollisionChannel CollisionChannel);

	/**
	 * Generates a set of random positions on the surface of a given spawn location, while ensuring that the generated positions
	 * are at least `MinDistanceToEdge` away from any edges and follow the other settings specified in `SpawnSettings`.
	 * @param OutTransforms An array of transforms representing the generated positions.
	 * @return A boolean value indicating whether valid positions were found. If no valid positions could be found, `OutTransforms` will be empty.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool GenerateRandomPositionsOnSurface(TArray<FTransform>& OutTransforms);

	/**
	 * Generates a set of random positions on the surface of a given spawn location, while ensuring that the generated positions
	 * are at least `MinDistanceToEdge` away from any edges and follow the other settings specified in `SpawnSettings` in the
	 * give room.
	 * @param Room The room where the positions should be generated in.
	 * @param OutTransforms An array of transforms representing the generated positions.
	 * @return A boolean value indicating whether valid positions were found. If no valid positions could be found, `OutTransforms` will be empty.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool GenerateRandomPositionsOnSurfaceInRoom(AMRUKRoom* Room, TArray<FTransform>& OutTransforms);

	/**
	 * Whether GenerateRandomPositionsOnSurface() should be called automatically after the mixed reality utility kit has been initialized
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	bool RunOnStart = true;

	/**
	 * Settings that should be used when generating random positions.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	FMRUKRandomSpawnSettings RandomSpawnSettings;

protected:
	virtual void BeginPlay() override;

private:
	virtual UWorld* GetTickableGameObjectWorld() const { return GetWorld(); }

	UFUNCTION()
	void SceneLoaded(bool Success);
};
