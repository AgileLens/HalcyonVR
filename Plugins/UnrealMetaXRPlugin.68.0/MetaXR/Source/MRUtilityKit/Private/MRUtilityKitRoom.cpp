// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitRoom.h"
#include "MRUtilityKitAnchor.h"
#include "MRUtilityKitSerializationHelpers.h"
#include "MRUtilityKitSeatsComponent.h"
#include "MRUtilityKitSubsystem.h"
#include "MRUtilityKitBPLibrary.h"
#include "Engine/GameInstance.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/WorldSettings.h"
#include "Kismet/KismetMathLibrary.h"

#define LOCTEXT_NAMESPACE "MRUtilityKitRoom"

namespace
{
	double GetSeamlessFactor(double Perimeter, double StepSize)
	{
		double RoundedPerimeter = FMath::RoundHalfFromZero(Perimeter / StepSize);
		if (RoundedPerimeter <= 0.0)
		{
			RoundedPerimeter = 1.0;
		}
		return Perimeter / RoundedPerimeter;
	}

	FBox2D GetBoundsFromBoxForSide(const EMRUKBoxSide Side, const FBox& Box)
	{
		switch (Side)
		{
			case EMRUKBoxSide::XPos:
			case EMRUKBoxSide::XNeg:
				return FBox2D(FVector2D(Box.Min.Y, Box.Min.Z), FVector2D(Box.Max.Y, Box.Max.Z));
			case EMRUKBoxSide::YPos:
			case EMRUKBoxSide::YNeg:
				return FBox2D(FVector2D(Box.Min.X, Box.Min.Z), FVector2D(Box.Max.X, Box.Max.Z));
			case EMRUKBoxSide::ZPos:
			case EMRUKBoxSide::ZNeg:
				return FBox2D(FVector2D(Box.Min.X, Box.Min.Y), FVector2D(Box.Max.X, Box.Max.Y));
		}
		return {};
	}

	FVector GetNormalBoxSide(const EMRUKBoxSide Side)
	{
		switch (Side)
		{
			case EMRUKBoxSide::XPos:
				return FVector(1, 0, 0);
			case EMRUKBoxSide::XNeg:
				return FVector(-1, 0, 0);
			case EMRUKBoxSide::YPos:
				return FVector(0, 1, 0);
			case EMRUKBoxSide::YNeg:
				return FVector(0, -1, 0);
			case EMRUKBoxSide::ZPos:
				return FVector(0, 0, 1);
			case EMRUKBoxSide::ZNeg:
				return FVector(0, 0, -1);
		}
		return {};
	}

	FVector GetWorldPos(const FVector2D Pos2D, const AMRUKAnchor* ParentAnchor, const EMRUKBoxSide Side)
	{
		FVector LocalPos = FVector::Zero();
		switch (Side)
		{
			case EMRUKBoxSide::XPos:
				LocalPos = FVector(ParentAnchor->VolumeBounds.Max.X, Pos2D.X, Pos2D.Y);
				break;
			case EMRUKBoxSide::XNeg:
				LocalPos = FVector(ParentAnchor->VolumeBounds.Min.X, Pos2D.X, Pos2D.Y);
				break;
			case EMRUKBoxSide::YPos:
				LocalPos = FVector(Pos2D.X, ParentAnchor->VolumeBounds.Max.Y, Pos2D.Y);
				break;
			case EMRUKBoxSide::YNeg:
				LocalPos = FVector(Pos2D.X, ParentAnchor->VolumeBounds.Min.Y, Pos2D.Y);
				break;
			case EMRUKBoxSide::ZPos:
				LocalPos = FVector(Pos2D.X, Pos2D.Y, ParentAnchor->VolumeBounds.Max.Z);
				break;
			case EMRUKBoxSide::ZNeg:
				LocalPos = FVector(Pos2D.X, Pos2D.Y, ParentAnchor->VolumeBounds.Min.Z);
				break;
		}
		return ParentAnchor->ActorToWorld().TransformPosition(LocalPos);
	}

	const float InvSqrt2 = 1.0f / FMath::Sqrt(2.0f);

	bool IsActorOrientationHorizontal(const AActor* Actor)
	{
		bool bRet = false;
		if (Actor == nullptr)
			bRet = false;
		else if (Actor->GetActorUpVector().Z >= InvSqrt2) // walls, door or similar
			bRet = false;
		else if (FMath::Abs(Actor->GetActorUpVector().X) >= InvSqrt2)
			bRet = true;
		return bRet;
	}
} // namespace

AMRUKRoom::AMRUKRoom(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Create a scene component as root so we can attach spawned actors to it
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
}

void AMRUKRoom::EndPlay(EEndPlayReason::Type Reason)
{
	for (const auto& Anchor : AllAnchors)
	{
		OnAnchorRemoved.Broadcast(Anchor);
		Anchor->Destroy();
	}

	GetGameInstance()->GetSubsystem<UMRUKSubsystem>()->UnregisterRoom(this);
	Super::EndPlay(Reason);
}

void AMRUKRoom::LoadFromData(UMRUKRoomData* RoomData)
{
	check(RoomData);

	AnchorUUID = RoomData->SpaceQuery.UUID;
	SpaceHandle = RoomData->SpaceQuery.Space;
	RoomLayout = RoomData->RoomLayout;

	auto AnchorsToRemove = AllAnchors;

	AllAnchors.Empty();
	CeilingAnchor = nullptr;
	FloorAnchor = nullptr;
	WallAnchors.Empty();
	SeatAnchors.Empty();

	TArray<TObjectPtr<AMRUKAnchor>> AnchorsCreated;
	TArray<TObjectPtr<AMRUKAnchor>> AnchorsUpdated;

	for (const auto& AnchorData : RoomData->AnchorsData)
	{
		const auto AnchorFound = AnchorsToRemove.FindByPredicate([AnchorData](TObjectPtr<AMRUKAnchor> Anchor) {
			return Anchor && Anchor->AnchorUUID == AnchorData->SpaceQuery.UUID;
		});
		AMRUKAnchor* Anchor = nullptr;
		if (AnchorFound)
		{
			Anchor = *AnchorFound;
			UE_LOG(LogMRUK, Log, TEXT("Update existing anchor in room"));
			if (Anchor->LoadFromData(AnchorData))
			{
				AnchorsUpdated.Push(Anchor);
			}
			AnchorsToRemove.Remove(Anchor);
		}
		else
		{
			UE_LOG(LogMRUK, Log, TEXT("Spawn new anchor in room"));
			Anchor = SpawnAnchor();
			Anchor->LoadFromData(AnchorData);
			AnchorsCreated.Push(Anchor);
		}
		AddAnchorToRoom(Anchor);
	}

	UE_LOG(LogMRUK, Log, TEXT("Destroy %d old anchors"), AnchorsToRemove.Num());
	for (auto& OldAnchor : AnchorsToRemove)
	{
		OnAnchorRemoved.Broadcast(OldAnchor);
		OldAnchor->Destroy();
	}

	InitializeRoom();

	for (auto& Anchor : AnchorsUpdated)
	{
		OnAnchorUpdated.Broadcast(Anchor);
	}
	for (auto& Anchor : AnchorsCreated)
	{
		OnAnchorCreated.Broadcast(Anchor);
	}
}

TSharedRef<FJsonObject> AMRUKRoom::JsonSerialize()
{
	TSharedRef<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	TArray<TSharedPtr<FJsonValue>> AnchorsArray;
	for (const auto& Anchor : AllAnchors)
	{
		if (Anchor)
		{
			AnchorsArray.Add(MakeShareable(new FJsonValueObject(Anchor->JsonSerialize())));
		}
	}
	JsonObject->SetField(TEXT("UUID"), MRUKSerialize(AnchorUUID));
	JsonObject->SetField(TEXT("RoomLayout"), MRUKSerialize(RoomLayout));
	JsonObject->SetArrayField(TEXT("Anchors"), AnchorsArray);
	return JsonObject;
}

bool AMRUKRoom::Corresponds(UMRUKRoomData* RoomData) const
{
	if (!RoomData)
	{
		UE_LOG(LogMRUK, Warning, TEXT("Room query is null"));
		return false;
	}

	if (AnchorUUID == RoomData->SpaceQuery.UUID)
	{
		UE_LOG(LogMRUK, Log, TEXT("Rooms UUID equals"));
		return true;
	}

	for (const auto& Anchor : AllAnchors)
	{
		auto UUID = Anchor->AnchorUUID;
		const auto Found = RoomData->AnchorsData.FindByPredicate([UUID](TObjectPtr<UMRUKAnchorData> AnchorData) {
			return UUID == AnchorData->SpaceQuery.UUID;
		});
		if (Found)
		{
			return true;
		}
	}

	UE_LOG(LogMRUK, Log, TEXT("Room is not equal"));
	return false;
}

AMRUKAnchor* AMRUKRoom::SpawnAnchor()
{
	FActorSpawnParameters SpawnParameters{};
	SpawnParameters.Owner = this;
	const auto Anchor = GetWorld()->SpawnActor<AMRUKAnchor>(SpawnParameters);
	Anchor->Room = this;
	GetRootComponent()->SetMobility(EComponentMobility::Movable);
	Anchor->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

	return Anchor;
}

void AMRUKRoom::AddAnchorToRoom(AMRUKAnchor* Anchor)
{
#if WITH_EDITOR
	if (Anchor->SemanticClassifications.Num() > 0)
	{
		const FString Semantics = FString::Join(Anchor->SemanticClassifications, TEXT("-"));
		Anchor->SetActorLabel(Semantics);
	}
#endif

	if (Anchor->AnchorUUID == RoomLayout.FloorUuid)
	{
		FloorAnchor = Anchor;
	}
	if (Anchor->AnchorUUID == RoomLayout.CeilingUuid)
	{
		CeilingAnchor = Anchor;
	}
	if (RoomLayout.WallsUuid.Contains(Anchor->AnchorUUID))
	{
		WallAnchors.Push(Anchor);
	}
	if (Anchor->HasLabel(FMRUKLabels::GlobalMesh))
	{
		GlobalMeshAnchor = Anchor;
	}
	if (Anchor->HasLabel(FMRUKLabels::Couch))
	{
		SeatAnchors.Push(Anchor);
	}

	AllAnchors.Push(Anchor);
}

void AMRUKRoom::InitializeRoom()
{
	ComputeRoomBounds();
	ComputeAnchorHierarchy();
	ComputeSeats();
	ComputeRoomEdges();
	KeyWallAnchor = nullptr;
}

void AMRUKRoom::ComputeRoomBounds()
{
	RoomBounds.Init();

	for (auto& Anchor : { FloorAnchor, CeilingAnchor })
	{
		if (Anchor)
		{
			auto Transform = Anchor->GetTransform();
			for (const auto& Vertex : Anchor->PlaneBoundary2D)
			{
				const auto Pos = Transform.TransformPosition(FVector(0.0f, Vertex.X, Vertex.Y));
				RoomBounds += Pos;
			}
		}
	}
}

void AMRUKRoom::ComputeAnchorHierarchy()
{
	// Reset anchor hierarchy
	for (auto& Anchor : AllAnchors)
	{
		Anchor->ParentAnchor = nullptr;
		Anchor->ChildAnchors.Empty();
	}

	constexpr float OffsetTolerance = 4.0f; // 4 cm offset allowed
	// Find things where are attached to walls such as doors, windows frames or wall art
	for (const auto& WallAnchor : WallAnchors)
	{
		if (!WallAnchor)
		{
			continue;
		}
		const auto& WallTransform = WallAnchor->GetTransform();
		const auto WallNormal = WallTransform.GetUnitAxis(EAxis::X);
		for (const auto& ChildAnchor : AllAnchors)
		{
			// Don't parent walls to themselves
			if (ChildAnchor == WallAnchor)
			{
				continue;
			}
			const auto& ChildTransform = ChildAnchor->GetTransform();
			const auto ChildNormal = ChildTransform.GetUnitAxis(EAxis::X);
			// Check that the two transforms face the same direction
			if (!FVector::Coincident(WallNormal, ChildNormal))
			{
				continue;
			}
			// Check that the position is close to the surface (they are a little bit offset
			// to prevent Z fighting so allow for that).
			auto LocalPos = WallTransform.InverseTransformPosition(ChildTransform.GetLocation());
			if (FMath::Abs(LocalPos.X) > OffsetTolerance)
			{
				continue;
			}
			// Check that the anchor is within the wall boundary
			if (!WallAnchor->IsPositionInBoundary(FVector2D(LocalPos.Y, LocalPos.Z)))
			{
				continue;
			}
			// We have a match
			ensureMsgf(!ChildAnchor->ParentAnchor, TEXT("This anchor already has a parent"));
			ChildAnchor->ParentAnchor = WallAnchor;
			WallAnchor->ChildAnchors.Push(ChildAnchor);
		}
	}

	// Find volumes on the floor
	if (FloorAnchor)
	{
		const auto& FloorTransform = FloorAnchor->GetTransform();
		const auto FloorNormal = FloorTransform.GetUnitAxis(EAxis::X);
		ensureMsgf(FVector::Coincident(FloorNormal, FVector::DownVector), TEXT("Floor normal should be pointing downwards"));
		auto FloorHeight = FloorTransform.GetLocation().Z;
		for (const auto& ChildAnchor : AllAnchors)
		{
			// Don't parent the floor to itself
			if (ChildAnchor == FloorAnchor)
			{
				continue;
			}
			const auto& ChildTransform = ChildAnchor->GetTransform();
			const auto ChildXAxis = ChildTransform.GetUnitAxis(EAxis::X);
			const auto& ChildVolumeBounds = ChildAnchor->VolumeBounds;
			// Only interested in scene volumes, the assumption is that all scene volumes have X axis pointing downwards
			if (!ChildVolumeBounds.IsValid || !FVector::Coincident(ChildXAxis, FVector::DownVector))
			{
				continue;
			}
			auto ChildBottom = ChildTransform.GetLocation().Z - ChildVolumeBounds.Max.X;
			// Check that the volume is on the floor
			if (FMath::Abs(FloorHeight - ChildBottom) > OffsetTolerance)
			{
				continue;
			}
			auto LocalPos = FloorTransform.InverseTransformPosition(ChildTransform.GetLocation());
			// Check that child anchor is within the bounds of the floor
			if (!FloorAnchor->IsPositionInBoundary(FVector2D(LocalPos.Y, LocalPos.Z)))
			{
				continue;
			}
			// We have a match
			ensureMsgf(!ChildAnchor->ParentAnchor, TEXT("This anchor already has a parent"));
			ChildAnchor->ParentAnchor = FloorAnchor;
			FloorAnchor->ChildAnchors.Push(ChildAnchor);
		}
	}

	// Find relationship between scene volumes
	for (const auto& ParentAnchor : AllAnchors)
	{
		if (!ParentAnchor)
		{
			continue;
		}
		const auto& ParentTransform = ParentAnchor->GetTransform();
		const auto ParentXAxis = ParentTransform.GetUnitAxis(EAxis::X);
		const auto& ParentVolumeBounds = ParentAnchor->VolumeBounds;
		// Only interested in scene volumes, the assumption is that all scene volumes have X axis pointing downwards
		if (!ParentVolumeBounds.IsValid || !FVector::Coincident(ParentXAxis, FVector::DownVector))
		{
			continue;
		}
		auto ParentTop = ParentTransform.GetLocation().Z - ParentVolumeBounds.Min.X;
		for (const auto& ChildAnchor : AllAnchors)
		{
			// Don't parent anchors to themselves
			if (ChildAnchor == ParentAnchor)
			{
				continue;
			}
			const auto& ChildTransform = ChildAnchor->GetTransform();
			const auto ChildXAxis = ChildTransform.GetUnitAxis(EAxis::X);
			const auto& ChildVolumeBounds = ChildAnchor->VolumeBounds;
			// Only interested in scene volumes, the assumption is that all scene volumes have X axis pointing downwards
			if (!ChildVolumeBounds.IsValid || !FVector::Coincident(ChildXAxis, FVector::DownVector))
			{
				continue;
			}
			auto ChildBottom = ChildTransform.GetLocation().Z - ChildVolumeBounds.Max.X;
			// Check that the two volumes are stack on top of each other
			if (FMath::Abs(ParentTop - ChildBottom) > OffsetTolerance)
			{
				continue;
			}
			// Check that at least one of the corners of the child volume is inside the bounds of the parent's volume
			// when projected onto the horizontal plane. This is to match the Scene Capture tool which requires the
			// user to defined stacked volumes by starting with one corner of the volume which must be on the parent's
			// volume.
			bool AnyCornerInside = false;
			for (int i = 0; i < 4; ++i)
			{
				// Get a different corner on each iteration of the loop (height is not important here)
				FVector ChildLocalPos(0.0f, i < 2 ? ChildVolumeBounds.Min.Y : ChildVolumeBounds.Max.Y, i % 2 == 0 ? ChildVolumeBounds.Min.Z : ChildVolumeBounds.Max.Z);
				auto LocalPos = ParentTransform.InverseTransformPosition(ChildTransform.TransformPosition(ChildLocalPos));
				// Check that child anchor is within the bounds of the parent on the horizontal plane
				if (LocalPos.Y >= ParentVolumeBounds.Min.Y && LocalPos.Y <= ParentVolumeBounds.Max.Y && LocalPos.Z >= ParentVolumeBounds.Min.Z && LocalPos.Z <= ParentVolumeBounds.Max.Z)
				{
					AnyCornerInside = true;
					break;
				}
			}
			if (!AnyCornerInside)
			{
				continue;
			}
			// We have a match
			ensureMsgf(!ChildAnchor->ParentAnchor, TEXT("This anchor already has a parent"));
			ChildAnchor->ParentAnchor = ParentAnchor;
			ParentAnchor->ChildAnchors.Push(ChildAnchor);
		}
	}
}

void AMRUKRoom::ComputeSeats()
{
	for (const auto& SeatAnchor : SeatAnchors)
	{
		if (SeatAnchor)
		{
			auto SeatsComponent = SeatAnchor->FindComponentByClass<UMRUKSeatsComponent>();
			if (!SeatsComponent)
			{
				SeatsComponent = NewObject<UMRUKSeatsComponent>(SeatAnchor, TEXT("Seats"));
				SeatsComponent->RegisterComponent();
			}
			SeatsComponent->CalculateSeatPoses();
		}
	}
}

void AMRUKRoom::ComputeRoomEdges()
{
	if (!FloorAnchor)
	{
		UE_LOG(LogMRUK, Warning, TEXT("Floor anchor not set, can not compute room edges"));
		return;
	}

	const auto& FloorBoundary = FloorAnchor->PlaneBoundary2D;
	const auto& FloorTransform = FloorAnchor->GetActorTransform();

	RoomEdges.SetNum(FloorBoundary.Num(), true);
	for (int i = 0; i < RoomEdges.Num(); ++i)
	{
		const auto& BoundaryPoint = FloorBoundary[i];
		FVector Edge = FVector(0.0, BoundaryPoint.X, BoundaryPoint.Y);
		Edge = FloorTransform.TransformPosition(Edge);
		Edge.Z = 0.0;
		RoomEdges[i] = Edge;
	}
}


bool AMRUKRoom::IsPositionInRoom(const FVector& Position, bool TestVerticalBounds)
{
	if (!FloorAnchor)
	{
		return false;
	}

	if (!(TestVerticalBounds ? RoomBounds.IsInside(Position) : RoomBounds.IsInsideXY(Position)))
	{
		return false;
	}

	const auto Transform = FloorAnchor->GetTransform();
	const FVector LocalPos = Transform.InverseTransformPositionNoScale(Position);
	return FloorAnchor->IsPositionInBoundary(FVector2D(LocalPos.Y, LocalPos.Z));
}

bool AMRUKRoom::GenerateRandomPositionInRoom(FVector& OutPosition, float MinDistanceToSurface, bool AvoidVolumes)
{
	return GenerateRandomPositionInRoomFromStream(OutPosition, FRandomStream(NAME_None), MinDistanceToSurface, AvoidVolumes);
}

bool AMRUKRoom::GenerateRandomPositionInRoomFromStream(FVector& OutPosition, const FRandomStream& RandomStream, float MinDistanceToSurface, bool AvoidVolumes)
{
	if (!FloorAnchor)
	{
		return false;
	}
	if (MinDistanceToSurface > RoomBounds.GetExtent().GetMin())
	{
		// We can exit early here as we know it's not possible to generate a position in the room that satisfies
		// the MinDistanceToSurface requirement
		return false;
	}
	FVector Position;
	constexpr int MaxIterations = 1000;
	// Bail after MaxIteration tries to avoid infinite loop in case MinDistanceToSurface is too large
	// and we can't find a position which does not intersect with the walls and volumes
	for (int i = 0; i < MaxIterations; ++i)
	{
		if (MinDistanceToSurface > 0.0f)
		{
			// If MinDistanceToSurface is large then it can be more efficient to randomly generate points within
			// the shrunken bounds of the room
			Position.X = RandomStream.FRandRange(RoomBounds.Min.X + MinDistanceToSurface, RoomBounds.Max.X - MinDistanceToSurface);
			Position.Y = RandomStream.FRandRange(RoomBounds.Min.Y + MinDistanceToSurface, RoomBounds.Max.Y - MinDistanceToSurface);
			Position.Z = RandomStream.FRandRange(RoomBounds.Min.Z + MinDistanceToSurface, RoomBounds.Max.Z - MinDistanceToSurface);
			if (!IsPositionInRoom(Position))
			{
				// Reject points that are outside the room
				continue;
			}
			FVector SurfacePos;
			double SurfaceDistance;
			FMRUKLabelFilter Filter;
			Filter.IncludedLabels = { FMRUKLabels::WallFace };
			if (TryGetClosestSurfacePosition(Position, SurfacePos, SurfaceDistance, Filter, MinDistanceToSurface))
			{
				// Reject points that are too close to the walls
				continue;
			}
		}
		else
		{
			Position = FloorAnchor->GenerateRandomPositionOnPlaneFromStream(RandomStream);
			Position = FloorAnchor->GetTransform().TransformPosition(Position);
			Position.Z = RandomStream.FRandRange(RoomBounds.Min.Z + MinDistanceToSurface, RoomBounds.Max.Z - MinDistanceToSurface);
		}
		if (AvoidVolumes && IsPositionInSceneVolume(Position, true, MinDistanceToSurface))
		{
			// Reject points inside volumes if avoid volumes has been enabled
			continue;
		}
		OutPosition = Position;
		return true;
	}
	return false;
}

bool AMRUKRoom::GenerateRandomPositionOnSurface(EMRUKSpawnLocation SpawnLocation, float MinDistanceToEdge,
	FMRUKLabelFilter LabelFilter, FVector& OutPosition, FVector& OutNormal)
{
	TArray<Surface> Surfaces;
	float TotalUsableSurfaceArea = 0.0f;
	const float MinWidth = 2.0f * MinDistanceToEdge;

	OutPosition = FVector::ZeroVector;
	OutNormal = FVector::ForwardVector;
	for (auto& Anchor : AllAnchors)
	{
		if (!LabelFilter.PassesFilter(Anchor->SemanticClassifications))
		{
			continue;
		}
		if (Anchor->PlaneBounds.bIsValid)
		{
			bool bSkipPlane = false;

			const bool bIsHorizontal = IsActorOrientationHorizontal(Anchor);

			// We skip the plane if it's vertical and if we are not spawning for vertical surfaces
			if (SpawnLocation == EMRUKSpawnLocation::VerticalSurfaces)
			{
				bSkipPlane = bIsHorizontal;
			}
			// We skip the plane if it's not horizontal and if it's the ceiling
			else if (SpawnLocation == EMRUKSpawnLocation::OnTopOfSurface)
			{
				bSkipPlane = !bIsHorizontal;
				if (Anchor->SemanticClassifications.Contains(FMRUKLabels::Ceiling))
					bSkipPlane = true;
			}
			else if (SpawnLocation == EMRUKSpawnLocation::AnySurface)
			{
				bSkipPlane = false;
			}
			else if (SpawnLocation == EMRUKSpawnLocation::HangingDown)
			{
				bSkipPlane = !Anchor->SemanticClassifications.Contains(FMRUKLabels::Ceiling);
			}

			if (!bSkipPlane)
			{
				const auto Size = Anchor->PlaneBounds.GetSize();
				if (Size.X > MinWidth && Size.Y > MinWidth)
				{
					const float UsableArea = (Size.X - MinWidth) * (Size.Y - MinWidth);
					TotalUsableSurfaceArea += UsableArea;
					Surfaces.Add({ Anchor, UsableArea, true, Anchor->PlaneBounds, EMRUKBoxSide{} });
				}
			}
		}

		if (Anchor->VolumeBounds.IsValid)
		{
			for (int FaceIndex = 0; FaceIndex < 6; ++FaceIndex)
			{
				const EMRUKBoxSide BoxSide = static_cast<EMRUKBoxSide>(FaceIndex);

				// Only top when spawning on top of surfaces. The negative X face corresponds to the top surface.
				if (SpawnLocation == EMRUKSpawnLocation::OnTopOfSurface && BoxSide != EMRUKBoxSide::XNeg)
					continue;

				// Switch top and bottom faces. The vertical surfaces are the Y and Z faces.
				if (SpawnLocation == EMRUKSpawnLocation::VerticalSurfaces && FaceIndex < 2)
					continue;

				// Only bottom when spawning on hanging down. The positive X face corresponds to the top surface.
				if (SpawnLocation == EMRUKSpawnLocation::HangingDown && BoxSide != EMRUKBoxSide::XPos)
					continue;

				FBox2D Bound = GetBoundsFromBoxForSide(BoxSide, Anchor->VolumeBounds);

				if (const auto Size = Bound.GetSize(); Size.X > MinWidth && Size.Y > MinWidth)
				{
					const float UsableArea = (Size.X - MinWidth) * (Size.Y - MinWidth);
					TotalUsableSurfaceArea += UsableArea;
					Surfaces.Add({ Anchor, UsableArea, false, Bound, BoxSide });
				}
			}
		}
	}
	if (Surfaces.Num() == 0)
	{
		return false;
	}

	constexpr int MaxIterations = 1000;
	for (int i = 0; i < MaxIterations; ++i)
	{
		// Pick a random surface weighted by surface area (surfaces with a larger
		// area have more chance of being chosen)
		float Rand = FMath::RandRange(0.f, TotalUsableSurfaceArea);
		int Index = 0;
		for (; Index < Surfaces.Num() - 1; ++Index)
		{
			Rand -= Surfaces[Index].UsableArea;
			if (Rand <= 0.0f)
			{
				break;
			}
		}
		auto& [Anchor, UsableArea, IsPlane, Bounds, BoxSide] = Surfaces[Index];

		FVector2D Pos = FVector2D(
			FMath::RandRange(Bounds.Min.X + MinDistanceToEdge, Bounds.Max.X - MinDistanceToEdge),
			FMath::RandRange(Bounds.Min.Y + MinDistanceToEdge, Bounds.Max.Y - MinDistanceToEdge));

		if (IsPlane && !Anchor->IsPositionInBoundary(Pos))
			continue;

		if (IsPlane)
		{
			const FVector Pos3DPlane = Anchor->ActorToWorld().TransformPosition(FVector(0.f, Pos.X, Pos.Y));
			OutPosition = Pos3DPlane;
			OutNormal = Anchor->ActorToWorld().TransformVector(FVector::BackwardVector);
			return true;
		}

		OutPosition = GetWorldPos(Pos, Anchor, BoxSide);
		OutNormal = Anchor->ActorToWorld().TransformVector(GetNormalBoxSide(BoxSide));
		return true;
	}
	return false;
}

AMRUKAnchor* AMRUKRoom::Raycast(const FVector& Origin, const FVector& Direction, float MaxDist, const FMRUKLabelFilter& LabelFilter, FMRUKHit& OutHit)
{
	AMRUKAnchor* HitComponent = nullptr;
	for (const auto& Anchor : AllAnchors)
	{
		if (!Anchor || !Anchor->PassesLabelFilter(LabelFilter))
		{
			continue;
		}
		FMRUKHit HitResult;
		if (Anchor->Raycast(Origin, Direction, MaxDist, HitResult))
		{
			// Prevent further hits which are further away from being found
			MaxDist = HitResult.HitDistance;
			OutHit = HitResult;
			HitComponent = Anchor;
		}
	}
	return HitComponent;
}

bool AMRUKRoom::RaycastAll(const FVector& Origin, const FVector& Direction, float MaxDist, const FMRUKLabelFilter& LabelFilter, TArray<FMRUKHit>& OutHits, TArray<AMRUKAnchor*>& OutAnchors)
{
	bool HitAnything = false;
	for (const auto& Anchor : AllAnchors)
	{
		if (!Anchor || !Anchor->PassesLabelFilter(LabelFilter))
		{
			continue;
		}
		if (Anchor->RaycastAll(Origin, Direction, MaxDist, OutHits))
		{
			HitAnything = true;
			// For each element in OutHits we want an equivalent entry in OutAnchors with the same index
			// which represents which anchor was hit.
			while (OutHits.Num() > OutAnchors.Num())
			{
				OutAnchors.Push(Anchor);
			}
		}
	}
	return HitAnything;
}

void AMRUKRoom::ClearRoom()
{
	RoomLayout = {};
	AnchorUUID = {};
	SpaceHandle = {};
	RoomBounds.Init();
	for (auto& Anchor : AllAnchors)
	{
		if (Anchor)
		{
			Anchor->Destroy();
		}
	}
	AllAnchors.Empty();
	WallAnchors.Empty();
	SeatAnchors.Empty();
	FloorAnchor = nullptr;
	CeilingAnchor = nullptr;
	KeyWallAnchor = nullptr;
}

bool AMRUKRoom::DoesRoomHave(const TArray<FString>& Labels)
{
	if (Labels.IsEmpty())
	{
		return true;
	}

	TArray<FString> RemainingLabels = Labels;

	for (const auto& Anchor : AllAnchors)
	{
		for (const auto& AnchorLabel : Anchor->SemanticClassifications)
		{
			const auto AnchorLabelIndex = RemainingLabels.Find(AnchorLabel);
			if (AnchorLabelIndex != INDEX_NONE)
			{
				RemainingLabels.RemoveAt(AnchorLabelIndex);
				if (RemainingLabels.IsEmpty())
				{
					return true;
				}
			}
		}
	}

	return false;
}

AMRUKAnchor* AMRUKRoom::TryGetClosestSurfacePosition(const FVector& WorldPosition, FVector& OutSurfacePosition, double& OutSurfaceDistance, const FMRUKLabelFilter& LabelFilter, double MaxDistance)
{
	if (MaxDistance <= 0.0)
	{
		MaxDistance = DBL_MAX;
	}
	OutSurfacePosition = FVector::Zero();
	AMRUKAnchor* ClosestAnchor = nullptr;

	for (const auto& Anchor : AllAnchors)
	{
		if (!Anchor || !Anchor->PassesLabelFilter(LabelFilter))
		{
			continue;
		}

		FVector SurfacePos{};
		const auto Distance = Anchor->GetClosestSurfacePosition(WorldPosition, SurfacePos);
		if (Distance < MaxDistance)
		{
			MaxDistance = Distance;
			OutSurfacePosition = SurfacePos;
			ClosestAnchor = Anchor;
		}
	}

	OutSurfaceDistance = MaxDistance;
	return ClosestAnchor;
}

AMRUKAnchor* AMRUKRoom::IsPositionInSceneVolume(const FVector& WorldPosition, bool TestVerticalBounds, double Tolerance)
{
	for (const auto& Anchor : AllAnchors)
	{
		if (!Anchor)
		{
			continue;
		}

		if (Anchor->IsPositionInVolumeBounds(WorldPosition, TestVerticalBounds, Tolerance))
		{
			return Anchor;
		}
	}

	return nullptr;
}

AMRUKAnchor* AMRUKRoom::TryGetClosestSeatPose(const FVector& RayOrigin, const FVector& RayDirection, FTransform& OutSeatTransform)
{
	FTransform ClosestPose{};
	AMRUKAnchor* ClosestAnchor = nullptr;
	double ClosestDot = DBL_MIN;

	for (const auto& SeatAnchor : SeatAnchors)
	{
		if (!SeatAnchor)
		{
			continue;
		}
		const auto SeatsComponent = SeatAnchor->FindComponentByClass<UMRUKSeatsComponent>();
		if (!SeatsComponent)
		{
			continue;
		}

		for (const auto& SeatPose : SeatsComponent->SeatPoses)
		{
			const auto VecToSeat = (SeatPose.GetLocation() - RayOrigin).GetSafeNormal();
			const auto ThisDot = RayDirection.Dot(VecToSeat);
			if (ThisDot <= ClosestDot)
			{
				continue;
			}
			ClosestDot = ThisDot;
			ClosestPose = SeatPose;
			ClosestAnchor = SeatAnchor;
		}
	}

	OutSeatTransform = ClosestPose;
	return ClosestAnchor;
}

TArray<AMRUKAnchor*> AMRUKRoom::GetAnchorsByLabel(const FString& Label) const
{
	TArray<TObjectPtr<AMRUKAnchor>> Anchors;

	for (const auto& Anchor : AllAnchors)
	{
		if (Anchor && Anchor->HasLabel(Label))
		{
			Anchors.Push(Anchor);
		}
	}
	return Anchors;
}

AMRUKAnchor* AMRUKRoom::GetFirstAnchorByLabel(const FString& Label) const
{
	const auto Anchors = GetAnchorsByLabel(Label);
	if (Anchors.IsEmpty())
	{
		return nullptr;
	}
	return Anchors[0];
}

AMRUKAnchor* AMRUKRoom::GetBestPoseFromRaycast(const FVector& RayOrigin, const FVector& RayDirection, double MaxDist, const FMRUKLabelFilter& LabelFilter, FTransform& OutPose, EMRUKPositioningMethod PositioningMethod)
{
	FTransform BestPose{};

	FMRUKHit Hit{};
	const auto HitAnchor = Raycast(RayOrigin, RayDirection, MaxDist, LabelFilter, Hit);
	if (!HitAnchor)
	{
		return nullptr;
	}

	FVector PosePosition = Hit.HitPosition;
	FVector PoseUp = FVector::UpVector;
	// By default, use the surface normal for pose forward
	// Caution: Make sure all the cases of this being "up" are caught below
	FVector PoseForward = Hit.HitNormal;

	constexpr double ParallelTolerance = 0.999;

	if (!HitAnchor->VolumeBounds.IsValid && Hit.HitNormal.Dot(PoseUp) >= ParallelTolerance)
	{
		// HitNormal and PoseUp are parallel. E.g. Walls and floors.
		PoseForward = FVector{ RayOrigin.X - Hit.HitPosition.X, RayOrigin.Y - Hit.HitPosition.Y, 0.0 }.GetSafeNormal();
	}
	else if (HitAnchor->VolumeBounds.IsValid)
	{
		// This is a volume object, and the ray has hit the top surface
		if (Hit.HitNormal.Dot(FVector::UpVector) >= ParallelTolerance)
		{
			const auto& Transform = HitAnchor->GetActorTransform();

			switch (PositioningMethod)
			{
				case EMRUKPositioningMethod::Center:
				{
					const auto HitLocalPos = Transform.InverseTransformPosition(Hit.HitPosition);

					double ShortestDistance = DBL_MAX;
					FVector Forward = FVector::ZeroVector;

					auto Dist = FMath::Abs(HitLocalPos.Y - HitAnchor->VolumeBounds.Min.Y);
					if (Dist < ShortestDistance)
					{
						ShortestDistance = Dist;
						Forward = -HitAnchor->GetActorRightVector();
					}
					Dist = FMath::Abs(HitLocalPos.Y - HitAnchor->VolumeBounds.Max.Y);
					if (Dist < ShortestDistance)
					{
						ShortestDistance = Dist;
						Forward = HitAnchor->GetActorRightVector();
					}
					Dist = FMath::Abs(HitLocalPos.Z - HitAnchor->VolumeBounds.Min.Z);
					if (Dist < ShortestDistance)
					{
						ShortestDistance = Dist;
						Forward = -HitAnchor->GetActorUpVector();
					}
					Dist = FMath::Abs(HitLocalPos.Z - HitAnchor->VolumeBounds.Max.Z);
					if (Dist < ShortestDistance)
					{
						ShortestDistance = Dist;
						Forward = HitAnchor->GetActorUpVector();
					}

					PoseForward = Forward;
					PosePosition = Transform.TransformPosition(FVector::ZeroVector);
				}
				break;
				case EMRUKPositioningMethod::Edge:
				{
					const auto HitLocalPos = Transform.InverseTransformPosition(Hit.HitPosition);

					double ShortestDistance = DBL_MAX;
					FVector PoseLocal = FVector::ZeroVector;

					auto Dist = FMath::Abs(HitLocalPos.Y - HitAnchor->VolumeBounds.Min.Y);
					if (Dist < ShortestDistance)
					{
						ShortestDistance = Dist;
						PoseForward = -HitAnchor->GetActorRightVector();
						PoseLocal = { 0.0, HitAnchor->VolumeBounds.Min.Y, HitLocalPos.Z };
					}
					Dist = FMath::Abs(HitLocalPos.Y - HitAnchor->VolumeBounds.Max.Y);
					if (Dist < ShortestDistance)
					{
						ShortestDistance = Dist;
						PoseForward = HitAnchor->GetActorRightVector();
						PoseLocal = { 0.0, HitAnchor->VolumeBounds.Max.Y, HitLocalPos.Z };
					}
					Dist = FMath::Abs(HitLocalPos.Z - HitAnchor->VolumeBounds.Min.Z);
					if (Dist < ShortestDistance)
					{
						ShortestDistance = Dist;
						PoseForward = -HitAnchor->GetActorUpVector();
						PoseLocal = { 0.0, HitLocalPos.Y, HitAnchor->VolumeBounds.Min.Z };
					}
					Dist = FMath::Abs(HitLocalPos.Z - HitAnchor->VolumeBounds.Max.Z);
					if (Dist < ShortestDistance)
					{
						ShortestDistance = Dist;
						PoseForward = HitAnchor->GetActorUpVector();
						PoseLocal = { 0.0, HitLocalPos.Y, HitAnchor->VolumeBounds.Max.Z };
					}
					PosePosition = Transform.TransformPosition(PoseLocal);
				}
				break;
				default:
				{
					const auto HitLocalPos = Transform.InverseTransformPosition(Hit.HitPosition);
					PosePosition = Transform.TransformPosition({ 0.0, HitLocalPos.Y, HitLocalPos.Z });
					PoseForward = FVector{ RayOrigin.X - Hit.HitPosition.X, RayOrigin.Y - Hit.HitPosition.Y, 0.0 }.GetSafeNormal();
				}
				break;
			}
		}
	}

	BestPose.SetLocation(PosePosition);
	BestPose.SetRotation(UKismetMathLibrary::MakeRotFromXZ(PoseForward, PoseUp).Quaternion());
	OutPose = BestPose;

	return HitAnchor;
}

AMRUKAnchor* AMRUKRoom::GetKeyWall(double Tolerance)
{
	if (KeyWallAnchor)
	{
		return KeyWallAnchor;
	}

	TArray<TObjectPtr<AMRUKAnchor>> SortedWalls = WallAnchors;
	SortedWalls.Sort([](const AMRUKAnchor& a, const AMRUKAnchor& b) { return a.PlaneBounds.GetExtent().X < b.PlaneBounds.GetExtent().X; });
	// Find the first one with no other walls behind it.
	// SortedWalls is sorted from shortest side to longest
	for (int i = SortedWalls.Num() - 1; i >= 0; --i)
	{
		const auto WallAnchor = SortedWalls[i];

		bool NoPointsBehind = true;

		// Loop through the other corners, making sure none is behind the wall in question
		for (const auto& RoomEdge : RoomEdges)
		{
			auto VecToCorner = RoomEdge - WallAnchor->GetActorLocation();
			// Due to anchor precision, we use a tolerance value.
			// For example, an adjacent wall edge may be just behind the wall, leading to a false result
			VecToCorner -= WallAnchor->GetActorForwardVector() * Tolerance;

			NoPointsBehind &= (-WallAnchor->GetActorForwardVector()).Dot(VecToCorner) >= 0.0;
			if (!NoPointsBehind)
			{
				break;
			}
		}

		if (NoPointsBehind)
		{
			KeyWallAnchor = WallAnchor;
			return WallAnchor;
		}
	}

	return nullptr;
}

AMRUKAnchor* AMRUKRoom::GetLargestSurface(const FString& Label)
{
	AMRUKAnchor* LargestSurfaceAnchor = nullptr;
	double LargestSurfaceArea = 0.0;
	const auto LabelUpper = Label.ToUpper();

	for (const auto& Anchor : AllAnchors)
	{
		if (!Anchor || !Anchor->HasLabel(Label))
		{
			continue;
		}

		double ThisSurfaceArea = 0.0;
		if (Anchor->PlaneBounds.bIsValid)
		{
			ThisSurfaceArea = Anchor->PlaneBounds.GetArea();
		}
		else if (Anchor->VolumeBounds.IsValid)
		{
			const auto VolumeSize = Anchor->VolumeBounds.GetSize();
			ThisSurfaceArea = VolumeSize.Y * VolumeSize.Z;
		}

		if (ThisSurfaceArea > LargestSurfaceArea)
		{
			LargestSurfaceArea = ThisSurfaceArea;
			LargestSurfaceAnchor = Anchor;
		}
	}

	return LargestSurfaceAnchor;
}

void AMRUKRoom::AttachProceduralMeshToWalls(const TArray<FString>& CutHoleLabels, UMaterialInterface* ProceduralMaterial)
{
	AttachProceduralMeshToWalls({}, CutHoleLabels, ProceduralMaterial);
}

void AMRUKRoom::ComputeWallMeshUVAdjustments(const TArray<FMRUKTexCoordModes>& WallTextureCoordinateModes, TArray<FMRUKAnchorWithPlaneUVs>& OutAnchorsWithPlaneUVs)
{
	TArray<TObjectPtr<AMRUKAnchor>> ConnectedWalls = ComputeConnectedWalls();
	double Perimeter = 0.0;
	for (const auto& WallAnchor : ConnectedWalls)
	{
		Perimeter += WallAnchor->PlaneBounds.GetSize().X;
	}
	const float WorldToMeters = GetWorldSettings()->WorldToMeters;
	const double WallHeight = RoomBounds.GetSize().Z;
	const double SeamlessWorldToMeters = GetSeamlessFactor(Perimeter, WorldToMeters);
	double UOffset = 0.0;
	const TArray<FMRUKTexCoordModes>& TexCoordModes = WallTextureCoordinateModes.IsEmpty() ? TArray<FMRUKTexCoordModes>{ FMRUKTexCoordModes{} } : WallTextureCoordinateModes;
	for (const auto& WallAnchor : ConnectedWalls)
	{
		const double WallWidth = WallAnchor->PlaneBounds.GetSize().X;
		TArray<FMRUKPlaneUV> PlaneUVAdjustments;
		for (const auto TexCoordMode : TexCoordModes)
		{
			float DenominatorX;
			float DenominatorY;
			// Determine the scaling in the V direction first, if this is set to maintain aspect
			// ratio we need to come back to it after U scaling has been determined.
			switch (TexCoordMode.V)
			{
				// Default to stretch in case maintain aspect ratio is set for both axes
				default:
				case EMRUKCoordModeV::Stretch:
					DenominatorY = WallHeight;
					break;
				case EMRUKCoordModeV::Metric:
					DenominatorY = WorldToMeters;
					break;
			}
			switch (TexCoordMode.U)
			{
				default:
				case EMRUKCoordModeU::Stretch:
					DenominatorX = Perimeter;
					break;
				case EMRUKCoordModeU::Metric:
					DenominatorX = WorldToMeters;
					break;
				case EMRUKCoordModeU::MetricSeamless:
					DenominatorX = SeamlessWorldToMeters;
					break;
				case EMRUKCoordModeU::MaintainAspectRatio:
					DenominatorX = DenominatorY;
					break;
				case EMRUKCoordModeU::MaintainAspectRatioSeamless:
					DenominatorX = GetSeamlessFactor(Perimeter, DenominatorY);
					break;
			}
			// Do another pass on V in case it has maintain aspect ratio set
			if (TexCoordMode.V == EMRUKCoordModeV::MaintainAspectRatio)
			{
				DenominatorY = DenominatorX;
			}

			const FVector2D Offset(UOffset / DenominatorX, 0);
			const FVector2D Scale(WallWidth / DenominatorX, WallHeight / DenominatorY);
			PlaneUVAdjustments.Push({ Offset, Scale });
		}
		if (!WallAnchor->HasLabel(FMRUKLabels::InvisibleWallFace))
		{
			OutAnchorsWithPlaneUVs.Push({ WallAnchor, PlaneUVAdjustments });
		}
		UOffset += WallWidth;
	}
}

UProceduralMeshComponent* AMRUKRoom::GetOrCreateGlobalMeshProceduralMeshComponent(bool& OutExistedAlready) const
{
	// Try to find the global mesh procedural mesh component if it already exists
	TArray<UProceduralMeshComponent*> ProcMeshComponents;
	GetComponents<UProceduralMeshComponent>(ProcMeshComponents);
	for (const auto& ProcMeshComponent : ProcMeshComponents)
	{
		if (ProcMeshComponent->ComponentHasTag("GlobalMesh"))
		{
			OutExistedAlready = true;
			return ProcMeshComponent;
		}
	}

	// Create the procedural mesh component if it doesn't exist already
	const auto ProceduralMesh = NewObject<UProceduralMeshComponent>(GlobalMeshAnchor, TEXT("GlobalMesh"));
	ProceduralMesh->ComponentTags.Add("GlobalMesh");
	ProceduralMesh->RegisterComponent();
	OutExistedAlready = false;
	return ProceduralMesh;
}

void AMRUKRoom::SetupGlobalMeshProceduralMeshComponent(UProceduralMeshComponent& ProcMeshComponent, bool ExistedAlready, UMaterialInterface* Material) const
{
	ProcMeshComponent.SetMaterial(0, Material);
	if (!ExistedAlready)
	{
		ProcMeshComponent.SetCollisionProfileName(TEXT("BlockAll"));
		GlobalMeshAnchor->AddOwnedComponent(GlobalMeshAnchor->GetRootComponent());
		ProcMeshComponent.AttachToComponent(GlobalMeshAnchor->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
		ProcMeshComponent.SetRelativeScale3D(FVector(GetWorld()->GetWorldSettings()->WorldToMeters));
	}
}

bool AMRUKRoom::LoadGlobalMeshFromDevice(UMaterialInterface* Material)
{
	if (!GlobalMeshAnchor)
	{
		UE_LOG(LogMRUK, Warning, TEXT("This room doesn't have a global mesh anchor"));
		return false;
	}

	bool ProcMeshExisted = false;
	UProceduralMeshComponent* ProcMesh = GetOrCreateGlobalMeshProceduralMeshComponent(ProcMeshExisted);

	if (!UMRUKBPLibrary::LoadGlobalMeshFromDevice(GlobalMeshAnchor->SpaceHandle, ProcMesh, true, GetWorld()))
	{
		UE_LOG(LogMRUK, Warning, TEXT("Could not load Global Mesh from device"));
		ProcMesh->DestroyComponent();
		return false;
	}

	SetupGlobalMeshProceduralMeshComponent(*ProcMesh, ProcMeshExisted, Material);

	return true;
}

bool AMRUKRoom::LoadGlobalMeshFromJsonString(const FString& JsonString, UMaterialInterface* Material)
{
	if (!GlobalMeshAnchor)
	{
		UE_LOG(LogMRUK, Warning, TEXT("A global mesh can only be loaded from a JSON string if it has a global mesh anchor. Please make sure you provide one."));
		return false;
	}

	bool ProcMeshExisted = false;
	UProceduralMeshComponent* ProcMesh = GetOrCreateGlobalMeshProceduralMeshComponent(ProcMeshExisted);

	if (!UMRUKBPLibrary::LoadGlobalMeshFromJsonString(JsonString, AnchorUUID, ProcMesh, true))
	{
		UE_LOG(LogMRUK, Warning, TEXT("Failed parsing global mesh from JSON string"));
		ProcMesh->DestroyComponent();
		return false;
	}

	SetupGlobalMeshProceduralMeshComponent(*ProcMesh, ProcMeshExisted, Material);

	return true;
}

FVector AMRUKRoom::ComputeCentroid(double Z)
{
	if (!FloorAnchor || !CeilingAnchor)
	{
		return FVector::ZeroVector;
	}

	Z = FMath::Clamp(Z, 0.0, 1.0);

	const FVector2D CentroidLS = UMRUKBPLibrary::ComputeCentroid(FloorAnchor->PlaneBoundary2D);
	const FVector CentroidWS = FloorAnchor->GetActorTransform().TransformPosition(FVector(0.0, CentroidLS.X, CentroidLS.Y));

	const FVector Dir = (CeilingAnchor->GetActorLocation() - FloorAnchor->GetActorLocation());
	const double Dist = Dir.Length();

	return CentroidWS + Dir.GetSafeNormal() * FMath::Lerp(0.0, Dist, Z);
}

void AMRUKRoom::AttachProceduralMeshToWalls(const TArray<FMRUKTexCoordModes>& WallTextureCoordinateModes, const TArray<FString>& CutHoleLabels, UMaterialInterface* ProceduralMaterial)
{
	TArray<FMRUKAnchorWithPlaneUVs> AnchorsWithPlaneUVs;
	ComputeWallMeshUVAdjustments(WallTextureCoordinateModes, AnchorsWithPlaneUVs);
	for (const auto& AnchorWithPlaneUVs : AnchorsWithPlaneUVs)
	{
		AnchorWithPlaneUVs.Anchor->AttachProceduralMesh(AnchorWithPlaneUVs.PlaneUVs, CutHoleLabels, true, ProceduralMaterial);
	}
}

TArray<TObjectPtr<AMRUKAnchor>> AMRUKRoom::ComputeConnectedWalls() const
{
	if (WallAnchors.IsEmpty())
	{
		return {};
	}

	TArray<TObjectPtr<AMRUKAnchor>> ConnectedWalls;
	TArray<TObjectPtr<AMRUKAnchor>> RemainingWalls = WallAnchors;

	for (int i = RemainingWalls.Num() - 1; i >= 0; --i)
	{
		if (RemainingWalls[i] == nullptr)
		{
			RemainingWalls.RemoveAt(i);
		}
	}

	ConnectedWalls.Reserve(WallAnchors.Num());
	ConnectedWalls.Push(RemainingWalls.Last());
	RemainingWalls.Pop();

	while (!RemainingWalls.IsEmpty())
	{
		const auto PrevWall = ConnectedWalls.Last();
		FVector LocalMaxEdge(0, PrevWall->PlaneBounds.Max.X, 0);
		auto MaxEdge = PrevWall->GetTransform().TransformPosition(LocalMaxEdge);
		int ClosestIndex = 0;
		float ClosestDist = UE_MAX_FLT;
		for (int i = 0; i < RemainingWalls.Num(); i++)
		{
			const auto& WallAnchor = RemainingWalls[i];
			FVector LocalMinEdge(0, WallAnchor->PlaneBounds.Min.X, 0);
			auto MinEdge = WallAnchor->GetTransform().TransformPosition(LocalMinEdge);
			const double Dist = FVector::Dist2D(MaxEdge, MinEdge);
			if (Dist < ClosestDist)
			{
				ClosestDist = Dist;
				ClosestIndex = i;
			}
		}
		ConnectedWalls.Push(RemainingWalls[ClosestIndex]);
		RemainingWalls.RemoveAt(ClosestIndex);
	}

	return ConnectedWalls;
}

TArray<AActor*> AMRUKRoom::SpawnInterior(const TMap<FString, FMRUKSpawnGroup>& SpawnGroups, const TArray<FString>& CutHoleLabels, UMaterialInterface* ProceduralMaterial, bool ShouldFallbackToProcedural)
{
	return SpawnInteriorFromStream(SpawnGroups, FRandomStream(NAME_None), CutHoleLabels, ProceduralMaterial, ShouldFallbackToProcedural);
}

TArray<AActor*> AMRUKRoom::SpawnInteriorFromStream(const TMap<FString, FMRUKSpawnGroup>& SpawnGroups, const FRandomStream& RandomStream, const TArray<FString>& CutHoleLabels, UMaterialInterface* ProceduralMaterial, bool GlobalShouldFallbackToProcedural)
{
	TArray<AActor*> InteriorActors;

	const auto ShouldFallbackToProcedural = [GlobalShouldFallbackToProcedural](const FMRUKSpawnGroup* Anchor) -> bool {
		check(Anchor);
		switch (Anchor->FallbackToProcedural)
		{
			case EMRUKFallbackToProceduralOverwrite::Default:
				return GlobalShouldFallbackToProcedural;
			case EMRUKFallbackToProceduralOverwrite::Fallback:
				return true;
			case EMRUKFallbackToProceduralOverwrite::NoFallback:
				return false;
		}
		return false;
	};

	const float WorldToMeters = GetWorldSettings()->WorldToMeters;
	const auto WallFace = SpawnGroups.Find(FMRUKLabels::WallFace);
	if (!WallFace || (WallFace->Actors.IsEmpty() && ShouldFallbackToProcedural(WallFace)))
	{
		// If no wall mesh is given we want to spawn the walls procedural to make seamless UVs
		AttachProceduralMeshToWalls(CutHoleLabels, ProceduralMaterial);
	}
	const auto Floor = SpawnGroups.Find(FMRUKLabels::Floor);
	if (FloorAnchor && (!Floor || (Floor->Actors.IsEmpty() && ShouldFallbackToProcedural(Floor))))
	{
		// Use metric scaling to match walls
		const FVector2D Scale = FloorAnchor->PlaneBounds.GetSize() / WorldToMeters;
		FloorAnchor->AttachProceduralMesh({ { FVector2D::ZeroVector, Scale } }, CutHoleLabels, true, ProceduralMaterial);
	}
	const auto Ceiling = SpawnGroups.Find(FMRUKLabels::Ceiling);
	if (CeilingAnchor && (!Ceiling || (Ceiling->Actors.IsEmpty() && ShouldFallbackToProcedural(Ceiling))))
	{
		// Use metric scaling to match walls
		const FVector2D Scale = CeilingAnchor->PlaneBounds.GetSize() / WorldToMeters;
		CeilingAnchor->AttachProceduralMesh({ { FVector2D::ZeroVector, Scale } }, CutHoleLabels, true, ProceduralMaterial);
	}
	const auto Subsystem = GetGameInstance()->GetSubsystem<UMRUKSubsystem>();

	for (const auto& Anchor : AllAnchors)
	{
		if (!Anchor)
		{
			continue;
		}
		if (Anchor->SemanticClassifications.IsEmpty())
		{
			Anchor->AttachProceduralMesh();
			continue;
		}

		bool SpawnProceduralMesh = true;
		for (const auto& SemanticClassification : Anchor->SemanticClassifications)
		{
			if (SemanticClassification == FMRUKLabels::WallFace && Anchor->SemanticClassifications.Contains(FMRUKLabels::InvisibleWallFace))
			{
				// Treat anchors with WALL_FACE and INVISIBLE_WALL_FACE as anchors that only have INVISIBLE_WALL_FACE
				continue;
			}

			const auto SpawnGroup = SpawnGroups.Find(SemanticClassification);

			if (!SpawnGroup)
			{
				continue;
			}
			if (SpawnGroup->Actors.IsEmpty())
			{
				if (!ShouldFallbackToProcedural(SpawnGroup))
				{
					SpawnProceduralMesh = false;
				}
				continue;
			}

			SpawnProceduralMesh = false;

			int Index = 0;
			if (SpawnGroup->Actors.Num() > 1)
			{
				if (SpawnGroup->SelectionMode == EMRUKSpawnerSelectionMode::Random)
				{
					Index = RandomStream.RandRange(0, SpawnGroup->Actors.Num() - 1);
				}
				else if (SpawnGroup->SelectionMode == EMRUKSpawnerSelectionMode::ClosestSize)
				{
					if (Anchor->VolumeBounds.IsValid)
					{
						const double AnchorSize = FMath::Pow(Anchor->VolumeBounds.GetVolume(), 1.0 / 3.0);
						double ClosestSizeDifference = UE_BIG_NUMBER;
						for (int i = 0; i < SpawnGroup->Actors.Num(); ++i)
						{
							const auto& SpawnActor = SpawnGroup->Actors[i];
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
			}

			const auto& SpawnActor = SpawnGroup->Actors[Index];
			if (SpawnActor.Actor)
			{
				auto InteriorActor = Anchor->SpawnInterior(SpawnActor.Actor, SpawnActor.MatchAspectRatio, SpawnActor.CalculateFacingDirection, SpawnActor.ScalingMode);
				InteriorActors.Push(InteriorActor);
			}
			else
			{
				UE_LOG(LogMRUK, Error, TEXT("Actor is nullptr for label %s."), *SemanticClassification);
			}
			break;
		}

		if (SpawnProceduralMesh)
		{
			Anchor->AttachProceduralMesh(CutHoleLabels, true, ProceduralMaterial);
		}
	}

	return InteriorActors;
}

bool AMRUKRoom::IsWallAnchor(AMRUKAnchor* Anchor) const
{
	return WallAnchors.Contains(Anchor);
}

void AMRUKRoom::UpdateWorldLock(APawn* Pawn, const FVector& HeadWorldPosition) const
{
	const auto& PawnTransform = Pawn->GetActorTransform();
	const auto PawnInverseTransform = PawnTransform.Inverse();

	const auto& Anchor = FloorAnchor;

	FTransform AnchorTransform;
	if (Anchor->SpaceHandle && UOculusXRAnchorBPFunctionLibrary::GetAnchorTransformByHandle(Anchor->SpaceHandle, AnchorTransform))
	{
		// Convert the Anchor Transform back into tracking space. Ideally we would have a version of
		// UOculusXRAnchorBPFunctionLibrary::GetAnchorTransformByHandle
		// which does not transform from Tracking To World space so we don't need to undo it here.
		AnchorTransform *= PawnInverseTransform;

		const FTransform& Transform = Anchor->GetActorTransform();
		const FTransform Adjustment = AnchorTransform.Inverse() * Transform;

		// Only use the Yaw component of the rotation, we don't want to introduce any errors with
		// pitch or roll.
		const double Yaw = Adjustment.Rotator().Yaw;

		Pawn->SetActorLocationAndRotation(Adjustment.GetLocation(), FRotator(0.0, Yaw, 0.0));
	}
}

#undef LOCTEXT_NAMESPACE
