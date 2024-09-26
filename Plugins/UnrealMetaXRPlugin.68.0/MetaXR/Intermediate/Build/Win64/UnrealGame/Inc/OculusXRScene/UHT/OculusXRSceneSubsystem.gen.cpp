// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRScene/Public/OculusXRSceneSubsystem.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRSceneSubsystem() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
OCULUSXRSCENE_API UClass* Z_Construct_UClass_UOculusXRSceneSubsystem();
OCULUSXRSCENE_API UClass* Z_Construct_UClass_UOculusXRSceneSubsystem_NoRegister();
OCULUSXRSCENE_API UEnum* Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility();
UPackage* Z_Construct_UPackage__Script_OculusXRScene();
// End Cross Module References

// Begin Class UOculusXRSceneSubsystem Function GetBoundaryVisibility
struct Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics
{
	struct OculusXRSceneSubsystem_eventGetBoundaryVisibility_Parms
	{
		EOculusXRBoundaryVisibility ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene" },
		{ "Comment", "// FTickableGameObject implementation End\n" },
		{ "ModuleRelativePath", "Public/OculusXRSceneSubsystem.h" },
		{ "ToolTip", "FTickableGameObject implementation End" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRSceneSubsystem_eventGetBoundaryVisibility_Parms, ReturnValue), Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility, METADATA_PARAMS(0, nullptr) }; // 1439512401
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRSceneSubsystem, nullptr, "GetBoundaryVisibility", nullptr, nullptr, Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics::OculusXRSceneSubsystem_eventGetBoundaryVisibility_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics::OculusXRSceneSubsystem_eventGetBoundaryVisibility_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRSceneSubsystem::execGetBoundaryVisibility)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EOculusXRBoundaryVisibility*)Z_Param__Result=P_THIS->GetBoundaryVisibility();
	P_NATIVE_END;
}
// End Class UOculusXRSceneSubsystem Function GetBoundaryVisibility

// Begin Class UOculusXRSceneSubsystem Function GetRequestedBoundaryVisibility
struct Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics
{
	struct OculusXRSceneSubsystem_eventGetRequestedBoundaryVisibility_Parms
	{
		EOculusXRBoundaryVisibility ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene" },
		{ "ModuleRelativePath", "Public/OculusXRSceneSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRSceneSubsystem_eventGetRequestedBoundaryVisibility_Parms, ReturnValue), Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility, METADATA_PARAMS(0, nullptr) }; // 1439512401
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRSceneSubsystem, nullptr, "GetRequestedBoundaryVisibility", nullptr, nullptr, Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics::OculusXRSceneSubsystem_eventGetRequestedBoundaryVisibility_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics::OculusXRSceneSubsystem_eventGetRequestedBoundaryVisibility_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRSceneSubsystem::execGetRequestedBoundaryVisibility)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EOculusXRBoundaryVisibility*)Z_Param__Result=P_THIS->GetRequestedBoundaryVisibility();
	P_NATIVE_END;
}
// End Class UOculusXRSceneSubsystem Function GetRequestedBoundaryVisibility

// Begin Class UOculusXRSceneSubsystem Function SetRequestedBoundaryVisibility
struct Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics
{
	struct OculusXRSceneSubsystem_eventSetRequestedBoundaryVisibility_Parms
	{
		EOculusXRBoundaryVisibility Visibility;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene" },
		{ "ModuleRelativePath", "Public/OculusXRSceneSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Visibility_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Visibility;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics::NewProp_Visibility_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics::NewProp_Visibility = { "Visibility", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRSceneSubsystem_eventSetRequestedBoundaryVisibility_Parms, Visibility), Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility, METADATA_PARAMS(0, nullptr) }; // 1439512401
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics::NewProp_Visibility_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics::NewProp_Visibility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRSceneSubsystem, nullptr, "SetRequestedBoundaryVisibility", nullptr, nullptr, Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics::OculusXRSceneSubsystem_eventSetRequestedBoundaryVisibility_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics::OculusXRSceneSubsystem_eventSetRequestedBoundaryVisibility_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRSceneSubsystem::execSetRequestedBoundaryVisibility)
{
	P_GET_ENUM(EOculusXRBoundaryVisibility,Z_Param_Visibility);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetRequestedBoundaryVisibility(EOculusXRBoundaryVisibility(Z_Param_Visibility));
	P_NATIVE_END;
}
// End Class UOculusXRSceneSubsystem Function SetRequestedBoundaryVisibility

// Begin Class UOculusXRSceneSubsystem
void UOculusXRSceneSubsystem::StaticRegisterNativesUOculusXRSceneSubsystem()
{
	UClass* Class = UOculusXRSceneSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetBoundaryVisibility", &UOculusXRSceneSubsystem::execGetBoundaryVisibility },
		{ "GetRequestedBoundaryVisibility", &UOculusXRSceneSubsystem::execGetRequestedBoundaryVisibility },
		{ "SetRequestedBoundaryVisibility", &UOculusXRSceneSubsystem::execSetRequestedBoundaryVisibility },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRSceneSubsystem);
UClass* Z_Construct_UClass_UOculusXRSceneSubsystem_NoRegister()
{
	return UOculusXRSceneSubsystem::StaticClass();
}
struct Z_Construct_UClass_UOculusXRSceneSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "OculusXRSceneSubsystem.h" },
		{ "ModuleRelativePath", "Public/OculusXRSceneSubsystem.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOculusXRSceneSubsystem_GetBoundaryVisibility, "GetBoundaryVisibility" }, // 894211442
		{ &Z_Construct_UFunction_UOculusXRSceneSubsystem_GetRequestedBoundaryVisibility, "GetRequestedBoundaryVisibility" }, // 1410752313
		{ &Z_Construct_UFunction_UOculusXRSceneSubsystem_SetRequestedBoundaryVisibility, "SetRequestedBoundaryVisibility" }, // 1817965372
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRSceneSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UOculusXRSceneSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRScene,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRSceneSubsystem_Statics::ClassParams = {
	&UOculusXRSceneSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRSceneSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRSceneSubsystem()
{
	if (!Z_Registration_Info_UClass_UOculusXRSceneSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRSceneSubsystem.OuterSingleton, Z_Construct_UClass_UOculusXRSceneSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRSceneSubsystem.OuterSingleton;
}
template<> OCULUSXRSCENE_API UClass* StaticClass<UOculusXRSceneSubsystem>()
{
	return UOculusXRSceneSubsystem::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRSceneSubsystem);
UOculusXRSceneSubsystem::~UOculusXRSceneSubsystem() {}
// End Class UOculusXRSceneSubsystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneSubsystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRSceneSubsystem, UOculusXRSceneSubsystem::StaticClass, TEXT("UOculusXRSceneSubsystem"), &Z_Registration_Info_UClass_UOculusXRSceneSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRSceneSubsystem), 3698302774U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneSubsystem_h_721734388(TEXT("/Script/OculusXRScene"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneSubsystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
