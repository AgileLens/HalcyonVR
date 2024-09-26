// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRScene/Public/OculusXRSceneActor.h"
#include "OculusXRAnchors/Public/OculusXRAnchorTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRSceneActor() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
OCULUSXRANCHORS_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRRoomLayout();
OCULUSXRANCHORS_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRUInt64();
OCULUSXRSCENE_API UClass* Z_Construct_UClass_AOculusXRSceneActor();
OCULUSXRSCENE_API UClass* Z_Construct_UClass_AOculusXRSceneActor_NoRegister();
OCULUSXRSCENE_API UClass* Z_Construct_UClass_UOculusXRSceneAnchorComponent_NoRegister();
OCULUSXRSCENE_API UEnum* Z_Construct_UEnum_OculusXRScene_EOculusXRLaunchCaptureFlowWhenMissingScene();
OCULUSXRSCENE_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties();
UPackage* Z_Construct_UPackage__Script_OculusXRScene();
// End Cross Module References

// Begin Enum EOculusXRLaunchCaptureFlowWhenMissingScene
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRLaunchCaptureFlowWhenMissingScene;
static UEnum* EOculusXRLaunchCaptureFlowWhenMissingScene_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRLaunchCaptureFlowWhenMissingScene.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRLaunchCaptureFlowWhenMissingScene.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRScene_EOculusXRLaunchCaptureFlowWhenMissingScene, (UObject*)Z_Construct_UPackage__Script_OculusXRScene(), TEXT("EOculusXRLaunchCaptureFlowWhenMissingScene"));
	}
	return Z_Registration_Info_UEnum_EOculusXRLaunchCaptureFlowWhenMissingScene.OuterSingleton;
}
template<> OCULUSXRSCENE_API UEnum* StaticEnum<EOculusXRLaunchCaptureFlowWhenMissingScene>()
{
	return EOculusXRLaunchCaptureFlowWhenMissingScene_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRScene_EOculusXRLaunchCaptureFlowWhenMissingScene_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "ALWAYS.DisplayName", "Always" },
		{ "ALWAYS.Name", "ALWAYS" },
		{ "BlueprintType", "true" },
		{ "Comment", "/** EOculusXRLaunchCaptureFlowWhenMissingScene\n * Used to dictate whether the actor should launch the Capture Flow application when a scene is not detected on the device.\n * The Actor will check if a scene capture is either non-existent or invalid (ie. missing walls/ceiling/floor) before checking if Capture Flow\n * should be launched.\n *\n * NEVER:\x09will never launch Flow Capture.\n * ONCE:\x09\x09will only launch it once.  If the actor still doesn't detect that a scene was captured, it will not launch Capture Flow again.\n * ALWAYS:\x09will always re-launch Flow Capture if a scene was not detected on the device.\n */" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
		{ "NEVER.DisplayName", "Never" },
		{ "NEVER.Name", "NEVER" },
		{ "ONCE.DisplayName", "Once" },
		{ "ONCE.Name", "ONCE" },
		{ "ToolTip", "EOculusXRLaunchCaptureFlowWhenMissingScene\nUsed to dictate whether the actor should launch the Capture Flow application when a scene is not detected on the device.\nThe Actor will check if a scene capture is either non-existent or invalid (ie. missing walls/ceiling/floor) before checking if Capture Flow\nshould be launched.\n\nNEVER:      will never launch Flow Capture.\nONCE:               will only launch it once.  If the actor still doesn't detect that a scene was captured, it will not launch Capture Flow again.\nALWAYS:     will always re-launch Flow Capture if a scene was not detected on the device." },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "NEVER", (int64)NEVER },
		{ "ONCE", (int64)ONCE },
		{ "ALWAYS", (int64)ALWAYS },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRScene_EOculusXRLaunchCaptureFlowWhenMissingScene_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRScene,
	nullptr,
	"EOculusXRLaunchCaptureFlowWhenMissingScene",
	"EOculusXRLaunchCaptureFlowWhenMissingScene",
	Z_Construct_UEnum_OculusXRScene_EOculusXRLaunchCaptureFlowWhenMissingScene_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRScene_EOculusXRLaunchCaptureFlowWhenMissingScene_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::Regular,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRScene_EOculusXRLaunchCaptureFlowWhenMissingScene_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRScene_EOculusXRLaunchCaptureFlowWhenMissingScene_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRScene_EOculusXRLaunchCaptureFlowWhenMissingScene()
{
	if (!Z_Registration_Info_UEnum_EOculusXRLaunchCaptureFlowWhenMissingScene.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRLaunchCaptureFlowWhenMissingScene.InnerSingleton, Z_Construct_UEnum_OculusXRScene_EOculusXRLaunchCaptureFlowWhenMissingScene_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRLaunchCaptureFlowWhenMissingScene.InnerSingleton;
}
// End Enum EOculusXRLaunchCaptureFlowWhenMissingScene

// Begin ScriptStruct FOculusXRSpawnedSceneAnchorProperties
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OculusXRSpawnedSceneAnchorProperties;
class UScriptStruct* FOculusXRSpawnedSceneAnchorProperties::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRSpawnedSceneAnchorProperties.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OculusXRSpawnedSceneAnchorProperties.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties, (UObject*)Z_Construct_UPackage__Script_OculusXRScene(), TEXT("OculusXRSpawnedSceneAnchorProperties"));
	}
	return Z_Registration_Info_UScriptStruct_OculusXRSpawnedSceneAnchorProperties.OuterSingleton;
}
template<> OCULUSXRSCENE_API UScriptStruct* StaticStruct<FOculusXRSpawnedSceneAnchorProperties>()
{
	return FOculusXRSpawnedSceneAnchorProperties::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/** FOculusXRSpawnedSceneAnchorProperties\n * Properties/Components that a spawned scene anchor will use.\n */" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
		{ "ToolTip", "FOculusXRSpawnedSceneAnchorProperties\nProperties/Components that a spawned scene anchor will use." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorComponent_MetaData[] = {
		{ "Category", "Spawned Scene Anchor Properties" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[] = {
		{ "Category", "Spawned Scene Anchor Properties" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ForceParallelToFloor_MetaData[] = {
		{ "Category", "Spawned Scene Anchor Properties" },
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "This property is deprecated. Alignment is done automatically at lower level." },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AddOffset_MetaData[] = {
		{ "Category", "Spawned Scene Anchor Properties" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_ActorComponent;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_StaticMesh;
	static void NewProp_ForceParallelToFloor_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ForceParallelToFloor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AddOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOculusXRSpawnedSceneAnchorProperties>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::NewProp_ActorComponent = { "ActorComponent", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRSpawnedSceneAnchorProperties, ActorComponent), Z_Construct_UClass_UOculusXRSceneAnchorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorComponent_MetaData), NewProp_ActorComponent_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::NewProp_StaticMesh = { "StaticMesh", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRSpawnedSceneAnchorProperties, StaticMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StaticMesh_MetaData), NewProp_StaticMesh_MetaData) };
void Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::NewProp_ForceParallelToFloor_SetBit(void* Obj)
{
	((FOculusXRSpawnedSceneAnchorProperties*)Obj)->ForceParallelToFloor = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::NewProp_ForceParallelToFloor = { "ForceParallelToFloor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FOculusXRSpawnedSceneAnchorProperties), &Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::NewProp_ForceParallelToFloor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ForceParallelToFloor_MetaData), NewProp_ForceParallelToFloor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::NewProp_AddOffset = { "AddOffset", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRSpawnedSceneAnchorProperties, AddOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AddOffset_MetaData), NewProp_AddOffset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::NewProp_ActorComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::NewProp_StaticMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::NewProp_ForceParallelToFloor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::NewProp_AddOffset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRScene,
	nullptr,
	&NewStructOps,
	"OculusXRSpawnedSceneAnchorProperties",
	Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::PropPointers),
	sizeof(FOculusXRSpawnedSceneAnchorProperties),
	alignof(FOculusXRSpawnedSceneAnchorProperties),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRSpawnedSceneAnchorProperties.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OculusXRSpawnedSceneAnchorProperties.InnerSingleton, Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OculusXRSpawnedSceneAnchorProperties.InnerSingleton;
}
// End ScriptStruct FOculusXRSpawnedSceneAnchorProperties

// Begin Class AOculusXRSceneActor Function ClearScene
struct Z_Construct_UFunction_AOculusXRSceneActor_ClearScene_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOculusXRSceneActor_ClearScene_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOculusXRSceneActor, nullptr, "ClearScene", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_ClearScene_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOculusXRSceneActor_ClearScene_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AOculusXRSceneActor_ClearScene()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOculusXRSceneActor_ClearScene_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOculusXRSceneActor::execClearScene)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearScene();
	P_NATIVE_END;
}
// End Class AOculusXRSceneActor Function ClearScene

// Begin Class AOculusXRSceneActor Function GetActorsBySemanticLabel
struct Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics
{
	struct OculusXRSceneActor_eventGetActorsBySemanticLabel_Parms
	{
		FString SemanticLabel;
		TArray<AActor*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SemanticLabel_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_SemanticLabel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::NewProp_SemanticLabel = { "SemanticLabel", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRSceneActor_eventGetActorsBySemanticLabel_Parms, SemanticLabel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SemanticLabel_MetaData), NewProp_SemanticLabel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRSceneActor_eventGetActorsBySemanticLabel_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::NewProp_SemanticLabel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOculusXRSceneActor, nullptr, "GetActorsBySemanticLabel", nullptr, nullptr, Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::OculusXRSceneActor_eventGetActorsBySemanticLabel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::OculusXRSceneActor_eventGetActorsBySemanticLabel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOculusXRSceneActor::execGetActorsBySemanticLabel)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SemanticLabel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AActor*>*)Z_Param__Result=P_THIS->GetActorsBySemanticLabel(Z_Param_SemanticLabel);
	P_NATIVE_END;
}
// End Class AOculusXRSceneActor Function GetActorsBySemanticLabel

// Begin Class AOculusXRSceneActor Function GetRoomLayouts
struct Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics
{
	struct OculusXRSceneActor_eventGetRoomLayouts_Parms
	{
		TArray<FOculusXRRoomLayout> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOculusXRRoomLayout, METADATA_PARAMS(0, nullptr) }; // 3375187172
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRSceneActor_eventGetRoomLayouts_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3375187172
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOculusXRSceneActor, nullptr, "GetRoomLayouts", nullptr, nullptr, Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics::OculusXRSceneActor_eventGetRoomLayouts_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics::OculusXRSceneActor_eventGetRoomLayouts_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOculusXRSceneActor::execGetRoomLayouts)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FOculusXRRoomLayout>*)Z_Param__Result=P_THIS->GetRoomLayouts();
	P_NATIVE_END;
}
// End Class AOculusXRSceneActor Function GetRoomLayouts

// Begin Class AOculusXRSceneActor Function IsRoomLayoutValid
struct Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics
{
	struct OculusXRSceneActor_eventIsRoomLayoutValid_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "DeprecatedFunction", "" },
		{ "DeprecationMessage", "Is Room Layout Valid is deprecated and no longer returns any value but true. Please validate your room configuration in the way your application requires." },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRSceneActor_eventIsRoomLayoutValid_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRSceneActor_eventIsRoomLayoutValid_Parms), &Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOculusXRSceneActor, nullptr, "IsRoomLayoutValid", nullptr, nullptr, Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics::OculusXRSceneActor_eventIsRoomLayoutValid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics::OculusXRSceneActor_eventIsRoomLayoutValid_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOculusXRSceneActor::execIsRoomLayoutValid)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsRoomLayoutValid();
	P_NATIVE_END;
}
// End Class AOculusXRSceneActor Function IsRoomLayoutValid

// Begin Class AOculusXRSceneActor Function IsScenePopulated
struct Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics
{
	struct OculusXRSceneActor_eventIsScenePopulated_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRSceneActor_eventIsScenePopulated_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRSceneActor_eventIsScenePopulated_Parms), &Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOculusXRSceneActor, nullptr, "IsScenePopulated", nullptr, nullptr, Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics::OculusXRSceneActor_eventIsScenePopulated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics::OculusXRSceneActor_eventIsScenePopulated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOculusXRSceneActor::execIsScenePopulated)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsScenePopulated();
	P_NATIVE_END;
}
// End Class AOculusXRSceneActor Function IsScenePopulated

// Begin Class AOculusXRSceneActor Function LaunchCaptureFlow
struct Z_Construct_UFunction_AOculusXRSceneActor_LaunchCaptureFlow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOculusXRSceneActor_LaunchCaptureFlow_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOculusXRSceneActor, nullptr, "LaunchCaptureFlow", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_LaunchCaptureFlow_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOculusXRSceneActor_LaunchCaptureFlow_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AOculusXRSceneActor_LaunchCaptureFlow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOculusXRSceneActor_LaunchCaptureFlow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOculusXRSceneActor::execLaunchCaptureFlow)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LaunchCaptureFlow();
	P_NATIVE_END;
}
// End Class AOculusXRSceneActor Function LaunchCaptureFlow

// Begin Class AOculusXRSceneActor Function PopulateScene
struct Z_Construct_UFunction_AOculusXRSceneActor_PopulateScene_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOculusXRSceneActor_PopulateScene_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOculusXRSceneActor, nullptr, "PopulateScene", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_PopulateScene_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOculusXRSceneActor_PopulateScene_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AOculusXRSceneActor_PopulateScene()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOculusXRSceneActor_PopulateScene_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOculusXRSceneActor::execPopulateScene)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PopulateScene();
	P_NATIVE_END;
}
// End Class AOculusXRSceneActor Function PopulateScene

// Begin Class AOculusXRSceneActor Function SetVisibilityToAllSceneAnchors
struct Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics
{
	struct OculusXRSceneActor_eventSetVisibilityToAllSceneAnchors_Parms
	{
		bool bIsVisible;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsVisible_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static void NewProp_bIsVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsVisible;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics::NewProp_bIsVisible_SetBit(void* Obj)
{
	((OculusXRSceneActor_eventSetVisibilityToAllSceneAnchors_Parms*)Obj)->bIsVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics::NewProp_bIsVisible = { "bIsVisible", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRSceneActor_eventSetVisibilityToAllSceneAnchors_Parms), &Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics::NewProp_bIsVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsVisible_MetaData), NewProp_bIsVisible_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics::NewProp_bIsVisible,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOculusXRSceneActor, nullptr, "SetVisibilityToAllSceneAnchors", nullptr, nullptr, Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics::OculusXRSceneActor_eventSetVisibilityToAllSceneAnchors_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics::OculusXRSceneActor_eventSetVisibilityToAllSceneAnchors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOculusXRSceneActor::execSetVisibilityToAllSceneAnchors)
{
	P_GET_UBOOL(Z_Param_bIsVisible);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetVisibilityToAllSceneAnchors(Z_Param_bIsVisible);
	P_NATIVE_END;
}
// End Class AOculusXRSceneActor Function SetVisibilityToAllSceneAnchors

// Begin Class AOculusXRSceneActor Function SetVisibilityToSceneAnchorsBySemanticLabel
struct Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics
{
	struct OculusXRSceneActor_eventSetVisibilityToSceneAnchorsBySemanticLabel_Parms
	{
		FString SemanticLabel;
		bool bIsVisible;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SemanticLabel_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsVisible_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_SemanticLabel;
	static void NewProp_bIsVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsVisible;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::NewProp_SemanticLabel = { "SemanticLabel", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRSceneActor_eventSetVisibilityToSceneAnchorsBySemanticLabel_Parms, SemanticLabel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SemanticLabel_MetaData), NewProp_SemanticLabel_MetaData) };
void Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::NewProp_bIsVisible_SetBit(void* Obj)
{
	((OculusXRSceneActor_eventSetVisibilityToSceneAnchorsBySemanticLabel_Parms*)Obj)->bIsVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::NewProp_bIsVisible = { "bIsVisible", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRSceneActor_eventSetVisibilityToSceneAnchorsBySemanticLabel_Parms), &Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::NewProp_bIsVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsVisible_MetaData), NewProp_bIsVisible_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::NewProp_SemanticLabel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::NewProp_bIsVisible,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOculusXRSceneActor, nullptr, "SetVisibilityToSceneAnchorsBySemanticLabel", nullptr, nullptr, Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::PropPointers), sizeof(Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::OculusXRSceneActor_eventSetVisibilityToSceneAnchorsBySemanticLabel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::Function_MetaDataParams), Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::OculusXRSceneActor_eventSetVisibilityToSceneAnchorsBySemanticLabel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AOculusXRSceneActor::execSetVisibilityToSceneAnchorsBySemanticLabel)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_SemanticLabel);
	P_GET_UBOOL(Z_Param_bIsVisible);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetVisibilityToSceneAnchorsBySemanticLabel(Z_Param_SemanticLabel,Z_Param_bIsVisible);
	P_NATIVE_END;
}
// End Class AOculusXRSceneActor Function SetVisibilityToSceneAnchorsBySemanticLabel

// Begin Class AOculusXRSceneActor
void AOculusXRSceneActor::StaticRegisterNativesAOculusXRSceneActor()
{
	UClass* Class = AOculusXRSceneActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClearScene", &AOculusXRSceneActor::execClearScene },
		{ "GetActorsBySemanticLabel", &AOculusXRSceneActor::execGetActorsBySemanticLabel },
		{ "GetRoomLayouts", &AOculusXRSceneActor::execGetRoomLayouts },
		{ "IsRoomLayoutValid", &AOculusXRSceneActor::execIsRoomLayoutValid },
		{ "IsScenePopulated", &AOculusXRSceneActor::execIsScenePopulated },
		{ "LaunchCaptureFlow", &AOculusXRSceneActor::execLaunchCaptureFlow },
		{ "PopulateScene", &AOculusXRSceneActor::execPopulateScene },
		{ "SetVisibilityToAllSceneAnchors", &AOculusXRSceneActor::execSetVisibilityToAllSceneAnchors },
		{ "SetVisibilityToSceneAnchorsBySemanticLabel", &AOculusXRSceneActor::execSetVisibilityToSceneAnchorsBySemanticLabel },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOculusXRSceneActor);
UClass* Z_Construct_UClass_AOculusXRSceneActor_NoRegister()
{
	return AOculusXRSceneActor::StaticClass();
}
struct Z_Construct_UClass_AOculusXRSceneActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ClassGroupNames", "OculusXRScene" },
		{ "Comment", "/**\n * AOculusXRSceneActor\n *\n * DEPRECATED: AOculusXRSceneActor and associated classes are deprecated (v65), please use MR Utility Kit instead\n * (https://developer.oculus.com/documentation/unreal/unreal-mr-utility-kit-overview)\n *\n * The purpose of this actor is to be able to spawn \"scene anchor\" actors.\n *\n * Each actor type (based on their semantic label) can be configured to be spawned with a specific mesh and actor component.\n *\n * Overall, it provides a simple interface to be able to quickly get a captured scene from Capture Flow populated at runtime.\n * It also provides a basic and flexible template to making use of the OculusAnchorSDK and UOculusXRRoomLayoutManagerComponent\n * to drive the actor's logic.  This removes the need for the developer to implement a system from scratch that makes use of\n * the native methods and components.\n *\n * TLDR:\n * - This actor populates a captured scene (created in Capture Flow) by spawning child actors with predefined actor and mesh components.\n * - Can be used as is, or can be derived or modified as needed depending on the application's needs.\n */" },
		{ "IncludePath", "OculusXRSceneActor.h" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "AOculusXRSceneActor\n\nDEPRECATED: AOculusXRSceneActor and associated classes are deprecated (v65), please use MR Utility Kit instead\n(https://developer.oculus.com/documentation/unreal/unreal-mr-utility-kit-overview)\n\nThe purpose of this actor is to be able to spawn \"scene anchor\" actors.\n\nEach actor type (based on their semantic label) can be configured to be spawned with a specific mesh and actor component.\n\nOverall, it provides a simple interface to be able to quickly get a captured scene from Capture Flow populated at runtime.\nIt also provides a basic and flexible template to making use of the OculusAnchorSDK and UOculusXRRoomLayoutManagerComponent\nto drive the actor's logic.  This removes the need for the developer to implement a system from scratch that makes use of\nthe native methods and components.\n\nTLDR:\n- This actor populates a captured scene (created in Capture Flow) by spawning child actors with predefined actor and mesh components.\n- Can be used as is, or can be derived or modified as needed depending on the application's needs." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LauchCaptureFlowWhenMissingScene_MetaData[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxQueries_MetaData[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "ClampMax", "1024" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
		{ "UIMax", "1024" },
		{ "UIMin", "1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPopulateSceneOnBeginPlay_MetaData[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bActiveRoomOnly_MetaData[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "Comment", "// If true then when the scene model is loaded we will only attempt to populate the room the user is standing in.\n// Otherwise all rooms and all scene anchors will be loaded.\n" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
		{ "ToolTip", "If true then when the scene model is loaded we will only attempt to populate the room the user is standing in.\nOtherwise all rooms and all scene anchors will be loaded." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScenePlaneSpawnedSceneAnchorProperties_MetaData[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneVolumeSpawnedSceneAnchorProperties_MetaData[] = {
		{ "Category", "OculusXR|Scene Actor" },
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomLayouts_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRSceneActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_LauchCaptureFlowWhenMissingScene;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxQueries;
	static void NewProp_bPopulateSceneOnBeginPlay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPopulateSceneOnBeginPlay;
	static void NewProp_bActiveRoomOnly_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bActiveRoomOnly;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ScenePlaneSpawnedSceneAnchorProperties_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ScenePlaneSpawnedSceneAnchorProperties_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ScenePlaneSpawnedSceneAnchorProperties;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SceneVolumeSpawnedSceneAnchorProperties_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SceneVolumeSpawnedSceneAnchorProperties_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_SceneVolumeSpawnedSceneAnchorProperties;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoomLayouts_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoomLayouts_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_RoomLayouts;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AOculusXRSceneActor_ClearScene, "ClearScene" }, // 2167589153
		{ &Z_Construct_UFunction_AOculusXRSceneActor_GetActorsBySemanticLabel, "GetActorsBySemanticLabel" }, // 1011445447
		{ &Z_Construct_UFunction_AOculusXRSceneActor_GetRoomLayouts, "GetRoomLayouts" }, // 1878641602
		{ &Z_Construct_UFunction_AOculusXRSceneActor_IsRoomLayoutValid, "IsRoomLayoutValid" }, // 3402458960
		{ &Z_Construct_UFunction_AOculusXRSceneActor_IsScenePopulated, "IsScenePopulated" }, // 1188930239
		{ &Z_Construct_UFunction_AOculusXRSceneActor_LaunchCaptureFlow, "LaunchCaptureFlow" }, // 27303317
		{ &Z_Construct_UFunction_AOculusXRSceneActor_PopulateScene, "PopulateScene" }, // 1791873824
		{ &Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToAllSceneAnchors, "SetVisibilityToAllSceneAnchors" }, // 4183605602
		{ &Z_Construct_UFunction_AOculusXRSceneActor_SetVisibilityToSceneAnchorsBySemanticLabel, "SetVisibilityToSceneAnchorsBySemanticLabel" }, // 1436898146
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOculusXRSceneActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_LauchCaptureFlowWhenMissingScene = { "LauchCaptureFlowWhenMissingScene", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRSceneActor, LauchCaptureFlowWhenMissingScene), Z_Construct_UEnum_OculusXRScene_EOculusXRLaunchCaptureFlowWhenMissingScene, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LauchCaptureFlowWhenMissingScene_MetaData), NewProp_LauchCaptureFlowWhenMissingScene_MetaData) }; // 3395214585
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_MaxQueries = { "MaxQueries", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRSceneActor, MaxQueries), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxQueries_MetaData), NewProp_MaxQueries_MetaData) };
void Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_bPopulateSceneOnBeginPlay_SetBit(void* Obj)
{
	((AOculusXRSceneActor*)Obj)->bPopulateSceneOnBeginPlay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_bPopulateSceneOnBeginPlay = { "bPopulateSceneOnBeginPlay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AOculusXRSceneActor), &Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_bPopulateSceneOnBeginPlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPopulateSceneOnBeginPlay_MetaData), NewProp_bPopulateSceneOnBeginPlay_MetaData) };
void Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_bActiveRoomOnly_SetBit(void* Obj)
{
	((AOculusXRSceneActor*)Obj)->bActiveRoomOnly = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_bActiveRoomOnly = { "bActiveRoomOnly", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AOculusXRSceneActor), &Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_bActiveRoomOnly_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bActiveRoomOnly_MetaData), NewProp_bActiveRoomOnly_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_ScenePlaneSpawnedSceneAnchorProperties_ValueProp = { "ScenePlaneSpawnedSceneAnchorProperties", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties, METADATA_PARAMS(0, nullptr) }; // 205757215
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_ScenePlaneSpawnedSceneAnchorProperties_Key_KeyProp = { "ScenePlaneSpawnedSceneAnchorProperties_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_ScenePlaneSpawnedSceneAnchorProperties = { "ScenePlaneSpawnedSceneAnchorProperties", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRSceneActor, ScenePlaneSpawnedSceneAnchorProperties), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScenePlaneSpawnedSceneAnchorProperties_MetaData), NewProp_ScenePlaneSpawnedSceneAnchorProperties_MetaData) }; // 205757215
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_SceneVolumeSpawnedSceneAnchorProperties_ValueProp = { "SceneVolumeSpawnedSceneAnchorProperties", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties, METADATA_PARAMS(0, nullptr) }; // 205757215
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_SceneVolumeSpawnedSceneAnchorProperties_Key_KeyProp = { "SceneVolumeSpawnedSceneAnchorProperties_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_SceneVolumeSpawnedSceneAnchorProperties = { "SceneVolumeSpawnedSceneAnchorProperties", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRSceneActor, SceneVolumeSpawnedSceneAnchorProperties), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneVolumeSpawnedSceneAnchorProperties_MetaData), NewProp_SceneVolumeSpawnedSceneAnchorProperties_MetaData) }; // 205757215
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_RoomLayouts_ValueProp = { "RoomLayouts", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FOculusXRRoomLayout, METADATA_PARAMS(0, nullptr) }; // 3375187172
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_RoomLayouts_Key_KeyProp = { "RoomLayouts_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOculusXRUInt64, METADATA_PARAMS(0, nullptr) }; // 2016766802
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_RoomLayouts = { "RoomLayouts", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRSceneActor, RoomLayouts), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomLayouts_MetaData), NewProp_RoomLayouts_MetaData) }; // 2016766802 3375187172
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOculusXRSceneActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_LauchCaptureFlowWhenMissingScene,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_MaxQueries,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_bPopulateSceneOnBeginPlay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_bActiveRoomOnly,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_ScenePlaneSpawnedSceneAnchorProperties_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_ScenePlaneSpawnedSceneAnchorProperties_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_ScenePlaneSpawnedSceneAnchorProperties,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_SceneVolumeSpawnedSceneAnchorProperties_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_SceneVolumeSpawnedSceneAnchorProperties_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_SceneVolumeSpawnedSceneAnchorProperties,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_RoomLayouts_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_RoomLayouts_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRSceneActor_Statics::NewProp_RoomLayouts,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOculusXRSceneActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AOculusXRSceneActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRScene,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOculusXRSceneActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AOculusXRSceneActor_Statics::ClassParams = {
	&AOculusXRSceneActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AOculusXRSceneActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AOculusXRSceneActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOculusXRSceneActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AOculusXRSceneActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AOculusXRSceneActor()
{
	if (!Z_Registration_Info_UClass_AOculusXRSceneActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOculusXRSceneActor.OuterSingleton, Z_Construct_UClass_AOculusXRSceneActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AOculusXRSceneActor.OuterSingleton;
}
template<> OCULUSXRSCENE_API UClass* StaticClass<AOculusXRSceneActor>()
{
	return AOculusXRSceneActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AOculusXRSceneActor);
AOculusXRSceneActor::~AOculusXRSceneActor() {}
// End Class AOculusXRSceneActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOculusXRLaunchCaptureFlowWhenMissingScene_StaticEnum, TEXT("EOculusXRLaunchCaptureFlowWhenMissingScene"), &Z_Registration_Info_UEnum_EOculusXRLaunchCaptureFlowWhenMissingScene, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3395214585U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOculusXRSpawnedSceneAnchorProperties::StaticStruct, Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics::NewStructOps, TEXT("OculusXRSpawnedSceneAnchorProperties"), &Z_Registration_Info_UScriptStruct_OculusXRSpawnedSceneAnchorProperties, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOculusXRSpawnedSceneAnchorProperties), 205757215U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AOculusXRSceneActor, AOculusXRSceneActor::StaticClass, TEXT("AOculusXRSceneActor"), &Z_Registration_Info_UClass_AOculusXRSceneActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOculusXRSceneActor), 96136163U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_450054365(TEXT("/Script/OculusXRScene"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
