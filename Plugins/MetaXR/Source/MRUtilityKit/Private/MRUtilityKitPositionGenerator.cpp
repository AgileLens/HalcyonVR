// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitPositionGenerator.h"
#include "MRUtilityKitSubsystem.h"
#include "Engine/OverlapResult.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "CollisionShape.h"

bool AMRUtilityKitPositionGenerator::CanSpawnBox(const UWorld* World, const FBox& Box, const FVector& SpawnPosition, const FQuat& SpawnRotation, const FCollisionQueryParams& QueryParams, const ECollisionChannel CollisionChannel)
{
	TArray<FOverlapResult> OutOverlaps;
	const bool bHasOverlap = World->OverlapMultiByChannel(OutOverlaps, SpawnPosition, SpawnRotation, CollisionChannel, FCollisionShape::MakeBox(Box.GetExtent()), QueryParams);
	return !bHasOverlap;
}

void AMRUtilityKitPositionGenerator::BeginPlay()
{
	Super::BeginPlay();

	if (RunOnStart)
	{
		const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
		if (Subsystem->SceneLoadStatus == EMRUKInitStatus::Complete)
		{
			SceneLoaded(true);
		}
		Subsystem->OnSceneLoaded.AddUniqueDynamic(this, &AMRUtilityKitPositionGenerator::SceneLoaded);
	}
}

bool AMRUtilityKitPositionGenerator::GenerateRandomPositionsOnSurface(TArray<FTransform>& OutTransforms)
{
	const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
	bool bSuccess = true;
	bool bAnyFailure = false;
	switch (RandomSpawnSettings.RoomFilter)
	{
		case EMRUKRoomFilter::None:
			break;
		case EMRUKRoomFilter::CurrentRoomOnly:
		{
			const auto Room = Subsystem->GetCurrentRoom();
			bSuccess = GenerateRandomPositionsOnSurfaceInRoom(Room, OutTransforms);
			break;
		}
		case EMRUKRoomFilter::AllRooms:
		{
			for (auto& Room : Subsystem->Rooms)
			{
				if (!GenerateRandomPositionsOnSurfaceInRoom(Room, OutTransforms))
				{
					bAnyFailure = true;
				}
			}
			bSuccess = !bAnyFailure;
			break;
		}
		default:;
	}
	return bSuccess;
}

bool AMRUtilityKitPositionGenerator::GenerateRandomPositionsOnSurfaceInRoom(AMRUKRoom* Room, TArray<FTransform>& OutTransforms)
{
	bool bInitializedAnchor = IsValid(RandomSpawnSettings.ActorInstance);
	if (bInitializedAnchor && RandomSpawnSettings.ActorClass != nullptr)
	{
		UE_LOG(LogMRUK, Error, TEXT("Cannot use an initialized Actor AND a defined ActorClass together. Use one of the options"));
		return false;
	}
	if (!bInitializedAnchor && RandomSpawnSettings.ActorClass == nullptr)
	{
		UE_LOG(LogMRUK, Error, TEXT("Please define ActorClass."));
		return false;
	}

	const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
	auto Bounds = bInitializedAnchor ? RandomSpawnSettings.ActorInstance->CalculateComponentsBoundingBoxInLocalSpace() : Subsystem->GetActorClassBounds(RandomSpawnSettings.ActorClass);

	float MinRadius = 0.0f;
	float CenterOffset = (Bounds.GetCenter().Z != 0) ? Bounds.GetCenter().Z : 0.0f;
	float BaseOffset = (Bounds.Min.Z != 0) ? -Bounds.Min.Z : 0.0f;

	FBox AdjustedBounds;

	TArray<FBox> SpawnedBounds;

	if (Bounds.IsValid)
	{
		constexpr float ClearanceDistance = 0.01f;
		CenterOffset = Bounds.GetCenter().Z;

		MinRadius = FMath::Min(FMath::Min(-Bounds.Min.X, -Bounds.Min.Y), FMath::Min(Bounds.Max.X, Bounds.Max.Y));
		if (MinRadius < 0.0f)
		{
			MinRadius = 0.0f;
		}

		FVector Min = Bounds.Min;
		FVector Max = Bounds.Max;
		Min.Z += ClearanceDistance;

		if (Max.Z < Min.Z)
		{
			Max.Z = Min.Z;
		}

		AdjustedBounds = FBox(Min, Max);
		if (RandomSpawnSettings.OverrideBounds > 0)
		{
			FVector Center = FVector(0.0f, 0.0f, ClearanceDistance);
			FVector Extents = FVector((RandomSpawnSettings.OverrideBounds), (RandomSpawnSettings.OverrideBounds), ClearanceDistance);
			AdjustedBounds = FBox(Center - Extents, Center + Extents);
		}
	}

	int FoundPositions = 0;

	for (int i = 0; i < RandomSpawnSettings.SpawnAmount; ++i)
	{
		for (int j = 0; j < RandomSpawnSettings.MaxIterations; ++j)
		{
			FVector SpawnPosition = FVector::ZeroVector;
			FVector SpawnNormal = FVector::ZeroVector;
			bool FoundSpawnPos = false;
			if (RandomSpawnSettings.SpawnLocations == EMRUKSpawnLocation::Floating)
			{
				FVector OutPos;
				if (auto bRandomPos = Room->GenerateRandomPositionInRoom(OutPos, MinRadius, true); !bRandomPos)
				{
					break;
				}
				SpawnPosition = OutPos;
				FoundSpawnPos = true;
			}
			else
			{
				if (FVector Normal, Pos; Room->GenerateRandomPositionOnSurface(RandomSpawnSettings.SpawnLocations, MinRadius, RandomSpawnSettings.Labels, Pos, Normal))
				{
					SpawnPosition = Pos + Normal * BaseOffset;
					SpawnNormal = Normal;
					auto Center = SpawnPosition + Normal * CenterOffset;
					if (auto bInRoom = Room->IsPositionInRoom(Center); !bInRoom)
					{
						continue;
					}
					if (Room->IsPositionInSceneVolume(Center))
					{
						continue;
					}
					if (FMRUKHit Hit{}; Room->Raycast(SpawnPosition, Normal, RandomSpawnSettings.SurfaceClearanceDistance, RandomSpawnSettings.Labels, Hit))
					{
						continue;
					}
					FoundSpawnPos = true;
				}
			}
			FQuat SpawnRotation = FQuat::Identity;
			if (!SpawnNormal.IsNearlyZero())
			{
				SpawnNormal.Normalize();
				SpawnRotation = FQuat::FindBetweenNormals(FVector::UpVector, SpawnNormal);
			}

			if (RandomSpawnSettings.CheckOverlaps && Bounds.IsValid && FoundSpawnPos)
			{
				FBox WorldBounds(AdjustedBounds.Min + SpawnPosition - AdjustedBounds.GetCenter(), AdjustedBounds.Max + SpawnPosition - AdjustedBounds.GetCenter());

				FVector AdjustedSpawnPos = SpawnPosition + SpawnRotation * AdjustedBounds.GetCenter();

				// check against world
				if (!CanSpawnBox(GetTickableGameObjectWorld(), WorldBounds, AdjustedSpawnPos, SpawnRotation, FCollisionQueryParams::DefaultQueryParam, RandomSpawnSettings.CollisionChannel))
				{
					continue;
				}
			}
			if (bInitializedAnchor && FoundSpawnPos)
			{
				RandomSpawnSettings.ActorInstance->SetActorLocationAndRotation(SpawnPosition, SpawnRotation);

				// ignore SpawnAmount once we have a successful move of existing object in the scene
				return true;
			}

			if (FoundSpawnPos)
			{
				OutTransforms.Add(FTransform(SpawnRotation, SpawnPosition, FVector::OneVector));
				FoundPositions++;
				break;
			}
		}
	}
	return FoundPositions == RandomSpawnSettings.SpawnAmount;
}

void AMRUtilityKitPositionGenerator::SceneLoaded(bool Success)
{
	if (Success)
	{
		TArray<FTransform> OutTransforms;
		const bool bSuccess = GenerateRandomPositionsOnSurface(OutTransforms);

		if (!bSuccess)
		{
			UE_LOG(LogMRUK, Warning, TEXT("Generate Random Positions on Surface not successful"));
			return;
		}

		if (RandomSpawnSettings.ActorClass != nullptr)
		{
			for (auto Transform : OutTransforms)
			{
				FActorSpawnParameters Params{};
				Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
				GetWorld()->SpawnActor(RandomSpawnSettings.ActorClass, &Transform, Params);
			}
		}
	}
}
