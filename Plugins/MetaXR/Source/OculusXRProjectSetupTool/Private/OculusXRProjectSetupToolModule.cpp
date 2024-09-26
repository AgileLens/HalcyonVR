// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRProjectSetupToolModule.h"
#include "CoreMinimal.h"
#include "OculusXRPSTEvents.h"
#include "OculusXRPSTSettings.h"
#include "OculusXRPSTUtils.h"
#include "OculusXRRuleProcessorSubsystem.h"
#include "OculusXRTelemetry.h"
#include "WorkspaceMenuStructure.h"
#include "WorkspaceMenuStructureModule.h"
#include "Brushes/SlateImageBrush.h"
#include "Styling/SlateStyle.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleRegistry.h"
#include "Widget/OculusXRProjectSetupToolWidget.h"
#include "Widget/OculusXRStatusBarWidget.h"
#include "Interfaces/IMainFrameModule.h"
#include "Widget/OculusXRProjectTutorialWidget.h"

DEFINE_LOG_CATEGORY(LogProjectSetupTool);
#define LOCTEXT_NAMESPACE "OculusXRProjectSetupToolModule"

IMPLEMENT_MODULE(FOculusXRProjectSetupToolModule, OculusXRProjectSetupTool)

/** Style set */
TSharedPtr<FSlateStyleSet> IconStyle = nullptr;

const char* MetaLogo = "ProjectSetupTool.MetaLogo";
const FName ProjectSetupToolTabName = FName("OculusXRProjectSetupTool");
/**
 * Perform module initialization
 */
void FOculusXRProjectSetupToolModule::StartupModule()
{
	UE_LOG(LogProjectSetupTool, Display, TEXT("StartupModule: OculusXRProjectSetupTool"));
	RegisterConsoleCommands();

	// Prepare the main project setup tool tab
	if (IsRunningCommandlet())
	{
		return;
	}
	RegisterStyleWithStyleRegistry();
	RegisterProjectSetupToolWithTabManager();
	RegisterStatusBarWidgetWithToolMenu();
}

/**
 * Perform module cleanup
 */
void FOculusXRProjectSetupToolModule::ShutdownModule()
{
	UnregisterConsoleCommands();
	if (IsRunningCommandlet())
	{
		return;
	}

	UnregisterStyleWithStyleRegistry();
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(ProjectSetupToolTabName);
}

/**
 * Show the project setup tool
 */
void FOculusXRProjectSetupToolModule::ShowProjectSetupTool(const FString& Origin)
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
	FGlobalTabmanager::Get()->TryInvokeTab(ProjectSetupToolTabName);
	TriggerOrigin = Origin;
#endif
}

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)

TSharedPtr<FSlateStyleSet> FOculusXRProjectSetupToolModule::GetSlateStyle()
{
	return IconStyle;
}

/**
 * Register console commands
 */
void FOculusXRProjectSetupToolModule::RegisterConsoleCommands()
{
	ConsoleCommands.Add(IConsoleManager::Get().RegisterConsoleCommand(TEXT("vr.oculus.ApplyRule"), TEXT("Applies a rule.\n"), FConsoleCommandWithArgsDelegate::CreateStatic(&FOculusXRProjectSetupToolModule::ProcessApplyRuleCommand), ECVF_Default));

	ConsoleCommands.Add(IConsoleManager::Get().RegisterConsoleCommand(TEXT("vr.oculus.IsRuleApplied"), TEXT("Determines whether a rule is applied.\n"), FConsoleCommandWithArgsDelegate::CreateStatic(&FOculusXRProjectSetupToolModule::ProcessIsRuleAppliedCommand), ECVF_Default));

	ConsoleCommands.Add(IConsoleManager::Get().RegisterConsoleCommand(TEXT("vr.oculus.ListAppliedRules"), TEXT("Lists all applied rules.\n"), FConsoleCommandDelegate::CreateStatic(&FOculusXRProjectSetupToolModule::ProcessListAppliedRulesCommand), ECVF_Default));

	ConsoleCommands.Add(IConsoleManager::Get().RegisterConsoleCommand(TEXT("vr.oculus.ListRules"), TEXT("Lists all registered rules.\n"), FConsoleCommandDelegate::CreateStatic(&FOculusXRProjectSetupToolModule::ProcessListRulesCommand), ECVF_Default));
}

/**
 * Unregister console commands
 */
void FOculusXRProjectSetupToolModule::UnregisterConsoleCommands()
{
	for (const auto ConsoleCommand : ConsoleCommands)
	{
		IConsoleManager::Get().UnregisterConsoleObject(ConsoleCommand);
	}
}

/**
 * Register styles
 */
void FOculusXRProjectSetupToolModule::RegisterStyleWithStyleRegistry() const
{
	const FString PluginContentRoot = IPluginManager::Get().FindPlugin("OculusXR")->GetBaseDir() / TEXT("Resources");

	IconStyle = MakeShared<FSlateStyleSet>("OculusXRProjectSetupToolStyle");
	IconStyle->SetContentRoot(PluginContentRoot);
	IconStyle->Set(MetaLogo,
		new FSlateVectorImageBrush(IconStyle->RootToContentDir("MetaLogo", TEXT(".svg")),
			FVector2D(32.0f, 32.0f)));

	IconStyle->Set("ProjectSetupTool.MetaQuestBackground",
		new FSlateImageBrush(IconStyle->RootToContentDir("MetaQuestBackground", TEXT(".png")),
			FVector2D(480.f, 570.f)));

	IconStyle->Set("ProjectSetupTool.RedDot",
		new FSlateVectorImageBrush(IconStyle->RootToContentDir("RedDot", TEXT(".svg")),
			FVector2D(32.0f, 32.0f)));

	IconStyle->Set("ProjectSetupTool.YellowDot",
		new FSlateVectorImageBrush(IconStyle->RootToContentDir("YellowDot", TEXT(".svg")),
			FVector2D(32.0f, 32.0f)));

	IconStyle->Set("ProjectSetupTool.GreenDot",
		new FSlateVectorImageBrush(IconStyle->RootToContentDir("GreenDot", TEXT(".svg")),
			FVector2D(32.0f, 32.0f)));

	IconStyle->Set("ProjectSetupTool.GreyDot",
		new FSlateVectorImageBrush(IconStyle->RootToContentDir("GreyDot", TEXT(".svg")),
			FVector2D(32.0f, 32.0f)));

	IconStyle->Set("ProjectSetupTool.WhiteDot",
		new FSlateVectorImageBrush(IconStyle->RootToContentDir("WhiteDot", TEXT(".svg")),
			FVector2D(32.0f, 32.0f)));

	OculusXRPSTUtils::SetBrushStyle(IconStyle, ESetupRulePlatform::MetaLink);
	OculusXRPSTUtils::SetBrushStyle(IconStyle, ESetupRulePlatform::MetaQuest_2);
	OculusXRPSTUtils::SetBrushStyle(IconStyle, ESetupRulePlatform::MetaQuest_3);
	OculusXRPSTUtils::SetBrushStyle(IconStyle, ESetupRulePlatform::MetaQuest_Pro);
	OculusXRPSTUtils::SetBrushStyle(IconStyle, MetaQuest_All);

	FSlateStyleRegistry::RegisterSlateStyle(*IconStyle.Get());
}

/**
 * Unregister styles
 */
void FOculusXRProjectSetupToolModule::UnregisterStyleWithStyleRegistry() const
{
	if (IconStyle.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*IconStyle.Get());
		IconStyle.Reset();
	}
}

/**
 * Register tab widget
 */
void FOculusXRProjectSetupToolModule::RegisterProjectSetupToolWithTabManager()
{
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
								ProjectSetupToolTabName,
								FOnSpawnTab::CreateRaw(this,
									&FOculusXRProjectSetupToolModule::OnSpawnProjectSetupToolTab))
		.SetDisplayName(LOCTEXT("ProjectSetupToolTab_Title", "Meta XR Project Setup Tool"))
		.SetTooltipText(LOCTEXT("ProjectSetupToolTab_Tooltip", "Meta XR Project Setup tool"))
		.SetGroup(WorkspaceMenu::GetMenuStructure().GetToolsCategory())
		.SetIcon(FSlateIcon(IconStyle->GetStyleSetName(), MetaLogo));
}

/**
 * Register status bar widget
 */
void FOculusXRProjectSetupToolModule::RegisterStatusBarWidgetWithToolMenu() const
{
	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu(TEXT("LevelEditor.StatusBar.ToolBar"));

	FToolMenuSection& ProjectSetupToolSection = Menu->AddSection(TEXT("ProjectSetupTool"), FText::GetEmpty(), FToolMenuInsert(NAME_None, EToolMenuInsertType::First));

	ProjectSetupToolSection.AddEntry(
		FToolMenuEntry::InitWidget(TEXT("ProjectSetupTool"), SNew(SOculusXRStatusBarWidget), FText::GetEmpty(), true, false));
}

/**
 * Process 'ApplyRule' console command
 */
void FOculusXRProjectSetupToolModule::ProcessApplyRuleCommand(const TArray<FString>& Arguments)
{
	if (Arguments.Num() != 1)
	{
		UE_LOG(LogProjectSetupTool, Warning, TEXT("Expected only 1 argument"));
	}

	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();
	const FString& ConsoleRuleId = Arguments[0];
	const auto& Rule = RuleProcessorSubsystem->GetRule(FName(ConsoleRuleId));

	if (Rule != nullptr)
	{
		bool ShouldRestart;
		Rule->Apply(ShouldRestart);

		UE_LOG(LogProjectSetupTool, Display, TEXT("Applied rule <%s>"), *ConsoleRuleId);
	}
	else
	{
		UE_LOG(LogProjectSetupTool, Warning, TEXT("Cannot apply unknown rule <%s>"), *ConsoleRuleId);
	}
}

/**
 * Process 'IsRuleApplied' console command
 */
void FOculusXRProjectSetupToolModule::ProcessIsRuleAppliedCommand(const TArray<FString>& Arguments)
{
	if (Arguments.Num() != 1)
	{
		UE_LOG(LogProjectSetupTool, Warning, TEXT("Expected only 1 argument"));
	}

	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();
	const FString& ConsoleRuleId = Arguments[0];
	const auto& Rule = RuleProcessorSubsystem->GetRule(FName(ConsoleRuleId));
	if (Rule != nullptr)
	{
		UE_LOG(LogProjectSetupTool, Display, TEXT("Rule <%s> is %s"), *ConsoleRuleId, Rule->IsApplied() ? TEXT("applied") : TEXT("not applied"));
	}
	else
	{
		UE_LOG(LogProjectSetupTool, Warning, TEXT("Cannot query unknown rule <%s>"), *ConsoleRuleId);
	}
}

/**
 * Process 'ListAppliedRules' console command
 */
void FOculusXRProjectSetupToolModule::ProcessListAppliedRulesCommand()
{
	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();

	uint32 Index = 0;

	for (auto& Rule : RuleProcessorSubsystem->GetRules())
	{
		if (Rule->IsApplied())
		{
			UE_LOG(LogProjectSetupTool, Display, TEXT("Applied rule <%s>"), *(Rule->GetId().ToString()));
			++Index;
		}
	}
	UE_LOG(LogProjectSetupTool, Display, TEXT("There are %d applied rules"), Index);
}

/**
 * Process 'ListRules' console command
 */
void FOculusXRProjectSetupToolModule::ProcessListRulesCommand()
{
	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();

	UE_LOG(LogProjectSetupTool, Display, TEXT("There are %d registered rules"), RuleProcessorSubsystem->GetRules().Num());
	UE_LOG(LogProjectSetupTool, Display, TEXT("|%60hs|%60hs|%20hs|%20hs|%10hs|"), "Rule id", "Display Name",
		"Category", "Severity", "Is Ignored");

	for (const auto& RegisteredRule : RuleProcessorSubsystem->GetRules())
	{
		UE_LOG(
			LogProjectSetupTool,
			Display,
			TEXT("|%60ls|%60s|%20hs|%20hs|%10hs|"),
			*RegisteredRule->GetId().ToString(),
			*RegisteredRule->GetDisplayName().ToString(),
			OculusXRPSTUtils::ToString(RegisteredRule->GetCategory()),
			OculusXRPSTUtils::ToString(RegisteredRule->GetSeverity()),
			RegisteredRule->IsIgnored() ? "yes" : "no");
	}
}

void FOculusXRProjectSetupToolModule::ProcessIgnoreRuleCommand(const TArray<FString>& Arguments)
{
	if (Arguments.Num() != 1)
	{
		UE_LOG(LogProjectSetupTool, Warning, TEXT("Expected only 1 argument"));
	}

	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();
	const FString& ConsoleRuleId = Arguments[0];
	const auto& Rule = RuleProcessorSubsystem->GetRule(FName(ConsoleRuleId));
	if (Rule != nullptr)
	{
		Rule->SetIgnoreRule(true);
	}
	else
	{
		UE_LOG(LogProjectSetupTool, Warning, TEXT("Cannot query unknown rule <%s>"), *ConsoleRuleId);
	}
}
void FOculusXRProjectSetupToolModule::ProcessUnIgnoreRuleCommand(const TArray<FString>& Arguments)
{
	if (Arguments.Num() != 1)
	{
		UE_LOG(LogProjectSetupTool, Warning, TEXT("Expected only 1 argument"));
	}

	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();
	const FString& ConsoleRuleId = Arguments[0];
	const auto& Rule = RuleProcessorSubsystem->GetRule(FName(ConsoleRuleId));
	if (Rule != nullptr)
	{
		Rule->SetIgnoreRule(false);
	}
	else
	{
		UE_LOG(LogProjectSetupTool, Warning, TEXT("Cannot query unknown rule <%s>"), *ConsoleRuleId);
	}
}
void FOculusXRProjectSetupToolModule::ProcessUnIgnoreAllRulesCommand()
{
	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();

	for (const auto& Rule : RuleProcessorSubsystem->GetRules())
	{
		Rule->SetIgnoreRule(false);
	}
}

void FOculusXRProjectSetupToolModule::OnWidgetClosed()
{
	const auto& Platform = static_cast<ESetupRulePlatform>(GetMutableDefault<UOculusXRPSTSettings>()->CurrentPlatform);
	const OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FProjectSetupToolClose> CloseEvent;
	const auto& Annotated = CloseEvent
								.AddAnnotation(OculusXRTelemetry::Annotations::BuildTargetGroup, OculusXRPSTUtils::ToString(Platform))
								.AddAnnotation(OculusXRTelemetry::Annotations::Origin, TCHAR_TO_ANSI(*TriggerOrigin));
}

/**
 * Spawn the project setup tool tab
 */
TSharedRef<SDockTab> FOculusXRProjectSetupToolModule::OnSpawnProjectSetupToolTab(const FSpawnTabArgs& SpawnTabArgs)
{
	SpawnTutorialWindowIfNeeded();
	const auto& Platform = static_cast<ESetupRulePlatform>(GetMutableDefault<UOculusXRPSTSettings>()->CurrentPlatform);
	const OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FProjectSetupToolOpen> OpenEvent;
	const auto& Annotated = OpenEvent
								.AddAnnotation(OculusXRTelemetry::Annotations::BuildTargetGroup, OculusXRPSTUtils::ToString(Platform))
								.AddAnnotation(OculusXRTelemetry::Annotations::Origin, TCHAR_TO_ANSI(*TriggerOrigin));
	TriggerOrigin = "Menu";
	TSharedRef<SDockTab> DockTab = SNew(SDockTab)
									   .TabRole(ETabRole::NomadTab)
									   .OnTabClosed(SDockTab::FOnTabClosedCallback::CreateLambda([this](TSharedRef<SDockTab>) {
										   OnWidgetClosed();
									   }))
									   .Label(NSLOCTEXT("MetaXRProjectSetupTool", "MetaXRPSTTitle", "Meta XR Project Setup Tool"))
										   [SNew(SOculusXRProjectSetupToolWidget)];

	DockTab->SetTabIcon(IconStyle->GetBrush(MetaLogo));
	return DockTab;
}

void FOculusXRProjectSetupToolModule::SpawnTutorialWindowIfNeeded() const
{
	const auto Settings = GetMutableDefault<UOculusXRPSTSettings>();
	if (Settings->bShowGuidedTutorial)
	{
		TSharedPtr<SWindow> ParentWindow;

		if (FModuleManager::Get().IsModuleLoaded("MainFrame"))
		{
			const IMainFrameModule& MainFrame = FModuleManager::LoadModuleChecked<IMainFrameModule>("MainFrame");
			ParentWindow = MainFrame.GetParentWindow();
		}
		const TSharedRef<SWindow> Window = SNew(SWindow)
											   .Title(LOCTEXT("Meta XR Project Setup Tool", "Meta XR Project Setup Tool"))
											   .SizingRule(ESizingRule::Autosized)
											   .SupportsMaximize(false)
											   .SupportsMinimize(false)[SNew(SOculusXRTutorialWindow)];

		Window->SetOnWindowClosed(FOnWindowClosed::CreateLambda([](const TSharedRef<SWindow>&) {
			auto Settings = GetMutableDefault<UOculusXRPSTSettings>();
			Settings->bShowGuidedTutorial = false;
			Settings->SaveConfig();
			const OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FProjectSetupToolTutorialClose> ClosedEvent;
			const auto& Annotated = ClosedEvent
										.AddAnnotation(OculusXRTelemetry::Annotations::TutorialCompleted, Settings->bGuidedTutorialComplete ? "true" : "false");
		}));
		FSlateApplication::Get().AddModalWindow(Window, ParentWindow, false);
	}
}

#endif
#undef LOCTEXT_NAMESPACE
