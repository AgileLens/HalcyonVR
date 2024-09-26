// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"

#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Layout/SScrollBox.h"

class FActiveTimerHandle;
/**
 * Slate widget for the tutorial
 */
class SOculusXRTutorialWindow : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SOculusXRTutorialWindow) {}
	SLATE_END_ARGS()

	/** Construct the slate layout for the widget */
	void Construct(const FArguments& InArgs);

private:
	/** Build the guided tutorial layout */
	void BuildGuidedTutorialLayout(const TSharedPtr<SVerticalBox>& RootContainer);

	FReply OnPreviousClicked();
	bool OnPreviousEnabled() const;

	FReply OnNextClicked();
	bool OnNextEnabled() const;

	FReply OnSkipClicked() const;

	const FSlateBrush* GetPaginationImageForIndex(int32 PageIndex) const;

	void AddTutorialPage1(const TSharedPtr<SVerticalBox>& TextWidget) const;
	void AddTutorialPage2(const TSharedPtr<SVerticalBox>& TextWidget) const;
	void AddTutorialPage3(const TSharedPtr<SVerticalBox>& TextWidget) const;

	/** Root container */
	TSharedPtr<SVerticalBox> RootContainerWidget{};

	/** Current tutorial page */
	int32 GuidedTutorialPageIndex = 0;
};
