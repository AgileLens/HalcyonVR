// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitGuardian.h"

AMRUKGuardian::AMRUKGuardian(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Create a scene component as root so we can attach spawned actors to it
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
}

void AMRUKGuardian::CreateGuardian(UProceduralMeshComponent* GuardianMesh)
{
	GuardianMesh->SetupAttachment(RootComponent);
	GuardianMesh->RegisterComponent();
	GuardianMeshComponent = GuardianMesh;
}
