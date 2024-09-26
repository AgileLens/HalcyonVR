// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRHMD_FoveatedRendering.h"

#include "HeadMountedDisplayTypes.h" // For the LogHMD log category
#include "RenderGraphBuilder.h"
#include "SceneView.h"
#include "StereoRendering.h"

FOculusXRFoveatedRenderingImageGenerator::FOculusXRFoveatedRenderingImageGenerator(const FXRSwapChainPtr& Swapchain)
	: FoveationSwapchain(Swapchain)
{
	GVRSImageManager.RegisterExternalImageGenerator(this);
}

FOculusXRFoveatedRenderingImageGenerator::~FOculusXRFoveatedRenderingImageGenerator()
{
	GVRSImageManager.UnregisterExternalImageGenerator(this);
}

#if !UE_VERSION_OLDER_THAN(5, 4, 0)
FRDGTextureRef FOculusXRFoveatedRenderingImageGenerator::GetImage(
	FRDGBuilder& GraphBuilder,
	const FViewInfo& ViewInfo,
	FVariableRateShadingImageManager::EVRSImageType ImageType, bool bGetSoftwareImage)
#else
FRDGTextureRef FOculusXRFoveatedRenderingImageGenerator::GetImage(
	FRDGBuilder& GraphBuilder,
	const FViewInfo& ViewInfo,
	FVariableRateShadingImageManager::EVRSImageType ImageType)
#endif
{
	if (!FoveationSwapchain.IsValid())
	{
		return nullptr;
	}

	FTexture2DRHIRef SwapchainTexture = FoveationSwapchain->GetTexture2DArray() ? FoveationSwapchain->GetTexture2DArray() : FoveationSwapchain->GetTexture2D();
	FIntPoint TexSize = SwapchainTexture->GetSizeXY();
	// Only set texture and return true if we have a valid texture of compatible size
	if (SwapchainTexture->IsValid() && TexSize.X > 0 && TexSize.Y > 0)
	{
		TRefCountPtr<IPooledRenderTarget> PooledRenderTarget = CreateRenderTarget(SwapchainTexture, *SwapchainTexture->GetName().ToString());
		return GraphBuilder.RegisterExternalTexture(PooledRenderTarget, *SwapchainTexture->GetName().ToString(), ERDGTextureFlags::SkipTracking);
	}
	return nullptr;
}

#if !UE_VERSION_OLDER_THAN(5, 4, 0)
bool FOculusXRFoveatedRenderingImageGenerator::IsSupportedByView(const FSceneView& View) const
#else
bool FOculusXRFoveatedRenderingImageGenerator::IsEnabledForView(const FSceneView& View) const
#endif
{
	return View.StereoPass != EStereoscopicPass::eSSP_FULL;
}

#if !UE_VERSION_OLDER_THAN(5, 4, 0)
FRDGTextureRef FOculusXRFoveatedRenderingImageGenerator::GetDebugImage(
	FRDGBuilder& GraphBuilder,
	const FViewInfo& ViewInfo,
	FVariableRateShadingImageManager::EVRSImageType ImageType,
	bool bGetSoftwareImage)

#else
FRDGTextureRef FOculusXRFoveatedRenderingImageGenerator::GetDebugImage(
	FRDGBuilder& GraphBuilder,
	const FViewInfo& ViewInfo,
	FVariableRateShadingImageManager::EVRSImageType ImageType)
#endif
{
	return nullptr;
}
