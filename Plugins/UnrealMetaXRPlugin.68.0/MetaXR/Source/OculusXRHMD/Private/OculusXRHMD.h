// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "OculusXRHMDModule.h"

#if OCULUS_HMD_SUPPORTED_PLATFORMS
#include "OculusXRHMD_Settings.h"
#include "OculusXRHMD_GameFrame.h"
#include "OculusXRHMD_CustomPresent.h"
#include "OculusXRHMD_Layer.h"
#include "OculusXRHMD_Splash.h"
#include "OculusXRHMD_StressTester.h"
#include "OculusXRHMD_ConsoleCommands.h"
#include "OculusXRHMD_SpectatorScreenController.h"
#include "OculusXRHMD_DynamicResolutionState.h"
#include "OculusXRHMD_DeferredDeletionQueue.h"

#include "OculusXRAssetManager.h"

#include "HeadMountedDisplayBase.h"
#include "HeadMountedDisplay.h"
#include "XRRenderTargetManager.h"
#include "XRRenderBridge.h"
#include "IStereoLayers.h"
#include "Stats/Stats.h"
#include "SceneViewExtension.h"
#include "Engine/Engine.h"
#include "Engine/StaticMeshActor.h"
#include "XRThreadUtils.h"
#include "ProceduralMeshComponent.h"
#include "Shader.h"
#include "Misc/EngineVersionComparison.h"
#include "OculusXRHMD_FoveatedRendering.h"

namespace OculusXRHMD
{

	DECLARE_DELEGATE_TwoParams(FOculusXRHMDEventPollingDelegate, ovrpEventDataBuffer*, bool&);

	//-------------------------------------------------------------------------------------------------
	// FPerformanceStats
	//-------------------------------------------------------------------------------------------------

	struct FPerformanceStats
	{
		uint64 Frames;
		double Seconds;

		FPerformanceStats(uint32 InFrames = 0, double InSeconds = 0.0)
			: Frames(InFrames)
			, Seconds(InSeconds)
		{
		}

		FPerformanceStats operator-(const FPerformanceStats& PerformanceStats) const
		{
			return FPerformanceStats(
				Frames - PerformanceStats.Frames,
				Seconds - PerformanceStats.Seconds);
		}
	};

	enum FRecenterTypes
	{
		RecenterOrientation = 0x1,
		RecenterPosition = 0x2,
		RecenterOrientationAndPosition = 0x3
	};

	//-------------------------------------------------------------------------------------------------
	// FOculusXRHMD - Oculus Rift Head Mounted Display
	//-------------------------------------------------------------------------------------------------

	class FOculusXRHMD : public FHeadMountedDisplayBase, public FXRRenderTargetManager, public IStereoLayers, public FHMDSceneViewExtension, public FOculusAssetManager
	{
		friend class UOculusXRFunctionLibrary;
		friend FOculusXRHMDModule;
		friend class FSplash;
		friend class FConsoleCommands;

	public:
		OCULUSXRHMD_API static const FName OculusSystemName;
		// IXRSystemIdentifier
		virtual FName GetSystemName() const override;
		virtual int32 GetXRSystemFlags() const override;

		// IXRTrackingSystem
		virtual FString GetVersionString() const override;
		virtual bool DoesSupportPositionalTracking() const override;
		virtual bool HasValidTrackingPosition() override;
		virtual bool EnumerateTrackedDevices(TArray<int32>& OutDevices, EXRTrackedDeviceType Type = EXRTrackedDeviceType::Any) override;
		virtual bool GetCurrentPose(int32 InDeviceId, FQuat& OutOrientation, FVector& OutPosition) override;
		virtual bool GetRelativeEyePose(int32 InDeviceId, int32 ViewIndex, FQuat& OutOrientation, FVector& OutPosition) override;
		virtual bool GetTrackingSensorProperties(int32 InDeviceId, FQuat& OutOrientation, FVector& OutPosition, FXRSensorProperties& OutSensorProperties) override;
		virtual void SetTrackingOrigin(EHMDTrackingOrigin::Type NewOrigin) override;
		virtual EHMDTrackingOrigin::Type GetTrackingOrigin() const override;
		virtual bool GetFloorToEyeTrackingTransform(FTransform& OutFloorToEye) const override;
		// virtual FVector GetAudioListenerOffset(int32 InDeviceId = HMDDeviceId) const override;
		virtual void ResetOrientationAndPosition(float Yaw = 0.f) override;
		virtual void ResetOrientation(float Yaw = 0.f) override;
		virtual void ResetPosition() override;
		virtual void SetBaseRotation(const FRotator& BaseRot) override;
		virtual FRotator GetBaseRotation() const override;
		virtual void SetBaseOrientation(const FQuat& BaseOrient) override;
		virtual FQuat GetBaseOrientation() const override;
		// virtual TSharedPtr<class IXRCamera, ESPMode::ThreadSafe> GetXRCamera(int32 DeviceId = HMDDeviceId) override;
		virtual class IHeadMountedDisplay* GetHMDDevice() override { return this; }
		virtual class TSharedPtr<class IStereoRendering, ESPMode::ThreadSafe> GetStereoRenderingDevice() override
		{
			return SharedThis(this);
		}
		// virtual class IXRInput* GetXRInput() override;
		virtual bool
		IsHeadTrackingEnforced() const override;
		virtual void SetHeadTrackingEnforced(bool bEnabled) override;
		virtual bool IsHeadTrackingAllowed() const override;
		virtual void OnBeginPlay(FWorldContext& InWorldContext) override;
		virtual void OnEndPlay(FWorldContext& InWorldContext) override;
		virtual bool OnStartGameFrame(FWorldContext& WorldContext) override;
		virtual bool OnEndGameFrame(FWorldContext& WorldContext) override;
		virtual void OnBeginRendering_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& ViewFamily) override;
		virtual void OnBeginRendering_GameThread() override;
		virtual class IXRLoadingScreen* CreateLoadingScreen() override { return GetSplash(); }
		virtual FVector2D GetPlayAreaBounds(EHMDTrackingOrigin::Type Origin) const override;

		// IHeadMountedDisplay
		virtual bool IsHMDConnected() override { return true; }
		virtual bool IsHMDEnabled() const override;
		virtual EHMDWornState::Type GetHMDWornState() override;
		virtual void EnableHMD(bool bEnable = true) override;
		virtual bool GetHMDMonitorInfo(MonitorInfo&) override;
		virtual void GetFieldOfView(float& InOutHFOVInDegrees, float& InOutVFOVInDegrees) const override;
		virtual void SetInterpupillaryDistance(float NewInterpupillaryDistance) override;
		virtual float GetInterpupillaryDistance() const override;
		// virtual void SetClippingPlanes(float NCP, float FCP) override;
		// virtual FVector GetAudioListenerOffset() const override;
		virtual bool GetHMDDistortionEnabled(EShadingPath ShadingPath) const override;
		// virtual void BeginRendering_RenderThread(const FTransform& NewRelativeTransform, FRHICommandListImmediate& RHICmdList, FSceneViewFamily& ViewFamily) override;
		// virtual bool IsSpectatorScreenActive() const override;
		// virtual class ISpectatorScreenController* GetSpectatorScreenController() override;
		// virtual class ISpectatorScreenController const* GetSpectatorScreenController() const override;
		// virtual float GetDistortionScalingFactor() const override;
		// virtual float GetLensCenterOffset() const override;
		// virtual void GetDistortionWarpValues(FVector4& K) const override;
		virtual bool IsChromaAbCorrectionEnabled() const override;
		// virtual bool GetChromaAbCorrectionValues(FVector4& K) const override;
		virtual bool HasHiddenAreaMesh() const override;
		virtual bool HasVisibleAreaMesh() const override;
#ifdef WITH_OCULUS_BRANCH
		virtual void DrawHiddenAreaMesh(class FRHICommandList& RHICmdList, int32 ViewIndex, int32 InstanceCount = 1) const override;
		virtual void DrawVisibleAreaMesh(class FRHICommandList& RHICmdList, int32 ViewIndex, int32 InstanceCount = 1) const override;
#else
		virtual void DrawHiddenAreaMesh(class FRHICommandList& RHICmdList, int32 ViewIndex) const override;
		virtual void DrawVisibleAreaMesh(class FRHICommandList& RHICmdList, int32 ViewIndex) const override;
#endif // WITH_OCULUS_BRANCH
	   // virtual void DrawDistortionMesh_RenderThread(struct FHeadMountedDisplayPassContext& Context, const FIntPoint& TextureSize) override;
	   // virtual void UpdateScreenSettings(const FViewport* InViewport) override;
	   // virtual void UpdatePostProcessSettings(FPostProcessSettings*) override;
	   // virtual FTexture* GetDistortionTextureLeft() const override;
	   // virtual FTexture* GetDistortionTextureRight() const override;
	   // virtual FVector2D GetTextureOffsetLeft() const override;
	   // virtual FVector2D GetTextureOffsetRight() const override;
	   // virtual FVector2D GetTextureScaleLeft() const override;
	   // virtual FVector2D GetTextureScaleRight() const override;
	   // virtual const float* GetRedDistortionParameters() const override;
	   // virtual const float* GetGreenDistortionParameters() const override;
	   // virtual const float* GetBlueDistortionParameters() const override;
	   // virtual bool NeedsUpscalePostProcessPass() override;
	   // virtual void RecordAnalytics() override;
	   // virtual bool DoesAppUseVRFocus() const override;
	   // virtual bool DoesAppHaveVRFocus() const override;
		virtual float GetPixelDenity() const override;
		virtual void SetPixelDensity(const float NewPixelDensity) override;
		virtual FIntPoint GetIdealRenderTargetSize() const override;
		virtual void GetMotionControllerData(UObject* WorldContext, const EControllerHand Hand, FXRMotionControllerData& MotionControllerData) override;

		// IStereoRendering interface
		virtual bool IsStereoEnabled() const override;
		virtual bool IsStereoEnabledOnNextFrame() const override;
		virtual bool EnableStereo(bool stereo = true) override;
		virtual void AdjustViewRect(int32 ViewIndex, int32& X, int32& Y, uint32& SizeX, uint32& SizeY) const override;
		virtual void SetFinalViewRect(FRHICommandListImmediate& RHICmdList, const int32 ViewIndex, const FIntRect& FinalViewRect) override;
		// virtual FVector2D GetTextSafeRegionBounds() const override;
		virtual void CalculateStereoViewOffset(const int32 ViewIndex, FRotator& ViewRotation, const float WorldToMeters, FVector& ViewLocation) override;
		virtual FMatrix GetStereoProjectionMatrix(const int32 ViewIndex) const override;
		virtual void InitCanvasFromView(class FSceneView* InView, class UCanvas* Canvas) override;
		// virtual void GetEyeRenderParams_RenderThread(const struct FRenderingCompositePassContext& Context, FVector2D& EyeToSrcUVScaleValue, FVector2D& EyeToSrcUVOffsetValue) const override;
		virtual void RenderTexture_RenderThread(class FRHICommandListImmediate& RHICmdList, class FRHITexture* BackBuffer, class FRHITexture* SrcTexture, FVector2D WindowSize) const override;
		// virtual void SetClippingPlanes(float NCP, float FCP) override;
		virtual IStereoRenderTargetManager* GetRenderTargetManager() override { return this; }
		virtual IStereoLayers* GetStereoLayers() override { return this; }
		// virtual void UseImplicitHmdPosition(bool bInImplicitHmdPosition) override;
		// virtual bool GetUseImplicitHmdPosition() override;
		virtual bool IsStandaloneStereoOnlyDevice() const override { return bIsStandaloneStereoOnlyDevice; }
		bool SupportsSpaceWarp() const;
#ifdef WITH_OCULUS_BRANCH
		virtual void CalculateScissorRect(const int32 ViewIndex, const FIntRect& ViewRect, FIntRect& OutRect) override;
#endif // WITH_OCULUS_BRANCH

		// FHeadMountedDisplayBase interface
		virtual FVector2D GetEyeCenterPoint_RenderThread(int32 ViewIndex) const override;
		virtual FIntRect GetFullFlatEyeRect_RenderThread(FTexture2DRHIRef EyeTexture) const override;
		virtual void CopyTexture_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture2D* SrcTexture, FIntRect SrcRect, FRHITexture2D* DstTexture, FIntRect DstRect, bool bClearBlack, bool bNoAlpha) const override;
		virtual bool PopulateAnalyticsAttributes(TArray<struct FAnalyticsEventAttribute>& EventAttributes) override;

		// FXRRenderTargetManager interface
		virtual bool ShouldUseSeparateRenderTarget() const override;
#ifdef WITH_OCULUS_BRANCH
		virtual void CalculateRenderTargetSize(uint32& InOutSizeX, uint32& InOutSizeY) override;
#else  // WITH_OCULUS_BRANCH
		virtual void CalculateRenderTargetSize(const FViewport& Viewport, uint32& InOutSizeX, uint32& InOutSizeY) override;
#endif // WITH_OCULUS_BRANCH
		virtual bool NeedReAllocateViewportRenderTarget(const class FViewport& Viewport) override;
		virtual bool NeedReAllocateDepthTexture(const TRefCountPtr<IPooledRenderTarget>& DepthTarget) override;
		virtual bool NeedReAllocateShadingRateTexture(const TRefCountPtr<IPooledRenderTarget>& FoveationTarget) override;
#ifdef WITH_OCULUS_BRANCH
		virtual bool NeedReAllocateMotionVectorTexture(const TRefCountPtr<IPooledRenderTarget>& MotionVectorTarget, const TRefCountPtr<IPooledRenderTarget>& MotionVectorDepthTarget) override;
#endif // WITH_OCULUS_BRANCH
		virtual bool AllocateRenderTargetTexture(uint32 Index, uint32 SizeX, uint32 SizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags InTexFlags, ETextureCreateFlags InTargetableTextureFlags, FTexture2DRHIRef& OutTargetableTexture, FTexture2DRHIRef& OutShaderResourceTexture, uint32 NumSamples = 1) override;
		virtual bool AllocateDepthTexture(uint32 Index, uint32 SizeX, uint32 SizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags InTexFlags, ETextureCreateFlags TargetableTextureFlags, FTexture2DRHIRef& OutTargetableTexture, FTexture2DRHIRef& OutShaderResourceTexture, uint32 NumSamples = 1) override;
		virtual bool AllocateShadingRateTexture(uint32 Index, uint32 RenderSizeX, uint32 RenderSizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags InTexFlags, ETextureCreateFlags InTargetableTextureFlags, FTexture2DRHIRef& OutTexture, FIntPoint& OutTextureSize) override;
#ifdef WITH_OCULUS_BRANCH
		virtual bool AllocateMotionVectorTexture(uint32 Index, uint8 Format, uint32 NumMips, ETextureCreateFlags InTexFlags, ETextureCreateFlags InTargetableTextureFlags, FTexture2DRHIRef& OutTexture, FIntPoint& OutTextureSize, FTexture2DRHIRef& OutDepthTexture, FIntPoint& OutDepthTextureSize) override;
		virtual bool FindEnvironmentDepthTexture_RenderThread(FTextureRHIRef& OutTexture, FTextureRHIRef& OutMinMaxTexture, FVector2f& OutDepthFactors, FMatrix44f OutScreenToDepthMatrices[2], FMatrix44f OutDepthViewProjMatrices[2]) override;
#endif // WITH_OCULUS_BRANCH
		virtual EPixelFormat GetActualColorSwapchainFormat() const override;

		virtual void UpdateViewportWidget(bool bUseSeparateRenderTarget, const class FViewport& Viewport, class SViewport* ViewportWidget) override;
		virtual FXRRenderBridge* GetActiveRenderBridge_GameThread(bool bUseSeparateRenderTarget);
		void AllocateEyeBuffer();

		// IStereoLayers interface
		virtual uint32 CreateLayer(const IStereoLayers::FLayerDesc& InLayerDesc) override;
		virtual void DestroyLayer(uint32 LayerId) override;
		virtual void SetLayerDesc(uint32 LayerId, const IStereoLayers::FLayerDesc& InLayerDesc) override;
		virtual bool GetLayerDesc(uint32 LayerId, IStereoLayers::FLayerDesc& OutLayerDesc) override;
		virtual void MarkTextureForUpdate(uint32 LayerId) override;
		virtual IStereoLayers::FLayerDesc GetDebugCanvasLayerDesc(FTextureRHIRef Texture) override;
		virtual void GetAllocatedTexture(uint32 LayerId, FTextureRHIRef& Texture, FTextureRHIRef& LeftTexture) override;
		virtual bool ShouldCopyDebugLayersToSpectatorScreen() const override { return true; }
		virtual void PushLayerState(bool) override
		{ /* Todo */
		}
		virtual void PopLayerState() override
		{ /* Todo */
		}

		// ISceneViewExtension
		virtual void SetupViewFamily(FSceneViewFamily& InViewFamily) override;
		virtual void SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView) override;
		virtual void BeginRenderViewFamily(FSceneViewFamily& InViewFamily) override;
		virtual void PreRenderViewFamily_RenderThread(FRDGBuilder& GraphBuilder, FSceneViewFamily& InViewFamily) override;
		virtual void PreRenderView_RenderThread(FRDGBuilder& GraphBuilder, FSceneView& InView) override;
		virtual void PostRenderViewFamily_RenderThread(FRDGBuilder& GraphBuilder, FSceneViewFamily& InViewFamily) override;
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		virtual void PostRenderBasePassMobile_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView) override;
#ifdef WITH_OCULUS_BRANCH
		virtual void PostSceneColorRenderingMobile_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView) override;
#endif
#else
		virtual void PostRenderBasePassMobile_RenderThread(FRHICommandList& RHICmdList, FSceneView& InView) override;
#ifdef WITH_OCULUS_BRANCH
		virtual void PostSceneColorRenderingMobile_RenderThread(FRHICommandList& RHICmdList, FSceneView& InView) override;
#endif
#endif
		virtual void PostRenderBasePassDeferred_RenderThread(FRDGBuilder& GraphBuilder, FSceneView& InView, const FRenderTargetBindingSlots& RenderTargets, TRDGUniformBufferRef<FSceneTextureUniformParameters> SceneTextures) override;
		virtual int32 GetPriority() const override;
#ifdef WITH_OCULUS_BRANCH
		virtual bool LateLatchingEnabled() const override;
		virtual void PreLateLatchingViewFamily_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& InViewFamily) override;
#endif

		// MultiPlayer
		void SwitchPrimaryPIE(int PrimaryPIEIndex);
		const FOculusXRPerformanceMetrics GetPerformanceMetrics() const;

	public:
		FOculusXRHMD(const FAutoRegister&);
		~FOculusXRHMD();

	protected:
		bool Startup();
		void PreShutdown();
		void Shutdown();
		bool InitializeSession();
		void ShutdownSession();
		bool InitDevice();
		void ReleaseDevice();
		void ApplicationPauseDelegate();
		void ApplicationResumeDelegate();
		bool CheckEyeTrackingPermission(EOculusXRFoveatedRenderingMethod FoveatedRenderingMethod);
		void SetupOcclusionMeshes();
		void UpdateStereoRenderingParams();
		void UpdateHmdRenderInfo();
		void InitializeEyeLayer_RenderThread(FRHICommandListImmediate& RHICmdList);
		void ApplySystemOverridesOnStereo(bool force = false);
		bool OnOculusStateChange(bool bIsEnabledNow);
		bool ShouldDisableHiddenAndVisibileAreaMeshForSpectatorScreen_RenderThread() const;
		void Recenter(FRecenterTypes RecenterType, float Yaw);
		FIntRect GetAsymmetricViewRect(const int32 ViewIndex, const FIntRect& ViewRect);
#if !UE_BUILD_SHIPPING
		void DrawDebug(UCanvas* InCanvas, APlayerController* InPlayerController);
#endif

		class FSceneViewport* FindSceneViewport();
		FOculusXRSplashDesc GetUESplashScreenDesc();
		void EyeTrackedFoveatedRenderingFallback();

	public:
		OCULUSXRHMD_API static FOculusXRHMD* GetOculusXRHMD();

		bool IsHMDActive() const;

		FSplash* GetSplash() const { return Splash.Get(); }
		FCustomPresent* GetCustomPresent_Internal() const { return CustomPresent; }

		float GetWorldToMetersScale() const;

		ESpectatorScreenMode GetSpectatorScreenMode_RenderThread() const;

		FVector GetNeckPosition(const FQuat& HeadOrientation, const FVector& HeadPosition);

		/**
		 * Sets base position offset (in meters). The base position offset is the distance from the physical (0, 0, 0) position
		 * to current HMD position (bringing the (0, 0, 0) point to the current HMD position)
		 * Note, this vector is set by ResetPosition call; use this method with care.
		 * The axis of the vector are the same as in Unreal: X - forward, Y - right, Z - up.
		 *
		 * @param BaseOffset			(in) the vector to be set as base offset, in meters.
		 */
		void SetBaseOffsetInMeters(const FVector& BaseOffset);

		/**
		 * Returns the currently used base position offset, previously set by the
		 * ResetPosition or SetBasePositionOffset calls. It represents a vector that translates the HMD's position
		 * into (0,0,0) point, in meters.
		 * The axis of the vector are the same as in Unreal: X - forward, Y - right, Z - up.
		 *
		 * @return Base position offset, in meters.
		 */
		FVector GetBaseOffsetInMeters() const;

		OCULUSXRHMD_API bool ConvertPose(const ovrpPosef& InPose, FPose& OutPose) const;
		OCULUSXRHMD_API bool ConvertPose(const FPose& InPose, ovrpPosef& OutPose) const;
		OCULUSXRHMD_API bool ConvertPose_RenderThread(const ovrpPosef& InPose, FPose& OutPose) const;
		OCULUSXRHMD_API static bool ConvertPose_Internal(const ovrpPosef& InPose, FPose& OutPose, const FSettings* Settings, float WorldToMetersScale = 100.0f);
		OCULUSXRHMD_API static bool ConvertPose_Internal(const FPose& InPose, ovrpPosef& OutPose, const FSettings* Settings, float WorldToMetersScale = 100.0f);

		/** Turns ovrVector3f in Unreal World space to a scaled FVector and applies translation and rotation corresponding to player movement */
		FVector ScaleAndMovePointWithPlayer(ovrpVector3f& OculusXRHMDPoint);

		/** The inverse of ScaleAndMovePointWithPlayer */
		ovrpVector3f WorldLocationToOculusPoint(const FVector& InUnrealPosition);

		/** Convert dimension of a float (e.g., a distance) from meters to Unreal Units */
		float ConvertFloat_M2U(float OculusFloat) const;
		FVector ConvertVector_M2U(ovrpVector3f OculusPoint) const;

		struct UserProfile
		{
			float IPD;
			float EyeDepth;
			float EyeHeight;
		};

		bool GetUserProfile(UserProfile& OutProfile);
		float GetVsyncToNextVsync() const;
		FPerformanceStats GetPerformanceStats() const;
		bool DoEnableStereo(bool bStereo);
		void ResetControlRotation() const;
		void UpdateFoveationOffsets_RenderThread();
		bool ComputeEnvironmentDepthParameters_RenderThread(FVector2f& DepthFactors, FMatrix44f ScreenToDepth[ovrpEye_Count], FMatrix44f DepthViewProj[ovrpEye_Count], int& SwapchainIndex);
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		void RenderHardOcclusions_RenderThread(FRHICommandListImmediate& RHICmdList, const FSceneView& InView);
#else
		void RenderHardOcclusions_RenderThread(FRHICommandList& RHICmdList, const FSceneView& InView);
#endif
		void RenderEnvironmentDepthMinMaxTexture_RenderThread(FRHICommandListImmediate& RHICmdList);

		FSettingsPtr CreateNewSettings() const;
		FGameFramePtr CreateNewGameFrame() const;

		FGameFrame* GetFrame()
		{
			CheckInGameThread();
			return Frame.Get();
		}
		const FGameFrame* GetFrame() const
		{
			CheckInGameThread();
			return Frame.Get();
		}
		FGameFrame* GetFrame_RenderThread()
		{
			CheckInRenderThread();
			return Frame_RenderThread.Get();
		}
		const FGameFrame* GetFrame_RenderThread() const
		{
			CheckInRenderThread();
			return Frame_RenderThread.Get();
		}
		FGameFrame* GetFrame_RHIThread()
		{
			CheckInRHIThread();
			return Frame_RHIThread.Get();
		}
		const FGameFrame* GetFrame_RHIThread() const
		{
			CheckInRHIThread();
			return Frame_RHIThread.Get();
		}
		FGameFrame* GetNextFrameToRender()
		{
			CheckInGameThread();
			return NextFrameToRender.Get();
		}
		const FGameFrame* GetNextFrameToRender() const
		{
			CheckInGameThread();
			return NextFrameToRender.Get();
		}

		FSettings* GetSettings()
		{
			CheckInGameThread();
			return Settings.Get();
		}
		const FSettings* GetSettings() const
		{
			CheckInGameThread();
			return Settings.Get();
		}
		FSettings* GetSettings_RenderThread()
		{
			CheckInRenderThread();
			return Settings_RenderThread.Get();
		}
		const FSettings* GetSettings_RenderThread() const
		{
			CheckInRenderThread();
			return Settings_RenderThread.Get();
		}
		FSettings* GetSettings_RHIThread()
		{
			CheckInRHIThread();
			return Settings_RHIThread.Get();
		}
		const FSettings* GetSettings_RHIThread() const
		{
			CheckInRHIThread();
			return Settings_RHIThread.Get();
		}

		const int GetNextFrameNumber() const { return NextFrameNumber; }

		const FRotator GetSplashRotation() const { return SplashRotation; }
		void SetSplashRotationToForward();

		OCULUSXRHMD_API void StartGameFrame_GameThread();				// Called from OnStartGameFrame or from FOculusXRInput::SendControllerEvents (first actual call of the frame)
		void FinishGameFrame_GameThread();								// Called from OnEndGameFrame
		void StartRenderFrame_GameThread();								// Called from BeginRenderViewFamily
		void FinishRenderFrame_RenderThread(FRDGBuilder& GraphBuilder); // Called from PostRenderViewFamily_RenderThread
		void StartRHIFrame_RenderThread();								// Called from PreRenderViewFamily_RenderThread
		void FinishRHIFrame_RHIThread();								// Called from FinishRendering_RHIThread

		void GetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel& CpuPerfLevel, EOculusXRProcessorPerformanceLevel& GpuPerfLevel);
		void SetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel CpuPerfLevel, EOculusXRProcessorPerformanceLevel GpuPerfLevel);
		void SetFoveatedRenderingMethod(EOculusXRFoveatedRenderingMethod InFoveationMethod);
		void SetFoveatedRenderingLevel(EOculusXRFoveatedRenderingLevel InFoveationLevel, bool isDynamic);
		void SetColorScaleAndOffset(FLinearColor ColorScale, FLinearColor ColorOffset, bool bApplyToAllLayers);
		void SetEnvironmentDepthHandRemoval(bool RemoveHands);
		void StartEnvironmentDepth(int CreateFlags);
		void StopEnvironmentDepth();
		bool IsEnvironmentDepthStarted();

		void EnableHardOcclusions(bool bEnable);
		void EnableSoftOcclusions(bool bEnable);

		OCULUSXRHMD_API void UpdateRTPoses();

		FTransform GetLastTrackingToWorld() const { return LastTrackingToWorld; }
		OCULUSXRHMD_API void AddEventPollingDelegate(const FOculusXRHMDEventPollingDelegate& NewDelegate);

		OCULUSXRHMD_API uint32 GetLayerIdFromOvrpId(int OvrpId) const;

	protected:
		FConsoleCommands ConsoleCommands;
		void UpdateOnRenderThreadCommandHandler(const TArray<FString>& Args, UWorld* World, FOutputDevice& Ar);
		void PixelDensityMinCommandHandler(const TArray<FString>& Args, UWorld* World, FOutputDevice& Ar);
		void PixelDensityMaxCommandHandler(const TArray<FString>& Args, UWorld* World, FOutputDevice& Ar);
		void HQBufferCommandHandler(const TArray<FString>& Args, UWorld*, FOutputDevice& Ar);
		void HQDistortionCommandHandler(const TArray<FString>& Args, UWorld*, FOutputDevice& Ar);
		void ShowGlobalMenuCommandHandler(const TArray<FString>& Args, UWorld* World, FOutputDevice& Ar);
		void ShowQuitMenuCommandHandler(const TArray<FString>& Args, UWorld* World, FOutputDevice& Ar);
#if !UE_BUILD_SHIPPING
		void StatsCommandHandler(const TArray<FString>& Args, UWorld* World, FOutputDevice& Ar);
		void ShowSettingsCommandHandler(const TArray<FString>& Args, UWorld* World, FOutputDevice& Ar);
		void IPDCommandHandler(const TArray<FString>& Args, UWorld* World, FOutputDevice& Ar);
#endif

		void LoadFromSettings();
		void DoSessionShutdown();

	protected:
		void UpdateHMDWornState();
		EHMDWornState::Type HMDWornState = EHMDWornState::Unknown;

		void UpdateHMDEvents();

		void EnableInsightPassthrough_RenderThread(bool bEnablePassthrough);

		void DrawHmdViewMesh(
			FRHICommandList& RHICmdList,
			float X,
			float Y,
			float SizeX,
			float SizeY,
			float U,
			float V,
			float SizeU,
			float SizeV,
			FIntPoint TargetSize,
			FIntPoint TextureSize,
			int32 StereoView,
			const TShaderRef<class FShader>& VertexShader);

		// MultiPlayer
		void InitMultiPlayerPoses(const FPose& CurPose);
		void ResetMultiPlayerPoses();
		void ReCalcMultiPlayerPoses(FPose& CurHMDHeadPose);

		union
		{
			struct
			{
				uint64 bApplySystemOverridesOnStereo : 1;

				uint64 bNeedEnableStereo : 1;
				uint64 bNeedDisableStereo : 1;
			};
			uint64 Raw;
		} Flags;

		union
		{
			struct
			{
				// set to true when origin was set while OvrSession == null; the origin will be set ASA OvrSession != null
				uint64 NeedSetTrackingOrigin : 1;
				// enforces exit; used mostly for testing
				uint64 EnforceExit : 1;
				// set if a game is paused by the plug-in
				uint64 AppIsPaused : 1;
				// set to indicate that DisplayLost was detected by game thread.
				uint64 DisplayLostDetected : 1;
				// set to true once new session is created; being handled and reset as soon as session->IsVisible.
				uint64 NeedSetFocusToGameViewport : 1;
			};
			uint64 Raw;
		} OCFlags;

		TRefCountPtr<FCustomPresent> CustomPresent;
		FSplashPtr Splash;
		IRendererModule* RendererModule;

		FDeferredDeletionQueue DeferredDeletion;

		EHMDTrackingOrigin::Type TrackingOrigin;
		// Stores difference between ViewRotation and EyeOrientation from previous frame
		FQuat LastPlayerOrientation;
		// Stores GetFrame()->PlayerLocation (i.e., ViewLocation) from the previous frame
		FVector LastPlayerLocation;
		FRotator DeltaControlRotation; // used from ApplyHmdRotation
		TWeakPtr<SWidget> CachedViewportWidget;
		TWeakPtr<SWindow> CachedWindow;
		FIntPoint CachedWindowSize;
		float CachedWorldToMetersScale;
		bool bIsStandaloneStereoOnlyDevice;
		// Stores TrackingToWorld from previous frame
		FTransform LastTrackingToWorld;
		std::atomic<bool> bHardOcclusionsEnabled;
		std::atomic<bool> bSoftOcclusionsEnabled;
		std::atomic<bool> bEnvironmentDepthHandRemovalEnabled;

		// These three properties indicate the current state of foveated rendering, which may differ from what's in Settings
		// due to cases such as falling back to FFR when eye tracked foveated rendering isn't enabled. Will allow us to resume
		// ETFR from situations such as when ET gets paused.
		std::atomic<EOculusXRFoveatedRenderingMethod> FoveatedRenderingMethod;
		std::atomic<EOculusXRFoveatedRenderingLevel> FoveatedRenderingLevel;
		std::atomic<bool> bDynamicFoveatedRendering;

		// Game thread
		FSettingsPtr Settings;
		uint32 NextFrameNumber;
		uint32 WaitFrameNumber;
		FGameFramePtr Frame;			 // Valid from OnStartGameFrame to OnEndGameFrame
		FGameFramePtr NextFrameToRender; // Valid from OnStartGameFrame to BeginRenderViewFamily
		FGameFramePtr LastFrameToRender; // Valid from OnStartGameFrame to BeginRenderViewFamily
		uint32 NextLayerId;
		TMap<uint32, FLayerPtr> LayerMap;
		bool bNeedReAllocateViewportRenderTarget;

		// Render thread
		FSettingsPtr Settings_RenderThread;
		FGameFramePtr Frame_RenderThread; // Valid from BeginRenderViewFamily to PostRenderViewFamily_RenderThread
		TArray<FLayerPtr> Layers_RenderThread;
		FLayerPtr EyeLayer_RenderThread; // Valid to be accessed from game thread, since updated only when game thread is waiting
		bool bNeedReAllocateDepthTexture_RenderThread;
		bool bNeedReAllocateFoveationTexture_RenderThread;
		bool bNeedReAllocateMotionVectorTexture_RenderThread;
#if !UE_VERSION_OLDER_THAN(5, 3, 0)
		TSharedPtr<FOculusXRFoveatedRenderingImageGenerator, ESPMode::ThreadSafe> FoveationImageGenerator;
#endif // !UE_VERSION_OLDER_THAN(5, 3, 0)

		// RHI thread
		FSettingsPtr Settings_RHIThread;
		FGameFramePtr Frame_RHIThread; // Valid from PreRenderViewFamily_RenderThread to FinishRendering_RHIThread
		TArray<FLayerPtr> Layers_RHIThread;

		FHMDViewMesh HiddenAreaMeshes[2];
		FHMDViewMesh VisibleAreaMeshes[2];

		FPerformanceStats PerformanceStats;

		FRotator SplashRotation; // rotation applied to all splash screens (dependent on HMD orientation as the splash is shown)

		TArray<FTextureRHIRef> EnvironmentDepthSwapchain;
		FTextureRHIRef EnvironmentDepthMinMaxTexture;
		int PrevEnvironmentDepthMinMaxSwapchainIndex = -1;

#if !UE_BUILD_SHIPPING
		FDelegateHandle DrawDebugDelegateHandle;
#endif

		enum class FInsightInitStatus
		{
			NotInitialized,
			Initialized,
			Failed,
		};

		FInsightInitStatus InsightInitStatus;

		bool bShutdownRequestQueued;
		bool bEyeTrackedFoveatedRenderingSupported;

		FOculusXRPerformanceMetrics PerformanceMetrics;

		TArray<FOculusXRHMDEventPollingDelegate> EventPollingDelegates;

		// MultiPlayer
		int CurPlayerIndex;
		FPose LastFrameHMDHeadPose;
		TArray<FPose> MultiPlayerPoses;
		bool bShouldWait_GameThread;
		bool bIsRendering_RenderThread;
	};

	typedef TSharedPtr<FOculusXRHMD, ESPMode::ThreadSafe> FOculusXRHMDPtr;

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
