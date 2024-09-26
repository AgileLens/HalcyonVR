// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "UObject/ObjectMacros.h"
#include "OculusXRFunctionLibrary.h"
#include "OculusXRPluginWrapper.h"

#include "OculusXRMR_State.generated.h"

USTRUCT()
struct FOculusXRTrackedCamera
{
	GENERATED_USTRUCT_BODY()

	/** >=0: the index of the external camera
	 * -1: not bind to any external camera (and would be setup to match the manual CastingCameraActor placement)
	 */
	UPROPERTY()
	int32 Index;

	/** The external camera name set through the CameraTool */
	UPROPERTY()
	FString Name;

	/** The time that this camera was updated */
	UPROPERTY()
	double UpdateTime;

	/** The horizontal FOV, in degrees */
	UPROPERTY(meta = (UIMin = "5.0", UIMax = "170", ClampMin = "0.001", ClampMax = "360.0", Units = deg))
	float FieldOfView;

	/** The resolution of the camera frame */
	UPROPERTY()
	int32 SizeX;

	/** The resolution of the camera frame */
	UPROPERTY()
	int32 SizeY;

	/** The tracking node the external camera is bound to */
	UPROPERTY()
	EOculusXRTrackedDeviceType AttachedTrackedDevice;

	/** The relative pose of the camera to the attached tracking device */
	UPROPERTY()
	FRotator CalibratedRotation;

	/** The relative pose of the camera to the attached tracking device */
	UPROPERTY()
	FVector CalibratedOffset;

	/** (optional) The user pose is provided to fine tuning the relative camera pose at the run-time */
	UPROPERTY()
	FRotator UserRotation;

	/** (optional) The user pose is provided to fine tuning the relative camera pose at the run-time */
	UPROPERTY()
	FVector UserOffset;

	/** The raw pose of the camera to the attached tracking device (Deprecated) */
	UPROPERTY(meta = (DeprecatedProperty, DeprecationMessage = "All camera pose info is now in stage space, do not use raw pose data."))
	FRotator RawRotation_DEPRECATED;

	/** The raw pose of the camera to the attached tracking device (Deprecated) */
	UPROPERTY(meta = (DeprecatedProperty, DeprecationMessage = "All camera pose info is now in stage space, do not use raw pose data."))
	FVector RawOffset_DEPRECATED;

	FOculusXRTrackedCamera()
		: Index(-1)
		, Name(TEXT("Unknown"))
		, UpdateTime(0.0f)
		, FieldOfView(90.0f)
		, SizeX(1280)
		, SizeY(720)
		, AttachedTrackedDevice(EOculusXRTrackedDeviceType::None)
		, CalibratedRotation(EForceInit::ForceInitToZero)
		, CalibratedOffset(EForceInit::ForceInitToZero)
		, UserRotation(EForceInit::ForceInitToZero)
		, UserOffset(EForceInit::ForceInitToZero)
		, RawRotation_DEPRECATED(EForceInit::ForceInitToZero)
		, RawOffset_DEPRECATED(EForceInit::ForceInitToZero)
	{
	}
};

/**
 * Object to hold the state of MR capture and capturing camera
 */
UCLASS(ClassGroup = OculusXRMR, NotPlaceable, NotBlueprintable)
class UOculusXRMR_State : public UObject
{
	GENERATED_BODY()

public:
	UOculusXRMR_State(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()
	FOculusXRTrackedCamera TrackedCamera;

	// Component at the tracking origin that the camera calibration is applied to
	UPROPERTY()
	class USceneComponent* TrackingReferenceComponent;

	// A multiplier on the camera distance, should be based on the scaling of the player component
	UPROPERTY()
	double ScalingFactor;

	/** Flag indicating a change in the tracked camera state for the camera actor to consume */
	UPROPERTY()
	bool ChangeCameraStateRequested;

	/** Flag indicating a change in the tracked camera index for the camera actor to consume */
	UPROPERTY()
	bool BindToTrackedCameraIndexRequested;
};
