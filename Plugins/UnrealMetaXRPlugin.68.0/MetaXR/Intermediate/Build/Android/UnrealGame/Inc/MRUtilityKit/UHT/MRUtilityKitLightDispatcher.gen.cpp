// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MRUtilityKit/Public/MRUtilityKitLightDispatcher.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMRUtilityKitLightDispatcher() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APointLight_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialParameterCollection_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKLightDispatcher();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKLightDispatcher_NoRegister();
UPackage* Z_Construct_UPackage__Script_MRUtilityKit();
// End Cross Module References

// Begin Class AMRUKLightDispatcher Function AddAdditionalPointLightActor
struct Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor_Statics
{
	struct MRUKLightDispatcher_eventAddAdditionalPointLightActor_Parms
	{
		AActor* Actor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Add a actor to the AdditionalActorsToLookForPointLightComponents list.\n\x09 * This should be used during runtime instead of adding actors directly to AdditionalActorsToLookForPointLightComponents.\n\x09 * @param Actor Actor to add to AdditionalActorsToLookForPointLightComponents.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitLightDispatcher.h" },
		{ "ToolTip", "Add a actor to the AdditionalActorsToLookForPointLightComponents list.\nThis should be used during runtime instead of adding actors directly to AdditionalActorsToLookForPointLightComponents.\n@param Actor Actor to add to AdditionalActorsToLookForPointLightComponents." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKLightDispatcher_eventAddAdditionalPointLightActor_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor_Statics::NewProp_Actor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKLightDispatcher, nullptr, "AddAdditionalPointLightActor", nullptr, nullptr, Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor_Statics::MRUKLightDispatcher_eventAddAdditionalPointLightActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor_Statics::MRUKLightDispatcher_eventAddAdditionalPointLightActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKLightDispatcher::execAddAdditionalPointLightActor)
{
	P_GET_OBJECT(AActor,Z_Param_Actor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddAdditionalPointLightActor(Z_Param_Actor);
	P_NATIVE_END;
}
// End Class AMRUKLightDispatcher Function AddAdditionalPointLightActor

// Begin Class AMRUKLightDispatcher Function ForceUpdateCollection
struct Z_Construct_UFunction_AMRUKLightDispatcher_ForceUpdateCollection_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Only callable in the editor from the scene, will update the linked parameter collection with the info\n\x09 * of the point lights in the scene (based on the parameters), updating the highlight effect in the process.\n\x09 * This is meant to preview the effect in the editor.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitLightDispatcher.h" },
		{ "ToolTip", "Only callable in the editor from the scene, will update the linked parameter collection with the info\nof the point lights in the scene (based on the parameters), updating the highlight effect in the process.\nThis is meant to preview the effect in the editor." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMRUKLightDispatcher_ForceUpdateCollection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMRUKLightDispatcher, nullptr, "ForceUpdateCollection", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMRUKLightDispatcher_ForceUpdateCollection_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMRUKLightDispatcher_ForceUpdateCollection_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMRUKLightDispatcher_ForceUpdateCollection()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMRUKLightDispatcher_ForceUpdateCollection_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMRUKLightDispatcher::execForceUpdateCollection)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ForceUpdateCollection();
	P_NATIVE_END;
}
// End Class AMRUKLightDispatcher Function ForceUpdateCollection

// Begin Class AMRUKLightDispatcher
void AMRUKLightDispatcher::StaticRegisterNativesAMRUKLightDispatcher()
{
	UClass* Class = AMRUKLightDispatcher::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddAdditionalPointLightActor", &AMRUKLightDispatcher::execAddAdditionalPointLightActor },
		{ "ForceUpdateCollection", &AMRUKLightDispatcher::execForceUpdateCollection },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMRUKLightDispatcher);
UClass* Z_Construct_UClass_AMRUKLightDispatcher_NoRegister()
{
	return AMRUKLightDispatcher::StaticClass();
}
struct Z_Construct_UClass_AMRUKLightDispatcher_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ClassGroupNames", "MRUtilityKit" },
		{ "Comment", "/**\n * Collects lights and sends them to a highlight material.\n * This can be used to achieve highlights over Passthrough.\n */" },
		{ "DisplayName", "MR Utility Kit Light Dispatcher" },
		{ "IncludePath", "MRUtilityKitLightDispatcher.h" },
		{ "ModuleRelativePath", "Public/MRUtilityKitLightDispatcher.h" },
		{ "ToolTip", "Collects lights and sends them to a highlight material.\nThis can be used to achieve highlights over Passthrough." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Collection_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * The material parameter collection in which to fill lights data.\n\x09 * This parameter collection gets then send to the shader.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitLightDispatcher.h" },
		{ "ToolTip", "The material parameter collection in which to fill lights data.\nThis parameter collection gets then send to the shader." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShouldFetchPointLightsAtBeginPlay_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Whether all point lights should be fetched automatically at BeginPlay().\n\x09 * The automatic fetching only works for PointLightActors. Actors that have PointLightComponents\n\x09 * attached to them will not be detected. These should be specified in AdditionalActorsToLookForPointLightComponents.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitLightDispatcher.h" },
		{ "ToolTip", "Whether all point lights should be fetched automatically at BeginPlay().\nThe automatic fetching only works for PointLightActors. Actors that have PointLightComponents\nattached to them will not be detected. These should be specified in AdditionalActorsToLookForPointLightComponents." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdditionalActorsToLookForPointLightComponents_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * List of actor(s) that contain a PointLightComponent that should contribute to the highlight effect.\n\x09 * Use AddAdditionalPointLightActor to add actors during runtime.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitLightDispatcher.h" },
		{ "ToolTip", "List of actor(s) that contain a PointLightComponent that should contribute to the highlight effect.\nUse AddAdditionalPointLightActor to add actors during runtime." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ManualPointLights_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * PointLightActors to use for the highlight effect (not available if \"Fetch Point Lights At Begin Play\" is true).\n\x09 */" },
		{ "EditCondition", "!ShouldFetchPointLightsAtBeginPlay" },
		{ "ModuleRelativePath", "Public/MRUtilityKitLightDispatcher.h" },
		{ "ToolTip", "PointLightActors to use for the highlight effect (not available if \"Fetch Point Lights At Begin Play\" is true)." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PointLightComponents_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MRUtilityKitLightDispatcher.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Collection;
	static void NewProp_ShouldFetchPointLightsAtBeginPlay_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ShouldFetchPointLightsAtBeginPlay;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AdditionalActorsToLookForPointLightComponents_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AdditionalActorsToLookForPointLightComponents;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ManualPointLights_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ManualPointLights;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PointLightComponents_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PointLightComponents;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMRUKLightDispatcher_AddAdditionalPointLightActor, "AddAdditionalPointLightActor" }, // 492926442
		{ &Z_Construct_UFunction_AMRUKLightDispatcher_ForceUpdateCollection, "ForceUpdateCollection" }, // 2530821860
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMRUKLightDispatcher>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_Collection = { "Collection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKLightDispatcher, Collection), Z_Construct_UClass_UMaterialParameterCollection_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Collection_MetaData), NewProp_Collection_MetaData) };
void Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_ShouldFetchPointLightsAtBeginPlay_SetBit(void* Obj)
{
	((AMRUKLightDispatcher*)Obj)->ShouldFetchPointLightsAtBeginPlay = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_ShouldFetchPointLightsAtBeginPlay = { "ShouldFetchPointLightsAtBeginPlay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMRUKLightDispatcher), &Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_ShouldFetchPointLightsAtBeginPlay_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShouldFetchPointLightsAtBeginPlay_MetaData), NewProp_ShouldFetchPointLightsAtBeginPlay_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_AdditionalActorsToLookForPointLightComponents_Inner = { "AdditionalActorsToLookForPointLightComponents", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_AdditionalActorsToLookForPointLightComponents = { "AdditionalActorsToLookForPointLightComponents", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKLightDispatcher, AdditionalActorsToLookForPointLightComponents), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdditionalActorsToLookForPointLightComponents_MetaData), NewProp_AdditionalActorsToLookForPointLightComponents_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_ManualPointLights_Inner = { "ManualPointLights", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_APointLight_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_ManualPointLights = { "ManualPointLights", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKLightDispatcher, ManualPointLights), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ManualPointLights_MetaData), NewProp_ManualPointLights_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_PointLightComponents_Inner = { "PointLightComponents", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_PointLightComponents = { "PointLightComponents", nullptr, (EPropertyFlags)0x0020088000002008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMRUKLightDispatcher, PointLightComponents), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PointLightComponents_MetaData), NewProp_PointLightComponents_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMRUKLightDispatcher_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_Collection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_ShouldFetchPointLightsAtBeginPlay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_AdditionalActorsToLookForPointLightComponents_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_AdditionalActorsToLookForPointLightComponents,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_ManualPointLights_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_ManualPointLights,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_PointLightComponents_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMRUKLightDispatcher_Statics::NewProp_PointLightComponents,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKLightDispatcher_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMRUKLightDispatcher_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKLightDispatcher_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMRUKLightDispatcher_Statics::ClassParams = {
	&AMRUKLightDispatcher::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMRUKLightDispatcher_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKLightDispatcher_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMRUKLightDispatcher_Statics::Class_MetaDataParams), Z_Construct_UClass_AMRUKLightDispatcher_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMRUKLightDispatcher()
{
	if (!Z_Registration_Info_UClass_AMRUKLightDispatcher.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMRUKLightDispatcher.OuterSingleton, Z_Construct_UClass_AMRUKLightDispatcher_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMRUKLightDispatcher.OuterSingleton;
}
template<> MRUTILITYKIT_API UClass* StaticClass<AMRUKLightDispatcher>()
{
	return AMRUKLightDispatcher::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMRUKLightDispatcher);
AMRUKLightDispatcher::~AMRUKLightDispatcher() {}
// End Class AMRUKLightDispatcher

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitLightDispatcher_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMRUKLightDispatcher, AMRUKLightDispatcher::StaticClass, TEXT("AMRUKLightDispatcher"), &Z_Registration_Info_UClass_AMRUKLightDispatcher, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMRUKLightDispatcher), 879639867U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitLightDispatcher_h_3600380408(TEXT("/Script/MRUtilityKit"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitLightDispatcher_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitLightDispatcher_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
