// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRPassthrough/Public/OculusXRPersistentPassthroughInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRPersistentPassthroughInstance() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UClass* Z_Construct_UClass_UCurveLinearColor_NoRegister();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRColorMapType();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRPassthroughLayerOrder();
OCULUSXRHMD_API UFunction* Z_Construct_UDelegateFunction_OculusXRHMD_OculusXRPassthrough_LayerResumed__DelegateSignature();
OCULUSXRPASSTHROUGH_API UClass* Z_Construct_UClass_UOculusXRPassthroughColorLut_NoRegister();
OCULUSXRPASSTHROUGH_API UClass* Z_Construct_UClass_UOculusXRPersistentPassthroughInstance();
OCULUSXRPASSTHROUGH_API UClass* Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_NoRegister();
OCULUSXRPASSTHROUGH_API UClass* Z_Construct_UClass_UOculusXRStereoLayerShapeReconstructed_NoRegister();
OCULUSXRPASSTHROUGH_API UFunction* Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_LayerResumed_Single__DelegateSignature();
OCULUSXRPASSTHROUGH_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters();
UPackage* Z_Construct_UPackage__Script_OculusXRPassthrough();
// End Cross Module References

// Begin Delegate FOculusXRPassthrough_LayerResumed_Single
struct Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_LayerResumed_Single__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_LayerResumed_Single__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OculusXRPassthrough, nullptr, "OculusXRPassthrough_LayerResumed_Single__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_LayerResumed_Single__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_LayerResumed_Single__DelegateSignature_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_LayerResumed_Single__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_LayerResumed_Single__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOculusXRPassthrough_LayerResumed_Single_DelegateWrapper(const FScriptDelegate& OculusXRPassthrough_LayerResumed_Single)
{
	OculusXRPassthrough_LayerResumed_Single.ProcessDelegate<UObject>(NULL);
}
// End Delegate FOculusXRPassthrough_LayerResumed_Single

// Begin ScriptStruct FOculusXRPersistentPassthroughParameters
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OculusXRPersistentPassthroughParameters;
class UScriptStruct* FOculusXRPersistentPassthroughParameters::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRPersistentPassthroughParameters.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OculusXRPersistentPassthroughParameters.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters, (UObject*)Z_Construct_UPackage__Script_OculusXRPassthrough(), TEXT("OculusXRPersistentPassthroughParameters"));
	}
	return Z_Registration_Info_UScriptStruct_OculusXRPersistentPassthroughParameters.OuterSingleton;
}
template<> OCULUSXRPASSTHROUGH_API UScriptStruct* StaticStruct<FOculusXRPersistentPassthroughParameters>()
{
	return FOculusXRPersistentPassthroughParameters::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisableSplitPin", "" },
		{ "HasNativeBreak", "" },
		{ "HasNativeMake", "" },
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bVisible_MetaData[] = {
		{ "Category", "Passthrough|Persistent" },
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Priority_MetaData[] = {
		{ "Category", "Passthrough|Persistent" },
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Shape_MetaData[] = {
		{ "Category", "Passthrough|Persistent" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_LayerOrder_MetaData[] = {
		{ "Comment", "// These properties are all the ones from UOculusXRStereoLayerShapeReconstructed.\n" },
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
		{ "ToolTip", "These properties are all the ones from UOculusXRStereoLayerShapeReconstructed." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_TextureOpacityFactor_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_bEnableEdgeColor_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_EdgeColor_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_bEnableColorMap_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_ColorMapType_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_bUseColorMapCurve_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_ColorMapCurve_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_Contrast_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_Brightness_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_Posterize_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_Saturation_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_LutWeight_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_ColorLUTSource_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_ColorLUTTarget_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_ColorScale_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempShape_ColorOffset_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bVisible;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Priority;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Shape;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TempShape_LayerOrder;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TempShape_TextureOpacityFactor;
	static void NewProp_TempShape_bEnableEdgeColor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_TempShape_bEnableEdgeColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TempShape_EdgeColor;
	static void NewProp_TempShape_bEnableColorMap_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_TempShape_bEnableColorMap;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TempShape_ColorMapType;
	static void NewProp_TempShape_bUseColorMapCurve_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_TempShape_bUseColorMapCurve;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TempShape_ColorMapCurve;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TempShape_Contrast;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TempShape_Brightness;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TempShape_Posterize;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TempShape_Saturation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TempShape_LutWeight;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TempShape_ColorLUTSource;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TempShape_ColorLUTTarget;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TempShape_ColorScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TempShape_ColorOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOculusXRPersistentPassthroughParameters>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_bVisible_SetBit(void* Obj)
{
	((FOculusXRPersistentPassthroughParameters*)Obj)->bVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_bVisible = { "bVisible", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOculusXRPersistentPassthroughParameters), &Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_bVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bVisible_MetaData), NewProp_bVisible_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_Priority = { "Priority", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, Priority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Priority_MetaData), NewProp_Priority_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_Shape = { "Shape", nullptr, (EPropertyFlags)0x011600000208001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, Shape), Z_Construct_UClass_UOculusXRStereoLayerShapeReconstructed_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Shape_MetaData), NewProp_Shape_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_LayerOrder = { "TempShape_LayerOrder", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, TempShape_LayerOrder), Z_Construct_UEnum_OculusXRHMD_EOculusXRPassthroughLayerOrder, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_LayerOrder_MetaData), NewProp_TempShape_LayerOrder_MetaData) }; // 377958872
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_TextureOpacityFactor = { "TempShape_TextureOpacityFactor", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, TempShape_TextureOpacityFactor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_TextureOpacityFactor_MetaData), NewProp_TempShape_TextureOpacityFactor_MetaData) };
void Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_bEnableEdgeColor_SetBit(void* Obj)
{
	((FOculusXRPersistentPassthroughParameters*)Obj)->TempShape_bEnableEdgeColor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_bEnableEdgeColor = { "TempShape_bEnableEdgeColor", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOculusXRPersistentPassthroughParameters), &Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_bEnableEdgeColor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_bEnableEdgeColor_MetaData), NewProp_TempShape_bEnableEdgeColor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_EdgeColor = { "TempShape_EdgeColor", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, TempShape_EdgeColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_EdgeColor_MetaData), NewProp_TempShape_EdgeColor_MetaData) };
void Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_bEnableColorMap_SetBit(void* Obj)
{
	((FOculusXRPersistentPassthroughParameters*)Obj)->TempShape_bEnableColorMap = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_bEnableColorMap = { "TempShape_bEnableColorMap", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOculusXRPersistentPassthroughParameters), &Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_bEnableColorMap_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_bEnableColorMap_MetaData), NewProp_TempShape_bEnableColorMap_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_ColorMapType = { "TempShape_ColorMapType", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, TempShape_ColorMapType), Z_Construct_UEnum_OculusXRHMD_EOculusXRColorMapType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_ColorMapType_MetaData), NewProp_TempShape_ColorMapType_MetaData) }; // 2255796882
void Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_bUseColorMapCurve_SetBit(void* Obj)
{
	((FOculusXRPersistentPassthroughParameters*)Obj)->TempShape_bUseColorMapCurve = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_bUseColorMapCurve = { "TempShape_bUseColorMapCurve", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOculusXRPersistentPassthroughParameters), &Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_bUseColorMapCurve_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_bUseColorMapCurve_MetaData), NewProp_TempShape_bUseColorMapCurve_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_ColorMapCurve = { "TempShape_ColorMapCurve", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, TempShape_ColorMapCurve), Z_Construct_UClass_UCurveLinearColor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_ColorMapCurve_MetaData), NewProp_TempShape_ColorMapCurve_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_Contrast = { "TempShape_Contrast", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, TempShape_Contrast), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_Contrast_MetaData), NewProp_TempShape_Contrast_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_Brightness = { "TempShape_Brightness", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, TempShape_Brightness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_Brightness_MetaData), NewProp_TempShape_Brightness_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_Posterize = { "TempShape_Posterize", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, TempShape_Posterize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_Posterize_MetaData), NewProp_TempShape_Posterize_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_Saturation = { "TempShape_Saturation", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, TempShape_Saturation), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_Saturation_MetaData), NewProp_TempShape_Saturation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_LutWeight = { "TempShape_LutWeight", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, TempShape_LutWeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_LutWeight_MetaData), NewProp_TempShape_LutWeight_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_ColorLUTSource = { "TempShape_ColorLUTSource", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, TempShape_ColorLUTSource), Z_Construct_UClass_UOculusXRPassthroughColorLut_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_ColorLUTSource_MetaData), NewProp_TempShape_ColorLUTSource_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_ColorLUTTarget = { "TempShape_ColorLUTTarget", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, TempShape_ColorLUTTarget), Z_Construct_UClass_UOculusXRPassthroughColorLut_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_ColorLUTTarget_MetaData), NewProp_TempShape_ColorLUTTarget_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_ColorScale = { "TempShape_ColorScale", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, TempShape_ColorScale), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_ColorScale_MetaData), NewProp_TempShape_ColorScale_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_ColorOffset = { "TempShape_ColorOffset", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPersistentPassthroughParameters, TempShape_ColorOffset), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempShape_ColorOffset_MetaData), NewProp_TempShape_ColorOffset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_bVisible,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_Priority,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_Shape,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_LayerOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_TextureOpacityFactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_bEnableEdgeColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_EdgeColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_bEnableColorMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_ColorMapType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_bUseColorMapCurve,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_ColorMapCurve,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_Contrast,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_Brightness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_Posterize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_Saturation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_LutWeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_ColorLUTSource,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_ColorLUTTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_ColorScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewProp_TempShape_ColorOffset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRPassthrough,
	nullptr,
	&NewStructOps,
	"OculusXRPersistentPassthroughParameters",
	Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::PropPointers),
	sizeof(FOculusXRPersistentPassthroughParameters),
	alignof(FOculusXRPersistentPassthroughParameters),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRPersistentPassthroughParameters.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OculusXRPersistentPassthroughParameters.InnerSingleton, Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OculusXRPersistentPassthroughParameters.InnerSingleton;
}
// End ScriptStruct FOculusXRPersistentPassthroughParameters

// Begin Class UOculusXRPersistentPassthroughInstance Function GetPriority
struct Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority_Statics
{
	struct OculusXRPersistentPassthroughInstance_eventGetPriority_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Passthrough|Persistent" },
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRPersistentPassthroughInstance_eventGetPriority_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRPersistentPassthroughInstance, nullptr, "GetPriority", nullptr, nullptr, Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority_Statics::OculusXRPersistentPassthroughInstance_eventGetPriority_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority_Statics::OculusXRPersistentPassthroughInstance_eventGetPriority_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRPersistentPassthroughInstance::execGetPriority)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetPriority();
	P_NATIVE_END;
}
// End Class UOculusXRPersistentPassthroughInstance Function GetPriority

// Begin Class UOculusXRPersistentPassthroughInstance Function GetShape
struct Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape_Statics
{
	struct OculusXRPersistentPassthroughInstance_eventGetShape_Parms
	{
		UOculusXRStereoLayerShapeReconstructed* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Passthrough|Persistent" },
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRPersistentPassthroughInstance_eventGetShape_Parms, ReturnValue), Z_Construct_UClass_UOculusXRStereoLayerShapeReconstructed_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRPersistentPassthroughInstance, nullptr, "GetShape", nullptr, nullptr, Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape_Statics::OculusXRPersistentPassthroughInstance_eventGetShape_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape_Statics::OculusXRPersistentPassthroughInstance_eventGetShape_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRPersistentPassthroughInstance::execGetShape)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UOculusXRStereoLayerShapeReconstructed**)Z_Param__Result=P_THIS->GetShape();
	P_NATIVE_END;
}
// End Class UOculusXRPersistentPassthroughInstance Function GetShape

// Begin Class UOculusXRPersistentPassthroughInstance Function IsVisible
struct Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics
{
	struct OculusXRPersistentPassthroughInstance_eventIsVisible_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Passthrough|Persistent" },
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRPersistentPassthroughInstance_eventIsVisible_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRPersistentPassthroughInstance_eventIsVisible_Parms), &Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRPersistentPassthroughInstance, nullptr, "IsVisible", nullptr, nullptr, Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics::OculusXRPersistentPassthroughInstance_eventIsVisible_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics::OculusXRPersistentPassthroughInstance_eventIsVisible_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRPersistentPassthroughInstance::execIsVisible)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsVisible();
	P_NATIVE_END;
}
// End Class UOculusXRPersistentPassthroughInstance Function IsVisible

// Begin Class UOculusXRPersistentPassthroughInstance Function OnAnyLayerResumedEvent
struct Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent_Statics
{
	struct OculusXRPersistentPassthroughInstance_eventOnAnyLayerResumedEvent_Parms
	{
		int32 InLayerId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_InLayerId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent_Statics::NewProp_InLayerId = { "InLayerId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRPersistentPassthroughInstance_eventOnAnyLayerResumedEvent_Parms, InLayerId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent_Statics::NewProp_InLayerId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRPersistentPassthroughInstance, nullptr, "OnAnyLayerResumedEvent", nullptr, nullptr, Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent_Statics::OculusXRPersistentPassthroughInstance_eventOnAnyLayerResumedEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent_Statics::OculusXRPersistentPassthroughInstance_eventOnAnyLayerResumedEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRPersistentPassthroughInstance::execOnAnyLayerResumedEvent)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InLayerId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAnyLayerResumedEvent(Z_Param_InLayerId);
	P_NATIVE_END;
}
// End Class UOculusXRPersistentPassthroughInstance Function OnAnyLayerResumedEvent

// Begin Class UOculusXRPersistentPassthroughInstance Function SetPriority
struct Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority_Statics
{
	struct OculusXRPersistentPassthroughInstance_eventSetPriority_Parms
	{
		int32 InPriority;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Passthrough|Persistent" },
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_InPriority;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority_Statics::NewProp_InPriority = { "InPriority", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRPersistentPassthroughInstance_eventSetPriority_Parms, InPriority), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority_Statics::NewProp_InPriority,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRPersistentPassthroughInstance, nullptr, "SetPriority", nullptr, nullptr, Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority_Statics::OculusXRPersistentPassthroughInstance_eventSetPriority_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority_Statics::OculusXRPersistentPassthroughInstance_eventSetPriority_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRPersistentPassthroughInstance::execSetPriority)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InPriority);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPriority(Z_Param_InPriority);
	P_NATIVE_END;
}
// End Class UOculusXRPersistentPassthroughInstance Function SetPriority

// Begin Class UOculusXRPersistentPassthroughInstance Function SetVisible
struct Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics
{
	struct OculusXRPersistentPassthroughInstance_eventSetVisible_Parms
	{
		bool InVisible;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Passthrough|Persistent" },
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
#endif // WITH_METADATA
	static void NewProp_InVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_InVisible;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics::NewProp_InVisible_SetBit(void* Obj)
{
	((OculusXRPersistentPassthroughInstance_eventSetVisible_Parms*)Obj)->InVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics::NewProp_InVisible = { "InVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRPersistentPassthroughInstance_eventSetVisible_Parms), &Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics::NewProp_InVisible_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics::NewProp_InVisible,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRPersistentPassthroughInstance, nullptr, "SetVisible", nullptr, nullptr, Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics::OculusXRPersistentPassthroughInstance_eventSetVisible_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics::OculusXRPersistentPassthroughInstance_eventSetVisible_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRPersistentPassthroughInstance::execSetVisible)
{
	P_GET_UBOOL(Z_Param_InVisible);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetVisible(Z_Param_InVisible);
	P_NATIVE_END;
}
// End Class UOculusXRPersistentPassthroughInstance Function SetVisible

// Begin Class UOculusXRPersistentPassthroughInstance
void UOculusXRPersistentPassthroughInstance::StaticRegisterNativesUOculusXRPersistentPassthroughInstance()
{
	UClass* Class = UOculusXRPersistentPassthroughInstance::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetPriority", &UOculusXRPersistentPassthroughInstance::execGetPriority },
		{ "GetShape", &UOculusXRPersistentPassthroughInstance::execGetShape },
		{ "IsVisible", &UOculusXRPersistentPassthroughInstance::execIsVisible },
		{ "OnAnyLayerResumedEvent", &UOculusXRPersistentPassthroughInstance::execOnAnyLayerResumedEvent },
		{ "SetPriority", &UOculusXRPersistentPassthroughInstance::execSetPriority },
		{ "SetVisible", &UOculusXRPersistentPassthroughInstance::execSetVisible },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRPersistentPassthroughInstance);
UClass* Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_NoRegister()
{
	return UOculusXRPersistentPassthroughInstance::StaticClass();
}
struct Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "OculusXRPersistentPassthroughInstance.h" },
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Parameters_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnLayerResumed_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPersistentPassthroughInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Parameters;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLayerResumed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetPriority, "GetPriority" }, // 1838333546
		{ &Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_GetShape, "GetShape" }, // 1189454806
		{ &Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_IsVisible, "IsVisible" }, // 1267654611
		{ &Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_OnAnyLayerResumedEvent, "OnAnyLayerResumedEvent" }, // 861371057
		{ &Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetPriority, "SetPriority" }, // 606177786
		{ &Z_Construct_UFunction_UOculusXRPersistentPassthroughInstance_SetVisible, "SetVisible" }, // 3900065944
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRPersistentPassthroughInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics::NewProp_Parameters = { "Parameters", nullptr, (EPropertyFlags)0x0020088000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRPersistentPassthroughInstance, Parameters), Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Parameters_MetaData), NewProp_Parameters_MetaData) }; // 2817404716
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics::NewProp_OnLayerResumed = { "OnLayerResumed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRPersistentPassthroughInstance, OnLayerResumed), Z_Construct_UDelegateFunction_OculusXRHMD_OculusXRPassthrough_LayerResumed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnLayerResumed_MetaData), NewProp_OnLayerResumed_MetaData) }; // 2607586265
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics::NewProp_Parameters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics::NewProp_OnLayerResumed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRPassthrough,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics::ClassParams = {
	&UOculusXRPersistentPassthroughInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRPersistentPassthroughInstance()
{
	if (!Z_Registration_Info_UClass_UOculusXRPersistentPassthroughInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRPersistentPassthroughInstance.OuterSingleton, Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRPersistentPassthroughInstance.OuterSingleton;
}
template<> OCULUSXRPASSTHROUGH_API UClass* StaticClass<UOculusXRPersistentPassthroughInstance>()
{
	return UOculusXRPersistentPassthroughInstance::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRPersistentPassthroughInstance);
UOculusXRPersistentPassthroughInstance::~UOculusXRPersistentPassthroughInstance() {}
// End Class UOculusXRPersistentPassthroughInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOculusXRPersistentPassthroughParameters::StaticStruct, Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters_Statics::NewStructOps, TEXT("OculusXRPersistentPassthroughParameters"), &Z_Registration_Info_UScriptStruct_OculusXRPersistentPassthroughParameters, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOculusXRPersistentPassthroughParameters), 2817404716U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRPersistentPassthroughInstance, UOculusXRPersistentPassthroughInstance::StaticClass, TEXT("UOculusXRPersistentPassthroughInstance"), &Z_Registration_Info_UClass_UOculusXRPersistentPassthroughInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRPersistentPassthroughInstance), 1151483567U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_2397422049(TEXT("/Script/OculusXRPassthrough"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPersistentPassthroughInstance_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
