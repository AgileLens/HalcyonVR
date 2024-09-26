// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRHMD/Private/OculusXRTelemetryPrivacySettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRTelemetryPrivacySettings() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_UImportantToggleSettingInterface_NoRegister();
OCULUSXRHMD_API UClass* Z_Construct_UClass_UOculusXRTelemetryPrivacySettings();
OCULUSXRHMD_API UClass* Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_OculusXRHMD();
// End Cross Module References

// Begin Class UOculusXRTelemetryPrivacySettings
void UOculusXRTelemetryPrivacySettings::StaticRegisterNativesUOculusXRTelemetryPrivacySettings()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRTelemetryPrivacySettings);
UClass* Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_NoRegister()
{
	return UOculusXRTelemetryPrivacySettings::StaticClass();
}
struct Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "OculusXRTelemetryPrivacySettings.h" },
		{ "ModuleRelativePath", "Private/OculusXRTelemetryPrivacySettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsEnabled_MetaData[] = {
		{ "Category", "Options" },
		{ "ModuleRelativePath", "Private/OculusXRTelemetryPrivacySettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasNotified_MetaData[] = {
		{ "ModuleRelativePath", "Private/OculusXRTelemetryPrivacySettings.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bIsEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsEnabled;
	static void NewProp_bHasNotified_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasNotified;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRTelemetryPrivacySettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::NewProp_bIsEnabled_SetBit(void* Obj)
{
	((UOculusXRTelemetryPrivacySettings*)Obj)->bIsEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::NewProp_bIsEnabled = { "bIsEnabled", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRTelemetryPrivacySettings), &Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::NewProp_bIsEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsEnabled_MetaData), NewProp_bIsEnabled_MetaData) };
void Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::NewProp_bHasNotified_SetBit(void* Obj)
{
	((UOculusXRTelemetryPrivacySettings*)Obj)->bHasNotified = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::NewProp_bHasNotified = { "bHasNotified", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRTelemetryPrivacySettings), &Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::NewProp_bHasNotified_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasNotified_MetaData), NewProp_bHasNotified_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::NewProp_bIsEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::NewProp_bHasNotified,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRHMD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UImportantToggleSettingInterface_NoRegister, (int32)VTABLE_OFFSET(UOculusXRTelemetryPrivacySettings, IImportantToggleSettingInterface), false },  // 3659353408
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::ClassParams = {
	&UOculusXRTelemetryPrivacySettings::StaticClass,
	"EditorSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x000800A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRTelemetryPrivacySettings()
{
	if (!Z_Registration_Info_UClass_UOculusXRTelemetryPrivacySettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRTelemetryPrivacySettings.OuterSingleton, Z_Construct_UClass_UOculusXRTelemetryPrivacySettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRTelemetryPrivacySettings.OuterSingleton;
}
template<> OCULUSXRHMD_API UClass* StaticClass<UOculusXRTelemetryPrivacySettings>()
{
	return UOculusXRTelemetryPrivacySettings::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRTelemetryPrivacySettings);
UOculusXRTelemetryPrivacySettings::~UOculusXRTelemetryPrivacySettings() {}
// End Class UOculusXRTelemetryPrivacySettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Private_OculusXRTelemetryPrivacySettings_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRTelemetryPrivacySettings, UOculusXRTelemetryPrivacySettings::StaticClass, TEXT("UOculusXRTelemetryPrivacySettings"), &Z_Registration_Info_UClass_UOculusXRTelemetryPrivacySettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRTelemetryPrivacySettings), 2598987775U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Private_OculusXRTelemetryPrivacySettings_h_3772050213(TEXT("/Script/OculusXRHMD"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Private_OculusXRTelemetryPrivacySettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Private_OculusXRTelemetryPrivacySettings_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
