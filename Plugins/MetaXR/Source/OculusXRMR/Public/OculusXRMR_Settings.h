// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "UObject/ObjectMacros.h"

#include "OculusXRMR_Settings.generated.h"

UENUM(BlueprintType)
enum class EOculusXRMR_CameraDeviceEnum : uint8 // Deprecated
{
	CD_None_DEPRECATED UMETA(DisplayName = "None"),
	CD_WebCamera0_DEPRECATED UMETA(DisplayName = "Web Camera 0"),
	CD_WebCamera1_DEPRECATED UMETA(DisplayName = "Web Camera 1"),
};

UENUM(BlueprintType)
enum class EOculusXRMR_ClippingReference : uint8
{
	CR_TrackingReference UMETA(DisplayName = "Tracking Reference"),
	CR_Head UMETA(DisplayName = "Head"),
};

UENUM(BlueprintType)
enum class EOculusXRMR_PostProcessEffects : uint8
{
	PPE_Off UMETA(DisplayName = "Off"),
	PPE_On UMETA(DisplayName = "On"),
};

UENUM(BlueprintType)
enum class EOculusXRMR_CompositionMethod : uint8
{
	/* Generate both foreground and background views for compositing with 3rd-party software like OBS. */
	ExternalComposition UMETA(DisplayName = "External Composition"),
	/* (Deprecated) Composite the camera stream directly to the output with the proper depth.*/
	DirectComposition_DEPRECATED UMETA(DisplayName = "Direct Composition (DEPRECATED)")
};

UCLASS(ClassGroup = OculusXRMR, Blueprintable)
class UOculusXRMR_Settings : public UObject
{
	GENERATED_BODY()

public:
	UOculusXRMR_Settings(const FObjectInitializer& ObjectInitializer);

	/** Specify the distance to the camera which divide the background and foreground in MxR casting.
	 * Set it to CR_TrackingReference to use the distance to the Tracking Reference, which works better
	 * in the stationary experience. Set it to CR_Head would use the distance to the HMD, which works better
	 * in the room scale experience.
	 */
	UPROPERTY(Category = MetaXR, EditAnywhere, BlueprintReadWrite)
	EOculusXRMR_ClippingReference ClippingReference;

	/** The casting viewports would use the same resolution of the camera which used in the calibration process. */
	UPROPERTY(Category = MetaXR, EditAnywhere, BlueprintReadWrite)
	bool bUseTrackedCameraResolution;

	/** When bUseTrackedCameraResolution is false, the width of each casting viewport */
	UPROPERTY(Category = MetaXR, EditAnywhere, BlueprintReadWrite)
	int WidthPerView;

	/** When bUseTrackedCameraResolution is false, the height of each casting viewport */
	UPROPERTY(Category = MetaXR, EditAnywhere, BlueprintReadWrite)
	int HeightPerView;

	/** When CompositionMethod is External Composition, the latency of the casting output which could be adjusted to
	 * match the camera latency in the external composition application */
	UPROPERTY(Category = MetaXR, EditAnywhere, BlueprintReadWrite, meta = (UIMin = "0.0", UIMax = "0.1"))
	float CastingLatency;

	/** When CompositionMethod is External Composition, the color of the backdrop in the foreground view */
	UPROPERTY(Category = MetaXR, EditAnywhere, BlueprintReadWrite)
	FColor BackdropColor;

	/** When CompositionMethod is Direct Composition, you could adjust this latency to delay the virtual
	 * hand movement by a small amount of time to match the camera latency */
	UPROPERTY(meta = (DeprecatedProperty, DeprecationMessage = "Direct Composition deprecated."))
	float HandPoseStateLatency_DEPRECATED;

	/** [Green-screen removal] Chroma Key Color. Apply when CompositionMethod is DirectComposition */
	UPROPERTY(meta = (DeprecatedProperty, DeprecationMessage = "Direct Composition deprecated."))
	FColor ChromaKeyColor_DEPRECATED;

	/** [Green-screen removal] Chroma Key Similarity. Apply when CompositionMethod is DirectComposition */
	UPROPERTY(meta = (DeprecatedProperty, DeprecationMessage = "Direct Composition deprecated."))
	float ChromaKeySimilarity_DEPRECATED;

	/** [Green-screen removal] Chroma Key Smooth Range. Apply when CompositionMethod is DirectComposition */
	UPROPERTY(meta = (DeprecatedProperty, DeprecationMessage = "Direct Composition deprecated."))
	float ChromaKeySmoothRange_DEPRECATED;

	/** [Green-screen removal] Chroma Key Spill Range. Apply when CompositionMethod is DirectComposition */
	UPROPERTY(meta = (DeprecatedProperty, DeprecationMessage = "Direct Composition deprecated."))
	float ChromaKeySpillRange_DEPRECATED;

	/** Set the amount of post process effects in the MR view for external composition */
	UPROPERTY(Category = MetaXR, EditAnywhere, BlueprintReadWrite)
	EOculusXRMR_PostProcessEffects ExternalCompositionPostProcessEffects;

	/** ExternalComposition: The casting window includes the background and foreground view
	 * DirectComposition: The game scene would be composited with the camera frame directly
	 */
	UFUNCTION(BlueprintCallable, Category = MetaXR)
	EOculusXRMR_CompositionMethod GetCompositionMethod() { return CompositionMethod; }

	/** ExternalComposition: The casting window includes the background and foreground view
	 * DirectComposition: The game scene would be composited with the camera frame directly
	 */
	UFUNCTION(BlueprintCallable, Category = MetaXR)
	void SetCompositionMethod(EOculusXRMR_CompositionMethod val);

	/** When CompositionMethod is DirectComposition, the physical camera device which provide the frame */
	UFUNCTION(BlueprintCallable, Category = MetaXR, meta = (DeprecatedFunction, DeprecationMessage = "Direct Composition deprecated."))
	EOculusXRMR_CameraDeviceEnum GetCapturingCamera() { return EOculusXRMR_CameraDeviceEnum::CD_None_DEPRECATED; }

	/** When CompositionMethod is DirectComposition, the physical camera device which provide the frame */
	UFUNCTION(BlueprintCallable, Category = MetaXR, meta = (DeprecatedFunction, DeprecationMessage = "Direct Composition deprecated."))
	void SetCapturingCamera(EOculusXRMR_CameraDeviceEnum val);

	/** Is MRC on and off */
	UFUNCTION(BlueprintCallable, Category = MetaXR)
	bool GetIsCasting() { return bIsCasting; }

	/** Turns MRC on and off */
	UFUNCTION(BlueprintCallable, Category = MetaXR)
	void SetIsCasting(bool val);

	/** Bind the casting camera to the calibrated external camera.
	 * (Requires a calibrated external camera)
	 */
	UFUNCTION(BlueprintCallable, Category = MetaXR)
	void BindToTrackedCameraIndexIfAvailable(int InTrackedCameraIndex);

	UFUNCTION(BlueprintCallable, Category = MetaXR)
	int GetBindToTrackedCameraIndex() { return BindToTrackedCameraIndex; }

	/** Load settings from the config file */
	UFUNCTION(BlueprintCallable, Category = MetaXR)
	void LoadFromIni();

	/** Save settings to the config file */
	UFUNCTION(BlueprintCallable, Category = MetaXR)
	void SaveToIni() const;

private:
	/** Turns MRC on and off (does not get saved to or loaded from ini) */
	UPROPERTY()
	bool bIsCasting;

	/** ExternalComposition: The casting window includes the background and foreground view
	 * DirectComposition: The game scene would be composited with the camera frame directly
	 */
	UPROPERTY()
	EOculusXRMR_CompositionMethod CompositionMethod;

	/** When CompositionMethod is DirectComposition, the physical camera device which provide the frame */
	UPROPERTY(meta = (DeprecatedProperty, DeprecationMessage = "Direct Composition deprecated."))
	EOculusXRMR_CameraDeviceEnum CapturingCamera_DEPRECATED;

	/** Tracked camera that we want to bind the in-game MR camera to*/
	int BindToTrackedCameraIndex;

	DECLARE_DELEGATE_TwoParams(OnCompositionMethodChangeDelegate, EOculusXRMR_CompositionMethod, EOculusXRMR_CompositionMethod);
	DECLARE_DELEGATE_TwoParams(OnBooleanSettingChangeDelegate, bool, bool);
	DECLARE_DELEGATE_TwoParams(OnIntegerSettingChangeDelegate, int, int);

	OnIntegerSettingChangeDelegate TrackedCameraIndexChangeDelegate;
	OnCompositionMethodChangeDelegate CompositionMethodChangeDelegate;
	OnBooleanSettingChangeDelegate IsCastingChangeDelegate;

	// Give the OculusXRMR module access to the delegates so that
	friend class FOculusXRMRModule;
};
