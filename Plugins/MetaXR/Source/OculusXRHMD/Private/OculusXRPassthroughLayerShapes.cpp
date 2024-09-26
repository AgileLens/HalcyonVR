// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRPassthroughLayerShapes.h"

#include "OculusXRHMDPrivate.h"
#include "Curves/CurveLinearColor.h"
#include "OculusXRPluginWrapper.h"

const FName FReconstructedLayer::ShapeName = FName("ReconstructedLayer");
const FName FUserDefinedLayer::ShapeName = FName("UserDefinedLayer");

FColorLutDesc::FColorLutDesc()
	: Weight(0)
	, ColorLuts{}
{
}

FColorLutDesc::FColorLutDesc(const TArray<uint64>& InColorLuts, float InWeight)
	: Weight(InWeight)
	, ColorLuts(InColorLuts)
{
}

FEdgeStyleParameters::FEdgeStyleParameters()
	: bEnableEdgeColor(false)
	, bEnableColorMap(false)
	, bUseColorLuts(false)
	, TextureOpacityFactor(1.0f)
	, EdgeColor{}
	, ColorMapType{}
	, ColorMapData{}
	, ColorLutDesc{} {

	};

FEdgeStyleParameters::FEdgeStyleParameters(
	bool bEnableEdgeColor,
	bool bEnableColorMap,
	float TextureOpacityFactor,
	float Brightness,
	float Contrast,
	float Posterize,
	float Saturation,
	FLinearColor EdgeColor,
	FLinearColor ColorScale,
	FLinearColor ColorOffset,
	EOculusXRColorMapType InColorMapType,
	const TArray<FLinearColor>& InColorMapGradient,
	const FColorLutDesc& InLutDesc)
	: bEnableEdgeColor(bEnableEdgeColor)
	, bEnableColorMap(bEnableColorMap)
	, TextureOpacityFactor(TextureOpacityFactor)
	, Brightness(Brightness)
	, Contrast(Contrast)
	, Posterize(Posterize)
	, Saturation(Saturation)
	, EdgeColor(EdgeColor)
	, ColorScale(ColorScale)
	, ColorOffset(ColorOffset)
	, ColorMapType(InColorMapType)
	, ColorLutDesc(InLutDesc)
{
	bUseColorLuts = (InColorMapType == ColorMapType_ColorLut && InLutDesc.ColorLuts.Num() == 1)
		|| (InColorMapType == ColorMapType_ColorLut_Interpolated && InLutDesc.ColorLuts.Num() == 2);
	if ((InColorMapType == ColorMapType_ColorLut || InColorMapType == ColorMapType_ColorLut_Interpolated)
		&& !bUseColorLuts)
	{
		ColorMapType = ColorMapType_None;
	}
	ColorMapData = GenerateColorMapData(InColorMapType, InColorMapGradient);
};

TArray<uint8> FEdgeStyleParameters::GenerateColorMapData(EOculusXRColorMapType InColorMapType, const TArray<FLinearColor>& InColorMapGradient)
{
	switch (InColorMapType)
	{
		case ColorMapType_GrayscaleToColor:
		{
			TArray<uint8> NewColorMapData = GenerateMonoBrightnessContrastPosterizeMap();
			return GenerateMonoToRGBA(InColorMapGradient, NewColorMapData);
		}
		case ColorMapType_Grayscale:
			return GenerateMonoBrightnessContrastPosterizeMap();
		case ColorMapType_ColorAdjustment:
			return GenerateBrightnessContrastSaturationColorMap();
		default:
			return TArray<uint8>();
	}
}

TArray<uint8> FEdgeStyleParameters::GenerateMonoToRGBA(const TArray<FLinearColor>& InColorMapGradient, const TArray<uint8>& InColorMapData)
{
	TArray<uint8> NewColorMapData;
	FInterpCurveLinearColor InterpCurve;
	const uint32 TotalEntries = 256;

	for (int32 Index = 0; Index < InColorMapGradient.Num(); ++Index)
	{
		InterpCurve.AddPoint(Index, (InColorMapGradient[Index] * ColorScale) + ColorOffset);
	}

	NewColorMapData.SetNum(TotalEntries * sizeof(ovrpColorf));
	uint8* Dest = NewColorMapData.GetData();
	for (int32 Index = 0; Index < TotalEntries; ++Index)
	{
		const ovrpColorf Color = OculusXRHMD::ToOvrpColorf(InterpCurve.Eval(InColorMapData[Index]));
		FMemory::Memcpy(Dest, &Color, sizeof(Color));
		Dest += sizeof(ovrpColorf);
	}
	return NewColorMapData;
}

TArray<uint8> FEdgeStyleParameters::GenerateMonoBrightnessContrastPosterizeMap()
{
	TArray<uint8> NewColorMapData;
	const int32 TotalEntries = 256;
	NewColorMapData.SetNum(TotalEntries * sizeof(uint8));
	for (int32 Index = 0; Index < TotalEntries; ++Index)
	{
		float Alpha = ((float)Index / TotalEntries);
		float ContrastFactor = Contrast + 1.0;
		Alpha = (Alpha - 0.5) * ContrastFactor + 0.5 + Brightness;

		if (Posterize > 0.0f)
		{
			const float PosterizationBase = 50.0f;
			float FinalPosterize = (FMath::Pow(PosterizationBase, Posterize) - 1.0) / (PosterizationBase - 1.0);
			Alpha = FMath::RoundToFloat(Alpha / FinalPosterize) * FinalPosterize;
		}

		NewColorMapData[Index] = (uint8)(FMath::Min(FMath::Max(Alpha, 0.0f), 1.0f) * 255.0f);
	}
	return NewColorMapData;
}

TArray<uint8> FEdgeStyleParameters::GenerateBrightnessContrastSaturationColorMap()
{
	TArray<uint8> NewColorMapData;
	NewColorMapData.SetNum(3 * sizeof(float));
	float newB = Brightness * 100.0f;
	float newC = Contrast + 1.0f;
	float newS = Saturation + 1.0f;

	uint8* Dest = NewColorMapData.GetData();
	FMemory::Memcpy(Dest, &newB, sizeof(float));
	Dest += sizeof(float);
	FMemory::Memcpy(Dest, &newC, sizeof(float));
	Dest += sizeof(float);
	FMemory::Memcpy(Dest, &newS, sizeof(float));

	return NewColorMapData;
}
