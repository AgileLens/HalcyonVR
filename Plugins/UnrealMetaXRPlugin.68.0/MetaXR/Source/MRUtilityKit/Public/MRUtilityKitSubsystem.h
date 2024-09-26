// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "Dom/JsonObject.h"
#include "GameFramework/Actor.h"
#include "GameFramework/WorldSettings.h"
#include "MRUtilityKitRoom.h"
#include "MRUtilityKit.h"
#include "MRUtilityKitData.h"
#include "OculusXRSceneTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Tickable.h"

#include "MRUtilityKitSubsystem.generated.h"

/**
 * The Mixed Reality Utility Kit subsystem.
 *
 * This subsystem acts as a container for scene/anchor data. It has methods to load
 * the scene data from the device or a JSON file. After the scene data has been loaded
 * it will be stored inside the subsystem to make it possible to query the data from
 * everywhere. In addition, it offers methods to fulfill queries on the scene data
 * like ray casts or simple content placement.
 *
 * The subsystem only contains core functionality that is useful for most cases.
 * More specific functionality is part of actors. For example, if your goal is to spawn
 * meshes in the place of scene anchors you can place the AMRUKAnchorActorSpawner in the
 * level to do this. When a level loads you would first load the anchor data from the
 * device with this subsystem by calling LoadSceneFromDevice() and then the AMRUKAnchorActorSpawner
 * will listen for the subsystem to load the scene data and then spawn the actors accordingly.
 *
 * You can expect methods in this subsystem to take all loaded rooms into consideration when computing.
 * If you want to use a method only on a single specific room, there is most of the time a method
 * with the same name on the AMRUKRoom.
 */
UCLASS(ClassGroup = MRUtilityKit)
class MRUTILITYKIT_API UMRUKSubsystem : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoaded, bool, Success);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCaptureComplete, bool, Success);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoomCreated, AMRUKRoom*, Room);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoomUpdated, AMRUKRoom*, Room);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoomRemoved, AMRUKRoom*, Room);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoomEntered, AMRUKRoom*, Room);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoomExited, AMRUKRoom*, Room);

	/**
	 * The status of the scene loading. When loading from device this is an asynchronous process
	 * so will be in the Busy state until it moves to Complete or Failed.
	 */
	UPROPERTY(VisibleInstanceOnly, Transient, BlueprintReadOnly, Category = "MR Utility Kit")
	EMRUKInitStatus SceneLoadStatus = EMRUKInitStatus::None;

	/**
	 * An event that will trigger when a scene is loaded either from Device or from JSON.
	 * The Success parameter indicates whether the scene was loaded successfully or not.
	 */
	UPROPERTY(BlueprintAssignable, Category = "MR Utility Kit")
	FOnLoaded OnSceneLoaded;

	/**
	 * An event that gets fired after a room has been created.
	 */
	UPROPERTY(BlueprintAssignable, Category = "MR Utility Kit")
	FOnRoomCreated OnRoomCreated;

	/**
	 * An event that gets fired after a room has been updated.
	 */
	UPROPERTY(BlueprintAssignable, Category = "MR Utility Kit")
	FOnRoomUpdated OnRoomUpdated;

	/**
	 * An event that gets fired when a room gets removed.
	 */
	UPROPERTY(BlueprintAssignable, Category = "MR Utility Kit")
	FOnRoomRemoved OnRoomRemoved;

	/**
	 * Event that gets fired if the user enters this room.
	 * This is a system level event that gets only fired when working with room data that was loaded
	 * from the device. E.g. it will not fire on rooms that were loaded from JSON.
	 * This means that it may not be in sync with UMRUKSubsystem::GetCurrentRoom().
	 */
	UPROPERTY(BlueprintAssignable, Category = "MR Utility Kit")
	FOnRoomEntered OnRoomEntered;

	/**
	 * Event that gets fired if the user exit this room.
	 * This is a system level event that gets only fired when working with room data that was loaded
	 * from the device. E.g. it will not fire on rooms that were loaded from JSON.
	 * This means that it may not be in sync with UMRUKSubsystem::GetCurrentRoom().
	 */
	UPROPERTY(BlueprintAssignable, Category = "MR Utility Kit")
	FOnRoomExited OnRoomExited;

	/**
	 * An event that will trigger when the capture flow completed.
	 * The Success parameter indicates whether the scene was captured successfully or not.
	 */
	UPROPERTY(BlueprintAssignable, Category = "MR Utility Kit")
	FOnCaptureComplete OnCaptureComplete;

	/**
	 * Contains a list of rooms that are tracked by the mixed reality utility kit subsystem.
	 */
	UPROPERTY(VisibleInstanceOnly, Transient, BlueprintReadOnly, Category = "MR Utility Kit")
	TArray<TObjectPtr<AMRUKRoom>> Rooms;

	/**
	 * When world locking is enabled the position of the VR Pawn will be adjusted each frame to ensure
	 * the room anchors are where they should be relative to the camera position. This is necessary to
	 * ensure the position of the virtual objects in the world do not get out of sync with the real world.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	bool EnableWorldLock = true;


	/**
	 * Cast a ray and return the closest hit anchor in the scene.
	 * @param Origin      Origin The origin of the ray.
	 * @param Direction   Direction The direction of the ray.
	 * @param MaxDist     The maximum distance the ray should travel.
	 * @param LabelFilter The label filter can be used to include/exclude certain labels from the search.
	 * @param OutHit      The closest hit.
	 * @return            The anchor that the ray hit
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit", meta = (AutoCreateRefTerm = "LabelFilter"))
	AMRUKAnchor* Raycast(const FVector& Origin, const FVector& Direction, float MaxDist, const FMRUKLabelFilter& LabelFilter, FMRUKHit& OutHit);

	/**
	 * Cast a ray and collect hits against the volumes and plane bounds in every room in the scene.
	 * The order of the hits in the array is not specified.
	 * @param Origin      Origin The origin of the ray.
	 * @param Direction   Direction The direction of the ray.
	 * @param MaxDist     The maximum distance the ray should travel.
	 * @param LabelFilter The label filter can be used to include/exclude certain labels from the search.
	 * @param OutHits     The hits the ray collected.
	 * @param OutAnchors  The anchors that were hit. Each anchor in this array corresponds to a entry at the same position in OutHits.
	 * @return            Whether the ray hit anything
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit", meta = (AutoCreateRefTerm = "LabelFilter"))
	bool RaycastAll(const FVector& Origin, const FVector& Direction, float MaxDist, const FMRUKLabelFilter& LabelFilter, TArray<FMRUKHit>& OutHits, TArray<AMRUKAnchor*>& OutAnchors);

	/**
	 * Return the room that the headset is currently in. If the headset is not in any given room
	 * then it will return the room the headset was last in when this function was called.
	 * If the headset hasn't been in a valid room yet then return the first room in the list.
	 * If no rooms have been loaded yet then return null.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	AMRUKRoom* GetCurrentRoom() const;

	/**
	 * Save all rooms and anchors to JSON. This JSON representation can than later be used by
	 * LoadSceneFromJsonString() to load the scene again.
	 * @return the JSON string.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	FString SaveSceneToJsonString();

	/**
	 * Load rooms and anchors from a JSON representation.
	 * If the scene is already loaded the scene will be updated with the changes.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void LoadSceneFromJsonString(const FString& String);

	/**
	 * Load rooms and anchors from the device.
	 * If the scene is already loaded the scene will be updated with the changes.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void LoadSceneFromDevice(int MaxQueries = 64);


	/**
	 * Removes and clears every room.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void ClearScene();

	/**
	 *  Get the position on the surface that is closest to the given position with respect to the distance in all rooms.
	 *  @param WorldPosition      The position in world space from which the closest surface point should be found.
	 *  @param OutSurfacePosition The closest position on the closest surface if any. Otherwise zero.
	 *  @param LabelFilter        The label filter can be used to include/exclude certain labels from the search.
	 *  @param MaxDistance        The distance to which a closest surface position should be searched. Everything below or equal to zero will be treated as infinity.
	 *  @return                   The Anchor on which the closest surface position was found or a null pointer otherwise.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit", meta = (AutoCreateRefTerm = "LabelFilter"))
	AMRUKAnchor* TryGetClosestSurfacePosition(const FVector& WorldPosition, FVector& OutSurfacePosition, const FMRUKLabelFilter& LabelFilter, double MaxDistance = 0.0);

	/**
	 * Finds the closest seat given a ray.
	 * @param RayOrigin The origin of the ray.
	 * @param RayDirection The direction of the ray.
	 * @param OutSeatTransform The seat pose.
	 * @return If any seat was found the Anchor that has seats available will be returned. Otherwise a null pointer.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	AMRUKAnchor* TryGetClosestSeatPose(const FVector& RayOrigin, const FVector& RayDirection, FTransform& OutSeatTransform);

	/**
	 * Get a suggested pose (position & rotation) from a raycast to place objects on surfaces in the scene.
	 * There are different positioning modes available. Default just uses the position where the raycast
	 * hit the object. Edge snaps the position to the edge that is nearest to the user and Center simply
	 * centers the position on top of the surface.
	 * @param RayOrigin         The origin of the ray.
	 * @param RayDirection      The direction of the ray.
	 * @param MaxDist           The maximum distance the ray should travel.
	 * @param LabelFilter       The label filter can be used to include/exclude certain labels from the search.
	 * @param OutPose           The calculated pose.
	 * @param PositioningMethod The method that should be used for determining the position on the surface.
	 * @return                  The anchor that was hit by the ray if any. Otherwise a null pointer.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit", meta = (AutoCreateRefTerm = "LabelFilter"))
	AMRUKAnchor* GetBestPoseFromRaycast(const FVector& RayOrigin, const FVector& RayDirection, double MaxDist, const FMRUKLabelFilter& LabelFilter, FTransform& OutPose, EMRUKPositioningMethod PositioningMethod = EMRUKPositioningMethod::Default);

	/**
	 * Return the longest wall in the current room that has no other walls behind it.
	 * @param Tolerance The tolerance to use when determining wall that are behind.
	 * @return          The wall anchor that is the key wall in the room.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	AMRUKAnchor* GetKeyWall(double Tolerance = 0.1);

	/**
	 * Return the largest surface for a given label in the current room.
	 * @param Label The label of the surfaces to search in.
	 * @return      The anchor that has the largest surface if any. Otherwise, a null pointer.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	AMRUKAnchor* GetLargestSurface(const FString& Label);

	/**
	 * Checks if the given position is on or inside of any scene volume in the rooms.
	 * All rooms will be checked and the first anchors scene volume that has the point on or inside it will be returned.
	 * @param WorldPosition      The position in world space to check
	 * @param TestVerticalBounds Whether the vertical bounds should be checked or not
	 * @param Tolerance          Tolerance
	 * @return					 The anchor the WorldPosition is in. A null pointer otherwise.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	AMRUKAnchor* IsPositionInSceneVolume(const FVector& WorldPosition, bool TestVerticalBounds = true, double Tolerance = 0.0);

	/**
	 * Spawn meshes on the position of the anchors of each room.
	 * The actors should have Z as up Y as right and X as forward.
	 * The pivot point should be in the bottom center.
	 * @param SpawnGroups                A map which tells to spawn which actor to a given label.
	 * @param ProceduralMaterial         Material to apply on top of the procedural mesh if any.
	 * @param CutHoleLabels		         Labels for which the generated mesh should have holes. Only works with planes.
	 * @param ShouldFallbackToProcedural Whether or not it should by default fallback to generating a procedural mesh if no actor class has been specified for a label.
	 * @return                           The spawned actors.
	 */
	UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage = "Use AMRUKAnchorActorSpawner instead."), Category = "MR Utility Kit")
	TArray<AActor*> SpawnInterior(const TMap<FString, FMRUKSpawnGroup>& SpawnGroups, const TArray<FString>& CutHoleLabels, UMaterialInterface* ProceduralMaterial = nullptr, bool ShouldFallbackToProcedural = true);

	/**
	 * Spawn meshes on the position of the anchors of each room from a random stream.
	 * The actors should have Z as up Y as right and X as forward.
	 * The pivot point should be in the bottom center.
	 * @param SpawnGroups                A map which tells to spawn which actor to a given label.
	 * @param RandomStream               A random generator to choose randomly between actor classes if there a multiple for one label.
	 * @param CutHoleLabels		         Labels for which the generated mesh should have holes. Only works with planes.
	 * @param ProceduralMaterial         Material to apply on top of the procedural mesh if any.
	 * @param ShouldFallbackToProcedural Whether or not it should by default fallback to generating a procedural mesh if no actor class has been specified for a label.
	 * @return                           The spawned actors.
	 */
	UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage = "Use AMRUKAnchorActorSpawner instead."), Category = "MR Utility Kit")
	TArray<AActor*> SpawnInteriorFromStream(const TMap<FString, FMRUKSpawnGroup>& SpawnGroups, const FRandomStream& RandomStream, const TArray<FString>& CutHoleLabels, UMaterialInterface* ProceduralMaterial = nullptr, bool ShouldFallbackToProcedural = true);

	/**
	 * Launch the scene capture. After a successful capture the scene should be updated.
	 * @return Whether the capture was successful.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool LaunchSceneCapture();

public:

	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	TSharedRef<FJsonObject> JsonSerialize();
	void UnregisterRoom(AMRUKRoom* Room);
	// Calculate the bounds of an Actor class and return it, the result is saved in a cache for faster lookup.
	FBox GetActorClassBounds(TSubclassOf<AActor> Actor);
	UOculusXRRoomLayoutManagerComponent* GetRoomLayoutManager();

private:
	AMRUKRoom* SpawnRoom();

	void FinishedLoading(bool Success);

	// FTickableGameObject interface
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual ETickableTickType GetTickableTickType() const override { return (HasAnyFlags(RF_ClassDefaultObject) ? ETickableTickType::Never : ETickableTickType::Conditional); }
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(UMRUKSubsystem, STATGROUP_Tickables); }
	virtual UWorld* GetTickableGameObjectWorld() const override { return GetWorld(); }
	// ~FTickableGameObject interface

	UFUNCTION()
	void SceneDataLoadedComplete(bool Success);
	UFUNCTION()
	void UpdatedSceneDataLoadedComplete(bool Success);
	UFUNCTION()
	void SceneCaptureComplete(FOculusXRUInt64 RequestId, bool bSuccess);

	UPROPERTY()
	TObjectPtr<UMRUKSceneData> SceneData = nullptr;

	UPROPERTY()
	AActor* RoomLayoutManagerActor = nullptr;
	UPROPERTY()
	UOculusXRRoomLayoutManagerComponent* RoomLayoutManager = nullptr;
	UPROPERTY()
	mutable AMRUKRoom* CachedCurrentRoom = nullptr;
	mutable int64 CachedCurrentRoomFrame = 0;
	UPROPERTY()
	AActor* PositionGenerator = nullptr;

	TMap<TSubclassOf<AActor>, FBox> ActorClassBoundsCache;
};
