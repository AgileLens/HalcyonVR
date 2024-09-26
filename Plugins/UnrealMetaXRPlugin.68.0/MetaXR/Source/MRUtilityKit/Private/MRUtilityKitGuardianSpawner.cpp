// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitGuardianSpawner.h"

#include "Engine/GameInstance.h"
#include "Engine/GameEngine.h"
#include "IXRTrackingSystem.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "MRUtilityKitAnchor.h"
#include "MRUtilityKitGuardian.h"
#include "MRUtilityKitRoom.h"
#include "MRUtilityKitSubsystem.h"
#include "MRUtilityKitTelemetry.h"

AMRUKGuardianSpawner::AMRUKGuardianSpawner()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
}

void AMRUKGuardianSpawner::SetGuardianMaterial(UMaterialInstance* Material)
{
	if (!Material)
	{
		return;
	}

	GuardianMaterial = Material;
	DynamicGuardianMaterial = UMaterialInstanceDynamic::Create(GuardianMaterial, this);
	DynamicGuardianMaterial->SetVectorParameterValue(TEXT("WallScale"), FVector(GridDensity));

	// Recreate guardian meshes
	TArray<AMRUKRoom*> Rooms;
	SpawnedGuardians.GetKeys(Rooms);
	for (AMRUKRoom* Room : Rooms)
	{
		SpawnGuardians(Room);
	}
}

void AMRUKGuardianSpawner::SpawnGuardians(AMRUKRoom* Room)
{
	if (!IsValid(Room))
	{
		UE_LOG(LogMRUK, Warning, TEXT("Can not spawn Guardians for a room that is a nullptr"));
		return;
	}

	// Remove guardians that are already in this room
	DestroyGuardians(Room);

	const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
	Subsystem->OnRoomUpdated.AddUniqueDynamic(this, &AMRUKGuardianSpawner::OnRoomUpdated);
	Subsystem->OnRoomRemoved.AddUniqueDynamic(this, &AMRUKGuardianSpawner::OnRoomRemoved);

	const auto SpawnGuardian = [this](AMRUKAnchor* Anchor, const TArray<FMRUKPlaneUV>& PlaneUVAdjustments) {
		// Create guardian actor
		const auto GuardianActor = GetWorld()->SpawnActor<AMRUKGuardian>();
		GuardianActor->AttachToComponent(Anchor->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		GuardianActor->SetActorHiddenInGame(IsHidden());

		// Generate procedural mesh
		const auto ProceduralMesh = NewObject<UProceduralMeshComponent>(GuardianActor, TEXT("GuardianMesh"));
		Anchor->GenerateProceduralAnchorMesh(ProceduralMesh, PlaneUVAdjustments, {}, true, false, 0.01);
		ProceduralMesh->SetMaterial(0, DynamicGuardianMaterial);
		GuardianActor->CreateGuardian(ProceduralMesh);

		return GuardianActor;
	};

	TArray<AMRUKGuardian*> SpawnedActors;

	// Attach procedural meshes to the walls first because they are connected.
	TArray<FMRUKAnchorWithPlaneUVs> AnchorsWithPlaneUVs;
	const TArray<FMRUKTexCoordModes> WallTextureCoordinateModes = { { EMRUKCoordModeU::Metric, EMRUKCoordModeV::Metric } };
	Room->ComputeWallMeshUVAdjustments(WallTextureCoordinateModes, AnchorsWithPlaneUVs);

	for (const auto& [Anchor, PlaneUVs] : AnchorsWithPlaneUVs)
	{
		SpawnedActors.Push(SpawnGuardian(Anchor, PlaneUVs));
	}

	// Attach procedural meshes to the rest of the anchors. The walls have already meshes applied
	// because of the first step and will therefore be ignored by this code automatically.
	for (const auto& Anchor : Room->AllAnchors)
	{
		if (!Anchor || Anchor == Room->FloorAnchor || Anchor == Room->CeilingAnchor || Room->IsWallAnchor(Anchor))
		{
			continue;
		}

		SpawnedActors.Push(SpawnGuardian(Anchor, {}));
	}

	SpawnedGuardians.Add(Room, SpawnedActors);
}

void AMRUKGuardianSpawner::SetGridDensity(double Density)
{
	GridDensity = Density;

	if (DynamicGuardianMaterial)
	{
		DynamicGuardianMaterial->SetVectorParameterValue(TEXT("WallScale"), FVector(GridDensity));
	}
}

void AMRUKGuardianSpawner::Tick(float DeltaSeconds)
{
	if (!DynamicGuardianMaterial)
	{
		return;
	}

	if (EnableFade)
	{
		const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
		const auto CurrentRoom = Subsystem->GetCurrentRoom();
		if (!CurrentRoom)
		{
			return;
		}

		FQuat HeadsetOrientation;
		FVector HeadsetPosition(0.f);
		GEngine->XRSystem->GetCurrentPose(IXRTrackingSystem::HMDDeviceId, HeadsetOrientation, HeadsetPosition);

		FVector SurfacePosition = FVector::ZeroVector;
		double SurfaceDistance = 0.0;
		FMRUKLabelFilter LabelFilter;
		LabelFilter.ExcludedLabels = { FMRUKLabels::Ceiling, FMRUKLabels::Floor };
		CurrentRoom->TryGetClosestSurfacePosition(HeadsetPosition, SurfacePosition, SurfaceDistance, LabelFilter);

		const auto WorldToMeters = GetWorldSettings()->WorldToMeters;
		const auto GuardianFade = FMath::Clamp(1.0 - ((SurfaceDistance / WorldToMeters) / GuardianDistance), 0.0, 1.0);
		DynamicGuardianMaterial->SetScalarParameterValue(TEXT("Fade"), GuardianFade);
	}
}

void AMRUKGuardianSpawner::BeginPlay()
{
	Super::BeginPlay();

	SetGuardianMaterial(GuardianMaterial);

#if WITH_EDITOR
	if (OculusXRTelemetry::IsActive())
	{
		MRUKTelemetry::FLoadGuardianMarker().Start().End(OculusXRTelemetry::EAction::Success);
	}
#endif

	if (SpawnMode == EMRUKSpawnMode::CurrentRoomOnly)
	{
		const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
		if (Subsystem->SceneLoadStatus == EMRUKInitStatus::Complete)
		{
			if (AMRUKRoom* CurrentRoom = Subsystem->GetCurrentRoom())
			{
				SpawnGuardians(CurrentRoom);
			}
		}
		else
		{
			// Only listen for the room created event in case no current room was available yet
			Subsystem->OnRoomCreated.AddUniqueDynamic(this, &AMRUKGuardianSpawner::OnRoomCreated);
		}
	}
	else if (SpawnMode == EMRUKSpawnMode::AllRooms)
	{
		const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
		for (auto Room : Subsystem->Rooms)
		{
			SpawnGuardians(Room);
		}

		// Listen for new rooms that get created
		Subsystem->OnRoomCreated.AddUniqueDynamic(this, &AMRUKGuardianSpawner::OnRoomCreated);
	}
}

#if WITH_EDITOR
void AMRUKGuardianSpawner::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	const auto PropertyName = (PropertyChangedEvent.Property != nullptr) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	if (PropertyName == GET_MEMBER_NAME_CHECKED(AMRUKGuardianSpawner, GridDensity))
	{
		SetGridDensity(GridDensity);
	}
	else if (PropertyName == GET_MEMBER_NAME_CHECKED(AMRUKGuardianSpawner, GuardianMaterial))
	{
		SetGuardianMaterial(GuardianMaterial);
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void AMRUKGuardianSpawner::OnRoomCreated(AMRUKRoom* Room)
{
	if (SpawnMode == EMRUKSpawnMode::CurrentRoomOnly && SpawnedGuardians.Num() > 0)
	{
		// We already spawned a room
		return;
	}

	SpawnGuardians(Room);
}

void AMRUKGuardianSpawner::OnRoomUpdated(AMRUKRoom* Room)
{
	if (!SpawnedGuardians.Find(Room))
	{
		// A room was updated that we don't care about. If we are in current room only mode
		// we only want to update the one room we created
		return;
	}
	SpawnGuardians(Room);
}

void AMRUKGuardianSpawner::OnRoomRemoved(AMRUKRoom* Room)
{
	DestroyGuardians(Room);
}

void AMRUKGuardianSpawner::DestroyGuardians(AMRUKRoom* Room)
{
	if (TArray<AMRUKGuardian*>* Actors = SpawnedGuardians.Find(Room))
	{
		for (AActor* Actor : *Actors)
		{
			if (IsValid(Actor))
			{
				Actor->Destroy();
			}
		}
		Actors->Empty();
		SpawnedGuardians.Remove(Room);
	}
}
