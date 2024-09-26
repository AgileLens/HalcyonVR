// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OculusXRHMDPrivate.h"
#include "IXRLoadingScreen.h"

#if WITH_EDITOR
#include "Editor.h"
#endif

#if OCULUS_HMD_SUPPORTED_PLATFORMS
#include "OculusXRHMD_GameFrame.h"
#include "OculusXRHMD_Layer.h"
#include "TickableObjectRenderThread.h"
#include "OculusXRHMDTypes.h"

namespace OculusXRHMD
{

	class FOculusXRHMD;

	//-------------------------------------------------------------------------------------------------
	// FSplashLayer
	//-------------------------------------------------------------------------------------------------

	struct FSplashLayer
	{
		FOculusXRSplashDesc Desc;
		FLayerPtr Layer;

	public:
		FSplashLayer(const FOculusXRSplashDesc& InDesc)
			: Desc(InDesc) {}
		FSplashLayer(const FSplashLayer& InSplashLayer)
			: Desc(InSplashLayer.Desc), Layer(InSplashLayer.Layer) {}
	};

	//-------------------------------------------------------------------------------------------------
	// FSplash
	//-------------------------------------------------------------------------------------------------

	class FSplash : public IXRLoadingScreen, public TSharedFromThis<FSplash>
	{
	protected:
		class FTicker : public FTickableObjectRenderThread, public TSharedFromThis<FTicker>
		{
		public:
			FTicker(FSplash* InSplash)
				: FTickableObjectRenderThread(false, true), pSplash(InSplash) {}

			virtual void Tick(float DeltaTime) override { pSplash->Tick_RenderThread(DeltaTime); }
			virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(FSplash, STATGROUP_Tickables); }
			virtual bool IsTickable() const override { return true; }

		protected:
			FSplash* pSplash;
		};

	public:
		FSplash(FOculusXRHMD* InPlugin);
		virtual ~FSplash();

		void Tick_RenderThread(float DeltaTime);

		void Startup();
		void LoadSettings();
		void ReleaseResources_RHIThread();
		void PreShutdown();
		void Shutdown();

		void OnPreLoadMap(const FString&);
		void OnPostLoadMap(UWorld* LoadedWorld);
#if WITH_EDITOR
		void OnPieBegin(bool bIsSimulating);
#endif

		// Called from FOculusXRHMD
		void UpdateLoadingScreen_GameThread();

		// Internal extended API
		int AddSplash(const FOculusXRSplashDesc&);
		bool GetSplash(unsigned index, FOculusXRSplashDesc& OutDesc);
		void StopTicker();
		void StartTicker();

		// The standard IXRLoadingScreen interface
		virtual void ShowLoadingScreen() override;
		virtual void HideLoadingScreen() override;
		virtual void ClearSplashes() override;
		virtual void AddSplash(const FSplashDesc& Splash) override;
		virtual bool IsShown() const override { return bIsShown; }
#if !UE_VERSION_OLDER_THAN(5, 3, 0)
		virtual bool IsPlayingLoadingMovie() const override
		{
			return false;
		}
#endif

	protected:
		void DoShow();
		void DoHide();
		void UnloadTextures();
		void LoadTexture(FSplashLayer& InSplashLayer);
		void UnloadTexture(FSplashLayer& InSplashLayer);

		void RenderFrame_RenderThread(FRHICommandListImmediate& RHICmdList);
		IStereoLayers::FLayerDesc StereoLayerDescFromOculusSplashDesc(FOculusXRSplashDesc OculusDesc);

	protected:
		FOculusXRHMD* OculusXRHMD;
		FCustomPresent* CustomPresent;
		TSharedPtr<FTicker> Ticker;
		int32 FramesOutstanding;
		FCriticalSection RenderThreadLock;
		FSettingsPtr Settings;
		FGameFramePtr Frame;
		TArray<FSplashLayer> SplashLayers;
		uint32 NextLayerId;
		FLayerPtr BlackLayer;
		FLayerPtr UELayer;
		TArray<TTuple<FLayerPtr, FQuat>> Layers_RenderThread_DeltaRotation;
		TArray<FLayerPtr> Layers_RenderThread_Input;
		TArray<FLayerPtr> Layers_RenderThread;
		TArray<FLayerPtr> Layers_RHIThread;

		// All these flags are only modified from the Game thread
		bool bInitialized;
		bool bIsShown;
		bool bNeedSplashUpdate;
		bool bShouldShowSplash;

		float SystemDisplayInterval;
		double LastTimeInSeconds;
		FDelegateHandle PreLoadLevelDelegate;
		FDelegateHandle PostLoadLevelDelegate;
#if WITH_EDITOR
		FDelegateHandle PieBeginDelegateHandle;
#endif
	};

	typedef TSharedPtr<FSplash> FSplashPtr;

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
