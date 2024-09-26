// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"

#include "Curves/CurveLinearColor.h"
#include "OculusXRPassthroughLayerShapes.h"
#include "StereoLayerComponent.h"
#include "StereoRendering.h"
#include "UObject/NoExportTypes.h"

#include "OculusXRPersistentPassthroughInstance.generated.h"

DECLARE_DYNAMIC_DELEGATE(FOculusXRPassthrough_LayerResumed_Single);

class UOculusXRStereoLayerShapeReconstructed;
class UOculusXRPassthroughColorLut;

USTRUCT(BlueprintType, meta = (DisableSplitPin, HasNativeMake = "", HasNativeBreak = ""))
struct OCULUSXRPASSTHROUGH_API FOculusXRPersistentPassthroughParameters
{
	GENERATED_BODY()
public:
	UPROPERTY(Category = "Passthrough|Persistent", EditAnywhere, BlueprintReadWrite)
	bool bVisible;

	UPROPERTY(Category = "Passthrough|Persistent", EditAnywhere, BlueprintReadWrite)
	int32 Priority;

	UPROPERTY(Category = "Passthrough|Persistent", EditAnywhere, BlueprintReadOnly, NoClear, Instanced)
	TObjectPtr<UOculusXRStereoLayerShapeReconstructed> Shape;

	FOculusXRPersistentPassthroughParameters()
	{
		bVisible = true;
		Priority = 0;

		TempShape_LayerOrder = EOculusXRPassthroughLayerOrder::PassthroughLayerOrder_Overlay;
		TempShape_TextureOpacityFactor = 0.f;
		TempShape_bEnableEdgeColor = false;
		TempShape_EdgeColor = FLinearColor::Black;
		TempShape_bEnableColorMap = false;
		TempShape_ColorMapType = EOculusXRColorMapType::ColorMapType_None;
		TempShape_bUseColorMapCurve = false;
		TempShape_ColorMapCurve = nullptr;
		TempShape_Contrast = 0.f;
		TempShape_Brightness = 0.f;
		TempShape_Posterize = 0.f;
		TempShape_Saturation = 0.f;
		TempShape_LutWeight = 0.f;
		TempShape_ColorLUTSource = nullptr;
		TempShape_ColorLUTTarget = nullptr;
		TempShape_ColorScale = FLinearColor::Black;
		TempShape_ColorOffset = FLinearColor::Black;
	}

	void ApplyShape();
	UOculusXRStereoLayerShapeReconstructed* LoadShape(UObject* Owner);

private:
	// These properties are all the ones from UOculusXRStereoLayerShapeReconstructed.
	UPROPERTY()
	TEnumAsByte<EOculusXRPassthroughLayerOrder> TempShape_LayerOrder;
	UPROPERTY()
	float TempShape_TextureOpacityFactor;
	UPROPERTY()
	bool TempShape_bEnableEdgeColor;
	UPROPERTY()
	FLinearColor TempShape_EdgeColor;
	UPROPERTY()
	bool TempShape_bEnableColorMap;
	UPROPERTY()
	TEnumAsByte<EOculusXRColorMapType> TempShape_ColorMapType;
	UPROPERTY()
	bool TempShape_bUseColorMapCurve;
	UPROPERTY()
	UCurveLinearColor* TempShape_ColorMapCurve;
	UPROPERTY()
	float TempShape_Contrast;
	UPROPERTY()
	float TempShape_Brightness;
	UPROPERTY()
	float TempShape_Posterize;
	UPROPERTY()
	float TempShape_Saturation;
	UPROPERTY()
	float TempShape_LutWeight;
	UPROPERTY()
	UOculusXRPassthroughColorLut* TempShape_ColorLUTSource;
	UPROPERTY()
	UOculusXRPassthroughColorLut* TempShape_ColorLUTTarget;
	UPROPERTY()
	FLinearColor TempShape_ColorScale;
	UPROPERTY()
	FLinearColor TempShape_ColorOffset;
};

UCLASS(EditInlineNew, DefaultToInstanced, BlueprintType)
class OCULUSXRPASSTHROUGH_API UOculusXRPersistentPassthroughInstance : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FOculusXRPersistentPassthroughParameters Parameters;

public:
	UFUNCTION(Category = "Passthrough|Persistent", BlueprintCallable)
	void SetVisible(bool InVisible);
	UFUNCTION(Category = "Passthrough|Persistent", BlueprintPure)
	bool IsVisible() const { return Parameters.bVisible; }

	UFUNCTION(Category = "Passthrough|Persistent", BlueprintCallable)
	void SetPriority(int32 InPriority);
	UFUNCTION(Category = "Passthrough|Persistent", BlueprintPure)
	int32 GetPriority() const { return Parameters.Priority; }

	UFUNCTION(Category = "Passthrough|Persistent", BlueprintPure)
	UOculusXRStereoLayerShapeReconstructed* GetShape() const { return Parameters.Shape; }

	UOculusXRPersistentPassthroughInstance(const FObjectInitializer& ObjectInitializer);

	virtual void InitLayer(FOculusXRPersistentPassthroughParameters InParameters);
	virtual void UpdateParameters(FOculusXRPersistentPassthroughParameters InParameters);
	virtual void UpdateLayer();
	virtual void BeginDestroy() override;

	void AddLayerResumedSingleDelegate(const FOculusXRPassthrough_LayerResumed_Single& Delegate);

	UFUNCTION()
	void OnAnyLayerResumedEvent(int InLayerId);

	UPROPERTY(BlueprintAssignable)
	FOculusXRPassthrough_LayerResumed OnLayerResumed;

protected:
	TArray<FOculusXRPassthrough_LayerResumed_Single> LayerResumedSingleDelegates;
	uint32 LayerId = IStereoLayers::FLayerDesc::INVALID_LAYER_ID;
};
