// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRProjectTutorialWidget.h"

#include "OculusXRProjectSetupToolModule.h"
#include "OculusXRPSTEvents.h"
#include "OculusXRPSTSettings.h"
#include "OculusXRTelemetry.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Input/SButton.h"
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleMacros.h"

#define LOCTEXT_NAMESPACE "OculusXRProjectTutorialWidget"

static constexpr int32 NumTutorialPages = 3;

/**
 * Construct the layout for the project setup tool tab
 *
 * @param InArgs [in] the arguments associated with this tool
 */
void SOculusXRTutorialWindow::Construct(const FArguments& InArgs)
{
	// Construct the layout
	RootContainerWidget = SNew(SVerticalBox);

	BuildGuidedTutorialLayout(RootContainerWidget);

	ChildSlot
		[SNew(SBox)
				.WidthOverride(1080)
				.HeightOverride(600)
					[RootContainerWidget.ToSharedRef()]];
}

/**
 * Build the guided tutorial layout
 */
void SOculusXRTutorialWindow::BuildGuidedTutorialLayout(const TSharedPtr<SVerticalBox>& RootContainer)
{
	// Construct the row of buttons
	const TSharedPtr<SHorizontalBox> PreviousNextWidget = SNew(SHorizontalBox);

	PreviousNextWidget->AddSlot()
		.AutoWidth()
			[SNew(SButton)
					.OnClicked(this, &SOculusXRTutorialWindow::OnPreviousClicked)
					.IsEnabled(this, &SOculusXRTutorialWindow::OnPreviousEnabled)
					.Text(LOCTEXT("Previous", "Previous"))];

	PreviousNextWidget->AddSlot()
		.AutoWidth()
		.Padding(10, 0, 0, 0)
			[SNew(SButton)
					.OnClicked(this, &SOculusXRTutorialWindow::OnNextClicked)
					.IsEnabled(this, &SOculusXRTutorialWindow::OnNextEnabled)
					.Text(LOCTEXT("Next", "Next"))];

	const TSharedPtr<SHorizontalBox> SkipWidget = SNew(SHorizontalBox);

	SkipWidget->AddSlot()
		.AutoWidth()
			[SNew(SButton)
					.OnClicked(this, &SOculusXRTutorialWindow::OnSkipClicked)
					.ButtonStyle(&FAppStyle::Get().GetWidgetStyle<FButtonStyle>("PrimaryButton"))
					.Text_Lambda([this]() {
						if (GuidedTutorialPageIndex == NumTutorialPages - 1)
						{
							return LOCTEXT("Close", "Close");
						}
						return LOCTEXT("Skip", "Skip");
					})];

	const TSharedPtr<SHorizontalBox> PaginationWidget = SNew(SHorizontalBox);

	for (int i = 0; i < NumTutorialPages; ++i)
	{
		PaginationWidget->AddSlot()
			.Padding(4.0f, 0.0f)
				[SNew(SImage)
						.DesiredSizeOverride(FVector2D(8.0f, 8.0f))
						.Image_Raw(this, &SOculusXRTutorialWindow::GetPaginationImageForIndex, i)];
	}

	const TSharedPtr<SHorizontalBox> ButtonsWidget = SNew(SHorizontalBox);

	ButtonsWidget->AddSlot()
		.HAlign(HAlign_Left)
			[PreviousNextWidget.ToSharedRef()];

	ButtonsWidget->AddSlot()
		.Padding(0.0f, 7.0f)
		.HAlign(HAlign_Center)
			[PaginationWidget.ToSharedRef()];

	ButtonsWidget->AddSlot()
		.HAlign(HAlign_Right)
			[SkipWidget.ToSharedRef()];

	// Construct the text widget
	const TSharedPtr<SVerticalBox> TextWidget = SNew(SVerticalBox);
	AddTutorialPage1(TextWidget);
	AddTutorialPage2(TextWidget);
	AddTutorialPage3(TextWidget);

	// Construct the image panel
	const TSharedPtr<SOverlay> ImagePanel = SNew(SOverlay);

	ImagePanel->AddSlot()
		[SNew(SImage)
				.Image(FOculusXRProjectSetupToolModule::GetSlateStyle()->GetBrush("ProjectSetupTool.MetaQuestBackground"))];

	// Construct the instruction panel
	const TSharedPtr<SOverlay> InstructionsPanel = SNew(SOverlay);

	InstructionsPanel->AddSlot()
		[SNew(SVerticalBox)
			+ SVerticalBox::Slot()
				  .Padding(40)
				  .VAlign(VAlign_Center)
					  [TextWidget.ToSharedRef()]];

	InstructionsPanel->AddSlot()
		[SNew(SVerticalBox)
			+ SVerticalBox::Slot()
				  .Padding(40, 20)
				  .VAlign(VAlign_Bottom)
					  [ButtonsWidget.ToSharedRef()]];

	// Construct the main panel

	const TSharedPtr<SHorizontalBox> MainPanel = SNew(SHorizontalBox);

	MainPanel->AddSlot()
		[ImagePanel.ToSharedRef()];

	MainPanel->AddSlot()
		[InstructionsPanel.ToSharedRef()];

	// Add to the root container

	RootContainer->AddSlot()
		[MainPanel.ToSharedRef()];
}

/**
 * Previous button clicked
 */
FReply SOculusXRTutorialWindow::OnPreviousClicked()
{
	--GuidedTutorialPageIndex;

	if (GuidedTutorialPageIndex < 0)
	{
		GuidedTutorialPageIndex = 0;
	}

	const OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FProjectSetupToolPrev> Previous;
	const auto& Annotated = Previous
								.AddAnnotation(OculusXRTelemetry::Annotations::Value,
									TCHAR_TO_ANSI(*FString::FromInt(GuidedTutorialPageIndex)));

	return FReply::Handled();
}

/**
 * Previous button enabled
 */
bool SOculusXRTutorialWindow::OnPreviousEnabled() const
{
	return GuidedTutorialPageIndex > 0;
}

/**
 * Next button clicked
 */
FReply SOculusXRTutorialWindow::OnNextClicked()
{
	++GuidedTutorialPageIndex;

	if (GuidedTutorialPageIndex == NumTutorialPages - 1)
	{
		GetMutableDefault<UOculusXRPSTSettings>()->bGuidedTutorialComplete = true;
		GetMutableDefault<UOculusXRPSTSettings>()->SaveConfig();
	}
	const OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FProjectSetupToolNext> NextEvent;
	const auto& Annotated = NextEvent
								.AddAnnotation(OculusXRTelemetry::Annotations::Value,
									TCHAR_TO_ANSI(*FString::FromInt(GuidedTutorialPageIndex)));
	return FReply::Handled();
}

/**
 * Next button enabled
 */
bool SOculusXRTutorialWindow::OnNextEnabled() const
{
	return GuidedTutorialPageIndex < NumTutorialPages - 1;
}

/**
 * Skip button clicked
 */
FReply SOculusXRTutorialWindow::OnSkipClicked() const
{
	FSlateApplication::Get().FindWidgetWindow(AsShared())->RequestDestroyWindow();
	return FReply::Handled();
}

/**
 * Get the image to use for the pagination indicator
 */
const FSlateBrush* SOculusXRTutorialWindow::GetPaginationImageForIndex(int32 PageIndex) const
{
	if (PageIndex == GuidedTutorialPageIndex)
	{
		return FOculusXRProjectSetupToolModule::GetSlateStyle()->GetBrush("ProjectSetupTool.WhiteDot");
	}

	return FOculusXRProjectSetupToolModule::GetSlateStyle()->GetBrush("ProjectSetupTool.GreyDot");
}

void SOculusXRTutorialWindow::AddTutorialPage1(const TSharedPtr<SVerticalBox>& TextWidget) const
{
	TextWidget->AddSlot()
		.AutoHeight()
			[SNew(STextBlock)
					.AutoWrapText(true)
					.Font(DEFAULT_FONT("Regular", 24))
					.Visibility_Lambda([this]() { return GuidedTutorialPageIndex == 0 ? EVisibility::Visible : EVisibility::Collapsed; })
					.Text(LOCTEXT("Title1", "Welcome to the Meta XR Project Setup Tool"))];

	TextWidget->AddSlot()
		.AutoHeight()
		.Padding(0, 20, 0, 0)
			[SNew(STextBlock)
					.AutoWrapText(true)
					.Font(DEFAULT_FONT("Regular", 12))
					.Visibility_Lambda([this]() { return GuidedTutorialPageIndex == 0 ? EVisibility::Visible : EVisibility::Collapsed; })
					.Text(LOCTEXT("Body1",
						"The Unreal Project Setup Tool can help you quickly configure projects using the Meta XR Plugin. This tool guides you through the necessary steps so you can start developing faster. The Unreal Project Setup Tool tests a registry of rules called Configuration Tasks. We provide default rules to make your project Quest Ready."))];
}

void SOculusXRTutorialWindow::AddTutorialPage2(const TSharedPtr<SVerticalBox>& TextWidget) const
{

	TextWidget->AddSlot()
		.AutoHeight()
			[SNew(STextBlock)
					.AutoWrapText(true)
					.Font(DEFAULT_FONT("Regular", 24))
					.Visibility_Lambda([this]() { return GuidedTutorialPageIndex == 1 ? EVisibility::Visible : EVisibility::Collapsed; })
					.Text(LOCTEXT("Title2", "Here are the key things to know about Unreal Project Setup Tool"))];

	TextWidget->AddSlot()
		.AutoHeight()
		.Padding(0, 10, 0, 0)
			[SNew(STextBlock)
					.AutoWrapText(true)
					.Font(DEFAULT_FONT("Bold", 12))
					.Visibility_Lambda([this]() { return GuidedTutorialPageIndex == 1 ? EVisibility::Visible : EVisibility::Collapsed; })
					.Text(LOCTEXT("Body2.1", "Actions"))];
	TextWidget->AddSlot()
		.AutoHeight()
		.Padding(0, 3, 0, 0)
			[SNew(STextBlock)
					.AutoWrapText(true)
					.Font(DEFAULT_FONT("Regular", 12))
					.Visibility_Lambda([this]() { return GuidedTutorialPageIndex == 1 ? EVisibility::Visible : EVisibility::Collapsed; })
					.Text(LOCTEXT("Body2.2", "A Configuration Task is regularly checked for its validation. You can interact directly with a Task in the following ways."))];

	TextWidget->AddSlot()
		.AutoHeight()
		.Padding(0, 3, 0, 0)
			[SNew(STextBlock)
					.AutoWrapText(true)
					.Font(DEFAULT_FONT("Bold", 12))
					.Visibility_Lambda([this]() { return GuidedTutorialPageIndex == 1 ? EVisibility::Visible : EVisibility::Collapsed; })
					.Text(LOCTEXT("Body2.3", "Fix/Apply"))];

	TextWidget->AddSlot()
		.AutoHeight()
		.Padding(0, 3, 0, 0)
			[SNew(STextBlock)
					.AutoWrapText(true)
					.Font(DEFAULT_FONT("Regular", 12))
					.Visibility_Lambda([this]() { return GuidedTutorialPageIndex == 1 ? EVisibility::Visible : EVisibility::Collapsed; })
					.Text(LOCTEXT("Body2.3", "Manually call the fix delegate for this Task in order to resolve the issue. This action is only available for tasks that are not already validated."))];

	TextWidget->AddSlot()
		.AutoHeight()
		.Padding(0, 3, 0, 0)
			[SNew(STextBlock)
					.AutoWrapText(true)
					.Font(DEFAULT_FONT("Bold", 12))
					.Visibility_Lambda([this]() { return GuidedTutorialPageIndex == 1 ? EVisibility::Visible : EVisibility::Collapsed; })
					.Text(LOCTEXT("Body2.4", "Ignore / Unignore"))];

	TextWidget->AddSlot()
		.AutoHeight()
		.Padding(0, 3, 0, 0)
			[SNew(STextBlock)
					.AutoWrapText(true)
					.Font(DEFAULT_FONT("Regular", 12))
					.Visibility_Lambda([this]() { return GuidedTutorialPageIndex == 1 ? EVisibility::Visible : EVisibility::Collapsed; })
					.Text(LOCTEXT("Body2.5", "This moves the task to another category that will get ignored for both checks and fixes. This gives the control back to developers who may not want to be forced to follow some guidelines or even requirements in some specific cases."))];
}

void SOculusXRTutorialWindow::AddTutorialPage3(const TSharedPtr<SVerticalBox>& TextWidget) const
{
	TextWidget->AddSlot()
		.AutoHeight()
			[SNew(STextBlock)
					.AutoWrapText(true)
					.Font(DEFAULT_FONT("Bold", 24))
					.Visibility_Lambda([this]() { return GuidedTutorialPageIndex == 2 ? EVisibility::Visible : EVisibility::Collapsed; })
					.Text(LOCTEXT("Title3", "You’re good to go! Start developing faster with Unreal Project Setup Tool"))];

	TextWidget->AddSlot()
		.AutoHeight()
		.Padding(0, 20, 0, 0)
			[SNew(STextBlock)
					.AutoWrapText(true)
					.Font(DEFAULT_FONT("Regular", 12))
					.Visibility_Lambda([this]() { return GuidedTutorialPageIndex == 2 ? EVisibility::Visible : EVisibility::Collapsed; })
					.Text(LOCTEXT("Body3", "You can check Unreal Project Setup Tool from the Tools menu bar, Meta XR Plugin Settings Page or from the Meta icon on the bottom bar. The tool proactively checks for configuration changes."))];
}
#undef LOCTEXT_NAMESPACE
