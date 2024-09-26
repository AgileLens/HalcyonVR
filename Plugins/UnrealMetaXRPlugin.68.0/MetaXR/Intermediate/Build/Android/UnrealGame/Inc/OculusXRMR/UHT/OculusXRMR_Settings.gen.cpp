// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRMR/Public/OculusXRMR_Settings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRMR_Settings() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
OCULUSXRMR_API UClass* Z_Construct_UClass_UOculusXRMR_Settings();
OCULUSXRMR_API UClass* Z_Construct_UClass_UOculusXRMR_Settings_NoRegister();
OCULUSXRMR_API UEnum* Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CameraDeviceEnum();
OCULUSXRMR_API UEnum* Z_Construct_UEnum_OculusXRMR_EOculusXRMR_ClippingReference();
OCULUSXRMR_API UEnum* Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CompositionMethod();
OCULUSXRMR_API UEnum* Z_Construct_UEnum_OculusXRMR_EOculusXRMR_PostProcessEffects();
UPackage* Z_Construct_UPackage__Script_OculusXRMR();
// End Cross Module References

// Begin Enum EOculusXRMR_CameraDeviceEnum
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRMR_CameraDeviceEnum;
static UEnum* EOculusXRMR_CameraDeviceEnum_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRMR_CameraDeviceEnum.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRMR_CameraDeviceEnum.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CameraDeviceEnum, (UObject*)Z_Construct_UPackage__Script_OculusXRMR(), TEXT("EOculusXRMR_CameraDeviceEnum"));
	}
	return Z_Registration_Info_UEnum_EOculusXRMR_CameraDeviceEnum.OuterSingleton;
}
template<> OCULUSXRMR_API UEnum* StaticEnum<EOculusXRMR_CameraDeviceEnum>()
{
	return EOculusXRMR_CameraDeviceEnum_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CameraDeviceEnum_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CD_None_DEPRECATED.DisplayName", "None" },
		{ "CD_None_DEPRECATED.Name", "EOculusXRMR_CameraDeviceEnum::CD_None_DEPRECATED" },
		{ "CD_WebCamera0_DEPRECATED.DisplayName", "Web Camera 0" },
		{ "CD_WebCamera0_DEPRECATED.Name", "EOculusXRMR_CameraDeviceEnum::CD_WebCamera0_DEPRECATED" },
		{ "CD_WebCamera1_DEPRECATED.DisplayName", "Web Camera 1" },
		{ "CD_WebCamera1_DEPRECATED.Name", "EOculusXRMR_CameraDeviceEnum::CD_WebCamera1_DEPRECATED" },
		{ "Comment", "// Deprecated\n" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "Deprecated" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRMR_CameraDeviceEnum::CD_None_DEPRECATED", (int64)EOculusXRMR_CameraDeviceEnum::CD_None_DEPRECATED },
		{ "EOculusXRMR_CameraDeviceEnum::CD_WebCamera0_DEPRECATED", (int64)EOculusXRMR_CameraDeviceEnum::CD_WebCamera0_DEPRECATED },
		{ "EOculusXRMR_CameraDeviceEnum::CD_WebCamera1_DEPRECATED", (int64)EOculusXRMR_CameraDeviceEnum::CD_WebCamera1_DEPRECATED },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CameraDeviceEnum_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRMR,
	nullptr,
	"EOculusXRMR_CameraDeviceEnum",
	"EOculusXRMR_CameraDeviceEnum",
	Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CameraDeviceEnum_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CameraDeviceEnum_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CameraDeviceEnum_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CameraDeviceEnum_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CameraDeviceEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRMR_CameraDeviceEnum.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRMR_CameraDeviceEnum.InnerSingleton, Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CameraDeviceEnum_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRMR_CameraDeviceEnum.InnerSingleton;
}
// End Enum EOculusXRMR_CameraDeviceEnum

// Begin Enum EOculusXRMR_ClippingReference
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRMR_ClippingReference;
static UEnum* EOculusXRMR_ClippingReference_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRMR_ClippingReference.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRMR_ClippingReference.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRMR_EOculusXRMR_ClippingReference, (UObject*)Z_Construct_UPackage__Script_OculusXRMR(), TEXT("EOculusXRMR_ClippingReference"));
	}
	return Z_Registration_Info_UEnum_EOculusXRMR_ClippingReference.OuterSingleton;
}
template<> OCULUSXRMR_API UEnum* StaticEnum<EOculusXRMR_ClippingReference>()
{
	return EOculusXRMR_ClippingReference_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRMR_EOculusXRMR_ClippingReference_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CR_Head.DisplayName", "Head" },
		{ "CR_Head.Name", "EOculusXRMR_ClippingReference::CR_Head" },
		{ "CR_TrackingReference.DisplayName", "Tracking Reference" },
		{ "CR_TrackingReference.Name", "EOculusXRMR_ClippingReference::CR_TrackingReference" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRMR_ClippingReference::CR_TrackingReference", (int64)EOculusXRMR_ClippingReference::CR_TrackingReference },
		{ "EOculusXRMR_ClippingReference::CR_Head", (int64)EOculusXRMR_ClippingReference::CR_Head },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRMR_EOculusXRMR_ClippingReference_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRMR,
	nullptr,
	"EOculusXRMR_ClippingReference",
	"EOculusXRMR_ClippingReference",
	Z_Construct_UEnum_OculusXRMR_EOculusXRMR_ClippingReference_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRMR_EOculusXRMR_ClippingReference_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRMR_EOculusXRMR_ClippingReference_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRMR_EOculusXRMR_ClippingReference_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRMR_EOculusXRMR_ClippingReference()
{
	if (!Z_Registration_Info_UEnum_EOculusXRMR_ClippingReference.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRMR_ClippingReference.InnerSingleton, Z_Construct_UEnum_OculusXRMR_EOculusXRMR_ClippingReference_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRMR_ClippingReference.InnerSingleton;
}
// End Enum EOculusXRMR_ClippingReference

// Begin Enum EOculusXRMR_PostProcessEffects
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRMR_PostProcessEffects;
static UEnum* EOculusXRMR_PostProcessEffects_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRMR_PostProcessEffects.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRMR_PostProcessEffects.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRMR_EOculusXRMR_PostProcessEffects, (UObject*)Z_Construct_UPackage__Script_OculusXRMR(), TEXT("EOculusXRMR_PostProcessEffects"));
	}
	return Z_Registration_Info_UEnum_EOculusXRMR_PostProcessEffects.OuterSingleton;
}
template<> OCULUSXRMR_API UEnum* StaticEnum<EOculusXRMR_PostProcessEffects>()
{
	return EOculusXRMR_PostProcessEffects_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRMR_EOculusXRMR_PostProcessEffects_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "PPE_Off.DisplayName", "Off" },
		{ "PPE_Off.Name", "EOculusXRMR_PostProcessEffects::PPE_Off" },
		{ "PPE_On.DisplayName", "On" },
		{ "PPE_On.Name", "EOculusXRMR_PostProcessEffects::PPE_On" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRMR_PostProcessEffects::PPE_Off", (int64)EOculusXRMR_PostProcessEffects::PPE_Off },
		{ "EOculusXRMR_PostProcessEffects::PPE_On", (int64)EOculusXRMR_PostProcessEffects::PPE_On },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRMR_EOculusXRMR_PostProcessEffects_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRMR,
	nullptr,
	"EOculusXRMR_PostProcessEffects",
	"EOculusXRMR_PostProcessEffects",
	Z_Construct_UEnum_OculusXRMR_EOculusXRMR_PostProcessEffects_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRMR_EOculusXRMR_PostProcessEffects_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRMR_EOculusXRMR_PostProcessEffects_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRMR_EOculusXRMR_PostProcessEffects_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRMR_EOculusXRMR_PostProcessEffects()
{
	if (!Z_Registration_Info_UEnum_EOculusXRMR_PostProcessEffects.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRMR_PostProcessEffects.InnerSingleton, Z_Construct_UEnum_OculusXRMR_EOculusXRMR_PostProcessEffects_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRMR_PostProcessEffects.InnerSingleton;
}
// End Enum EOculusXRMR_PostProcessEffects

// Begin Enum EOculusXRMR_CompositionMethod
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRMR_CompositionMethod;
static UEnum* EOculusXRMR_CompositionMethod_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRMR_CompositionMethod.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRMR_CompositionMethod.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CompositionMethod, (UObject*)Z_Construct_UPackage__Script_OculusXRMR(), TEXT("EOculusXRMR_CompositionMethod"));
	}
	return Z_Registration_Info_UEnum_EOculusXRMR_CompositionMethod.OuterSingleton;
}
template<> OCULUSXRMR_API UEnum* StaticEnum<EOculusXRMR_CompositionMethod>()
{
	return EOculusXRMR_CompositionMethod_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CompositionMethod_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DirectComposition_DEPRECATED.Comment", "/* (Deprecated) Composite the camera stream directly to the output with the proper depth.*/" },
		{ "DirectComposition_DEPRECATED.DisplayName", "Direct Composition (DEPRECATED)" },
		{ "DirectComposition_DEPRECATED.Name", "EOculusXRMR_CompositionMethod::DirectComposition_DEPRECATED" },
		{ "DirectComposition_DEPRECATED.ToolTip", "(Deprecated) Composite the camera stream directly to the output with the proper depth." },
		{ "ExternalComposition.Comment", "/* Generate both foreground and background views for compositing with 3rd-party software like OBS. */" },
		{ "ExternalComposition.DisplayName", "External Composition" },
		{ "ExternalComposition.Name", "EOculusXRMR_CompositionMethod::ExternalComposition" },
		{ "ExternalComposition.ToolTip", "Generate both foreground and background views for compositing with 3rd-party software like OBS." },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRMR_CompositionMethod::ExternalComposition", (int64)EOculusXRMR_CompositionMethod::ExternalComposition },
		{ "EOculusXRMR_CompositionMethod::DirectComposition_DEPRECATED", (int64)EOculusXRMR_CompositionMethod::DirectComposition_DEPRECATED },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CompositionMethod_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRMR,
	nullptr,
	"EOculusXRMR_CompositionMethod",
	"EOculusXRMR_CompositionMethod",
	Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CompositionMethod_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CompositionMethod_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CompositionMethod_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CompositionMethod_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CompositionMethod()
{
	if (!Z_Registration_Info_UEnum_EOculusXRMR_CompositionMethod.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRMR_CompositionMethod.InnerSingleton, Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CompositionMethod_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRMR_CompositionMethod.InnerSingleton;
}
// End Enum EOculusXRMR_CompositionMethod

// Begin Class UOculusXRMR_Settings Function BindToTrackedCameraIndexIfAvailable
struct Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable_Statics
{
	struct OculusXRMR_Settings_eventBindToTrackedCameraIndexIfAvailable_Parms
	{
		int32 InTrackedCameraIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** Bind the casting camera to the calibrated external camera.\n\x09 * (Requires a calibrated external camera)\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "Bind the casting camera to the calibrated external camera.\n(Requires a calibrated external camera)" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_InTrackedCameraIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable_Statics::NewProp_InTrackedCameraIndex = { "InTrackedCameraIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRMR_Settings_eventBindToTrackedCameraIndexIfAvailable_Parms, InTrackedCameraIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable_Statics::NewProp_InTrackedCameraIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRMR_Settings, nullptr, "BindToTrackedCameraIndexIfAvailable", nullptr, nullptr, Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable_Statics::OculusXRMR_Settings_eventBindToTrackedCameraIndexIfAvailable_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable_Statics::OculusXRMR_Settings_eventBindToTrackedCameraIndexIfAvailable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRMR_Settings::execBindToTrackedCameraIndexIfAvailable)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InTrackedCameraIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BindToTrackedCameraIndexIfAvailable(Z_Param_InTrackedCameraIndex);
	P_NATIVE_END;
}
// End Class UOculusXRMR_Settings Function BindToTrackedCameraIndexIfAvailable

// Begin Class UOculusXRMR_Settings Function GetBindToTrackedCameraIndex
struct Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex_Statics
{
	struct OculusXRMR_Settings_eventGetBindToTrackedCameraIndex_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRMR_Settings_eventGetBindToTrackedCameraIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRMR_Settings, nullptr, "GetBindToTrackedCameraIndex", nullptr, nullptr, Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex_Statics::OculusXRMR_Settings_eventGetBindToTrackedCameraIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex_Statics::OculusXRMR_Settings_eventGetBindToTrackedCameraIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRMR_Settings::execGetBindToTrackedCameraIndex)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetBindToTrackedCameraIndex();
	P_NATIVE_END;
}
// End Class UOculusXRMR_Settings Function GetBindToTrackedCameraIndex

// Begin Class UOculusXRMR_Settings Function GetCapturingCamera
struct Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics
{
	struct OculusXRMR_Settings_eventGetCapturingCamera_Parms
	{
		EOculusXRMR_CameraDeviceEnum ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** When CompositionMethod is DirectComposition, the physical camera device which provide the frame */" },
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Direct Composition deprecated." },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "When CompositionMethod is DirectComposition, the physical camera device which provide the frame" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRMR_Settings_eventGetCapturingCamera_Parms, ReturnValue), Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CameraDeviceEnum, METADATA_PARAMS(0, nullptr) }; // 783225587
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRMR_Settings, nullptr, "GetCapturingCamera", nullptr, nullptr, Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics::OculusXRMR_Settings_eventGetCapturingCamera_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics::OculusXRMR_Settings_eventGetCapturingCamera_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRMR_Settings::execGetCapturingCamera)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EOculusXRMR_CameraDeviceEnum*)Z_Param__Result=P_THIS->GetCapturingCamera();
	P_NATIVE_END;
}
// End Class UOculusXRMR_Settings Function GetCapturingCamera

// Begin Class UOculusXRMR_Settings Function GetCompositionMethod
struct Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics
{
	struct OculusXRMR_Settings_eventGetCompositionMethod_Parms
	{
		EOculusXRMR_CompositionMethod ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** ExternalComposition: The casting window includes the background and foreground view\n\x09 * DirectComposition: The game scene would be composited with the camera frame directly\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "ExternalComposition: The casting window includes the background and foreground view\nDirectComposition: The game scene would be composited with the camera frame directly" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRMR_Settings_eventGetCompositionMethod_Parms, ReturnValue), Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CompositionMethod, METADATA_PARAMS(0, nullptr) }; // 2450647924
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRMR_Settings, nullptr, "GetCompositionMethod", nullptr, nullptr, Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics::OculusXRMR_Settings_eventGetCompositionMethod_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics::OculusXRMR_Settings_eventGetCompositionMethod_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRMR_Settings::execGetCompositionMethod)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EOculusXRMR_CompositionMethod*)Z_Param__Result=P_THIS->GetCompositionMethod();
	P_NATIVE_END;
}
// End Class UOculusXRMR_Settings Function GetCompositionMethod

// Begin Class UOculusXRMR_Settings Function GetIsCasting
struct Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics
{
	struct OculusXRMR_Settings_eventGetIsCasting_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** Is MRC on and off */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "Is MRC on and off" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRMR_Settings_eventGetIsCasting_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRMR_Settings_eventGetIsCasting_Parms), &Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRMR_Settings, nullptr, "GetIsCasting", nullptr, nullptr, Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics::OculusXRMR_Settings_eventGetIsCasting_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics::OculusXRMR_Settings_eventGetIsCasting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRMR_Settings::execGetIsCasting)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetIsCasting();
	P_NATIVE_END;
}
// End Class UOculusXRMR_Settings Function GetIsCasting

// Begin Class UOculusXRMR_Settings Function LoadFromIni
struct Z_Construct_UFunction_UOculusXRMR_Settings_LoadFromIni_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** Load settings from the config file */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "Load settings from the config file" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRMR_Settings_LoadFromIni_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRMR_Settings, nullptr, "LoadFromIni", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_LoadFromIni_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRMR_Settings_LoadFromIni_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UOculusXRMR_Settings_LoadFromIni()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRMR_Settings_LoadFromIni_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRMR_Settings::execLoadFromIni)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LoadFromIni();
	P_NATIVE_END;
}
// End Class UOculusXRMR_Settings Function LoadFromIni

// Begin Class UOculusXRMR_Settings Function SaveToIni
struct Z_Construct_UFunction_UOculusXRMR_Settings_SaveToIni_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** Save settings to the config file */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "Save settings to the config file" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRMR_Settings_SaveToIni_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRMR_Settings, nullptr, "SaveToIni", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x44020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_SaveToIni_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRMR_Settings_SaveToIni_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UOculusXRMR_Settings_SaveToIni()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRMR_Settings_SaveToIni_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRMR_Settings::execSaveToIni)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SaveToIni();
	P_NATIVE_END;
}
// End Class UOculusXRMR_Settings Function SaveToIni

// Begin Class UOculusXRMR_Settings Function SetCapturingCamera
struct Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics
{
	struct OculusXRMR_Settings_eventSetCapturingCamera_Parms
	{
		EOculusXRMR_CameraDeviceEnum val;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** When CompositionMethod is DirectComposition, the physical camera device which provide the frame */" },
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Direct Composition deprecated." },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "When CompositionMethod is DirectComposition, the physical camera device which provide the frame" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_val_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_val;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics::NewProp_val_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics::NewProp_val = { "val", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRMR_Settings_eventSetCapturingCamera_Parms, val), Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CameraDeviceEnum, METADATA_PARAMS(0, nullptr) }; // 783225587
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics::NewProp_val_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics::NewProp_val,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRMR_Settings, nullptr, "SetCapturingCamera", nullptr, nullptr, Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics::OculusXRMR_Settings_eventSetCapturingCamera_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics::OculusXRMR_Settings_eventSetCapturingCamera_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRMR_Settings::execSetCapturingCamera)
{
	P_GET_ENUM(EOculusXRMR_CameraDeviceEnum,Z_Param_val);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCapturingCamera(EOculusXRMR_CameraDeviceEnum(Z_Param_val));
	P_NATIVE_END;
}
// End Class UOculusXRMR_Settings Function SetCapturingCamera

// Begin Class UOculusXRMR_Settings Function SetCompositionMethod
struct Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics
{
	struct OculusXRMR_Settings_eventSetCompositionMethod_Parms
	{
		EOculusXRMR_CompositionMethod val;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** ExternalComposition: The casting window includes the background and foreground view\n\x09 * DirectComposition: The game scene would be composited with the camera frame directly\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "ExternalComposition: The casting window includes the background and foreground view\nDirectComposition: The game scene would be composited with the camera frame directly" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_val_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_val;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics::NewProp_val_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics::NewProp_val = { "val", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRMR_Settings_eventSetCompositionMethod_Parms, val), Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CompositionMethod, METADATA_PARAMS(0, nullptr) }; // 2450647924
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics::NewProp_val_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics::NewProp_val,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRMR_Settings, nullptr, "SetCompositionMethod", nullptr, nullptr, Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics::OculusXRMR_Settings_eventSetCompositionMethod_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics::OculusXRMR_Settings_eventSetCompositionMethod_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRMR_Settings::execSetCompositionMethod)
{
	P_GET_ENUM(EOculusXRMR_CompositionMethod,Z_Param_val);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCompositionMethod(EOculusXRMR_CompositionMethod(Z_Param_val));
	P_NATIVE_END;
}
// End Class UOculusXRMR_Settings Function SetCompositionMethod

// Begin Class UOculusXRMR_Settings Function SetIsCasting
struct Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics
{
	struct OculusXRMR_Settings_eventSetIsCasting_Parms
	{
		bool val;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** Turns MRC on and off */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "Turns MRC on and off" },
	};
#endif // WITH_METADATA
	static void NewProp_val_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_val;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics::NewProp_val_SetBit(void* Obj)
{
	((OculusXRMR_Settings_eventSetIsCasting_Parms*)Obj)->val = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics::NewProp_val = { "val", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRMR_Settings_eventSetIsCasting_Parms), &Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics::NewProp_val_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics::NewProp_val,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRMR_Settings, nullptr, "SetIsCasting", nullptr, nullptr, Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics::OculusXRMR_Settings_eventSetIsCasting_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics::OculusXRMR_Settings_eventSetIsCasting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRMR_Settings::execSetIsCasting)
{
	P_GET_UBOOL(Z_Param_val);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetIsCasting(Z_Param_val);
	P_NATIVE_END;
}
// End Class UOculusXRMR_Settings Function SetIsCasting

// Begin Class UOculusXRMR_Settings
void UOculusXRMR_Settings::StaticRegisterNativesUOculusXRMR_Settings()
{
	UClass* Class = UOculusXRMR_Settings::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "BindToTrackedCameraIndexIfAvailable", &UOculusXRMR_Settings::execBindToTrackedCameraIndexIfAvailable },
		{ "GetBindToTrackedCameraIndex", &UOculusXRMR_Settings::execGetBindToTrackedCameraIndex },
		{ "GetCapturingCamera", &UOculusXRMR_Settings::execGetCapturingCamera },
		{ "GetCompositionMethod", &UOculusXRMR_Settings::execGetCompositionMethod },
		{ "GetIsCasting", &UOculusXRMR_Settings::execGetIsCasting },
		{ "LoadFromIni", &UOculusXRMR_Settings::execLoadFromIni },
		{ "SaveToIni", &UOculusXRMR_Settings::execSaveToIni },
		{ "SetCapturingCamera", &UOculusXRMR_Settings::execSetCapturingCamera },
		{ "SetCompositionMethod", &UOculusXRMR_Settings::execSetCompositionMethod },
		{ "SetIsCasting", &UOculusXRMR_Settings::execSetIsCasting },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRMR_Settings);
UClass* Z_Construct_UClass_UOculusXRMR_Settings_NoRegister()
{
	return UOculusXRMR_Settings::StaticClass();
}
struct Z_Construct_UClass_UOculusXRMR_Settings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "OculusXRMR" },
		{ "IncludePath", "OculusXRMR_Settings.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClippingReference_MetaData[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** Specify the distance to the camera which divide the background and foreground in MxR casting.\n\x09 * Set it to CR_TrackingReference to use the distance to the Tracking Reference, which works better\n\x09 * in the stationary experience. Set it to CR_Head would use the distance to the HMD, which works better\n\x09 * in the room scale experience.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "Specify the distance to the camera which divide the background and foreground in MxR casting.\nSet it to CR_TrackingReference to use the distance to the Tracking Reference, which works better\nin the stationary experience. Set it to CR_Head would use the distance to the HMD, which works better\nin the room scale experience." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseTrackedCameraResolution_MetaData[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** The casting viewports would use the same resolution of the camera which used in the calibration process. */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "The casting viewports would use the same resolution of the camera which used in the calibration process." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WidthPerView_MetaData[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** When bUseTrackedCameraResolution is false, the width of each casting viewport */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "When bUseTrackedCameraResolution is false, the width of each casting viewport" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeightPerView_MetaData[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** When bUseTrackedCameraResolution is false, the height of each casting viewport */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "When bUseTrackedCameraResolution is false, the height of each casting viewport" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CastingLatency_MetaData[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** When CompositionMethod is External Composition, the latency of the casting output which could be adjusted to\n\x09 * match the camera latency in the external composition application */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "When CompositionMethod is External Composition, the latency of the casting output which could be adjusted to\nmatch the camera latency in the external composition application" },
		{ "UIMax", "0.1" },
		{ "UIMin", "0.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BackdropColor_MetaData[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** When CompositionMethod is External Composition, the color of the backdrop in the foreground view */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "When CompositionMethod is External Composition, the color of the backdrop in the foreground view" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HandPoseStateLatency_MetaData[] = {
		{ "Comment", "/** When CompositionMethod is Direct Composition, you could adjust this latency to delay the virtual\n\x09 * hand movement by a small amount of time to match the camera latency */" },
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Direct Composition deprecated." },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "When CompositionMethod is Direct Composition, you could adjust this latency to delay the virtual\nhand movement by a small amount of time to match the camera latency" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChromaKeyColor_MetaData[] = {
		{ "Comment", "/** [Green-screen removal] Chroma Key Color. Apply when CompositionMethod is DirectComposition */" },
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Direct Composition deprecated." },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "[Green-screen removal] Chroma Key Color. Apply when CompositionMethod is DirectComposition" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChromaKeySimilarity_MetaData[] = {
		{ "Comment", "/** [Green-screen removal] Chroma Key Similarity. Apply when CompositionMethod is DirectComposition */" },
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Direct Composition deprecated." },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "[Green-screen removal] Chroma Key Similarity. Apply when CompositionMethod is DirectComposition" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChromaKeySmoothRange_MetaData[] = {
		{ "Comment", "/** [Green-screen removal] Chroma Key Smooth Range. Apply when CompositionMethod is DirectComposition */" },
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Direct Composition deprecated." },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "[Green-screen removal] Chroma Key Smooth Range. Apply when CompositionMethod is DirectComposition" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChromaKeySpillRange_MetaData[] = {
		{ "Comment", "/** [Green-screen removal] Chroma Key Spill Range. Apply when CompositionMethod is DirectComposition */" },
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Direct Composition deprecated." },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "[Green-screen removal] Chroma Key Spill Range. Apply when CompositionMethod is DirectComposition" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExternalCompositionPostProcessEffects_MetaData[] = {
		{ "Category", "MetaXR" },
		{ "Comment", "/** Set the amount of post process effects in the MR view for external composition */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "Set the amount of post process effects in the MR view for external composition" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsCasting_MetaData[] = {
		{ "Comment", "/** Turns MRC on and off (does not get saved to or loaded from ini) */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "Turns MRC on and off (does not get saved to or loaded from ini)" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CompositionMethod_MetaData[] = {
		{ "Comment", "/** ExternalComposition: The casting window includes the background and foreground view\n\x09 * DirectComposition: The game scene would be composited with the camera frame directly\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "ExternalComposition: The casting window includes the background and foreground view\nDirectComposition: The game scene would be composited with the camera frame directly" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CapturingCamera_MetaData[] = {
		{ "Comment", "/** When CompositionMethod is DirectComposition, the physical camera device which provide the frame */" },
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Direct Composition deprecated." },
		{ "ModuleRelativePath", "Public/OculusXRMR_Settings.h" },
		{ "ToolTip", "When CompositionMethod is DirectComposition, the physical camera device which provide the frame" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ClippingReference_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ClippingReference;
	static void NewProp_bUseTrackedCameraResolution_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseTrackedCameraResolution;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WidthPerView;
	static const UECodeGen_Private::FIntPropertyParams NewProp_HeightPerView;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CastingLatency;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BackdropColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HandPoseStateLatency;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ChromaKeyColor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ChromaKeySimilarity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ChromaKeySmoothRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ChromaKeySpillRange;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ExternalCompositionPostProcessEffects_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ExternalCompositionPostProcessEffects;
	static void NewProp_bIsCasting_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsCasting;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CompositionMethod_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CompositionMethod;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CapturingCamera_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CapturingCamera;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOculusXRMR_Settings_BindToTrackedCameraIndexIfAvailable, "BindToTrackedCameraIndexIfAvailable" }, // 4031588809
		{ &Z_Construct_UFunction_UOculusXRMR_Settings_GetBindToTrackedCameraIndex, "GetBindToTrackedCameraIndex" }, // 182022339
		{ &Z_Construct_UFunction_UOculusXRMR_Settings_GetCapturingCamera, "GetCapturingCamera" }, // 472747544
		{ &Z_Construct_UFunction_UOculusXRMR_Settings_GetCompositionMethod, "GetCompositionMethod" }, // 1717036307
		{ &Z_Construct_UFunction_UOculusXRMR_Settings_GetIsCasting, "GetIsCasting" }, // 3318005005
		{ &Z_Construct_UFunction_UOculusXRMR_Settings_LoadFromIni, "LoadFromIni" }, // 3633951061
		{ &Z_Construct_UFunction_UOculusXRMR_Settings_SaveToIni, "SaveToIni" }, // 4052442966
		{ &Z_Construct_UFunction_UOculusXRMR_Settings_SetCapturingCamera, "SetCapturingCamera" }, // 3140590420
		{ &Z_Construct_UFunction_UOculusXRMR_Settings_SetCompositionMethod, "SetCompositionMethod" }, // 2685948277
		{ &Z_Construct_UFunction_UOculusXRMR_Settings_SetIsCasting, "SetIsCasting" }, // 3713086907
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRMR_Settings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ClippingReference_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ClippingReference = { "ClippingReference", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRMR_Settings, ClippingReference), Z_Construct_UEnum_OculusXRMR_EOculusXRMR_ClippingReference, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClippingReference_MetaData), NewProp_ClippingReference_MetaData) }; // 3333274306
void Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_bUseTrackedCameraResolution_SetBit(void* Obj)
{
	((UOculusXRMR_Settings*)Obj)->bUseTrackedCameraResolution = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_bUseTrackedCameraResolution = { "bUseTrackedCameraResolution", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRMR_Settings), &Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_bUseTrackedCameraResolution_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseTrackedCameraResolution_MetaData), NewProp_bUseTrackedCameraResolution_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_WidthPerView = { "WidthPerView", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRMR_Settings, WidthPerView), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WidthPerView_MetaData), NewProp_WidthPerView_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_HeightPerView = { "HeightPerView", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRMR_Settings, HeightPerView), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeightPerView_MetaData), NewProp_HeightPerView_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_CastingLatency = { "CastingLatency", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRMR_Settings, CastingLatency), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CastingLatency_MetaData), NewProp_CastingLatency_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_BackdropColor = { "BackdropColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRMR_Settings, BackdropColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BackdropColor_MetaData), NewProp_BackdropColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_HandPoseStateLatency = { "HandPoseStateLatency", nullptr, (EPropertyFlags)0x0010000020000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRMR_Settings, HandPoseStateLatency_DEPRECATED), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HandPoseStateLatency_MetaData), NewProp_HandPoseStateLatency_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ChromaKeyColor = { "ChromaKeyColor", nullptr, (EPropertyFlags)0x0010000020000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRMR_Settings, ChromaKeyColor_DEPRECATED), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChromaKeyColor_MetaData), NewProp_ChromaKeyColor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ChromaKeySimilarity = { "ChromaKeySimilarity", nullptr, (EPropertyFlags)0x0010000020000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRMR_Settings, ChromaKeySimilarity_DEPRECATED), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChromaKeySimilarity_MetaData), NewProp_ChromaKeySimilarity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ChromaKeySmoothRange = { "ChromaKeySmoothRange", nullptr, (EPropertyFlags)0x0010000020000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRMR_Settings, ChromaKeySmoothRange_DEPRECATED), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChromaKeySmoothRange_MetaData), NewProp_ChromaKeySmoothRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ChromaKeySpillRange = { "ChromaKeySpillRange", nullptr, (EPropertyFlags)0x0010000020000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRMR_Settings, ChromaKeySpillRange_DEPRECATED), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChromaKeySpillRange_MetaData), NewProp_ChromaKeySpillRange_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ExternalCompositionPostProcessEffects_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ExternalCompositionPostProcessEffects = { "ExternalCompositionPostProcessEffects", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRMR_Settings, ExternalCompositionPostProcessEffects), Z_Construct_UEnum_OculusXRMR_EOculusXRMR_PostProcessEffects, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExternalCompositionPostProcessEffects_MetaData), NewProp_ExternalCompositionPostProcessEffects_MetaData) }; // 1753569748
void Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_bIsCasting_SetBit(void* Obj)
{
	((UOculusXRMR_Settings*)Obj)->bIsCasting = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_bIsCasting = { "bIsCasting", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRMR_Settings), &Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_bIsCasting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsCasting_MetaData), NewProp_bIsCasting_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_CompositionMethod_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_CompositionMethod = { "CompositionMethod", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRMR_Settings, CompositionMethod), Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CompositionMethod, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CompositionMethod_MetaData), NewProp_CompositionMethod_MetaData) }; // 2450647924
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_CapturingCamera_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_CapturingCamera = { "CapturingCamera", nullptr, (EPropertyFlags)0x0040000020000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRMR_Settings, CapturingCamera_DEPRECATED), Z_Construct_UEnum_OculusXRMR_EOculusXRMR_CameraDeviceEnum, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CapturingCamera_MetaData), NewProp_CapturingCamera_MetaData) }; // 783225587
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRMR_Settings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ClippingReference_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ClippingReference,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_bUseTrackedCameraResolution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_WidthPerView,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_HeightPerView,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_CastingLatency,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_BackdropColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_HandPoseStateLatency,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ChromaKeyColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ChromaKeySimilarity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ChromaKeySmoothRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ChromaKeySpillRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ExternalCompositionPostProcessEffects_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_ExternalCompositionPostProcessEffects,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_bIsCasting,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_CompositionMethod_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_CompositionMethod,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_CapturingCamera_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRMR_Settings_Statics::NewProp_CapturingCamera,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRMR_Settings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRMR_Settings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRMR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRMR_Settings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRMR_Settings_Statics::ClassParams = {
	&UOculusXRMR_Settings::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOculusXRMR_Settings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRMR_Settings_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRMR_Settings_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRMR_Settings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRMR_Settings()
{
	if (!Z_Registration_Info_UClass_UOculusXRMR_Settings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRMR_Settings.OuterSingleton, Z_Construct_UClass_UOculusXRMR_Settings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRMR_Settings.OuterSingleton;
}
template<> OCULUSXRMR_API UClass* StaticClass<UOculusXRMR_Settings>()
{
	return UOculusXRMR_Settings::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRMR_Settings);
UOculusXRMR_Settings::~UOculusXRMR_Settings() {}
// End Class UOculusXRMR_Settings

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOculusXRMR_CameraDeviceEnum_StaticEnum, TEXT("EOculusXRMR_CameraDeviceEnum"), &Z_Registration_Info_UEnum_EOculusXRMR_CameraDeviceEnum, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 783225587U) },
		{ EOculusXRMR_ClippingReference_StaticEnum, TEXT("EOculusXRMR_ClippingReference"), &Z_Registration_Info_UEnum_EOculusXRMR_ClippingReference, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3333274306U) },
		{ EOculusXRMR_PostProcessEffects_StaticEnum, TEXT("EOculusXRMR_PostProcessEffects"), &Z_Registration_Info_UEnum_EOculusXRMR_PostProcessEffects, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1753569748U) },
		{ EOculusXRMR_CompositionMethod_StaticEnum, TEXT("EOculusXRMR_CompositionMethod"), &Z_Registration_Info_UEnum_EOculusXRMR_CompositionMethod, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2450647924U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRMR_Settings, UOculusXRMR_Settings::StaticClass, TEXT("UOculusXRMR_Settings"), &Z_Registration_Info_UClass_UOculusXRMR_Settings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRMR_Settings), 1904550804U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h_925395316(TEXT("/Script/OculusXRMR"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Public_OculusXRMR_Settings_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
