// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitSubsystem.h"
#include "MRUtilityKitAnchor.h"
#include "Kismet/GameplayStatics.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "MRUtilityKitPositionGenerator.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonSerializer.h"
#include "GameFramework/Pawn.h"
#include "OculusXRRoomLayoutManagerComponent.h"
#include "OculusXRSceneEventDelegates.h"
#include "OculusXRSceneFunctionLibrary.h"
#include "Engine/Engine.h"

AMRUKAnchor* UMRUKSubsystem::Raycast(const FVector& Origin, const FVector& Direction, float MaxDist, const FMRUKLabelFilter& LabelFilter, FMRUKHit& OutHit)
{
	AMRUKAnchor* HitComponent = nullptr;
	for (const auto& Room : Rooms)
	{
		FMRUKHit HitResult;
		if (!Room)
		{
			continue;
		}
		if (AMRUKAnchor* Anchor = Room->Raycast(Origin, Direction, MaxDist, LabelFilter, HitResult))
		{
			// Prevent further hits which are further away from being found
			MaxDist = HitResult.HitDistance;
			OutHit = HitResult;
			HitComponent = Anchor;
		}
	}
	return HitComponent;
}

bool UMRUKSubsystem::RaycastAll(const FVector& Origin, const FVector& Direction, float MaxDist, const FMRUKLabelFilter& LabelFilter, TArray<FMRUKHit>& OutHits, TArray<AMRUKAnchor*>& OutAnchors)
{
	bool HitAnything = false;
	for (const auto& Room : Rooms)
	{
		if (!Room)
		{
			continue;
		}
		if (Room->RaycastAll(Origin, Direction, MaxDist, LabelFilter, OutHits, OutAnchors))
		{
			HitAnything = true;
		}
	}
	return HitAnything;
}

void UMRUKSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	const UMRUKSettings* Settings = GetMutableDefault<UMRUKSettings>();
	EnableWorldLock = Settings->EnableWorldLock;

}

void UMRUKSubsystem::Deinitialize()
{
}

TSharedRef<FJsonObject> UMRUKSubsystem::JsonSerialize()
{
	TSharedRef<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	TArray<TSharedPtr<FJsonValue>> RoomsArray;

	for (const auto& Room : Rooms)
	{
		if (Room)
		{
			RoomsArray.Add(MakeShareable(new FJsonValueObject(Room->JsonSerialize())));
		}
	}

	JsonObject->SetArrayField(TEXT("Rooms"), RoomsArray);

	return JsonObject;
}

void UMRUKSubsystem::UnregisterRoom(AMRUKRoom* Room)
{
	Rooms.Remove(Room);
}

AMRUKRoom* UMRUKSubsystem::GetCurrentRoom() const
{
	// This is a rather expensive operation, we should only do it at most once per frame.
	if (CachedCurrentRoomFrame != GFrameCounter)
	{
		if (const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0))
		{
			if (APawn* Pawn = PlayerController->GetPawn())
			{
				const auto& PawnTransform = Pawn->GetActorTransform();

				FVector HeadPosition;
				FRotator Unused;

				// Get the position and rotation of the VR headset
				UHeadMountedDisplayFunctionLibrary::GetOrientationAndPosition(Unused, HeadPosition);

				HeadPosition = PawnTransform.TransformPosition(HeadPosition);

				for (const auto& Room : Rooms)
				{
					if (IsValid(Room) && Room->IsPositionInRoom(HeadPosition))
					{
						CachedCurrentRoom = Room;
						CachedCurrentRoomFrame = GFrameCounter;
						return Room;
					}
				}
			}
		}
	}

	if (IsValid(CachedCurrentRoom))
	{
		return CachedCurrentRoom;
	}

	for (const auto& Room : Rooms)
	{
		if (IsValid(Room))
		{
			return Room;
		}
	}
	return nullptr;
}

FString UMRUKSubsystem::SaveSceneToJsonString()
{
	FString Json;
	const TSharedRef<TJsonWriter<>> JsonWriter = TJsonWriterFactory<>::Create(&Json, 0);
	FJsonSerializer::Serialize(JsonSerialize(), JsonWriter);
	return Json;
}

void UMRUKSubsystem::LoadSceneFromJsonString(const FString& String)
{
	if (SceneData || SceneLoadStatus == EMRUKInitStatus::Busy)
	{
		UE_LOG(LogMRUK, Error, TEXT("Can't start loading a scene from JSON while the scene is already loading"));
		return;
	}

	SceneData = NewObject<UMRUKSceneData>(this);

	if (SceneLoadStatus == EMRUKInitStatus::Complete)
	{
		// Update the scene
		UE_LOG(LogMRUK, Log, TEXT("Update scene from JSON"));
		SceneData->OnComplete.AddDynamic(this, &UMRUKSubsystem::UpdatedSceneDataLoadedComplete);
	}
	else
	{
		UE_LOG(LogMRUK, Log, TEXT("Load scene from JSON"));
		SceneData->OnComplete.AddDynamic(this, &UMRUKSubsystem::SceneDataLoadedComplete);
	}
	SceneLoadStatus = EMRUKInitStatus::Busy;
	SceneData->LoadFromJson(String);
}

void UMRUKSubsystem::LoadSceneFromDevice(int MaxQueries)
{
	const auto SceneEventDelegates = GEngine->GetEngineSubsystem<UOculusXRSceneEventDelegates>();

	if (SceneData || SceneLoadStatus == EMRUKInitStatus::Busy)
	{
		UE_LOG(LogMRUK, Error, TEXT("Can't start loading a scene from device while the scene is already loading"));
		if (SceneData)
		{
			UE_LOG(LogMRUK, Error, TEXT("Ongoing scene data query"));
		}
		return;
	}

	SceneData = NewObject<UMRUKSceneData>(this);
	if (!Rooms.IsEmpty())
	{
		// Update the scene
		UE_LOG(LogMRUK, Log, TEXT("Update scene from device"));
		SceneData->OnComplete.AddDynamic(this, &UMRUKSubsystem::UpdatedSceneDataLoadedComplete);
	}
	else
	{
		UE_LOG(LogMRUK, Log, TEXT("Load scene from device"));
		SceneData->OnComplete.AddDynamic(this, &UMRUKSubsystem::SceneDataLoadedComplete);
	}
	SceneLoadStatus = EMRUKInitStatus::Busy;
	SceneData->LoadFromDevice(MaxQueries);
}

void UMRUKSubsystem::SceneDataLoadedComplete(bool Success)
{
	UE_LOG(LogMRUK, Log, TEXT("Loaded scene data. Success==%d"), Success);
	if (!SceneData)
	{
		UE_LOG(LogMRUK, Warning, TEXT("Can't process scene data if it's not loaded"));
		FinishedLoading(false);
		return;
	}
	if (SceneData->RoomsData.IsEmpty())
	{
		UE_LOG(LogMRUK, Warning, TEXT("No room data found"));
		FinishedLoading(false);
		return;
	}

	if (Success)
	{
		UE_LOG(LogMRUK, Log, TEXT("Spawn rooms from scene data"));
		for (const auto& RoomData : SceneData->RoomsData)
		{
			AMRUKRoom* Room = SpawnRoom();
			Room->LoadFromData(RoomData);
		}
	}
	FinishedLoading(Success);

	for (const auto& Room : Rooms)
	{
		OnRoomCreated.Broadcast(Room);
	}
}

void UMRUKSubsystem::UpdatedSceneDataLoadedComplete(bool Success)
{
	UE_LOG(LogMRUK, Log, TEXT("Loaded updated scene data from device. Sucess==%d"), Success);

	TArray<TObjectPtr<AMRUKRoom>> RoomsCreated;
	TArray<TObjectPtr<AMRUKRoom>> RoomsUpdated;

	if (Success)
	{
		UE_LOG(LogMRUK, Log, TEXT("Update found %d rooms"), SceneData->RoomsData.Num());

		TArray<TObjectPtr<AMRUKRoom>> RoomsToRemove = Rooms;
		Rooms.Empty();

		for (int i = 0; i < SceneData->RoomsData.Num(); ++i)
		{
			UMRUKRoomData* RoomData = SceneData->RoomsData[i];
			const TObjectPtr<AMRUKRoom>* RoomFound = RoomsToRemove.FindByPredicate([RoomData](TObjectPtr<AMRUKRoom> Room) {
				return Room->Corresponds(RoomData);
			});
			TObjectPtr<AMRUKRoom> Room = nullptr;
			if (RoomFound)
			{
				Room = *RoomFound;
				UE_LOG(LogMRUK, Log, TEXT("Update room from query"));
				Rooms.Push(Room);
				RoomsToRemove.Remove(Room);
				RoomsUpdated.Push(Room);
			}
			else
			{
				UE_LOG(LogMRUK, Log, TEXT("Spawn room from query"));
				Room = SpawnRoom();
				RoomsCreated.Push(Room);
			}
			Room->LoadFromData(RoomData);
		}

		UE_LOG(LogMRUK, Log, TEXT("Destroy %d old rooms"), RoomsToRemove.Num());
		for (const auto& Room : RoomsToRemove)
		{
			OnRoomRemoved.Broadcast(Room);
			Room->Destroy();
		}
	}
	FinishedLoading(Success);

	for (const auto& Room : RoomsUpdated)
	{
		OnRoomUpdated.Broadcast(Room);
	}
	for (const auto& Room : RoomsCreated)
	{
		OnRoomCreated.Broadcast(Room);
	}
}

void UMRUKSubsystem::ClearScene()
{
	if (SceneLoadStatus == EMRUKInitStatus::Busy)
	{
		UE_LOG(LogMRUK, Error, TEXT("Cannot clear scene while scene is loading"));
		return;
	}
	SceneLoadStatus = EMRUKInitStatus::None;
	// No ranged for loop because rooms may remove themselves from the array during destruction
	for (int32 I = Rooms.Num() - 1; I >= 0; --I)
	{
		AMRUKRoom* Room = Rooms[I];
		if (IsValid(Room))
		{
			Room->Destroy();
		}
	}
	Rooms.Empty();
}

AMRUKAnchor* UMRUKSubsystem::TryGetClosestSurfacePosition(const FVector& WorldPosition, FVector& OutSurfacePosition, const FMRUKLabelFilter& LabelFilter, double MaxDistance)
{
	AMRUKAnchor* ClosestAnchor = nullptr;

	for (const auto& Room : Rooms)
	{
		if (!Room)
		{
			continue;
		}
		double SurfaceDistance{};
		FVector SurfacePos{};
		if (const auto Anchor = Room->TryGetClosestSurfacePosition(WorldPosition, SurfacePos, SurfaceDistance, LabelFilter, MaxDistance))
		{
			ClosestAnchor = Anchor;
			OutSurfacePosition = SurfacePos;
			MaxDistance = SurfaceDistance;
		}
	}

	return ClosestAnchor;
}

AMRUKAnchor* UMRUKSubsystem::TryGetClosestSeatPose(const FVector& RayOrigin, const FVector& RayDirection, FTransform& OutSeatTransform)
{
	AMRUKAnchor* ClosestAnchor = nullptr;
	double ClosestSeatDistanceSq = DBL_MAX;

	for (const auto& Room : Rooms)
	{
		if (!Room)
		{
			continue;
		}

		FTransform SeatTransform{};
		if (AMRUKAnchor* Anchor = Room->TryGetClosestSeatPose(RayOrigin, RayDirection, SeatTransform))
		{
			const double SeatDistanceSq = (RayOrigin - Anchor->GetActorTransform().GetTranslation()).SquaredLength();
			if (SeatDistanceSq < ClosestSeatDistanceSq)
			{
				ClosestAnchor = Anchor;
				ClosestSeatDistanceSq = SeatDistanceSq;
				OutSeatTransform = SeatTransform;
			}
		}
	}

	return ClosestAnchor;
}

AMRUKAnchor* UMRUKSubsystem::GetBestPoseFromRaycast(const FVector& RayOrigin, const FVector& RayDirection, double MaxDist, const FMRUKLabelFilter& LabelFilter, FTransform& OutPose, EMRUKPositioningMethod PositioningMethod)
{
	AMRUKAnchor* ClosestAnchor = nullptr;
	double ClosestPoseDistanceSq = DBL_MAX;

	for (const auto& Room : Rooms)
	{
		if (!Room)
		{
			continue;
		}

		FTransform Pose{};
		AMRUKAnchor* Anchor = Room->GetBestPoseFromRaycast(RayOrigin, RayDirection, MaxDist, LabelFilter, Pose, PositioningMethod);
		if (Anchor)
		{
			const double PoseDistanceSq = (RayOrigin - OutPose.GetTranslation()).SquaredLength();
			if (PoseDistanceSq < ClosestPoseDistanceSq)
			{
				ClosestAnchor = Anchor;
				ClosestPoseDistanceSq = PoseDistanceSq;
				OutPose = Pose;
			}
		}
	}

	return ClosestAnchor;
}

AMRUKAnchor* UMRUKSubsystem::GetKeyWall(double Tolerance)
{
	if (AMRUKRoom* CurrentRoom = GetCurrentRoom())
	{
		return CurrentRoom->GetKeyWall(Tolerance);
	}
	return nullptr;
}

AMRUKAnchor* UMRUKSubsystem::GetLargestSurface(const FString& Label)
{
	if (AMRUKRoom* CurrentRoom = GetCurrentRoom())
	{
		return CurrentRoom->GetLargestSurface(Label);
	}
	return nullptr;
}

AMRUKAnchor* UMRUKSubsystem::IsPositionInSceneVolume(const FVector& WorldPosition, bool TestVerticalBounds, double Tolerance)
{
	for (const auto& Room : Rooms)
	{
		if (!Room)
		{
			continue;
		}
		if (const auto Anchor = Room->IsPositionInSceneVolume(WorldPosition, TestVerticalBounds, Tolerance))
		{
			return Anchor;
		}
	}
	return nullptr;
}

TArray<AActor*> UMRUKSubsystem::SpawnInterior(const TMap<FString, FMRUKSpawnGroup>& SpawnGroups, const TArray<FString>& CutHoleLabels, UMaterialInterface* ProceduralMaterial, bool ShouldFallbackToProcedural)
{
	return SpawnInteriorFromStream(SpawnGroups, FRandomStream(NAME_None), CutHoleLabels, ProceduralMaterial, ShouldFallbackToProcedural);
}

TArray<AActor*> UMRUKSubsystem::SpawnInteriorFromStream(const TMap<FString, FMRUKSpawnGroup>& SpawnGroups, const FRandomStream& RandomStream, const TArray<FString>& CutHoleLabels, UMaterialInterface* ProceduralMaterial, bool ShouldFallbackToProcedural)
{
	TArray<AActor*> AllInteriorActors;

	for (const auto& Room : Rooms)
	{
		if (!Room)
		{
			continue;
		}
		auto InteriorActors = Room->SpawnInteriorFromStream(SpawnGroups, RandomStream, CutHoleLabels, ProceduralMaterial, ShouldFallbackToProcedural);
		AllInteriorActors.Append(InteriorActors);
	}

	return AllInteriorActors;
}

bool UMRUKSubsystem::LaunchSceneCapture()
{
	const bool Success = GetRoomLayoutManager()->LaunchCaptureFlow();
	if (Success)
	{
		UE_LOG(LogMRUK, Log, TEXT("Capture flow launched with success"));
	}
	else
	{
		UE_LOG(LogMRUK, Error, TEXT("Launching capture flow failed!"));
	}
	return Success;
}

FBox UMRUKSubsystem::GetActorClassBounds(TSubclassOf<AActor> Actor)
{
	if (const auto Entry = ActorClassBoundsCache.Find(Actor))
	{
		return *Entry;
	}
	const auto TempActor = GetWorld()->SpawnActor(Actor);
	const auto Bounds = TempActor->CalculateComponentsBoundingBoxInLocalSpace(true);
	TempActor->Destroy();
	ActorClassBoundsCache.Add(Actor, Bounds);
	return Bounds;
}

void UMRUKSubsystem::SceneCaptureComplete(FOculusXRUInt64 RequestId, bool bSuccess)
{
	UE_LOG(LogMRUK, Log, TEXT("Scene capture complete Success==%d"), bSuccess);
	OnCaptureComplete.Broadcast(bSuccess);
}


UOculusXRRoomLayoutManagerComponent* UMRUKSubsystem::GetRoomLayoutManager()
{
	if (!RoomLayoutManager)
	{
		FActorSpawnParameters Params{};
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		Params.Owner = nullptr;
		RoomLayoutManagerActor = GetWorld()->SpawnActor<AActor>(Params);
		RoomLayoutManagerActor->SetRootComponent(NewObject<USceneComponent>(RoomLayoutManagerActor, TEXT("SceneComponent")));

		RoomLayoutManagerActor->AddComponentByClass(UOculusXRRoomLayoutManagerComponent::StaticClass(), false, FTransform::Identity, false);
		RoomLayoutManager = RoomLayoutManagerActor->GetComponentByClass<UOculusXRRoomLayoutManagerComponent>();
		RoomLayoutManager->OculusXRRoomLayoutSceneCaptureComplete.AddDynamic(this, &UMRUKSubsystem::SceneCaptureComplete);
	}
	return RoomLayoutManager;
}

AMRUKRoom* UMRUKSubsystem::SpawnRoom()
{
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AMRUKRoom* Room = GetWorld()->SpawnActor<AMRUKRoom>(ActorSpawnParams);


#if WITH_EDITOR
	Room->SetActorLabel(TEXT("ROOM"));
#endif

	Rooms.Push(Room);

	return Room;
}

void UMRUKSubsystem::FinishedLoading(bool Success)
{
	UE_LOG(LogMRUK, Log, TEXT("Finished loading: Success==%d"), Success);
	if (SceneData)
	{
		SceneData->MarkAsGarbage();
		SceneData = nullptr;
	}

	if (Success)
	{
		SceneLoadStatus = EMRUKInitStatus::Complete;
	}
	else
	{
		SceneLoadStatus = EMRUKInitStatus::Failed;
	}
	OnSceneLoaded.Broadcast(Success);
}

void UMRUKSubsystem::Tick(float DeltaTime)
{
	if (EnableWorldLock)
	{
		if (const auto Room = GetCurrentRoom())
		{
			if (const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0))
			{
				if (APawn* Pawn = PlayerController->GetPawn())
				{
					const auto& PawnTransform = Pawn->GetActorTransform();

					FVector HeadPosition;
					FRotator Unused;

					// Get the position and rotation of the VR headset
					UHeadMountedDisplayFunctionLibrary::GetOrientationAndPosition(Unused, HeadPosition);

					HeadPosition = PawnTransform.TransformPosition(HeadPosition);

					Room->UpdateWorldLock(Pawn, HeadPosition);
				}
			}
		}
	}

}

bool UMRUKSubsystem::IsTickable() const
{
	return !HasAnyFlags(RF_BeginDestroyed) && IsValidChecked(this) && (EnableWorldLock);
}

