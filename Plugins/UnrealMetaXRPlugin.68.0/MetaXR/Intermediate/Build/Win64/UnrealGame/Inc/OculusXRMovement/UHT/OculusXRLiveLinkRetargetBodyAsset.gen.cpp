// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRMovement/Public/OculusXRLiveLinkRetargetBodyAsset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRLiveLinkRetargetBodyAsset() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
LIVELINKANIMATIONCORE_API UClass* Z_Construct_UClass_ULiveLinkRetargetAsset();
OCULUSXRMOVEMENT_API UClass* Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset();
OCULUSXRMOVEMENT_API UClass* Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_NoRegister();
OCULUSXRMOVEMENT_API UEnum* Z_Construct_UEnum_OculusXRMovement_EOculusXRAxis();
OCULUSXRMOVEMENT_API UEnum* Z_Construct_UEnum_OculusXRMovement_EOculusXRBoneID();
OCULUSXRMOVEMENT_API UEnum* Z_Construct_UEnum_OculusXRMovement_EOculusXRRetargetingMode();
OCULUSXRMOVEMENT_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRBoneCorrection();
OCULUSXRMOVEMENT_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet();
UPackage* Z_Construct_UPackage__Script_OculusXRMovement();
// End Cross Module References

// Begin Enum EOculusXRAxis
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRAxis;
static UEnum* EOculusXRAxis_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRAxis.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRAxis.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRMovement_EOculusXRAxis, (UObject*)Z_Construct_UPackage__Script_OculusXRMovement(), TEXT("EOculusXRAxis"));
	}
	return Z_Registration_Info_UEnum_EOculusXRAxis.OuterSingleton;
}
template<> OCULUSXRMOVEMENT_API UEnum* StaticEnum<EOculusXRAxis>()
{
	return EOculusXRAxis_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRMovement_EOculusXRAxis_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "Axis" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetBodyAsset.h" },
		{ "NegativeX.DisplayName", "-X" },
		{ "NegativeX.Name", "EOculusXRAxis::NegativeX" },
		{ "NegativeY.DisplayName", "-Y" },
		{ "NegativeY.Name", "EOculusXRAxis::NegativeY" },
		{ "NegativeZ.DisplayName", "-Z" },
		{ "NegativeZ.Name", "EOculusXRAxis::NegativeZ" },
		{ "X.DisplayName", "X" },
		{ "X.Name", "EOculusXRAxis::X" },
		{ "Y.DisplayName", "Y" },
		{ "Y.Name", "EOculusXRAxis::Y" },
		{ "Z.DisplayName", "Z" },
		{ "Z.Name", "EOculusXRAxis::Z" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRAxis::X", (int64)EOculusXRAxis::X },
		{ "EOculusXRAxis::Y", (int64)EOculusXRAxis::Y },
		{ "EOculusXRAxis::Z", (int64)EOculusXRAxis::Z },
		{ "EOculusXRAxis::NegativeX", (int64)EOculusXRAxis::NegativeX },
		{ "EOculusXRAxis::NegativeY", (int64)EOculusXRAxis::NegativeY },
		{ "EOculusXRAxis::NegativeZ", (int64)EOculusXRAxis::NegativeZ },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRMovement_EOculusXRAxis_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRMovement,
	nullptr,
	"EOculusXRAxis",
	"EOculusXRAxis",
	Z_Construct_UEnum_OculusXRMovement_EOculusXRAxis_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRMovement_EOculusXRAxis_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRMovement_EOculusXRAxis_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRMovement_EOculusXRAxis_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRMovement_EOculusXRAxis()
{
	if (!Z_Registration_Info_UEnum_EOculusXRAxis.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRAxis.InnerSingleton, Z_Construct_UEnum_OculusXRMovement_EOculusXRAxis_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRAxis.InnerSingleton;
}
// End Enum EOculusXRAxis

// Begin Enum EOculusXRRetargetingMode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRRetargetingMode;
static UEnum* EOculusXRRetargetingMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRRetargetingMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRRetargetingMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRMovement_EOculusXRRetargetingMode, (UObject*)Z_Construct_UPackage__Script_OculusXRMovement(), TEXT("EOculusXRRetargetingMode"));
	}
	return Z_Registration_Info_UEnum_EOculusXRRetargetingMode.OuterSingleton;
}
template<> OCULUSXRMOVEMENT_API UEnum* StaticEnum<EOculusXRRetargetingMode>()
{
	return EOculusXRRetargetingMode_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRMovement_EOculusXRRetargetingMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "Retargeting mode" },
		{ "Full.DisplayName", "Rotations and positions" },
		{ "Full.Name", "EOculusXRRetargetingMode::Full" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetBodyAsset.h" },
		{ "None.DisplayName", "Disabled" },
		{ "None.Name", "EOculusXRRetargetingMode::None" },
		{ "Rotations.DisplayName", "Only rotations" },
		{ "Rotations.Name", "EOculusXRRetargetingMode::Rotations" },
		{ "RotationsPlusHips.DisplayName", "Rotations and hips position" },
		{ "RotationsPlusHips.Name", "EOculusXRRetargetingMode::RotationsPlusHips" },
		{ "RotationsPlusRoot.DisplayName", "Rotations and root position" },
		{ "RotationsPlusRoot.Name", "EOculusXRRetargetingMode::RotationsPlusRoot" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRRetargetingMode::Full", (int64)EOculusXRRetargetingMode::Full },
		{ "EOculusXRRetargetingMode::Rotations", (int64)EOculusXRRetargetingMode::Rotations },
		{ "EOculusXRRetargetingMode::RotationsPlusRoot", (int64)EOculusXRRetargetingMode::RotationsPlusRoot },
		{ "EOculusXRRetargetingMode::RotationsPlusHips", (int64)EOculusXRRetargetingMode::RotationsPlusHips },
		{ "EOculusXRRetargetingMode::None", (int64)EOculusXRRetargetingMode::None },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRMovement_EOculusXRRetargetingMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRMovement,
	nullptr,
	"EOculusXRRetargetingMode",
	"EOculusXRRetargetingMode",
	Z_Construct_UEnum_OculusXRMovement_EOculusXRRetargetingMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRMovement_EOculusXRRetargetingMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRMovement_EOculusXRRetargetingMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRMovement_EOculusXRRetargetingMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRMovement_EOculusXRRetargetingMode()
{
	if (!Z_Registration_Info_UEnum_EOculusXRRetargetingMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRRetargetingMode.InnerSingleton, Z_Construct_UEnum_OculusXRMovement_EOculusXRRetargetingMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRRetargetingMode.InnerSingleton;
}
// End Enum EOculusXRRetargetingMode

// Begin ScriptStruct FOculusXRBoneCorrection
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OculusXRBoneCorrection;
class UScriptStruct* FOculusXRBoneCorrection::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRBoneCorrection.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OculusXRBoneCorrection.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOculusXRBoneCorrection, (UObject*)Z_Construct_UPackage__Script_OculusXRMovement(), TEXT("OculusXRBoneCorrection"));
	}
	return Z_Registration_Info_UScriptStruct_OculusXRBoneCorrection.OuterSingleton;
}
template<> OCULUSXRMOVEMENT_API UScriptStruct* StaticStruct<FOculusXRBoneCorrection>()
{
	return FOculusXRBoneCorrection::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "Bone local correction" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetBodyAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionOffset_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * Position offset in local space.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetBodyAsset.h" },
		{ "ToolTip", "Position offset in local space." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationOffset_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * Rotation offset in local space.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetBodyAsset.h" },
		{ "ToolTip", "Rotation offset in local space." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PositionOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RotationOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOculusXRBoneCorrection>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics::NewProp_PositionOffset = { "PositionOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRBoneCorrection, PositionOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionOffset_MetaData), NewProp_PositionOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics::NewProp_RotationOffset = { "RotationOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRBoneCorrection, RotationOffset), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationOffset_MetaData), NewProp_RotationOffset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics::NewProp_PositionOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics::NewProp_RotationOffset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRMovement,
	nullptr,
	&NewStructOps,
	"OculusXRBoneCorrection",
	Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics::PropPointers),
	sizeof(FOculusXRBoneCorrection),
	alignof(FOculusXRBoneCorrection),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOculusXRBoneCorrection()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRBoneCorrection.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OculusXRBoneCorrection.InnerSingleton, Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OculusXRBoneCorrection.InnerSingleton;
}
// End ScriptStruct FOculusXRBoneCorrection

// Begin ScriptStruct FOculusXRBoneCorrectionSet
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OculusXRBoneCorrectionSet;
class UScriptStruct* FOculusXRBoneCorrectionSet::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRBoneCorrectionSet.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OculusXRBoneCorrectionSet.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet, (UObject*)Z_Construct_UPackage__Script_OculusXRMovement(), TEXT("OculusXRBoneCorrectionSet"));
	}
	return Z_Registration_Info_UScriptStruct_OculusXRBoneCorrectionSet.OuterSingleton;
}
template<> OCULUSXRMOVEMENT_API UScriptStruct* StaticStruct<FOculusXRBoneCorrectionSet>()
{
	return FOculusXRBoneCorrectionSet::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "Correction applied to set of bones" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetBodyAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bones_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * Set of bones to which the correction will be applied.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetBodyAsset.h" },
		{ "ToolTip", "Set of bones to which the correction will be applied." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneCorrection_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * The correction for this set.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetBodyAsset.h" },
		{ "ToolTip", "The correction for this set." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Bones_ElementProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Bones_ElementProp;
	static const UECodeGen_Private::FSetPropertyParams NewProp_Bones;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BoneCorrection;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOculusXRBoneCorrectionSet>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::NewProp_Bones_ElementProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::NewProp_Bones_ElementProp = { "Bones", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_OculusXRMovement_EOculusXRBoneID, METADATA_PARAMS(0, nullptr) }; // 1177430570
const UECodeGen_Private::FSetPropertyParams Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::NewProp_Bones = { "Bones", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRBoneCorrectionSet, Bones), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bones_MetaData), NewProp_Bones_MetaData) }; // 1177430570
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::NewProp_BoneCorrection = { "BoneCorrection", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRBoneCorrectionSet, BoneCorrection), Z_Construct_UScriptStruct_FOculusXRBoneCorrection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneCorrection_MetaData), NewProp_BoneCorrection_MetaData) }; // 748400694
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::NewProp_Bones_ElementProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::NewProp_Bones_ElementProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::NewProp_Bones,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::NewProp_BoneCorrection,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRMovement,
	nullptr,
	&NewStructOps,
	"OculusXRBoneCorrectionSet",
	Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::PropPointers),
	sizeof(FOculusXRBoneCorrectionSet),
	alignof(FOculusXRBoneCorrectionSet),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRBoneCorrectionSet.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OculusXRBoneCorrectionSet.InnerSingleton, Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OculusXRBoneCorrectionSet.InnerSingleton;
}
// End ScriptStruct FOculusXRBoneCorrectionSet

// Begin Class UOculusXRLiveLinkRetargetBodyAsset
void UOculusXRLiveLinkRetargetBodyAsset::StaticRegisterNativesUOculusXRLiveLinkRetargetBodyAsset()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRLiveLinkRetargetBodyAsset);
UClass* Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_NoRegister()
{
	return UOculusXRLiveLinkRetargetBodyAsset::StaticClass();
}
struct Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "OculusXRHMD" },
		{ "DisplayName", "MetaXR MovementSDK LiveLink retarget body asset" },
		{ "IncludePath", "OculusXRLiveLinkRetargetBodyAsset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetBodyAsset.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneRemapping_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * Remapping from bone ID to target skeleton's bone name.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetBodyAsset.h" },
		{ "ToolTip", "Remapping from bone ID to target skeleton's bone name." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GlobalCorrection_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * Correction applied to all bones.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetBodyAsset.h" },
		{ "ToolTip", "Correction applied to all bones." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocalCorrections_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * Groups of local bone corrections.\n\x09 *\n\x09 * Order matters. A bone can be corrected multiple times.\n\x09 * Corrections will be applied with the same order as in this array.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetBodyAsset.h" },
		{ "ToolTip", "Groups of local bone corrections.\n\nOrder matters. A bone can be corrected multiple times.\nCorrections will be applied with the same order as in this array." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RetargetingMode_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * Switch between retargeting modes.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetBodyAsset.h" },
		{ "ToolTip", "Switch between retargeting modes." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ForwardMesh_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * Forward vector axis is the direction towards which the target mesh is oriented.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRLiveLinkRetargetBodyAsset.h" },
		{ "ToolTip", "Forward vector axis is the direction towards which the target mesh is oriented." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_BoneRemapping_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BoneRemapping_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BoneRemapping_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_BoneRemapping;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GlobalCorrection;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LocalCorrections_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_LocalCorrections;
	static const UECodeGen_Private::FBytePropertyParams NewProp_RetargetingMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RetargetingMode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ForwardMesh_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ForwardMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRLiveLinkRetargetBodyAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_BoneRemapping_ValueProp = { "BoneRemapping", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_BoneRemapping_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_BoneRemapping_Key_KeyProp = { "BoneRemapping_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_OculusXRMovement_EOculusXRBoneID, METADATA_PARAMS(0, nullptr) }; // 1177430570
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_BoneRemapping = { "BoneRemapping", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRLiveLinkRetargetBodyAsset, BoneRemapping), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneRemapping_MetaData), NewProp_BoneRemapping_MetaData) }; // 1177430570
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_GlobalCorrection = { "GlobalCorrection", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRLiveLinkRetargetBodyAsset, GlobalCorrection), Z_Construct_UScriptStruct_FOculusXRBoneCorrection, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GlobalCorrection_MetaData), NewProp_GlobalCorrection_MetaData) }; // 748400694
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_LocalCorrections_Inner = { "LocalCorrections", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet, METADATA_PARAMS(0, nullptr) }; // 1912405969
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_LocalCorrections = { "LocalCorrections", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRLiveLinkRetargetBodyAsset, LocalCorrections), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocalCorrections_MetaData), NewProp_LocalCorrections_MetaData) }; // 1912405969
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_RetargetingMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_RetargetingMode = { "RetargetingMode", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRLiveLinkRetargetBodyAsset, RetargetingMode), Z_Construct_UEnum_OculusXRMovement_EOculusXRRetargetingMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RetargetingMode_MetaData), NewProp_RetargetingMode_MetaData) }; // 2164196993
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_ForwardMesh_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_ForwardMesh = { "ForwardMesh", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRLiveLinkRetargetBodyAsset, ForwardMesh), Z_Construct_UEnum_OculusXRMovement_EOculusXRAxis, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ForwardMesh_MetaData), NewProp_ForwardMesh_MetaData) }; // 909652461
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_BoneRemapping_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_BoneRemapping_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_BoneRemapping_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_BoneRemapping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_GlobalCorrection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_LocalCorrections_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_LocalCorrections,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_RetargetingMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_RetargetingMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_ForwardMesh_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::NewProp_ForwardMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULiveLinkRetargetAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRMovement,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::ClassParams = {
	&UOculusXRLiveLinkRetargetBodyAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset()
{
	if (!Z_Registration_Info_UClass_UOculusXRLiveLinkRetargetBodyAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRLiveLinkRetargetBodyAsset.OuterSingleton, Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRLiveLinkRetargetBodyAsset.OuterSingleton;
}
template<> OCULUSXRMOVEMENT_API UClass* StaticClass<UOculusXRLiveLinkRetargetBodyAsset>()
{
	return UOculusXRLiveLinkRetargetBodyAsset::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRLiveLinkRetargetBodyAsset);
UOculusXRLiveLinkRetargetBodyAsset::~UOculusXRLiveLinkRetargetBodyAsset() {}
// End Class UOculusXRLiveLinkRetargetBodyAsset

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOculusXRAxis_StaticEnum, TEXT("EOculusXRAxis"), &Z_Registration_Info_UEnum_EOculusXRAxis, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 909652461U) },
		{ EOculusXRRetargetingMode_StaticEnum, TEXT("EOculusXRRetargetingMode"), &Z_Registration_Info_UEnum_EOculusXRRetargetingMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2164196993U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOculusXRBoneCorrection::StaticStruct, Z_Construct_UScriptStruct_FOculusXRBoneCorrection_Statics::NewStructOps, TEXT("OculusXRBoneCorrection"), &Z_Registration_Info_UScriptStruct_OculusXRBoneCorrection, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOculusXRBoneCorrection), 748400694U) },
		{ FOculusXRBoneCorrectionSet::StaticStruct, Z_Construct_UScriptStruct_FOculusXRBoneCorrectionSet_Statics::NewStructOps, TEXT("OculusXRBoneCorrectionSet"), &Z_Registration_Info_UScriptStruct_OculusXRBoneCorrectionSet, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOculusXRBoneCorrectionSet), 1912405969U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRLiveLinkRetargetBodyAsset, UOculusXRLiveLinkRetargetBodyAsset::StaticClass, TEXT("UOculusXRLiveLinkRetargetBodyAsset"), &Z_Registration_Info_UClass_UOculusXRLiveLinkRetargetBodyAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRLiveLinkRetargetBodyAsset), 2244839621U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_3131210668(TEXT("/Script/OculusXRMovement"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRLiveLinkRetargetBodyAsset_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
