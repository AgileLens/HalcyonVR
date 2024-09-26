// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRHMD/Private/OculusXRSceneCaptureCubemap.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRSceneCaptureCubemap() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D_NoRegister();
OCULUSXRHMD_API UClass* Z_Construct_UClass_UOculusXRSceneCaptureCubemap();
OCULUSXRHMD_API UClass* Z_Construct_UClass_UOculusXRSceneCaptureCubemap_NoRegister();
UPackage* Z_Construct_UPackage__Script_OculusXRHMD();
// End Cross Module References

// Begin Class UOculusXRSceneCaptureCubemap
void UOculusXRSceneCaptureCubemap::StaticRegisterNativesUOculusXRSceneCaptureCubemap()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRSceneCaptureCubemap);
UClass* Z_Construct_UClass_UOculusXRSceneCaptureCubemap_NoRegister()
{
	return UOculusXRSceneCaptureCubemap::StaticClass();
}
struct Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "OculusXRSceneCaptureCubemap.h" },
		{ "ModuleRelativePath", "Private/OculusXRSceneCaptureCubemap.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CaptureComponents_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/OculusXRSceneCaptureCubemap.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CaptureComponents_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CaptureComponents;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRSceneCaptureCubemap>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics::NewProp_CaptureComponents_Inner = { "CaptureComponents", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics::NewProp_CaptureComponents = { "CaptureComponents", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRSceneCaptureCubemap, CaptureComponents), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CaptureComponents_MetaData), NewProp_CaptureComponents_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics::NewProp_CaptureComponents_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics::NewProp_CaptureComponents,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRHMD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics::ClassParams = {
	&UOculusXRSceneCaptureCubemap::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics::PropPointers),
	0,
	0x008000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRSceneCaptureCubemap()
{
	if (!Z_Registration_Info_UClass_UOculusXRSceneCaptureCubemap.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRSceneCaptureCubemap.OuterSingleton, Z_Construct_UClass_UOculusXRSceneCaptureCubemap_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRSceneCaptureCubemap.OuterSingleton;
}
template<> OCULUSXRHMD_API UClass* StaticClass<UOculusXRSceneCaptureCubemap>()
{
	return UOculusXRSceneCaptureCubemap::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRSceneCaptureCubemap);
UOculusXRSceneCaptureCubemap::~UOculusXRSceneCaptureCubemap() {}
// End Class UOculusXRSceneCaptureCubemap

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Private_OculusXRSceneCaptureCubemap_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRSceneCaptureCubemap, UOculusXRSceneCaptureCubemap::StaticClass, TEXT("UOculusXRSceneCaptureCubemap"), &Z_Registration_Info_UClass_UOculusXRSceneCaptureCubemap, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRSceneCaptureCubemap), 2098859990U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Private_OculusXRSceneCaptureCubemap_h_631847360(TEXT("/Script/OculusXRHMD"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Private_OculusXRSceneCaptureCubemap_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Private_OculusXRSceneCaptureCubemap_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
