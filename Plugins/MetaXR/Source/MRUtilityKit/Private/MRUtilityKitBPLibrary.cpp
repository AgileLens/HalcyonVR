// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitBPLibrary.h"

#include "MRUtilityKit.h"
#include "MRUtilityKitAnchor.h"
#include "MRUtilityKitSubsystem.h"
#include "MRUtilityKitSerializationHelpers.h"
#include "ProceduralMeshComponent.h"
#include "VectorUtil.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Engine/Engine.h"
#include "TextureResource.h"
#include "Engine/TextureRenderTarget2D.h"

#include "Engine/Texture2D.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

namespace
{
	TArray<FVector> RecalculateNormals(const TArray<FVector>& Vertices, const TArray<uint32>& Triangles)
	{
		TArray<FVector> Normals;

		// Initialize the normals array with zero vectors
		Normals.Init(FVector::ZeroVector, Vertices.Num());

		// Iterate through each triangle
		for (int32 TriIndex = 0; TriIndex < Triangles.Num(); TriIndex += 3)
		{
			// Get the vertices of the triangle
			FVector VertexA = Vertices[Triangles[TriIndex]];
			FVector VertexB = Vertices[Triangles[TriIndex + 1]];
			FVector VertexC = Vertices[Triangles[TriIndex + 2]];

			// Calculate the triangle's normal
			const FVector TriangleNormal = FVector::CrossProduct(VertexC - VertexA, VertexB - VertexA).GetSafeNormal();

			// Add the triangle's normal to each of its vertices' normals
			Normals[Triangles[TriIndex]] += TriangleNormal;
			Normals[Triangles[TriIndex + 1]] += TriangleNormal;
			Normals[Triangles[TriIndex + 2]] += TriangleNormal;
		}

		// Normalize the vertex normals
		for (FVector& Normal : Normals)
		{
			if (!Normal.IsNearlyZero())
			{
				Normal.Normalize();
			}
			else
			{
				Normal = FVector::UpVector;
			}
		}

		return Normals;
	}

	TArray<FProcMeshTangent> RecalculateTangents(const TArray<FVector>& Normals)
	{
		TArray<FProcMeshTangent> Tangents;

		// Initialize the tangents array with zero tangents
		Tangents.Init(FProcMeshTangent(0.f, 0.f, 0.f), Normals.Num());

		// Iterate through each normal
		for (int32 NormalIndex = 0; NormalIndex < Normals.Num(); NormalIndex++)
		{
			const FVector& Normal = Normals[NormalIndex];

			// Calculate a tangent based on the normal
			FVector TangentX = FVector(1.0f, 0.0f, 0.0f);

			// Gram-Schmidt orthogonalization
			TangentX -= Normal * FVector::DotProduct(TangentX, Normal);
			if (!TangentX.IsNearlyZero())
			{
				TangentX.Normalize();
			}
			else
			{
				TangentX = FVector::UpVector;
			}

			// Store the tangent in the array
			Tangents[NormalIndex] = FProcMeshTangent(TangentX, false);
		}

		return Tangents;
	}

	void SetScaleRecursivelyAdjustingForRotationInternal(USceneComponent* SceneComponent, const FVector& UnRotatedScale, const FQuat& AccumulatedRotation, const FVector& ParentReciprocalScale)
	{
		if (SceneComponent)
		{
			const auto RelativeRotation = SceneComponent->GetRelativeRotationCache().RotatorToQuat(SceneComponent->GetRelativeRotation());
			const auto Rotation = AccumulatedRotation * RelativeRotation;
			const FVector RotatedXAxis = Rotation.GetAxisX();
			const FVector RotatedYAxis = Rotation.GetAxisY();
			const FVector RotatedZAxis = Rotation.GetAxisZ();
			FVector RotatedScale;
			if (FMath::Abs(RotatedXAxis.X) >= UE_INV_SQRT_2)
			{
				RotatedScale.X = UnRotatedScale.X;
			}
			else if (FMath::Abs(RotatedXAxis.Y) >= UE_INV_SQRT_2)
			{
				RotatedScale.X = UnRotatedScale.Y;
			}
			else
			{
				RotatedScale.X = UnRotatedScale.Z;
			}

			if (FMath::Abs(RotatedYAxis.X) >= UE_INV_SQRT_2)
			{
				RotatedScale.Y = UnRotatedScale.X;
			}
			else if (FMath::Abs(RotatedYAxis.Y) >= UE_INV_SQRT_2)
			{
				RotatedScale.Y = UnRotatedScale.Y;
			}
			else
			{
				RotatedScale.Y = UnRotatedScale.Z;
			}

			if (FMath::Abs(RotatedZAxis.X) >= UE_INV_SQRT_2)
			{
				RotatedScale.Z = UnRotatedScale.X;
			}
			else if (FMath::Abs(RotatedZAxis.Y) >= UE_INV_SQRT_2)
			{
				RotatedScale.Z = UnRotatedScale.Y;
			}
			else
			{
				RotatedScale.Z = UnRotatedScale.Z;
			}

			const FVector OldScale = SceneComponent->GetRelativeScale3D();
			const FVector NewScale = ParentReciprocalScale * RotatedScale * OldScale;
			SceneComponent->SetRelativeScale3D(NewScale);
			const FVector NewParentReciprocalScale = ParentReciprocalScale * (OldScale / NewScale);
			for (auto Child : SceneComponent->GetAttachChildren())
			{
				if (Child)
				{
					SetScaleRecursivelyAdjustingForRotationInternal(Child, UnRotatedScale, Rotation, NewParentReciprocalScale);
				}
			}
		}
	}
} // namespace

UMRUKLoadFromDevice* UMRUKLoadFromDevice::LoadSceneFromDeviceAsync(const UObject* WorldContext
)
{
	// We must have a valid contextual world for this action, so we don't even make it
	// unless we can resolve the UWorld from WorldContext.
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContext, EGetWorldErrorMode::ReturnNull);
	if (!ensureAlwaysMsgf(IsValid(WorldContext), TEXT("World Context was not valid.")))
	{
		return nullptr;
	}

	// Create a new UMyDelayAsyncAction, and store function arguments in it.
	UMRUKLoadFromDevice* NewAction = NewObject<UMRUKLoadFromDevice>();
	NewAction->World = World;
	NewAction->RegisterWithGameInstance(World->GetGameInstance());
	return NewAction;
}

void UMRUKLoadFromDevice::Activate()
{
	const auto Subsystem = World->GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
	Subsystem->OnSceneLoaded.AddDynamic(this, &UMRUKLoadFromDevice::OnSceneLoaded);

	{
		Subsystem->LoadSceneFromDevice();
	}
}

void UMRUKLoadFromDevice::OnSceneLoaded(bool Succeeded)
{
	const auto Subsystem = World->GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
	Subsystem->OnSceneLoaded.RemoveDynamic(this, &UMRUKLoadFromDevice::OnSceneLoaded);
	if (Succeeded)
	{
		Success.Broadcast();
	}
	else
	{
		Failure.Broadcast();
	}
	SetReadyToDestroy();
}

bool UMRUKBPLibrary::LoadGlobalMeshFromDevice(FOculusXRUInt64 SpaceHandle, UProceduralMeshComponent* OutProceduralMesh, bool LoadCollision, const UObject* WorldContext)
{
	ensure(OutProceduralMesh);

	const UWorld* World = GEngine->GetWorldFromContextObject(WorldContext, EGetWorldErrorMode::ReturnNull);
	if (!ensureAlwaysMsgf(IsValid(WorldContext), TEXT("World Context was not valid.")))
	{
		return false;
	}

	const auto RoomLayoutManager = World->GetGameInstance()->GetSubsystem<UMRUKSubsystem>()->GetRoomLayoutManager();
	const bool LoadResult = RoomLayoutManager->LoadTriangleMesh(SpaceHandle.Value, OutProceduralMesh, LoadCollision);
	if (!LoadResult)
	{
		UE_LOG(LogMRUK, Warning, TEXT("Could not load triangle mesh from layout manager"));
		return false;
	}

	return true;
}

bool UMRUKBPLibrary::LoadGlobalMeshFromJsonString(const FString& JsonString, FOculusXRUUID AnchorUUID, UProceduralMeshComponent* OutProceduralMesh, bool LoadCollision)
{
	ensure(OutProceduralMesh);

	TSharedPtr<FJsonValue> JsonValue;
	auto JsonReader = TJsonReaderFactory<>::Create(JsonString);
	if (!FJsonSerializer::Deserialize(JsonReader, JsonValue))
	{
		UE_LOG(LogMRUK, Warning, TEXT("Could not deserialize global mesh JSON data"));
		return false;
	}

	auto JsonObject = JsonValue->AsObject();

	// Find room
	auto RoomsJson = JsonObject->GetArrayField(TEXT("Rooms"));
	for (const auto& RoomJson : RoomsJson)
	{
		auto RoomObject = RoomJson->AsObject();
		FOculusXRUUID RoomUUID;
		MRUKDeserialize(*RoomObject->GetField<EJson::None>(TEXT("UUID")), RoomUUID);
		if (RoomUUID == AnchorUUID)
		{
			// Find global mesh anchor
			auto AnchorsJson = RoomObject->GetArrayField(TEXT("Anchors"));
			for (const auto& AnchorJson : AnchorsJson)
			{
				auto AnchorObject = AnchorJson->AsObject();
				if (AnchorObject->HasField(TEXT("GlobalMesh")))
				{
					auto GlobalMeshObject = AnchorObject->GetField<EJson::Object>(TEXT("GlobalMesh"))->AsObject();

					auto PositionsJson = GlobalMeshObject->GetArrayField(TEXT("Positions"));
					TArray<FVector> Positions;
					Positions.Reserve(PositionsJson.Num());
					for (const auto& PositionJson : PositionsJson)
					{
						FVector Position;
						MRUKDeserialize(*PositionJson, Position);
						Positions.Push(Position);
					}

					auto IndicesJson = GlobalMeshObject->GetArrayField(TEXT("Indices"));
					TArray<int32> Indices;
					Indices.Reserve(IndicesJson.Num());
					for (const auto& IndexJson : IndicesJson)
					{
						double Index;
						MRUKDeserialize(*IndexJson, Index);
						Indices.Push((int32)Index);
					}

					TArray<FVector> EmptyNormals;
					TArray<FVector2D> EmptyUV;
					TArray<FColor> EmptyVertexColors;
					TArray<FProcMeshTangent> EmptyTangents;
					OutProceduralMesh->CreateMeshSection(0, Positions, Indices, EmptyNormals, EmptyUV, EmptyVertexColors, EmptyTangents, LoadCollision);

					return true;
				}
			}

			break;
		}
	}

	UE_LOG(LogMRUK, Warning, TEXT("Could not find global mesh in room"));

	return false;
}

void UMRUKBPLibrary::RecalculateProceduralMeshAndTangents(UProceduralMeshComponent* Mesh)
{
	if (!IsValid(Mesh))
		return;

	for (int s = 0; s < Mesh->GetNumSections(); ++s)
	{
		FProcMeshSection* Section = Mesh->GetProcMeshSection(s);

		// Get vertices of the section
		TArray<FVector> Vertices;
		for (FProcMeshVertex Vertex : Section->ProcVertexBuffer)
		{
			Vertices.Add(Vertex.Position);
		}

		// Calculate normals and tangents
		TArray<FVector> Normals = RecalculateNormals(Vertices, Section->ProcIndexBuffer);
		TArray<FProcMeshTangent> Tangents = RecalculateTangents(Normals);
		TArray<FVector2D> EmptyUV;
		TArray<FColor> EmptyVertexColors;

		// Update mesh section
		Mesh->UpdateMeshSection(s, Vertices, Normals, EmptyUV, EmptyVertexColors, Tangents);
	}
}

bool UMRUKBPLibrary::IsUnrealEngineMetaFork()
{
#if defined(WITH_OCULUS_BRANCH)
	return true;
#else
	return false;
#endif
}

FVector2D UMRUKBPLibrary::ComputeCentroid(const TArray<FVector2D>& PolygonPoints)
{
	FVector2D Centroid = FVector2D::ZeroVector;

	double SignedArea = 0.0;
	for (int32 I = 0; I < PolygonPoints.Num(); ++I)
	{
		const double X0 = PolygonPoints[I].X;
		const double Y0 = PolygonPoints[I].Y;
		const double X1 = PolygonPoints[(I + 1) % PolygonPoints.Num()].X;
		const double Y1 = PolygonPoints[(I + 1) % PolygonPoints.Num()].Y;

		const double A = X0 * Y1 - X1 * Y0;
		SignedArea += A;

		Centroid.X += (X0 + X1) * A;
		Centroid.Y += (Y0 + Y1) * A;
	}

	return Centroid / (6.0 * (SignedArea * 0.5));
}

void UMRUKBPLibrary::SetScaleRecursivelyAdjustingForRotation(USceneComponent* SceneComponent, const FVector& UnRotatedScale)
{
	SetScaleRecursivelyAdjustingForRotationInternal(SceneComponent, UnRotatedScale, FQuat::Identity, FVector::OneVector);
}

FVector UMRUKBPLibrary::ComputeDirectionAwayFromClosestWall(const AMRUKAnchor* Anchor, int& OutCardinalAxisIndex, const TArray<int> ExcludedAxes)
{
	double ClosestWallDistance = DBL_MAX;
	FVector AwayFromWall{};

	for (int i = 0; i < 4; ++i)
	{
		if (ExcludedAxes.Contains(i))
		{
			continue;
		}
		// Shoot a ray along the cardinal directions
		// The "Up" (i.e. Z axis) for anchors typically points away from the facing direction, but it depends
		// entirely on how the user defined the volume in scene capture.
		const auto CardinalAxis = (FQuat::MakeFromEuler({ 0.0, 0.0, 90.0 * i }).RotateVector(Anchor->GetActorUpVector()));

		for (const auto& WallAnchor : Anchor->Room->WallAnchors)
		{
			if (!WallAnchor)
			{
				continue;
			}
			FMRUKHit Hit{};
			if (!WallAnchor->Raycast(Anchor->GetActorLocation(), CardinalAxis, 0.0, Hit))
			{
				continue;
			}
			const auto DistToWall = FVector::Distance(Hit.HitPosition, Anchor->GetActorLocation());
			if (DistToWall < ClosestWallDistance)
			{
				ClosestWallDistance = DistToWall;
				AwayFromWall = -CardinalAxis;
				OutCardinalAxisIndex = i;
			}
		}
	}

	return AwayFromWall;
}

UTexture2D* UMRUKBPLibrary::ConstructTexture2D(UTextureRenderTarget2D* RenderTarget2D, UObject* Outer, const FString& TexName)
{
	const auto SizeX = RenderTarget2D->SizeX;
	const auto SizeY = RenderTarget2D->SizeY;
	const auto Tex = UTexture2D::CreateTransient(SizeX, SizeY, RenderTarget2D->GetFormat());
	Tex->AddToRoot();
	Tex->Filter = TF_Bilinear;
	Tex->CompressionSettings = TC_Default;
	Tex->SRGB = 0;
	Tex->UpdateResource();

	FTextureRenderTargetResource* RenderTargetResource = RenderTarget2D->GameThread_GetRenderTargetResource();
	FReadSurfaceDataFlags ReadSurfaceDataFlags;
	ReadSurfaceDataFlags.SetLinearToGamma(false);

	TArray<FColor> OutBMP;
	RenderTargetResource->ReadPixels(OutBMP, ReadSurfaceDataFlags);

	FTexture2DMipMap& Mip = Tex->GetPlatformData()->Mips[0];
	void* Data = Mip.BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memcpy(Data, OutBMP.GetData(), SizeX * SizeY * 4);
	Mip.BulkData.Unlock();

	Tex->UpdateResource();
	return Tex;
}

FLinearColor UMRUKBPLibrary::GetMatrixColumn(const FMatrix& Matrix, int32 Index)
{
	ensure(0 <= Index && Index < 4);
	FLinearColor V;
	V.R = Matrix.M[0][Index];
	V.G = Matrix.M[1][Index];
	V.B = Matrix.M[2][Index];
	V.A = Matrix.M[3][Index];
	return V;
}
