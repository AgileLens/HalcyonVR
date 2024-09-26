// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MRUtilityKit/Public/MRUtilityKit.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMRUtilityKit() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_UMRUKSettings();
MRUTILITYKIT_API UClass* Z_Construct_UClass_UMRUKSettings_NoRegister();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKAlignMode();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeU();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeV();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKFallbackToProceduralOverwrite();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKInitStatus();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerScalingMode();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerSelectionMode();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode();
MRUTILITYKIT_API UScriptStruct* Z_Construct_UScriptStruct_FMRUKHit();
MRUTILITYKIT_API UScriptStruct* Z_Construct_UScriptStruct_FMRUKLabelFilter();
MRUTILITYKIT_API UScriptStruct* Z_Construct_UScriptStruct_FMRUKPlaneUV();
MRUTILITYKIT_API UScriptStruct* Z_Construct_UScriptStruct_FMRUKSpawnActor();
MRUTILITYKIT_API UScriptStruct* Z_Construct_UScriptStruct_FMRUKSpawnGroup();
MRUTILITYKIT_API UScriptStruct* Z_Construct_UScriptStruct_FMRUKTexCoordModes();
UPackage* Z_Construct_UPackage__Script_MRUtilityKit();
// End Cross Module References

// Begin Enum EMRUKInitStatus
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMRUKInitStatus;
static UEnum* EMRUKInitStatus_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMRUKInitStatus.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMRUKInitStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MRUtilityKit_EMRUKInitStatus, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("EMRUKInitStatus"));
	}
	return Z_Registration_Info_UEnum_EMRUKInitStatus.OuterSingleton;
}
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKInitStatus>()
{
	return EMRUKInitStatus_StaticEnum();
}
struct Z_Construct_UEnum_MRUtilityKit_EMRUKInitStatus_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Busy.Comment", "/// Is busy Initializing.\n" },
		{ "Busy.Name", "EMRUKInitStatus::Busy" },
		{ "Busy.ToolTip", "Is busy Initializing." },
		{ "Complete.Comment", "/// Has finished Initializing.\n" },
		{ "Complete.Name", "EMRUKInitStatus::Complete" },
		{ "Complete.ToolTip", "Has finished Initializing." },
		{ "Failed.Comment", "/// Failed to initialize.\n" },
		{ "Failed.Name", "EMRUKInitStatus::Failed" },
		{ "Failed.ToolTip", "Failed to initialize." },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
		{ "None.Comment", "/// Not Initialized.\n" },
		{ "None.Name", "EMRUKInitStatus::None" },
		{ "None.ToolTip", "Not Initialized." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMRUKInitStatus::None", (int64)EMRUKInitStatus::None },
		{ "EMRUKInitStatus::Busy", (int64)EMRUKInitStatus::Busy },
		{ "EMRUKInitStatus::Complete", (int64)EMRUKInitStatus::Complete },
		{ "EMRUKInitStatus::Failed", (int64)EMRUKInitStatus::Failed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MRUtilityKit_EMRUKInitStatus_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	"EMRUKInitStatus",
	"EMRUKInitStatus",
	Z_Construct_UEnum_MRUtilityKit_EMRUKInitStatus_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKInitStatus_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKInitStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MRUtilityKit_EMRUKInitStatus_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKInitStatus()
{
	if (!Z_Registration_Info_UEnum_EMRUKInitStatus.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMRUKInitStatus.InnerSingleton, Z_Construct_UEnum_MRUtilityKit_EMRUKInitStatus_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMRUKInitStatus.InnerSingleton;
}
// End Enum EMRUKInitStatus

// Begin Enum EMRUKCoordModeU
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMRUKCoordModeU;
static UEnum* EMRUKCoordModeU_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMRUKCoordModeU.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMRUKCoordModeU.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeU, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("EMRUKCoordModeU"));
	}
	return Z_Registration_Info_UEnum_EMRUKCoordModeU.OuterSingleton;
}
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKCoordModeU>()
{
	return EMRUKCoordModeU_StaticEnum();
}
struct Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeU_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "MaintainAspectRatio.Comment", "/// The texture coordinates are adjusted to the other dimensions to ensure the aspect ratio is maintained.\n" },
		{ "MaintainAspectRatio.Name", "EMRUKCoordModeU::MaintainAspectRatio" },
		{ "MaintainAspectRatio.ToolTip", "The texture coordinates are adjusted to the other dimensions to ensure the aspect ratio is maintained." },
		{ "MaintainAspectRatioSeamless.Comment", "/// The texture coordinates are adjusted to the other dimensions to ensure the aspect ratio is maintained but are adjusted to end on a whole number to avoid seams.\n" },
		{ "MaintainAspectRatioSeamless.Name", "EMRUKCoordModeU::MaintainAspectRatioSeamless" },
		{ "MaintainAspectRatioSeamless.ToolTip", "The texture coordinates are adjusted to the other dimensions to ensure the aspect ratio is maintained but are adjusted to end on a whole number to avoid seams." },
		{ "Metric.Comment", "/// The texture coordinates start at 0 and increase by 1 unit every meter.\n" },
		{ "Metric.Name", "EMRUKCoordModeU::Metric" },
		{ "Metric.ToolTip", "The texture coordinates start at 0 and increase by 1 unit every meter." },
		{ "MetricSeamless.Comment", "/// The texture coordinates start at 0 and increase by 1 unit every meter but are adjusted to end on a whole number to avoid seams.\n" },
		{ "MetricSeamless.Name", "EMRUKCoordModeU::MetricSeamless" },
		{ "MetricSeamless.ToolTip", "The texture coordinates start at 0 and increase by 1 unit every meter but are adjusted to end on a whole number to avoid seams." },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
		{ "Stretch.Comment", "/// The texture coordinates range from 0 to 1.\n" },
		{ "Stretch.Name", "EMRUKCoordModeU::Stretch" },
		{ "Stretch.ToolTip", "The texture coordinates range from 0 to 1." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMRUKCoordModeU::Metric", (int64)EMRUKCoordModeU::Metric },
		{ "EMRUKCoordModeU::MetricSeamless", (int64)EMRUKCoordModeU::MetricSeamless },
		{ "EMRUKCoordModeU::MaintainAspectRatio", (int64)EMRUKCoordModeU::MaintainAspectRatio },
		{ "EMRUKCoordModeU::MaintainAspectRatioSeamless", (int64)EMRUKCoordModeU::MaintainAspectRatioSeamless },
		{ "EMRUKCoordModeU::Stretch", (int64)EMRUKCoordModeU::Stretch },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeU_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	"EMRUKCoordModeU",
	"EMRUKCoordModeU",
	Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeU_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeU_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeU_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeU_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeU()
{
	if (!Z_Registration_Info_UEnum_EMRUKCoordModeU.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMRUKCoordModeU.InnerSingleton, Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeU_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMRUKCoordModeU.InnerSingleton;
}
// End Enum EMRUKCoordModeU

// Begin Enum EMRUKCoordModeV
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMRUKCoordModeV;
static UEnum* EMRUKCoordModeV_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMRUKCoordModeV.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMRUKCoordModeV.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeV, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("EMRUKCoordModeV"));
	}
	return Z_Registration_Info_UEnum_EMRUKCoordModeV.OuterSingleton;
}
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKCoordModeV>()
{
	return EMRUKCoordModeV_StaticEnum();
}
struct Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeV_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "MaintainAspectRatio.Comment", "/// The texture coordinates are adjusted to the other dimensions to ensure the aspect ratio is maintained.\n" },
		{ "MaintainAspectRatio.Name", "EMRUKCoordModeV::MaintainAspectRatio" },
		{ "MaintainAspectRatio.ToolTip", "The texture coordinates are adjusted to the other dimensions to ensure the aspect ratio is maintained." },
		{ "Metric.Comment", "/// The texture coordinates start at 0 and increase by 1 unit every meter.\n" },
		{ "Metric.Name", "EMRUKCoordModeV::Metric" },
		{ "Metric.ToolTip", "The texture coordinates start at 0 and increase by 1 unit every meter." },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
		{ "Stretch.Comment", "/// The texture coordinates range from 0 to 1.\n" },
		{ "Stretch.Name", "EMRUKCoordModeV::Stretch" },
		{ "Stretch.ToolTip", "The texture coordinates range from 0 to 1." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMRUKCoordModeV::Metric", (int64)EMRUKCoordModeV::Metric },
		{ "EMRUKCoordModeV::MaintainAspectRatio", (int64)EMRUKCoordModeV::MaintainAspectRatio },
		{ "EMRUKCoordModeV::Stretch", (int64)EMRUKCoordModeV::Stretch },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeV_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	"EMRUKCoordModeV",
	"EMRUKCoordModeV",
	Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeV_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeV_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeV_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeV_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeV()
{
	if (!Z_Registration_Info_UEnum_EMRUKCoordModeV.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMRUKCoordModeV.InnerSingleton, Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeV_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMRUKCoordModeV.InnerSingleton;
}
// End Enum EMRUKCoordModeV

// Begin Enum EMRUKSpawnerSelectionMode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMRUKSpawnerSelectionMode;
static UEnum* EMRUKSpawnerSelectionMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMRUKSpawnerSelectionMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMRUKSpawnerSelectionMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerSelectionMode, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("EMRUKSpawnerSelectionMode"));
	}
	return Z_Registration_Info_UEnum_EMRUKSpawnerSelectionMode.OuterSingleton;
}
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKSpawnerSelectionMode>()
{
	return EMRUKSpawnerSelectionMode_StaticEnum();
}
struct Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerSelectionMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClosestSize.Comment", "/// Pick the closest size.\n" },
		{ "ClosestSize.Name", "EMRUKSpawnerSelectionMode::ClosestSize" },
		{ "ClosestSize.ToolTip", "Pick the closest size." },
		{ "Custom.Comment", "/// Used in the AMRUKAnchorActorSpawner to use allow for a custom selection mode.\n" },
		{ "Custom.Name", "EMRUKSpawnerSelectionMode::Custom" },
		{ "Custom.ToolTip", "Used in the AMRUKAnchorActorSpawner to use allow for a custom selection mode." },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
		{ "Random.Comment", "/// Pick one at random.\n" },
		{ "Random.Name", "EMRUKSpawnerSelectionMode::Random" },
		{ "Random.ToolTip", "Pick one at random." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMRUKSpawnerSelectionMode::Random", (int64)EMRUKSpawnerSelectionMode::Random },
		{ "EMRUKSpawnerSelectionMode::ClosestSize", (int64)EMRUKSpawnerSelectionMode::ClosestSize },
		{ "EMRUKSpawnerSelectionMode::Custom", (int64)EMRUKSpawnerSelectionMode::Custom },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerSelectionMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	"EMRUKSpawnerSelectionMode",
	"EMRUKSpawnerSelectionMode",
	Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerSelectionMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerSelectionMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerSelectionMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerSelectionMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerSelectionMode()
{
	if (!Z_Registration_Info_UEnum_EMRUKSpawnerSelectionMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMRUKSpawnerSelectionMode.InnerSingleton, Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerSelectionMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMRUKSpawnerSelectionMode.InnerSingleton;
}
// End Enum EMRUKSpawnerSelectionMode

// Begin Enum EMRUKSpawnerScalingMode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMRUKSpawnerScalingMode;
static UEnum* EMRUKSpawnerScalingMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMRUKSpawnerScalingMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMRUKSpawnerScalingMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerScalingMode, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("EMRUKSpawnerScalingMode"));
	}
	return Z_Registration_Info_UEnum_EMRUKSpawnerScalingMode.OuterSingleton;
}
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKSpawnerScalingMode>()
{
	return EMRUKSpawnerScalingMode_StaticEnum();
}
struct Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerScalingMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Custom.Comment", "/// Used in the AMRUKAnchorActorSpawner to use allow for a custom scaling.\n" },
		{ "Custom.Name", "EMRUKSpawnerScalingMode::Custom" },
		{ "Custom.ToolTip", "Used in the AMRUKAnchorActorSpawner to use allow for a custom scaling." },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
		{ "NoScaling.Comment", "/// Don't perform any scaling.\n" },
		{ "NoScaling.Name", "EMRUKSpawnerScalingMode::NoScaling" },
		{ "NoScaling.ToolTip", "Don't perform any scaling." },
		{ "Stretch.Comment", "/// Stretch each axis to exactly match the size of the Plane/Volume.\n" },
		{ "Stretch.Name", "EMRUKSpawnerScalingMode::Stretch" },
		{ "Stretch.ToolTip", "Stretch each axis to exactly match the size of the Plane/Volume." },
		{ "UniformScaling.Comment", "/// Scale each axis by the same amount to maintain the correct aspect ratio.\n" },
		{ "UniformScaling.Name", "EMRUKSpawnerScalingMode::UniformScaling" },
		{ "UniformScaling.ToolTip", "Scale each axis by the same amount to maintain the correct aspect ratio." },
		{ "UniformXYScale.Comment", "/// Scale the X and Y axes uniformly but the Z scale can be different.\n" },
		{ "UniformXYScale.Name", "EMRUKSpawnerScalingMode::UniformXYScale" },
		{ "UniformXYScale.ToolTip", "Scale the X and Y axes uniformly but the Z scale can be different." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMRUKSpawnerScalingMode::Stretch", (int64)EMRUKSpawnerScalingMode::Stretch },
		{ "EMRUKSpawnerScalingMode::UniformScaling", (int64)EMRUKSpawnerScalingMode::UniformScaling },
		{ "EMRUKSpawnerScalingMode::UniformXYScale", (int64)EMRUKSpawnerScalingMode::UniformXYScale },
		{ "EMRUKSpawnerScalingMode::NoScaling", (int64)EMRUKSpawnerScalingMode::NoScaling },
		{ "EMRUKSpawnerScalingMode::Custom", (int64)EMRUKSpawnerScalingMode::Custom },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerScalingMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	"EMRUKSpawnerScalingMode",
	"EMRUKSpawnerScalingMode",
	Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerScalingMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerScalingMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerScalingMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerScalingMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerScalingMode()
{
	if (!Z_Registration_Info_UEnum_EMRUKSpawnerScalingMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMRUKSpawnerScalingMode.InnerSingleton, Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerScalingMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMRUKSpawnerScalingMode.InnerSingleton;
}
// End Enum EMRUKSpawnerScalingMode

// Begin Enum EMRUKAlignMode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMRUKAlignMode;
static UEnum* EMRUKAlignMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMRUKAlignMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMRUKAlignMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MRUtilityKit_EMRUKAlignMode, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("EMRUKAlignMode"));
	}
	return Z_Registration_Info_UEnum_EMRUKAlignMode.OuterSingleton;
}
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKAlignMode>()
{
	return EMRUKAlignMode_StaticEnum();
}
struct Z_Construct_UEnum_MRUtilityKit_EMRUKAlignMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BackOnBack.Comment", "/// Align the back of the bounding boxes and center the rest\n" },
		{ "BackOnBack.Name", "EMRUKAlignMode::BackOnBack" },
		{ "BackOnBack.ToolTip", "Align the back of the bounding boxes and center the rest" },
		{ "BackOnFront.Comment", "/// Align the back to the front of the anchor bounding box and center the rest\n" },
		{ "BackOnFront.Name", "EMRUKAlignMode::BackOnFront" },
		{ "BackOnFront.ToolTip", "Align the back to the front of the anchor bounding box and center the rest" },
		{ "BlueprintType", "true" },
		{ "BottomOnBottom.Comment", "/// Align the bottom of the bounding boxes and center the rest\n" },
		{ "BottomOnBottom.Name", "EMRUKAlignMode::BottomOnBottom" },
		{ "BottomOnBottom.ToolTip", "Align the bottom of the bounding boxes and center the rest" },
		{ "BottomOnTop.Comment", "/// Align the top to the bottom of the anchor bounding box and center the rest\n" },
		{ "BottomOnTop.Name", "EMRUKAlignMode::BottomOnTop" },
		{ "BottomOnTop.ToolTip", "Align the top to the bottom of the anchor bounding box and center the rest" },
		{ "CenterOnCenter.Comment", "/// Center the bounding box in the anchor bounding box\n" },
		{ "CenterOnCenter.Name", "EMRUKAlignMode::CenterOnCenter" },
		{ "CenterOnCenter.ToolTip", "Center the bounding box in the anchor bounding box" },
		{ "Custom.Comment", "/// Use custom alignment mode\n" },
		{ "Custom.Name", "EMRUKAlignMode::Custom" },
		{ "Custom.ToolTip", "Use custom alignment mode" },
		{ "Default.Comment", "/// Align the bottom of the bounding boxes and center the rest\n" },
		{ "Default.Name", "EMRUKAlignMode::Default" },
		{ "Default.ToolTip", "Align the bottom of the bounding boxes and center the rest" },
		{ "FrontOnBack.Comment", "/// Align the front to the back of the anchor bounding box and center the rest\n" },
		{ "FrontOnBack.Name", "EMRUKAlignMode::FrontOnBack" },
		{ "FrontOnBack.ToolTip", "Align the front to the back of the anchor bounding box and center the rest" },
		{ "FrontOnFront.Comment", "/// Align the front of the bounding boxes and center the rest\n" },
		{ "FrontOnFront.Name", "EMRUKAlignMode::FrontOnFront" },
		{ "FrontOnFront.ToolTip", "Align the front of the bounding boxes and center the rest" },
		{ "LeftOnLeft.Comment", "/// Align the left of the bounding boxes and center the rest\n" },
		{ "LeftOnLeft.Name", "EMRUKAlignMode::LeftOnLeft" },
		{ "LeftOnLeft.ToolTip", "Align the left of the bounding boxes and center the rest" },
		{ "LeftOnRight.Comment", "/// Align the left to the right of the anchor bounding box and center the rest\n" },
		{ "LeftOnRight.Name", "EMRUKAlignMode::LeftOnRight" },
		{ "LeftOnRight.ToolTip", "Align the left to the right of the anchor bounding box and center the rest" },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
		{ "None.Comment", "/// Do not perform any alignment\n" },
		{ "None.Name", "EMRUKAlignMode::None" },
		{ "None.ToolTip", "Do not perform any alignment" },
		{ "RightOnLeft.Comment", "/// Align the right to the left of the anchor bounding box and center the rest\n" },
		{ "RightOnLeft.Name", "EMRUKAlignMode::RightOnLeft" },
		{ "RightOnLeft.ToolTip", "Align the right to the left of the anchor bounding box and center the rest" },
		{ "RightOnRight.Comment", "/// Align the right of the bounding boxes and center the rest\n" },
		{ "RightOnRight.Name", "EMRUKAlignMode::RightOnRight" },
		{ "RightOnRight.ToolTip", "Align the right of the bounding boxes and center the rest" },
		{ "TopOnBottom.Comment", "/// Align the bottom to the top of the anchor bounding box and center the rest\n" },
		{ "TopOnBottom.Name", "EMRUKAlignMode::TopOnBottom" },
		{ "TopOnBottom.ToolTip", "Align the bottom to the top of the anchor bounding box and center the rest" },
		{ "TopOnTop.Comment", "/// Align the top of the bounding boxes and center the rest\n" },
		{ "TopOnTop.Name", "EMRUKAlignMode::TopOnTop" },
		{ "TopOnTop.ToolTip", "Align the top of the bounding boxes and center the rest" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMRUKAlignMode::None", (int64)EMRUKAlignMode::None },
		{ "EMRUKAlignMode::Default", (int64)EMRUKAlignMode::Default },
		{ "EMRUKAlignMode::CenterOnCenter", (int64)EMRUKAlignMode::CenterOnCenter },
		{ "EMRUKAlignMode::BottomOnBottom", (int64)EMRUKAlignMode::BottomOnBottom },
		{ "EMRUKAlignMode::TopOnTop", (int64)EMRUKAlignMode::TopOnTop },
		{ "EMRUKAlignMode::LeftOnLeft", (int64)EMRUKAlignMode::LeftOnLeft },
		{ "EMRUKAlignMode::RightOnRight", (int64)EMRUKAlignMode::RightOnRight },
		{ "EMRUKAlignMode::FrontOnFront", (int64)EMRUKAlignMode::FrontOnFront },
		{ "EMRUKAlignMode::BackOnBack", (int64)EMRUKAlignMode::BackOnBack },
		{ "EMRUKAlignMode::BottomOnTop", (int64)EMRUKAlignMode::BottomOnTop },
		{ "EMRUKAlignMode::TopOnBottom", (int64)EMRUKAlignMode::TopOnBottom },
		{ "EMRUKAlignMode::LeftOnRight", (int64)EMRUKAlignMode::LeftOnRight },
		{ "EMRUKAlignMode::RightOnLeft", (int64)EMRUKAlignMode::RightOnLeft },
		{ "EMRUKAlignMode::FrontOnBack", (int64)EMRUKAlignMode::FrontOnBack },
		{ "EMRUKAlignMode::BackOnFront", (int64)EMRUKAlignMode::BackOnFront },
		{ "EMRUKAlignMode::Custom", (int64)EMRUKAlignMode::Custom },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MRUtilityKit_EMRUKAlignMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	"EMRUKAlignMode",
	"EMRUKAlignMode",
	Z_Construct_UEnum_MRUtilityKit_EMRUKAlignMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKAlignMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKAlignMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MRUtilityKit_EMRUKAlignMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKAlignMode()
{
	if (!Z_Registration_Info_UEnum_EMRUKAlignMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMRUKAlignMode.InnerSingleton, Z_Construct_UEnum_MRUtilityKit_EMRUKAlignMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMRUKAlignMode.InnerSingleton;
}
// End Enum EMRUKAlignMode

// Begin ScriptStruct FMRUKHit
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MRUKHit;
class UScriptStruct* FMRUKHit::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MRUKHit.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MRUKHit.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMRUKHit, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("MRUKHit"));
	}
	return Z_Registration_Info_UScriptStruct_MRUKHit.OuterSingleton;
}
template<> MRUTILITYKIT_API UScriptStruct* StaticStruct<FMRUKHit>()
{
	return FMRUKHit::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMRUKHit_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitPosition_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The position where the raycast hit.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The position where the raycast hit." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitNormal_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The normal of the surface that was hit.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The normal of the surface that was hit." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitDistance_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The distance between the origin of the ray to the hit position.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The distance between the origin of the ray to the hit position." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitPosition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitNormal;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HitDistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMRUKHit>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMRUKHit_Statics::NewProp_HitPosition = { "HitPosition", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKHit, HitPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitPosition_MetaData), NewProp_HitPosition_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMRUKHit_Statics::NewProp_HitNormal = { "HitNormal", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKHit, HitNormal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitNormal_MetaData), NewProp_HitNormal_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMRUKHit_Statics::NewProp_HitDistance = { "HitDistance", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKHit, HitDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitDistance_MetaData), NewProp_HitDistance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMRUKHit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKHit_Statics::NewProp_HitPosition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKHit_Statics::NewProp_HitNormal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKHit_Statics::NewProp_HitDistance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKHit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMRUKHit_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	&NewStructOps,
	"MRUKHit",
	Z_Construct_UScriptStruct_FMRUKHit_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKHit_Statics::PropPointers),
	sizeof(FMRUKHit),
	alignof(FMRUKHit),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKHit_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMRUKHit_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMRUKHit()
{
	if (!Z_Registration_Info_UScriptStruct_MRUKHit.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MRUKHit.InnerSingleton, Z_Construct_UScriptStruct_FMRUKHit_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MRUKHit.InnerSingleton;
}
// End ScriptStruct FMRUKHit

// Begin ScriptStruct FMRUKLabelFilter
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MRUKLabelFilter;
class UScriptStruct* FMRUKLabelFilter::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MRUKLabelFilter.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MRUKLabelFilter.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMRUKLabelFilter, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("MRUKLabelFilter"));
	}
	return Z_Registration_Info_UScriptStruct_MRUKLabelFilter.OuterSingleton;
}
template<> MRUTILITYKIT_API UScriptStruct* StaticStruct<FMRUKLabelFilter>()
{
	return FMRUKLabelFilter::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IncludedLabels_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * If included labels is not empty then the anchor must have at\n\x09 * least one of the labels in this list.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If included labels is not empty then the anchor must have at\nleast one of the labels in this list." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExcludedLabels_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Anchors with any of the labels in this exclusion list\n\x09 * will be ignored.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Anchors with any of the labels in this exclusion list\nwill be ignored." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_IncludedLabels_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_IncludedLabels;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ExcludedLabels_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ExcludedLabels;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMRUKLabelFilter>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::NewProp_IncludedLabels_Inner = { "IncludedLabels", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::NewProp_IncludedLabels = { "IncludedLabels", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKLabelFilter, IncludedLabels), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IncludedLabels_MetaData), NewProp_IncludedLabels_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::NewProp_ExcludedLabels_Inner = { "ExcludedLabels", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::NewProp_ExcludedLabels = { "ExcludedLabels", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKLabelFilter, ExcludedLabels), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExcludedLabels_MetaData), NewProp_ExcludedLabels_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::NewProp_IncludedLabels_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::NewProp_IncludedLabels,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::NewProp_ExcludedLabels_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::NewProp_ExcludedLabels,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	&NewStructOps,
	"MRUKLabelFilter",
	Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::PropPointers),
	sizeof(FMRUKLabelFilter),
	alignof(FMRUKLabelFilter),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMRUKLabelFilter()
{
	if (!Z_Registration_Info_UScriptStruct_MRUKLabelFilter.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MRUKLabelFilter.InnerSingleton, Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MRUKLabelFilter.InnerSingleton;
}
// End ScriptStruct FMRUKLabelFilter

// Begin ScriptStruct FMRUKPlaneUV
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MRUKPlaneUV;
class UScriptStruct* FMRUKPlaneUV::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MRUKPlaneUV.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MRUKPlaneUV.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMRUKPlaneUV, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("MRUKPlaneUV"));
	}
	return Z_Registration_Info_UScriptStruct_MRUKPlaneUV.OuterSingleton;
}
template<> MRUTILITYKIT_API UScriptStruct* StaticStruct<FMRUKPlaneUV>()
{
	return FMRUKPlaneUV::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Offset_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Offset applied to the UV texture coordinates.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Offset applied to the UV texture coordinates." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Scale applied to the UV texture coordinates.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scale applied to the UV texture coordinates." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Offset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMRUKPlaneUV>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKPlaneUV, Offset), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Offset_MetaData), NewProp_Offset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKPlaneUV, Scale), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scale_MetaData), NewProp_Scale_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics::NewProp_Offset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics::NewProp_Scale,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	&NewStructOps,
	"MRUKPlaneUV",
	Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics::PropPointers),
	sizeof(FMRUKPlaneUV),
	alignof(FMRUKPlaneUV),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMRUKPlaneUV()
{
	if (!Z_Registration_Info_UScriptStruct_MRUKPlaneUV.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MRUKPlaneUV.InnerSingleton, Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MRUKPlaneUV.InnerSingleton;
}
// End ScriptStruct FMRUKPlaneUV

// Begin ScriptStruct FMRUKTexCoordModes
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MRUKTexCoordModes;
class UScriptStruct* FMRUKTexCoordModes::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MRUKTexCoordModes.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MRUKTexCoordModes.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMRUKTexCoordModes, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("MRUKTexCoordModes"));
	}
	return Z_Registration_Info_UScriptStruct_MRUKTexCoordModes.OuterSingleton;
}
template<> MRUTILITYKIT_API UScriptStruct* StaticStruct<FMRUKTexCoordModes>()
{
	return FMRUKTexCoordModes::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_U_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Texture Coordinate mode for the U direction.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Texture Coordinate mode for the U direction." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_V_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Texture Coordinate mode for the V direction.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Texture Coordinate mode for the V direction." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_U_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_U;
	static const UECodeGen_Private::FBytePropertyParams NewProp_V_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_V;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMRUKTexCoordModes>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::NewProp_U_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::NewProp_U = { "U", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKTexCoordModes, U), Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeU, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_U_MetaData), NewProp_U_MetaData) }; // 678678992
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::NewProp_V_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::NewProp_V = { "V", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKTexCoordModes, V), Z_Construct_UEnum_MRUtilityKit_EMRUKCoordModeV, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_V_MetaData), NewProp_V_MetaData) }; // 2918986210
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::NewProp_U_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::NewProp_U,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::NewProp_V_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::NewProp_V,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	&NewStructOps,
	"MRUKTexCoordModes",
	Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::PropPointers),
	sizeof(FMRUKTexCoordModes),
	alignof(FMRUKTexCoordModes),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMRUKTexCoordModes()
{
	if (!Z_Registration_Info_UScriptStruct_MRUKTexCoordModes.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MRUKTexCoordModes.InnerSingleton, Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MRUKTexCoordModes.InnerSingleton;
}
// End ScriptStruct FMRUKTexCoordModes

// Begin ScriptStruct FMRUKSpawnActor
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MRUKSpawnActor;
class UScriptStruct* FMRUKSpawnActor::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MRUKSpawnActor.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MRUKSpawnActor.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMRUKSpawnActor, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("MRUKSpawnActor"));
	}
	return Z_Registration_Info_UScriptStruct_MRUKSpawnActor.OuterSingleton;
}
template<> MRUTILITYKIT_API UScriptStruct* StaticStruct<FMRUKSpawnActor>()
{
	return FMRUKSpawnActor::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actor_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The class of actor to spawn.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The class of actor to spawn." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MatchAspectRatio_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * When match aspect ratio is enabled then the actor will be rotated\n\x09 * to try and match the aspect ratio of the volume as closely as possible.\n\x09 * This is most useful for long and thin volumes, keep this disabled for\n\x09 * objects with an aspect ratio close to 1:1. Only applies to volumes.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When match aspect ratio is enabled then the actor will be rotated\nto try and match the aspect ratio of the volume as closely as possible.\nThis is most useful for long and thin volumes, keep this disabled for\nobjects with an aspect ratio close to 1:1. Only applies to volumes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CalculateFacingDirection_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * When calculate facing direction is enabled the actor will be rotated to\n\x09 * face away from the closest wall. If match aspect ratio is also enabled\n\x09 * then that will take precedence and it will be constrained to a choice\n\x09 * between 2 directions only. Only applies to volumes.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When calculate facing direction is enabled the actor will be rotated to\nface away from the closest wall. If match aspect ratio is also enabled\nthen that will take precedence and it will be constrained to a choice\nbetween 2 directions only. Only applies to volumes." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScalingMode_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set what scaling mode to apply to the actor. By default the actor will\n\x09 * be stretched to fit the size of the plane/volume. But in some cases\n\x09 * this may not be desirable and can be customized here.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set what scaling mode to apply to the actor. By default the actor will\nbe stretched to fit the size of the plane/volume. But in some cases\nthis may not be desirable and can be customized here." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlignMode_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set what alignment mode to apply to the actor. By default the actor will\n\x09 * be aligned that its bounding box matches the one from the anchor.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set what alignment mode to apply to the actor. By default the actor will\nbe aligned that its bounding box matches the one from the anchor." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_Actor;
	static void NewProp_MatchAspectRatio_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_MatchAspectRatio;
	static void NewProp_CalculateFacingDirection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_CalculateFacingDirection;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ScalingMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ScalingMode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AlignMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AlignMode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMRUKSpawnActor>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKSpawnActor, Actor), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actor_MetaData), NewProp_Actor_MetaData) };
void Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_MatchAspectRatio_SetBit(void* Obj)
{
	((FMRUKSpawnActor*)Obj)->MatchAspectRatio = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_MatchAspectRatio = { "MatchAspectRatio", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FMRUKSpawnActor), &Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_MatchAspectRatio_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MatchAspectRatio_MetaData), NewProp_MatchAspectRatio_MetaData) };
void Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_CalculateFacingDirection_SetBit(void* Obj)
{
	((FMRUKSpawnActor*)Obj)->CalculateFacingDirection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_CalculateFacingDirection = { "CalculateFacingDirection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FMRUKSpawnActor), &Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_CalculateFacingDirection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CalculateFacingDirection_MetaData), NewProp_CalculateFacingDirection_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_ScalingMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_ScalingMode = { "ScalingMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKSpawnActor, ScalingMode), Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerScalingMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScalingMode_MetaData), NewProp_ScalingMode_MetaData) }; // 3830693870
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_AlignMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_AlignMode = { "AlignMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKSpawnActor, AlignMode), Z_Construct_UEnum_MRUtilityKit_EMRUKAlignMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlignMode_MetaData), NewProp_AlignMode_MetaData) }; // 3594544252
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_MatchAspectRatio,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_CalculateFacingDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_ScalingMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_ScalingMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_AlignMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewProp_AlignMode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	&NewStructOps,
	"MRUKSpawnActor",
	Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::PropPointers),
	sizeof(FMRUKSpawnActor),
	alignof(FMRUKSpawnActor),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMRUKSpawnActor()
{
	if (!Z_Registration_Info_UScriptStruct_MRUKSpawnActor.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MRUKSpawnActor.InnerSingleton, Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MRUKSpawnActor.InnerSingleton;
}
// End ScriptStruct FMRUKSpawnActor

// Begin Enum EMRUKFallbackToProceduralOverwrite
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMRUKFallbackToProceduralOverwrite;
static UEnum* EMRUKFallbackToProceduralOverwrite_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMRUKFallbackToProceduralOverwrite.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMRUKFallbackToProceduralOverwrite.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MRUtilityKit_EMRUKFallbackToProceduralOverwrite, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("EMRUKFallbackToProceduralOverwrite"));
	}
	return Z_Registration_Info_UEnum_EMRUKFallbackToProceduralOverwrite.OuterSingleton;
}
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKFallbackToProceduralOverwrite>()
{
	return EMRUKFallbackToProceduralOverwrite_StaticEnum();
}
struct Z_Construct_UEnum_MRUtilityKit_EMRUKFallbackToProceduralOverwrite_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Default.Comment", "/// Don't override the fallback to procedural standard behaviour.\n" },
		{ "Default.Name", "EMRUKFallbackToProceduralOverwrite::Default" },
		{ "Default.ToolTip", "Don't override the fallback to procedural standard behaviour." },
		{ "Fallback.Comment", "/// Fallback to a procedural mesh.\n" },
		{ "Fallback.Name", "EMRUKFallbackToProceduralOverwrite::Fallback" },
		{ "Fallback.ToolTip", "Fallback to a procedural mesh." },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
		{ "NoFallback.Comment", "/// Don't fallback to a procedural mesh.\n" },
		{ "NoFallback.Name", "EMRUKFallbackToProceduralOverwrite::NoFallback" },
		{ "NoFallback.ToolTip", "Don't fallback to a procedural mesh." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMRUKFallbackToProceduralOverwrite::Default", (int64)EMRUKFallbackToProceduralOverwrite::Default },
		{ "EMRUKFallbackToProceduralOverwrite::Fallback", (int64)EMRUKFallbackToProceduralOverwrite::Fallback },
		{ "EMRUKFallbackToProceduralOverwrite::NoFallback", (int64)EMRUKFallbackToProceduralOverwrite::NoFallback },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MRUtilityKit_EMRUKFallbackToProceduralOverwrite_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	"EMRUKFallbackToProceduralOverwrite",
	"EMRUKFallbackToProceduralOverwrite",
	Z_Construct_UEnum_MRUtilityKit_EMRUKFallbackToProceduralOverwrite_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKFallbackToProceduralOverwrite_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKFallbackToProceduralOverwrite_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MRUtilityKit_EMRUKFallbackToProceduralOverwrite_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKFallbackToProceduralOverwrite()
{
	if (!Z_Registration_Info_UEnum_EMRUKFallbackToProceduralOverwrite.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMRUKFallbackToProceduralOverwrite.InnerSingleton, Z_Construct_UEnum_MRUtilityKit_EMRUKFallbackToProceduralOverwrite_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMRUKFallbackToProceduralOverwrite.InnerSingleton;
}
// End Enum EMRUKFallbackToProceduralOverwrite

// Begin ScriptStruct FMRUKSpawnGroup
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MRUKSpawnGroup;
class UScriptStruct* FMRUKSpawnGroup::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MRUKSpawnGroup.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MRUKSpawnGroup.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMRUKSpawnGroup, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("MRUKSpawnGroup"));
	}
	return Z_Registration_Info_UScriptStruct_MRUKSpawnGroup.OuterSingleton;
}
template<> MRUTILITYKIT_API UScriptStruct* StaticStruct<FMRUKSpawnGroup>()
{
	return FMRUKSpawnGroup::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actors_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * List of actors to choose from, multiple actors can be specified and\n\x09 * the selection criteria will be determined by the SelectionMode option.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List of actors to choose from, multiple actors can be specified and\nthe selection criteria will be determined by the SelectionMode option." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectionMode_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the selection mode when multiple different actors are specified.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the selection mode when multiple different actors are specified." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FallbackToProcedural_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Control if there should happen a fallback to spawning a procedural mesh\n\x09 * in case no actor class has been specified for this label. The global\n\x09 * fallback behaviour can be specified in the AMRUKAnchorActorSpawner.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Control if there should happen a fallback to spawning a procedural mesh\nin case no actor class has been specified for this label. The global\nfallback behaviour can be specified in the AMRUKAnchorActorSpawner." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Actors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Actors;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SelectionMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SelectionMode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_FallbackToProcedural_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_FallbackToProcedural;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMRUKSpawnGroup>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::NewProp_Actors_Inner = { "Actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMRUKSpawnActor, METADATA_PARAMS(0, nullptr) }; // 1401691750
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::NewProp_Actors = { "Actors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKSpawnGroup, Actors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actors_MetaData), NewProp_Actors_MetaData) }; // 1401691750
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::NewProp_SelectionMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::NewProp_SelectionMode = { "SelectionMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKSpawnGroup, SelectionMode), Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerSelectionMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectionMode_MetaData), NewProp_SelectionMode_MetaData) }; // 3335168812
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::NewProp_FallbackToProcedural_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::NewProp_FallbackToProcedural = { "FallbackToProcedural", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKSpawnGroup, FallbackToProcedural), Z_Construct_UEnum_MRUtilityKit_EMRUKFallbackToProceduralOverwrite, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FallbackToProcedural_MetaData), NewProp_FallbackToProcedural_MetaData) }; // 2581155954
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::NewProp_Actors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::NewProp_Actors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::NewProp_SelectionMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::NewProp_SelectionMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::NewProp_FallbackToProcedural_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::NewProp_FallbackToProcedural,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	&NewStructOps,
	"MRUKSpawnGroup",
	Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::PropPointers),
	sizeof(FMRUKSpawnGroup),
	alignof(FMRUKSpawnGroup),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMRUKSpawnGroup()
{
	if (!Z_Registration_Info_UScriptStruct_MRUKSpawnGroup.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MRUKSpawnGroup.InnerSingleton, Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MRUKSpawnGroup.InnerSingleton;
}
// End ScriptStruct FMRUKSpawnGroup

// Begin Class UMRUKSettings
void UMRUKSettings::StaticRegisterNativesUMRUKSettings()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMRUKSettings);
UClass* Z_Construct_UClass_UMRUKSettings_NoRegister()
{
	return UMRUKSettings::StaticClass();
}
struct Z_Construct_UClass_UMRUKSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Implements the settings for the MRUtilityKit plugin.\n */" },
#endif
		{ "IncludePath", "MRUtilityKit.h" },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Implements the settings for the MRUtilityKit plugin." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnableWorldLock_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * When world locking is enabled the position of the VR Pawn will be adjusted each frame to ensure\n\x09 * the room anchors are where they should be relative to the camera position. This is necessary to\n\x09 * ensure the position of the virtual objects in the world do not get out of sync with the real world.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When world locking is enabled the position of the VR Pawn will be adjusted each frame to ensure\nthe room anchors are where they should be relative to the camera position. This is necessary to\nensure the position of the virtual objects in the world do not get out of sync with the real world." },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_EnableWorldLock_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_EnableWorldLock;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMRUKSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UMRUKSettings_Statics::NewProp_EnableWorldLock_SetBit(void* Obj)
{
	((UMRUKSettings*)Obj)->EnableWorldLock = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMRUKSettings_Statics::NewProp_EnableWorldLock = { "EnableWorldLock", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UMRUKSettings), &Z_Construct_UClass_UMRUKSettings_Statics::NewProp_EnableWorldLock_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnableWorldLock_MetaData), NewProp_EnableWorldLock_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMRUKSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMRUKSettings_Statics::NewProp_EnableWorldLock,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMRUKSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMRUKSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMRUKSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMRUKSettings_Statics::ClassParams = {
	&UMRUKSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UMRUKSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UMRUKSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMRUKSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UMRUKSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMRUKSettings()
{
	if (!Z_Registration_Info_UClass_UMRUKSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMRUKSettings.OuterSingleton, Z_Construct_UClass_UMRUKSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMRUKSettings.OuterSingleton;
}
template<> MRUTILITYKIT_API UClass* StaticClass<UMRUKSettings>()
{
	return UMRUKSettings::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMRUKSettings);
UMRUKSettings::~UMRUKSettings() {}
// End Class UMRUKSettings

// Begin Enum EMRUKSpawnMode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMRUKSpawnMode;
static UEnum* EMRUKSpawnMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMRUKSpawnMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMRUKSpawnMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("EMRUKSpawnMode"));
	}
	return Z_Registration_Info_UEnum_EMRUKSpawnMode.OuterSingleton;
}
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKSpawnMode>()
{
	return EMRUKSpawnMode_StaticEnum();
}
struct Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AllRooms.Comment", "/// Spawn in every room and keep on spawning whenever a new room was discovered.\n" },
		{ "AllRooms.Name", "EMRUKSpawnMode::AllRooms" },
		{ "AllRooms.ToolTip", "Spawn in every room and keep on spawning whenever a new room was discovered." },
		{ "BlueprintType", "true" },
		{ "CurrentRoomOnly.Comment", "/// Will only take the current room into account. This enables legacy single room behaviour. Keep in mind that if your\n/// experience loads multiple rooms and you use that mode the behaviour might be undefined.\n" },
		{ "CurrentRoomOnly.Name", "EMRUKSpawnMode::CurrentRoomOnly" },
		{ "CurrentRoomOnly.ToolTip", "Will only take the current room into account. This enables legacy single room behaviour. Keep in mind that if your\nexperience loads multiple rooms and you use that mode the behaviour might be undefined." },
		{ "ModuleRelativePath", "Public/MRUtilityKit.h" },
		{ "None.Comment", "/// Do not spawn anything on loading a scene or rooms.\n" },
		{ "None.Name", "EMRUKSpawnMode::None" },
		{ "None.ToolTip", "Do not spawn anything on loading a scene or rooms." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMRUKSpawnMode::None", (int64)EMRUKSpawnMode::None },
		{ "EMRUKSpawnMode::CurrentRoomOnly", (int64)EMRUKSpawnMode::CurrentRoomOnly },
		{ "EMRUKSpawnMode::AllRooms", (int64)EMRUKSpawnMode::AllRooms },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	"EMRUKSpawnMode",
	"EMRUKSpawnMode",
	Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode()
{
	if (!Z_Registration_Info_UEnum_EMRUKSpawnMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMRUKSpawnMode.InnerSingleton, Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMRUKSpawnMode.InnerSingleton;
}
// End Enum EMRUKSpawnMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKit_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EMRUKInitStatus_StaticEnum, TEXT("EMRUKInitStatus"), &Z_Registration_Info_UEnum_EMRUKInitStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2351161875U) },
		{ EMRUKCoordModeU_StaticEnum, TEXT("EMRUKCoordModeU"), &Z_Registration_Info_UEnum_EMRUKCoordModeU, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 678678992U) },
		{ EMRUKCoordModeV_StaticEnum, TEXT("EMRUKCoordModeV"), &Z_Registration_Info_UEnum_EMRUKCoordModeV, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2918986210U) },
		{ EMRUKSpawnerSelectionMode_StaticEnum, TEXT("EMRUKSpawnerSelectionMode"), &Z_Registration_Info_UEnum_EMRUKSpawnerSelectionMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3335168812U) },
		{ EMRUKSpawnerScalingMode_StaticEnum, TEXT("EMRUKSpawnerScalingMode"), &Z_Registration_Info_UEnum_EMRUKSpawnerScalingMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3830693870U) },
		{ EMRUKAlignMode_StaticEnum, TEXT("EMRUKAlignMode"), &Z_Registration_Info_UEnum_EMRUKAlignMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3594544252U) },
		{ EMRUKFallbackToProceduralOverwrite_StaticEnum, TEXT("EMRUKFallbackToProceduralOverwrite"), &Z_Registration_Info_UEnum_EMRUKFallbackToProceduralOverwrite, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2581155954U) },
		{ EMRUKSpawnMode_StaticEnum, TEXT("EMRUKSpawnMode"), &Z_Registration_Info_UEnum_EMRUKSpawnMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3624342257U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FMRUKHit::StaticStruct, Z_Construct_UScriptStruct_FMRUKHit_Statics::NewStructOps, TEXT("MRUKHit"), &Z_Registration_Info_UScriptStruct_MRUKHit, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMRUKHit), 928023772U) },
		{ FMRUKLabelFilter::StaticStruct, Z_Construct_UScriptStruct_FMRUKLabelFilter_Statics::NewStructOps, TEXT("MRUKLabelFilter"), &Z_Registration_Info_UScriptStruct_MRUKLabelFilter, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMRUKLabelFilter), 2546402197U) },
		{ FMRUKPlaneUV::StaticStruct, Z_Construct_UScriptStruct_FMRUKPlaneUV_Statics::NewStructOps, TEXT("MRUKPlaneUV"), &Z_Registration_Info_UScriptStruct_MRUKPlaneUV, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMRUKPlaneUV), 750307190U) },
		{ FMRUKTexCoordModes::StaticStruct, Z_Construct_UScriptStruct_FMRUKTexCoordModes_Statics::NewStructOps, TEXT("MRUKTexCoordModes"), &Z_Registration_Info_UScriptStruct_MRUKTexCoordModes, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMRUKTexCoordModes), 3108976041U) },
		{ FMRUKSpawnActor::StaticStruct, Z_Construct_UScriptStruct_FMRUKSpawnActor_Statics::NewStructOps, TEXT("MRUKSpawnActor"), &Z_Registration_Info_UScriptStruct_MRUKSpawnActor, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMRUKSpawnActor), 1401691750U) },
		{ FMRUKSpawnGroup::StaticStruct, Z_Construct_UScriptStruct_FMRUKSpawnGroup_Statics::NewStructOps, TEXT("MRUKSpawnGroup"), &Z_Registration_Info_UScriptStruct_MRUKSpawnGroup, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMRUKSpawnGroup), 1153535095U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMRUKSettings, UMRUKSettings::StaticClass, TEXT("UMRUKSettings"), &Z_Registration_Info_UClass_UMRUKSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMRUKSettings), 4265741352U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKit_h_3075800369(TEXT("/Script/MRUtilityKit"),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKit_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKit_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKit_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKit_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKit_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKit_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
