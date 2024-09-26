// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitDebugComponent.h"
#include "MRUtilityKitTelemetry.h"
#include "MRUtilityKitSubsystem.h"
#include "MRUtilityKitAnchor.h"
#include "Kismet/KismetMathLibrary.h"
#include "IXRTrackingSystem.h"
#include "TextRenderComponent.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Engine/Engine.h"

UMRUKDebugComponent::UMRUKDebugComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMRUKDebugComponent::ShowAnchorAtRayHit(const FVector& Origin, const FVector& Direction)
{
	if (!GizmoActorClass)
	{
		UE_LOG(LogMRUK, Warning, TEXT("Can not show anchor because no gizmo actor is set"));
		return;
	}

	HideAnchor();

	const auto Subsystem = GetOwner()->GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
	if (!Subsystem)
	{
		UE_LOG(LogMRUK, Warning, TEXT("Can not show anchor because there is no MRUtilityKit subsystem"));
		return;
	}

	FMRUKHit Hit{};
	FMRUKLabelFilter LabelFilter{};
	auto Anchor = Subsystem->Raycast(Origin, Direction, 0.0, LabelFilter, Hit);
	if (!Anchor)
	{
		return;
	}

	// Spawn Gizmo
	if (!ActiveGizmoActor)
	{
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		ActorSpawnParams.Owner = GetOwner();
		ActiveGizmoActor = GetWorld()->SpawnActor(GizmoActorClass, nullptr, ActorSpawnParams);
	}
	else
	{
		ActiveGizmoActor->SetActorHiddenInGame(false);
	}
	ActiveGizmoActor->SetActorLocation(Hit.HitPosition);
	ActiveGizmoActor->SetActorScale3D(GizmoScale);
	ActiveGizmoActor->SetActorRotation(Anchor->GetActorRotation());

	if (!TextActorClass)
	{
		UE_LOG(LogMRUK, Warning, TEXT("Can not show text at anchor because no text actor is set"));
		return;
	}

	// Spawn Text
	if (!ActiveTextActor)
	{
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		ActorSpawnParams.Owner = GetOwner();
		ActiveTextActor = GetWorld()->SpawnActor(TextActorClass, nullptr, ActorSpawnParams);
	}
	else
	{
		ActiveTextActor->SetActorHiddenInGame(false);
	}

	auto TextRenderComponent = ActiveTextActor->GetComponentByClass<UTextRenderComponent>();
	FString Text;
	for (int i = 0; i < Anchor->SemanticClassifications.Num(); ++i)
	{
		if (i != 0)
		{
			Text += ", ";
		}
		Text += Anchor->SemanticClassifications[i];
	}
	TextRenderComponent->SetText(FText::FromString(Text));

	ActiveTextActor->SetActorLocation(Hit.HitPosition + (Hit.HitNormal * 20.0));
	ActiveTextActor->SetActorScale3D(TextScale);
	OrientTextActorToPlayer();

	SetComponentTickEnabled(true);
}

void UMRUKDebugComponent::HideAnchor()
{
	if (ActiveGizmoActor)
	{
		ActiveGizmoActor->SetActorHiddenInGame(true);
	}
	if (ActiveTextActor)
	{
		ActiveTextActor->SetActorHiddenInGame(true);
	}
	SetComponentTickEnabled(false);
}

void UMRUKDebugComponent::ShowAnchorSpaceAtRayHit(const FVector& Origin, const FVector& Direction)
{
	const auto Subsystem = GetOwner()->GetGameInstance()->GetSubsystem<UMRUKSubsystem>();
	if (!Subsystem)
	{
		UE_LOG(LogMRUK, Warning, TEXT("Can not show anchor because there is no MRUtilityKit subsystem"));
		return;
	}

	FMRUKHit Hit{};
	const auto Anchor = Subsystem->Raycast(Origin, Direction, 0.0, {}, Hit);
	if (!Anchor)
	{
		return;
	}

	if (!ActiveAnchorSpaceActor || (ActiveAnchorSpaceActor && ActiveAnchorSpaceActor->GetParentActor() != Anchor))
	{
		static constexpr double DebugSpaceOffset = 0.5;

		HideAnchorSpace();

		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		ActorSpawnParams.Owner = Anchor;
		ActiveAnchorSpaceActor = GetWorld()->SpawnActor<AActor>(ActorSpawnParams);
		ActiveAnchorSpaceActor->SetRootComponent(NewObject<USceneComponent>(ActiveAnchorSpaceActor, TEXT("SceneComponent")));
		ActiveAnchorSpaceActor->AttachToActor(Anchor, FAttachmentTransformRules::KeepRelativeTransform);
		ActiveAnchorSpaceActor->GetRootComponent()->SetMobility(EComponentMobility::Movable);

		const auto ProceduralMesh = NewObject<UProceduralMeshComponent>(ActiveAnchorSpaceActor, TEXT("DebugVolumePlane"));
		Anchor->GenerateProceduralAnchorMesh(ProceduralMesh, {}, {}, true, false, DebugSpaceOffset);
		ActiveAnchorSpaceActor->AddInstanceComponent(ProceduralMesh);
		ProceduralMesh->SetupAttachment(ActiveAnchorSpaceActor->GetRootComponent());
		ProceduralMesh->RegisterComponent();
	}
}

void UMRUKDebugComponent::HideAnchorSpace()
{
	if (ActiveAnchorSpaceActor)
	{
		ActiveAnchorSpaceActor->Destroy();
		ActiveAnchorSpaceActor = nullptr;
	}
}

void UMRUKDebugComponent::BeginPlay()
{
	Super::BeginPlay();

#if WITH_EDITOR
	if (OculusXRTelemetry::IsActive())
	{
		MRUKTelemetry::FLoadDebugComponentMarker().Start().End(OculusXRTelemetry::EAction::Success);
	}
#endif

	SetComponentTickEnabled(false);
}

void UMRUKDebugComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Warning, TEXT("Ticking enabled"));
	OrientTextActorToPlayer();
}

void UMRUKDebugComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (ActiveGizmoActor)
	{
		ActiveGizmoActor->Destroy();
		ActiveGizmoActor = nullptr;
	}
	if (ActiveTextActor)
	{
		ActiveTextActor->Destroy();
		ActiveTextActor = nullptr;
	}
	if (ActiveAnchorSpaceActor)
	{
		ActiveAnchorSpaceActor->Destroy();
		ActiveAnchorSpaceActor = nullptr;
	}
}

void UMRUKDebugComponent::OrientTextActorToPlayer() const
{
	if (ActiveTextActor)
	{
		FQuat Orientation;
		FVector Position(0.0);
		GEngine->XRSystem->GetCurrentPose(IXRTrackingSystem::HMDDeviceId, Orientation, Position);
		const auto TextForward = (Position - ActiveTextActor->GetActorLocation()).GetSafeNormal();
		const auto TextUp = FVector::UpVector;
		const auto TextRot = UKismetMathLibrary::MakeRotFromXZ(TextForward, TextUp);
		ActiveTextActor->SetActorRotation(TextRot);
	}
}
