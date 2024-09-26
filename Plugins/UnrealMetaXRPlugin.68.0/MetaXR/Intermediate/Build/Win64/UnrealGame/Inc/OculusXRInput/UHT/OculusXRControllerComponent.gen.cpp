// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRInput/Public/OculusXRControllerComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRControllerComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent();
OCULUSXRINPUT_API UClass* Z_Construct_UClass_UOculusXRControllerComponent();
OCULUSXRINPUT_API UClass* Z_Construct_UClass_UOculusXRControllerComponent_NoRegister();
OCULUSXRINPUT_API UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRSide();
UPackage* Z_Construct_UPackage__Script_OculusXRInput();
// End Cross Module References

// Begin Class UOculusXRControllerComponent
void UOculusXRControllerComponent::StaticRegisterNativesUOculusXRControllerComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRControllerComponent);
UClass* Z_Construct_UClass_UOculusXRControllerComponent_NoRegister()
{
	return UOculusXRControllerComponent::StaticClass();
}
struct Z_Construct_UClass_UOculusXRControllerComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "OculusHand" },
		{ "HideCategories", "Object Activation Components|Activation Trigger" },
		{ "IncludePath", "OculusXRControllerComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OculusXRControllerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkeletonType_MetaData[] = {
		{ "Category", "Properties" },
		{ "Comment", "/** The skeleton that will be loaded */" },
		{ "ModuleRelativePath", "Public/OculusXRControllerComponent.h" },
		{ "ToolTip", "The skeleton that will be loaded" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RenderWhenUsingControllerDrivenHands_MetaData[] = {
		{ "Category", "Properties" },
		{ "Comment", "/** Should this controller be rendered when using controller driven hand poses */" },
		{ "ModuleRelativePath", "Public/OculusXRControllerComponent.h" },
		{ "ToolTip", "Should this controller be rendered when using controller driven hand poses" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SkeletonType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SkeletonType;
	static void NewProp_RenderWhenUsingControllerDrivenHands_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_RenderWhenUsingControllerDrivenHands;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRControllerComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRControllerComponent_Statics::NewProp_SkeletonType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRControllerComponent_Statics::NewProp_SkeletonType = { "SkeletonType", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRControllerComponent, SkeletonType), Z_Construct_UEnum_OculusXRInput_EOculusXRSide, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkeletonType_MetaData), NewProp_SkeletonType_MetaData) }; // 3337296388
void Z_Construct_UClass_UOculusXRControllerComponent_Statics::NewProp_RenderWhenUsingControllerDrivenHands_SetBit(void* Obj)
{
	((UOculusXRControllerComponent*)Obj)->RenderWhenUsingControllerDrivenHands = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRControllerComponent_Statics::NewProp_RenderWhenUsingControllerDrivenHands = { "RenderWhenUsingControllerDrivenHands", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRControllerComponent), &Z_Construct_UClass_UOculusXRControllerComponent_Statics::NewProp_RenderWhenUsingControllerDrivenHands_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RenderWhenUsingControllerDrivenHands_MetaData), NewProp_RenderWhenUsingControllerDrivenHands_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRControllerComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRControllerComponent_Statics::NewProp_SkeletonType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRControllerComponent_Statics::NewProp_SkeletonType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRControllerComponent_Statics::NewProp_RenderWhenUsingControllerDrivenHands,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRControllerComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRControllerComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UStaticMeshComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRInput,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRControllerComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRControllerComponent_Statics::ClassParams = {
	&UOculusXRControllerComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOculusXRControllerComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRControllerComponent_Statics::PropPointers),
	0,
	0x00A010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRControllerComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRControllerComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRControllerComponent()
{
	if (!Z_Registration_Info_UClass_UOculusXRControllerComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRControllerComponent.OuterSingleton, Z_Construct_UClass_UOculusXRControllerComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRControllerComponent.OuterSingleton;
}
template<> OCULUSXRINPUT_API UClass* StaticClass<UOculusXRControllerComponent>()
{
	return UOculusXRControllerComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRControllerComponent);
UOculusXRControllerComponent::~UOculusXRControllerComponent() {}
// End Class UOculusXRControllerComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRControllerComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRControllerComponent, UOculusXRControllerComponent::StaticClass, TEXT("UOculusXRControllerComponent"), &Z_Registration_Info_UClass_UOculusXRControllerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRControllerComponent), 1215303576U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRControllerComponent_h_3048629258(TEXT("/Script/OculusXRInput"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRControllerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRInput_Public_OculusXRControllerComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
