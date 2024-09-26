// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRHMD/Public/OculusXRMultiPlayerTestingSubsystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRMultiPlayerTestingSubsystem() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UEngineSubsystem();
OCULUSXRHMD_API UClass* Z_Construct_UClass_UOculusXRMultiPlayerTestingSubsystem();
OCULUSXRHMD_API UClass* Z_Construct_UClass_UOculusXRMultiPlayerTestingSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_OculusXRHMD();
// End Cross Module References

// Begin Class UOculusXRMultiPlayerTestingSubsystem
void UOculusXRMultiPlayerTestingSubsystem::StaticRegisterNativesUOculusXRMultiPlayerTestingSubsystem()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRMultiPlayerTestingSubsystem);
UClass* Z_Construct_UClass_UOculusXRMultiPlayerTestingSubsystem_NoRegister()
{
	return UOculusXRMultiPlayerTestingSubsystem::StaticClass();
}
struct Z_Construct_UClass_UOculusXRMultiPlayerTestingSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n * The rule processor handles registration and querying of rules\n */" },
		{ "IncludePath", "OculusXRMultiPlayerTestingSubsystem.h" },
		{ "ModuleRelativePath", "Public/OculusXRMultiPlayerTestingSubsystem.h" },
		{ "ToolTip", "The rule processor handles registration and querying of rules" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRMultiPlayerTestingSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UOculusXRMultiPlayerTestingSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEngineSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRHMD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRMultiPlayerTestingSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRMultiPlayerTestingSubsystem_Statics::ClassParams = {
	&UOculusXRMultiPlayerTestingSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRMultiPlayerTestingSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRMultiPlayerTestingSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRMultiPlayerTestingSubsystem()
{
	if (!Z_Registration_Info_UClass_UOculusXRMultiPlayerTestingSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRMultiPlayerTestingSubsystem.OuterSingleton, Z_Construct_UClass_UOculusXRMultiPlayerTestingSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRMultiPlayerTestingSubsystem.OuterSingleton;
}
template<> OCULUSXRHMD_API UClass* StaticClass<UOculusXRMultiPlayerTestingSubsystem>()
{
	return UOculusXRMultiPlayerTestingSubsystem::StaticClass();
}
UOculusXRMultiPlayerTestingSubsystem::UOculusXRMultiPlayerTestingSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRMultiPlayerTestingSubsystem);
UOculusXRMultiPlayerTestingSubsystem::~UOculusXRMultiPlayerTestingSubsystem() {}
// End Class UOculusXRMultiPlayerTestingSubsystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXRMultiPlayerTestingSubsystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRMultiPlayerTestingSubsystem, UOculusXRMultiPlayerTestingSubsystem::StaticClass, TEXT("UOculusXRMultiPlayerTestingSubsystem"), &Z_Registration_Info_UClass_UOculusXRMultiPlayerTestingSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRMultiPlayerTestingSubsystem), 794132511U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXRMultiPlayerTestingSubsystem_h_2287002820(TEXT("/Script/OculusXRHMD"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXRMultiPlayerTestingSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXRMultiPlayerTestingSubsystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
