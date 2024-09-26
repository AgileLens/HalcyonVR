// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "Misc/EngineVersionComparison.h"

#include "StereoLayerShapes.h"
#include "OculusXRPassthroughMesh.h"
#include "OculusXRPassthroughLayerShapes.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOculusXRPassthrough_LayerResumed);

UENUM()
enum EOculusXRColorMapType
{
	/** None*/
	ColorMapType_None = 0 UMETA(DisplayName = "None"),

	/** Grayscale to color */
	ColorMapType_GrayscaleToColor = 1 UMETA(DisplayName = "Grayscale To Color"),

	/** Grayscale */
	ColorMapType_Grayscale = 2 UMETA(DisplayName = "Grayscale"),

	/** Color Adjustment */
	ColorMapType_ColorAdjustment = 3 UMETA(DisplayName = "Color Adjustment"),

	/** Color LUT */
	ColorMapType_ColorLut = 4 UMETA(DisplayName = "Color LUT"),

	/** Interpolated Color LUT */
	ColorMapType_ColorLut_Interpolated = 5 UMETA(DisplayName = "Interpolated Color LUT"),

	ColorMapType_MAX = 255,
};

UENUM()
enum EOculusXRPassthroughLayerOrder
{
	/** Layer is rendered on top of scene */
	PassthroughLayerOrder_Overlay = 0 UMETA(DisplayName = "Overlay"),

	/** Layer is rendered under scene */
	PassthroughLayerOrder_Underlay = 1 UMETA(DisplayName = "Underlay"),

	PassthroughLayerOrder_MAX = 255,
};

struct OCULUSXRHMD_API FColorLutDesc
{
	FColorLutDesc();

	FColorLutDesc(const TArray<uint64>& InColorLuts, float InWeight);

	float Weight;
	TArray<uint64> ColorLuts;
};

struct OCULUSXRHMD_API FEdgeStyleParameters
{
public:
	FEdgeStyleParameters();

	FEdgeStyleParameters(
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
		const FColorLutDesc& InLutDesc);

	bool bEnableEdgeColor;
	bool bEnableColorMap;
	bool bUseColorLuts;
	float TextureOpacityFactor;
	float Brightness;
	float Contrast;
	float Posterize;
	float Saturation;
	FLinearColor EdgeColor;
	FLinearColor ColorScale;
	FLinearColor ColorOffset;
	EOculusXRColorMapType ColorMapType;
	TArray<uint8> ColorMapData;
	FColorLutDesc ColorLutDesc;

private:
	/** Generates the corresponding color map based on given color map type */
	TArray<uint8> GenerateColorMapData(EOculusXRColorMapType InColorMapType, const TArray<FLinearColor>& InColorMapGradient);

	/** Generates a grayscale to color color map based on given gradient --> It also applies the color scale and offset */
	TArray<uint8> GenerateMonoToRGBA(const TArray<FLinearColor>& InGradient, const TArray<uint8>& InColorMapData);

	/** Generates a grayscale color map with given Brightness/Contrast/Posterize settings */
	TArray<uint8> GenerateMonoBrightnessContrastPosterizeMap();

	/** Generates a luminance based colormap from the the Brightness/Contrast */
	TArray<uint8> GenerateBrightnessContrastSaturationColorMap();
};

#if UE_VERSION_OLDER_THAN(5, 3, 0)
#define OCULUSXRHMD_API_CLASS OCULUSXRHMD_API
#define OCULUSXRHMD_API_MEMBER
#else
#define OCULUSXRHMD_API_CLASS
#define OCULUSXRHMD_API_MEMBER OCULUSXRHMD_API
#endif

class OCULUSXRHMD_API_CLASS FReconstructedLayer : public IStereoLayerShape
{
public:
	OCULUSXRHMD_API_MEMBER static const FName ShapeName;
	virtual FName GetShapeName() override { return ShapeName; }
	virtual IStereoLayerShape* Clone() const override { return new FReconstructedLayer(*this); }

public:
	FReconstructedLayer(){};
	FReconstructedLayer(const FEdgeStyleParameters& EdgeStyleParameters, EOculusXRPassthroughLayerOrder PassthroughLayerOrder)
		: EdgeStyleParameters(EdgeStyleParameters), PassthroughLayerOrder(PassthroughLayerOrder){};
	FEdgeStyleParameters EdgeStyleParameters;
	EOculusXRPassthroughLayerOrder PassthroughLayerOrder;
};

struct FUserDefinedGeometryDesc
{
	FUserDefinedGeometryDesc(const FString& MeshName, OculusXRHMD::FOculusPassthroughMeshRef PassthroughMesh, const FTransform& Transform, bool bUpdateTransform)
		: MeshName(MeshName)
		, PassthroughMesh(PassthroughMesh)
		, Transform(Transform)
		, bUpdateTransform(bUpdateTransform){};

	FString MeshName;
	OculusXRHMD::FOculusPassthroughMeshRef PassthroughMesh;
	FTransform Transform;
	bool bUpdateTransform;
};

class OCULUSXRHMD_API_CLASS FUserDefinedLayer : public IStereoLayerShape
{
public:
	OCULUSXRHMD_API_MEMBER static const FName ShapeName;
	virtual FName GetShapeName() override { return ShapeName; }
	virtual IStereoLayerShape* Clone() const override { return new FUserDefinedLayer(*this); }

public:
	FUserDefinedLayer(){};
	FUserDefinedLayer(TArray<FUserDefinedGeometryDesc> InUserGeometryList, const FEdgeStyleParameters& EdgeStyleParameters, EOculusXRPassthroughLayerOrder PassthroughLayerOrder)
		: UserGeometryList{}
		, EdgeStyleParameters(EdgeStyleParameters)
		, PassthroughLayerOrder(PassthroughLayerOrder)
	{
		UserGeometryList = InUserGeometryList;
	}

	TArray<FUserDefinedGeometryDesc> UserGeometryList;
	FEdgeStyleParameters EdgeStyleParameters;
	EOculusXRPassthroughLayerOrder PassthroughLayerOrder;

private:
};
