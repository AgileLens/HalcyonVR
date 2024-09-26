// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"

#include "DetailColumnSizeData.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Layout/SScrollBox.h"
#include "OculusXRRuleProcessorSubsystem.h"

class FActiveTimerHandle;
/**
 * Slate widget for the Project Setup Tool main tab
 */
class SOculusXRProjectSetupToolWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SOculusXRProjectSetupToolWidget) {}
	SLATE_END_ARGS()

	/** Construct the slate layout for the widget */

	void Construct(const FArguments& InArgs);

private:
	enum class ERulesSection : uint8
	{
		Filter,
		Required,
		Recommended,
		Applied,
		Ignored
	};

	/** Build the main layout */
	void BuildLayout(const TSharedPtr<SVerticalBox>& RootContainer);

	/** Build the title section layout*/
	void BuildTitleSectionLayout(const TSharedPtr<SVerticalBox>& RootContainer);

	/** Build the filter section layout */
	void BuildFilterSectionLayout(const TSharedPtr<SVerticalBox>& RootContainer, const uint32 PlatformFilterIndex);

	/** Build a container for a rules section */
	TSharedPtr<SVerticalBox> BuildRulesContainerLayout(const TSharedPtr<SScrollBox>& RootContainer, ERulesSection Section, const FText& SectionTitle);

	/** Build a single rules item */
	void BuildRowItemLayout(const TSharedPtr<SVerticalBox>& SectionContentContainer, ERulesSection Section, const SetupRulePtr& Rule, const uint32 PlatformFilterIndex);

	/** Build the rules section layouts */
	void BuildRequiredRulesSectionLayout(const TSharedPtr<SScrollBox>& RootContainer);
	void BuildRecommendedRulesSectionLayout(const TSharedPtr<SScrollBox>& RootContainer);
	void BuildAppliedRulesSectionLayout(const TSharedPtr<SScrollBox>& RootContainer);
	void BuildIgnoredRulesSectionLayout(const TSharedPtr<SScrollBox>& RootContainer);

	/** Platform filter callbacks */
	FReply OnPlatformFilterChanged(ESetupRulePlatform ItemSelected);

	/** Button handling callbacks */
	FReply OnApplyRuleClicked(SetupRulePtr Rule);
	static bool OnApplyRuleEnabled(ERulesSection Section);

	FReply OnApplyAllRulesClicked(ERulesSection Section);
	bool OnApplyAllRulesEnabled(ERulesSection Section) const;

	void OnIgnoreRuleClicked(SetupRulePtr Rule, ERulesSection Section);
	static bool OnIgnoreRuleEnabled(ERulesSection Section);

	/** Rule visibility callback  */
	EVisibility OnRowVisibility(ERulesSection Section, ESetupRulePlatform CurrentPlatform, SetupRulePtr Rule) const;

	/** Expander callbacks */
	const FSlateBrush* GetHeaderExpanderImage(ERulesSection Section) const;
	static EVisibility OnHeaderExpanderVisibility(ERulesSection Section);
	FReply OnHeaderExpanderClicked(ERulesSection Section);

	/** Restart Editor Notice Visibility */
	EVisibility OnRestartEditorNoticeVisibility() const;
	/** Restart Editor Button Clicked */
	FReply OnRestartEditorButtonClicked();

	/** Perform refresh */
	static void Refresh();

	/** Register/Unregister timer */
	void UpdateActiveTimer(bool Register);

	/** Update the status of rules */
	void UpdateProjectStatus();

	/** Update the status string */
	void UpdateProjectStatusString() const;

	/** Root container */
	TSharedPtr<SVerticalBox> RootContainerWidget{};

	/** Column size data */
	TSharedPtr<FDetailColumnSizeData> ColumnSizeData{};

	/** Platform filter  */
	TArray<ESetupRulePlatform> PlatformFilters{};
	uint32 CurrentPlatformFilterIndex{};

	/** Active timer handle */
	TWeakPtr<FActiveTimerHandle> ActiveTimerHandle;

	/** Restart pending after rule application */
	bool bShowButtonToRestart = false;

	/** Expanded/collapsed state for each section */
	TArray<bool> BIsSectionExpanded{ true, true, true, true, true };

	/** Status string */
	TSharedPtr<STextBlock> ProjectStatusWidget;

	/** Rules status */
	UOculusXRRuleProcessorSubsystem::RuleStatus RuleStatus{};
};
