// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRHMD/Private/OculusXRResourceHolder.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRResourceHolder() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
OCULUSXRHMD_API UClass* Z_Construct_UClass_UOculusXRResourceHolder();
OCULUSXRHMD_API UClass* Z_Construct_UClass_UOculusXRResourceHolder_NoRegister();
UPackage* Z_Construct_UPackage__Script_OculusXRHMD();
// End Cross Module References

// Begin Class UOculusXRResourceHolder
void UOculusXRResourceHolder::StaticRegisterNativesUOculusXRResourceHolder()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRResourceHolder);
UClass* Z_Construct_UClass_UOculusXRResourceHolder_NoRegister()
{
	return UOculusXRResourceHolder::StaticClass();
}
struct Z_Construct_UClass_UOculusXRResourceHolder_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "IncludePath", "OculusXRResourceHolder.h" },
		{ "ModuleRelativePath", "Private/OculusXRResourceHolder.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PokeAHoleMaterial_MetaData[] = {
		{ "ModuleRelativePath", "Private/OculusXRResourceHolder.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PokeAHoleMaterial;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRResourceHolder>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOculusXRResourceHolder_Statics::NewProp_PokeAHoleMaterial = { "PokeAHoleMaterial", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRResourceHolder, PokeAHoleMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PokeAHoleMaterial_MetaData), NewProp_PokeAHoleMaterial_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRResourceHolder_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRResourceHolder_Statics::NewProp_PokeAHoleMaterial,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRResourceHolder_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRResourceHolder_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRHMD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRResourceHolder_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRResourceHolder_Statics::ClassParams = {
	&UOculusXRResourceHolder::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOculusXRResourceHolder_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRResourceHolder_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRResourceHolder_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRResourceHolder_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRResourceHolder()
{
	if (!Z_Registration_Info_UClass_UOculusXRResourceHolder.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRResourceHolder.OuterSingleton, Z_Construct_UClass_UOculusXRResourceHolder_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRResourceHolder.OuterSingleton;
}
template<> OCULUSXRHMD_API UClass* StaticClass<UOculusXRResourceHolder>()
{
	return UOculusXRResourceHolder::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRResourceHolder);
UOculusXRResourceHolder::~UOculusXRResourceHolder() {}
// End Class UOculusXRResourceHolder

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Private_OculusXRResourceHolder_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRResourceHolder, UOculusXRResourceHolder::StaticClass, TEXT("UOculusXRResourceHolder"), &Z_Registration_Info_UClass_UOculusXRResourceHolder, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRResourceHolder), 782594540U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Private_OculusXRResourceHolder_h_1529337929(TEXT("/Script/OculusXRHMD"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Private_OculusXRResourceHolder_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Private_OculusXRResourceHolder_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
