// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MetaXRHaptics/Public/MetaXRHapticClip.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMetaXRHapticClip() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
METAXRHAPTICS_API UClass* Z_Construct_UClass_UMetaXRHapticClip();
METAXRHAPTICS_API UClass* Z_Construct_UClass_UMetaXRHapticClip_NoRegister();
UPackage* Z_Construct_UPackage__Script_MetaXRHaptics();
// End Cross Module References

// Begin Class UMetaXRHapticClip
void UMetaXRHapticClip::StaticRegisterNativesUMetaXRHapticClip()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMetaXRHapticClip);
UClass* Z_Construct_UClass_UMetaXRHapticClip_NoRegister()
{
	return UMetaXRHapticClip::StaticClass();
}
struct Z_Construct_UClass_UMetaXRHapticClip_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "MetaXRHapticClip.h" },
		{ "ModuleRelativePath", "Public/MetaXRHapticClip.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClipData_MetaData[] = {
		{ "ModuleRelativePath", "Public/MetaXRHapticClip.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ClipData_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ClipData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMetaXRHapticClip>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UMetaXRHapticClip_Statics::NewProp_ClipData_Inner = { "ClipData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMetaXRHapticClip_Statics::NewProp_ClipData = { "ClipData", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMetaXRHapticClip, ClipData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClipData_MetaData), NewProp_ClipData_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMetaXRHapticClip_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMetaXRHapticClip_Statics::NewProp_ClipData_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMetaXRHapticClip_Statics::NewProp_ClipData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMetaXRHapticClip_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMetaXRHapticClip_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_MetaXRHaptics,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMetaXRHapticClip_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMetaXRHapticClip_Statics::ClassParams = {
	&UMetaXRHapticClip::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UMetaXRHapticClip_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UMetaXRHapticClip_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMetaXRHapticClip_Statics::Class_MetaDataParams), Z_Construct_UClass_UMetaXRHapticClip_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMetaXRHapticClip()
{
	if (!Z_Registration_Info_UClass_UMetaXRHapticClip.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMetaXRHapticClip.OuterSingleton, Z_Construct_UClass_UMetaXRHapticClip_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMetaXRHapticClip.OuterSingleton;
}
template<> METAXRHAPTICS_API UClass* StaticClass<UMetaXRHapticClip>()
{
	return UMetaXRHapticClip::StaticClass();
}
UMetaXRHapticClip::UMetaXRHapticClip(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMetaXRHapticClip);
UMetaXRHapticClip::~UMetaXRHapticClip() {}
// End Class UMetaXRHapticClip

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticClip_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMetaXRHapticClip, UMetaXRHapticClip::StaticClass, TEXT("UMetaXRHapticClip"), &Z_Registration_Info_UClass_UMetaXRHapticClip, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMetaXRHapticClip), 2033817146U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticClip_h_780514050(TEXT("/Script/MetaXRHaptics"),
	Z_CompiledInDeferFile_FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticClip_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticClip_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
