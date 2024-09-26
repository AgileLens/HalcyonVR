// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"

#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"

/**
 * Slate widget for the widget used to show any outstanding issues in the status bar
 */
class SOculusXRStatusBarWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SOculusXRStatusBarWidget) {}
	SLATE_END_ARGS()

	/** Construct the slate layout for the widget */

	void Construct(const FArguments& InArgs);

private:
	/**
	 * Determine the correct image to use
	 */
	static const FSlateBrush* GetDotImage();
};
