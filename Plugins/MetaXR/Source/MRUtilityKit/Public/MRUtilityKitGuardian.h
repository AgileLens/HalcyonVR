// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "MRUtilityKitRoom.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "MRUtilityKitGuardian.generated.h"

UCLASS(ClassGroup = MRUtilityKit, meta = (DisplayName = "MR Utility Kit Guardian Actor"))
class MRUTILITYKIT_API AMRUKGuardian : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * Procedural mesh that is generated from the anchor geometry and has the guardian material applied.
	 */
	UPROPERTY(VisibleInstanceOnly, Transient, BlueprintReadOnly, Category = "MR Utility Kit")
	TObjectPtr<UProceduralMeshComponent> GuardianMeshComponent;

	/**
	 * Attaches the procedural mesh component to this actor.
	 * @param GuardianMesh The mesh to attach.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void CreateGuardian(UProceduralMeshComponent* GuardianMesh);

public:
	AMRUKGuardian(const FObjectInitializer& ObjectInitializer);
};
