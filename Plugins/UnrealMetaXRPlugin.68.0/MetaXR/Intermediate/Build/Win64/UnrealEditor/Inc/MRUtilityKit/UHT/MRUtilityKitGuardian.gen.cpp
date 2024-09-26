// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MRUtilityKit/Public/MRUtilityKitGuardian.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMRUtilityKitGuardian() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKGuardian();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKGuardian_NoRegister();
PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_MRUtilityKit();
// End Cross Module References

// Begin Class AMRUKGuardian Function CreateGuardian
struct Z_Construct_UFunction_AMRUKGuardian_CreateGuardian_Statics
{
	struct MRUKGuardian_eventCreateGuardian_Parms
	{
		UProceduralMeshComponent* GuardianMesh;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Attaches the procedural mesh component to this actor.\n\x09 * @param GuardianMesh The mesh to attach.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardian.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Attaches the procedural mesh component to this actor.\n@param GuardianMesh The mesh to attach." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GuardianMesh_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GuardianMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKGuardian_CreateGuardian_Statics::NewProp_GuardianMesh = { "GuardianMesh", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKGuardian_eventCreateGuardian_Parms, GuardianMesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuardianMesh_MetaData), NewProp_GuardianMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKGuardian_CreateGuardian_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKGuardian_CreateGuardian_Statics::NewProp_GuardianMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardian_CreateGuardian_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKGuardian_CreateGuardian_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKGuardian, nullptr, "CreateGuardian", nullptr, nullptr, Z_Construct_UFunction_AMRUKGuardian_CreateGuardian_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardian_CreateGuardian_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKGuardian_CreateGuardian_Statics::MRUKGuardian_eventCreateGuardian_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKGuardian_CreateGuardian_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKGuardian_CreateGuardian_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKGuardian_CreateGuardian_Statics::MRUKGuardian_eventCreateGuardian_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKGuardian_CreateGuardian()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKGuardian_CreateGuardian_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKGuardian::execCreateGuardian)
{
	P_GET_OBJECT(UProceduralMeshComponent,Z_Param_GuardianMesh);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CreateGuardian(Z_Param_GuardianMesh);
	P_NATIVE_END;
}
// End Class AMRUKGuardian Function CreateGuardian

// Begin Class AMRUKGuardian
void AMRUKGuardian::StaticRegisterNativesAMRUKGuardian()
{
	UClass* Class = AMRUKGuardian::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CreateGuardian", &AMRUKGuardian::execCreateGuardian },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMRUKGuardian);
UClass* Z_Construct_UClass_AMRUKGuardian_NoRegister()
{
	return AMRUKGuardian::StaticClass();
}
struct Z_Construct_UClass_AMRUKGuardian_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ClassGroupNames", "MRUtilityKit" },
		{ "DisplayName", "MR Utility Kit Guardian Actor" },
		{ "IncludePath", "MRUtilityKitGuardian.h" },
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardian.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GuardianMeshComponent_MetaData[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Procedural mesh that is generated from the anchor geometry and has the guardian material applied.\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MRUtilityKitGuardian.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Procedural mesh that is generated from the anchor geometry and has the guardian material applied." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GuardianMeshComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMRUKGuardian_CreateGuardian, "CreateGuardian" }, // 2693972484
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMRUKGuardian>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKGuardian_Statics::NewProp_GuardianMeshComponent = { "GuardianMeshComponent", nullptr, (EPropertyFlags)0x01140000000a281d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKGuardian, GuardianMeshComponent), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GuardianMeshComponent_MetaData), NewProp_GuardianMeshComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMRUKGuardian_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKGuardian_Statics::NewProp_GuardianMeshComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKGuardian_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMRUKGuardian_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKGuardian_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMRUKGuardian_Statics::ClassParams = {
	&AMRUKGuardian::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMRUKGuardian_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKGuardian_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKGuardian_Statics::Class_MetaDataParams), Z_Construct_UClass_AMRUKGuardian_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMRUKGuardian()
{
	if (!Z_Registration_Info_UClass_AMRUKGuardian.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMRUKGuardian.OuterSingleton, Z_Construct_UClass_AMRUKGuardian_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMRUKGuardian.OuterSingleton;
}
template<> MRUTILITYKIT_API UClass* StaticClass<AMRUKGuardian>()
{
	return AMRUKGuardian::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMRUKGuardian);
AMRUKGuardian::~AMRUKGuardian() {}
// End Class AMRUKGuardian

// Begin Registration
struct Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitGuardian_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMRUKGuardian, AMRUKGuardian::StaticClass, TEXT("AMRUKGuardian"), &Z_Registration_Info_UClass_AMRUKGuardian, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMRUKGuardian), 1434016538U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitGuardian_h_3796885373(TEXT("/Script/MRUtilityKit"),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitGuardian_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitGuardian_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
