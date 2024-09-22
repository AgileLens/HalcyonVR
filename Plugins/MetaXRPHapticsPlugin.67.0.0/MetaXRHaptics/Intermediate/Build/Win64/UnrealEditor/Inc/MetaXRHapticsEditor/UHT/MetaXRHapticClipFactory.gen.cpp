// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MetaXRHapticsEditor/Private/MetaXRHapticClipFactory.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMetaXRHapticClipFactory() {}

// Begin Cross Module References
METAXRHAPTICSEDITOR_API UClass* Z_Construct_UClass_UMetaXRHapticClipFactory();
METAXRHAPTICSEDITOR_API UClass* Z_Construct_UClass_UMetaXRHapticClipFactory_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UFactory();
UPackage* Z_Construct_UPackage__Script_MetaXRHapticsEditor();
// End Cross Module References

// Begin Class UMetaXRHapticClipFactory
void UMetaXRHapticClipFactory::StaticRegisterNativesUMetaXRHapticClipFactory()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMetaXRHapticClipFactory);
UClass* Z_Construct_UClass_UMetaXRHapticClipFactory_NoRegister()
{
	return UMetaXRHapticClipFactory::StaticClass();
}
struct Z_Construct_UClass_UMetaXRHapticClipFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MetaXRHapticClipFactory.h" },
		{ "ModuleRelativePath", "Private/MetaXRHapticClipFactory.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMetaXRHapticClipFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMetaXRHapticClipFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UFactory,
	(UObject* (*)())Z_Construct_UPackage__Script_MetaXRHapticsEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMetaXRHapticClipFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMetaXRHapticClipFactory_Statics::ClassParams = {
	&UMetaXRHapticClipFactory::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMetaXRHapticClipFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UMetaXRHapticClipFactory_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMetaXRHapticClipFactory()
{
	if (!Z_Registration_Info_UClass_UMetaXRHapticClipFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMetaXRHapticClipFactory.OuterSingleton, Z_Construct_UClass_UMetaXRHapticClipFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMetaXRHapticClipFactory.OuterSingleton;
}
template<> METAXRHAPTICSEDITOR_API UClass* StaticClass<UMetaXRHapticClipFactory>()
{
	return UMetaXRHapticClipFactory::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMetaXRHapticClipFactory);
UMetaXRHapticClipFactory::~UMetaXRHapticClipFactory() {}
// End Class UMetaXRHapticClipFactory

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHapticsEditor_Private_MetaXRHapticClipFactory_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMetaXRHapticClipFactory, UMetaXRHapticClipFactory::StaticClass, TEXT("UMetaXRHapticClipFactory"), &Z_Registration_Info_UClass_UMetaXRHapticClipFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMetaXRHapticClipFactory), 3650883068U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHapticsEditor_Private_MetaXRHapticClipFactory_h_469851299(TEXT("/Script/MetaXRHapticsEditor"),
	Z_CompiledInDeferFile_FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHapticsEditor_Private_MetaXRHapticClipFactory_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHapticsEditor_Private_MetaXRHapticClipFactory_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
