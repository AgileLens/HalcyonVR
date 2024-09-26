// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRHMD/Public/OculusXRHMDTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRHMDTypes() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EFaceTrackingDataSourceConfig();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRColorSpace();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerPoseAlignment();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerType();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRDeviceType();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXREyeBufferSharpenType();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingLevel();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingMethod();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingFrequency();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingSupport();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingVersion();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyJointSet();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyTrackingFidelity();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRMPPoseRestoreType();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXROcclusionsMode();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRXrApi();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_EProcessorFavor();
OCULUSXRHMD_API UEnum* Z_Construct_UEnum_OculusXRHMD_ESystemSplashBackgroundType();
OCULUSXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRGuardianTestResult();
OCULUSXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRHmdUserProfile();
OCULUSXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField();
OCULUSXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics();
OCULUSXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRSplashDesc();
UPackage* Z_Construct_UPackage__Script_OculusXRHMD();
// End Cross Module References

// Begin Enum EOculusXRTrackedDeviceType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRTrackedDeviceType;
static UEnum* EOculusXRTrackedDeviceType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRTrackedDeviceType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRTrackedDeviceType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRTrackedDeviceType"));
	}
	return Z_Registration_Info_UEnum_EOculusXRTrackedDeviceType.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRTrackedDeviceType>()
{
	return EOculusXRTrackedDeviceType_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "All.DisplayName", "All Devices" },
		{ "All.Name", "EOculusXRTrackedDeviceType::All" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Tracked device types corresponding to ovrTrackedDeviceType enum*/" },
#endif
		{ "DeviceObjectZero.DisplayName", "DeviceObject Zero" },
		{ "DeviceObjectZero.Name", "EOculusXRTrackedDeviceType::DeviceObjectZero" },
		{ "HMD.DisplayName", "HMD" },
		{ "HMD.Name", "EOculusXRTrackedDeviceType::HMD" },
		{ "LTouch.DisplayName", "Left Hand" },
		{ "LTouch.Name", "EOculusXRTrackedDeviceType::LTouch" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
		{ "None.DisplayName", "No Devices" },
		{ "None.Name", "EOculusXRTrackedDeviceType::None" },
		{ "RTouch.DisplayName", "Right Hand" },
		{ "RTouch.Name", "EOculusXRTrackedDeviceType::RTouch" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tracked device types corresponding to ovrTrackedDeviceType enum" },
#endif
		{ "Touch.DisplayName", "All Hands" },
		{ "Touch.Name", "EOculusXRTrackedDeviceType::Touch" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRTrackedDeviceType::None", (int64)EOculusXRTrackedDeviceType::None },
		{ "EOculusXRTrackedDeviceType::HMD", (int64)EOculusXRTrackedDeviceType::HMD },
		{ "EOculusXRTrackedDeviceType::LTouch", (int64)EOculusXRTrackedDeviceType::LTouch },
		{ "EOculusXRTrackedDeviceType::RTouch", (int64)EOculusXRTrackedDeviceType::RTouch },
		{ "EOculusXRTrackedDeviceType::Touch", (int64)EOculusXRTrackedDeviceType::Touch },
		{ "EOculusXRTrackedDeviceType::DeviceObjectZero", (int64)EOculusXRTrackedDeviceType::DeviceObjectZero },
		{ "EOculusXRTrackedDeviceType::All", (int64)EOculusXRTrackedDeviceType::All },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRTrackedDeviceType",
	"EOculusXRTrackedDeviceType",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType()
{
	if (!Z_Registration_Info_UEnum_EOculusXRTrackedDeviceType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRTrackedDeviceType.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRTrackedDeviceType.InnerSingleton;
}
// End Enum EOculusXRTrackedDeviceType

// Begin ScriptStruct FOculusXRHmdUserProfileField
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfileField;
class UScriptStruct* FOculusXRHmdUserProfileField::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfileField.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfileField.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("OculusXRHmdUserProfileField"));
	}
	return Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfileField.OuterSingleton;
}
template<> OCULUSXRHMD_API UScriptStruct* StaticStruct<FOculusXRHmdUserProfileField>()
{
	return FOculusXRHmdUserProfileField::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "HMD User Profile Data Field" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldName_MetaData[] = {
		{ "Category", "Input|HeadMountedDisplay" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FieldValue_MetaData[] = {
		{ "Category", "Input|HeadMountedDisplay" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FieldValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOculusXRHmdUserProfileField>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics::NewProp_FieldName = { "FieldName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRHmdUserProfileField, FieldName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldName_MetaData), NewProp_FieldName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics::NewProp_FieldValue = { "FieldValue", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRHmdUserProfileField, FieldValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FieldValue_MetaData), NewProp_FieldValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics::NewProp_FieldName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics::NewProp_FieldValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	&NewStructOps,
	"OculusXRHmdUserProfileField",
	Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics::PropPointers),
	sizeof(FOculusXRHmdUserProfileField),
	alignof(FOculusXRHmdUserProfileField),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfileField.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfileField.InnerSingleton, Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfileField.InnerSingleton;
}
// End ScriptStruct FOculusXRHmdUserProfileField

// Begin ScriptStruct FOculusXRHmdUserProfile
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfile;
class UScriptStruct* FOculusXRHmdUserProfile::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfile.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfile.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOculusXRHmdUserProfile, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("OculusXRHmdUserProfile"));
	}
	return Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfile.OuterSingleton;
}
template<> OCULUSXRHMD_API UScriptStruct* StaticStruct<FOculusXRHmdUserProfile>()
{
	return FOculusXRHmdUserProfile::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "HMD User Profile Data" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Input|HeadMountedDisplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Name of the user's profile. */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name of the user's profile." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Gender_MetaData[] = {
		{ "Category", "Input|HeadMountedDisplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Gender of the user (\"male\", \"female\", etc). */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gender of the user (\"male\", \"female\", etc)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerHeight_MetaData[] = {
		{ "Category", "Input|HeadMountedDisplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Height of the player, in meters */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Height of the player, in meters" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EyeHeight_MetaData[] = {
		{ "Category", "Input|HeadMountedDisplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Height of the player, in meters */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Height of the player, in meters" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IPD_MetaData[] = {
		{ "Category", "Input|HeadMountedDisplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Interpupillary distance of the player, in meters */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Interpupillary distance of the player, in meters" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NeckToEyeDistance_MetaData[] = {
		{ "Category", "Input|HeadMountedDisplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Neck-to-eye distance, in meters. X - horizontal, Y - vertical. */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Neck-to-eye distance, in meters. X - horizontal, Y - vertical." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExtraFields_MetaData[] = {
		{ "Category", "Input|HeadMountedDisplay" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Gender;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EyeHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_IPD;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NeckToEyeDistance;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExtraFields_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ExtraFields;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOculusXRHmdUserProfile>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRHmdUserProfile, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_Gender = { "Gender", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRHmdUserProfile, Gender), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Gender_MetaData), NewProp_Gender_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_PlayerHeight = { "PlayerHeight", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRHmdUserProfile, PlayerHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerHeight_MetaData), NewProp_PlayerHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_EyeHeight = { "EyeHeight", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRHmdUserProfile, EyeHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EyeHeight_MetaData), NewProp_EyeHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_IPD = { "IPD", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRHmdUserProfile, IPD), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IPD_MetaData), NewProp_IPD_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_NeckToEyeDistance = { "NeckToEyeDistance", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRHmdUserProfile, NeckToEyeDistance), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NeckToEyeDistance_MetaData), NewProp_NeckToEyeDistance_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_ExtraFields_Inner = { "ExtraFields", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField, METADATA_PARAMS(0, nullptr) }; // 1686145672
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_ExtraFields = { "ExtraFields", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRHmdUserProfile, ExtraFields), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExtraFields_MetaData), NewProp_ExtraFields_MetaData) }; // 1686145672
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_Gender,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_PlayerHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_EyeHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_IPD,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_NeckToEyeDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_ExtraFields_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewProp_ExtraFields,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	&NewStructOps,
	"OculusXRHmdUserProfile",
	Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::PropPointers),
	sizeof(FOculusXRHmdUserProfile),
	alignof(FOculusXRHmdUserProfile),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOculusXRHmdUserProfile()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfile.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfile.InnerSingleton, Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfile.InnerSingleton;
}
// End ScriptStruct FOculusXRHmdUserProfile

// Begin Enum EOculusXRFoveatedRenderingMethod
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingMethod;
static UEnum* EOculusXRFoveatedRenderingMethod_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingMethod.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingMethod.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingMethod, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRFoveatedRenderingMethod"));
	}
	return Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingMethod.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRFoveatedRenderingMethod>()
{
	return EOculusXRFoveatedRenderingMethod_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingMethod_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "EyeTrackedFoveatedRendering.Name", "EOculusXRFoveatedRenderingMethod::EyeTrackedFoveatedRendering" },
		{ "FixedFoveatedRendering.Name", "EOculusXRFoveatedRenderingMethod::FixedFoveatedRendering" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRFoveatedRenderingMethod::FixedFoveatedRendering", (int64)EOculusXRFoveatedRenderingMethod::FixedFoveatedRendering },
		{ "EOculusXRFoveatedRenderingMethod::EyeTrackedFoveatedRendering", (int64)EOculusXRFoveatedRenderingMethod::EyeTrackedFoveatedRendering },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingMethod_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRFoveatedRenderingMethod",
	"EOculusXRFoveatedRenderingMethod",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingMethod_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingMethod_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingMethod_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingMethod_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingMethod()
{
	if (!Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingMethod.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingMethod.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingMethod_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingMethod.InnerSingleton;
}
// End Enum EOculusXRFoveatedRenderingMethod

// Begin Enum EOculusXRFoveatedRenderingLevel
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingLevel;
static UEnum* EOculusXRFoveatedRenderingLevel_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingLevel.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingLevel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingLevel, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRFoveatedRenderingLevel"));
	}
	return Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingLevel.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRFoveatedRenderingLevel>()
{
	return EOculusXRFoveatedRenderingLevel_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingLevel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "High.Name", "EOculusXRFoveatedRenderingLevel::High" },
		{ "HighTop.Comment", "// High foveation setting with more detail toward the bottom of the view and more foveation near the top\n" },
		{ "HighTop.Name", "EOculusXRFoveatedRenderingLevel::HighTop" },
		{ "HighTop.ToolTip", "High foveation setting with more detail toward the bottom of the view and more foveation near the top" },
		{ "Low.Name", "EOculusXRFoveatedRenderingLevel::Low" },
		{ "Medium.Name", "EOculusXRFoveatedRenderingLevel::Medium" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
		{ "Off.Name", "EOculusXRFoveatedRenderingLevel::Off" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRFoveatedRenderingLevel::Off", (int64)EOculusXRFoveatedRenderingLevel::Off },
		{ "EOculusXRFoveatedRenderingLevel::Low", (int64)EOculusXRFoveatedRenderingLevel::Low },
		{ "EOculusXRFoveatedRenderingLevel::Medium", (int64)EOculusXRFoveatedRenderingLevel::Medium },
		{ "EOculusXRFoveatedRenderingLevel::High", (int64)EOculusXRFoveatedRenderingLevel::High },
		{ "EOculusXRFoveatedRenderingLevel::HighTop", (int64)EOculusXRFoveatedRenderingLevel::HighTop },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingLevel_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRFoveatedRenderingLevel",
	"EOculusXRFoveatedRenderingLevel",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingLevel_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingLevel_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingLevel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingLevel_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingLevel()
{
	if (!Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingLevel.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingLevel.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRFoveatedRenderingLevel_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingLevel.InnerSingleton;
}
// End Enum EOculusXRFoveatedRenderingLevel

// Begin Enum EOculusXRBoundaryType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRBoundaryType;
static UEnum* EOculusXRBoundaryType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRBoundaryType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRBoundaryType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRBoundaryType"));
	}
	return Z_Registration_Info_UEnum_EOculusXRBoundaryType.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRBoundaryType>()
{
	return EOculusXRBoundaryType_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Boundary_Outer.DisplayName", "Outer Boundary" },
		{ "Boundary_Outer.Name", "EOculusXRBoundaryType::Boundary_Outer" },
		{ "Boundary_PlayArea.DisplayName", "Play Area" },
		{ "Boundary_PlayArea.Name", "EOculusXRBoundaryType::Boundary_PlayArea" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Guardian boundary types*/" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Guardian boundary types" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRBoundaryType::Boundary_Outer", (int64)EOculusXRBoundaryType::Boundary_Outer },
		{ "EOculusXRBoundaryType::Boundary_PlayArea", (int64)EOculusXRBoundaryType::Boundary_PlayArea },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRBoundaryType",
	"EOculusXRBoundaryType",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType()
{
	if (!Z_Registration_Info_UEnum_EOculusXRBoundaryType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRBoundaryType.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRBoundaryType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRBoundaryType.InnerSingleton;
}
// End Enum EOculusXRBoundaryType

// Begin Enum EOculusXRColorSpace
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRColorSpace;
static UEnum* EOculusXRColorSpace_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRColorSpace.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRColorSpace.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRColorSpace, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRColorSpace"));
	}
	return Z_Registration_Info_UEnum_EOculusXRColorSpace.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRColorSpace>()
{
	return EOculusXRColorSpace_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRColorSpace_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Adobe_RGB.Comment", "/// Similar to sRGB but with deeper greens using D65 white point\n" },
		{ "Adobe_RGB.Name", "EOculusXRColorSpace::Adobe_RGB" },
		{ "Adobe_RGB.ToolTip", "Similar to sRGB but with deeper greens using D65 white point" },
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
		{ "P3.Comment", "/// DCI-P3 color space. See documentation for more details\n" },
		{ "P3.DisplayName", "P3 (Recommended)" },
		{ "P3.Name", "EOculusXRColorSpace::P3" },
		{ "P3.ToolTip", "DCI-P3 color space. See documentation for more details" },
		{ "Quest.Comment", "/// Oculus Quest's native color space is slightly different than Rift CV1\n" },
		{ "Quest.DisplayName", "Quest 1" },
		{ "Quest.Name", "EOculusXRColorSpace::Quest" },
		{ "Quest.ToolTip", "Oculus Quest's native color space is slightly different than Rift CV1" },
		{ "Rec_2020.Comment", "/// Color space for standardized color across all Oculus HMDs with D65 white point\n" },
		{ "Rec_2020.Name", "EOculusXRColorSpace::Rec_2020" },
		{ "Rec_2020.ToolTip", "Color space for standardized color across all Oculus HMDs with D65 white point" },
		{ "Rec_709.Comment", "/// Rec. 709 is used on Oculus Go and shares the same primary color coordinates as sRGB\n" },
		{ "Rec_709.Name", "EOculusXRColorSpace::Rec_709" },
		{ "Rec_709.ToolTip", "Rec. 709 is used on Oculus Go and shares the same primary color coordinates as sRGB" },
		{ "Rift_CV1.Comment", "/// Oculus Rift CV1 uses a unique color space, see documentation for more info\n" },
		{ "Rift_CV1.DisplayName", "Rift CV1" },
		{ "Rift_CV1.Name", "EOculusXRColorSpace::Rift_CV1" },
		{ "Rift_CV1.ToolTip", "Oculus Rift CV1 uses a unique color space, see documentation for more info" },
		{ "Rift_S.Comment", "/// Oculus Rift S uses a unique color space, see documentation for more info\n" },
		{ "Rift_S.Name", "EOculusXRColorSpace::Rift_S" },
		{ "Rift_S.ToolTip", "Oculus Rift S uses a unique color space, see documentation for more info" },
		{ "Unknown.Comment", "/// The default value from GetHmdColorSpace until SetClientColorDesc is called. Only valid on PC, and will be remapped to Quest on Mobile\n" },
		{ "Unknown.Name", "EOculusXRColorSpace::Unknown" },
		{ "Unknown.ToolTip", "The default value from GetHmdColorSpace until SetClientColorDesc is called. Only valid on PC, and will be remapped to Quest on Mobile" },
		{ "Unmanaged.Comment", "/// No color correction, not recommended for production use. See documentation for more info\n" },
		{ "Unmanaged.Name", "EOculusXRColorSpace::Unmanaged" },
		{ "Unmanaged.ToolTip", "No color correction, not recommended for production use. See documentation for more info" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRColorSpace::Unknown", (int64)EOculusXRColorSpace::Unknown },
		{ "EOculusXRColorSpace::Unmanaged", (int64)EOculusXRColorSpace::Unmanaged },
		{ "EOculusXRColorSpace::Rec_2020", (int64)EOculusXRColorSpace::Rec_2020 },
		{ "EOculusXRColorSpace::Rec_709", (int64)EOculusXRColorSpace::Rec_709 },
		{ "EOculusXRColorSpace::Rift_CV1", (int64)EOculusXRColorSpace::Rift_CV1 },
		{ "EOculusXRColorSpace::Rift_S", (int64)EOculusXRColorSpace::Rift_S },
		{ "EOculusXRColorSpace::Quest", (int64)EOculusXRColorSpace::Quest },
		{ "EOculusXRColorSpace::P3", (int64)EOculusXRColorSpace::P3 },
		{ "EOculusXRColorSpace::Adobe_RGB", (int64)EOculusXRColorSpace::Adobe_RGB },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRColorSpace_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRColorSpace",
	"EOculusXRColorSpace",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRColorSpace_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRColorSpace_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRColorSpace_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRColorSpace_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRColorSpace()
{
	if (!Z_Registration_Info_UEnum_EOculusXRColorSpace.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRColorSpace.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRColorSpace_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRColorSpace.InnerSingleton;
}
// End Enum EOculusXRColorSpace

// Begin Enum EOculusXRHandTrackingSupport
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRHandTrackingSupport;
static UEnum* EOculusXRHandTrackingSupport_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRHandTrackingSupport.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRHandTrackingSupport.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingSupport, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRHandTrackingSupport"));
	}
	return Z_Registration_Info_UEnum_EOculusXRHandTrackingSupport.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRHandTrackingSupport>()
{
	return EOculusXRHandTrackingSupport_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingSupport_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * Hand tracking settings. Please check https://developer.oculus.com/documentation/unreal/unreal-hand-tracking/\n * for detailed information.\n */" },
#endif
		{ "ControllersAndHands.Name", "EOculusXRHandTrackingSupport::ControllersAndHands" },
		{ "ControllersOnly.Name", "EOculusXRHandTrackingSupport::ControllersOnly" },
		{ "HandsOnly.Name", "EOculusXRHandTrackingSupport::HandsOnly" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Hand tracking settings. Please check https://developer.oculus.com/documentation/unreal/unreal-hand-tracking/\n* for detailed information." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRHandTrackingSupport::ControllersOnly", (int64)EOculusXRHandTrackingSupport::ControllersOnly },
		{ "EOculusXRHandTrackingSupport::ControllersAndHands", (int64)EOculusXRHandTrackingSupport::ControllersAndHands },
		{ "EOculusXRHandTrackingSupport::HandsOnly", (int64)EOculusXRHandTrackingSupport::HandsOnly },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingSupport_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRHandTrackingSupport",
	"EOculusXRHandTrackingSupport",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingSupport_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingSupport_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingSupport_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingSupport_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingSupport()
{
	if (!Z_Registration_Info_UEnum_EOculusXRHandTrackingSupport.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRHandTrackingSupport.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingSupport_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRHandTrackingSupport.InnerSingleton;
}
// End Enum EOculusXRHandTrackingSupport

// Begin Enum EOculusXRHandTrackingFrequency
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRHandTrackingFrequency;
static UEnum* EOculusXRHandTrackingFrequency_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRHandTrackingFrequency.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRHandTrackingFrequency.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingFrequency, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRHandTrackingFrequency"));
	}
	return Z_Registration_Info_UEnum_EOculusXRHandTrackingFrequency.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRHandTrackingFrequency>()
{
	return EOculusXRHandTrackingFrequency_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingFrequency_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HIGH.Name", "EOculusXRHandTrackingFrequency::HIGH" },
		{ "LOW.Name", "EOculusXRHandTrackingFrequency::LOW" },
		{ "MAX.Name", "EOculusXRHandTrackingFrequency::MAX" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRHandTrackingFrequency::LOW", (int64)EOculusXRHandTrackingFrequency::LOW },
		{ "EOculusXRHandTrackingFrequency::HIGH", (int64)EOculusXRHandTrackingFrequency::HIGH },
		{ "EOculusXRHandTrackingFrequency::MAX", (int64)EOculusXRHandTrackingFrequency::MAX },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingFrequency_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRHandTrackingFrequency",
	"EOculusXRHandTrackingFrequency",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingFrequency_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingFrequency_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingFrequency_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingFrequency_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingFrequency()
{
	if (!Z_Registration_Info_UEnum_EOculusXRHandTrackingFrequency.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRHandTrackingFrequency.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingFrequency_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRHandTrackingFrequency.InnerSingleton;
}
// End Enum EOculusXRHandTrackingFrequency

// Begin Enum EOculusXRHandTrackingVersion
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRHandTrackingVersion;
static UEnum* EOculusXRHandTrackingVersion_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRHandTrackingVersion.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRHandTrackingVersion.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingVersion, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRHandTrackingVersion"));
	}
	return Z_Registration_Info_UEnum_EOculusXRHandTrackingVersion.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRHandTrackingVersion>()
{
	return EOculusXRHandTrackingVersion_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingVersion_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Default.Name", "EOculusXRHandTrackingVersion::Default" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
		{ "V1.Name", "EOculusXRHandTrackingVersion::V1" },
		{ "V2.Name", "EOculusXRHandTrackingVersion::V2" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRHandTrackingVersion::Default", (int64)EOculusXRHandTrackingVersion::Default },
		{ "EOculusXRHandTrackingVersion::V1", (int64)EOculusXRHandTrackingVersion::V1 },
		{ "EOculusXRHandTrackingVersion::V2", (int64)EOculusXRHandTrackingVersion::V2 },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingVersion_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRHandTrackingVersion",
	"EOculusXRHandTrackingVersion",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingVersion_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingVersion_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingVersion_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingVersion_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingVersion()
{
	if (!Z_Registration_Info_UEnum_EOculusXRHandTrackingVersion.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRHandTrackingVersion.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRHandTrackingVersion_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRHandTrackingVersion.InnerSingleton;
}
// End Enum EOculusXRHandTrackingVersion

// Begin Enum EOculusXRProcessorPerformanceLevel
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRProcessorPerformanceLevel;
static UEnum* EOculusXRProcessorPerformanceLevel_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRProcessorPerformanceLevel.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRProcessorPerformanceLevel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRProcessorPerformanceLevel"));
	}
	return Z_Registration_Info_UEnum_EOculusXRProcessorPerformanceLevel.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRProcessorPerformanceLevel>()
{
	return EOculusXRProcessorPerformanceLevel_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Boost.DisplayName", "Boost(*)" },
		{ "Boost.Name", "EOculusXRProcessorPerformanceLevel::Boost" },
		{ "Boost.ToolTip", "Allow XR Runtime to step up beyond the thermally sustainable range for short period. (Currently equivalent to SustainedHigh and not recommended to be used on Quest)" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
		{ "PowerSavings.DisplayName", "PowerSavings" },
		{ "PowerSavings.Name", "EOculusXRProcessorPerformanceLevel::PowerSavings" },
		{ "PowerSavings.ToolTip", "Usually used in non-XR section (head-locked / static screen), during which power savings are to be prioritized" },
		{ "SustainedHigh.DisplayName", "SustainedHigh" },
		{ "SustainedHigh.Name", "EOculusXRProcessorPerformanceLevel::SustainedHigh" },
		{ "SustainedHigh.ToolTip", "Let XR Runtime to perform consistent XR compositing and frame rendering within a thermally sustainable range" },
		{ "SustainedLow.DisplayName", "SustainedLow" },
		{ "SustainedLow.Name", "EOculusXRProcessorPerformanceLevel::SustainedLow" },
		{ "SustainedLow.ToolTip", "App enters a low and stable complexity section, during which reducing power is more important than occasional late rendering frames" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRProcessorPerformanceLevel::PowerSavings", (int64)EOculusXRProcessorPerformanceLevel::PowerSavings },
		{ "EOculusXRProcessorPerformanceLevel::SustainedLow", (int64)EOculusXRProcessorPerformanceLevel::SustainedLow },
		{ "EOculusXRProcessorPerformanceLevel::SustainedHigh", (int64)EOculusXRProcessorPerformanceLevel::SustainedHigh },
		{ "EOculusXRProcessorPerformanceLevel::Boost", (int64)EOculusXRProcessorPerformanceLevel::Boost },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRProcessorPerformanceLevel",
	"EOculusXRProcessorPerformanceLevel",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel()
{
	if (!Z_Registration_Info_UEnum_EOculusXRProcessorPerformanceLevel.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRProcessorPerformanceLevel.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRProcessorPerformanceLevel_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRProcessorPerformanceLevel.InnerSingleton;
}
// End Enum EOculusXRProcessorPerformanceLevel

// Begin Enum EOculusXRDeviceType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRDeviceType;
static UEnum* EOculusXRDeviceType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRDeviceType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRDeviceType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRDeviceType, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRDeviceType"));
	}
	return Z_Registration_Info_UEnum_EOculusXRDeviceType.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRDeviceType>()
{
	return EOculusXRDeviceType_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRDeviceType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "MetaQuest3.Name", "EOculusXRDeviceType::MetaQuest3" },
		{ "MetaQuest3Link.Name", "EOculusXRDeviceType::MetaQuest3Link" },
		{ "MetaQuestPro.Name", "EOculusXRDeviceType::MetaQuestPro" },
		{ "MetaQuestProLink.Name", "EOculusXRDeviceType::MetaQuestProLink" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
		{ "OculusMobile_Deprecated0.Comment", "// mobile HMDs\n" },
		{ "OculusMobile_Deprecated0.Name", "EOculusXRDeviceType::OculusMobile_Deprecated0" },
		{ "OculusMobile_Deprecated0.ToolTip", "mobile HMDs" },
		{ "OculusQuest2.Name", "EOculusXRDeviceType::OculusQuest2" },
		{ "OculusQuest_Deprecated.Name", "EOculusXRDeviceType::OculusQuest_Deprecated" },
		{ "OculusUnknown.Comment", "// default\n" },
		{ "OculusUnknown.Name", "EOculusXRDeviceType::OculusUnknown" },
		{ "OculusUnknown.ToolTip", "default" },
		{ "Quest2_Link.Name", "EOculusXRDeviceType::Quest2_Link" },
		{ "Quest_Link_Deprecated.Name", "EOculusXRDeviceType::Quest_Link_Deprecated" },
		{ "Rift.Comment", "// PC HMDs\n" },
		{ "Rift.Name", "EOculusXRDeviceType::Rift" },
		{ "Rift.ToolTip", "PC HMDs" },
		{ "Rift_S.Name", "EOculusXRDeviceType::Rift_S" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRDeviceType::OculusMobile_Deprecated0", (int64)EOculusXRDeviceType::OculusMobile_Deprecated0 },
		{ "EOculusXRDeviceType::OculusQuest_Deprecated", (int64)EOculusXRDeviceType::OculusQuest_Deprecated },
		{ "EOculusXRDeviceType::OculusQuest2", (int64)EOculusXRDeviceType::OculusQuest2 },
		{ "EOculusXRDeviceType::MetaQuestPro", (int64)EOculusXRDeviceType::MetaQuestPro },
		{ "EOculusXRDeviceType::MetaQuest3", (int64)EOculusXRDeviceType::MetaQuest3 },
		{ "EOculusXRDeviceType::Rift", (int64)EOculusXRDeviceType::Rift },
		{ "EOculusXRDeviceType::Rift_S", (int64)EOculusXRDeviceType::Rift_S },
		{ "EOculusXRDeviceType::Quest_Link_Deprecated", (int64)EOculusXRDeviceType::Quest_Link_Deprecated },
		{ "EOculusXRDeviceType::Quest2_Link", (int64)EOculusXRDeviceType::Quest2_Link },
		{ "EOculusXRDeviceType::MetaQuestProLink", (int64)EOculusXRDeviceType::MetaQuestProLink },
		{ "EOculusXRDeviceType::MetaQuest3Link", (int64)EOculusXRDeviceType::MetaQuest3Link },
		{ "EOculusXRDeviceType::OculusUnknown", (int64)EOculusXRDeviceType::OculusUnknown },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRDeviceType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRDeviceType",
	"EOculusXRDeviceType",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRDeviceType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRDeviceType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRDeviceType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRDeviceType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRDeviceType()
{
	if (!Z_Registration_Info_UEnum_EOculusXRDeviceType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRDeviceType.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRDeviceType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRDeviceType.InnerSingleton;
}
// End Enum EOculusXRDeviceType

// Begin Enum EOculusXRControllerType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRControllerType;
static UEnum* EOculusXRControllerType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRControllerType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRControllerType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerType, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRControllerType"));
	}
	return Z_Registration_Info_UEnum_EOculusXRControllerType.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRControllerType>()
{
	return EOculusXRControllerType_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "MetaQuestTouch.Name", "EOculusXRControllerType::MetaQuestTouch" },
		{ "MetaQuestTouchPlus.Name", "EOculusXRControllerType::MetaQuestTouchPlus" },
		{ "MetaQuestTouchPro.Name", "EOculusXRControllerType::MetaQuestTouchPro" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
		{ "None.Name", "EOculusXRControllerType::None" },
		{ "Unknown.Name", "EOculusXRControllerType::Unknown" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRControllerType::None", (int64)EOculusXRControllerType::None },
		{ "EOculusXRControllerType::MetaQuestTouch", (int64)EOculusXRControllerType::MetaQuestTouch },
		{ "EOculusXRControllerType::MetaQuestTouchPro", (int64)EOculusXRControllerType::MetaQuestTouchPro },
		{ "EOculusXRControllerType::MetaQuestTouchPlus", (int64)EOculusXRControllerType::MetaQuestTouchPlus },
		{ "EOculusXRControllerType::Unknown", (int64)EOculusXRControllerType::Unknown },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRControllerType",
	"EOculusXRControllerType",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerType()
{
	if (!Z_Registration_Info_UEnum_EOculusXRControllerType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRControllerType.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRControllerType.InnerSingleton;
}
// End Enum EOculusXRControllerType

// Begin Enum EOculusXRXrApi
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRXrApi;
static UEnum* EOculusXRXrApi_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRXrApi.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRXrApi.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRXrApi, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRXrApi"));
	}
	return Z_Registration_Info_UEnum_EOculusXRXrApi.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRXrApi>()
{
	return EOculusXRXrApi_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRXrApi_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
		{ "NativeOpenXR.DisplayName", "Epic Native OpenXR with Oculus vendor extensions" },
		{ "NativeOpenXR.Name", "EOculusXRXrApi::NativeOpenXR" },
		{ "NativeOpenXR.ToolTip", "Disable Legacy Oculus in favor of the native OpenXR implementation, with Oculus vendor extensions. Must enable the OpenXR plugin. This will be where Epic focuses XR development going forward. Oculus OpenXR extensions may be moved into a separate plugin (or plugins) in the future to improve modularity. The features supported by OpenXR are listed in the OpenXR specification on khronos.org, and the features supported by a given runtime can be verified with the \\\"OpenXR Explorer\\\" application on GitHub." },
		{ "OVRPluginOpenXR.DisplayName", "Oculus OVRPlugin + OpenXR backend (current recommended)" },
		{ "OVRPluginOpenXR.Name", "EOculusXRXrApi::OVRPluginOpenXR" },
		{ "OVRPluginOpenXR.ToolTip", "Oculus plugin integration using OpenXR backend on both Mobile and PC. All new features will ship on backend for the forseeable future." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRXrApi::OVRPluginOpenXR", (int64)EOculusXRXrApi::OVRPluginOpenXR },
		{ "EOculusXRXrApi::NativeOpenXR", (int64)EOculusXRXrApi::NativeOpenXR },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRXrApi_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRXrApi",
	"EOculusXRXrApi",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRXrApi_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRXrApi_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRXrApi_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRXrApi_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRXrApi()
{
	if (!Z_Registration_Info_UEnum_EOculusXRXrApi.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRXrApi.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRXrApi_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRXrApi.InnerSingleton;
}
// End Enum EOculusXRXrApi

// Begin ScriptStruct FOculusXRGuardianTestResult
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OculusXRGuardianTestResult;
class UScriptStruct* FOculusXRGuardianTestResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRGuardianTestResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OculusXRGuardianTestResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOculusXRGuardianTestResult, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("OculusXRGuardianTestResult"));
	}
	return Z_Registration_Info_UScriptStruct_OculusXRGuardianTestResult.OuterSingleton;
}
template<> OCULUSXRHMD_API UScriptStruct* StaticStruct<FOculusXRGuardianTestResult>()
{
	return FOculusXRGuardianTestResult::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * Information about relationships between a triggered boundary (EOculusXRBoundaryType::Boundary_Outer or\n * EOculusXRBoundaryType::Boundary_PlayArea) and a device or point in the world.\n * All dimensions, points, and vectors are returned in Unreal world coordinate space.\n */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Information about relationships between a triggered boundary (EOculusXRBoundaryType::Boundary_Outer or\n* EOculusXRBoundaryType::Boundary_PlayArea) and a device or point in the world.\n* All dimensions, points, and vectors are returned in Unreal world coordinate space." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsTriggering_MetaData[] = {
		{ "Category", "Boundary Test Result" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Is there a triggering interaction between the device/point and specified boundary? */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Is there a triggering interaction between the device/point and specified boundary?" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceType_MetaData[] = {
		{ "Category", "Boundary Test Result" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Device type triggering boundary (EOculusXRTrackedDeviceType::None if BoundaryTestResult corresponds to a point rather than a device) */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Device type triggering boundary (EOculusXRTrackedDeviceType::None if BoundaryTestResult corresponds to a point rather than a device)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClosestDistance_MetaData[] = {
		{ "Category", "Boundary Test Result" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Distance of device/point to surface of boundary specified by BoundaryType */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Distance of device/point to surface of boundary specified by BoundaryType" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClosestPoint_MetaData[] = {
		{ "Category", "Boundary Test Result" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Closest point on surface corresponding to specified boundary */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Closest point on surface corresponding to specified boundary" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClosestPointNormal_MetaData[] = {
		{ "Category", "Boundary Test Result" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Normal of closest point */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Normal of closest point" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_IsTriggering_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsTriggering;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ClosestDistance;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClosestPoint;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ClosestPointNormal;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOculusXRGuardianTestResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewProp_IsTriggering_SetBit(void* Obj)
{
	((FOculusXRGuardianTestResult*)Obj)->IsTriggering = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewProp_IsTriggering = { "IsTriggering", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOculusXRGuardianTestResult), &Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewProp_IsTriggering_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsTriggering_MetaData), NewProp_IsTriggering_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewProp_DeviceType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewProp_DeviceType = { "DeviceType", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRGuardianTestResult, DeviceType), Z_Construct_UEnum_OculusXRHMD_EOculusXRTrackedDeviceType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceType_MetaData), NewProp_DeviceType_MetaData) }; // 2225433783
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewProp_ClosestDistance = { "ClosestDistance", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRGuardianTestResult, ClosestDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClosestDistance_MetaData), NewProp_ClosestDistance_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewProp_ClosestPoint = { "ClosestPoint", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRGuardianTestResult, ClosestPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClosestPoint_MetaData), NewProp_ClosestPoint_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewProp_ClosestPointNormal = { "ClosestPointNormal", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRGuardianTestResult, ClosestPointNormal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClosestPointNormal_MetaData), NewProp_ClosestPointNormal_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewProp_IsTriggering,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewProp_DeviceType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewProp_DeviceType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewProp_ClosestDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewProp_ClosestPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewProp_ClosestPointNormal,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	&NewStructOps,
	"OculusXRGuardianTestResult",
	Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::PropPointers),
	sizeof(FOculusXRGuardianTestResult),
	alignof(FOculusXRGuardianTestResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOculusXRGuardianTestResult()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRGuardianTestResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OculusXRGuardianTestResult.InnerSingleton, Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OculusXRGuardianTestResult.InnerSingleton;
}
// End ScriptStruct FOculusXRGuardianTestResult

// Begin Enum EOculusXRControllerPoseAlignment
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRControllerPoseAlignment;
static UEnum* EOculusXRControllerPoseAlignment_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRControllerPoseAlignment.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRControllerPoseAlignment.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerPoseAlignment, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRControllerPoseAlignment"));
	}
	return Z_Registration_Info_UEnum_EOculusXRControllerPoseAlignment.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRControllerPoseAlignment>()
{
	return EOculusXRControllerPoseAlignment_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerPoseAlignment_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Aim.Name", "EOculusXRControllerPoseAlignment::Aim" },
		{ "Aim.ToolTip", "Aim pose alignment as defined by OpenXR. Use this for cross-plugin compatibility with assets designed for the native OpenXR aim pose." },
		{ "Default.Name", "EOculusXRControllerPoseAlignment::Default" },
		{ "Default.ToolTip", "Default pose alignment used in all versions of the Meta XR plugin. Recommended pose for compatibility with previous assets designed for the Meta XR plugin." },
		{ "Grip.Name", "EOculusXRControllerPoseAlignment::Grip" },
		{ "Grip.ToolTip", "Grip pose alignment as defined by OpenXR. Use this for cross-plugin compatibility with assets designed for the native OpenXR grip pose." },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRControllerPoseAlignment::Default", (int64)EOculusXRControllerPoseAlignment::Default },
		{ "EOculusXRControllerPoseAlignment::Grip", (int64)EOculusXRControllerPoseAlignment::Grip },
		{ "EOculusXRControllerPoseAlignment::Aim", (int64)EOculusXRControllerPoseAlignment::Aim },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerPoseAlignment_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRControllerPoseAlignment",
	"EOculusXRControllerPoseAlignment",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerPoseAlignment_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerPoseAlignment_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerPoseAlignment_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerPoseAlignment_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerPoseAlignment()
{
	if (!Z_Registration_Info_UEnum_EOculusXRControllerPoseAlignment.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRControllerPoseAlignment.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRControllerPoseAlignment_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRControllerPoseAlignment.InnerSingleton;
}
// End Enum EOculusXRControllerPoseAlignment

// Begin ScriptStruct FOculusXRSplashDesc
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OculusXRSplashDesc;
class UScriptStruct* FOculusXRSplashDesc::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRSplashDesc.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OculusXRSplashDesc.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOculusXRSplashDesc, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("OculusXRSplashDesc"));
	}
	return Z_Registration_Info_UScriptStruct_OculusXRSplashDesc.OuterSingleton;
}
template<> OCULUSXRHMD_API UScriptStruct* StaticStruct<FOculusXRSplashDesc>()
{
	return FOculusXRSplashDesc::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TexturePath_MetaData[] = {
		{ "AllowedClasses", "/Script/Engine.Texture" },
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Texture to display" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransformInMeters_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "transform of center of quad (meters)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuadSizeInMeters_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dimensions in meters." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeltaRotation_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A delta rotation that will be added each rendering frame (half rate of full vsync)." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextureOffset_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Texture offset amount from the top left corner." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextureScale_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Texture scale." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bNoAlphaChannel_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the splash layer uses it's alpha channel." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TexturePath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TransformInMeters;
	static const UECodeGen_Private::FStructPropertyParams NewProp_QuadSizeInMeters;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DeltaRotation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextureOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextureScale;
	static void NewProp_bNoAlphaChannel_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNoAlphaChannel;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOculusXRSplashDesc>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_TexturePath = { "TexturePath", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRSplashDesc, TexturePath), Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TexturePath_MetaData), NewProp_TexturePath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_TransformInMeters = { "TransformInMeters", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRSplashDesc, TransformInMeters), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransformInMeters_MetaData), NewProp_TransformInMeters_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_QuadSizeInMeters = { "QuadSizeInMeters", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRSplashDesc, QuadSizeInMeters), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuadSizeInMeters_MetaData), NewProp_QuadSizeInMeters_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_DeltaRotation = { "DeltaRotation", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRSplashDesc, DeltaRotation), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeltaRotation_MetaData), NewProp_DeltaRotation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_TextureOffset = { "TextureOffset", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRSplashDesc, TextureOffset), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextureOffset_MetaData), NewProp_TextureOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_TextureScale = { "TextureScale", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRSplashDesc, TextureScale), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextureScale_MetaData), NewProp_TextureScale_MetaData) };
void Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_bNoAlphaChannel_SetBit(void* Obj)
{
	((FOculusXRSplashDesc*)Obj)->bNoAlphaChannel = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_bNoAlphaChannel = { "bNoAlphaChannel", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOculusXRSplashDesc), &Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_bNoAlphaChannel_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bNoAlphaChannel_MetaData), NewProp_bNoAlphaChannel_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_TexturePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_TransformInMeters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_QuadSizeInMeters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_DeltaRotation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_TextureOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_TextureScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewProp_bNoAlphaChannel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	&NewStructOps,
	"OculusXRSplashDesc",
	Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::PropPointers),
	sizeof(FOculusXRSplashDesc),
	alignof(FOculusXRSplashDesc),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOculusXRSplashDesc()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRSplashDesc.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OculusXRSplashDesc.InnerSingleton, Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OculusXRSplashDesc.InnerSingleton;
}
// End ScriptStruct FOculusXRSplashDesc

// Begin Enum EOculusXROcclusionsMode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXROcclusionsMode;
static UEnum* EOculusXROcclusionsMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXROcclusionsMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXROcclusionsMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXROcclusionsMode, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXROcclusionsMode"));
	}
	return Z_Registration_Info_UEnum_EOculusXROcclusionsMode.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXROcclusionsMode>()
{
	return EOculusXROcclusionsMode_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXROcclusionsMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Disabled.Comment", "/// Environment depth occlusions disabled.\n" },
		{ "Disabled.Name", "EOculusXROcclusionsMode::Disabled" },
		{ "Disabled.ToolTip", "Environment depth occlusions disabled." },
		{ "HardOcclusions.Comment", "/// Hard occlusions, good performance, shows hard edges between the real and virtual world.\n" },
		{ "HardOcclusions.Name", "EOculusXROcclusionsMode::HardOcclusions" },
		{ "HardOcclusions.ToolTip", "Hard occlusions, good performance, shows hard edges between the real and virtual world." },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
		{ "SoftOcclusions.Comment", "/// Soft occlusions, most expensive, shows soft edges between the real and virtual world.\n" },
		{ "SoftOcclusions.Name", "EOculusXROcclusionsMode::SoftOcclusions" },
		{ "SoftOcclusions.ToolTip", "Soft occlusions, most expensive, shows soft edges between the real and virtual world." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXROcclusionsMode::Disabled", (int64)EOculusXROcclusionsMode::Disabled },
		{ "EOculusXROcclusionsMode::HardOcclusions", (int64)EOculusXROcclusionsMode::HardOcclusions },
		{ "EOculusXROcclusionsMode::SoftOcclusions", (int64)EOculusXROcclusionsMode::SoftOcclusions },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXROcclusionsMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXROcclusionsMode",
	"EOculusXROcclusionsMode",
	Z_Construct_UEnum_OculusXRHMD_EOculusXROcclusionsMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXROcclusionsMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXROcclusionsMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXROcclusionsMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXROcclusionsMode()
{
	if (!Z_Registration_Info_UEnum_EOculusXROcclusionsMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXROcclusionsMode.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXROcclusionsMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXROcclusionsMode.InnerSingleton;
}
// End Enum EOculusXROcclusionsMode

// Begin Enum EOculusXREyeBufferSharpenType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXREyeBufferSharpenType;
static UEnum* EOculusXREyeBufferSharpenType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXREyeBufferSharpenType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXREyeBufferSharpenType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXREyeBufferSharpenType, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXREyeBufferSharpenType"));
	}
	return Z_Registration_Info_UEnum_EOculusXREyeBufferSharpenType.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXREyeBufferSharpenType>()
{
	return EOculusXREyeBufferSharpenType_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXREyeBufferSharpenType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
		{ "SLST_Auto.Comment", "/// Auto Filtering: Runtime automatically chooses the appropriate sharpening filter\n" },
		{ "SLST_Auto.DisplayName", "Auto Filtering" },
		{ "SLST_Auto.Name", "EOculusXREyeBufferSharpenType::SLST_Auto" },
		{ "SLST_Auto.ToolTip", "Auto Filtering: Runtime automatically chooses the appropriate sharpening filter" },
		{ "SLST_MAX.Name", "EOculusXREyeBufferSharpenType::SLST_MAX" },
		{ "SLST_None.Comment", "/// No Sharpening\n" },
		{ "SLST_None.DisplayName", "No Sharpening" },
		{ "SLST_None.Name", "EOculusXREyeBufferSharpenType::SLST_None" },
		{ "SLST_None.ToolTip", "No Sharpening" },
		{ "SLST_Normal.Comment", "/// Normal Sharpening\n" },
		{ "SLST_Normal.DisplayName", "Normal Sharpening" },
		{ "SLST_Normal.Name", "EOculusXREyeBufferSharpenType::SLST_Normal" },
		{ "SLST_Normal.ToolTip", "Normal Sharpening" },
		{ "SLST_Quality.Comment", "/// Quality Sharpening\n" },
		{ "SLST_Quality.DisplayName", "Quality Sharpening" },
		{ "SLST_Quality.Name", "EOculusXREyeBufferSharpenType::SLST_Quality" },
		{ "SLST_Quality.ToolTip", "Quality Sharpening" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXREyeBufferSharpenType::SLST_None", (int64)EOculusXREyeBufferSharpenType::SLST_None },
		{ "EOculusXREyeBufferSharpenType::SLST_Normal", (int64)EOculusXREyeBufferSharpenType::SLST_Normal },
		{ "EOculusXREyeBufferSharpenType::SLST_Quality", (int64)EOculusXREyeBufferSharpenType::SLST_Quality },
		{ "EOculusXREyeBufferSharpenType::SLST_Auto", (int64)EOculusXREyeBufferSharpenType::SLST_Auto },
		{ "EOculusXREyeBufferSharpenType::SLST_MAX", (int64)EOculusXREyeBufferSharpenType::SLST_MAX },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXREyeBufferSharpenType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXREyeBufferSharpenType",
	"EOculusXREyeBufferSharpenType",
	Z_Construct_UEnum_OculusXRHMD_EOculusXREyeBufferSharpenType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXREyeBufferSharpenType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXREyeBufferSharpenType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXREyeBufferSharpenType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXREyeBufferSharpenType()
{
	if (!Z_Registration_Info_UEnum_EOculusXREyeBufferSharpenType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXREyeBufferSharpenType.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXREyeBufferSharpenType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXREyeBufferSharpenType.InnerSingleton;
}
// End Enum EOculusXREyeBufferSharpenType

// Begin Enum EProcessorFavor
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EProcessorFavor;
static UEnum* EProcessorFavor_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EProcessorFavor.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EProcessorFavor.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EProcessorFavor, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EProcessorFavor"));
	}
	return Z_Registration_Info_UEnum_EProcessorFavor.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EProcessorFavor>()
{
	return EProcessorFavor_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EProcessorFavor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "FavorCPU.DisplayName", "Favor CPU" },
		{ "FavorCPU.Name", "EProcessorFavor::FavorCPU" },
		{ "FavorEqually.DisplayName", "Favor Equally" },
		{ "FavorEqually.Name", "EProcessorFavor::FavorEqually" },
		{ "FavorGPU.DisplayName", "Favor GPU" },
		{ "FavorGPU.Name", "EProcessorFavor::FavorGPU" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EProcessorFavor::FavorEqually", (int64)EProcessorFavor::FavorEqually },
		{ "EProcessorFavor::FavorCPU", (int64)EProcessorFavor::FavorCPU },
		{ "EProcessorFavor::FavorGPU", (int64)EProcessorFavor::FavorGPU },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EProcessorFavor_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EProcessorFavor",
	"EProcessorFavor",
	Z_Construct_UEnum_OculusXRHMD_EProcessorFavor_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EProcessorFavor_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EProcessorFavor_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EProcessorFavor_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EProcessorFavor()
{
	if (!Z_Registration_Info_UEnum_EProcessorFavor.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EProcessorFavor.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EProcessorFavor_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EProcessorFavor.InnerSingleton;
}
// End Enum EProcessorFavor

// Begin Enum EOculusXRHMDBodyTrackingFidelity
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRHMDBodyTrackingFidelity;
static UEnum* EOculusXRHMDBodyTrackingFidelity_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRHMDBodyTrackingFidelity.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRHMDBodyTrackingFidelity.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyTrackingFidelity, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRHMDBodyTrackingFidelity"));
	}
	return Z_Registration_Info_UEnum_EOculusXRHMDBodyTrackingFidelity.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRHMDBodyTrackingFidelity>()
{
	return EOculusXRHMDBodyTrackingFidelity_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyTrackingFidelity_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "High.Name", "EOculusXRHMDBodyTrackingFidelity::High" },
		{ "Low.Name", "EOculusXRHMDBodyTrackingFidelity::Low" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
		{ "Unset.Hidden", "" },
		{ "Unset.Name", "EOculusXRHMDBodyTrackingFidelity::Unset" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRHMDBodyTrackingFidelity::Unset", (int64)EOculusXRHMDBodyTrackingFidelity::Unset },
		{ "EOculusXRHMDBodyTrackingFidelity::Low", (int64)EOculusXRHMDBodyTrackingFidelity::Low },
		{ "EOculusXRHMDBodyTrackingFidelity::High", (int64)EOculusXRHMDBodyTrackingFidelity::High },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyTrackingFidelity_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRHMDBodyTrackingFidelity",
	"EOculusXRHMDBodyTrackingFidelity",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyTrackingFidelity_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyTrackingFidelity_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyTrackingFidelity_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyTrackingFidelity_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyTrackingFidelity()
{
	if (!Z_Registration_Info_UEnum_EOculusXRHMDBodyTrackingFidelity.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRHMDBodyTrackingFidelity.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyTrackingFidelity_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRHMDBodyTrackingFidelity.InnerSingleton;
}
// End Enum EOculusXRHMDBodyTrackingFidelity

// Begin Enum EOculusXRHMDBodyJointSet
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRHMDBodyJointSet;
static UEnum* EOculusXRHMDBodyJointSet_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRHMDBodyJointSet.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRHMDBodyJointSet.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyJointSet, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRHMDBodyJointSet"));
	}
	return Z_Registration_Info_UEnum_EOculusXRHMDBodyJointSet.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRHMDBodyJointSet>()
{
	return EOculusXRHMDBodyJointSet_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyJointSet_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "FullBody.Name", "EOculusXRHMDBodyJointSet::FullBody" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
		{ "UpperBody.Name", "EOculusXRHMDBodyJointSet::UpperBody" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRHMDBodyJointSet::UpperBody", (int64)EOculusXRHMDBodyJointSet::UpperBody },
		{ "EOculusXRHMDBodyJointSet::FullBody", (int64)EOculusXRHMDBodyJointSet::FullBody },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyJointSet_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRHMDBodyJointSet",
	"EOculusXRHMDBodyJointSet",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyJointSet_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyJointSet_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyJointSet_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyJointSet_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyJointSet()
{
	if (!Z_Registration_Info_UEnum_EOculusXRHMDBodyJointSet.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRHMDBodyJointSet.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRHMDBodyJointSet_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRHMDBodyJointSet.InnerSingleton;
}
// End Enum EOculusXRHMDBodyJointSet

// Begin Enum EFaceTrackingDataSourceConfig
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFaceTrackingDataSourceConfig;
static UEnum* EFaceTrackingDataSourceConfig_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EFaceTrackingDataSourceConfig.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EFaceTrackingDataSourceConfig.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EFaceTrackingDataSourceConfig, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EFaceTrackingDataSourceConfig"));
	}
	return Z_Registration_Info_UEnum_EFaceTrackingDataSourceConfig.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EFaceTrackingDataSourceConfig>()
{
	return EFaceTrackingDataSourceConfig_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EFaceTrackingDataSourceConfig_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Audio.DisplayName", "Audio" },
		{ "Audio.Name", "EFaceTrackingDataSourceConfig::Audio" },
		{ "MAX.Hidden", "" },
		{ "MAX.Name", "EFaceTrackingDataSourceConfig::MAX" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
		{ "Visual.DisplayName", "Visual" },
		{ "Visual.Name", "EFaceTrackingDataSourceConfig::Visual" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EFaceTrackingDataSourceConfig::Visual", (int64)EFaceTrackingDataSourceConfig::Visual },
		{ "EFaceTrackingDataSourceConfig::Audio", (int64)EFaceTrackingDataSourceConfig::Audio },
		{ "EFaceTrackingDataSourceConfig::MAX", (int64)EFaceTrackingDataSourceConfig::MAX },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EFaceTrackingDataSourceConfig_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EFaceTrackingDataSourceConfig",
	"EFaceTrackingDataSourceConfig",
	Z_Construct_UEnum_OculusXRHMD_EFaceTrackingDataSourceConfig_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EFaceTrackingDataSourceConfig_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EFaceTrackingDataSourceConfig_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EFaceTrackingDataSourceConfig_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EFaceTrackingDataSourceConfig()
{
	if (!Z_Registration_Info_UEnum_EFaceTrackingDataSourceConfig.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFaceTrackingDataSourceConfig.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EFaceTrackingDataSourceConfig_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EFaceTrackingDataSourceConfig.InnerSingleton;
}
// End Enum EFaceTrackingDataSourceConfig

// Begin Enum ESystemSplashBackgroundType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESystemSplashBackgroundType;
static UEnum* ESystemSplashBackgroundType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESystemSplashBackgroundType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESystemSplashBackgroundType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_ESystemSplashBackgroundType, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("ESystemSplashBackgroundType"));
	}
	return Z_Registration_Info_UEnum_ESystemSplashBackgroundType.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<ESystemSplashBackgroundType>()
{
	return ESystemSplashBackgroundType_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_ESystemSplashBackgroundType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Black.DisplayName", "Black" },
		{ "Black.Name", "ESystemSplashBackgroundType::Black" },
		{ "Contextual.DisplayName", "Passthrough (Contextual)" },
		{ "Contextual.Name", "ESystemSplashBackgroundType::Contextual" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESystemSplashBackgroundType::Black", (int64)ESystemSplashBackgroundType::Black },
		{ "ESystemSplashBackgroundType::Contextual", (int64)ESystemSplashBackgroundType::Contextual },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_ESystemSplashBackgroundType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"ESystemSplashBackgroundType",
	"ESystemSplashBackgroundType",
	Z_Construct_UEnum_OculusXRHMD_ESystemSplashBackgroundType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_ESystemSplashBackgroundType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_ESystemSplashBackgroundType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_ESystemSplashBackgroundType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_ESystemSplashBackgroundType()
{
	if (!Z_Registration_Info_UEnum_ESystemSplashBackgroundType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESystemSplashBackgroundType.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_ESystemSplashBackgroundType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESystemSplashBackgroundType.InnerSingleton;
}
// End Enum ESystemSplashBackgroundType

// Begin ScriptStruct FOculusXRPerformanceMetrics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OculusXRPerformanceMetrics;
class UScriptStruct* FOculusXRPerformanceMetrics::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRPerformanceMetrics.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OculusXRPerformanceMetrics.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("OculusXRPerformanceMetrics"));
	}
	return Z_Registration_Info_UScriptStruct_OculusXRPerformanceMetrics.OuterSingleton;
}
template<> OCULUSXRHMD_API UScriptStruct* StaticStruct<FOculusXRPerformanceMetrics>()
{
	return FOculusXRPerformanceMetrics::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "Oculus Performance Metrics" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AppCpuTime_MetaData[] = {
		{ "Category", "Performance Metrics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** App CPU Time (ms) */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "App CPU Time (ms)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AppGpuTime_MetaData[] = {
		{ "Category", "Performance Metrics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** App GPU Time (ms) */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "App GPU Time (ms)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComCpuTime_MetaData[] = {
		{ "Category", "Performance Metrics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Compositor CPU Time (ms) */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compositor CPU Time (ms)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComGpuTime_MetaData[] = {
		{ "Category", "Performance Metrics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Compositor GPU Time (ms) */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compositor GPU Time (ms)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DroppedFrames_MetaData[] = {
		{ "Category", "Performance Metrics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Compositor Dropped Frames */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compositor Dropped Frames" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GpuUtil_MetaData[] = {
		{ "Category", "Performance Metrics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** System GPU Util % */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "System GPU Util %" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CpuUtilAvg_MetaData[] = {
		{ "Category", "Performance Metrics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** System CPU Util Avg % */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "System CPU Util Avg %" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CpuUtilWorst_MetaData[] = {
		{ "Category", "Performance Metrics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** System CPU Util Worst % */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "System CPU Util Worst %" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComSpaceWarpMode_MetaData[] = {
		{ "Category", "Performance Metrics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Compositor SpaceWarp Mode: 0: Disabled; 1: Enabled */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compositor SpaceWarp Mode: 0: Disabled; 1: Enabled" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CpuCoreUtil_MetaData[] = {
		{ "Category", "Performance Metrics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** CPU Core Util % */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CPU Core Util %" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AppCpuTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AppGpuTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ComCpuTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ComGpuTime;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DroppedFrames;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GpuUtil;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CpuUtilAvg;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CpuUtilWorst;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ComSpaceWarpMode;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CpuCoreUtil_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CpuCoreUtil;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOculusXRPerformanceMetrics>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_AppCpuTime = { "AppCpuTime", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPerformanceMetrics, AppCpuTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AppCpuTime_MetaData), NewProp_AppCpuTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_AppGpuTime = { "AppGpuTime", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPerformanceMetrics, AppGpuTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AppGpuTime_MetaData), NewProp_AppGpuTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_ComCpuTime = { "ComCpuTime", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPerformanceMetrics, ComCpuTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComCpuTime_MetaData), NewProp_ComCpuTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_ComGpuTime = { "ComGpuTime", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPerformanceMetrics, ComGpuTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComGpuTime_MetaData), NewProp_ComGpuTime_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_DroppedFrames = { "DroppedFrames", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPerformanceMetrics, DroppedFrames), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DroppedFrames_MetaData), NewProp_DroppedFrames_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_GpuUtil = { "GpuUtil", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPerformanceMetrics, GpuUtil), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GpuUtil_MetaData), NewProp_GpuUtil_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_CpuUtilAvg = { "CpuUtilAvg", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPerformanceMetrics, CpuUtilAvg), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CpuUtilAvg_MetaData), NewProp_CpuUtilAvg_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_CpuUtilWorst = { "CpuUtilWorst", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPerformanceMetrics, CpuUtilWorst), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CpuUtilWorst_MetaData), NewProp_CpuUtilWorst_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_ComSpaceWarpMode = { "ComSpaceWarpMode", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPerformanceMetrics, ComSpaceWarpMode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComSpaceWarpMode_MetaData), NewProp_ComSpaceWarpMode_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_CpuCoreUtil_Inner = { "CpuCoreUtil", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_CpuCoreUtil = { "CpuCoreUtil", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRPerformanceMetrics, CpuCoreUtil), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CpuCoreUtil_MetaData), NewProp_CpuCoreUtil_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_AppCpuTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_AppGpuTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_ComCpuTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_ComGpuTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_DroppedFrames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_GpuUtil,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_CpuUtilAvg,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_CpuUtilWorst,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_ComSpaceWarpMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_CpuCoreUtil_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewProp_CpuCoreUtil,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	&NewStructOps,
	"OculusXRPerformanceMetrics",
	Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::PropPointers),
	sizeof(FOculusXRPerformanceMetrics),
	alignof(FOculusXRPerformanceMetrics),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRPerformanceMetrics.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OculusXRPerformanceMetrics.InnerSingleton, Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OculusXRPerformanceMetrics.InnerSingleton;
}
// End ScriptStruct FOculusXRPerformanceMetrics

// Begin Enum EOculusXRMPPoseRestoreType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRMPPoseRestoreType;
static UEnum* EOculusXRMPPoseRestoreType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRMPPoseRestoreType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRMPPoseRestoreType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRHMD_EOculusXRMPPoseRestoreType, (UObject*)Z_Construct_UPackage__Script_OculusXRHMD(), TEXT("EOculusXRMPPoseRestoreType"));
	}
	return Z_Registration_Info_UEnum_EOculusXRMPPoseRestoreType.OuterSingleton;
}
template<> OCULUSXRHMD_API UEnum* StaticEnum<EOculusXRMPPoseRestoreType>()
{
	return EOculusXRMPPoseRestoreType_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRHMD_EOculusXRMPPoseRestoreType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Disabled.Comment", "/// DONOT restore head and controller poses\n" },
		{ "Disabled.DisplayName", "Disabled" },
		{ "Disabled.Name", "EOculusXRMPPoseRestoreType::Disabled" },
		{ "Disabled.ToolTip", "DONOT restore head and controller poses" },
		{ "ModuleRelativePath", "Public/OculusXRHMDTypes.h" },
		{ "PositionAndRotation.Comment", "/// Restore head and controller position and rotation\n" },
		{ "PositionAndRotation.DisplayName", "Restore Position And Rotation" },
		{ "PositionAndRotation.Name", "EOculusXRMPPoseRestoreType::PositionAndRotation" },
		{ "PositionAndRotation.ToolTip", "Restore head and controller position and rotation" },
		{ "PositionOnly.Comment", "/// Only restore head and controller position\n" },
		{ "PositionOnly.DisplayName", "Restore Position Only" },
		{ "PositionOnly.Name", "EOculusXRMPPoseRestoreType::PositionOnly" },
		{ "PositionOnly.ToolTip", "Only restore head and controller position" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRMPPoseRestoreType::Disabled", (int64)EOculusXRMPPoseRestoreType::Disabled },
		{ "EOculusXRMPPoseRestoreType::PositionOnly", (int64)EOculusXRMPPoseRestoreType::PositionOnly },
		{ "EOculusXRMPPoseRestoreType::PositionAndRotation", (int64)EOculusXRMPPoseRestoreType::PositionAndRotation },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRHMD_EOculusXRMPPoseRestoreType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRHMD,
	nullptr,
	"EOculusXRMPPoseRestoreType",
	"EOculusXRMPPoseRestoreType",
	Z_Construct_UEnum_OculusXRHMD_EOculusXRMPPoseRestoreType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRMPPoseRestoreType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRHMD_EOculusXRMPPoseRestoreType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRHMD_EOculusXRMPPoseRestoreType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRHMD_EOculusXRMPPoseRestoreType()
{
	if (!Z_Registration_Info_UEnum_EOculusXRMPPoseRestoreType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRMPPoseRestoreType.InnerSingleton, Z_Construct_UEnum_OculusXRHMD_EOculusXRMPPoseRestoreType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRMPPoseRestoreType.InnerSingleton;
}
// End Enum EOculusXRMPPoseRestoreType

// Begin Registration
struct Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRHMDTypes_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOculusXRTrackedDeviceType_StaticEnum, TEXT("EOculusXRTrackedDeviceType"), &Z_Registration_Info_UEnum_EOculusXRTrackedDeviceType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2225433783U) },
		{ EOculusXRFoveatedRenderingMethod_StaticEnum, TEXT("EOculusXRFoveatedRenderingMethod"), &Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingMethod, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1262503363U) },
		{ EOculusXRFoveatedRenderingLevel_StaticEnum, TEXT("EOculusXRFoveatedRenderingLevel"), &Z_Registration_Info_UEnum_EOculusXRFoveatedRenderingLevel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2300058379U) },
		{ EOculusXRBoundaryType_StaticEnum, TEXT("EOculusXRBoundaryType"), &Z_Registration_Info_UEnum_EOculusXRBoundaryType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3419051359U) },
		{ EOculusXRColorSpace_StaticEnum, TEXT("EOculusXRColorSpace"), &Z_Registration_Info_UEnum_EOculusXRColorSpace, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2401649762U) },
		{ EOculusXRHandTrackingSupport_StaticEnum, TEXT("EOculusXRHandTrackingSupport"), &Z_Registration_Info_UEnum_EOculusXRHandTrackingSupport, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3434875552U) },
		{ EOculusXRHandTrackingFrequency_StaticEnum, TEXT("EOculusXRHandTrackingFrequency"), &Z_Registration_Info_UEnum_EOculusXRHandTrackingFrequency, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 727404598U) },
		{ EOculusXRHandTrackingVersion_StaticEnum, TEXT("EOculusXRHandTrackingVersion"), &Z_Registration_Info_UEnum_EOculusXRHandTrackingVersion, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 997953093U) },
		{ EOculusXRProcessorPerformanceLevel_StaticEnum, TEXT("EOculusXRProcessorPerformanceLevel"), &Z_Registration_Info_UEnum_EOculusXRProcessorPerformanceLevel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1326426722U) },
		{ EOculusXRDeviceType_StaticEnum, TEXT("EOculusXRDeviceType"), &Z_Registration_Info_UEnum_EOculusXRDeviceType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3481782517U) },
		{ EOculusXRControllerType_StaticEnum, TEXT("EOculusXRControllerType"), &Z_Registration_Info_UEnum_EOculusXRControllerType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3572997132U) },
		{ EOculusXRXrApi_StaticEnum, TEXT("EOculusXRXrApi"), &Z_Registration_Info_UEnum_EOculusXRXrApi, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1350361086U) },
		{ EOculusXRControllerPoseAlignment_StaticEnum, TEXT("EOculusXRControllerPoseAlignment"), &Z_Registration_Info_UEnum_EOculusXRControllerPoseAlignment, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1845550723U) },
		{ EOculusXROcclusionsMode_StaticEnum, TEXT("EOculusXROcclusionsMode"), &Z_Registration_Info_UEnum_EOculusXROcclusionsMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4211737068U) },
		{ EOculusXREyeBufferSharpenType_StaticEnum, TEXT("EOculusXREyeBufferSharpenType"), &Z_Registration_Info_UEnum_EOculusXREyeBufferSharpenType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2052807746U) },
		{ EProcessorFavor_StaticEnum, TEXT("EProcessorFavor"), &Z_Registration_Info_UEnum_EProcessorFavor, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2971397453U) },
		{ EOculusXRHMDBodyTrackingFidelity_StaticEnum, TEXT("EOculusXRHMDBodyTrackingFidelity"), &Z_Registration_Info_UEnum_EOculusXRHMDBodyTrackingFidelity, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3841332885U) },
		{ EOculusXRHMDBodyJointSet_StaticEnum, TEXT("EOculusXRHMDBodyJointSet"), &Z_Registration_Info_UEnum_EOculusXRHMDBodyJointSet, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1156729292U) },
		{ EFaceTrackingDataSourceConfig_StaticEnum, TEXT("EFaceTrackingDataSourceConfig"), &Z_Registration_Info_UEnum_EFaceTrackingDataSourceConfig, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1265564137U) },
		{ ESystemSplashBackgroundType_StaticEnum, TEXT("ESystemSplashBackgroundType"), &Z_Registration_Info_UEnum_ESystemSplashBackgroundType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1293353650U) },
		{ EOculusXRMPPoseRestoreType_StaticEnum, TEXT("EOculusXRMPPoseRestoreType"), &Z_Registration_Info_UEnum_EOculusXRMPPoseRestoreType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3004586184U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOculusXRHmdUserProfileField::StaticStruct, Z_Construct_UScriptStruct_FOculusXRHmdUserProfileField_Statics::NewStructOps, TEXT("OculusXRHmdUserProfileField"), &Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfileField, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOculusXRHmdUserProfileField), 1686145672U) },
		{ FOculusXRHmdUserProfile::StaticStruct, Z_Construct_UScriptStruct_FOculusXRHmdUserProfile_Statics::NewStructOps, TEXT("OculusXRHmdUserProfile"), &Z_Registration_Info_UScriptStruct_OculusXRHmdUserProfile, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOculusXRHmdUserProfile), 1594008665U) },
		{ FOculusXRGuardianTestResult::StaticStruct, Z_Construct_UScriptStruct_FOculusXRGuardianTestResult_Statics::NewStructOps, TEXT("OculusXRGuardianTestResult"), &Z_Registration_Info_UScriptStruct_OculusXRGuardianTestResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOculusXRGuardianTestResult), 2633819891U) },
		{ FOculusXRSplashDesc::StaticStruct, Z_Construct_UScriptStruct_FOculusXRSplashDesc_Statics::NewStructOps, TEXT("OculusXRSplashDesc"), &Z_Registration_Info_UScriptStruct_OculusXRSplashDesc, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOculusXRSplashDesc), 197694465U) },
		{ FOculusXRPerformanceMetrics::StaticStruct, Z_Construct_UScriptStruct_FOculusXRPerformanceMetrics_Statics::NewStructOps, TEXT("OculusXRPerformanceMetrics"), &Z_Registration_Info_UScriptStruct_OculusXRPerformanceMetrics, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOculusXRPerformanceMetrics), 2824172626U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRHMDTypes_h_833536146(TEXT("/Script/OculusXRHMD"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRHMDTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRHMDTypes_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRHMDTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRHMD_Public_OculusXRHMDTypes_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
