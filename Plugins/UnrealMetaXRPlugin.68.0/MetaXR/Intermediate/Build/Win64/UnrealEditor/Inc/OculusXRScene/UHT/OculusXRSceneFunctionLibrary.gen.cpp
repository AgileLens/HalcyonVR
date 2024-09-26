// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRScene/Public/OculusXRSceneFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRSceneFunctionLibrary() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
OCULUSXRSCENE_API UClass* Z_Construct_UClass_UOculusXRSceneFunctionLibrary();
OCULUSXRSCENE_API UClass* Z_Construct_UClass_UOculusXRSceneFunctionLibrary_NoRegister();
OCULUSXRSCENE_API UEnum* Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility();
UPackage* Z_Construct_UPackage__Script_OculusXRScene();
// End Cross Module References

// Begin Class UOculusXRSceneFunctionLibrary Function GetBoundaryVisibility
struct Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics
{
	struct OculusXRSceneFunctionLibrary_eventGetBoundaryVisibility_Parms
	{
		const UObject* WorldContext;
		EOculusXRBoundaryVisibility OutVisibility;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Returns the current boundary visibility\n" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRSceneFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the current boundary visibility" },
#endif
		{ "WorldContext", "WorldContext" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContext_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContext;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OutVisibility_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OutVisibility;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::NewProp_WorldContext = { "WorldContext", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRSceneFunctionLibrary_eventGetBoundaryVisibility_Parms, WorldContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContext_MetaData), NewProp_WorldContext_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::NewProp_OutVisibility_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::NewProp_OutVisibility = { "OutVisibility", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRSceneFunctionLibrary_eventGetBoundaryVisibility_Parms, OutVisibility), Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility, METADATA_PARAMS(0, nullptr) }; // 1439512401
void Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRSceneFunctionLibrary_eventGetBoundaryVisibility_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRSceneFunctionLibrary_eventGetBoundaryVisibility_Parms), &Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::NewProp_WorldContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::NewProp_OutVisibility_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::NewProp_OutVisibility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRSceneFunctionLibrary, nullptr, "GetBoundaryVisibility", nullptr, nullptr, Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::OculusXRSceneFunctionLibrary_eventGetBoundaryVisibility_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::OculusXRSceneFunctionLibrary_eventGetBoundaryVisibility_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRSceneFunctionLibrary::execGetBoundaryVisibility)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContext);
	P_GET_ENUM_REF(EOculusXRBoundaryVisibility,Z_Param_Out_OutVisibility);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRSceneFunctionLibrary::GetBoundaryVisibility(Z_Param_WorldContext,(EOculusXRBoundaryVisibility&)(Z_Param_Out_OutVisibility));
	P_NATIVE_END;
}
// End Class UOculusXRSceneFunctionLibrary Function GetBoundaryVisibility

// Begin Class UOculusXRSceneFunctionLibrary Function GetRequestedBoundaryVisibility
struct Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics
{
	struct OculusXRSceneFunctionLibrary_eventGetRequestedBoundaryVisibility_Parms
	{
		const UObject* WorldContext;
		EOculusXRBoundaryVisibility OutVisibility;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Returns the requested boundary visibility state\n" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRSceneFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the requested boundary visibility state" },
#endif
		{ "WorldContext", "WorldContext" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContext_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContext;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OutVisibility_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OutVisibility;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::NewProp_WorldContext = { "WorldContext", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRSceneFunctionLibrary_eventGetRequestedBoundaryVisibility_Parms, WorldContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContext_MetaData), NewProp_WorldContext_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::NewProp_OutVisibility_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::NewProp_OutVisibility = { "OutVisibility", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRSceneFunctionLibrary_eventGetRequestedBoundaryVisibility_Parms, OutVisibility), Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility, METADATA_PARAMS(0, nullptr) }; // 1439512401
void Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRSceneFunctionLibrary_eventGetRequestedBoundaryVisibility_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRSceneFunctionLibrary_eventGetRequestedBoundaryVisibility_Parms), &Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::NewProp_WorldContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::NewProp_OutVisibility_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::NewProp_OutVisibility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRSceneFunctionLibrary, nullptr, "GetRequestedBoundaryVisibility", nullptr, nullptr, Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::OculusXRSceneFunctionLibrary_eventGetRequestedBoundaryVisibility_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::OculusXRSceneFunctionLibrary_eventGetRequestedBoundaryVisibility_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRSceneFunctionLibrary::execGetRequestedBoundaryVisibility)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContext);
	P_GET_ENUM_REF(EOculusXRBoundaryVisibility,Z_Param_Out_OutVisibility);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRSceneFunctionLibrary::GetRequestedBoundaryVisibility(Z_Param_WorldContext,(EOculusXRBoundaryVisibility&)(Z_Param_Out_OutVisibility));
	P_NATIVE_END;
}
// End Class UOculusXRSceneFunctionLibrary Function GetRequestedBoundaryVisibility

// Begin Class UOculusXRSceneFunctionLibrary Function RequestBoundaryVisibility
struct Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics
{
	struct OculusXRSceneFunctionLibrary_eventRequestBoundaryVisibility_Parms
	{
		const UObject* WorldContext;
		EOculusXRBoundaryVisibility NewVisibilityRequest;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Requests to change the current boundary visibility\n" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRSceneFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Requests to change the current boundary visibility" },
#endif
		{ "WorldContext", "WorldContext" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContext_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContext;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewVisibilityRequest_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewVisibilityRequest;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::NewProp_WorldContext = { "WorldContext", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRSceneFunctionLibrary_eventRequestBoundaryVisibility_Parms, WorldContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContext_MetaData), NewProp_WorldContext_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::NewProp_NewVisibilityRequest_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::NewProp_NewVisibilityRequest = { "NewVisibilityRequest", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRSceneFunctionLibrary_eventRequestBoundaryVisibility_Parms, NewVisibilityRequest), Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility, METADATA_PARAMS(0, nullptr) }; // 1439512401
void Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRSceneFunctionLibrary_eventRequestBoundaryVisibility_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRSceneFunctionLibrary_eventRequestBoundaryVisibility_Parms), &Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::NewProp_WorldContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::NewProp_NewVisibilityRequest_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::NewProp_NewVisibilityRequest,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRSceneFunctionLibrary, nullptr, "RequestBoundaryVisibility", nullptr, nullptr, Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::OculusXRSceneFunctionLibrary_eventRequestBoundaryVisibility_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::OculusXRSceneFunctionLibrary_eventRequestBoundaryVisibility_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRSceneFunctionLibrary::execRequestBoundaryVisibility)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContext);
	P_GET_ENUM(EOculusXRBoundaryVisibility,Z_Param_NewVisibilityRequest);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRSceneFunctionLibrary::RequestBoundaryVisibility(Z_Param_WorldContext,EOculusXRBoundaryVisibility(Z_Param_NewVisibilityRequest));
	P_NATIVE_END;
}
// End Class UOculusXRSceneFunctionLibrary Function RequestBoundaryVisibility

// Begin Class UOculusXRSceneFunctionLibrary
void UOculusXRSceneFunctionLibrary::StaticRegisterNativesUOculusXRSceneFunctionLibrary()
{
	UClass* Class = UOculusXRSceneFunctionLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetBoundaryVisibility", &UOculusXRSceneFunctionLibrary::execGetBoundaryVisibility },
		{ "GetRequestedBoundaryVisibility", &UOculusXRSceneFunctionLibrary::execGetRequestedBoundaryVisibility },
		{ "RequestBoundaryVisibility", &UOculusXRSceneFunctionLibrary::execRequestBoundaryVisibility },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRSceneFunctionLibrary);
UClass* Z_Construct_UClass_UOculusXRSceneFunctionLibrary_NoRegister()
{
	return UOculusXRSceneFunctionLibrary::StaticClass();
}
struct Z_Construct_UClass_UOculusXRSceneFunctionLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "OculusXRSceneFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/OculusXRSceneFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetBoundaryVisibility, "GetBoundaryVisibility" }, // 3200215393
		{ &Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_GetRequestedBoundaryVisibility, "GetRequestedBoundaryVisibility" }, // 2812046038
		{ &Z_Construct_UFunction_UOculusXRSceneFunctionLibrary_RequestBoundaryVisibility, "RequestBoundaryVisibility" }, // 1668565948
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRSceneFunctionLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UOculusXRSceneFunctionLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRScene,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneFunctionLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRSceneFunctionLibrary_Statics::ClassParams = {
	&UOculusXRSceneFunctionLibrary::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRSceneFunctionLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRSceneFunctionLibrary()
{
	if (!Z_Registration_Info_UClass_UOculusXRSceneFunctionLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRSceneFunctionLibrary.OuterSingleton, Z_Construct_UClass_UOculusXRSceneFunctionLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRSceneFunctionLibrary.OuterSingleton;
}
template<> OCULUSXRSCENE_API UClass* StaticClass<UOculusXRSceneFunctionLibrary>()
{
	return UOculusXRSceneFunctionLibrary::StaticClass();
}
UOculusXRSceneFunctionLibrary::UOculusXRSceneFunctionLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRSceneFunctionLibrary);
UOculusXRSceneFunctionLibrary::~UOculusXRSceneFunctionLibrary() {}
// End Class UOculusXRSceneFunctionLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRScene_Public_OculusXRSceneFunctionLibrary_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRSceneFunctionLibrary, UOculusXRSceneFunctionLibrary::StaticClass, TEXT("UOculusXRSceneFunctionLibrary"), &Z_Registration_Info_UClass_UOculusXRSceneFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRSceneFunctionLibrary), 1797711098U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRScene_Public_OculusXRSceneFunctionLibrary_h_3062319420(TEXT("/Script/OculusXRScene"),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRScene_Public_OculusXRSceneFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRScene_Public_OculusXRSceneFunctionLibrary_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
