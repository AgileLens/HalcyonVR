// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "OculusXRSetupRule.h"
#include "OculusXRPSTSettings.generated.h"

/**
 * Meta XR Project Setup tool Settings
 */
UCLASS(config = EditorPerProjectUserSettings)
class OCULUSXRPROJECTSETUPTOOL_API UOculusXRPSTSettings : public UObject
{
	GENERATED_BODY()
public:
	/**
	 * @brief Ignored rules by developer
	 */
	UPROPERTY(config)
	TSet<FName> IgnoredRules = {};

	/**
	 * @brief Selected platform for development
	 */
	UPROPERTY(config)
	uint32 CurrentPlatform = static_cast<uint32>(MetaQuest_All);

	/**
	 * @brief If tools should periodically check if list of rules and rules' status
	 */
	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	bool bBackGroundChecks = true;

	/**
	 * @brief If build should fail if critical rule is not applied
	 */
	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	bool bStopBuildOnUnAppliedCriticalItems = false;

	/**
	 * @brief If guided tutorial has been completed/skipped
	 */
	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	bool bGuidedTutorialComplete = false;

	/**
	 * @brief If guided tutorial showed
	 */
	UPROPERTY(config, EditAnywhere, Category = MetaXR)
	bool bShowGuidedTutorial = true;
};
