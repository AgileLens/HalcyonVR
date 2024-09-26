// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitAnchor.h"
#include "MRUtilityKit.h"
#include "MRUtilityKitBPLibrary.h"
#include "MRUtilityKitGeometry.h"
#include "MRUtilityKitSubsystem.h"
#include "MRUtilityKitSerializationHelpers.h"
#include "MRUtilityKitSeatsComponent.h"
#include "MRUtilityKitRoom.h"
#include "OculusXRAnchorTypes.h"
#include "Engine/World.h"

#define LOCTEXT_NAMESPACE "MRUKAnchor"

// #pragma optimize("", off)

AMRUKAnchor::AMRUKAnchor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Create a scene component as root so we can attach spawned actors to it
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
}

bool AMRUKAnchor::LoadFromData(UMRUKAnchorData* AnchorData)
{
	check(AnchorData);

	bool Changed = false;

	if (const auto Seat = GetComponentByClass<UMRUKSeatsComponent>(); Seat && !HasLabel(FMRUKLabels::Couch))
	{
		Seat->UnregisterComponent();
		Seat->DestroyComponent();
		Changed = true;
	}

	AnchorUUID = AnchorData->SpaceQuery.UUID;
	SpaceHandle = AnchorData->SpaceQuery.Space;

	SetActorTransform(AnchorData->Transform, false, nullptr, ETeleportType::ResetPhysics);
	const auto NewSemanticClassifications = AnchorData->SemanticClassifications;
	if (NewSemanticClassifications != SemanticClassifications)
	{
		Changed = true;
	}
	SemanticClassifications = NewSemanticClassifications;

	const FString Semantics = FString::Join(SemanticClassifications, TEXT("-"));
	UE_LOG(LogMRUK, Log, TEXT("SpatialAnchor label is %s"), *Semantics);

	if (PlaneBounds != AnchorData->PlaneBounds)
	{
		Changed = true;
	}
	PlaneBounds = AnchorData->PlaneBounds;
	PlaneBoundary2D = AnchorData->PlaneBoundary2D;

	if (VolumeBounds != AnchorData->VolumeBounds)
	{
		Changed = true;
	}
	VolumeBounds = AnchorData->VolumeBounds;

	if (Changed)
	{
		if (ProceduralMeshComponent)
		{
			ProceduralMeshComponent->UnregisterComponent();
			ProceduralMeshComponent->DestroyComponent();
			ProceduralMeshComponent = nullptr;
		}

		if (CachedMesh.IsSet())
		{
			CachedMesh.GetValue().Clear();
		}
	}

	return Changed;
}

bool AMRUKAnchor::IsPositionInBoundary(const FVector2D& Position)
{
	if (PlaneBoundary2D.IsEmpty())
	{
		return false;
	}

	int Intersections = 0;

	for (int i = 1; i <= PlaneBoundary2D.Num(); i++)
	{
		const FVector2D P1 = PlaneBoundary2D[i - 1];
		const FVector2D P2 = PlaneBoundary2D[i % PlaneBoundary2D.Num()];
		if (Position.Y > FMath::Min(P1.Y, P2.Y) && Position.Y <= FMath::Max(P1.Y, P2.Y))
		{
			if (Position.X <= FMath::Max(P1.X, P2.X))
			{
				if (P1.Y != P2.Y)
				{
					const auto Frac = (Position.Y - P1.Y) / (P2.Y - P1.Y);
					const auto XIntersection = P1.X + Frac * (P2.X - P1.X);
					if (P1.X == P2.X || Position.X <= XIntersection)
					{
						Intersections++;
					}
				}
			}
		}
	}

	return Intersections % 2 == 1;
}

FVector AMRUKAnchor::GenerateRandomPositionOnPlane()
{
	return GenerateRandomPositionOnPlaneFromStream(FRandomStream(NAME_None));
}

FVector AMRUKAnchor::GenerateRandomPositionOnPlaneFromStream(const FRandomStream& RandomStream)
{
	if (PlaneBoundary2D.IsEmpty())
	{
		return FVector::ZeroVector;
	}

	// Cache the mesh so that if the function is called multiple times it will re-use the previously triangulated mesh.
	if (!CachedMesh.IsSet())
	{
		TriangulatedMeshCache Mesh;
		const int32 NumVertices = PlaneBoundary2D.Num();
		Mesh.Vertices.Reserve(NumVertices);

		for (int i = 0; i < PlaneBoundary2D.Num(); ++i)
		{
			auto Vertex = PlaneBoundary2D[i];
			Mesh.Vertices.Push(FVector2D(Vertex.X, Vertex.Y));
		}
		Mesh.Triangles = MRUKTriangulatePoints(Mesh.Vertices);

		// Compute the area of each triangle and the total surface area of the mesh
		Mesh.Areas.Reserve(Mesh.Triangles.Num() / 3);
		Mesh.TotalArea = 0.0f;
		for (int i = 0; i < Mesh.Triangles.Num(); i += 3)
		{
			const auto I0 = Mesh.Triangles[i];
			const auto I1 = Mesh.Triangles[i + 1];
			const auto I2 = Mesh.Triangles[i + 2];
			auto V0 = Mesh.Vertices[I0];
			auto V1 = Mesh.Vertices[I1];
			auto V2 = Mesh.Vertices[I2];
			const auto Cross = FVector2D::CrossProduct(V1 - V0, V2 - V0);
			float Area = Cross * 0.5f;
			Mesh.TotalArea += Area;
			Mesh.Areas.Add(Area);
		}
		CachedMesh.Emplace(MoveTemp(Mesh));
	}

	const auto& [Vertices, Triangles, Areas, TotalArea] = CachedMesh.GetValue();

	// Pick a random triangle weighted by surface area (triangles with larger surface
	// area have more chance of being chosen)
	auto Rand = RandomStream.FRandRange(0.0f, TotalArea);
	int TriangleIndex = 0;
	for (; TriangleIndex < Areas.Num() - 1; ++TriangleIndex)
	{
		Rand -= Areas[TriangleIndex];
		if (Rand <= 0.0f)
		{
			break;
		}
	}

	// Get the vertices of the chosen triangle
	const auto I0 = Triangles[TriangleIndex * 3];
	const auto I1 = Triangles[TriangleIndex * 3 + 1];
	const auto I2 = Triangles[TriangleIndex * 3 + 2];
	const auto V0 = FVector(0.0, Vertices[I0].X, Vertices[I0].Y);
	const auto V1 = FVector(0.0, Vertices[I1].X, Vertices[I1].Y);
	const auto V2 = FVector(0.0, Vertices[I2].X, Vertices[I2].Y);

	// Calculate a random point on that triangle
	float U = RandomStream.FRandRange(0.0f, 1.0f);
	float V = RandomStream.FRandRange(0.0f, 1.0f);
	if (U + V > 1.0f)
	{
		if (U > V)
		{
			U = 1.0f - U;
		}
		else
		{
			V = 1.0f - V;
		}
	}
	return V0 + U * (V1 - V0) + V * (V2 - V0);
}

bool AMRUKAnchor::Raycast(const FVector& Origin, const FVector& Direction, float MaxDist, FMRUKHit& OutHit)
{
	// If this anchor is the global mesh test against it
	if (this == Room->GlobalMeshAnchor)
	{
		FHitResult GlobalMeshOutHit{};
		float Dist = MaxDist;
		if (MaxDist <= 0.0)
		{
			Dist = 100 * 1024; // 1024 m should cover every scene
		}
		if (ActorLineTraceSingle(GlobalMeshOutHit, Origin, Origin + Direction * Dist, ECollisionChannel::ECC_WorldDynamic, FCollisionQueryParams::DefaultQueryParam))
		{
			OutHit.HitPosition = GlobalMeshOutHit.Location;
			OutHit.HitNormal = GlobalMeshOutHit.Normal;
			OutHit.HitDistance = GlobalMeshOutHit.Distance;
			return true;
		}
		return false;
	}

	auto Transform = GetTransform();
	// Transform the ray into local space
	auto InverseTransform = Transform.Inverse();
	const auto OriginLocal = InverseTransform.TransformPositionNoScale(Origin);
	const auto DirectionLocal = InverseTransform.TransformVectorNoScale(Direction);
	FRay LocalRay = FRay(OriginLocal, DirectionLocal);
	bool FoundHit = false;

	// If this anchor has a plane, hit test against it
	if (PlaneBounds.bIsValid && RayCastPlane(LocalRay, MaxDist, OutHit))
	{
		// Update max dist for the volume raycast
		MaxDist = OutHit.HitDistance;
		FoundHit = true;
	}
	// If this anchor has a volume, hit test against it
	if (VolumeBounds.IsValid && RayCastVolume(LocalRay, MaxDist, OutHit))
	{
		MaxDist = OutHit.HitDistance;
		FoundHit = true;
	}

	return FoundHit;
}

bool AMRUKAnchor::RaycastAll(const FVector& Origin, const FVector& Direction, float MaxDist, TArray<FMRUKHit>& OutHits)
{
	if (this == Room->GlobalMeshAnchor)
	{
		FHitResult GlobalMeshOutHit{};
		float Dist = MaxDist;
		if (MaxDist <= 0.0)
		{
			Dist = 100 * 1024; // 1024 m should cover every scene
		}
		if (ActorLineTraceSingle(GlobalMeshOutHit, Origin, Origin + Direction * Dist, ECollisionChannel::ECC_WorldDynamic, FCollisionQueryParams::DefaultQueryParam))
		{
			FMRUKHit Hit{};
			Hit.HitPosition = GlobalMeshOutHit.Location;
			Hit.HitNormal = GlobalMeshOutHit.Normal;
			Hit.HitDistance = GlobalMeshOutHit.Distance;
			OutHits.Push(Hit);
			return true;
		}
		return false;
	}

	auto Transform = GetTransform();
	// Transform the ray into local space
	auto InverseTransform = Transform.Inverse();
	const auto OriginLocal = InverseTransform.TransformPositionNoScale(Origin);
	const auto DirectionLocal = InverseTransform.TransformVectorNoScale(Direction);
	FRay LocalRay = FRay(OriginLocal, DirectionLocal);
	bool FoundHit = false;
	// If this anchor has a plane, hit test against it
	FMRUKHit Hit;
	if (PlaneBounds.bIsValid && RayCastPlane(LocalRay, MaxDist, Hit))
	{
		OutHits.Push(Hit);
		FoundHit = true;
	}
	// If this anchor has a volume, hit test against it
	if (VolumeBounds.IsValid && RayCastVolume(LocalRay, MaxDist, Hit))
	{
		OutHits.Push(Hit);
		FoundHit = true;
	}

	return FoundHit;
}

void AMRUKAnchor::AttachProceduralMesh(const TArray<FString>& CutHoleLabels, bool GenerateCollision, UMaterialInterface* ProceduralMaterial)
{
	AttachProceduralMesh({}, CutHoleLabels, GenerateCollision, ProceduralMaterial);
}

void AMRUKAnchor::AttachProceduralMesh(TArray<FMRUKPlaneUV> PlaneUVAdjustments, const TArray<FString>& CutHoleLabels, bool GenerateCollision, UMaterialInterface* ProceduralMaterial)
{
	if (ProceduralMeshComponent)
	{
		// Procedural mesh already attached
		return;
	}

	ProceduralMeshComponent = NewObject<UProceduralMeshComponent>(this, TEXT("ProceduralMesh"));
	ProceduralMeshComponent->SetupAttachment(RootComponent);
	ProceduralMeshComponent->RegisterComponent();

	GenerateProceduralAnchorMesh(ProceduralMeshComponent, PlaneUVAdjustments, CutHoleLabels, false, GenerateCollision);

	for (int32 SectionIndex = 0; SectionIndex < ProceduralMeshComponent->GetNumSections(); ++SectionIndex)
	{
		ProceduralMeshComponent->SetMaterial(SectionIndex, ProceduralMaterial);
	}
}

void AMRUKAnchor::GenerateProceduralAnchorMesh(UProceduralMeshComponent* ProceduralMesh, const TArray<FMRUKPlaneUV>& PlaneUVAdjustments, const TArray<FString>& CutHoleLabels, bool PreferVolume, bool GenerateCollision, double Offset)
{
	int SectionIndex = 0;
	if (VolumeBounds.IsValid)
	{
		TArray<FVector> Vertices;
		TArray<int32> Triangles;
		TArray<FVector> Normals;
		TArray<FVector2D> UVs;
		TArray<FLinearColor> Colors;	   // Currently unused
		TArray<FProcMeshTangent> Tangents; // Currently unused
		constexpr int32 NumVertices = 24;
		constexpr int32 NumTriangles = 12;
		Vertices.Reserve(NumVertices);
		Triangles.Reserve(3 * NumTriangles);
		Normals.Reserve(NumVertices);
		UVs.Reserve(NumVertices);

		FBox VolumeBoundsOffset(VolumeBounds.Min - Offset, VolumeBounds.Max + Offset);
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				FVector Normal = FVector::ZeroVector;
				if (j == 0)
				{
					Normal[i] = -1.0f;
				}
				else
				{
					Normal[i] = 1.0f;
				}
				auto BaseIndex = Vertices.Num();
				FVector Vertex;
				Vertex[i] = VolumeBoundsOffset[j][i];
				for (int k = 0; k < 2; k++)
				{
					for (int l = 0; l < 2; l++)
					{
						Vertex[(i + 1) % 3] = VolumeBoundsOffset[k][(i + 1) % 3];
						Vertex[(i + 2) % 3] = VolumeBoundsOffset[l][(i + 2) % 3];
						Vertices.Push(Vertex);
						Normals.Push(Normal);
						// The 4 side faces of the cube should have their 0, 0 at the top left corner
						// when viewed from the outside.
						// The top face should have UVs that are consistent with planes to avoid Z fighting
						// in case a plane and volume overlap (e.g. in the case of the desk).
						FVector2D UV;
						switch (i)
						{
							case 0:
								UV = FVector2D(1 - k, 1 - l);
								break;
							case 1:
								UV = FVector2D(k, l);
								break;
							case 2:
								UV = FVector2D(1 - l, k);
								break;
							default:
								ensure(0);
						}
						if (j == 0)
						{
							UV.X = 1 - UV.X;
						}
						UVs.Push(UV);
					}
				}
				if (j == 1)
				{
					Triangles.Push(BaseIndex);
					Triangles.Push(BaseIndex + 1);
					Triangles.Push(BaseIndex + 2);
					Triangles.Push(BaseIndex + 2);
					Triangles.Push(BaseIndex + 1);
					Triangles.Push(BaseIndex + 3);
				}
				else
				{
					Triangles.Push(BaseIndex);
					Triangles.Push(BaseIndex + 2);
					Triangles.Push(BaseIndex + 1);
					Triangles.Push(BaseIndex + 1);
					Triangles.Push(BaseIndex + 2);
					Triangles.Push(BaseIndex + 3);
				}
			}
		}

		ProceduralMesh->CreateMeshSection_LinearColor(SectionIndex++, Vertices, Triangles, Normals, UVs, Colors, Tangents, GenerateCollision);
	}
	if (PlaneBounds.bIsValid && !(VolumeBounds.IsValid && PreferVolume))
	{
		TArray<TArray<FVector2D>> Holes;

		if (!CutHoleLabels.IsEmpty())
		{
			for (const auto& ChildAnchor : ChildAnchors)
			{
				if (!ChildAnchor->HasAnyLabel(CutHoleLabels))
				{
					continue;
				}

				if (!ChildAnchor->PlaneBounds.bIsValid)
				{
					UE_LOG(LogMRUK, Warning, TEXT("Can only cut holes with anchors that have a plane"));
					continue;
				}

				const FVector ChildPositionLS = GetActorTransform().InverseTransformPosition(ChildAnchor->GetActorLocation());
				TArray<FVector2D> HoleBoundary;
				HoleBoundary.Reserve(ChildAnchor->PlaneBoundary2D.Num());
				for (int32 I = ChildAnchor->PlaneBoundary2D.Num() - 1; I >= 0; --I)
				{
					HoleBoundary.Push(FVector2D(ChildPositionLS.Y, ChildPositionLS.Z) + ChildAnchor->PlaneBoundary2D[I]);
				}
				Holes.Push(HoleBoundary);
			}
		}

		const FMRUKOutline Outline = MRUKComputeOutline(PlaneBoundary2D, Holes);
		const TArray<int32> Triangles = MRUKTriangulateMesh(Outline);

		TArray<FVector> Vertices;
		TArray<FVector> Normals;
		TArray<FVector2D> UV0s;
		TArray<FVector2D> UV1s;
		TArray<FVector2D> UV2s;
		TArray<FVector2D> UV3s;
		TArray<FLinearColor> Colors; // Currently unused
		TArray<FProcMeshTangent> Tangents;
		const int32 NumVertices = Outline.Vertices.Num();
		Normals.Reserve(NumVertices);
		UV0s.Reserve(NumVertices);
		UV1s.Reserve(NumVertices);
		UV2s.Reserve(NumVertices);
		UV3s.Reserve(NumVertices);
		Tangents.Reserve(NumVertices);

		static const FVector Normal = -FVector::XAxisVector;
		const FVector NormalOffset = Normal * Offset;
		auto BoundsSize = PlaneBounds.GetSize();
		for (const auto& PlaneBoundaryVertex : Outline.Vertices)
		{
			const FVector Vertex = FVector(0, PlaneBoundaryVertex.X, PlaneBoundaryVertex.Y) + NormalOffset;
			Vertices.Push(Vertex);
			Normals.Push(Normal);
			Tangents.Push(FProcMeshTangent(-FVector::YAxisVector, false));
			auto U = (PlaneBoundaryVertex.X - PlaneBounds.Min.X) / BoundsSize.X;
			auto V = 1 - (PlaneBoundaryVertex.Y - PlaneBounds.Min.Y) / BoundsSize.Y;
			if (PlaneUVAdjustments.Num() == 0)
			{
				UV0s.Push(FVector2D(U, V));
			}
			if (PlaneUVAdjustments.Num() >= 1)
			{
				UV0s.Push(FVector2D(U, V) * PlaneUVAdjustments[0].Scale + PlaneUVAdjustments[0].Offset);
			}
			if (PlaneUVAdjustments.Num() >= 2)
			{
				UV1s.Push(FVector2D(U, V) * PlaneUVAdjustments[1].Scale + PlaneUVAdjustments[1].Offset);
			}
			if (PlaneUVAdjustments.Num() >= 3)
			{
				UV2s.Push(FVector2D(U, V) * PlaneUVAdjustments[2].Scale + PlaneUVAdjustments[2].Offset);
			}
			if (PlaneUVAdjustments.Num() >= 4)
			{
				UV3s.Push(FVector2D(U, V) * PlaneUVAdjustments[3].Scale + PlaneUVAdjustments[3].Offset);
			}
		}
		ProceduralMesh->CreateMeshSection_LinearColor(SectionIndex++, Vertices, Triangles, Normals, UV0s, UV1s, UV2s, UV3s, Colors, Tangents, GenerateCollision);
	}
}

bool AMRUKAnchor::HasLabel(const FString& Label) const
{
	return SemanticClassifications.Contains(Label);
}

bool AMRUKAnchor::HasAnyLabel(const TArray<FString>& Labels) const
{
	for (const auto& Label : Labels)
	{
		if (HasLabel(Label))
		{
			return true;
		}
	}
	return false;
}

bool AMRUKAnchor::PassesLabelFilter(const FMRUKLabelFilter& LabelFilter) const
{
	return LabelFilter.PassesFilter(SemanticClassifications);
}

double AMRUKAnchor::GetClosestSurfacePosition(const FVector& TestPosition, FVector& OutSurfacePosition)
{
	const auto& Transform = GetActorTransform();
	const auto TestPositionLocal = Transform.InverseTransformPosition(TestPosition);

	double ClosestDistance = DBL_MAX;
	FVector ClosestPoint = FVector::ZeroVector;

	if (PlaneBounds.bIsValid)
	{
		const auto BestPoint2D = PlaneBounds.GetClosestPointTo(FVector2D(TestPositionLocal.Y, TestPositionLocal.Z));
		const FVector BestPoint(0.0, BestPoint2D.X, BestPoint2D.Y);
		const auto Distance = FVector::Distance(BestPoint, TestPositionLocal);
		if (Distance < ClosestDistance)
		{
			ClosestPoint = BestPoint;
			ClosestDistance = Distance;
		}
	}
	if (VolumeBounds.IsValid)
	{
		const auto BestPoint = VolumeBounds.GetClosestPointTo(TestPositionLocal);
		const auto Distance = FVector::Distance(BestPoint, TestPositionLocal);
		if (Distance < ClosestDistance)
		{
			ClosestPoint = BestPoint;
			ClosestDistance = Distance;
		}
	}

	OutSurfacePosition = Transform.TransformPosition(ClosestPoint);
	return ClosestDistance;
}

bool AMRUKAnchor::IsPositionInVolumeBounds(const FVector& Position, bool TestVerticalBounds, double Tolerance)
{
	if (!VolumeBounds.IsValid)
	{
		return false;
	}

	const auto& LocalPosition = GetActorTransform().InverseTransformPosition(Position);

	return ((TestVerticalBounds ? ((LocalPosition.X >= VolumeBounds.Min.X - Tolerance) && (LocalPosition.X <= VolumeBounds.Max.X + Tolerance)) : true)
		&& (LocalPosition.Y >= VolumeBounds.Min.Y - Tolerance) && (LocalPosition.Y <= VolumeBounds.Max.Y + Tolerance)
		&& (LocalPosition.Z >= VolumeBounds.Min.Z - Tolerance) && (LocalPosition.Z <= VolumeBounds.Max.Z + Tolerance));
}

FVector AMRUKAnchor::GetFacingDirection() const
{
	if (Room == nullptr)
	{
		return {};
	}

	if (!VolumeBounds.IsValid)
	{
		return GetActorForwardVector();
	}

	int32 CardinalAxis = 0;
	return UMRUKBPLibrary::ComputeDirectionAwayFromClosestWall(this, CardinalAxis, {});
}

AActor* AMRUKAnchor::SpawnInterior(const TSubclassOf<class AActor>& ActorClass, bool MatchAspectRatio, bool CalculateFacingDirection, EMRUKSpawnerScalingMode ScalingMode)
{
	Interior = GetWorld()->SpawnActor(ActorClass);
	auto InteriorRoot = Interior->GetRootComponent();
	if (!InteriorRoot)
	{
		UE_LOG(LogMRUK, Error, TEXT("SpawnInterior Spawned actor does not have a root component."));
		return nullptr;
	}
	InteriorRoot->SetMobility(EComponentMobility::Movable);
	Interior->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	Interior->SetActorRelativeScale3D(FVector::OneVector);

	const auto ChildLocalBounds = Interior->CalculateComponentsBoundingBoxInLocalSpace(true);
	FQuat Rotation = FQuat::Identity;
	FVector Offset = FVector::ZeroVector;
	FVector Scale = FVector::OneVector;

	if (VolumeBounds.IsValid)
	{
		int CardinalAxisIndex = 0;
		if (CalculateFacingDirection && !MatchAspectRatio)
		{
			// Pick rotation that is pointing away from the closest wall
			// If we are also matching the aspect ratio then we only have a choice
			// between 2 directions and first need to figure out what those 2 directions
			// are before doing the ray casting.
			UMRUKBPLibrary::ComputeDirectionAwayFromClosestWall(this, CardinalAxisIndex, {});
		}
		Rotation = FQuat::MakeFromEuler(FVector(90, -(CardinalAxisIndex + 1) * 90, 90));

		FBox ChildBounds = ChildLocalBounds.TransformBy(FTransform(Rotation));
		const FVector ChildSize1 = ChildBounds.GetSize();

		Scale = VolumeBounds.GetSize() / ChildSize1;

		if (MatchAspectRatio)
		{
			FVector ChildSize2 = ChildSize1;
			Swap(ChildSize2.Y, ChildSize2.Z);
			FVector Scale2 = VolumeBounds.GetSize() / ChildSize2;

			float Distortion1 = FMath::Max(Scale.Y, Scale.Z) / FMath::Min(Scale.Y, Scale.Z);
			float Distortion2 = FMath::Max(Scale2.Y, Scale2.Z) / FMath::Min(Scale2.Y, Scale2.Z);

			bool FlipToMatchAspectRatio = Distortion1 > Distortion2;
			if (FlipToMatchAspectRatio)
			{
				CardinalAxisIndex = 1;
				Scale = Scale2;
			}
			if (CalculateFacingDirection)
			{
				UMRUKBPLibrary::ComputeDirectionAwayFromClosestWall(this, CardinalAxisIndex, FlipToMatchAspectRatio ? TArray<int>{ 0, 2 } : TArray<int>{ 1, 3 });
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
		}

		// Calculate the offset between the base of the two bounding boxes. Note that the anchor is on the
		// top of the volume and the X axis points downwards. So the base is at Max.X.
		FVector VolumeBase = FVector(VolumeBounds.Max.X, 0.5 * (VolumeBounds.Min.Y + VolumeBounds.Max.Y), 0.5 * (VolumeBounds.Min.Z + VolumeBounds.Max.Z));
		FVector ChildBase = FVector(ChildBounds.Max.X, 0.5 * (ChildBounds.Min.Y + ChildBounds.Max.Y), 0.5 * (ChildBounds.Min.Z + ChildBounds.Max.Z));

		Offset = VolumeBase - ChildBase * Scale;
	}
	else if (PlaneBounds.bIsValid)
	{
		const auto XAxis = GetTransform().GetUnitAxis(EAxis::X);
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
		auto Scale2D = PlaneBounds.GetSize() / ChildBounds2D.GetSize();

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
		}

		const auto Offset2D = PlaneBounds.GetCenter() - ChildBounds2D.GetCenter() * Scale2D;

		Offset = FVector(0.0, Offset2D.X, Offset2D.Y);
		Scale = FVector(0.5 * (Scale2D.X + Scale2D.Y), Scale2D.X, Scale2D.Y);
	}
	Interior->SetActorRelativeRotation(Rotation);
	Interior->SetActorRelativeLocation(Offset);
	UMRUKBPLibrary::SetScaleRecursivelyAdjustingForRotation(InteriorRoot, Scale);

	return Interior;
}

TSharedRef<FJsonObject> AMRUKAnchor::JsonSerialize()
{
	TSharedRef<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetField(TEXT("UUID"), MRUKSerialize(AnchorUUID));
	JsonObject->SetField(TEXT("SemanticClassifications"), MRUKSerialize(SemanticClassifications));
	JsonObject->SetField(TEXT("Transform"), MRUKSerialize(GetTransform()));
	if (PlaneBounds.bIsValid)
	{
		JsonObject->SetField(TEXT("PlaneBounds"), MRUKSerialize(PlaneBounds));
	}
	if (!PlaneBoundary2D.IsEmpty())
	{
		JsonObject->SetField(TEXT("PlaneBoundary2D"), MRUKSerialize(PlaneBoundary2D));
	}
	if (VolumeBounds.IsValid)
	{
		JsonObject->SetField(TEXT("VolumeBounds"), MRUKSerialize(VolumeBounds));
	}

	if (this == Room->GlobalMeshAnchor)
	{
		TArray<UProceduralMeshComponent*> ProcMeshComponents;
		GetComponents<UProceduralMeshComponent>(ProcMeshComponents);
		for (const auto& Component : ProcMeshComponents)
		{
			const auto ProcMeshComponent = Cast<UProceduralMeshComponent>(Component);
			if (ProcMeshComponent && ProcMeshComponent->ComponentHasTag("GlobalMesh"))
			{
				ensure(ProcMeshComponent->GetNumSections() == 1);

				auto GlobalMeshJson = MakeShared<FJsonObject>();
				GlobalMeshJson->SetField(TEXT("UUID"), MRUKSerialize(AnchorUUID));

				const auto ProcMeshSection = ProcMeshComponent->GetProcMeshSection(0);

				TArray<TSharedPtr<FJsonValue>> PositionsJson;
				for (const auto& Vertex : ProcMeshSection->ProcVertexBuffer)
				{
					PositionsJson.Add(MRUKSerialize(Vertex.Position));
				}
				GlobalMeshJson->SetArrayField(TEXT("Positions"), PositionsJson);

				TArray<TSharedPtr<FJsonValue>> IndicesJson;
				for (const auto& Index : ProcMeshSection->ProcIndexBuffer)
				{
					IndicesJson.Add(MakeShared<FJsonValueNumber>(Index));
				}
				GlobalMeshJson->SetArrayField(TEXT("Indices"), IndicesJson);

				JsonObject->SetObjectField(TEXT("GlobalMesh"), GlobalMeshJson);
			}
		}
	}

	return JsonObject;
}

void AMRUKAnchor::EndPlay(EEndPlayReason::Type Reason)
{
	if (Interior)
	{
		Interior->Destroy();
	}
	Super::EndPlay(Reason);
}

bool AMRUKAnchor::RayCastPlane(const FRay& LocalRay, float MaxDist, FMRUKHit& OutHit)
{
	// If the ray is behind or parallel to the anchor's plane then ignore it
	if (LocalRay.Direction.X >= UE_KINDA_SMALL_NUMBER)
	{
		// Distance to the plane from the ray origin along the ray's direction
		const float Dist = -LocalRay.Origin.X / LocalRay.Direction.X;
		// If the distance is negative or less than the maximum distance then ignore it
		if (Dist >= 0.0f && (MaxDist <= 0 || Dist < MaxDist))
		{
			const FVector HitPos = LocalRay.PointAt(Dist);
			// Ensure the hit is within the plane extends and within the boundary
			const FVector2D Pos2D(HitPos.Y, HitPos.Z);
			if (PlaneBounds.IsInside(Pos2D) && IsPositionInBoundary(Pos2D))
			{
				// Transform the result back into world space
				const auto Transform = GetTransform();
				OutHit.HitPosition = Transform.TransformPositionNoScale(HitPos);
				OutHit.HitNormal = Transform.TransformVectorNoScale(-FVector::XAxisVector);
				OutHit.HitDistance = Dist;
				return true;
			}
		}
	}
	return false;
}

bool AMRUKAnchor::RayCastVolume(const FRay& LocalRay, float MaxDist, FMRUKHit& OutHit)
{
	// Use the slab method to determine if the ray intersects with the bounding box
	// https://education.siggraph.org/static/HyperGraph/raytrace/rtinter3.htm
	float DistNear = -UE_BIG_NUMBER, DistFar = UE_BIG_NUMBER;
	int HitAxis = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (FMath::Abs(LocalRay.Direction.Component(i)) >= UE_KINDA_SMALL_NUMBER)
		{
			// Distance to the plane from the ray origin along the ray's direction
			float Dist1 = (VolumeBounds.Min.Component(i) - LocalRay.Origin.Component(i)) / LocalRay.Direction.Component(i);
			float Dist2 = (VolumeBounds.Max.Component(i) - LocalRay.Origin.Component(i)) / LocalRay.Direction.Component(i);

			if (Dist1 > Dist2)
			{
				std::swap(Dist1, Dist2);
			}
			if (Dist1 > DistNear)
			{
				DistNear = Dist1;
				HitAxis = i;
			}
			if (Dist2 < DistFar)
			{
				DistFar = Dist2;
			}
		}
		else
		{
			// In this case there is no intersection because the ray is parallel to the plane
			// Check that it is within bounds
			if (LocalRay.Origin.Component(i) < VolumeBounds.Min.Component(i) || LocalRay.Origin.Component(i) > VolumeBounds.Max.Component(i))
			{
				// No intersection, set DistNear to a large number
				DistNear = UE_BIG_NUMBER;
				break;
			}
		}
	}
	if (DistNear >= 0 && DistNear <= DistFar && (MaxDist <= 0 || DistNear < MaxDist))
	{
		const FVector HitPos = LocalRay.PointAt(DistNear);
		FVector HitNormal = FVector::ZeroVector;
		HitNormal.Component(HitAxis) = LocalRay.Direction.Component(HitAxis) > 0 ? -1 : 1;
		// Transform the result back into world space
		const auto Transform = GetTransform();
		OutHit.HitPosition = Transform.TransformPositionNoScale(HitPos);
		OutHit.HitNormal = Transform.TransformVectorNoScale(HitNormal);
		OutHit.HitDistance = DistNear;
		return true;
	}
	return false;
}

void AMRUKAnchor::TriangulatedMeshCache::Clear()
{
	Vertices.Empty();
	Triangles.Empty();
	Areas.Empty();
	TotalArea = 0.0f;
}

// #pragma optimize("", on)

#undef LOCTEXT_NAMESPACE
