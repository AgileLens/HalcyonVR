// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Misc/EngineVersionComparison.h"

#include "VariableRateShadingImageManager.h"
#include "XRSwapchain.h"

class FOculusXRFoveatedRenderingImageGenerator : public IVariableRateShadingImageGenerator
{
public:
	FOculusXRFoveatedRenderingImageGenerator(const FXRSwapChainPtr& Swapchain);
	virtual ~FOculusXRFoveatedRenderingImageGenerator() override;

	// IVariableRateShadingImageGenerator interface
#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	virtual FRDGTextureRef GetImage(
		FRDGBuilder& GraphBuilder,
		const FViewInfo& ViewInfo,
		FVariableRateShadingImageManager::EVRSImageType ImageType,
		bool bGetSoftwareImage = false) override;
#else
	virtual FRDGTextureRef GetImage(
		FRDGBuilder& GraphBuilder,
		const FViewInfo& ViewInfo,
		FVariableRateShadingImageManager::EVRSImageType ImageType) override;
#endif

#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	virtual void PrepareImages(
		FRDGBuilder& GraphBuilder,
		const FSceneViewFamily& ViewFamily,
		const FMinimalSceneTextures& SceneTextures,
		bool bPrepareHardwareImages,
		bool bPrepareSoftwareImages) override
	{
		return;
	}
#else
	virtual void PrepareImages(
		FRDGBuilder& GraphBuilder,
		const FSceneViewFamily& ViewFamily,
		const FMinimalSceneTextures& SceneTextures) override
	{
		return;
	}
#endif

#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	virtual bool IsEnabled() const override
	{
		return true;
	};
#endif

#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	virtual bool IsSupportedByView(const FSceneView& View) const override;
#else
	virtual bool IsEnabledForView(const FSceneView& View) const override;
#endif

#if !UE_VERSION_OLDER_THAN(5, 4, 0)
	virtual FRDGTextureRef GetDebugImage(
		FRDGBuilder& GraphBuilder,
		const FViewInfo& ViewInfo,
		FVariableRateShadingImageManager::EVRSImageType ImageType,
		bool bGetSoftwareImage = false) override;
#else
	virtual FRDGTextureRef GetDebugImage(
		FRDGBuilder& GraphBuilder,
		const FViewInfo& ViewInfo,
		FVariableRateShadingImageManager::EVRSImageType ImageType) override;
#endif

	virtual FVariableRateShadingImageManager::EVRSSourceType GetType() const override
	{
		return FVariableRateShadingImageManager::EVRSSourceType::FixedFoveation;
	}

private:
	const FXRSwapChainPtr& FoveationSwapchain;
};
