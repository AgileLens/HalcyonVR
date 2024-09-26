// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "GameFramework/Actor.h"
#include "Dom/JsonObject.h"
#include "MRUtilityKit.h"
#include "OculusXRAnchorTypes.h"
#include "MRUtilityKitRoom.generated.h"

class UMRUKRoomData;

UENUM(BlueprintType)
enum class EMRUKSpawnLocation : uint8
{
	Floating UMETA(DisplayName = "Floating"),				   // Spawn somewhere floating in the free space within the room
	AnySurface UMETA(DisplayName = "Any surface"),			   // Spawn on any surface (i.e. a combination of all 3 options below)
	VerticalSurfaces UMETA(DisplayName = "Vertical surfaces"), // Spawn only on vertical surfaces such as walls, windows, wall art, doors, etc...
	OnTopOfSurface UMETA(DisplayName = "On top of surfaces"),  // Spawn on surfaces facing upwards such as ground, top of tables, beds, couches, etc...
	HangingDown UMETA(DisplayName = "Hanging down")			   // Spawn on surfaces facing downwards such as the ceiling
};

enum class EMRUKBoxSide : uint8
{
	XPos,
	XNeg,
	YPos,
	YNeg,
	ZPos,
	ZNeg,
};

UENUM(BlueprintType)
enum class EMRUKRoomFilter : uint8
{
	None,
	CurrentRoomOnly,
	AllRooms
};

/**
 * Method to use when determining the position and rotation for the best pose.
 */
UENUM(BlueprintType)
enum class EMRUKPositioningMethod : uint8
{
	/**
	 * Center the object on the surface.
	 */
	Center = 0,
	/**
	 * Snap the object to edge which is closest to the user.
	 */
	Edge,
	/**
	 * Use the location where the ray hit the object as the location.
	 * The rotation is dependent on the objects shape. For example for walls
	 * the hit normal from the raycast will be used. For floors the rotation
	 * will be towards the user and for volumes that got hit on the top the
	 * rotation will be towards the longest edge that is nearest to the player.
	 */
	Default,
};

USTRUCT(BlueprintType)
struct FMRUKAnchorWithPlaneUVs
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "MR Utility Kit")
	TObjectPtr<AMRUKAnchor> Anchor;

	UPROPERTY(BlueprintReadOnly, Category = "MR Utility Kit")
	TArray<FMRUKPlaneUV> PlaneUVs;
};

UCLASS(ClassGroup = MRUtilityKit, meta = (DisplayName = "MR Utility Kit Room Actor"))
class MRUTILITYKIT_API AMRUKRoom : public AActor
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAnchorUpdated, AMRUKAnchor*, Anchor);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAnchorCreated, AMRUKAnchor*, Anchor);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAnchorRemoved, AMRUKAnchor*, Anchor);

	/**
	 * The space handle of this anchor
	 */
	UPROPERTY(VisibleInstanceOnly, Transient, BlueprintReadOnly, Category = "MR Utility Kit")
	FOculusXRUInt64 SpaceHandle;

	/**
	 * The anchors UUID
	 */
	UPROPERTY(VisibleInstanceOnly, Transient, BlueprintReadOnly, Category = "MR Utility Kit")
	FOculusXRUUID AnchorUUID;

	/**
	 * Event that gets fired if a anchor in this room was updated.
	 * E.g. volume or plane changed.
	 */
	UPROPERTY(BlueprintAssignable, Category = "MR Utility Kit")
	FOnAnchorUpdated OnAnchorUpdated;

	/**
	 * Event that gets fired if a new anchor was created in this room.
	 */
	UPROPERTY(BlueprintAssignable, Category = "MR Utility Kit")
	FOnAnchorCreated OnAnchorCreated;

	/**
	 * Event that gets fired if a anchor gets removed from this room.
	 */
	UPROPERTY(BlueprintAssignable, Category = "MR Utility Kit")
	FOnAnchorRemoved OnAnchorRemoved;

	/**
	 * Bounds of the room.
	 */
	UPROPERTY(VisibleInstanceOnly, Transient, BlueprintReadOnly, Category = "MR Utility Kit")
	FBox RoomBounds;

	/**
	 * Edges of the room.
	 */
	UPROPERTY(VisibleInstanceOnly, Transient, BlueprintReadOnly, Category = "MR Utility Kit")
	TArray<FVector> RoomEdges;

	/**
	 * The floor anchor of this room.
	 */
	UPROPERTY(VisibleInstanceOnly, Transient, BlueprintReadOnly, Category = "MR Utility Kit")
	TObjectPtr<AMRUKAnchor> FloorAnchor;

	/**
	 * The ceiling anchor of this room.
	 */
	UPROPERTY(VisibleInstanceOnly, Transient, BlueprintReadOnly, Category = "MR Utility Kit")
	TObjectPtr<AMRUKAnchor> CeilingAnchor;

	/**
	 * The wall anchors of this room.
	 */
	UPROPERTY(VisibleInstanceOnly, Transient, BlueprintReadOnly, Category = "MR Utility Kit")
	TArray<TObjectPtr<AMRUKAnchor>> WallAnchors;

	/**
	 * The global mesh anchor of this room.
	 */
	UPROPERTY(VisibleInstanceOnly, Transient, BlueprintReadOnly, Category = "MR Utility Kit")
	TObjectPtr<AMRUKAnchor> GlobalMeshAnchor;

	/**
	 * All anchors which are possible to sit on.
	 */
	UPROPERTY(VisibleInstanceOnly, Transient, BlueprintReadOnly, Category = "MR Utility Kit")
	TArray<TObjectPtr<AMRUKAnchor>> SeatAnchors;

	/**
	 * All anchors of this room.
	 */
	UPROPERTY(VisibleInstanceOnly, Transient, BlueprintReadOnly, Category = "MR Utility Kit")
	TArray<TObjectPtr<AMRUKAnchor>> AllAnchors;


	/**
	 * Check whether the position is inside the room or not.
	 * @param Position           The position in world space to check.
	 * @param TestVerticalBounds Whether the room should be constrained by vertical bounds or not in the check.
	 * @return                   Whether the position is inside the room or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool IsPositionInRoom(const FVector& Position, bool TestVerticalBounds = true);

	/**
	 * Generate a uniform random position within the room.
	 * @param OutPosition			Contains the randomly generated position.
	 * @param MinDistanceToSurface	The minimum distance between the generated position and the closest surface/volume.
	 * @param AvoidVolumes			If true then the position will not be inside a volume and min distance away from it.
	 * @return						Return true if success otherwise false. If this fails it can be because the min distance to surface is too large.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool GenerateRandomPositionInRoom(FVector& OutPosition, float MinDistanceToSurface = 0.0f, bool AvoidVolumes = false);

	/**
	 * Generate a uniform random position within the room from a random stream.
	 * @param OutPosition			Contains the randomly generated position.
	 * @param RandomStream			A random generator used to generate the position on the plane.
	 * @param MinDistanceToSurface	The minimum distance between the generated position and the closest surface/volume.
	 * @param AvoidVolumes			If true then the position will not be inside a volume and min distance away from it.
	 * @return						Return true if success otherwise false. If this fails it can be because the min distance to surface is too large.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool GenerateRandomPositionInRoomFromStream(FVector& OutPosition, const FRandomStream& RandomStream, float MinDistanceToSurface = 0.0f, bool AvoidVolumes = false);

	/**
	 * Generates a random position on the surface of a given spawn location, while ensuring that the generated position is at least `MinDistanceToEdge` away from any edges. The `LabelFilter` parameter allows you to specify which types of surfaces should be considered for generating the random position.
	 *
	 * @param SpawnLocation			The location where the random position should be generated.
	 * @param MinDistanceToEdge		The minimum distance from the edge that the generated position must have.
	 * @param LabelFilter			A filter that specifies which types of surfaces should be considered for generating the random position.
	 * @param OutPosition			The generated position.
	 * @param OutNormal				The normal vector of the generated position.
	 * @return						A boolean value indicating whether a valid position was found. If no valid position could be found, both `OutPosition` and `OutNormal` will be set to zero vectors.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool GenerateRandomPositionOnSurface(EMRUKSpawnLocation SpawnLocation, float MinDistanceToEdge, FMRUKLabelFilter LabelFilter, FVector& OutPosition, FVector& OutNormal);

	/**
	 * Cast a ray and return the closest hit anchor
	 * @param Origin      Origin The origin of the ray.
	 * @param Direction   Direction The direction of the ray.
	 * @param MaxDist     The maximum distance the ray should travel.
	 * @param LabelFilter The label filter can be used to include/exclude certain labels from the search.
	 * @param OutHit      The closest hit.
	 * @return            The anchor that the ray hit.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit", meta = (AutoCreateRefTerm = "LabelFilter"))
	AMRUKAnchor* Raycast(const FVector& Origin, const FVector& Direction, float MaxDist, const FMRUKLabelFilter& LabelFilter, FMRUKHit& OutHit);

	/**
	 * Cast a ray and collect hits against the volume and plane bounds in this room. The order of the hits in the array is not specified.
	 * @param Origin      Origin The origin of the ray.
	 * @param Direction   Direction The direction of the ray.
	 * @param MaxDist     The maximum distance the ray should travel.
	 * @param OutHits     The hits the ray collected.
	 * @param LabelFilter The label filter can be used to include/exclude certain labels from the search.
	 * @param OutAnchors  The anchors that were hit. Each anchor in this array corresponds to a entry at the same position in OutHits.
	 * @return            Whether the ray hit anything
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit", meta = (AutoCreateRefTerm = "LabelFilter"))
	bool RaycastAll(const FVector& Origin, const FVector& Direction, float MaxDist, const FMRUKLabelFilter& LabelFilter, TArray<FMRUKHit>& OutHits, TArray<AMRUKAnchor*>& OutAnchors);

	/**
	 * Clear all anchors from the room.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void ClearRoom();

	/**
	 * Check if the room does have any of the labels.
	 * @param Labels	The labels to check.
	 * @return			Whether the label was found in the room.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool DoesRoomHave(const TArray<FString>& Labels);

	/**
	 *  Get the position on the surface that is closest to the given position with respect to the distance.
	 *  @param WorldPosition      The position in world space from which the closest surface point should be found.
	 *  @param OutSurfacePosition The closest position on the closest surface if any. Otherwise zero.
	 *  @param OutSurfaceDistance The distance between WorldPosition and OutSurfacePosition.
	 *  @param LabelFilter        The label filter can be used to include/exclude certain labels from the search.
	 *  @param MaxDistance        The distance to which a closest surface position should be searched. Everything below or equal to zero will be treated as infinity.
	 *  @return                   The Anchor on which the closest surface position was found or a null pointer otherwise.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit", meta = (AutoCreateRefTerm = "LabelFilter"))
	AMRUKAnchor* TryGetClosestSurfacePosition(const FVector& WorldPosition, FVector& OutSurfacePosition, double& OutSurfaceDistance, const FMRUKLabelFilter& LabelFilter, double MaxDistance = 0.0);

	/**
	 * Checks if the given position is on or inside of any scene volume in the room.
	 * Floor, ceiling and wall anchors will be excluded from the search.
	 * @param WorldPosition      The position in world space to check
	 * @param TestVerticalBounds Whether the vertical bounds should be checked or not
	 * @param Tolerance          Tolerance
	 * @return					 The anchor the WorldPosition is in. A null pointer otherwise.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	AMRUKAnchor* IsPositionInSceneVolume(const FVector& WorldPosition, bool TestVerticalBounds = true, double Tolerance = 0.0);

	/**
	 * Finds the closest seat given a ray.
	 * @param RayOrigin				The origin of the ray.
	 * @param RayDirection			The direction of the ray.
	 * @param OutSeatTransform		The seat pose.
	 * @return						If any seat was found the Anchor that has seats available will be returned. Otherwise a null pointer.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	AMRUKAnchor* TryGetClosestSeatPose(const FVector& RayOrigin, const FVector& RayDirection, FTransform& OutSeatTransform);

	/**
	 * Finds all anchors in this room that have the given label attached.
	 * @param Label The label to search for.
	 * @return      An array off anchors with the given label.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	TArray<AMRUKAnchor*> GetAnchorsByLabel(const FString& Label) const;

	/**
	 * Finds the first anchor in this room that has the given label attached.
	 * @param Label The label to search for.
	 * @return      If found, the Anchor that has the label attached. Otherwise a null pointer.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	AMRUKAnchor* GetFirstAnchorByLabel(const FString& Label) const;

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
	 * Return the longest wall in the room that has no other walls behind it.
	 * @param Tolerance The tolerance to use when determining wall that are behind.
	 * @return          The wall anchor that is the key wall in the room.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	AMRUKAnchor* GetKeyWall(double Tolerance = 0.1);

	/**
	 * Return the largest surface for a given label.
	 * @param Label The label of the surfaces to search in.
	 * @return      The anchor that has the largest surface if any. Otherwise, a null pointer.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	AMRUKAnchor* GetLargestSurface(const FString& Label);

	/**
	 * Attach a procedural mesh to the walls. This is done at the room level to ensure the UV coordinates
	 * can be done in a seamless way if desired.
	 * @param WallTextureCoordinateModes	Mode of the wall texture coordinates.
	 * @param CutHoleLabels                 Labels for which holes should be cut into the plane meshes
	 * @param ProceduralMaterial			Material to apply on top of the procedural mesh.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit", meta = (AutoCreateRefTerm = "WallTextureCoordinateModes", DeprecatedFunction, DeprecationMessage = "Use GenerateProceduralMesh instead."))
	void AttachProceduralMeshToWalls(const TArray<FMRUKTexCoordModes>& WallTextureCoordinateModes, const TArray<FString>& CutHoleLabels, UMaterialInterface* ProceduralMaterial = nullptr);

	/**
	 * Spawn meshes on the position of the anchors of the room.
	 * The actors should have Z as up Y as right and X as forward.
	 * The pivot point should be in the bottom center.
	 * @param SpawnGroups                A map which tells to spawn which actor to a given label.
	 * @param CutHoleLabels		         Labels for which the generated mesh should have holes. Only works with planes.
	 * @param ProceduralMaterial         Material to apply on top of the procedural mesh if any.
	 * @param ShouldFallbackToProcedural Whether or not it should by default fallback to generating a procedural mesh if no actor class has been specified for a label.
	 * @return                           All spawned interior actors.
	 */
	UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage = "Use AMRUKAnchorActorSpawner instead."), Category = "MR Utility Kit")
	TArray<AActor*> SpawnInterior(const TMap<FString, FMRUKSpawnGroup>& SpawnGroups, const TArray<FString>& CutHoleLabels, UMaterialInterface* ProceduralMaterial = nullptr, bool ShouldFallbackToProcedural = true);

	/**
	 * Spawn meshes on the position of the anchors of the room from a random stream.
	 * The actors should have Z as up Y as right and X as forward.
	 * The pivot point should be in the bottom center.
	 * @param SpawnGroups                A map wich tells to spawn which actor to a given label.
	 * @param CutHoleLabels		         Labels for which the generated mesh should have holes. Only works with planes.
	 * @param RandomStream               A random generator to choose randomly between actor classes if there a multiple for one label.
	 * @param ProceduralMaterial         Material to apply on top of the procedural mesh if any.
	 * @param ShouldFallbackToProcedural Whether or not it should by default fallback to generating a procedural mesh if no actor class has been specified for a label.
	 * @return                           All spawned interior actors.
	 */
	UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage = "Use AMRUKAnchorActorSpawner instead."), Category = "MR Utility Kit")
	TArray<AActor*> SpawnInteriorFromStream(const TMap<FString, FMRUKSpawnGroup>& SpawnGroups, const FRandomStream& RandomStream, const TArray<FString>& CutHoleLabels, UMaterialInterface* ProceduralMaterial = nullptr, bool ShouldFallbackToProcedural = true);

	/**
	 * Check if the given anchor is a wall anchor.
	 * @param Anchor The anchor to check.
	 * @return       Whether the anchor is a wall anchor or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool IsWallAnchor(AMRUKAnchor* Anchor) const;

	/**
	 * Compute the wall mesh texture coordinate adjustments that are needed to generate proper texture coordinates for the walls.
	 * @param WallTextureCoordinateModes The texture coordinate mode to use for the walls.
	 * @param OutAnchorsWithPlaneUVs     The computed texture coordinate adjustment with the wall anchor.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void ComputeWallMeshUVAdjustments(const TArray<FMRUKTexCoordModes>& WallTextureCoordinateModes, TArray<FMRUKAnchorWithPlaneUVs>& OutAnchorsWithPlaneUVs);

	/**
	 * Load the triangle mesh of the global mesh anchor if it's available.
	 * @param Material The Material to show if the global mesh is visible.
	 * @return         On success true, otherwise false.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool LoadGlobalMeshFromDevice(UMaterialInterface* Material = nullptr);

	/**
	 * Load the triangle mesh of the global mesh anchor. For this function to succeed you need to make
	 * sure to have a global mesh specified in the JSON file. Not every JSON file has a global mesh in it.
	 * @param JsonString The string with the JSON data.
	 * @param Material   Material to apply on the global mesh.
	 * @return           On Success true, otherwise false.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	bool LoadGlobalMeshFromJsonString(const FString& JsonString, UMaterialInterface* Material = nullptr);

	/**
	 * Compute the centroid of the room by taking the points of the floor boundary.
	 * The centroid may be outside of the room for non convex rooms.
	 * The Z value determines the height of the resulting vectors and ranges from
	 * 0 to 1. A Z value of 1 corresponds to the ceiling positions Z, while a Z value
	 * of 0 corresponds to the floor positions Z. Any value between 0 and 1 will
	 * interpolate between the two values.
	 * In case the floor and ceiling anchors haven't been loaded yet a zero vector
	 * will be returned.
	 * @param  Z Value used for interpolation of Z.
	 * @return The centroid.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	FVector ComputeCentroid(double Z = 0.5);

public:
	AMRUKRoom(const FObjectInitializer& ObjectInitializer);

	void EndPlay(EEndPlayReason::Type Reason) override;

	void LoadFromData(UMRUKRoomData* RoomData);

	void AttachProceduralMeshToWalls(const TArray<FString>& CutHoleLabels, UMaterialInterface* ProceduralMaterial = nullptr);
	void UpdateWorldLock(APawn* Pawn, const FVector& HeadWorldPosition) const;

	TSharedRef<FJsonObject> JsonSerialize();

	bool Corresponds(UMRUKRoomData* RoomQuery) const;

private:
	friend class FMRUKSpec;

	AMRUKAnchor* SpawnAnchor();

	void InitializeRoom();
	void ComputeRoomBounds();
	void ComputeAnchorHierarchy();
	void ComputeSeats();
	void ComputeRoomEdges();

	UFUNCTION(CallInEditor)
	void AddAnchorToRoom(AMRUKAnchor* Anchor);

	class UProceduralMeshComponent* GetOrCreateGlobalMeshProceduralMeshComponent(bool& OutExistedAlready) const;
	void SetupGlobalMeshProceduralMeshComponent(UProceduralMeshComponent& ProcMeshComponent, bool ExistedAlready, UMaterialInterface* Material) const;

	/**
	 * Get the list of walls in an order such that each one wall shares an edge with the next
	 * one in the list.
	 */
	TArray<TObjectPtr<AMRUKAnchor>> ComputeConnectedWalls() const;

	FOculusXRRoomLayout RoomLayout;
	UPROPERTY()
	AMRUKAnchor* KeyWallAnchor = nullptr;


	struct Surface
	{
		AMRUKAnchor* Anchor;
		float UsableArea;
		bool IsPlane;
		FBox2D Bounds;
		EMRUKBoxSide Side;
	};
};
