// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "OculusXRSceneAnchorComponent.h"
#include "Engine/CollisionProfile.h"
#include "OculusXRRoomLayoutManagerComponent.h"
#include "OculusXRSceneGlobalMeshComponent.generated.h"

class UMaterialInterface;

/**
 * DEPRECATED: AOculusXRSceneActor and associated classes are deprecated (v65), please use MR Utility Kit instead
 * (https://developer.oculus.com/documentation/unreal/unreal-mr-utility-kit-overview)
 */
UCLASS(meta = (DisplayName = "OculusXR Scene Global Mesh Component", BlueprintSpawnableComponent))
class OCULUSXRSCENE_API UOculusXRSceneGlobalMeshComponent : public UActorComponent
{
	GENERATED_BODY()

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UOculusXRSceneGlobalMeshComponent(const FObjectInitializer& ObjectInitializer);

	void CreateMeshComponent(const FOculusXRUInt64& Space, AActor* GlobalMeshAnchor, const UOculusXRRoomLayoutManagerComponent* RoomLayoutManagerComponent) const;

	static const FString GlobalMeshSemanticLabel;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "OculusXR")
	bool Collision = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "OculusXR")
	FCollisionProfileName CollisionProfileName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "OculusXR")
	bool Visible = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "OculusXR")
	UMaterialInterface* Material = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "OculusXR")
	TSoftClassPtr<UOculusXRSceneAnchorComponent> SceneAnchorComponent = TSoftClassPtr<UOculusXRSceneAnchorComponent>(FSoftClassPath(UOculusXRSceneAnchorComponent::StaticClass()));

public:
	bool HasCollision() const;

	bool IsVisible() const;

	UClass* GetAnchorComponentClass() const;
};
