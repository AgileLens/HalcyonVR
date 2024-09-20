// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MetaXRHaptics/Private/MetaXRHapticsGameInstanceSubsystem.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMetaXRHapticsGameInstanceSubsystem() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
METAXRHAPTICS_API UClass* Z_Construct_UClass_UMetaXRHapticsGameInstanceSubsystem();
METAXRHAPTICS_API UClass* Z_Construct_UClass_UMetaXRHapticsGameInstanceSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_MetaXRHaptics();
// End Cross Module References

// Begin Class UMetaXRHapticsGameInstanceSubsystem
void UMetaXRHapticsGameInstanceSubsystem::StaticRegisterNativesUMetaXRHapticsGameInstanceSubsystem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMetaXRHapticsGameInstanceSubsystem);
UClass* Z_Construct_UClass_UMetaXRHapticsGameInstanceSubsystem_NoRegister()
{
	return UMetaXRHapticsGameInstanceSubsystem::StaticClass();
}
struct Z_Construct_UClass_UMetaXRHapticsGameInstanceSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * The game instance subsystem is responsible for initializing and uninitializing the native\n * library.\n */" },
		{ "IncludePath", "MetaXRHapticsGameInstanceSubsystem.h" },
		{ "ModuleRelativePath", "Private/MetaXRHapticsGameInstanceSubsystem.h" },
		{ "ToolTip", "The game instance subsystem is responsible for initializing and uninitializing the native\nlibrary." },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMetaXRHapticsGameInstanceSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMetaXRHapticsGameInstanceSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_MetaXRHaptics,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMetaXRHapticsGameInstanceSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMetaXRHapticsGameInstanceSubsystem_Statics::ClassParams = {
	&UMetaXRHapticsGameInstanceSubsystem::StaticClass,
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
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMetaXRHapticsGameInstanceSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UMetaXRHapticsGameInstanceSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMetaXRHapticsGameInstanceSubsystem()
{
	if (!Z_Registration_Info_UClass_UMetaXRHapticsGameInstanceSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMetaXRHapticsGameInstanceSubsystem.OuterSingleton, Z_Construct_UClass_UMetaXRHapticsGameInstanceSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMetaXRHapticsGameInstanceSubsystem.OuterSingleton;
}
template<> METAXRHAPTICS_API UClass* StaticClass<UMetaXRHapticsGameInstanceSubsystem>()
{
	return UMetaXRHapticsGameInstanceSubsystem::StaticClass();
}
UMetaXRHapticsGameInstanceSubsystem::UMetaXRHapticsGameInstanceSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMetaXRHapticsGameInstanceSubsystem);
UMetaXRHapticsGameInstanceSubsystem::~UMetaXRHapticsGameInstanceSubsystem() {}
// End Class UMetaXRHapticsGameInstanceSubsystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Private_MetaXRHapticsGameInstanceSubsystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMetaXRHapticsGameInstanceSubsystem, UMetaXRHapticsGameInstanceSubsystem::StaticClass, TEXT("UMetaXRHapticsGameInstanceSubsystem"), &Z_Registration_Info_UClass_UMetaXRHapticsGameInstanceSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMetaXRHapticsGameInstanceSubsystem), 3174225180U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Private_MetaXRHapticsGameInstanceSubsystem_h_2144281903(TEXT("/Script/MetaXRHaptics"),
	Z_CompiledInDeferFile_FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Private_MetaXRHapticsGameInstanceSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Private_MetaXRHapticsGameInstanceSubsystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
