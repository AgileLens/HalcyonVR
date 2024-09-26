// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitAnchorActorSpawner.h"

#include "MRUtilityKitAnchor.h"
#include "MRUtilityKitTelemetry.h"
#include "MRUtilityKitSubsystem.h"
#include "MRUtilityKitBPLibrary.h"
#include "GameFramework/WorldSettings.h"

#include "Engine/GameInstance.h"

const FName GMRUK_PROCEDURAL_ANCHOR_MESH_TAG = TEXT("MRUKProceduralAnchorMesh");

namespace
{
	AActor* SpawnProceduralMesh(AMRUKAnchor* Anchor, const TArray<FMRUKPlaneUV>& PlaneUVAdjustments, const TArray<FString>& CutHoleLabels, UMaterialInterface* Material)
	{
		AActor* Actor = Anchor->GetWorld()->SpawnActor<AActor>();
		Actor->SetOwner(Anchor);
		Actor->Tags.AddUnique(GMRUK_PROCEDURAL_ANCHOR_MESH_TAG);
		Actor->SetRootComponent(NewObject<USceneComponent>(Actor, TEXT("Root")));
		Actor->GetRootComponent()->SetMobility(EComponentMobility::Movable);
		Actor->AttachToComponent(Anchor->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		Actor->SetActorRelativeScale3D(FVector::OneVector);

		UProceduralMeshComponent* ProceduralMeshComponent = NewObject<UProceduralMeshComponent>(Actor, TEXT("ProceduralMesh"));
		ProceduralMeshComponent->SetupAttachment(Actor->GetRootComponent());
		ProceduralMeshComponent->RegisterComponent();
		Actor->AddInstanceComponent(ProceduralMeshComponent);

		Anchor->GenerateProceduralAnchorMesh(ProceduralMeshComponent, PlaneUVAdjustments, CutHoleLabels, false, true);

		for (int32 SectionIndex = 0; SectionIndex < ProceduralMeshComponent->GetNumSections(); ++SectionIndex)
		{
			ProceduralMeshComponent->SetMaterial(SectionIndex, Material);
		}
		return Actor;
	}
} // namespace

void AMRUKAnchorActorSpawner::BeginPlay()
{
	Super::BeginPlay();

#if WITH_EDITOR
	if (OculusXRTelemetry::IsActive())
	{
		MRUKTelemetry::FLoadAnchorActorSpawnerMarker().Start().End(OculusXRTelemetry::EAction::Success);
	}
#endif

	if (SpawnMode == EMRUKSpawnMode::CurrentRoomOnly)
	{
		const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
		if (Subsystem->SceneLoadStatus == EMRUKInitStatus::Complete)
		{
			SpawnActors(Subsystem->GetCurrentRoom());
		}
		else
		{
			// Only listen for the room created event in case no current room was available yet
			Subsystem->OnRoomCreated.AddUniqueDynamic(this, &AMRUKAnchorActorSpawner::OnRoomCreated);
		}
	}
	else if (SpawnMode == EMRUKSpawnMode::AllRooms)
	{
		const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
		for (auto Room : Subsystem->Rooms)
		{
			SpawnActors(Room);
		}

		// Listen for new rooms that get created
		Subsystem->OnRoomCreated.AddUniqueDynamic(this, &AMRUKAnchorActorSpawner::OnRoomCreated);
	}
}

void AMRUKAnchorActorSpawner::OnRoomCreated(AMRUKRoom* Room)
{
	if (SpawnMode == EMRUKSpawnMode::CurrentRoomOnly && SpawnedActors.Num() > 0)
	{
		// We already spawned a room
		return;
	}
	SpawnActors(Room);
}

void AMRUKAnchorActorSpawner::OnRoomUpdated(AMRUKRoom* Room)
{
	if (!SpawnedActors.Find(Room))
	{
		// A room was updated that we don't care about. If we are in current room only mode
		// we only want to update the one room we created
		return;
	}
	SpawnActors(Room);
}

void AMRUKAnchorActorSpawner::OnRoomRemoved(AMRUKRoom* Room)
{
	RemoveActors(Room);
}

void AMRUKAnchorActorSpawner::RemoveActors(AMRUKRoom* Room)
{
	if (!IsValid(Room))
	{
		UE_LOG(LogMRUK, Warning, TEXT("Can not remove actors from room that is a nullptr"));
		return;
	}

	if (TArray<AActor*>* Actors = SpawnedActors.Find(Room))
	{
		for (AActor* Actor : *Actors)
		{
			if (IsValid(Actor))
			{
				Actor->Destroy();
			}
		}
		Actors->Empty();
		SpawnedActors.Remove(Room);
	}
}

bool AMRUKAnchorActorSpawner::ShouldAnchorFallbackToProceduralMesh(const FMRUKSpawnGroup& SpawnGroup) const
{
	switch (SpawnGroup.FallbackToProcedural)
	{
		case EMRUKFallbackToProceduralOverwrite::Default:
			return ShouldFallbackToProcedural;
		case EMRUKFallbackToProceduralOverwrite::Fallback:
			return true;
		case EMRUKFallbackToProceduralOverwrite::NoFallback:
			return false;
	}
	return false;
}

TArray<AActor*> AMRUKAnchorActorSpawner::SpawnProceduralMeshesOnWallsIfNoWallActorGiven(AMRUKRoom* Room)
{
	TArray<AActor*> Actors;
	const auto WallFace = SpawnGroups.Find(FMRUKLabels::WallFace);
	if (!WallFace || (WallFace->Actors.IsEmpty() && ShouldAnchorFallbackToProceduralMesh(*WallFace)))
	{
		// If no wall mesh is given we want to spawn the walls procedural to make seamless UVs
		TArray<FMRUKAnchorWithPlaneUVs> AnchorsWithPlaneUVs;
		Room->ComputeWallMeshUVAdjustments({}, AnchorsWithPlaneUVs);
		for (const auto& AnchorWithPlaneUVs : AnchorsWithPlaneUVs)
		{
			Actors.Push(SpawnProceduralMesh(AnchorWithPlaneUVs.Anchor, AnchorWithPlaneUVs.PlaneUVs, CutHoleLabels, ProceduralMaterial));
		}
	}
	return Actors;
}

AActor* AMRUKAnchorActorSpawner::SpawnProceduralMeshOnFloorIfNoFloorActorGiven(AMRUKRoom* Room)
{
	const auto Floor = SpawnGroups.Find(FMRUKLabels::Floor);
	if (Room->FloorAnchor && (!Floor || (Floor->Actors.IsEmpty() && ShouldAnchorFallbackToProceduralMesh(*Floor))))
	{
		// Use metric scaling to match walls
		const float WorldToMeters = GetWorldSettings()->WorldToMeters;
		const FVector2D Scale = Room->FloorAnchor->PlaneBounds.GetSize() / WorldToMeters;
		const TArray<FMRUKPlaneUV> PlaneUVAdj = { { FVector2D::ZeroVector, Scale } };
		return SpawnProceduralMesh(Room->FloorAnchor, PlaneUVAdj, CutHoleLabels, ProceduralMaterial);
	}
	return nullptr;
}

AActor* AMRUKAnchorActorSpawner::SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven(AMRUKRoom* Room)
{
	const auto Ceiling = SpawnGroups.Find(FMRUKLabels::Ceiling);
	if (Room->CeilingAnchor && (!Ceiling || (Ceiling->Actors.IsEmpty() && ShouldAnchorFallbackToProceduralMesh(*Ceiling))))
	{
		// Use metric scaling to match walls
		const float WorldToMeters = GetWorldSettings()->WorldToMeters;
		const FVector2D Scale = Room->CeilingAnchor->PlaneBounds.GetSize() / WorldToMeters;
		const TArray<FMRUKPlaneUV> PlaneUVAdj = { { FVector2D::ZeroVector, Scale } };
		return SpawnProceduralMesh(Room->CeilingAnchor, PlaneUVAdj, CutHoleLabels, ProceduralMaterial);
	}
	return nullptr;
}

AActor* AMRUKAnchorActorSpawner::SpawnProceduralMeshForAnchorIfNeeded(AMRUKAnchor* Anchor)
{
	if (!IsValid(Anchor))
	{
		return nullptr;
	}

	if (Anchor->SemanticClassifications.IsEmpty())
	{
		// For unknown scene objects spawn a procedural mesh (should not happen in practice)
		return SpawnProceduralMesh(Anchor, {}, CutHoleLabels, ProceduralMaterial);
	}

	for (const FString& Label : Anchor->SemanticClassifications)
	{
		if (Label == FMRUKLabels::WallFace && Anchor->SemanticClassifications.Contains(FMRUKLabels::InvisibleWallFace))
		{
			// Treat anchors with WALL_FACE and INVISIBLE_WALL_FACE as anchors that only have INVISIBLE_WALL_FACE
			continue;
		}

		const FMRUKSpawnGroup* SpawnGroup = SpawnGroups.Find(Label);
		if (SpawnGroup && SpawnGroup->Actors.IsEmpty() && ShouldAnchorFallbackToProceduralMesh(*SpawnGroup))
		{
			return SpawnProceduralMesh(Anchor, {}, CutHoleLabels, ProceduralMaterial);
		}
	}

	return nullptr;
}

TArray<AActor*> AMRUKAnchorActorSpawner::SpawnProceduralMeshesInRoom(AMRUKRoom* Room)
{
	TArray<AActor*> Actors;

	const TArray<AActor*> WallActors = SpawnProceduralMeshesOnWallsIfNoWallActorGiven(Room);
	if (!WallActors.IsEmpty())
	{
		Actors.Append(WallActors);
	}

	AActor* Actor = nullptr;

	Actor = SpawnProceduralMeshOnFloorIfNoFloorActorGiven(Room);
	if (Actor)
	{
		Actors.Push(Actor);
	}
	Actor = SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven(Room);
	if (Actor)
	{
		Actors.Push(Actor);
	}
	for (const auto& Anchor : Room->AllAnchors)
	{
		if (Anchor->HasLabel(FMRUKLabels::Floor) || Anchor->HasLabel(FMRUKLabels::Ceiling) || Anchor->HasLabel(FMRUKLabels::WallFace))
		{
			// These have already been spawned above in case it was necessary
			continue;
		}
		Actor = SpawnProceduralMeshForAnchorIfNeeded(Anchor);
		if (Actor)
		{
			Actors.Push(Actor);
		}
	}

	return Actors;
}

bool AMRUKAnchorActorSpawner::SelectSpawnActorClosestSize(AMRUKAnchor* Anchor, const FMRUKSpawnGroup& SpawnGroup, FMRUKSpawnActor& OutSpawnActor)
{
	if (SpawnGroup.Actors.IsEmpty())
	{
		return false;
	}

	int Index = 0;
	if (SpawnGroup.Actors.Num() > 1)
	{
		if (Anchor->VolumeBounds.IsValid)
		{
			const double AnchorSize = FMath::Pow(Anchor->VolumeBounds.GetVolume(), 1.0 / 3.0);
			double ClosestSizeDifference = UE_BIG_NUMBER;
			for (int i = 0; i < SpawnGroup.Actors.Num(); ++i)
			{
				const auto& SpawnActor = SpawnGroup.Actors[i];
				const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
				auto Bounds = Subsystem->GetActorClassBounds(SpawnActor.Actor);
				if (Bounds.IsValid)
				{
					const double SpawnActorSize = FMath::Pow(Bounds.GetVolume(), 1.0 / 3.0);
					const double SizeDifference = FMath::Abs(AnchorSize - SpawnActorSize);
					if (SizeDifference < ClosestSizeDifference)
					{
						ClosestSizeDifference = SizeDifference;
						Index = i;
					}
				}
			}
		}
	}
	OutSpawnActor = SpawnGroup.Actors[Index];
	return true;
}

bool AMRUKAnchorActorSpawner::SelectSpawnActorRandom(const FMRUKSpawnGroup& SpawnGroup, const FRandomStream& RandomStream, FMRUKSpawnActor& OutSpawnActor)
{
	if (SpawnGroup.Actors.IsEmpty())
	{
		return false;
	}
	const int Index = RandomStream.RandRange(0, SpawnGroup.Actors.Num() - 1);
	OutSpawnActor = SpawnGroup.Actors[Index];
	return true;
}

bool AMRUKAnchorActorSpawner::SelectSpawnActorFromSpawnGroup(AMRUKAnchor* Anchor, const FMRUKSpawnGroup& SpawnGroup, const FRandomStream& RandomStream, FMRUKSpawnActor& OutSpawnActor)
{
	if (SpawnGroup.Actors.IsEmpty())
	{
		return false;
	}
	if (SpawnGroup.SelectionMode == EMRUKSpawnerSelectionMode::Random)
	{
		return SelectSpawnActorRandom(SpawnGroup, RandomStream, OutSpawnActor);
	}
	if (SpawnGroup.SelectionMode == EMRUKSpawnerSelectionMode::ClosestSize)
	{
		return SelectSpawnActorClosestSize(Anchor, SpawnGroup, OutSpawnActor);
	}
	if (SpawnGroup.SelectionMode == EMRUKSpawnerSelectionMode::Custom)
	{
		return SelectSpawnActorCustom(Anchor, SpawnGroup, RandomStream, OutSpawnActor);
	}
	OutSpawnActor = SpawnGroup.Actors[0];
	return true;
}

void AMRUKAnchorActorSpawner::AttachAndFitActorToAnchor(AMRUKAnchor* Anchor, AActor* Actor, EMRUKSpawnerScalingMode ScalingMode, EMRUKAlignMode AlignMode, bool bCalculateFacingDirection, bool bMatchAspectRatio)
{
	auto ActorRoot = Actor->GetRootComponent();
	if (!ActorRoot)
	{
		UE_LOG(LogMRUK, Error, TEXT("Spawned actor does not have a root component."));
		return;
	}
	ActorRoot->SetMobility(EComponentMobility::Movable);
	Actor->AttachToComponent(Anchor->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	Actor->SetActorRelativeScale3D(FVector::OneVector);

	const auto ChildLocalBounds = Actor->CalculateComponentsBoundingBoxInLocalSpace(true);
	FQuat Rotation = FQuat::Identity;
	FVector Offset = FVector::ZeroVector;
	FVector Scale = FVector::OneVector;

	if (Anchor->VolumeBounds.IsValid)
	{
		int CardinalAxisIndex = 0;
		if (bCalculateFacingDirection && !bMatchAspectRatio)
		{
			// Pick rotation that is pointing away from the closest wall
			// If we are also matching the aspect ratio then we only have a choice
			// between 2 directions and first need to figure out what those 2 directions
			// are before doing the ray casting.
			UMRUKBPLibrary::ComputeDirectionAwayFromClosestWall(Anchor, CardinalAxisIndex, {});
		}
		Rotation = FQuat::MakeFromEuler(FVector(90, -(CardinalAxisIndex + 1) * 90, 90));

		FBox ChildBounds = ChildLocalBounds.TransformBy(FTransform(Rotation));
		const FVector ChildSize1 = ChildBounds.GetSize();

		Scale = Anchor->VolumeBounds.GetSize() / ChildSize1;

		if (bMatchAspectRatio)
		{
			FVector ChildSize2 = ChildSize1;
			Swap(ChildSize2.Y, ChildSize2.Z);
			FVector Scale2 = Anchor->VolumeBounds.GetSize() / ChildSize2;

			float Distortion1 = FMath::Max(Scale.Y, Scale.Z) / FMath::Min(Scale.Y, Scale.Z);
			float Distortion2 = FMath::Max(Scale2.Y, Scale2.Z) / FMath::Min(Scale2.Y, Scale2.Z);

			bool FlipToMatchAspectRatio = Distortion1 > Distortion2;
			if (FlipToMatchAspectRatio)
			{
				CardinalAxisIndex = 1;
				Scale = Scale2;
			}
			if (bCalculateFacingDirection)
			{
				UMRUKBPLibrary::ComputeDirectionAwayFromClosestWall(Anchor, CardinalAxisIndex, FlipToMatchAspectRatio ? TArray<int>{ 0, 2 } : TArray<int>{ 1, 3 });
			}
			if (CardinalAxisIndex != 0)
			{
				// Update the rotation and child bounds if necessary
				Rotation = FQuat::MakeFromEuler(FVector(90, -(CardinalAxisIndex + 1) * 90, 90));
				ChildBounds = ChildLocalBounds.TransformBy(FTransform(Rotation));
			}
		}

		switch (ScalingMode)
		{
			case EMRUKSpawnerScalingMode::UniformScaling:
				Scale.X = Scale.Y = Scale.Z = FMath::Min3(Scale.X, Scale.Y, Scale.Z);
				break;
			case EMRUKSpawnerScalingMode::UniformXYScale:
				Scale.Y = Scale.Z = FMath::Min(Scale.Y, Scale.Z);
				break;
			case EMRUKSpawnerScalingMode::NoScaling:
				Scale = FVector::OneVector;
				break;
			case EMRUKSpawnerScalingMode::Stretch:
				// Nothing to do
				break;
			case EMRUKSpawnerScalingMode::Custom:
				Scale = ComputeCustomScaling(Anchor, Actor, Scale);
				break;
		}

		if (AlignMode == EMRUKAlignMode::Custom)
		{
			Offset = ComputeCustomAlign(Anchor, Actor, ChildBounds, Scale);
		}
		else if (AlignMode != EMRUKAlignMode::None)
		{
			FVector ChildBase;
			FVector VolumeBase;

			switch (AlignMode)
			{
				case EMRUKAlignMode::CenterOnCenter:
					ChildBase = FVector(0.5 * (ChildBounds.Min.X + ChildBounds.Max.X), 0.5 * (ChildBounds.Min.Y + ChildBounds.Max.Y), 0.5 * (ChildBounds.Min.Z + ChildBounds.Max.Z));
					break;

				case EMRUKAlignMode::TopOnTop:
				case EMRUKAlignMode::TopOnBottom:
					ChildBase = FVector(ChildBounds.Min.X, 0.5 * (ChildBounds.Min.Y + ChildBounds.Max.Y), 0.5 * (ChildBounds.Min.Z + ChildBounds.Max.Z));
					break;

				case EMRUKAlignMode::Default:
				case EMRUKAlignMode::BottomOnBottom:
				case EMRUKAlignMode::BottomOnTop:
					ChildBase = FVector(ChildBounds.Max.X, 0.5 * (ChildBounds.Min.Y + ChildBounds.Max.Y), 0.5 * (ChildBounds.Min.Z + ChildBounds.Max.Z));
					break;

				case EMRUKAlignMode::LeftOnLeft:
				case EMRUKAlignMode::LeftOnRight:
					ChildBase = FVector(0.5 * (ChildBounds.Min.X + ChildBounds.Max.X), 0.5 * (ChildBounds.Min.Y + ChildBounds.Max.Y), ChildBounds.Max.Z);
					break;

				case EMRUKAlignMode::RightOnRight:
				case EMRUKAlignMode::RightOnLeft:
					ChildBase = FVector(0.5 * (ChildBounds.Min.X + ChildBounds.Max.X), 0.5 * (ChildBounds.Min.Y + ChildBounds.Max.Y), ChildBounds.Min.Z);
					break;

				case EMRUKAlignMode::FrontOnFront:
				case EMRUKAlignMode::FrontOnBack:
					ChildBase = FVector(0.5 * (ChildBounds.Min.X + ChildBounds.Max.X), ChildBounds.Max.Y, 0.5 * (ChildBounds.Min.Z + ChildBounds.Max.Z));
					break;

				case EMRUKAlignMode::BackOnBack:
				case EMRUKAlignMode::BackOnFront:
					ChildBase = FVector(0.5 * (ChildBounds.Min.X + ChildBounds.Max.X), ChildBounds.Min.Y, 0.5 * (ChildBounds.Min.Z + ChildBounds.Max.Z));
					break;
			}

			switch (AlignMode)
			{
				case EMRUKAlignMode::CenterOnCenter:
					VolumeBase = FVector(0.5 * (Anchor->VolumeBounds.Min.X + Anchor->VolumeBounds.Max.X), 0.5 * (Anchor->VolumeBounds.Min.Y + Anchor->VolumeBounds.Max.Y), 0.5 * (Anchor->VolumeBounds.Min.Z + Anchor->VolumeBounds.Max.Z));
					break;

				case EMRUKAlignMode::TopOnTop:
				case EMRUKAlignMode::BottomOnTop:
					VolumeBase = FVector(Anchor->VolumeBounds.Min.X, 0.5 * (Anchor->VolumeBounds.Min.Y + Anchor->VolumeBounds.Max.Y), 0.5 * (Anchor->VolumeBounds.Min.Z + Anchor->VolumeBounds.Max.Z));
					break;

				case EMRUKAlignMode::Default:
				case EMRUKAlignMode::BottomOnBottom:
				case EMRUKAlignMode::TopOnBottom:
					VolumeBase = FVector(Anchor->VolumeBounds.Max.X, 0.5 * (Anchor->VolumeBounds.Min.Y + Anchor->VolumeBounds.Max.Y), 0.5 * (Anchor->VolumeBounds.Min.Z + Anchor->VolumeBounds.Max.Z));
					break;

				case EMRUKAlignMode::LeftOnLeft:
				case EMRUKAlignMode::RightOnLeft:
					VolumeBase = FVector(0.5 * (Anchor->VolumeBounds.Min.X + Anchor->VolumeBounds.Max.X), 0.5 * (Anchor->VolumeBounds.Min.Y + Anchor->VolumeBounds.Max.Y), Anchor->VolumeBounds.Max.Z);
					break;

				case EMRUKAlignMode::RightOnRight:
				case EMRUKAlignMode::LeftOnRight:
					VolumeBase = FVector(0.5 * (Anchor->VolumeBounds.Min.X + Anchor->VolumeBounds.Max.X), 0.5 * (Anchor->VolumeBounds.Min.Y + Anchor->VolumeBounds.Max.Y), Anchor->VolumeBounds.Min.Z);
					break;

				case EMRUKAlignMode::FrontOnFront:
				case EMRUKAlignMode::BackOnFront:
					VolumeBase = FVector(0.5 * (Anchor->VolumeBounds.Min.X + Anchor->VolumeBounds.Max.X), Anchor->VolumeBounds.Max.Y, 0.5 * (Anchor->VolumeBounds.Min.Z + Anchor->VolumeBounds.Max.Z));
					break;

				case EMRUKAlignMode::BackOnBack:
				case EMRUKAlignMode::FrontOnBack:
					VolumeBase = FVector(0.5 * (Anchor->VolumeBounds.Min.X + Anchor->VolumeBounds.Max.X), Anchor->VolumeBounds.Min.Y, 0.5 * (Anchor->VolumeBounds.Min.Z + Anchor->VolumeBounds.Max.Z));
					break;
			}
			Offset = VolumeBase - ChildBase * Scale;
		}
	}
	else if (Anchor->PlaneBounds.bIsValid)
	{
		const auto XAxis = Anchor->GetTransform().GetUnitAxis(EAxis::X);
		// Adjust the rotation so that Z always points up. This enables assets to be authored in a more natural
		// way and show up in the scene as expected.
		if (XAxis.Z <= -UE_INV_SQRT_2)
		{
			// This is a floor or other surface facing upwards
			Rotation = FQuat::MakeFromEuler(FVector(0, 90, 0));
		}
		else if (XAxis.Z >= UE_INV_SQRT_2)
		{
			// This is ceiling or other surface facing downwards.
			Rotation = FQuat::MakeFromEuler(FVector(0, -90, 0));
		}
		else
		{
			// This is a wall or other upright surface.
			Rotation = FQuat::MakeFromEuler(FVector(0, 0, 180));
		}

		const auto ChildBounds = ChildLocalBounds.TransformBy(FTransform(Rotation));
		const auto ChildBounds2D = FBox2D(FVector2D(ChildBounds.Min.Y, ChildBounds.Min.Z), FVector2D(ChildBounds.Max.Y, ChildBounds.Max.Z));
		auto Scale2D = Anchor->PlaneBounds.GetSize() / ChildBounds2D.GetSize();

		switch (ScalingMode)
		{
			case EMRUKSpawnerScalingMode::UniformScaling:
			case EMRUKSpawnerScalingMode::UniformXYScale:
				Scale2D.X = Scale2D.Y = FMath::Min(Scale2D.X, Scale2D.Y);
				break;
			case EMRUKSpawnerScalingMode::NoScaling:
				Scale2D = FVector2D::UnitVector;
				break;
			case EMRUKSpawnerScalingMode::Stretch:
				// Nothing to do
				break;
			case EMRUKSpawnerScalingMode::Custom:
				const FVector S = ComputeCustomScaling(Anchor, Actor, FVector(Scale2D.X, Scale2D.Y, 0.0));
				Scale2D.X = S.X;
				Scale2D.Y = S.Y;
				break;
		}

		FVector2D Offset2D = FVector2D::ZeroVector;
		switch (AlignMode)
		{
			case EMRUKAlignMode::None:
			case EMRUKAlignMode::BackOnBack:
			case EMRUKAlignMode::FrontOnFront:
			case EMRUKAlignMode::FrontOnBack:
			case EMRUKAlignMode::BackOnFront:
				Offset = FVector::ZeroVector;
				break;
			case EMRUKAlignMode::Default:
			case EMRUKAlignMode::CenterOnCenter:
				Offset2D = Anchor->PlaneBounds.GetCenter() - ChildBounds2D.GetCenter() * Scale2D;
				break;
			case EMRUKAlignMode::BottomOnBottom:
				Offset2D = FVector2D(Anchor->PlaneBounds.GetCenter().X, Anchor->PlaneBounds.Min.Y) - FVector2D(ChildBounds2D.GetCenter().X, ChildBounds2D.Min.Y) * Scale2D;
				break;
			case EMRUKAlignMode::TopOnTop:
				Offset2D = FVector2D(Anchor->PlaneBounds.GetCenter().X, Anchor->PlaneBounds.Max.Y) - FVector2D(ChildBounds2D.GetCenter().X, ChildBounds2D.Max.Y) * Scale2D;
				break;
			case EMRUKAlignMode::LeftOnLeft:
				Offset2D = FVector2D(Anchor->PlaneBounds.Max.X, Anchor->PlaneBounds.GetCenter().Y) - FVector2D(ChildBounds2D.Max.X, ChildBounds2D.GetCenter().Y) * Scale2D;
				break;
			case EMRUKAlignMode::RightOnRight:
				Offset2D = FVector2D(Anchor->PlaneBounds.Min.X, Anchor->PlaneBounds.GetCenter().Y) - FVector2D(ChildBounds2D.Min.X, ChildBounds2D.GetCenter().Y) * Scale2D;
				break;
			case EMRUKAlignMode::BottomOnTop:
				Offset2D = FVector2D(Anchor->PlaneBounds.GetCenter().X, Anchor->PlaneBounds.Max.Y) - FVector2D(ChildBounds2D.GetCenter().X, ChildBounds2D.Min.Y) * Scale2D;
				break;
			case EMRUKAlignMode::TopOnBottom:
				Offset2D = FVector2D(Anchor->PlaneBounds.GetCenter().X, Anchor->PlaneBounds.Min.Y) - FVector2D(ChildBounds2D.GetCenter().X, ChildBounds2D.Max.Y) * Scale2D;
				break;
			case EMRUKAlignMode::LeftOnRight:
				Offset2D = FVector2D(Anchor->PlaneBounds.Min.X, Anchor->PlaneBounds.GetCenter().Y) - FVector2D(ChildBounds2D.Max.X, ChildBounds2D.GetCenter().Y) * Scale2D;
				break;
			case EMRUKAlignMode::RightOnLeft:
				Offset2D = FVector2D(Anchor->PlaneBounds.Max.X, Anchor->PlaneBounds.GetCenter().Y) - FVector2D(ChildBounds2D.Min.X, ChildBounds2D.GetCenter().Y) * Scale2D;
				break;
			case EMRUKAlignMode::Custom:
				Offset = ComputeCustomAlign(Anchor, Actor, FBox(FVector(ChildBounds2D.Min, 0.0), FVector(ChildBounds2D.Max, 0.0)), FVector(Scale2D.X, Scale2D.Y, 0.0));
				Offset2D = FVector2D(Offset.X, Offset.Y);
				break;
		}

		Offset = FVector(0.0, Offset2D.X, Offset2D.Y);
		Scale = FVector(0.5 * (Scale2D.X + Scale2D.Y), Scale2D.X, Scale2D.Y);
	}
	Actor->SetActorRelativeRotation(Rotation);
	Actor->SetActorRelativeLocation(Offset);
	UMRUKBPLibrary::SetScaleRecursivelyAdjustingForRotation(ActorRoot, Scale);
}

AActor* AMRUKAnchorActorSpawner::SpawnAnchorActor_Implementation(AMRUKAnchor* Anchor, const FMRUKSpawnActor& SpawnActor)
{
	AActor* SpawnedActor = GetWorld()->SpawnActor(SpawnActor.Actor);
	AttachAndFitActorToAnchor(Anchor, SpawnedActor, SpawnActor.ScalingMode, SpawnActor.AlignMode, SpawnActor.CalculateFacingDirection, SpawnActor.MatchAspectRatio);
	return SpawnedActor;
}

FVector AMRUKAnchorActorSpawner::ComputeCustomScaling_Implementation(AMRUKAnchor* Anchor, AActor* SpawnedActor, const FVector& StretchedScale)
{
	UE_LOG(LogMRUK, Warning, TEXT("Custom scaling mode selected but default implementation used. Please override ComputeCustomScaling() to define custom scaling"));
	return StretchedScale;
}

bool AMRUKAnchorActorSpawner::SelectSpawnActorCustom_Implementation(AMRUKAnchor* Anchor, const FMRUKSpawnGroup& SpawnGroup, const FRandomStream& RandomStream, FMRUKSpawnActor& OutSpawnActor)
{
	UE_LOG(LogMRUK, Warning, TEXT("Custom selection mode specified, but custom selection logic was not overwritten. Please overwrite SelectSpawnActorCustom() to define custom selection logic"));
	return SelectSpawnActorRandom(SpawnGroup, RandomStream, OutSpawnActor);
}

FVector AMRUKAnchorActorSpawner::ComputeCustomAlign_Implementation(AMRUKAnchor* Anchor, AActor* Actor, const FBox& ChildBounds, const FVector& Scale)
{
	UE_LOG(LogMRUK, Warning, TEXT("Custom align mode selected but default implementation used. Please override ComputeCustomAlign() to define custom align"));
	return FVector::ZeroVector;
}

bool AMRUKAnchorActorSpawner::ShouldSpawnActorForAnchor(AMRUKAnchor* Anchor, const FString& Label, FMRUKSpawnGroup& OutSpawnGroup) const
{
	if (Label == FMRUKLabels::WallFace && Anchor->SemanticClassifications.Contains(FMRUKLabels::InvisibleWallFace))
	{
		// Treat anchors with WALL_FACE and INVISIBLE_WALL_FACE as anchors that only have INVISIBLE_WALL_FACE
		return false;
	}

	const auto SpawnGroup = SpawnGroups.Find(Label);
	if (!SpawnGroup)
	{
		return false;
	}
	if (SpawnGroup->Actors.IsEmpty() && ShouldAnchorFallbackToProceduralMesh(*SpawnGroup))
	{
		return false;
	}

	OutSpawnGroup = *SpawnGroup;
	return true;
}

AActor* AMRUKAnchorActorSpawner::SpawnAnchorActorForLabel_Implementation(AMRUKAnchor* Anchor, const FString& Label, const FMRUKSpawnGroup& SpawnGroup, const FRandomStream& RandomStream)
{
	FMRUKSpawnActor SpawnActor{};
	if (SelectSpawnActorFromSpawnGroup(Anchor, SpawnGroup, RandomStream, SpawnActor))
	{
		return SpawnAnchorActor(Anchor, SpawnActor);
	}
	UE_LOG(LogMRUK, Error, TEXT("Actor is nullptr for label %s."), *Label);
	return nullptr;
}

TArray<AActor*> AMRUKAnchorActorSpawner::SpawnAnchorActorsInRoom_Implementation(AMRUKRoom* Room, const FRandomStream& RandomStream)
{
	TArray<AActor*> SpawnedActorsInRoom;

	SpawnedActorsInRoom.Append(SpawnProceduralMeshesInRoom(Room));

	for (const auto& Anchor : Room->AllAnchors)
	{
		if (!IsValid(Anchor))
		{
			continue;
		}

		for (const FString& Label : Anchor->SemanticClassifications)
		{
			FMRUKSpawnGroup SpawnGroup{};
			if (!ShouldSpawnActorForAnchor(Anchor, Label, SpawnGroup))
			{
				continue;
			}

			if (AActor* SpawnedActor = SpawnAnchorActorForLabel(Anchor, Label, SpawnGroup, RandomStream))
			{
				SpawnedActorsInRoom.Push(SpawnedActor);
			}
		}
	}

	return SpawnedActorsInRoom;
}

void AMRUKAnchorActorSpawner::SpawnActors(AMRUKRoom* Room)
{
	if (!IsValid(Room))
	{
		UE_LOG(LogMRUK, Warning, TEXT("Can not spawn actors in Room that is a nullptr"));
		return;
	}

	RemoveActors(Room);

	// Use last seed if possible to keep spawning deterministic after the first spawn.
	// In case the anchor random spawn seed has been changed it will be used instead
	// of the last seed.
	int32 Seed = -1;
	if (LastSeed >= 0)
	{
		if ((AnchorRandomSpawnSeed >= 0) && (LastSeed != AnchorRandomSpawnSeed))
		{
			Seed = AnchorRandomSpawnSeed;
		}
		else
		{
			Seed = LastSeed;
		}
	}
	else if (AnchorRandomSpawnSeed >= 0)
	{
		Seed = AnchorRandomSpawnSeed;
	}

	FRandomStream RandomStream(Seed);
	if (Seed < 0)
	{
		RandomStream.GenerateNewSeed();
	}
	LastSeed = RandomStream.GetCurrentSeed();
	const TArray<AActor*>& Actors = SpawnAnchorActorsInRoom(Room, RandomStream);
	SpawnedActors.Add(Room, Actors);

	const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
	Subsystem->OnRoomUpdated.AddUniqueDynamic(this, &AMRUKAnchorActorSpawner::OnRoomUpdated);
	Subsystem->OnRoomRemoved.AddUniqueDynamic(this, &AMRUKAnchorActorSpawner::OnRoomRemoved);

	OnActorsSpawned.Broadcast(Room);
}

void AMRUKAnchorActorSpawner::GetSpawnedActorsByRoom(AMRUKRoom* Room, TArray<AActor*>& Actors)
{
	if (const TArray<AActor*>* A = SpawnedActors.Find(Room))
	{
		Actors.Append(*A);
	}
}

void AMRUKAnchorActorSpawner::GetSpawnedActors(TArray<AActor*>& Actors)
{
	for (const auto& KeyValue : SpawnedActors)
	{
		Actors.Append(KeyValue.Value);
	}
}
