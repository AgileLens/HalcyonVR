// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once
#include "UObject/Class.h"
#include "OculusXRAnchorTypes.h"
#include "OculusXRAnchorComponents.generated.h"

UCLASS(Blueprintable)
class OCULUSXRANCHORS_API UOculusXRBaseAnchorComponent : public UObject
{
	GENERATED_BODY()
public:
	template <typename T>
	static T* FromSpace(uint64 space, UObject* Outer)
	{
		T* Component = NewObject<T>(Outer);
		Component->Space = space;
		return Component;
	}

	UFUNCTION(BlueprintCallable, Category = "OculusXR|SpatialAnchor")
	bool IsComponentEnabled() const;

	UFUNCTION(BlueprintCallable, Category = "OculusXR|SpatialAnchor")
	EOculusXRSpaceComponentType GetType() const;

	uint64 GetSpace() const;

protected:
	uint64 Space;
	EOculusXRSpaceComponentType Type = EOculusXRSpaceComponentType::Undefined;
};

UCLASS(Blueprintable)
class OCULUSXRANCHORS_API UOculusXRLocatableAnchorComponent : public UOculusXRBaseAnchorComponent
{
	GENERATED_BODY()
public:
	UOculusXRLocatableAnchorComponent()
	{
		Type = EOculusXRSpaceComponentType::Locatable;
	}

	UFUNCTION(BlueprintCallable, Category = "OculusXR|SpatialAnchor")
	bool GetTransform(FTransform& outTransform) const;
};

UCLASS(Blueprintable)
class OCULUSXRANCHORS_API UOculusXRPlaneAnchorComponent : public UOculusXRBaseAnchorComponent
{
	GENERATED_BODY()
public:
	UOculusXRPlaneAnchorComponent()
	{
		Type = EOculusXRSpaceComponentType::ScenePlane;
	}

	UFUNCTION(BlueprintCallable, Category = "OculusXR|SpatialAnchor")
	bool GetPositionAndSize(FVector& outPosition, FVector& outSize) const;
};

UCLASS(Blueprintable)
class OCULUSXRANCHORS_API UOculusXRVolumeAnchorComponent : public UOculusXRBaseAnchorComponent
{
	GENERATED_BODY()
public:
	UOculusXRVolumeAnchorComponent()
	{
		Type = EOculusXRSpaceComponentType::SceneVolume;
	}

	UFUNCTION(BlueprintCallable, Category = "OculusXR|SpatialAnchor")
	bool GetPositionAndSize(FVector& outPosition, FVector& outSize) const;
};

UCLASS(Blueprintable)
class OCULUSXRANCHORS_API UOculusXRSemanticClassificationAnchorComponent : public UOculusXRBaseAnchorComponent
{
	GENERATED_BODY()
public:
	UOculusXRSemanticClassificationAnchorComponent()
	{
		Type = EOculusXRSpaceComponentType::SemanticClassification;
	}

	UFUNCTION(BlueprintCallable, Category = "OculusXR|SpatialAnchor")
	bool GetSemanticClassifications(TArray<FString>& outClassifications) const;
};

UCLASS(Blueprintable)
class OCULUSXRANCHORS_API UOculusXRRoomLayoutAnchorComponent : public UOculusXRBaseAnchorComponent
{
	GENERATED_BODY()
public:
	UOculusXRRoomLayoutAnchorComponent()
	{
		Type = EOculusXRSpaceComponentType::RoomLayout;
	}

	UFUNCTION(BlueprintCallable, Category = "OculusXR|SpatialAnchor")
	bool GetRoomLayout(FOculusXRUUID& outFloorUUID, FOculusXRUUID& outCeilingUUID, TArray<FOculusXRUUID>& outWallsUUIDs) const;
};

UCLASS(Blueprintable)
class OCULUSXRANCHORS_API UOculusXRSpaceContainerAnchorComponent : public UOculusXRBaseAnchorComponent
{
	GENERATED_BODY()
public:
	UOculusXRSpaceContainerAnchorComponent()
	{
		Type = EOculusXRSpaceComponentType::SpaceContainer;
	}

	UFUNCTION(BlueprintCallable, Category = "OculusXR|SpatialAnchor")
	bool GetUUIDs(TArray<FOculusXRUUID>& outUUIDs) const;
};

UCLASS(Blueprintable)
class OCULUSXRANCHORS_API UOculusXRSharableAnchorComponent : public UOculusXRBaseAnchorComponent
{
	GENERATED_BODY()
public:
	UOculusXRSharableAnchorComponent()
	{
		Type = EOculusXRSpaceComponentType::Sharable;
	}
};

UCLASS(Blueprintable)
class OCULUSXRANCHORS_API UOculusXRStorableAnchorComponent : public UOculusXRBaseAnchorComponent
{
	GENERATED_BODY()
public:
	UOculusXRStorableAnchorComponent()
	{
		Type = EOculusXRSpaceComponentType::Storable;
	}
};

UCLASS(Blueprintable)
class OCULUSXRANCHORS_API UOculusXRTriangleMeshAnchorComponent : public UOculusXRBaseAnchorComponent
{
	GENERATED_BODY()
public:
	UOculusXRTriangleMeshAnchorComponent()
	{
		Type = EOculusXRSpaceComponentType::TriangleMesh;
	}
};
