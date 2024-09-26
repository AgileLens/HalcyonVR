// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRPassthrough/Public/OculusXRPassthroughSubsystem.h"
#include "OculusXRPassthrough/Public/OculusXRPersistentPassthroughInstance.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRPassthroughSubsystem() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
OCULUSXRPASSTHROUGH_API UClass* Z_Construct_UClass_UOculusXRPassthroughSubsystem();
OCULUSXRPASSTHROUGH_API UClass* Z_Construct_UClass_UOculusXRPassthroughSubsystem_NoRegister();
OCULUSXRPASSTHROUGH_API UClass* Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_NoRegister();
OCULUSXRPASSTHROUGH_API UFunction* Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature();
OCULUSXRPASSTHROUGH_API UFunction* Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_LayerResumed_Single__DelegateSignature();
OCULUSXRPASSTHROUGH_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters();
UPackage* Z_Construct_UPackage__Script_OculusXRPassthrough();
// End Cross Module References

// Begin Delegate FOculusXRPassthrough_AnyLayerResumed
struct Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature_Statics
{
	struct _Script_OculusXRPassthrough_eventOculusXRPassthrough_AnyLayerResumed_Parms
	{
		int32 LayerID;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OculusXRPassthroughSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_LayerID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature_Statics::NewProp_LayerID = { "LayerID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OculusXRPassthrough_eventOculusXRPassthrough_AnyLayerResumed_Parms, LayerID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature_Statics::NewProp_LayerID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OculusXRPassthrough, nullptr, "OculusXRPassthrough_AnyLayerResumed__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature_Statics::_Script_OculusXRPassthrough_eventOculusXRPassthrough_AnyLayerResumed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature_Statics::_Script_OculusXRPassthrough_eventOculusXRPassthrough_AnyLayerResumed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOculusXRPassthrough_AnyLayerResumed_DelegateWrapper(const FMulticastScriptDelegate& OculusXRPassthrough_AnyLayerResumed, int32 LayerID)
{
	struct _Script_OculusXRPassthrough_eventOculusXRPassthrough_AnyLayerResumed_Parms
	{
		int32 LayerID;
	};
	_Script_OculusXRPassthrough_eventOculusXRPassthrough_AnyLayerResumed_Parms Parms;
	Parms.LayerID=LayerID;
	OculusXRPassthrough_AnyLayerResumed.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOculusXRPassthrough_AnyLayerResumed

// Begin Class UOculusXRPassthroughSubsystem Function DestroyPersistentPassthrough
struct Z_Construct_UFunction_UOculusXRPassthroughSubsystem_DestroyPersistentPassthrough_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Passthrough|Persistent" },
		{ "ModuleRelativePath", "Public/OculusXRPassthroughSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRPassthroughSubsystem_DestroyPersistentPassthrough_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRPassthroughSubsystem, nullptr, "DestroyPersistentPassthrough", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPassthroughSubsystem_DestroyPersistentPassthrough_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRPassthroughSubsystem_DestroyPersistentPassthrough_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UOculusXRPassthroughSubsystem_DestroyPersistentPassthrough()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRPassthroughSubsystem_DestroyPersistentPassthrough_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRPassthroughSubsystem::execDestroyPersistentPassthrough)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DestroyPersistentPassthrough();
	P_NATIVE_END;
}
// End Class UOculusXRPassthroughSubsystem Function DestroyPersistentPassthrough

// Begin Class UOculusXRPassthroughSubsystem Function GetPersistentPassthrough
struct Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough_Statics
{
	struct OculusXRPassthroughSubsystem_eventGetPersistentPassthrough_Parms
	{
		UOculusXRPersistentPassthroughInstance* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Passthrough|Persistent" },
		{ "ModuleRelativePath", "Public/OculusXRPassthroughSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRPassthroughSubsystem_eventGetPersistentPassthrough_Parms, ReturnValue), Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRPassthroughSubsystem, nullptr, "GetPersistentPassthrough", nullptr, nullptr, Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough_Statics::OculusXRPassthroughSubsystem_eventGetPersistentPassthrough_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough_Statics::OculusXRPassthroughSubsystem_eventGetPersistentPassthrough_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRPassthroughSubsystem::execGetPersistentPassthrough)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UOculusXRPersistentPassthroughInstance**)Z_Param__Result=P_THIS->GetPersistentPassthrough();
	P_NATIVE_END;
}
// End Class UOculusXRPassthroughSubsystem Function GetPersistentPassthrough

// Begin Class UOculusXRPassthroughSubsystem Function InitializePersistentPassthrough
struct Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics
{
	struct OculusXRPassthroughSubsystem_eventInitializePersistentPassthrough_Parms
	{
		FOculusXRPersistentPassthroughParameters Parameters;
		FScriptDelegate LayerResumed;
		UOculusXRPersistentPassthroughInstance* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "LayerResumed" },
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "Passthrough|Persistent" },
		{ "Comment", "/**\n\x09 * Creates a Reconstructed Passthrough layer that stays alive until \"Destroy Persistent Passthrough\" is called.\n\x09 * If used in blueprints, layer's parameters are available in the Details window when selecting the node.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRPassthroughSubsystem.h" },
		{ "ToolTip", "Creates a Reconstructed Passthrough layer that stays alive until \"Destroy Persistent Passthrough\" is called.\nIf used in blueprints, layer's parameters are available in the Details window when selecting the node." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LayerResumed_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Parameters;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_LayerResumed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::NewProp_Parameters = { "Parameters", nullptr, (EPropertyFlags)0x0010008000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRPassthroughSubsystem_eventInitializePersistentPassthrough_Parms, Parameters), Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters, METADATA_PARAMS(0, nullptr) }; // 2817404716
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::NewProp_LayerResumed = { "LayerResumed", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRPassthroughSubsystem_eventInitializePersistentPassthrough_Parms, LayerResumed), Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_LayerResumed_Single__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LayerResumed_MetaData), NewProp_LayerResumed_MetaData) }; // 871567561
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRPassthroughSubsystem_eventInitializePersistentPassthrough_Parms, ReturnValue), Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::NewProp_Parameters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::NewProp_LayerResumed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRPassthroughSubsystem, nullptr, "InitializePersistentPassthrough", nullptr, nullptr, Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::OculusXRPassthroughSubsystem_eventInitializePersistentPassthrough_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::OculusXRPassthroughSubsystem_eventInitializePersistentPassthrough_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRPassthroughSubsystem::execInitializePersistentPassthrough)
{
	P_GET_STRUCT(FOculusXRPersistentPassthroughParameters,Z_Param_Parameters);
	P_GET_PROPERTY_REF(FDelegateProperty,Z_Param_Out_LayerResumed);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UOculusXRPersistentPassthroughInstance**)Z_Param__Result=P_THIS->InitializePersistentPassthrough(Z_Param_Parameters,FOculusXRPassthrough_LayerResumed_Single(Z_Param_Out_LayerResumed));
	P_NATIVE_END;
}
// End Class UOculusXRPassthroughSubsystem Function InitializePersistentPassthrough

// Begin Class UOculusXRPassthroughSubsystem
void UOculusXRPassthroughSubsystem::StaticRegisterNativesUOculusXRPassthroughSubsystem()
{
	UClass* Class = UOculusXRPassthroughSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "DestroyPersistentPassthrough", &UOculusXRPassthroughSubsystem::execDestroyPersistentPassthrough },
		{ "GetPersistentPassthrough", &UOculusXRPassthroughSubsystem::execGetPersistentPassthrough },
		{ "InitializePersistentPassthrough", &UOculusXRPassthroughSubsystem::execInitializePersistentPassthrough },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRPassthroughSubsystem);
UClass* Z_Construct_UClass_UOculusXRPassthroughSubsystem_NoRegister()
{
	return UOculusXRPassthroughSubsystem::StaticClass();
}
struct Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Passthrough Subsystem" },
		{ "IncludePath", "OculusXRPassthroughSubsystem.h" },
		{ "ModuleRelativePath", "Public/OculusXRPassthroughSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnAnyLayerResumed_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRPassthroughSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PPTInstance_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OculusXRPassthroughSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnAnyLayerResumed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PPTInstance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOculusXRPassthroughSubsystem_DestroyPersistentPassthrough, "DestroyPersistentPassthrough" }, // 3018445201
		{ &Z_Construct_UFunction_UOculusXRPassthroughSubsystem_GetPersistentPassthrough, "GetPersistentPassthrough" }, // 805969360
		{ &Z_Construct_UFunction_UOculusXRPassthroughSubsystem_InitializePersistentPassthrough, "InitializePersistentPassthrough" }, // 3616353288
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRPassthroughSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics::NewProp_OnAnyLayerResumed = { "OnAnyLayerResumed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRPassthroughSubsystem, OnAnyLayerResumed), Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnAnyLayerResumed_MetaData), NewProp_OnAnyLayerResumed_MetaData) }; // 1810088291
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics::NewProp_PPTInstance = { "PPTInstance", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRPassthroughSubsystem, PPTInstance), Z_Construct_UClass_UOculusXRPersistentPassthroughInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PPTInstance_MetaData), NewProp_PPTInstance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics::NewProp_OnAnyLayerResumed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics::NewProp_PPTInstance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRPassthrough,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics::ClassParams = {
	&UOculusXRPassthroughSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRPassthroughSubsystem()
{
	if (!Z_Registration_Info_UClass_UOculusXRPassthroughSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRPassthroughSubsystem.OuterSingleton, Z_Construct_UClass_UOculusXRPassthroughSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRPassthroughSubsystem.OuterSingleton;
}
template<> OCULUSXRPASSTHROUGH_API UClass* StaticClass<UOculusXRPassthroughSubsystem>()
{
	return UOculusXRPassthroughSubsystem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRPassthroughSubsystem);
UOculusXRPassthroughSubsystem::~UOculusXRPassthroughSubsystem() {}
// End Class UOculusXRPassthroughSubsystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPassthroughSubsystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRPassthroughSubsystem, UOculusXRPassthroughSubsystem::StaticClass, TEXT("UOculusXRPassthroughSubsystem"), &Z_Registration_Info_UClass_UOculusXRPassthroughSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRPassthroughSubsystem), 1650251557U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPassthroughSubsystem_h_3966871118(TEXT("/Script/OculusXRPassthrough"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPassthroughSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRPassthrough_Public_OculusXRPassthroughSubsystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
