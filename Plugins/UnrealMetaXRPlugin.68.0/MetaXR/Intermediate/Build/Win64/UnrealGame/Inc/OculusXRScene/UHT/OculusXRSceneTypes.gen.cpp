// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRScene/Public/OculusXRSceneTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRSceneTypes() {}

// Begin Cross Module References
OCULUSXRSCENE_API UEnum* Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility();
OCULUSXRSCENE_API UScriptStruct* Z_Construct_UScriptStruct_FSceneTypesPlaceholder();
UPackage* Z_Construct_UPackage__Script_OculusXRScene();
// End Cross Module References

// Begin ScriptStruct FSceneTypesPlaceholder
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SceneTypesPlaceholder;
class UScriptStruct* FSceneTypesPlaceholder::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SceneTypesPlaceholder.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SceneTypesPlaceholder.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSceneTypesPlaceholder, (UObject*)Z_Construct_UPackage__Script_OculusXRScene(), TEXT("SceneTypesPlaceholder"));
	}
	return Z_Registration_Info_UScriptStruct_SceneTypesPlaceholder.OuterSingleton;
}
template<> OCULUSXRSCENE_API UScriptStruct* StaticStruct<FSceneTypesPlaceholder>()
{
	return FSceneTypesPlaceholder::StaticStruct();
}
struct Z_Construct_UScriptStruct_FSceneTypesPlaceholder_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OculusXRSceneTypes.h" },
	};
#endif // WITH_METADATA
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSceneTypesPlaceholder>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSceneTypesPlaceholder_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRScene,
	nullptr,
	&NewStructOps,
	"SceneTypesPlaceholder",
	nullptr,
	0,
	sizeof(FSceneTypesPlaceholder),
	alignof(FSceneTypesPlaceholder),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSceneTypesPlaceholder_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSceneTypesPlaceholder_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSceneTypesPlaceholder()
{
	if (!Z_Registration_Info_UScriptStruct_SceneTypesPlaceholder.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SceneTypesPlaceholder.InnerSingleton, Z_Construct_UScriptStruct_FSceneTypesPlaceholder_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_SceneTypesPlaceholder.InnerSingleton;
}
// End ScriptStruct FSceneTypesPlaceholder

// Begin Enum EOculusXRBoundaryVisibility
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRBoundaryVisibility;
static UEnum* EOculusXRBoundaryVisibility_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRBoundaryVisibility.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRBoundaryVisibility.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility, (UObject*)Z_Construct_UPackage__Script_OculusXRScene(), TEXT("EOculusXRBoundaryVisibility"));
	}
	return Z_Registration_Info_UEnum_EOculusXRBoundaryVisibility.OuterSingleton;
}
template<> OCULUSXRSCENE_API UEnum* StaticEnum<EOculusXRBoundaryVisibility>()
{
	return EOculusXRBoundaryVisibility_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Invalid.Name", "EOculusXRBoundaryVisibility::Invalid" },
		{ "ModuleRelativePath", "Public/OculusXRSceneTypes.h" },
		{ "NotSuppressed.Name", "EOculusXRBoundaryVisibility::NotSuppressed" },
		{ "Suppressed.Name", "EOculusXRBoundaryVisibility::Suppressed" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRBoundaryVisibility::Invalid", (int64)EOculusXRBoundaryVisibility::Invalid },
		{ "EOculusXRBoundaryVisibility::NotSuppressed", (int64)EOculusXRBoundaryVisibility::NotSuppressed },
		{ "EOculusXRBoundaryVisibility::Suppressed", (int64)EOculusXRBoundaryVisibility::Suppressed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRScene,
	nullptr,
	"EOculusXRBoundaryVisibility",
	"EOculusXRBoundaryVisibility",
	Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility()
{
	if (!Z_Registration_Info_UEnum_EOculusXRBoundaryVisibility.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRBoundaryVisibility.InnerSingleton, Z_Construct_UEnum_OculusXRScene_EOculusXRBoundaryVisibility_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRBoundaryVisibility.InnerSingleton;
}
// End Enum EOculusXRBoundaryVisibility

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneTypes_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOculusXRBoundaryVisibility_StaticEnum, TEXT("EOculusXRBoundaryVisibility"), &Z_Registration_Info_UEnum_EOculusXRBoundaryVisibility, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1439512401U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FSceneTypesPlaceholder::StaticStruct, Z_Construct_UScriptStruct_FSceneTypesPlaceholder_Statics::NewStructOps, TEXT("SceneTypesPlaceholder"), &Z_Registration_Info_UScriptStruct_SceneTypesPlaceholder, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSceneTypesPlaceholder), 2073649506U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneTypes_h_2931422663(TEXT("/Script/OculusXRScene"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneTypes_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneTypes_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
