// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#include "OculusXRMRFunctionLibrary.h"
#include "OculusXRMRPrivate.h"
#include "OculusXRMRModule.h"
#include "OculusXRMR_CastingCameraActor.h"
#include "OculusXRMR_State.h"
#include "OculusXRHMD.h"
#include "OculusXRHMDPrivate.h"
#include "IHeadMountedDisplay.h"

#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"

//-------------------------------------------------------------------------------------------------
// UOculusXRFunctionLibrary
//-------------------------------------------------------------------------------------------------

UOculusXRMRFunctionLibrary::UOculusXRMRFunctionLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UOculusXRMRFunctionLibrary::GetAllTrackedCamera(TArray<FOculusXRTrackedCamera>& TrackedCameras, bool bCalibratedOnly)
{
	TrackedCameras.Empty();

	if (!FOculusXRMRModule::IsAvailable() || !FOculusXRMRModule::Get().IsInitialized())
	{
		UE_LOG(LogMR, Error, TEXT("OculusXRMR not available"));
		return;
	}

	if (FOculusXRHMDModule::GetPluginWrapper().GetInitialized() == ovrpBool_False)
	{
		UE_LOG(LogMR, Error, TEXT("OVRPlugin not initialized"));
		return;
	}

	if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().UpdateExternalCamera()))
	{
		UE_LOG(LogMR, Error, TEXT("FOculusXRHMDModule::GetPluginWrapper().UpdateExternalCamera failure"));
		return;
	}

	int cameraCount = 0;
	if (OVRP_FAILURE(FOculusXRHMDModule::GetPluginWrapper().GetExternalCameraCount(&cameraCount)))
	{
		UE_LOG(LogMR, Log, TEXT("FOculusXRHMDModule::GetPluginWrapper().GetExternalCameraCount failure"));
		return;
	}

	for (int i = 0; i < cameraCount; ++i)
	{
		char cameraName[OVRP_EXTERNAL_CAMERA_NAME_SIZE];
		ovrpCameraIntrinsics cameraIntrinsics;
		ovrpCameraExtrinsics cameraExtrinsics;
		FOculusXRHMDModule::GetPluginWrapper().GetExternalCameraName(i, cameraName);
		FOculusXRHMDModule::GetPluginWrapper().GetExternalCameraIntrinsics(i, &cameraIntrinsics);
		FOculusXRHMDModule::GetPluginWrapper().GetExternalCameraExtrinsics(i, &cameraExtrinsics);
		if ((bCalibratedOnly == false || cameraExtrinsics.CameraStatus == ovrpCameraStatus_Calibrated) && cameraIntrinsics.IsValid && cameraExtrinsics.IsValid)
		{
			FOculusXRTrackedCamera camera;
			camera.Index = i;
			camera.Name = cameraName;
			camera.FieldOfView = FMath::RadiansToDegrees(FMath::Atan(cameraIntrinsics.FOVPort.LeftTan) + FMath::Atan(cameraIntrinsics.FOVPort.RightTan));
			camera.SizeX = cameraIntrinsics.ImageSensorPixelResolution.w;
			camera.SizeY = cameraIntrinsics.ImageSensorPixelResolution.h;
			camera.AttachedTrackedDevice = OculusXRHMD::ToEOculusXRTrackedDeviceType(cameraExtrinsics.AttachedToNode);
			OculusXRHMD::FPose Pose;
			GetOculusXRHMD()->ConvertPose(cameraExtrinsics.RelativePose, Pose);
			camera.CalibratedRotation = Pose.Orientation.Rotator();
			camera.CalibratedOffset = Pose.Position;
			camera.UserRotation = FRotator::ZeroRotator;
			camera.UserOffset = FVector::ZeroVector;
			TrackedCameras.Add(camera);
		}
	}
}

OculusXRHMD::FOculusXRHMD* UOculusXRMRFunctionLibrary::GetOculusXRHMD()
{
#if OCULUS_HMD_SUPPORTED_PLATFORMS
	if (GEngine && GEngine->XRSystem.IsValid())
	{
		static const FName OculusSystemName(TEXT("OculusXRHMD"));
		if (GEngine->XRSystem->GetSystemName() == OculusSystemName)
		{
			return static_cast<OculusXRHMD::FOculusXRHMD*>(GEngine->XRSystem.Get());
		}
	}
#endif
	return nullptr;
}

bool UOculusXRMRFunctionLibrary::GetTrackingReferenceLocationAndRotationInWorldSpace(USceneComponent* TrackingReferenceComponent, FVector& TRLocation, FRotator& TRRotation)
{
	if (!TrackingReferenceComponent)
	{
		APlayerController* PlayerController = GWorld->GetFirstPlayerController();
		if (!PlayerController)
		{
			return false;
		}
		APawn* Pawn = PlayerController->GetPawn();
		if (!Pawn)
		{
			return false;
		}
		TRLocation = Pawn->GetActorLocation();
		TRRotation = Pawn->GetActorRotation();
		return true;
	}
	else
	{
		TRLocation = TrackingReferenceComponent->GetComponentLocation();
		TRRotation = TrackingReferenceComponent->GetComponentRotation();
		return true;
	}
}

UOculusXRMR_Settings* UOculusXRMRFunctionLibrary::GetOculusXRMRSettings()
{
	UOculusXRMR_Settings* Settings = nullptr;
	if (FOculusXRMRModule::IsAvailable())
	{
		Settings = FOculusXRMRModule::Get().GetMRSettings();
	}
	return Settings;
}

USceneComponent* UOculusXRMRFunctionLibrary::GetTrackingReferenceComponent()
{
	USceneComponent* TrackingRef = nullptr;
	if (FOculusXRMRModule::IsAvailable())
	{
		TrackingRef = FOculusXRMRModule::Get().GetMRState()->TrackingReferenceComponent;
	}
	return TrackingRef;
}

bool UOculusXRMRFunctionLibrary::SetTrackingReferenceComponent(USceneComponent* Component)
{
	if (FOculusXRMRModule::IsAvailable())
	{
		FOculusXRMRModule::Get().GetMRState()->TrackingReferenceComponent = Component;
		return true;
	}
	return false;
}

float UOculusXRMRFunctionLibrary::GetMrcScalingFactor()
{
	if (FOculusXRMRModule::IsAvailable())
	{
		return FOculusXRMRModule::Get().GetMRState()->ScalingFactor;
	}
	return 0.0;
}

bool UOculusXRMRFunctionLibrary::SetMrcScalingFactor(float ScalingFactor)
{
	if (FOculusXRMRModule::IsAvailable() && ScalingFactor > 0.0f)
	{
		FOculusXRMRModule::Get().GetMRState()->ScalingFactor = ScalingFactor;
		return true;
	}
	return false;
}

bool UOculusXRMRFunctionLibrary::IsMrcEnabled()
{
	return FOculusXRMRModule::IsAvailable() && FOculusXRMRModule::Get().IsInitialized();
}

bool UOculusXRMRFunctionLibrary::IsMrcActive()
{
	return FOculusXRMRModule::IsAvailable() && FOculusXRMRModule::Get().IsActive();
}
