// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "GameFramework/Actor.h"
#include "OculusXRRoomLayoutManagerComponent.h"
#include "OculusXRAnchorComponent.h"
#include "OculusXRFunctionLibrary.h"
#include "OculusXRSceneAnchorComponent.h"
#include "OculusXRSceneTypes.h"
#include "OculusXRSceneActor.generated.h"

/** EOculusXRLaunchCaptureFlowWhenMissingScene
 * Used to dictate whether the actor should launch the Capture Flow application when a scene is not detected on the device.
 * The Actor will check if a scene capture is either non-existent or invalid (ie. missing walls/ceiling/floor) before checking if Capture Flow
 * should be launched.
 *
 * NEVER:	will never launch Flow Capture.
 * ONCE:		will only launch it once.  If the actor still doesn't detect that a scene was captured, it will not launch Capture Flow again.
 * ALWAYS:	will always re-launch Flow Capture if a scene was not detected on the device.
 */
UENUM(BlueprintType)
enum EOculusXRLaunchCaptureFlowWhenMissingScene
{
	NEVER UMETA(DisplayName = "Never"),
	ONCE UMETA(DisplayName = "Once"),
	ALWAYS UMETA(DisplayName = "Always")
};

/** FOculusXRSpawnedSceneAnchorProperties
 * Properties/Components that a spawned scene anchor will use.
 */
USTRUCT(BlueprintType)
struct OCULUSXRSCENE_API FOculusXRSpawnedSceneAnchorProperties
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Spawned Scene Anchor Properties")
	TSoftClassPtr<UOculusXRSceneAnchorComponent> ActorComponent = TSoftClassPtr<UOculusXRSceneAnchorComponent>(FSoftClassPath(UOculusXRSceneAnchorComponent::StaticClass()));

	UPROPERTY(EditAnywhere, Category = "Spawned Scene Anchor Properties")
	TSoftObjectPtr<UStaticMesh> StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Spawned Scene Anchor Properties", Meta = (DeprecatedProperty, DeprecationMessage = "This property is deprecated. Alignment is done automatically at lower level."))
	bool ForceParallelToFloor = false;

	UPROPERTY(EditAnywhere, Category = "Spawned Scene Anchor Properties")
	FVector AddOffset = FVector::ZeroVector;
};

/**
 * AOculusXRSceneActor
 *
 * DEPRECATED: AOculusXRSceneActor and associated classes are deprecated (v65), please use MR Utility Kit instead
 * (https://developer.oculus.com/documentation/unreal/unreal-mr-utility-kit-overview)
 *
 * The purpose of this actor is to be able to spawn "scene anchor" actors.
 *
 * Each actor type (based on their semantic label) can be configured to be spawned with a specific mesh and actor component.
 *
 * Overall, it provides a simple interface to be able to quickly get a captured scene from Capture Flow populated at runtime.
 * It also provides a basic and flexible template to making use of the OculusAnchorSDK and UOculusXRRoomLayoutManagerComponent
 * to drive the actor's logic.  This removes the need for the developer to implement a system from scratch that makes use of
 * the native methods and components.
 *
 * TLDR:
 * - This actor populates a captured scene (created in Capture Flow) by spawning child actors with predefined actor and mesh components.
 * - Can be used as is, or can be derived or modified as needed depending on the application's needs.
 */
UCLASS(ClassGroup = OculusXRScene)
class OCULUSXRSCENE_API AOculusXRSceneActor : public AActor
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Scene Actor")
	void LaunchCaptureFlow();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Scene Actor")
	bool IsScenePopulated();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Scene Actor", Meta = (DeprecatedFunction, DeprecationMessage = "Is Room Layout Valid is deprecated and no longer returns any value but true. Please validate your room configuration in the way your application requires."))
	bool IsRoomLayoutValid();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Scene Actor")
	void PopulateScene();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Scene Actor")
	void ClearScene();

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Scene Actor")
	void SetVisibilityToAllSceneAnchors(const bool bIsVisible);

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Scene Actor")
	void SetVisibilityToSceneAnchorsBySemanticLabel(const FString SemanticLabel, const bool bIsVisible);

	UFUNCTION(BlueprintCallable, Category = "OculusXR|Scene Actor")
	TArray<AActor*> GetActorsBySemanticLabel(const FString SemanticLabel);

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "OculusXR|Scene Actor")
	TArray<FOculusXRRoomLayout> GetRoomLayouts() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OculusXR|Scene Actor")
	TEnumAsByte<EOculusXRLaunchCaptureFlowWhenMissingScene> LauchCaptureFlowWhenMissingScene = EOculusXRLaunchCaptureFlowWhenMissingScene::ALWAYS;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OculusXR|Scene Actor", meta = (UIMin = 1, ClampMin = 1, UIMax = 1024, ClampMax = 1024))
	int32 MaxQueries = 64;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OculusXR|Scene Actor")
	bool bPopulateSceneOnBeginPlay = true;

	// If true then when the scene model is loaded we will only attempt to populate the room the user is standing in.
	// Otherwise all rooms and all scene anchors will be loaded.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OculusXR|Scene Actor")
	bool bActiveRoomOnly = true;

	UPROPERTY(EditAnywhere, Category = "OculusXR|Scene Actor")
	TMap<FString, FOculusXRSpawnedSceneAnchorProperties> ScenePlaneSpawnedSceneAnchorProperties;

	UPROPERTY(EditAnywhere, Category = "OculusXR|Scene Actor")
	TMap<FString, FOculusXRSpawnedSceneAnchorProperties> SceneVolumeSpawnedSceneAnchorProperties;


public:
	AOculusXRSceneActor(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type Reason) override;
	virtual void Tick(float DeltaTime) override;

	virtual void PostLoad() override;

private:
	EOculusXRAnchorResult::Type QueryAllRooms();
	void RoomLayoutDiscoveryResultsAvailable(const TArray<FOculusXRAnchorsDiscoverResult>& QueryResults);
	void ProcessRoomQueryResult(FOculusXRUInt64 AnchorHandle, FOculusXRUUID UUID);

	EOculusXRAnchorResult::Type QueryRoomUUIDs(const FOculusXRUInt64 RoomSpaceID, const TArray<FOculusXRUUID>& RoomUUIDs);
	void SceneRoomDiscoveryResultsAvailable(const TArray<FOculusXRAnchorsDiscoverResult>& QueryResults, const FOculusXRUInt64 RoomSpaceID);
	void ProcessRoomElementsResult(FOculusXRUInt64 AnchorHandle, const FOculusXRUInt64 RoomSpaceID);

	void StartSingleRoomQuery(FOculusXRUInt64 RoomSpaceID, FOculusXRRoomLayout RoomLayout);
	EOculusXRAnchorResult::Type QueryFloorForActiveRoom(FOculusXRUInt64 RoomSpaceID, FOculusXRRoomLayout RoomLayout);
	void ActiveRoomFloorDiscoveryResultsAvailable(const TArray<FOculusXRAnchorsDiscoverResult>& QueryResults, FOculusXRUInt64 RoomSpaceID, FOculusXRRoomLayout RoomLayout);

	bool CheckFloorBounds(FOculusXRUInt64 AnchorHandle, FOculusXRUUID UUID, FOculusXRUInt64 RoomAnchorHandle);

	bool PointInPolygon2D(FVector2f PointToTest, const TArray<FVector2f>& PolyVerts) const;

	void GetSemanticClassifications(uint64 Space, TArray<FString>& OutSemanticLabels) const;

	// Scene capture event handler
	void SceneCaptureComplete_Handler(FOculusXRUInt64 RequestId, bool bResult);

	// Launches Capture Flow if (based on LauchCaptureFlowWhenMissingScene member value)
	void LaunchCaptureFlowIfNeeded();

	// Resets states of the Actor
	void ResetStates();

	// Validates UUID
	bool IsValidUuid(const FOculusXRUUID& Uuid);

	// Helper method to spawn an actor for anchor
	AActor* SpawnActorWithSceneComponent(const FOculusXRUInt64& Space, const FOculusXRUInt64& RoomSpaceID, const TArray<FString>& SemanticClassifications, UClass* sceneAnchorComponentInstanceClass);

	// Spawns a scene anchor
	AActor* SpawnOrUpdateSceneAnchor(AActor* Anchor, const FOculusXRUInt64& Space, const FOculusXRUInt64& RoomSpaceID, const FVector& BoundedPos, const FVector& BoundedSize, const TArray<FString>& SemanticClassifications, const EOculusXRSpaceComponentType AnchorComponentType);


	// Components for room layout and spatial anchors functionalities
	UOculusXRRoomLayoutManagerComponent* RoomLayoutManagerComponent = nullptr;

	class UOculusXRSceneGlobalMeshComponent* SceneGlobalMeshComponent = nullptr;

	// Whether Capture Flow was already launched once
	bool bCaptureFlowWasLaunched;

	// Whether last room layout was valid
	bool bRoomLayoutIsValid;

	// Whether we found a captured scene
	bool bFoundCapturedScene;

	UPROPERTY(Transient)
	TMap<FOculusXRUInt64, FOculusXRRoomLayout> RoomLayouts;
};
