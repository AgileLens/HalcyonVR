// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "OculusXRSetupRule.h"

// Collection of rules related to rendering. Can be extended as needed
namespace OculusXRRenderingRules
{
	class FUseVulkanRule final : public ISetupRule
	{
	public:
		FUseVulkanRule()
			: ISetupRule("Rendering_UseVulkan",
				  NSLOCTEXT("OculusXRRenderingRules", "UseVulkan_DisplayName", "Use Vulkan Rendering Backend"),
				  NSLOCTEXT("OculusXRRenderingRules", "UseVulkan_Description", "Oculus recommends using Vulkan as the rendering backend for all mobile apps."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  MetaQuest_All) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FUseHalfPrecisionFloatRule final : public ISetupRule
	{
	public:
		FUseHalfPrecisionFloatRule()
			: ISetupRule("Rendering_UseHalfPrecisionFloat",
				  NSLOCTEXT("OculusXRRenderingRules", "UseHalfPrecisionFloat_DisplayName", "Use Half Precision Float"),
				  NSLOCTEXT("OculusXRRenderingRules", "UseHalfPrecisionFloat_Description", "Half precision float provides increased shader performance."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  MetaQuest_All) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnableInstancedStereoRule final : public ISetupRule
	{
	public:
		FEnableInstancedStereoRule()
			: ISetupRule("Rendering_EnableInstancedStereo",
				  NSLOCTEXT("OculusXRRenderingRules", "EnableInstancedStereo_DisplayName", "Enable Instanced Stereo"),
				  NSLOCTEXT("OculusXRRenderingRules", "EnableInstancedStereo_Description", "Instanced stereo substantially reduces draw calls, and improves rendering performance."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  ESetupRulePlatform::MetaLink) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnableForwardShadingRule final : public ISetupRule
	{
	public:
		FEnableForwardShadingRule()
			: ISetupRule("Rendering_EnableForwardShading",
				  NSLOCTEXT("OculusXRRenderingRules", "EnableForwardShading_DisplayName", "Enable Forward Shading"),
				  NSLOCTEXT("OculusXRRenderingRules", "EnableForwardShading_Description", "Forward shading is often better suited for VR rendering."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  ESetupRulePlatform::MetaQuest_2) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnablePCForwardShadingRule final : public ISetupRule
	{
	public:
		FEnablePCForwardShadingRule()
			: ISetupRule("Rendering_EnablePCForwardShading",
				  NSLOCTEXT("OculusXRRenderingRules", "EnablePCForwardShading_DisplayName", "Enable PC Forward Shading"),
				  NSLOCTEXT("OculusXRRenderingRules", "EnablePCForwardShading_Description", "Forward shading is often better suited for VR rendering."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  ESetupRulePlatform::MetaLink) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnableMSAARule final : public ISetupRule
	{
	public:
		FEnableMSAARule()
			: ISetupRule("Rendering_EnableMSAA",
				  NSLOCTEXT("OculusXRRenderingRules", "EnableMSAA_DisplayName", "Enable MSAA"),
				  NSLOCTEXT("OculusXRRenderingRules", "EnableMSAA_Description", "MSAA provides higher quality antialiasing at a reasonable cost."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  MetaQuest_All) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnableOcclusionCullingRule final : public ISetupRule
	{
	public:
		FEnableOcclusionCullingRule()
			: ISetupRule("Rendering_EnableOcclusionCulling",
				  NSLOCTEXT("OculusXRRenderingRules", "EnableOcclusionCulling_DisplayName", "Enable Occlusion Culling"),
				  NSLOCTEXT("OculusXRRenderingRules", "EnableOcclusionCulling_Description", "Occlusion culling can provide significant performance gains."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnableDynamicFoveationRule final : public ISetupRule
	{
	public:
		FEnableDynamicFoveationRule()
			: ISetupRule("Rendering_EnableDynamicFoveation",
				  NSLOCTEXT("OculusXRRenderingRules", "EnableDynamicFoveation_DisplayName", "Enable Dynamic Foveation"),
				  NSLOCTEXT("OculusXRRenderingRules", "EnableDynamicFoveation_Description", "Dynamic foveated rendering significantly reduces rendering cost."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  MetaQuest_All) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

#ifdef WITH_OCULUS_BRANCH
	class FEnableDynamicResolutionRule final : public ISetupRule
	{
	public:
		FEnableDynamicResolutionRule()
			: ISetupRule("Rendering_EnableDynamicResolution",
				  NSLOCTEXT("OculusXRRenderingRules", "EnableDynamicResolution_DisplayName", "Enable Dynamic Resolution"),
				  NSLOCTEXT("OculusXRRenderingRules", "EnableDynamicResolution_Description", "Dynamic resolution rendering significantly reduces rendering cost."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  MetaQuest_All) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnableMobileUniformLocalLightsRule final : public ISetupRule
	{
	public:
		FEnableMobileUniformLocalLightsRule()
			: ISetupRule("Rendering_MobileUniformLocalLights",
				  NSLOCTEXT("OculusXRRenderingRules", "MobileUniformLocalLights_DisplayName", "Enable MobileUniformLocalLights"),
				  NSLOCTEXT("OculusXRRenderingRules", "MobileUniformLocalLights_Description", "MobileUniformLocalLights is recommended for Meta Quest devices."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  MetaQuest_All) {}

		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};
#endif

	class FDisableLensFlareRule final : public ISetupRule
	{
	public:
		FDisableLensFlareRule()
			: ISetupRule("Rendering_DisableLensFlare",
				  NSLOCTEXT("OculusXRRenderingRules", "DisableLensFlare_DisplayName", "Disable Lens Flare"),
				  NSLOCTEXT("OculusXRRenderingRules", "DisableLensFlare_Description", "Lens flare can be expensive and exhibit visible artifacts in VR."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FDisablePostProcessingRule final : public ISetupRule
	{
	public:
		FDisablePostProcessingRule()
			: ISetupRule("Rendering_DisablePostProcessing",
				  NSLOCTEXT("OculusXRRenderingRules", "DisablePostProcessing_DisplayName", "Disable Post Processing"),
				  NSLOCTEXT("OculusXRRenderingRules", "DisablePostProcessing_Description", "Mobile HDR has performance and stability issues in VR. We strongly recommend disabling it."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  MetaQuest_All) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FDisableAmbientOcclusionRule final : public ISetupRule
	{
	public:
		FDisableAmbientOcclusionRule()
			: ISetupRule("Rendering_DisableAmbientOcclusion",
				  NSLOCTEXT("OculusXRRenderingRules", "DisableAmbientOcclusion_DisplayName", "Disable Ambient Occlusion"),
				  NSLOCTEXT("OculusXRRenderingRules", "DisableAmbientOcclusion_Description", "Ambient occlusion has performance issues. We recommend disabling it."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  MetaQuest_All) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnableMultiViewRule final : public ISetupRule
	{
	public:
		FEnableMultiViewRule()
			: ISetupRule("Rendering_EnableMultiView",
				  NSLOCTEXT("OculusXRRenderingRules", "EnableMultiView_DisplayName", "Enable Mobile Multiveiw"),
				  NSLOCTEXT("OculusXRRenderingRules", "EnableMultiView_Description", "Enable mobile multi-view and direct mobile multi-view to significantly reduce CPU overhead."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  MetaQuest_All) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FEnableStaticLightingRule final : public ISetupRule
	{
	public:
		FEnableStaticLightingRule()
			: ISetupRule("Rendering_EnableStaticLighting",
				  NSLOCTEXT("OculusXRRenderingRules", "EnableStaticLighting_DisplayName", "Enable Static Lighting"),
				  NSLOCTEXT("OculusXRRenderingRules", "EnableStaticLighting_Description", "Static lighting should be disallowed only if project is intended to be 100% dynamically lit."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  All_Platforms) {}
		virtual bool IsApplied() const override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FDisableMobileShaderStaticAndCSMShadowReceiversRule final : public ISetupRule
	{
	public:
		FDisableMobileShaderStaticAndCSMShadowReceiversRule()
			: ISetupRule(
				  "Rendering_MobileShaderStaticAndCSMShadowReceivers",
				  NSLOCTEXT("OculusXRRenderingRules", "MobileShaderStaticAndCSMShadowReceivers_DisplayName", "Disable Support Combined Static and CSM Shadowing"),
				  NSLOCTEXT("OculusXRRenderingRules", "MobileShaderStaticAndCSMShadowReceivers_Description", "The project does not contain any stationary lights. Support Combined Static and CSM Shadowing can be disabled to reduce shader permutations."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance) {}

		virtual bool IsApplied() const override;
		virtual bool IsValid() override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FDisableMobileShaderAllowDistanceFieldShadowsRule final : public ISetupRule
	{
	public:
		FDisableMobileShaderAllowDistanceFieldShadowsRule()
			: ISetupRule("Rendering_MobileShaderAllowDistanceFieldShadows",
				  NSLOCTEXT("OculusXRRenderingRules", "MobileShaderAllowDistanceFieldShadows_DisplayName", "Disable Support Support Distance Field Shadows"),
				  NSLOCTEXT("OculusXRRenderingRules", "MobileShaderAllowDistanceFieldShadows_Description", "The project does not contain any stationary lights. Support Support Distance Field Shadows can be disabled to reduce shader permutations."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  MetaQuest_All) {}

		virtual bool IsApplied() const override;
		virtual bool IsValid() override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FDisableMobileShaderAllowMovableDirectionalLightsRule final : public ISetupRule
	{
	public:
		FDisableMobileShaderAllowMovableDirectionalLightsRule()
			: ISetupRule("Rendering_MobileShaderAllowMovableDirectionalLights",
				  NSLOCTEXT("OculusXRRenderingRules", "MobileShaderAllowMovableDirectionalLights_DisplayName", "Disable Support Movable Directional Lights"),
				  NSLOCTEXT("OculusXRRenderingRules", "MobileShaderAllowMovableDirectionalLights_Description", "The project does not contain any movable lights. Support Movable Directional Lights can be disabled to reduce shader permutations."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  MetaQuest_All) {}

		virtual bool IsApplied() const override;
		virtual bool IsValid() override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FDisableMobileGPUSceneRule final : public ISetupRule
	{
	public:
		FDisableMobileGPUSceneRule()
			: ISetupRule("Rendering_MobileGPUScene",
				  NSLOCTEXT("OculusXRRenderingRules", "MobileGPUSceneLights_DisplayName", "Disable Support GPUScene"),
				  NSLOCTEXT("OculusXRRenderingRules", "MobileGPUSceneLights_Description", "GPUScene is not recommended and might cause performance hit."),
				  ESetupRuleCategory::Rendering,
				  ESetupRuleSeverity::Performance,
				  MetaQuest_All) {}

		virtual bool IsApplied() const override;
		virtual bool IsValid() override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;
	};

	class FUseAndroidVulkanPreviewPlatform final : public ISetupRule
	{
	public:
		FUseAndroidVulkanPreviewPlatform();
		virtual bool IsApplied() const override;
		virtual bool IsValid() override;

	protected:
		virtual void ApplyImpl(bool& OutShouldRestartEditor) override;

	private:
		FPreviewPlatformInfo AndroidVulkanPreview;
	};

	// All defined rendering rules. Add new rules to this table for them to be auto-registered
	inline TArray<SetupRulePtr> RenderingRules_Table{
		MakeShared<FUseVulkanRule>(),
		MakeShared<FUseHalfPrecisionFloatRule>(),
		MakeShared<FEnableInstancedStereoRule>(),
		MakeShared<FEnableForwardShadingRule>(),
		MakeShared<FEnablePCForwardShadingRule>(),
		MakeShared<FEnableMSAARule>(),
		MakeShared<FEnableOcclusionCullingRule>(),
		MakeShared<FEnableDynamicFoveationRule>(),
#ifdef WITH_OCULUS_BRANCH
		MakeShared<FEnableDynamicResolutionRule>(),
		MakeShared<FEnableMobileUniformLocalLightsRule>(),
#endif
		MakeShared<FDisableLensFlareRule>(),
		MakeShared<FDisablePostProcessingRule>(),
		MakeShared<FDisableAmbientOcclusionRule>(),
		MakeShared<FEnableMultiViewRule>(),
		MakeShared<FEnableStaticLightingRule>(),
		MakeShared<FDisableMobileShaderStaticAndCSMShadowReceiversRule>(),
		MakeShared<FDisableMobileShaderAllowDistanceFieldShadowsRule>(),
		MakeShared<FDisableMobileShaderAllowMovableDirectionalLightsRule>(),
		MakeShared<FDisableMobileGPUSceneRule>(),
		MakeShared<FUseAndroidVulkanPreviewPlatform>()
	};
} // namespace OculusXRRenderingRules
