// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRInput/Public/OculusXRHandComponent.h"
#include "OculusXRInput/Public/OculusXRInputFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRHandComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPoseableMeshComponent();
OCULUSXRINPUT_API UClass* Z_Construct_UClass_UOculusXRHandComponent();
OCULUSXRINPUT_API UClass* Z_Construct_UClass_UOculusXRHandComponent_NoRegister();
OCULUSXRINPUT_API UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRBone();
OCULUSXRINPUT_API UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRConfidenceBehavior();
OCULUSXRINPUT_API UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRHandType();
OCULUSXRINPUT_API UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRSystemGestureBehavior();
OCULUSXRINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRCapsuleCollider();
UPackage* Z_Construct_UPackage__Script_OculusXRInput();
// End Cross Module References

// Begin Enum EOculusXRConfidenceBehavior
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRConfidenceBehavior;
static UEnum* EOculusXRConfidenceBehavior_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRConfidenceBehavior.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRConfidenceBehavior.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRInput_EOculusXRConfidenceBehavior, (UObject*)Z_Construct_UPackage__Script_OculusXRInput(), TEXT("EOculusXRConfidenceBehavior"));
	}
	return Z_Registration_Info_UEnum_EOculusXRConfidenceBehavior.OuterSingleton;
}
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRConfidenceBehavior>()
{
	return EOculusXRConfidenceBehavior_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRInput_EOculusXRConfidenceBehavior_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideActor.Name", "EOculusXRConfidenceBehavior::HideActor" },
		{ "ModuleRelativePath", "Public/OculusXRHandComponent.h" },
		{ "None.Name", "EOculusXRConfidenceBehavior::None" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRConfidenceBehavior::None", (int64)EOculusXRConfidenceBehavior::None },
		{ "EOculusXRConfidenceBehavior::HideActor", (int64)EOculusXRConfidenceBehavior::HideActor },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRInput_EOculusXRConfidenceBehavior_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRInput,
	nullptr,
	"EOculusXRConfidenceBehavior",
	"EOculusXRConfidenceBehavior",
	Z_Construct_UEnum_OculusXRInput_EOculusXRConfidenceBehavior_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRConfidenceBehavior_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRConfidenceBehavior_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRInput_EOculusXRConfidenceBehavior_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRConfidenceBehavior()
{
	if (!Z_Registration_Info_UEnum_EOculusXRConfidenceBehavior.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRConfidenceBehavior.InnerSingleton, Z_Construct_UEnum_OculusXRInput_EOculusXRConfidenceBehavior_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRConfidenceBehavior.InnerSingleton;
}
// End Enum EOculusXRConfidenceBehavior

// Begin Enum EOculusXRSystemGestureBehavior
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRSystemGestureBehavior;
static UEnum* EOculusXRSystemGestureBehavior_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRSystemGestureBehavior.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRSystemGestureBehavior.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRInput_EOculusXRSystemGestureBehavior, (UObject*)Z_Construct_UPackage__Script_OculusXRInput(), TEXT("EOculusXRSystemGestureBehavior"));
	}
	return Z_Registration_Info_UEnum_EOculusXRSystemGestureBehavior.OuterSingleton;
}
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRSystemGestureBehavior>()
{
	return EOculusXRSystemGestureBehavior_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRInput_EOculusXRSystemGestureBehavior_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OculusXRHandComponent.h" },
		{ "None.Name", "EOculusXRSystemGestureBehavior::None" },
		{ "SwapMaterial.Name", "EOculusXRSystemGestureBehavior::SwapMaterial" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRSystemGestureBehavior::None", (int64)EOculusXRSystemGestureBehavior::None },
		{ "EOculusXRSystemGestureBehavior::SwapMaterial", (int64)EOculusXRSystemGestureBehavior::SwapMaterial },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRInput_EOculusXRSystemGestureBehavior_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRInput,
	nullptr,
	"EOculusXRSystemGestureBehavior",
	"EOculusXRSystemGestureBehavior",
	Z_Construct_UEnum_OculusXRInput_EOculusXRSystemGestureBehavior_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRSystemGestureBehavior_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRSystemGestureBehavior_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRInput_EOculusXRSystemGestureBehavior_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRSystemGestureBehavior()
{
	if (!Z_Registration_Info_UEnum_EOculusXRSystemGestureBehavior.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRSystemGestureBehavior.InnerSingleton, Z_Construct_UEnum_OculusXRInput_EOculusXRSystemGestureBehavior_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRSystemGestureBehavior.InnerSingleton;
}
// End Enum EOculusXRSystemGestureBehavior

// Begin Class UOculusXRHandComponent
void UOculusXRHandComponent::StaticRegisterNativesUOculusXRHandComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRHandComponent);
UClass* Z_Construct_UClass_UOculusXRHandComponent_NoRegister()
{
	return UOculusXRHandComponent::StaticClass();
}
struct Z_Construct_UClass_UOculusXRHandComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "OculusHand" },
		{ "HideCategories", "Object Physics Object Mobility Trigger" },
		{ "IncludePath", "OculusXRHandComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OculusXRHandComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkeletonType_MetaData[] = {
		{ "Category", "HandProperties" },
		{ "Comment", "/** The hand skeleton that will be loaded */" },
		{ "ModuleRelativePath", "Public/OculusXRHandComponent.h" },
		{ "ToolTip", "The hand skeleton that will be loaded" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshType_MetaData[] = {
		{ "Category", "HandProperties" },
		{ "Comment", "/** The hand mesh that will be applied to the skeleton */" },
		{ "ModuleRelativePath", "Public/OculusXRHandComponent.h" },
		{ "ToolTip", "The hand mesh that will be applied to the skeleton" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConfidenceBehavior_MetaData[] = {
		{ "Category", "HandProperties" },
		{ "Comment", "/** Behavior for when hand tracking loses high confidence tracking */" },
		{ "ModuleRelativePath", "Public/OculusXRHandComponent.h" },
		{ "ToolTip", "Behavior for when hand tracking loses high confidence tracking" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemGestureBehavior_MetaData[] = {
		{ "Category", "HandProperties" },
		{ "Comment", "/** Behavior for when the system gesture is actived */" },
		{ "ModuleRelativePath", "Public/OculusXRHandComponent.h" },
		{ "ToolTip", "Behavior for when the system gesture is actived" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemGestureMaterial_MetaData[] = {
		{ "Category", "HandProperties" },
		{ "Comment", "/** Material that gets applied to the hands when the system gesture is active */" },
		{ "ModuleRelativePath", "Public/OculusXRHandComponent.h" },
		{ "ToolTip", "Material that gets applied to the hands when the system gesture is active" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInitializePhysics_MetaData[] = {
		{ "Category", "HandProperties" },
		{ "Comment", "/** Whether or not to initialize physics capsules on the skeletal mesh */" },
		{ "ModuleRelativePath", "Public/OculusXRHandComponent.h" },
		{ "ToolTip", "Whether or not to initialize physics capsules on the skeletal mesh" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUpdateHandScale_MetaData[] = {
		{ "Category", "HandProperties" },
		{ "Comment", "/** Whether or not the hand scale should update based on values from the runtime to match the users hand scale */" },
		{ "ModuleRelativePath", "Public/OculusXRHandComponent.h" },
		{ "ToolTip", "Whether or not the hand scale should update based on values from the runtime to match the users hand scale" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialOverride_MetaData[] = {
		{ "Category", "HandProperties" },
		{ "Comment", "/** Material override for the runtime skeletal mesh */" },
		{ "ModuleRelativePath", "Public/OculusXRHandComponent.h" },
		{ "ToolTip", "Material override for the runtime skeletal mesh" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneNameMappings_MetaData[] = {
		{ "Category", "CustomSkeletalMesh" },
		{ "Comment", "/** Bone mapping for custom hand skeletal meshes */" },
		{ "ModuleRelativePath", "Public/OculusXRHandComponent.h" },
		{ "ToolTip", "Bone mapping for custom hand skeletal meshes" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionCapsules_MetaData[] = {
		{ "Category", "HandProperties" },
		{ "Comment", "/** List of capsule colliders created for the skeletal mesh */" },
		{ "ModuleRelativePath", "Public/OculusXRHandComponent.h" },
		{ "ToolTip", "List of capsule colliders created for the skeletal mesh" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSkeletalMeshInitialized_MetaData[] = {
		{ "Category", "HandProperties" },
		{ "Comment", "/** Whether or not the runtime skeletal mesh has been loaded and initialized */" },
		{ "ModuleRelativePath", "Public/OculusXRHandComponent.h" },
		{ "ToolTip", "Whether or not the runtime skeletal mesh has been loaded and initialized" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SkeletonType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SkeletonType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_MeshType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MeshType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ConfidenceBehavior_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ConfidenceBehavior;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SystemGestureBehavior_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SystemGestureBehavior;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SystemGestureMaterial;
	static void NewProp_bInitializePhysics_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInitializePhysics;
	static void NewProp_bUpdateHandScale_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUpdateHandScale;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaterialOverride;
	static const UECodeGen_Private::FNamePropertyParams NewProp_BoneNameMappings_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BoneNameMappings_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BoneNameMappings_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_BoneNameMappings;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CollisionCapsules_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CollisionCapsules;
	static void NewProp_bSkeletalMeshInitialized_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSkeletalMeshInitialized;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRHandComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_SkeletonType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_SkeletonType = { "SkeletonType", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRHandComponent, SkeletonType), Z_Construct_UEnum_OculusXRInput_EOculusXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkeletonType_MetaData), NewProp_SkeletonType_MetaData) }; // 1666178145
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_MeshType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_MeshType = { "MeshType", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRHandComponent, MeshType), Z_Construct_UEnum_OculusXRInput_EOculusXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshType_MetaData), NewProp_MeshType_MetaData) }; // 1666178145
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_ConfidenceBehavior_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_ConfidenceBehavior = { "ConfidenceBehavior", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRHandComponent, ConfidenceBehavior), Z_Construct_UEnum_OculusXRInput_EOculusXRConfidenceBehavior, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConfidenceBehavior_MetaData), NewProp_ConfidenceBehavior_MetaData) }; // 1257310379
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_SystemGestureBehavior_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_SystemGestureBehavior = { "SystemGestureBehavior", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRHandComponent, SystemGestureBehavior), Z_Construct_UEnum_OculusXRInput_EOculusXRSystemGestureBehavior, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemGestureBehavior_MetaData), NewProp_SystemGestureBehavior_MetaData) }; // 185340541
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_SystemGestureMaterial = { "SystemGestureMaterial", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRHandComponent, SystemGestureMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemGestureMaterial_MetaData), NewProp_SystemGestureMaterial_MetaData) };
void Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_bInitializePhysics_SetBit(void* Obj)
{
	((UOculusXRHandComponent*)Obj)->bInitializePhysics = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_bInitializePhysics = { "bInitializePhysics", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRHandComponent), &Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_bInitializePhysics_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInitializePhysics_MetaData), NewProp_bInitializePhysics_MetaData) };
void Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_bUpdateHandScale_SetBit(void* Obj)
{
	((UOculusXRHandComponent*)Obj)->bUpdateHandScale = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_bUpdateHandScale = { "bUpdateHandScale", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRHandComponent), &Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_bUpdateHandScale_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUpdateHandScale_MetaData), NewProp_bUpdateHandScale_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_MaterialOverride = { "MaterialOverride", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRHandComponent, MaterialOverride), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialOverride_MetaData), NewProp_MaterialOverride_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_BoneNameMappings_ValueProp = { "BoneNameMappings", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_BoneNameMappings_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_BoneNameMappings_Key_KeyProp = { "BoneNameMappings_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_OculusXRInput_EOculusXRBone, METADATA_PARAMS(0, nullptr) }; // 948790416
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_BoneNameMappings = { "BoneNameMappings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRHandComponent, BoneNameMappings), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneNameMappings_MetaData), NewProp_BoneNameMappings_MetaData) }; // 948790416
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_CollisionCapsules_Inner = { "CollisionCapsules", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOculusXRCapsuleCollider, METADATA_PARAMS(0, nullptr) }; // 2642326584
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_CollisionCapsules = { "CollisionCapsules", nullptr, (EPropertyFlags)0x0010008000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRHandComponent, CollisionCapsules), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionCapsules_MetaData), NewProp_CollisionCapsules_MetaData) }; // 2642326584
void Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_bSkeletalMeshInitialized_SetBit(void* Obj)
{
	((UOculusXRHandComponent*)Obj)->bSkeletalMeshInitialized = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_bSkeletalMeshInitialized = { "bSkeletalMeshInitialized", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRHandComponent), &Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_bSkeletalMeshInitialized_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSkeletalMeshInitialized_MetaData), NewProp_bSkeletalMeshInitialized_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRHandComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_SkeletonType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_SkeletonType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_MeshType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_MeshType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_ConfidenceBehavior_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_ConfidenceBehavior,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_SystemGestureBehavior_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_SystemGestureBehavior,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_SystemGestureMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_bInitializePhysics,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_bUpdateHandScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_MaterialOverride,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_BoneNameMappings_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_BoneNameMappings_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_BoneNameMappings_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_BoneNameMappings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_CollisionCapsules_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_CollisionCapsules,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRHandComponent_Statics::NewProp_bSkeletalMeshInitialized,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRHandComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRHandComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPoseableMeshComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRInput,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRHandComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRHandComponent_Statics::ClassParams = {
	&UOculusXRHandComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOculusXRHandComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRHandComponent_Statics::PropPointers),
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRHandComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRHandComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRHandComponent()
{
	if (!Z_Registration_Info_UClass_UOculusXRHandComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRHandComponent.OuterSingleton, Z_Construct_UClass_UOculusXRHandComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRHandComponent.OuterSingleton;
}
template<> OCULUSXRINPUT_API UClass* StaticClass<UOculusXRHandComponent>()
{
	return UOculusXRHandComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRHandComponent);
UOculusXRHandComponent::~UOculusXRHandComponent() {}
// End Class UOculusXRHandComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRHandComponent_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOculusXRConfidenceBehavior_StaticEnum, TEXT("EOculusXRConfidenceBehavior"), &Z_Registration_Info_UEnum_EOculusXRConfidenceBehavior, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1257310379U) },
		{ EOculusXRSystemGestureBehavior_StaticEnum, TEXT("EOculusXRSystemGestureBehavior"), &Z_Registration_Info_UEnum_EOculusXRSystemGestureBehavior, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 185340541U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRHandComponent, UOculusXRHandComponent::StaticClass, TEXT("UOculusXRHandComponent"), &Z_Registration_Info_UClass_UOculusXRHandComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRHandComponent), 1340885636U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRHandComponent_h_2490252999(TEXT("/Script/OculusXRInput"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRHandComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRHandComponent_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRHandComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRHandComponent_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
