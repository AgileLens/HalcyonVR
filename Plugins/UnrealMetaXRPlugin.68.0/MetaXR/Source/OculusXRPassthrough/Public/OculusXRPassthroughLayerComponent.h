// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.
// OculusEventComponent.h: Component to handle receiving events from Oculus HMDs

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "UObject/ObjectMacros.h"
#include "Components/StereoLayerComponent.h"
#include "OculusXRPassthroughLayerShapes.h"
#include "OculusXRPassthroughColorLut.h"
#include "OculusXRHMDRuntimeSettings.h"
#include "OculusXRPassthroughLayerComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogOculusPassthrough, Log, All);

UCLASS(Abstract, meta = (DisplayName = "Passthrough Layer Base"))
class OCULUSXRPASSTHROUGH_API UOculusXRPassthroughLayerBase : public UStereoLayerShape
{
	GENERATED_BODY()
public:
	/** Ordering of passthrough layer in relation to scene rendering */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties", DisplayName = "Layer Placement")
	TEnumAsByte<enum EOculusXRPassthroughLayerOrder> LayerOrder;

	/** Opacity of the (main) passthrough texture.  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties", meta = (UIMin = 0.0, UIMax = 1.0, ClampMin = 0.0, ClampMax = 1.0))
	float TextureOpacityFactor = 1.0f;

	/** Enable edge color */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties", meta = (DisplayName = "Enable Edge Rendering"))
	bool bEnableEdgeColor = false;

	/** Color of the passthrough edge rendering effect. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties", meta = (EditCondition = "bEnableEdgeColor", EditConditionHides))
	FLinearColor EdgeColor;

	/** Enable color mapping */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties")
	bool bEnableColorMap = false;

	/** Type of colormapping to perform */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties", meta = (EditCondition = "bEnableColorMap", EditConditionHides))
	TEnumAsByte<enum EOculusXRColorMapType> ColorMapType;

	/** Whether to use color map curve or gradient*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties", meta = (EditCondition = "bEnableColorMap && ColorMapType == 1", EditConditionHides))
	bool bUseColorMapCurve = false;

	/** Passthrough color mapping gradient converts grayscale to color*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties", meta = (EditCondition = "bEnableColorMap && bUseColorMapCurve && ColorMapType == 1", EditConditionHides))
	UCurveLinearColor* ColorMapCurve;

	/** Contrast setting for color mapping*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties", meta = (ClampMin = "-1", ClampMax = "1", EditCondition = "bEnableColorMap && ColorMapType > 0 && ColorMapType < 4", EditConditionHides))
	float Contrast = 0.0f;

	/** Brightness setting for color mapping*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties", meta = (ClampMin = "-1", ClampMax = "1", EditCondition = "bEnableColorMap && ColorMapType > 0 && ColorMapType < 4", EditConditionHides))
	float Brightness = 0.0f;

	/** Posterize setting for grayscale and grayscale to color mapping*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties", meta = (ClampMin = "0", ClampMax = "1", EditCondition = "bEnableColorMap && ColorMapType > 0 && ColorMapType < 3", EditConditionHides))
	float Posterize = 0.0f;

	/** Saturation setting for color adjustment mapping*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties", meta = (ClampMin = "-1", ClampMax = "1", EditCondition = "bEnableColorMap && ColorMapType == 3", EditConditionHides))
	float Saturation = 0.0f;

	/** Color LUT Weight. It is used to combine LUT with Passthrough if one LUT is provided. If two LUTs are provided LutWeight will be used to blend them. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties", meta = (ClampMin = "0", ClampMax = "1", EditCondition = "bEnableColorMap && ColorMapType > 3", EditConditionHides))
	float LutWeight = 1.0f;

	/**
	 *  Color LUT properties. If only ColorLUTSource is provided it will be blended with passthrough layer using following formula:
	 *  Result = ColorLUTSource * LutWeight + Passthrough * (1 - LutWeight )
	 */
	UPROPERTY(EditAnywhere, Category = "Passthrough Properties", meta = (EditCondition = "bEnableColorMap && ColorMapType > 3", EditConditionHides))
	UOculusXRPassthroughColorLut* ColorLUTSource;

	/**
	 *  Color LUT properties. If two LUTs are provided they will be blended using following formula:
	 *  Result = ColorLUTsSource * (  1 - LutWeight ) + ColorLUTsTarget * LutWeight
	 */
	UPROPERTY(EditAnywhere, Category = "Passthrough Properties", meta = (EditCondition = "bEnableColorMap && ColorMapType > 4", EditConditionHides))
	UOculusXRPassthroughColorLut* ColorLUTTarget;

	/** Color value that will be multiplied to the current color map*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties", meta = (EditCondition = "bEnableColorMap", EditConditionHides))
	FLinearColor ColorScale = FLinearColor::White;

	/** Color value that will be added to the current color map*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Passthrough Properties", meta = (EditCondition = "bEnableColorMap", EditConditionHides))
	FLinearColor ColorOffset = FLinearColor::Black;

	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void SetTextureOpacity(float InOpacity);

	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void EnableEdgeColor(bool bInEnableEdgeColor);

	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void EnableColorMap(bool bInEnableColorMap);

	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void EnableColorMapCurve(bool bInEnableColorMapCurve);

	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void SetEdgeRenderingColor(FLinearColor InEdgeColor);

	/** Set color map controls for grayscale and grayscale to rgb color mapping*/
	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void SetColorMapControls(float InContrast = 0, float InBrightness = 0, float InPosterize = 0);

	/** Set color map controls for color adjustment color mapping */
	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void SetBrightnessContrastSaturation(float InContrast = 0, float InBrightness = 0, float InSaturation = 0);

	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void SetColorScaleAndOffset(FLinearColor InColorScale = FLinearColor::White, FLinearColor InColorOffset = FLinearColor::Black);

	/** Set color curve that will be added to the color map in grayscale modes --> will be converted into a gradient*/
	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void SetColorMapCurve(UCurveLinearColor* InColorMapCurve);

	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void SetColorMapType(EOculusXRColorMapType InColorMapType);

	/** Set color map array directly instead through a color curve*/
	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void SetColorArray(const TArray<FLinearColor>& InColorArray);

	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void ClearColorMap();

	UFUNCTION(BlueprintCallable, Category = "Passthrough Properties")
	void SetLayerPlacement(EOculusXRPassthroughLayerOrder InLayerOrder);

	/**
	 * Sets Color LUT source.
	 * If ColorMapType is "Color LUT", then source will be blended with passthrough
	 * using folowing formula:
	 * Result = ColorLUTSource * LutWeight + Passthrough * (1 - LutWeight )
	 * If ColorMapType is "Interpolated Color LUT", then source will be blended with color LUT target
	 * using folowing formula:
	 * Result = ColorLUTSource * (  1 - LutWeight ) + ColorLUTTarget * LutWeight
	 */
	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void SetColorLUTSource(class UOculusXRPassthroughColorLut* InColorLUTSource);

	/**
	 * Sets Color LUT target.
	 * If ColorMapType is "Interpolated Color LUT", then target will be blended with passthrough
	 * using folowing formula:
	 * Result = ColorLUTSource * (  1 - LutWeight ) + ColorLUTTarget * LutWeight
	 * Note: If ColorLUTSource is not specified, Color LUT will be not be applied to the Passthrough layer.
	 */
	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void SetColorLUTTarget(class UOculusXRPassthroughColorLut* InColorLUTTarget);

	/** Sets LUT weight. */
	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void SetColorLUTWeight(float InWeight = 1.0f);

	/** Removes color grading if any is active. */
	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void RemoveColorLut();

	void ClearLUTsReferences();

	virtual void BeginDestroy();

protected:
	TArray<FLinearColor> ColorArray;
	TArray<FLinearColor> NeutralColorArray;
	TArray<FLinearColor> GenerateColorArrayFromColorCurve(const UCurveLinearColor* InColorMapCurve) const;
	TArray<FLinearColor> GetOrGenerateNeutralColorArray();
	TArray<FLinearColor> GenerateColorArray(bool bInUseColorMapCurve, const UCurveLinearColor* InColorMapCurve);
	TArray<FLinearColor> GetColorArray(bool bInUseColorMapCurve, const UCurveLinearColor* InColorMapCurve);
	FColorLutDesc GenerateColorLutDescription(float InLutWeight, UOculusXRPassthroughColorLut* InLutSource, UOculusXRPassthroughColorLut* InLutTarget);

	void MarkStereoLayerDirty();
};

/* Reconstructed Passthrough Layer*/
UCLASS(meta = (DisplayName = "Reconstructed Passthrough Layer"))
class OCULUSXRPASSTHROUGH_API UOculusXRStereoLayerShapeReconstructed : public UOculusXRPassthroughLayerBase
{
	GENERATED_BODY()
public:
	virtual void ApplyShape(IStereoLayers::FLayerDesc& LayerDesc) override;
};

/* User Defined Passthrough Layer*/
UCLASS(meta = (DisplayName = "User Defined Passthrough Layer"))
class OCULUSXRPASSTHROUGH_API UOculusXRStereoLayerShapeUserDefined : public UOculusXRPassthroughLayerBase
{
	GENERATED_BODY()
public:
	void AddGeometry(const FString& MeshName, OculusXRHMD::FOculusPassthroughMeshRef PassthroughMesh, FTransform Transform, bool bUpdateTransform);
	void RemoveGeometry(const FString& MeshName);

	virtual void ApplyShape(IStereoLayers::FLayerDesc& LayerDesc) override;
	TArray<FUserDefinedGeometryDesc>& GetUserGeometryList() { return UserGeometryList; };

private:
	TArray<FUserDefinedGeometryDesc> UserGeometryList;
};

class UProceduralMeshComponent;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent), ClassGroup = OculusXRHMD)
class OCULUSXRPASSTHROUGH_API UOculusXRPassthroughLayerComponent : public UStereoLayerComponent
{
	GENERATED_UCLASS_BODY()

public:
	void DestroyComponent(bool bPromoteChildren) override;
	void OnRegister() override;

	void BeginPlay() override;
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void UpdatePassthroughObjects();

	UFUNCTION(BlueprintCallable, Category = "Passthrough", meta = (DeprecatedFunction, DeprecationMessage = "Please use AddStaticSurfaceGeometry instead"))
	void AddSurfaceGeometry(AStaticMeshActor* StaticMeshActor, bool updateTransform);
	UFUNCTION(BlueprintCallable, Category = "Passthrough")
	void AddStaticSurfaceGeometry(UStaticMeshComponent* StaticMeshComponent, bool updateTransform);
	UFUNCTION(BlueprintCallable, Category = "Passthrough")
	void AddProceduralSurfaceGeometry(UProceduralMeshComponent* ProceduralMeshComponent, bool updateTransform);

	UFUNCTION(BlueprintCallable, Category = "Passthrough", meta = (DeprecatedFunction, DeprecationMessage = "Please use RemoveStaticSurfaceGeometry instead"))
	void RemoveSurfaceGeometry(AStaticMeshActor* StaticMeshActor);
	UFUNCTION(BlueprintCallable, Category = "Passthrough")
	void RemoveStaticSurfaceGeometry(UStaticMeshComponent* StaticMeshComponent);
	UFUNCTION(BlueprintCallable, Category = "Passthrough")
	void RemoveProceduralSurfaceGeometry(UProceduralMeshComponent* ProceduralMeshComponent);

	UFUNCTION(BlueprintCallable, Category = "Passthrough", meta = (DeprecatedFunction, DeprecationMessage = "Please use IsSurfaceGeometryComponent instead"))
	bool IsSurfaceGeometry(AStaticMeshActor* StaticMeshActor) const;
	UFUNCTION(BlueprintPure, Category = "Passthrough")
	bool IsSurfaceGeometryComponent(const UMeshComponent* MeshComponent) const;

	// Manually mark the stereo layer passthrough effect for updating
	UFUNCTION(BlueprintCallable, Category = "Components|Stereo Layer")
	void MarkPassthroughStyleForUpdate();

#if WITH_EDITOR
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif // WITH_EDITOR

	UFUNCTION()
	void OnAnyLayerResumedEvent(int InLayerId);

	UPROPERTY(BlueprintAssignable)
	FOculusXRPassthrough_LayerResumed OnLayerResumed;

protected:
	virtual bool LayerRequiresTexture();
	virtual void RemoveSurfaceGeometryComponent(UMeshComponent* MeshComponent);

	UPROPERTY(Transient)
	TMap<FString, const UMeshComponent*> PassthroughComponentMap;

private:
	OculusXRHMD::FOculusPassthroughMeshRef CreatePassthroughMesh(UProceduralMeshComponent* ProceduralMeshComponent);
	OculusXRHMD::FOculusPassthroughMeshRef CreatePassthroughMesh(UStaticMeshComponent* StaticMeshComponent);

	/** Passthrough style needs to be marked for update **/
	bool bPassthroughStyleNeedsUpdate;
};
