// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "MRUtilityKit.h"
#include "GameFramework/Actor.h"
#include "MRUtilityKitGuardian.h"
#include "MRUtilityKitGuardianSpawner.generated.h"

class AMRUKRoom;

/**
 * Show a guardian if the player gets close to any furniture or walls.
 */
UCLASS(ClassGroup = MRUtilityKit, meta = (DisplayName = "MR Utility Kit Guardian"))
class MRUTILITYKIT_API AMRUKGuardianSpawner : public AActor
{
	GENERATED_BODY()

public:
	AMRUKGuardianSpawner();

	/**
	 * Whether SpawnGuardian() should be called automatically after the mixed reality utility kit
	 * has been initialized.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	EMRUKSpawnMode SpawnMode = EMRUKSpawnMode::CurrentRoomOnly;

	/**
	 * How close the camera needs to come to a surface before the guardian appears.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	double GuardianDistance = 0.75;

	/**
	 * Whether the fading value should be calculated for the shader or not.
	 If fading is not needed this can save performance.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	bool EnableFade = true;

	/**
	 * Spawn the guardian. This will get called automatically after the mixed reality utility kit has
	 * been initialized if SpawnMode is set to something other than None.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void SpawnGuardians(AMRUKRoom* Room);

	/**
	 * Set the guardian material to a different one.
	 * @param Material The guardian material.
	 */
	UFUNCTION(BlueprintSetter, Category = "MR Utility Kit")
	void SetGuardianMaterial(UMaterialInstance* Material);

	/**
	 * Set the density of the grid.
	 * @param Density The grid density.
	 */
	UFUNCTION(BlueprintSetter, Category = "MR Utility Kit")
	void SetGridDensity(double Density);

public:
	void Tick(float DeltaSeconds) override;

protected:
	/**
	 * The material to use for the guardian. It needs to have a scalar parameter Fade
	 * and a vector parameter WallScale. If this material is not set a default one
	 * will be used.
	 */
	UPROPERTY(EditAnywhere, BlueprintSetter = SetGuardianMaterial, Category = "MR Utility Kit")
	TObjectPtr<UMaterialInstance> GuardianMaterial = nullptr;

	/**
	 * How dense the grid should be.
	 */
	UPROPERTY(EditAnywhere, BlueprintSetter = SetGridDensity, Category = "MR Utility Kit")
	double GridDensity = 2.0;

	void BeginPlay() override;
#if WITH_EDITOR
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
	// Room UUID to spawned actors in this room
	TMap<AMRUKRoom*, TArray<AMRUKGuardian*>> SpawnedGuardians;

	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> DynamicGuardianMaterial = nullptr;

	UFUNCTION()
	void DestroyGuardians(AMRUKRoom* Room);

	UFUNCTION()
	void OnRoomCreated(AMRUKRoom* Room);

	UFUNCTION()
	void OnRoomUpdated(AMRUKRoom* Room);

	UFUNCTION()
	void OnRoomRemoved(AMRUKRoom* Room);
};
