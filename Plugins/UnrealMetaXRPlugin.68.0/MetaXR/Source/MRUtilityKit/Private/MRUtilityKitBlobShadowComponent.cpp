// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitBlobShadowComponent.h"
#include "MRUtilityKitTelemetry.h"
#include "MRUtilityKit.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInstance.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/StaticMesh.h"

UMRUKBlobShadowComponent::UMRUKBlobShadowComponent()
{
	const ConstructorHelpers::FObjectFinder<UStaticMesh> PlaneAsset(TEXT("/Engine/BasicShapes/Plane"));
	if (PlaneAsset.Succeeded())
	{
		SetStaticMesh(PlaneAsset.Object);
	}
	else
	{
		UE_LOG(LogMRUK, Log, TEXT("Blob shadow couldn't find plane mesh in /Engine/BasicShapes/Plane"));
	}

	const ConstructorHelpers::FObjectFinder<UMaterialInstance> BlobShadowMaterialAsset(TEXT("/OculusXR/Materials/MI_BlobShadow"));
	if (BlobShadowMaterialAsset.Succeeded())
	{
		SetMaterial(0, BlobShadowMaterialAsset.Object);
	}
	else
	{
		UE_LOG(LogMRUK, Log, TEXT("Blob shadow couldn't find blob shadow material in /OculusXR/Materials/MI_BlobShadow"));
	}

	// Prevent sorting issue with transparent ground
	SetTranslucentSortPriority(1);

	// We don't want any collision
	SetCollisionProfileName("NoCollision");

	// Need tick to be enabled
	SetComponentTickEnabled(true);
	PrimaryComponentTick.bCanEverTick = true;
	bAutoActivate = true;
}

void UMRUKBlobShadowComponent::BeginPlay()
{
	Super::BeginPlay();

#if WITH_EDITOR
	if (OculusXRTelemetry::IsActive())
	{
		MRUKTelemetry::FLoadBlobShadowMarker().Start().End(OculusXRTelemetry::EAction::Success);
	}
#endif

	// Create dynamic material (for roundness and gradient settings)
	DynMaterial = CreateAndSetMaterialInstanceDynamic(0);

	// Since we're updating the component size and position every frame it's better to not be influenced by parent
	SetUsingAbsoluteLocation(true);
	SetUsingAbsoluteRotation(true);
	SetUsingAbsoluteScale(true);

	// Compute size and position once
	UpdatePlaneSizeAndPosition();
}

void UMRUKBlobShadowComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Update component size and position every frame
	UpdatePlaneSizeAndPosition();
}

void UMRUKBlobShadowComponent::UpdatePlaneSizeAndPosition()
{
	FVector Origin;
	FVector2D Extent;
	double Yaw;
	ComputeOwner2DBounds(Origin, Extent, Yaw);

	Extent += FVector2D::UnitVector * ExtraExtent; // Additional extent
	SetWorldScale3D(FVector(Extent * 0.02f, 1.f)); // Plane mesh is 100x100, multiplying by 0.02f to match the correct size when scaling
	SetWorldRotation(FRotator(0.f, Yaw, 0.f));

	// Sphere trace to the ground
	FHitResult Hit;
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwner());
	const bool bHasHit = UKismetSystemLibrary::SphereTraceSingle(this, Origin, Origin + FVector::DownVector * MaxVerticalDistance, Extent.Length() * 0.5f, TraceTypeQuery1,
		true, ActorsToIgnore, EDrawDebugTrace::None, Hit, true);
	float Opacity = 0.f;
	if (bHasHit)
	{
		SetHiddenInGame(false);										   // Make plane visible
		SetWorldLocation(Hit.ImpactPoint + FVector::UpVector * 0.02f); // Impact + some offset to avoid Z-fighting
		Opacity = FMath::GetMappedRangeValueClamped(
			FVector2D(MaxVerticalDistance - FadeDistance, MaxVerticalDistance),
			FVector2D(1.f, 0.f),
			Hit.Distance); // Set opacity based on distance to ground
	}
	else
		SetHiddenInGame(true); // Hide plane

	// Update material's parameters
	if (DynMaterial)
	{
		DynMaterial->SetScalarParameterValue("CornerWorldSize", FMath::Min(Extent.X, Extent.Y) * Roundness);
		DynMaterial->SetScalarParameterValue("Gradient", Gradient);
		DynMaterial->SetScalarParameterValue("GradientPower", GradientPower);
		DynMaterial->SetScalarParameterValue("Opacity", Opacity);
	}
	else // In case DynMaterial doesn't exist (e.g. in editor), update values directly on the mesh
	{
		SetScalarParameterValueOnMaterials("CornerWorldSize", FMath::Min(Extent.X, Extent.Y) * Roundness);
		SetScalarParameterValueOnMaterials("Gradient", Gradient);
		SetScalarParameterValueOnMaterials("GradientPower", GradientPower);
		SetScalarParameterValueOnMaterials("Opacity", Opacity);
	}
}

void UMRUKBlobShadowComponent::ComputeOwner2DBounds(FVector& Origin, FVector2D& Extent, double& Yaw) const
{
	const AActor* Actor = GetOwner();

	// Calculate local space BoundingBox from all components, but keep yaw to have a correct 2D bounding box at the end
	FBox Box(ForceInit);
	const FRotator YawOnly = FRotator(0.f, Actor->GetActorRotation().Yaw, 0.f);
	const FTransform ActorToWorld = FTransform(YawOnly.Quaternion());
	const FTransform WorldToActor = ActorToWorld.Inverse();

	Actor->ForEachComponent<UPrimitiveComponent>(true, [&](const UPrimitiveComponent* InPrimComp) {
		// Ignore editor & blob shadow components
		if (InPrimComp->IsRegistered() && !InPrimComp->IsEditorOnly() && !InPrimComp->bUseAttachParentBound && !InPrimComp->IsA<UMRUKBlobShadowComponent>())
		{
			const FTransform ComponentToActor = InPrimComp->GetComponentTransform() * WorldToActor;
			Box += InPrimComp->CalcBounds(ComponentToActor).GetBox();
		}
	});

	const FTransform Transform = Actor->GetTransform();
	// Project 3D extent to 2D
	const FVector ProjectedExtent = FVector::VectorPlaneProject(Box.GetExtent(), FVector::UpVector);

	Origin = ActorToWorld.TransformPosition(Box.GetCenter());
	Extent = FVector2D(ProjectedExtent);
	Yaw = Transform.GetRotation().Rotator().Yaw;
}
