// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MRUtilityKit/Public/MRUtilityKitGuardianSpawner.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMRUtilityKitGuardianSpawner() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstance_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKGuardianSpawner();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKGuardianSpawner_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKRoom_NoRegister();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode();
UPackage* Z_Construct_UPackage__Script_MRUtilityKit();
// End Cross Module References

// Begin Class AMRUKGuardianSpawner Function DestroyGuardians
struct Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians_Statics
{
	struct MRUKGuardianSpawner_eventDestroyGuardians_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardianSpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKGuardianSpawner_eventDestroyGuardians_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKGuardianSpawner, nullptr, "DestroyGuardians", nullptr, nullptr, Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians_Statics::MRUKGuardianSpawner_eventDestroyGuardians_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians_Statics::MRUKGuardianSpawner_eventDestroyGuardians_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKGuardianSpawner::execDestroyGuardians)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DestroyGuardians(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKGuardianSpawner Function DestroyGuardians

// Begin Class AMRUKGuardianSpawner Function OnRoomCreated
struct Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated_Statics
{
	struct MRUKGuardianSpawner_eventOnRoomCreated_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardianSpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKGuardianSpawner_eventOnRoomCreated_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKGuardianSpawner, nullptr, "OnRoomCreated", nullptr, nullptr, Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated_Statics::MRUKGuardianSpawner_eventOnRoomCreated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated_Statics::MRUKGuardianSpawner_eventOnRoomCreated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKGuardianSpawner::execOnRoomCreated)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRoomCreated(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKGuardianSpawner Function OnRoomCreated

// Begin Class AMRUKGuardianSpawner Function OnRoomRemoved
struct Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved_Statics
{
	struct MRUKGuardianSpawner_eventOnRoomRemoved_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardianSpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKGuardianSpawner_eventOnRoomRemoved_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKGuardianSpawner, nullptr, "OnRoomRemoved", nullptr, nullptr, Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved_Statics::MRUKGuardianSpawner_eventOnRoomRemoved_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved_Statics::MRUKGuardianSpawner_eventOnRoomRemoved_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKGuardianSpawner::execOnRoomRemoved)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRoomRemoved(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKGuardianSpawner Function OnRoomRemoved

// Begin Class AMRUKGuardianSpawner Function OnRoomUpdated
struct Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated_Statics
{
	struct MRUKGuardianSpawner_eventOnRoomUpdated_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardianSpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKGuardianSpawner_eventOnRoomUpdated_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKGuardianSpawner, nullptr, "OnRoomUpdated", nullptr, nullptr, Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated_Statics::MRUKGuardianSpawner_eventOnRoomUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated_Statics::MRUKGuardianSpawner_eventOnRoomUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKGuardianSpawner::execOnRoomUpdated)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRoomUpdated(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKGuardianSpawner Function OnRoomUpdated

// Begin Class AMRUKGuardianSpawner Function SetGridDensity
struct Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity_Statics
{
	struct MRUKGuardianSpawner_eventSetGridDensity_Parms
	{
		double Density;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Set the density of the grid.\n\x09 * @param Density The grid density.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardianSpawner.h" },
		{ "ToolTip", "Set the density of the grid.\n@param Density The grid density." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDoublePropertyParams NewProp_Density;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity_Statics::NewProp_Density = { "Density", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKGuardianSpawner_eventSetGridDensity_Parms, Density), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity_Statics::NewProp_Density,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKGuardianSpawner, nullptr, "SetGridDensity", nullptr, nullptr, Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity_Statics::MRUKGuardianSpawner_eventSetGridDensity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity_Statics::MRUKGuardianSpawner_eventSetGridDensity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKGuardianSpawner::execSetGridDensity)
{
	P_GET_PROPERTY(FDoubleProperty,Z_Param_Density);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetGridDensity(Z_Param_Density);
	P_NATIVE_END;
}
// End Class AMRUKGuardianSpawner Function SetGridDensity

// Begin Class AMRUKGuardianSpawner Function SetGuardianMaterial
struct Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial_Statics
{
	struct MRUKGuardianSpawner_eventSetGuardianMaterial_Parms
	{
		UMaterialInstance* Material;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintSetter", "" },
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Set the guardian material to a different one.\n\x09 * @param Material The guardian material.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardianSpawner.h" },
		{ "ToolTip", "Set the guardian material to a different one.\n@param Material The guardian material." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Material;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial_Statics::NewProp_Material = { "Material", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKGuardianSpawner_eventSetGuardianMaterial_Parms, Material), Z_Construct_UClass_UMaterialInstance_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial_Statics::NewProp_Material,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKGuardianSpawner, nullptr, "SetGuardianMaterial", nullptr, nullptr, Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial_Statics::MRUKGuardianSpawner_eventSetGuardianMaterial_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial_Statics::MRUKGuardianSpawner_eventSetGuardianMaterial_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKGuardianSpawner::execSetGuardianMaterial)
{
	P_GET_OBJECT(UMaterialInstance,Z_Param_Material);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetGuardianMaterial(Z_Param_Material);
	P_NATIVE_END;
}
// End Class AMRUKGuardianSpawner Function SetGuardianMaterial

// Begin Class AMRUKGuardianSpawner Function SpawnGuardians
struct Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians_Statics
{
	struct MRUKGuardianSpawner_eventSpawnGuardians_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Spawn the guardian. This will get called automatically after the mixed reality utility kit has\n\x09 * been initialized if SpawnMode is set to something other than None.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardianSpawner.h" },
		{ "ToolTip", "Spawn the guardian. This will get called automatically after the mixed reality utility kit has\nbeen initialized if SpawnMode is set to something other than None." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKGuardianSpawner_eventSpawnGuardians_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKGuardianSpawner, nullptr, "SpawnGuardians", nullptr, nullptr, Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians_Statics::MRUKGuardianSpawner_eventSpawnGuardians_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians_Statics::MRUKGuardianSpawner_eventSpawnGuardians_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKGuardianSpawner::execSpawnGuardians)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnGuardians(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKGuardianSpawner Function SpawnGuardians

// Begin Class AMRUKGuardianSpawner
void AMRUKGuardianSpawner::StaticRegisterNativesAMRUKGuardianSpawner()
{
	UClass* Class = AMRUKGuardianSpawner::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "DestroyGuardians", &AMRUKGuardianSpawner::execDestroyGuardians },
		{ "OnRoomCreated", &AMRUKGuardianSpawner::execOnRoomCreated },
		{ "OnRoomRemoved", &AMRUKGuardianSpawner::execOnRoomRemoved },
		{ "OnRoomUpdated", &AMRUKGuardianSpawner::execOnRoomUpdated },
		{ "SetGridDensity", &AMRUKGuardianSpawner::execSetGridDensity },
		{ "SetGuardianMaterial", &AMRUKGuardianSpawner::execSetGuardianMaterial },
		{ "SpawnGuardians", &AMRUKGuardianSpawner::execSpawnGuardians },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMRUKGuardianSpawner);
UClass* Z_Construct_UClass_AMRUKGuardianSpawner_NoRegister()
{
	return AMRUKGuardianSpawner::StaticClass();
}
struct Z_Construct_UClass_AMRUKGuardianSpawner_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ClassGroupNames", "MRUtilityKit" },
		{ "Comment", "/**\n * Show a guardian if the player gets close to any furniture or walls.\n */" },
		{ "DisplayName", "MR Utility Kit Guardian" },
		{ "IncludePath", "MRUtilityKitGuardianSpawner.h" },
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardianSpawner.h" },
		{ "ToolTip", "Show a guardian if the player gets close to any furniture or walls." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnMode_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Whether SpawnGuardian() should be called automatically after the mixed reality utility kit\n\x09 * has been initialized.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardianSpawner.h" },
		{ "ToolTip", "Whether SpawnGuardian() should be called automatically after the mixed reality utility kit\nhas been initialized." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GuardianDistance_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * How close the camera needs to come to a surface before the guardian appears.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardianSpawner.h" },
		{ "ToolTip", "How close the camera needs to come to a surface before the guardian appears." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EnableFade_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Whether the fading value should be calculated for the shader or not.\n\x09 If fading is not needed this can save performance.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardianSpawner.h" },
		{ "ToolTip", "Whether the fading value should be calculated for the shader or not.\n        If fading is not needed this can save performance." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GuardianMaterial_MetaData[] = {
		{ "BlueprintSetter", "SetGuardianMaterial" },
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * The material to use for the guardian. It needs to have a scalar parameter Fade\n\x09 * and a vector parameter WallScale. If this material is not set a default one\n\x09 * will be used.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardianSpawner.h" },
		{ "ToolTip", "The material to use for the guardian. It needs to have a scalar parameter Fade\nand a vector parameter WallScale. If this material is not set a default one\nwill be used." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridDensity_MetaData[] = {
		{ "BlueprintSetter", "SetGridDensity" },
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * How dense the grid should be.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardianSpawner.h" },
		{ "ToolTip", "How dense the grid should be." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DynamicGuardianMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardianSpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SpawnMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SpawnMode;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_GuardianDistance;
	static void NewProp_EnableFade_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_EnableFade;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GuardianMaterial;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_GridDensity;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DynamicGuardianMaterial;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMRUKGuardianSpawner_DestroyGuardians, "DestroyGuardians" }, // 1467484535
		{ &Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomCreated, "OnRoomCreated" }, // 2086946087
		{ &Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomRemoved, "OnRoomRemoved" }, // 1192773763
		{ &Z_Construct_UFunction_AMRUKGuardianSpawner_OnRoomUpdated, "OnRoomUpdated" }, // 2612351689
		{ &Z_Construct_UFunction_AMRUKGuardianSpawner_SetGridDensity, "SetGridDensity" }, // 729556713
		{ &Z_Construct_UFunction_AMRUKGuardianSpawner_SetGuardianMaterial, "SetGuardianMaterial" }, // 3915525029
		{ &Z_Construct_UFunction_AMRUKGuardianSpawner_SpawnGuardians, "SpawnGuardians" }, // 3687174452
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMRUKGuardianSpawner>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_SpawnMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_SpawnMode = { "SpawnMode", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKGuardianSpawner, SpawnMode), Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnMode_MetaData), NewProp_SpawnMode_MetaData) }; // 3624342257
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_GuardianDistance = { "GuardianDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKGuardianSpawner, GuardianDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuardianDistance_MetaData), NewProp_GuardianDistance_MetaData) };
void Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_EnableFade_SetBit(void* Obj)
{
	((AMRUKGuardianSpawner*)Obj)->EnableFade = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_EnableFade = { "EnableFade", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMRUKGuardianSpawner), &Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_EnableFade_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EnableFade_MetaData), NewProp_EnableFade_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_GuardianMaterial = { "GuardianMaterial", nullptr, (EPropertyFlags)0x0124080000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKGuardianSpawner, GuardianMaterial), Z_Construct_UClass_UMaterialInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuardianMaterial_MetaData), NewProp_GuardianMaterial_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_GridDensity = { "GridDensity", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKGuardianSpawner, GridDensity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridDensity_MetaData), NewProp_GridDensity_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_DynamicGuardianMaterial = { "DynamicGuardianMaterial", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKGuardianSpawner, DynamicGuardianMaterial), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DynamicGuardianMaterial_MetaData), NewProp_DynamicGuardianMaterial_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMRUKGuardianSpawner_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_SpawnMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_SpawnMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_GuardianDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_EnableFade,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_GuardianMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_GridDensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKGuardianSpawner_Statics::NewProp_DynamicGuardianMaterial,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKGuardianSpawner_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMRUKGuardianSpawner_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKGuardianSpawner_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMRUKGuardianSpawner_Statics::ClassParams = {
	&AMRUKGuardianSpawner::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMRUKGuardianSpawner_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKGuardianSpawner_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKGuardianSpawner_Statics::Class_MetaDataParams), Z_Construct_UClass_AMRUKGuardianSpawner_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMRUKGuardianSpawner()
{
	if (!Z_Registration_Info_UClass_AMRUKGuardianSpawner.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMRUKGuardianSpawner.OuterSingleton, Z_Construct_UClass_AMRUKGuardianSpawner_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMRUKGuardianSpawner.OuterSingleton;
}
template<> MRUTILITYKIT_API UClass* StaticClass<AMRUKGuardianSpawner>()
{
	return AMRUKGuardianSpawner::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMRUKGuardianSpawner);
AMRUKGuardianSpawner::~AMRUKGuardianSpawner() {}
// End Class AMRUKGuardianSpawner

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGuardianSpawner_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMRUKGuardianSpawner, AMRUKGuardianSpawner::StaticClass, TEXT("AMRUKGuardianSpawner"), &Z_Registration_Info_UClass_AMRUKGuardianSpawner, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMRUKGuardianSpawner), 3413660816U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGuardianSpawner_h_2974658263(TEXT("/Script/MRUtilityKit"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGuardianSpawner_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGuardianSpawner_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
