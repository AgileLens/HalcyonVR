// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRProjectSetupTool/Public/OculusXRSetupRule.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRSetupRule() {}

// Begin Cross Module References
OCULUSXRPROJECTSETUPTOOL_API UEnum* Z_Construct_UEnum_OculusXRProjectSetupTool_ESetupRulePlatform();
UPackage* Z_Construct_UPackage__Script_OculusXRProjectSetupTool();
// End Cross Module References

// Begin Enum ESetupRulePlatform
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESetupRulePlatform;
static UEnum* ESetupRulePlatform_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESetupRulePlatform.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESetupRulePlatform.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRProjectSetupTool_ESetupRulePlatform, (UObject*)Z_Construct_UPackage__Script_OculusXRProjectSetupTool(), TEXT("ESetupRulePlatform"));
	}
	return Z_Registration_Info_UEnum_ESetupRulePlatform.OuterSingleton;
}
template<> OCULUSXRPROJECTSETUPTOOL_API UEnum* StaticEnum<ESetupRulePlatform>()
{
	return ESetupRulePlatform_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRProjectSetupTool_ESetupRulePlatform_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Rule platforms\n */" },
#endif
		{ "MetaLink.Comment", "// Link\n" },
		{ "MetaLink.DisplayName", "Link" },
		{ "MetaLink.Name", "ESetupRulePlatform::MetaLink" },
		{ "MetaLink.ToolTip", "Link" },
		{ "MetaQuest_2.Comment", "// Quest\n" },
		{ "MetaQuest_2.DisplayName", "Quest 2" },
		{ "MetaQuest_2.Name", "ESetupRulePlatform::MetaQuest_2" },
		{ "MetaQuest_2.ToolTip", "Quest" },
		{ "MetaQuest_3.DisplayName", "Quest 3" },
		{ "MetaQuest_3.Name", "ESetupRulePlatform::MetaQuest_3" },
		{ "MetaQuest_Pro.DisplayName", "Quest Pro" },
		{ "MetaQuest_Pro.Name", "ESetupRulePlatform::MetaQuest_Pro" },
		{ "ModuleRelativePath", "Public/OculusXRSetupRule.h" },
		{ "None.Comment", "// None\n" },
		{ "None.Name", "ESetupRulePlatform::None" },
		{ "None.ToolTip", "None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rule platforms" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESetupRulePlatform::None", (int64)ESetupRulePlatform::None },
		{ "ESetupRulePlatform::MetaLink", (int64)ESetupRulePlatform::MetaLink },
		{ "ESetupRulePlatform::MetaQuest_2", (int64)ESetupRulePlatform::MetaQuest_2 },
		{ "ESetupRulePlatform::MetaQuest_3", (int64)ESetupRulePlatform::MetaQuest_3 },
		{ "ESetupRulePlatform::MetaQuest_Pro", (int64)ESetupRulePlatform::MetaQuest_Pro },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRProjectSetupTool_ESetupRulePlatform_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRProjectSetupTool,
	nullptr,
	"ESetupRulePlatform",
	"ESetupRulePlatform",
	Z_Construct_UEnum_OculusXRProjectSetupTool_ESetupRulePlatform_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRProjectSetupTool_ESetupRulePlatform_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRProjectSetupTool_ESetupRulePlatform_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRProjectSetupTool_ESetupRulePlatform_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRProjectSetupTool_ESetupRulePlatform()
{
	if (!Z_Registration_Info_UEnum_ESetupRulePlatform.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESetupRulePlatform.InnerSingleton, Z_Construct_UEnum_OculusXRProjectSetupTool_ESetupRulePlatform_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESetupRulePlatform.InnerSingleton;
}
// End Enum ESetupRulePlatform

// Begin Registration
struct Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRProjectSetupTool_Public_OculusXRSetupRule_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ESetupRulePlatform_StaticEnum, TEXT("ESetupRulePlatform"), &Z_Registration_Info_UEnum_ESetupRulePlatform, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1951508977U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRProjectSetupTool_Public_OculusXRSetupRule_h_3613461101(TEXT("/Script/OculusXRProjectSetupTool"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRProjectSetupTool_Public_OculusXRSetupRule_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRProjectSetupTool_Public_OculusXRSetupRule_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
