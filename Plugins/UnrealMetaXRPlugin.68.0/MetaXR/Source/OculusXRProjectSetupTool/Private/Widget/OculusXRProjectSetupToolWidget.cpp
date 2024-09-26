// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRProjectSetupToolWidget.h"

#include "DetailColumnSizeData.h"
#include "OculusXRProjectSetupToolModule.h"
#include "OculusXRPSTEvents.h"
#include "OculusXRPSTSettings.h"
#include "OculusXRPSTUtils.h"
#include "OculusXRTelemetry.h"
#include "SWarningOrErrorBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Input/SButton.h"
#include "Styling/SlateStyle.h"

#define LOCTEXT_NAMESPACE "OculusXRProjectSetupToolWidget"

/**
 * Construct the layout for the project setup tool tab
 *
 * @param InArgs [in] the arguments associated with this tool
 */
void SOculusXRProjectSetupToolWidget::Construct(const FArguments& InArgs)
{
	Refresh();

	// Populate the platform filter
	PlatformFilters.Add(MetaQuest_All);
	PlatformFilters.Add(ESetupRulePlatform::MetaLink);
	PlatformFilters.Add(ESetupRulePlatform::MetaQuest_3);
	PlatformFilters.Add(ESetupRulePlatform::MetaQuest_Pro);
	PlatformFilters.Add(ESetupRulePlatform::MetaQuest_2);

	const auto Settings = GetMutableDefault<UOculusXRPSTSettings>();

	UpdateActiveTimer(Settings->bBackGroundChecks);

	// Apply the starting platform filter.
	const auto& Platform = static_cast<ESetupRulePlatform>(Settings->CurrentPlatform);
	CurrentPlatformFilterIndex = PlatformFilters.Find(Platform);

	if (CurrentPlatformFilterIndex == INDEX_NONE)
	{
		CurrentPlatformFilterIndex = 0;
	}

	// Setup the column information for the layout
	ColumnSizeData = MakeShared<FDetailColumnSizeData>();
	ColumnSizeData->SetValueColumnWidth(0.75f);
	ColumnSizeData->SetRightColumnMinWidth(150);

	// Construct the layout

	RootContainerWidget = SNew(SVerticalBox);

	BuildLayout(RootContainerWidget);

	ChildSlot
		[RootContainerWidget.ToSharedRef()];
}

/**
 * Build the layout for the main window
 */
void SOculusXRProjectSetupToolWidget::BuildLayout(const TSharedPtr<SVerticalBox>& RootContainer)
{
	// Clear all existing contents
	RootContainer->ClearChildren();

	const TSharedPtr<SVerticalBox> HeaderContainer = SNew(SVerticalBox);
	// Section to contain the title bar
	BuildTitleSectionLayout(HeaderContainer);

	// Section to contain the filters
	BuildFilterSectionLayout(HeaderContainer, CurrentPlatformFilterIndex);

	const TSharedPtr<SScrollBox> RulesContainer = SNew(SScrollBox);
	// Section to contain the required rules
	BuildRequiredRulesSectionLayout(RulesContainer);

	// Section to contain the recommended rules
	BuildRecommendedRulesSectionLayout(RulesContainer);

	// Section to contain the applied rules
	BuildAppliedRulesSectionLayout(RulesContainer);

	// Section to contain the ignored rules
	BuildIgnoredRulesSectionLayout(RulesContainer);

	RootContainer->AddSlot()
		.AutoHeight()
		.Padding(0)
			[HeaderContainer.ToSharedRef()];

	RootContainer->AddSlot()
		.Padding(0)
			[RulesContainer.ToSharedRef()];

	// Section to show warning about restarting editor
	RootContainer->AddSlot()
		.AutoHeight()
			[SNew(SVerticalBox)
				+ SVerticalBox::Slot()
					  .AutoHeight()
					  .Padding(FMargin(18.0f, 20.0f, 18.0f, 16.0f))
						  [SNew(SWarningOrErrorBox)
								  .Visibility(this, &SOculusXRProjectSetupToolWidget::OnRestartEditorNoticeVisibility)
								  .MessageStyle(EMessageStyle::Warning)
								  .Message(LOCTEXT("PluginSettingsRestartNotice", "You must restart Unreal Editor for your changes to take effect."))
									  [SNew(SButton)
											  .OnClicked(this, &SOculusXRProjectSetupToolWidget::OnRestartEditorButtonClicked)
											  .TextStyle(FAppStyle::Get(), "NormalText")
											  .Text(LOCTEXT("PluginSettingsRestartEditor", "Restart Now"))]]];
}

/**
 * Build the title section layout
 */
void SOculusXRProjectSetupToolWidget::BuildTitleSectionLayout(const TSharedPtr<SVerticalBox>& RootContainer)
{
	const TSharedPtr<SHorizontalBox> TitleWidget = SNew(SHorizontalBox)
													   .Clipping(EWidgetClipping::OnDemand);

	ProjectStatusWidget = SNew(STextBlock)
							  .Font(FAppStyle::Get().GetFontStyle(TEXT("DetailsView.CategoryFontStyle")))
							  .TextStyle(FAppStyle::Get(), "DetailsView.CategoryTextStyle")
							  .Text(FText());

	UpdateProjectStatus();

	TitleWidget->AddSlot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(8, 0, 0, 0)
			[ProjectStatusWidget.ToSharedRef()];

	const TSharedPtr<SHorizontalBox> ButtonWidget = SNew(SHorizontalBox);

	auto Settings = GetMutableDefault<UOculusXRPSTSettings>();
	FMenuBuilder DetailViewOptions(true, nullptr);

	DetailViewOptions.AddMenuEntry(
		LOCTEXT("BackGroundChecks", "Enable background rule checks"),
		LOCTEXT("BackGroundChecks_ToolTip", "If enabled background rule validity will be performed every 30 seconds."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateLambda([Settings] {
				Settings->bBackGroundChecks = !Settings->bBackGroundChecks;
				Settings->SaveConfig();
				const OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FProjectSetupToolOption> OptionEvent;
				const auto& Annotated = OptionEvent
											.AddAnnotation(OculusXRTelemetry::Annotations::Uid, "bBackGroundChecks")
											.AddAnnotation(OculusXRTelemetry::Annotations::Value,
												Settings->bBackGroundChecks ? "true" : "false");
			}),
			FCanExecuteAction(),
			FIsActionChecked::CreateLambda([Settings]() -> bool {
				return Settings->bBackGroundChecks;
			})),
		NAME_None,
		EUserInterfaceActionType::ToggleButton);

	DetailViewOptions.AddMenuEntry(
		LOCTEXT("StopBuildOnUnappliedRequredItem", "Stop build on unapplied items"),
		LOCTEXT("StopBuildOnUnappliedRequredItem_ToolTip", "Stop build if required items are not applied or ignored."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateLambda([Settings] {
				Settings->bStopBuildOnUnAppliedCriticalItems = !Settings->bStopBuildOnUnAppliedCriticalItems;
				Settings->SaveConfig();
				const OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FProjectSetupToolOption> OptionEvent;
				const auto& Annotated = OptionEvent
											.AddAnnotation(OculusXRTelemetry::Annotations::Uid, "bStopBuildOnUnAppliedCriticalItems")
											.AddAnnotation(OculusXRTelemetry::Annotations::Value,
												Settings->bStopBuildOnUnAppliedCriticalItems ? "true" : "false");
			}),
			FCanExecuteAction(),
			FIsActionChecked::CreateLambda([Settings]() -> bool {
				return Settings->bStopBuildOnUnAppliedCriticalItems;
			})),
		NAME_None,
		EUserInterfaceActionType::ToggleButton);

	ButtonWidget->AddSlot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Padding(FMargin(8.f, 0.f, 8.f, 0.f))
			[SNew(SComboButton)
					.ContentPadding(0)
					.HasDownArrow(false)
					.ForegroundColor(FSlateColor::UseForeground())
					.ComboButtonStyle(FAppStyle::Get(), "SimpleComboButton")
					.AddMetaData<FTagMetaData>(FTagMetaData(TEXT("ViewOptions")))
					.MenuContent()
						[DetailViewOptions.MakeWidget()]
					.ButtonContent()
						[SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
								  .AutoWidth()
								  .HAlign(HAlign_Center)
									  [SNew(SImage)
											  .Image(FAppStyle::Get().GetBrush("Icons.Toolbar.Settings"))
											  .ColorAndOpacity(FSlateColor::UseForeground())]]];

	// Top level container for the whole row
	const TSharedPtr<SHorizontalBox> RowWidget = SNew(SHorizontalBox);

	RowWidget->AddSlot()
		.HAlign(HAlign_Left)
			[TitleWidget.ToSharedRef()];

	RowWidget->AddSlot()
		.HAlign(HAlign_Right)
			[ButtonWidget.ToSharedRef()];

	// Add into the root container
	RootContainer->AddSlot()
		.AutoHeight()
		.Padding(0)
			[SNew(SBorder)
					.BorderImage(FAppStyle::Get().GetBrush("DetailsView.GridLine"))
					.Padding(FMargin(0, 0, 0, 1))
						[SNew(SHorizontalBox)

							+ SHorizontalBox::Slot()
								[SNew(SBorder)
										.BorderImage(FAppStyle::Get().GetBrush("DetailsView.CategoryTop"))
										.BorderBackgroundColor(FSlateColor(FLinearColor::White))
										.Padding(0)
											[SNew(SBox)
													.MinDesiredHeight(26.0f)
														[RowWidget.ToSharedRef()]]]]];
}

/**
 * Build the filter section layout
 */
void SOculusXRProjectSetupToolWidget::BuildFilterSectionLayout(const TSharedPtr<SVerticalBox>& RootContainer, const uint32 PlatformFilterIndex)
{
	// Top level container for the whole row
	const TSharedPtr<SHorizontalBox> RowWidget = SNew(SHorizontalBox);

	uint32 index = 0;

	for (const auto& Platform : PlatformFilters)
	{
		const FSlateBrush* BorderBrush = FAppStyle::Get().GetBrush("DetailsView.GridLine");

		if (index == PlatformFilterIndex)
		{
			BorderBrush = FAppStyle::Get().GetBrush("DetailsView.CategoryTop");
		}

		++index;

		RowWidget->AddSlot()
			.Padding(FMargin(0, 1, 1, 1))
				[SNew(SBorder)
						.BorderImage(BorderBrush)
							[SNew(SHorizontalBox)
								+ SHorizontalBox::Slot()
									[SNew(SButton)
											.HAlign(HAlign_Center)
											.VAlign(VAlign_Center)
											.ContentPadding(0)
											.ButtonStyle(FCoreStyle::Get(), "NoBorder")
											.OnClicked(this, &SOculusXRProjectSetupToolWidget::OnPlatformFilterChanged, Platform)
												[SNew(SHorizontalBox)
													+ SHorizontalBox::Slot()
														  .Padding(0, 3, 3, 3)
															  [SNew(SImage)
																	  .Image(
																		  FOculusXRProjectSetupToolModule::GetSlateStyle()
																			  ->GetBrush(OculusXRPSTUtils::GetDisplayName(
																				  Platform)))
																	  .ColorAndOpacity(FSlateColor::UseForeground())]
													+ SHorizontalBox::Slot()
														  .Padding(3, 0, 0, 0)
														  .AutoWidth()
														  .VAlign(VAlign_Center)
															  [SNew(STextBlock)
																	  .Text(FText::FromString(OculusXRPSTUtils::GetDisplayName(Platform)))]]]]];
	}

	// Add into the root container
	RootContainer->AddSlot()
		.AutoHeight()
		.Padding(0)
			[SNew(SBorder)
					.BorderImage(FAppStyle::Get().GetBrush("DetailsView.GridLine"))
					.Padding(FMargin(0, 0, 0, 1))
						[SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
								[SNew(SBorder)
										.BorderImage(FAppStyle::Get().GetBrush("DetailsView.CategoryTop"))
										.BorderBackgroundColor(FSlateColor(FLinearColor::White))
										.Padding(0)
											[SNew(SBox)
													.MinDesiredHeight(26.0f)
														[RowWidget.ToSharedRef()]]]]];
}

/**
 * Build a container for a rules section
 */
TSharedPtr<SVerticalBox> SOculusXRProjectSetupToolWidget::BuildRulesContainerLayout(const TSharedPtr<SScrollBox>& RootContainer, ERulesSection Section, const FText& SectionTitle)
{
	// Top level container for the whole row
	const TSharedPtr<SHorizontalBox> TitleAndExpanderWidget = SNew(SHorizontalBox)
																  .Clipping(EWidgetClipping::OnDemand);

	TitleAndExpanderWidget->AddSlot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(8, 0, 8, 0)
		.AutoWidth()
			[SNew(SHorizontalBox)
					.Visibility_Static(&SOculusXRProjectSetupToolWidget::OnHeaderExpanderVisibility, Section)
				+ SHorizontalBox::Slot()
					[SNew(SButton)
							.ButtonStyle(FCoreStyle::Get(), "NoBorder")
							.VAlign(VAlign_Center)
							.HAlign(HAlign_Center)
							.ClickMethod(EButtonClickMethod::MouseDown)
							.OnClicked(this, &SOculusXRProjectSetupToolWidget::OnHeaderExpanderClicked, Section)
							.ContentPadding(0)
							.IsFocusable(false)
								[SNew(SImage)
										.Image(this, &SOculusXRProjectSetupToolWidget::GetHeaderExpanderImage, Section)
										.ColorAndOpacity(FSlateColor::UseSubduedForeground())]]];

	TitleAndExpanderWidget->AddSlot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(0, 0, 0, 0)
			[SNew(STextBlock)
					.Font(FAppStyle::Get().GetFontStyle(TEXT("DetailsView.CategoryFontStyle")))
					.TextStyle(FAppStyle::Get(), "DetailsView.CategoryTextStyle")
					.Text(SectionTitle)];

	const TSharedPtr<SHorizontalBox> EmptyDescriptionWidget = SNew(SHorizontalBox);
	const TSharedPtr<SHorizontalBox> ButtonWidget = SNew(SHorizontalBox);

	if (Section == ERulesSection::Required || Section == ERulesSection::Recommended)
	{
		ButtonWidget->AddSlot()
			.Padding(FMargin(6, 3, 3, 3))
				[SNew(SButton)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.ButtonStyle(&FAppStyle::Get().GetWidgetStyle<FButtonStyle>("PrimaryButton"))
						.Text(LOCTEXT("ApplyAllRules", "Apply All"))
						.OnClicked(this, &SOculusXRProjectSetupToolWidget::OnApplyAllRulesClicked, Section)
						.IsEnabled_Raw(this, &SOculusXRProjectSetupToolWidget::OnApplyAllRulesEnabled, Section)];

		// This is not actually needed but we add it to ensure correct alignment
		ButtonWidget->AddSlot()
			.AutoWidth()
			.VAlign(VAlign_Center)
			.Padding(FMargin(4.f, 0.f, 8.f, 0.f))
				[SNew(SComboButton)
						.ContentPadding(0)
						.Visibility_Lambda([this]() -> EVisibility { return EVisibility::Hidden; })
						.HasDownArrow(false)
						.ForegroundColor(FSlateColor::UseForeground())
						.ComboButtonStyle(FAppStyle::Get(), "SimpleComboButton")
						.ButtonContent()
							[SNew(SHorizontalBox)
								+ SHorizontalBox::Slot()
									  .AutoWidth()
									  .HAlign(HAlign_Center)
										  [SNew(SImage)
												  .Image(FAppStyle::Get().GetBrush("PropertyWindow.Button_Ellipsis"))
												  .ColorAndOpacity(FSlateColor::UseForeground())]]];
	}

	// Splitter so each row can contain Name | Description | Buttons
	const TSharedPtr<SSplitter> Splitter = SNew(SSplitter)
											   .Style(FAppStyle::Get(), "DetailsView.Splitter")
											   .PhysicalSplitterHandleSize(1.0f)
											   .HitDetectionSplitterHandleSize(5.0f);

	// Add the widgets to the splitter
	Splitter->AddSlot()
		.Value(ColumnSizeData->GetNameColumnWidth())
		.OnSlotResized(ColumnSizeData->GetOnNameColumnResized())
			[TitleAndExpanderWidget.ToSharedRef()];

	Splitter->AddSlot()
		.Value(ColumnSizeData->GetValueColumnWidth())
		.OnSlotResized(ColumnSizeData->GetOnValueColumnResized())
			[EmptyDescriptionWidget.ToSharedRef()];

	Splitter->AddSlot()
		.Value(ColumnSizeData->GetRightColumnWidth())
		.OnSlotResized(ColumnSizeData->GetOnRightColumnResized())
		.MinSize(ColumnSizeData->GetRightColumnMinWidth())
			[ButtonWidget.ToSharedRef()];

	// Top level container for the whole row
	const TSharedPtr<SWidget> RowWidget = SNew(SBox)
											  .Padding(0)
												  [Splitter.ToSharedRef()];
	// Add into the root container
	RootContainer->AddSlot()
		.Padding(0)
			[SNew(SBorder)
					.BorderImage(FAppStyle::Get().GetBrush("DetailsView.GridLine"))
					.Padding(FMargin(0, 0, 0, 1))
						[SNew(SHorizontalBox)

							+ SHorizontalBox::Slot()
								[SNew(SBorder)
										.BorderImage(FAppStyle::Get().GetBrush("DetailsView.CategoryTop"))
										.BorderBackgroundColor(FSlateColor(FLinearColor::White))
										.Padding(0)
											[SNew(SBox)
													.MinDesiredHeight(26.0f)
														[RowWidget.ToSharedRef()]]]]];

	// Contents
	TSharedPtr<SVerticalBox> SectionContentContainer = SNew(SVerticalBox);

	RootContainer->AddSlot()
		.Padding(0)
			[SectionContentContainer.ToSharedRef()];

	return SectionContentContainer;
}

/**
 * Build the layout for a single row (filter or rule row)
 */
void SOculusXRProjectSetupToolWidget::BuildRowItemLayout(const TSharedPtr<SVerticalBox>& SectionContentContainer, ERulesSection Section, const SetupRulePtr& Rule, const uint32 PlatformFilterIndex)
{
	// RowWidget -> Splitter -> (NameWidget | DescriptionWidget | ButtonWidget)
	const bool bShouldHideApplyButton = Section == ERulesSection::Applied;
	const FSlateBrush* IconBrush = nullptr;

	if (Rule != nullptr)
	{
		if (Section == ERulesSection::Applied)
		{
			IconBrush = FAppStyle::Get().GetBrush("Icons.SuccessWithColor");
		}
		else if (Rule->GetSeverity() == ESetupRuleSeverity::Critical)
		{
			IconBrush = FAppStyle::Get().GetBrush("Icons.ErrorWithColor");
		}
		else
		{
			IconBrush = FAppStyle::Get().GetBrush("Icons.WarningWithColor");
		}
	}

	// Name widget
	const TSharedPtr<SHorizontalBox> NameWidget = SNew(SHorizontalBox)
													  .Clipping(EWidgetClipping::OnDemand);

	if (IconBrush != nullptr)
	{
		NameWidget->AddSlot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.Padding(8, 0, 8, 0)
			.AutoWidth()
				[SNew(SImage)
						.Image(IconBrush)];
	}

	NameWidget->AddSlot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(0, 0, 0, 0)
			[SNew(STextBlock)
					.Font(FAppStyle::Get().GetFontStyle(TEXT("PropertyWindow.NormalFont")))
					.ColorAndOpacity(FSlateColor::UseStyle())
					.Text(Rule != nullptr ? Rule->GetDisplayName() : FText::GetEmpty())];

	// Description widget
	const TSharedPtr<SHorizontalBox> DescriptionWidget = SNew(SHorizontalBox)
															 .Clipping(EWidgetClipping::OnDemand);

	DescriptionWidget->AddSlot()
		.VAlign(VAlign_Center)
		.Padding(6, 0)
			[SNew(STextBlock)
					.Font(FAppStyle::Get().GetFontStyle(TEXT("PropertyWindow.NormalFont")))
					.ColorAndOpacity(FSlateColor::UseStyle())
					.Text(Rule != nullptr ? Rule->GetDescription() : FText::GetEmpty())];

	// Button widget. There are two buttons slots that are customised based on section
	const TSharedPtr<SHorizontalBox> ButtonWidget = SNew(SHorizontalBox);

	ButtonWidget->AddSlot()
		.Padding(FMargin(6, 3, 3, 3))
			[SNew(SButton)
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					.Text(LOCTEXT("ApplyRule", "Apply"))
					.Visibility_Lambda([bShouldHideApplyButton]() -> EVisibility { return bShouldHideApplyButton ? EVisibility::Hidden : EVisibility::Visible; })
					.OnClicked(this, &SOculusXRProjectSetupToolWidget::OnApplyRuleClicked, Rule)
					.IsEnabled_Static(&SOculusXRProjectSetupToolWidget::OnApplyRuleEnabled, Section)];

	FMenuBuilder EllipsisMenuBuilder(true, nullptr);

	const auto IgnoreButtonText = Section == ERulesSection::Ignored ? LOCTEXT("UnignoreRule", "Unignore") : LOCTEXT("IgnoreRule", "Ignore");
	const auto IgnoreButtonTooltip = Section == ERulesSection::Ignored ? LOCTEXT("UnignoreRule_Tooltip", "Unignore this rule") : LOCTEXT("IgnoreRule_Tooltip", "Ignore this rule");
	const FString SupportURL(TEXT("https://forums.oculusvr.com/developer"));

	EllipsisMenuBuilder.AddMenuEntry(
		IgnoreButtonText,
		IgnoreButtonTooltip,
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateRaw(this, &SOculusXRProjectSetupToolWidget::OnIgnoreRuleClicked, Rule, Section),
			FCanExecuteAction::CreateStatic(&SOculusXRProjectSetupToolWidget::OnIgnoreRuleEnabled, Section)));

	EllipsisMenuBuilder.AddMenuEntry(
		LOCTEXT("SupportButton", "Support"),
		LOCTEXT("SupportButton_ToolTip", "Get more information about this rule."),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Comment"),
		FUIAction(
			FExecuteAction::CreateLambda([SupportURL] { FPlatformProcess::LaunchURL(*SupportURL, nullptr, nullptr); }),
			FCanExecuteAction()));

	ButtonWidget->AddSlot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		.Padding(FMargin(4.f, 0.f, 8.f, 0.f))
			[SNew(SComboButton)
					.ContentPadding(0)
					.HasDownArrow(false)
					.Visibility_Lambda([bShouldHideApplyButton]() -> EVisibility { return bShouldHideApplyButton ? EVisibility::Hidden : EVisibility::Visible; })
					.ForegroundColor(FSlateColor::UseForeground())
					.ComboButtonStyle(FAppStyle::Get(), "SimpleComboButton")
					.AddMetaData<FTagMetaData>(FTagMetaData(TEXT("ViewOptions")))
					.MenuContent()
						[EllipsisMenuBuilder.MakeWidget()]
					.ButtonContent()
						[SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
								  .AutoWidth()
								  .HAlign(HAlign_Center)
									  [SNew(SImage)
											  .Image(FAppStyle::Get().GetBrush("PropertyWindow.Button_Ellipsis"))
											  .ColorAndOpacity(FSlateColor::UseForeground())]]];

	// Splitter so each row can contain Name | Description | Buttons
	const TSharedPtr<SSplitter> Splitter = SNew(SSplitter)
											   .Style(FAppStyle::Get(), "DetailsView.Splitter")
											   .PhysicalSplitterHandleSize(1.0f)
											   .HitDetectionSplitterHandleSize(5.0f);

	// Add the widgets to the splitter
	Splitter->AddSlot()
		.Value(ColumnSizeData->GetNameColumnWidth())
		.OnSlotResized(ColumnSizeData->GetOnNameColumnResized())
			[NameWidget.ToSharedRef()];

	Splitter->AddSlot()
		.Value(ColumnSizeData->GetValueColumnWidth())
		.OnSlotResized(ColumnSizeData->GetOnValueColumnResized())
			[DescriptionWidget.ToSharedRef()];

	Splitter->AddSlot()
		.Value(ColumnSizeData->GetRightColumnWidth())
		.OnSlotResized(ColumnSizeData->GetOnRightColumnResized())
		.MinSize(ColumnSizeData->GetRightColumnMinWidth())
			[ButtonWidget.ToSharedRef()];

	// Top level container for the whole row
	const TSharedPtr<SWidget> RowWidget = SNew(SBorder)
											  .BorderImage(FAppStyle::Get().GetBrush("DetailsView.CategoryMiddle"))
											  .BorderBackgroundColor(FAppStyle::Get().GetSlateColor("Colors.Panel"))
											  .Padding(0)
												  [Splitter.ToSharedRef()];

	// Add a slot into the content container for this item and add the row widget to it
	SectionContentContainer->AddSlot()
		.AutoHeight()
			[SNew(SBorder)
					.BorderImage(FAppStyle::Get().GetBrush("DetailsView.GridLine"))
					.Padding(FMargin(0, 0, 0, 1))
					.Clipping(EWidgetClipping::ClipToBounds)
					.Visibility(this, &SOculusXRProjectSetupToolWidget::OnRowVisibility, Section, PlatformFilters[CurrentPlatformFilterIndex], Rule)
						[SNew(SBox)
								.MinDesiredHeight(26.0f)
									[SNew(SHorizontalBox)
										+ SHorizontalBox::Slot()
											  .HAlign(HAlign_Fill)
											  .VAlign(VAlign_Fill)
												  [SNew(SBorder)
														  .BorderImage(FAppStyle::Get().GetBrush("DetailsView.Highlight"))
														  .Padding(0)
															  [SNew(SBorder)
																	  .BorderImage(FAppStyle::Get().GetBrush("DetailsView.CategoryMiddle"))
																	  .BorderBackgroundColor(FAppStyle::Get().GetSlateColor("Colors.Panel"))
																	  .Padding(0)
																		  [RowWidget.ToSharedRef()]]]]]];
}

/**
 * Build the layout for the required rules
 */
void SOculusXRProjectSetupToolWidget::BuildRequiredRulesSectionLayout(const TSharedPtr<SScrollBox>& RootContainer)
{
	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();

	if (RuleProcessorSubsystem == nullptr)
	{
		return;
	}

	const TSharedPtr<SVerticalBox> SectionContentContainer = BuildRulesContainerLayout(RootContainer, ERulesSection::Required, LOCTEXT("RequiredRules_Title", "Required Rules"));

	for (const auto& Rule : RuleProcessorSubsystem->GetRules())
	{
		if (Rule->GetSeverity() == ESetupRuleSeverity::Critical)
		{
			BuildRowItemLayout(SectionContentContainer, ERulesSection::Required, Rule, 0);
		}
	}
}

/**
 * Build the layout for the recommended rules
 */
void SOculusXRProjectSetupToolWidget::BuildRecommendedRulesSectionLayout(const TSharedPtr<SScrollBox>& RootContainer)
{
	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();

	if (RuleProcessorSubsystem == nullptr)
	{
		return;
	}

	const TSharedPtr<SVerticalBox> SectionContentContainer = BuildRulesContainerLayout(RootContainer, ERulesSection::Recommended, LOCTEXT("RecommendedRules_Title", "Recommended Rules"));

	for (const auto& Rule : RuleProcessorSubsystem->GetRules())
	{
		if (Rule->GetSeverity() < ESetupRuleSeverity::Critical)
		{
			BuildRowItemLayout(SectionContentContainer, ERulesSection::Recommended, Rule, 0);
		}
	}
}

/**
 * Build the layout for the applied rules
 */
void SOculusXRProjectSetupToolWidget::BuildAppliedRulesSectionLayout(const TSharedPtr<SScrollBox>& RootContainer)
{
	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();

	if (RuleProcessorSubsystem == nullptr)
	{
		return;
	}

	const TSharedPtr<SVerticalBox> SectionContentContainer = BuildRulesContainerLayout(RootContainer, ERulesSection::Applied, LOCTEXT("AppliedRules_Title", "Applied Rules"));

	// Add all rules and let the visibility function take care of which ones to show

	for (const auto& Rule : RuleProcessorSubsystem->GetRules())
	{
		BuildRowItemLayout(SectionContentContainer, ERulesSection::Applied, Rule, 0);
	}
}

/**
 * Build the layout for the ignored rules
 */
void SOculusXRProjectSetupToolWidget::BuildIgnoredRulesSectionLayout(const TSharedPtr<SScrollBox>& RootContainer)
{
	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();

	if (RuleProcessorSubsystem == nullptr)
	{
		return;
	}

	const TSharedPtr<SVerticalBox> SectionContentContainer = BuildRulesContainerLayout(RootContainer, ERulesSection::Ignored, LOCTEXT("IgnoredRules_Title", "Ignored Rules"));

	// Add all rules and let the visibility function take care of which ones to show

	for (const auto& Rule : RuleProcessorSubsystem->GetRules())
	{
		BuildRowItemLayout(SectionContentContainer, ERulesSection::Ignored, Rule, 0);
	}
}

/**
 * Is an un-applied rule visible?
 */
EVisibility SOculusXRProjectSetupToolWidget::OnRowVisibility(ERulesSection Section, ESetupRulePlatform CurrentPlatform, SetupRulePtr Rule) const
{
	if (Section == ERulesSection::Filter)
	{
		return EVisibility::Visible;
	}

	if (!BIsSectionExpanded[static_cast<uint32>(Section)])
	{
		return EVisibility::Collapsed;
	}

	if (Rule == nullptr)
	{
		return EVisibility::Collapsed;
	}

	if (!Rule->IsValid())
	{
		return EVisibility::Collapsed;
	}

	if ((Rule->GetPlatform() & CurrentPlatform) != CurrentPlatform)
	{
		return EVisibility::Collapsed;
	}

	switch (Section)
	{
		case ERulesSection::Required:
		case ERulesSection::Recommended:
		{
			if (Rule->IsApplied())
			{
				return EVisibility::Collapsed;
			}

			return Rule->IsIgnored() ? EVisibility::Collapsed : EVisibility::Visible;
		}

		case ERulesSection::Applied:
		{
			return Rule->IsApplied() ? EVisibility::Visible : EVisibility::Collapsed;
		}

		case ERulesSection::Ignored:
		{
			// Applied rules always show in the Applied section even if ignored

			if (Rule->IsApplied())
			{
				return EVisibility::Collapsed;
			}

			return Rule->IsIgnored() ? EVisibility::Visible : EVisibility::Collapsed;
		}

		default:
		{
			break;
		}
	}

	return EVisibility::Collapsed;
}

EVisibility SOculusXRProjectSetupToolWidget::OnRestartEditorNoticeVisibility() const
{
	return bShowButtonToRestart ? EVisibility::Visible : EVisibility::Collapsed;
}

FReply SOculusXRProjectSetupToolWidget::OnRestartEditorButtonClicked()
{
	bShowButtonToRestart = false;
	FUnrealEdMisc::Get().RestartEditor(false);
	return FReply::Handled();
}

void SOculusXRProjectSetupToolWidget::Refresh()
{
	UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();

	if (RuleProcessorSubsystem != nullptr)
	{
		RuleProcessorSubsystem->Refresh();
	}
}

void SOculusXRProjectSetupToolWidget::UpdateActiveTimer(bool Register)
{
	if (!Register)
	{
		if (!ActiveTimerHandle.IsValid())
		{
			return;
		}
		UnRegisterActiveTimer(ActiveTimerHandle.Pin().ToSharedRef());
		return;
	}

	if (ActiveTimerHandle.IsValid())
	{
		UnRegisterActiveTimer(ActiveTimerHandle.Pin().ToSharedRef());
	}

	ActiveTimerHandle = RegisterActiveTimer(
		30.f,
		FWidgetActiveTimerDelegate::CreateLambda([this](double /*InCurrentTime*/, float /*InDeltaTime*/) {
			Refresh();
			UpdateProjectStatus();
			return EActiveTimerReturnType::Continue;
		}));
}

/**
 * Apply a new platform filter
 */
FReply SOculusXRProjectSetupToolWidget::OnPlatformFilterChanged(ESetupRulePlatform ItemSelected)
{
	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();

	if (RuleProcessorSubsystem == nullptr)
	{
		return FReply::Handled();
	}

	const int32 Index = PlatformFilters.Find(ItemSelected);

	if (Index != INDEX_NONE)
	{
		CurrentPlatformFilterIndex = Index;
		GetMutableDefault<UOculusXRPSTSettings>()->CurrentPlatform = static_cast<uint32>(ItemSelected);
		BuildLayout(RootContainerWidget);
	}

	return FReply::Handled();
}

/**
 * Apply rule button callback
 */
FReply SOculusXRProjectSetupToolWidget::OnApplyRuleClicked(SetupRulePtr Rule)
{
	if (Rule == nullptr)
	{
		return FReply::Handled();
	}
	bool bShouldRestartEditor = false;
	Rule->Apply(bShouldRestartEditor);
	bShowButtonToRestart |= bShouldRestartEditor;
	UpdateProjectStatus();
	return FReply::Handled();
}

/**
 * Apply rule enabled callback
 */
bool SOculusXRProjectSetupToolWidget::OnApplyRuleEnabled(ERulesSection Section)
{
	return Section != ERulesSection::Applied && Section != ERulesSection::Ignored;
}

/**
 * Ignore/Unignore rule button callback
 */
void SOculusXRProjectSetupToolWidget::OnIgnoreRuleClicked(SetupRulePtr Rule, ERulesSection Section)
{
	if (Rule == nullptr)
	{
		return;
	}

	if (Section != ERulesSection::Ignored)
	{
		Rule->SetIgnoreRule(true);
	}
	else
	{
		Rule->SetIgnoreRule(false);
	}

	UpdateProjectStatus();
}

/**
 * Apply rule button callback
 */
FReply SOculusXRProjectSetupToolWidget::OnApplyAllRulesClicked(ERulesSection Section)
{
	bool bShouldRestartEditor = false;

	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();

	for (auto& Rule : RuleProcessorSubsystem->GetRules())
	{
		// Only apply rules that are critical and are in the required section or non-critical and are in the recommended section
		bool bShouldApplyRule = Rule->GetSeverity() == ESetupRuleSeverity::Critical && Section == ERulesSection::Required;
		bShouldApplyRule = bShouldApplyRule || Rule->GetSeverity() != ESetupRuleSeverity::Critical && Section == ERulesSection::Recommended;
		// Only apply rules that in the current platform
		bShouldApplyRule = bShouldApplyRule && (Rule->GetPlatform() & PlatformFilters[CurrentPlatformFilterIndex]) == PlatformFilters[CurrentPlatformFilterIndex];
		// Only apply rules that are valid
		bShouldApplyRule = bShouldApplyRule && Rule->IsValid();
		// Only apply rules that are not applied yet
		bShouldApplyRule = bShouldApplyRule && !Rule->IsApplied();
		// Only apply rules that are not ignored
		bShouldApplyRule = bShouldApplyRule && !Rule->IsIgnored();
		if (!bShouldApplyRule)
		{
			continue;
		}

		Rule->Apply(bShouldRestartEditor);
		bShowButtonToRestart |= bShouldRestartEditor;
	}

	UpdateProjectStatus();

	return FReply::Handled();
}

/**
 * Apply rule enabled callback
 */
bool SOculusXRProjectSetupToolWidget::OnApplyAllRulesEnabled(ERulesSection Section) const
{
	switch (Section)
	{
		case ERulesSection::Required:
			return RuleStatus.PendingRequiredRulesCount > 0;
		case ERulesSection::Recommended:
			return RuleStatus.PendingRecommendedRulesCount > 0;
		default:
			return false;
	}
}

/**
 * Ignore rule enabled callback
 */
bool SOculusXRProjectSetupToolWidget::OnIgnoreRuleEnabled(ERulesSection Section)
{
	return Section != ERulesSection::Applied;
}

/**
 * Expander visibility
 */
EVisibility SOculusXRProjectSetupToolWidget::OnHeaderExpanderVisibility(ERulesSection Section)
{
	return Section == ERulesSection::Filter ? EVisibility::Collapsed : EVisibility::Visible;
}

/**
 * Expander image
 */
const FSlateBrush* SOculusXRProjectSetupToolWidget::GetHeaderExpanderImage(ERulesSection Section) const
{
	const bool bIsHeaderExpanded = BIsSectionExpanded[static_cast<uint32>(Section)];

	FName ResourceName;
	if (bIsHeaderExpanded)
	{
		static const FName ExpandedName = "TreeArrow_Expanded";
		ResourceName = ExpandedName;
	}
	else
	{
		static const FName CollapsedName = "TreeArrow_Collapsed";
		ResourceName = CollapsedName;
	}

	return FAppStyle::Get().GetBrush(ResourceName);
}

/**
 * Expander clicked
 */
FReply SOculusXRProjectSetupToolWidget::OnHeaderExpanderClicked(ERulesSection Section)
{
	const uint8 index = static_cast<uint8>(Section);
	BIsSectionExpanded[index] = !BIsSectionExpanded[index];
	return FReply::Handled();
}

void SOculusXRProjectSetupToolWidget::UpdateProjectStatus()
{
	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();

	if (RuleProcessorSubsystem != nullptr)
	{
		RuleStatus = RuleProcessorSubsystem->UnAppliedRulesStatus(PlatformFilters[CurrentPlatformFilterIndex]);
	}

	UpdateProjectStatusString();
}

/**
 * Build the project status string
 */
void SOculusXRProjectSetupToolWidget::UpdateProjectStatusString() const
{
	if (ProjectStatusWidget == nullptr)
	{
		return;
	}

	FString Status;

	if (RuleStatus.PendingRequiredRulesCount == 0 && RuleStatus.PendingRecommendedRulesCount == 0)
	{
		Status = TEXT("Current Project Status: All rules have been applied");
	}
	else if (RuleStatus.PendingRequiredRulesCount == 0)
	{
		Status = FString::Printf(TEXT("Current Project Status: There are %d recommended rules to apply"), RuleStatus.PendingRecommendedRulesCount);
	}
	else if (RuleStatus.PendingRecommendedRulesCount == 0)
	{
		Status = FString::Printf(TEXT("Current Project Status: There are %d required rules to apply"), RuleStatus.PendingRequiredRulesCount);
	}
	else
	{
		Status = FString::Printf(TEXT("Current Project Status: There are %d required rules and %d recommended rules to apply"), RuleStatus.PendingRequiredRulesCount, RuleStatus.PendingRecommendedRulesCount);
	}

	ProjectStatusWidget->SetText(FText::FromString(Status));
}

#undef LOCTEXT_NAMESPACE
