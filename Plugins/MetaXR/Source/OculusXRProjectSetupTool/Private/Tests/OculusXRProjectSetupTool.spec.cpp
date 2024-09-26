// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "Misc/AutomationTest.h"
#include "OculusXRRuleProcessorSubsystem.h"
#include "OculusXRSetupRule.h"
#include "Rules/OculusXRAnchorsRules.h"
#include "Rules/OculusXRCompatibilityRules.h"
#include "Rules/OculusXRMovementRules.h"
#include "Rules/OculusXRPassthroughRules.h"
#include "Rules/OculusXRPluginRules.h"
#include "Rules/OculusXRRenderingRules.h"

namespace
{
	const char* TestRule_Id = "test_id";
	const FText TestRule_DisName = FText::FromString("Test Display");
	const FText TestRule_Desc = FText::FromString("Test Desc");
} // namespace

BEGIN_DEFINE_SPEC(FOculusXRProjectSetupToolSpec, TEXT("Project Setup Tool"), EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
UOculusXRRuleProcessorSubsystem* ProcessorSubsystem;
bool bShouldRestartEditor = false;
TSet<FName> RulesThatRequireRestart = {
	FName("Feature_AllowAlphaToneMapperPassthrough"),
	FName("Rendering_DisableAmbientOcclusion"),
	FName("Rendering_DisablePostProcessing"),
	FName("Rendering_EnableForwardShading"),
	FName("Rendering_EnablePCForwardShading"),
	FName("Rendering_EnableInstancedStereo"),
	FName("Rendering_EnableMultiView"),
	FName("Rendering_EnableStaticLighting"),
	FName("Rendering_MobileShaderAllowDistanceFieldShadows"),
	FName("Rendering_MobileShaderAllowMovableDirectionalLights"),
	FName("Rendering_MobileGPUScene"),
	FName("Rendering_MobileUniformLocalLights"),
	FName("Rendering_UseHalfPrecisionFloat")
};

void Setup();
END_DEFINE_SPEC(FOculusXRProjectSetupToolSpec)

void FOculusXRProjectSetupToolSpec::Setup()
{
	BeforeEach([this] {
		ProcessorSubsystem = GEngine->GetEngineSubsystem<UOculusXRRuleProcessorSubsystem>();
		bShouldRestartEditor = false;
	});
}

class FMockRule : public ISetupRule
{
public:
	FMockRule()
		: ISetupRule(TestRule_Id, TestRule_DisName, TestRule_Desc, ESetupRuleCategory::Miscellaneous, ESetupRuleSeverity::Warning)
	{
	}

	virtual bool IsApplied() const override
	{
		return bIsApplied;
	}

protected:
	virtual void ApplyImpl(bool& ShouldRestartEditor) override
	{
		bIsApplied = true;
	}

private:
	bool bIsApplied = false;
};

void FOculusXRProjectSetupToolSpec::Define()
{
	Describe(TEXT("Rule Processor"), [this] {
		Setup();

		It(TEXT("Rule registered and unregistered successfully"), [this] {
			const auto RuleNum = ProcessorSubsystem->GetRules().Num();
			const SetupRulePtr mockRule = MakeShared<FMockRule>();
			TestTrue(TEXT("Rule added"), ProcessorSubsystem->RegisterRule(mockRule));
			TestEqual(TEXT("After rule is added"), ProcessorSubsystem->GetRules().Num(), RuleNum + 1);

			TestTrue(TEXT("Rule removed"), ProcessorSubsystem->UnregisterRule(mockRule));
			TestEqual(TEXT("After rule is removed"), ProcessorSubsystem->GetRules().Num(), RuleNum);
		});

		It(TEXT("Rule applied"), [this] {
			const SetupRulePtr mockRule = MakeShared<FMockRule>();

			// apply rule
			TestFalse(TEXT("Rule is not applied yet"), mockRule->IsApplied());
			mockRule->Apply(bShouldRestartEditor);

			TestTrue(TEXT("Rule applied"), mockRule->IsApplied());
		});

		It(TEXT("Rule ignored"), [this] {
			const SetupRulePtr mockRule = MakeShared<FMockRule>();
			// ignore rule
			TestFalse(TEXT("Rule is not ignored yet"), mockRule->IsIgnored());
			mockRule->SetIgnoreRule(true);
			TestTrue(TEXT("Rule ignored"), mockRule->IsIgnored());
		});
	});

	Describe(TEXT("Rendering rules"), [this] {
		for (auto Rule : OculusXRRenderingRules::RenderingRules_Table)
		{
			It(TEXT("Test " + Rule->GetId().ToString()), [this, Rule] {
				Rule->Apply(bShouldRestartEditor);
				TestTrue(TEXT("Rule is applied"), Rule->IsApplied());
				TestEqual(TEXT("Restart is pending"), RulesThatRequireRestart.Contains(Rule->GetId()), bShouldRestartEditor);
			});
		}
	});

	Describe(TEXT("Plugin rules"), [this] {
		for (auto Rule : OculusXRPluginRules::PluginRules_Table)
		{
			It(TEXT("Test " + Rule->GetId().ToString()), [this, Rule] {
				Rule->Apply(bShouldRestartEditor);
				TestTrue(TEXT("Rule is applied"), Rule->IsApplied());
				TestEqual(TEXT("Restart is pending"), RulesThatRequireRestart.Contains(Rule->GetId()), bShouldRestartEditor);
			});
		}
	});

	Describe(TEXT("Compatibility rules"), [this] {
		for (auto Rule : OculusXRCompatibilityRules::CompatibilityRules_Table)
		{
			It(TEXT("Test " + Rule->GetId().ToString()), [this, Rule] {
				Rule->Apply(bShouldRestartEditor);
				TestTrue(TEXT("Rule is applied"), Rule->IsApplied());
				TestEqual(TEXT("Restart is pending"), RulesThatRequireRestart.Contains(Rule->GetId()), bShouldRestartEditor);
			});
		}
	});

	Describe(TEXT("Anchor rules"), [this] {
		for (auto Rule : OculusXRAnchorsRules::AnchorRules_Table)
		{
			It(TEXT("Test " + Rule->GetId().ToString()), [this, Rule] {
				Rule->Apply(bShouldRestartEditor);
				TestTrue(TEXT("Rule is applied"), Rule->IsApplied());
				TestEqual(TEXT("Restart is pending"), RulesThatRequireRestart.Contains(Rule->GetId()), bShouldRestartEditor);
			});
		}
	});

	Describe(TEXT("Movement rules"), [this] {
		for (auto Rule : OculusXRMovementRules::MovementRules_Table)
		{
			It(TEXT("Test " + Rule->GetId().ToString()), [this, Rule] {
				Rule->Apply(bShouldRestartEditor);
				TestTrue(TEXT("Rule is applied"), Rule->IsApplied());
				TestEqual(TEXT("Restart is pending"), RulesThatRequireRestart.Contains(Rule->GetId()), bShouldRestartEditor);
			});
		}
	});

	Describe(TEXT("Passthrough rules"), [this] {
		for (auto Rule : OculusXRPassthroughRules::PassthroughRules_Table)
		{
			It(TEXT("Test " + Rule->GetId().ToString()), [this, Rule] {
				Rule->Apply(bShouldRestartEditor);
				TestTrue(TEXT("Rule is applied"), Rule->IsApplied());
				TestEqual(TEXT("Restart is pending"), RulesThatRequireRestart.Contains(Rule->GetId()), bShouldRestartEditor);
			});
		}
	});
}
