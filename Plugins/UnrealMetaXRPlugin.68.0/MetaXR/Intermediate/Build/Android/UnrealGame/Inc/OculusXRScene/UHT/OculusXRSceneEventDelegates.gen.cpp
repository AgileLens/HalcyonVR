// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRScene/Public/OculusXRSceneEventDelegates.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRSceneEventDelegates() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UEngineSubsystem();
OCULUSXRSCENE_API UClass* Z_Construct_UClass_UOculusXRSceneEventDelegates();
OCULUSXRSCENE_API UClass* Z_Construct_UClass_UOculusXRSceneEventDelegates_NoRegister();
OCULUSXRSCENE_API UEnum* Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility();
OCULUSXRSCENE_API UFunction* Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_OculusXRScene();
// End Cross Module References

// Begin Delegate FOculusXRScene_BoundaryVisibilityChanged
struct Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics
{
	struct _Script_OculusXRScene_eventOculusXRScene_BoundaryVisibilityChanged_Parms
	{
		EOculusXRBoundaryVisibility BoundaryVisibility;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OculusXRSceneEventDelegates.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_BoundaryVisibility_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BoundaryVisibility;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics::NewProp_BoundaryVisibility_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics::NewProp_BoundaryVisibility = { "BoundaryVisibility", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OculusXRScene_eventOculusXRScene_BoundaryVisibilityChanged_Parms, BoundaryVisibility), Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility, METADATA_PARAMS(0, nullptr) }; // 1439512401
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics::NewProp_BoundaryVisibility_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics::NewProp_BoundaryVisibility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OculusXRScene, nullptr, "OculusXRScene_BoundaryVisibilityChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics::_Script_OculusXRScene_eventOculusXRScene_BoundaryVisibilityChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics::_Script_OculusXRScene_eventOculusXRScene_BoundaryVisibilityChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOculusXRScene_BoundaryVisibilityChanged_DelegateWrapper(const FMulticastScriptDelegate& OculusXRScene_BoundaryVisibilityChanged, EOculusXRBoundaryVisibility BoundaryVisibility)
{
	struct _Script_OculusXRScene_eventOculusXRScene_BoundaryVisibilityChanged_Parms
	{
		EOculusXRBoundaryVisibility BoundaryVisibility;
	};
	_Script_OculusXRScene_eventOculusXRScene_BoundaryVisibilityChanged_Parms Parms;
	Parms.BoundaryVisibility=BoundaryVisibility;
	OculusXRScene_BoundaryVisibilityChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOculusXRScene_BoundaryVisibilityChanged

// Begin Class UOculusXRSceneEventDelegates
void UOculusXRSceneEventDelegates::StaticRegisterNativesUOculusXRSceneEventDelegates()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRSceneEventDelegates);
UClass* Z_Construct_UClass_UOculusXRSceneEventDelegates_NoRegister()
{
	return UOculusXRSceneEventDelegates::StaticClass();
}
struct Z_Construct_UClass_UOculusXRSceneEventDelegates_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "OculusXRSceneEventDelegates.h" },
		{ "ModuleRelativePath", "Public/OculusXRSceneEventDelegates.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnBoundaryVisibilityChanged_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRSceneEventDelegates.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnBoundaryVisibilityChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRSceneEventDelegates>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UOculusXRSceneEventDelegates_Statics::NewProp_OnBoundaryVisibilityChanged = { "OnBoundaryVisibilityChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRSceneEventDelegates, OnBoundaryVisibilityChanged), Z_Construct_UDelegateFunction_OculusXRScene_OculusXRScene_BoundaryVisibilityChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnBoundaryVisibilityChanged_MetaData), NewProp_OnBoundaryVisibilityChanged_MetaData) }; // 3701824866
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRSceneEventDelegates_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRSceneEventDelegates_Statics::NewProp_OnBoundaryVisibilityChanged,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneEventDelegates_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRSceneEventDelegates_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEngineSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRScene,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneEventDelegates_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRSceneEventDelegates_Statics::ClassParams = {
	&UOculusXRSceneEventDelegates::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOculusXRSceneEventDelegates_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneEventDelegates_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneEventDelegates_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRSceneEventDelegates_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRSceneEventDelegates()
{
	if (!Z_Registration_Info_UClass_UOculusXRSceneEventDelegates.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRSceneEventDelegates.OuterSingleton, Z_Construct_UClass_UOculusXRSceneEventDelegates_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRSceneEventDelegates.OuterSingleton;
}
template<> OCULUSXRSCENE_API UClass* StaticClass<UOculusXRSceneEventDelegates>()
{
	return UOculusXRSceneEventDelegates::StaticClass();
}
UOculusXRSceneEventDelegates::UOculusXRSceneEventDelegates() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRSceneEventDelegates);
UOculusXRSceneEventDelegates::~UOculusXRSceneEventDelegates() {}
// End Class UOculusXRSceneEventDelegates

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneEventDelegates_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRSceneEventDelegates, UOculusXRSceneEventDelegates::StaticClass, TEXT("UOculusXRSceneEventDelegates"), &Z_Registration_Info_UClass_UOculusXRSceneEventDelegates, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRSceneEventDelegates), 1666777956U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneEventDelegates_h_967509793(TEXT("/Script/OculusXRScene"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneEventDelegates_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneEventDelegates_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
