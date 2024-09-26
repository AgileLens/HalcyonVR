// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRSceneActor.h"
#include "OculusXRSceneModule.h"
#include "OculusXRHMDModule.h"
#include "OculusXRHMD.h"
#include "OculusXRAnchorManager.h"
#include "OculusXRAnchorTypes.h"
#include "OculusXRAnchorBPFunctionLibrary.h"
#include "OculusXRSceneDelegates.h"
#include "OculusXRDelegates.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/AssetManager.h"
#include "Engine/StaticMesh.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/World.h"
#include "GameFramework/WorldSettings.h"
#include "ProceduralMeshComponent.h"
#include "OculusXRSceneGlobalMeshComponent.h"

#define LOCTEXT_NAMESPACE "OculusXRSceneActor"

//////////////////////////////////////////////////////////////////////////
// ASceneActor

AOculusXRSceneActor::AOculusXRSceneActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ResetStates();

	// Create required components
	RoomLayoutManagerComponent = CreateDefaultSubobject<UOculusXRRoomLayoutManagerComponent>(TEXT("OculusXRRoomLayoutManagerComponent"));

	// Following are the semantic labels we want to support default properties for.  User can always add new ones through the properties panel if needed.
	const FString default2DSemanticClassifications[] = {
		TEXT("WALL_FACE"),
		TEXT("CEILING"),
		TEXT("FLOOR"),
		TEXT("COUCH"),
		TEXT("TABLE"),
		TEXT("DOOR_FRAME"),
		TEXT("WINDOW_FRAME"),
		TEXT("WALL_ART"),
		TEXT("INVISIBLE_WALL_FACE"),
		TEXT("OTHER")
	};

	const FString default3DSemanticClassifications[] = {
		TEXT("COUCH"),
		TEXT("TABLE"),
		TEXT("SCREEN"),
		TEXT("BED"),
		TEXT("LAMP"),
		TEXT("PLANT"),
		TEXT("STORAGE"),
		TEXT("OTHER")
	};

	FOculusXRSpawnedSceneAnchorProperties spawnedAnchorProps;
	spawnedAnchorProps.ActorComponent = nullptr;
	spawnedAnchorProps.StaticMesh = nullptr;

	// Setup initial scene plane and volume properties
	for (auto& semanticLabel2D : default2DSemanticClassifications)
	{
		FOculusXRSpawnedSceneAnchorProperties& props = ScenePlaneSpawnedSceneAnchorProperties.Add(semanticLabel2D, spawnedAnchorProps);
		props.ForceParallelToFloor = (semanticLabel2D != "WALL_FACE");
	}

	for (auto& semanticLabel3D : default3DSemanticClassifications)
	{
		FOculusXRSpawnedSceneAnchorProperties& props = SceneVolumeSpawnedSceneAnchorProperties.Add(semanticLabel3D, spawnedAnchorProps);
		props.ForceParallelToFloor = true;
	}
}

void AOculusXRSceneActor::ResetStates()
{
	bCaptureFlowWasLaunched = false;
	ClearScene();
}

void AOculusXRSceneActor::BeginPlay()
{
	Super::BeginPlay();

	// Create a scene component as root so we can attach spawned actors to it
	USceneComponent* rootSceneComponent = NewObject<USceneComponent>(this, USceneComponent::StaticClass());
	rootSceneComponent->SetMobility(EComponentMobility::Static);
	rootSceneComponent->RegisterComponent();
	SetRootComponent(rootSceneComponent);

	SceneGlobalMeshComponent = FindComponentByClass<UOculusXRSceneGlobalMeshComponent>();

	// Register delegates
	RoomLayoutManagerComponent->OculusXRRoomLayoutSceneCaptureCompleteNative.AddUObject(this, &AOculusXRSceneActor::SceneCaptureComplete_Handler);

	// Make an initial request to query for the room layout if bPopulateSceneOnBeginPlay was set to true
	if (bPopulateSceneOnBeginPlay)
	{
		PopulateScene();
	}

}

void AOculusXRSceneActor::EndPlay(EEndPlayReason::Type Reason)
{
	// Unregister delegates
	RoomLayoutManagerComponent->OculusXRRoomLayoutSceneCaptureCompleteNative.RemoveAll(this);

	// Calling ResetStates will reset member variables to their default values (including the request IDs).
	ResetStates();


	Super::EndPlay(Reason);
}

void AOculusXRSceneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AOculusXRSceneActor::IsValidUuid(const FOculusXRUUID& Uuid)
{
	return Uuid.UUIDBytes != nullptr;
}

void AOculusXRSceneActor::LaunchCaptureFlow()
{
	UE_LOG(LogOculusXRScene, Verbose, TEXT("Launch capture flow"));

	if (RoomLayoutManagerComponent)
	{
		UE_LOG(LogOculusXRScene, Verbose, TEXT("Launch capture flow -- RoomLayoutManagerComponent"));

		const bool bResult = RoomLayoutManagerComponent->LaunchCaptureFlow();
		if (!bResult)
		{
			UE_LOG(LogOculusXRScene, Error, TEXT("LaunchCaptureFlow() failed!"));
		}
	}
}

void AOculusXRSceneActor::LaunchCaptureFlowIfNeeded()
{
#if WITH_EDITOR
	UE_LOG(LogOculusXRScene, Display, TEXT("Scene Capture does not work over Link. Please capture a scene with the HMD in standalone mode, then access the scene model over Link."));
#else
	// Depending on LauchCaptureFlowWhenMissingScene, we might not want to launch Capture Flow
	if (LauchCaptureFlowWhenMissingScene != EOculusXRLaunchCaptureFlowWhenMissingScene::NEVER)
	{
		if (LauchCaptureFlowWhenMissingScene == EOculusXRLaunchCaptureFlowWhenMissingScene::ALWAYS || (!bCaptureFlowWasLaunched && LauchCaptureFlowWhenMissingScene == EOculusXRLaunchCaptureFlowWhenMissingScene::ONCE))
		{
			LaunchCaptureFlow();
		}
	}
#endif
}

AActor* AOculusXRSceneActor::SpawnActorWithSceneComponent(const FOculusXRUInt64& Space, const FOculusXRUInt64& RoomSpaceID, const TArray<FString>& SemanticClassifications, UClass* sceneAnchorComponentInstanceClass)
{
	FActorSpawnParameters actorSpawnParams;
	actorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AActor* Anchor = GetWorld()->SpawnActor<AActor>(AActor::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, actorSpawnParams);

	USceneComponent* rootComponent = NewObject<USceneComponent>(Anchor, USceneComponent::StaticClass());
	rootComponent->SetMobility(EComponentMobility::Movable);
	rootComponent->RegisterComponent();
	Anchor->SetRootComponent(rootComponent);
	rootComponent->SetWorldLocation(FVector::ZeroVector);

	Anchor->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

#if WITH_EDITOR
	if (SemanticClassifications.Num() > 0)
	{
		Anchor->SetActorLabel(FString::Join(SemanticClassifications, TEXT("-")), false);
	}
#endif

	UOculusXRSceneAnchorComponent* sceneAnchorComponent = NewObject<UOculusXRSceneAnchorComponent>(Anchor, sceneAnchorComponentInstanceClass);
	sceneAnchorComponent->RegisterComponent();

	sceneAnchorComponent->SetHandle(Space);
	sceneAnchorComponent->SemanticClassifications = SemanticClassifications;
	sceneAnchorComponent->RoomSpaceID = RoomSpaceID;

	EOculusXRAnchorResult::Type Result;
	OculusXRAnchors::FOculusXRAnchors::SetAnchorComponentStatus(sceneAnchorComponent, EOculusXRSpaceComponentType::Locatable, true, 0.0f, FOculusXRAnchorSetComponentStatusDelegate(), Result);

	return Anchor;
}

AActor* AOculusXRSceneActor::SpawnOrUpdateSceneAnchor(AActor* Anchor, const FOculusXRUInt64& Space, const FOculusXRUInt64& RoomSpaceID, const FVector& BoundedPos, const FVector& BoundedSize, const TArray<FString>& SemanticClassifications, const EOculusXRSpaceComponentType AnchorComponentType)
{
	if (Space.Value == 0)
	{
		UE_LOG(LogOculusXRScene, Error, TEXT("AOculusXRSceneActor::SpawnOrUpdateSceneAnchor Invalid Space handle."));
		return Anchor;
	}

	if (!(AnchorComponentType == EOculusXRSpaceComponentType::ScenePlane || AnchorComponentType == EOculusXRSpaceComponentType::SceneVolume))
	{
		UE_LOG(LogOculusXRScene, Error, TEXT("AOculusXRSceneActor::SpawnOrUpdateSceneAnchor Anchor doesn't have ScenePlane or SceneVolume component active."));
		return Anchor;
	}

	if (0 == SemanticClassifications.Num())
	{
		UE_LOG(LogOculusXRScene, Error, TEXT("AOculusXRSceneActor::SpawnOrUpdateSceneAnchor No semantic classification found."));
		return Anchor;
	}

	FOculusXRSpawnedSceneAnchorProperties* foundProperties = (AnchorComponentType == EOculusXRSpaceComponentType::ScenePlane) ? ScenePlaneSpawnedSceneAnchorProperties.Find(SemanticClassifications[0]) : SceneVolumeSpawnedSceneAnchorProperties.Find(SemanticClassifications[0]);

	if (!foundProperties)
	{
		UE_LOG(LogOculusXRScene, Warning, TEXT("AOculusXRSceneActor::SpawnOrUpdateSceneAnchor Scene object has an unknown semantic label.  Will not be spawned."));
		return Anchor;
	}

	TSoftClassPtr<UOculusXRSceneAnchorComponent>* sceneAnchorComponentClassPtrRef = &foundProperties->ActorComponent;
	TSoftObjectPtr<UStaticMesh>* staticMeshObjPtrRef = &foundProperties->StaticMesh;

	UClass* sceneAnchorComponentInstanceClass = sceneAnchorComponentClassPtrRef->LoadSynchronous();
	if (!sceneAnchorComponentInstanceClass)
	{
		UE_LOG(LogOculusXRScene, Error, TEXT("AOculusXRSceneActor::SpawnOrUpdateSceneAnchor Scene anchor component class is invalid!  Cannot spawn actor to populate the scene."));
		return Anchor;
	}

	if (!Anchor)
	{
		Anchor = SpawnActorWithSceneComponent(Space, RoomSpaceID, SemanticClassifications, sceneAnchorComponentInstanceClass);
	}

	if (staticMeshObjPtrRef && staticMeshObjPtrRef->IsPending())
	{
		staticMeshObjPtrRef->LoadSynchronous();
	}
	UStaticMesh* refStaticMesh = staticMeshObjPtrRef ? staticMeshObjPtrRef->Get() : nullptr;
	if (refStaticMesh == nullptr)
	{
		UE_LOG(LogOculusXRScene, Warning, TEXT("AOculusXRSceneActor::SpawnOrUpdateSceneAnchor Spawn scene anchor mesh is invalid for %s!"), *SemanticClassifications[0]);
		return Anchor;
	}

	UStaticMeshComponent* staticMeshComponent = NewObject<UStaticMeshComponent>(Anchor, UStaticMeshComponent::StaticClass());
	staticMeshComponent->RegisterComponent();
	staticMeshComponent->SetStaticMesh(refStaticMesh);
	staticMeshComponent->AttachToComponent(Anchor->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
	const float worldToMeters = GetWorld()->GetWorldSettings()->WorldToMeters;
	FVector offset(0.0f, BoundedSize.Y / 2.0f, BoundedSize.Z / 2.0f);
	staticMeshComponent->SetRelativeLocation(foundProperties->AddOffset + ((BoundedPos + offset) * worldToMeters), false, nullptr, ETeleportType::ResetPhysics);

	// Setup scale based on bounded size and the actual size of the mesh
	UStaticMesh* staticMesh = staticMeshComponent->GetStaticMesh();
	FBoxSphereBounds staticMeshBounds;
	staticMeshBounds.BoxExtent = FVector{ 1.f, 1.f, 1.f };
	if (staticMesh)
	{
		staticMeshBounds = staticMesh->GetBounds();
	}

	staticMeshComponent->SetRelativeScale3D(FVector(
		(BoundedSize.X < UE_SMALL_NUMBER) ? 1 : (BoundedSize.X / (staticMeshBounds.BoxExtent.X * 2.f)) * worldToMeters,
		(BoundedSize.Y < UE_SMALL_NUMBER) ? 1 : (BoundedSize.Y / (staticMeshBounds.BoxExtent.Y * 2.f)) * worldToMeters,
		(BoundedSize.Z < UE_SMALL_NUMBER) ? 1 : (BoundedSize.Z / (staticMeshBounds.BoxExtent.Z * 2.f)) * worldToMeters));

	return Anchor;
}


bool AOculusXRSceneActor::IsScenePopulated()
{
	if (!RootComponent)
	{
		return false;
	}

	return RootComponent->GetNumChildrenComponents() > 0;
}

bool AOculusXRSceneActor::IsRoomLayoutValid()
{
	return true;
}

void AOculusXRSceneActor::PopulateScene()
{
	if (!RootComponent)
	{
		return;
	}

	const EOculusXRAnchorResult::Type result = QueryAllRooms();
	if (!UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(result))
	{
		UE_LOG(LogOculusXRScene, Error, TEXT("PopulateScene Failed to query available rooms"));
	}
}

void AOculusXRSceneActor::ClearScene()
{
	if (!RootComponent)
		return;

	TArray<USceneComponent*> childrenComponents = RootComponent->GetAttachChildren();
	for (USceneComponent* SceneComponent : childrenComponents)
	{
		Cast<AActor>(SceneComponent->GetOuter())->Destroy();
	}

	bRoomLayoutIsValid = false;
	bFoundCapturedScene = false;
}

void AOculusXRSceneActor::SetVisibilityToAllSceneAnchors(const bool bIsVisible)
{
	if (!RootComponent)
		return;

	TArray<USceneComponent*> childrenComponents = RootComponent->GetAttachChildren();
	for (USceneComponent* sceneComponent : childrenComponents)
	{
		sceneComponent->SetVisibility(bIsVisible, true);
	}
}

void AOculusXRSceneActor::SetVisibilityToSceneAnchorsBySemanticLabel(const FString SemanticLabel, const bool bIsVisible)
{
	FString label = SemanticLabel;
	if (SemanticLabel == TEXT("DESK"))
	{
		label = TEXT("TABLE");
		UE_LOG(LogOculusXRScene, Warning, TEXT("XR Scene Actor semantic lable 'DESK' is deprecated, use 'TABLE' instead."));
	}

	if (!RootComponent)
		return;

	TArray<USceneComponent*> childrenComponents = RootComponent->GetAttachChildren();
	for (USceneComponent* sceneComponent : childrenComponents)
	{
		UObject* outerObject = sceneComponent->GetOuter();
		if (!outerObject)
		{
			continue;
		}

		AActor* outerActor = Cast<AActor>(outerObject);
		if (!outerActor)
		{
			continue;
		}

		UActorComponent* sceneAnchorComponent = outerActor->GetComponentByClass(UOculusXRSceneAnchorComponent::StaticClass());
		if (!sceneAnchorComponent)
		{
			continue;
		}

		if (Cast<UOculusXRSceneAnchorComponent>(sceneAnchorComponent)->SemanticClassifications.Contains(label))
		{
			sceneComponent->SetVisibility(bIsVisible, true);
		}
	}
}

TArray<AActor*> AOculusXRSceneActor::GetActorsBySemanticLabel(const FString SemanticLabel)
{
	FString label = SemanticLabel;
	if (SemanticLabel == TEXT("DESK"))
	{
		label = TEXT("TABLE");
		UE_LOG(LogOculusXRScene, Warning, TEXT("XR Scene Actor semantic lable 'DESK' is deprecated, use 'TABLE' instead."));
	}

	TArray<AActor*> actors;

	if (!RootComponent)
		return actors;

	TArray<USceneComponent*> childrenComponents = RootComponent->GetAttachChildren();
	for (USceneComponent* sceneComponent : childrenComponents)
	{
		UObject* outerObject = sceneComponent->GetOuter();
		if (!outerObject)
		{
			continue;
		}

		AActor* outerActor = Cast<AActor>(outerObject);
		if (!outerActor)
		{
			continue;
		}

		UActorComponent* sceneAnchorComponent = outerActor->GetComponentByClass(UOculusXRSceneAnchorComponent::StaticClass());
		if (!sceneAnchorComponent)
		{
			continue;
		}

		if (Cast<UOculusXRSceneAnchorComponent>(sceneAnchorComponent)->SemanticClassifications.Contains(label))
		{
			actors.Add(outerActor);
		}
	}

	return actors;
}

TArray<FOculusXRRoomLayout> AOculusXRSceneActor::GetRoomLayouts() const
{
	TArray<FOculusXRRoomLayout> layouts;
	RoomLayouts.GenerateValueArray(layouts);
	return layouts;
}

EOculusXRAnchorResult::Type AOculusXRSceneActor::QueryAllRooms()
{
	EOculusXRAnchorResult::Type anchorQueryResult;

	auto componentFilter = NewObject<UOculusXRSpaceDiscoveryComponentsFilter>(this);
	componentFilter->ComponentType = EOculusXRSpaceComponentType::RoomLayout;

	FOculusXRSpaceDiscoveryInfo discoveryInfo;
	discoveryInfo.Filters.Add(componentFilter);

	OculusXRAnchors::FOculusXRAnchors::DiscoverAnchors(discoveryInfo,
		FOculusXRDiscoverAnchorsResultsDelegate::CreateUObject(this, &AOculusXRSceneActor::RoomLayoutDiscoveryResultsAvailable),
		FOculusXRDiscoverAnchorsCompleteDelegate(),
		anchorQueryResult);

	return anchorQueryResult;
}

void AOculusXRSceneActor::RoomLayoutDiscoveryResultsAvailable(const TArray<FOculusXRAnchorsDiscoverResult>& QueryResults)
{
	UE_LOG(LogOculusXRScene, Verbose, TEXT("RoomLayoutDiscoveryResultsAvailable"));

	for (auto& QueryElement : QueryResults)
	{
		ProcessRoomQueryResult(QueryElement.Space, QueryElement.UUID);
	}
}

void AOculusXRSceneActor::ProcessRoomQueryResult(FOculusXRUInt64 AnchorHandle, FOculusXRUUID UUID)
{
	UE_LOG(LogOculusXRScene, Verbose, TEXT("Process Room Query Result -- Query Element (space = %llu, uuid = %s"), AnchorHandle.Value, *BytesToHex(UUID.UUIDBytes, OCULUSXR_UUID_SIZE));

	FOculusXRRoomLayout roomLayout;
	const bool bGetRoomLayoutResult = RoomLayoutManagerComponent->GetRoomLayout(AnchorHandle.Value, roomLayout, MaxQueries);
	if (!bGetRoomLayoutResult)
	{
		UE_LOG(LogOculusXRScene, Error, TEXT("Process Room Query Result -- Failed to get room layout for space (space = %llu, uuid = %s"),
			AnchorHandle.Value, *BytesToHex(UUID.UUIDBytes, OCULUSXR_UUID_SIZE));
		return;
	}

	roomLayout.RoomAnchorHandle = AnchorHandle;
	roomLayout.RoomUuid = UUID;


	// If we're only loading the active room we start that floor check query here, otherwise do the room query
	if (bActiveRoomOnly)
	{
		QueryFloorForActiveRoom(AnchorHandle, roomLayout);
	}
	else
	{
		StartSingleRoomQuery(AnchorHandle, roomLayout);
	}
}

EOculusXRAnchorResult::Type AOculusXRSceneActor::QueryRoomUUIDs(const FOculusXRUInt64 RoomSpaceID, const TArray<FOculusXRUUID>& RoomUUIDs)
{
	EOculusXRAnchorResult::Type startAnchorQueryResult;

	auto uuidFilter = NewObject<UOculusXRSpaceDiscoveryIdsFilter>(this);
	uuidFilter->Uuids = RoomUUIDs;

	FOculusXRSpaceDiscoveryInfo discoveryInfo;
	discoveryInfo.Filters.Add(uuidFilter);

	OculusXRAnchors::FOculusXRAnchors::DiscoverAnchors(discoveryInfo,
		FOculusXRDiscoverAnchorsResultsDelegate::CreateUObject(this, &AOculusXRSceneActor::SceneRoomDiscoveryResultsAvailable, RoomSpaceID),
		FOculusXRDiscoverAnchorsCompleteDelegate(),
		startAnchorQueryResult);

	return startAnchorQueryResult;
}

void AOculusXRSceneActor::SceneRoomDiscoveryResultsAvailable(const TArray<FOculusXRAnchorsDiscoverResult>& DiscoveryResults, const FOculusXRUInt64 RoomSpaceID)
{
	for (auto& AnchorQueryElement : DiscoveryResults)
	{
		ProcessRoomElementsResult(AnchorQueryElement.Space, RoomSpaceID);
	}
}

void AOculusXRSceneActor::ProcessRoomElementsResult(FOculusXRUInt64 AnchorHandle, const FOculusXRUInt64 RoomSpaceID)
{
	bool bOutPending = false;

	if (SceneGlobalMeshComponent)
	{
		TArray<FString> semanticClassifications;
		GetSemanticClassifications(AnchorHandle.Value, semanticClassifications);
		UE_LOG(LogOculusXRScene, Log, TEXT("SpatialAnchor Scene label is %s"), semanticClassifications.Num() > 0 ? *semanticClassifications[0] : TEXT("unknown"));
		if (semanticClassifications.Contains(UOculusXRSceneGlobalMeshComponent::GlobalMeshSemanticLabel))
		{
			bool bIsTriangleMesh = false;
			EOculusXRAnchorResult::Type result = OculusXRAnchors::FOculusXRAnchorManager::GetSpaceComponentStatus(
				AnchorHandle.Value, EOculusXRSpaceComponentType::TriangleMesh, bIsTriangleMesh, bOutPending);

			if (!UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(result) || !bIsTriangleMesh)
			{
				UE_LOG(LogOculusXRScene, Error, TEXT("SpatialAnchorQueryResult_Handler Failed to load Triangle Mesh Component for a GLOBAL_MESH"));
				return;
			}

			UClass* sceneAnchorComponentInstanceClass = SceneGlobalMeshComponent->GetAnchorComponentClass();

			AActor* globalMeshAnchor = SpawnActorWithSceneComponent(AnchorHandle.Value, RoomSpaceID, semanticClassifications, sceneAnchorComponentInstanceClass);

			SceneGlobalMeshComponent->CreateMeshComponent(AnchorHandle, globalMeshAnchor, RoomLayoutManagerComponent);
			return;
		}
	}

	bool bIsScenePlane = false;
	bool bIsSceneVolume = false;
	EOculusXRAnchorResult::Type isPlaneResult = OculusXRAnchors::FOculusXRAnchorManager::GetSpaceComponentStatus(
		AnchorHandle.Value, EOculusXRSpaceComponentType::ScenePlane, bIsScenePlane, bOutPending);

	EOculusXRAnchorResult::Type isVolumeResult = OculusXRAnchors::FOculusXRAnchorManager::GetSpaceComponentStatus(
		AnchorHandle.Value, EOculusXRSpaceComponentType::SceneVolume, bIsSceneVolume, bOutPending);

	bool bIsPlaneResultSuccess = UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(isPlaneResult);
	bool bIsVolumeResultSuccess = UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(isVolumeResult);

	AActor* anchor = nullptr;

	if (bIsPlaneResultSuccess && bIsScenePlane)
	{
		EOculusXRAnchorResult::Type Result;
		FVector scenePlanePos;
		FVector scenePlaneSize;
		bool ResultSuccess = OculusXRAnchors::FOculusXRAnchors::GetSpaceScenePlane(AnchorHandle.Value, scenePlanePos, scenePlaneSize, Result);
		if (ResultSuccess)
		{
			UE_LOG(LogOculusXRScene, Log, TEXT("SpatialAnchorQueryResult_Handler ScenePlane pos = [%.2f, %.2f, %.2f], size = [%.2f, %.2f, %.2f]."),
				scenePlanePos.X, scenePlanePos.Y, scenePlanePos.Z,
				scenePlaneSize.X, scenePlaneSize.Y, scenePlaneSize.Z);

			TArray<FString> semanticClassifications;
			GetSemanticClassifications(AnchorHandle.Value, semanticClassifications);

			UE_LOG(LogOculusXRScene, Log, TEXT("SpatialAnchor ScenePlane label is %s"), semanticClassifications.Num() > 0 ? *semanticClassifications[0] : TEXT("unknown"));

			anchor = SpawnOrUpdateSceneAnchor(anchor, AnchorHandle, RoomSpaceID, scenePlanePos, scenePlaneSize, semanticClassifications, EOculusXRSpaceComponentType::ScenePlane);
			if (!anchor)
			{
				UE_LOG(LogOculusXRScene, Error, TEXT("SpatialAnchorQueryResult_Handler Failed to spawn scene anchor."));
			}
		}
		else
		{
			UE_LOG(LogOculusXRScene, Error, TEXT("SpatialAnchorQueryResult_Handler Failed to get bounds for ScenePlane space."));
		}
	}

	if (bIsVolumeResultSuccess && bIsSceneVolume)
	{
		EOculusXRAnchorResult::Type Result;
		FVector sceneVolumePos;
		FVector sceneVolumeSize;
		bool ResultSuccess = OculusXRAnchors::FOculusXRAnchors::GetSpaceSceneVolume(AnchorHandle.Value, sceneVolumePos, sceneVolumeSize, Result);
		if (ResultSuccess)
		{
			UE_LOG(LogOculusXRScene, Log, TEXT("SpatialAnchorQueryResult_Handler SceneVolume pos = [%.2f, %.2f, %.2f], size = [%.2f, %.2f, %.2f]."),
				sceneVolumePos.X, sceneVolumePos.Y, sceneVolumePos.Z,
				sceneVolumeSize.X, sceneVolumeSize.Y, sceneVolumeSize.Z);

			TArray<FString> semanticClassifications;
			GetSemanticClassifications(AnchorHandle.Value, semanticClassifications);

			UE_LOG(LogOculusXRScene, Log, TEXT("SpatialAnchor SceneVolume label is %s"), semanticClassifications.Num() > 0 ? *semanticClassifications[0] : TEXT("unknown"));

			anchor = SpawnOrUpdateSceneAnchor(anchor, AnchorHandle, RoomSpaceID, sceneVolumePos, sceneVolumeSize, semanticClassifications, EOculusXRSpaceComponentType::SceneVolume);
			if (!anchor)
			{
				UE_LOG(LogOculusXRScene, Error, TEXT("SpatialAnchorQueryResult_Handler Failed to spawn scene anchor."));
			}
		}
		else
		{
			UE_LOG(LogOculusXRScene, Error, TEXT("SpatialAnchorQueryResult_Handler Failed to get bounds for SceneVolume space."));
		}
	}
}

void AOculusXRSceneActor::StartSingleRoomQuery(FOculusXRUInt64 RoomSpaceID, FOculusXRRoomLayout RoomLayout)
{
	EOculusXRAnchorResult::Type startQueryResult = QueryRoomUUIDs(RoomSpaceID, RoomLayout.RoomObjectUUIDs);
	if (UOculusXRAnchorBPFunctionLibrary::IsAnchorResultSuccess(startQueryResult))
	{
		RoomLayouts.Add(RoomSpaceID, std::move(RoomLayout));
	}
}

EOculusXRAnchorResult::Type AOculusXRSceneActor::QueryFloorForActiveRoom(FOculusXRUInt64 RoomSpaceID, FOculusXRRoomLayout RoomLayout)
{
	EOculusXRAnchorResult::Type anchorQueryResult;

	auto uuidFilter = NewObject<UOculusXRSpaceDiscoveryIdsFilter>(this);
	uuidFilter->Uuids = { RoomLayout.FloorUuid };

	FOculusXRSpaceDiscoveryInfo discoveryInfo;
	discoveryInfo.Filters.Add(uuidFilter);

	OculusXRAnchors::FOculusXRAnchors::DiscoverAnchors(discoveryInfo,
		FOculusXRDiscoverAnchorsResultsDelegate::CreateUObject(this, &AOculusXRSceneActor::ActiveRoomFloorDiscoveryResultsAvailable, RoomSpaceID, RoomLayout),
		FOculusXRDiscoverAnchorsCompleteDelegate(),
		anchorQueryResult);

	return anchorQueryResult;
}

void AOculusXRSceneActor::ActiveRoomFloorDiscoveryResultsAvailable(const TArray<FOculusXRAnchorsDiscoverResult>& DiscoveryResults, FOculusXRUInt64 RoomSpaceID, FOculusXRRoomLayout RoomLayout)
{
	if (DiscoveryResults.Num() != 1)
	{
		UE_LOG(LogOculusXRScene, Error, TEXT("Wrong number of elements returned from discover anchors for floor UUID. Result count (%d), UUID (%s), Room Space ID (%llu)"), DiscoveryResults.Num(), *RoomLayout.FloorUuid.ToString(), RoomSpaceID.Value);
		return;
	}

	const FOculusXRAnchorsDiscoverResult& floorQueryResult = DiscoveryResults[0];
	if (!CheckFloorBounds(floorQueryResult.Space, floorQueryResult.UUID, RoomLayout.RoomAnchorHandle))
	{
		UE_LOG(LogOculusXRScene, Verbose, TEXT("User is not within bounds of queried floor in room. UUID (%s), Room Space ID (%llu)"), *floorQueryResult.UUID.ToString(), RoomLayout.RoomAnchorHandle.GetValue());
		return;
	}

	StartSingleRoomQuery(RoomSpaceID, RoomLayout);
}

bool AOculusXRSceneActor::CheckFloorBounds(FOculusXRUInt64 AnchorHandle, FOculusXRUUID UUID, FOculusXRUInt64 RoomAnchorHandle)
{
	TArray<FString> semanticClassifications;
	GetSemanticClassifications(AnchorHandle, semanticClassifications);
	if (!semanticClassifications.Contains("FLOOR"))
	{
		UE_LOG(LogOculusXRScene, Error, TEXT("Queried floor in room doesn't contain a floor semantic label. UUID (%s), Room Space ID (%llu)"), *UUID.ToString(), RoomAnchorHandle.GetValue());
		return false;
	}

	EOculusXRAnchorResult::Type getBoundaryResult;
	TArray<FVector2f> boundaryVertices;
	if (!OculusXRAnchors::FOculusXRAnchors::GetSpaceBoundary2D(AnchorHandle, boundaryVertices, getBoundaryResult))
	{
		UE_LOG(LogOculusXRScene, Error, TEXT("Failed to get space boundary vertices for floor. UUID (%s), Room Space ID (%llu)"), *UUID.ToString(), RoomAnchorHandle.GetValue());
		return false;
	}

	OculusXRHMD::FOculusXRHMD* HMD = OculusXRHMD::FOculusXRHMD::GetOculusXRHMD();
	check(HMD);

	OculusXRHMD::FPose headPose;
	HMD->GetCurrentPose(OculusXRHMD::ToExternalDeviceId(ovrpNode_Head), headPose.Orientation, headPose.Position);

	TArray<FVector> convertedBoundaryPoints;

	FTransform floorTransform;
	if (!UOculusXRAnchorBPFunctionLibrary::GetAnchorTransformByHandle(AnchorHandle, floorTransform))
	{
		UE_LOG(LogOculusXRScene, Error, TEXT("Failed to get the floor anchor transform. Floor Space ID (%llu)"), AnchorHandle.GetValue());
		return false;
	}

	// Convert the boundary vertices to game engine world space
	for (auto& it : boundaryVertices)
	{
		FVector pos = floorTransform.TransformPosition(FVector(0, it.X * HMD->GetWorldToMetersScale(), it.Y * HMD->GetWorldToMetersScale()));
		convertedBoundaryPoints.Add(pos);
	}

	// Create the new 2D boundary
	TArray<FVector2f> new2DBoundary;
	for (auto& it : convertedBoundaryPoints)
	{
		new2DBoundary.Add(FVector2f(it.X, it.Y));
	}

	// Check if inside poly
	if (!PointInPolygon2D(FVector2f(headPose.Position.X, headPose.Position.Y), new2DBoundary))
	{
		UE_LOG(LogOculusXRScene, Verbose, TEXT("Floor failed active room check. UUID (%s), Room Space ID (%llu)"), *UUID.ToString(), RoomAnchorHandle.GetValue());
		return false;
	}

	return true;
}

bool AOculusXRSceneActor::PointInPolygon2D(FVector2f PointToTest, const TArray<FVector2f>& PolyVerts) const
{
	if (PolyVerts.Num() < 3)
	{
		return false;
	}

	int collision = 0;
	float x = PointToTest.X;
	float y = PointToTest.Y;

	int vertCount = PolyVerts.Num();
	for (int i = 0; i < vertCount; i++)
	{
		float x1 = PolyVerts[i].X;
		float y1 = PolyVerts[i].Y;

		float x2 = PolyVerts[(i + 1) % vertCount].X;
		float y2 = PolyVerts[(i + 1) % vertCount].Y;

		if (y < y1 != y < y2 && x < x1 + ((y - y1) / (y2 - y1)) * (x2 - x1))
		{
			collision += (y1 < y2) ? 1 : -1;
		}
	}

	return collision != 0;
}

void AOculusXRSceneActor::GetSemanticClassifications(uint64 Space, TArray<FString>& OutSemanticLabels) const
{
	EOculusXRAnchorResult::Type SemanticLabelAnchorResult;
	bool Result = OculusXRAnchors::FOculusXRAnchors::GetSpaceSemanticClassification(Space, OutSemanticLabels, SemanticLabelAnchorResult);
	if (Result)
	{
		UE_LOG(LogOculusXRScene, Verbose, TEXT("GetSemanticClassifications -- Space (%llu) Classifications:"), Space);
		for (FString& label : OutSemanticLabels)
		{
			UE_LOG(LogOculusXRScene, Verbose, TEXT("%s"), *label);
		}
	}
	else
	{
		UE_LOG(LogOculusXRScene, Error, TEXT("SpatialAnchorQueryResult_Handler Failed to get semantic classification space."));
	}
}

// DELEGATE HANDLERS
void AOculusXRSceneActor::SceneCaptureComplete_Handler(FOculusXRUInt64 RequestId, bool bResult)
{
	if (!bResult)
	{
		UE_LOG(LogOculusXRScene, Error, TEXT("Scene Capture Complete failed!"));
		return;
	}

	// Mark that we already launched Capture Flow and try to query spatial anchors again
	bCaptureFlowWasLaunched = true;

	ClearScene();
	PopulateScene();
}

void AOculusXRSceneActor::PostLoad()
{
	Super::PostLoad();

	FOculusXRSpawnedSceneAnchorProperties desk;
	if (ScenePlaneSpawnedSceneAnchorProperties.RemoveAndCopyValue(TEXT("DESK"), desk))
	{
		UE_LOG(LogOculusXRScene, Log, TEXT("Running XR Scene Actor plane semantic lable migration: 'DESK' to 'TABLE'"));
		ScenePlaneSpawnedSceneAnchorProperties[TEXT("TABLE")] = desk;
	}

	if (SceneVolumeSpawnedSceneAnchorProperties.RemoveAndCopyValue(TEXT("DESK"), desk))
	{
		UE_LOG(LogOculusXRScene, Log, TEXT("Running XR Scene Actor volume semantic lable migration: 'DESK' to 'TABLE'"));
		SceneVolumeSpawnedSceneAnchorProperties[TEXT("TABLE")] = desk;
	}
}

#undef LOCTEXT_NAMESPACE
