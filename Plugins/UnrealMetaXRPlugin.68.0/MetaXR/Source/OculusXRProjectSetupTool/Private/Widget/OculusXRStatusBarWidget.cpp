// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRStatusBarWidget.h"

#include "OculusXRProjectSetupToolModule.h"
#include "OculusXRRuleProcessorSubsystem.h"

#define LOCTEXT_NAMESPACE "OculusXRStatusBarWidget"

/**
 * Construct the layout for the status bar widget
 *
 * @param InArgs [in] the arguments associated with this tool
 */
void SOculusXRStatusBarWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
		[SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
				[SNew(SButton)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						.ButtonStyle(FAppStyle::Get(), "SimpleButton")
						.ToolTipText(LOCTEXT("StatusBarWidget_Tooltip", "Launch Meta XR Project Setup tool"))
						.OnClicked_Lambda([]() -> FReply {
							IOculusXRProjectSetupToolModule::Get().ShowProjectSetupTool("Toolbar");
							return FReply::Handled();
						})
						.ContentPadding(0)
							[SNew(SOverlay)
								+ SOverlay::Slot()
									[SNew(SHorizontalBox)
										+ SHorizontalBox::Slot()
											  .AutoWidth()
												  [SNew(SImage)
														  .Image(FOculusXRProjectSetupToolModule::GetSlateStyle()->GetBrush("ProjectSetupTool.MetaLogo"))
														  .DesiredSizeOverride(FVector2D(22.0f, 22.0f))]]
								+ SOverlay::Slot()
									[SNew(SHorizontalBox)
										+ SHorizontalBox::Slot()
											  .AutoWidth()
											  .Padding(16, 4, -2, 10)
												  [SNew(SImage)
														  .Image_Static(SOculusXRStatusBarWidget::GetDotImage)
														  .DesiredSizeOverride(FVector2D(8.0f, 8.0f))]]]]];
}

/**
 * Determine the correct image to use
 */
const FSlateBrush* SOculusXRStatusBarWidget::GetDotImage()
{
	const UOculusXRRuleProcessorSubsystem* RuleProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();

	if (RuleProcessorSubsystem == nullptr)
	{
		return FOculusXRProjectSetupToolModule::GetSlateStyle()->GetBrush("ProjectSetupTool.GreenDot");
	}

	const auto& RuleStatus = RuleProcessorSubsystem->UnAppliedRulesStatus(MetaQuest_All);

	if (RuleStatus.PendingRequiredRulesCount > 0)
	{
		return FOculusXRProjectSetupToolModule::GetSlateStyle()->GetBrush("ProjectSetupTool.RedDot");
	}

	if (RuleStatus.PendingRecommendedRulesCount > 0)
	{
		return FOculusXRProjectSetupToolModule::GetSlateStyle()->GetBrush("ProjectSetupTool.YellowDot");
	}

	return FOculusXRProjectSetupToolModule::GetSlateStyle()->GetBrush("ProjectSetupTool.GreenDot");
}

#undef LOCTEXT_NAMESPACE
