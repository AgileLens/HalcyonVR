// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "IOculusXRProjectSetupModule.h"

DECLARE_LOG_CATEGORY_EXTERN(LogProjectSetupTool, Log, All);

/**
 * The module for the implementation of the Project Setup Tool
 */
class FOculusXRProjectSetupToolModule : public IOculusXRProjectSetupToolModule
{
public:
	/**
	 * IModuleInterface implementation
	 */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** Show the project setup tool window */
	virtual void ShowProjectSetupTool(const FString& Origin) override;

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	static TSharedPtr<FSlateStyleSet> GetSlateStyle();

private:
	/** Register and unregister console commands */
	void RegisterConsoleCommands();
	void UnregisterConsoleCommands();

	/** Register and unregister styles */
	void RegisterStyleWithStyleRegistry() const;
	void UnregisterStyleWithStyleRegistry() const;

	/** Register tool extensions */
	void RegisterProjectSetupToolWithTabManager();
	void RegisterStatusBarWidgetWithToolMenu() const;

	/** Process functions for all the console commands */
	static void ProcessApplyRuleCommand(const TArray<FString>& Arguments);
	static void ProcessIsRuleAppliedCommand(const TArray<FString>& Arguments);
	static void ProcessListAppliedRulesCommand();
	static void ProcessListRulesCommand();
	static void ProcessIgnoreRuleCommand(const TArray<FString>& Arguments);
	static void ProcessUnIgnoreRuleCommand(const TArray<FString>& Arguments);
	static void ProcessUnIgnoreAllRulesCommand();

	void OnWidgetClosed();
	void SpawnTutorialWindowIfNeeded() const;

	/** Spawn function for creating the project setup tool tab */
	TSharedRef<SDockTab> OnSpawnProjectSetupToolTab(const FSpawnTabArgs& SpawnTabArgs);

	/** All registered console commands */
	TArray<IConsoleCommand*> ConsoleCommands{};

	/** If PST is triggered from toolbar*/
	FString TriggerOrigin = "Menu";
#endif
};
