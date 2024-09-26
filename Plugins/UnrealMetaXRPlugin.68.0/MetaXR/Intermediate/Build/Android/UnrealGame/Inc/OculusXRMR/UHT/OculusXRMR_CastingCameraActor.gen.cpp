// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRMR/Private/OculusXRMR_CastingCameraActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRMR_CastingCameraActor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ASceneCapture2D();
ENGINE_API UClass* Z_Construct_UClass_ASceneCapture2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
OCULUSXRMR_API UClass* Z_Construct_UClass_AOculusXRMR_CastingCameraActor();
OCULUSXRMR_API UClass* Z_Construct_UClass_AOculusXRMR_CastingCameraActor_NoRegister();
OCULUSXRMR_API UClass* Z_Construct_UClass_UOculusXRMR_PlaneMeshComponent_NoRegister();
OCULUSXRMR_API UClass* Z_Construct_UClass_UOculusXRMR_Settings_NoRegister();
OCULUSXRMR_API UClass* Z_Construct_UClass_UOculusXRMR_State_NoRegister();
UPackage* Z_Construct_UPackage__Script_OculusXRMR();
XRBASE_API UClass* Z_Construct_UClass_UVRNotificationsComponent_NoRegister();
// End Cross Module References

// Begin Class AOculusXRMR_CastingCameraActor
void AOculusXRMR_CastingCameraActor::StaticRegisterNativesAOculusXRMR_CastingCameraActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOculusXRMR_CastingCameraActor);
UClass* Z_Construct_UClass_AOculusXRMR_CastingCameraActor_NoRegister()
{
	return AOculusXRMR_CastingCameraActor::StaticClass();
}
struct Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ClassGroupNames", "OculusXRMR" },
		{ "Comment", "/**\n * The camera actor in the level that tracks the binded physical camera in game\n */" },
		{ "HideCategories", "Collision Material Attachment Actor Collision Attachment Actor" },
		{ "IncludePath", "OculusXRMR_CastingCameraActor.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Private/OculusXRMR_CastingCameraActor.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
		{ "ToolTip", "The camera actor in the level that tracks the binded physical camera in game" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VRNotificationComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/OculusXRMR_CastingCameraActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlaneMeshComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/OculusXRMR_CastingCameraActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OpaqueColoredMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Private/OculusXRMR_CastingCameraActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BackdropMaterialInstance_MetaData[] = {
		{ "ModuleRelativePath", "Private/OculusXRMR_CastingCameraActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultTexture_White_MetaData[] = {
		{ "ModuleRelativePath", "Private/OculusXRMR_CastingCameraActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BackgroundRenderTargets_MetaData[] = {
		{ "ModuleRelativePath", "Private/OculusXRMR_CastingCameraActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ForegroundCaptureActor_MetaData[] = {
		{ "ModuleRelativePath", "Private/OculusXRMR_CastingCameraActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ForegroundRenderTargets_MetaData[] = {
		{ "ModuleRelativePath", "Private/OculusXRMR_CastingCameraActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PoseTimes_MetaData[] = {
		{ "ModuleRelativePath", "Private/OculusXRMR_CastingCameraActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MRSettings_MetaData[] = {
		{ "ModuleRelativePath", "Private/OculusXRMR_CastingCameraActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MRState_MetaData[] = {
		{ "ModuleRelativePath", "Private/OculusXRMR_CastingCameraActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VRNotificationComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlaneMeshComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OpaqueColoredMaterial;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BackdropMaterialInstance;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultTexture_White;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BackgroundRenderTargets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_BackgroundRenderTargets;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ForegroundCaptureActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ForegroundRenderTargets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ForegroundRenderTargets;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_PoseTimes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PoseTimes;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MRSettings;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MRState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOculusXRMR_CastingCameraActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_VRNotificationComponent = { "VRNotificationComponent", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRMR_CastingCameraActor, VRNotificationComponent), Z_Construct_UClass_UVRNotificationsComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VRNotificationComponent_MetaData), NewProp_VRNotificationComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_PlaneMeshComponent = { "PlaneMeshComponent", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRMR_CastingCameraActor, PlaneMeshComponent), Z_Construct_UClass_UOculusXRMR_PlaneMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlaneMeshComponent_MetaData), NewProp_PlaneMeshComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_OpaqueColoredMaterial = { "OpaqueColoredMaterial", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRMR_CastingCameraActor, OpaqueColoredMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OpaqueColoredMaterial_MetaData), NewProp_OpaqueColoredMaterial_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_BackdropMaterialInstance = { "BackdropMaterialInstance", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRMR_CastingCameraActor, BackdropMaterialInstance), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BackdropMaterialInstance_MetaData), NewProp_BackdropMaterialInstance_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_DefaultTexture_White = { "DefaultTexture_White", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRMR_CastingCameraActor, DefaultTexture_White), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultTexture_White_MetaData), NewProp_DefaultTexture_White_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_BackgroundRenderTargets_Inner = { "BackgroundRenderTargets", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_BackgroundRenderTargets = { "BackgroundRenderTargets", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRMR_CastingCameraActor, BackgroundRenderTargets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BackgroundRenderTargets_MetaData), NewProp_BackgroundRenderTargets_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_ForegroundCaptureActor = { "ForegroundCaptureActor", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRMR_CastingCameraActor, ForegroundCaptureActor), Z_Construct_UClass_ASceneCapture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ForegroundCaptureActor_MetaData), NewProp_ForegroundCaptureActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_ForegroundRenderTargets_Inner = { "ForegroundRenderTargets", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_ForegroundRenderTargets = { "ForegroundRenderTargets", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRMR_CastingCameraActor, ForegroundRenderTargets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ForegroundRenderTargets_MetaData), NewProp_ForegroundRenderTargets_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_PoseTimes_Inner = { "PoseTimes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_PoseTimes = { "PoseTimes", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRMR_CastingCameraActor, PoseTimes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PoseTimes_MetaData), NewProp_PoseTimes_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_MRSettings = { "MRSettings", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRMR_CastingCameraActor, MRSettings), Z_Construct_UClass_UOculusXRMR_Settings_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MRSettings_MetaData), NewProp_MRSettings_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_MRState = { "MRState", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOculusXRMR_CastingCameraActor, MRState), Z_Construct_UClass_UOculusXRMR_State_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MRState_MetaData), NewProp_MRState_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_VRNotificationComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_PlaneMeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_OpaqueColoredMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_BackdropMaterialInstance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_DefaultTexture_White,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_BackgroundRenderTargets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_BackgroundRenderTargets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_ForegroundCaptureActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_ForegroundRenderTargets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_ForegroundRenderTargets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_PoseTimes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_PoseTimes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_MRSettings,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::NewProp_MRState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ASceneCapture2D,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRMR,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::ClassParams = {
	&AOculusXRMR_CastingCameraActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::PropPointers),
	0,
	0x008002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AOculusXRMR_CastingCameraActor()
{
	if (!Z_Registration_Info_UClass_AOculusXRMR_CastingCameraActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOculusXRMR_CastingCameraActor.OuterSingleton, Z_Construct_UClass_AOculusXRMR_CastingCameraActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AOculusXRMR_CastingCameraActor.OuterSingleton;
}
template<> OCULUSXRMR_API UClass* StaticClass<AOculusXRMR_CastingCameraActor>()
{
	return AOculusXRMR_CastingCameraActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AOculusXRMR_CastingCameraActor);
AOculusXRMR_CastingCameraActor::~AOculusXRMR_CastingCameraActor() {}
// End Class AOculusXRMR_CastingCameraActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Private_OculusXRMR_CastingCameraActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AOculusXRMR_CastingCameraActor, AOculusXRMR_CastingCameraActor::StaticClass, TEXT("AOculusXRMR_CastingCameraActor"), &Z_Registration_Info_UClass_AOculusXRMR_CastingCameraActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOculusXRMR_CastingCameraActor), 3454710090U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Private_OculusXRMR_CastingCameraActor_h_2862242208(TEXT("/Script/OculusXRMR"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Private_OculusXRMR_CastingCameraActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMR_Private_OculusXRMR_CastingCameraActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
