// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OculusXRHMDPrivate.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS
#include "DefaultSpectatorScreenController.h"

class UTextureRenderTarget2D;

namespace OculusXRHMD
{

	// Oculus specific spectator screen modes that override the regular VR spectator screens
	enum class EMRSpectatorScreenMode : uint8
	{
		Default,
		ExternalComposition,
		DirectComposition
	};

	//-------------------------------------------------------------------------------------------------
	// FSpectatorScreenController
	//-------------------------------------------------------------------------------------------------

	class FSpectatorScreenController : public FDefaultSpectatorScreenController
	{
	public:
		FSpectatorScreenController(class FOculusXRHMD* InOculusXRHMD);

		void SetMRSpectatorScreenMode(EMRSpectatorScreenMode Mode) { SpectatorMode = Mode; }
		void SetMRForeground(UTextureRenderTarget2D* Texture) { ForegroundRenderTexture = Texture; }
		void SetMRBackground(UTextureRenderTarget2D* Texture) { BackgroundRenderTexture = Texture; }

		virtual void RenderSpectatorScreen_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture2D* BackBuffer, FTexture2DRHIRef RenderTarget, FVector2D WindowSize) override;
		virtual void RenderSpectatorModeUndistorted(FRHICommandListImmediate& RHICmdList, FTexture2DRHIRef TargetTexture, FTexture2DRHIRef EyeTexture, FTexture2DRHIRef OtherTexture, FVector2D WindowSize) override;
		virtual void RenderSpectatorModeDistorted(FRHICommandListImmediate& RHICmdList, FTexture2DRHIRef TargetTexture, FTexture2DRHIRef EyeTexture, FTexture2DRHIRef OtherTexture, FVector2D WindowSize) override;
		virtual void RenderSpectatorModeSingleEye(FRHICommandListImmediate& RHICmdList, FTexture2DRHIRef TargetTexture, FTexture2DRHIRef EyeTexture, FTexture2DRHIRef OtherTexture, FVector2D WindowSize) override;

	private:
		FOculusXRHMD* OculusXRHMD;
		EMRSpectatorScreenMode SpectatorMode;
		UTextureRenderTarget2D* ForegroundRenderTexture;
		UTextureRenderTarget2D* BackgroundRenderTexture;

		void RenderSpectatorModeDirectComposition(FRHICommandListImmediate& RHICmdList, FTexture2DRHIRef TargetTexture, const FTexture2DRHIRef SrcTexture) const;
		void RenderSpectatorModeExternalComposition(FRHICommandListImmediate& RHICmdList, FTexture2DRHIRef TargetTexture, const FTexture2DRHIRef FrontTexture, const FTexture2DRHIRef BackTexture) const;
	};

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
