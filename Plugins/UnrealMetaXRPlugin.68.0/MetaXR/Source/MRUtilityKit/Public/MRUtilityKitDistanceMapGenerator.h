// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "MRUtilityKit.h"
#include "GameFramework/Actor.h"
#include "MRUtilityKitDistanceMapGenerator.generated.h"

const FName GMRUK_DISTANCE_MAP_ACTOR_TAG = TEXT("DistanceMapActor");

UENUM(BlueprintType)
enum class EMRUKDistanceMapGenerationMode : uint8
{
	// Do not generate a distance map
	None,
	/// Generate distance map only for the free space. E.g. The floor inside the room.
	FreeSpace,
	/// Generate the distance map only for the occupied space. E.g. outside the room and inside scene objects.
	OccupiedSpace,
	/// Generate the distance map for free space and occupied space.
	AllSpace,
};

/**
 * Generates a distance map that can be used in materials to calculate the distance to various objects.
 * This can enable interesting effects. With the distance map you can get the distance from scene objects
 * or walls in a material shader.
 *
 * The Jump Flood Algorithm is used to generate the distance map. This is fast enough to regenerate
 * every tick.
 *
 * To capture a distance map after a room has been loaded call CaptureDistanceMap().
 * It will return a captured distance map. In case you already called CaptureDistanceMap()
 * you can receive the last captured distance map with GetDistanceMap(). No other setup is required.
 *
 * This class will create procedural meshes for every anchor to create a mask. These meshes have their
 * visibility set to scene capture only. That however means that if you place a scene capture component yourself
 * that the meshes will show up in your scene capture component. The actors that have the procedural meshes
 * attached are tagged with GMRUK_DISTANCE_MAP_ACTOR_TAG. In case you don't want them to show up in your
 * scene capture you can hide them by receiving all these actors with the tag GMRUK_DISTANCE_MAP_ACTOR_TAG
 * and add these to the scene captures hidden actors.
 */
UCLASS(ClassGroup = MRUtilityKit, meta = (DisplayName = "MR Utility Kit Distance Map Generator"))
class MRUTILITYKIT_API AMRUKDistanceMapGenerator : public AActor
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnReady);

	UPROPERTY(BlueprintAssignable, Category = "MR Utility Kit")
	FOnReady OnReady;

	/**
	 * The mode in which the final distance map should be generated.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	EMRUKDistanceMapGenerationMode DistanceMapGenerationMode = EMRUKDistanceMapGenerationMode::FreeSpace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	class USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	class USceneCaptureComponent2D* SceneCapture2D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	EMRUKSpawnMode SpawnMode = EMRUKSpawnMode::CurrentRoomOnly;

	/**
	 * First render target for jump flood algorithm.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	class UCanvasRenderTarget2D* RenderTarget1;

	/**
	 * Second render target for jump flood algorithm.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	class UCanvasRenderTarget2D* RenderTarget2;

	/**
	 * Render target for the final distance map
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	class UCanvasRenderTarget2D* DistanceMapRenderTarget;

	/**
	 * Material to render a mask that gets used to calculate the distance map.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	class UMaterialInterface* MaskMaterial;

	/**
	 * Material that executes a pass of the jump flood algorithm.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	class UMaterialInterface* JFPassMaterial;

	/**
	 * Material to render final distance map
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	class UMaterialInterface* DistanceMapFreeSpaceMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	class UMaterialInterface* DistanceMapOccupiedSpaceMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	class UMaterialInterface* DistanceMapAllSpaceMaterial;

	/**
	 * Capture the distance map.
	 * @return The captured distance map.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	UTexture* CaptureDistanceMap();

	/**
	 * Create mask meshes for the given room.
	 * These mask meshes are needed for the distance map to be rendered. It should only be called once before
	 * CaptureDistanceMap in case the SpawnMode has been set to None.
	 * The operation that this function executes is expensive. It only needs to be called after the room has been
	 * created or updated.
	 * @param Room The room for which the masked meshes should be created.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void CreateMaskMeshesForRoom(AMRUKRoom* Room);

	/**
	 * Remove mask meshes for the given room.
	 * This function should only be executed when SpawnMode is set to None.
	 * It only needs to be called after a room has been removed.
	 * @param Room The room for which the masked meshes should be removed.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void RemoveMaskMeshesFromRoom(AMRUKRoom* Room);

	/**
	 * Return the captured distance map. Be sure to call CaptureDistanceMap() before
	 * @return The captured distance map.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	UTexture* GetDistanceMap() const;

	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	UCanvasRenderTarget2D* GetDistanceMapRenderTarget() const;

	/**
	 * Retrieve the view info from the scene capture. This is useful for re projection of
	 * the distance map in a material.
	 * @return The view info.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	FMinimalViewInfo GetSceneCaptureView() const;

public:
	AMRUKDistanceMapGenerator();

protected:
	void BeginPlay() override;

private:
	TMap<AMRUKRoom*, TArray<AActor*>> SpawnedMaskMeshes;

	int32 DistanceMapRT = -1;

	UPROPERTY()
	class UMaterialInstanceDynamic* JFPassMaterialInstance = nullptr;

	UPROPERTY()
	class UMaterialInstanceDynamic* DistanceMapFreeSpaceMaterialInstance = nullptr;
	UPROPERTY()
	class UMaterialInstanceDynamic* DistanceMapOccupiedSpaceMaterialInstance = nullptr;
	UPROPERTY()
	class UMaterialInstanceDynamic* DistanceMapAllSpaceMaterialInstance = nullptr;

	UPROPERTY()
	UMaterialInterface* SceneObjectMaskMaterial;

	UPROPERTY()
	UMaterialInterface* FloorMaskMaterial;

	void CaptureInitialSceneMask();
	void RenderDistanceMap();

	UFUNCTION()
	void OnRoomCreated(AMRUKRoom* Room);

	UFUNCTION()
	AActor* CreateMaskMeshOfAnchor(AMRUKAnchor* Anchor);

	UFUNCTION()
	AActor* UpdateMaskMeshOfAnchor(AMRUKAnchor* Anchor);
};
