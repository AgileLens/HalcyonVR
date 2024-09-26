// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRHMD_CustomPresent.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS
#include "OculusXRHMD.h"
#include "ScreenRendering.h"
#include "PipelineStateCache.h"
#include "ClearQuad.h"
#include "OculusShaders.h"
#include "CommonRenderResources.h"
#include "RHIStaticStates.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidEGL.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidPlatformMisc.h"
#endif

#define VULKAN_CUBEMAP_POSITIVE_Y 2
#define VULKAN_CUBEMAP_NEGATIVE_Y 3

namespace OculusXRHMD
{
	/**
	 * A pixel shader for rendering a textured screen element with mip maps and array slice.
	 */
	class FScreenPSMipLevelArray : public FGlobalShader
	{
		DECLARE_SHADER_TYPE(FScreenPSMipLevelArray, Global);

	public:
		static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters) { return true; }

		FScreenPSMipLevelArray(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
			: FGlobalShader(Initializer)
		{
			InTexture.Bind(Initializer.ParameterMap, TEXT("InTexture"), SPF_Mandatory);
			InTextureSampler.Bind(Initializer.ParameterMap, TEXT("InTextureSampler"));
			InMipLevelParameter.Bind(Initializer.ParameterMap, TEXT("MipLevel"));
			InArraySliceParameter.Bind(Initializer.ParameterMap, TEXT("ArraySlice"));
		}
		FScreenPSMipLevelArray() {}

		void SetParameters(FRHIBatchedShaderParameters& BatchedParameters, const FTexture* Texture, int ArraySlice, int MipLevel)
		{
			SetTextureParameter(BatchedParameters, InTexture, InTextureSampler, Texture);
			SetShaderValue(BatchedParameters, InMipLevelParameter, MipLevel);
			SetShaderValue(BatchedParameters, InArraySliceParameter, ArraySlice);
		}

		void SetParameters(FRHIBatchedShaderParameters& BatchedParameters, FRHISamplerState* SamplerStateRHI, FRHITexture* TextureRHI, int ArraySlice, int MipLevel)
		{
			SetTextureParameter(BatchedParameters, InTexture, InTextureSampler, SamplerStateRHI, TextureRHI);
			SetShaderValue(BatchedParameters, InMipLevelParameter, MipLevel);
			SetShaderValue(BatchedParameters, InArraySliceParameter, ArraySlice);
		}

	private:
		LAYOUT_FIELD(FShaderResourceParameter, InTexture);
		LAYOUT_FIELD(FShaderResourceParameter, InTextureSampler);
		LAYOUT_FIELD(FShaderParameter, InMipLevelParameter);
		LAYOUT_FIELD(FShaderParameter, InArraySliceParameter);
	};
	IMPLEMENT_SHADER_TYPE(, FScreenPSMipLevelArray, TEXT("/Plugin/OculusXR/Private/ScreenPixelShaderArraySlice.usf"), TEXT("MainMipLevel"), SF_Pixel);

	/**
	 * A pixel shader for rendering a textured screen element with mip maps and array slice.
	 */
	class FScreenPSsRGBSourceMipLevelArray : public FGlobalShader
	{
		DECLARE_SHADER_TYPE(FScreenPSsRGBSourceMipLevelArray, Global);

	public:
		static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters) { return true; }

		FScreenPSsRGBSourceMipLevelArray(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
			: FGlobalShader(Initializer)
		{
			InTexture.Bind(Initializer.ParameterMap, TEXT("InTexture"), SPF_Mandatory);
			InTextureSampler.Bind(Initializer.ParameterMap, TEXT("InTextureSampler"));
			InMipLevelParameter.Bind(Initializer.ParameterMap, TEXT("MipLevel"));
			InArraySliceParameter.Bind(Initializer.ParameterMap, TEXT("ArraySlice"));
		}
		FScreenPSsRGBSourceMipLevelArray() {}

		void SetParameters(FRHIBatchedShaderParameters& BatchedParameters, const FTexture* Texture, int ArraySlice, int MipLevel)
		{
			SetTextureParameter(BatchedParameters, InTexture, InTextureSampler, Texture);
			SetShaderValue(BatchedParameters, InMipLevelParameter, MipLevel);
			SetShaderValue(BatchedParameters, InArraySliceParameter, ArraySlice);
		}

		void SetParameters(FRHIBatchedShaderParameters& BatchedParameters, FRHISamplerState* SamplerStateRHI, FRHITexture* TextureRHI, int ArraySlice, int MipLevel)
		{
			SetTextureParameter(BatchedParameters, InTexture, InTextureSampler, SamplerStateRHI, TextureRHI);
			SetShaderValue(BatchedParameters, InMipLevelParameter, MipLevel);
			SetShaderValue(BatchedParameters, InArraySliceParameter, ArraySlice);
		}

	private:
		LAYOUT_FIELD(FShaderResourceParameter, InTexture);
		LAYOUT_FIELD(FShaderResourceParameter, InTextureSampler);
		LAYOUT_FIELD(FShaderParameter, InMipLevelParameter);
		LAYOUT_FIELD(FShaderParameter, InArraySliceParameter);
	};
	IMPLEMENT_SHADER_TYPE(, FScreenPSsRGBSourceMipLevelArray, TEXT("/Plugin/OculusXR/Private/ScreenPixelShaderArraySlice.usf"), TEXT("MainsRGBSourceMipLevel"), SF_Pixel);

	//-------------------------------------------------------------------------------------------------
	// FCustomPresent
	//-------------------------------------------------------------------------------------------------

	FCustomPresent::FCustomPresent(class FOculusXRHMD* InOculusXRHMD, ovrpRenderAPIType InRenderAPI, EPixelFormat InDefaultPixelFormat, bool bInSupportsSRGB)
		: OculusXRHMD(InOculusXRHMD)
		, RenderAPI(InRenderAPI)
		, DefaultPixelFormat(InDefaultPixelFormat)
		, bSupportsSRGB(bInSupportsSRGB)
		, bSupportsSubsampled(false)
		, bIsStandaloneStereoDevice(false)
	{
		CheckInGameThread();

		DefaultOvrpTextureFormat = GetOvrpTextureFormat(GetDefaultPixelFormat());
		DefaultDepthOvrpTextureFormat = ovrpTextureFormat_None;

#if PLATFORM_ANDROID
		bIsStandaloneStereoDevice = FAndroidMisc::GetDeviceMake() == FString("Oculus");
#endif

		// grab a pointer to the renderer module for displaying our mirror window
		static const FName RendererModuleName("Renderer");
		RendererModule = FModuleManager::GetModulePtr<IRendererModule>(RendererModuleName);
	}

	void FCustomPresent::ReleaseResources_RHIThread()
	{
		CheckInRHIThread();

		if (MirrorTextureRHI.IsValid())
		{
			FOculusXRHMDModule::GetPluginWrapper().DestroyMirrorTexture2();
			MirrorTextureRHI = nullptr;
		}
	}

	void FCustomPresent::Shutdown()
	{
		CheckInGameThread();

		// OculusXRHMD is going away, but this object can live on until viewport is destroyed
		ExecuteOnRenderThread([this]() {
			ExecuteOnRHIThread([this]() {
				OculusXRHMD = nullptr;
			});
		});
	}

	bool FCustomPresent::NeedsNativePresent()
	{
		return !bIsStandaloneStereoDevice;
	}

	bool FCustomPresent::Present(int32& SyncInterval)
	{
		CheckInRHIThread();

		if (OculusXRHMD)
		{
			FGameFrame* Frame_RHIThread = OculusXRHMD->GetFrame_RHIThread();
			if (Frame_RHIThread)
			{
				FinishRendering_RHIThread();
			}
		}

		SyncInterval = 0; // VSync off

		return NeedsNativePresent();
	}

	void FCustomPresent::UpdateMirrorTexture_RenderThread()
	{
		SCOPE_CYCLE_COUNTER(STAT_BeginRendering);

		CheckInRenderThread();

		const ESpectatorScreenMode MirrorWindowMode = OculusXRHMD->GetSpectatorScreenMode_RenderThread();
		const FIntPoint MirrorWindowSize = OculusXRHMD->GetFrame_RenderThread()->WindowSize;

		if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized())
		{
			// Need to destroy mirror texture?
			if (MirrorTextureRHI.IsValid())
			{
				const auto MirrorTextureSize = FIntPoint(MirrorTextureRHI->GetDesc().Extent.X, MirrorTextureRHI->GetDesc().Extent.Y);
				if (MirrorWindowMode != ESpectatorScreenMode::Distorted || MirrorWindowSize != MirrorTextureSize)
				{
					ExecuteOnRHIThread([]() {
						FOculusXRHMDModule::GetPluginWrapper().DestroyMirrorTexture2();
					});

					MirrorTextureRHI = nullptr;
				}
			}

			// Need to create mirror texture?
			if (!MirrorTextureRHI.IsValid() && MirrorWindowMode == ESpectatorScreenMode::Distorted && MirrorWindowSize.X != 0 && MirrorWindowSize.Y != 0)
			{
				const int Width = MirrorWindowSize.X;
				const int Height = MirrorWindowSize.Y;
				ovrpTextureHandle TextureHandle;

				ExecuteOnRHIThread([&]() {
					FOculusXRHMDModule::GetPluginWrapper().SetupMirrorTexture2(GetOvrpDevice(), Height, Width, GetDefaultOvrpTextureFormat(), &TextureHandle);
				});

				UE_LOG(LogHMD, Log, TEXT("Allocated a new mirror texture (size %d x %d)"), Width, Height);

				ETextureCreateFlags TexCreateFlags = TexCreate_ShaderResource | TexCreate_RenderTargetable;

				MirrorTextureRHI = CreateTexture_RenderThread(Width, Height, GetDefaultPixelFormat(), FClearValueBinding::None, 1, 1, 1, RRT_Texture2D, TextureHandle, TexCreateFlags)->GetTexture2D();
			}
		}
	}

	void FCustomPresent::FinishRendering_RHIThread()
	{
		SCOPE_CYCLE_COUNTER(STAT_FinishRendering);
		CheckInRHIThread();

#if STATS
		if (OculusXRHMD->GetFrame_RHIThread()->ShowFlags.Rendering)
		{
			ovrpAppLatencyTimings AppLatencyTimings;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetAppLatencyTimings2(&AppLatencyTimings)))
			{
				SET_FLOAT_STAT(STAT_LatencyRender, AppLatencyTimings.LatencyRender * 1000.0f);
				SET_FLOAT_STAT(STAT_LatencyTimewarp, AppLatencyTimings.LatencyTimewarp * 1000.0f);
				SET_FLOAT_STAT(STAT_LatencyPostPresent, AppLatencyTimings.LatencyPostPresent * 1000.0f);
				SET_FLOAT_STAT(STAT_ErrorRender, AppLatencyTimings.ErrorRender * 1000.0f);
				SET_FLOAT_STAT(STAT_ErrorTimewarp, AppLatencyTimings.ErrorTimewarp * 1000.0f);
			}
		}
#endif

		OculusXRHMD->FinishRHIFrame_RHIThread();

#if PLATFORM_ANDROID
		float GPUFrameTime = 0.0f;
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetGPUFrameTime(&GPUFrameTime)))
		{
			SubmitGPUFrameTime(GPUFrameTime);
		}
#endif
	}

	EPixelFormat FCustomPresent::GetPixelFormat(EPixelFormat Format) const
	{
		switch (Format)
		{
				//	case PF_B8G8R8A8:
			case PF_FloatRGBA:
			case PF_FloatR11G11B10:
				//	case PF_R8G8B8A8:
			case PF_G16:
			case PF_R16F:
			case PF_R32_FLOAT:
			case PF_ShadowDepth:
			case PF_D24:
				return Format;
		}

		return GetDefaultPixelFormat();
	}

	EPixelFormat FCustomPresent::GetPixelFormat(ovrpTextureFormat Format) const
	{
		switch (Format)
		{
				//		case ovrpTextureFormat_R8G8B8A8_sRGB:
				//		case ovrpTextureFormat_R8G8B8A8:
				//			return PF_R8G8B8A8;
			case ovrpTextureFormat_R16G16B16A16_FP:
				return PF_FloatRGBA;
			case ovrpTextureFormat_R11G11B10_FP:
				return PF_FloatR11G11B10;
				//		case ovrpTextureFormat_B8G8R8A8_sRGB:
				//		case ovrpTextureFormat_B8G8R8A8:
				//			return PF_B8G8R8A8;
			case ovrpTextureFormat_R16:
				return PF_G16; // G stands for grey here, not green, and is actually R16 in RHI
			case ovrpTextureFormat_R16_FP:
				return PF_R16F;
			case ovrpTextureFormat_R32_FP:
				return PF_R32_FLOAT;
			case ovrpTextureFormat_D16:
				return PF_ShadowDepth; // ShadowDepth maps to D16 in Vulkan
			case ovrpTextureFormat_D24_S8:
				return PF_D24;
		}

		return GetDefaultPixelFormat();
	}

	ovrpTextureFormat FCustomPresent::GetOvrpTextureFormat(EPixelFormat Format, bool usesRGB) const
	{
		switch (GetPixelFormat(Format))
		{
			case PF_B8G8R8A8:
				return bSupportsSRGB && usesRGB ? ovrpTextureFormat_B8G8R8A8_sRGB : ovrpTextureFormat_B8G8R8A8;
			case PF_FloatRGBA:
				return ovrpTextureFormat_R16G16B16A16_FP;
			case PF_FloatR11G11B10:
				return ovrpTextureFormat_R11G11B10_FP;
			case PF_R8G8B8A8:
				return bSupportsSRGB && usesRGB ? ovrpTextureFormat_R8G8B8A8_sRGB : ovrpTextureFormat_R8G8B8A8;
			case PF_G16:
				return ovrpTextureFormat_R16;
			case PF_R16F:
				return ovrpTextureFormat_R16_FP;
			case PF_R32_FLOAT:
				return ovrpTextureFormat_R32_FP;
			case PF_ShadowDepth:
				return ovrpTextureFormat_D16;
			case PF_D24:
				return ovrpTextureFormat_D24_S8;
		}

		return ovrpTextureFormat_None;
	}

	bool FCustomPresent::IsSRGB(ovrpTextureFormat InFormat)
	{
		switch (InFormat)
		{
			case ovrpTextureFormat_B8G8R8A8_sRGB:
			case ovrpTextureFormat_R8G8B8A8_sRGB:
				return true;
		}

		return false;
	}

	int FCustomPresent::GetSystemRecommendedMSAALevel() const
	{
		int SystemRecommendedMSAALevel = 1;
		FOculusXRHMDModule::GetPluginWrapper().GetSystemRecommendedMSAALevel2(&SystemRecommendedMSAALevel);
		return SystemRecommendedMSAALevel;
	}

	FXRSwapChainPtr FCustomPresent::CreateSwapChain_RenderThread(uint32 InSizeX, uint32 InSizeY, EPixelFormat InFormat, FClearValueBinding InBinding, uint32 InNumMips, uint32 InNumSamples, uint32 InNumSamplesTileMem, ERHIResourceType InResourceType, const TArray<ovrpTextureHandle>& InTextures, ETextureCreateFlags InTexCreateFlags, const TCHAR* DebugName)
	{
		TArray<FTextureRHIRef> RHITextureSwapChain = CreateSwapChainTextures_RenderThread(InSizeX, InSizeY, InFormat, InBinding, InNumMips, InNumSamples, InNumSamplesTileMem, InResourceType, InTextures, InTexCreateFlags, DebugName);

		FTextureRHIRef RHITexture = GDynamicRHI->RHICreateAliasedTexture(RHITextureSwapChain[0]);

		return CreateXRSwapChain(MoveTemp(RHITextureSwapChain), RHITexture);
	}

	TArray<FTextureRHIRef> FCustomPresent::CreateSwapChainTextures_RenderThread(uint32 InSizeX, uint32 InSizeY, EPixelFormat InFormat, FClearValueBinding InBinding, uint32 InNumMips, uint32 InNumSamples, uint32 InNumSamplesTileMem, ERHIResourceType InResourceType, const TArray<ovrpTextureHandle>& InTextures, ETextureCreateFlags InTexCreateFlags, const TCHAR* DebugName)
	{
		CheckInRenderThread();

		TArray<FTextureRHIRef> RHITextureSwapChain;
		{
			for (int32 TextureIndex = 0; TextureIndex < InTextures.Num(); ++TextureIndex)
			{
				FTextureRHIRef TexRef = CreateTexture_RenderThread(InSizeX, InSizeY, InFormat, InBinding, InNumMips, InNumSamples, InNumSamplesTileMem, InResourceType, InTextures[TextureIndex], InTexCreateFlags);

				FString TexName = FString::Printf(TEXT("%s (%d/%d)"), DebugName, TextureIndex, InTextures.Num());
				TexRef->SetName(*TexName);
				RHIBindDebugLabelName(TexRef, *TexName);

				RHITextureSwapChain.Add(TexRef);
			}
		}

		return RHITextureSwapChain;
	}

	void FCustomPresent::CopyTexture_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture* DstTexture, FRHITexture* SrcTexture,
		FIntRect DstRect, FIntRect SrcRect, bool bAlphaPremultiply, bool bNoAlphaWrite, bool bInvertY, bool sRGBSource, bool bInvertAlpha) const
	{
		CheckInRenderThread();

		FIntPoint DstSize;
		FIntPoint SrcSize;

		if (DstTexture->GetDesc().IsTexture2D() && SrcTexture->GetDesc().IsTexture2D())
		{
			DstSize = FIntPoint(DstTexture->GetSizeX(), DstTexture->GetSizeY());
			SrcSize = FIntPoint(SrcTexture->GetSizeX(), SrcTexture->GetSizeY());
		}
		else if (DstTexture->GetDesc().IsTextureCube() && SrcTexture->GetDesc().IsTextureCube())
		{
			DstSize = FIntPoint(DstTexture->GetSize(), DstTexture->GetSize());
			SrcSize = FIntPoint(SrcTexture->GetSize(), SrcTexture->GetSize());
		}
		else
		{
			return;
		}

		if (DstRect.IsEmpty())
		{
			DstRect = FIntRect(FIntPoint::ZeroValue, DstSize);
		}

		if (SrcRect.IsEmpty())
		{
			SrcRect = FIntRect(FIntPoint::ZeroValue, SrcSize);
		}

		const uint32 ViewportWidth = DstRect.Width();
		const uint32 ViewportHeight = DstRect.Height();
		const FIntPoint TargetSize(ViewportWidth, ViewportHeight);
		float U = SrcRect.Min.X / (float)SrcSize.X;
		float V = SrcRect.Min.Y / (float)SrcSize.Y;
		float USize = SrcRect.Width() / (float)SrcSize.X;
		float VSize = SrcRect.Height() / (float)SrcSize.Y;

#if PLATFORM_ANDROID // on android, top-left isn't 0/0 but 1/0.
		if (bInvertY)
		{
			V = 1.0f - V;
			VSize = -VSize;
		}
#endif

		FRHITexture* SrcTextureRHI = SrcTexture;
		RHICmdList.Transition(FRHITransitionInfo(SrcTextureRHI, ERHIAccess::Unknown, ERHIAccess::SRVGraphics));
		FGraphicsPipelineStateInitializer GraphicsPSOInit;

		if (bInvertAlpha)
		{
			// write RGBA, RGB = src.rgb * 1 + dst.rgb * 0, A = src.a * 0 + dst.a * (1 - src.a)
			GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_One, BF_Zero, BO_Add, BF_Zero, BF_InverseSourceAlpha>::GetRHI();
		}
		else if (bAlphaPremultiply)
		{
			if (bNoAlphaWrite)
			{
				// for quads, write RGB, RGB = src.rgb * 1 + dst.rgb * 0
				GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGB, BO_Add, BF_One, BF_Zero, BO_Add, BF_One, BF_Zero>::GetRHI();
			}
			else
			{
				// for quads, write RGBA, RGB = src.rgb * src.a + dst.rgb * 0, A = src.a + dst.a * 0
				GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_SourceAlpha, BF_Zero, BO_Add, BF_One, BF_Zero>::GetRHI();
			}
		}
		else
		{
			if (bNoAlphaWrite)
			{
				GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGB>::GetRHI();
			}
			else
			{
				// for mirror window, write RGBA, RGB = src.rgb * src.a + dst.rgb * (1 - src.a), A = src.a * 1 + dst.a * (1 - src a)
				GraphicsPSOInit.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_SourceAlpha, BF_InverseSourceAlpha, BO_Add, BF_One, BF_InverseSourceAlpha>::GetRHI();
			}
		}

		GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
		GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
		GraphicsPSOInit.PrimitiveType = PT_TriangleList;

		const auto FeatureLevel = OculusXRHMD->GetSettings_RenderThread()->CurrentFeatureLevel;
		auto ShaderMap = GetGlobalShaderMap(FeatureLevel);
		TShaderMapRef<FScreenVS> VertexShader(ShaderMap);
		GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
		GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();

		if (DstTexture->GetDesc().IsTexture2D())
		{
			sRGBSource &= EnumHasAnyFlags(SrcTexture->GetFlags(), TexCreate_SRGB);

			// Need to copy over mip maps on Android since they are not generated like they are on PC
#if PLATFORM_ANDROID
			uint32 NumMips = SrcTexture->GetNumMips();
#else
			uint32 NumMips = 1;
#endif

			const bool bUseTexArrayShader = SrcTexture->GetDesc().IsTextureArray() && DstTexture->GetDesc().IsTextureArray();
			const int32 SliceCount = bUseTexArrayShader ? FMath::Min(SrcTexture->GetDesc().ArraySize, DstTexture->GetDesc().ArraySize) : 1;

			for (uint32 MipIndex = 0; MipIndex < NumMips; MipIndex++)
			{
				FRHIRenderPassInfo RPInfo(DstTexture, ERenderTargetActions::Load_Store);
				RPInfo.ColorRenderTargets[0].MipIndex = MipIndex;

				for (int32 SliceIndex = 0; SliceIndex < SliceCount; ++SliceIndex)
				{
					RPInfo.ColorRenderTargets[0].ArraySlice = SliceIndex;

					RHICmdList.BeginRenderPass(RPInfo, TEXT("CopyTexture"));
					{
						const uint32 MipViewportWidth = ViewportWidth >> MipIndex;
						const uint32 MipViewportHeight = ViewportHeight >> MipIndex;
						const FIntPoint MipTargetSize(MipViewportWidth, MipViewportHeight);

						if (bNoAlphaWrite || bInvertAlpha)
						{
							RHICmdList.SetViewport(DstRect.Min.X, DstRect.Min.Y, 0.0f, DstRect.Max.X, DstRect.Max.Y, 1.0f);
							DrawClearQuad(RHICmdList, bAlphaPremultiply ? FLinearColor::Black : FLinearColor::White);
						}

						RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
						FRHISamplerState* SamplerState = DstRect.Size() == SrcRect.Size() ? TStaticSamplerState<SF_Point>::GetRHI() : TStaticSamplerState<SF_Bilinear>::GetRHI();

						if (!sRGBSource)
						{
							if (bUseTexArrayShader)
							{
								TShaderMapRef<FScreenPSMipLevelArray> PixelShader(ShaderMap);
								GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
								SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit, 0);
								FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
								PixelShader->SetParameters(BatchedParameters, SamplerState, SrcTextureRHI, SliceIndex, MipIndex);
								RHICmdList.SetBatchedShaderParameters(RHICmdList.GetBoundPixelShader(), BatchedParameters);
							}
							else
							{

								TShaderMapRef<FScreenPSMipLevel> PixelShader(ShaderMap);
								GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
								SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit, 0);
#if UE_VERSION_OLDER_THAN(5, 3, 0)
								PixelShader->SetParameters(RHICmdList, SamplerState, SrcTextureRHI, MipIndex);
#else
								FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
								PixelShader->SetParameters(BatchedParameters, SamplerState, SrcTextureRHI, MipIndex);
								RHICmdList.SetBatchedShaderParameters(RHICmdList.GetBoundPixelShader(), BatchedParameters);
#endif
							}
						}
						else
						{
							if (bUseTexArrayShader)
							{
								TShaderMapRef<FScreenPSsRGBSourceMipLevelArray> PixelShader(ShaderMap);
								GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
								SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit, 0);
								FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
								PixelShader->SetParameters(BatchedParameters, SamplerState, SrcTextureRHI, SliceIndex, MipIndex);
								RHICmdList.SetBatchedShaderParameters(RHICmdList.GetBoundPixelShader(), BatchedParameters);
							}
							else
							{
								TShaderMapRef<FScreenPSsRGBSourceMipLevel> PixelShader(ShaderMap);
								GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
								SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit, 0);
#if UE_VERSION_OLDER_THAN(5, 3, 0)
								PixelShader->SetParameters(RHICmdList, SamplerState, SrcTextureRHI, MipIndex);
#else
								FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
								PixelShader->SetParameters(BatchedParameters, SamplerState, SrcTextureRHI, MipIndex);
								RHICmdList.SetBatchedShaderParameters(RHICmdList.GetBoundPixelShader(), BatchedParameters);
#endif
							}
						}

						RHICmdList.SetViewport(DstRect.Min.X, DstRect.Min.Y, 0.0f, DstRect.Min.X + MipViewportWidth, DstRect.Min.Y + MipViewportHeight, 1.0f);

						RendererModule->DrawRectangle(
							RHICmdList,
							0, 0, MipViewportWidth, MipViewportHeight,
							U, V, USize, VSize,
							MipTargetSize,
							FIntPoint(1, 1),
							VertexShader,
							EDRF_Default);
					}
					RHICmdList.EndRenderPass();
				}
			}
		}
		else
		{
			for (int FaceIndex = 0; FaceIndex < 6; FaceIndex++)
			{
				FRHIRenderPassInfo RPInfo(DstTexture, ERenderTargetActions::Load_Store);

				// On Vulkan the positive and negative Y faces of the cubemap need to be flipped
				if (RenderAPI == ovrpRenderAPI_Vulkan)
				{
					int NewFaceIndex = 0;

					if (FaceIndex == VULKAN_CUBEMAP_POSITIVE_Y)
						NewFaceIndex = VULKAN_CUBEMAP_NEGATIVE_Y;
					else if (FaceIndex == VULKAN_CUBEMAP_NEGATIVE_Y)
						NewFaceIndex = VULKAN_CUBEMAP_POSITIVE_Y;
					else
						NewFaceIndex = FaceIndex;

					RPInfo.ColorRenderTargets[0].ArraySlice = NewFaceIndex;
				}
				else
				{
					RPInfo.ColorRenderTargets[0].ArraySlice = FaceIndex;
				}

				RHICmdList.BeginRenderPass(RPInfo, TEXT("CopyTextureFace"));
				{
					if (bNoAlphaWrite)
					{
						DrawClearQuad(RHICmdList, bAlphaPremultiply ? FLinearColor::Black : FLinearColor::White);
					}

					RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);

					TShaderMapRef<FOculusCubemapPS> PixelShader(ShaderMap);
					GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
					SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit, 0);
					FRHISamplerState* SamplerState = DstRect.Size() == SrcRect.Size() ? TStaticSamplerState<SF_Point>::GetRHI() : TStaticSamplerState<SF_Bilinear>::GetRHI();
#if UE_VERSION_OLDER_THAN(5, 3, 0)
					PixelShader->SetParameters(RHICmdList, SamplerState, SrcTextureRHI, FaceIndex);
#else
					FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
					PixelShader->SetParameters(BatchedParameters, SamplerState, SrcTextureRHI, FaceIndex);
					RHICmdList.SetBatchedShaderParameters(RHICmdList.GetBoundPixelShader(), BatchedParameters);
#endif

					RHICmdList.SetViewport(DstRect.Min.X, DstRect.Min.Y, 0.0f, DstRect.Max.X, DstRect.Max.Y, 1.0f);

					RendererModule->DrawRectangle(
						RHICmdList,
						0, 0, ViewportWidth, ViewportHeight,
#if PLATFORM_ANDROID
						U, V, USize, VSize,
#else
						U, 1.0 - V, USize, -VSize,
#endif
						TargetSize,
						FIntPoint(1, 1),
						VertexShader,
						EDRF_Default);
				}
				RHICmdList.EndRenderPass();
			}
		}
	}

	void FCustomPresent::SubmitGPUCommands_RenderThread(FRHICommandListImmediate& RHICmdList)
	{
		CheckInRenderThread();

		RHICmdList.SubmitCommandsHint();
	}

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
