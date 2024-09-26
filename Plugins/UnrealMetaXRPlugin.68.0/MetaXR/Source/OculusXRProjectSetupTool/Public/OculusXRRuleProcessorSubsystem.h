// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "OculusXRSetupRule.h"
#include "Developer/LauncherServices/Public/ILauncher.h"
#include "Subsystems/EngineSubsystem.h"
#include "OculusXRRuleProcessorSubsystem.generated.h"

/**
 * The rule processor handles registration and querying of rules
 */
UCLASS()
class OCULUSXRPROJECTSETUPTOOL_API UOculusXRRuleProcessorSubsystem final : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	struct RuleStatus
	{
		unsigned PendingRequiredRulesCount = 0;
		unsigned PendingRecommendedRulesCount = 0;
	};
	/**
	 * Initialize the subsystem. USubsystem override
	 */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/**
	 * De-initializes the subsystem. USubsystem override
	 */
	virtual void Deinitialize() override;

	/**
	 * Register a rule
	 *
	 * @return true if successfully registered
	 */
	bool RegisterRule(const SetupRulePtr& Rule);

	/**
	 * Unregister a rule
	 *
	 * @return true if successfully unregistered
	 */
	bool UnregisterRule(const SetupRulePtr& Rule);

	/**
	 * Unregister all rules
	 */
	void UnregisterAllRules();

	/**
	 * Fetch all rules
	 */
	const TSet<SetupRulePtr, FSetupRuleKeyFunc>& GetRules() const;

	/**
	 *  Fetch rule with given `Id`
	 */
	SetupRulePtr GetRule(const FName& Id) const;

	/**
	 * Returns if there are dynamic lights in project
	 */
	bool DynamicLightsExistInProject() const;

	void SendSummaryEvent();

	void SendSummaryEvent(ESetupRulePlatform Platform) const;
	/**
	 * Refresh state
	 */
	void Refresh();

	/**
	 * Returns number of not applied critical and recommended rules
	 */
	RuleStatus UnAppliedRulesStatus(ESetupRulePlatform Platform) const;

private:
	void PopulateDynamicLights();
	void RegisterRules(const TArray<SetupRulePtr>& Rules);

	//** A set containing all the registered rules
	TSet<SetupRulePtr, FSetupRuleKeyFunc> Rules = {};

	// Dynamic lights in project
	TMap<FString, TWeakObjectPtr<ULightComponentBase>> DynamicLights;

	// Launcher handles
	FDelegateHandle LauncherCallbackHandle;
	void OnLauncherCreated(ILauncherRef Launcher);
	void OnLauncherWorkerStarted(ILauncherWorkerPtr LauncherWorker, ILauncherProfileRef Profile);

	void OnPIEEnded(bool bIsSimulating);

	TArray<SetupRulePtr> UnAppliedRulesForPlatform(ESetupRulePlatform Platform, const TSet<ESetupRuleSeverity>& Severities) const;
};
