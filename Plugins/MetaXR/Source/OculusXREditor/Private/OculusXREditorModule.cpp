// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXREditorModule.h"

#include "AssetToolsModule.h"
#include "OculusXRToolStyle.h"
#include "OculusXRToolCommands.h"
#include "OculusXRPlatformToolWidget.h"
#include "OculusXRAssetDirectory.h"
#include "OculusXRHMDRuntimeSettings.h"
#include "IOculusXRProjectSetupModule.h"
#include "OculusXRHMDTypes.h"
#include "LevelEditor.h"
#include "Modules/ModuleManager.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Input/SButton.h"
#include "PropertyEditorModule.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "DetailWidgetRow.h"
#include "IDetailPropertyRow.h"
#include "GeneralProjectSettings.h"
#include "IAssetTools.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "ISettingsModule.h"
#include "OculusXRPassthroughColorLutAsset.h"
#include "OculusXRHMDModule.h"
#include "OculusXRPrivacyNotification.h"
#include "OculusXRSettingsToggle.h"
#include "OculusXRTelemetryPrivacySettings.h"
#include "OculusXRTelemetry.h"
#include "OculusXRTelemetryEditorEvents.h"
#include "OculusXRBuildAnalytics.h"
#include "OculusXRPTLayerComponentDetailsCustomization.h"
#include "OculusXRPassthroughLayerComponent.h"
#include "SExternalImageReference.h"
#include "AndroidRuntimeSettings.h"
#include "SourceControlHelpers.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Interfaces/IProjectManager.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Editor/EditorPerformanceSettings.h"

#define LOCTEXT_NAMESPACE "OculusXREditor"

const FName FOculusXREditorModule::OculusPlatToolTabName = FName("OculusXRPlaformTool");

void FOculusXREditorModule::PostLoadCallback()
{
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
}

void FOculusXREditorModule::StartupModule()
{
	bModuleValid = true;
	RegisterSettings();

	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.RegisterCustomClassLayout(UOculusXRPassthroughLayerComponent::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&FOculusXRPTLayerComponentDetailsCustomization::MakeInstance));

	FOculusAssetDirectory::LoadForCook();

	if (!IsRunningCommandlet())
	{
		FOculusToolStyle::Initialize();
		FOculusToolStyle::ReloadTextures();

		FOculusToolCommands::Register();

		PluginCommands = MakeShareable(new FUICommandList);

		PluginCommands->MapAction(
			FOculusToolCommands::Get().OpenProjectSetupTool,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::PluginOpenSetupToolWindow),
			FCanExecuteAction());
		PluginCommands->MapAction(
			FOculusToolCommands::Get().OpenPlatWindow,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::PluginOpenPlatWindow),
			FCanExecuteAction());
		PluginCommands->MapAction(
			FOculusToolCommands::Get().ToggleDeploySo,
			FExecuteAction::CreateLambda([=]() {
				UOculusXRHMDRuntimeSettings* settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();
				settings->bDeploySoToDevice = !settings->bDeploySoToDevice;
				settings->Modify(true);
				settings->UpdateSinglePropertyInConfigFile(settings->GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UOculusXRHMDRuntimeSettings, bDeploySoToDevice)), settings->GetDefaultConfigFilename());
			}),
			FCanExecuteAction(),
			FIsActionChecked::CreateLambda([=]() {
				return GetMutableDefault<UOculusXRHMDRuntimeSettings>()->bDeploySoToDevice;
			}));
		PluginCommands->MapAction(
			FOculusToolCommands::Get().ToggleIterativeCookOnTheFly,
			FExecuteAction::CreateLambda([=]() {
				UOculusXRHMDRuntimeSettings* settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();
				settings->bIterativeCookOnTheFly = !settings->bIterativeCookOnTheFly;
				settings->Modify(true);
				settings->UpdateSinglePropertyInConfigFile(settings->GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UOculusXRHMDRuntimeSettings, bIterativeCookOnTheFly)), settings->GetDefaultConfigFilename());
			}),

			FCanExecuteAction(),
			FIsActionChecked::CreateLambda([=]() {
				return GetMutableDefault<UOculusXRHMDRuntimeSettings>()->bIterativeCookOnTheFly;
			}));
		PluginCommands->MapAction(
			FOculusToolCommands::Get().ToggleMetaXRSim,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::ToggleOpenXRRuntime),
			FCanExecuteAction(),
			FIsActionChecked::CreateLambda([=]() {
				return FOculusXRHMDModule::IsSimulatorActivated();
			}));
		PluginCommands->MapAction(
			FOculusToolCommands::Get().LaunchGameRoom,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::LaunchSESGameRoom),
			FCanExecuteAction());
		PluginCommands->MapAction(
			FOculusToolCommands::Get().LaunchLivingRoom,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::LaunchSESLivingRoom),
			FCanExecuteAction());
		PluginCommands->MapAction(
			FOculusToolCommands::Get().LaunchBedroom,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::LaunchSESBedroom),
			FCanExecuteAction());
		PluginCommands->MapAction(
			FOculusToolCommands::Get().Corridor,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::LaunchSESMoreRoomsCorridor),
			FCanExecuteAction());
		PluginCommands->MapAction(
			FOculusToolCommands::Get().FurnitureFilledRoom,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::LaunchSESMoreRoomsFurnitureFilledRoom),
			FCanExecuteAction());
		PluginCommands->MapAction(
			FOculusToolCommands::Get().HighCeilingRoom,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::LaunchSESMoreRoomsHighCeilingRoom),
			FCanExecuteAction());
		PluginCommands->MapAction(
			FOculusToolCommands::Get().LivingRoomWithMultipleSpaces,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::LaunchSESMoreRoomsLivingRoomWithMultipleSpaces),
			FCanExecuteAction());
		PluginCommands->MapAction(
			FOculusToolCommands::Get().LShapeRoom,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::LaunchSESMoreRoomsLShapeRoom),
			FCanExecuteAction());
		PluginCommands->MapAction(
			FOculusToolCommands::Get().Office,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::LaunchSESMoreRoomsOffice),
			FCanExecuteAction());
		PluginCommands->MapAction(
			FOculusToolCommands::Get().RoomWithStaircase,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::LaunchSESMoreRoomsRoomWithStaircase),
			FCanExecuteAction());
		PluginCommands->MapAction(
			FOculusToolCommands::Get().TrapezoidalRoom,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::LaunchSESMoreRoomsTrapezoidalRoom),
			FCanExecuteAction());
		PluginCommands->MapAction(
			FOculusToolCommands::Get().StopServer,
			FExecuteAction::CreateRaw(this, &FOculusXREditorModule::StopSESServer),
			FCanExecuteAction());

		FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

		// Adds an option to launch the tool to Window->Developer Tools.
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("Miscellaneous", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FOculusXREditorModule::AddMenuExtension));
		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);

		// We add the Oculus menu on the toolbar
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Play", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FOculusXREditorModule::AddToolbarExtension));
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);

		FGlobalTabmanager::Get()->RegisterNomadTabSpawner(OculusPlatToolTabName, FOnSpawnTab::CreateRaw(this, &FOculusXREditorModule::OnSpawnPlatToolTab)).SetDisplayName(LOCTEXT("FOculusPlatfToolTabTitle", "Meta XR Platform Tool")).SetMenuType(ETabSpawnerMenuType::Hidden);

		// Register asset types
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
		AssetTools.RegisterAssetTypeActions(MakeShareable(new FAssetTypeActions_OculusXRPassthroughColorLut));

		OculusXRTelemetry::PropagateTelemetryConsent();

		// If needed, open a notification here.
		OculusXRTelemetry::SpawnNotification();

		FOculusBuildAnalytics::GetInstance();

		const OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FEditorStart> StartEvent;
		bool bProjectCreatedFromMRTemplate = false;
		FProjectStatus ProjectStatus;
		if (IProjectManager::Get().QueryStatusForCurrentProject(ProjectStatus))
		{
			bProjectCreatedFromMRTemplate = ProjectStatus.Category == "MetaMRTemplate";
		}
		const auto& Annotated = StartEvent.AddAnnotation("created_from_mr_template", bProjectCreatedFromMRTemplate ? "true" : "false");

		UEditorPerformanceSettings* EditorPerformanceSettings = GetMutableDefault<UEditorPerformanceSettings>();
		if (EditorPerformanceSettings->bOverrideMaxViewportRenderingResolution)
		{
			UE_LOG(LogTemp, Warning, TEXT("Existing value for UEditorPerformanceSettings::MaxViewportRenderingResolution will be overriden."));
		}

		UE_LOG(LogTemp, Log, TEXT("MetaXR ignores max viewport resolution in editor to support full HMD resolutions."));
		EditorPerformanceSettings->bOverrideMaxViewportRenderingResolution = true;
		EditorPerformanceSettings->MaxViewportRenderingResolution = 0;

		FPropertyChangedEvent DisabledMaxResolutionEvent(EditorPerformanceSettings->GetClass()->FindPropertyByName(GET_MEMBER_NAME_CHECKED(UEditorPerformanceSettings, MaxViewportRenderingResolution)), EPropertyChangeType::ValueSet);
		EditorPerformanceSettings->PostEditChangeProperty(DisabledMaxResolutionEvent);
	}
}

void FOculusXREditorModule::ShutdownModule()
{
	if (!bModuleValid)
	{
		return;
	}

	if (!IsRunningCommandlet())
	{
		FOculusToolStyle::Shutdown();
		FOculusToolCommands::Unregister();
		FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(OculusPlatToolTabName);
		FOculusBuildAnalytics::Shutdown();
	}

	FOculusAssetDirectory::ReleaseAll();
	if (UObjectInitialized())
	{
		UnregisterSettings();
	}
}

TSharedRef<SDockTab> FOculusXREditorModule::OnSpawnPlatToolTab(const FSpawnTabArgs& SpawnTabArgs)
{
	/* clang-format off */
	auto myTab = SNew(SDockTab)
	.TabRole(ETabRole::NomadTab)
	[
		SNew(SOculusPlatformToolWidget)
	];
	/* clang-format on */

	return myTab;
}

void FOculusXREditorModule::RegisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "OculusXR",
			LOCTEXT("RuntimeSettingsName", "Meta XR"),
			LOCTEXT("RuntimeSettingsDescription", "Configure the Meta XR plugin"),
			GetMutableDefault<UOculusXRHMDRuntimeSettings>());

		FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyModule.RegisterCustomClassLayout(UOculusXRHMDRuntimeSettings::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&FOculusXRHMDSettingsDetailsCustomization::MakeInstance));

		SettingsModule->RegisterSettings("Editor", "Privacy", "OculusXR",
			LOCTEXT("PrivacyTelemetrySettingsName", "MetaXR Usage Data"),
			LOCTEXT("PrivacyTelemetrySettingsDescription", "Configure the way MetaXR usage information is handled."),
			GetMutableDefault<UOculusXRTelemetryPrivacySettings>());
		PropertyModule.RegisterCustomClassLayout(UOculusXRTelemetryPrivacySettings::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&FOculusXRSettingsToggle::MakeInstance));
	}
}

void FOculusXREditorModule::UnregisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "OculusXR");
		SettingsModule->UnregisterSettings("Editor", "Privacy", "OculusXR");
	}
}

FReply FOculusXREditorModule::PluginClickFn(bool text)
{
	PluginOpenSetupToolWindow();
	return FReply::Handled();
}

void FOculusXREditorModule::PluginOpenSetupToolWindow()
{
	IOculusXRProjectSetupToolModule::Get().ShowProjectSetupTool("Meta Menu");
}

void FOculusXREditorModule::PluginOpenPlatWindow()
{
	FGlobalTabmanager::Get()->TryInvokeTab(OculusPlatToolTabName);
}

void FOculusXREditorModule::ToggleOpenXRRuntime()
{
	FOculusXRHMDModule::ToggleOpenXRRuntime();
}

void FOculusXREditorModule::LaunchSESGameRoom()
{
	FOculusXRHMDModule::LaunchEnvironment("GameRoom");
}

void FOculusXREditorModule::LaunchSESLivingRoom()
{
	FOculusXRHMDModule::LaunchEnvironment("LivingRoom");
}

void FOculusXREditorModule::LaunchSESBedroom()
{
	FOculusXRHMDModule::LaunchEnvironment("Bedroom");
}

void FOculusXREditorModule::LaunchSESMoreRoomsCorridor()
{
	FOculusXRHMDModule::LaunchMoreRoomsEnvironment("XRoom2_3");
}

void FOculusXREditorModule::LaunchSESMoreRoomsFurnitureFilledRoom()
{
	FOculusXRHMDModule::LaunchMoreRoomsEnvironment("XRoom2_4");
}

void FOculusXREditorModule::LaunchSESMoreRoomsHighCeilingRoom()
{
	FOculusXRHMDModule::LaunchMoreRoomsEnvironment("XRoom5_6");
}

void FOculusXREditorModule::LaunchSESMoreRoomsLivingRoomWithMultipleSpaces()
{
	FOculusXRHMDModule::LaunchMoreRoomsEnvironment("XRoom3_1");
}

void FOculusXREditorModule::LaunchSESMoreRoomsLShapeRoom()
{
	FOculusXRHMDModule::LaunchMoreRoomsEnvironment("XRoom5_1");
}

void FOculusXREditorModule::LaunchSESMoreRoomsOffice()
{
	FOculusXRHMDModule::LaunchMoreRoomsEnvironment("XRoom1_2");
}

void FOculusXREditorModule::LaunchSESMoreRoomsRoomWithStaircase()
{
	FOculusXRHMDModule::LaunchMoreRoomsEnvironment("XRoom1_1");
}

void FOculusXREditorModule::LaunchSESMoreRoomsTrapezoidalRoom()
{
	FOculusXRHMDModule::LaunchMoreRoomsEnvironment("XRoom1_4");
}

void FOculusXREditorModule::StopSESServer()
{
	FOculusXRHMDModule::StopServer();
}

void FOculusXREditorModule::AddMenuExtension(FMenuBuilder& Builder)
{
	bool v = false;
	GConfig->GetBool(TEXT("/Script/OculusXREditor.OculusXREditorSettings"), TEXT("bAddMenuOption"), v, GEditorIni);
	if (v)
	{
		Builder.AddMenuEntry(FOculusToolCommands::Get().OpenProjectSetupTool);
	}
}

void FOculusXREditorModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.SetLabelVisibility(EVisibility::All);
	Builder.AddComboButton(
		FUIAction(),
		FOnGetContent::CreateRaw(this, &FOculusXREditorModule::CreateToolbarEntryMenu, PluginCommands),
		LOCTEXT("OculusToolsToolBarCombo", "Meta XR Tools"),
		LOCTEXT("OculusToolsToolBarComboTooltip", "Meta XR tools"),
		TAttribute<FSlateIcon>::CreateLambda([]() {
			return FSlateIcon(FOculusToolStyle::GetStyleSetName(), "OculusTool.MenuButton");
		}),
		false);

	Builder.AddComboButton(
		FUIAction(),
		FOnGetContent::CreateRaw(this, &FOculusXREditorModule::CreateXrSimToolbarEntryMenu, PluginCommands),
		LOCTEXT("MetaXRSimulatorCombo", "Meta XR Simulator"),
		LOCTEXT("MetaXRSimulatorComboTooltip", "Meta XR Simulator"),
		TAttribute<FSlateIcon>::CreateLambda([]() {
			return FSlateIcon(FOculusToolStyle::GetStyleSetName(), "OculusTool.MenuButton");
		}),
		false);
}

// Add the entries to the OculusXR Tools toolbar menu button
TSharedRef<SWidget> FOculusXREditorModule::CreateToolbarEntryMenu(TSharedPtr<class FUICommandList> Commands)
{
	FMenuBuilder MenuBuilder(true, Commands);
	MenuBuilder.BeginSection("OculusXRBuilds", LOCTEXT("OculusXRBuilds", "Builds"));
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().ToggleDeploySo);
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().ToggleIterativeCookOnTheFly);
	MenuBuilder.EndSection();

	MenuBuilder.BeginSection("OculusXRTools", LOCTEXT("OculusXRTools", "Tools"));
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().OpenProjectSetupTool);
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().OpenPlatWindow);
	MenuBuilder.EndSection();

	return MenuBuilder.MakeWidget();
}

TSharedRef<SWidget> FOculusXREditorModule::CreateXrSimToolbarEntryMenu(TSharedPtr<class FUICommandList> Commands)
{
	FMenuBuilder MenuBuilder(true, Commands);

	MenuBuilder.BeginSection("MetaXRSimulator", LOCTEXT("MetaXRSimulator", "Toggle"));
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().ToggleMetaXRSim);
	MenuBuilder.EndSection();

	MenuBuilder.BeginSection("SES", LOCTEXT("SES", "SES"));
	MenuBuilder.AddSubMenu(
		LOCTEXT("Synthetic Environment Server", "Synthetic Environment Server"),
		LOCTEXT("Synthetic Environment Server", "Synthetic Environment Server"),
		FNewMenuDelegate::CreateRaw(this, &FOculusXREditorModule::CreateSESSubMenus));
	MenuBuilder.EndSection();

	return MenuBuilder.MakeWidget();
}

void FOculusXREditorModule::CreateSESSubMenus(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.BeginSection("Synthetic Environment Server", LOCTEXT("Synthetic Environment Server", "Synthetic Environment Server"));
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().LaunchGameRoom);
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().LaunchLivingRoom);
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().LaunchBedroom);
	MenuBuilder.AddSubMenu(
		LOCTEXT("More Rooms", "More Rooms"),
		LOCTEXT("More Rooms", "More Rooms"),
		FNewMenuDelegate::CreateRaw(this, &FOculusXREditorModule::CreateSESMoreRoomsSubMenus));
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().StopServer);
	MenuBuilder.EndSection();
}

void FOculusXREditorModule::CreateSESMoreRoomsSubMenus(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.BeginSection("More Rooms", LOCTEXT("More Rooms", "More Rooms"));
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().Corridor);
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().FurnitureFilledRoom);
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().HighCeilingRoom);
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().LivingRoomWithMultipleSpaces);
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().LShapeRoom);
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().Office);
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().RoomWithStaircase);
	MenuBuilder.AddMenuEntry(FOculusToolCommands::Get().TrapezoidalRoom);
	MenuBuilder.EndSection();
}

FOculusXRHMDSettingsDetailsCustomization::FOculusXRHMDSettingsDetailsCustomization()
	: LaunchImageLandscape(FPlatformIconInfo(TEXT("res/drawable/splashscreen_landscape.png"), LOCTEXT("SystemSplashImage", "System Splash Image"), FText::GetEmpty(), 640, 360, FPlatformIconInfo::Required))
	, EngineAndroidPath(FPaths::EngineDir() + TEXT("Build/Android/Java"))
	, GameAndroidPath(FPaths::ProjectDir() + TEXT("Build/Android"))
	, VRSplashPath(FPaths::ProjectDir() + TEXT("Build/Android/assets/vr_splash.png"))

{
}

TSharedRef<IDetailCustomization> FOculusXRHMDSettingsDetailsCustomization::MakeInstance()
{
	return MakeShareable(new FOculusXRHMDSettingsDetailsCustomization);
}

FReply FOculusXRHMDSettingsDetailsCustomization::PluginClickPerfFn(bool text)
{
	IOculusXRProjectSetupToolModule::Get().ShowProjectSetupTool("Settings");
	return FReply::Handled();
}

FReply FOculusXRHMDSettingsDetailsCustomization::PluginClickPlatFn(bool text)
{
	FGlobalTabmanager::Get()->TryInvokeTab(FOculusXREditorModule::OculusPlatToolTabName);
	return FReply::Handled();
}

FReply FOculusXRHMDSettingsDetailsCustomization::DisableEngineSplash(bool text)
{
	UOculusXRHMDRuntimeSettings* Settings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();
	Settings->bAutoEnabled = false;
	Settings->SplashDescs.Empty();
	Settings->TryUpdateDefaultConfigFile();
	return FReply::Handled();
}

FReply FOculusXRHMDSettingsDetailsCustomization::AddSplashImage(bool text)
{
	const FString AutomaticImagePath = EngineAndroidPath / LaunchImageLandscape.IconPath;
	FText FailReason;
	if (!SourceControlHelpers::CopyFileUnderSourceControl(VRSplashPath, AutomaticImagePath, LOCTEXT("ImageDescription", "image"), FailReason))
	{
		FNotificationInfo Info(FailReason);
		Info.ExpireDuration = 3.0f;
		FSlateNotificationManager::Get().AddNotification(Info);
		return FReply::Unhandled();
	}

	return FReply::Handled();
}

void FOculusXRHMDSettingsDetailsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	static const FName WarningColorStyle("Colors.AccentYellow");
	SavedLayoutBuilder = &DetailLayout;

	// Labeled "General OculusXR" instead of "General" to enable searchability. The button "Launch Oculus Utilities Window" doesn't show up if you search for "Oculus"
	IDetailCategoryBuilder& CategoryBuilder = DetailLayout.EditCategory("General Meta XR", FText::GetEmpty(), ECategoryPriority::Important);
	/* clang-format off */
	CategoryBuilder.AddCustomRow(LOCTEXT("General", "General"))
	.WholeRowContent()
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot().AutoHeight().Padding(2)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth()
			[
				SNew(SButton)
				.Text(LOCTEXT("LaunchTool", "Launch Meta XR Project Setup Tool"))
				.OnClicked(this, &FOculusXRHMDSettingsDetailsCustomization::PluginClickPerfFn, true)
			]
			+ SHorizontalBox::Slot().FillWidth(8)
		]
		+ SVerticalBox::Slot().AutoHeight().Padding(2)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth()
			[
				SNew(SButton)
				.Text(LOCTEXT("LaunchPlatTool", "Launch Meta XR Platform Window"))
				.OnClicked(this, &FOculusXRHMDSettingsDetailsCustomization::PluginClickPlatFn, true)
			]
			+ SHorizontalBox::Slot().FillWidth(8)
		]
	];

	IDetailCategoryBuilder& CTXPTCategoryBuilder = DetailLayout.EditCategory("System SplashScreen", FText::GetEmpty(), ECategoryPriority::Important);

	CTXPTCategoryBuilder.AddCustomRow(LOCTEXT("CTXPTWarning", "Contextual Passthrough Warning"))
	.Visibility(TAttribute<EVisibility>(this, &FOculusXRHMDSettingsDetailsCustomization::GetContextualPassthroughWarningVisibility))
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot().FillHeight(1.f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().FillWidth(1.f).VAlign(EVerticalAlignment::VAlign_Center)
			[
				SNew(STextBlock)
				.Font(IDetailLayoutBuilder::GetDetailFont())
				.AutoWrapText(true)
				.Justification(ETextJustify::Center)
				.Text(LOCTEXT("CTXPT_EngineSplashWarning", "Engine Splash Screen is enabled, this will result in an inconsistent experience."))
				.ColorAndOpacity(FAppStyle::Get().GetSlateColor(WarningColorStyle))
			]
			+ SHorizontalBox::Slot().FillWidth(1.f).HAlign(EHorizontalAlignment::HAlign_Left)
			[
				SNew(SButton)
				.VAlign(EVerticalAlignment::VAlign_Center)
				.Text(LOCTEXT("DisableEngineSplashScreen", "Disable Engine Splash Screen"))
				.OnClicked(this, &FOculusXRHMDSettingsDetailsCustomization::DisableEngineSplash, true)
			]
		]
	];


	// Duplicate "Show Launch Image" and "Launch Landscape" properties from Android Settings

	CTXPTCategoryBuilder.AddCustomRow(LOCTEXT("ShowSystemSplashImageRow", "Show System Splash Image Row"))
		.NameContent()
		[
			SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.Padding(FMargin(0, 1, 0, 1))
				.FillWidth(1.0f)
				[
					SNew(STextBlock)
						.Text(LOCTEXT("ShowSystemSplashImage", "Show System Splash Image"))
						.Font(DetailLayout.GetDetailFont())
						.ToolTipText(LOCTEXT("ShowSystemSplashImageToolTip", "Same as \"Show Launch Image\" setting in the \"Platform > Android > Launch Images\" section. If set, the image will be presented by the Operating System at launch time"))
				]
		]
		.ValueContent()
		.MaxDesiredWidth(400.0f)
		.MinDesiredWidth(100.0f)
		[
			SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				[
					SNew(SCheckBox)
						.IsChecked(TAttribute<ECheckBoxState>(this, &FOculusXRHMDSettingsDetailsCustomization::GetShowLaunchImageCheckBoxState))
						.OnCheckStateChanged(this, &FOculusXRHMDSettingsDetailsCustomization::OnShowLaunchImageCheckStateChanged)
				]
		];


	const FString AutomaticImagePath = EngineAndroidPath / LaunchImageLandscape.IconPath;
	const FString TargetImagePath = GameAndroidPath / LaunchImageLandscape.IconPath;
	const FVector2D LaunchImageMaxSize(150.0f, 150.0f);

	CTXPTCategoryBuilder.AddCustomRow(LaunchImageLandscape.IconName)
		.IsEnabled(TAttribute<bool>(this, &FOculusXRHMDSettingsDetailsCustomization::IsLaunchImageEnabled))
		.NameContent()
		[
			SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.Padding(FMargin(0, 1, 0, 1))
				.FillWidth(1.0f)
				[
					SNew(STextBlock)
						.Text(LaunchImageLandscape.IconName)
						.Font(DetailLayout.GetDetailFont())
						.ToolTipText(LOCTEXT("SystemSplashImageToolTip", "Same as \"Launch Landscape\" setting in the \"Platform > Android > Launch Images\" section. This is the image that will be presented by the Operating System at launch time"))
				]
		]
		.ValueContent()
		.MaxDesiredWidth(400.0f)
		.MinDesiredWidth(100.0f)
		[
			SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.FillWidth(1.0f)
				.VAlign(VAlign_Center)
				[
					SNew(SExternalImageReference, AutomaticImagePath, TargetImagePath)
						.FileDescription(LaunchImageLandscape.IconDescription)
						.MaxDisplaySize(LaunchImageMaxSize)
						.OnPostExternalImageCopy(FOnPostExternalImageCopy::CreateSP(this, &FOculusXRHMDSettingsDetailsCustomization::OnLaunchImageChanged))
				]
		];

	CTXPTCategoryBuilder.AddCustomRow(LOCTEXT("SystemSplashImageWarning", "System Splash Image warning"))
		.Visibility(TAttribute<EVisibility>(this, &FOculusXRHMDSettingsDetailsCustomization::GetSystemSplashImageWarningVisibility))
		[
			SNew(SVerticalBox)
				+ SVerticalBox::Slot().FillHeight(1.f)
				[
					SNew(SHorizontalBox)
						+ SHorizontalBox::Slot().FillWidth(1.f).VAlign(EVerticalAlignment::VAlign_Center)
						[
							SNew(STextBlock)
								.Font(IDetailLayoutBuilder::GetDetailFont())
								.AutoWrapText(true)
								.Justification(ETextJustify::Center)
								.Text(LOCTEXT("SystemSplashWarningText", "Splash Image is currently missing from project. Click button to add it."))
								.ColorAndOpacity(FAppStyle::Get().GetSlateColor(WarningColorStyle))
						]
						+ SHorizontalBox::Slot().FillWidth(1.f).HAlign(EHorizontalAlignment::HAlign_Left)
						[
							SNew(SButton)
								.VAlign(EVerticalAlignment::VAlign_Center)
								.Text(LOCTEXT("DisableEngineSplashScreen", "Add Splash Image file to project"))
								.OnClicked(this, &FOculusXRHMDSettingsDetailsCustomization::AddSplashImage, true)
						]
				]
		];
	/* clang-format on */
}

EVisibility FOculusXRHMDSettingsDetailsCustomization::GetContextualPassthroughWarningVisibility() const
{
	UOculusXRHMDRuntimeSettings* OculusSettings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();
	return OculusSettings->SystemSplashBackground == ESystemSplashBackgroundType::Contextual && (OculusSettings->bAutoEnabled || !OculusSettings->SplashDescs.IsEmpty()) ? EVisibility::Visible : EVisibility::Collapsed;
}

ECheckBoxState FOculusXRHMDSettingsDetailsCustomization::GetShowLaunchImageCheckBoxState() const
{
	UAndroidRuntimeSettings* AndroidSettings = GetMutableDefault<UAndroidRuntimeSettings>();
	return AndroidSettings->bShowLaunchImage ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

bool FOculusXRHMDSettingsDetailsCustomization::IsLaunchImageEnabled() const
{
	UAndroidRuntimeSettings* AndroidSettings = GetMutableDefault<UAndroidRuntimeSettings>();
	return AndroidSettings->bShowLaunchImage;
}

void FOculusXRHMDSettingsDetailsCustomization::OnShowLaunchImageCheckStateChanged(const ECheckBoxState NewState)
{
	UAndroidRuntimeSettings* AndroidSettings = GetMutableDefault<UAndroidRuntimeSettings>();
	AndroidSettings->bShowLaunchImage = NewState == ECheckBoxState::Checked;
	AndroidSettings->TryUpdateDefaultConfigFile();
}

bool FOculusXRHMDSettingsDetailsCustomization::OnLaunchImageChanged(const FString& InChosenImage)
{
	// This will refresh the launch image located in android settings as well
	SavedLayoutBuilder->ForceRefreshDetails();

	FText FailReason;
	if (!SourceControlHelpers::CopyFileUnderSourceControl(VRSplashPath, InChosenImage, LOCTEXT("ImageDescription", "image"), FailReason))
	{
		FNotificationInfo Info(FailReason);
		Info.ExpireDuration = 3.0f;
		FSlateNotificationManager::Get().AddNotification(Info);
		return false;
	}

	return true;
}

EVisibility FOculusXRHMDSettingsDetailsCustomization::GetSystemSplashImageWarningVisibility() const
{
	IFileManager& FileManager = IFileManager::Get();

	return !FileManager.FileExists(*VRSplashPath) ? EVisibility::Visible : EVisibility::Collapsed;
}

//////////////////////////////////////////////////////////////////////////

IMPLEMENT_MODULE(FOculusXREditorModule, OculusXREditor);

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
