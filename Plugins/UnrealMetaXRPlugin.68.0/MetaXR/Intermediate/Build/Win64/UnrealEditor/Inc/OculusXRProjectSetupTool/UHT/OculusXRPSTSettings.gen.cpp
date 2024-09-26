// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRProjectSetupTool/Public/OculusXRPSTSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRPSTSettings() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
OCULUSXRPROJECTSETUPTOOL_API UClass* Z_Construct_UClass_UOculusXRPSTSettings();
OCULUSXRPROJECTSETUPTOOL_API UClass* Z_Construct_UClass_UOculusXRPSTSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_OculusXRProjectSetupTool();
// End Cross Module References

// Begin Class UOculusXRPSTSettings
void UOculusXRPSTSettings::StaticRegisterNativesUOculusXRPSTSettings()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRPSTSettings);
UClass* Z_Construct_UClass_UOculusXRPSTSettings_NoRegister()
{
	return UOculusXRPSTSettings::StaticClass();
}
struct Z_Construct_UClass_UOculusXRPSTSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Meta XR Project Setup tool Settings\n */" },
#endif
		{ "IncludePath", "OculusXRPSTSettings.h" },
		{ "ModuleRelativePath", "Public/OculusXRPSTSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Meta XR Project Setup tool Settings" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IgnoredRules_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Ignored rules by developer\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRPSTSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Ignored rules by developer" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentPlatform_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Selected platform for development\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRPSTSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Selected platform for development" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bBackGroundChecks_MetaData[] = {
		{ "Category", "MetaXR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief If tools should periodically check if list of rules and rules' status\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRPSTSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief If tools should periodically check if list of rules and rules' status" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStopBuildOnUnAppliedCriticalItems_MetaData[] = {
		{ "Category", "MetaXR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief If build should fail if critical rule is not applied\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRPSTSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief If build should fail if critical rule is not applied" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bGuidedTutorialComplete_MetaData[] = {
		{ "Category", "MetaXR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief If guided tutorial has been completed/skipped\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRPSTSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief If guided tutorial has been completed/skipped" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowGuidedTutorial_MetaData[] = {
		{ "Category", "MetaXR" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief If guided tutorial showed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRPSTSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief If guided tutorial showed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_IgnoredRules_ElementProp;
	static const UECodeGen_Private::FSetPropertyParams NewProp_IgnoredRules;
	static const UECodeGen_Private::FUInt32PropertyParams NewProp_CurrentPlatform;
	static void NewProp_bBackGroundChecks_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bBackGroundChecks;
	static void NewProp_bStopBuildOnUnAppliedCriticalItems_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopBuildOnUnAppliedCriticalItems;
	static void NewProp_bGuidedTutorialComplete_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bGuidedTutorialComplete;
	static void NewProp_bShowGuidedTutorial_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowGuidedTutorial;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRPSTSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_IgnoredRules_ElementProp = { "IgnoredRules", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_IgnoredRules = { "IgnoredRules", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRPSTSettings, IgnoredRules), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IgnoredRules_MetaData), NewProp_IgnoredRules_MetaData) };
const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_CurrentPlatform = { "CurrentPlatform", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRPSTSettings, CurrentPlatform), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentPlatform_MetaData), NewProp_CurrentPlatform_MetaData) };
void Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bBackGroundChecks_SetBit(void* Obj)
{
	((UOculusXRPSTSettings*)Obj)->bBackGroundChecks = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bBackGroundChecks = { "bBackGroundChecks", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRPSTSettings), &Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bBackGroundChecks_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bBackGroundChecks_MetaData), NewProp_bBackGroundChecks_MetaData) };
void Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bStopBuildOnUnAppliedCriticalItems_SetBit(void* Obj)
{
	((UOculusXRPSTSettings*)Obj)->bStopBuildOnUnAppliedCriticalItems = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bStopBuildOnUnAppliedCriticalItems = { "bStopBuildOnUnAppliedCriticalItems", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRPSTSettings), &Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bStopBuildOnUnAppliedCriticalItems_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStopBuildOnUnAppliedCriticalItems_MetaData), NewProp_bStopBuildOnUnAppliedCriticalItems_MetaData) };
void Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bGuidedTutorialComplete_SetBit(void* Obj)
{
	((UOculusXRPSTSettings*)Obj)->bGuidedTutorialComplete = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bGuidedTutorialComplete = { "bGuidedTutorialComplete", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRPSTSettings), &Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bGuidedTutorialComplete_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bGuidedTutorialComplete_MetaData), NewProp_bGuidedTutorialComplete_MetaData) };
void Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bShowGuidedTutorial_SetBit(void* Obj)
{
	((UOculusXRPSTSettings*)Obj)->bShowGuidedTutorial = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bShowGuidedTutorial = { "bShowGuidedTutorial", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRPSTSettings), &Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bShowGuidedTutorial_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowGuidedTutorial_MetaData), NewProp_bShowGuidedTutorial_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRPSTSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_IgnoredRules_ElementProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_IgnoredRules,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_CurrentPlatform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bBackGroundChecks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bStopBuildOnUnAppliedCriticalItems,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bGuidedTutorialComplete,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRPSTSettings_Statics::NewProp_bShowGuidedTutorial,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRPSTSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRPSTSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRProjectSetupTool,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRPSTSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRPSTSettings_Statics::ClassParams = {
	&UOculusXRPSTSettings::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOculusXRPSTSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRPSTSettings_Statics::PropPointers),
	0,
	0x001000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRPSTSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRPSTSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRPSTSettings()
{
	if (!Z_Registration_Info_UClass_UOculusXRPSTSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRPSTSettings.OuterSingleton, Z_Construct_UClass_UOculusXRPSTSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRPSTSettings.OuterSingleton;
}
template<> OCULUSXRPROJECTSETUPTOOL_API UClass* StaticClass<UOculusXRPSTSettings>()
{
	return UOculusXRPSTSettings::StaticClass();
}
UOculusXRPSTSettings::UOculusXRPSTSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRPSTSettings);
UOculusXRPSTSettings::~UOculusXRPSTSettings() {}
// End Class UOculusXRPSTSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRProjectSetupTool_Public_OculusXRPSTSettings_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRPSTSettings, UOculusXRPSTSettings::StaticClass, TEXT("UOculusXRPSTSettings"), &Z_Registration_Info_UClass_UOculusXRPSTSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRPSTSettings), 2007067904U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRProjectSetupTool_Public_OculusXRPSTSettings_h_482883530(TEXT("/Script/OculusXRProjectSetupTool"),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRProjectSetupTool_Public_OculusXRPSTSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRProjectSetupTool_Public_OculusXRPSTSettings_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
