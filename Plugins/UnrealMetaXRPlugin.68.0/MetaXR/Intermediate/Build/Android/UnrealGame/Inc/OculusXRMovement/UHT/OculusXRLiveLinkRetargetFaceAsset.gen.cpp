// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRMovement/Public/OculusXRLiveLinkRetargetFaceAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRLiveLinkRetargetFaceAsset() {}

// Begin Cross Module References
LIVELINKANIMATIONCORE_API UClass* Z_Construct_UClass_ULiveLinkRetargetAsset();
OCULUSXRMOVEMENT_API UClass* Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset();
OCULUSXRMOVEMENT_API UClass* Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_NoRegister();
OCULUSXRMOVEMENT_API UEnum* Z_Construct_UEnum_OculusXRMovement_EOculusXRFaceExpression();
OCULUSXRMOVEMENT_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping();
UPackage* Z_Construct_UPackage__Script_OculusXRMovement();
// End Cross Module References

// Begin ScriptStruct FOculusXRAnimCurveMapping
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OculusXRAnimCurveMapping;
class UScriptStruct* FOculusXRAnimCurveMapping::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRAnimCurveMapping.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OculusXRAnimCurveMapping.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping, (UObject*)Z_Construct_UPackage__Script_OculusXRMovement(), TEXT("OculusXRAnimCurveMapping"));
	}
	return Z_Registration_Info_UScriptStruct_OculusXRAnimCurveMapping.OuterSingleton;
}
template<> OCULUSXRMOVEMENT_API UScriptStruct* StaticStruct<FOculusXRAnimCurveMapping>()
{
	return FOculusXRAnimCurveMapping::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetFaceAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurveNames_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * Skeleton's animation curve names\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetFaceAsset.h" },
		{ "ToolTip", "Skeleton's animation curve names" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_CurveNames_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CurveNames;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOculusXRAnimCurveMapping>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping_Statics::NewProp_CurveNames_Inner = { "CurveNames", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping_Statics::NewProp_CurveNames = { "CurveNames", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRAnimCurveMapping, CurveNames), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurveNames_MetaData), NewProp_CurveNames_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping_Statics::NewProp_CurveNames_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping_Statics::NewProp_CurveNames,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRMovement,
	nullptr,
	&NewStructOps,
	"OculusXRAnimCurveMapping",
	Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping_Statics::PropPointers),
	sizeof(FOculusXRAnimCurveMapping),
	alignof(FOculusXRAnimCurveMapping),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRAnimCurveMapping.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OculusXRAnimCurveMapping.InnerSingleton, Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OculusXRAnimCurveMapping.InnerSingleton;
}
// End ScriptStruct FOculusXRAnimCurveMapping

// Begin Class UOculusXRLiveLinkRetargetFaceAsset
void UOculusXRLiveLinkRetargetFaceAsset::StaticRegisterNativesUOculusXRLiveLinkRetargetFaceAsset()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRLiveLinkRetargetFaceAsset);
UClass* Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_NoRegister()
{
	return UOculusXRLiveLinkRetargetFaceAsset::StaticClass();
}
struct Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "OculusXRHMD" },
		{ "DisplayName", "MetaXR MovementSDK LiveLink retarget face asset" },
		{ "IncludePath", "OculusXRLiveLinkRetargetFaceAsset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetFaceAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurveRemapping_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * Map face expression to Skeleton's animation curve mapping names.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetFaceAsset.h" },
		{ "ToolTip", "Map face expression to Skeleton's animation curve mapping names." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurveRemapping_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurveRemapping_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurveRemapping_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_CurveRemapping;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRLiveLinkRetargetFaceAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::NewProp_CurveRemapping_ValueProp = { "CurveRemapping", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping, METADATA_PARAMS(0, nullptr) }; // 2528629887
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::NewProp_CurveRemapping_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::NewProp_CurveRemapping_Key_KeyProp = { "CurveRemapping_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_OculusXRMovement_EOculusXRFaceExpression, METADATA_PARAMS(0, nullptr) }; // 44156253
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::NewProp_CurveRemapping = { "CurveRemapping", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRLiveLinkRetargetFaceAsset, CurveRemapping), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurveRemapping_MetaData), NewProp_CurveRemapping_MetaData) }; // 44156253 2528629887
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::NewProp_CurveRemapping_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::NewProp_CurveRemapping_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::NewProp_CurveRemapping_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::NewProp_CurveRemapping,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULiveLinkRetargetAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRMovement,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::ClassParams = {
	&UOculusXRLiveLinkRetargetFaceAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset()
{
	if (!Z_Registration_Info_UClass_UOculusXRLiveLinkRetargetFaceAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRLiveLinkRetargetFaceAsset.OuterSingleton, Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRLiveLinkRetargetFaceAsset.OuterSingleton;
}
template<> OCULUSXRMOVEMENT_API UClass* StaticClass<UOculusXRLiveLinkRetargetFaceAsset>()
{
	return UOculusXRLiveLinkRetargetFaceAsset::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRLiveLinkRetargetFaceAsset);
UOculusXRLiveLinkRetargetFaceAsset::~UOculusXRLiveLinkRetargetFaceAsset() {}
// End Class UOculusXRLiveLinkRetargetFaceAsset

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetFaceAsset_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOculusXRAnimCurveMapping::StaticStruct, Z_Construct_UScriptStruct_FOculusXRAnimCurveMapping_Statics::NewStructOps, TEXT("OculusXRAnimCurveMapping"), &Z_Registration_Info_UScriptStruct_OculusXRAnimCurveMapping, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOculusXRAnimCurveMapping), 2528629887U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRLiveLinkRetargetFaceAsset, UOculusXRLiveLinkRetargetFaceAsset::StaticClass, TEXT("UOculusXRLiveLinkRetargetFaceAsset"), &Z_Registration_Info_UClass_UOculusXRLiveLinkRetargetFaceAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRLiveLinkRetargetFaceAsset), 1816541383U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetFaceAsset_h_330757142(TEXT("/Script/OculusXRMovement"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetFaceAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetFaceAsset_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetFaceAsset_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetFaceAsset_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
