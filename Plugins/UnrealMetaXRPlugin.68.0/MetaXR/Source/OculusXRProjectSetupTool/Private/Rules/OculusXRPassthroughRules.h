// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once
#include "OculusXRSetupRule.h"

/*
 * Collection of rules related to passthrough. Can be extended as needed
 */
namespace OculusXRPassthroughRules
{
	class FEnablePassthroughRule final : public ISetupRule
	{
	public:
		FEnablePassthroughRule()
			: ISetupRule(
				  "Feature_EnablePassthrough",
				  NSLOCTEXT("OculusXRPassthroughRules", "EnablePassthrough_DisplayName", "Enable Passthrough"),
				  NSLOCTEXT("OculusXRPassthroughRules", "EnablePassthrough_Description", "Passthrough must be enabled when using passthrough features"),
				  ESetupRuleCategory::Features,
				  ESetupRuleSeverity::Critical) {}
		virtual bool IsApplied() const override;
		virtual bool IsValid() override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FAllowAlphaToneMapperPassthroughRule final : public ISetupRule
	{
	public:
		FAllowAlphaToneMapperPassthroughRule()
			: ISetupRule(
				  "Feature_AllowAlphaToneMapperPassthrough",
				  NSLOCTEXT("OculusXRPassthroughRules", "AllowAlphaToneMapperPassthrough_DisplayName", "Enable passing alpha channel through tonemapper"),
				  NSLOCTEXT("OculusXRPassthroughRules", "AllowAlphaToneMapperPassthrough_Description", "For passthrough to work over Link alpha channel must be passed through tonemapper."),
				  ESetupRuleCategory::Features,
				  ESetupRuleSeverity::Warning) {}
		virtual bool IsApplied() const override;
		virtual bool IsValid() override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	inline TArray<SetupRulePtr> PassthroughRules_Table{
		MakeShared<FEnablePassthroughRule>(),
		MakeShared<FAllowAlphaToneMapperPassthroughRule>()
	};
} // namespace OculusXRPassthroughRules
