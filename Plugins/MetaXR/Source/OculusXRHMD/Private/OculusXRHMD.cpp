// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRHMD.h"
#include "OculusXRHMDPrivateRHI.h"

#include "EngineAnalytics.h"
#include "Interfaces/IAnalyticsProvider.h"
#include "AnalyticsEventAttribute.h"
#include "Slate/SceneViewport.h"
#include "PostProcess/PostProcessHMD.h"
#include "PostProcess/SceneRenderTargets.h"
#include "HardwareInfo.h"
#include "ScreenRendering.h"
#include "GameFramework/PlayerController.h"
#include "Math/UnrealMathUtility.h"
#include "Math/TranslationMatrix.h"
#include "Widgets/SViewport.h"
#include "Layout/WidgetPath.h"
#include "Framework/Application/SlateApplication.h"
#include "Engine/Canvas.h"
#include "Engine/GameEngine.h"
#include "Engine/RendererSettings.h"
#include "Misc/CoreDelegates.h"
#include "GameFramework/WorldSettings.h"
#include "Engine/StaticMesh.h"
#include "Engine/StaticMeshActor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Misc/EngineVersion.h"
#include "ClearQuad.h"
#include "DynamicResolutionState.h"
#include "DynamicResolutionProxy.h"
#include "OculusXRHMDRuntimeSettings.h"
#include "OculusXRDelegates.h"
#include "DataDrivenShaderPlatformInfo.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "LegacyScreenPercentageDriver.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "HAL/IConsoleManager.h"
#include "AndroidPermissionFunctionLibrary.h"
#include "AndroidPermissionCallbackProxy.h"
#endif
#include "GeneralProjectSettings.h"
#include "OculusShaders.h"
#include "PipelineStateCache.h"

#include "IOculusXRMRModule.h"

#if WITH_EDITOR
#include "Editor/UnrealEd/Classes/Editor/EditorEngine.h"
#include "Settings/LevelEditorPlaySettings.h"
#endif

#if !UE_BUILD_SHIPPING
#include "Debug/DebugDrawService.h"
#endif

#if OCULUS_HMD_SUPPORTED_PLATFORMS

static TAutoConsoleVariable<int32> CVarOculusEnableSubsampledLayout(
	TEXT("r.Mobile.Oculus.EnableSubsampled"),
	1,
	TEXT("0: Disable subsampled layout\n")
		TEXT("1: Enable subsampled layout on supported platforms (Default)\n"),
	ECVF_Scalability | ECVF_RenderThreadSafe);

static TAutoConsoleVariable<int32> CVarOculusEnableLowLatencyVRS(
	TEXT("r.Mobile.Oculus.EnableLowLatencyVRS"),
	0,
	TEXT("0: Disable late update of VRS textures (Default)\n")
		TEXT("1: Enable late update of VRS textures\n"),
	ECVF_Scalability | ECVF_RenderThreadSafe);

static TAutoConsoleVariable<int32> CVarOculusForceSymmetric(
	TEXT("r.Mobile.Oculus.ForceSymmetric"),
	0,
	TEXT("0: Use standard runtime-provided projection matrices (Default)\n")
		TEXT("1: Render both eyes with a symmetric projection, union of both FOVs (and corresponding higher rendertarget size to maintain PD)\n"),
	ECVF_Scalability | ECVF_RenderThreadSafe);

static TAutoConsoleVariable<int32> CVarOculusIncreaseThreadPrio(
	TEXT("r.Mobile.Oculus.IncreaseThreadPrio"),
	1,
	TEXT("0: Use standard engine thread priority for all threads\n")
		TEXT("1: Use increased thread priority provided by runtime (Default)\n"),
	ECVF_Scalability | ECVF_RenderThreadSafe);

// AppSpaceWarp
static TAutoConsoleVariable<int32> CVarOculusEnableSpaceWarpUser(
	TEXT("r.Mobile.Oculus.SpaceWarp.Enable"),
	0,
	TEXT("0 Disable spacewarp at runtime.\n")
		TEXT("1 Enable spacewarp at runtime.\n"),
	ECVF_Scalability | ECVF_RenderThreadSafe);

static TAutoConsoleVariable<int32> CVarOculusEnableSpaceWarpInternal(
	TEXT("r.Mobile.Oculus.SpaceWarp.EnableInternal"),
	0,
	TEXT("0 Disable spacewarp, for internal engine checking, don't modify.\n")
		TEXT("1 Enable spacewarp, for internal enegine checking, don't modify.\n"),
	ECVF_Scalability | ECVF_RenderThreadSafe);

// Foveated Rendering
static TAutoConsoleVariable<int32> CVarOculusFoveatedRenderingMethod(
	TEXT("r.Mobile.Oculus.FoveatedRendering.Method"),
	-1,
	TEXT("0 Fixed Foveated Rendering.\n")
		TEXT("1 Eye-Tracked Foveated Rendering.\n"),
	ECVF_Scalability | ECVF_RenderThreadSafe);

static TAutoConsoleVariable<int32> CVarOculusFoveatedRenderingLevel(
	TEXT("r.Mobile.Oculus.FoveatedRendering.Level"),
	-1,
	TEXT("0 Off.\n")
		TEXT("1 Low.\n")
			TEXT("2 Medium.\n")
				TEXT("3 High.\n")
					TEXT("4 High Top.\n"),
	ECVF_Scalability | ECVF_RenderThreadSafe);

static TAutoConsoleVariable<int32> CVarOculusDynamicFoveatedRendering(
	TEXT("r.Mobile.Oculus.FoveatedRendering.Dynamic"),
	-1,
	TEXT("0 Disable Dynamic Foveated Rendering at runtime.\n")
		TEXT("1 Enable Dynamic Foveated Rendering at runtime.\n"),
	ECVF_Scalability | ECVF_RenderThreadSafe);

static TAutoConsoleVariable<float> CVarOculusDynamicResolutionPixelDensity(
	TEXT("r.Oculus.DynamicResolution.PixelDensity"),
	0,
	TEXT("0 Static Pixel Density corresponding to Pixel Density 1.0 (default)\n")
		TEXT(">0 Manual Pixel Density Override\n"),
	ECVF_Scalability | ECVF_RenderThreadSafe);

#define OCULUS_PAUSED_IDLE_FPS 10

static const FString USE_SCENE_PERMISSION_NAME("com.oculus.permission.USE_SCENE");
static const FString PROJECT_ID_TELEMETRY("META_PROJECT_TELEMETRY_ID");

static bool IsMobileTonemapSubpassEnabled(const FStaticShaderPlatform Platform)
{
	static auto* MobileTonemapSubpassPathCvar = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.Mobile.TonemapSubpass"));
	return (MobileTonemapSubpassPathCvar && (MobileTonemapSubpassPathCvar->GetValueOnAnyThread() == 1)) && !IsMobileDeferredShadingEnabled(Platform);
}

namespace OculusXRHMD
{

	/**
	 * A pixel shader for rendering occlusions, this is the min/max preprocessing step.
	 */
	template <bool bEnableMultiView>
	class FScreenPSEnvironmentDepthMinMax : public FGlobalShader
	{
		DECLARE_SHADER_TYPE(FScreenPSEnvironmentDepthMinMax, Global);

	public:
		static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
		{
			return !bEnableMultiView || Parameters.Platform == SP_VULKAN_ES3_1_ANDROID || Parameters.Platform == SP_VULKAN_SM5;
		}

		static void ModifyCompilationEnvironment(const FPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
		{
			OutEnvironment.SetDefine(TEXT("ENABLE_MULTI_VIEW"), bEnableMultiView ? 1 : 0);
		}

		FScreenPSEnvironmentDepthMinMax(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
			: FGlobalShader(Initializer)
		{
			InTexture.Bind(Initializer.ParameterMap, TEXT("InTexture"), SPF_Mandatory);
			InTextureSampler.Bind(Initializer.ParameterMap, TEXT("InTextureSampler"));
			if (!bEnableMultiView)
			{
				InArraySliceParameter.Bind(Initializer.ParameterMap, TEXT("ArraySlice"));
			}
		}

		FScreenPSEnvironmentDepthMinMax() {}

		void SetParameters(FRHIBatchedShaderParameters& BatchedParameters, FRHISamplerState* SamplerStateRHI, FRHITexture* TextureRHI, int ArraySlice)
		{
			SetTextureParameter(BatchedParameters, InTexture, InTextureSampler, SamplerStateRHI, TextureRHI);
			if (!bEnableMultiView)
			{
				SetShaderValue(BatchedParameters, InArraySliceParameter, ArraySlice);
			}
		}

	private:
		LAYOUT_FIELD(FShaderResourceParameter, InTexture);
		LAYOUT_FIELD(FShaderResourceParameter, InTextureSampler);
		LAYOUT_FIELD(FShaderParameter, InArraySliceParameter);
	};
	IMPLEMENT_SHADER_TYPE(template <>, FScreenPSEnvironmentDepthMinMax<true>, TEXT("/Plugin/OculusXR/Private/ScreenPSEnvironmentDepthMinMax.usf"), TEXT("Main"), SF_Pixel);
	IMPLEMENT_SHADER_TYPE(template <>, FScreenPSEnvironmentDepthMinMax<false>, TEXT("/Plugin/OculusXR/Private/ScreenPSEnvironmentDepthMinMax.usf"), TEXT("Main"), SF_Pixel);

#if !UE_BUILD_SHIPPING
	static void __cdecl OvrpLogCallback(ovrpLogLevel level, const char* message)
	{
		FString tbuf = ANSI_TO_TCHAR(message);
		const TCHAR* levelStr = TEXT("");
		switch (level)
		{
			case ovrpLogLevel_Debug:
				levelStr = TEXT(" Debug:");
				break;
			case ovrpLogLevel_Info:
				levelStr = TEXT(" Info:");
				break;
			case ovrpLogLevel_Error:
				levelStr = TEXT(" Error:");
				break;
		}

		GLog->Logf(TEXT("OCULUS:%s %s"), levelStr, *tbuf);
	}
#endif // !UE_BUILD_SHIPPING

	//-------------------------------------------------------------------------------------------------
	// FOculusXRHMD
	//-------------------------------------------------------------------------------------------------

	const FName FOculusXRHMD::OculusSystemName(TEXT("OculusXRHMD"));

	FName FOculusXRHMD::GetSystemName() const
	{
		return OculusSystemName;
	}
	int32 FOculusXRHMD::GetXRSystemFlags() const
	{
		return EXRSystemFlags::IsHeadMounted;
	}

	FString FOculusXRHMD::GetVersionString() const
	{
		const char* Version;

		if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetVersion2(&Version)))
		{
			Version = "Unknown";
		}

		return FString::Printf(TEXT("OVRPlugin: %s"), UTF8_TO_TCHAR(Version));
	}

	bool FOculusXRHMD::DoesSupportPositionalTracking() const
	{
		ovrpBool trackingPositionSupported;
		return OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetTrackingPositionSupported2(&trackingPositionSupported)) && trackingPositionSupported;
	}

	bool FOculusXRHMD::HasValidTrackingPosition()
	{
		ovrpBool nodePositionTracked;
		return OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetNodePositionTracked2(ovrpNode_Head, &nodePositionTracked)) && nodePositionTracked;
	}

	struct TrackedDevice
	{
		ovrpNode Node;
		EXRTrackedDeviceType Type;
	};

	static TrackedDevice TrackedDevices[] = {
		{ ovrpNode_Head, EXRTrackedDeviceType::HeadMountedDisplay },
		{ ovrpNode_HandLeft, EXRTrackedDeviceType::Controller },
		{ ovrpNode_HandRight, EXRTrackedDeviceType::Controller },
		{ ovrpNode_TrackerZero, EXRTrackedDeviceType::TrackingReference },
		{ ovrpNode_TrackerOne, EXRTrackedDeviceType::TrackingReference },
		{ ovrpNode_TrackerTwo, EXRTrackedDeviceType::TrackingReference },
		{ ovrpNode_TrackerThree, EXRTrackedDeviceType::TrackingReference },
		{ ovrpNode_DeviceObjectZero, EXRTrackedDeviceType::Other },
	};

	static uint32 TrackedDeviceCount = sizeof(TrackedDevices) / sizeof(TrackedDevices[0]);

	bool FOculusXRHMD::EnumerateTrackedDevices(TArray<int32>& OutDevices, EXRTrackedDeviceType Type)
	{
		CheckInGameThread();

		for (uint32 TrackedDeviceId = 0; TrackedDeviceId < TrackedDeviceCount; TrackedDeviceId++)
		{
			if (Type == EXRTrackedDeviceType::Any || Type == TrackedDevices[TrackedDeviceId].Type)
			{
				ovrpBool nodePresent;

				ovrpNode Node = TrackedDevices[TrackedDeviceId].Node;
				if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetNodePresent2(Node, &nodePresent)) && nodePresent)
				{
					const int32 ExternalDeviceId = OculusXRHMD::ToExternalDeviceId(Node);
					OutDevices.Add(ExternalDeviceId);
				}
			}
		}

		return true;
	}

	void FOculusXRHMD::UpdateRTPoses()
	{
		CheckInRenderThread();
		FGameFrame* CurrentFrame = GetFrame_RenderThread();
		if (CurrentFrame)
		{
			if (!CurrentFrame->Flags.bRTLateUpdateDone)
			{
				FOculusXRHMDModule::GetPluginWrapper().Update3(ovrpStep_Render, CurrentFrame->FrameNumber, 0.0);
				CurrentFrame->Flags.bRTLateUpdateDone = true;
			}
		}
		// else, Frame_RenderThread has already been reset/rendered (or not created yet).
		// This can happen when DoEnableStereo() is called, as SetViewportSize (which it calls) enques a render
		// immediately - meaning two render frames were enqueued in the span of one game tick.
	}

	void FOculusXRHMD::SwitchPrimaryPIE(int PrimaryPIEIndex)
	{
		CurPlayerIndex = PrimaryPIEIndex;
	}

	void FOculusXRHMD::InitMultiPlayerPoses(const FPose& CurPose)
	{
#if WITH_EDITOR && PLATFORM_WINDOWS
		if (!GIsEditor || MultiPlayerPoses.Num())
		{
			return;
		}

		ovrpBool bAppHasVRFocus = ovrpBool_False;
		FOculusXRHMDModule::GetPluginWrapper().GetAppHasVrFocus2(&bAppHasVRFocus);
		if (!bAppHasVRFocus)
			return;

		ULevelEditorPlaySettings* PlayInSettings = GetMutableDefault<ULevelEditorPlaySettings>();
		check(PlayInSettings);
		int PlayNumberOfClients;
		PlayInSettings->GetPlayNumberOfClients(PlayNumberOfClients);
		if (PlayNumberOfClients <= 1)
		{
			return;
		}
		LastFrameHMDHeadPose = CurPose;
		MultiPlayerPoses.Empty();
		MultiPlayerPoses.InsertDefaulted(0, PlayNumberOfClients);
		for (auto& PlayerPose : MultiPlayerPoses)
		{
			PlayerPose = CurPose;
		}
		UE_LOG(LogHMD, Log, TEXT("MultiPlayer poses are initialized."));
#endif
	}

	void FOculusXRHMD::ResetMultiPlayerPoses()
	{
#if WITH_EDITOR && PLATFORM_WINDOWS
		if (!GIsEditor || GetMutableDefault<UOculusXRHMDRuntimeSettings>()->MPPoseRestoreType == EOculusXRMPPoseRestoreType::Disabled)
		{
			return;
		}

		CurPlayerIndex = 0;
		LastFrameHMDHeadPose = FPose();
		MultiPlayerPoses.Empty();
#endif
	}

	void FOculusXRHMD::ReCalcMultiPlayerPoses(FPose& CurHMDHeadPose)
	{
#if WITH_EDITOR && PLATFORM_WINDOWS
		if (!GIsEditor || GetMutableDefault<UOculusXRHMDRuntimeSettings>()->MPPoseRestoreType == EOculusXRMPPoseRestoreType::Disabled)
		{
			return;
		}

		if (!MultiPlayerPoses.Num())
		{
			InitMultiPlayerPoses(CurHMDHeadPose);
		}

		if (!MultiPlayerPoses.Num())
		{
			return;
		}

		FPose& PlayerPose = MultiPlayerPoses[CurPlayerIndex];
		if (GetMutableDefault<UOculusXRHMDRuntimeSettings>()->MPPoseRestoreType == EOculusXRMPPoseRestoreType::PositionOnly)
		{
			FVector DeltaPosition = CurHMDHeadPose.Position - LastFrameHMDHeadPose.Position;
			PlayerPose.Position += DeltaPosition;
			LastFrameHMDHeadPose.Position = CurHMDHeadPose.Position;
			CurHMDHeadPose.Position = PlayerPose.Position;
		}
		else
		{
			FPose DeltaPose = LastFrameHMDHeadPose.Inverse() * CurHMDHeadPose;
			PlayerPose = PlayerPose * DeltaPose;
			LastFrameHMDHeadPose = CurHMDHeadPose;
			CurHMDHeadPose = PlayerPose;
		}
#endif
	}

	bool FOculusXRHMD::GetCurrentPose(int32 InDeviceId, FQuat& OutOrientation, FVector& OutPosition)
	{
		OutOrientation = FQuat::Identity;
		OutPosition = FVector::ZeroVector;

		if ((size_t)InDeviceId >= TrackedDeviceCount)
		{
			return false;
		}

		ovrpNode Node = OculusXRHMD::ToOvrpNode(InDeviceId);
		const FSettings* CurrentSettings;
		FGameFrame* CurrentFrame;

		if (InRenderThread())
		{
			CurrentSettings = GetSettings_RenderThread();
			CurrentFrame = GetFrame_RenderThread();
			UpdateRTPoses();
		}
		else if (InGameThread())
		{
			CurrentSettings = GetSettings();
			CurrentFrame = NextFrameToRender.Get();
		}
		else
		{
			return false;
		}

		if (!CurrentSettings || !CurrentFrame)
		{
			return false;
		}

		ovrpPoseStatef PoseState;
		FPose Pose;

		if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetNodePoseState3(ovrpStep_Render, CurrentFrame->FrameNumber, Node, &PoseState)) || !ConvertPose_Internal(PoseState.Pose, Pose, CurrentSettings, CurrentFrame->WorldToMetersScale))
		{
			return false;
		}

		if (Node == ovrpNode_Head || Node == ovrpNode_EyeCenter)
		{
			ReCalcMultiPlayerPoses(Pose);
		}

		OutPosition = Pose.Position;
		OutOrientation = Pose.Orientation;
		return true;
	}

	bool FOculusXRHMD::GetRelativeEyePose(int32 InDeviceId, int32 ViewIndex, FQuat& OutOrientation, FVector& OutPosition)
	{
		OutOrientation = FQuat::Identity;
		OutPosition = FVector::ZeroVector;

		if (InDeviceId != HMDDeviceId)
		{
			return false;
		}

		ovrpNode Node;

		switch (ViewIndex)
		{
			case EStereoscopicEye::eSSE_LEFT_EYE:
				Node = ovrpNode_EyeLeft;
				break;
			case EStereoscopicEye::eSSE_RIGHT_EYE:
				Node = ovrpNode_EyeRight;
				break;
			case EStereoscopicEye::eSSE_MONOSCOPIC:
				Node = ovrpNode_EyeCenter;
				break;
			default:
				return false;
		}

		const FSettings* CurrentSettings;
		FGameFrame* CurrentFrame;

		if (InRenderThread())
		{
			CurrentSettings = GetSettings_RenderThread();
			CurrentFrame = GetFrame_RenderThread();
			UpdateRTPoses();
		}
		else if (InGameThread())
		{
			CurrentSettings = GetSettings();
			CurrentFrame = NextFrameToRender.Get();
		}
		else
		{
			return false;
		}

		if (!CurrentSettings || !CurrentFrame)
		{
			return false;
		}

		ovrpPoseStatef HmdPoseState, EyePoseState;

		if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetNodePoseState3(ovrpStep_Render, CurrentFrame->FrameNumber, ovrpNode_Head, &HmdPoseState)) || OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetNodePoseState3(ovrpStep_Render, CurrentFrame->FrameNumber, Node, &EyePoseState)))
		{
			return false;
		}

		FPose HmdPose, EyePose;
		HmdPose.Orientation = ToFQuat(HmdPoseState.Pose.Orientation);
		HmdPose.Position = ToFVector(HmdPoseState.Pose.Position) * CurrentFrame->WorldToMetersScale;
		EyePose.Orientation = ToFQuat(EyePoseState.Pose.Orientation);
		EyePose.Position = ToFVector(EyePoseState.Pose.Position) * CurrentFrame->WorldToMetersScale;

		FQuat HmdOrientationInv = HmdPose.Orientation.Inverse();
		OutOrientation = HmdOrientationInv * EyePose.Orientation;
		OutOrientation.Normalize();
		OutPosition = HmdOrientationInv.RotateVector(EyePose.Position - HmdPose.Position);
		return true;
	}

	bool FOculusXRHMD::GetTrackingSensorProperties(int32 InDeviceId, FQuat& OutOrientation, FVector& OutPosition, FXRSensorProperties& OutSensorProperties)
	{
		CheckInGameThread();

		if ((size_t)InDeviceId >= TrackedDeviceCount)
		{
			return false;
		}

		ovrpNode Node = OculusXRHMD::ToOvrpNode(InDeviceId);
		ovrpPoseStatef PoseState;
		FPose Pose;
		ovrpFrustum2f Frustum;

		if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetNodePoseState3(ovrpStep_Render, OVRP_CURRENT_FRAMEINDEX, Node, &PoseState)) || !ConvertPose(PoseState.Pose, Pose) || OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetNodeFrustum2(Node, &Frustum)))
		{
			return false;
		}

		OutPosition = Pose.Position;
		OutOrientation = Pose.Orientation;
		OutSensorProperties.LeftFOV = FMath::RadiansToDegrees(FMath::Atan(Frustum.Fov.LeftTan));
		OutSensorProperties.RightFOV = FMath::RadiansToDegrees(FMath::Atan(Frustum.Fov.RightTan));
		OutSensorProperties.TopFOV = FMath::RadiansToDegrees(FMath::Atan(Frustum.Fov.UpTan));
		OutSensorProperties.BottomFOV = FMath::RadiansToDegrees(FMath::Atan(Frustum.Fov.DownTan));
		OutSensorProperties.NearPlane = Frustum.zNear * Frame->WorldToMetersScale;
		OutSensorProperties.FarPlane = Frustum.zFar * Frame->WorldToMetersScale;
		OutSensorProperties.CameraDistance = 1.0f * Frame->WorldToMetersScale;
		return true;
	}

	void FOculusXRHMD::SetTrackingOrigin(EHMDTrackingOrigin::Type InOrigin)
	{
		TrackingOrigin = InOrigin;
		ovrpTrackingOrigin ovrpOrigin = ovrpTrackingOrigin_EyeLevel;

#if UE_VERSION_OLDER_THAN(5, 4, 0)
		const bool bIsOrginOnFloor = (InOrigin == EHMDTrackingOrigin::Floor);
#else
		const bool bIsOrginOnFloor = (InOrigin == EHMDTrackingOrigin::LocalFloor);
#endif

		if (bIsOrginOnFloor)
			ovrpOrigin = ovrpTrackingOrigin_FloorLevel;

		if (InOrigin == EHMDTrackingOrigin::Stage)
			ovrpOrigin = ovrpTrackingOrigin_Stage;

		if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized())
		{
			EHMDTrackingOrigin::Type lastOrigin = GetTrackingOrigin();
			FOculusXRHMDModule::GetPluginWrapper().SetTrackingOriginType2(ovrpOrigin);
			OCFlags.NeedSetTrackingOrigin = false;

			if (lastOrigin != InOrigin)
				Settings->BaseOffset = FVector::ZeroVector;
		}

		OnTrackingOriginChanged();
	}

	EHMDTrackingOrigin::Type FOculusXRHMD::GetTrackingOrigin() const
	{
#if UE_VERSION_OLDER_THAN(5, 4, 0)
		EHMDTrackingOrigin::Type rv = EHMDTrackingOrigin::Eye;
#else
		EHMDTrackingOrigin::Type rv = EHMDTrackingOrigin::View;
#endif
		ovrpTrackingOrigin ovrpOrigin = ovrpTrackingOrigin_EyeLevel;

		if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized() && OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetTrackingOriginType2(&ovrpOrigin)))
		{
			switch (ovrpOrigin)
			{
				case ovrpTrackingOrigin_EyeLevel:
#if UE_VERSION_OLDER_THAN(5, 4, 0)
					rv = EHMDTrackingOrigin::Eye;
#else
					rv = EHMDTrackingOrigin::View;
#endif
					break;
				case ovrpTrackingOrigin_FloorLevel:
#if UE_VERSION_OLDER_THAN(5, 4, 0)
					rv = EHMDTrackingOrigin::Floor;
#else
					rv = EHMDTrackingOrigin::LocalFloor;
#endif
					break;
				case ovrpTrackingOrigin_Stage:
					rv = EHMDTrackingOrigin::Stage;
					break;
				default:
					UE_LOG(LogHMD, Error, TEXT("Unsupported ovr tracking origin type %d"), int(ovrpOrigin));
					break;
			}
		}
		return rv;
	}

	bool FOculusXRHMD::GetFloorToEyeTrackingTransform(FTransform& OutFloorToEye) const
	{
		float EyeHeight = 0.f;
		const bool bSuccess = FOculusXRHMDModule::GetPluginWrapper().GetInitialized() && OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetUserEyeHeight2(&EyeHeight));
		OutFloorToEye = FTransform(FVector(0.f, 0.f, -ConvertFloat_M2U(EyeHeight)));

		return bSuccess;
	}

	void FOculusXRHMD::ResetOrientationAndPosition(float yaw)
	{
		Recenter(RecenterOrientationAndPosition, yaw);
	}

	void FOculusXRHMD::ResetOrientation(float yaw)
	{
		Recenter(RecenterOrientation, yaw);
	}

	void FOculusXRHMD::ResetPosition()
	{
		Recenter(RecenterPosition, 0);
	}

	void FOculusXRHMD::Recenter(FRecenterTypes RecenterType, float Yaw)
	{
		CheckInGameThread();

		if (NextFrameToRender)
		{
#if UE_VERSION_OLDER_THAN(5, 4, 0)
			const bool floorLevel = GetTrackingOrigin() != EHMDTrackingOrigin::Eye;
#else
			const bool floorLevel = GetTrackingOrigin() != EHMDTrackingOrigin::View;
#endif
			ovrpPoseStatef poseState;
			FOculusXRHMDModule::GetPluginWrapper().Update3(ovrpStep_Render, NextFrameToRender->FrameNumber, 0.0);
			FOculusXRHMDModule::GetPluginWrapper().GetNodePoseState3(ovrpStep_Render, NextFrameToRender->FrameNumber, ovrpNode_Head, &poseState);

			if (RecenterType & RecenterPosition)
			{
				Settings->BaseOffset = ToFVector(poseState.Pose.Position);
				if (floorLevel)
					Settings->BaseOffset.Z = 0;
			}

			if (RecenterType & RecenterOrientation)
			{
				Settings->BaseOrientation = FRotator(0, FRotator(ToFQuat(poseState.Pose.Orientation)).Yaw - Yaw, 0).Quaternion();
			}
		}
	}

	void FOculusXRHMD::SetBaseRotation(const FRotator& BaseRot)
	{
		SetBaseOrientation(BaseRot.Quaternion());
	}

	FRotator FOculusXRHMD::GetBaseRotation() const
	{
		return GetBaseOrientation().Rotator();
	}

	void FOculusXRHMD::SetBaseOrientation(const FQuat& BaseOrient)
	{
		CheckInGameThread();

		Settings->BaseOrientation = BaseOrient;
	}

	FQuat FOculusXRHMD::GetBaseOrientation() const
	{
		CheckInGameThread();

		return Settings->BaseOrientation;
	}

	bool FOculusXRHMD::IsHeadTrackingEnforced() const
	{
		if (IsInGameThread())
		{
			return Settings.IsValid() && Settings->Flags.bHeadTrackingEnforced;
		}
		else
		{
			CheckInRenderThread();
			return Settings_RenderThread.IsValid() && Settings_RenderThread->Flags.bHeadTrackingEnforced;
		}
	}

	void FOculusXRHMD::SetHeadTrackingEnforced(bool bEnabled)
	{
		CheckInGameThread();
		check(Settings.IsValid());

		const bool bOldValue = Settings->Flags.bHeadTrackingEnforced;
		Settings->Flags.bHeadTrackingEnforced = bEnabled;

		if (!bEnabled)
		{
			ResetControlRotation();
		}
		else if (!bOldValue)
		{
			InitDevice();
		}
	}

	bool FOculusXRHMD::IsHeadTrackingAllowed() const
	{
		bool bNeedEnableStereo = false;
		CheckInGameThread();

		if (!FOculusXRHMDModule::GetPluginWrapper().GetInitialized())
		{
			return false;
		}

#if PLATFORM_WINDOWS
		// TODO: This is a temp fix of the case that callers wants to use IsHeadTrackingAllowed() to do something in UGameEngine::Start().
		//  Settings->Flags.bStereoEnabled won't be true until Window.IsValid() and UGameEngine::Tick() starts which is very late.
		//  We might need a better mechanism to decouple Window.IsValid() and Settings->Flags.bStereoEnabled.
		bNeedEnableStereo = !GIsEditor && Flags.bNeedEnableStereo;
#endif
		return (FHeadMountedDisplayBase::IsHeadTrackingAllowed() || bNeedEnableStereo);
	}

	void FOculusXRHMD::OnBeginPlay(FWorldContext& InWorldContext)
	{
		CheckInGameThread();

		CachedViewportWidget.Reset();
		CachedWindow.Reset();

		bHardOcclusionsEnabled = false;
		bSoftOcclusionsEnabled = false;

#if WITH_EDITOR
		// @TODO: add more values here.
		// This call make sense when 'Play' is used from the Editor;
		if (GIsEditor && !GEnableVREditorHacks)
		{
#if PLATFORM_WINDOWS
			const auto ProjectSettings = GetDefault<UGeneralProjectSettings>();
			if (ProjectSettings != nullptr)
			{
				FWindowsPlatformMisc::SetEnvironmentVar(*PROJECT_ID_TELEMETRY, *ProjectSettings->ProjectID.ToString());
			}
#endif
			Settings->BaseOrientation = FQuat::Identity;
			Settings->BaseOffset = FVector::ZeroVector;
			Settings->ColorScale = ovrpVector4f{ 1, 1, 1, 1 };
			Settings->ColorOffset = ovrpVector4f{ 0, 0, 0, 0 };

			// Settings->WorldToMetersScale = InWorldContext.World()->GetWorldSettings()->WorldToMeters;
			// Settings->Flags.bWorldToMetersOverride = false;
			InitDevice();
			ResetMultiPlayerPoses();

			FApp::SetUseVRFocus(true);
			FApp::SetHasVRFocus(true);
			OnStartGameFrame(InWorldContext);
		}
#endif
	}

	void FOculusXRHMD::OnEndPlay(FWorldContext& InWorldContext)
	{
		CheckInGameThread();

#if WITH_EDITOR
		if (GIsEditor && !GEnableVREditorHacks)
		{
			// @todo vreditor: If we add support for starting PIE while in VR Editor, we don't want to kill stereo mode when exiting PIE
			if (Splash->IsShown())
			{
				Splash->HideLoadingScreen();			  // This will only request hiding the screen
				Splash->UpdateLoadingScreen_GameThread(); // Update is needed to complete removing the loading screen
			}
			EnableStereo(false);
			ReleaseDevice();

			FApp::SetUseVRFocus(false);
			FApp::SetHasVRFocus(false);
		}
#endif
	}

	DECLARE_STATS_GROUP(TEXT("Oculus System Metrics"), STATGROUP_OculusSystemMetrics, STATCAT_Advanced);

	DECLARE_FLOAT_COUNTER_STAT_EXTERN(TEXT("App CPU Time (ms)"), STAT_OculusSystem_AppCpuTime, STATGROUP_OculusSystemMetrics, );
	DECLARE_FLOAT_COUNTER_STAT_EXTERN(TEXT("App GPU Time (ms)"), STAT_OculusSystem_AppGpuTime, STATGROUP_OculusSystemMetrics, );
	DECLARE_FLOAT_COUNTER_STAT_EXTERN(TEXT("Compositor CPU Time (ms)"), STAT_OculusSystem_ComCpuTime, STATGROUP_OculusSystemMetrics, );
	DECLARE_FLOAT_COUNTER_STAT_EXTERN(TEXT("Compositor GPU Time (ms)"), STAT_OculusSystem_ComGpuTime, STATGROUP_OculusSystemMetrics, );
	DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("Compositor Dropped Frames"), STAT_OculusSystem_DroppedFrames, STATGROUP_OculusSystemMetrics, );
	DECLARE_FLOAT_COUNTER_STAT_EXTERN(TEXT("System GPU Util %"), STAT_OculusSystem_GpuUtil, STATGROUP_OculusSystemMetrics, );
	DECLARE_FLOAT_COUNTER_STAT_EXTERN(TEXT("System CPU Util Avg %"), STAT_OculusSystem_CpuUtilAvg, STATGROUP_OculusSystemMetrics, );
	DECLARE_FLOAT_COUNTER_STAT_EXTERN(TEXT("System CPU Util Worst %"), STAT_OculusSystem_CpuUtilWorst, STATGROUP_OculusSystemMetrics, );
	DECLARE_FLOAT_COUNTER_STAT_EXTERN(TEXT("CPU Clock Freq (MHz)"), STAT_OculusSystem_CpuFreq, STATGROUP_OculusSystemMetrics, );
	DECLARE_FLOAT_COUNTER_STAT_EXTERN(TEXT("GPU Clock Freq (MHz)"), STAT_OculusSystem_GpuFreq, STATGROUP_OculusSystemMetrics, );
	DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("CPU Clock Level"), STAT_OculusSystem_CpuClockLvl, STATGROUP_OculusSystemMetrics, );
	DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("GPU Clock Level"), STAT_OculusSystem_GpuClockLvl, STATGROUP_OculusSystemMetrics, );
	DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("SpaceWarp Mode"), STAT_OculusSystem_ComSpaceWarpMode, STATGROUP_OculusSystemMetrics, );
	DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("CPU Core0 Util %"), STAT_OculusSystem_CpuCore0Util, STATGROUP_OculusSystemMetrics, );
	DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("CPU Core1 Util %"), STAT_OculusSystem_CpuCore1Util, STATGROUP_OculusSystemMetrics, );
	DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("CPU Core2 Util %"), STAT_OculusSystem_CpuCore2Util, STATGROUP_OculusSystemMetrics, );
	DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("CPU Core3 Util %"), STAT_OculusSystem_CpuCore3Util, STATGROUP_OculusSystemMetrics, );
	DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("CPU Core4 Util %"), STAT_OculusSystem_CpuCore4Util, STATGROUP_OculusSystemMetrics, );
	DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("CPU Core5 Util %"), STAT_OculusSystem_CpuCore5Util, STATGROUP_OculusSystemMetrics, );
	DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("CPU Core6 Util %"), STAT_OculusSystem_CpuCore6Util, STATGROUP_OculusSystemMetrics, );
	DECLARE_DWORD_COUNTER_STAT_EXTERN(TEXT("CPU Core7 Util %"), STAT_OculusSystem_CpuCore7Util, STATGROUP_OculusSystemMetrics, );

	DEFINE_STAT(STAT_OculusSystem_AppCpuTime);
	DEFINE_STAT(STAT_OculusSystem_AppGpuTime);
	DEFINE_STAT(STAT_OculusSystem_ComCpuTime);
	DEFINE_STAT(STAT_OculusSystem_ComGpuTime);
	DEFINE_STAT(STAT_OculusSystem_DroppedFrames);
	DEFINE_STAT(STAT_OculusSystem_GpuUtil);
	DEFINE_STAT(STAT_OculusSystem_CpuUtilAvg);
	DEFINE_STAT(STAT_OculusSystem_CpuUtilWorst);
	DEFINE_STAT(STAT_OculusSystem_CpuFreq);
	DEFINE_STAT(STAT_OculusSystem_GpuFreq);
	DEFINE_STAT(STAT_OculusSystem_CpuClockLvl);
	DEFINE_STAT(STAT_OculusSystem_GpuClockLvl);
	DEFINE_STAT(STAT_OculusSystem_ComSpaceWarpMode);
	DEFINE_STAT(STAT_OculusSystem_CpuCore0Util);
	DEFINE_STAT(STAT_OculusSystem_CpuCore1Util);
	DEFINE_STAT(STAT_OculusSystem_CpuCore2Util);
	DEFINE_STAT(STAT_OculusSystem_CpuCore3Util);
	DEFINE_STAT(STAT_OculusSystem_CpuCore4Util);
	DEFINE_STAT(STAT_OculusSystem_CpuCore5Util);
	DEFINE_STAT(STAT_OculusSystem_CpuCore6Util);
	DEFINE_STAT(STAT_OculusSystem_CpuCore7Util);

	void UpdateOculusSystemMetricsStats(FOculusXRPerformanceMetrics& PerformanceMetrics)
	{
		if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized() == ovrpBool_False)
		{
			return;
		}

		if (PerformanceMetrics.CpuCoreUtil.Num() == 0)
		{
			PerformanceMetrics.CpuCoreUtil.Init(0, 8);
		}

		ovrpBool bIsSupported;
		float valueFloat = 0;
		int valueInt = 0;
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_App_CpuTime_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_App_CpuTime_Float, &valueFloat)))
			{
				PerformanceMetrics.AppCpuTime = valueFloat * 1000;
				SET_FLOAT_STAT(STAT_OculusSystem_AppCpuTime, PerformanceMetrics.AppCpuTime);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_App_GpuTime_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_App_GpuTime_Float, &valueFloat)))
			{
				PerformanceMetrics.AppGpuTime = valueFloat * 1000;
				SET_FLOAT_STAT(STAT_OculusSystem_AppGpuTime, PerformanceMetrics.AppGpuTime);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Compositor_CpuTime_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_Compositor_CpuTime_Float, &valueFloat)))
			{
				PerformanceMetrics.ComCpuTime = valueFloat * 1000;
				SET_FLOAT_STAT(STAT_OculusSystem_ComCpuTime, PerformanceMetrics.ComCpuTime);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Compositor_GpuTime_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_Compositor_GpuTime_Float, &valueFloat)))
			{
				PerformanceMetrics.ComGpuTime = valueFloat * 1000;
				SET_FLOAT_STAT(STAT_OculusSystem_ComGpuTime, PerformanceMetrics.ComGpuTime);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Compositor_DroppedFrameCount_Int, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsInt(ovrpPerfMetrics_Compositor_DroppedFrameCount_Int, &valueInt)))
			{
				PerformanceMetrics.DroppedFrames = valueInt;
				SET_DWORD_STAT(STAT_OculusSystem_DroppedFrames, PerformanceMetrics.DroppedFrames);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_System_GpuUtilPercentage_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_System_GpuUtilPercentage_Float, &valueFloat)))
			{
				PerformanceMetrics.GpuUtil = valueFloat * 100;
				SET_FLOAT_STAT(STAT_OculusSystem_GpuUtil, PerformanceMetrics.GpuUtil);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_System_CpuUtilAveragePercentage_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_System_CpuUtilAveragePercentage_Float, &valueFloat)))
			{
				PerformanceMetrics.CpuUtilAvg = valueFloat * 100;
				SET_FLOAT_STAT(STAT_OculusSystem_CpuUtilAvg, PerformanceMetrics.CpuUtilAvg);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_System_CpuUtilWorstPercentage_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_System_CpuUtilWorstPercentage_Float, &valueFloat)))
			{
				PerformanceMetrics.CpuUtilWorst = valueFloat * 100;
				SET_FLOAT_STAT(STAT_OculusSystem_CpuUtilWorst, PerformanceMetrics.CpuUtilWorst);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Device_CpuClockFrequencyInMHz_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_Device_CpuClockFrequencyInMHz_Float, &valueFloat)))
			{
				SET_FLOAT_STAT(STAT_OculusSystem_CpuFreq, valueFloat);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Device_GpuClockFrequencyInMHz_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_Device_GpuClockFrequencyInMHz_Float, &valueFloat)))
			{
				SET_FLOAT_STAT(STAT_OculusSystem_GpuFreq, valueFloat);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Device_CpuClockLevel_Int, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsInt(ovrpPerfMetrics_Device_CpuClockLevel_Int, &valueInt)))
			{
				SET_DWORD_STAT(STAT_OculusSystem_CpuClockLvl, valueInt);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Device_GpuClockLevel_Int, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsInt(ovrpPerfMetrics_Device_GpuClockLevel_Int, &valueInt)))
			{
				SET_DWORD_STAT(STAT_OculusSystem_GpuClockLvl, valueInt);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Compositor_SpaceWarp_Mode_Int, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsInt(ovrpPerfMetrics_Compositor_SpaceWarp_Mode_Int, &valueInt)))
			{
				PerformanceMetrics.ComSpaceWarpMode = valueInt;
				SET_DWORD_STAT(STAT_OculusSystem_ComSpaceWarpMode, PerformanceMetrics.ComSpaceWarpMode);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Device_CpuCore0UtilPercentage_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_Device_CpuCore0UtilPercentage_Float, &valueFloat)))
			{
				PerformanceMetrics.CpuCoreUtil[0] = valueFloat;
				SET_FLOAT_STAT(STAT_OculusSystem_CpuCore0Util, PerformanceMetrics.CpuCoreUtil[0]);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Device_CpuCore1UtilPercentage_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_Device_CpuCore1UtilPercentage_Float, &valueFloat)))
			{
				PerformanceMetrics.CpuCoreUtil[1] = valueFloat;
				SET_FLOAT_STAT(STAT_OculusSystem_CpuCore1Util, PerformanceMetrics.CpuCoreUtil[1]);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Device_CpuCore2UtilPercentage_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_Device_CpuCore2UtilPercentage_Float, &valueFloat)))
			{
				PerformanceMetrics.CpuCoreUtil[2] = valueFloat;
				SET_FLOAT_STAT(STAT_OculusSystem_CpuCore2Util, PerformanceMetrics.CpuCoreUtil[2]);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Device_CpuCore3UtilPercentage_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_Device_CpuCore3UtilPercentage_Float, &valueFloat)))
			{
				PerformanceMetrics.CpuCoreUtil[3] = valueFloat;
				SET_FLOAT_STAT(STAT_OculusSystem_CpuCore3Util, PerformanceMetrics.CpuCoreUtil[3]);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Device_CpuCore4UtilPercentage_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_Device_CpuCore4UtilPercentage_Float, &valueFloat)))
			{
				PerformanceMetrics.CpuCoreUtil[4] = valueFloat;
				SET_FLOAT_STAT(STAT_OculusSystem_CpuCore4Util, PerformanceMetrics.CpuCoreUtil[4]);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Device_CpuCore5UtilPercentage_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_Device_CpuCore5UtilPercentage_Float, &valueFloat)))
			{
				PerformanceMetrics.CpuCoreUtil[5] = valueFloat;
				SET_FLOAT_STAT(STAT_OculusSystem_CpuCore5Util, PerformanceMetrics.CpuCoreUtil[5]);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Device_CpuCore6UtilPercentage_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_Device_CpuCore6UtilPercentage_Float, &valueFloat)))
			{
				PerformanceMetrics.CpuCoreUtil[6] = valueFloat;
				SET_FLOAT_STAT(STAT_OculusSystem_CpuCore6Util, PerformanceMetrics.CpuCoreUtil[6]);
			}
		}
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().IsPerfMetricsSupported(ovrpPerfMetrics_Device_CpuCore7UtilPercentage_Float, &bIsSupported)) && bIsSupported == ovrpBool_True)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetPerfMetricsFloat(ovrpPerfMetrics_Device_CpuCore7UtilPercentage_Float, &valueFloat)))
			{
				PerformanceMetrics.CpuCoreUtil[7] = valueFloat;
				SET_FLOAT_STAT(STAT_OculusSystem_CpuCore7Util, PerformanceMetrics.CpuCoreUtil[7]);
			}
		}
	}

	const FOculusXRPerformanceMetrics FOculusXRHMD::GetPerformanceMetrics() const
	{
		return PerformanceMetrics;
	}

	void FOculusXRHMD::OnBeginRendering_GameThread()
	{
		CheckInGameThread();
		// We need to make sure we keep the Wait/Begin/End triplet in sync, so here we signal that we
		// can wait for the next frame in the next tick. Without this signal it's possible that two ticks
		// happen before the next frame is actually rendered.
		bShouldWait_GameThread = true;
	}

	bool FOculusXRHMD::OnStartGameFrame(FWorldContext& InWorldContext)
	{
#if WITH_EDITOR
		// In the editor there can be multiple worlds.  An editor world, pie worlds, other viewport worlds for editor pages.
		// XR hardware can only be running with one of them.
		if (GIsEditor && GEditor && GEditor->GetPIEWorldContext() != nullptr)
		{
			if (!InWorldContext.bIsPrimaryPIEInstance)
			{
				return false;
			}
		}
#endif // WITH_EDITOR

		CheckInGameThread();

		if (IsEngineExitRequested())
		{
			return false;
		}

		UpdateOculusSystemMetricsStats(PerformanceMetrics);

		RefreshTrackingToWorldTransform(InWorldContext);

		// check if HMD is marked as invalid and needs to be killed.
		ovrpBool appShouldRecreateDistortionWindow;

		if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized() && OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetAppShouldRecreateDistortionWindow2(&appShouldRecreateDistortionWindow)) && appShouldRecreateDistortionWindow)
		{
			DoEnableStereo(false);
			ReleaseDevice();

			if (!OCFlags.DisplayLostDetected)
			{
				FCoreDelegates::VRHeadsetLost.Broadcast();
				OCFlags.DisplayLostDetected = true;
			}

			Flags.bNeedEnableStereo = true;
		}
#if PLATFORM_ANDROID
		Flags.bNeedEnableStereo = true; // !!!
#endif

		check(Settings.IsValid());
		if (!Settings->IsStereoEnabled())
		{
			FApp::SetUseVRFocus(false);
			FApp::SetHasVRFocus(false);
		}

#if OCULUS_STRESS_TESTS_ENABLED
		FStressTester::TickCPU_GameThread(this);
#endif

		if (bShutdownRequestQueued)
		{
			bShutdownRequestQueued = false;
			DoSessionShutdown();
		}

		if (!InWorldContext.World() || (!(GEnableVREditorHacks && InWorldContext.WorldType == EWorldType::Editor) && !InWorldContext.World()->IsGameWorld())) // @todo vreditor: (Also see OnEndGameFrame()) Kind of a hack here so we can use VR in editor viewports.  We need to consider when running GameWorld viewports inside the editor with VR.
		{
			// ignore all non-game worlds
			return false;
		}

		bool bStereoEnabled = Settings->Flags.bStereoEnabled;
		bool bStereoDesired = bStereoEnabled;

		if (Flags.bNeedEnableStereo)
		{
			bStereoDesired = true;
		}

		if (bStereoDesired && (Flags.bNeedDisableStereo || !Settings->Flags.bHMDEnabled))
		{
			bStereoDesired = false;
		}

		bool bStereoDesiredAndIsConnected = bStereoDesired;

		if (bStereoDesired && !(bStereoEnabled ? IsHMDActive() : IsHMDEnabled()))
		{
			bStereoDesiredAndIsConnected = false;
		}

		Flags.bNeedEnableStereo = false;
		Flags.bNeedDisableStereo = false;

		if (bStereoEnabled != bStereoDesiredAndIsConnected)
		{
			bStereoEnabled = DoEnableStereo(bStereoDesiredAndIsConnected);
		}

		// Keep trying to enable stereo until we succeed
		Flags.bNeedEnableStereo = bStereoDesired && !bStereoEnabled;

		if (!Settings->IsStereoEnabled() && !Settings->Flags.bHeadTrackingEnforced)
		{
			return false;
		}

		if (Flags.bApplySystemOverridesOnStereo)
		{
			ApplySystemOverridesOnStereo();
			Flags.bApplySystemOverridesOnStereo = false;
		}

		CachedWorldToMetersScale = InWorldContext.World()->GetWorldSettings()->WorldToMeters;

		// this should have already happened in FOculusXRInput, so this is usually a no-op.
		StartGameFrame_GameThread();

		bool retval = true;

		UpdateHMDEvents();

		if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized())
		{
			if (OCFlags.DisplayLostDetected)
			{
				FCoreDelegates::VRHeadsetReconnected.Broadcast();
				OCFlags.DisplayLostDetected = false;
			}

			if (OCFlags.NeedSetTrackingOrigin)
			{
				SetTrackingOrigin(TrackingOrigin);
			}

			ovrpBool bAppHasVRFocus = ovrpBool_False;
			FOculusXRHMDModule::GetPluginWrapper().GetAppHasVrFocus2(&bAppHasVRFocus);

			FApp::SetUseVRFocus(true);
			FApp::SetHasVRFocus(bAppHasVRFocus != ovrpBool_False);

			// Do not pause if Editor is running (otherwise it will become very laggy)
			if (!GIsEditor)
			{
				if (!bAppHasVRFocus)
				{
					// not visible,
					if (!Settings->Flags.bPauseRendering)
					{
						UE_LOG(LogHMD, Log, TEXT("The app went out of VR focus, seizing rendering..."));
					}
				}
				else if (Settings->Flags.bPauseRendering)
				{
					UE_LOG(LogHMD, Log, TEXT("The app got VR focus, restoring rendering..."));
				}
				if (OCFlags.NeedSetFocusToGameViewport)
				{
					if (bAppHasVRFocus)
					{
						UE_LOG(LogHMD, Log, TEXT("Setting user focus to game viewport since session status is visible..."));
						FSlateApplication::Get().SetAllUserFocusToGameViewport();
						OCFlags.NeedSetFocusToGameViewport = false;
					}
				}

				bool bPrevPause = Settings->Flags.bPauseRendering;
				Settings->Flags.bPauseRendering = !bAppHasVRFocus;

				if (Settings->Flags.bPauseRendering && (GEngine->GetMaxFPS() != OCULUS_PAUSED_IDLE_FPS))
				{
					GEngine->SetMaxFPS(OCULUS_PAUSED_IDLE_FPS);
				}

				if (bPrevPause != Settings->Flags.bPauseRendering)
				{
					APlayerController* const PC = GEngine->GetFirstLocalPlayerController(InWorldContext.World());
					if (Settings->Flags.bPauseRendering)
					{
						// focus is lost
						GEngine->SetMaxFPS(OCULUS_PAUSED_IDLE_FPS);

						if (!FCoreDelegates::ApplicationWillEnterBackgroundDelegate.IsBound())
						{
							OCFlags.AppIsPaused = false;
							// default action: set pause if not already paused
							if (PC && !PC->IsPaused())
							{
								PC->SetPause(true);
								OCFlags.AppIsPaused = true;
							}
						}
						else
						{
							FCoreDelegates::ApplicationWillEnterBackgroundDelegate.Broadcast();
						}
					}
					else
					{
						// focus is gained
						GEngine->SetMaxFPS(0);

						if (!FCoreDelegates::ApplicationHasEnteredForegroundDelegate.IsBound())
						{
							// default action: unpause if was paused by the plugin
							if (PC && OCFlags.AppIsPaused)
							{
								PC->SetPause(false);
							}
							OCFlags.AppIsPaused = false;
						}
						else
						{
							FCoreDelegates::ApplicationHasEnteredForegroundDelegate.Broadcast();
						}
					}
				}
			}

			ovrpBool AppShouldQuit;
			ovrpBool AppShouldRecenter;

			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetAppShouldQuit2(&AppShouldQuit)) && AppShouldQuit || OCFlags.EnforceExit)
			{
				FPlatformMisc::LowLevelOutputDebugString(TEXT("OculusXRHMD plugin requested exit (ShouldQuit == 1)\n"));
#if WITH_EDITOR
				if (GIsEditor)
				{
					FSceneViewport* SceneVP = FindSceneViewport();
					if (SceneVP && SceneVP->IsStereoRenderingAllowed())
					{
						TSharedPtr<SWindow> Window = SceneVP->FindWindow();
						Window->RequestDestroyWindow();
					}
				}
				else
#endif // WITH_EDITOR
				{
					// ApplicationWillTerminateDelegate will fire from inside of the RequestExit
					FPlatformMisc::RequestExit(false);
				}
				OCFlags.EnforceExit = false;
				retval = false;
			}
			else if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetAppShouldRecenter2(&AppShouldRecenter)) && AppShouldRecenter)
			{
				FPlatformMisc::LowLevelOutputDebugString(TEXT("OculusXRHMD plugin was requested to recenter\n"));
				if (FCoreDelegates::VRHeadsetRecenter.IsBound())
				{
					FCoreDelegates::VRHeadsetRecenter.Broadcast();
				}
				else
				{
					ResetOrientationAndPosition();
				}

				// Call FOculusXRHMDModule::GetPluginWrapper().RecenterTrackingOrigin2 to clear AppShouldRecenter flag
				FOculusXRHMDModule::GetPluginWrapper().RecenterTrackingOrigin2(ovrpRecenterFlag_IgnoreAll);
			}

			UpdateHMDWornState();
		}

#if OCULUS_MR_SUPPORTED_PLATFORMS
		if (FOculusXRHMDModule::GetPluginWrapper().GetMixedRealityInitialized())
		{
			FOculusXRHMDModule::GetPluginWrapper().UpdateExternalCamera();
		}
#endif

		if (IsEngineExitRequested())
		{
			PreShutdown();
		}

		return retval;
	}

	void FOculusXRHMD::DoSessionShutdown()
	{
		// Release resources
		ExecuteOnRenderThread([this]() {
			ExecuteOnRHIThread([this]() {
				for (int32 LayerIndex = 0; LayerIndex < Layers_RenderThread.Num(); LayerIndex++)
				{
					Layers_RenderThread[LayerIndex]->ReleaseResources_RHIThread();
				}

				for (int32 LayerIndex = 0; LayerIndex < Layers_RHIThread.Num(); LayerIndex++)
				{
					Layers_RHIThread[LayerIndex]->ReleaseResources_RHIThread();
				}

				if (Splash.IsValid())
				{
					Splash->ReleaseResources_RHIThread();
				}

				if (CustomPresent)
				{
					CustomPresent->ReleaseResources_RHIThread();
				}

				Settings_RHIThread.Reset();
				Frame_RHIThread.Reset();
				Layers_RHIThread.Reset();
			});

			Settings_RenderThread.Reset();
			Frame_RenderThread.Reset();
			Layers_RenderThread.Reset();
			EyeLayer_RenderThread.Reset();

			DeferredDeletion.HandleLayerDeferredDeletionQueue_RenderThread(true);

			EnableInsightPassthrough_RenderThread(false);
		});

		Frame.Reset();
		NextFrameToRender.Reset();
		LastFrameToRender.Reset();

#if !UE_BUILD_SHIPPING
		UDebugDrawService::Unregister(DrawDebugDelegateHandle);
#endif

		// The Editor may release VR focus in OnEndPlay
		if (!GIsEditor)
		{
			FApp::SetUseVRFocus(false);
			FApp::SetHasVRFocus(false);
		}

		ShutdownSession();
	}

	bool FOculusXRHMD::OnEndGameFrame(FWorldContext& InWorldContext)
	{
		CheckInGameThread();

		FGameFrame* const CurrentGameFrame = Frame.Get();

		if (CurrentGameFrame)
		{
			// don't use the cached value, as it could be affected by the player's position, so we update it here at the latest point in the game frame
			CurrentGameFrame->TrackingToWorld = ComputeTrackingToWorldTransform(InWorldContext);
			CurrentGameFrame->LastTrackingToWorld = LastTrackingToWorld;
			LastTrackingToWorld = CurrentGameFrame->TrackingToWorld;
		}
		else
		{
			return false;
		}

		if (!InWorldContext.World() || (!(GEnableVREditorHacks && InWorldContext.WorldType == EWorldType::Editor) && !InWorldContext.World()->IsGameWorld()))
		{
			// ignore all non-game worlds
			return false;
		}

		FinishGameFrame_GameThread();

		return true;
	}

	FVector2D FOculusXRHMD::GetPlayAreaBounds(EHMDTrackingOrigin::Type Origin) const
	{
		ovrpVector3f Dimensions;

		if (Origin == EHMDTrackingOrigin::Stage && OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetBoundaryDimensions2(ovrpBoundary_PlayArea, &Dimensions)))
		{
			Dimensions.z *= -1.0;
			FVector Bounds = ConvertVector_M2U(Dimensions);
			return FVector2D(Bounds.X, Bounds.Z);
		}
		return FVector2D::ZeroVector;
	}

	bool FOculusXRHMD::IsHMDEnabled() const
	{
		CheckInGameThread();

		return (Settings->Flags.bHMDEnabled);
	}

	EHMDWornState::Type FOculusXRHMD::GetHMDWornState()
	{
		ovrpBool userPresent;

		if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized() && OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetUserPresent2(&userPresent)) && userPresent)
		{
			return EHMDWornState::Worn;
		}
		else
		{
			return EHMDWornState::NotWorn;
		}
	}

	void FOculusXRHMD::EnableHMD(bool enable)
	{
		CheckInGameThread();

		Settings->Flags.bHMDEnabled = enable;
		if (!Settings->Flags.bHMDEnabled)
		{
			EnableStereo(false);
		}
	}

	bool FOculusXRHMD::GetHMDMonitorInfo(MonitorInfo& MonitorDesc)
	{
		CheckInGameThread();

		MonitorDesc.MonitorName = FString("Oculus Window");
		MonitorDesc.MonitorId = 0;
		MonitorDesc.DesktopX = MonitorDesc.DesktopY = 0;
		MonitorDesc.ResolutionX = MonitorDesc.ResolutionY = 0;
		MonitorDesc.WindowSizeX = MonitorDesc.WindowSizeY = 0;

		if (Settings.IsValid())
		{
			MonitorDesc.ResolutionX = MonitorDesc.WindowSizeX = Settings->RenderTargetSize.X;
			MonitorDesc.ResolutionY = MonitorDesc.WindowSizeY = Settings->RenderTargetSize.Y;
		}

		return true;
	}

	void FOculusXRHMD::GetFieldOfView(float& InOutHFOVInDegrees, float& InOutVFOVInDegrees) const

	{
		ovrpFrustum2f Frustum;

		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetNodeFrustum2(ovrpNode_EyeCenter, &Frustum)))
		{
			InOutVFOVInDegrees = FMath::RadiansToDegrees(FMath::Atan(Frustum.Fov.UpTan) + FMath::Atan(Frustum.Fov.DownTan));
			InOutHFOVInDegrees = FMath::RadiansToDegrees(FMath::Atan(Frustum.Fov.LeftTan) + FMath::Atan(Frustum.Fov.RightTan));
		}
	}

	void FOculusXRHMD::SetInterpupillaryDistance(float NewInterpupillaryDistance)
	{
		CheckInGameThread();

		if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized())
		{
			FOculusXRHMDModule::GetPluginWrapper().SetUserIPD2(NewInterpupillaryDistance);
		}
	}

	float FOculusXRHMD::GetInterpupillaryDistance() const
	{
		CheckInGameThread();

		float UserIPD;

		if (!FOculusXRHMDModule::GetPluginWrapper().GetInitialized() || OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetUserIPD2(&UserIPD)))
		{
			return 0.0f;
		}

		return UserIPD;
	}

	bool FOculusXRHMD::GetHMDDistortionEnabled(EShadingPath /* ShadingPath */) const
	{
		return false;
	}

	bool FOculusXRHMD::IsChromaAbCorrectionEnabled() const
	{
		CheckInGameThread();

		return true;
	}

	bool FOculusXRHMD::HasHiddenAreaMesh() const
	{
		if (IsInParallelRenderingThread())
		{
			if (ShouldDisableHiddenAndVisibileAreaMeshForSpectatorScreen_RenderThread())
			{
				return false;
			}
		}

		return HiddenAreaMeshes[0].IsValid() && HiddenAreaMeshes[1].IsValid();
	}

	bool FOculusXRHMD::HasVisibleAreaMesh() const
	{
		if (IsInParallelRenderingThread())
		{
			if (ShouldDisableHiddenAndVisibileAreaMeshForSpectatorScreen_RenderThread())
			{
				return false;
			}
		}

		return VisibleAreaMeshes[0].IsValid() && VisibleAreaMeshes[1].IsValid();
	}

	static void DrawOcclusionMesh(FRHICommandList& RHICmdList, int32 ViewIndex, const FHMDViewMesh MeshAssets[], int32 InstanceCount = 1)
	{
		check(ViewIndex != INDEX_NONE);

		const uint32 MeshIndex = (ViewIndex == EStereoscopicEye::eSSE_LEFT_EYE) ? 0 : 1;
		const FHMDViewMesh& Mesh = MeshAssets[MeshIndex];
		check(Mesh.IsValid());

		RHICmdList.SetStreamSource(0, Mesh.VertexBufferRHI, 0);
		RHICmdList.DrawIndexedPrimitive(Mesh.IndexBufferRHI, 0, 0, Mesh.NumVertices, 0, Mesh.NumTriangles, InstanceCount);
	}

#ifdef WITH_OCULUS_BRANCH
	void FOculusXRHMD::DrawHiddenAreaMesh(FRHICommandList& RHICmdList, int32 ViewIndex, int32 InstanceCount) const
	{
		DrawOcclusionMesh(RHICmdList, ViewIndex, HiddenAreaMeshes, InstanceCount);
	}

	void FOculusXRHMD::DrawVisibleAreaMesh(FRHICommandList& RHICmdList, int32 ViewIndex, int32 InstanceCount) const
	{
		DrawOcclusionMesh(RHICmdList, ViewIndex, VisibleAreaMeshes, InstanceCount);
	}
#else
	void FOculusXRHMD::DrawHiddenAreaMesh(FRHICommandList& RHICmdList, int32 ViewIndex) const
	{
		DrawOcclusionMesh(RHICmdList, ViewIndex, HiddenAreaMeshes);
	}

	void FOculusXRHMD::DrawVisibleAreaMesh(FRHICommandList& RHICmdList, int32 ViewIndex) const
	{
		DrawOcclusionMesh(RHICmdList, ViewIndex, VisibleAreaMeshes);
	}
#endif // WITH_OCULUS_BRANCH

	float FOculusXRHMD::GetPixelDenity() const
	{
		if (IsInGameThread())
		{
			return Settings.IsValid() ? Settings->PixelDensity : 1.0f;
		}
		else
		{
			return Settings_RenderThread.IsValid() ? Settings_RenderThread->PixelDensity : 1.0f;
		}
	}

	void FOculusXRHMD::SetPixelDensity(const float NewPixelDensity)
	{
		CheckInGameThread();
		Settings->SetPixelDensity(NewPixelDensity);
	}

	FIntPoint FOculusXRHMD::GetIdealRenderTargetSize() const
	{
		if (IsInGameThread())
		{
			return Settings.IsValid() ? Settings->RenderTargetSize : 1.0f;
		}
		else
		{
			return Settings_RenderThread.IsValid() ? Settings_RenderThread->RenderTargetSize : 1.0f;
		}
	}

	void FOculusXRHMD::GetMotionControllerData(UObject* WorldContext, const EControllerHand Hand, FXRMotionControllerData& MotionControllerData)
	{
		MotionControllerData.DeviceName = OculusSystemName;
		MotionControllerData.ApplicationInstanceID = FApp::GetInstanceId();
		MotionControllerData.DeviceVisualType = EXRVisualType::Controller;
		MotionControllerData.TrackingStatus = ETrackingStatus::NotTracked;
		MotionControllerData.HandIndex = Hand;
		MotionControllerData.bValid = false;

		if ((Hand == EControllerHand::Left) || (Hand == EControllerHand::Right))
		{
			const FName MotionControllerName("OculusXRInputDevice");
			TArray<IMotionController*> MotionControllers = IModularFeatures::Get().GetModularFeatureImplementations<IMotionController>(IMotionController::GetModularFeatureName());
			const IMotionController* MotionController = nullptr;
			for (const IMotionController* Itr : MotionControllers)
			{
				if (Itr->GetMotionControllerDeviceTypeName() == MotionControllerName)
				{
					MotionController = Itr;
					break;
				}
			}

			const float WorldToMeters = GetWorldToMetersScale();
			if (MotionController)
			{
				bool bSuccess = false;
				FVector Position = FVector::ZeroVector;
				FRotator Rotation = FRotator::ZeroRotator;
				const FTransform TrackingToWorld = GetTrackingToWorldTransform();
				const FName AimSource = Hand == EControllerHand::Left ? FName("LeftAim") : FName("RightAim");
				bSuccess = MotionController->GetControllerOrientationAndPosition(0, AimSource, Rotation, Position, WorldToMeters);
				if (bSuccess)
				{
					MotionControllerData.AimPosition = TrackingToWorld.TransformPosition(Position);
					MotionControllerData.AimRotation = TrackingToWorld.TransformRotation(FQuat(Rotation));
				}
				MotionControllerData.bValid |= bSuccess;

				FName GripSource = Hand == EControllerHand::Left ? FName("LeftGrip") : FName("RightGrip");
				bSuccess = MotionController->GetControllerOrientationAndPosition(0, GripSource, Rotation, Position, WorldToMeters);
				if (bSuccess)
				{
					MotionControllerData.GripPosition = TrackingToWorld.TransformPosition(Position);
					MotionControllerData.GripRotation = TrackingToWorld.TransformRotation(FQuat(Rotation));
				}
				MotionControllerData.bValid |= bSuccess;

				MotionControllerData.TrackingStatus = MotionController->GetControllerTrackingStatus(0, GripSource);
			}
		}
	}

	bool FOculusXRHMD::IsStereoEnabled() const
	{
		if (IsInGameThread())
		{
			return Settings.IsValid() && Settings->IsStereoEnabled();
		}
		else
		{
			return Settings_RenderThread.IsValid() && Settings_RenderThread->IsStereoEnabled();
		}
	}

	bool FOculusXRHMD::IsStereoEnabledOnNextFrame() const
	{
		// !!!

		return Settings.IsValid() && Settings->IsStereoEnabled();
	}

	bool FOculusXRHMD::EnableStereo(bool bStereo)
	{
		CheckInGameThread();

		if (bStereo)
		{
			LoadFromSettings();
#if PLATFORM_WINDOWS
			FOculusXRHMDModule::GetPluginWrapper().SetTrackingPoseEnabledForInvisibleSession(GetMutableDefault<UOculusXRHMDRuntimeSettings>()->bUpdateHeadPoseForInactivePlayer);
#endif
		}

		return DoEnableStereo(bStereo);
	}

	void FOculusXRHMD::AdjustViewRect(int32 ViewIndex, int32& X, int32& Y, uint32& SizeX, uint32& SizeY) const
	{
		if (Settings.IsValid())
		{
			X = Settings->EyeUnscaledRenderViewport[ViewIndex].Min.X;
			Y = Settings->EyeUnscaledRenderViewport[ViewIndex].Min.Y;
			SizeX = Settings->EyeUnscaledRenderViewport[ViewIndex].Size().X;
			SizeY = Settings->EyeUnscaledRenderViewport[ViewIndex].Size().Y;
		}
		else
		{
			SizeX = SizeX / 2;
			X += SizeX * ViewIndex;
		}
	}

	FIntRect FOculusXRHMD::GetAsymmetricViewRect(const int32 ViewIndex, const FIntRect& ViewRect)
	{
		FIntRect AsymmetricViewRect = ViewRect;
		if (Settings_RenderThread.IsValid() && Frame_RenderThread.IsValid())
		{
			const ovrpFovf& EyeBufferFov = Frame_RenderThread->Fov[ViewIndex];
			const ovrpFovf& FrameFov = Frame_RenderThread->SymmetricFov[ViewIndex];
			const int32 ViewPixelSize = AsymmetricViewRect.Size().X;

			// if using symmetric rendering, only send UVs of the asymmetrical subrect (the rest isn't useful) to the VR runtime
			const float symTanSize = FrameFov.LeftTan + FrameFov.RightTan;

			AsymmetricViewRect.Min.X += (FrameFov.LeftTan - EyeBufferFov.LeftTan) * (ViewPixelSize / symTanSize);
			AsymmetricViewRect.Max.X -= (FrameFov.RightTan - EyeBufferFov.RightTan) * (ViewPixelSize / symTanSize);
		}

		return AsymmetricViewRect;
	}

	void FOculusXRHMD::SetFinalViewRect(FRHICommandListImmediate& RHICmdList, const int32 ViewIndex, const FIntRect& FinalViewRect)
	{
		CheckInRenderThread();
		if (ViewIndex == INDEX_NONE || ViewIndex < 0 || ViewIndex >= ovrpEye_Count)
		{
			return;
		}

		FIntRect AsymmetricViewRect = GetAsymmetricViewRect(ViewIndex, FinalViewRect);

		if (Settings_RenderThread.IsValid())
		{
			Settings_RenderThread->EyeRenderViewport[ViewIndex] = AsymmetricViewRect;
		}

		// Called after RHIThread has already started.  Need to update Settings_RHIThread as well.
		ExecuteOnRHIThread_DoNotWait([this, ViewIndex, AsymmetricViewRect]() {
			CheckInRHIThread();

			if (Settings_RHIThread.IsValid())
			{
				Settings_RHIThread->EyeRenderViewport[ViewIndex] = AsymmetricViewRect;
			}
		});
	}

#ifdef WITH_OCULUS_BRANCH
	void FOculusXRHMD::CalculateScissorRect(const int32 ViewIndex, const FIntRect& ViewRect, FIntRect& OutRect)
	{
		CheckInRenderThread();
		if (ViewIndex == INDEX_NONE || ViewIndex < 0 || ViewIndex >= ovrpEye_Count)
		{
			return;
		}

		OutRect = GetAsymmetricViewRect(ViewIndex, ViewRect);
	}
#endif // WITH_OCULUS_BRANCH

	void FOculusXRHMD::CalculateStereoViewOffset(const int32 ViewIndex, FRotator& ViewRotation, const float WorldToMeters, FVector& ViewLocation)
	{
		// This method is called from GetProjectionData on a game thread.
		if (InGameThread() && ViewIndex == EStereoscopicEye::eSSE_LEFT_EYE && NextFrameToRender.IsValid())
		{
			// Inverse out GameHeadPose.Rotation since PlayerOrientation already contains head rotation.
			FQuat HeadOrientation = FQuat::Identity;
			FVector HeadPosition;

			GetCurrentPose(HMDDeviceId, HeadOrientation, HeadPosition);

			NextFrameToRender->HeadOrientation = HeadOrientation;
			NextFrameToRender->PlayerOrientation = LastPlayerOrientation = ViewRotation.Quaternion() * HeadOrientation.Inverse();
			NextFrameToRender->PlayerLocation = LastPlayerLocation = ViewLocation;
		}

		FHeadMountedDisplayBase::CalculateStereoViewOffset(ViewIndex, ViewRotation, WorldToMeters, ViewLocation);
	}

	FMatrix FOculusXRHMD::GetStereoProjectionMatrix(int32 ViewIndex) const
	{
		CheckInGameThread();

		check(IsStereoEnabled());

		FMatrix proj = (ViewIndex == EStereoscopicEye::eSSE_MONOSCOPIC) ? ToFMatrix(Settings->MonoProjectionMatrix) : ToFMatrix(Settings->EyeProjectionMatrices[ViewIndex]);

		// correct far and near planes for reversed-Z projection matrix
		const float WorldScale = GetWorldToMetersScale() * (1.0 / 100.0f); // physical scale is 100 UUs/meter
		float InNearZ = GNearClippingPlane * WorldScale;

		proj.M[3][3] = 0.0f;
		proj.M[2][3] = 1.0f;

		proj.M[2][2] = 0.0f;
		proj.M[3][2] = InNearZ;

		return proj;
	}

	void FOculusXRHMD::InitCanvasFromView(FSceneView* InView, UCanvas* Canvas)
	{
		// This is used for placing small HUDs (with names)
		// over other players (for example, in Capture Flag).
		// HmdOrientation should be initialized by GetCurrentOrientation (or
		// user's own value).
	}

	void FOculusXRHMD::RenderTexture_RenderThread(class FRHICommandListImmediate& RHICmdList, class FRHITexture* BackBuffer, class FRHITexture* SrcTexture, FVector2D WindowSize) const
	{
		CheckInRenderThread();
		check(CustomPresent);

#if PLATFORM_ANDROID
		return;
#endif

		if (SpectatorScreenController)
		{
			SpectatorScreenController->RenderSpectatorScreen_RenderThread(RHICmdList, BackBuffer, SrcTexture, WindowSize);
		}
	}

	FVector2D FOculusXRHMD::GetEyeCenterPoint_RenderThread(int32 ViewIndex) const
	{
		CheckInRenderThread();

		check(IsStereoEnabled() || IsHeadTrackingEnforced());

		// Don't use GetStereoProjectionMatrix because it is game thread only on oculus, we also don't need the zplane adjustments for this.
		const FMatrix StereoProjectionMatrix = ToFMatrix(Settings_RenderThread->EyeProjectionMatrices[ViewIndex]);

		// 0,0,1 is the straight ahead point, wherever it maps to is the center of the projection plane in -1..1 coordinates.  -1,-1 is bottom left.
		const FVector4 ScreenCenter = StereoProjectionMatrix.TransformPosition(FVector(0.0f, 0.0f, 1.0f));
		// transform into 0-1 screen coordinates 0,0 is top left.
		const FVector2D CenterPoint(0.5f + (ScreenCenter.X / 2.0f), 0.5f - (ScreenCenter.Y / 2.0f));

		return CenterPoint;
	}

	FIntRect FOculusXRHMD::GetFullFlatEyeRect_RenderThread(FTexture2DRHIRef EyeTexture) const
	{
		CheckInRenderThread();

		// Rift does this differently than other platforms, it already has an idea of what rectangle it wants to use stored.
		FIntRect& EyeRect = Settings_RenderThread->EyeRenderViewport[0];

		// But the rectangle rift specifies has corners cut off, so we will crop a little more.
		if (ShouldDisableHiddenAndVisibileAreaMeshForSpectatorScreen_RenderThread())
		{
			return EyeRect;
		}
		else
		{
			static FVector2D SrcNormRectMin(0.05f, 0.0f);
			static FVector2D SrcNormRectMax(0.95f, 1.0f);
			const int32 SizeX = EyeRect.Max.X - EyeRect.Min.X;
			const int32 SizeY = EyeRect.Max.Y - EyeRect.Min.Y;
			return FIntRect(EyeRect.Min.X + SizeX * SrcNormRectMin.X, EyeRect.Min.Y + SizeY * SrcNormRectMin.Y, EyeRect.Min.X + SizeX * SrcNormRectMax.X, EyeRect.Min.Y + SizeY * SrcNormRectMax.Y);
		}
	}

	void FOculusXRHMD::CopyTexture_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture2D* SrcTexture, FIntRect SrcRect, FRHITexture2D* DstTexture, FIntRect DstRect, bool bClearBlack, bool bNoAlpha) const
	{
		if (bClearBlack)
		{
			FRHIRenderPassInfo RPInfo(DstTexture, ERenderTargetActions::DontLoad_Store);
			RHICmdList.BeginRenderPass(RPInfo, TEXT("ClearToBlack"));
			{
				const FIntRect ClearRect(0, 0, DstTexture->GetSizeX(), DstTexture->GetSizeY());
				RHICmdList.SetViewport(ClearRect.Min.X, ClearRect.Min.Y, 0, ClearRect.Max.X, ClearRect.Max.Y, 1.0f);
				DrawClearQuad(RHICmdList, FLinearColor::Black);
			}
			RHICmdList.EndRenderPass();
		}

		check(CustomPresent);
		CustomPresent->CopyTexture_RenderThread(RHICmdList, DstTexture, SrcTexture, DstRect, SrcRect, false, bNoAlpha, true, true);
	}

	bool FOculusXRHMD::PopulateAnalyticsAttributes(TArray<FAnalyticsEventAttribute>& EventAttributes)
	{
		if (!FHeadMountedDisplayBase::PopulateAnalyticsAttributes(EventAttributes))
		{
			return false;
		}

		EventAttributes.Add(FAnalyticsEventAttribute(TEXT("HQBuffer"), (bool)Settings->Flags.bHQBuffer));
		EventAttributes.Add(FAnalyticsEventAttribute(TEXT("HQDistortion"), (bool)Settings->Flags.bHQDistortion));
		EventAttributes.Add(FAnalyticsEventAttribute(TEXT("UpdateOnRT"), (bool)Settings->Flags.bUpdateOnRT));

		return true;
	}

	bool FOculusXRHMD::ShouldUseSeparateRenderTarget() const
	{
		return IsStereoEnabled();
	}

#ifdef WITH_OCULUS_BRANCH
	void FOculusXRHMD::CalculateRenderTargetSize(uint32& InOutSizeX, uint32& InOutSizeY)
#else  // WITH_OCULUS_BRANCH
	void FOculusXRHMD::CalculateRenderTargetSize(const FViewport& Viewport, uint32& InOutSizeX, uint32& InOutSizeY)
#endif // WITH_OCULUS_BRANCH
	{
		// TODO this should use Settings_RenderThread if !CheckInGameThread()
		// This is called before StartRenderFrame_GameThread() on startup
		if (!Settings->IsStereoEnabled())
		{
			return;
		}

		InOutSizeX = Settings->RenderTargetSize.X;
		InOutSizeY = Settings->RenderTargetSize.Y;

		check(InOutSizeX != 0 && InOutSizeY != 0);
	}

	void FOculusXRHMD::AllocateEyeBuffer()
	{
		CheckInGameThread();

		ExecuteOnRenderThread([&]() {
			InitializeEyeLayer_RenderThread(GetImmediateCommandList_ForRenderCommand());

			const FXRSwapChainPtr& SwapChain = EyeLayer_RenderThread->GetSwapChain();
			if (SwapChain.IsValid())
			{
				const FRHITexture2D* const SwapChainTexture = SwapChain->GetTexture2DArray() ? SwapChain->GetTexture2DArray() : SwapChain->GetTexture2D();
				UE_LOG(LogHMD, Log, TEXT("Allocating Oculus %d x %d rendertarget swapchain"), SwapChainTexture->GetSizeX(), SwapChainTexture->GetSizeY());
			}
		});

		bNeedReAllocateViewportRenderTarget = true;
	}

	bool FOculusXRHMD::NeedReAllocateViewportRenderTarget(const FViewport& Viewport)
	{
		CheckInGameThread();

		return ensureMsgf(Settings.IsValid(), TEXT("Unexpected issue with Oculus settings on the GameThread. This should be valid when this is called in EnqueueBeginRenderFrame() - has the callsite changed?")) && Settings->IsStereoEnabled() && bNeedReAllocateViewportRenderTarget;
	}

	bool FOculusXRHMD::NeedReAllocateDepthTexture(const TRefCountPtr<IPooledRenderTarget>& DepthTarget)
	{
		CheckInRenderThread();

		return ensureMsgf(Settings_RenderThread.IsValid(), TEXT("Unexpected issue with Oculus settings on the RenderThread. This should be valid when this is called in AllocateCommonDepthTargets() - has the callsite changed?")) && Settings_RenderThread->IsStereoEnabled() && bNeedReAllocateDepthTexture_RenderThread;
	}

	bool FOculusXRHMD::NeedReAllocateShadingRateTexture(const TRefCountPtr<IPooledRenderTarget>& FoveationTarget)
	{
		CheckInRenderThread();

		return ensureMsgf(Settings_RenderThread.IsValid(), TEXT("Unexpected issue with Oculus settings on the RenderThread. This should be valid when this is called in AllocateFoveationTexture() - has the callsite changed?")) && Settings_RenderThread->IsStereoEnabled() && bNeedReAllocateFoveationTexture_RenderThread;
	}

#ifdef WITH_OCULUS_BRANCH
	bool FOculusXRHMD::NeedReAllocateMotionVectorTexture(const TRefCountPtr<IPooledRenderTarget>& MotionVectorTarget, const TRefCountPtr<IPooledRenderTarget>& MotionVectorDepthTarget)
	{
		CheckInRenderThread();

		return ensureMsgf(Settings_RenderThread.IsValid(), TEXT("Unexpected issue with Oculus settings on the RenderThread. This should be valid when this is called in AllocateMotionVectorTexture() - has the callsite changed?")) && Settings_RenderThread->IsStereoEnabled() && bNeedReAllocateMotionVectorTexture_RenderThread;
	}
#endif // WITH_OCULUS_BRANCH

	bool FOculusXRHMD::AllocateRenderTargetTexture(uint32 Index, uint32 SizeX, uint32 SizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags InTexFlags, ETextureCreateFlags InTargetableTextureFlags, FTexture2DRHIRef& OutTargetableTexture, FTexture2DRHIRef& OutShaderResourceTexture, uint32 NumSamples)
	{
		CheckInRenderThread();

		check(Index == 0);

		if (LayerMap[0].IsValid())
		{
			const FXRSwapChainPtr& SwapChain = EyeLayer_RenderThread->GetSwapChain();
			if (SwapChain.IsValid())
			{
				OutTargetableTexture = OutShaderResourceTexture = SwapChain->GetTexture2DArray() ? SwapChain->GetTexture2DArray() : SwapChain->GetTexture2D();
				bNeedReAllocateViewportRenderTarget = false;
				return true;
			}
		}

		OutTargetableTexture = OutShaderResourceTexture = nullptr;
		return false;
	}

	bool FOculusXRHMD::AllocateDepthTexture(uint32 Index, uint32 SizeX, uint32 SizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags FlagsIn, ETextureCreateFlags TargetableTextureFlags, FTexture2DRHIRef& OutTargetableTexture, FTexture2DRHIRef& OutShaderResourceTexture, uint32 NumSamples)
	{
		CheckInRenderThread();

		check(Index == 0);

		if (EyeLayer_RenderThread.IsValid())
		{
			const FXRSwapChainPtr& SwapChain = EyeLayer_RenderThread->GetDepthSwapChain();

			if (SwapChain.IsValid())
			{
				FTexture2DRHIRef Texture = SwapChain->GetTexture2DArray() ? SwapChain->GetTexture2DArray() : SwapChain->GetTexture2D();
				FIntPoint TexSize = Texture->GetSizeXY();

				// Ensure the texture size matches the eye layer. We may get other depth allocations unrelated to the main scene render.
				if (FIntPoint(SizeX, SizeY) == TexSize)
				{
					if (bNeedReAllocateDepthTexture_RenderThread)
					{
						UE_LOG(LogHMD, Log, TEXT("Allocating Oculus %d x %d depth rendertarget swapchain"), SizeX, SizeY);
						bNeedReAllocateDepthTexture_RenderThread = false;
					}

					OutTargetableTexture = OutShaderResourceTexture = Texture;
					return true;
				}
			}
		}

		OutTargetableTexture = OutShaderResourceTexture = nullptr;
		return false;
	}

	bool FOculusXRHMD::AllocateShadingRateTexture(uint32 Index, uint32 RenderSizeX, uint32 RenderSizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags InTexFlags, ETextureCreateFlags InTargetableTextureFlags, FTexture2DRHIRef& OutTexture, FIntPoint& OutTextureSize)
	{
		CheckInRenderThread();

		check(Index == 0);

		if (EyeLayer_RenderThread.IsValid())
		{
			const FXRSwapChainPtr& SwapChain = EyeLayer_RenderThread->GetFoveationSwapChain();

			if (SwapChain.IsValid())
			{
				FTexture2DRHIRef Texture = SwapChain->GetTexture2DArray() ? SwapChain->GetTexture2DArray() : SwapChain->GetTexture2D();
				FIntPoint TexSize = Texture->GetSizeXY();

				// Only set texture and return true if we have a valid texture of compatible size
				if (Texture->IsValid() && TexSize.X > 0 && TexSize.Y > 0)
				{
					if (bNeedReAllocateFoveationTexture_RenderThread)
					{
						UE_LOG(LogHMD, Log, TEXT("Allocating Oculus %d x %d variable resolution swapchain"), TexSize.X, TexSize.Y, Index);
						bNeedReAllocateFoveationTexture_RenderThread = false;
					}

					// This is a hack to turn force the runtime to use FDM over FSR when we allocate our FDM to avoid a crash on Quest 3
					// TODO: Remove this for UE 5.3 after there's an engine-side fix
					ExecuteOnRHIThread_DoNotWait([this]() {
						// Set this in AllocateShadingRateTexture because it guarantees that this runs after VulkanExtensions has initially
						// selected the shading rate type, before the FDM is actually going to be used, and only when we actually have an FDM
						CustomPresent->UseFragmentDensityMapOverShadingRate_RHIThread();
					});

					OutTexture = Texture;
					OutTextureSize = TexSize;
					return true;
				}
			}
		}

		OutTexture = nullptr;
		return false;
	}

#ifdef WITH_OCULUS_BRANCH
	bool FOculusXRHMD::AllocateMotionVectorTexture(uint32 Index, uint8 Format, uint32 NumMips, ETextureCreateFlags InTexFlags, ETextureCreateFlags InTargetableTextureFlags, FTexture2DRHIRef& OutTexture, FIntPoint& OutTextureSize, FTexture2DRHIRef& OutDepthTexture, FIntPoint& OutDepthTextureSize)
	{
		CheckInRenderThread();

		check(Index == 0);
		if (EyeLayer_RenderThread.IsValid())
		{
			const FXRSwapChainPtr& SwapChain = EyeLayer_RenderThread->GetMotionVectorSwapChain();
			if (SwapChain.IsValid())
			{
				FTexture2DRHIRef Texture = SwapChain->GetTexture2DArray() ? SwapChain->GetTexture2DArray() : SwapChain->GetTexture2D();
				FIntPoint TexSize = Texture->GetSizeXY();

				const FXRSwapChainPtr& DepthSwapChain = EyeLayer_RenderThread->GetMotionVectorDepthSwapChain();
				if (DepthSwapChain.IsValid())
				{
					FTexture2DRHIRef DepthTexture = DepthSwapChain->GetTexture2DArray() ? DepthSwapChain->GetTexture2DArray() : DepthSwapChain->GetTexture2D();
					FIntPoint DepthTexSize = DepthTexture->GetSizeXY();

					if (DepthTexture->IsValid() && DepthTexSize.X > 0 && DepthTexSize.Y > 0)
					{
						OutDepthTextureSize = DepthTexSize;
						OutDepthTexture = DepthTexture;
					}
					else
					{
						return false;
					}
				}

				// Only set texture and return true if we have a valid texture of compatible size
				if (Texture->IsValid() && TexSize.X > 0 && TexSize.Y > 0)
				{
					if (bNeedReAllocateMotionVectorTexture_RenderThread)
					{
						UE_LOG(LogHMD, Log, TEXT("[Mobile SpaceWarp] Allocating Oculus %d x %d motion vector swapchain"), TexSize.X, TexSize.Y, Index);
						bNeedReAllocateMotionVectorTexture_RenderThread = false;
					}

					OutTexture = Texture;
					OutTextureSize = TexSize;
					return true;
				}
			}
		}

		OutTexture = nullptr;
		return false;
	}
#endif // WITH_OCULUS_BRANCH

#if defined(WITH_OCULUS_BRANCH)
	bool FOculusXRHMD::FindEnvironmentDepthTexture_RenderThread(FTextureRHIRef& OutTexture, FTextureRHIRef& OutMinMaxTexture, FVector2f& OutDepthFactors, FMatrix44f OutScreenToDepthMatrices[2], FMatrix44f OutDepthViewProjMatrices[2])
	{
		CheckInRenderThread();

		if (Frame_RenderThread.IsValid())
		{
			int SwapchainIndex;
			if (ComputeEnvironmentDepthParameters_RenderThread(OutDepthFactors, OutScreenToDepthMatrices, OutDepthViewProjMatrices, SwapchainIndex))
			{
				if (SwapchainIndex >= EnvironmentDepthSwapchain.Num())
				{
					return false;
				}
				OutTexture = EnvironmentDepthSwapchain[SwapchainIndex];
				OutMinMaxTexture = EnvironmentDepthMinMaxTexture;
				return true;
			}
		}
		return false;
	}
#endif // defined(WITH_OCULUS_BRANCH)

	EPixelFormat FOculusXRHMD::GetActualColorSwapchainFormat() const
	{
		if (!CustomPresent.IsValid())
		{
			UE_LOG(LogHMD, Log, TEXT("Invalid CustomPresent! PF_R8G8B8A8 will be used as the default swapchain format!"));
			return PF_R8G8B8A8;
		}
		return CustomPresent->GetDefaultPixelFormat();
	}

	void FOculusXRHMD::UpdateViewportWidget(bool bUseSeparateRenderTarget, const class FViewport& Viewport, class SViewport* ViewportWidget)
	{
		CheckInGameThread();
		check(ViewportWidget);

		TSharedPtr<SWindow> Window = CachedWindow.Pin();
		TSharedPtr<SWidget> CurrentlyCachedWidget = CachedViewportWidget.Pin();
		TSharedRef<SWidget> Widget = ViewportWidget->AsShared();

		if (!Window.IsValid() || Widget != CurrentlyCachedWidget)
		{
			Window = FSlateApplication::Get().FindWidgetWindow(Widget);

			CachedViewportWidget = Widget;
			CachedWindow = Window;
		}

		if (!Settings->IsStereoEnabled())
		{
			// Restore AutoResizeViewport mode for the window
			if (Window.IsValid())
			{
				Window->SetMirrorWindow(false);
				Window->SetViewportSizeDrivenByWindow(true);
			}
			return;
		}

		if (bUseSeparateRenderTarget && Frame.IsValid())
		{
			if (Window.IsValid())
			{
				const auto SlateWindowSize = Window->GetSizeInScreen();
				CachedWindowSize = FIntPoint(static_cast<int>(SlateWindowSize.X), static_cast<int>(SlateWindowSize.Y));
			}
			else
			{
				CachedWindowSize = Viewport.GetSizeXY();
			}
		}
	}

	FXRRenderBridge* FOculusXRHMD::GetActiveRenderBridge_GameThread(bool bUseSeparateRenderTarget)
	{
		CheckInGameThread();

		if (bUseSeparateRenderTarget && NextFrameToRender.IsValid())
		{
			return CustomPresent;
		}
		else
		{
			return nullptr;
		}
	}

	void FOculusXRHMD::UpdateHMDWornState()
	{
		const EHMDWornState::Type NewHMDWornState = GetHMDWornState();

		if (NewHMDWornState != HMDWornState)
		{
			HMDWornState = NewHMDWornState;
			if (HMDWornState == EHMDWornState::Worn)
			{
				FCoreDelegates::VRHeadsetPutOnHead.Broadcast();
			}
			else if (HMDWornState == EHMDWornState::NotWorn)
			{
				FCoreDelegates::VRHeadsetRemovedFromHead.Broadcast();
			}
		}
	}

	void FOculusXRHMD::UpdateHMDEvents()
	{
		ovrpEventDataBuffer buf;
		while (FOculusXRHMDModule::GetPluginWrapper().PollEvent(&buf) == ovrpSuccess)
		{
			if (buf.EventType == ovrpEventType_None)
			{
				break;
			}
			else if (buf.EventType == ovrpEventType_DisplayRefreshRateChange)
			{
				ovrpEventDisplayRefreshRateChange* rateChangedEvent = (ovrpEventDisplayRefreshRateChange*)&buf;
				FOculusEventDelegates::OculusDisplayRefreshRateChanged.Broadcast(rateChangedEvent->FromRefreshRate, rateChangedEvent->ToRefreshRate);
			}
			else
			{
				for (auto& it : EventPollingDelegates)
				{
					bool HandledEvent = false;
					it.ExecuteIfBound(&buf, HandledEvent);
				}
			}
		}
	}

	uint32 FOculusXRHMD::CreateLayer(const IStereoLayers::FLayerDesc& InLayerDesc)
	{
		CheckInGameThread();

		uint32 LayerId = NextLayerId++;
		FLayerPtr Layer = MakeShareable(new FLayer(LayerId));
		LayerMap.Add(LayerId, Layer);
		Layer->SetDesc(Settings.Get(), InLayerDesc);
		return LayerId;
	}

	void FOculusXRHMD::DestroyLayer(uint32 LayerId)
	{
		CheckInGameThread();
		FLayerPtr* LayerFound = LayerMap.Find(LayerId);
		if (LayerFound)
		{
			(*LayerFound)->DestroyLayer();
		}
		LayerMap.Remove(LayerId);
	}

	void FOculusXRHMD::SetLayerDesc(uint32 LayerId, const IStereoLayers::FLayerDesc& InLayerDesc)
	{
		CheckInGameThread();
		FLayerPtr* LayerFound = LayerMap.Find(LayerId);

		if (LayerFound)
		{
			FLayer* Layer = new FLayer(**LayerFound);
			Layer->SetDesc(Settings.Get(), InLayerDesc);
			*LayerFound = MakeShareable(Layer);
		}
	}

	bool FOculusXRHMD::GetLayerDesc(uint32 LayerId, IStereoLayers::FLayerDesc& OutLayerDesc)
	{
		CheckInGameThread();
		FLayerPtr* LayerFound = LayerMap.Find(LayerId);

		if (LayerFound)
		{
			OutLayerDesc = (*LayerFound)->GetDesc();
			return true;
		}

		return false;
	}

	void FOculusXRHMD::MarkTextureForUpdate(uint32 LayerId)
	{
		CheckInGameThread();
		FLayerPtr* LayerFound = LayerMap.Find(LayerId);

		if (LayerFound)
		{
			(*LayerFound)->MarkTextureForUpdate();
		}
	}

	uint32 FOculusXRHMD::GetLayerIdFromOvrpId(int OvrpID) const
	{
		for (FLayerPtr layer : Layers_RenderThread)
		{
			int CurrentLayerOvrpId = layer->GetOvrpId();

			if (CurrentLayerOvrpId == OvrpID)
				return layer->GetId();
		}

		return 0;
	}

	void FOculusXRHMD::SetSplashRotationToForward()
	{
		// if update splash screen is shown, update the head orientation default to recenter splash screens
		FQuat HeadOrientation = FQuat::Identity;
		FVector HeadPosition;
		GetCurrentPose(HMDDeviceId, HeadOrientation, HeadPosition);
		SplashRotation = FRotator(HeadOrientation);
		SplashRotation.Pitch = 0;
		SplashRotation.Roll = 0;
	}

	FOculusXRSplashDesc FOculusXRHMD::GetUESplashScreenDesc()
	{
		FOculusXRSplashDesc Desc;
		Desc.LoadedTexture = bSplashShowMovie ? SplashMovie : SplashTexture;
		Desc.TransformInMeters = Desc.TransformInMeters * FTransform(SplashOffset / GetWorldToMetersScale());
		Desc.bNoAlphaChannel = true;
		Desc.bIsDynamic = bSplashShowMovie;
		Desc.QuadSizeInMeters *= SplashScale;
		return Desc;
	}

	void FOculusXRHMD::EyeTrackedFoveatedRenderingFallback()
	{
		FoveatedRenderingMethod = EOculusXRFoveatedRenderingMethod::FixedFoveatedRendering;
		FoveatedRenderingLevel = EOculusXRFoveatedRenderingLevel::High;
		bDynamicFoveatedRendering = true;
	}

	void FOculusXRHMD::GetAllocatedTexture(uint32 LayerId, FTextureRHIRef& Texture, FTextureRHIRef& LeftTexture)
	{
		Texture = LeftTexture = nullptr;
		FLayerPtr* LayerFound = nullptr;

		if (IsInGameThread())
		{
			LayerFound = LayerMap.Find(LayerId);
		}
		else if (IsInParallelRenderingThread())
		{
			for (int32 LayerIndex = 0; LayerIndex < Layers_RenderThread.Num(); LayerIndex++)
			{
				if (Layers_RenderThread[LayerIndex]->GetId() == LayerId)
				{
					LayerFound = &Layers_RenderThread[LayerIndex];
				}
			}
		}
		else if (IsInRHIThread())
		{
			for (int32 LayerIndex = 0; LayerIndex < Layers_RHIThread.Num(); LayerIndex++)
			{
				if (Layers_RHIThread[LayerIndex]->GetId() == LayerId)
				{
					LayerFound = &Layers_RHIThread[LayerIndex];
				}
			}
		}
		else
		{
			return;
		}

		if (LayerFound && (*LayerFound)->GetSwapChain().IsValid())
		{
			bool bRightTexture = (*LayerFound)->GetRightSwapChain().IsValid();
			const IStereoLayers::FLayerDesc& Desc = (*LayerFound)->GetDesc();

			if (Desc.HasShape<FCubemapLayer>())
			{
				if (bRightTexture)
				{
					Texture = (*LayerFound)->GetRightSwapChain()->GetTextureCube();
					LeftTexture = (*LayerFound)->GetSwapChain()->GetTextureCube();
				}
				else
				{
					Texture = LeftTexture = (*LayerFound)->GetSwapChain()->GetTextureCube();
				}
			}
			else if (Desc.HasShape<FCylinderLayer>() || Desc.HasShape<FQuadLayer>())
			{
				if (bRightTexture)
				{
					Texture = (*LayerFound)->GetRightSwapChain()->GetTexture2D();
					LeftTexture = (*LayerFound)->GetSwapChain()->GetTexture2D();
				}
				else
				{
					Texture = LeftTexture = (*LayerFound)->GetSwapChain()->GetTexture2D();
				}
			}
		}
	}

	IStereoLayers::FLayerDesc FOculusXRHMD::GetDebugCanvasLayerDesc(FTextureRHIRef Texture)
	{
		IStereoLayers::FLayerDesc StereoLayerDesc;

		ovrpBool cylinderSupported = ovrpBool_False;
		ovrpResult result = FOculusXRHMDModule::GetPluginWrapper().GetInitialized() ? FOculusXRHMDModule::GetPluginWrapper().IsLayerShapeSupported(ovrpShape_Cylinder, &cylinderSupported) : ovrpFailure;
		if (OVRP_SUCCESS(result) && cylinderSupported)
		{
			StereoLayerDesc = IStereoLayers::FLayerDesc(FCylinderLayer(100.f, 488.f / 4, 180.f));
			StereoLayerDesc.Transform = FTransform(FVector(0.f, 0, 0)); // 100/0/0 for quads
		}
		else
		{
			StereoLayerDesc.Transform = FTransform(FVector(100.f, 0, 0));
		}

		StereoLayerDesc.QuadSize = FVector2D(180.f, 180.f);
		StereoLayerDesc.PositionType = IStereoLayers::ELayerType::FaceLocked;
		StereoLayerDesc.LayerSize = Texture->GetTexture2D()->GetSizeXY();
		StereoLayerDesc.Flags = IStereoLayers::ELayerFlags::LAYER_FLAG_TEX_CONTINUOUS_UPDATE;
		StereoLayerDesc.Flags |= IStereoLayers::ELayerFlags::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO;
		return StereoLayerDesc;
	}


	void FOculusXRHMD::SetupViewFamily(FSceneViewFamily& InViewFamily)
	{
		InViewFamily.EngineShowFlags.StereoRendering = IsStereoEnabled();
	}

	void FOculusXRHMD::SetupView(FSceneViewFamily& InViewFamily, FSceneView& InView)
	{
		CheckInGameThread();
	}

	void FOculusXRHMD::BeginRenderViewFamily(FSceneViewFamily& InViewFamily)
	{
		CheckInGameThread();

		if (Settings.IsValid() && Settings->IsStereoEnabled())
		{
			// This should already have been set by UpdateStereoRenderingParams().
			// It must still match the value used there.
			check(Settings->CurrentShaderPlatform == InViewFamily.Scene->GetShaderPlatform());
			Settings->Flags.bsRGBEyeBuffer = IsMobilePlatform(Settings->CurrentShaderPlatform) && IsMobileColorsRGB() && !IsMobileTonemapSubpassEnabled(Settings->CurrentShaderPlatform);

			if (NextFrameToRender.IsValid())
			{
				NextFrameToRender->ShowFlags = InViewFamily.EngineShowFlags;
			}

			if (SpectatorScreenController != nullptr)
			{
				SpectatorScreenController->BeginRenderViewFamily();
			}
		}

		StartRenderFrame_GameThread();
	}

	void FOculusXRHMD::EnableInsightPassthrough_RenderThread(bool bEnablePassthrough)
	{
		const bool bShouldEnable = (InsightInitStatus == FInsightInitStatus::NotInitialized) && bEnablePassthrough;

		if (bShouldEnable)
		{
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().InitializeInsightPassthrough()))
			{
				UE_LOG(LogHMD, Log, TEXT("Passthrough Initialized"));
				InsightInitStatus = FInsightInitStatus::Initialized;
			}
			else
			{
				InsightInitStatus = FInsightInitStatus::Failed;
				UE_LOG(LogHMD, Log, TEXT("Passthrough initialization failed"));
			}
		}
		else
		{
			const bool bShouldShutdown = (InsightInitStatus == FInsightInitStatus::Initialized) && !bEnablePassthrough;
			if (bShouldShutdown)
			{
				// it may already be deinitialized.
				if (!FOculusXRHMDModule::GetPluginWrapper().GetInsightPassthroughInitialized() || OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().ShutdownInsightPassthrough()))
				{
					UE_LOG(LogHMD, Log, TEXT("Passthrough shutdown"));
					InsightInitStatus = FInsightInitStatus::NotInitialized;
				}
				else
				{
					UE_LOG(LogHMD, Log, TEXT("Failed to shut down passthrough. It may be still in use."));
				}
			}
		}
	}

	void FOculusXRHMD::PreRenderViewFamily_RenderThread(FRDGBuilder& GraphBuilder, FSceneViewFamily& ViewFamily)
	{
		CheckInRenderThread();
	}

	void FOculusXRHMD::OnBeginRendering_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& ViewFamily)
	{
		CheckInRenderThread();

		if (!Frame_RenderThread.IsValid())
		{
			return;
		}

		if (!Settings_RenderThread.IsValid() || !Settings_RenderThread->IsStereoEnabled())
		{
			return;
		}

		// If using OVRPlugin OpenXR, only update spectator screen mode with VR focus, since we are running the frameloop
		// and cycling through the swapchain even without VR focus with OVRPlugin OpenXR
		ovrpXrApi NativeXrApi;
		FOculusXRHMDModule::GetPluginWrapper().GetNativeXrApiType(&NativeXrApi);
		if (SpectatorScreenController && (NativeXrApi != ovrpXrApi_OpenXR || FApp::HasVRFocus()))
		{
			SpectatorScreenController->UpdateSpectatorScreenMode_RenderThread();
			Frame_RenderThread->Flags.bSpectatorScreenActive = SpectatorScreenController->GetSpectatorScreenMode() != ESpectatorScreenMode::Disabled;
		}

		// Update mirror texture
		CustomPresent->UpdateMirrorTexture_RenderThread();

#if !PLATFORM_ANDROID
#if 0 // The entire target should be cleared by the tonemapper and pp material \
	  // Clear the padding between two eyes
		const int32 GapMinX = ViewFamily.Views[0]->UnscaledViewRect.Max.X;
		const int32 GapMaxX = ViewFamily.Views[1]->UnscaledViewRect.Min.X;

		if (GapMinX < GapMaxX)
		{
			SCOPED_DRAW_EVENT(RHICmdList, OculusClearQuad)

			const int32 GapMinY = ViewFamily.Views[0]->UnscaledViewRect.Min.Y;
			const int32 GapMaxY = ViewFamily.Views[1]->UnscaledViewRect.Max.Y;

			FRHIRenderPassInfo RPInfo(ViewFamily.RenderTarget->GetRenderTargetTexture(), ERenderTargetActions::DontLoad_Store);
			RHICmdList.BeginRenderPass(RPInfo, TEXT("Clear"));
			{
				RHICmdList.SetViewport(GapMinX, GapMinY, 0, GapMaxX, GapMaxY, 1.0f);
				DrawClearQuad(RHICmdList, FLinearColor::Black);
			}
			RHICmdList.EndRenderPass();
		}
#endif
#else
		// ensure we have attached JNI to this thread - this has to happen persistently as the JNI could detach if the app loses focus
		FAndroidApplication::GetJavaEnv();
#endif

		EnableInsightPassthrough_RenderThread(Settings_RenderThread->Flags.bInsightPassthroughEnabled);

		// Start RHI frame
		StartRHIFrame_RenderThread();

		// Update performance stats
		PerformanceStats.Frames++;
		PerformanceStats.Seconds = FPlatformTime::Seconds();

		if (bSoftOcclusionsEnabled && EnvironmentDepthMinMaxTexture != nullptr && !EnvironmentDepthSwapchain.IsEmpty())
		{
			RenderEnvironmentDepthMinMaxTexture_RenderThread(RHICmdList);
		}
	}

	void FOculusXRHMD::PreRenderView_RenderThread(FRDGBuilder& GraphBuilder, FSceneView& InView)
	{
	}

	void FOculusXRHMD::PostRenderViewFamily_RenderThread(FRDGBuilder& GraphBuilder, FSceneViewFamily& InViewFamily)
	{
		CheckInRenderThread();

		const bool bIsSceneCapture = InViewFamily.Views.Num() > 0 && InViewFamily.Views[0]->bIsSceneCapture;

		if (!bIsSceneCapture && InViewFamily.Views[0]->StereoPass != EStereoscopicPass::eSSP_FULL)
		{
			FinishRenderFrame_RenderThread(GraphBuilder);
		}
	}

#if UE_VERSION_OLDER_THAN(5, 3, 0)
	void FOculusXRHMD::PostRenderBasePassMobile_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView)
#else
	void FOculusXRHMD::PostRenderBasePassMobile_RenderThread(FRHICommandList& RHICmdList, FSceneView& InView)
#endif
	{
		if (bHardOcclusionsEnabled)
		{
			RenderHardOcclusions_RenderThread(RHICmdList, InView);
		}
#ifndef WITH_OCULUS_BRANCH
		UpdateFoveationOffsets_RenderThread();
#endif
	}

	BEGIN_SHADER_PARAMETER_STRUCT(FPostBasePassViewExtensionParameters, )
	SHADER_PARAMETER_RDG_UNIFORM_BUFFER(FSceneTextureUniformParameters, SceneTextures)
	RENDER_TARGET_BINDING_SLOTS()
	END_SHADER_PARAMETER_STRUCT()

	void FOculusXRHMD::PostRenderBasePassDeferred_RenderThread(FRDGBuilder& GraphBuilder, FSceneView& InView, const FRenderTargetBindingSlots& RenderTargets, TRDGUniformBufferRef<FSceneTextureUniformParameters> SceneTextures)
	{
		if (bHardOcclusionsEnabled)
		{
			auto* PassParameters = GraphBuilder.AllocParameters<FPostBasePassViewExtensionParameters>();
			PassParameters->RenderTargets = RenderTargets;
			PassParameters->SceneTextures = SceneTextures;

			GraphBuilder.AddPass(RDG_EVENT_NAME("RenderHardOcclusions_RenderThread"), PassParameters, ERDGPassFlags::Raster, [this, &InView](FRHICommandListImmediate& RHICmdList) {
				RenderHardOcclusions_RenderThread(RHICmdList, InView);
			});
		}
	}

#ifdef WITH_OCULUS_BRANCH
#if UE_VERSION_OLDER_THAN(5, 3, 0)
	void FOculusXRHMD::PostSceneColorRenderingMobile_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneView& InView)
#else
	void FOculusXRHMD::PostSceneColorRenderingMobile_RenderThread(FRHICommandList& RHICmdList, FSceneView& InView)
#endif
	{
		UpdateFoveationOffsets_RenderThread();
	}
#endif

	int32 FOculusXRHMD::GetPriority() const
	{
		// We want to run after the FDefaultXRCamera's view extension
		return -1;
	}

#ifdef WITH_OCULUS_BRANCH
	bool FOculusXRHMD::LateLatchingEnabled() const
	{
#if OCULUS_HMD_SUPPORTED_PLATFORMS_VULKAN && PLATFORM_ANDROID
		// No LateLatching supported when occlusion culling is enabled due to mid frame submission
		// No LateLatching supported for non Multi view ATM due to viewUniformBuffer reusing.
		// The setting can be disabled in FOculusXRHMD::UpdateStereoRenderingParams
		return Settings->bLateLatching;
#else
		return false;
#endif
	}

	void FOculusXRHMD::PreLateLatchingViewFamily_RenderThread(FRHICommandListImmediate& RHICmdList, FSceneViewFamily& InViewFamily)
	{
		CheckInRenderThread();
		FGameFrame* CurrentFrame = GetFrame_RenderThread();
		if (CurrentFrame)
		{
			CurrentFrame->Flags.bRTLateUpdateDone = false; // Allow LateLatching to update poses again
		}
	}
#endif

	bool FOculusXRHMD::SupportsSpaceWarp() const
	{
#if PLATFORM_ANDROID
		// Use All static value here since those can't be change at runtime
		ensureMsgf(CustomPresent.IsValid(), TEXT("SupportsSpaceWarp can only be called post CustomPresent created"));
		const bool bOvrPlugin_OpenXR = Settings->XrApi == EOculusXRXrApi::OVRPluginOpenXR;
		static const auto CVarMobileMultiView = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("vr.MobileMultiView"));
		static const auto CVarSupportMobileSpaceWarp = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("vr.SupportMobileSpaceWarp"));
		bool bIsMobileMultiViewEnabled = (CVarMobileMultiView && CVarMobileMultiView->GetValueOnAnyThread() != 0);
		bool bIsUsingMobileMultiView = GSupportsMobileMultiView && bIsMobileMultiViewEnabled;
		bool bIsVulkan = CustomPresent->GetRenderAPI() == ovrpRenderAPI_Vulkan;
		bool spaceWarpSupported = bOvrPlugin_OpenXR && bIsVulkan && bIsUsingMobileMultiView && CVarSupportMobileSpaceWarp && (CVarSupportMobileSpaceWarp->GetValueOnAnyThread() != 0);
		return spaceWarpSupported;
#else
		return false;
#endif
	}

	FOculusXRHMD::FOculusXRHMD(const FAutoRegister& AutoRegister)
		: FHeadMountedDisplayBase(nullptr)
		, FHMDSceneViewExtension(AutoRegister)
		, ConsoleCommands(this)
		, InsightInitStatus(FInsightInitStatus::NotInitialized)
		, bShutdownRequestQueued(false)
		, bShouldWait_GameThread(true)
		, bIsRendering_RenderThread(false)
	{
		Flags.Raw = 0;
		OCFlags.Raw = 0;
#if UE_VERSION_OLDER_THAN(5, 4, 0)
		TrackingOrigin = EHMDTrackingOrigin::Eye;
#else
		TrackingOrigin = EHMDTrackingOrigin::View;
#endif
		DeltaControlRotation = FRotator::ZeroRotator; // used from ApplyHmdRotation
		LastPlayerOrientation = FQuat::Identity;
		LastPlayerLocation = FVector::ZeroVector;
		CachedWindowSize = FIntPoint::ZeroValue;
		CachedWorldToMetersScale = 100.0f;
		LastTrackingToWorld = FTransform::Identity;

		NextFrameNumber = 0;
		WaitFrameNumber = (uint32)-1;
		NextLayerId = 0;

		Settings = CreateNewSettings();

		RendererModule = nullptr;

		SplashLayerHandle = -1;

		SplashRotation = FRotator();

		bIsStandaloneStereoOnlyDevice = IHeadMountedDisplayModule::IsAvailable() && IHeadMountedDisplayModule::Get().IsStandaloneStereoOnlyDevice();

		CurPlayerIndex = 0;
		LastFrameHMDHeadPose = FPose();
		MultiPlayerPoses.Empty();
	}

	FOculusXRHMD::~FOculusXRHMD()
	{
		Shutdown();
	}

	bool FOculusXRHMD::Startup()
	{
		if (GIsEditor)
		{
			Settings->Flags.bHeadTrackingEnforced = true;
		}

		check(!CustomPresent.IsValid());

		FString RHIString;
		{
			FString HardwareDetails = FHardwareInfo::GetHardwareDetailsString();
			FString RHILookup = NAME_RHI.ToString() + TEXT("=");

			if (!FParse::Value(*HardwareDetails, *RHILookup, RHIString))
			{
				return false;
			}
		}

#if OCULUS_HMD_SUPPORTED_PLATFORMS_D3D11
		if (RHIString == TEXT("D3D11"))
		{
			CustomPresent = CreateCustomPresent_D3D11(this);
		}
		else
#endif
#if OCULUS_HMD_SUPPORTED_PLATFORMS_D3D12
			if (RHIString == TEXT("D3D12"))
		{
			CustomPresent = CreateCustomPresent_D3D12(this);
		}
		else
#endif
#if OCULUS_HMD_SUPPORTED_PLATFORMS_VULKAN
			if (RHIString == TEXT("Vulkan"))
		{
			CustomPresent = CreateCustomPresent_Vulkan(this);
		}
		else
#endif
		{
			UE_LOG(LogHMD, Warning, TEXT("%s is not currently supported by OculusXRHMD plugin"), *RHIString);
			return false;
		}

		// grab a pointer to the renderer module for displaying our mirror window
		static const FName RendererModuleName("Renderer");
		RendererModule = FModuleManager::GetModulePtr<IRendererModule>(RendererModuleName);

#if PLATFORM_ANDROID
		// register our application lifetime delegates
		FCoreDelegates::ApplicationWillEnterBackgroundDelegate.AddRaw(this, &FOculusXRHMD::ApplicationPauseDelegate);
		FCoreDelegates::ApplicationHasEnteredForegroundDelegate.AddRaw(this, &FOculusXRHMD::ApplicationResumeDelegate);
#endif

		// Create eye layer
		IStereoLayers::FLayerDesc EyeLayerDesc;
		EyeLayerDesc.Priority = INT_MIN;
		EyeLayerDesc.Flags = LAYER_FLAG_TEX_CONTINUOUS_UPDATE;
		uint32 EyeLayerId = CreateLayer(EyeLayerDesc);
		check(EyeLayerId == 0);

		Splash = MakeShareable(new FSplash(this));
		Splash->Startup();

#if !PLATFORM_ANDROID
		SpectatorScreenController = MakeUnique<FSpectatorScreenController>(this);
#endif
		UE_LOG(LogHMD, Log, TEXT("Oculus plugin initialized. Version: %s"), *GetVersionString());

		return true;
	}

	void FOculusXRHMD::PreShutdown()
	{
		if (Splash.IsValid())
		{
			Splash->PreShutdown();
		}
	}

	void FOculusXRHMD::Shutdown()
	{
		CheckInGameThread();

		if (Splash.IsValid())
		{
			Splash->Shutdown();
			Splash = nullptr;
			// The base implementation stores a raw pointer to the Splash object and tries to deallocate it in its destructor
			LoadingScreen = nullptr;
		}

		if (CustomPresent.IsValid())
		{
			CustomPresent->Shutdown();
			CustomPresent = nullptr;
		}

		ReleaseDevice();

		Settings.Reset();
		LayerMap.Reset();
	}

	void FOculusXRHMD::ApplicationPauseDelegate()
	{
		ExecuteOnRenderThread([this]() {
			ExecuteOnRHIThread([this]() {
				FOculusXRHMDModule::GetPluginWrapper().DestroyDistortionWindow2();
			});
		});
		OCFlags.AppIsPaused = true;
	}

	void FOculusXRHMD::ApplicationResumeDelegate()
	{
		if (OCFlags.AppIsPaused && !InitializeSession())
		{
			UE_LOG(LogHMD, Log, TEXT("HMD initialization failed"));
		}
		OCFlags.AppIsPaused = false;
	}

	static const FString EYE_TRACKING_PERMISSION_NAME("com.oculus.permission.EYE_TRACKING");

	bool FOculusXRHMD::CheckEyeTrackingPermission(EOculusXRFoveatedRenderingMethod InFoveatedRenderingMethod)
	{
#if PLATFORM_ANDROID
		// Check and request eye tracking permissions, bind delegate for handling permission request result
		if (!UAndroidPermissionFunctionLibrary::CheckPermission(EYE_TRACKING_PERMISSION_NAME))
		{
			TArray<FString> Permissions;
			Permissions.Add(EYE_TRACKING_PERMISSION_NAME);
			UAndroidPermissionCallbackProxy* Proxy = UAndroidPermissionFunctionLibrary::AcquirePermissions(Permissions);
			Proxy->OnPermissionsGrantedDelegate.AddLambda([this, InFoveatedRenderingMethod](const TArray<FString>& Permissions, const TArray<bool>& GrantResults) {
				int PermIndex = Permissions.Find(EYE_TRACKING_PERMISSION_NAME);
				if (PermIndex != INDEX_NONE && GrantResults[PermIndex])
				{
					UE_LOG(LogHMD, Verbose, TEXT("com.oculus.permission.EYE_TRACKING permission granted"));
					FoveatedRenderingMethod = InFoveatedRenderingMethod;
					FOculusEventDelegates::OculusEyeTrackingStateChanged.Broadcast(true);
				}
				else
				{
					UE_LOG(LogHMD, Log, TEXT("com.oculus.permission.EYE_TRACKING permission denied"));
					if (InFoveatedRenderingMethod == EOculusXRFoveatedRenderingMethod::EyeTrackedFoveatedRendering)
					{
						EyeTrackedFoveatedRenderingFallback();
					}
					FOculusEventDelegates::OculusEyeTrackingStateChanged.Broadcast(false);
				}
			});
			return false;
		}
#endif // PLATFORM_ANDROID
		return true;
	}

	bool FOculusXRHMD::InitializeSession()
	{
		UE_LOG(LogHMD, Log, TEXT("Initializing OVRPlugin session"));

		if (!FOculusXRHMDModule::GetPluginWrapper().GetInitialized())
		{
#if !UE_BUILD_SHIPPING
			ovrpLogCallback logCallback = OvrpLogCallback;
#else
			ovrpLogCallback logCallback = nullptr;
#endif

#if PLATFORM_ANDROID
			void* activity = (void*)FAndroidApplication::GetGameActivityThis();
#else
			void* activity = nullptr;
#endif

			int initializeFlags = GIsEditor ? ovrpInitializeFlag_SupportsVRToggle : 0;

			initializeFlags |= CustomPresent->SupportsSRGB() ? ovrpInitializeFlag_SupportSRGBFrameBuffer : 0;

			if (Settings->Flags.bSupportsDash)
			{
				initializeFlags |= ovrpInitializeFlag_FocusAware;
			}

			if (SupportsSpaceWarp()) // Configure for space warp
			{
				initializeFlags |= ovrpInitializeFlag_SupportAppSpaceWarp;
				UE_LOG(LogHMD, Log, TEXT("[Mobile SpaceWarp] Application is configured to support mobile spacewarp"));
			}
			bNeedReAllocateMotionVectorTexture_RenderThread = false;

#if WITH_EDITOR && PLATFORM_WINDOWS
			// Attempt Late Initialization in-editor
			// FOculusXRHMDModule::PreInit always returns true in this case,
			// so we need to check the flag directly.
			if (GIsEditor && FOculusXRHMDModule::Get().PreInit() && !FOculusXRHMDModule::Get().bPreInit)
			{
				return false;
			}
#endif

			if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().Initialize7(
					CustomPresent->GetRenderAPI(),
					logCallback,
					activity,
					CustomPresent->GetOvrpInstance(),
					CustomPresent->GetOvrpPhysicalDevice(),
					CustomPresent->GetOvrpDevice(),
					CustomPresent->GetOvrpCommandQueue(),
					nullptr /*vkGetInstanceProcAddr*/,
					0 /*vkQueueFamilyIndex*/,
					nullptr /*d3dDevice*/,
					initializeFlags,
					{ OVRP_VERSION })))
			{
				return false;
			}

			ovrpBool Supported = ovrpBool_False;
			if (Settings->bSupportEyeTrackedFoveatedRendering)
			{
				FOculusXRHMDModule::GetPluginWrapper().GetFoveationEyeTrackedSupported(&Supported);
			}
			bEyeTrackedFoveatedRenderingSupported = Supported == ovrpBool_True;
			SetFoveatedRenderingMethod(Settings->FoveatedRenderingMethod);
			SetFoveatedRenderingLevel(Settings->FoveatedRenderingLevel, Settings->bDynamicFoveatedRendering);

			NextFrameNumber = 0;
			WaitFrameNumber = (uint32)-1;
		}

		FOculusXRHMDModule::GetPluginWrapper().SetAppEngineInfo2(
			"Unreal Engine",
			TCHAR_TO_ANSI(*FEngineVersion::Current().ToString()),
			GIsEditor ? ovrpBool_True : ovrpBool_False);

		int flag = ovrpDistortionWindowFlag_None;

		FOculusXRHMDModule::GetPluginWrapper().SetupDistortionWindow3(flag);
		FOculusXRHMDModule::GetPluginWrapper().SetSuggestedCpuPerformanceLevel((ovrpProcessorPerformanceLevel)Settings->SuggestedCpuPerfLevel);
		FOculusXRHMDModule::GetPluginWrapper().SetSuggestedGpuPerformanceLevel((ovrpProcessorPerformanceLevel)Settings->SuggestedGpuPerfLevel);
		FOculusXRHMDModule::GetPluginWrapper().SetFoveationEyeTracked(FoveatedRenderingMethod == EOculusXRFoveatedRenderingMethod::EyeTrackedFoveatedRendering);
		FOculusXRHMDModule::GetPluginWrapper().SetTiledMultiResLevel((ovrpTiledMultiResLevel)FoveatedRenderingLevel.load());
		FOculusXRHMDModule::GetPluginWrapper().SetTiledMultiResDynamic(bDynamicFoveatedRendering.load());
		FOculusXRHMDModule::GetPluginWrapper().SetAppCPUPriority2(((ovrpBool)CVarOculusIncreaseThreadPrio.GetValueOnAnyThread()));
		FOculusXRHMDModule::GetPluginWrapper().SetLocalDimming(ovrpBool_True);

		OCFlags.NeedSetTrackingOrigin = true;

		FOculusXRHMDModule::GetPluginWrapper().SetClientColorDesc((ovrpColorSpace)Settings->ColorSpace);

		return true;
	}

	void FOculusXRHMD::ShutdownSession()
	{
		ExecuteOnRenderThread([this]() {
			ExecuteOnRHIThread([this]() {
				FOculusXRHMDModule::GetPluginWrapper().DestroyDistortionWindow2();
			});
		});

		FOculusXRHMDModule::GetPluginWrapper().Shutdown2();

		bIsRendering_RenderThread = false;
	}

	bool FOculusXRHMD::InitDevice()
	{
		CheckInGameThread();

		if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized())
		{
			// Already created and present
			return true;
		}

		if (!IsHMDEnabled())
		{
			// Don't bother if HMD is not connected
			return false;
		}

		LoadFromSettings();

		if (!InitializeSession())
		{
			UE_LOG(LogHMD, Log, TEXT("HMD initialization failed"));
			return false;
		}

		// Don't need to reset these flags on application resume, so put them in InitDevice instead of InitializeSession
		bNeedReAllocateViewportRenderTarget = true;
		bNeedReAllocateDepthTexture_RenderThread = false;
		bNeedReAllocateFoveationTexture_RenderThread = false;
		Flags.bNeedDisableStereo = false;
		OCFlags.NeedSetFocusToGameViewport = true;

		if (!CustomPresent->IsUsingCorrectDisplayAdapter())
		{
			UE_LOG(LogHMD, Error, TEXT("Using incorrect display adapter for HMD."));
			ShutdownSession();
			return false;
		}

		if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetSystemHeadsetType2(&Settings->SystemHeadset)))
		{
			Settings->SystemHeadset = ovrpSystemHeadset_None;
		}

		FOculusXRHMDModule::GetPluginWrapper().Update3(ovrpStep_Render, 0, 0.0);

		if (Settings->Flags.bPixelDensityAdaptive)
		{
			static const auto DynamicResOperationCVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.DynamicRes.OperationMode"));
			if (DynamicResOperationCVar)
			{
				DynamicResOperationCVar->Set(2);
			}
			GEngine->ChangeDynamicResolutionStateAtNextFrame(MakeShareable(new FDynamicResolutionState(Settings)));
		}

		UpdateHmdRenderInfo();
		UpdateStereoRenderingParams();

		const bool bEnablePassthrough = Settings->Flags.bInsightPassthroughEnabled;

		ExecuteOnRenderThread([this, bEnablePassthrough](FRHICommandListImmediate& RHICmdList) {
			InitializeEyeLayer_RenderThread(RHICmdList);
			EnableInsightPassthrough_RenderThread(bEnablePassthrough);
		});

		if (!EyeLayer_RenderThread.IsValid() || !EyeLayer_RenderThread->GetSwapChain().IsValid())
		{
			UE_LOG(LogHMD, Error, TEXT("Failed to create eye layer swap chain."));
			ShutdownSession();
			return false;
		}

		if (!HiddenAreaMeshes[0].IsValid() || !HiddenAreaMeshes[1].IsValid())
		{
			SetupOcclusionMeshes();
		}

#if !UE_BUILD_SHIPPING
		DrawDebugDelegateHandle = UDebugDrawService::Register(TEXT("Game"), FDebugDrawDelegate::CreateRaw(this, &FOculusXRHMD::DrawDebug));
#endif

		// Do not set VR focus in Editor by just creating a device; Editor may have it created w/o requiring focus.
		// Instead, set VR focus in OnBeginPlay (VR Preview will run there first).
		if (!GIsEditor)
		{
			FApp::SetUseVRFocus(true);
			FApp::SetHasVRFocus(true);
		}

		FOculusXRHMDModule::GetPluginWrapper().SetClientColorDesc((ovrpColorSpace)Settings->ColorSpace);

		return true;
	}

	void FOculusXRHMD::ReleaseDevice()
	{
		CheckInGameThread();

		if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized())
		{
			// Wait until the next frame before ending the session (workaround for DX12/Vulkan resources being ripped out from under us before we're done with them).
			bShutdownRequestQueued = true;
		}
	}

	void BuildOcclusionMesh(FRHICommandList& RHICmdList, FHMDViewMesh& Mesh, ovrpEye Eye, ovrpViewportStencilType MeshType)
	{
		int VertexCount = 0;
		int IndexCount = 0;

		ovrpResult Result = ovrpResult::ovrpFailure;
		if (OVRP_FAILURE(Result = FOculusXRHMDModule::GetPluginWrapper().GetViewportStencil(Eye, MeshType, nullptr, &VertexCount, nullptr, &IndexCount)))
		{
			return;
		}

		FRHIResourceCreateInfo CreateInfo(TEXT("FOculusXRHMD"));
#if UE_VERSION_OLDER_THAN(5, 3, 0)
		Mesh.VertexBufferRHI = RHICreateVertexBuffer(sizeof(FFilterVertex) * VertexCount, BUF_Static, CreateInfo);
		void* VoidPtr = RHILockBuffer(Mesh.VertexBufferRHI, 0, sizeof(FFilterVertex) * VertexCount, RLM_WriteOnly);
#else
		Mesh.VertexBufferRHI = RHICmdList.CreateVertexBuffer(sizeof(FFilterVertex) * VertexCount, BUF_Static, CreateInfo);
		void* VoidPtr = RHICmdList.LockBuffer(Mesh.VertexBufferRHI, 0, sizeof(FFilterVertex) * VertexCount, RLM_WriteOnly);
#endif
		FFilterVertex* pVertices = reinterpret_cast<FFilterVertex*>(VoidPtr);

#if UE_VERSION_OLDER_THAN(5, 3, 0)
		Mesh.IndexBufferRHI = RHICreateIndexBuffer(sizeof(uint16), sizeof(uint16) * IndexCount, BUF_Static, CreateInfo);
		void* VoidPtr2 = RHILockBuffer(Mesh.IndexBufferRHI, 0, sizeof(uint16) * IndexCount, RLM_WriteOnly);
#else
		Mesh.IndexBufferRHI = RHICmdList.CreateIndexBuffer(sizeof(uint16), sizeof(uint16) * IndexCount, BUF_Static, CreateInfo);
		void* VoidPtr2 = RHICmdList.LockBuffer(Mesh.IndexBufferRHI, 0, sizeof(uint16) * IndexCount, RLM_WriteOnly);
#endif
		uint16* pIndices = reinterpret_cast<uint16*>(VoidPtr2);

		ovrpVector2f* const ovrpVertices = new ovrpVector2f[VertexCount];

		FOculusXRHMDModule::GetPluginWrapper().GetViewportStencil(Eye, MeshType, ovrpVertices, &VertexCount, pIndices, &IndexCount);

		for (int i = 0; i < VertexCount; ++i)
		{
			FFilterVertex& Vertex = pVertices[i];
			CA_SUPPRESS(6385); //  warning C6385: Reading invalid data from 'ovrpVertices':  the readable size is 'VertexCount*8' bytes, but '16' bytes may be read
			const ovrpVector2f& Position = ovrpVertices[i];
			if (MeshType == ovrpViewportStencilType_HiddenArea)
			{
				Vertex.Position.X = (Position.x * 2.0f) - 1.0f;
				Vertex.Position.Y = (Position.y * 2.0f) - 1.0f;
				Vertex.Position.Z = 1.0f;
				Vertex.Position.W = 1.0f;
				Vertex.UV.X = 0.0f;
				Vertex.UV.Y = 0.0f;
			}
			else if (MeshType == ovrpViewportStencilType_VisibleArea)
			{
				Vertex.Position.X = Position.x;
				Vertex.Position.Y = 1.0f - Position.y;
				Vertex.Position.Z = 0.0f;
				Vertex.Position.W = 1.0f;
				Vertex.UV.X = Position.x;
				Vertex.UV.Y = 1.0f - Position.y;
			}
			else
			{
				check(0);
			}
		}

		Mesh.NumIndices = IndexCount;
		Mesh.NumVertices = VertexCount;
		Mesh.NumTriangles = IndexCount / 3;

		delete[] ovrpVertices;

#if UE_VERSION_OLDER_THAN(5, 3, 0)
		RHIUnlockBuffer(Mesh.VertexBufferRHI);
		RHIUnlockBuffer(Mesh.IndexBufferRHI);
#else
		RHICmdList.UnlockBuffer(Mesh.VertexBufferRHI);
		RHICmdList.UnlockBuffer(Mesh.IndexBufferRHI);
#endif
	}

	void FOculusXRHMD::SetupOcclusionMeshes()
	{
		CheckInGameThread();

		FOculusXRHMD* const Self = this;
		ENQUEUE_RENDER_COMMAND(SetupOcclusionMeshesCmd)
		([Self](FRHICommandList& RHICmdList) {
			BuildOcclusionMesh(RHICmdList, Self->HiddenAreaMeshes[0], ovrpEye_Left, ovrpViewportStencilType_HiddenArea);
			BuildOcclusionMesh(RHICmdList, Self->HiddenAreaMeshes[1], ovrpEye_Right, ovrpViewportStencilType_HiddenArea);
			BuildOcclusionMesh(RHICmdList, Self->VisibleAreaMeshes[0], ovrpEye_Left, ovrpViewportStencilType_VisibleArea);
			BuildOcclusionMesh(RHICmdList, Self->VisibleAreaMeshes[1], ovrpEye_Right, ovrpViewportStencilType_VisibleArea);
		});
	}

	static ovrpMatrix4f ovrpMatrix4f_Projection(const ovrpFrustum2f& frustum, bool leftHanded)
	{
		float handednessScale = leftHanded ? 1.0f : -1.0f;

		// A projection matrix is very like a scaling from NDC, so we can start with that.
		float projXScale = 2.0f / (frustum.Fov.LeftTan + frustum.Fov.RightTan);
		float projXOffset = (frustum.Fov.LeftTan - frustum.Fov.RightTan) * projXScale * 0.5f;
		float projYScale = 2.0f / (frustum.Fov.UpTan + frustum.Fov.DownTan);
		float projYOffset = (frustum.Fov.UpTan - frustum.Fov.DownTan) * projYScale * 0.5f;

		ovrpMatrix4f projection;

		// Produces X result, mapping clip edges to [-w,+w]
		projection.M[0][0] = projXScale;
		projection.M[0][1] = 0.0f;
		projection.M[0][2] = handednessScale * projXOffset;
		projection.M[0][3] = 0.0f;

		// Produces Y result, mapping clip edges to [-w,+w]
		// Hey - why is that YOffset negated?
		// It's because a projection matrix transforms from world coords with Y=up,
		// whereas this is derived from an NDC scaling, which is Y=down.
		projection.M[1][0] = 0.0f;
		projection.M[1][1] = projYScale;
		projection.M[1][2] = handednessScale * -projYOffset;
		projection.M[1][3] = 0.0f;

		// Produces Z-buffer result
		projection.M[2][0] = 0.0f;
		projection.M[2][1] = 0.0f;
		if (FGenericPlatformMath::IsFinite(frustum.zFar))
		{
			projection.M[2][2] = -handednessScale * frustum.zFar / (frustum.zNear - frustum.zFar);
			projection.M[2][3] = (frustum.zFar * frustum.zNear) / (frustum.zNear - frustum.zFar);
		}
		else
		{
			projection.M[2][2] = handednessScale;
			projection.M[2][3] = -frustum.zNear;
		}

		// Produces W result (= Z in)
		projection.M[3][0] = 0.0f;
		projection.M[3][1] = 0.0f;
		projection.M[3][2] = handednessScale;
		projection.M[3][3] = 0.0f;

		return projection;
	}

	void FOculusXRHMD::UpdateStereoRenderingParams()
	{
		CheckInGameThread();

		// Update PixelDensity
		bool bSupportsDepth = true;

		if (Settings->Flags.bPixelDensityAdaptive)
		{
			FLayer* EyeLayer = EyeLayer_RenderThread.Get();
			float NewPixelDensity = 1.0;
			if (EyeLayer && EyeLayer->GetOvrpId())
			{
				ovrpSizei RecommendedResolution = { 0, 0 };
				FOculusXRHMDModule::GetPluginWrapper().GetLayerRecommendedResolution(EyeLayer->GetOvrpId(), &RecommendedResolution);
				if (RecommendedResolution.h > 0)
				{
					NewPixelDensity = RecommendedResolution.h * (float)Settings->PixelDensityMax / Settings->RenderTargetSize.Y;
				}
			}

			const float PixelDensityCVarOverride = CVarOculusDynamicResolutionPixelDensity.GetValueOnAnyThread();
			if (PixelDensityCVarOverride > 0)
			{
				NewPixelDensity = PixelDensityCVarOverride;
			}
			Settings->SetPixelDensitySmooth(NewPixelDensity);
		}
		else
		{
			static const auto PixelDensityCVar = IConsoleManager::Get().FindConsoleVariable(TEXT("vr.PixelDensity"));
			Settings->SetPixelDensity(PixelDensityCVar ? PixelDensityCVar->GetFloat() : 1.0f);

			// Due to hijacking the depth target directly from the scene context, we can't support depth compositing if it's being scaled by screen percentage since it wont match our color render target dimensions.
			static const auto ScreenPercentageCVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.ScreenPercentage"));
			float ScreenPercentage = (!ScreenPercentageCVar) ? 100.0f : ScreenPercentageCVar->GetFloat();
#if !UE_VERSION_OLDER_THAN(5, 3, 0)
			// 5.3 changes the default screen percentage to 0 and uses r.ScreenPercentage.Default values to determine screen percentage
			if (ScreenPercentageCVar->GetFloat() <= 0.0f)
			{
				static const auto VRScreenPercentageModeCVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.ScreenPercentage.Default.VR.Mode"));
				// With default VR screen percentage modes, only support depth with manual screen percentage set to 100
				if (VRScreenPercentageModeCVar && VRScreenPercentageModeCVar->GetInt() == static_cast<int>(EScreenPercentageMode::Manual))
				{
					static const auto ManualScreenPercentageCVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.ScreenPercentage.Default"));
					ScreenPercentage = ManualScreenPercentageCVar->GetFloat();
				}
			}
#endif
			bSupportsDepth = ScreenPercentage == 100.0f;
		}

		// Update EyeLayer
		FLayerPtr* EyeLayerFound = LayerMap.Find(0);
		FLayer* EyeLayer = new FLayer(**EyeLayerFound);
		*EyeLayerFound = MakeShareable(EyeLayer);

		ovrpLayout Layout = ovrpLayout_DoubleWide;

		static const auto CVarMobileMultiView = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("vr.MobileMultiView"));
		const bool bIsMobileMultiViewEnabled = (CVarMobileMultiView && CVarMobileMultiView->GetValueOnAnyThread() != 0);

		const bool bIsUsingMobileMultiView = (GSupportsMobileMultiView || GRHISupportsArrayIndexFromAnyShader) && bIsMobileMultiViewEnabled;

		Settings->CurrentFeatureLevel = GEngine ? GEngine->GetDefaultWorldFeatureLevel() : GMaxRHIFeatureLevel;
		Settings->CurrentShaderPlatform = GShaderPlatformForFeatureLevel[Settings->CurrentFeatureLevel];

		// for now only mobile rendering codepaths use the array rendering system, so PC-native should stay in doublewide
		if (bIsUsingMobileMultiView && IsMobilePlatform(Settings->CurrentShaderPlatform))
		{
			Layout = ovrpLayout_Array;
		}

#if PLATFORM_ANDROID
		if (!bIsUsingMobileMultiView && Settings->bLateLatching)
		{
			UE_CLOG(true, LogHMD, Error, TEXT("LateLatching can't be used when Multiview is off, force disabling."));
			Settings->bLateLatching = false;
		}

		if (GetMutableDefault<URendererSettings>()->bOcclusionCulling && Settings->bLateLatching)
		{
			UE_CLOG(true, LogHMD, Error, TEXT("LateLatching can't used when Occlusion culling is on due to mid frame vkQueueSubmit, force disabling"));
			Settings->bLateLatching = false;
		}
#endif

		const bool bForceSymmetric = CVarOculusForceSymmetric.GetValueOnAnyThread() == 1 && (Layout == ovrpLayout_Array);

		ovrpLayerDesc_EyeFov EyeLayerDesc;
		const bool requestsSubsampled = CVarOculusEnableSubsampledLayout.GetValueOnAnyThread() == 1 && CustomPresent->SupportsSubsampled();
		int eyeLayerFlags = requestsSubsampled ? ovrpLayerFlag_Subsampled : 0;

		ovrpTextureFormat MvPixelFormat = ovrpTextureFormat_R16G16B16A16_FP;
		ovrpTextureFormat MvDepthFormat = ovrpTextureFormat_D24_S8;
		int SpaceWarpAllocateFlag = 0;

		if (SupportsSpaceWarp())
		{
			SpaceWarpAllocateFlag = ovrpLayerFlag_SpaceWarpDataAllocation | ovrpLayerFlag_SpaceWarpDedicatedDepth;

			bool spaceWarpEnabledByUser = CVarOculusEnableSpaceWarpUser.GetValueOnAnyThread() != 0;
			bool spaceWarpEnabledInternal = CVarOculusEnableSpaceWarpInternal.GetValueOnAnyThread() != 0;
			if (spaceWarpEnabledByUser != spaceWarpEnabledInternal)
			{
				CVarOculusEnableSpaceWarpInternal->Set(spaceWarpEnabledByUser);
			}
		}

		const bool bCompositeDepth = Settings->Flags.bCompositeDepth;

		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().CalculateEyeLayerDesc3(
				Layout,
				Settings->Flags.bPixelDensityAdaptive ? Settings->PixelDensityMax : Settings->PixelDensity,
				Settings->Flags.bHQDistortion ? 0 : 1,
				1, // UNDONE
				CustomPresent->GetOvrpTextureFormat(CustomPresent->GetDefaultPixelFormat(), Settings->Flags.bsRGBEyeBuffer),
				(bCompositeDepth && bSupportsDepth) ? CustomPresent->GetDefaultDepthOvrpTextureFormat() : ovrpTextureFormat_None,
				MvPixelFormat,
				MvDepthFormat,
				1.0f,
				CustomPresent->GetLayerFlags() | eyeLayerFlags | SpaceWarpAllocateFlag,
				&EyeLayerDesc)))
		{
			ovrpFovf FrameFov[ovrpEye_Count] = { EyeLayerDesc.Fov[0], EyeLayerDesc.Fov[1] };
			if (bForceSymmetric)
			{
				// calculate symmetric FOV from runtime-provided asym in EyeLayerDesc
				FrameFov[0].RightTan = FrameFov[1].RightTan = FMath::Max(EyeLayerDesc.Fov[0].RightTan, EyeLayerDesc.Fov[1].RightTan);
				FrameFov[0].LeftTan = FrameFov[1].LeftTan = FMath::Max(EyeLayerDesc.Fov[0].LeftTan, EyeLayerDesc.Fov[1].LeftTan);

				const float asymTanSize = EyeLayerDesc.Fov[0].RightTan + EyeLayerDesc.Fov[0].LeftTan;
				const float symTanSize = FrameFov[0].RightTan + FrameFov[0].LeftTan;

				// compute new resolution from a number of tile multiple, and the increase in width from symmetric FOV
				const int numberTiles = (int)floor(EyeLayerDesc.TextureSize.w * symTanSize / (96.0 * asymTanSize));
				EyeLayerDesc.TextureSize.w = EyeLayerDesc.MaxViewportSize.w = numberTiles * 96;
			}

			// Scaling for DynamicResolution will happen later - see FSceneRenderer::PrepareViewRectsForRendering.
			// If scaling does occur, EyeRenderViewport will be updated in FOculusXRHMD::SetFinalViewRect.
			FIntPoint UnscaledViewportSize = FIntPoint(EyeLayerDesc.MaxViewportSize.w, EyeLayerDesc.MaxViewportSize.h);
			if (Settings->Flags.bPixelDensityAdaptive)
			{
				FIntPoint ViewRect = FIntPoint(
					FMath::CeilToInt(EyeLayerDesc.MaxViewportSize.w / Settings->PixelDensityMax),
					FMath::CeilToInt(EyeLayerDesc.MaxViewportSize.h / Settings->PixelDensityMax));
				UnscaledViewportSize = ViewRect;

				FIntPoint UpperViewRect = FIntPoint(
					FMath::CeilToInt(ViewRect.X * Settings->PixelDensityMax),
					FMath::CeilToInt(ViewRect.Y * Settings->PixelDensityMax));

				FIntPoint TextureSize;
				QuantizeSceneBufferSize(UpperViewRect, TextureSize);

				EyeLayerDesc.MaxViewportSize.w = TextureSize.X;
				EyeLayerDesc.MaxViewportSize.h = TextureSize.Y;
			}

			// Unreal assumes no gutter between eyes
			EyeLayerDesc.TextureSize.w = EyeLayerDesc.MaxViewportSize.w;
			EyeLayerDesc.TextureSize.h = EyeLayerDesc.MaxViewportSize.h;

			if (Layout == ovrpLayout_DoubleWide)
			{
				EyeLayerDesc.TextureSize.w *= 2;
			}

			EyeLayer->SetEyeLayerDesc(EyeLayerDesc);
			EyeLayer->bNeedsTexSrgbCreate = Settings->Flags.bsRGBEyeBuffer;

			Settings->RenderTargetSize = FIntPoint(EyeLayerDesc.TextureSize.w, EyeLayerDesc.TextureSize.h);
			Settings->EyeRenderViewport[0].Min = FIntPoint::ZeroValue;
			Settings->EyeRenderViewport[0].Max = UnscaledViewportSize;
			Settings->EyeRenderViewport[1].Min = FIntPoint(Layout == ovrpLayout_DoubleWide ? UnscaledViewportSize.X : 0, 0);
			Settings->EyeRenderViewport[1].Max = Settings->EyeRenderViewport[1].Min + UnscaledViewportSize;

			Settings->EyeUnscaledRenderViewport[0] = Settings->EyeRenderViewport[0];
			Settings->EyeUnscaledRenderViewport[1] = Settings->EyeRenderViewport[1];

			// Update projection matrices
			ovrpFrustum2f frustumLeft = { 0.001f, 1000.0f, FrameFov[0] };
			ovrpFrustum2f frustumRight = { 0.001f, 1000.0f, FrameFov[1] };
			ovrpFrustum2f frustumCenter = { 0.001f, 1000.0f, { FrameFov[0].UpTan, FrameFov[0].DownTan, FrameFov[0].LeftTan, FrameFov[1].RightTan } };

			Settings->EyeProjectionMatrices[0] = ovrpMatrix4f_Projection(frustumLeft, true);
			Settings->EyeProjectionMatrices[1] = ovrpMatrix4f_Projection(frustumRight, true);
			Settings->MonoProjectionMatrix = ovrpMatrix4f_Projection(frustumCenter, true);

			// given that we send a subrect in vpRectSubmit, the FOV is the default asym one in EyeLayerDesc, not FrameFov
			if (Frame.IsValid())
			{
				Frame->Fov[0] = EyeLayerDesc.Fov[0];
				Frame->Fov[1] = EyeLayerDesc.Fov[1];
				Frame->SymmetricFov[0] = FrameFov[0];
				Frame->SymmetricFov[1] = FrameFov[1];
			}

			// Flag if need to recreate render targets
			if (!EyeLayer->CanReuseResources(EyeLayer_RenderThread.Get()))
			{
				AllocateEyeBuffer();
			}
		}
	}

	void FOculusXRHMD::UpdateHmdRenderInfo()
	{
		CheckInGameThread();
		FOculusXRHMDModule::GetPluginWrapper().GetSystemDisplayFrequency2(&Settings->VsyncToNextVsync);
	}

	void FOculusXRHMD::InitializeEyeLayer_RenderThread(FRHICommandListImmediate& RHICmdList)
	{
		check(!InGameThread());
		CheckInRenderThread();

		if (LayerMap[0].IsValid())
		{
			FLayerPtr EyeLayer = LayerMap[0]->Clone();
			EyeLayer->Initialize_RenderThread(Settings_RenderThread.Get(), CustomPresent, &DeferredDeletion, RHICmdList, EyeLayer_RenderThread.Get());

			if (Layers_RenderThread.Num() > 0)
			{
				Layers_RenderThread[0] = EyeLayer;
			}
			else
			{
				Layers_RenderThread.Add(EyeLayer);
			}

			if (EyeLayer->GetDepthSwapChain().IsValid())
			{
				if (!EyeLayer_RenderThread.IsValid() || EyeLayer->GetDepthSwapChain() != EyeLayer_RenderThread->GetDepthSwapChain())
				{
					bNeedReAllocateDepthTexture_RenderThread = true;
				}
			}
			if (EyeLayer->GetFoveationSwapChain().IsValid())
			{
				if (!EyeLayer_RenderThread.IsValid() || EyeLayer->GetFoveationSwapChain() != EyeLayer_RenderThread->GetFoveationSwapChain())
				{
					bNeedReAllocateFoveationTexture_RenderThread = true;
				}
#if !UE_VERSION_OLDER_THAN(5, 3, 0)
				FoveationImageGenerator = MakeShared<FOculusXRFoveatedRenderingImageGenerator, ESPMode::ThreadSafe>(EyeLayer->GetFoveationSwapChain());
#endif // !UE_VERSION_OLDER_THAN(5, 3, 0)
			}

			if (EyeLayer->GetMotionVectorSwapChain().IsValid())
			{
				if (!EyeLayer_RenderThread.IsValid() || EyeLayer->GetMotionVectorSwapChain() != EyeLayer_RenderThread->GetMotionVectorSwapChain()
					|| EyeLayer->GetMotionVectorDepthSwapChain() != EyeLayer_RenderThread->GetMotionVectorDepthSwapChain())
				{
					bNeedReAllocateMotionVectorTexture_RenderThread = true;
					UE_LOG(LogHMD, VeryVerbose, TEXT("[Mobile SpaceWarp]  request to re-allocate motionVector textures"));
				}
			}

			if (EyeLayer_RenderThread.IsValid())
			{
				DeferredDeletion.AddLayerToDeferredDeletionQueue(EyeLayer_RenderThread);
			}

			EyeLayer_RenderThread = EyeLayer;
		}
	}

	void FOculusXRHMD::ApplySystemOverridesOnStereo(bool force)
	{
		CheckInGameThread();
		// ALWAYS SET r.FinishCurrentFrame to 0! Otherwise the perf might be poor.
		// @TODO: revise the FD3D11DynamicRHI::RHIEndDrawingViewport code (and other renderers)
		// to ignore this var completely.
		static const auto CFinishFrameVar = IConsoleManager::Get().FindConsoleVariable(TEXT("r.FinishCurrentFrame"));
		CFinishFrameVar->Set(0);
	}

	bool FOculusXRHMD::OnOculusStateChange(bool bIsEnabledNow)
	{
		if (!bIsEnabledNow)
		{
			// Switching from stereo
			ReleaseDevice();

			ResetControlRotation();
			return true;
		}
		else
		{
			// Switching to stereo
			if (InitDevice())
			{
				Flags.bApplySystemOverridesOnStereo = true;
				return true;
			}
			DeltaControlRotation = FRotator::ZeroRotator;
		}
		return false;
	}

	class FSceneViewport* FOculusXRHMD::FindSceneViewport()
	{
		if (!GIsEditor)
		{
			UGameEngine* GameEngine = Cast<UGameEngine>(GEngine);
			return GameEngine->SceneViewport.Get();
		}
#if WITH_EDITOR
		else
		{
			UEditorEngine* EditorEngine = CastChecked<UEditorEngine>(GEngine);
			FSceneViewport* PIEViewport = (FSceneViewport*)EditorEngine->GetPIEViewport();
			if (PIEViewport != nullptr && PIEViewport->IsStereoRenderingAllowed())
			{
				// PIE is setup for stereo rendering
				return PIEViewport;
			}
			else
			{
				// Check to see if the active editor viewport is drawing in stereo mode
				// @todo vreditor: Should work with even non-active viewport!
				FSceneViewport* EditorViewport = (FSceneViewport*)EditorEngine->GetActiveViewport();
				if (EditorViewport != nullptr && EditorViewport->IsStereoRenderingAllowed())
				{
					return EditorViewport;
				}
			}
		}
#endif
		return nullptr;
	}

	bool FOculusXRHMD::ShouldDisableHiddenAndVisibileAreaMeshForSpectatorScreen_RenderThread() const
	{
		CheckInRenderThread();

		// If you really need the eye corners to look nice, and can't just crop more,
		// and are willing to suffer a frametime hit... you could do this:
#if 0
		switch(GetSpectatorScreenMode_RenderThread())
		{
		case ESpectatorScreenMode::SingleEyeLetterboxed:
		case ESpectatorScreenMode::SingleEyeCroppedToFill:
		case ESpectatorScreenMode::TexturePlusEye:
			return true;
		}
#endif

		return false;
	}

	ESpectatorScreenMode FOculusXRHMD::GetSpectatorScreenMode_RenderThread() const
	{
		CheckInRenderThread();
		return SpectatorScreenController ? SpectatorScreenController->GetSpectatorScreenMode() : ESpectatorScreenMode::Disabled;
	}

#if !UE_BUILD_SHIPPING
	static const char* FormatLatencyReading(char* buff, size_t size, float val)
	{
		if (val < 0.000001f)
		{
			FCStringAnsi::Strcpy(buff, size, "N/A   ");
		}
		else
		{
			FCStringAnsi::Snprintf(buff, size, "%4.2fms", val * 1000.0f);
		}
		return buff;
	}

	void FOculusXRHMD::DrawDebug(UCanvas* InCanvas, APlayerController* InPlayerController)
	{
		CheckInGameThread();

		if (InCanvas && IsStereoEnabled() && Settings->Flags.bShowStats)
		{
			static const FColor TextColor(0, 255, 0);
			// Pick a larger font on console.
			UFont* const Font = FPlatformProperties::SupportsWindowedMode() ? GEngine->GetSmallFont() : GEngine->GetMediumFont();
			const int32 RowHeight = FMath::TruncToInt(Font->GetMaxCharHeight() * 1.1f);

			float ClipX = InCanvas->ClipX;
			float ClipY = InCanvas->ClipY;
			float LeftPos = 0;

			ClipX -= 100;
			LeftPos = ClipX * 0.3f;
			float TopPos = ClipY * 0.4f;

			int32 X = (int32)LeftPos;
			int32 Y = (int32)TopPos;

			FString Str;

			if (!Settings->Flags.bPixelDensityAdaptive)
			{
				Str = FString::Printf(TEXT("PD: %.2f"), Settings->PixelDensity);
			}
			else
			{
				Str = FString::Printf(TEXT("PD: %.2f [%0.2f, %0.2f]"), Settings->PixelDensity,
					Settings->PixelDensityMin, Settings->PixelDensityMax);
			}
			InCanvas->Canvas->DrawShadowedString(X, Y, *Str, Font, TextColor);
			Y += RowHeight;

			Str = FString::Printf(TEXT("W-to-m scale: %.2f uu/m"), GetWorldToMetersScale());
			InCanvas->Canvas->DrawShadowedString(X, Y, *Str, Font, TextColor);

			ovrpAppLatencyTimings AppLatencyTimings;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetAppLatencyTimings2(&AppLatencyTimings)))
			{
				Y += RowHeight;

				char buf[5][20];
				char destStr[100];

				FCStringAnsi::Snprintf(destStr, sizeof(destStr), "Latency, ren: %s tw: %s pp: %s err: %s %s",
					FormatLatencyReading(buf[0], sizeof(buf[0]), AppLatencyTimings.LatencyRender),
					FormatLatencyReading(buf[1], sizeof(buf[1]), AppLatencyTimings.LatencyTimewarp),
					FormatLatencyReading(buf[2], sizeof(buf[2]), AppLatencyTimings.LatencyPostPresent),
					FormatLatencyReading(buf[3], sizeof(buf[3]), AppLatencyTimings.ErrorRender),
					FormatLatencyReading(buf[4], sizeof(buf[4]), AppLatencyTimings.ErrorTimewarp));

				Str = ANSI_TO_TCHAR(destStr);
				InCanvas->Canvas->DrawShadowedString(X, Y, *Str, Font, TextColor);
			}

			// Second row
			X = (int32)LeftPos + 200;
			Y = (int32)TopPos;

			Str = FString::Printf(TEXT("HQ dist: %s"), (Settings->Flags.bHQDistortion) ? TEXT("ON") : TEXT("OFF"));
			InCanvas->Canvas->DrawShadowedString(X, Y, *Str, Font, TextColor);
			Y += RowHeight;

			float UserIPD;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetUserIPD2(&UserIPD)))
			{
				Str = FString::Printf(TEXT("IPD: %.2f mm"), UserIPD * 1000.f);
				InCanvas->Canvas->DrawShadowedString(X, Y, *Str, Font, TextColor);
				Y += RowHeight;
			}
		}
	}
#endif // #if !UE_BUILD_SHIPPING

	FOculusXRHMD* FOculusXRHMD::GetOculusXRHMD()
	{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
		if (GEngine && GEngine->XRSystem.IsValid())
		{
			if (GEngine->XRSystem->GetSystemName() == OculusXRHMD::FOculusXRHMD::OculusSystemName)
			{
				return static_cast<OculusXRHMD::FOculusXRHMD*>(GEngine->XRSystem.Get());
			}
		}
#endif
		return nullptr;
	}

	bool FOculusXRHMD::IsHMDActive() const
	{
		return FOculusXRHMDModule::GetPluginWrapper().GetInitialized() != ovrpBool_False;
	}

	float FOculusXRHMD::GetWorldToMetersScale() const
	{
		CheckInGameThread();

		if (NextFrameToRender.IsValid())
		{
			return NextFrameToRender->WorldToMetersScale;
		}

		if (GWorld != nullptr)
		{
#if WITH_EDITOR
			// Workaround to allow WorldToMeters scaling to work correctly for controllers while running inside PIE.
			// The main world will most likely not be pointing at the PIE world while polling input, so if we find a world context
			// of that type, use that world's WorldToMeters instead.
			if (GIsEditor)
			{
				for (const FWorldContext& Context : GEngine->GetWorldContexts())
				{
					if (Context.WorldType == EWorldType::PIE)
					{
						return Context.World()->GetWorldSettings()->WorldToMeters;
					}
				}
			}
#endif // WITH_EDITOR

			// We're not currently rendering a frame, so just use whatever world to meters the main world is using.
			// This can happen when we're polling input in the main engine loop, before ticking any worlds.
			return GWorld->GetWorldSettings()->WorldToMeters;
		}

		return 100.0f;
	}

	FVector FOculusXRHMD::GetNeckPosition(const FQuat& HeadOrientation, const FVector& HeadPosition)
	{
		CheckInGameThread();

		FVector NeckPosition = HeadOrientation.Inverse().RotateVector(HeadPosition);

		ovrpVector2f NeckEyeDistance;
		if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetUserNeckEyeDistance2(&NeckEyeDistance)))
		{
			const float WorldToMetersScale = GetWorldToMetersScale();
			NeckPosition.X -= NeckEyeDistance.x * WorldToMetersScale;
			NeckPosition.Z -= NeckEyeDistance.y * WorldToMetersScale;
		}

		return NeckPosition;
	}

	void FOculusXRHMD::SetBaseOffsetInMeters(const FVector& BaseOffset)
	{
		CheckInGameThread();

		Settings->BaseOffset = BaseOffset;
	}

	FVector FOculusXRHMD::GetBaseOffsetInMeters() const
	{
		CheckInGameThread();

		return Settings->BaseOffset;
	}

	bool FOculusXRHMD::ConvertPose(const ovrpPosef& InPose, FPose& OutPose) const
	{
		CheckInGameThread();

		if (!NextFrameToRender.IsValid())
		{
			return false;
		}

		return ConvertPose_Internal(InPose, OutPose, Settings.Get(), NextFrameToRender->WorldToMetersScale);
	}

	bool FOculusXRHMD::ConvertPose(const FPose& InPose, ovrpPosef& OutPose) const
	{
		CheckInGameThread();

		if (!NextFrameToRender.IsValid())
		{
			return false;
		}

		return ConvertPose_Internal(InPose, OutPose, Settings.Get(), NextFrameToRender->WorldToMetersScale);
	}

	bool FOculusXRHMD::ConvertPose_RenderThread(const ovrpPosef& InPose, FPose& OutPose) const
	{
		CheckInRenderThread();

		if (!Frame_RenderThread.IsValid())
		{
			return false;
		}

		return ConvertPose_Internal(InPose, OutPose, Settings_RenderThread.Get(), Frame_RenderThread->WorldToMetersScale);
	}

	bool FOculusXRHMD::ConvertPose_Internal(const ovrpPosef& InPose, FPose& OutPose, const FSettings* Settings, float WorldToMetersScale)
	{
		return OculusXRHMD::ConvertPose_Internal(InPose, OutPose, Settings->BaseOrientation, Settings->BaseOffset, WorldToMetersScale);
	}

	bool FOculusXRHMD::ConvertPose_Internal(const FPose& InPose, ovrpPosef& OutPose, const FSettings* Settings, float WorldToMetersScale)
	{
		return OculusXRHMD::ConvertPose_Internal(InPose, OutPose, Settings->BaseOrientation, Settings->BaseOffset, WorldToMetersScale);
	}

	FVector FOculusXRHMD::ScaleAndMovePointWithPlayer(ovrpVector3f& OculusXRHMDPoint)
	{
		CheckInGameThread();

		FMatrix TranslationMatrix;
		TranslationMatrix.SetIdentity();
		TranslationMatrix = TranslationMatrix.ConcatTranslation(LastPlayerLocation);

		FVector ConvertedPoint = ToFVector(OculusXRHMDPoint) * GetWorldToMetersScale();
		FRotator RotateWithPlayer = LastPlayerOrientation.Rotator();
		FVector TransformWithPlayer = RotateWithPlayer.RotateVector(ConvertedPoint);
		TransformWithPlayer = FVector(TranslationMatrix.TransformPosition(TransformWithPlayer));

		if (GetXRCamera(HMDDeviceId)->GetUseImplicitHMDPosition())
		{
			FQuat HeadOrientation = FQuat::Identity;
			FVector HeadPosition;
			GetCurrentPose(HMDDeviceId, HeadOrientation, HeadPosition);
			TransformWithPlayer -= RotateWithPlayer.RotateVector(HeadPosition);
		}

		return TransformWithPlayer;
	}

	ovrpVector3f FOculusXRHMD::WorldLocationToOculusPoint(const FVector& InUnrealPosition)
	{
		CheckInGameThread();
		FQuat AdjustedPlayerOrientation = GetBaseOrientation().Inverse() * LastPlayerOrientation;
		AdjustedPlayerOrientation.Normalize();

		FVector AdjustedPlayerLocation = LastPlayerLocation;
		if (GetXRCamera(HMDDeviceId)->GetUseImplicitHMDPosition())
		{
			FQuat HeadOrientation = FQuat::Identity; // Unused
			FVector HeadPosition;
			GetCurrentPose(HMDDeviceId, HeadOrientation, HeadPosition);
			AdjustedPlayerLocation -= LastPlayerOrientation.Inverse().RotateVector(HeadPosition);
		}
		const FTransform InvWorldTransform = FTransform(AdjustedPlayerOrientation, AdjustedPlayerLocation).Inverse();
		const FVector ConvertedPosition = InvWorldTransform.TransformPosition(InUnrealPosition) / GetWorldToMetersScale();

		return ToOvrpVector3f(ConvertedPosition);
	}

	float FOculusXRHMD::ConvertFloat_M2U(float OculusFloat) const
	{
		CheckInGameThread();

		return OculusFloat * GetWorldToMetersScale();
	}

	FVector FOculusXRHMD::ConvertVector_M2U(ovrpVector3f OculusXRHMDPoint) const
	{
		CheckInGameThread();

		return ToFVector(OculusXRHMDPoint) * GetWorldToMetersScale();
	}

	bool FOculusXRHMD::GetUserProfile(UserProfile& OutProfile)
	{
		float UserIPD;
		ovrpVector2f UserNeckEyeDistance;
		float UserEyeHeight;

		if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized() && OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetUserIPD2(&UserIPD)) && OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetUserNeckEyeDistance2(&UserNeckEyeDistance)) && OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetUserEyeHeight2(&UserEyeHeight)))
		{
			OutProfile.IPD = UserIPD;
			OutProfile.EyeDepth = UserNeckEyeDistance.x;
			OutProfile.EyeHeight = UserEyeHeight;
			return true;
		}

		return false;
	}

	float FOculusXRHMD::GetVsyncToNextVsync() const
	{
		CheckInGameThread();

		return Settings->VsyncToNextVsync;
	}

	FPerformanceStats FOculusXRHMD::GetPerformanceStats() const
	{
		return PerformanceStats;
	}

	void FOculusXRHMD::GetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel& CpuPerfLevel, EOculusXRProcessorPerformanceLevel& GpuPerfLevel)
	{
		CheckInGameThread();
		CpuPerfLevel = Settings->SuggestedCpuPerfLevel;
		GpuPerfLevel = Settings->SuggestedGpuPerfLevel;
	}

	void FOculusXRHMD::SetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel CpuPerfLevel, EOculusXRProcessorPerformanceLevel GpuPerfLevel)
	{
		CheckInGameThread();
		FOculusXRHMDModule::GetPluginWrapper().SetSuggestedCpuPerformanceLevel((ovrpProcessorPerformanceLevel)CpuPerfLevel);
		FOculusXRHMDModule::GetPluginWrapper().SetSuggestedGpuPerformanceLevel((ovrpProcessorPerformanceLevel)GpuPerfLevel);
		Settings->SuggestedCpuPerfLevel = CpuPerfLevel;
		Settings->SuggestedGpuPerfLevel = GpuPerfLevel;
	}

	void FOculusXRHMD::SetFoveatedRenderingMethod(EOculusXRFoveatedRenderingMethod InFoveatedRenderingMethod)
	{
#ifdef WITH_OCULUS_BRANCH
		Settings->FoveatedRenderingMethod = InFoveatedRenderingMethod;
		// Don't switch to eye tracked foveated rendering when it's not supported or permissions are denied
		if (InFoveatedRenderingMethod == EOculusXRFoveatedRenderingMethod::EyeTrackedFoveatedRendering && !(bEyeTrackedFoveatedRenderingSupported && CheckEyeTrackingPermission(InFoveatedRenderingMethod)))
		{
			return;
		}
#else
		Settings->FoveatedRenderingMethod = EOculusXRFoveatedRenderingMethod::FixedFoveatedRendering;
		if (InFoveatedRenderingMethod == EOculusXRFoveatedRenderingMethod::EyeTrackedFoveatedRendering)
		{
			UE_LOG(LogHMD, Warning, TEXT("Eye Tracked Foveated Rendering is not supported on this engine version, using Fixed Foveated Rendering instead"));
		}
#endif // WITH_OCULUS_BRANCH

		FoveatedRenderingMethod = Settings->FoveatedRenderingMethod;
	}

	void FOculusXRHMD::SetFoveatedRenderingLevel(EOculusXRFoveatedRenderingLevel InFoveationLevel, bool isDynamic)
	{
		FoveatedRenderingLevel = Settings->FoveatedRenderingLevel = InFoveationLevel;
		bDynamicFoveatedRendering = Settings->bDynamicFoveatedRendering = isDynamic;
	}

	void FOculusXRHMD::SetColorScaleAndOffset(FLinearColor ColorScale, FLinearColor ColorOffset, bool bApplyToAllLayers)
	{
		CheckInGameThread();
		Settings->bApplyColorScaleAndOffsetToAllLayers = bApplyToAllLayers;
		Settings->ColorScale = LinearColorToOvrpVector4f(ColorScale);
		Settings->ColorOffset = LinearColorToOvrpVector4f(ColorOffset);
	}

	void FOculusXRHMD::SetEnvironmentDepthHandRemoval(bool RemoveHands)
	{
		FOculusXRHMDModule::GetPluginWrapper().SetEnvironmentDepthHandRemoval(RemoveHands);
		bEnvironmentDepthHandRemovalEnabled = RemoveHands;
	}

	void FOculusXRHMD::StartEnvironmentDepth(int CreateFlags)
	{
#if PLATFORM_ANDROID
		// Check and request scene permissions (this is needed for environment depth to work)
		// bind delegate for handling permission request result
		if (!UAndroidPermissionFunctionLibrary::CheckPermission(USE_SCENE_PERMISSION_NAME))
		{
			TArray<FString> Permissions;
			Permissions.Add(USE_SCENE_PERMISSION_NAME);
			UAndroidPermissionCallbackProxy* Proxy = UAndroidPermissionFunctionLibrary::AcquirePermissions(Permissions);
			static FDelegateHandle DelegateHandle;
			DelegateHandle = Proxy->OnPermissionsGrantedDelegate.AddLambda([this, Proxy, CreateFlags](const TArray<FString>& Permissions, const TArray<bool>& GrantResults) {
				int PermIndex = Permissions.Find(USE_SCENE_PERMISSION_NAME);
				if (PermIndex != INDEX_NONE && GrantResults[PermIndex])
				{
					UE_LOG(LogHMD, Verbose, TEXT("%s permission granted"), *USE_SCENE_PERMISSION_NAME);
					StartEnvironmentDepth(CreateFlags);
				}
				else
				{
					UE_LOG(LogHMD, Log, TEXT("%s permission denied"), *USE_SCENE_PERMISSION_NAME);
				}
				Proxy->OnPermissionsGrantedDelegate.Remove(DelegateHandle);
			});
			return;
		}
#endif // PLATFORM_ANDROID

		ExecuteOnRenderThread_DoNotWait([this, CreateFlags]() {
			ovrpEnvironmentDepthTextureDesc DepthTextureDesc;
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().InitializeEnvironmentDepth(CreateFlags)) && OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetEnvironmentDepthTextureDesc(&DepthTextureDesc)))
			{
				TArray<ovrpTextureHandle> DepthTextures;
				int32 TextureCount;
				if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetEnvironmentDepthTextureStageCount(&TextureCount)))
				{
					// We don't really do different depth texture formats right now and it's always a
					// single multiview texture, so no need for a separate right eye texture for now.
					// We may need a separate Left/RightDepthTextures in the future.
					DepthTextures.SetNum(TextureCount);

					for (int32 TextureIndex = 0; TextureIndex < TextureCount; TextureIndex++)
					{
						if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetEnvironmentDepthTexture(TextureIndex, ovrpEye_Left, &DepthTextures[TextureIndex])))
						{
							UE_LOG(LogHMD, Error, TEXT("Failed to create insight depth texture. NOTE: This causes a leak of %d other texture(s), which will go unused."), TextureIndex);
							return;
						}
					}

					uint32 SizeX = DepthTextureDesc.TextureSize.w;
					uint32 SizeY = DepthTextureDesc.TextureSize.h;
					EPixelFormat DepthFormat = CustomPresent->GetPixelFormat(DepthTextureDesc.Format);
					uint32 NumMips = DepthTextureDesc.MipLevels;
					uint32 NumSamples = DepthTextureDesc.SampleCount;
					uint32 NumSamplesTileMem = 1;
					ETextureCreateFlags DepthTexCreateFlags = TexCreate_ShaderResource | TexCreate_InputAttachmentRead;
					FClearValueBinding DepthTextureBinding = FClearValueBinding::DepthFar;
					ERHIResourceType ResourceType;
					if (DepthTextureDesc.Layout == ovrpLayout_Array)
					{
						ResourceType = RRT_Texture2DArray;
					}
					else
					{
						ResourceType = RRT_Texture2D;
					}

					if (CustomPresent)
					{
						if (!EnvironmentDepthSwapchain.IsEmpty())
						{
							EnvironmentDepthSwapchain.Empty();
						}
						EnvironmentDepthSwapchain = CustomPresent->CreateSwapChainTextures_RenderThread(SizeX, SizeY, DepthFormat, DepthTextureBinding, NumMips, NumSamples, NumSamplesTileMem, ResourceType, DepthTextures, DepthTexCreateFlags, *FString::Printf(TEXT("Oculus Environment Depth Swapchain")));
					}

					ETextureCreateFlags MinMaxTextureCreateFlags = TexCreate_ShaderResource | TexCreate_RenderTargetable;
					FRHITextureCreateDesc MinMaxTextureDesc = FRHITextureCreateDesc::Create(TEXT("EnvironmentDepthMinMaxTexture"), DepthTextureDesc.Layout == ovrpLayout_Array ? ETextureDimension::Texture2DArray : ETextureDimension::Texture2D)
																  .SetExtent(SizeX, SizeY)
																  .SetFormat(PF_FloatRGBA) // Note: PF_R16G16B16A16_UNORM would be better from a precision perspective but is less performant.
																  .SetNumMips(NumMips)
																  .SetNumSamples(NumSamples)
																  .SetClearValue(FClearValueBinding::None);
					if (DepthTextureDesc.Layout == ovrpLayout_Array)
					{
						MinMaxTextureDesc.SetArraySize(2);
						MinMaxTextureCreateFlags |= TexCreate_TargetArraySlicesIndependently;
					}
					MinMaxTextureDesc.SetFlags(MinMaxTextureCreateFlags);
					EnvironmentDepthMinMaxTexture = RHICreateTexture(MinMaxTextureDesc);

					FOculusXRHMDModule::GetPluginWrapper().SetEnvironmentDepthHandRemoval(bEnvironmentDepthHandRemovalEnabled);
					FOculusXRHMDModule::GetPluginWrapper().StartEnvironmentDepth();
				}
			}
		});
	}

	void FOculusXRHMD::StopEnvironmentDepth()
	{
		ExecuteOnRenderThread_DoNotWait([this]() {
			if (!EnvironmentDepthSwapchain.IsEmpty())
			{
				EnvironmentDepthSwapchain.Empty();
			}
			if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().StopEnvironmentDepth()))
			{
				FOculusXRHMDModule::GetPluginWrapper().DestroyEnvironmentDepth();
			}
			EnvironmentDepthMinMaxTexture = nullptr;
			PrevEnvironmentDepthMinMaxSwapchainIndex = -1;
		});
	}

	bool FOculusXRHMD::IsEnvironmentDepthStarted()
	{
		return !EnvironmentDepthSwapchain.IsEmpty();
	}

	void FOculusXRHMD::EnableHardOcclusions(bool bEnable)
	{
		bHardOcclusionsEnabled = bEnable;
	}

	void FOculusXRHMD::EnableSoftOcclusions(bool bEnable)
	{
		bSoftOcclusionsEnabled = bEnable;
	}

	bool FOculusXRHMD::DoEnableStereo(bool bStereo)
	{
		CheckInGameThread();

		FSceneViewport* SceneVP = FindSceneViewport();

		if (!Settings->Flags.bHMDEnabled || (SceneVP && !SceneVP->IsStereoRenderingAllowed()))
		{
			bStereo = false;
		}

		if (Settings->Flags.bStereoEnabled && bStereo || !Settings->Flags.bStereoEnabled && !bStereo)
		{
			// already in the desired mode
			return Settings->Flags.bStereoEnabled;
		}

		TSharedPtr<SWindow> Window;

		if (SceneVP)
		{
			Window = SceneVP->FindWindow();
		}

		if (!Window.IsValid() || !SceneVP || !SceneVP->GetViewportWidget().IsValid())
		{
			// try again next frame
			if (bStereo)
			{
				Flags.bNeedEnableStereo = true;

				// a special case when stereo is enabled while window is not available yet:
				// most likely this is happening from BeginPlay. In this case, if frame exists (created in OnBeginPlay)
				// then we need init device and populate the initial tracking for head/hand poses.
				if (Frame.IsValid())
				{
					InitDevice();
				}
			}
			else
			{
				Flags.bNeedDisableStereo = true;
			}

			return Settings->Flags.bStereoEnabled;
		}

		if (OnOculusStateChange(bStereo))
		{
			Settings->Flags.bStereoEnabled = bStereo;

			// Uncap fps to enable FPS higher than 62
			GEngine->bForceDisableFrameRateSmoothing = bStereo;

			// Set MirrorWindow state on the Window
			Window->SetMirrorWindow(bStereo);

			if (bStereo)
			{
				// Start frame
				StartGameFrame_GameThread();
				StartRenderFrame_GameThread();

				// Set viewport size to Rift resolution
				// NOTE: this can enqueue a render frame right away as a result (calling into FOculusXRHMD::BeginRenderViewFamily)
				SceneVP->SetViewportSize(Settings->RenderTargetSize.X, Settings->RenderTargetSize.Y);

				if (Settings->Flags.bPauseRendering)
				{
					GEngine->SetMaxFPS(10);
				}
			}
			else
			{
				// Work around an error log that can happen when enabling stereo rendering again
				if (NextFrameNumber == WaitFrameNumber)
				{
					NextFrameNumber++;
				}

				if (Settings->Flags.bPauseRendering)
				{
					GEngine->SetMaxFPS(0);
				}

				// Restore viewport size to window size
				FVector2D size = Window->GetSizeInScreen();
				SceneVP->SetViewportSize(size.X, size.Y);
				Window->SetViewportSizeDrivenByWindow(true);
			}
		}

		return Settings->Flags.bStereoEnabled;
	}

	void FOculusXRHMD::ResetControlRotation() const
	{
		// Switching back to non-stereo mode: reset player rotation and aim.
		// Should we go through all playercontrollers here?
		APlayerController* pc = GEngine->GetFirstLocalPlayerController(GWorld);
		if (pc)
		{
			// Reset Aim? @todo
			FRotator r = pc->GetControlRotation();
			r.Normalize();
			// Reset roll and pitch of the player
			r.Roll = 0;
			r.Pitch = 0;
			pc->SetControlRotation(r);
		}
	}

	void FOculusXRHMD::UpdateFoveationOffsets_RenderThread()
	{
#ifdef WITH_OCULUS_BRANCH
		CheckInRenderThread();

		SCOPED_NAMED_EVENT(UpdateFoveationOffsets_RenderThread, FColor::Red);

		// Don't execute anything if we're not using Eye Tracked Foveated Rendering (this already takes into account if it's supported or not)
		if (!Frame_RenderThread.IsValid() || Frame_RenderThread->FoveatedRenderingMethod != EOculusXRFoveatedRenderingMethod::EyeTrackedFoveatedRendering)
		{
			return;
		}

		const FXRSwapChainPtr& SwapChain = EyeLayer_RenderThread->GetSwapChain();
		if (!SwapChain.IsValid())
		{
			return;
		}

		const FRHITexture2D* const SwapChainTexture = SwapChain->GetTexture2DArray() ? SwapChain->GetTexture2DArray() : SwapChain->GetTexture2D();
		if (!SwapChainTexture)
		{
			return;
		}
		const FIntPoint SwapChainDimensions = SwapChainTexture->GetSizeXY();

		// Enqueue the actual update on the RHI thread, which should execute right before the EndRenderPass call
		ExecuteOnRHIThread_DoNotWait([this, SwapChainDimensions]() {
			SCOPED_NAMED_EVENT(UpdateFoveationEyeTracked_RHIThread, FColor::Red);

			bool bUseOffsets = false;
			FIntPoint Offsets[2];
			// Make sure the the Foveated Rendering Method is still eye tracked at RHI thread time before getting offsets.
			// If the base setting was changed to fixed, even if the frame's setting is still eye tracked, we should switch to fixed. This
			// usually indicates that eye tracking failed on the previous frame, so we don't need to try it again.
			if (Frame_RHIThread.IsValid() && Frame_RHIThread->FoveatedRenderingMethod == EOculusXRFoveatedRenderingMethod::EyeTrackedFoveatedRendering && FoveatedRenderingMethod == EOculusXRFoveatedRenderingMethod::EyeTrackedFoveatedRendering)
			{
				if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().SetFoveationEyeTracked(ovrpBool_True)))
				{
					ovrpVector2f fovCenter[2];
					ovrpResult Result = FOculusXRHMDModule::GetPluginWrapper().GetFoveationEyeTrackedCenter(fovCenter);
					if (OVRP_SUCCESS(Result))
					{
						Offsets[0].X = fovCenter[0].x * SwapChainDimensions.X / 2;
						Offsets[0].Y = fovCenter[0].y * SwapChainDimensions.Y / 2;
						Offsets[1].X = fovCenter[1].x * SwapChainDimensions.X / 2;
						Offsets[1].Y = fovCenter[1].y * SwapChainDimensions.Y / 2;
						bUseOffsets = true;
					}
					else if (Result != ovrpFailure_DataIsInvalid)
					{
						// Fall back to dynamic FFR High if OVRPlugin call actually fails, since we're not expecting GFR to work again.
						// Additional rendering changes can be made by binding the changes to OculusEyeTrackingStateChanged
						EyeTrackedFoveatedRenderingFallback();
						FOculusEventDelegates::OculusEyeTrackingStateChanged.Broadcast(false);
					}
				}
			}

			if (CustomPresent)
			{
				CustomPresent->UpdateFoveationOffsets_RHIThread(bUseOffsets, Offsets);
			}
		});
#endif // WITH_OCULUS_BRANCH
	}

	class FHardOcclusionsPS : public FGlobalShader
	{
		DECLARE_SHADER_TYPE(FHardOcclusionsPS, Global);

		static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
		{
			FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);
		}

		static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
		{
			// This file is already guarded with OCULUS_HMD_SUPPORTED_PLATFORMS
			return true;
		}

		/** Default constructor. */
		FHardOcclusionsPS() {}

		/** Initialization constructor. */
		FHardOcclusionsPS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
			: FGlobalShader(Initializer)
		{
			EnvironmentDepthTexture.Bind(Initializer.ParameterMap, TEXT("EnvironmentDepthTexture"));
			EnvironmentDepthSampler.Bind(Initializer.ParameterMap, TEXT("EnvironmentDepthSampler"));
			DepthFactors.Bind(Initializer.ParameterMap, TEXT("DepthFactors"));
			ScreenToDepthMatrices.Bind(Initializer.ParameterMap, TEXT("ScreenToDepthMatrices"));
			DepthViewId.Bind(Initializer.ParameterMap, TEXT("DepthViewId"));
		}

#if UE_VERSION_OLDER_THAN(5, 3, 0)
		template <typename TShaderRHIParamRef>
		void SetParameters(
			FRHICommandListImmediate& RHICmdList,
			const TShaderRHIParamRef ShaderRHI,
			FRHISamplerState* Sampler,
			FRHITexture* Texture,
			const FVector2f& Factors,
			const FMatrix44f ScreenToDepth[ovrpEye_Count],
			const int ViewId)
		{
			SetTextureParameter(RHICmdList, ShaderRHI, EnvironmentDepthTexture, EnvironmentDepthSampler, Sampler, Texture);

			SetShaderValue(RHICmdList, ShaderRHI, DepthFactors, Factors);
			SetShaderValueArray(RHICmdList, ShaderRHI, ScreenToDepthMatrices, ScreenToDepth, ovrpEye_Count);
			SetShaderValue(RHICmdList, ShaderRHI, DepthViewId, ViewId);
		}
#else
		void SetParameters(
			FRHIBatchedShaderParameters& BatchedParameters,
			FRHISamplerState* Sampler,
			FRHITexture* Texture,
			const FVector2f& Factors,
			const FMatrix44f ScreenToDepth[ovrpEye_Count],
			const int ViewId)
		{
			SetTextureParameter(BatchedParameters, EnvironmentDepthTexture, EnvironmentDepthSampler, Sampler, Texture);

			SetShaderValue(BatchedParameters, DepthFactors, Factors);
			SetShaderValueArray(BatchedParameters, ScreenToDepthMatrices, ScreenToDepth, ovrpEye_Count);
			SetShaderValue(BatchedParameters, DepthViewId, ViewId);
		}
#endif

	private:
		LAYOUT_FIELD(FShaderResourceParameter, EnvironmentDepthTexture);
		LAYOUT_FIELD(FShaderResourceParameter, EnvironmentDepthSampler);
		LAYOUT_FIELD(FShaderParameter, DepthFactors);
		LAYOUT_FIELD(FShaderParameter, ScreenToDepthMatrices);
		LAYOUT_FIELD(FShaderParameter, DepthViewId);
	};

	IMPLEMENT_SHADER_TYPE(, FHardOcclusionsPS, TEXT("/Plugin/OculusXR/Private/HardOcclusions.usf"), TEXT("HardOcclusionsPS"), SF_Pixel);

	FMatrix44f MakeProjectionMatrix(ovrpFovf cameraFovAngles)
	{
		const float tanAngleWidth = cameraFovAngles.RightTan + cameraFovAngles.LeftTan;
		const float tanAngleHeight = cameraFovAngles.UpTan + cameraFovAngles.DownTan;

		FMatrix44f Matrix = FMatrix44f::Identity;

		// Scale
		Matrix.M[0][0] = 1.0f / tanAngleWidth;
		Matrix.M[1][1] = 1.0f / tanAngleHeight;

		// Offset
		Matrix.M[0][3] = cameraFovAngles.LeftTan / tanAngleWidth;
		Matrix.M[1][3] = cameraFovAngles.DownTan / tanAngleHeight;
		Matrix.M[2][3] = -1.0f;

		return Matrix;
	}

	FMatrix44f MakeUnprojectionMatrix(ovrpFovf cameraFovAngles)
	{
		FMatrix44f Matrix = FMatrix44f::Identity;

		// Scale
		Matrix.M[0][0] = cameraFovAngles.RightTan + cameraFovAngles.LeftTan;
		Matrix.M[1][1] = cameraFovAngles.UpTan + cameraFovAngles.DownTan;

		// Offset
		Matrix.M[0][3] = -cameraFovAngles.LeftTan;
		Matrix.M[1][3] = -cameraFovAngles.DownTan;
		Matrix.M[2][3] = 1.0;

		return Matrix;
	}

	bool FOculusXRHMD::ComputeEnvironmentDepthParameters_RenderThread(FVector2f& DepthFactors, FMatrix44f ScreenToDepth[ovrpEye_Count], FMatrix44f DepthViewProj[ovrpEye_Count], int& SwapchainIndex)
	{
		float ScreenNearZ = GNearClippingPlane / Frame_RenderThread->WorldToMetersScale;
		ovrpFovf* ScreenFov = Frame_RenderThread->SymmetricFov;

		ovrpEnvironmentDepthFrameDesc DepthFrameDesc[ovrpEye_Count];
		if (FOculusXRHMDModule::GetPluginWrapper().GetEnvironmentDepthFrameDesc(ovrpEye_Left, &DepthFrameDesc[0]) != ovrpSuccess || !DepthFrameDesc[0].IsValid)
		{
			return false;
		}
		if (FOculusXRHMDModule::GetPluginWrapper().GetEnvironmentDepthFrameDesc(ovrpEye_Right, &DepthFrameDesc[1]) != ovrpSuccess || !DepthFrameDesc[1].IsValid)
		{
			return false;
		}

		SwapchainIndex = DepthFrameDesc[0].SwapchainIndex;
		const float WorldToMetersScale = Frame_RenderThread->WorldToMetersScale;

		if (DepthViewProj != nullptr)
		{
			for (int i = 0; i < ovrpEye_Count; ++i)
			{
				ovrpFrustum2f DepthFrustum;
				DepthFrustum.Fov = DepthFrameDesc[i].Fov;
				DepthFrustum.zNear = DepthFrameDesc[i].NearZ * WorldToMetersScale;
				DepthFrustum.zFar = DepthFrameDesc[i].FarZ * WorldToMetersScale;
				FMatrix DepthProjectionMatrix = ToFMatrix(ovrpMatrix4f_Projection(DepthFrustum, true));

				auto DepthOrientation = Frame_RenderThread->TrackingToWorld.GetRotation() * ToFQuat(DepthFrameDesc[i].CreatePose.Orientation);

				// NOTE: This matrix is the same as applied in SetupViewFrustum in SceneView.cpp
				auto ViewMatrix = DepthOrientation.Inverse().ToMatrix() * FMatrix(FPlane(0, 0, 1, 0), FPlane(1, 0, 0, 0), FPlane(0, 1, 0, 0), FPlane(0, 0, 0, 1));

				ovrpPoseStatef EyePoseState;
				if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().GetNodePoseState3(ovrpStep_Render, Frame_RenderThread->FrameNumber, (ovrpNode)i, &EyePoseState)))
				{
					auto DepthTranslation = ToFVector(DepthFrameDesc[i].CreatePose.Position) * WorldToMetersScale;
					auto EyePos = ToFVector(EyePoseState.Pose.Position) * WorldToMetersScale;
					auto Delta = EyePos - DepthTranslation;

					// NOTE: The view matrix here is relative to the VR camera, this is necessary to support
					// Large Worlds and avoid rounding errors when getting very far away from the origin
					ViewMatrix = ViewMatrix.ConcatTranslation(ViewMatrix.TransformPosition(Delta));
				}

				DepthViewProj[i] = (FMatrix44f)(ViewMatrix * DepthProjectionMatrix);
			}
		}

		// Assume NearZ and FarZ are the same for left and right eyes
		float DepthNearZ = DepthFrameDesc[ovrpEye_Left].NearZ;
		float DepthFarZ = DepthFrameDesc[ovrpEye_Left].FarZ;

		float Scale;
		float Offset;

		if (DepthFarZ < DepthNearZ || (!FGenericPlatformMath::IsFinite(DepthFarZ)))
		{
			// Inf far plane:
			Scale = DepthNearZ;
			Offset = 0.0f;
		}
		else
		{
			// Finite far plane:
			Scale = (DepthFarZ * DepthNearZ) / (DepthFarZ - DepthNearZ);
			Offset = DepthNearZ / (DepthFarZ - DepthNearZ);
		}

		DepthFactors.X = -ScreenNearZ / Scale;
		DepthFactors.Y = Offset * ScreenNearZ / Scale + 1.0f;

		// The pose extrapolated to the predicted display time of the current frame
		FQuat ScreenOrientation = Frame_RenderThread->HeadOrientation;

		for (int i = 0; i < ovrpEye_Count; ++i)
		{
			// Screen To Depth represents the transformation matrix used to map normalised screen UV coordinates to
			// normalised environment depth texture UV coordinates. This needs to account for 2 things:
			// 1. The field of view of the two textures may be different, Unreal typically renders using a symmetric fov.
			//    That is to say the FOV of the left and right eyes is the same. The environment depth on the other hand
			//    has a different FOV for the left and right eyes. So we need to scale and offset accordingly to account
			//    for this difference.
			auto T_ScreenCamera_ScreenNormCoord = MakeUnprojectionMatrix(ScreenFov[i]);
			auto T_DepthNormCoord_DepthCamera = MakeProjectionMatrix(DepthFrameDesc[i].Fov);

			// 2. The headset may have moved in between capturing the environment depth and rendering the frame. We
			//    can only account for rotation of the headset, not translation.
			auto DepthOrientation = ToFQuat(DepthFrameDesc[i].CreatePose.Orientation);
			if (!DepthOrientation.IsNormalized())
			{
				UE_LOG(LogHMD, Error, TEXT("DepthOrientation is not normalized %f %f %f %f"), DepthOrientation.X, DepthOrientation.Y, DepthOrientation.Z, DepthOrientation.W);
				DepthOrientation.Normalize();
			}
			auto ScreenToDepthQuat = ScreenOrientation.Inverse() * DepthOrientation;

			FMatrix44f R_DepthCamera_ScreenCamera = FQuat4f(ScreenToDepthQuat.Y, ScreenToDepthQuat.Z, ScreenToDepthQuat.X, ScreenToDepthQuat.W).GetNormalized().ToMatrix();

			ScreenToDepth[i] = T_DepthNormCoord_DepthCamera * R_DepthCamera_ScreenCamera * T_ScreenCamera_ScreenNormCoord;
		}
		return true;
	}

#if !UE_VERSION_OLDER_THAN(5, 3, 0)
	BEGIN_SHADER_PARAMETER_STRUCT(FDrawRectangleParameters, )
	SHADER_PARAMETER(FVector4f, PosScaleBias)
	SHADER_PARAMETER(FVector4f, UVScaleBias)
	SHADER_PARAMETER(FVector4f, InvTargetSizeAndTextureSize)
	END_SHADER_PARAMETER_STRUCT()
#endif

	void FOculusXRHMD::DrawHmdViewMesh(
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
		const TShaderRef<FShader>& VertexShader)
	{
		FDrawRectangleParameters Parameters;
		Parameters.PosScaleBias = FVector4f(SizeX, SizeY, X, Y);
		Parameters.UVScaleBias = FVector4f(SizeU, SizeV, U, V);

		Parameters.InvTargetSizeAndTextureSize = FVector4f(
			1.0f / TargetSize.X, 1.0f / TargetSize.Y,
			1.0f / TextureSize.X, 1.0f / TextureSize.Y);

#if UE_VERSION_OLDER_THAN(5, 3, 0)
		SetUniformBufferParameterImmediate(RHICmdList, VertexShader.GetVertexShader(), VertexShader->GetUniformBufferParameter<FDrawRectangleParameters>(), Parameters);
#else
		FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
		SetUniformBufferParameterImmediate(BatchedParameters, VertexShader->GetUniformBufferParameter<FDrawRectangleParameters>(), Parameters);
		RHICmdList.SetBatchedShaderParameters(VertexShader.GetVertexShader(), BatchedParameters);
#endif
		RendererModule->DrawRectangle(
			RHICmdList,
			X, Y,
			SizeX, SizeY,
			0, 0,
			TextureSize.X, TextureSize.Y,
			TargetSize,
			TextureSize,
			VertexShader);
	}

#if UE_VERSION_OLDER_THAN(5, 3, 0)
	void FOculusXRHMD::RenderHardOcclusions_RenderThread(FRHICommandListImmediate& RHICmdList, const FSceneView& InView)
#else
	void FOculusXRHMD::RenderHardOcclusions_RenderThread(FRHICommandList& RHICmdList, const FSceneView& InView)
#endif
	{
		checkSlow(RHICmdList.IsInsideRenderPass());

		FVector2f DepthFactors;
		FMatrix44f ScreenToDepthMatrices[ovrpEye_Count];
		int SwapchainIndex;

		if (!Frame_RenderThread.IsValid() || InView.bIsSceneCapture || InView.bIsReflectionCapture || InView.bIsPlanarReflection || !ComputeEnvironmentDepthParameters_RenderThread(DepthFactors, ScreenToDepthMatrices, nullptr, SwapchainIndex))
		{
			return;
		}
		if (SwapchainIndex >= EnvironmentDepthSwapchain.Num())
		{
			UE_LOG(LogHMD, Error, TEXT("Depth texture swapchain index %d outside of boundaries"), SwapchainIndex);
			return;
		}

		FGraphicsPipelineStateInitializer GraphicsPSOInit;
		RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);

		GraphicsPSOInit.BlendState = TStaticBlendState<>::GetRHI();
		GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
		GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<>::GetRHI();

		FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(InView.FeatureLevel);
		TShaderMapRef<FScreenPassVS> VertexShader(GlobalShaderMap);
		TShaderMapRef<FHardOcclusionsPS> PixelShader(GlobalShaderMap);

		GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
		GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
		GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
		GraphicsPSOInit.PrimitiveType = PT_TriangleList;

		SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit, 0);

		FRHITexture* DepthTexture = EnvironmentDepthSwapchain[SwapchainIndex];
		FRHISamplerState* DepthSampler = TStaticSamplerState<>::GetRHI();

		FIntPoint TextureSize = DepthTexture->GetDesc().Extent;
		FIntRect ScreenRect = InView.UnscaledViewRect;

#if UE_VERSION_OLDER_THAN(5, 3, 0)
		PixelShader->SetParameters(RHICmdList, PixelShader.GetPixelShader(), DepthSampler, DepthTexture, DepthFactors, ScreenToDepthMatrices, InView.StereoViewIndex);
#else
		FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
		PixelShader->SetParameters(BatchedParameters, DepthSampler, DepthTexture, DepthFactors, ScreenToDepthMatrices, InView.StereoViewIndex);
		RHICmdList.SetBatchedShaderParameters(PixelShader.GetPixelShader(), BatchedParameters);
#endif

		check(Settings->CurrentShaderPlatform == InView.Family->Scene->GetShaderPlatform());
		if (!IsMobilePlatform(Settings->CurrentShaderPlatform) && InView.StereoViewIndex != INDEX_NONE)
		{
			SCOPED_DRAW_EVENTF(RHICmdList, RenderHardOcclusions_RenderThread, TEXT("View %d"), InView.StereoViewIndex);

			int32 width = ScreenRect.Width() / 2;
			int32 height = ScreenRect.Height();
			int32 x = InView.StereoViewIndex == EStereoscopicEye::eSSE_LEFT_EYE ? 0 : width;
			int32 y = 0;

			DrawHmdViewMesh(
				RHICmdList,
				x, y,
				width, height,
				0, 0,
				TextureSize.X, TextureSize.Y,
				FIntPoint(ScreenRect.Width(), ScreenRect.Height()),
				TextureSize,
				InView.StereoViewIndex,
				VertexShader);
		}
		else
		{
			SCOPED_DRAW_EVENT(RHICmdList, RenderHardOcclusions_RenderThread);

			RendererModule->DrawRectangle(
				RHICmdList,
				0, 0,
				ScreenRect.Width(), ScreenRect.Height(),
				0, 0,
				TextureSize.X, TextureSize.Y,
				FIntPoint(ScreenRect.Width(), ScreenRect.Height()),
				TextureSize,
				VertexShader);
		}
	}

	void FOculusXRHMD::RenderEnvironmentDepthMinMaxTexture_RenderThread(FRHICommandListImmediate& RHICmdList)
	{
		ovrpEnvironmentDepthFrameDesc DepthFrameDesc;
		if (FOculusXRHMDModule::GetPluginWrapper().GetEnvironmentDepthFrameDesc(ovrpEye_Left, &DepthFrameDesc) != ovrpSuccess || !DepthFrameDesc.IsValid)
		{
			return;
		}
		if (EnvironmentDepthSwapchain.Num() <= DepthFrameDesc.SwapchainIndex || DepthFrameDesc.SwapchainIndex == PrevEnvironmentDepthMinMaxSwapchainIndex)
		{
			return;
		}

		FRHIRenderPassInfo RPInfo(EnvironmentDepthMinMaxTexture, ERenderTargetActions::DontLoad_Store);
		int32 SliceCount = EnvironmentDepthMinMaxTexture->GetDesc().ArraySize;
		bool bEnableMultiView = GSupportsMobileMultiView;
		if (bEnableMultiView)
		{
			RPInfo.MultiViewCount = 2;
			SliceCount = 1;
		}
		for (int32 SliceIndex = 0; SliceIndex < SliceCount; ++SliceIndex)
		{
			if (!bEnableMultiView)
			{
				RPInfo.ColorRenderTargets[0].ArraySlice = SliceIndex;
			}
			RHICmdList.BeginRenderPass(RPInfo, TEXT("EnvironmentDepthMinMaxPrePass"));
			{
				auto SrcTexture = EnvironmentDepthSwapchain[DepthFrameDesc.SwapchainIndex];
				auto Extent = SrcTexture->GetDesc().Extent;
				const uint32 ViewportWidth = Extent.X;
				const uint32 ViewportHeight = Extent.Y;
				const FIntPoint TargetSize(ViewportWidth, ViewportHeight);

				FGraphicsPipelineStateInitializer GraphicsPSOInit;
				GraphicsPSOInit.BlendState = TStaticBlendState<>::GetRHI();
				GraphicsPSOInit.RasterizerState = TStaticRasterizerState<>::GetRHI();
				GraphicsPSOInit.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
				GraphicsPSOInit.PrimitiveType = PT_TriangleList;

				const auto FeatureLevel = Settings_RenderThread->CurrentFeatureLevel;
				auto ShaderMap = GetGlobalShaderMap(FeatureLevel);
				TShaderMapRef<FScreenVS> VertexShader(ShaderMap);
				GraphicsPSOInit.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
				GraphicsPSOInit.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();

				RHICmdList.ApplyCachedRenderTargets(GraphicsPSOInit);
				FRHISamplerState* SamplerState = TStaticSamplerState<SF_Point>::GetRHI();

				FRHIBatchedShaderParameters& BatchedParameters = RHICmdList.GetScratchShaderParameters();
				if (bEnableMultiView)
				{
					GraphicsPSOInit.MultiViewCount = 2;
					TShaderMapRef<FScreenPSEnvironmentDepthMinMax<true>> PixelShader(ShaderMap);
					GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
					PixelShader->SetParameters(BatchedParameters, SamplerState, SrcTexture, SliceIndex);
				}
				else
				{
					TShaderMapRef<FScreenPSEnvironmentDepthMinMax<false>> PixelShader(ShaderMap);
					GraphicsPSOInit.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
					PixelShader->SetParameters(BatchedParameters, SamplerState, SrcTexture, SliceIndex);
				}
				SetGraphicsPipelineState(RHICmdList, GraphicsPSOInit, 0);
				RHICmdList.SetBatchedShaderParameters(RHICmdList.GetBoundPixelShader(), BatchedParameters);

#ifdef WITH_OCULUS_BRANCH
				// If GSupportsMultiViewPerViewViewports is true then we must specify a stereo viewport otherwise
				// it will lead to undefined behaviour in the right eye.
				if (GSupportsMultiViewPerViewViewports)
				{
					RHICmdList.SetStereoViewport(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, ViewportWidth, ViewportWidth, ViewportHeight, ViewportHeight, 1.0f);
					RHICmdList.SetStereoScissor(0.0f, 0.0f, 0.0f, 0.0f, ViewportWidth, ViewportWidth, ViewportHeight, ViewportHeight);
				}
				else
#endif
				{
					RHICmdList.SetViewport(0.0f, 0.0f, 0.0f, ViewportWidth, ViewportHeight, 1.0f);
				}

				RendererModule->DrawRectangle(
					RHICmdList,
					0.0f, 0.0f, ViewportWidth, ViewportHeight,
					0.0f, 0.0f, 1.0f, 1.0f,
					TargetSize,
					FIntPoint(1, 1),
					VertexShader,
					EDRF_Default);
			}
			RHICmdList.EndRenderPass();
		}
		PrevEnvironmentDepthMinMaxSwapchainIndex = DepthFrameDesc.SwapchainIndex;
	}

	FSettingsPtr FOculusXRHMD::CreateNewSettings() const
	{
		FSettingsPtr Result(MakeShareable(new FSettings()));
		return Result;
	}

	FGameFramePtr FOculusXRHMD::CreateNewGameFrame() const
	{
		FGameFramePtr Result(MakeShareable(new FGameFrame()));
		Result->FrameNumber = NextFrameNumber;
		Result->WindowSize = CachedWindowSize;
		Result->WorldToMetersScale = CachedWorldToMetersScale;
		Result->NearClippingPlane = GNearClippingPlane;
		// Allow CVars to override the app's foveated rendering settings (set -1 to restore app's setting)
		Result->FoveatedRenderingMethod = CVarOculusFoveatedRenderingMethod.GetValueOnAnyThread() >= 0 ? (EOculusXRFoveatedRenderingMethod)CVarOculusFoveatedRenderingMethod.GetValueOnAnyThread() : FoveatedRenderingMethod.load();
		Result->FoveatedRenderingLevel = CVarOculusFoveatedRenderingLevel.GetValueOnAnyThread() >= 0 ? (EOculusXRFoveatedRenderingLevel)CVarOculusFoveatedRenderingLevel.GetValueOnAnyThread() : FoveatedRenderingLevel.load();
		Result->bDynamicFoveatedRendering = CVarOculusDynamicFoveatedRendering.GetValueOnAnyThread() >= 0 ? (bool)CVarOculusDynamicFoveatedRendering.GetValueOnAnyThread() : bDynamicFoveatedRendering.load();
		Result->Flags.bSplashIsShown = Splash->IsShown();
		return Result;
	}

	void FOculusXRHMD::StartGameFrame_GameThread()
	{
		CheckInGameThread();
		check(Settings.IsValid());

		// bShouldWait_GameThread is to prevent to WaitToBeginFrame() twice back-two-back (for two frames) which will further fall into a deadlock.
		if (!bShouldWait_GameThread)
		{
			return;
		}

		if (!Frame.IsValid())
		{
			Splash->UpdateLoadingScreen_GameThread(); // the result of this is used in CreateGameFrame to know if Frame is a "real" one or a "splash" one.
			if (Settings->Flags.bHMDEnabled)
			{
				Frame = CreateNewGameFrame();
				NextFrameToRender = Frame;

				UE_LOG(LogHMD, VeryVerbose, TEXT("StartGameFrame %u"), Frame->FrameNumber);

				if (!Splash->IsShown())
				{
					FThreadIdleStats::FScopeIdle Scope;

					if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized() && WaitFrameNumber != Frame->FrameNumber)
					{
						SCOPED_NAMED_EVENT(WaitFrame, FColor::Red);

						UE_LOG(LogHMD, Verbose, TEXT("FOculusXRHMDModule::GetPluginWrapper().WaitToBeginFrame %u"), Frame->FrameNumber);

						ovrpResult Result;
						if (OVRP_FAILURE(Result = FOculusXRHMDModule::GetPluginWrapper().WaitToBeginFrame(Frame->FrameNumber)))
						{
							UE_LOG(LogHMD, Error, TEXT("FOculusXRHMDModule::GetPluginWrapper().WaitToBeginFrame %u failed (%d)"), Frame->FrameNumber, Result);
						}
						else
						{
							WaitFrameNumber = Frame->FrameNumber;
							bShouldWait_GameThread = false;
						}
					}

					FOculusXRHMDModule::GetPluginWrapper().Update3(ovrpStep_Render, Frame->FrameNumber, 0.0);
				}
			}

			UpdateStereoRenderingParams();
		}
	}

	void FOculusXRHMD::FinishGameFrame_GameThread()
	{
		CheckInGameThread();

		if (Frame.IsValid())
		{
			UE_LOG(LogHMD, VeryVerbose, TEXT("FinishGameFrame %u"), Frame->FrameNumber);
		}

		Frame.Reset();
	}

	void FOculusXRHMD::StartRenderFrame_GameThread()
	{
		CheckInGameThread();

		if (NextFrameToRender.IsValid() && NextFrameToRender != LastFrameToRender)
		{
			UE_LOG(LogHMD, VeryVerbose, TEXT("StartRenderFrame %u"), NextFrameToRender->FrameNumber);

			LastFrameToRender = NextFrameToRender;
			NextFrameToRender->Flags.bSplashIsShown = Splash->IsShown();

			ovrpXrApi NativeXrApi;
			FOculusXRHMDModule::GetPluginWrapper().GetNativeXrApiType(&NativeXrApi);
			if ((NextFrameToRender->ShowFlags.Rendering || NativeXrApi == ovrpXrApi_OpenXR) && !NextFrameToRender->Flags.bSplashIsShown)
			{
				NextFrameNumber++;
			}

			FSettingsPtr XSettings = Settings->Clone();
			FGameFramePtr XFrame = NextFrameToRender->Clone();
			TArray<FLayerPtr> XLayers;

			XLayers.Empty(LayerMap.Num());

			for (auto Pair : LayerMap)
			{
				XLayers.Emplace(Pair.Value->Clone());
			}

			XLayers.Sort(FLayerPtr_CompareId());

			ExecuteOnRenderThread_DoNotWait([this, XSettings, XFrame, XLayers](FRHICommandListImmediate& RHICmdList) {
				if (XFrame.IsValid())
				{
					Settings_RenderThread = XSettings;
					Frame_RenderThread = XFrame;

					int32 XLayerIndex = 0;
					int32 LayerIndex_RenderThread = 0;
					TArray<FLayerPtr> ValidXLayers;

					while (XLayerIndex < XLayers.Num() && LayerIndex_RenderThread < Layers_RenderThread.Num())
					{
						uint32 LayerIdA = XLayers[XLayerIndex]->GetId();
						uint32 LayerIdB = Layers_RenderThread[LayerIndex_RenderThread]->GetId();

						if (LayerIdA < LayerIdB)
						{
							if (XLayers[XLayerIndex]->Initialize_RenderThread(Settings_RenderThread.Get(), CustomPresent, &DeferredDeletion, RHICmdList))
							{
								ValidXLayers.Add(XLayers[XLayerIndex]);
							}
							XLayerIndex++;
						}
						else if (LayerIdA > LayerIdB)
						{
							DeferredDeletion.AddLayerToDeferredDeletionQueue(Layers_RenderThread[LayerIndex_RenderThread++]);
						}
						else
						{
							if (XLayers[XLayerIndex]->Initialize_RenderThread(Settings_RenderThread.Get(), CustomPresent, &DeferredDeletion, RHICmdList, Layers_RenderThread[LayerIndex_RenderThread].Get()))
							{
								LayerIndex_RenderThread++;
								ValidXLayers.Add(XLayers[XLayerIndex]);
							}
							XLayerIndex++;
						}
					}

					while (XLayerIndex < XLayers.Num())
					{
						if (XLayers[XLayerIndex]->Initialize_RenderThread(Settings_RenderThread.Get(), CustomPresent, &DeferredDeletion, RHICmdList))
						{
							ValidXLayers.Add(XLayers[XLayerIndex]);
						}
						XLayerIndex++;
					}

					while (LayerIndex_RenderThread < Layers_RenderThread.Num())
					{
						DeferredDeletion.AddLayerToDeferredDeletionQueue(Layers_RenderThread[LayerIndex_RenderThread++]);
					}

					Layers_RenderThread = ValidXLayers;

					DeferredDeletion.HandleLayerDeferredDeletionQueue_RenderThread();
				}
			});
		}
	}

	void FOculusXRHMD::FinishRenderFrame_RenderThread(FRDGBuilder& GraphBuilder)
	{
		CheckInRenderThread();

		// bIsRendering_RenderThread is to keep Frame_RenderThread alive if we haven't started to use it to render yet!
		if (!bIsRendering_RenderThread)
		{
			return;
		}

		if (Frame_RenderThread.IsValid())
		{
			UE_LOG(LogHMD, VeryVerbose, TEXT("FinishRenderFrame %u"), Frame_RenderThread->FrameNumber);

			AddPass(GraphBuilder, RDG_EVENT_NAME("FinishRenderFrame"), [this](FRHICommandListImmediate& RHICmdList) {
				if (Frame_RenderThread->ShowFlags.Rendering)
				{
					for (int32 LayerIndex = 0; LayerIndex < Layers_RenderThread.Num(); LayerIndex++)
					{
						Layers_RenderThread[LayerIndex]->UpdateTexture_RenderThread(Settings_RenderThread.Get(), CustomPresent, RHICmdList);
						Layers_RenderThread[LayerIndex]->UpdatePassthrough_RenderThread(CustomPresent, RHICmdList, Frame_RenderThread.Get());
					}
				}
				Frame_RenderThread.Reset();
			});
		}

		bIsRendering_RenderThread = false;
	}

	void FOculusXRHMD::StartRHIFrame_RenderThread()
	{
		CheckInRenderThread();

		if (Frame_RenderThread.IsValid())
		{
			UE_LOG(LogHMD, VeryVerbose, TEXT("StartRHIFrame %u"), Frame_RenderThread->FrameNumber);

			FSettingsPtr XSettings = Settings_RenderThread->Clone();
			FGameFramePtr XFrame = Frame_RenderThread->Clone();
			TArray<FLayerPtr> XLayers = Layers_RenderThread;

			for (int32 XLayerIndex = 0; XLayerIndex < XLayers.Num(); XLayerIndex++)
			{
				XLayers[XLayerIndex] = XLayers[XLayerIndex]->Clone();
			}

			ExecuteOnRHIThread_DoNotWait([this, XSettings, XFrame, XLayers]() {
				if (XFrame.IsValid())
				{
					Settings_RHIThread = XSettings;
					Frame_RHIThread = XFrame;
					Layers_RHIThread = XLayers;

					ovrpXrApi NativeXrApi;
					FOculusXRHMDModule::GetPluginWrapper().GetNativeXrApiType(&NativeXrApi);
					if ((Frame_RHIThread->ShowFlags.Rendering || NativeXrApi == ovrpXrApi_OpenXR) && !Frame_RHIThread->Flags.bSplashIsShown)
					{
						SCOPED_NAMED_EVENT(BeginFrame, FColor::Red);

						UE_LOG(LogHMD, Verbose, TEXT("FOculusXRHMDModule::GetPluginWrapper().BeginFrame4 %u"), Frame_RHIThread->FrameNumber);

						ovrpResult Result;
						if (OVRP_FAILURE(Result = FOculusXRHMDModule::GetPluginWrapper().BeginFrame4(Frame_RHIThread->FrameNumber, CustomPresent->GetOvrpCommandQueue())))
						{
							UE_LOG(LogHMD, Error, TEXT("FOculusXRHMDModule::GetPluginWrapper().BeginFrame4 %u failed (%d)"), Frame_RHIThread->FrameNumber, Result);
							Frame_RHIThread->ShowFlags.Rendering = false;
						}
						else
						{
#if PLATFORM_ANDROID
							FOculusXRHMDModule::GetPluginWrapper().SetTiledMultiResLevel((ovrpTiledMultiResLevel)Frame_RHIThread->FoveatedRenderingLevel);
							FOculusXRHMDModule::GetPluginWrapper().SetTiledMultiResDynamic(Frame_RHIThread->bDynamicFoveatedRendering ? ovrpBool_True : ovrpBool_False);
#ifdef WITH_OCULUS_BRANCH
							// If we're using eye tracked foveated rendering, set that at the end of the render pass instead (through UpdateFoveationOffsets_RenderThread)
							if (Frame_RHIThread->FoveatedRenderingMethod != EOculusXRFoveatedRenderingMethod::EyeTrackedFoveatedRendering)
							{
								FOculusXRHMDModule::GetPluginWrapper().SetFoveationEyeTracked(ovrpBool_False);
								// Need to also not use offsets when turning off eye tracked foveated rendering
								if (CustomPresent)
								{
									CustomPresent->UpdateFoveationOffsets_RHIThread(false, nullptr);
								}
							}
#endif // WITH_OCULUS_BRANCH
#endif // PLATFORM_ANDROID
						}
					}
				}
			});

			bIsRendering_RenderThread = true;
		}
	}

	void FOculusXRHMD::FinishRHIFrame_RHIThread()
	{
		CheckInRHIThread();

		if (Frame_RHIThread.IsValid())
		{
			UE_LOG(LogHMD, VeryVerbose, TEXT("FinishRHIFrame %u"), Frame_RHIThread->FrameNumber);

			ovrpXrApi NativeXrApi;
			FOculusXRHMDModule::GetPluginWrapper().GetNativeXrApiType(&NativeXrApi);
			if ((Frame_RHIThread->ShowFlags.Rendering || NativeXrApi == ovrpXrApi_OpenXR) && !Frame_RHIThread->Flags.bSplashIsShown)
			{
				SCOPED_NAMED_EVENT(EndFrame, FColor::Red);

				TArray<FLayerPtr> Layers = Layers_RHIThread;
				Layers.Sort(FLayerPtr_CompareTotal());
				TArray<const ovrpLayerSubmit*> LayerSubmitPtr;

				int32 LayerNum = Layers.Num();

				LayerSubmitPtr.SetNum(LayerNum);

				int32 FinalLayerNumber = 0;
				for (int32 LayerIndex = 0; LayerIndex < LayerNum; LayerIndex++)
				{
					if (Layers[LayerIndex]->IsVisible())
					{
						LayerSubmitPtr[FinalLayerNumber++] = Layers[LayerIndex]->UpdateLayer_RHIThread(Settings_RHIThread.Get(), Frame_RHIThread.Get(), LayerIndex);
					}
				}

				UE_LOG(LogHMD, Verbose, TEXT("FOculusXRHMDModule::GetPluginWrapper().EndFrame4 %u"), Frame_RHIThread->FrameNumber);
				FOculusXRHMDModule::GetPluginWrapper().SetEyeFovPremultipliedAlphaMode(false);

				ovrpResult Result;
				if (OVRP_FAILURE(Result = FOculusXRHMDModule::GetPluginWrapper().EndFrame4(Frame_RHIThread->FrameNumber, LayerSubmitPtr.GetData(), FinalLayerNumber, CustomPresent->GetOvrpCommandQueue())))
				{
					UE_LOG(LogHMD, Error, TEXT("FOculusXRHMDModule::GetPluginWrapper().EndFrame4 %u failed (%d)"), Frame_RHIThread->FrameNumber, Result);
				}
				else
				{
					for (int32 LayerIndex = 0; LayerIndex < Layers.Num(); LayerIndex++)
					{
						Layers[LayerIndex]->IncrementSwapChainIndex_RHIThread(CustomPresent);
					}
				}
			}
		}

		Frame_RHIThread.Reset();
	}

	void FOculusXRHMD::AddEventPollingDelegate(const FOculusXRHMDEventPollingDelegate& NewDelegate)
	{
		EventPollingDelegates.Add(NewDelegate);
	}

	/// @cond DOXYGEN_WARNINGS

#define BOOLEAN_COMMAND_HANDLER_BODY(ConsoleName, FieldExpr)                        \
	do                                                                              \
	{                                                                               \
		if (Args.Num())                                                             \
		{                                                                           \
			if (Args[0].Equals(TEXT("toggle"), ESearchCase::IgnoreCase))            \
			{                                                                       \
				(FieldExpr) = !(FieldExpr);                                         \
			}                                                                       \
			else                                                                    \
			{                                                                       \
				(FieldExpr) = FCString::ToBool(*Args[0]);                           \
			}                                                                       \
		}                                                                           \
		Ar.Logf(ConsoleName TEXT(" = %s"), (FieldExpr) ? TEXT("On") : TEXT("Off")); \
	}                                                                               \
	while (false)

	void FOculusXRHMD::UpdateOnRenderThreadCommandHandler(const TArray<FString>& Args, UWorld* World, FOutputDevice& Ar)
	{
		CheckInGameThread();

		BOOLEAN_COMMAND_HANDLER_BODY(TEXT("vr.oculus.bUpdateOnRenderThread"), Settings->Flags.bUpdateOnRT);
	}

	void FOculusXRHMD::PixelDensityMinCommandHandler(const TArray<FString>& Args, UWorld*, FOutputDevice& Ar)
	{
		CheckInGameThread();

		if (Args.Num())
		{
			Settings->SetPixelDensityMin(FCString::Atof(*Args[0]));
		}
		Ar.Logf(TEXT("vr.oculus.PixelDensity.min = \"%1.2f\""), Settings->PixelDensityMin);
	}

	void FOculusXRHMD::PixelDensityMaxCommandHandler(const TArray<FString>& Args, UWorld*, FOutputDevice& Ar)
	{
		CheckInGameThread();

		if (Args.Num())
		{
			Settings->SetPixelDensityMax(FCString::Atof(*Args[0]));
		}
		Ar.Logf(TEXT("vr.oculus.PixelDensity.max = \"%1.2f\""), Settings->PixelDensityMax);
	}

	void FOculusXRHMD::HQBufferCommandHandler(const TArray<FString>& Args, UWorld*, FOutputDevice& Ar)
	{
		CheckInGameThread();

		BOOLEAN_COMMAND_HANDLER_BODY(TEXT("vr.oculus.bHQBuffer"), Settings->Flags.bHQBuffer);
	}

	void FOculusXRHMD::HQDistortionCommandHandler(const TArray<FString>& Args, UWorld*, FOutputDevice& Ar)
	{
		CheckInGameThread();

		BOOLEAN_COMMAND_HANDLER_BODY(TEXT("vr.oculus.bHQDistortion"), Settings->Flags.bHQDistortion);
	}

	void FOculusXRHMD::ShowGlobalMenuCommandHandler(const TArray<FString>& Args, UWorld* World, FOutputDevice& Ar)
	{
		CheckInGameThread();

		if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().ShowSystemUI2(ovrpUI::ovrpUI_GlobalMenu)))
		{
			Ar.Logf(TEXT("Could not show platform menu"));
		}
	}

	void FOculusXRHMD::ShowQuitMenuCommandHandler(const TArray<FString>& Args, UWorld* World, FOutputDevice& Ar)
	{
		CheckInGameThread();

		if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().ShowSystemUI2(ovrpUI::ovrpUI_ConfirmQuit)))
		{
			Ar.Logf(TEXT("Could not show platform menu"));
		}
	}

#if !UE_BUILD_SHIPPING
	void FOculusXRHMD::StatsCommandHandler(const TArray<FString>& Args, UWorld*, FOutputDevice& Ar)
	{
		CheckInGameThread();

		BOOLEAN_COMMAND_HANDLER_BODY(TEXT("vr.oculus.Debug.bShowStats"), Settings->Flags.bShowStats);
	}

	void FOculusXRHMD::ShowSettingsCommandHandler(const TArray<FString>& Args, UWorld* World, FOutputDevice& Ar)
	{
		Ar.Logf(TEXT("stereo ipd=%.4f\n nearPlane=%.4f"), GetInterpupillaryDistance(), GNearClippingPlane);
	}

	void FOculusXRHMD::IPDCommandHandler(const TArray<FString>& Args, UWorld* World, FOutputDevice& Ar)
	{
		if (Args.Num() > 0)
		{
			SetInterpupillaryDistance(FCString::Atof(*Args[0]));
		}
		Ar.Logf(TEXT("vr.oculus.Debug.IPD = %f"), GetInterpupillaryDistance());
	}

#endif // !UE_BUILD_SHIPPING

	void FOculusXRHMD::LoadFromSettings()
	{
		UOculusXRHMDRuntimeSettings* HMDSettings = GetMutableDefault<UOculusXRHMDRuntimeSettings>();
		check(HMDSettings);

		Settings->Flags.bSupportsDash = HMDSettings->bSupportsDash;
#if PLATFORM_ANDROID
		Settings->Flags.bCompositeDepth = HMDSettings->bCompositeDepthMobile;
#else
		Settings->Flags.bCompositeDepth = HMDSettings->bCompositesDepth;
#endif
		Settings->Flags.bHQDistortion = HMDSettings->bHQDistortion;
		Settings->Flags.bInsightPassthroughEnabled = HMDSettings->bInsightPassthroughEnabled;
#ifdef WITH_OCULUS_BRANCH
		Settings->Flags.bPixelDensityAdaptive = HMDSettings->bDynamicResolution;
#endif
		Settings->SuggestedCpuPerfLevel = HMDSettings->SuggestedCpuPerfLevel;
		Settings->SuggestedGpuPerfLevel = HMDSettings->SuggestedGpuPerfLevel;
		Settings->FoveatedRenderingMethod = HMDSettings->FoveatedRenderingMethod;
		Settings->FoveatedRenderingLevel = HMDSettings->FoveatedRenderingLevel;
		Settings->bDynamicFoveatedRendering = HMDSettings->bDynamicFoveatedRendering;
		Settings->PixelDensityMin = HMDSettings->PixelDensityMin;
		Settings->PixelDensityMax = HMDSettings->PixelDensityMax;
		Settings->ColorSpace = HMDSettings->ColorSpace;
		Settings->ControllerPoseAlignment = HMDSettings->ControllerPoseAlignment;
		Settings->bLateLatching = HMDSettings->bLateLatching;
		Settings->XrApi = HMDSettings->XrApi;
		Settings->bSupportExperimentalFeatures = HMDSettings->bSupportExperimentalFeatures;
		Settings->bSupportEyeTrackedFoveatedRendering = HMDSettings->bSupportEyeTrackedFoveatedRendering;
		Settings->SystemSplashBackground = HMDSettings->SystemSplashBackground;

		Settings->BodyTrackingFidelity = HMDSettings->BodyTrackingFidelity;
		Settings->BodyTrackingJointSet = HMDSettings->BodyTrackingJointSet;

		Settings->FaceTrackingDataSource.Empty(ovrpFaceConstants_FaceTrackingDataSourcesCount);
		Settings->FaceTrackingDataSource.Append(HMDSettings->FaceTrackingDataSource);
	}
	/// @endcond

} // namespace OculusXRHMD

#endif // OCULUS_HMD_SUPPORTED_PLATFORMS
