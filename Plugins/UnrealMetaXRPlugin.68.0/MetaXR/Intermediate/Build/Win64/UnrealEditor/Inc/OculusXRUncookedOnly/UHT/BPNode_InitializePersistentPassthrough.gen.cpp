// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRUncookedOnly/Private/BPNode_InitializePersistentPassthrough.h"
#include "OculusXRPassthrough/Public/OculusXRPersistentPassthroughInstance.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBPNode_InitializePersistentPassthrough() {}

// Begin Cross Module References
BLUEPRINTGRAPH_API UClass* Z_Construct_UClass_UK2Node_CallFunction();
OCULUSXRPASSTHROUGH_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters();
OCULUSXRUNCOOKEDONLY_API UClass* Z_Construct_UClass_UBPNode_InitializePersistentPassthrough();
OCULUSXRUNCOOKEDONLY_API UClass* Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_NoRegister();
UPackage* Z_Construct_UPackage__Script_OculusXRUncookedOnly();
// End Cross Module References

// Begin Class UBPNode_InitializePersistentPassthrough
void UBPNode_InitializePersistentPassthrough::StaticRegisterNativesUBPNode_InitializePersistentPassthrough()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBPNode_InitializePersistentPassthrough);
UClass* Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_NoRegister()
{
	return UBPNode_InitializePersistentPassthrough::StaticClass();
}
struct Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "BPNode_InitializePersistentPassthrough.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Private/BPNode_InitializePersistentPassthrough.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowInputPin_MetaData[] = {
		{ "Category", "Parameters" },
		{ "ModuleRelativePath", "Private/BPNode_InitializePersistentPassthrough.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LayerParameters_MetaData[] = {
		{ "Category", "Parameters" },
		{ "EditCondition", "!bShowInputPin" },
		{ "ModuleRelativePath", "Private/BPNode_InitializePersistentPassthrough.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bShowInputPin_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowInputPin;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LayerParameters;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBPNode_InitializePersistentPassthrough>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::NewProp_bShowInputPin_SetBit(void* Obj)
{
	((UBPNode_InitializePersistentPassthrough*)Obj)->bShowInputPin = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::NewProp_bShowInputPin = { "bShowInputPin", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UBPNode_InitializePersistentPassthrough), &Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::NewProp_bShowInputPin_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowInputPin_MetaData), NewProp_bShowInputPin_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::NewProp_LayerParameters = { "LayerParameters", nullptr, (EPropertyFlags)0x0010008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBPNode_InitializePersistentPassthrough, LayerParameters), Z_Construct_UScriptStruct_FOculusXRPersistentPassthroughParameters, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LayerParameters_MetaData), NewProp_LayerParameters_MetaData) }; // 2056145856
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::NewProp_bShowInputPin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::NewProp_LayerParameters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UK2Node_CallFunction,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRUncookedOnly,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::ClassParams = {
	&UBPNode_InitializePersistentPassthrough::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::Class_MetaDataParams), Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBPNode_InitializePersistentPassthrough()
{
	if (!Z_Registration_Info_UClass_UBPNode_InitializePersistentPassthrough.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBPNode_InitializePersistentPassthrough.OuterSingleton, Z_Construct_UClass_UBPNode_InitializePersistentPassthrough_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBPNode_InitializePersistentPassthrough.OuterSingleton;
}
template<> OCULUSXRUNCOOKEDONLY_API UClass* StaticClass<UBPNode_InitializePersistentPassthrough>()
{
	return UBPNode_InitializePersistentPassthrough::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBPNode_InitializePersistentPassthrough);
UBPNode_InitializePersistentPassthrough::~UBPNode_InitializePersistentPassthrough() {}
IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(UBPNode_InitializePersistentPassthrough)
// End Class UBPNode_InitializePersistentPassthrough

// Begin Registration
struct Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRUncookedOnly_Private_BPNode_InitializePersistentPassthrough_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBPNode_InitializePersistentPassthrough, UBPNode_InitializePersistentPassthrough::StaticClass, TEXT("UBPNode_InitializePersistentPassthrough"), &Z_Registration_Info_UClass_UBPNode_InitializePersistentPassthrough, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBPNode_InitializePersistentPassthrough), 3020226618U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRUncookedOnly_Private_BPNode_InitializePersistentPassthrough_h_4084132128(TEXT("/Script/OculusXRUncookedOnly"),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRUncookedOnly_Private_BPNode_InitializePersistentPassthrough_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRUncookedOnly_Private_BPNode_InitializePersistentPassthrough_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
