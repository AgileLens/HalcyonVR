// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRScene/Public/OculusXRSceneGlobalMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/CollisionProfile.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRSceneGlobalMeshComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FCollisionProfileName();
OCULUSXRSCENE_API UClass* Z_Construct_UClass_UOculusXRSceneAnchorComponent_NoRegister();
OCULUSXRSCENE_API UClass* Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent();
OCULUSXRSCENE_API UClass* Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_OculusXRScene();
// End Cross Module References

// Begin Class UOculusXRSceneGlobalMeshComponent
void UOculusXRSceneGlobalMeshComponent::StaticRegisterNativesUOculusXRSceneGlobalMeshComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRSceneGlobalMeshComponent);
UClass* Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_NoRegister()
{
	return UOculusXRSceneGlobalMeshComponent::StaticClass();
}
struct Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "Comment", "/**\n * DEPRECATED: AOculusXRSceneActor and associated classes are deprecated (v65), please use MR Utility Kit instead\n * (https://developer.oculus.com/documentation/unreal/unreal-mr-utility-kit-overview)\n */" },
		{ "DisplayName", "OculusXR Scene Global Mesh Component" },
		{ "IncludePath", "OculusXRSceneGlobalMeshComponent.h" },
		{ "ModuleRelativePath", "Public/OculusXRSceneGlobalMeshComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "DEPRECATED: AOculusXRSceneActor and associated classes are deprecated (v65), please use MR Utility Kit instead\n(https://developer.oculus.com/documentation/unreal/unreal-mr-utility-kit-overview)" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Collision_MetaData[] = {
		{ "Category", "OculusXR" },
		{ "ModuleRelativePath", "Public/OculusXRSceneGlobalMeshComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionProfileName_MetaData[] = {
		{ "Category", "OculusXR" },
		{ "ModuleRelativePath", "Public/OculusXRSceneGlobalMeshComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Visible_MetaData[] = {
		{ "Category", "OculusXR" },
		{ "ModuleRelativePath", "Public/OculusXRSceneGlobalMeshComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Material_MetaData[] = {
		{ "Category", "OculusXR" },
		{ "ModuleRelativePath", "Public/OculusXRSceneGlobalMeshComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneAnchorComponent_MetaData[] = {
		{ "Category", "OculusXR" },
		{ "ModuleRelativePath", "Public/OculusXRSceneGlobalMeshComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_Collision_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Collision;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CollisionProfileName;
	static void NewProp_Visible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Visible;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Material;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_SceneAnchorComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRSceneGlobalMeshComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::NewProp_Collision_SetBit(void* Obj)
{
	((UOculusXRSceneGlobalMeshComponent*)Obj)->Collision = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::NewProp_Collision = { "Collision", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRSceneGlobalMeshComponent), &Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::NewProp_Collision_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Collision_MetaData), NewProp_Collision_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::NewProp_CollisionProfileName = { "CollisionProfileName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRSceneGlobalMeshComponent, CollisionProfileName), Z_Construct_UScriptStruct_FCollisionProfileName, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionProfileName_MetaData), NewProp_CollisionProfileName_MetaData) }; // 3816324900
void Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::NewProp_Visible_SetBit(void* Obj)
{
	((UOculusXRSceneGlobalMeshComponent*)Obj)->Visible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::NewProp_Visible = { "Visible", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRSceneGlobalMeshComponent), &Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::NewProp_Visible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Visible_MetaData), NewProp_Visible_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::NewProp_Material = { "Material", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRSceneGlobalMeshComponent, Material), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Material_MetaData), NewProp_Material_MetaData) };
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::NewProp_SceneAnchorComponent = { "SceneAnchorComponent", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRSceneGlobalMeshComponent, SceneAnchorComponent), Z_Construct_UClass_UOculusXRSceneAnchorComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneAnchorComponent_MetaData), NewProp_SceneAnchorComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::NewProp_Collision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::NewProp_CollisionProfileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::NewProp_Visible,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::NewProp_Material,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::NewProp_SceneAnchorComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRScene,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::ClassParams = {
	&UOculusXRSceneGlobalMeshComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent()
{
	if (!Z_Registration_Info_UClass_UOculusXRSceneGlobalMeshComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRSceneGlobalMeshComponent.OuterSingleton, Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRSceneGlobalMeshComponent.OuterSingleton;
}
template<> OCULUSXRSCENE_API UClass* StaticClass<UOculusXRSceneGlobalMeshComponent>()
{
	return UOculusXRSceneGlobalMeshComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRSceneGlobalMeshComponent);
UOculusXRSceneGlobalMeshComponent::~UOculusXRSceneGlobalMeshComponent() {}
// End Class UOculusXRSceneGlobalMeshComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneGlobalMeshComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRSceneGlobalMeshComponent, UOculusXRSceneGlobalMeshComponent::StaticClass, TEXT("UOculusXRSceneGlobalMeshComponent"), &Z_Registration_Info_UClass_UOculusXRSceneGlobalMeshComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRSceneGlobalMeshComponent), 1980906268U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneGlobalMeshComponent_h_1424556234(TEXT("/Script/OculusXRScene"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneGlobalMeshComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneGlobalMeshComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
