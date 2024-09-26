// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "Subsystems/GameInstanceSubsystem.h"
#include "Tickable.h"
#include "OculusXRPersistentPassthroughInstance.h"
#include "OculusXRPassthroughLayerShapes.h"
#include "OculusXRPassthroughSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOculusXRPassthrough_AnyLayerResumed, int, LayerID);

UCLASS(DisplayName = "Passthrough Subsystem")
class OCULUSXRPASSTHROUGH_API UOculusXRPassthroughSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	static UOculusXRPassthroughSubsystem* GetPassthroughSubsystem(const UWorld* InWorld);

	UOculusXRPassthroughSubsystem();

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/**
	 * Creates a Reconstructed Passthrough layer that stays alive until "Destroy Persistent Passthrough" is called.
	 * If used in blueprints, layer's parameters are available in the Details window when selecting the node.
	 */
	UFUNCTION(BlueprintCallable, BlueprintInternalUseOnly, Category = "Passthrough|Persistent", meta = (AutoCreateRefTerm = "LayerResumed"))
	UOculusXRPersistentPassthroughInstance* InitializePersistentPassthrough(FOculusXRPersistentPassthroughParameters Parameters, const FOculusXRPassthrough_LayerResumed_Single& LayerResumed);
	UFUNCTION(BlueprintCallable, Category = "Passthrough|Persistent")
	void DestroyPersistentPassthrough();
	UFUNCTION(BlueprintPure, Category = "Passthrough|Persistent")
	UOculusXRPersistentPassthroughInstance* GetPersistentPassthrough() const;

	UPROPERTY(BlueprintAssignable)
	FOculusXRPassthrough_AnyLayerResumed OnAnyLayerResumed;

private:
	UPROPERTY()
	UOculusXRPersistentPassthroughInstance* PPTInstance;

	FDelegateHandle DelegateHandleLayerResumed;
};
