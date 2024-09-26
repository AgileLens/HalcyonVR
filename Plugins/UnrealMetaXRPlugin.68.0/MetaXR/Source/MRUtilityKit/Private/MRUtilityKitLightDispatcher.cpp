// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitLightDispatcher.h"
#include "MRUtilityKit.h"
#include "MRUtilityKitTelemetry.h"
#include "Components/PointLightComponent.h"
#include "Engine/PointLight.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Materials/MaterialParameterCollection.h"
#include "Materials/MaterialParameterCollectionInstance.h"
#include "UObject/ConstructorHelpers.h"

AMRUKLightDispatcher::AMRUKLightDispatcher()
{
	PrimaryActorTick.bCanEverTick = true;

	const ConstructorHelpers::FObjectFinder<UMaterialParameterCollection> MpcAsset(TEXT("/OculusXR/Materials/MPC_Highlights"));
	if (MpcAsset.Succeeded())
	{
		Collection = MpcAsset.Object;
	}
	else
	{
		UE_LOG(LogMRUK, Log, TEXT("Light dispatcher couldn't find material parameter collection in /OculusXR/Materials/MPC_Highlights"));
	}
}

void AMRUKLightDispatcher::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	FillParameterCollection();
}

void AMRUKLightDispatcher::FillParameterCollection()
{
	if (!Collection || PointLightComponents.IsEmpty())
	{
		return;
	}

	UMaterialParameterCollectionInstance* Instance = GetWorld()->GetParameterCollectionInstance(Collection);

	for (int i = 0; i < PointLightComponents.Num(); i++)
	{
		const UPointLightComponent* Light = PointLightComponents[i];
		if (!IsValid(Light))
		{
			continue;
		}

		const int Step = i * 3;

		// It's not possible to expand the amount of parameters in collection at runtime,
		// in case we exceed the count of existing parameters break the loop
		if (Collection->VectorParameters.Num() < Step + 3)
		{
			break;
		}

		// Prepare parameters
		FCollectionVectorParameter PositionParam, DataParam, ColorParam;

		PositionParam.ParameterName = FName("PointLightPosition" + FString::FromInt(i));
		DataParam.ParameterName = FName("PointLightData" + FString::FromInt(i));
		ColorParam.ParameterName = FName("PointLightColor" + FString::FromInt(i));

		PositionParam.DefaultValue = FLinearColor(Light->GetComponentLocation());
		DataParam.DefaultValue = FLinearColor(1.f / Light->AttenuationRadius, Light->ComputeLightBrightness(), Light->LightFalloffExponent, Light->bUseInverseSquaredFalloff);
		ColorParam.DefaultValue = Light->GetLightColor();

		// Fill collection's vector parameters
		Collection->VectorParameters[Step] = PositionParam;
		Collection->VectorParameters[Step + 1] = DataParam;
		Collection->VectorParameters[Step + 2] = ColorParam;
	}

	// Send count of lights
	Collection->ScalarParameters[0].DefaultValue = PointLightComponents.Num();
	UKismetMaterialLibrary::SetScalarParameterValue(GetWorld(), Collection, "TotalLights", PointLightComponents.Num());

	// Update instance
	Instance->UpdateRenderState(false);
}

void AMRUKLightDispatcher::AddAdditionalPointLightActor(AActor* Actor)
{
	AdditionalActorsToLookForPointLightComponents.AddUnique(Actor);
	AddPointLightsFromActor(Actor);
}

void AMRUKLightDispatcher::ForceUpdateCollection()
{
	FillPointLights();
	FillParameterCollection();
	PointLightComponents.Empty();
}

void AMRUKLightDispatcher::BeginPlay()
{
	Super::BeginPlay();
#if WITH_EDITOR
	if (OculusXRTelemetry::IsActive())
	{
		MRUKTelemetry::FLoadLightDispatcherMarker().Start().End(OculusXRTelemetry::EAction::Success);
	}
#endif
	FillPointLights();
}

void AMRUKLightDispatcher::FillPointLights()
{
	// Make sure we don't have duplicates in the array
	PointLightComponents.Empty();

	if (ShouldFetchPointLightsAtBeginPlay)
	{
		// Fetch all point light actors from the level

		TArray<AActor*> PointLightActors;
		UGameplayStatics::GetAllActorsOfClass(this, APointLight::StaticClass(), PointLightActors);

		for (AActor* Actor : PointLightActors)
		{
			const APointLight* PointLightActor = Cast<APointLight>(Actor);

			PointLightComponents.Add(PointLightActor->PointLightComponent);
		}
	}
	else
	{
		// Only use the point lights that have been specified in ManualPointLights

		for (AActor* Actor : ManualPointLights)
		{
			if (!IsValid(Actor))
			{
				continue;
			}

			const APointLight* PointLightActor = Cast<APointLight>(Actor);

			PointLightComponents.Add(PointLightActor->PointLightComponent);
		}
	}

	// Check the additional added actors for point lights and add them in case they have
	// PointLightComponents attached
	for (const AActor* Actor : AdditionalActorsToLookForPointLightComponents)
	{
		if (!IsValid(Actor))
		{
			continue;
		}

		AddPointLightsFromActor(Actor);
	}
}

void AMRUKLightDispatcher::AddPointLightsFromActor(const AActor* Actor)
{
	TArray<UPointLightComponent*> LightComponents;
	Actor->GetComponents(LightComponents, false);
	PointLightComponents.Append(LightComponents);
}
