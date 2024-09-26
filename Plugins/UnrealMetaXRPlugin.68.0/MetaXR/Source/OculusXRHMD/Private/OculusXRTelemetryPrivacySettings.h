// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/ImportantToggleSettingInterface.h"
#include "OculusXRTelemetryPrivacySettings.generated.h"

UCLASS(MinimalAPI, hidecategories = Object, config = EditorSettings)
class UOculusXRTelemetryPrivacySettings : public UObject, public IImportantToggleSettingInterface
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, config, Category = Options)
	bool bIsEnabled = false;

	UPROPERTY(config)
	bool bHasNotified = false;

public:
	// BEGIN IImportantToggleSettingInterface
	virtual void GetToggleCategoryAndPropertyNames(FName& OutCategory, FName& OutProperty) const override;
	virtual FText GetFalseStateLabel() const override;
	virtual FText GetFalseStateTooltip() const override;
	virtual FText GetFalseStateDescription() const override;
	virtual FText GetTrueStateLabel() const override;
	virtual FText GetTrueStateTooltip() const override;
	virtual FText GetTrueStateDescription() const override;
	virtual FString GetAdditionalInfoUrl() const override;
	virtual FText GetAdditionalInfoUrlLabel() const override;
	// END IImportantToggleSettingInterface

#if WITH_EDITOR
	//~ Begin UObject Interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	//~ End UObject Interface
#endif // WITH_EDITOR
};
