// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MRUtilityKit/Public/MRUtilityKitDistanceMapGenerator.h"
#include "Runtime/Engine/Classes/Camera/CameraTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMRUtilityKitDistanceMapGenerator() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCanvasRenderTarget2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FMinimalViewInfo();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKAnchor_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKDistanceMapGenerator();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKDistanceMapGenerator_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKRoom_NoRegister();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKDistanceMapGenerationMode();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode();
MRUTILITYKIT_API UFunction* Z_Construct_UDelegateFunction_AMRUKDistanceMapGenerator_OnReady__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_MRUtilityKit();
// End Cross Module References

// Begin Enum EMRUKDistanceMapGenerationMode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMRUKDistanceMapGenerationMode;
static UEnum* EMRUKDistanceMapGenerationMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMRUKDistanceMapGenerationMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMRUKDistanceMapGenerationMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MRUtilityKit_EMRUKDistanceMapGenerationMode, (UObject*)Z_Construct_UPackage__Script_MRUtilityKit(), TEXT("EMRUKDistanceMapGenerationMode"));
	}
	return Z_Registration_Info_UEnum_EMRUKDistanceMapGenerationMode.OuterSingleton;
}
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKDistanceMapGenerationMode>()
{
	return EMRUKDistanceMapGenerationMode_StaticEnum();
}
struct Z_Construct_UEnum_MRUtilityKit_EMRUKDistanceMapGenerationMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AllSpace.Comment", "/// Generate the distance map for free space and occupied space.\n" },
		{ "AllSpace.Name", "EMRUKDistanceMapGenerationMode::AllSpace" },
		{ "AllSpace.ToolTip", "Generate the distance map for free space and occupied space." },
		{ "BlueprintType", "true" },
		{ "FreeSpace.Comment", "/// Generate distance map only for the free space. E.g. The floor inside the room.\n" },
		{ "FreeSpace.Name", "EMRUKDistanceMapGenerationMode::FreeSpace" },
		{ "FreeSpace.ToolTip", "Generate distance map only for the free space. E.g. The floor inside the room." },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
		{ "None.Comment", "// Do not generate a distance map\n" },
		{ "None.Name", "EMRUKDistanceMapGenerationMode::None" },
		{ "None.ToolTip", "Do not generate a distance map" },
		{ "OccupiedSpace.Comment", "/// Generate the distance map only for the occupied space. E.g. outside the room and inside scene objects.\n" },
		{ "OccupiedSpace.Name", "EMRUKDistanceMapGenerationMode::OccupiedSpace" },
		{ "OccupiedSpace.ToolTip", "Generate the distance map only for the occupied space. E.g. outside the room and inside scene objects." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMRUKDistanceMapGenerationMode::None", (int64)EMRUKDistanceMapGenerationMode::None },
		{ "EMRUKDistanceMapGenerationMode::FreeSpace", (int64)EMRUKDistanceMapGenerationMode::FreeSpace },
		{ "EMRUKDistanceMapGenerationMode::OccupiedSpace", (int64)EMRUKDistanceMapGenerationMode::OccupiedSpace },
		{ "EMRUKDistanceMapGenerationMode::AllSpace", (int64)EMRUKDistanceMapGenerationMode::AllSpace },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MRUtilityKit_EMRUKDistanceMapGenerationMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MRUtilityKit,
	nullptr,
	"EMRUKDistanceMapGenerationMode",
	"EMRUKDistanceMapGenerationMode",
	Z_Construct_UEnum_MRUtilityKit_EMRUKDistanceMapGenerationMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKDistanceMapGenerationMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MRUtilityKit_EMRUKDistanceMapGenerationMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MRUtilityKit_EMRUKDistanceMapGenerationMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKDistanceMapGenerationMode()
{
	if (!Z_Registration_Info_UEnum_EMRUKDistanceMapGenerationMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMRUKDistanceMapGenerationMode.InnerSingleton, Z_Construct_UEnum_MRUtilityKit_EMRUKDistanceMapGenerationMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMRUKDistanceMapGenerationMode.InnerSingleton;
}
// End Enum EMRUKDistanceMapGenerationMode

// Begin Delegate FOnReady
struct Z_Construct_UDelegateFunction_AMRUKDistanceMapGenerator_OnReady__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_AMRUKDistanceMapGenerator_OnReady__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKDistanceMapGenerator, nullptr, "OnReady__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AMRUKDistanceMapGenerator_OnReady__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_AMRUKDistanceMapGenerator_OnReady__DelegateSignature_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UDelegateFunction_AMRUKDistanceMapGenerator_OnReady__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_AMRUKDistanceMapGenerator_OnReady__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void AMRUKDistanceMapGenerator::FOnReady_DelegateWrapper(const FMulticastScriptDelegate& OnReady)
{
	OnReady.ProcessMulticastDelegate<UObject>(NULL);
}
// End Delegate FOnReady

// Begin Class AMRUKDistanceMapGenerator Function CaptureDistanceMap
struct Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap_Statics
{
	struct MRUKDistanceMapGenerator_eventCaptureDistanceMap_Parms
	{
		UTexture* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Capture the distance map.\n\x09 * @return The captured distance map.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
		{ "ToolTip", "Capture the distance map.\n@return The captured distance map." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDistanceMapGenerator_eventCaptureDistanceMap_Parms, ReturnValue), Z_Construct_UClass_UTexture_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKDistanceMapGenerator, nullptr, "CaptureDistanceMap", nullptr, nullptr, Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap_Statics::MRUKDistanceMapGenerator_eventCaptureDistanceMap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap_Statics::MRUKDistanceMapGenerator_eventCaptureDistanceMap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKDistanceMapGenerator::execCaptureDistanceMap)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTexture**)Z_Param__Result=P_THIS->CaptureDistanceMap();
	P_NATIVE_END;
}
// End Class AMRUKDistanceMapGenerator Function CaptureDistanceMap

// Begin Class AMRUKDistanceMapGenerator Function CreateMaskMeshesForRoom
struct Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom_Statics
{
	struct MRUKDistanceMapGenerator_eventCreateMaskMeshesForRoom_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Create mask meshes for the given room.\n\x09 * These mask meshes are needed for the distance map to be rendered. It should only be called once before\n\x09 * CaptureDistanceMap in case the SpawnMode has been set to None.\n\x09 * The operation that this function executes is expensive. It only needs to be called after the room has been\n\x09 * created or updated.\n\x09 * @param Room The room for which the masked meshes should be created.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
		{ "ToolTip", "Create mask meshes for the given room.\nThese mask meshes are needed for the distance map to be rendered. It should only be called once before\nCaptureDistanceMap in case the SpawnMode has been set to None.\nThe operation that this function executes is expensive. It only needs to be called after the room has been\ncreated or updated.\n@param Room The room for which the masked meshes should be created." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDistanceMapGenerator_eventCreateMaskMeshesForRoom_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKDistanceMapGenerator, nullptr, "CreateMaskMeshesForRoom", nullptr, nullptr, Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom_Statics::MRUKDistanceMapGenerator_eventCreateMaskMeshesForRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom_Statics::MRUKDistanceMapGenerator_eventCreateMaskMeshesForRoom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKDistanceMapGenerator::execCreateMaskMeshesForRoom)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CreateMaskMeshesForRoom(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKDistanceMapGenerator Function CreateMaskMeshesForRoom

// Begin Class AMRUKDistanceMapGenerator Function CreateMaskMeshOfAnchor
struct Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics
{
	struct MRUKDistanceMapGenerator_eventCreateMaskMeshOfAnchor_Parms
	{
		AMRUKAnchor* Anchor;
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDistanceMapGenerator_eventCreateMaskMeshOfAnchor_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDistanceMapGenerator_eventCreateMaskMeshOfAnchor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKDistanceMapGenerator, nullptr, "CreateMaskMeshOfAnchor", nullptr, nullptr, Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics::MRUKDistanceMapGenerator_eventCreateMaskMeshOfAnchor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics::MRUKDistanceMapGenerator_eventCreateMaskMeshOfAnchor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKDistanceMapGenerator::execCreateMaskMeshOfAnchor)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->CreateMaskMeshOfAnchor(Z_Param_Anchor);
	P_NATIVE_END;
}
// End Class AMRUKDistanceMapGenerator Function CreateMaskMeshOfAnchor

// Begin Class AMRUKDistanceMapGenerator Function GetDistanceMap
struct Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap_Statics
{
	struct MRUKDistanceMapGenerator_eventGetDistanceMap_Parms
	{
		UTexture* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Return the captured distance map. Be sure to call CaptureDistanceMap() before\n\x09 * @return The captured distance map.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
		{ "ToolTip", "Return the captured distance map. Be sure to call CaptureDistanceMap() before\n@return The captured distance map." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDistanceMapGenerator_eventGetDistanceMap_Parms, ReturnValue), Z_Construct_UClass_UTexture_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKDistanceMapGenerator, nullptr, "GetDistanceMap", nullptr, nullptr, Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap_Statics::MRUKDistanceMapGenerator_eventGetDistanceMap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap_Statics::MRUKDistanceMapGenerator_eventGetDistanceMap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKDistanceMapGenerator::execGetDistanceMap)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTexture**)Z_Param__Result=P_THIS->GetDistanceMap();
	P_NATIVE_END;
}
// End Class AMRUKDistanceMapGenerator Function GetDistanceMap

// Begin Class AMRUKDistanceMapGenerator Function GetDistanceMapRenderTarget
struct Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget_Statics
{
	struct MRUKDistanceMapGenerator_eventGetDistanceMapRenderTarget_Parms
	{
		UCanvasRenderTarget2D* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDistanceMapGenerator_eventGetDistanceMapRenderTarget_Parms, ReturnValue), Z_Construct_UClass_UCanvasRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKDistanceMapGenerator, nullptr, "GetDistanceMapRenderTarget", nullptr, nullptr, Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget_Statics::MRUKDistanceMapGenerator_eventGetDistanceMapRenderTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget_Statics::MRUKDistanceMapGenerator_eventGetDistanceMapRenderTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKDistanceMapGenerator::execGetDistanceMapRenderTarget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCanvasRenderTarget2D**)Z_Param__Result=P_THIS->GetDistanceMapRenderTarget();
	P_NATIVE_END;
}
// End Class AMRUKDistanceMapGenerator Function GetDistanceMapRenderTarget

// Begin Class AMRUKDistanceMapGenerator Function GetSceneCaptureView
struct Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView_Statics
{
	struct MRUKDistanceMapGenerator_eventGetSceneCaptureView_Parms
	{
		FMinimalViewInfo ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Retrieve the view info from the scene capture. This is useful for re projection of\n\x09 * the distance map in a material.\n\x09 * @return The view info.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
		{ "ToolTip", "Retrieve the view info from the scene capture. This is useful for re projection of\nthe distance map in a material.\n@return The view info." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDistanceMapGenerator_eventGetSceneCaptureView_Parms, ReturnValue), Z_Construct_UScriptStruct_FMinimalViewInfo, METADATA_PARAMS(0, nullptr) }; // 994039058
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKDistanceMapGenerator, nullptr, "GetSceneCaptureView", nullptr, nullptr, Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView_Statics::MRUKDistanceMapGenerator_eventGetSceneCaptureView_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView_Statics::MRUKDistanceMapGenerator_eventGetSceneCaptureView_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKDistanceMapGenerator::execGetSceneCaptureView)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FMinimalViewInfo*)Z_Param__Result=P_THIS->GetSceneCaptureView();
	P_NATIVE_END;
}
// End Class AMRUKDistanceMapGenerator Function GetSceneCaptureView

// Begin Class AMRUKDistanceMapGenerator Function OnRoomCreated
struct Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated_Statics
{
	struct MRUKDistanceMapGenerator_eventOnRoomCreated_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDistanceMapGenerator_eventOnRoomCreated_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKDistanceMapGenerator, nullptr, "OnRoomCreated", nullptr, nullptr, Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated_Statics::MRUKDistanceMapGenerator_eventOnRoomCreated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated_Statics::MRUKDistanceMapGenerator_eventOnRoomCreated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKDistanceMapGenerator::execOnRoomCreated)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRoomCreated(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKDistanceMapGenerator Function OnRoomCreated

// Begin Class AMRUKDistanceMapGenerator Function RemoveMaskMeshesFromRoom
struct Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom_Statics
{
	struct MRUKDistanceMapGenerator_eventRemoveMaskMeshesFromRoom_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Remove mask meshes for the given room.\n\x09 * This function should only be executed when SpawnMode is set to None.\n\x09 * It only needs to be called after a room has been removed.\n\x09 * @param Room The room for which the masked meshes should be removed.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
		{ "ToolTip", "Remove mask meshes for the given room.\nThis function should only be executed when SpawnMode is set to None.\nIt only needs to be called after a room has been removed.\n@param Room The room for which the masked meshes should be removed." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDistanceMapGenerator_eventRemoveMaskMeshesFromRoom_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKDistanceMapGenerator, nullptr, "RemoveMaskMeshesFromRoom", nullptr, nullptr, Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom_Statics::MRUKDistanceMapGenerator_eventRemoveMaskMeshesFromRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom_Statics::MRUKDistanceMapGenerator_eventRemoveMaskMeshesFromRoom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKDistanceMapGenerator::execRemoveMaskMeshesFromRoom)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveMaskMeshesFromRoom(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKDistanceMapGenerator Function RemoveMaskMeshesFromRoom

// Begin Class AMRUKDistanceMapGenerator Function UpdateMaskMeshOfAnchor
struct Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics
{
	struct MRUKDistanceMapGenerator_eventUpdateMaskMeshOfAnchor_Parms
	{
		AMRUKAnchor* Anchor;
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDistanceMapGenerator_eventUpdateMaskMeshOfAnchor_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDistanceMapGenerator_eventUpdateMaskMeshOfAnchor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKDistanceMapGenerator, nullptr, "UpdateMaskMeshOfAnchor", nullptr, nullptr, Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics::MRUKDistanceMapGenerator_eventUpdateMaskMeshOfAnchor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics::MRUKDistanceMapGenerator_eventUpdateMaskMeshOfAnchor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKDistanceMapGenerator::execUpdateMaskMeshOfAnchor)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->UpdateMaskMeshOfAnchor(Z_Param_Anchor);
	P_NATIVE_END;
}
// End Class AMRUKDistanceMapGenerator Function UpdateMaskMeshOfAnchor

// Begin Class AMRUKDistanceMapGenerator
void AMRUKDistanceMapGenerator::StaticRegisterNativesAMRUKDistanceMapGenerator()
{
	UClass* Class = AMRUKDistanceMapGenerator::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CaptureDistanceMap", &AMRUKDistanceMapGenerator::execCaptureDistanceMap },
		{ "CreateMaskMeshesForRoom", &AMRUKDistanceMapGenerator::execCreateMaskMeshesForRoom },
		{ "CreateMaskMeshOfAnchor", &AMRUKDistanceMapGenerator::execCreateMaskMeshOfAnchor },
		{ "GetDistanceMap", &AMRUKDistanceMapGenerator::execGetDistanceMap },
		{ "GetDistanceMapRenderTarget", &AMRUKDistanceMapGenerator::execGetDistanceMapRenderTarget },
		{ "GetSceneCaptureView", &AMRUKDistanceMapGenerator::execGetSceneCaptureView },
		{ "OnRoomCreated", &AMRUKDistanceMapGenerator::execOnRoomCreated },
		{ "RemoveMaskMeshesFromRoom", &AMRUKDistanceMapGenerator::execRemoveMaskMeshesFromRoom },
		{ "UpdateMaskMeshOfAnchor", &AMRUKDistanceMapGenerator::execUpdateMaskMeshOfAnchor },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMRUKDistanceMapGenerator);
UClass* Z_Construct_UClass_AMRUKDistanceMapGenerator_NoRegister()
{
	return AMRUKDistanceMapGenerator::StaticClass();
}
struct Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ClassGroupNames", "MRUtilityKit" },
		{ "Comment", "/**\n * Generates a distance map that can be used in materials to calculate the distance to various objects.\n * This can enable interesting effects. With the distance map you can get the distance from scene objects\n * or walls in a material shader.\n *\n * The Jump Flood Algorithm is used to generate the distance map. This is fast enough to regenerate\n * every tick.\n *\n * To capture a distance map after a room has been loaded call CaptureDistanceMap().\n * It will return a captured distance map. In case you already called CaptureDistanceMap()\n * you can receive the last captured distance map with GetDistanceMap(). No other setup is required.\n *\n * This class will create procedural meshes for every anchor to create a mask. These meshes have their\n * visibility set to scene capture only. That however means that if you place a scene capture component yourself\n * that the meshes will show up in your scene capture component. The actors that have the procedural meshes\n * attached are tagged with GMRUK_DISTANCE_MAP_ACTOR_TAG. In case you don't want them to show up in your\n * scene capture you can hide them by receiving all these actors with the tag GMRUK_DISTANCE_MAP_ACTOR_TAG\n * and add these to the scene captures hidden actors.\n */" },
		{ "DisplayName", "MR Utility Kit Distance Map Generator" },
		{ "IncludePath", "MRUtilityKitDistanceMapGenerator.h" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
		{ "ToolTip", "Generates a distance map that can be used in materials to calculate the distance to various objects.\nThis can enable interesting effects. With the distance map you can get the distance from scene objects\nor walls in a material shader.\n\nThe Jump Flood Algorithm is used to generate the distance map. This is fast enough to regenerate\nevery tick.\n\nTo capture a distance map after a room has been loaded call CaptureDistanceMap().\nIt will return a captured distance map. In case you already called CaptureDistanceMap()\nyou can receive the last captured distance map with GetDistanceMap(). No other setup is required.\n\nThis class will create procedural meshes for every anchor to create a mask. These meshes have their\nvisibility set to scene capture only. That however means that if you place a scene capture component yourself\nthat the meshes will show up in your scene capture component. The actors that have the procedural meshes\nattached are tagged with GMRUK_DISTANCE_MAP_ACTOR_TAG. In case you don't want them to show up in your\nscene capture you can hide them by receiving all these actors with the tag GMRUK_DISTANCE_MAP_ACTOR_TAG\nand add these to the scene captures hidden actors." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnReady_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceMapGenerationMode_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * The mode in which the final distance map should be generated.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
		{ "ToolTip", "The mode in which the final distance map should be generated." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Root_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneCapture2D_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnMode_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget1_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * First render target for jump flood algorithm.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
		{ "ToolTip", "First render target for jump flood algorithm." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderTarget2_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Second render target for jump flood algorithm.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
		{ "ToolTip", "Second render target for jump flood algorithm." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceMapRenderTarget_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Render target for the final distance map\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
		{ "ToolTip", "Render target for the final distance map" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaskMaterial_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Material to render a mask that gets used to calculate the distance map.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
		{ "ToolTip", "Material to render a mask that gets used to calculate the distance map." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JFPassMaterial_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Material that executes a pass of the jump flood algorithm.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
		{ "ToolTip", "Material that executes a pass of the jump flood algorithm." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceMapFreeSpaceMaterial_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Material to render final distance map\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
		{ "ToolTip", "Material to render final distance map" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceMapOccupiedSpaceMaterial_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceMapAllSpaceMaterial_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JFPassMaterialInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceMapFreeSpaceMaterialInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceMapOccupiedSpaceMaterialInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceMapAllSpaceMaterialInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneObjectMaskMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloorMaskMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitDistanceMapGenerator.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnReady;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DistanceMapGenerationMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DistanceMapGenerationMode;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Root;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneCapture2D;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SpawnMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SpawnMode;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget1;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget2;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DistanceMapRenderTarget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaskMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JFPassMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DistanceMapFreeSpaceMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DistanceMapOccupiedSpaceMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DistanceMapAllSpaceMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JFPassMaterialInstance;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DistanceMapFreeSpaceMaterialInstance;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DistanceMapOccupiedSpaceMaterialInstance;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DistanceMapAllSpaceMaterialInstance;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneObjectMaskMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FloorMaskMaterial;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMRUKDistanceMapGenerator_CaptureDistanceMap, "CaptureDistanceMap" }, // 464140816
		{ &Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshesForRoom, "CreateMaskMeshesForRoom" }, // 1996583469
		{ &Z_Construct_UFunction_AMRUKDistanceMapGenerator_CreateMaskMeshOfAnchor, "CreateMaskMeshOfAnchor" }, // 3568184141
		{ &Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMap, "GetDistanceMap" }, // 4144779077
		{ &Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetDistanceMapRenderTarget, "GetDistanceMapRenderTarget" }, // 1221862847
		{ &Z_Construct_UFunction_AMRUKDistanceMapGenerator_GetSceneCaptureView, "GetSceneCaptureView" }, // 1595188306
		{ &Z_Construct_UDelegateFunction_AMRUKDistanceMapGenerator_OnReady__DelegateSignature, "OnReady__DelegateSignature" }, // 2139756664
		{ &Z_Construct_UFunction_AMRUKDistanceMapGenerator_OnRoomCreated, "OnRoomCreated" }, // 1001687009
		{ &Z_Construct_UFunction_AMRUKDistanceMapGenerator_RemoveMaskMeshesFromRoom, "RemoveMaskMeshesFromRoom" }, // 2910908603
		{ &Z_Construct_UFunction_AMRUKDistanceMapGenerator_UpdateMaskMeshOfAnchor, "UpdateMaskMeshOfAnchor" }, // 1959265787
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMRUKDistanceMapGenerator>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_OnReady = { "OnReady", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, OnReady), Z_Construct_UDelegateFunction_AMRUKDistanceMapGenerator_OnReady__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnReady_MetaData), NewProp_OnReady_MetaData) }; // 2139756664
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapGenerationMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapGenerationMode = { "DistanceMapGenerationMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, DistanceMapGenerationMode), Z_Construct_UEnum_MRUtilityKit_EMRUKDistanceMapGenerationMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceMapGenerationMode_MetaData), NewProp_DistanceMapGenerationMode_MetaData) }; // 1178102912
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_Root = { "Root", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, Root), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Root_MetaData), NewProp_Root_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_SceneCapture2D = { "SceneCapture2D", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, SceneCapture2D), Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneCapture2D_MetaData), NewProp_SceneCapture2D_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_SpawnMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_SpawnMode = { "SpawnMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, SpawnMode), Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnMode_MetaData), NewProp_SpawnMode_MetaData) }; // 3624342257
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_RenderTarget1 = { "RenderTarget1", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, RenderTarget1), Z_Construct_UClass_UCanvasRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget1_MetaData), NewProp_RenderTarget1_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_RenderTarget2 = { "RenderTarget2", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, RenderTarget2), Z_Construct_UClass_UCanvasRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderTarget2_MetaData), NewProp_RenderTarget2_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapRenderTarget = { "DistanceMapRenderTarget", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, DistanceMapRenderTarget), Z_Construct_UClass_UCanvasRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceMapRenderTarget_MetaData), NewProp_DistanceMapRenderTarget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_MaskMaterial = { "MaskMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, MaskMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaskMaterial_MetaData), NewProp_MaskMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_JFPassMaterial = { "JFPassMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, JFPassMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JFPassMaterial_MetaData), NewProp_JFPassMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapFreeSpaceMaterial = { "DistanceMapFreeSpaceMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, DistanceMapFreeSpaceMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceMapFreeSpaceMaterial_MetaData), NewProp_DistanceMapFreeSpaceMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapOccupiedSpaceMaterial = { "DistanceMapOccupiedSpaceMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, DistanceMapOccupiedSpaceMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceMapOccupiedSpaceMaterial_MetaData), NewProp_DistanceMapOccupiedSpaceMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapAllSpaceMaterial = { "DistanceMapAllSpaceMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, DistanceMapAllSpaceMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceMapAllSpaceMaterial_MetaData), NewProp_DistanceMapAllSpaceMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_JFPassMaterialInstance = { "JFPassMaterialInstance", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, JFPassMaterialInstance), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JFPassMaterialInstance_MetaData), NewProp_JFPassMaterialInstance_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapFreeSpaceMaterialInstance = { "DistanceMapFreeSpaceMaterialInstance", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, DistanceMapFreeSpaceMaterialInstance), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceMapFreeSpaceMaterialInstance_MetaData), NewProp_DistanceMapFreeSpaceMaterialInstance_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapOccupiedSpaceMaterialInstance = { "DistanceMapOccupiedSpaceMaterialInstance", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, DistanceMapOccupiedSpaceMaterialInstance), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceMapOccupiedSpaceMaterialInstance_MetaData), NewProp_DistanceMapOccupiedSpaceMaterialInstance_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapAllSpaceMaterialInstance = { "DistanceMapAllSpaceMaterialInstance", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, DistanceMapAllSpaceMaterialInstance), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceMapAllSpaceMaterialInstance_MetaData), NewProp_DistanceMapAllSpaceMaterialInstance_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_SceneObjectMaskMaterial = { "SceneObjectMaskMaterial", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, SceneObjectMaskMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneObjectMaskMaterial_MetaData), NewProp_SceneObjectMaskMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_FloorMaskMaterial = { "FloorMaskMaterial", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKDistanceMapGenerator, FloorMaskMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloorMaskMaterial_MetaData), NewProp_FloorMaskMaterial_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_OnReady,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapGenerationMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapGenerationMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_Root,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_SceneCapture2D,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_SpawnMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_SpawnMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_RenderTarget1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_RenderTarget2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapRenderTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_MaskMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_JFPassMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapFreeSpaceMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapOccupiedSpaceMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapAllSpaceMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_JFPassMaterialInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapFreeSpaceMaterialInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapOccupiedSpaceMaterialInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_DistanceMapAllSpaceMaterialInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_SceneObjectMaskMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::NewProp_FloorMaskMaterial,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::ClassParams = {
	&AMRUKDistanceMapGenerator::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::Class_MetaDataParams), Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMRUKDistanceMapGenerator()
{
	if (!Z_Registration_Info_UClass_AMRUKDistanceMapGenerator.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMRUKDistanceMapGenerator.OuterSingleton, Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMRUKDistanceMapGenerator.OuterSingleton;
}
template<> MRUTILITYKIT_API UClass* StaticClass<AMRUKDistanceMapGenerator>()
{
	return AMRUKDistanceMapGenerator::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMRUKDistanceMapGenerator);
AMRUKDistanceMapGenerator::~AMRUKDistanceMapGenerator() {}
// End Class AMRUKDistanceMapGenerator

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EMRUKDistanceMapGenerationMode_StaticEnum, TEXT("EMRUKDistanceMapGenerationMode"), &Z_Registration_Info_UEnum_EMRUKDistanceMapGenerationMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1178102912U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMRUKDistanceMapGenerator, AMRUKDistanceMapGenerator::StaticClass, TEXT("AMRUKDistanceMapGenerator"), &Z_Registration_Info_UClass_AMRUKDistanceMapGenerator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMRUKDistanceMapGenerator), 3449415897U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_2057663479(TEXT("/Script/MRUtilityKit"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
