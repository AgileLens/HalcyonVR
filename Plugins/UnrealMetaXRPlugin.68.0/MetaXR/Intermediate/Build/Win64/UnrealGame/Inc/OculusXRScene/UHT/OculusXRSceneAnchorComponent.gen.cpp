// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRScene/Public/OculusXRSceneAnchorComponent.h"
#include "OculusXRAnchors/Public/OculusXRAnchorTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRSceneAnchorComponent() {}

// Begin Cross Module References
OCULUSXRANCHORS_API UClass* Z_Construct_UClass_UOculusXRAnchorComponent();
OCULUSXRANCHORS_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRUInt64();
OCULUSXRSCENE_API UClass* Z_Construct_UClass_UOculusXRSceneAnchorComponent();
OCULUSXRSCENE_API UClass* Z_Construct_UClass_UOculusXRSceneAnchorComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_OculusXRScene();
// End Cross Module References

// Begin Class UOculusXRSceneAnchorComponent
void UOculusXRSceneAnchorComponent::StaticRegisterNativesUOculusXRSceneAnchorComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRSceneAnchorComponent);
UClass* Z_Construct_UClass_UOculusXRSceneAnchorComponent_NoRegister()
{
	return UOculusXRSceneAnchorComponent::StaticClass();
}
struct Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "Comment", "/**\n * DEPRECATED: AOculusXRSceneActor and associated classes are deprecated (v65), please use MR Utility Kit instead\n * (https://developer.oculus.com/documentation/unreal/unreal-mr-utility-kit-overview)\n */" },
		{ "DisplayName", "OculusXR Scene Anchor Component" },
		{ "IncludePath", "OculusXRSceneAnchorComponent.h" },
		{ "ModuleRelativePath", "Public/OculusXRSceneAnchorComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "DEPRECATED: AOculusXRSceneActor and associated classes are deprecated (v65), please use MR Utility Kit instead\n(https://developer.oculus.com/documentation/unreal/unreal-mr-utility-kit-overview)" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SemanticClassifications_MetaData[] = {
		{ "Category", "OculusXR|Scene Anchor Component" },
		{ "ModuleRelativePath", "Public/OculusXRSceneAnchorComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomSpaceID_MetaData[] = {
		{ "Category", "OculusXR|Scene Anchor Component" },
		{ "ModuleRelativePath", "Public/OculusXRSceneAnchorComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_SemanticClassifications_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SemanticClassifications;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoomSpaceID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRSceneAnchorComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::NewProp_SemanticClassifications_Inner = { "SemanticClassifications", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::NewProp_SemanticClassifications = { "SemanticClassifications", nullptr, (EPropertyFlags)0x0010000000002014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRSceneAnchorComponent, SemanticClassifications), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SemanticClassifications_MetaData), NewProp_SemanticClassifications_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::NewProp_RoomSpaceID = { "RoomSpaceID", nullptr, (EPropertyFlags)0x0010000000002014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRSceneAnchorComponent, RoomSpaceID), Z_Construct_UScriptStruct_FOculusXRUInt64, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomSpaceID_MetaData), NewProp_RoomSpaceID_MetaData) }; // 2016766802
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::NewProp_SemanticClassifications_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::NewProp_SemanticClassifications,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::NewProp_RoomSpaceID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UOculusXRAnchorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRScene,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::ClassParams = {
	&UOculusXRSceneAnchorComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRSceneAnchorComponent()
{
	if (!Z_Registration_Info_UClass_UOculusXRSceneAnchorComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRSceneAnchorComponent.OuterSingleton, Z_Construct_UClass_UOculusXRSceneAnchorComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRSceneAnchorComponent.OuterSingleton;
}
template<> OCULUSXRSCENE_API UClass* StaticClass<UOculusXRSceneAnchorComponent>()
{
	return UOculusXRSceneAnchorComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRSceneAnchorComponent);
UOculusXRSceneAnchorComponent::~UOculusXRSceneAnchorComponent() {}
// End Class UOculusXRSceneAnchorComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneAnchorComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRSceneAnchorComponent, UOculusXRSceneAnchorComponent::StaticClass, TEXT("UOculusXRSceneAnchorComponent"), &Z_Registration_Info_UClass_UOculusXRSceneAnchorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRSceneAnchorComponent), 3685099626U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneAnchorComponent_h_2713978153(TEXT("/Script/OculusXRScene"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneAnchorComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneAnchorComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
