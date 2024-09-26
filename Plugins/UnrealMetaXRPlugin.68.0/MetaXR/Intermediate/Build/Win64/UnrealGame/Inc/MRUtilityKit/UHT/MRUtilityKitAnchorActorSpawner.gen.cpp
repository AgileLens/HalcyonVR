// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MRUtilityKit/Public/MRUtilityKitAnchorActorSpawner.h"
#include "MRUtilityKit/Public/MRUtilityKit.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMRUtilityKitAnchorActorSpawner() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FBox();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRandomStream();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKAnchor_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKAnchorActorSpawner();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKAnchorActorSpawner_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKRoom_NoRegister();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKAlignMode();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerScalingMode();
MRUTILITYKIT_API UEnum* Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode();
MRUTILITYKIT_API UFunction* Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature();
MRUTILITYKIT_API UScriptStruct* Z_Construct_UScriptStruct_FMRUKSpawnActor();
MRUTILITYKIT_API UScriptStruct* Z_Construct_UScriptStruct_FMRUKSpawnGroup();
UPackage* Z_Construct_UPackage__Script_MRUtilityKit();
// End Cross Module References

// Begin Delegate FOnInteriorSpawned
struct Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature_Statics
{
	struct MRUKAnchorActorSpawner_eventOnInteriorSpawned_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventOnInteriorSpawned_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "OnInteriorSpawned__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature_Statics::MRUKAnchorActorSpawner_eventOnInteriorSpawned_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature_Statics::MRUKAnchorActorSpawner_eventOnInteriorSpawned_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void AMRUKAnchorActorSpawner::FOnInteriorSpawned_DelegateWrapper(const FMulticastScriptDelegate& OnInteriorSpawned, AMRUKRoom* Room)
{
	struct MRUKAnchorActorSpawner_eventOnInteriorSpawned_Parms
	{
		AMRUKRoom* Room;
	};
	MRUKAnchorActorSpawner_eventOnInteriorSpawned_Parms Parms;
	Parms.Room=Room;
	OnInteriorSpawned.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnInteriorSpawned

// Begin Class AMRUKAnchorActorSpawner Function AttachAndFitActorToAnchor
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics
{
	struct MRUKAnchorActorSpawner_eventAttachAndFitActorToAnchor_Parms
	{
		AMRUKAnchor* Anchor;
		AActor* Actor;
		EMRUKSpawnerScalingMode ScalingMode;
		EMRUKAlignMode AlignMode;
		bool bCalculateFacingDirection;
		bool bMatchAspectRatio;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Orient and scale the given actor to the anchors plane or volume bounds.\n\x09 * @param Anchor The anchor\n\x09 * @param Actor The actor which should be oriented and scaled to the given anchor.\n\x09 * @param ScalingMode The scaling mode that should be used when doing the matching.\n\x09 * @param bCalculateFacingDirection Whether or not the facing direction of the anchor should be calculated and used for the orientation process.\n\x09 * @param bMatchAspectRatio Whether or not the aspect ratio of the anchor should be matched.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Orient and scale the given actor to the anchors plane or volume bounds.\n@param Anchor The anchor\n@param Actor The actor which should be oriented and scaled to the given anchor.\n@param ScalingMode The scaling mode that should be used when doing the matching.\n@param bCalculateFacingDirection Whether or not the facing direction of the anchor should be calculated and used for the orientation process.\n@param bMatchAspectRatio Whether or not the aspect ratio of the anchor should be matched." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ScalingMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ScalingMode;
	static const UECodeGen_Private::FBytePropertyParams NewProp_AlignMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AlignMode;
	static void NewProp_bCalculateFacingDirection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCalculateFacingDirection;
	static void NewProp_bMatchAspectRatio_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bMatchAspectRatio;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventAttachAndFitActorToAnchor_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventAttachAndFitActorToAnchor_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_ScalingMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_ScalingMode = { "ScalingMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventAttachAndFitActorToAnchor_Parms, ScalingMode), Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnerScalingMode, METADATA_PARAMS(0, nullptr) }; // 3830693870
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_AlignMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_AlignMode = { "AlignMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventAttachAndFitActorToAnchor_Parms, AlignMode), Z_Construct_UEnum_MRUtilityKit_EMRUKAlignMode, METADATA_PARAMS(0, nullptr) }; // 3594544252
void Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_bCalculateFacingDirection_SetBit(void* Obj)
{
	((MRUKAnchorActorSpawner_eventAttachAndFitActorToAnchor_Parms*)Obj)->bCalculateFacingDirection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_bCalculateFacingDirection = { "bCalculateFacingDirection", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUKAnchorActorSpawner_eventAttachAndFitActorToAnchor_Parms), &Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_bCalculateFacingDirection_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_bMatchAspectRatio_SetBit(void* Obj)
{
	((MRUKAnchorActorSpawner_eventAttachAndFitActorToAnchor_Parms*)Obj)->bMatchAspectRatio = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_bMatchAspectRatio = { "bMatchAspectRatio", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUKAnchorActorSpawner_eventAttachAndFitActorToAnchor_Parms), &Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_bMatchAspectRatio_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_ScalingMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_ScalingMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_AlignMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_AlignMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_bCalculateFacingDirection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::NewProp_bMatchAspectRatio,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "AttachAndFitActorToAnchor", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::MRUKAnchorActorSpawner_eventAttachAndFitActorToAnchor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::MRUKAnchorActorSpawner_eventAttachAndFitActorToAnchor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execAttachAndFitActorToAnchor)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_GET_OBJECT(AActor,Z_Param_Actor);
	P_GET_ENUM(EMRUKSpawnerScalingMode,Z_Param_ScalingMode);
	P_GET_ENUM(EMRUKAlignMode,Z_Param_AlignMode);
	P_GET_UBOOL(Z_Param_bCalculateFacingDirection);
	P_GET_UBOOL(Z_Param_bMatchAspectRatio);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AttachAndFitActorToAnchor(Z_Param_Anchor,Z_Param_Actor,EMRUKSpawnerScalingMode(Z_Param_ScalingMode),EMRUKAlignMode(Z_Param_AlignMode),Z_Param_bCalculateFacingDirection,Z_Param_bMatchAspectRatio);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function AttachAndFitActorToAnchor

// Begin Class AMRUKAnchorActorSpawner Function ComputeCustomAlign
struct MRUKAnchorActorSpawner_eventComputeCustomAlign_Parms
{
	AMRUKAnchor* Anchor;
	AActor* Actor;
	FBox ChildBounds;
	FVector Scale;
	FVector ReturnValue;

	/** Constructor, initializes return property only **/
	MRUKAnchorActorSpawner_eventComputeCustomAlign_Parms()
		: ReturnValue(ForceInit)
	{
	}
};
static FName NAME_AMRUKAnchorActorSpawner_ComputeCustomAlign = FName(TEXT("ComputeCustomAlign"));
FVector AMRUKAnchorActorSpawner::ComputeCustomAlign(AMRUKAnchor* Anchor, AActor* Actor, FBox const& ChildBounds, FVector const& Scale)
{
	MRUKAnchorActorSpawner_eventComputeCustomAlign_Parms Parms;
	Parms.Anchor=Anchor;
	Parms.Actor=Actor;
	Parms.ChildBounds=ChildBounds;
	Parms.Scale=Scale;
	ProcessEvent(FindFunctionChecked(NAME_AMRUKAnchorActorSpawner_ComputeCustomAlign),&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Override this method to inject custom scaling logic into the orientation process of an actor. The scale that this method returns\n\x09 * gets used to scale the actor that will be spawned.\n\x09 * @param Anchor The anchor for which the actor gets spawned.\n\x09 * @param Actor The actor that gets spawned.\n\x09 * @param ChildBounds the rotated bounding box of the actor that should be spawned. For planes only X and Y components are relevant.\n\x09 * @param Scale The scale that will be applied to the actor that will be spawned in place of the anchor. For planes only X and Y components are relevant.\n\x09 * @return The offset that should be applied to the actor. In case it's a plane anchor only the X and Y component are relevant.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Override this method to inject custom scaling logic into the orientation process of an actor. The scale that this method returns\ngets used to scale the actor that will be spawned.\n@param Anchor The anchor for which the actor gets spawned.\n@param Actor The actor that gets spawned.\n@param ChildBounds the rotated bounding box of the actor that should be spawned. For planes only X and Y components are relevant.\n@param Scale The scale that will be applied to the actor that will be spawned in place of the anchor. For planes only X and Y components are relevant.\n@return The offset that should be applied to the actor. In case it's a plane anchor only the X and Y component are relevant." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChildBounds_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scale_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ChildBounds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Scale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventComputeCustomAlign_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventComputeCustomAlign_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::NewProp_ChildBounds = { "ChildBounds", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventComputeCustomAlign_Parms, ChildBounds), Z_Construct_UScriptStruct_FBox, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChildBounds_MetaData), NewProp_ChildBounds_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventComputeCustomAlign_Parms, Scale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scale_MetaData), NewProp_Scale_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventComputeCustomAlign_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::NewProp_ChildBounds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "ComputeCustomAlign", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::PropPointers), sizeof(MRUKAnchorActorSpawner_eventComputeCustomAlign_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC80C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::Function_MetaDataParams) };
static_assert(sizeof(MRUKAnchorActorSpawner_eventComputeCustomAlign_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execComputeCustomAlign)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_GET_OBJECT(AActor,Z_Param_Actor);
	P_GET_STRUCT_REF(FBox,Z_Param_Out_ChildBounds);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Scale);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->ComputeCustomAlign_Implementation(Z_Param_Anchor,Z_Param_Actor,Z_Param_Out_ChildBounds,Z_Param_Out_Scale);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function ComputeCustomAlign

// Begin Class AMRUKAnchorActorSpawner Function ComputeCustomScaling
struct MRUKAnchorActorSpawner_eventComputeCustomScaling_Parms
{
	AMRUKAnchor* Anchor;
	AActor* SpawnedActor;
	FVector StretchedScale;
	FVector ReturnValue;

	/** Constructor, initializes return property only **/
	MRUKAnchorActorSpawner_eventComputeCustomScaling_Parms()
		: ReturnValue(ForceInit)
	{
	}
};
static FName NAME_AMRUKAnchorActorSpawner_ComputeCustomScaling = FName(TEXT("ComputeCustomScaling"));
FVector AMRUKAnchorActorSpawner::ComputeCustomScaling(AMRUKAnchor* Anchor, AActor* SpawnedActor, FVector const& StretchedScale)
{
	MRUKAnchorActorSpawner_eventComputeCustomScaling_Parms Parms;
	Parms.Anchor=Anchor;
	Parms.SpawnedActor=SpawnedActor;
	Parms.StretchedScale=StretchedScale;
	ProcessEvent(FindFunctionChecked(NAME_AMRUKAnchorActorSpawner_ComputeCustomScaling),&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Override this method to inject custom scaling logic into the orientation process of an actor. The scale that this method returns\n\x09 * gets used to scale the actor that will be spawned.\n\x09 * @param Anchor The anchor for which the actor gets spawned.\n\x09 * @param SpawnedActor The actor that gets spawned.\n\x09 * @param StretchedScale The scale that would need to be applied to the actor to make it match with the bounding box of the anchor.\n\x09 *                       In case it's a plane anchor only the X and Y component of the scale are relevant.\n\x09 * @return The scale that should be applied to the actor. In case it's a plane anchor only the X and Y component are relevant.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Override this method to inject custom scaling logic into the orientation process of an actor. The scale that this method returns\ngets used to scale the actor that will be spawned.\n@param Anchor The anchor for which the actor gets spawned.\n@param SpawnedActor The actor that gets spawned.\n@param StretchedScale The scale that would need to be applied to the actor to make it match with the bounding box of the anchor.\n                      In case it's a plane anchor only the X and Y component of the scale are relevant.\n@return The scale that should be applied to the actor. In case it's a plane anchor only the X and Y component are relevant." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StretchedScale_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StretchedScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventComputeCustomScaling_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::NewProp_SpawnedActor = { "SpawnedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventComputeCustomScaling_Parms, SpawnedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::NewProp_StretchedScale = { "StretchedScale", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventComputeCustomScaling_Parms, StretchedScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StretchedScale_MetaData), NewProp_StretchedScale_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventComputeCustomScaling_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::NewProp_SpawnedActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::NewProp_StretchedScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "ComputeCustomScaling", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::PropPointers), sizeof(MRUKAnchorActorSpawner_eventComputeCustomScaling_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC80C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::Function_MetaDataParams) };
static_assert(sizeof(MRUKAnchorActorSpawner_eventComputeCustomScaling_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execComputeCustomScaling)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_GET_OBJECT(AActor,Z_Param_SpawnedActor);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_StretchedScale);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=P_THIS->ComputeCustomScaling_Implementation(Z_Param_Anchor,Z_Param_SpawnedActor,Z_Param_Out_StretchedScale);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function ComputeCustomScaling

// Begin Class AMRUKAnchorActorSpawner Function GetSpawnedActors
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics
{
	struct MRUKAnchorActorSpawner_eventGetSpawnedActors_Parms
	{
		TArray<AActor*> Actors;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Return all spawned actors from all rooms.\n\x09 * @param Actors The spawned actors.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Return all spawned actors from all rooms.\n@param Actors The spawned actors." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Actors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics::NewProp_Actors_Inner = { "Actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics::NewProp_Actors = { "Actors", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventGetSpawnedActors_Parms, Actors), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics::NewProp_Actors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics::NewProp_Actors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "GetSpawnedActors", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics::MRUKAnchorActorSpawner_eventGetSpawnedActors_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics::MRUKAnchorActorSpawner_eventGetSpawnedActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execGetSpawnedActors)
{
	P_GET_TARRAY_REF(AActor*,Z_Param_Out_Actors);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GetSpawnedActors(Z_Param_Out_Actors);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function GetSpawnedActors

// Begin Class AMRUKAnchorActorSpawner Function GetSpawnedActorsByRoom
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics
{
	struct MRUKAnchorActorSpawner_eventGetSpawnedActorsByRoom_Parms
	{
		AMRUKRoom* Room;
		TArray<AActor*> Actors;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Return all spawned actors from the give room.\n\x09 * @param Room The room from which the actors should be returned\n\x09 * @param Actors The spawned actors.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Return all spawned actors from the give room.\n@param Room The room from which the actors should be returned\n@param Actors The spawned actors." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Actors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventGetSpawnedActorsByRoom_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::NewProp_Actors_Inner = { "Actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::NewProp_Actors = { "Actors", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventGetSpawnedActorsByRoom_Parms, Actors), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::NewProp_Room,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::NewProp_Actors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::NewProp_Actors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "GetSpawnedActorsByRoom", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::MRUKAnchorActorSpawner_eventGetSpawnedActorsByRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::MRUKAnchorActorSpawner_eventGetSpawnedActorsByRoom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execGetSpawnedActorsByRoom)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_GET_TARRAY_REF(AActor*,Z_Param_Out_Actors);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->GetSpawnedActorsByRoom(Z_Param_Room,Z_Param_Out_Actors);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function GetSpawnedActorsByRoom

// Begin Class AMRUKAnchorActorSpawner Function OnRoomCreated
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated_Statics
{
	struct MRUKAnchorActorSpawner_eventOnRoomCreated_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventOnRoomCreated_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "OnRoomCreated", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated_Statics::MRUKAnchorActorSpawner_eventOnRoomCreated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated_Statics::MRUKAnchorActorSpawner_eventOnRoomCreated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execOnRoomCreated)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRoomCreated(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function OnRoomCreated

// Begin Class AMRUKAnchorActorSpawner Function OnRoomRemoved
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved_Statics
{
	struct MRUKAnchorActorSpawner_eventOnRoomRemoved_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventOnRoomRemoved_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "OnRoomRemoved", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved_Statics::MRUKAnchorActorSpawner_eventOnRoomRemoved_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved_Statics::MRUKAnchorActorSpawner_eventOnRoomRemoved_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execOnRoomRemoved)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRoomRemoved(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function OnRoomRemoved

// Begin Class AMRUKAnchorActorSpawner Function OnRoomUpdated
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated_Statics
{
	struct MRUKAnchorActorSpawner_eventOnRoomUpdated_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventOnRoomUpdated_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "OnRoomUpdated", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated_Statics::MRUKAnchorActorSpawner_eventOnRoomUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated_Statics::MRUKAnchorActorSpawner_eventOnRoomUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execOnRoomUpdated)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRoomUpdated(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function OnRoomUpdated

// Begin Class AMRUKAnchorActorSpawner Function RemoveActors
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors_Statics
{
	struct MRUKAnchorActorSpawner_eventRemoveActors_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventRemoveActors_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "RemoveActors", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors_Statics::MRUKAnchorActorSpawner_eventRemoveActors_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors_Statics::MRUKAnchorActorSpawner_eventRemoveActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execRemoveActors)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveActors(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function RemoveActors

// Begin Class AMRUKAnchorActorSpawner Function SelectSpawnActorClosestSize
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics
{
	struct MRUKAnchorActorSpawner_eventSelectSpawnActorClosestSize_Parms
	{
		AMRUKAnchor* Anchor;
		FMRUKSpawnGroup SpawnGroup;
		FMRUKSpawnActor OutSpawnActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Select the SpawnActor based on the size that matches best the anchor bounds.\n\x09 * @param Anchor The anchor for which a actor should be spawned.\n\x09 * @param SpawnGroup The spawn group.\n\x09 * @param OutSpawnActor The found spawn actor.\n\x09 * @return True if a SpawnActor could be found. Otherwise, false.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Select the SpawnActor based on the size that matches best the anchor bounds.\n@param Anchor The anchor for which a actor should be spawned.\n@param SpawnGroup The spawn group.\n@param OutSpawnActor The found spawn actor.\n@return True if a SpawnActor could be found. Otherwise, false." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnGroup;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutSpawnActor;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSelectSpawnActorClosestSize_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::NewProp_SpawnGroup = { "SpawnGroup", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSelectSpawnActorClosestSize_Parms, SpawnGroup), Z_Construct_UScriptStruct_FMRUKSpawnGroup, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnGroup_MetaData), NewProp_SpawnGroup_MetaData) }; // 2478180099
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::NewProp_OutSpawnActor = { "OutSpawnActor", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSelectSpawnActorClosestSize_Parms, OutSpawnActor), Z_Construct_UScriptStruct_FMRUKSpawnActor, METADATA_PARAMS(0, nullptr) }; // 2323401766
void Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MRUKAnchorActorSpawner_eventSelectSpawnActorClosestSize_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUKAnchorActorSpawner_eventSelectSpawnActorClosestSize_Parms), &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::NewProp_SpawnGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::NewProp_OutSpawnActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "SelectSpawnActorClosestSize", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::MRUKAnchorActorSpawner_eventSelectSpawnActorClosestSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::MRUKAnchorActorSpawner_eventSelectSpawnActorClosestSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execSelectSpawnActorClosestSize)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_GET_STRUCT_REF(FMRUKSpawnGroup,Z_Param_Out_SpawnGroup);
	P_GET_STRUCT_REF(FMRUKSpawnActor,Z_Param_Out_OutSpawnActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SelectSpawnActorClosestSize(Z_Param_Anchor,Z_Param_Out_SpawnGroup,Z_Param_Out_OutSpawnActor);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function SelectSpawnActorClosestSize

// Begin Class AMRUKAnchorActorSpawner Function SelectSpawnActorCustom
struct MRUKAnchorActorSpawner_eventSelectSpawnActorCustom_Parms
{
	AMRUKAnchor* Anchor;
	FMRUKSpawnGroup SpawnGroup;
	FRandomStream RandomStream;
	FMRUKSpawnActor OutSpawnActor;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	MRUKAnchorActorSpawner_eventSelectSpawnActorCustom_Parms()
		: ReturnValue(false)
	{
	}
};
static FName NAME_AMRUKAnchorActorSpawner_SelectSpawnActorCustom = FName(TEXT("SelectSpawnActorCustom"));
bool AMRUKAnchorActorSpawner::SelectSpawnActorCustom(AMRUKAnchor* Anchor, FMRUKSpawnGroup const& SpawnGroup, FRandomStream const& RandomStream, FMRUKSpawnActor& OutSpawnActor)
{
	MRUKAnchorActorSpawner_eventSelectSpawnActorCustom_Parms Parms;
	Parms.Anchor=Anchor;
	Parms.SpawnGroup=SpawnGroup;
	Parms.RandomStream=RandomStream;
	Parms.OutSpawnActor=OutSpawnActor;
	ProcessEvent(FindFunctionChecked(NAME_AMRUKAnchorActorSpawner_SelectSpawnActorCustom),&Parms);
	OutSpawnActor=Parms.OutSpawnActor;
	return !!Parms.ReturnValue;
}
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Override this method to inject custom actor selection logic. This will be called for every actor that gets spawned by the AMRUKAnchorActorSpawner.\n\x09 * @param Anchor The anchor for which a actor should be spawned\n\x09 * @param SpawnGroup The group of actors that can be used for decision making.\n\x09 * @param RandomStream A random stream to randomize outputs if necessary.\n\x09 * @param OutSpawnActor The actor which should be spawned.\n\x09 * @return Whether the selection process was successful or not.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Override this method to inject custom actor selection logic. This will be called for every actor that gets spawned by the AMRUKAnchorActorSpawner.\n@param Anchor The anchor for which a actor should be spawned\n@param SpawnGroup The group of actors that can be used for decision making.\n@param RandomStream A random stream to randomize outputs if necessary.\n@param OutSpawnActor The actor which should be spawned.\n@return Whether the selection process was successful or not." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomStream_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnGroup;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomStream;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutSpawnActor;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSelectSpawnActorCustom_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::NewProp_SpawnGroup = { "SpawnGroup", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSelectSpawnActorCustom_Parms, SpawnGroup), Z_Construct_UScriptStruct_FMRUKSpawnGroup, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnGroup_MetaData), NewProp_SpawnGroup_MetaData) }; // 2478180099
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::NewProp_RandomStream = { "RandomStream", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSelectSpawnActorCustom_Parms, RandomStream), Z_Construct_UScriptStruct_FRandomStream, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomStream_MetaData), NewProp_RandomStream_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::NewProp_OutSpawnActor = { "OutSpawnActor", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSelectSpawnActorCustom_Parms, OutSpawnActor), Z_Construct_UScriptStruct_FMRUKSpawnActor, METADATA_PARAMS(0, nullptr) }; // 2323401766
void Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MRUKAnchorActorSpawner_eventSelectSpawnActorCustom_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUKAnchorActorSpawner_eventSelectSpawnActorCustom_Parms), &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::NewProp_SpawnGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::NewProp_RandomStream,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::NewProp_OutSpawnActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "SelectSpawnActorCustom", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::PropPointers), sizeof(MRUKAnchorActorSpawner_eventSelectSpawnActorCustom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC80C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::Function_MetaDataParams) };
static_assert(sizeof(MRUKAnchorActorSpawner_eventSelectSpawnActorCustom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execSelectSpawnActorCustom)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_GET_STRUCT_REF(FMRUKSpawnGroup,Z_Param_Out_SpawnGroup);
	P_GET_STRUCT_REF(FRandomStream,Z_Param_Out_RandomStream);
	P_GET_STRUCT_REF(FMRUKSpawnActor,Z_Param_Out_OutSpawnActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SelectSpawnActorCustom_Implementation(Z_Param_Anchor,Z_Param_Out_SpawnGroup,Z_Param_Out_RandomStream,Z_Param_Out_OutSpawnActor);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function SelectSpawnActorCustom

// Begin Class AMRUKAnchorActorSpawner Function SelectSpawnActorFromSpawnGroup
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics
{
	struct MRUKAnchorActorSpawner_eventSelectSpawnActorFromSpawnGroup_Parms
	{
		AMRUKAnchor* Anchor;
		FMRUKSpawnGroup SpawnGroup;
		FRandomStream RandomStream;
		FMRUKSpawnActor OutSpawnActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Select a SpawnActor from the SpawnGroup with respect to the given selection mode in SpawnGroup.\n\x09 * @param Anchor The anchor for which the actor should be spawned.\n\x09 * @param SpawnGroup The spawn group.\n\x09 * @param RandomStream The random stream\n\x09 * @param OutSpawnActor The found spawn actor\n\x09 * @return True if a spawn actor has been found. Otherwise, false.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Select a SpawnActor from the SpawnGroup with respect to the given selection mode in SpawnGroup.\n@param Anchor The anchor for which the actor should be spawned.\n@param SpawnGroup The spawn group.\n@param RandomStream The random stream\n@param OutSpawnActor The found spawn actor\n@return True if a spawn actor has been found. Otherwise, false." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomStream_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnGroup;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomStream;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutSpawnActor;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSelectSpawnActorFromSpawnGroup_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::NewProp_SpawnGroup = { "SpawnGroup", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSelectSpawnActorFromSpawnGroup_Parms, SpawnGroup), Z_Construct_UScriptStruct_FMRUKSpawnGroup, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnGroup_MetaData), NewProp_SpawnGroup_MetaData) }; // 2478180099
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::NewProp_RandomStream = { "RandomStream", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSelectSpawnActorFromSpawnGroup_Parms, RandomStream), Z_Construct_UScriptStruct_FRandomStream, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomStream_MetaData), NewProp_RandomStream_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::NewProp_OutSpawnActor = { "OutSpawnActor", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSelectSpawnActorFromSpawnGroup_Parms, OutSpawnActor), Z_Construct_UScriptStruct_FMRUKSpawnActor, METADATA_PARAMS(0, nullptr) }; // 2323401766
void Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MRUKAnchorActorSpawner_eventSelectSpawnActorFromSpawnGroup_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUKAnchorActorSpawner_eventSelectSpawnActorFromSpawnGroup_Parms), &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::NewProp_SpawnGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::NewProp_RandomStream,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::NewProp_OutSpawnActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "SelectSpawnActorFromSpawnGroup", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::MRUKAnchorActorSpawner_eventSelectSpawnActorFromSpawnGroup_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C80401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::MRUKAnchorActorSpawner_eventSelectSpawnActorFromSpawnGroup_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execSelectSpawnActorFromSpawnGroup)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_GET_STRUCT_REF(FMRUKSpawnGroup,Z_Param_Out_SpawnGroup);
	P_GET_STRUCT_REF(FRandomStream,Z_Param_Out_RandomStream);
	P_GET_STRUCT_REF(FMRUKSpawnActor,Z_Param_Out_OutSpawnActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SelectSpawnActorFromSpawnGroup(Z_Param_Anchor,Z_Param_Out_SpawnGroup,Z_Param_Out_RandomStream,Z_Param_Out_OutSpawnActor);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function SelectSpawnActorFromSpawnGroup

// Begin Class AMRUKAnchorActorSpawner Function SelectSpawnActorRandom
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics
{
	struct MRUKAnchorActorSpawner_eventSelectSpawnActorRandom_Parms
	{
		FMRUKSpawnGroup SpawnGroup;
		FRandomStream RandomStream;
		FMRUKSpawnActor OutSpawnActor;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Select the SpawnActor randomly\n\x09 * @param SpawnGroup The spawn group.\n\x09 * @param RandomStream The random stream to use for the random selection.\n\x09 * @param OutSpawnActor The found spawn actor.\n\x09 * @return True if a SpawnActor could be found. Otherwise, false.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Select the SpawnActor randomly\n@param SpawnGroup The spawn group.\n@param RandomStream The random stream to use for the random selection.\n@param OutSpawnActor The found spawn actor.\n@return True if a SpawnActor could be found. Otherwise, false." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomStream_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnGroup;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomStream;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutSpawnActor;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::NewProp_SpawnGroup = { "SpawnGroup", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSelectSpawnActorRandom_Parms, SpawnGroup), Z_Construct_UScriptStruct_FMRUKSpawnGroup, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnGroup_MetaData), NewProp_SpawnGroup_MetaData) }; // 2478180099
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::NewProp_RandomStream = { "RandomStream", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSelectSpawnActorRandom_Parms, RandomStream), Z_Construct_UScriptStruct_FRandomStream, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomStream_MetaData), NewProp_RandomStream_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::NewProp_OutSpawnActor = { "OutSpawnActor", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSelectSpawnActorRandom_Parms, OutSpawnActor), Z_Construct_UScriptStruct_FMRUKSpawnActor, METADATA_PARAMS(0, nullptr) }; // 2323401766
void Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MRUKAnchorActorSpawner_eventSelectSpawnActorRandom_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUKAnchorActorSpawner_eventSelectSpawnActorRandom_Parms), &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::NewProp_SpawnGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::NewProp_RandomStream,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::NewProp_OutSpawnActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "SelectSpawnActorRandom", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::MRUKAnchorActorSpawner_eventSelectSpawnActorRandom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C80401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::MRUKAnchorActorSpawner_eventSelectSpawnActorRandom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execSelectSpawnActorRandom)
{
	P_GET_STRUCT_REF(FMRUKSpawnGroup,Z_Param_Out_SpawnGroup);
	P_GET_STRUCT_REF(FRandomStream,Z_Param_Out_RandomStream);
	P_GET_STRUCT_REF(FMRUKSpawnActor,Z_Param_Out_OutSpawnActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SelectSpawnActorRandom(Z_Param_Out_SpawnGroup,Z_Param_Out_RandomStream,Z_Param_Out_OutSpawnActor);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function SelectSpawnActorRandom

// Begin Class AMRUKAnchorActorSpawner Function ShouldAnchorFallbackToProceduralMesh
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics
{
	struct MRUKAnchorActorSpawner_eventShouldAnchorFallbackToProceduralMesh_Parms
	{
		FMRUKSpawnGroup SpawnGroup;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Check if for the given SpawnGroup a procedural mesh should be spawned.\n\x09 * @param SpawnGroup The spawn group to check\n\x09 * @return Whether a procedural mesh should be spawned or not\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Check if for the given SpawnGroup a procedural mesh should be spawned.\n@param SpawnGroup The spawn group to check\n@return Whether a procedural mesh should be spawned or not" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnGroup;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::NewProp_SpawnGroup = { "SpawnGroup", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventShouldAnchorFallbackToProceduralMesh_Parms, SpawnGroup), Z_Construct_UScriptStruct_FMRUKSpawnGroup, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnGroup_MetaData), NewProp_SpawnGroup_MetaData) }; // 2478180099
void Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MRUKAnchorActorSpawner_eventShouldAnchorFallbackToProceduralMesh_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUKAnchorActorSpawner_eventShouldAnchorFallbackToProceduralMesh_Parms), &Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::NewProp_SpawnGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "ShouldAnchorFallbackToProceduralMesh", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::MRUKAnchorActorSpawner_eventShouldAnchorFallbackToProceduralMesh_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::MRUKAnchorActorSpawner_eventShouldAnchorFallbackToProceduralMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execShouldAnchorFallbackToProceduralMesh)
{
	P_GET_STRUCT_REF(FMRUKSpawnGroup,Z_Param_Out_SpawnGroup);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ShouldAnchorFallbackToProceduralMesh(Z_Param_Out_SpawnGroup);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function ShouldAnchorFallbackToProceduralMesh

// Begin Class AMRUKAnchorActorSpawner Function ShouldSpawnActorForAnchor
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics
{
	struct MRUKAnchorActorSpawner_eventShouldSpawnActorForAnchor_Parms
	{
		AMRUKAnchor* Anchor;
		FString Label;
		FMRUKSpawnGroup OutSpawnGroup;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Check if there should be spawned a actor for the given label. This function may return false in case\n\x09 * the spawner should fallback to a procedural mesh.\n\x09 * @param Anchor The anchor where the actor should be spawned\n\x09 * @param Label The label of the anchor\n\x09 * @param OutSpawnGroup Will be set in case a actor should be spawned\n\x09 * @return Whether or not a actor should be spawned for the anchor\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Check if there should be spawned a actor for the given label. This function may return false in case\nthe spawner should fallback to a procedural mesh.\n@param Anchor The anchor where the actor should be spawned\n@param Label The label of the anchor\n@param OutSpawnGroup Will be set in case a actor should be spawned\n@return Whether or not a actor should be spawned for the anchor" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Label_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutSpawnGroup;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventShouldSpawnActorForAnchor_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventShouldSpawnActorForAnchor_Parms, Label), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Label_MetaData), NewProp_Label_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::NewProp_OutSpawnGroup = { "OutSpawnGroup", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventShouldSpawnActorForAnchor_Parms, OutSpawnGroup), Z_Construct_UScriptStruct_FMRUKSpawnGroup, METADATA_PARAMS(0, nullptr) }; // 2478180099
void Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MRUKAnchorActorSpawner_eventShouldSpawnActorForAnchor_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUKAnchorActorSpawner_eventShouldSpawnActorForAnchor_Parms), &Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::NewProp_Label,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::NewProp_OutSpawnGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "ShouldSpawnActorForAnchor", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::MRUKAnchorActorSpawner_eventShouldSpawnActorForAnchor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::MRUKAnchorActorSpawner_eventShouldSpawnActorForAnchor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execShouldSpawnActorForAnchor)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_GET_PROPERTY(FStrProperty,Z_Param_Label);
	P_GET_STRUCT_REF(FMRUKSpawnGroup,Z_Param_Out_OutSpawnGroup);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ShouldSpawnActorForAnchor(Z_Param_Anchor,Z_Param_Label,Z_Param_Out_OutSpawnGroup);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function ShouldSpawnActorForAnchor

// Begin Class AMRUKAnchorActorSpawner Function SpawnActors
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors_Statics
{
	struct MRUKAnchorActorSpawner_eventSpawnActors_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Spawns the meshes for the given labels above on the anchor positions in each room.\n\x09 * There might be multiple actor classes for a give label. If thats the case a actor class will be chosen radomly.\n\x09 * The seed for this random generator can be set by AnchorRandomSpawnSeed.\n\x09 * This function will be called automatically after the mixed reality utility kit initialized unless\n\x09 * the option SpawnOnStart is set to false.\n\x09 * If there is no actor class specified for a label then a procedural mesh matching the anchors volume and plane\n\x09 * will be generated.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Spawns the meshes for the given labels above on the anchor positions in each room.\nThere might be multiple actor classes for a give label. If thats the case a actor class will be chosen radomly.\nThe seed for this random generator can be set by AnchorRandomSpawnSeed.\nThis function will be called automatically after the mixed reality utility kit initialized unless\nthe option SpawnOnStart is set to false.\nIf there is no actor class specified for a label then a procedural mesh matching the anchors volume and plane\nwill be generated." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnActors_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "SpawnActors", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors_Statics::MRUKAnchorActorSpawner_eventSpawnActors_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors_Statics::MRUKAnchorActorSpawner_eventSpawnActors_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execSpawnActors)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnActors(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function SpawnActors

// Begin Class AMRUKAnchorActorSpawner Function SpawnAnchorActor
struct MRUKAnchorActorSpawner_eventSpawnAnchorActor_Parms
{
	AMRUKAnchor* Anchor;
	FMRUKSpawnActor SpawnActor;
	AActor* ReturnValue;

	/** Constructor, initializes return property only **/
	MRUKAnchorActorSpawner_eventSpawnAnchorActor_Parms()
		: ReturnValue(NULL)
	{
	}
};
static FName NAME_AMRUKAnchorActorSpawner_SpawnAnchorActor = FName(TEXT("SpawnAnchorActor"));
AActor* AMRUKAnchorActorSpawner::SpawnAnchorActor(AMRUKAnchor* Anchor, FMRUKSpawnActor const& SpawnActor)
{
	MRUKAnchorActorSpawner_eventSpawnAnchorActor_Parms Parms;
	Parms.Anchor=Anchor;
	Parms.SpawnActor=SpawnActor;
	ProcessEvent(FindFunctionChecked(NAME_AMRUKAnchorActorSpawner_SpawnAnchorActor),&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * This method gets called by the default implementation of SpawnAnchorActorForLabel() to spawn the anchor and orient and scale\n\x09 * it correct to the given anchor. If you are planning to implement a custom spawning logic you likely want to use this function\n\x09 * in the end to actually spawn the actor as it takes care of orientation and scaling of the actor with regards to the anchor bounds.\n\x09 * @param Anchor The anchor to spawn the actor for.\n\x09 * @param SpawnActor Information on which actor should be spawned.\n\x09 * @return The spawned actor.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "This method gets called by the default implementation of SpawnAnchorActorForLabel() to spawn the anchor and orient and scale\nit correct to the given anchor. If you are planning to implement a custom spawning logic you likely want to use this function\nin the end to actually spawn the actor as it takes care of orientation and scaling of the actor with regards to the anchor bounds.\n@param Anchor The anchor to spawn the actor for.\n@param SpawnActor Information on which actor should be spawned.\n@return The spawned actor." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnActor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnAnchorActor_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics::NewProp_SpawnActor = { "SpawnActor", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnAnchorActor_Parms, SpawnActor), Z_Construct_UScriptStruct_FMRUKSpawnActor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnActor_MetaData), NewProp_SpawnActor_MetaData) }; // 2323401766
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnAnchorActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics::NewProp_SpawnActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "SpawnAnchorActor", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics::PropPointers), sizeof(MRUKAnchorActorSpawner_eventSpawnAnchorActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C480C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics::Function_MetaDataParams) };
static_assert(sizeof(MRUKAnchorActorSpawner_eventSpawnAnchorActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execSpawnAnchorActor)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_GET_STRUCT_REF(FMRUKSpawnActor,Z_Param_Out_SpawnActor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->SpawnAnchorActor_Implementation(Z_Param_Anchor,Z_Param_Out_SpawnActor);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function SpawnAnchorActor

// Begin Class AMRUKAnchorActorSpawner Function SpawnAnchorActorForLabel
struct MRUKAnchorActorSpawner_eventSpawnAnchorActorForLabel_Parms
{
	AMRUKAnchor* Anchor;
	FString Label;
	FMRUKSpawnGroup SpawnGroup;
	FRandomStream RandomStream;
	AActor* ReturnValue;

	/** Constructor, initializes return property only **/
	MRUKAnchorActorSpawner_eventSpawnAnchorActorForLabel_Parms()
		: ReturnValue(NULL)
	{
	}
};
static FName NAME_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel = FName(TEXT("SpawnAnchorActorForLabel"));
AActor* AMRUKAnchorActorSpawner::SpawnAnchorActorForLabel(AMRUKAnchor* Anchor, const FString& Label, FMRUKSpawnGroup const& SpawnGroup, FRandomStream const& RandomStream)
{
	MRUKAnchorActorSpawner_eventSpawnAnchorActorForLabel_Parms Parms;
	Parms.Anchor=Anchor;
	Parms.Label=Label;
	Parms.SpawnGroup=SpawnGroup;
	Parms.RandomStream=RandomStream;
	ProcessEvent(FindFunctionChecked(NAME_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel),&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * This method gets called by the default implementation of the SpawnAnchorActorsInRoom() for every label that should spawn a actor.\n\x09 * By overwriting this function it is possible to inject custom spawning logic for actors on a per label basis.\n\x09 * When implementing a custom spawning logic you may want to use SpawnAnchorActor() to spawn the actual actor and take care of it's\n\x09 * orientation and scaling to match the anchors bounds.\n\x09 * @param Anchor The anchor to spawn a actor for.\n\x09 * @param Label The label to spawn a actor for.\n\x09 * @param SpawnGroup Information on which actor should be spawned.\n\x09 * @param RandomStream A random stream for implementing the random selection logic.\n\x09 * @return The spawned actor.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "This method gets called by the default implementation of the SpawnAnchorActorsInRoom() for every label that should spawn a actor.\nBy overwriting this function it is possible to inject custom spawning logic for actors on a per label basis.\nWhen implementing a custom spawning logic you may want to use SpawnAnchorActor() to spawn the actual actor and take care of it's\norientation and scaling to match the anchors bounds.\n@param Anchor The anchor to spawn a actor for.\n@param Label The label to spawn a actor for.\n@param SpawnGroup Information on which actor should be spawned.\n@param RandomStream A random stream for implementing the random selection logic.\n@return The spawned actor." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Label_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomStream_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Label;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnGroup;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomStream;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnAnchorActorForLabel_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::NewProp_Label = { "Label", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnAnchorActorForLabel_Parms, Label), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Label_MetaData), NewProp_Label_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::NewProp_SpawnGroup = { "SpawnGroup", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnAnchorActorForLabel_Parms, SpawnGroup), Z_Construct_UScriptStruct_FMRUKSpawnGroup, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnGroup_MetaData), NewProp_SpawnGroup_MetaData) }; // 2478180099
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::NewProp_RandomStream = { "RandomStream", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnAnchorActorForLabel_Parms, RandomStream), Z_Construct_UScriptStruct_FRandomStream, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomStream_MetaData), NewProp_RandomStream_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnAnchorActorForLabel_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::NewProp_Label,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::NewProp_SpawnGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::NewProp_RandomStream,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "SpawnAnchorActorForLabel", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::PropPointers), sizeof(MRUKAnchorActorSpawner_eventSpawnAnchorActorForLabel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0CC80C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::Function_MetaDataParams) };
static_assert(sizeof(MRUKAnchorActorSpawner_eventSpawnAnchorActorForLabel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execSpawnAnchorActorForLabel)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_GET_PROPERTY(FStrProperty,Z_Param_Label);
	P_GET_STRUCT_REF(FMRUKSpawnGroup,Z_Param_Out_SpawnGroup);
	P_GET_STRUCT_REF(FRandomStream,Z_Param_Out_RandomStream);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->SpawnAnchorActorForLabel_Implementation(Z_Param_Anchor,Z_Param_Label,Z_Param_Out_SpawnGroup,Z_Param_Out_RandomStream);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function SpawnAnchorActorForLabel

// Begin Class AMRUKAnchorActorSpawner Function SpawnAnchorActorsInRoom
struct MRUKAnchorActorSpawner_eventSpawnAnchorActorsInRoom_Parms
{
	AMRUKRoom* Room;
	FRandomStream RandomStream;
	TArray<AActor*> ReturnValue;
};
static FName NAME_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom = FName(TEXT("SpawnAnchorActorsInRoom"));
TArray<AActor*> AMRUKAnchorActorSpawner::SpawnAnchorActorsInRoom(AMRUKRoom* Room, FRandomStream const& RandomStream)
{
	MRUKAnchorActorSpawner_eventSpawnAnchorActorsInRoom_Parms Parms;
	Parms.Room=Room;
	Parms.RandomStream=RandomStream;
	ProcessEvent(FindFunctionChecked(NAME_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom),&Parms);
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * This method gets called by the AnchorActorSpawner when it wants to spawn actors and procedural meshes in the room.\n\x09 * It's possible to overwrite this function in Blueprint or C++ to implement custom spawning logic.\n\x09 * The protected methods in the AnchorActorSpawner contain helper functions which can be useful when implementing\n\x09 * a custom spawning logic. When implementing a custom spawning logic you may want to use SpawnAnchorActor() to spawn\n\x09 * the actual actor and take care of it's orientation and scaling to match the anchors bounds.\n\x09 * @param Room The room to spawn actors for.\n\x09 * @param RandomStream A random stream to be used with the random selection mode.\n\x09 * @return A list of all spawned actors.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "This method gets called by the AnchorActorSpawner when it wants to spawn actors and procedural meshes in the room.\nIt's possible to overwrite this function in Blueprint or C++ to implement custom spawning logic.\nThe protected methods in the AnchorActorSpawner contain helper functions which can be useful when implementing\na custom spawning logic. When implementing a custom spawning logic you may want to use SpawnAnchorActor() to spawn\nthe actual actor and take care of it's orientation and scaling to match the anchors bounds.\n@param Room The room to spawn actors for.\n@param RandomStream A random stream to be used with the random selection mode.\n@return A list of all spawned actors." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RandomStream_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RandomStream;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnAnchorActorsInRoom_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::NewProp_RandomStream = { "RandomStream", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnAnchorActorsInRoom_Parms, RandomStream), Z_Construct_UScriptStruct_FRandomStream, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RandomStream_MetaData), NewProp_RandomStream_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnAnchorActorsInRoom_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::NewProp_Room,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::NewProp_RandomStream,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "SpawnAnchorActorsInRoom", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::PropPointers), sizeof(MRUKAnchorActorSpawner_eventSpawnAnchorActorsInRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08C80C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::Function_MetaDataParams) };
static_assert(sizeof(MRUKAnchorActorSpawner_eventSpawnAnchorActorsInRoom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execSpawnAnchorActorsInRoom)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_GET_STRUCT_REF(FRandomStream,Z_Param_Out_RandomStream);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AActor*>*)Z_Param__Result=P_THIS->SpawnAnchorActorsInRoom_Implementation(Z_Param_Room,Z_Param_Out_RandomStream);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function SpawnAnchorActorsInRoom

// Begin Class AMRUKAnchorActorSpawner Function SpawnProceduralMeshesInRoom
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics
{
	struct MRUKAnchorActorSpawner_eventSpawnProceduralMeshesInRoom_Parms
	{
		AMRUKRoom* Room;
		TArray<AActor*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Spawn procedural meshes for every anchor that needs them. Including walls, ceiling and floor.\n\x09 * The method determines if procedural mesh should be spawned or not based on the settings of the\n\x09 * AnchorActorSpawner.\n\x09 * @param Room The room to spawn in.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Spawn procedural meshes for every anchor that needs them. Including walls, ceiling and floor.\nThe method determines if procedural mesh should be spawned or not based on the settings of the\nAnchorActorSpawner.\n@param Room The room to spawn in." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnProceduralMeshesInRoom_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnProceduralMeshesInRoom_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::NewProp_Room,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "SpawnProceduralMeshesInRoom", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::MRUKAnchorActorSpawner_eventSpawnProceduralMeshesInRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::MRUKAnchorActorSpawner_eventSpawnProceduralMeshesInRoom_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execSpawnProceduralMeshesInRoom)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AActor*>*)Z_Param__Result=P_THIS->SpawnProceduralMeshesInRoom(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function SpawnProceduralMeshesInRoom

// Begin Class AMRUKAnchorActorSpawner Function SpawnProceduralMeshesOnWallsIfNoWallActorGiven
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics
{
	struct MRUKAnchorActorSpawner_eventSpawnProceduralMeshesOnWallsIfNoWallActorGiven_Parms
	{
		AMRUKRoom* Room;
		TArray<AActor*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Spawn a procedural mesh for all walls if no wall actor is given to the spawner.\n\x09 * This will take care of generating seamless UVs for the walls.\n\x09 * @param Room The room to spawn in.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Spawn a procedural mesh for all walls if no wall actor is given to the spawner.\nThis will take care of generating seamless UVs for the walls.\n@param Room The room to spawn in." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnProceduralMeshesOnWallsIfNoWallActorGiven_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnProceduralMeshesOnWallsIfNoWallActorGiven_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::NewProp_Room,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "SpawnProceduralMeshesOnWallsIfNoWallActorGiven", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::MRUKAnchorActorSpawner_eventSpawnProceduralMeshesOnWallsIfNoWallActorGiven_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::MRUKAnchorActorSpawner_eventSpawnProceduralMeshesOnWallsIfNoWallActorGiven_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execSpawnProceduralMeshesOnWallsIfNoWallActorGiven)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AActor*>*)Z_Param__Result=P_THIS->SpawnProceduralMeshesOnWallsIfNoWallActorGiven(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function SpawnProceduralMeshesOnWallsIfNoWallActorGiven

// Begin Class AMRUKAnchorActorSpawner Function SpawnProceduralMeshForAnchorIfNeeded
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics
{
	struct MRUKAnchorActorSpawner_eventSpawnProceduralMeshForAnchorIfNeeded_Parms
	{
		AMRUKAnchor* Anchor;
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Spawn a procedural mesh for the given anchor if the settings on the AnchorActorSpawner say so.\n\x09 * @param Anchor The anchor for which the procedural mesh should be spawned\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Spawn a procedural mesh for the given anchor if the settings on the AnchorActorSpawner say so.\n@param Anchor The anchor for which the procedural mesh should be spawned" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnProceduralMeshForAnchorIfNeeded_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnProceduralMeshForAnchorIfNeeded_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "SpawnProceduralMeshForAnchorIfNeeded", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics::MRUKAnchorActorSpawner_eventSpawnProceduralMeshForAnchorIfNeeded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics::MRUKAnchorActorSpawner_eventSpawnProceduralMeshForAnchorIfNeeded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execSpawnProceduralMeshForAnchorIfNeeded)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->SpawnProceduralMeshForAnchorIfNeeded(Z_Param_Anchor);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function SpawnProceduralMeshForAnchorIfNeeded

// Begin Class AMRUKAnchorActorSpawner Function SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics
{
	struct MRUKAnchorActorSpawner_eventSpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Parms
	{
		AMRUKRoom* Room;
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Spawn a procedural mesh for the ceiling if no ceiling actor is given to the spawner.\n\x09 * @param Room The room to spawn in.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Spawn a procedural mesh for the ceiling if no ceiling actor is given to the spawner.\n@param Room The room to spawn in." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics::NewProp_Room,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics::MRUKAnchorActorSpawner_eventSpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics::MRUKAnchorActorSpawner_eventSpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execSpawnProceduralMeshOnCeilingIfNoCeilingActorGiven)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven

// Begin Class AMRUKAnchorActorSpawner Function SpawnProceduralMeshOnFloorIfNoFloorActorGiven
struct Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics
{
	struct MRUKAnchorActorSpawner_eventSpawnProceduralMeshOnFloorIfNoFloorActorGiven_Parms
	{
		AMRUKRoom* Room;
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Spawn a procedural mesh for the floor if no floor actor is given to the spawner.\n\x09 * @param Room The room to spawn in.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Spawn a procedural mesh for the floor if no floor actor is given to the spawner.\n@param Room The room to spawn in." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnProceduralMeshOnFloorIfNoFloorActorGiven_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKAnchorActorSpawner_eventSpawnProceduralMeshOnFloorIfNoFloorActorGiven_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics::NewProp_Room,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKAnchorActorSpawner, nullptr, "SpawnProceduralMeshOnFloorIfNoFloorActorGiven", nullptr, nullptr, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics::MRUKAnchorActorSpawner_eventSpawnProceduralMeshOnFloorIfNoFloorActorGiven_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics::MRUKAnchorActorSpawner_eventSpawnProceduralMeshOnFloorIfNoFloorActorGiven_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKAnchorActorSpawner::execSpawnProceduralMeshOnFloorIfNoFloorActorGiven)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->SpawnProceduralMeshOnFloorIfNoFloorActorGiven(Z_Param_Room);
	P_NATIVE_END;
}
// End Class AMRUKAnchorActorSpawner Function SpawnProceduralMeshOnFloorIfNoFloorActorGiven

// Begin Class AMRUKAnchorActorSpawner
void AMRUKAnchorActorSpawner::StaticRegisterNativesAMRUKAnchorActorSpawner()
{
	UClass* Class = AMRUKAnchorActorSpawner::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AttachAndFitActorToAnchor", &AMRUKAnchorActorSpawner::execAttachAndFitActorToAnchor },
		{ "ComputeCustomAlign", &AMRUKAnchorActorSpawner::execComputeCustomAlign },
		{ "ComputeCustomScaling", &AMRUKAnchorActorSpawner::execComputeCustomScaling },
		{ "GetSpawnedActors", &AMRUKAnchorActorSpawner::execGetSpawnedActors },
		{ "GetSpawnedActorsByRoom", &AMRUKAnchorActorSpawner::execGetSpawnedActorsByRoom },
		{ "OnRoomCreated", &AMRUKAnchorActorSpawner::execOnRoomCreated },
		{ "OnRoomRemoved", &AMRUKAnchorActorSpawner::execOnRoomRemoved },
		{ "OnRoomUpdated", &AMRUKAnchorActorSpawner::execOnRoomUpdated },
		{ "RemoveActors", &AMRUKAnchorActorSpawner::execRemoveActors },
		{ "SelectSpawnActorClosestSize", &AMRUKAnchorActorSpawner::execSelectSpawnActorClosestSize },
		{ "SelectSpawnActorCustom", &AMRUKAnchorActorSpawner::execSelectSpawnActorCustom },
		{ "SelectSpawnActorFromSpawnGroup", &AMRUKAnchorActorSpawner::execSelectSpawnActorFromSpawnGroup },
		{ "SelectSpawnActorRandom", &AMRUKAnchorActorSpawner::execSelectSpawnActorRandom },
		{ "ShouldAnchorFallbackToProceduralMesh", &AMRUKAnchorActorSpawner::execShouldAnchorFallbackToProceduralMesh },
		{ "ShouldSpawnActorForAnchor", &AMRUKAnchorActorSpawner::execShouldSpawnActorForAnchor },
		{ "SpawnActors", &AMRUKAnchorActorSpawner::execSpawnActors },
		{ "SpawnAnchorActor", &AMRUKAnchorActorSpawner::execSpawnAnchorActor },
		{ "SpawnAnchorActorForLabel", &AMRUKAnchorActorSpawner::execSpawnAnchorActorForLabel },
		{ "SpawnAnchorActorsInRoom", &AMRUKAnchorActorSpawner::execSpawnAnchorActorsInRoom },
		{ "SpawnProceduralMeshesInRoom", &AMRUKAnchorActorSpawner::execSpawnProceduralMeshesInRoom },
		{ "SpawnProceduralMeshesOnWallsIfNoWallActorGiven", &AMRUKAnchorActorSpawner::execSpawnProceduralMeshesOnWallsIfNoWallActorGiven },
		{ "SpawnProceduralMeshForAnchorIfNeeded", &AMRUKAnchorActorSpawner::execSpawnProceduralMeshForAnchorIfNeeded },
		{ "SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven", &AMRUKAnchorActorSpawner::execSpawnProceduralMeshOnCeilingIfNoCeilingActorGiven },
		{ "SpawnProceduralMeshOnFloorIfNoFloorActorGiven", &AMRUKAnchorActorSpawner::execSpawnProceduralMeshOnFloorIfNoFloorActorGiven },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMRUKAnchorActorSpawner);
UClass* Z_Construct_UClass_AMRUKAnchorActorSpawner_NoRegister()
{
	return AMRUKAnchorActorSpawner::StaticClass();
}
struct Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ClassGroupNames", "MRUtilityKit" },
		{ "Comment", "/**\n * Spawns meshes on anchor positions.\n * If the out of the box functionality doesn't match your goals the AnchorActorSpawner provides way to inject\n * custom spawning logic into every step of it's spawning process by overwriting certain functions.\n * For this please take a look at SpawnAnchorActorsForRoom(), SpawnAnchorActorForLabel(), and SpawnAnchorActor().\n */" },
		{ "DisplayName", "MR Utility Kit Anchor Actor Spawner" },
		{ "IncludePath", "MRUtilityKitAnchorActorSpawner.h" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Spawns meshes on anchor positions.\nIf the out of the box functionality doesn't match your goals the AnchorActorSpawner provides way to inject\ncustom spawning logic into every step of it's spawning process by overwriting certain functions.\nFor this please take a look at SpawnAnchorActorsForRoom(), SpawnAnchorActorForLabel(), and SpawnAnchorActor()." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnActorsSpawned_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Event that gets fired when the interior spawner finished spawning actors.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Event that gets fired when the interior spawner finished spawning actors." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnchorRandomSpawnSeed_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Seed to use for the random generator that decideds wich actor class to\n\x09 * spawn if there a given multiple for a label.\n\x09 * negative values will have the effect to initialize the random generator\n\x09 * to a random seed.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Seed to use for the random generator that decideds wich actor class to\nspawn if there a given multiple for a label.\nnegative values will have the effect to initialize the random generator\nto a random seed." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnMode_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Whether actors should be spawned automatically after the mixed reality\n\x09 * utility kit has been initialized. This should not be changed after the scene has been loaded.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Whether actors should be spawned automatically after the mixed reality\nutility kit has been initialized. This should not be changed after the scene has been loaded." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProceduralMaterial_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Material to use when falling back to procedural material.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Material to use when falling back to procedural material." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShouldFallbackToProcedural_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Whether or not the spawner should fallback to procedural meshes in case no actor\n\x09 * class has been defined for a label. This behaviour can be overwritten on the label\n\x09 * basis in SpawnGroups.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Whether or not the spawner should fallback to procedural meshes in case no actor\nclass has been defined for a label. This behaviour can be overwritten on the label\nbasis in SpawnGroups." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CutHoleLabels_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Labels for which holes should be created in the parents plane mesh.\n\x09 * E.g. if holes are needed in the walls where the windows and doors are, specify DOOR_FRAME and WINDOW_FRAME.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "Labels for which holes should be created in the parents plane mesh.\nE.g. if holes are needed in the walls where the windows and doors are, specify DOOR_FRAME and WINDOW_FRAME." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnGroups_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * A map of Actor classes to spawn for the given label.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitAnchorActorSpawner.h" },
		{ "ToolTip", "A map of Actor classes to spawn for the given label." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnActorsSpawned;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AnchorRandomSpawnSeed;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SpawnMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SpawnMode;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ProceduralMaterial;
	static void NewProp_ShouldFallbackToProcedural_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ShouldFallbackToProcedural;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CutHoleLabels_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CutHoleLabels;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnGroups_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SpawnGroups_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_SpawnGroups;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_AttachAndFitActorToAnchor, "AttachAndFitActorToAnchor" }, // 2340817585
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomAlign, "ComputeCustomAlign" }, // 2181124801
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_ComputeCustomScaling, "ComputeCustomScaling" }, // 3673417304
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActors, "GetSpawnedActors" }, // 1193341280
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_GetSpawnedActorsByRoom, "GetSpawnedActorsByRoom" }, // 1342535191
		{ &Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature, "OnInteriorSpawned__DelegateSignature" }, // 3158354467
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomCreated, "OnRoomCreated" }, // 2089559097
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomRemoved, "OnRoomRemoved" }, // 1235546957
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_OnRoomUpdated, "OnRoomUpdated" }, // 213957764
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_RemoveActors, "RemoveActors" }, // 1419473802
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorClosestSize, "SelectSpawnActorClosestSize" }, // 2151001575
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorCustom, "SelectSpawnActorCustom" }, // 2191789982
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorFromSpawnGroup, "SelectSpawnActorFromSpawnGroup" }, // 2919362975
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SelectSpawnActorRandom, "SelectSpawnActorRandom" }, // 3585254949
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldAnchorFallbackToProceduralMesh, "ShouldAnchorFallbackToProceduralMesh" }, // 1445582826
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_ShouldSpawnActorForAnchor, "ShouldSpawnActorForAnchor" }, // 2725009967
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnActors, "SpawnActors" }, // 1403224451
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActor, "SpawnAnchorActor" }, // 2214534854
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorForLabel, "SpawnAnchorActorForLabel" }, // 1019120413
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnAnchorActorsInRoom, "SpawnAnchorActorsInRoom" }, // 2191583066
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesInRoom, "SpawnProceduralMeshesInRoom" }, // 1190182086
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshesOnWallsIfNoWallActorGiven, "SpawnProceduralMeshesOnWallsIfNoWallActorGiven" }, // 1683752223
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshForAnchorIfNeeded, "SpawnProceduralMeshForAnchorIfNeeded" }, // 1560802842
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven, "SpawnProceduralMeshOnCeilingIfNoCeilingActorGiven" }, // 2029268524
		{ &Z_Construct_UFunction_AMRUKAnchorActorSpawner_SpawnProceduralMeshOnFloorIfNoFloorActorGiven, "SpawnProceduralMeshOnFloorIfNoFloorActorGiven" }, // 4219026393
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMRUKAnchorActorSpawner>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_OnActorsSpawned = { "OnActorsSpawned", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKAnchorActorSpawner, OnActorsSpawned), Z_Construct_UDelegateFunction_AMRUKAnchorActorSpawner_OnInteriorSpawned__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnActorsSpawned_MetaData), NewProp_OnActorsSpawned_MetaData) }; // 3158354467
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_AnchorRandomSpawnSeed = { "AnchorRandomSpawnSeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKAnchorActorSpawner, AnchorRandomSpawnSeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnchorRandomSpawnSeed_MetaData), NewProp_AnchorRandomSpawnSeed_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_SpawnMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_SpawnMode = { "SpawnMode", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKAnchorActorSpawner, SpawnMode), Z_Construct_UEnum_MRUtilityKit_EMRUKSpawnMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnMode_MetaData), NewProp_SpawnMode_MetaData) }; // 3624342257
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_ProceduralMaterial = { "ProceduralMaterial", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKAnchorActorSpawner, ProceduralMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProceduralMaterial_MetaData), NewProp_ProceduralMaterial_MetaData) };
void Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_ShouldFallbackToProcedural_SetBit(void* Obj)
{
	((AMRUKAnchorActorSpawner*)Obj)->ShouldFallbackToProcedural = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_ShouldFallbackToProcedural = { "ShouldFallbackToProcedural", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMRUKAnchorActorSpawner), &Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_ShouldFallbackToProcedural_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShouldFallbackToProcedural_MetaData), NewProp_ShouldFallbackToProcedural_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_CutHoleLabels_Inner = { "CutHoleLabels", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_CutHoleLabels = { "CutHoleLabels", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKAnchorActorSpawner, CutHoleLabels), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CutHoleLabels_MetaData), NewProp_CutHoleLabels_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_SpawnGroups_ValueProp = { "SpawnGroups", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FMRUKSpawnGroup, METADATA_PARAMS(0, nullptr) }; // 2478180099
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_SpawnGroups_Key_KeyProp = { "SpawnGroups_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_SpawnGroups = { "SpawnGroups", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKAnchorActorSpawner, SpawnGroups), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnGroups_MetaData), NewProp_SpawnGroups_MetaData) }; // 2478180099
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_OnActorsSpawned,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_AnchorRandomSpawnSeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_SpawnMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_SpawnMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_ProceduralMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_ShouldFallbackToProcedural,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_CutHoleLabels_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_CutHoleLabels,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_SpawnGroups_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_SpawnGroups_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::NewProp_SpawnGroups,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::ClassParams = {
	&AMRUKAnchorActorSpawner::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::Class_MetaDataParams), Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMRUKAnchorActorSpawner()
{
	if (!Z_Registration_Info_UClass_AMRUKAnchorActorSpawner.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMRUKAnchorActorSpawner.OuterSingleton, Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMRUKAnchorActorSpawner.OuterSingleton;
}
template<> MRUTILITYKIT_API UClass* StaticClass<AMRUKAnchorActorSpawner>()
{
	return AMRUKAnchorActorSpawner::StaticClass();
}
AMRUKAnchorActorSpawner::AMRUKAnchorActorSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMRUKAnchorActorSpawner);
AMRUKAnchorActorSpawner::~AMRUKAnchorActorSpawner() {}
// End Class AMRUKAnchorActorSpawner

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMRUKAnchorActorSpawner, AMRUKAnchorActorSpawner::StaticClass, TEXT("AMRUKAnchorActorSpawner"), &Z_Registration_Info_UClass_AMRUKAnchorActorSpawner, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMRUKAnchorActorSpawner), 2415641046U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_2417261115(TEXT("/Script/MRUtilityKit"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
