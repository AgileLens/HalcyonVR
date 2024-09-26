// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRAnchors/Public/OculusXRSpatialAnchorComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRSpatialAnchorComponent() {}

// Begin Cross Module References
OCULUSXRANCHORS_API UClass* Z_Construct_UClass_UOculusXRAnchorComponent();
OCULUSXRANCHORS_API UClass* Z_Construct_UClass_UOculusXRSpatialAnchorComponent();
OCULUSXRANCHORS_API UClass* Z_Construct_UClass_UOculusXRSpatialAnchorComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_OculusXRAnchors();
// End Cross Module References

// Begin Class UOculusXRSpatialAnchorComponent
void UOculusXRSpatialAnchorComponent::StaticRegisterNativesUOculusXRSpatialAnchorComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRSpatialAnchorComponent);
UClass* Z_Construct_UClass_UOculusXRSpatialAnchorComponent_NoRegister()
{
	return UOculusXRSpatialAnchorComponent::StaticClass();
}
struct Z_Construct_UClass_UOculusXRSpatialAnchorComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "DisplayName", "Oculus Spatial Anchor Component" },
		{ "IncludePath", "OculusXRSpatialAnchorComponent.h" },
		{ "ModuleRelativePath", "Public/OculusXRSpatialAnchorComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRSpatialAnchorComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UOculusXRSpatialAnchorComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UOculusXRAnchorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRAnchors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSpatialAnchorComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRSpatialAnchorComponent_Statics::ClassParams = {
	&UOculusXRSpatialAnchorComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRSpatialAnchorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRSpatialAnchorComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRSpatialAnchorComponent()
{
	if (!Z_Registration_Info_UClass_UOculusXRSpatialAnchorComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRSpatialAnchorComponent.OuterSingleton, Z_Construct_UClass_UOculusXRSpatialAnchorComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRSpatialAnchorComponent.OuterSingleton;
}
template<> OCULUSXRANCHORS_API UClass* StaticClass<UOculusXRSpatialAnchorComponent>()
{
	return UOculusXRSpatialAnchorComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRSpatialAnchorComponent);
UOculusXRSpatialAnchorComponent::~UOculusXRSpatialAnchorComponent() {}
// End Class UOculusXRSpatialAnchorComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRSpatialAnchorComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRSpatialAnchorComponent, UOculusXRSpatialAnchorComponent::StaticClass, TEXT("UOculusXRSpatialAnchorComponent"), &Z_Registration_Info_UClass_UOculusXRSpatialAnchorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRSpatialAnchorComponent), 3313782627U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRSpatialAnchorComponent_h_1289670671(TEXT("/Script/OculusXRAnchors"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRSpatialAnchorComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRSpatialAnchorComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
