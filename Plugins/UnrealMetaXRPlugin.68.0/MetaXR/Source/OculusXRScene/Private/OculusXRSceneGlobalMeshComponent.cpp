// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRSceneGlobalMeshComponent.h"
#include "OculusXRSceneModule.h"
#include "OculusXRRoomLayoutManagerComponent.h"
#include "ProceduralMeshComponent.h"
#include "Engine/World.h"
#include "GameFramework/WorldSettings.h"
#include "Materials/MaterialInterface.h"

const FString UOculusXRSceneGlobalMeshComponent::GlobalMeshSemanticLabel = TEXT("GLOBAL_MESH");

UOculusXRSceneGlobalMeshComponent::UOculusXRSceneGlobalMeshComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UOculusXRSceneGlobalMeshComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UOculusXRSceneGlobalMeshComponent::HasCollision() const
{
	return Collision;
}

bool UOculusXRSceneGlobalMeshComponent::IsVisible() const
{
	return Visible;
}

UClass* UOculusXRSceneGlobalMeshComponent::GetAnchorComponentClass() const
{
	UClass* sceneAnchorComponentInstanceClass = SceneAnchorComponent ? SceneAnchorComponent.LoadSynchronous() : nullptr;
	return sceneAnchorComponentInstanceClass;
}

void UOculusXRSceneGlobalMeshComponent::CreateMeshComponent(const FOculusXRUInt64& Space, AActor* GlobalMeshAnchor, const UOculusXRRoomLayoutManagerComponent* RoomLayoutManagerComponent) const
{
	bool hasCollision = HasCollision();
	UProceduralMeshComponent* proceduralMeshComponent = NewObject<UProceduralMeshComponent>(GlobalMeshAnchor);
	proceduralMeshComponent->RegisterComponent();

	bool bLoaded = RoomLayoutManagerComponent->LoadTriangleMesh(Space.Value, proceduralMeshComponent, hasCollision);
	ensure(bLoaded);
	UMaterialInterface* refMaterial = Material;
	if (refMaterial != nullptr)
	{
		UE_LOG(LogOculusXRScene, Verbose, TEXT("GLOBAL MESH Set Material %s"), *refMaterial->GetName());
		proceduralMeshComponent->SetMaterial(0, refMaterial);
	}
	if (hasCollision)
	{
		FName refCollisionProfile = CollisionProfileName.Name;
		proceduralMeshComponent->SetCollisionProfileName(refCollisionProfile);
		UE_LOG(LogOculusXRScene, Verbose, TEXT("GLOBAL MESH Set Collision Profile %s"), *refCollisionProfile.ToString());
	}
	GlobalMeshAnchor->AddOwnedComponent(proceduralMeshComponent);
	proceduralMeshComponent->AttachToComponent(GlobalMeshAnchor->GetRootComponent(), FAttachmentTransformRules::KeepWorldTransform);
	proceduralMeshComponent->SetRelativeLocation(FVector::ZeroVector, false, nullptr, ETeleportType::ResetPhysics);

	proceduralMeshComponent->SetVisibility(IsVisible());

	const float worldToMeters = GetWorld()->GetWorldSettings()->WorldToMeters;
	proceduralMeshComponent->SetRelativeScale3D(FVector(worldToMeters, worldToMeters, worldToMeters));
}
