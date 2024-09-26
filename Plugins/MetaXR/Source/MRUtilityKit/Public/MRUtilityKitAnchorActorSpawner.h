// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "GameFramework/Actor.h"
#include "MRUtilityKit.h"
#include "MRUtilityKitAnchorActorSpawner.generated.h"

extern const FName GMRUK_PROCEDURAL_ANCHOR_MESH_TAG;

class AMRUKAnchor;
/**
 * Spawns meshes on anchor positions.
 * If the out of the box functionality doesn't match your goals the AnchorActorSpawner provides way to inject
 * custom spawning logic into every step of it's spawning process by overwriting certain functions.
 * For this please take a look at SpawnAnchorActorsForRoom(), SpawnAnchorActorForLabel(), and SpawnAnchorActor().
 */
UCLASS(ClassGroup = MRUtilityKit, meta = (DisplayName = "MR Utility Kit Anchor Actor Spawner"))
class MRUTILITYKIT_API AMRUKAnchorActorSpawner : public AActor
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteriorSpawned, AMRUKRoom*, Room);

	/**
	 * Event that gets fired when the interior spawner finished spawning actors.
	 */
	UPROPERTY(BlueprintAssignable, Category = "MR Utility Kit")
	FOnInteriorSpawned OnActorsSpawned;

	/**
	 * Seed to use for the random generator that decideds wich actor class to
	 * spawn if there a given multiple for a label.
	 * negative values will have the effect to initialize the random generator
	 * to a random seed.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	int AnchorRandomSpawnSeed = -1;

	/**
	 * Whether actors should be spawned automatically after the mixed reality
	 * utility kit has been initialized. This should not be changed after the scene has been loaded.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	EMRUKSpawnMode SpawnMode = EMRUKSpawnMode::CurrentRoomOnly;

	/**
	 * Material to use when falling back to procedural material.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	UMaterialInterface* ProceduralMaterial = nullptr;

	/**
	 * Whether or not the spawner should fallback to procedural meshes in case no actor
	 * class has been defined for a label. This behaviour can be overwritten on the label
	 * basis in SpawnGroups.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	bool ShouldFallbackToProcedural = true;

	/**
	 * Labels for which holes should be created in the parents plane mesh.
	 * E.g. if holes are needed in the walls where the windows and doors are, specify DOOR_FRAME and WINDOW_FRAME.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	TArray<FString> CutHoleLabels;

	/**
	 * A map of Actor classes to spawn for the given label.
	 */
	UPROPERTY(EditAnywhere, Category = "MR Utility Kit")
	TMap<FString, FMRUKSpawnGroup> SpawnGroups{
		{ FMRUKLabels::Bed, {} },
		{ FMRUKLabels::Ceiling, {} },
		{ FMRUKLabels::Couch, {} },
		{ FMRUKLabels::DoorFrame, {} },
		{ FMRUKLabels::Floor, {} },
		{ FMRUKLabels::Lamp, {} },
		{ FMRUKLabels::Plant, {} },
		{ FMRUKLabels::Screen, {} },
		{ FMRUKLabels::Storage, {} },
		{ FMRUKLabels::Table, {} },
		{ FMRUKLabels::WallArt, {} },
		{ FMRUKLabels::WallFace, {} },
		{ FMRUKLabels::InvisibleWallFace, { {}, EMRUKSpawnerSelectionMode::Random, EMRUKFallbackToProceduralOverwrite::NoFallback } },
		{ FMRUKLabels::WindowFrame, {} },
		{ FMRUKLabels::Other, {} },
	};

	/**
	 * Spawns the meshes for the given labels above on the anchor positions in each room.
	 * There might be multiple actor classes for a give label. If thats the case a actor class will be chosen radomly.
	 * The seed for this random generator can be set by AnchorRandomSpawnSeed.
	 * This function will be called automatically after the mixed reality utility kit initialized unless
	 * the option SpawnOnStart is set to false.
	 * If there is no actor class specified for a label then a procedural mesh matching the anchors volume and plane
	 * will be generated.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void SpawnActors(AMRUKRoom* Room);

	/**
	 * Return all spawned actors from the give room.
	 * @param Room The room from which the actors should be returned
	 * @param Actors The spawned actors.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void GetSpawnedActorsByRoom(AMRUKRoom* Room, TArray<AActor*>& Actors);

	/**
	 * Return all spawned actors from all rooms.
	 * @param Actors The spawned actors.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void GetSpawnedActors(TArray<AActor*>& Actors);

protected:
	/**
	 * This method gets called by the AnchorActorSpawner when it wants to spawn actors and procedural meshes in the room.
	 * It's possible to overwrite this function in Blueprint or C++ to implement custom spawning logic.
	 * The protected methods in the AnchorActorSpawner contain helper functions which can be useful when implementing
	 * a custom spawning logic. When implementing a custom spawning logic you may want to use SpawnAnchorActor() to spawn
	 * the actual actor and take care of it's orientation and scaling to match the anchors bounds.
	 * @param Room The room to spawn actors for.
	 * @param RandomStream A random stream to be used with the random selection mode.
	 * @return A list of all spawned actors.
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "MR Utility Kit")
	TArray<AActor*> SpawnAnchorActorsInRoom(AMRUKRoom* Room, const FRandomStream& RandomStream);

	virtual TArray<AActor*> SpawnAnchorActorsInRoom_Implementation(AMRUKRoom* Room, const FRandomStream& RandomStream);

	/**
	 * This method gets called by the default implementation of the SpawnAnchorActorsInRoom() for every label that should spawn a actor.
	 * By overwriting this function it is possible to inject custom spawning logic for actors on a per label basis.
	 * When implementing a custom spawning logic you may want to use SpawnAnchorActor() to spawn the actual actor and take care of it's
	 * orientation and scaling to match the anchors bounds.
	 * @param Anchor The anchor to spawn a actor for.
	 * @param Label The label to spawn a actor for.
	 * @param SpawnGroup Information on which actor should be spawned.
	 * @param RandomStream A random stream for implementing the random selection logic.
	 * @return The spawned actor.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MR Utility Kit")
	AActor* SpawnAnchorActorForLabel(AMRUKAnchor* Anchor, const FString& Label, const FMRUKSpawnGroup& SpawnGroup, const FRandomStream& RandomStream);

	virtual AActor* SpawnAnchorActorForLabel_Implementation(AMRUKAnchor* Anchor, const FString& Label, const FMRUKSpawnGroup& SpawnGroup, const FRandomStream& RandomStream);

	/**
	 * This method gets called by the default implementation of SpawnAnchorActorForLabel() to spawn the anchor and orient and scale
	 * it correct to the given anchor. If you are planning to implement a custom spawning logic you likely want to use this function
	 * in the end to actually spawn the actor as it takes care of orientation and scaling of the actor with regards to the anchor bounds.
	 * @param Anchor The anchor to spawn the actor for.
	 * @param SpawnActor Information on which actor should be spawned.
	 * @return The spawned actor.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MR Utility Kit")
	AActor* SpawnAnchorActor(AMRUKAnchor* Anchor, const FMRUKSpawnActor& SpawnActor);

	virtual AActor* SpawnAnchorActor_Implementation(AMRUKAnchor* Anchor, const FMRUKSpawnActor& SpawnActor);

	/**
	 * Override this method to inject custom scaling logic into the orientation process of an actor. The scale that this method returns
	 * gets used to scale the actor that will be spawned.
	 * @param Anchor The anchor for which the actor gets spawned.
	 * @param SpawnedActor The actor that gets spawned.
	 * @param StretchedScale The scale that would need to be applied to the actor to make it match with the bounding box of the anchor.
	 *                       In case it's a plane anchor only the X and Y component of the scale are relevant.
	 * @return The scale that should be applied to the actor. In case it's a plane anchor only the X and Y component are relevant.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MR Utility Kit")
	FVector ComputeCustomScaling(AMRUKAnchor* Anchor, AActor* SpawnedActor, const FVector& StretchedScale);

	virtual FVector ComputeCustomScaling_Implementation(AMRUKAnchor* Anchor, AActor* SpawnedActor, const FVector& StretchedScale);

	/**
	 * Override this method to inject custom actor selection logic. This will be called for every actor that gets spawned by the AMRUKAnchorActorSpawner.
	 * @param Anchor The anchor for which a actor should be spawned
	 * @param SpawnGroup The group of actors that can be used for decision making.
	 * @param RandomStream A random stream to randomize outputs if necessary.
	 * @param OutSpawnActor The actor which should be spawned.
	 * @return Whether the selection process was successful or not.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MR Utility Kit")
	bool SelectSpawnActorCustom(AMRUKAnchor* Anchor, const FMRUKSpawnGroup& SpawnGroup, const FRandomStream& RandomStream, FMRUKSpawnActor& OutSpawnActor);

	virtual bool SelectSpawnActorCustom_Implementation(AMRUKAnchor* Anchor, const FMRUKSpawnGroup& SpawnGroup, const FRandomStream& RandomStream, FMRUKSpawnActor& OutSpawnActor);

	/**
	 * Override this method to inject custom scaling logic into the orientation process of an actor. The scale that this method returns
	 * gets used to scale the actor that will be spawned.
	 * @param Anchor The anchor for which the actor gets spawned.
	 * @param Actor The actor that gets spawned.
	 * @param ChildBounds the rotated bounding box of the actor that should be spawned. For planes only X and Y components are relevant.
	 * @param Scale The scale that will be applied to the actor that will be spawned in place of the anchor. For planes only X and Y components are relevant.
	 * @return The offset that should be applied to the actor. In case it's a plane anchor only the X and Y component are relevant.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MR Utility Kit")
	FVector ComputeCustomAlign(AMRUKAnchor* Anchor, AActor* Actor, const FBox& ChildBounds, const FVector& Scale);

	virtual FVector ComputeCustomAlign_Implementation(AMRUKAnchor* Anchor, AActor* Actor, const FBox& ChildBounds, const FVector& Scale);

	/**
	 * Check if for the given SpawnGroup a procedural mesh should be spawned.
	 * @param SpawnGroup The spawn group to check
	 * @return Whether a procedural mesh should be spawned or not
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool ShouldAnchorFallbackToProceduralMesh(const FMRUKSpawnGroup& SpawnGroup) const;

	/**
	 * Check if there should be spawned a actor for the given label. This function may return false in case
	 * the spawner should fallback to a procedural mesh.
	 * @param Anchor The anchor where the actor should be spawned
	 * @param Label The label of the anchor
	 * @param OutSpawnGroup Will be set in case a actor should be spawned
	 * @return Whether or not a actor should be spawned for the anchor
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool ShouldSpawnActorForAnchor(AMRUKAnchor* Anchor, const FString& Label, FMRUKSpawnGroup& OutSpawnGroup) const;

	/**
	 * Spawn a procedural mesh for all walls if no wall actor is given to the spawner.
	 * This will take care of generating seamless UVs for the walls.
	 * @param Room The room to spawn in.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	TArray<AActor*> SpawnProceduralMeshesOnWallsIfNoWallActorGiven(AMRUKRoom* Room);

	/**
	 * Spawn a procedural mesh for the floor if no floor actor is given to the spawner.
	 * @param Room The room to spawn in.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	AActor* SpawnProceduralMeshOnFloorIfNoFloorActorGiven(AMRUKRoom* Room);

	/**
	 * Spawn a procedural mesh for the ceiling if no ceiling actor is given to the spawner.
	 * @param Room The room to spawn in.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	AActor* SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven(AMRUKRoom* Room);

	/**
	 * Spawn a procedural mesh for the given anchor if the settings on the AnchorActorSpawner say so.
	 * @param Anchor The anchor for which the procedural mesh should be spawned
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	AActor* SpawnProceduralMeshForAnchorIfNeeded(AMRUKAnchor* Anchor);

	/**
	 * Spawn procedural meshes for every anchor that needs them. Including walls, ceiling and floor.
	 * The method determines if procedural mesh should be spawned or not based on the settings of the
	 * AnchorActorSpawner.
	 * @param Room The room to spawn in.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	TArray<AActor*> SpawnProceduralMeshesInRoom(AMRUKRoom* Room);

	/**
	 * Select the SpawnActor based on the size that matches best the anchor bounds.
	 * @param Anchor The anchor for which a actor should be spawned.
	 * @param SpawnGroup The spawn group.
	 * @param OutSpawnActor The found spawn actor.
	 * @return True if a SpawnActor could be found. Otherwise, false.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool SelectSpawnActorClosestSize(AMRUKAnchor* Anchor, const FMRUKSpawnGroup& SpawnGroup, FMRUKSpawnActor& OutSpawnActor);

	/**
	 * Select the SpawnActor randomly
	 * @param SpawnGroup The spawn group.
	 * @param RandomStream The random stream to use for the random selection.
	 * @param OutSpawnActor The found spawn actor.
	 * @return True if a SpawnActor could be found. Otherwise, false.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool SelectSpawnActorRandom(const FMRUKSpawnGroup& SpawnGroup, const FRandomStream& RandomStream, FMRUKSpawnActor& OutSpawnActor);

	/**
	 * Select a SpawnActor from the SpawnGroup with respect to the given selection mode in SpawnGroup.
	 * @param Anchor The anchor for which the actor should be spawned.
	 * @param SpawnGroup The spawn group.
	 * @param RandomStream The random stream
	 * @param OutSpawnActor The found spawn actor
	 * @return True if a spawn actor has been found. Otherwise, false.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool SelectSpawnActorFromSpawnGroup(AMRUKAnchor* Anchor, const FMRUKSpawnGroup& SpawnGroup, const FRandomStream& RandomStream, FMRUKSpawnActor& OutSpawnActor);

	/**
	 * Orient and scale the given actor to the anchors plane or volume bounds.
	 * @param Anchor The anchor
	 * @param Actor The actor which should be oriented and scaled to the given anchor.
	 * @param ScalingMode The scaling mode that should be used when doing the matching.
	 * @param bCalculateFacingDirection Whether or not the facing direction of the anchor should be calculated and used for the orientation process.
	 * @param bMatchAspectRatio Whether or not the aspect ratio of the anchor should be matched.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void AttachAndFitActorToAnchor(AMRUKAnchor* Anchor, AActor* Actor, EMRUKSpawnerScalingMode ScalingMode, EMRUKAlignMode AlignMode, bool bCalculateFacingDirection, bool bMatchAspectRatio);

	void BeginPlay() override;

	UFUNCTION()
	void OnRoomCreated(AMRUKRoom* Room);

	UFUNCTION()
	void OnRoomUpdated(AMRUKRoom* Room);

	UFUNCTION()
	void OnRoomRemoved(AMRUKRoom* Room);

	UFUNCTION()
	void RemoveActors(AMRUKRoom* Room);

private:
	// Room UUID to spawned actors in this room
	TMap<AMRUKRoom*, TArray<AActor*>> SpawnedActors;

	int32 LastSeed = -1;
};
