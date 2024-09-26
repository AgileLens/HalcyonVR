// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once
#include "OculusXRSetupRule.h"

/*
 * Collection of rules related to anchors. Can be extended as needed
 */
namespace OculusXRAnchorsRules
{
	class FEnableAnchorSupportRule final : public ISetupRule
	{
	public:
		FEnableAnchorSupportRule()
			: ISetupRule(
				  "Feature_EnableAnchorSupport",
				  NSLOCTEXT("OculusXRAnchorsRules", "EnableAnchorSupport_DisplayName", "Enable Anchor Support"),
				  NSLOCTEXT("OculusXRAnchorsRules", "EnableAnchorSupport_Description", "Anchor support must be enabled when using anchor features"),
				  ESetupRuleCategory::Features,
				  ESetupRuleSeverity::Critical) {}
		virtual bool IsApplied() const override;
		virtual bool IsValid() override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnableSceneSupportRule final : public ISetupRule
	{
	public:
		FEnableSceneSupportRule()
			: ISetupRule(
				  "Feature_EnableSceneSupport",
				  NSLOCTEXT("OculusXRAnchorsRules", "EnableSceneSupport_DisplayName", "Enable Scene Support"),
				  NSLOCTEXT("OculusXRAnchorsRules", "EnableSceneSupport_Description", "Scene support must be enabled when using scene features"),
				  ESetupRuleCategory::Features,
				  ESetupRuleSeverity::Critical) {}
		virtual bool IsApplied() const override;
		virtual bool IsValid() override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	inline TArray<SetupRulePtr> AnchorRules_Table{
		MakeShared<FEnableAnchorSupportRule>(),
		MakeShared<FEnableSceneSupportRule>()
	};
} // namespace OculusXRAnchorsRules
