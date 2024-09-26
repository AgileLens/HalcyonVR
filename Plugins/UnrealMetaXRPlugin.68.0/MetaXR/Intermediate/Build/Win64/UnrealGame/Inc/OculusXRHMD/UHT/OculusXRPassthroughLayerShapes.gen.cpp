// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRHMD/Public/OculusXRPassthroughLayerShapes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRPassthroughLayerShapes() {}

// Begin Cross Module References
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRColorMapType();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRPassthroughLayerOrder();
OCULUSXRHMD_API UFunction* Z_Construct_UDelegateFunction_OculusXRHMD_OculusXRPassthrough_LayerResumed__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_OculusXRHMD();
// End Cross Module References

// Begin Delegate FOculusXRPassthrough_LayerResumed
struct Z_Construct_UDelegateFunction_OculusXRHMD_OculusXRPassthrough_LayerResumed__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OculusXRPassthroughLayerShapes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OculusXRHMD_OculusXRPassthrough_LayerResumed__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD, nullptr, "OculusXRPassthrough_LayerResumed__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OculusXRHMD_OculusXRPassthrough_LayerResumed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OculusXRHMD_OculusXRPassthrough_LayerResumed__DelegateSignature_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UDelegateFunction_OculusXRHMD_OculusXRPassthrough_LayerResumed__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OculusXRHMD_OculusXRPassthrough_LayerResumed__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOculusXRPassthrough_LayerResumed_DelegateWrapper(const FMulticastScriptDelegate& OculusXRPassthrough_LayerResumed)
{
	OculusXRPassthrough_LayerResumed.ProcessMulticastDelegate<UObject>(NULL);
}
// End Delegate FOculusXRPassthrough_LayerResumed

// Begin Enum EOculusXRColorMapType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRColorMapType;
static UEnum* EOculusXRColorMapType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRColorMapType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRColorMapType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRColorMapType, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRColorMapType"));
	}
	return Z_Registration_Info_UEnum_EOculusXRColorMapType.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRColorMapType>()
{
	return EOculusXRColorMapType_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRColorMapType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ColorMapType_ColorAdjustment.Comment", "/** Color Adjustment */" },
		{ "ColorMapType_ColorAdjustment.DisplayName", "Color Adjustment" },
		{ "ColorMapType_ColorAdjustment.Name", "ColorMapType_ColorAdjustment" },
		{ "ColorMapType_ColorAdjustment.ToolTip", "Color Adjustment" },
		{ "ColorMapType_ColorLut.Comment", "/** Color LUT */" },
		{ "ColorMapType_ColorLut.DisplayName", "Color LUT" },
		{ "ColorMapType_ColorLut.Name", "ColorMapType_ColorLut" },
		{ "ColorMapType_ColorLut.ToolTip", "Color LUT" },
		{ "ColorMapType_ColorLut_Interpolated.Comment", "/** Interpolated Color LUT */" },
		{ "ColorMapType_ColorLut_Interpolated.DisplayName", "Interpolated Color LUT" },
		{ "ColorMapType_ColorLut_Interpolated.Name", "ColorMapType_ColorLut_Interpolated" },
		{ "ColorMapType_ColorLut_Interpolated.ToolTip", "Interpolated Color LUT" },
		{ "ColorMapType_Grayscale.Comment", "/** Grayscale */" },
		{ "ColorMapType_Grayscale.DisplayName", "Grayscale" },
		{ "ColorMapType_Grayscale.Name", "ColorMapType_Grayscale" },
		{ "ColorMapType_Grayscale.ToolTip", "Grayscale" },
		{ "ColorMapType_GrayscaleToColor.Comment", "/** Grayscale to color */" },
		{ "ColorMapType_GrayscaleToColor.DisplayName", "Grayscale To Color" },
		{ "ColorMapType_GrayscaleToColor.Name", "ColorMapType_GrayscaleToColor" },
		{ "ColorMapType_GrayscaleToColor.ToolTip", "Grayscale to color" },
		{ "ColorMapType_MAX.Name", "ColorMapType_MAX" },
		{ "ColorMapType_None.Comment", "/** None*/" },
		{ "ColorMapType_None.DisplayName", "None" },
		{ "ColorMapType_None.Name", "ColorMapType_None" },
		{ "ColorMapType_None.ToolTip", "None" },
		{ "ModuleRelativePath", "Public/OculusXRPassthroughLayerShapes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ColorMapType_None", (int64)ColorMapType_None },
		{ "ColorMapType_GrayscaleToColor", (int64)ColorMapType_GrayscaleToColor },
		{ "ColorMapType_Grayscale", (int64)ColorMapType_Grayscale },
		{ "ColorMapType_ColorAdjustment", (int64)ColorMapType_ColorAdjustment },
		{ "ColorMapType_ColorLut", (int64)ColorMapType_ColorLut },
		{ "ColorMapType_ColorLut_Interpolated", (int64)ColorMapType_ColorLut_Interpolated },
		{ "ColorMapType_MAX", (int64)ColorMapType_MAX },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRColorMapType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRColorMapType",
	"EOculusXRColorMapType",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRColorMapType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRColorMapType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::Regular,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRColorMapType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRColorMapType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRColorMapType()
{
	if (!Z_Registration_Info_UEnum_EOculusXRColorMapType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRColorMapType.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRColorMapType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRColorMapType.InnerSingleton;
}
// End Enum EOculusXRColorMapType

// Begin Enum EOculusXRPassthroughLayerOrder
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRPassthroughLayerOrder;
static UEnum* EOculusXRPassthroughLayerOrder_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRPassthroughLayerOrder.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRPassthroughLayerOrder.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRPassthroughLayerOrder, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRPassthroughLayerOrder"));
	}
	return Z_Registration_Info_UEnum_EOculusXRPassthroughLayerOrder.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRPassthroughLayerOrder>()
{
	return EOculusXRPassthroughLayerOrder_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRPassthroughLayerOrder_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OculusXRPassthroughLayerShapes.h" },
		{ "PassthroughLayerOrder_MAX.Name", "PassthroughLayerOrder_MAX" },
		{ "PassthroughLayerOrder_Overlay.Comment", "/** Layer is rendered on top of scene */" },
		{ "PassthroughLayerOrder_Overlay.DisplayName", "Overlay" },
		{ "PassthroughLayerOrder_Overlay.Name", "PassthroughLayerOrder_Overlay" },
		{ "PassthroughLayerOrder_Overlay.ToolTip", "Layer is rendered on top of scene" },
		{ "PassthroughLayerOrder_Underlay.Comment", "/** Layer is rendered under scene */" },
		{ "PassthroughLayerOrder_Underlay.DisplayName", "Underlay" },
		{ "PassthroughLayerOrder_Underlay.Name", "PassthroughLayerOrder_Underlay" },
		{ "PassthroughLayerOrder_Underlay.ToolTip", "Layer is rendered under scene" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "PassthroughLayerOrder_Overlay", (int64)PassthroughLayerOrder_Overlay },
		{ "PassthroughLayerOrder_Underlay", (int64)PassthroughLayerOrder_Underlay },
		{ "PassthroughLayerOrder_MAX", (int64)PassthroughLayerOrder_MAX },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRPassthroughLayerOrder_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRPassthroughLayerOrder",
	"EOculusXRPassthroughLayerOrder",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRPassthroughLayerOrder_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRPassthroughLayerOrder_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::Regular,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRPassthroughLayerOrder_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRPassthroughLayerOrder_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRPassthroughLayerOrder()
{
	if (!Z_Registration_Info_UEnum_EOculusXRPassthroughLayerOrder.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRPassthroughLayerOrder.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRPassthroughLayerOrder_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRPassthroughLayerOrder.InnerSingleton;
}
// End Enum EOculusXRPassthroughLayerOrder

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXRPassthroughLayerShapes_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOculusXRColorMapType_StaticEnum, TEXT("EOculusXRColorMapType"), &Z_Registration_Info_UEnum_EOculusXRColorMapType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2255796882U) },
		{ EOculusXRPassthroughLayerOrder_StaticEnum, TEXT("EOculusXRPassthroughLayerOrder"), &Z_Registration_Info_UEnum_EOculusXRPassthroughLayerOrder, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 377958872U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXRPassthroughLayerShapes_h_2280785614(TEXT("/Script/OculusXRHMD"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXRPassthroughLayerShapes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXRPassthroughLayerShapes_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
