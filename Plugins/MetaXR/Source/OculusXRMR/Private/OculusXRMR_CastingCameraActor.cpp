// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRMR_CastingCameraActor.h"

#include "OculusXRMRPrivate.h"
#include "OculusXRHMD_Settings.h"
#include "OculusXRHMD.h"
#include "OculusXRHMD_SpectatorScreenController.h"
#include "OculusXRMRModule.h"
#include "OculusXRMR_Settings.h"
#include "OculusXRMR_State.h"
#include "OculusXRMR_PlaneMeshComponent.h"
#include "OculusXRMRFunctionLibrary.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/WorldSettings.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Rendering/Texture2DResource.h"
#include "RenderingThread.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "VRNotificationsComponent.h"
#include "RenderUtils.h"
#include "AudioDevice.h"
#include "Materials/Material.h"
#include "RHIDefinitions.h"
#include "DataDrivenShaderPlatformInfo.h"

#define LOCTEXT_NAMESPACE "OculusXRMR_CastingCameraActor"

// Possibly add 2=Limited in a future update
static TAutoConsoleVariable<int32> CEnableExternalCompositionPostProcess(TEXT("oculus.mr.ExternalCompositionPostProcess"), 0, TEXT("Enable MR external composition post process: 0=Off, 1=On"));
static TAutoConsoleVariable<int32> COverrideMixedRealityParametersVar(TEXT("oculus.mr.OverrideParameters"), 0, TEXT("Use the Mixed Reality console variables"));

namespace
{
	bool GetCameraTrackedObjectPoseInTrackingSpace(OculusXRHMD::FOculusXRHMD* OculusXRHMD, const FOculusXRTrackedCamera& TrackedCamera, OculusXRHMD::FPose& CameraTrackedObjectPose)
	{
		using namespace OculusXRHMD;

		CameraTrackedObjectPose = FPose(FQuat::Identity, FVector::ZeroVector);

		if (TrackedCamera.AttachedTrackedDevice != EOculusXRTrackedDeviceType::None)
		{
			ovrpResult result = ovrpSuccess;
			ovrpPoseStatef cameraPoseState;
			ovrpNode deviceNode = ToOvrpNode(TrackedCamera.AttachedTrackedDevice);
			ovrpBool nodePresent = ovrpBool_False;
			result = FOculusXRHMDModule::GetPluginWrapper().GetNodePresent2(deviceNode, &nodePresent);
			if (OVRP_FAILURE(result))
			{
				UE_LOG(LogMR, Warning, TEXT("Unable to check if AttachedTrackedDevice is present"));
				return false;
			}
			if (!nodePresent)
			{
				UE_LOG(LogMR, Warning, TEXT("AttachedTrackedDevice is not present"));
				return false;
			}

			OculusXRHMD::FGameFrame* CurrentFrame;
			if (IsInGameThread())
			{
				CurrentFrame = OculusXRHMD->GetNextFrameToRender();
			}
			else
			{
				CurrentFrame = OculusXRHMD->GetFrame_RenderThread();
			}

			result = CurrentFrame ? FOculusXRHMDModule::GetPluginWrapper().GetNodePoseState3(ovrpStep_Render, CurrentFrame->FrameNumber, deviceNode, &cameraPoseState) : ovrpFailure;
			if (OVRP_FAILURE(result))
			{
				UE_LOG(LogMR, Warning, TEXT("Unable to retrieve AttachedTrackedDevice pose state"));
				return false;
			}
			OculusXRHMD->ConvertPose(cameraPoseState.Pose, CameraTrackedObjectPose);
		}

		return true;
	}
} // namespace

//////////////////////////////////////////////////////////////////////////
// ACastingCameraActor

AOculusXRMR_CastingCameraActor::AOculusXRMR_CastingCameraActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, TrackedCameraCalibrationRequired(false)
	, HasTrackedCameraCalibrationCalibrated(false)
	, RefreshBoundaryMeshCounter(3)
	, ForegroundLayerBackgroundColor(FColor::Green)
	, ForegroundMaxDistance(300.0f)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = true;

	VRNotificationComponent = CreateDefaultSubobject<UVRNotificationsComponent>(TEXT("VRNotificationComponent"));

#if PLATFORM_WINDOWS
	PlaneMeshComponent = CreateDefaultSubobject<UOculusXRMR_PlaneMeshComponent>(TEXT("PlaneMeshComponent"));
	PlaneMeshComponent->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);
	PlaneMeshComponent->ResetRelativeTransform();
	PlaneMeshComponent->SetVisibility(false);
#endif

	OpaqueColoredMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), nullptr, TEXT("/OculusXR/Materials/OculusMR_OpaqueColoredMaterial")));
	if (!OpaqueColoredMaterial)
	{
		UE_LOG(LogMR, Warning, TEXT("Invalid OpaqueColoredMaterial"));
	}

	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UTexture2D> WhiteSquareTexture;

		FConstructorStatics()
			: WhiteSquareTexture(TEXT("/Engine/EngineResources/WhiteSquareTexture"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	DefaultTexture_White = ConstructorStatics.WhiteSquareTexture.Object;
	check(DefaultTexture_White);

	ForegroundCaptureActor = nullptr;

	// Set the render targets for background and foreground to copies of the default texture
#if PLATFORM_WINDOWS
	BackgroundRenderTargets.SetNum(1);
	ForegroundRenderTargets.SetNum(1);

	BackgroundRenderTargets[0] = NewObject<UTextureRenderTarget2D>();
	BackgroundRenderTargets[0]->RenderTargetFormat = RTF_RGBA8_SRGB;

	ForegroundRenderTargets[0] = NewObject<UTextureRenderTarget2D>();
	ForegroundRenderTargets[0]->RenderTargetFormat = RTF_RGBA8_SRGB;
#elif PLATFORM_ANDROID
	BackgroundRenderTargets.SetNum(NumRTs);
	ForegroundRenderTargets.SetNum(NumRTs);
	AudioBuffers.SetNum(NumRTs);
	AudioTimes.SetNum(NumRTs);
	PoseTimes.SetNum(NumRTs);

	for (unsigned int i = 0; i < NumRTs; ++i)
	{
		BackgroundRenderTargets[i] = NewObject<UTextureRenderTarget2D>();
		BackgroundRenderTargets[i]->RenderTargetFormat = RTF_RGBA8_SRGB;

		ForegroundRenderTargets[i] = NewObject<UTextureRenderTarget2D>();
		ForegroundRenderTargets[i]->RenderTargetFormat = RTF_RGBA8_SRGB;

		AudioTimes[i] = 0.0;
		PoseTimes[i] = 0.0;
	}

	SyncId = -1;
	RenderedRTs = 0;
	CaptureIndex = 0;
#endif
}

void AOculusXRMR_CastingCameraActor::BeginDestroy()
{
	CloseTrackedCamera();
	Super::BeginDestroy();
}

bool AOculusXRMR_CastingCameraActor::RefreshExternalCamera()
{
	using namespace OculusXRHMD;
	if (MRState->TrackedCamera.Index >= 0)
	{
		int cameraCount;
		if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetExternalCameraCount(&cameraCount)))
		{
			cameraCount = 0;
		}
		if (MRState->TrackedCamera.Index >= cameraCount)
		{
			UE_LOG(LogMR, Error, TEXT("Invalid TrackedCamera Index"));
			return false;
		}
		FOculusXRHMD* OculusXRHMD = GEngine->XRSystem.IsValid() ? (FOculusXRHMD*)(GEngine->XRSystem->GetHMDDevice()) : nullptr;
		if (!OculusXRHMD)
		{
			UE_LOG(LogMR, Error, TEXT("Unable to retrieve OculusXRHMD"));
			return false;
		}
		ovrpResult result = ovrpSuccess;
		ovrpCameraExtrinsics cameraExtrinsics;
		result = FOculusXRHMDModule::GetPluginWrapper().GetExternalCameraExtrinsics(MRState->TrackedCamera.Index, &cameraExtrinsics);
		if (OVRP_FAILURE(result))
		{
			UE_LOG(LogMR, Error, TEXT("FOculusXRHMDModule::GetPluginWrapper().GetExternalCameraExtrinsics failed"));
			return false;
		}
		MRState->TrackedCamera.AttachedTrackedDevice = OculusXRHMD::ToEOculusXRTrackedDeviceType(cameraExtrinsics.AttachedToNode);
		OculusXRHMD::FPose Pose;
		OculusXRHMD->ConvertPose(cameraExtrinsics.RelativePose, Pose);
		MRState->TrackedCamera.CalibratedRotation = Pose.Orientation.Rotator();
		MRState->TrackedCamera.CalibratedOffset = Pose.Position;
		MRState->TrackedCamera.UpdateTime = cameraExtrinsics.LastChangedTimeSeconds;
	}

	return true;
}

void AOculusXRMR_CastingCameraActor::BeginPlay()
{
	Super::BeginPlay();

	SetupTrackedCamera();
	RequestTrackedCameraCalibration();
	SetupMRCScreen();

	FScriptDelegate Delegate;
	Delegate.BindUFunction(this, FName(TEXT("OnHMDRecentered")));
	VRNotificationComponent->HMDRecenteredDelegate.Add(Delegate);

#if PLATFORM_ANDROID
	FAudioDeviceHandle AudioDevice = FAudioDevice::GetMainAudioDevice();
	if (AudioDevice.GetAudioDevice())
	{
		AudioDevice->StartRecording(nullptr, 0.1);
	}
#endif
}

void AOculusXRMR_CastingCameraActor::EndPlay(EEndPlayReason::Type Reason)
{
#if PLATFORM_ANDROID
	FAudioDeviceHandle AudioDevice = FAudioDevice::GetMainAudioDevice();
	if (AudioDevice.GetAudioDevice())
	{
		float NumChannels = 2;
		float SampleRate = AudioDevice->GetSampleRate();
		AudioDevice->StopRecording(nullptr, NumChannels, SampleRate);
	}
#endif

	VRNotificationComponent->HMDRecenteredDelegate.Remove(this, FName(TEXT("OnHMDRecentered")));

	MRState->TrackingReferenceComponent = nullptr;

	CloseMRCScreen();

	CloseTrackedCamera();
	Super::EndPlay(Reason);
}

void AOculusXRMR_CastingCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MRState->BindToTrackedCameraIndexRequested)
	{
		Execute_BindToTrackedCameraIndexIfAvailable();
	}

	if (!RefreshExternalCamera())
	{
		CloseTrackedCamera();
		return;
	}

	// Reset capturing components if the composition method changes
	if (MRState->ChangeCameraStateRequested)
	{
		CloseTrackedCamera();
		CloseMRCScreen();
		SetupTrackedCamera();
		SetupMRCScreen();
	}

#if PLATFORM_WINDOWS
	if (MRSettings->GetCompositionMethod() == EOculusXRMR_CompositionMethod::ExternalComposition)
#endif
	{
		if (ForegroundLayerBackgroundColor != MRSettings->BackdropColor)
		{
			ForegroundLayerBackgroundColor = MRSettings->BackdropColor;
			SetBackdropMaterialColor();
		}
		// Enable external composition post process based on setting
		bool bPostProcess = MRSettings->ExternalCompositionPostProcessEffects != EOculusXRMR_PostProcessEffects::PPE_Off;
		if (COverrideMixedRealityParametersVar.GetValueOnAnyThread() > 0)
		{
			bPostProcess = CEnableExternalCompositionPostProcess.GetValueOnAnyThread() > 0;
		}
		GetCaptureComponent2D()->ShowFlags.PostProcessing = bPostProcess;
		if (ForegroundCaptureActor)
		{
			ForegroundCaptureActor->GetCaptureComponent2D()->ShowFlags.PostProcessing = bPostProcess;
		}
	}

	if (TrackedCameraCalibrationRequired)
	{
		CalibrateTrackedCameraPose();
	}

	UpdateTrackedCameraPosition();

#if PLATFORM_WINDOWS
	RepositionPlaneMesh();
#endif

	UpdateRenderTargetSize();

#if PLATFORM_ANDROID
	OculusXRHMD::FOculusXRHMD* OculusXRHMD = GEngine->XRSystem.IsValid() ? (OculusXRHMD::FOculusXRHMD*)(GEngine->XRSystem->GetHMDDevice()) : nullptr;
	if (OculusXRHMD)
	{
		ovrpPosef OvrpPose, OvrpHeadPose, OvrpLeftHandPose, OvrpRightHandPose;
		FOculusXRHMDModule::GetPluginWrapper().GetTrackingTransformRelativePose(&OvrpPose, ovrpTrackingOrigin_Stage);
		OculusXRHMD::FPose StageToLocalPose;
		OculusXRHMD->ConvertPose(OvrpPose, StageToLocalPose);
		OculusXRHMD::FPose LocalToStagePose = StageToLocalPose.Inverse();

		OculusXRHMD::FPose HeadPose;
		OculusXRHMD->GetCurrentPose(OculusXRHMD::ToExternalDeviceId(ovrpNode_Head), HeadPose.Orientation, HeadPose.Position);
		HeadPose = LocalToStagePose * HeadPose;
		OculusXRHMD->ConvertPose(HeadPose, OvrpHeadPose);

		OculusXRHMD::FPose LeftHandPose;
		OculusXRHMD->GetCurrentPose(OculusXRHMD::ToExternalDeviceId(ovrpNode_HandLeft), HeadPose.Orientation, HeadPose.Position);
		LeftHandPose = LocalToStagePose * LeftHandPose;
		OculusXRHMD->ConvertPose(LeftHandPose, OvrpLeftHandPose);

		OculusXRHMD::FPose RightHandPose;
		OculusXRHMD->GetCurrentPose(OculusXRHMD::ToExternalDeviceId(ovrpNode_HandRight), HeadPose.Orientation, HeadPose.Position);
		RightHandPose = LocalToStagePose * RightHandPose;
		OculusXRHMD->ConvertPose(RightHandPose, OvrpRightHandPose);

		FOculusXRHMDModule::GetPluginWrapper().Media_SetHeadsetControllerPose(OvrpHeadPose, OvrpLeftHandPose, OvrpRightHandPose);
	}

	// Alternate foreground and background captures by nulling the capture component texture target
	if (GetCaptureComponent2D()->IsVisible())
	{
		GetCaptureComponent2D()->SetVisibility(false);

		// Encode a texture the frame before we render to it again to ensure completed render at the cost of latency
		unsigned int EncodeIndex = (CaptureIndex + 1) % NumRTs;

		// Skip encoding for the first few frames before they have completed rendering
		if (RenderedRTs > EncodeIndex)
		{
			FOculusXRHMDModule::GetPluginWrapper().Media_SyncMrcFrame(SyncId);

			int NumChannels = 2;
			double AudioTime = AudioTimes[EncodeIndex];
			void* BackgroundTexture;
			void* ForegroundTexture;

			if (IsVulkanPlatform(GMaxRHIShaderPlatform))
			{
				ExecuteOnRenderThread([this, EncodeIndex, &BackgroundTexture, &ForegroundTexture]() {
					ExecuteOnRHIThread([this, EncodeIndex, &BackgroundTexture, &ForegroundTexture]() {
						// The Vulkan RHI's implementation of GetNativeResource is different and returns the VkImage cast
						// as a void* instead of a pointer to the VkImage, so we need this workaround
						BackgroundTexture = (void*)BackgroundRenderTargets[EncodeIndex]->GetResource()->TextureRHI->GetNativeResource();
						ForegroundTexture = (void*)ForegroundRenderTargets[EncodeIndex]->GetResource()->TextureRHI->GetNativeResource();
					});
				});
			}
			else
			{
				ExecuteOnRenderThread([this, EncodeIndex, &BackgroundTexture, &ForegroundTexture]() {
					ExecuteOnRHIThread([this, EncodeIndex, &BackgroundTexture, &ForegroundTexture]() {
						BackgroundTexture = *((void**)BackgroundRenderTargets[EncodeIndex]->GetResource()->TextureRHI->GetNativeResource());
						ForegroundTexture = *((void**)ForegroundRenderTargets[EncodeIndex]->GetResource()->TextureRHI->GetNativeResource());
					});
				});
			}
			FOculusXRHMDModule::GetPluginWrapper().Media_EncodeMrcFrameDualTexturesWithPoseTime(BackgroundTexture, ForegroundTexture, AudioBuffers[EncodeIndex].GetData(), AudioBuffers[EncodeIndex].Num() * sizeof(float), NumChannels, AudioTime, PoseTimes[CaptureIndex], &SyncId);
		}
		ForegroundCaptureActor->GetCaptureComponent2D()->SetVisibility(true);
	}
	else if (ForegroundCaptureActor && ForegroundCaptureActor->GetCaptureComponent2D()->IsVisible())
	{
		ForegroundCaptureActor->GetCaptureComponent2D()->SetVisibility(false);

		// Increment scene captures to next texture
		CaptureIndex = (CaptureIndex + 1) % NumRTs;
		GetCaptureComponent2D()->TextureTarget = BackgroundRenderTargets[CaptureIndex];
		ForegroundCaptureActor->GetCaptureComponent2D()->TextureTarget = ForegroundRenderTargets[CaptureIndex];
		GetCaptureComponent2D()->SetVisibility(true);

		FAudioDeviceHandle AudioDevice = FAudioDevice::GetMainAudioDevice();
		if (AudioDevice.GetAudioDevice())
		{
			float NumChannels, SampleRate;
			NumChannels = 2;
			SampleRate = AudioDevice->GetSampleRate();
			AudioBuffers[CaptureIndex] = AudioDevice->StopRecording(nullptr, NumChannels, SampleRate);
			AudioTimes[CaptureIndex] = AudioDevice->GetAudioTime();
			// UE_LOG(LogMR, Error, TEXT("SampleRate: %f, NumChannels: %f, Time: %f, Buffer Length: %d, Buffer: %p"), SampleRate, NumChannels, AudioDevice->GetAudioTime(), AudioBuffers[EncodeIndex].Num(), AudioBuffers[EncodeIndex].GetData());
			AudioDevice->StartRecording(nullptr, 0.1);
		}

		// PoseTimes[CaptureIndex] = MRState->TrackedCamera.UpdateTime;

		// Increment this counter for the initial cycle through "swapchain"
		if (RenderedRTs < NumRTs)
		{
			RenderedRTs++;
		}
	}
#endif
}

void AOculusXRMR_CastingCameraActor::Execute_BindToTrackedCameraIndexIfAvailable()
{
	if (!MRState->BindToTrackedCameraIndexRequested)
	{
		return;
	}

	FOculusXRTrackedCamera TempTrackedCamera;
	if (MRSettings->GetBindToTrackedCameraIndex() >= 0)
	{
		TArray<FOculusXRTrackedCamera> TrackedCameras;
		UOculusXRMRFunctionLibrary::GetAllTrackedCamera(TrackedCameras);
		int i;
		for (i = 0; i < TrackedCameras.Num(); ++i)
		{
			if (TrackedCameras[i].Index == MRSettings->GetBindToTrackedCameraIndex())
			{
				TempTrackedCamera = TrackedCameras[i];
				break;
			}
		}
		if (i == TrackedCameras.Num())
		{
			UE_LOG(LogMR, Warning, TEXT("Unable to find TrackedCamera at index %d, use TempTrackedCamera"), MRSettings->GetBindToTrackedCameraIndex());
		}
	}
	else
	{
		UE_LOG(LogMR, Warning, TEXT("BindToTrackedCameraIndex == %d, use TempTrackedCamera"), MRSettings->GetBindToTrackedCameraIndex());
	}

	MRState->TrackedCamera = TempTrackedCamera;
	if (MRState->TrackedCamera.Index < 0)
	{
		SetTrackedCameraUserPoseWithCameraTransform();
	}

	MRState->BindToTrackedCameraIndexRequested = false;
}

void AOculusXRMR_CastingCameraActor::RequestTrackedCameraCalibration()
{
	TrackedCameraCalibrationRequired = true;
}

void AOculusXRMR_CastingCameraActor::CalibrateTrackedCameraPose()
{
	SetTrackedCameraInitialPoseWithPlayerTransform();
	HasTrackedCameraCalibrationCalibrated = true;
	TrackedCameraCalibrationRequired = false;
}

void AOculusXRMR_CastingCameraActor::SetTrackedCameraInitialPoseWithPlayerTransform()
{
	using namespace OculusXRHMD;

	FOculusXRHMD* OculusXRHMD = GEngine->XRSystem.IsValid() ? (FOculusXRHMD*)(GEngine->XRSystem->GetHMDDevice()) : nullptr;
	if (!OculusXRHMD)
	{
		UE_LOG(LogMR, Warning, TEXT("Unable to retrieve OculusXRHMD"));
		return;
	}

	FPose CameraTrackedObjectPose;
	if (!GetCameraTrackedObjectPoseInTrackingSpace(OculusXRHMD, MRState->TrackedCamera, CameraTrackedObjectPose))
	{
		return;
	}

	FPose CameraPose = CameraTrackedObjectPose * FPose(MRState->TrackedCamera.CalibratedRotation.Quaternion(), MRState->TrackedCamera.CalibratedOffset);
	CameraPose = CameraPose * FPose(MRState->TrackedCamera.UserRotation.Quaternion(), MRState->TrackedCamera.UserOffset);

	FQuat TROrientation;
	FVector TRLocation;
	FRotator TRRotation;
	if (!UOculusXRMRFunctionLibrary::GetTrackingReferenceLocationAndRotationInWorldSpace(MRState->TrackingReferenceComponent, TRLocation, TRRotation))
	{
		UE_LOG(LogMR, Warning, TEXT("Could not get player position"));
		return;
	}

	TROrientation = TRRotation.Quaternion();
	FPose FinalPose = FPose(TROrientation, TRLocation) * CameraPose;

	InitialCameraAbsoluteOrientation = FinalPose.Orientation;
	InitialCameraAbsolutePosition = FinalPose.Position;
	InitialCameraRelativeOrientation = CameraPose.Orientation;
	InitialCameraRelativePosition = CameraPose.Position;

	GetCaptureComponent2D()->FOVAngle = MRState->TrackedCamera.FieldOfView;

	if (ForegroundCaptureActor)
	{
		ForegroundCaptureActor->GetCaptureComponent2D()->FOVAngle = MRState->TrackedCamera.FieldOfView;
	}
}

void AOculusXRMR_CastingCameraActor::SetTrackedCameraUserPoseWithCameraTransform()
{
	using namespace OculusXRHMD;

	FOculusXRHMD* OculusXRHMD = GEngine->XRSystem.IsValid() ? (FOculusXRHMD*)(GEngine->XRSystem->GetHMDDevice()) : nullptr;
	if (!OculusXRHMD)
	{
		UE_LOG(LogMR, Warning, TEXT("Unable to retrieve OculusXRHMD"));
		return;
	}

	FPose CameraTrackedObjectPose;
	if (!GetCameraTrackedObjectPoseInTrackingSpace(OculusXRHMD, MRState->TrackedCamera, CameraTrackedObjectPose))
	{
		return;
	}

	FPose CameraPose = CameraTrackedObjectPose * FPose(MRState->TrackedCamera.CalibratedRotation.Quaternion(), MRState->TrackedCamera.CalibratedOffset);

	FQuat TROrientation;
	FVector TRLocation;
	FRotator TRRotation;
	if (!UOculusXRMRFunctionLibrary::GetTrackingReferenceLocationAndRotationInWorldSpace(MRState->TrackingReferenceComponent, TRLocation, TRRotation))
	{
		UE_LOG(LogMR, Warning, TEXT("Could not get player position"));
		return;
	}
	TROrientation = TRRotation.Quaternion();
	FPose PlayerPose(TROrientation, TRLocation);
	FPose CurrentCameraPose = PlayerPose * CameraPose;

	FPose ExpectedCameraPose(GetCaptureComponent2D()->GetComponentRotation().Quaternion(), GetCaptureComponent2D()->GetComponentLocation());
	FPose UserPose = CurrentCameraPose.Inverse() * ExpectedCameraPose;

	MRState->TrackedCamera.UserRotation = UserPose.Orientation.Rotator();
	MRState->TrackedCamera.UserOffset = UserPose.Position;
}

void AOculusXRMR_CastingCameraActor::UpdateTrackedCameraPosition()
{
	check(HasTrackedCameraCalibrationCalibrated);

	using namespace OculusXRHMD;

	FOculusXRHMD* OculusXRHMD = GEngine->XRSystem.IsValid() ? (FOculusXRHMD*)(GEngine->XRSystem->GetHMDDevice()) : nullptr;
	if (!OculusXRHMD)
	{
		UE_LOG(LogMR, Warning, TEXT("Unable to retrieve OculusXRHMD"));
		return;
	}

	FPose CameraTrackedObjectPose;
	if (!GetCameraTrackedObjectPoseInTrackingSpace(OculusXRHMD, MRState->TrackedCamera, CameraTrackedObjectPose))
	{
		return;
	}

	FPose CameraTrackingSpacePose = FPose(MRState->TrackedCamera.CalibratedRotation.Quaternion(), MRState->TrackedCamera.CalibratedOffset);
#if PLATFORM_ANDROID
	ovrpPosef OvrpPose;
	FOculusXRHMDModule::GetPluginWrapper().GetTrackingTransformRelativePose(&OvrpPose, ovrpTrackingOrigin_Stage);
	FPose StageToLocalPose;
	OculusXRHMD->ConvertPose(OvrpPose, StageToLocalPose);
	CameraTrackingSpacePose = StageToLocalPose * CameraTrackingSpacePose;
#endif
	FPose CameraPose = CameraTrackedObjectPose * CameraTrackingSpacePose;
	CameraPose = CameraPose * FPose(MRState->TrackedCamera.UserRotation.Quaternion(), MRState->TrackedCamera.UserOffset);
	CameraPose.Position = CameraPose.Position * MRState->ScalingFactor;

	float Distance = 0.0f;
	if (MRSettings->ClippingReference == EOculusXRMR_ClippingReference::CR_TrackingReference)
	{
		Distance = -FVector::DotProduct(CameraPose.Orientation.GetForwardVector().GetSafeNormal2D(), CameraPose.Position);
	}
	else if (MRSettings->ClippingReference == EOculusXRMR_ClippingReference::CR_Head)
	{
		FQuat HeadOrientation;
		FVector HeadPosition;
		OculusXRHMD->GetCurrentPose(IXRTrackingSystem::HMDDeviceId, HeadOrientation, HeadPosition);
		FVector HeadToCamera = HeadPosition - CameraPose.Position;
		Distance = FVector::DotProduct(CameraPose.Orientation.GetForwardVector().GetSafeNormal2D(), HeadToCamera);
	}
	else
	{
		checkNoEntry();
	}
	ForegroundMaxDistance = FMath::Max(Distance, GMinClipZ);
	if (ForegroundCaptureActor)
	{
		ForegroundCaptureActor->GetCaptureComponent2D()->MaxViewDistanceOverride = ForegroundMaxDistance;
	}

	FPose FinalPose;
	FQuat TROrientation;
	FVector TRLocation;
	FRotator TRRotation;
	if (!UOculusXRMRFunctionLibrary::GetTrackingReferenceLocationAndRotationInWorldSpace(MRState->TrackingReferenceComponent, TRLocation, TRRotation))
	{
		UE_LOG(LogMR, Warning, TEXT("Could not get player position"));
		return;
	}

	TROrientation = TRRotation.Quaternion();
	FinalPose = FPose(TROrientation, TRLocation) * CameraPose;

	FTransform FinalTransform(FinalPose.Orientation, FinalPose.Position);
	RootComponent->SetWorldTransform(FinalTransform);
	GetCaptureComponent2D()->FOVAngle = MRState->TrackedCamera.FieldOfView;

	if (ForegroundCaptureActor)
	{
		ForegroundCaptureActor->GetCaptureComponent2D()->FOVAngle = MRState->TrackedCamera.FieldOfView;
	}
}

void AOculusXRMR_CastingCameraActor::InitializeStates(UOculusXRMR_Settings* MRSettingsIn, UOculusXRMR_State* MRStateIn)
{
	MRSettings = MRSettingsIn;
	MRState = MRStateIn;
}

void AOculusXRMR_CastingCameraActor::SetupTrackedCamera()
{
	if (!RefreshExternalCamera())
	{
		return;
	}

	RequestTrackedCameraCalibration();

	// Unset this flag before we can return
	MRState->ChangeCameraStateRequested = false;

#if PLATFORM_WINDOWS
	if (MRSettings->GetCompositionMethod() == EOculusXRMR_CompositionMethod::ExternalComposition)
	{
		SetupBackdropMaterialInstance();
	}

	RepositionPlaneMesh();
#endif
}

void AOculusXRMR_CastingCameraActor::SetBackdropMaterialColor()
{
	if (BackdropMaterialInstance)
	{
		BackdropMaterialInstance->SetVectorParameterValue(FName(TEXT("Color")), GetForegroundLayerBackgroundColor());
	}
}

void AOculusXRMR_CastingCameraActor::SetupBackdropMaterialInstance()
{
	if (!BackdropMaterialInstance && OpaqueColoredMaterial)
	{
		BackdropMaterialInstance = UMaterialInstanceDynamic::Create(OpaqueColoredMaterial, this);
		BackdropMaterialInstance->SetScalarParameterValue(FName("Opacity"), 0.0f);
	}
	PlaneMeshComponent->SetMaterial(0, BackdropMaterialInstance);
	SetBackdropMaterialColor();
}

void AOculusXRMR_CastingCameraActor::RepositionPlaneMesh()
{
	FVector PlaneCenter = FVector::ForwardVector * ForegroundMaxDistance;
	FVector PlaneUp = FVector::UpVector;
	FVector PlaneNormal = -FVector::ForwardVector;
	int ViewWidth = MRSettings->bUseTrackedCameraResolution ? MRState->TrackedCamera.SizeX : MRSettings->WidthPerView;
	int ViewHeight = MRSettings->bUseTrackedCameraResolution ? MRState->TrackedCamera.SizeY : MRSettings->HeightPerView;
	float Width = ForegroundMaxDistance * FMath::Tan(FMath::DegreesToRadians(GetCaptureComponent2D()->FOVAngle) * 0.5f) * 2.0f;
	float Height = Width * ViewHeight / ViewWidth;
	FVector2D PlaneSize = FVector2D(Width, Height);
	PlaneMeshComponent->Place(PlaneCenter, PlaneUp, PlaneNormal, PlaneSize);
	PlaneMeshComponent->ResetRelativeTransform();
	PlaneMeshComponent->SetVisibility(true);
}

void AOculusXRMR_CastingCameraActor::OnHMDRecentered()
{
#if PLATFORM_WINDOWS
	RefreshBoundaryMesh();
#endif
	RequestTrackedCameraCalibration();
}

void AOculusXRMR_CastingCameraActor::RefreshBoundaryMesh()
{
	RefreshBoundaryMeshCounter = 3;
}

void BuildProjectionMatrix(float YMultiplier, float FOV, float FarClipPlane, FMatrix& ProjectionMatrix)
{
	if (FarClipPlane < GNearClippingPlane)
	{
		FarClipPlane = GNearClippingPlane;
	}

	if ((int32)ERHIZBuffer::IsInverted)
	{
		ProjectionMatrix = FReversedZPerspectiveMatrix(
			FOV,
			FOV,
			1.0f,
			YMultiplier,
			GNearClippingPlane,
			FarClipPlane);
	}
	else
	{
		ProjectionMatrix = FPerspectiveMatrix(
			FOV,
			FOV,
			1.0f,
			YMultiplier,
			GNearClippingPlane,
			FarClipPlane);
	}
}

void AOculusXRMR_CastingCameraActor::UpdateRenderTargetSize()
{
	int ViewWidth = MRSettings->bUseTrackedCameraResolution ? MRState->TrackedCamera.SizeX : MRSettings->WidthPerView;
	int ViewHeight = MRSettings->bUseTrackedCameraResolution ? MRState->TrackedCamera.SizeY : MRSettings->HeightPerView;

#if PLATFORM_WINDOWS
	BackgroundRenderTargets[0]->ResizeTarget(ViewWidth, ViewHeight);
	if (ForegroundRenderTargets[0])
	{
		ForegroundRenderTargets[0]->ResizeTarget(ViewWidth, ViewHeight);
	}
#endif
#if PLATFORM_ANDROID
	FIntPoint CameraTargetSize = FIntPoint(ViewWidth, ViewHeight);
	float FOV = GetCaptureComponent2D()->FOVAngle * (float)PI / 360.0f;

	if (OVRP_SUCCESS(FOculusXRHMDModule::GetPluginWrapper().Media_GetMrcFrameSize(&ViewWidth, &ViewHeight)))
	{
		// Frame size is doublewide, so divide by 2
		ViewWidth /= 2;

		for (unsigned int i = 0; i < NumRTs; ++i)
		{
			BackgroundRenderTargets[i]->ResizeTarget(ViewWidth, ViewHeight);
			if (ForegroundRenderTargets[i])
			{
				ForegroundRenderTargets[i]->ResizeTarget(ViewWidth, ViewHeight);
			}
		}

		// Use custom projection matrix for far clip plane and to use camera aspect ratio instead of rendertarget aspect ratio
		float YMultiplier = (float)CameraTargetSize.X / (float)CameraTargetSize.Y;
		GetCaptureComponent2D()->bUseCustomProjectionMatrix = true;
		BuildProjectionMatrix(YMultiplier, FOV, GNearClippingPlane, GetCaptureComponent2D()->CustomProjectionMatrix);
		if (ForegroundCaptureActor)
		{
			ForegroundCaptureActor->GetCaptureComponent2D()->bUseCustomProjectionMatrix = true;
			BuildProjectionMatrix(YMultiplier, FOV, ForegroundMaxDistance, ForegroundCaptureActor->GetCaptureComponent2D()->CustomProjectionMatrix);
		}
	}
#endif
}

void AOculusXRMR_CastingCameraActor::SetupMRCScreen()
{
#if PLATFORM_WINDOWS
	OculusXRHMD::FSpectatorScreenController* SpecScreen = nullptr;
	IHeadMountedDisplay* HMD = GEngine->XRSystem.IsValid() ? GEngine->XRSystem->GetHMDDevice() : nullptr;
	if (HMD)
	{
		SpecScreen = (OculusXRHMD::FSpectatorScreenController*)HMD->GetSpectatorScreenController();
	}
	if (SpecScreen)
	{
#endif
		UpdateRenderTargetSize();

		// LDR for gamma correction and post process
		GetCaptureComponent2D()->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;

		// Render scene capture 2D output to spectator screen
		GetCaptureComponent2D()->TextureTarget = BackgroundRenderTargets[0];

#if PLATFORM_WINDOWS
		if (MRSettings->GetCompositionMethod() == EOculusXRMR_CompositionMethod::ExternalComposition)
#endif
		{
			ForegroundCaptureActor = GetWorld()->SpawnActor<ASceneCapture2D>();

			// LDR for gamma correction and post process
			ForegroundCaptureActor->GetCaptureComponent2D()->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;
#if PLATFORM_ANDROID
			// Start with foreground capture actor off on android
			ForegroundCaptureActor->GetCaptureComponent2D()->SetVisibility(false);
#endif

			// Don't render anything past the foreground for performance
			ForegroundCaptureActor->GetCaptureComponent2D()->MaxViewDistanceOverride = ForegroundMaxDistance;

			ForegroundCaptureActor->GetCaptureComponent2D()->TextureTarget = ForegroundRenderTargets[0];
#if PLATFORM_WINDOWS
			// Render use split foreground/background rendering to spectator screen
			SpecScreen->SetMRForeground(ForegroundRenderTargets[0]);
			SpecScreen->SetMRBackground(BackgroundRenderTargets[0]);
			SpecScreen->SetMRSpectatorScreenMode(OculusXRHMD::EMRSpectatorScreenMode::ExternalComposition);

			// Set the plane mesh to only render to foreground target
			PlaneMeshComponent->SetPlaneRenderTarget(ForegroundRenderTargets[0]);
#endif
			// Set foreground capture to match background capture
			ForegroundCaptureActor->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true));
		}
#if PLATFORM_WINDOWS
	}
	else
	{
		UE_LOG(LogMR, Error, TEXT("Cannot find spectator screen"));
	}
#endif
}

void AOculusXRMR_CastingCameraActor::CloseMRCScreen()
{
#if PLATFORM_WINDOWS
	OculusXRHMD::FSpectatorScreenController* SpecScreen = nullptr;
	IHeadMountedDisplay* HMD = GEngine->XRSystem.IsValid() ? GEngine->XRSystem->GetHMDDevice() : nullptr;
	if (HMD)
	{
		SpecScreen = (OculusXRHMD::FSpectatorScreenController*)HMD->GetSpectatorScreenController();
	}
	// Restore original spectator screen mode
	if (SpecScreen)
	{
		SpecScreen->SetMRSpectatorScreenMode(OculusXRHMD::EMRSpectatorScreenMode::Default);
		SpecScreen->SetMRForeground(nullptr);
		SpecScreen->SetMRBackground(nullptr);
	}
#endif
	if (ForegroundCaptureActor)
	{
		ForegroundCaptureActor->Destroy();
		ForegroundCaptureActor = nullptr;
	}
}

void AOculusXRMR_CastingCameraActor::CloseTrackedCamera()
{
	if (PlaneMeshComponent)
	{
		PlaneMeshComponent->SetVisibility(false);
	}
}

#undef LOCTEXT_NAMESPACE
