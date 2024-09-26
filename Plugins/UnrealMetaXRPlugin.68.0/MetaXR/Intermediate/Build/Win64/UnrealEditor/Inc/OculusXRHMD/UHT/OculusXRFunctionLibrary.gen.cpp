// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRHMD/Public/OculusXRFunctionLibrary.h"
#include "OculusXRHMD/Public/OculusXRHMDTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRFunctionLibrary() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
HEADMOUNTEDDISPLAY_API UEnum* Z_Construct_UEnum_HeadMountedDisplay_EOrientPositionSelector();
INPUTCORE_API UEnum* Z_Construct_UEnum_InputCore_EControllerHand();
OCULUSXRHMD_API UClass* Z_Construct_UClass_UOculusXRFunctionLibrary();
OCULUSXRHMD_API UClass* Z_Construct_UClass_UOculusXRFunctionLibrary_NoRegister();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRColorSpace();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerType();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRDeviceType();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXREyeBufferSharpenType();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingLevel();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingMethod();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXROcclusionsMode();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType();
OCULUSXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRGuardianTestResult();
OCULUSXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRHmdUserProfile();
OCULUSXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics();
UPackage* Z_Construct_UPackage__Script_OculusXRHMD();
// End Cross Module References

// Begin Class UOculusXRFunctionLibrary Function AddLoadingSplashScreen
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics
{
	struct OculusXRFunctionLibrary_eventAddLoadingSplashScreen_Parms
	{
		UTexture2D* Texture;
		FVector TranslationInMeters;
		FRotator Rotation;
		FVector2D SizeInMeters;
		FRotator DeltaRotation;
		bool bClearBeforeAdd;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Adds loading splash screen with parameters\n\x09 *\n\x09 * @param Texture\x09\x09\x09(in) A texture asset to be used for the splash.\n\x09 * @param TranslationInMeters (in) Initial translation of the center of the splash screen (in meters).\n\x09 * @param Rotation\x09\x09\x09(in) Initial rotation of the splash screen, with the origin at the center of the splash screen.\n\x09 * @param SizeInMeters\x09\x09(in) Size, in meters, of the quad with the splash screen.\n\x09 * @param DeltaRotation\x09\x09(in) Incremental rotation, that is added each 2nd frame to the quad transform. The quad is rotated around the center of the quad.\n\x09 * @param bClearBeforeAdd\x09(in) If true, clears splashes before adding a new one.\n\x09 */" },
#endif
		{ "CPP_Default_bClearBeforeAdd", "false" },
		{ "CPP_Default_DeltaRotation", "" },
		{ "CPP_Default_SizeInMeters", "(X=1.000,Y=1.000)" },
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Use Add Loading Screen Splash from the Head Mounted Display Loading Screen functions instead." },
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds loading splash screen with parameters\n\n@param Texture                       (in) A texture asset to be used for the splash.\n@param TranslationInMeters (in) Initial translation of the center of the splash screen (in meters).\n@param Rotation                      (in) Initial rotation of the splash screen, with the origin at the center of the splash screen.\n@param SizeInMeters          (in) Size, in meters, of the quad with the splash screen.\n@param DeltaRotation         (in) Incremental rotation, that is added each 2nd frame to the quad transform. The quad is rotated around the center of the quad.\n@param bClearBeforeAdd       (in) If true, clears splashes before adding a new one." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TranslationInMeters;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SizeInMeters;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DeltaRotation;
	static void NewProp_bClearBeforeAdd_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bClearBeforeAdd;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventAddLoadingSplashScreen_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::NewProp_TranslationInMeters = { "TranslationInMeters", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventAddLoadingSplashScreen_Parms, TranslationInMeters), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventAddLoadingSplashScreen_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::NewProp_SizeInMeters = { "SizeInMeters", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventAddLoadingSplashScreen_Parms, SizeInMeters), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::NewProp_DeltaRotation = { "DeltaRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventAddLoadingSplashScreen_Parms, DeltaRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::NewProp_bClearBeforeAdd_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventAddLoadingSplashScreen_Parms*)Obj)->bClearBeforeAdd = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::NewProp_bClearBeforeAdd = { "bClearBeforeAdd", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventAddLoadingSplashScreen_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::NewProp_bClearBeforeAdd_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::NewProp_Texture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::NewProp_TranslationInMeters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::NewProp_SizeInMeters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::NewProp_DeltaRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::NewProp_bClearBeforeAdd,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "AddLoadingSplashScreen", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::OculusXRFunctionLibrary_eventAddLoadingSplashScreen_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::OculusXRFunctionLibrary_eventAddLoadingSplashScreen_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execAddLoadingSplashScreen)
{
	P_GET_OBJECT(UTexture2D,Z_Param_Texture);
	P_GET_STRUCT(FVector,Z_Param_TranslationInMeters);
	P_GET_STRUCT(FRotator,Z_Param_Rotation);
	P_GET_STRUCT(FVector2D,Z_Param_SizeInMeters);
	P_GET_STRUCT(FRotator,Z_Param_DeltaRotation);
	P_GET_UBOOL(Z_Param_bClearBeforeAdd);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::AddLoadingSplashScreen(Z_Param_Texture,Z_Param_TranslationInMeters,Z_Param_Rotation,Z_Param_SizeInMeters,Z_Param_DeltaRotation,Z_Param_bClearBeforeAdd);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function AddLoadingSplashScreen

// Begin Class UOculusXRFunctionLibrary Function ClearLoadingSplashScreens
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_ClearLoadingSplashScreens_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Removes all the splash screens.\n\x09 */" },
#endif
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Use Clear Loading Screen Splashes from the Head Mounted Display Loading Screen functions instead." },
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes all the splash screens." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_ClearLoadingSplashScreens_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "ClearLoadingSplashScreens", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_ClearLoadingSplashScreens_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_ClearLoadingSplashScreens_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_ClearLoadingSplashScreens()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_ClearLoadingSplashScreens_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execClearLoadingSplashScreens)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::ClearLoadingSplashScreens();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function ClearLoadingSplashScreens

// Begin Class UOculusXRFunctionLibrary Function EnableOrientationTracking
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics
{
	struct OculusXRFunctionLibrary_eventEnableOrientationTracking_Parms
	{
		bool bOrientationTracking;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Enables/disables orientation tracking on devices that support it.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enables/disables orientation tracking on devices that support it." },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bOrientationTracking_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOrientationTracking;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics::NewProp_bOrientationTracking_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventEnableOrientationTracking_Parms*)Obj)->bOrientationTracking = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics::NewProp_bOrientationTracking = { "bOrientationTracking", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventEnableOrientationTracking_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics::NewProp_bOrientationTracking_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics::NewProp_bOrientationTracking,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "EnableOrientationTracking", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics::OculusXRFunctionLibrary_eventEnableOrientationTracking_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics::OculusXRFunctionLibrary_eventEnableOrientationTracking_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execEnableOrientationTracking)
{
	P_GET_UBOOL(Z_Param_bOrientationTracking);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::EnableOrientationTracking(Z_Param_bOrientationTracking);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function EnableOrientationTracking

// Begin Class UOculusXRFunctionLibrary Function EnablePositionTracking
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics
{
	struct OculusXRFunctionLibrary_eventEnablePositionTracking_Parms
	{
		bool bPositionTracking;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Enables/disables positional tracking on devices that support it.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enables/disables positional tracking on devices that support it." },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bPositionTracking_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPositionTracking;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics::NewProp_bPositionTracking_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventEnablePositionTracking_Parms*)Obj)->bPositionTracking = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics::NewProp_bPositionTracking = { "bPositionTracking", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventEnablePositionTracking_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics::NewProp_bPositionTracking_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics::NewProp_bPositionTracking,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "EnablePositionTracking", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics::OculusXRFunctionLibrary_eventEnablePositionTracking_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics::OculusXRFunctionLibrary_eventEnablePositionTracking_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execEnablePositionTracking)
{
	P_GET_UBOOL(Z_Param_bPositionTracking);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::EnablePositionTracking(Z_Param_bPositionTracking);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function EnablePositionTracking

// Begin Class UOculusXRFunctionLibrary Function GetAvailableDisplayFrequencies
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics
{
	struct OculusXRFunctionLibrary_eventGetAvailableDisplayFrequencies_Parms
	{
		TArray<float> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the current available frequencies\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the current available frequencies" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetAvailableDisplayFrequencies_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetAvailableDisplayFrequencies", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics::OculusXRFunctionLibrary_eventGetAvailableDisplayFrequencies_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics::OculusXRFunctionLibrary_eventGetAvailableDisplayFrequencies_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetAvailableDisplayFrequencies)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<float>*)Z_Param__Result=UOculusXRFunctionLibrary::GetAvailableDisplayFrequencies();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetAvailableDisplayFrequencies

// Begin Class UOculusXRFunctionLibrary Function GetBaseRotationAndBaseOffsetInMeters
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics
{
	struct OculusXRFunctionLibrary_eventGetBaseRotationAndBaseOffsetInMeters_Parms
	{
		FRotator OutRotation;
		FVector OutBaseOffsetInMeters;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns current base rotation and base offset.\n\x09 * The base offset is currently used base position offset, previously set by the\n\x09 * ResetPosition or SetBasePositionOffset calls. It represents a vector that translates the HMD's position\n\x09 * into (0,0,0) point, in meters.\n\x09 * The axis of the vector are the same as in Unreal: X - forward, Y - right, Z - up.\n\x09 *\n\x09 * @param OutRotation\x09\x09\x09(out) Rotator object with base rotation\n\x09 * @param OutBaseOffsetInMeters\x09(out) base position offset, vector, in meters.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns current base rotation and base offset.\nThe base offset is currently used base position offset, previously set by the\nResetPosition or SetBasePositionOffset calls. It represents a vector that translates the HMD's position\ninto (0,0,0) point, in meters.\nThe axis of the vector are the same as in Unreal: X - forward, Y - right, Z - up.\n\n@param OutRotation                   (out) Rotator object with base rotation\n@param OutBaseOffsetInMeters (out) base position offset, vector, in meters." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutBaseOffsetInMeters;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_OutRotation = { "OutRotation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetBaseRotationAndBaseOffsetInMeters_Parms, OutRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_OutBaseOffsetInMeters = { "OutBaseOffsetInMeters", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetBaseRotationAndBaseOffsetInMeters_Parms, OutBaseOffsetInMeters), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_OutRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_OutBaseOffsetInMeters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetBaseRotationAndBaseOffsetInMeters", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics::OculusXRFunctionLibrary_eventGetBaseRotationAndBaseOffsetInMeters_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics::OculusXRFunctionLibrary_eventGetBaseRotationAndBaseOffsetInMeters_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetBaseRotationAndBaseOffsetInMeters)
{
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_OutRotation);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_OutBaseOffsetInMeters);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::GetBaseRotationAndBaseOffsetInMeters(Z_Param_Out_OutRotation,Z_Param_Out_OutBaseOffsetInMeters);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetBaseRotationAndBaseOffsetInMeters

// Begin Class UOculusXRFunctionLibrary Function GetBaseRotationAndPositionOffset
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics
{
	struct OculusXRFunctionLibrary_eventGetBaseRotationAndPositionOffset_Parms
	{
		FRotator OutRot;
		FVector OutPosOffset;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns current base rotation and position offset.\n\x09 *\n\x09 * @param OutRot\x09\x09\x09(out) Rotator object with base rotation\n\x09 * @param OutPosOffset\x09\x09(out) the vector with previously set position offset.\n\x09 */" },
#endif
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "A hack, proper camera positioning should be used" },
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns current base rotation and position offset.\n\n@param OutRot                        (out) Rotator object with base rotation\n@param OutPosOffset          (out) the vector with previously set position offset." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutRot;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutPosOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics::NewProp_OutRot = { "OutRot", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetBaseRotationAndPositionOffset_Parms, OutRot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics::NewProp_OutPosOffset = { "OutPosOffset", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetBaseRotationAndPositionOffset_Parms, OutPosOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics::NewProp_OutRot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics::NewProp_OutPosOffset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetBaseRotationAndPositionOffset", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics::OculusXRFunctionLibrary_eventGetBaseRotationAndPositionOffset_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics::OculusXRFunctionLibrary_eventGetBaseRotationAndPositionOffset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetBaseRotationAndPositionOffset)
{
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_OutRot);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_OutPosOffset);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::GetBaseRotationAndPositionOffset(Z_Param_Out_OutRot,Z_Param_Out_OutPosOffset);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetBaseRotationAndPositionOffset

// Begin Class UOculusXRFunctionLibrary Function GetControllerType
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics
{
	struct OculusXRFunctionLibrary_eventGetControllerType_Parms
	{
		EControllerHand deviceHand;
		EOculusXRControllerType ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the current controller's type\n\x09 * @param deviceHand\x09\x09\x09\x09(in) The hand to get the position from\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the current controller's type\n@param deviceHand                            (in) The hand to get the position from" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_deviceHand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_deviceHand;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::NewProp_deviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::NewProp_deviceHand = { "deviceHand", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetControllerType_Parms, deviceHand), Z_Construct_UEnum_InputCore_EControllerHand, METADATA_PARAMS(0, nullptr) }; // 775183092
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetControllerType_Parms, ReturnValue), Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerType, METADATA_PARAMS(0, nullptr) }; // 3572997132
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::NewProp_deviceHand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::NewProp_deviceHand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetControllerType", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::OculusXRFunctionLibrary_eventGetControllerType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::OculusXRFunctionLibrary_eventGetControllerType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetControllerType)
{
	P_GET_ENUM(EControllerHand,Z_Param_deviceHand);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EOculusXRControllerType*)Z_Param__Result=UOculusXRFunctionLibrary::GetControllerType(EControllerHand(Z_Param_deviceHand));
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetControllerType

// Begin Class UOculusXRFunctionLibrary Function GetCurrentDisplayFrequency
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency_Statics
{
	struct OculusXRFunctionLibrary_eventGetCurrentDisplayFrequency_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the current display frequency\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the current display frequency" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetCurrentDisplayFrequency_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetCurrentDisplayFrequency", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency_Statics::OculusXRFunctionLibrary_eventGetCurrentDisplayFrequency_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency_Statics::OculusXRFunctionLibrary_eventGetCurrentDisplayFrequency_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetCurrentDisplayFrequency)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UOculusXRFunctionLibrary::GetCurrentDisplayFrequency();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetCurrentDisplayFrequency

// Begin Class UOculusXRFunctionLibrary Function GetDeviceName
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName_Statics
{
	struct OculusXRFunctionLibrary_eventGetDeviceName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "UOculusXRFunctionLibrary::GetDeviceName has been deprecated and no longer functions as before. Please use the enum-based GetDeviceType instead." },
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetDeviceName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetDeviceName", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName_Statics::OculusXRFunctionLibrary_eventGetDeviceName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName_Statics::OculusXRFunctionLibrary_eventGetDeviceName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetDeviceName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UOculusXRFunctionLibrary::GetDeviceName();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetDeviceName

// Begin Class UOculusXRFunctionLibrary Function GetDeviceType
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics
{
	struct OculusXRFunctionLibrary_eventGetDeviceType_Parms
	{
		EOculusXRDeviceType ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetDeviceType_Parms, ReturnValue), Z_Construct_UEnum_OculusXRHMD_EOculusXRDeviceType, METADATA_PARAMS(0, nullptr) }; // 3481782517
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetDeviceType", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics::OculusXRFunctionLibrary_eventGetDeviceType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics::OculusXRFunctionLibrary_eventGetDeviceType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetDeviceType)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EOculusXRDeviceType*)Z_Param__Result=UOculusXRFunctionLibrary::GetDeviceType();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetDeviceType

// Begin Class UOculusXRFunctionLibrary Function GetEyeTrackedFoveatedRenderingSupported
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics
{
	struct OculusXRFunctionLibrary_eventGetEyeTrackedFoveatedRenderingSupported_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns whether eye-tracked foveated rendering is supported or not\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns whether eye-tracked foveated rendering is supported or not" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventGetEyeTrackedFoveatedRenderingSupported_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventGetEyeTrackedFoveatedRenderingSupported_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetEyeTrackedFoveatedRenderingSupported", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics::OculusXRFunctionLibrary_eventGetEyeTrackedFoveatedRenderingSupported_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics::OculusXRFunctionLibrary_eventGetEyeTrackedFoveatedRenderingSupported_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetEyeTrackedFoveatedRenderingSupported)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRFunctionLibrary::GetEyeTrackedFoveatedRenderingSupported();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetEyeTrackedFoveatedRenderingSupported

// Begin Class UOculusXRFunctionLibrary Function GetFoveatedRenderingLevel
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics
{
	struct OculusXRFunctionLibrary_eventGetFoveatedRenderingLevel_Parms
	{
		EOculusXRFoveatedRenderingLevel ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the current multiresolution level\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the current multiresolution level" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetFoveatedRenderingLevel_Parms, ReturnValue), Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingLevel, METADATA_PARAMS(0, nullptr) }; // 2300058379
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetFoveatedRenderingLevel", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics::OculusXRFunctionLibrary_eventGetFoveatedRenderingLevel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics::OculusXRFunctionLibrary_eventGetFoveatedRenderingLevel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetFoveatedRenderingLevel)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EOculusXRFoveatedRenderingLevel*)Z_Param__Result=UOculusXRFunctionLibrary::GetFoveatedRenderingLevel();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetFoveatedRenderingLevel

// Begin Class UOculusXRFunctionLibrary Function GetFoveatedRenderingMethod
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics
{
	struct OculusXRFunctionLibrary_eventGetFoveatedRenderingMethod_Parms
	{
		EOculusXRFoveatedRenderingMethod ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the foveated rendering method currently being used\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the foveated rendering method currently being used" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetFoveatedRenderingMethod_Parms, ReturnValue), Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingMethod, METADATA_PARAMS(0, nullptr) }; // 1262503363
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetFoveatedRenderingMethod", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics::OculusXRFunctionLibrary_eventGetFoveatedRenderingMethod_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics::OculusXRFunctionLibrary_eventGetFoveatedRenderingMethod_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetFoveatedRenderingMethod)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EOculusXRFoveatedRenderingMethod*)Z_Param__Result=UOculusXRFunctionLibrary::GetFoveatedRenderingMethod();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetFoveatedRenderingMethod

// Begin Class UOculusXRFunctionLibrary Function GetGPUFrameTime
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime_Statics
{
	struct OculusXRFunctionLibrary_eventGetGPUFrameTime_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the GPU frame time on supported mobile platforms (Go for now)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the GPU frame time on supported mobile platforms (Go for now)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetGPUFrameTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetGPUFrameTime", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime_Statics::OculusXRFunctionLibrary_eventGetGPUFrameTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime_Statics::OculusXRFunctionLibrary_eventGetGPUFrameTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetGPUFrameTime)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UOculusXRFunctionLibrary::GetGPUFrameTime();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetGPUFrameTime

// Begin Class UOculusXRFunctionLibrary Function GetGPUUtilization
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics
{
	struct OculusXRFunctionLibrary_eventGetGPUUtilization_Parms
	{
		bool IsGPUAvailable;
		float GPUUtilization;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the GPU utilization availability and value\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the GPU utilization availability and value" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_IsGPUAvailable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsGPUAvailable;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GPUUtilization;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::NewProp_IsGPUAvailable_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventGetGPUUtilization_Parms*)Obj)->IsGPUAvailable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::NewProp_IsGPUAvailable = { "IsGPUAvailable", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventGetGPUUtilization_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::NewProp_IsGPUAvailable_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::NewProp_GPUUtilization = { "GPUUtilization", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetGPUUtilization_Parms, GPUUtilization), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::NewProp_IsGPUAvailable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::NewProp_GPUUtilization,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetGPUUtilization", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::OculusXRFunctionLibrary_eventGetGPUUtilization_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::OculusXRFunctionLibrary_eventGetGPUUtilization_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetGPUUtilization)
{
	P_GET_UBOOL_REF(Z_Param_Out_IsGPUAvailable);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_GPUUtilization);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::GetGPUUtilization(Z_Param_Out_IsGPUAvailable,Z_Param_Out_GPUUtilization);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetGPUUtilization

// Begin Class UOculusXRFunctionLibrary Function GetGuardianDimensions
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics
{
	struct OculusXRFunctionLibrary_eventGetGuardianDimensions_Parms
	{
		EOculusXRBoundaryType BoundaryType;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Guardian" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the dimensions in UE world space of the requested Boundary Type\n\x09 * @param BoundaryType\x09\x09\x09(in) An enum representing the boundary type requested, either Outer Boundary (exact guardian bounds) or PlayArea (rectangle inside the Outer Boundary)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the dimensions in UE world space of the requested Boundary Type\n@param BoundaryType                  (in) An enum representing the boundary type requested, either Outer Boundary (exact guardian bounds) or PlayArea (rectangle inside the Outer Boundary)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_BoundaryType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BoundaryType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::NewProp_BoundaryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::NewProp_BoundaryType = { "BoundaryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetGuardianDimensions_Parms, BoundaryType), Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType, METADATA_PARAMS(0, nullptr) }; // 3419051359
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetGuardianDimensions_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::NewProp_BoundaryType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::NewProp_BoundaryType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetGuardianDimensions", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::OculusXRFunctionLibrary_eventGetGuardianDimensions_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::OculusXRFunctionLibrary_eventGetGuardianDimensions_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetGuardianDimensions)
{
	P_GET_ENUM(EOculusXRBoundaryType,Z_Param_BoundaryType);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=UOculusXRFunctionLibrary::GetGuardianDimensions(EOculusXRBoundaryType(Z_Param_BoundaryType));
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetGuardianDimensions

// Begin Class UOculusXRFunctionLibrary Function GetGuardianPoints
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics
{
	struct OculusXRFunctionLibrary_eventGetGuardianPoints_Parms
	{
		EOculusXRBoundaryType BoundaryType;
		bool UsePawnSpace;
		TArray<FVector> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Guardian" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the list of points in UE world space of the requested Boundary Type\n\x09 * @param BoundaryType\x09\x09\x09(in) An enum representing the boundary type requested, either Outer Boundary (exact guardian bounds) or PlayArea (rectangle inside the Outer Boundary)\n\x09 * @param UsePawnSpace\x09\x09\x09(in) Boolean indicating to return the points in world space or pawn space\n\x09 */" },
#endif
		{ "CPP_Default_UsePawnSpace", "false" },
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the list of points in UE world space of the requested Boundary Type\n@param BoundaryType                  (in) An enum representing the boundary type requested, either Outer Boundary (exact guardian bounds) or PlayArea (rectangle inside the Outer Boundary)\n@param UsePawnSpace                  (in) Boolean indicating to return the points in world space or pawn space" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_BoundaryType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BoundaryType;
	static void NewProp_UsePawnSpace_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_UsePawnSpace;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::NewProp_BoundaryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::NewProp_BoundaryType = { "BoundaryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetGuardianPoints_Parms, BoundaryType), Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType, METADATA_PARAMS(0, nullptr) }; // 3419051359
void Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::NewProp_UsePawnSpace_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventGetGuardianPoints_Parms*)Obj)->UsePawnSpace = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::NewProp_UsePawnSpace = { "UsePawnSpace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventGetGuardianPoints_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::NewProp_UsePawnSpace_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetGuardianPoints_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::NewProp_BoundaryType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::NewProp_BoundaryType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::NewProp_UsePawnSpace,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetGuardianPoints", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::OculusXRFunctionLibrary_eventGetGuardianPoints_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::OculusXRFunctionLibrary_eventGetGuardianPoints_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetGuardianPoints)
{
	P_GET_ENUM(EOculusXRBoundaryType,Z_Param_BoundaryType);
	P_GET_UBOOL(Z_Param_UsePawnSpace);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FVector>*)Z_Param__Result=UOculusXRFunctionLibrary::GetGuardianPoints(EOculusXRBoundaryType(Z_Param_BoundaryType),Z_Param_UsePawnSpace);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetGuardianPoints

// Begin Class UOculusXRFunctionLibrary Function GetHmdColorDesc
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics
{
	struct OculusXRFunctionLibrary_eventGetHmdColorDesc_Parms
	{
		EOculusXRColorSpace ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the color space of the target HMD\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the color space of the target HMD" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetHmdColorDesc_Parms, ReturnValue), Z_Construct_UEnum_OculusXRHMD_EOculusXRColorSpace, METADATA_PARAMS(0, nullptr) }; // 2401649762
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetHmdColorDesc", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics::OculusXRFunctionLibrary_eventGetHmdColorDesc_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics::OculusXRFunctionLibrary_eventGetHmdColorDesc_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetHmdColorDesc)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EOculusXRColorSpace*)Z_Param__Result=UOculusXRFunctionLibrary::GetHmdColorDesc();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetHmdColorDesc

// Begin Class UOculusXRFunctionLibrary Function GetNodeGuardianIntersection
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics
{
	struct OculusXRFunctionLibrary_eventGetNodeGuardianIntersection_Parms
	{
		EOculusXRTrackedDeviceType DeviceType;
		EOculusXRBoundaryType BoundaryType;
		FOculusXRGuardianTestResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Guardian" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the intersection result between a tracked device (HMD or controllers) and a guardian boundary\n\x09 * @param DeviceType             (in) Tracked Device type to test against guardian boundaries\n\x09 * @param BoundaryType\x09\x09\x09(in) An enum representing the boundary type requested, either Outer Boundary (exact guardian bounds) or PlayArea (rectangle inside the Outer Boundary)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the intersection result between a tracked device (HMD or controllers) and a guardian boundary\n@param DeviceType             (in) Tracked Device type to test against guardian boundaries\n@param BoundaryType                  (in) An enum representing the boundary type requested, either Outer Boundary (exact guardian bounds) or PlayArea (rectangle inside the Outer Boundary)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BoundaryType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BoundaryType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::NewProp_DeviceType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::NewProp_DeviceType = { "DeviceType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetNodeGuardianIntersection_Parms, DeviceType), Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType, METADATA_PARAMS(0, nullptr) }; // 2225433783
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::NewProp_BoundaryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::NewProp_BoundaryType = { "BoundaryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetNodeGuardianIntersection_Parms, BoundaryType), Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType, METADATA_PARAMS(0, nullptr) }; // 3419051359
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetNodeGuardianIntersection_Parms, ReturnValue), Z_Construct_UScriptStruct_FOculusXRGuardianTestResult, METADATA_PARAMS(0, nullptr) }; // 2633819891
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::NewProp_DeviceType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::NewProp_DeviceType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::NewProp_BoundaryType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::NewProp_BoundaryType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetNodeGuardianIntersection", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::OculusXRFunctionLibrary_eventGetNodeGuardianIntersection_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::OculusXRFunctionLibrary_eventGetNodeGuardianIntersection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetNodeGuardianIntersection)
{
	P_GET_ENUM(EOculusXRTrackedDeviceType,Z_Param_DeviceType);
	P_GET_ENUM(EOculusXRBoundaryType,Z_Param_BoundaryType);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FOculusXRGuardianTestResult*)Z_Param__Result=UOculusXRFunctionLibrary::GetNodeGuardianIntersection(EOculusXRTrackedDeviceType(Z_Param_DeviceType),EOculusXRBoundaryType(Z_Param_BoundaryType));
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetNodeGuardianIntersection

// Begin Class UOculusXRFunctionLibrary Function GetPerformanceMetrics
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics_Statics
{
	struct OculusXRFunctionLibrary_eventGetPerformanceMetrics_Parms
	{
		FOculusXRPerformanceMetrics PerformanceMetrics;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the performance metrics\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the performance metrics" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PerformanceMetrics;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics_Statics::NewProp_PerformanceMetrics = { "PerformanceMetrics", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetPerformanceMetrics_Parms, PerformanceMetrics), Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics, METADATA_PARAMS(0, nullptr) }; // 2824172626
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics_Statics::NewProp_PerformanceMetrics,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetPerformanceMetrics", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics_Statics::OculusXRFunctionLibrary_eventGetPerformanceMetrics_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics_Statics::OculusXRFunctionLibrary_eventGetPerformanceMetrics_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetPerformanceMetrics)
{
	P_GET_STRUCT_REF(FOculusXRPerformanceMetrics,Z_Param_Out_PerformanceMetrics);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::GetPerformanceMetrics(Z_Param_Out_PerformanceMetrics);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetPerformanceMetrics

// Begin Class UOculusXRFunctionLibrary Function GetPlayAreaTransform
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform_Statics
{
	struct OculusXRFunctionLibrary_eventGetPlayAreaTransform_Parms
	{
		FTransform ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Guardian" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns the transform of the play area rectangle, defining its position, rotation and scale to apply to a unit cube to match it with the play area.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the transform of the play area rectangle, defining its position, rotation and scale to apply to a unit cube to match it with the play area." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetPlayAreaTransform_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetPlayAreaTransform", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform_Statics::OculusXRFunctionLibrary_eventGetPlayAreaTransform_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform_Statics::OculusXRFunctionLibrary_eventGetPlayAreaTransform_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetPlayAreaTransform)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTransform*)Z_Param__Result=UOculusXRFunctionLibrary::GetPlayAreaTransform();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetPlayAreaTransform

// Begin Class UOculusXRFunctionLibrary Function GetPointGuardianIntersection
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics
{
	struct OculusXRFunctionLibrary_eventGetPointGuardianIntersection_Parms
	{
		FVector Point;
		EOculusXRBoundaryType BoundaryType;
		FOculusXRGuardianTestResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Guardian" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the intersection result between a UE4 coordinate and a guardian boundary\n\x09 * @param Point\x09\x09\x09\x09\x09(in) Point in UE space to test against guardian boundaries\n\x09 * @param BoundaryType\x09\x09\x09(in) An enum representing the boundary type requested, either Outer Boundary (exact guardian bounds) or PlayArea (rectangle inside the Outer Boundary)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the intersection result between a UE4 coordinate and a guardian boundary\n@param Point                                 (in) Point in UE space to test against guardian boundaries\n@param BoundaryType                  (in) An enum representing the boundary type requested, either Outer Boundary (exact guardian bounds) or PlayArea (rectangle inside the Outer Boundary)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Point_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Point;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BoundaryType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BoundaryType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::NewProp_Point = { "Point", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetPointGuardianIntersection_Parms, Point), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Point_MetaData), NewProp_Point_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::NewProp_BoundaryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::NewProp_BoundaryType = { "BoundaryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetPointGuardianIntersection_Parms, BoundaryType), Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType, METADATA_PARAMS(0, nullptr) }; // 3419051359
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetPointGuardianIntersection_Parms, ReturnValue), Z_Construct_UScriptStruct_FOculusXRGuardianTestResult, METADATA_PARAMS(0, nullptr) }; // 2633819891
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::NewProp_Point,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::NewProp_BoundaryType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::NewProp_BoundaryType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetPointGuardianIntersection", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::OculusXRFunctionLibrary_eventGetPointGuardianIntersection_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::OculusXRFunctionLibrary_eventGetPointGuardianIntersection_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetPointGuardianIntersection)
{
	P_GET_STRUCT(FVector,Z_Param_Point);
	P_GET_ENUM(EOculusXRBoundaryType,Z_Param_BoundaryType);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FOculusXRGuardianTestResult*)Z_Param__Result=UOculusXRFunctionLibrary::GetPointGuardianIntersection(Z_Param_Point,EOculusXRBoundaryType(Z_Param_BoundaryType));
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetPointGuardianIntersection

// Begin Class UOculusXRFunctionLibrary Function GetPose
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics
{
	struct OculusXRFunctionLibrary_eventGetPose_Parms
	{
		FRotator DeviceRotation;
		FVector DevicePosition;
		FVector NeckPosition;
		bool bUseOrienationForPlayerCamera;
		bool bUsePositionForPlayerCamera;
		FVector PositionScale;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Grabs the current orientation and position for the HMD.  If positional tracking is not available, DevicePosition will be a zero vector\n\x09 *\n\x09 * @param DeviceRotation\x09(out) The device's current rotation\n\x09 * @param DevicePosition\x09(out) The device's current position, in its own tracking space\n\x09 * @param NeckPosition\x09\x09(out) The estimated neck position, calculated using NeckToEye vector from User Profile. Same coordinate space as DevicePosition.\n\x09 * @param bUseOrienationForPlayerCamera\x09(in) Should be set to 'true' if the orientation is going to be used to update orientation of the camera manually.\n\x09 * @param bUsePositionForPlayerCamera\x09(in) Should be set to 'true' if the position is going to be used to update position of the camera manually.\n\x09 * @param PositionScale\x09\x09(in) The 3D scale that will be applied to position.\n\x09 */" },
#endif
		{ "CPP_Default_bUseOrienationForPlayerCamera", "false" },
		{ "CPP_Default_bUsePositionForPlayerCamera", "false" },
		{ "CPP_Default_PositionScale", "" },
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Grabs the current orientation and position for the HMD.  If positional tracking is not available, DevicePosition will be a zero vector\n\n@param DeviceRotation        (out) The device's current rotation\n@param DevicePosition        (out) The device's current position, in its own tracking space\n@param NeckPosition          (out) The estimated neck position, calculated using NeckToEye vector from User Profile. Same coordinate space as DevicePosition.\n@param bUseOrienationForPlayerCamera (in) Should be set to 'true' if the orientation is going to be used to update orientation of the camera manually.\n@param bUsePositionForPlayerCamera   (in) Should be set to 'true' if the position is going to be used to update position of the camera manually.\n@param PositionScale         (in) The 3D scale that will be applied to position." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionScale_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_DeviceRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DevicePosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NeckPosition;
	static void NewProp_bUseOrienationForPlayerCamera_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseOrienationForPlayerCamera;
	static void NewProp_bUsePositionForPlayerCamera_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUsePositionForPlayerCamera;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PositionScale;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_DeviceRotation = { "DeviceRotation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetPose_Parms, DeviceRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_DevicePosition = { "DevicePosition", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetPose_Parms, DevicePosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_NeckPosition = { "NeckPosition", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetPose_Parms, NeckPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_bUseOrienationForPlayerCamera_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventGetPose_Parms*)Obj)->bUseOrienationForPlayerCamera = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_bUseOrienationForPlayerCamera = { "bUseOrienationForPlayerCamera", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventGetPose_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_bUseOrienationForPlayerCamera_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_bUsePositionForPlayerCamera_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventGetPose_Parms*)Obj)->bUsePositionForPlayerCamera = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_bUsePositionForPlayerCamera = { "bUsePositionForPlayerCamera", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventGetPose_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_bUsePositionForPlayerCamera_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_PositionScale = { "PositionScale", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetPose_Parms, PositionScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionScale_MetaData), NewProp_PositionScale_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_DeviceRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_DevicePosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_NeckPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_bUseOrienationForPlayerCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_bUsePositionForPlayerCamera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::NewProp_PositionScale,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetPose", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::OculusXRFunctionLibrary_eventGetPose_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::OculusXRFunctionLibrary_eventGetPose_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetPose)
{
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_DeviceRotation);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_DevicePosition);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_NeckPosition);
	P_GET_UBOOL(Z_Param_bUseOrienationForPlayerCamera);
	P_GET_UBOOL(Z_Param_bUsePositionForPlayerCamera);
	P_GET_STRUCT(FVector,Z_Param_PositionScale);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::GetPose(Z_Param_Out_DeviceRotation,Z_Param_Out_DevicePosition,Z_Param_Out_NeckPosition,Z_Param_bUseOrienationForPlayerCamera,Z_Param_bUsePositionForPlayerCamera,Z_Param_PositionScale);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetPose

// Begin Class UOculusXRFunctionLibrary Function GetRawSensorData
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics
{
	struct OculusXRFunctionLibrary_eventGetRawSensorData_Parms
	{
		FVector AngularAcceleration;
		FVector LinearAcceleration;
		FVector AngularVelocity;
		FVector LinearVelocity;
		float TimeInSeconds;
		EOculusXRTrackedDeviceType DeviceType;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Reports raw sensor data. If HMD doesn't support any of the parameters then it will be set to zero.\n\x09 *\n\x09 * @param AngularAcceleration\x09(out) Angular acceleration in radians per second per second.\n\x09 * @param LinearAcceleration\x09\x09(out) Acceleration in meters per second per second.\n\x09 * @param AngularVelocity\x09\x09(out) Angular velocity in radians per second.\n\x09 * @param LinearVelocity\x09\x09\x09(out) Velocity in meters per second.\n\x09 * @param TimeInSeconds\x09\x09\x09(out) Time when the reported IMU reading took place, in seconds.\n\x09 */" },
#endif
		{ "CPP_Default_DeviceType", "HMD" },
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reports raw sensor data. If HMD doesn't support any of the parameters then it will be set to zero.\n\n@param AngularAcceleration   (out) Angular acceleration in radians per second per second.\n@param LinearAcceleration            (out) Acceleration in meters per second per second.\n@param AngularVelocity               (out) Angular velocity in radians per second.\n@param LinearVelocity                        (out) Velocity in meters per second.\n@param TimeInSeconds                 (out) Time when the reported IMU reading took place, in seconds." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_AngularAcceleration;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LinearAcceleration;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AngularVelocity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LinearVelocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeInSeconds;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::NewProp_AngularAcceleration = { "AngularAcceleration", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetRawSensorData_Parms, AngularAcceleration), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::NewProp_LinearAcceleration = { "LinearAcceleration", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetRawSensorData_Parms, LinearAcceleration), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::NewProp_AngularVelocity = { "AngularVelocity", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetRawSensorData_Parms, AngularVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::NewProp_LinearVelocity = { "LinearVelocity", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetRawSensorData_Parms, LinearVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::NewProp_TimeInSeconds = { "TimeInSeconds", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetRawSensorData_Parms, TimeInSeconds), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::NewProp_DeviceType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::NewProp_DeviceType = { "DeviceType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetRawSensorData_Parms, DeviceType), Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType, METADATA_PARAMS(0, nullptr) }; // 2225433783
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::NewProp_AngularAcceleration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::NewProp_LinearAcceleration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::NewProp_AngularVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::NewProp_LinearVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::NewProp_TimeInSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::NewProp_DeviceType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::NewProp_DeviceType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetRawSensorData", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::OculusXRFunctionLibrary_eventGetRawSensorData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::OculusXRFunctionLibrary_eventGetRawSensorData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetRawSensorData)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_AngularAcceleration);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_LinearAcceleration);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_AngularVelocity);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_LinearVelocity);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_TimeInSeconds);
	P_GET_ENUM(EOculusXRTrackedDeviceType,Z_Param_DeviceType);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::GetRawSensorData(Z_Param_Out_AngularAcceleration,Z_Param_Out_LinearAcceleration,Z_Param_Out_AngularVelocity,Z_Param_Out_LinearVelocity,Z_Param_Out_TimeInSeconds,EOculusXRTrackedDeviceType(Z_Param_DeviceType));
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetRawSensorData

// Begin Class UOculusXRFunctionLibrary Function GetSuggestedCpuAndGpuPerformanceLevels
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics
{
	struct OculusXRFunctionLibrary_eventGetSuggestedCpuAndGpuPerformanceLevels_Parms
	{
		EOculusXRProcessorPerformanceLevel CpuPerfLevel;
		EOculusXRProcessorPerformanceLevel GpuPerfLevel;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the suggested CPU and GPU levels to the Oculus device.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the suggested CPU and GPU levels to the Oculus device." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_CpuPerfLevel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CpuPerfLevel;
	static const UECodeGen_Private::FBytePropertyParams NewProp_GpuPerfLevel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_GpuPerfLevel;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_CpuPerfLevel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_CpuPerfLevel = { "CpuPerfLevel", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetSuggestedCpuAndGpuPerformanceLevels_Parms, CpuPerfLevel), Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel, METADATA_PARAMS(0, nullptr) }; // 1326426722
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_GpuPerfLevel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_GpuPerfLevel = { "GpuPerfLevel", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetSuggestedCpuAndGpuPerformanceLevels_Parms, GpuPerfLevel), Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel, METADATA_PARAMS(0, nullptr) }; // 1326426722
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_CpuPerfLevel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_CpuPerfLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_GpuPerfLevel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_GpuPerfLevel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetSuggestedCpuAndGpuPerformanceLevels", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::OculusXRFunctionLibrary_eventGetSuggestedCpuAndGpuPerformanceLevels_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::OculusXRFunctionLibrary_eventGetSuggestedCpuAndGpuPerformanceLevels_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetSuggestedCpuAndGpuPerformanceLevels)
{
	P_GET_ENUM_REF(EOculusXRProcessorPerformanceLevel,Z_Param_Out_CpuPerfLevel);
	P_GET_ENUM_REF(EOculusXRProcessorPerformanceLevel,Z_Param_Out_GpuPerfLevel);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::GetSuggestedCpuAndGpuPerformanceLevels((EOculusXRProcessorPerformanceLevel&)(Z_Param_Out_CpuPerfLevel),(EOculusXRProcessorPerformanceLevel&)(Z_Param_Out_GpuPerfLevel));
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetSuggestedCpuAndGpuPerformanceLevels

// Begin Class UOculusXRFunctionLibrary Function GetSystemHmd3DofModeEnabled
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics
{
	struct OculusXRFunctionLibrary_eventGetSystemHmd3DofModeEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns true if system headset is in 3dof mode\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns true if system headset is in 3dof mode" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventGetSystemHmd3DofModeEnabled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventGetSystemHmd3DofModeEnabled_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetSystemHmd3DofModeEnabled", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics::OculusXRFunctionLibrary_eventGetSystemHmd3DofModeEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics::OculusXRFunctionLibrary_eventGetSystemHmd3DofModeEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetSystemHmd3DofModeEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRFunctionLibrary::GetSystemHmd3DofModeEnabled();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetSystemHmd3DofModeEnabled

// Begin Class UOculusXRFunctionLibrary Function GetUserProfile
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics
{
	struct OculusXRFunctionLibrary_eventGetUserProfile_Parms
	{
		FOculusXRHmdUserProfile Profile;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns current user profile.\n\x09 *\n\x09 * @param Profile\x09\x09(out) Structure to hold current user profile.\n\x09 * @return (boolean)\x09True, if user profile was acquired.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns current user profile.\n\n@param Profile               (out) Structure to hold current user profile.\n@return (boolean)    True, if user profile was acquired." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Profile;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::NewProp_Profile = { "Profile", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventGetUserProfile_Parms, Profile), Z_Construct_UScriptStruct_FOculusXRHmdUserProfile, METADATA_PARAMS(0, nullptr) }; // 1594008665
void Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventGetUserProfile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventGetUserProfile_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::NewProp_Profile,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "GetUserProfile", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::OculusXRFunctionLibrary_eventGetUserProfile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::OculusXRFunctionLibrary_eventGetUserProfile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execGetUserProfile)
{
	P_GET_STRUCT_REF(FOculusXRHmdUserProfile,Z_Param_Out_Profile);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRFunctionLibrary::GetUserProfile(Z_Param_Out_Profile);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function GetUserProfile

// Begin Class UOculusXRFunctionLibrary Function HasInputFocus
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics
{
	struct OculusXRFunctionLibrary_eventHasInputFocus_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns true, if the app has input focus.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns true, if the app has input focus." },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventHasInputFocus_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventHasInputFocus_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "HasInputFocus", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics::OculusXRFunctionLibrary_eventHasInputFocus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics::OculusXRFunctionLibrary_eventHasInputFocus_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execHasInputFocus)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRFunctionLibrary::HasInputFocus();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function HasInputFocus

// Begin Class UOculusXRFunctionLibrary Function HasSystemOverlayPresent
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics
{
	struct OculusXRFunctionLibrary_eventHasSystemOverlayPresent_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns true, if the system overlay is present.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns true, if the system overlay is present." },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventHasSystemOverlayPresent_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventHasSystemOverlayPresent_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "HasSystemOverlayPresent", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics::OculusXRFunctionLibrary_eventHasSystemOverlayPresent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics::OculusXRFunctionLibrary_eventHasSystemOverlayPresent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execHasSystemOverlayPresent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRFunctionLibrary::HasSystemOverlayPresent();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function HasSystemOverlayPresent

// Begin Class UOculusXRFunctionLibrary Function IsColorPassthroughSupported
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics
{
	struct OculusXRFunctionLibrary_eventIsColorPassthroughSupported_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Checks if color passthrough is supported\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Checks if color passthrough is supported" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventIsColorPassthroughSupported_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventIsColorPassthroughSupported_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "IsColorPassthroughSupported", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics::OculusXRFunctionLibrary_eventIsColorPassthroughSupported_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics::OculusXRFunctionLibrary_eventIsColorPassthroughSupported_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execIsColorPassthroughSupported)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRFunctionLibrary::IsColorPassthroughSupported();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function IsColorPassthroughSupported

// Begin Class UOculusXRFunctionLibrary Function IsDeviceTracked
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics
{
	struct OculusXRFunctionLibrary_eventIsDeviceTracked_Parms
	{
		EOculusXRTrackedDeviceType DeviceType;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns if the device is currently tracked by the runtime or not.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns if the device is currently tracked by the runtime or not." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceType;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::NewProp_DeviceType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::NewProp_DeviceType = { "DeviceType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventIsDeviceTracked_Parms, DeviceType), Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType, METADATA_PARAMS(0, nullptr) }; // 2225433783
void Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventIsDeviceTracked_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventIsDeviceTracked_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::NewProp_DeviceType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::NewProp_DeviceType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "IsDeviceTracked", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::OculusXRFunctionLibrary_eventIsDeviceTracked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::OculusXRFunctionLibrary_eventIsDeviceTracked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execIsDeviceTracked)
{
	P_GET_ENUM(EOculusXRTrackedDeviceType,Z_Param_DeviceType);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRFunctionLibrary::IsDeviceTracked(EOculusXRTrackedDeviceType(Z_Param_DeviceType));
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function IsDeviceTracked

// Begin Class UOculusXRFunctionLibrary Function IsEnvironmentDepthStarted
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics
{
	struct OculusXRFunctionLibrary_eventIsEnvironmentDepthStarted_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns true if StartEnvironmentDepth() has been called and is currently running.\n\x09 * If called right after calling StartEnvironmentDepth() it'll return false as it needs some time for EnvironmentDepth to start\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns true if StartEnvironmentDepth() has been called and is currently running.\nIf called right after calling StartEnvironmentDepth() it'll return false as it needs some time for EnvironmentDepth to start" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventIsEnvironmentDepthStarted_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventIsEnvironmentDepthStarted_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "IsEnvironmentDepthStarted", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics::OculusXRFunctionLibrary_eventIsEnvironmentDepthStarted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics::OculusXRFunctionLibrary_eventIsEnvironmentDepthStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execIsEnvironmentDepthStarted)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRFunctionLibrary::IsEnvironmentDepthStarted();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function IsEnvironmentDepthStarted

// Begin Class UOculusXRFunctionLibrary Function IsGuardianConfigured
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics
{
	struct OculusXRFunctionLibrary_eventIsGuardianConfigured_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Guardian" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns true if the Guardian has been set up by the user, false if the user is in \"seated\" mode and has not set up a play space.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns true if the Guardian has been set up by the user, false if the user is in \"seated\" mode and has not set up a play space." },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventIsGuardianConfigured_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventIsGuardianConfigured_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "IsGuardianConfigured", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics::OculusXRFunctionLibrary_eventIsGuardianConfigured_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics::OculusXRFunctionLibrary_eventIsGuardianConfigured_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execIsGuardianConfigured)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRFunctionLibrary::IsGuardianConfigured();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function IsGuardianConfigured

// Begin Class UOculusXRFunctionLibrary Function IsGuardianDisplayed
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics
{
	struct OculusXRFunctionLibrary_eventIsGuardianDisplayed_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Guardian" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Returns true if the Guardian Outer Boundary is being displayed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns true if the Guardian Outer Boundary is being displayed" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventIsGuardianDisplayed_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventIsGuardianDisplayed_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "IsGuardianDisplayed", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics::OculusXRFunctionLibrary_eventIsGuardianDisplayed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics::OculusXRFunctionLibrary_eventIsGuardianDisplayed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execIsGuardianDisplayed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRFunctionLibrary::IsGuardianDisplayed();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function IsGuardianDisplayed

// Begin Class UOculusXRFunctionLibrary Function IsPassthroughRecommended
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics
{
	struct OculusXRFunctionLibrary_eventIsPassthroughRecommended_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get a system recommendation on whether Passthrough should be active.\n\x09 * When set, it is recommended for apps which optionally support an MR experience\n\x09 * with Passthrough to default to that mode.\n\x09 * Currently, this is determined based on whether the user has Passthrough active in the home environment.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get a system recommendation on whether Passthrough should be active.\nWhen set, it is recommended for apps which optionally support an MR experience\nwith Passthrough to default to that mode.\nCurrently, this is determined based on whether the user has Passthrough active in the home environment." },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventIsPassthroughRecommended_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventIsPassthroughRecommended_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "IsPassthroughRecommended", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics::OculusXRFunctionLibrary_eventIsPassthroughRecommended_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics::OculusXRFunctionLibrary_eventIsPassthroughRecommended_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execIsPassthroughRecommended)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRFunctionLibrary::IsPassthroughRecommended();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function IsPassthroughRecommended

// Begin Class UOculusXRFunctionLibrary Function IsPassthroughSupported
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics
{
	struct OculusXRFunctionLibrary_eventIsPassthroughSupported_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Checks if passthrough is supported\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Checks if passthrough is supported" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventIsPassthroughSupported_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventIsPassthroughSupported_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "IsPassthroughSupported", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics::OculusXRFunctionLibrary_eventIsPassthroughSupported_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics::OculusXRFunctionLibrary_eventIsPassthroughSupported_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execIsPassthroughSupported)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRFunctionLibrary::IsPassthroughSupported();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function IsPassthroughSupported

// Begin Class UOculusXRFunctionLibrary Function SetBaseRotationAndBaseOffsetInMeters
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics
{
	struct OculusXRFunctionLibrary_eventSetBaseRotationAndBaseOffsetInMeters_Parms
	{
		FRotator Rotation;
		FVector BaseOffsetInMeters;
		TEnumAsByte<EOrientPositionSelector::Type> Options;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets 'base rotation' - the rotation that will be subtracted from\n\x09 * the actual HMD orientation.\n\x09 * Sets base position offset (in meters). The base position offset is the distance from the physical (0, 0, 0) position\n\x09 * to current HMD position (bringing the (0, 0, 0) point to the current HMD position)\n\x09 * Note, this vector is set by ResetPosition call; use this method with care.\n\x09 * The axis of the vector are the same as in Unreal: X - forward, Y - right, Z - up.\n\x09 *\n\x09 * @param Rotation\x09\x09\x09(in) Rotator object with base rotation\n\x09 * @param BaseOffsetInMeters (in) the vector to be set as base offset, in meters.\n\x09 * @param Options\x09\x09\x09(in) specifies either position, orientation or both should be set.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets 'base rotation' - the rotation that will be subtracted from\nthe actual HMD orientation.\nSets base position offset (in meters). The base position offset is the distance from the physical (0, 0, 0) position\nto current HMD position (bringing the (0, 0, 0) point to the current HMD position)\nNote, this vector is set by ResetPosition call; use this method with care.\nThe axis of the vector are the same as in Unreal: X - forward, Y - right, Z - up.\n\n@param Rotation                      (in) Rotator object with base rotation\n@param BaseOffsetInMeters (in) the vector to be set as base offset, in meters.\n@param Options                       (in) specifies either position, orientation or both should be set." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BaseOffsetInMeters;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Options;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetBaseRotationAndBaseOffsetInMeters_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_BaseOffsetInMeters = { "BaseOffsetInMeters", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetBaseRotationAndBaseOffsetInMeters_Parms, BaseOffsetInMeters), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_Options = { "Options", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetBaseRotationAndBaseOffsetInMeters_Parms, Options), Z_Construct_UEnum_HeadMountedDisplay_EOrientPositionSelector, METADATA_PARAMS(0, nullptr) }; // 3091753543
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_Rotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_BaseOffsetInMeters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_Options,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetBaseRotationAndBaseOffsetInMeters", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::OculusXRFunctionLibrary_eventSetBaseRotationAndBaseOffsetInMeters_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::OculusXRFunctionLibrary_eventSetBaseRotationAndBaseOffsetInMeters_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetBaseRotationAndBaseOffsetInMeters)
{
	P_GET_STRUCT(FRotator,Z_Param_Rotation);
	P_GET_STRUCT(FVector,Z_Param_BaseOffsetInMeters);
	P_GET_PROPERTY(FByteProperty,Z_Param_Options);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetBaseRotationAndBaseOffsetInMeters(Z_Param_Rotation,Z_Param_BaseOffsetInMeters,EOrientPositionSelector::Type(Z_Param_Options));
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetBaseRotationAndBaseOffsetInMeters

// Begin Class UOculusXRFunctionLibrary Function SetBaseRotationAndPositionOffset
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics
{
	struct OculusXRFunctionLibrary_eventSetBaseRotationAndPositionOffset_Parms
	{
		FRotator BaseRot;
		FVector PosOffset;
		TEnumAsByte<EOrientPositionSelector::Type> Options;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets 'base rotation' - the rotation that will be subtracted from\n\x09 * the actual HMD orientation.\n\x09 * The position offset might be added to current HMD position,\n\x09 * effectively moving the virtual camera by the specified offset. The addition\n\x09 * occurs after the HMD orientation and position are applied.\n\x09 *\n\x09 * @param BaseRot\x09\x09\x09(in) Rotator object with base rotation\n\x09 * @param PosOffset\x09\x09\x09(in) the vector to be added to HMD position.\n\x09 * @param Options\x09\x09\x09(in) specifies either position, orientation or both should be set.\n\x09 */" },
#endif
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "A hack, proper camera positioning should be used" },
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets 'base rotation' - the rotation that will be subtracted from\nthe actual HMD orientation.\nThe position offset might be added to current HMD position,\neffectively moving the virtual camera by the specified offset. The addition\noccurs after the HMD orientation and position are applied.\n\n@param BaseRot                       (in) Rotator object with base rotation\n@param PosOffset                     (in) the vector to be added to HMD position.\n@param Options                       (in) specifies either position, orientation or both should be set." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_BaseRot;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PosOffset;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Options;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::NewProp_BaseRot = { "BaseRot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetBaseRotationAndPositionOffset_Parms, BaseRot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::NewProp_PosOffset = { "PosOffset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetBaseRotationAndPositionOffset_Parms, PosOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::NewProp_Options = { "Options", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetBaseRotationAndPositionOffset_Parms, Options), Z_Construct_UEnum_HeadMountedDisplay_EOrientPositionSelector, METADATA_PARAMS(0, nullptr) }; // 3091753543
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::NewProp_BaseRot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::NewProp_PosOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::NewProp_Options,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetBaseRotationAndPositionOffset", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::OculusXRFunctionLibrary_eventSetBaseRotationAndPositionOffset_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::OculusXRFunctionLibrary_eventSetBaseRotationAndPositionOffset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetBaseRotationAndPositionOffset)
{
	P_GET_STRUCT(FRotator,Z_Param_BaseRot);
	P_GET_STRUCT(FVector,Z_Param_PosOffset);
	P_GET_PROPERTY(FByteProperty,Z_Param_Options);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetBaseRotationAndPositionOffset(Z_Param_BaseRot,Z_Param_PosOffset,EOrientPositionSelector::Type(Z_Param_Options));
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetBaseRotationAndPositionOffset

// Begin Class UOculusXRFunctionLibrary Function SetClientColorDesc
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics
{
	struct OculusXRFunctionLibrary_eventSetClientColorDesc_Parms
	{
		EOculusXRColorSpace ColorSpace;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets the target HMD to do color space correction to a specific color space\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the target HMD to do color space correction to a specific color space" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ColorSpace_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ColorSpace;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics::NewProp_ColorSpace_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics::NewProp_ColorSpace = { "ColorSpace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetClientColorDesc_Parms, ColorSpace), Z_Construct_UEnum_OculusXRHMD_EOculusXRColorSpace, METADATA_PARAMS(0, nullptr) }; // 2401649762
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics::NewProp_ColorSpace_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics::NewProp_ColorSpace,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetClientColorDesc", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics::OculusXRFunctionLibrary_eventSetClientColorDesc_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics::OculusXRFunctionLibrary_eventSetClientColorDesc_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetClientColorDesc)
{
	P_GET_ENUM(EOculusXRColorSpace,Z_Param_ColorSpace);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetClientColorDesc(EOculusXRColorSpace(Z_Param_ColorSpace));
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetClientColorDesc

// Begin Class UOculusXRFunctionLibrary Function SetColorScaleAndOffset
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics
{
	struct OculusXRFunctionLibrary_eventSetColorScaleAndOffset_Parms
	{
		FLinearColor ColorScale;
		FLinearColor ColorOffset;
		bool bApplyToAllLayers;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the Color Scale/Offset\n\x09 */" },
#endif
		{ "CPP_Default_bApplyToAllLayers", "false" },
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the Color Scale/Offset" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ColorScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ColorOffset;
	static void NewProp_bApplyToAllLayers_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bApplyToAllLayers;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::NewProp_ColorScale = { "ColorScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetColorScaleAndOffset_Parms, ColorScale), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::NewProp_ColorOffset = { "ColorOffset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetColorScaleAndOffset_Parms, ColorOffset), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::NewProp_bApplyToAllLayers_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventSetColorScaleAndOffset_Parms*)Obj)->bApplyToAllLayers = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::NewProp_bApplyToAllLayers = { "bApplyToAllLayers", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventSetColorScaleAndOffset_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::NewProp_bApplyToAllLayers_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::NewProp_ColorScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::NewProp_ColorOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::NewProp_bApplyToAllLayers,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetColorScaleAndOffset", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::OculusXRFunctionLibrary_eventSetColorScaleAndOffset_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::OculusXRFunctionLibrary_eventSetColorScaleAndOffset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetColorScaleAndOffset)
{
	P_GET_STRUCT(FLinearColor,Z_Param_ColorScale);
	P_GET_STRUCT(FLinearColor,Z_Param_ColorOffset);
	P_GET_UBOOL(Z_Param_bApplyToAllLayers);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetColorScaleAndOffset(Z_Param_ColorScale,Z_Param_ColorOffset,Z_Param_bApplyToAllLayers);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetColorScaleAndOffset

// Begin Class UOculusXRFunctionLibrary Function SetCPUAndGPULevels
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics
{
	struct OculusXRFunctionLibrary_eventSetCPUAndGPULevels_Parms
	{
		int32 CPULevel;
		int32 GPULevel;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the CPU and GPU levels as hints to the Oculus device (Deprecated).\n\x09 */" },
#endif
		{ "DeprecatedFunction", "" },
		{ "DeprecatedMessage", "Deprecated. Please use Get/SetSuggestedCpuAndGpuPerformanceLevels instead" },
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the CPU and GPU levels as hints to the Oculus device (Deprecated)." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_CPULevel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GPULevel;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics::NewProp_CPULevel = { "CPULevel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetCPUAndGPULevels_Parms, CPULevel), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics::NewProp_GPULevel = { "GPULevel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetCPUAndGPULevels_Parms, GPULevel), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics::NewProp_CPULevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics::NewProp_GPULevel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetCPUAndGPULevels", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics::OculusXRFunctionLibrary_eventSetCPUAndGPULevels_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics::OculusXRFunctionLibrary_eventSetCPUAndGPULevels_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetCPUAndGPULevels)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_CPULevel);
	P_GET_PROPERTY(FIntProperty,Z_Param_GPULevel);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetCPUAndGPULevels(Z_Param_CPULevel,Z_Param_GPULevel);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetCPUAndGPULevels

// Begin Class UOculusXRFunctionLibrary Function SetDisplayFrequency
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency_Statics
{
	struct OculusXRFunctionLibrary_eventSetDisplayFrequency_Parms
	{
		float RequestedFrequency;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets the requested display frequency\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the requested display frequency" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RequestedFrequency;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency_Statics::NewProp_RequestedFrequency = { "RequestedFrequency", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetDisplayFrequency_Parms, RequestedFrequency), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency_Statics::NewProp_RequestedFrequency,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetDisplayFrequency", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency_Statics::OculusXRFunctionLibrary_eventSetDisplayFrequency_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency_Statics::OculusXRFunctionLibrary_eventSetDisplayFrequency_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetDisplayFrequency)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_RequestedFrequency);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetDisplayFrequency(Z_Param_RequestedFrequency);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetDisplayFrequency

// Begin Class UOculusXRFunctionLibrary Function SetEnvironmentDepthHandRemoval
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics
{
	struct OculusXRFunctionLibrary_eventSetEnvironmentDepthHandRemoval_Parms
	{
		bool RemoveHands;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * When hands removal is enabled and hand tracking is active, the region\n\x09 * of the depth texture which contains the hands will be replaced with\n\x09 * the best estimate for depth behind the hands.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When hands removal is enabled and hand tracking is active, the region\nof the depth texture which contains the hands will be replaced with\nthe best estimate for depth behind the hands." },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_RemoveHands_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_RemoveHands;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics::NewProp_RemoveHands_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventSetEnvironmentDepthHandRemoval_Parms*)Obj)->RemoveHands = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics::NewProp_RemoveHands = { "RemoveHands", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventSetEnvironmentDepthHandRemoval_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics::NewProp_RemoveHands_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics::NewProp_RemoveHands,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetEnvironmentDepthHandRemoval", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics::OculusXRFunctionLibrary_eventSetEnvironmentDepthHandRemoval_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics::OculusXRFunctionLibrary_eventSetEnvironmentDepthHandRemoval_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetEnvironmentDepthHandRemoval)
{
	P_GET_UBOOL(Z_Param_RemoveHands);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetEnvironmentDepthHandRemoval(Z_Param_RemoveHands);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetEnvironmentDepthHandRemoval

// Begin Class UOculusXRFunctionLibrary Function SetEyeBufferSharpenType
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics
{
	struct OculusXRFunctionLibrary_eventSetEyeBufferSharpenType_Parms
	{
		EOculusXREyeBufferSharpenType EyeBufferSharpenType;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets the eyebuffer sharpen type. This amplifies contrast and fine details.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the eyebuffer sharpen type. This amplifies contrast and fine details." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_EyeBufferSharpenType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EyeBufferSharpenType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics::NewProp_EyeBufferSharpenType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics::NewProp_EyeBufferSharpenType = { "EyeBufferSharpenType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetEyeBufferSharpenType_Parms, EyeBufferSharpenType), Z_Construct_UEnum_OculusXRHMD_EOculusXREyeBufferSharpenType, METADATA_PARAMS(0, nullptr) }; // 2052807746
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics::NewProp_EyeBufferSharpenType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics::NewProp_EyeBufferSharpenType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetEyeBufferSharpenType", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics::OculusXRFunctionLibrary_eventSetEyeBufferSharpenType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics::OculusXRFunctionLibrary_eventSetEyeBufferSharpenType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetEyeBufferSharpenType)
{
	P_GET_ENUM(EOculusXREyeBufferSharpenType,Z_Param_EyeBufferSharpenType);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetEyeBufferSharpenType(EOculusXREyeBufferSharpenType(Z_Param_EyeBufferSharpenType));
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetEyeBufferSharpenType

// Begin Class UOculusXRFunctionLibrary Function SetFoveatedRenderingLevel
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics
{
	struct OculusXRFunctionLibrary_eventSetFoveatedRenderingLevel_Parms
	{
		EOculusXRFoveatedRenderingLevel level;
		bool isDynamic;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the requested foveated rendering level for the next frame, and whether FFR's level is now dynamic or not.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the requested foveated rendering level for the next frame, and whether FFR's level is now dynamic or not." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_level_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_level;
	static void NewProp_isDynamic_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_isDynamic;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::NewProp_level_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::NewProp_level = { "level", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetFoveatedRenderingLevel_Parms, level), Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingLevel, METADATA_PARAMS(0, nullptr) }; // 2300058379
void Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::NewProp_isDynamic_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventSetFoveatedRenderingLevel_Parms*)Obj)->isDynamic = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::NewProp_isDynamic = { "isDynamic", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventSetFoveatedRenderingLevel_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::NewProp_isDynamic_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::NewProp_level_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::NewProp_level,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::NewProp_isDynamic,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetFoveatedRenderingLevel", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::OculusXRFunctionLibrary_eventSetFoveatedRenderingLevel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::OculusXRFunctionLibrary_eventSetFoveatedRenderingLevel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetFoveatedRenderingLevel)
{
	P_GET_ENUM(EOculusXRFoveatedRenderingLevel,Z_Param_level);
	P_GET_UBOOL(Z_Param_isDynamic);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetFoveatedRenderingLevel(EOculusXRFoveatedRenderingLevel(Z_Param_level),Z_Param_isDynamic);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetFoveatedRenderingLevel

// Begin Class UOculusXRFunctionLibrary Function SetFoveatedRenderingMethod
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics
{
	struct OculusXRFunctionLibrary_eventSetFoveatedRenderingMethod_Parms
	{
		EOculusXRFoveatedRenderingMethod Method;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the requested foveated rendering method\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the requested foveated rendering method" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Method_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Method;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics::NewProp_Method_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics::NewProp_Method = { "Method", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetFoveatedRenderingMethod_Parms, Method), Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingMethod, METADATA_PARAMS(0, nullptr) }; // 1262503363
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics::NewProp_Method_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics::NewProp_Method,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetFoveatedRenderingMethod", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics::OculusXRFunctionLibrary_eventSetFoveatedRenderingMethod_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics::OculusXRFunctionLibrary_eventSetFoveatedRenderingMethod_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetFoveatedRenderingMethod)
{
	P_GET_ENUM(EOculusXRFoveatedRenderingMethod,Z_Param_Method);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetFoveatedRenderingMethod(EOculusXRFoveatedRenderingMethod(Z_Param_Method));
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetFoveatedRenderingMethod

// Begin Class UOculusXRFunctionLibrary Function SetGuardianVisibility
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics
{
	struct OculusXRFunctionLibrary_eventSetGuardianVisibility_Parms
	{
		bool GuardianVisible;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Guardian" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Forces the runtime to render guardian at all times or not\n\x09 * @param GuardianVisible\x09\x09\x09(in) True will display guardian, False will hide it\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Forces the runtime to render guardian at all times or not\n@param GuardianVisible                       (in) True will display guardian, False will hide it" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_GuardianVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_GuardianVisible;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics::NewProp_GuardianVisible_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventSetGuardianVisibility_Parms*)Obj)->GuardianVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics::NewProp_GuardianVisible = { "GuardianVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventSetGuardianVisibility_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics::NewProp_GuardianVisible_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics::NewProp_GuardianVisible,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetGuardianVisibility", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics::OculusXRFunctionLibrary_eventSetGuardianVisibility_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics::OculusXRFunctionLibrary_eventSetGuardianVisibility_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetGuardianVisibility)
{
	P_GET_UBOOL(Z_Param_GuardianVisible);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetGuardianVisibility(Z_Param_GuardianVisible);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetGuardianVisibility

// Begin Class UOculusXRFunctionLibrary Function SetLocalDimmingOn
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics
{
	struct OculusXRFunctionLibrary_eventSetLocalDimmingOn_Parms
	{
		bool LocalDimmingOn;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Turns on or off local dimming\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Turns on or off local dimming" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_LocalDimmingOn_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_LocalDimmingOn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics::NewProp_LocalDimmingOn_SetBit(void* Obj)
{
	((OculusXRFunctionLibrary_eventSetLocalDimmingOn_Parms*)Obj)->LocalDimmingOn = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics::NewProp_LocalDimmingOn = { "LocalDimmingOn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRFunctionLibrary_eventSetLocalDimmingOn_Parms), &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics::NewProp_LocalDimmingOn_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics::NewProp_LocalDimmingOn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetLocalDimmingOn", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics::OculusXRFunctionLibrary_eventSetLocalDimmingOn_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics::OculusXRFunctionLibrary_eventSetLocalDimmingOn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetLocalDimmingOn)
{
	P_GET_UBOOL(Z_Param_LocalDimmingOn);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetLocalDimmingOn(Z_Param_LocalDimmingOn);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetLocalDimmingOn

// Begin Class UOculusXRFunctionLibrary Function SetPositionScale3D
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D_Statics
{
	struct OculusXRFunctionLibrary_eventSetPositionScale3D_Parms
	{
		FVector PosScale3D;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Scales the HMD position that gets added to the virtual camera position.\n\x09 *\n\x09 * @param PosScale3D\x09(in) the scale to apply to the HMD position.\n\x09 */" },
#endif
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "This feature is no longer supported." },
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scales the HMD position that gets added to the virtual camera position.\n\n@param PosScale3D    (in) the scale to apply to the HMD position." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PosScale3D;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D_Statics::NewProp_PosScale3D = { "PosScale3D", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetPositionScale3D_Parms, PosScale3D), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D_Statics::NewProp_PosScale3D,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetPositionScale3D", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D_Statics::OculusXRFunctionLibrary_eventSetPositionScale3D_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D_Statics::OculusXRFunctionLibrary_eventSetPositionScale3D_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetPositionScale3D)
{
	P_GET_STRUCT(FVector,Z_Param_PosScale3D);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetPositionScale3D(Z_Param_PosScale3D);
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetPositionScale3D

// Begin Class UOculusXRFunctionLibrary Function SetSuggestedCpuAndGpuPerformanceLevels
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics
{
	struct OculusXRFunctionLibrary_eventSetSuggestedCpuAndGpuPerformanceLevels_Parms
	{
		EOculusXRProcessorPerformanceLevel CpuPerfLevel;
		EOculusXRProcessorPerformanceLevel GpuPerfLevel;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the suggested CPU and GPU levels to the Oculus device.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the suggested CPU and GPU levels to the Oculus device." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_CpuPerfLevel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CpuPerfLevel;
	static const UECodeGen_Private::FBytePropertyParams NewProp_GpuPerfLevel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_GpuPerfLevel;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_CpuPerfLevel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_CpuPerfLevel = { "CpuPerfLevel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetSuggestedCpuAndGpuPerformanceLevels_Parms, CpuPerfLevel), Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel, METADATA_PARAMS(0, nullptr) }; // 1326426722
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_GpuPerfLevel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_GpuPerfLevel = { "GpuPerfLevel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetSuggestedCpuAndGpuPerformanceLevels_Parms, GpuPerfLevel), Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel, METADATA_PARAMS(0, nullptr) }; // 1326426722
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_CpuPerfLevel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_CpuPerfLevel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_GpuPerfLevel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::NewProp_GpuPerfLevel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetSuggestedCpuAndGpuPerformanceLevels", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::OculusXRFunctionLibrary_eventSetSuggestedCpuAndGpuPerformanceLevels_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::OculusXRFunctionLibrary_eventSetSuggestedCpuAndGpuPerformanceLevels_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetSuggestedCpuAndGpuPerformanceLevels)
{
	P_GET_ENUM(EOculusXRProcessorPerformanceLevel,Z_Param_CpuPerfLevel);
	P_GET_ENUM(EOculusXRProcessorPerformanceLevel,Z_Param_GpuPerfLevel);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetSuggestedCpuAndGpuPerformanceLevels(EOculusXRProcessorPerformanceLevel(Z_Param_CpuPerfLevel),EOculusXRProcessorPerformanceLevel(Z_Param_GpuPerfLevel));
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetSuggestedCpuAndGpuPerformanceLevels

// Begin Class UOculusXRFunctionLibrary Function SetXROcclusionsMode
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics
{
	struct OculusXRFunctionLibrary_eventSetXROcclusionsMode_Parms
	{
		UObject* WorldContextObject;
		EOculusXROcclusionsMode Mode;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sets the occlusions mode using environment depth. When occlusions are enabled\n\x09 * virtual objects that are behind physical objects will be occluded so that\n\x09 * the sense of immersion is preserved.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the occlusions mode using environment depth. When occlusions are enabled\nvirtual objects that are behind physical objects will be occluded so that\nthe sense of immersion is preserved." },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Mode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Mode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetXROcclusionsMode_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::NewProp_Mode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::NewProp_Mode = { "Mode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFunctionLibrary_eventSetXROcclusionsMode_Parms, Mode), Z_Construct_UEnum_OculusXRHMD_EOculusXROcclusionsMode, METADATA_PARAMS(0, nullptr) }; // 4211737068
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::NewProp_Mode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::NewProp_Mode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "SetXROcclusionsMode", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::OculusXRFunctionLibrary_eventSetXROcclusionsMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::OculusXRFunctionLibrary_eventSetXROcclusionsMode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execSetXROcclusionsMode)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_ENUM(EOculusXROcclusionsMode,Z_Param_Mode);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::SetXROcclusionsMode(Z_Param_WorldContextObject,EOculusXROcclusionsMode(Z_Param_Mode));
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function SetXROcclusionsMode

// Begin Class UOculusXRFunctionLibrary Function StartEnvironmentDepth
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_StartEnvironmentDepth_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Create the environment depth texture swap chain and start receiving\n\x09 * depth texture every frame until stopped.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Create the environment depth texture swap chain and start receiving\ndepth texture every frame until stopped." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_StartEnvironmentDepth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "StartEnvironmentDepth", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_StartEnvironmentDepth_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_StartEnvironmentDepth_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_StartEnvironmentDepth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_StartEnvironmentDepth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execStartEnvironmentDepth)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::StartEnvironmentDepth();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function StartEnvironmentDepth

// Begin Class UOculusXRFunctionLibrary Function StopEnvironmentDepth
struct Z_Construct_UFunction_UOculusXRFunctionLibrary_StopEnvironmentDepth_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Destroy the environment depth texture swap chain and stop receiving\n\x09 * new depth textures every frame. Call this when environment depth is\n\x09 * no longer needed to free up resources.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Destroy the environment depth texture swap chain and stop receiving\nnew depth textures every frame. Call this when environment depth is\nno longer needed to free up resources." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFunctionLibrary_StopEnvironmentDepth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFunctionLibrary, nullptr, "StopEnvironmentDepth", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFunctionLibrary_StopEnvironmentDepth_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFunctionLibrary_StopEnvironmentDepth_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UOculusXRFunctionLibrary_StopEnvironmentDepth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFunctionLibrary_StopEnvironmentDepth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFunctionLibrary::execStopEnvironmentDepth)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRFunctionLibrary::StopEnvironmentDepth();
	P_NATIVE_END;
}
// End Class UOculusXRFunctionLibrary Function StopEnvironmentDepth

// Begin Class UOculusXRFunctionLibrary
void UOculusXRFunctionLibrary::StaticRegisterNativesUOculusXRFunctionLibrary()
{
	UClass* Class = UOculusXRFunctionLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddLoadingSplashScreen", &UOculusXRFunctionLibrary::execAddLoadingSplashScreen },
		{ "ClearLoadingSplashScreens", &UOculusXRFunctionLibrary::execClearLoadingSplashScreens },
		{ "EnableOrientationTracking", &UOculusXRFunctionLibrary::execEnableOrientationTracking },
		{ "EnablePositionTracking", &UOculusXRFunctionLibrary::execEnablePositionTracking },
		{ "GetAvailableDisplayFrequencies", &UOculusXRFunctionLibrary::execGetAvailableDisplayFrequencies },
		{ "GetBaseRotationAndBaseOffsetInMeters", &UOculusXRFunctionLibrary::execGetBaseRotationAndBaseOffsetInMeters },
		{ "GetBaseRotationAndPositionOffset", &UOculusXRFunctionLibrary::execGetBaseRotationAndPositionOffset },
		{ "GetControllerType", &UOculusXRFunctionLibrary::execGetControllerType },
		{ "GetCurrentDisplayFrequency", &UOculusXRFunctionLibrary::execGetCurrentDisplayFrequency },
		{ "GetDeviceName", &UOculusXRFunctionLibrary::execGetDeviceName },
		{ "GetDeviceType", &UOculusXRFunctionLibrary::execGetDeviceType },
		{ "GetEyeTrackedFoveatedRenderingSupported", &UOculusXRFunctionLibrary::execGetEyeTrackedFoveatedRenderingSupported },
		{ "GetFoveatedRenderingLevel", &UOculusXRFunctionLibrary::execGetFoveatedRenderingLevel },
		{ "GetFoveatedRenderingMethod", &UOculusXRFunctionLibrary::execGetFoveatedRenderingMethod },
		{ "GetGPUFrameTime", &UOculusXRFunctionLibrary::execGetGPUFrameTime },
		{ "GetGPUUtilization", &UOculusXRFunctionLibrary::execGetGPUUtilization },
		{ "GetGuardianDimensions", &UOculusXRFunctionLibrary::execGetGuardianDimensions },
		{ "GetGuardianPoints", &UOculusXRFunctionLibrary::execGetGuardianPoints },
		{ "GetHmdColorDesc", &UOculusXRFunctionLibrary::execGetHmdColorDesc },
		{ "GetNodeGuardianIntersection", &UOculusXRFunctionLibrary::execGetNodeGuardianIntersection },
		{ "GetPerformanceMetrics", &UOculusXRFunctionLibrary::execGetPerformanceMetrics },
		{ "GetPlayAreaTransform", &UOculusXRFunctionLibrary::execGetPlayAreaTransform },
		{ "GetPointGuardianIntersection", &UOculusXRFunctionLibrary::execGetPointGuardianIntersection },
		{ "GetPose", &UOculusXRFunctionLibrary::execGetPose },
		{ "GetRawSensorData", &UOculusXRFunctionLibrary::execGetRawSensorData },
		{ "GetSuggestedCpuAndGpuPerformanceLevels", &UOculusXRFunctionLibrary::execGetSuggestedCpuAndGpuPerformanceLevels },
		{ "GetSystemHmd3DofModeEnabled", &UOculusXRFunctionLibrary::execGetSystemHmd3DofModeEnabled },
		{ "GetUserProfile", &UOculusXRFunctionLibrary::execGetUserProfile },
		{ "HasInputFocus", &UOculusXRFunctionLibrary::execHasInputFocus },
		{ "HasSystemOverlayPresent", &UOculusXRFunctionLibrary::execHasSystemOverlayPresent },
		{ "IsColorPassthroughSupported", &UOculusXRFunctionLibrary::execIsColorPassthroughSupported },
		{ "IsDeviceTracked", &UOculusXRFunctionLibrary::execIsDeviceTracked },
		{ "IsEnvironmentDepthStarted", &UOculusXRFunctionLibrary::execIsEnvironmentDepthStarted },
		{ "IsGuardianConfigured", &UOculusXRFunctionLibrary::execIsGuardianConfigured },
		{ "IsGuardianDisplayed", &UOculusXRFunctionLibrary::execIsGuardianDisplayed },
		{ "IsPassthroughRecommended", &UOculusXRFunctionLibrary::execIsPassthroughRecommended },
		{ "IsPassthroughSupported", &UOculusXRFunctionLibrary::execIsPassthroughSupported },
		{ "SetBaseRotationAndBaseOffsetInMeters", &UOculusXRFunctionLibrary::execSetBaseRotationAndBaseOffsetInMeters },
		{ "SetBaseRotationAndPositionOffset", &UOculusXRFunctionLibrary::execSetBaseRotationAndPositionOffset },
		{ "SetClientColorDesc", &UOculusXRFunctionLibrary::execSetClientColorDesc },
		{ "SetColorScaleAndOffset", &UOculusXRFunctionLibrary::execSetColorScaleAndOffset },
		{ "SetCPUAndGPULevels", &UOculusXRFunctionLibrary::execSetCPUAndGPULevels },
		{ "SetDisplayFrequency", &UOculusXRFunctionLibrary::execSetDisplayFrequency },
		{ "SetEnvironmentDepthHandRemoval", &UOculusXRFunctionLibrary::execSetEnvironmentDepthHandRemoval },
		{ "SetEyeBufferSharpenType", &UOculusXRFunctionLibrary::execSetEyeBufferSharpenType },
		{ "SetFoveatedRenderingLevel", &UOculusXRFunctionLibrary::execSetFoveatedRenderingLevel },
		{ "SetFoveatedRenderingMethod", &UOculusXRFunctionLibrary::execSetFoveatedRenderingMethod },
		{ "SetGuardianVisibility", &UOculusXRFunctionLibrary::execSetGuardianVisibility },
		{ "SetLocalDimmingOn", &UOculusXRFunctionLibrary::execSetLocalDimmingOn },
		{ "SetPositionScale3D", &UOculusXRFunctionLibrary::execSetPositionScale3D },
		{ "SetSuggestedCpuAndGpuPerformanceLevels", &UOculusXRFunctionLibrary::execSetSuggestedCpuAndGpuPerformanceLevels },
		{ "SetXROcclusionsMode", &UOculusXRFunctionLibrary::execSetXROcclusionsMode },
		{ "StartEnvironmentDepth", &UOculusXRFunctionLibrary::execStartEnvironmentDepth },
		{ "StopEnvironmentDepth", &UOculusXRFunctionLibrary::execStopEnvironmentDepth },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRFunctionLibrary);
UClass* Z_Construct_UClass_UOculusXRFunctionLibrary_NoRegister()
{
	return UOculusXRFunctionLibrary::StaticClass();
}
struct Z_Construct_UClass_UOculusXRFunctionLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// namespace OculusXRHMD\n" },
#endif
		{ "IncludePath", "OculusXRFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/OculusXRFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "namespace OculusXRHMD" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_AddLoadingSplashScreen, "AddLoadingSplashScreen" }, // 4012373072
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_ClearLoadingSplashScreens, "ClearLoadingSplashScreens" }, // 1812995599
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_EnableOrientationTracking, "EnableOrientationTracking" }, // 235755366
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_EnablePositionTracking, "EnablePositionTracking" }, // 1151443954
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetAvailableDisplayFrequencies, "GetAvailableDisplayFrequencies" }, // 1769703612
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndBaseOffsetInMeters, "GetBaseRotationAndBaseOffsetInMeters" }, // 2030721259
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetBaseRotationAndPositionOffset, "GetBaseRotationAndPositionOffset" }, // 1261408369
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetControllerType, "GetControllerType" }, // 266458433
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetCurrentDisplayFrequency, "GetCurrentDisplayFrequency" }, // 3862592351
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceName, "GetDeviceName" }, // 3274409741
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetDeviceType, "GetDeviceType" }, // 1330604978
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetEyeTrackedFoveatedRenderingSupported, "GetEyeTrackedFoveatedRenderingSupported" }, // 3692420446
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingLevel, "GetFoveatedRenderingLevel" }, // 616163560
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetFoveatedRenderingMethod, "GetFoveatedRenderingMethod" }, // 422215113
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUFrameTime, "GetGPUFrameTime" }, // 2579252523
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGPUUtilization, "GetGPUUtilization" }, // 341461584
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianDimensions, "GetGuardianDimensions" }, // 1861359645
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetGuardianPoints, "GetGuardianPoints" }, // 1093542772
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetHmdColorDesc, "GetHmdColorDesc" }, // 2905553267
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetNodeGuardianIntersection, "GetNodeGuardianIntersection" }, // 1657820636
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPerformanceMetrics, "GetPerformanceMetrics" }, // 712256159
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPlayAreaTransform, "GetPlayAreaTransform" }, // 4283960447
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPointGuardianIntersection, "GetPointGuardianIntersection" }, // 166799170
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetPose, "GetPose" }, // 2155236182
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetRawSensorData, "GetRawSensorData" }, // 2109272662
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSuggestedCpuAndGpuPerformanceLevels, "GetSuggestedCpuAndGpuPerformanceLevels" }, // 1443443601
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetSystemHmd3DofModeEnabled, "GetSystemHmd3DofModeEnabled" }, // 2929288384
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_GetUserProfile, "GetUserProfile" }, // 376368943
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_HasInputFocus, "HasInputFocus" }, // 2905903522
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_HasSystemOverlayPresent, "HasSystemOverlayPresent" }, // 1098786671
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_IsColorPassthroughSupported, "IsColorPassthroughSupported" }, // 4068529560
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_IsDeviceTracked, "IsDeviceTracked" }, // 1217315043
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_IsEnvironmentDepthStarted, "IsEnvironmentDepthStarted" }, // 832230900
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianConfigured, "IsGuardianConfigured" }, // 3527318730
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_IsGuardianDisplayed, "IsGuardianDisplayed" }, // 784181876
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughRecommended, "IsPassthroughRecommended" }, // 4259648790
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_IsPassthroughSupported, "IsPassthroughSupported" }, // 2794562773
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndBaseOffsetInMeters, "SetBaseRotationAndBaseOffsetInMeters" }, // 2503251562
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetBaseRotationAndPositionOffset, "SetBaseRotationAndPositionOffset" }, // 3680878887
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetClientColorDesc, "SetClientColorDesc" }, // 3982169354
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetColorScaleAndOffset, "SetColorScaleAndOffset" }, // 3930104321
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetCPUAndGPULevels, "SetCPUAndGPULevels" }, // 776777371
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetDisplayFrequency, "SetDisplayFrequency" }, // 191909841
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEnvironmentDepthHandRemoval, "SetEnvironmentDepthHandRemoval" }, // 1305291747
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetEyeBufferSharpenType, "SetEyeBufferSharpenType" }, // 2691000372
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingLevel, "SetFoveatedRenderingLevel" }, // 3348927362
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetFoveatedRenderingMethod, "SetFoveatedRenderingMethod" }, // 651222549
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetGuardianVisibility, "SetGuardianVisibility" }, // 3916264593
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetLocalDimmingOn, "SetLocalDimmingOn" }, // 258713080
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetPositionScale3D, "SetPositionScale3D" }, // 1480079323
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetSuggestedCpuAndGpuPerformanceLevels, "SetSuggestedCpuAndGpuPerformanceLevels" }, // 146911240
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_SetXROcclusionsMode, "SetXROcclusionsMode" }, // 3338985374
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_StartEnvironmentDepth, "StartEnvironmentDepth" }, // 3323401751
		{ &Z_Construct_UFunction_UOculusXRFunctionLibrary_StopEnvironmentDepth, "StopEnvironmentDepth" }, // 2716154454
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRFunctionLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UOculusXRFunctionLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRHMD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRFunctionLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRFunctionLibrary_Statics::ClassParams = {
	&UOculusXRFunctionLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRFunctionLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRFunctionLibrary()
{
	if (!Z_Registration_Info_UClass_UOculusXRFunctionLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRFunctionLibrary.OuterSingleton, Z_Construct_UClass_UOculusXRFunctionLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRFunctionLibrary.OuterSingleton;
}
template<> OCULUSXRHMD_API UClass* StaticClass<UOculusXRFunctionLibrary>()
{
	return UOculusXRFunctionLibrary::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRFunctionLibrary);
UOculusXRFunctionLibrary::~UOculusXRFunctionLibrary() {}
// End Class UOculusXRFunctionLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRFunctionLibrary_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRFunctionLibrary, UOculusXRFunctionLibrary::StaticClass, TEXT("UOculusXRFunctionLibrary"), &Z_Registration_Info_UClass_UOculusXRFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRFunctionLibrary), 1177380954U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRFunctionLibrary_h_3389656498(TEXT("/Script/OculusXRHMD"),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRFunctionLibrary_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
