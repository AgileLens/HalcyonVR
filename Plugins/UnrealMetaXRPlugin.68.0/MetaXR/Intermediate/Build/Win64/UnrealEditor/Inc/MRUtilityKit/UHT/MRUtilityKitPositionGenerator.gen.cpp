// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MRUtilityKit/Public/MRUtilityKitPositionGenerator.h"
#include "MRUtilityKit/Public/MRUtilityKit.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMRUtilityKitPositionGenerator() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKRoom_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUtilityKitPositionGenerator();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUtilityKitPositionGenerator_NoRegister();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKRoomFilter();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnLocation();
MRUTILITYKIT_API UScriptStruct* Z_Construct_UScriptStruct_FMRUKLabelFilter();
MRUTILITYKIT_API UScriptStruct* Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings();
UPackage* Z_Construct_UPackage__Script_MRUtilityKit();
// End Cross Module References

// Begin ScriptStruct FMRUKRandomSpawnSettings
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MRUKRandomSpawnSettings;
class UScriptStruct* FMRUKRandomSpawnSettings::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MRUKRandomSpawnSettings.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MRUKRandomSpawnSettings.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("MRUKRandomSpawnSettings"));
	}
	return Z_Registration_Info_UScriptStruct_MRUKRandomSpawnSettings.OuterSingleton;
}
template<> MRUTILITYKIT_API UScriptStruct* StaticStruct<FMRUKRandomSpawnSettings>()
{
	return FMRUKRandomSpawnSettings::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomFilter_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * When the scene data is loaded, this controls what room(s) the position generator will be used in.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When the scene data is loaded, this controls what room(s) the position generator will be used in." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorInstance_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * When an actor instance is reference here, this actor will be moved around.\n\x09 * If you'd need to spawn new actors, use ActorClass.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When an actor instance is reference here, this actor will be moved around.\nIf you'd need to spawn new actors, use ActorClass." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorClass_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Reference the specific actor class for spawning.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference the specific actor class for spawning." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnAmount_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * How many instances to spawn at the random generated position per room.\n\x09 * Note: If using an ActorInstance this property is ignored\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How many instances to spawn at the random generated position per room.\nNote: If using an ActorInstance this property is ignored" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxIterations_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Maximum number of times to attempt spawning/moving an object before giving up.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum number of times to attempt spawning/moving an object before giving up." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnLocations_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The type of surface by which to limit the generation.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The type of surface by which to limit the generation." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Labels_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The labels to include or exclude.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The labels to include or exclude." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CheckOverlaps_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * If enabled then the spawn position will be checked to make sure there is no overlap with physics colliders including themselves.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If enabled then the spawn position will be checked to make sure there is no overlap with physics colliders including themselves." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverrideBounds_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Required free space for the object.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Required free space for the object." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionChannel_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The CollisionChannel to use.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The CollisionChannel to use." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SurfaceClearanceDistance_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The clearance distance required in front of the surface in order for it to be considered a valid spawn position.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The clearance distance required in front of the surface in order for it to be considered a valid spawn position." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_RoomFilter_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_RoomFilter;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActorInstance;
	static const UECodeGen_Private::FClassPropertyParams NewProp_ActorClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SpawnAmount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxIterations;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SpawnLocations_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SpawnLocations;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Labels;
	static void NewProp_CheckOverlaps_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_CheckOverlaps;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OverrideBounds;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CollisionChannel;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SurfaceClearanceDistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMRUKRandomSpawnSettings>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_RoomFilter_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_RoomFilter = { "RoomFilter", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKRandomSpawnSettings, RoomFilter), Z_Construct_UEnum_MRUtilityKit_EMRUKRoomFilter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomFilter_MetaData), NewProp_RoomFilter_MetaData) }; // 1183284872
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_ActorInstance = { "ActorInstance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKRandomSpawnSettings, ActorInstance), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorInstance_MetaData), NewProp_ActorInstance_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_ActorClass = { "ActorClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKRandomSpawnSettings, ActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorClass_MetaData), NewProp_ActorClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_SpawnAmount = { "SpawnAmount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKRandomSpawnSettings, SpawnAmount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnAmount_MetaData), NewProp_SpawnAmount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_MaxIterations = { "MaxIterations", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKRandomSpawnSettings, MaxIterations), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxIterations_MetaData), NewProp_MaxIterations_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_SpawnLocations_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_SpawnLocations = { "SpawnLocations", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKRandomSpawnSettings, SpawnLocations), Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnLocation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnLocations_MetaData), NewProp_SpawnLocations_MetaData) }; // 1396309959
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_Labels = { "Labels", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKRandomSpawnSettings, Labels), Z_Construct_UScriptStruct_FMRUKLabelFilter, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Labels_MetaData), NewProp_Labels_MetaData) }; // 2546402197
void Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_CheckOverlaps_SetBit(void* Obj)
{
	((FMRUKRandomSpawnSettings*)Obj)->CheckOverlaps = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_CheckOverlaps = { "CheckOverlaps", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FMRUKRandomSpawnSettings), &Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_CheckOverlaps_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CheckOverlaps_MetaData), NewProp_CheckOverlaps_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_OverrideBounds = { "OverrideBounds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKRandomSpawnSettings, OverrideBounds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverrideBounds_MetaData), NewProp_OverrideBounds_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_CollisionChannel = { "CollisionChannel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKRandomSpawnSettings, CollisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionChannel_MetaData), NewProp_CollisionChannel_MetaData) }; // 756624936
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_SurfaceClearanceDistance = { "SurfaceClearanceDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMRUKRandomSpawnSettings, SurfaceClearanceDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SurfaceClearanceDistance_MetaData), NewProp_SurfaceClearanceDistance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_RoomFilter_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_RoomFilter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_ActorInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_ActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_SpawnAmount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_MaxIterations,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_SpawnLocations_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_SpawnLocations,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_Labels,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_CheckOverlaps,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_OverrideBounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_CollisionChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewProp_SurfaceClearanceDistance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	&NewStructOps,
	"MRUKRandomSpawnSettings",
	Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::PropPointers),
	sizeof(FMRUKRandomSpawnSettings),
	alignof(FMRUKRandomSpawnSettings),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings()
{
	if (!Z_Registration_Info_UScriptStruct_MRUKRandomSpawnSettings.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MRUKRandomSpawnSettings.InnerSingleton, Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MRUKRandomSpawnSettings.InnerSingleton;
}
// End ScriptStruct FMRUKRandomSpawnSettings

// Begin Class AMRUtilityKitPositionGenerator Function GenerateRandomPositionsOnSurface
struct Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics
{
	struct MRUtilityKitPositionGenerator_eventGenerateRandomPositionsOnSurface_Parms
	{
		TArray<FTransform> OutTransforms;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Generates a set of random positions on the surface of a given spawn location, while ensuring that the generated positions\n\x09 * are at least `MinDistanceToEdge` away from any edges and follow the other settings specified in `SpawnSettings`.\n\x09 * @param OutTransforms An array of transforms representing the generated positions.\n\x09 * @return A boolean value indicating whether valid positions were found. If no valid positions could be found, `OutTransforms` will be empty.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Generates a set of random positions on the surface of a given spawn location, while ensuring that the generated positions\nare at least `MinDistanceToEdge` away from any edges and follow the other settings specified in `SpawnSettings`.\n@param OutTransforms An array of transforms representing the generated positions.\n@return A boolean value indicating whether valid positions were found. If no valid positions could be found, `OutTransforms` will be empty." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutTransforms_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutTransforms;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::NewProp_OutTransforms_Inner = { "OutTransforms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::NewProp_OutTransforms = { "OutTransforms", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUtilityKitPositionGenerator_eventGenerateRandomPositionsOnSurface_Parms, OutTransforms), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MRUtilityKitPositionGenerator_eventGenerateRandomPositionsOnSurface_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUtilityKitPositionGenerator_eventGenerateRandomPositionsOnSurface_Parms), &Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::NewProp_OutTransforms_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::NewProp_OutTransforms,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUtilityKitPositionGenerator, nullptr, "GenerateRandomPositionsOnSurface", nullptr, nullptr, Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::MRUtilityKitPositionGenerator_eventGenerateRandomPositionsOnSurface_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::MRUtilityKitPositionGenerator_eventGenerateRandomPositionsOnSurface_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUtilityKitPositionGenerator::execGenerateRandomPositionsOnSurface)
{
	P_GET_TARRAY_REF(FTransform,Z_Param_Out_OutTransforms);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GenerateRandomPositionsOnSurface(Z_Param_Out_OutTransforms);
	P_NATIVE_END;
}
// End Class AMRUtilityKitPositionGenerator Function GenerateRandomPositionsOnSurface

// Begin Class AMRUtilityKitPositionGenerator Function GenerateRandomPositionsOnSurfaceInRoom
struct Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics
{
	struct MRUtilityKitPositionGenerator_eventGenerateRandomPositionsOnSurfaceInRoom_Parms
	{
		AMRUKRoom* Room;
		TArray<FTransform> OutTransforms;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Generates a set of random positions on the surface of a given spawn location, while ensuring that the generated positions\n\x09 * are at least `MinDistanceToEdge` away from any edges and follow the other settings specified in `SpawnSettings` in the\n\x09 * give room.\n\x09 * @param Room The room where the positions should be generated in.\n\x09 * @param OutTransforms An array of transforms representing the generated positions.\n\x09 * @return A boolean value indicating whether valid positions were found. If no valid positions could be found, `OutTransforms` will be empty.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Generates a set of random positions on the surface of a given spawn location, while ensuring that the generated positions\nare at least `MinDistanceToEdge` away from any edges and follow the other settings specified in `SpawnSettings` in the\ngive room.\n@param Room The room where the positions should be generated in.\n@param OutTransforms An array of transforms representing the generated positions.\n@return A boolean value indicating whether valid positions were found. If no valid positions could be found, `OutTransforms` will be empty." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutTransforms_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutTransforms;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUtilityKitPositionGenerator_eventGenerateRandomPositionsOnSurfaceInRoom_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::NewProp_OutTransforms_Inner = { "OutTransforms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::NewProp_OutTransforms = { "OutTransforms", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUtilityKitPositionGenerator_eventGenerateRandomPositionsOnSurfaceInRoom_Parms, OutTransforms), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MRUtilityKitPositionGenerator_eventGenerateRandomPositionsOnSurfaceInRoom_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUtilityKitPositionGenerator_eventGenerateRandomPositionsOnSurfaceInRoom_Parms), &Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::NewProp_Room,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::NewProp_OutTransforms_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::NewProp_OutTransforms,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUtilityKitPositionGenerator, nullptr, "GenerateRandomPositionsOnSurfaceInRoom", nullptr, nullptr, Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::MRUtilityKitPositionGenerator_eventGenerateRandomPositionsOnSurfaceInRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::MRUtilityKitPositionGenerator_eventGenerateRandomPositionsOnSurfaceInRoom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUtilityKitPositionGenerator::execGenerateRandomPositionsOnSurfaceInRoom)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_GET_TARRAY_REF(FTransform,Z_Param_Out_OutTransforms);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GenerateRandomPositionsOnSurfaceInRoom(Z_Param_Room,Z_Param_Out_OutTransforms);
	P_NATIVE_END;
}
// End Class AMRUtilityKitPositionGenerator Function GenerateRandomPositionsOnSurfaceInRoom

// Begin Class AMRUtilityKitPositionGenerator Function SceneLoaded
struct Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics
{
	struct MRUtilityKitPositionGenerator_eventSceneLoaded_Parms
	{
		bool Success;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
	};
#endif // WITH_METADATA
	static void NewProp_Success_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Success;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics::NewProp_Success_SetBit(void* Obj)
{
	((MRUtilityKitPositionGenerator_eventSceneLoaded_Parms*)Obj)->Success = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics::NewProp_Success = { "Success", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUtilityKitPositionGenerator_eventSceneLoaded_Parms), &Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics::NewProp_Success_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics::NewProp_Success,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUtilityKitPositionGenerator, nullptr, "SceneLoaded", nullptr, nullptr, Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics::MRUtilityKitPositionGenerator_eventSceneLoaded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics::MRUtilityKitPositionGenerator_eventSceneLoaded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUtilityKitPositionGenerator::execSceneLoaded)
{
	P_GET_UBOOL(Z_Param_Success);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SceneLoaded(Z_Param_Success);
	P_NATIVE_END;
}
// End Class AMRUtilityKitPositionGenerator Function SceneLoaded

// Begin Class AMRUtilityKitPositionGenerator
void AMRUtilityKitPositionGenerator::StaticRegisterNativesAMRUtilityKitPositionGenerator()
{
	UClass* Class = AMRUtilityKitPositionGenerator::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GenerateRandomPositionsOnSurface", &AMRUtilityKitPositionGenerator::execGenerateRandomPositionsOnSurface },
		{ "GenerateRandomPositionsOnSurfaceInRoom", &AMRUtilityKitPositionGenerator::execGenerateRandomPositionsOnSurfaceInRoom },
		{ "SceneLoaded", &AMRUtilityKitPositionGenerator::execSceneLoaded },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMRUtilityKitPositionGenerator);
UClass* Z_Construct_UClass_AMRUtilityKitPositionGenerator_NoRegister()
{
	return AMRUtilityKitPositionGenerator::StaticClass();
}
struct Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MRUtilityKitPositionGenerator.h" },
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RunOnStart_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Whether GenerateRandomPositionsOnSurface() should be called automatically after the mixed reality utility kit has been initialized\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether GenerateRandomPositionsOnSurface() should be called automatically after the mixed reality utility kit has been initialized" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomSpawnSettings_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Settings that should be used when generating random positions.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitPositionGenerator.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Settings that should be used when generating random positions." },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_RunOnStart_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_RunOnStart;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomSpawnSettings;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurface, "GenerateRandomPositionsOnSurface" }, // 3380534613
		{ &Z_Construct_UFunction_AMRUtilityKitPositionGenerator_GenerateRandomPositionsOnSurfaceInRoom, "GenerateRandomPositionsOnSurfaceInRoom" }, // 2467514666
		{ &Z_Construct_UFunction_AMRUtilityKitPositionGenerator_SceneLoaded, "SceneLoaded" }, // 3778029353
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMRUtilityKitPositionGenerator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::NewProp_RunOnStart_SetBit(void* Obj)
{
	((AMRUtilityKitPositionGenerator*)Obj)->RunOnStart = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::NewProp_RunOnStart = { "RunOnStart", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMRUtilityKitPositionGenerator), &Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::NewProp_RunOnStart_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RunOnStart_MetaData), NewProp_RunOnStart_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::NewProp_RandomSpawnSettings = { "RandomSpawnSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUtilityKitPositionGenerator, RandomSpawnSettings), Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomSpawnSettings_MetaData), NewProp_RandomSpawnSettings_MetaData) }; // 746160023
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::NewProp_RunOnStart,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::NewProp_RandomSpawnSettings,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::ClassParams = {
	&AMRUtilityKitPositionGenerator::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::Class_MetaDataParams), Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMRUtilityKitPositionGenerator()
{
	if (!Z_Registration_Info_UClass_AMRUtilityKitPositionGenerator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMRUtilityKitPositionGenerator.OuterSingleton, Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMRUtilityKitPositionGenerator.OuterSingleton;
}
template<> MRUTILITYKIT_API UClass* StaticClass<AMRUtilityKitPositionGenerator>()
{
	return AMRUtilityKitPositionGenerator::StaticClass();
}
AMRUtilityKitPositionGenerator::AMRUtilityKitPositionGenerator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMRUtilityKitPositionGenerator);
AMRUtilityKitPositionGenerator::~AMRUtilityKitPositionGenerator() {}
// End Class AMRUtilityKitPositionGenerator

// Begin Registration
struct Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FMRUKRandomSpawnSettings::StaticStruct, Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics::NewStructOps, TEXT("MRUKRandomSpawnSettings"), &Z_Registration_Info_UScriptStruct_MRUKRandomSpawnSettings, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMRUKRandomSpawnSettings), 746160023U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMRUtilityKitPositionGenerator, AMRUtilityKitPositionGenerator::StaticClass, TEXT("AMRUtilityKitPositionGenerator"), &Z_Registration_Info_UClass_AMRUtilityKitPositionGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMRUtilityKitPositionGenerator), 2045255531U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_1236472539(TEXT("/Script/MRUtilityKit"),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
