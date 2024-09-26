// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MRUtilityKitLightDispatcher.generated.h"

/**
 * Collects lights and sends them to a highlight material.
 * This can be used to achieve highlights over Passthrough.
 */
UCLASS(ClassGroup = MRUtilityKit, meta = (DisplayName = "MR Utility Kit Light Dispatcher"))
class MRUTILITYKIT_API AMRUKLightDispatcher : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * The material parameter collection in which to fill lights data.
	 * This parameter collection gets then send to the shader.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	class UMaterialParameterCollection* Collection;

	/**
	 * Whether all point lights should be fetched automatically at BeginPlay().
	 * The automatic fetching only works for PointLightActors. Actors that have PointLightComponents
	 * attached to them will not be detected. These should be specified in AdditionalActorsToLookForPointLightComponents.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	bool ShouldFetchPointLightsAtBeginPlay = true;

	/**
	 * List of actor(s) that contain a PointLightComponent that should contribute to the highlight effect.
	 * Use AddAdditionalPointLightActor to add actors during runtime.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MR Utility Kit")
	TArray<AActor*> AdditionalActorsToLookForPointLightComponents;

	/**
	 * PointLightActors to use for the highlight effect (not available if "Fetch Point Lights At Begin Play" is true).
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "!ShouldFetchPointLightsAtBeginPlay"), Category = "MR Utility Kit")
	TArray<class APointLight*> ManualPointLights;

	/**
	 * Add a actor to the AdditionalActorsToLookForPointLightComponents list.
	 * This should be used during runtime instead of adding actors directly to AdditionalActorsToLookForPointLightComponents.
	 * @param Actor Actor to add to AdditionalActorsToLookForPointLightComponents.
	 */
	UFUNCTION(BlueprintCallable, Category = "MR Utility Kit")
	void AddAdditionalPointLightActor(AActor* Actor);

	/**
	 * Only callable in the editor from the scene, will update the linked parameter collection with the info
	 * of the point lights in the scene (based on the parameters), updating the highlight effect in the process.
	 * This is meant to preview the effect in the editor.
	 */
	UFUNCTION(CallInEditor, Category = "MR Utility Kit")
	void ForceUpdateCollection();

public:
	AMRUKLightDispatcher();

	void Tick(float DeltaSeconds) override;

	void FillParameterCollection();

protected:
	UPROPERTY(Transient)
	TArray<class UPointLightComponent*> PointLightComponents;

	void BeginPlay() override;

	void FillPointLights();
	void AddPointLightsFromActor(const AActor* Actor);
};
