// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRMovement/Public/OculusXRBodyTrackingComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRBodyTrackingComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UPoseableMeshComponent();
OCULUSXRMOVEMENT_API UClass* Z_Construct_UClass_UOculusXRBodyTrackingComponent();
OCULUSXRMOVEMENT_API UClass* Z_Construct_UClass_UOculusXRBodyTrackingComponent_NoRegister();
OCULUSXRMOVEMENT_API UEnum* Z_Construct_UEnum_OculusXRMovement_EOculusXRBodyTrackingMode();
OCULUSXRMOVEMENT_API UEnum* Z_Construct_UEnum_OculusXRMovement_EOculusXRBoneID();
UPackage* Z_Construct_UPackage__Script_OculusXRMovement();
// End Cross Module References

// Begin Enum EOculusXRBodyTrackingMode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRBodyTrackingMode;
static UEnum* EOculusXRBodyTrackingMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRBodyTrackingMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRBodyTrackingMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRMovement_EOculusXRBodyTrackingMode, (UObject*)Z_Construct_UPackage__Script_OculusXRMovement(), TEXT("EOculusXRBodyTrackingMode"));
	}
	return Z_Registration_Info_UEnum_EOculusXRBodyTrackingMode.OuterSingleton;
}
template<> OCULUSXRMOVEMENT_API UEnum* StaticEnum<EOculusXRBodyTrackingMode>()
{
	return EOculusXRBodyTrackingMode_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRMovement_EOculusXRBodyTrackingMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/OculusXRBodyTrackingComponent.h" },
		{ "NoTracking.Name", "EOculusXRBodyTrackingMode::NoTracking" },
		{ "PositionAndRotation.Name", "EOculusXRBodyTrackingMode::PositionAndRotation" },
		{ "RotationOnly.Name", "EOculusXRBodyTrackingMode::RotationOnly" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRBodyTrackingMode::PositionAndRotation", (int64)EOculusXRBodyTrackingMode::PositionAndRotation },
		{ "EOculusXRBodyTrackingMode::RotationOnly", (int64)EOculusXRBodyTrackingMode::RotationOnly },
		{ "EOculusXRBodyTrackingMode::NoTracking", (int64)EOculusXRBodyTrackingMode::NoTracking },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRMovement_EOculusXRBodyTrackingMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRMovement,
	nullptr,
	"EOculusXRBodyTrackingMode",
	"EOculusXRBodyTrackingMode",
	Z_Construct_UEnum_OculusXRMovement_EOculusXRBodyTrackingMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRMovement_EOculusXRBodyTrackingMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRMovement_EOculusXRBodyTrackingMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRMovement_EOculusXRBodyTrackingMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRMovement_EOculusXRBodyTrackingMode()
{
	if (!Z_Registration_Info_UEnum_EOculusXRBodyTrackingMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRBodyTrackingMode.InnerSingleton, Z_Construct_UEnum_OculusXRMovement_EOculusXRBodyTrackingMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRBodyTrackingMode.InnerSingleton;
}
// End Enum EOculusXRBodyTrackingMode

// Begin Class UOculusXRBodyTrackingComponent Function ResetAllBoneTransforms
struct Z_Construct_UFunction_UOculusXRBodyTrackingComponent_ResetAllBoneTransforms_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * Restore all bones to their initial transforms\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRBodyTrackingComponent.h" },
		{ "ToolTip", "Restore all bones to their initial transforms" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRBodyTrackingComponent_ResetAllBoneTransforms_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRBodyTrackingComponent, nullptr, "ResetAllBoneTransforms", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRBodyTrackingComponent_ResetAllBoneTransforms_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRBodyTrackingComponent_ResetAllBoneTransforms_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UOculusXRBodyTrackingComponent_ResetAllBoneTransforms()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRBodyTrackingComponent_ResetAllBoneTransforms_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRBodyTrackingComponent::execResetAllBoneTransforms)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetAllBoneTransforms();
	P_NATIVE_END;
}
// End Class UOculusXRBodyTrackingComponent Function ResetAllBoneTransforms

// Begin Class UOculusXRBodyTrackingComponent
void UOculusXRBodyTrackingComponent::StaticRegisterNativesUOculusXRBodyTrackingComponent()
{
	UClass* Class = UOculusXRBodyTrackingComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ResetAllBoneTransforms", &UOculusXRBodyTrackingComponent::execResetAllBoneTransforms },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRBodyTrackingComponent);
UClass* Z_Construct_UClass_UOculusXRBodyTrackingComponent_NoRegister()
{
	return UOculusXRBodyTrackingComponent::StaticClass();
}
struct Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "OculusXRHMD" },
		{ "DisplayName", "OculusXR Body Tracking Component" },
		{ "HideCategories", "Object Physics Object Mobility Trigger" },
		{ "IncludePath", "OculusXRBodyTrackingComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OculusXRBodyTrackingComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BodyTrackingMode_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * How are the results of body tracking applied to the mesh.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRBodyTrackingComponent.h" },
		{ "ToolTip", "How are the results of body tracking applied to the mesh." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneNames_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * The bone name associated with each bone ID.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRBodyTrackingComponent.h" },
		{ "ToolTip", "The bone name associated with each bone ID." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ConfidenceThreshold_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "ClampMax", "1" },
		{ "ClampMin", "0" },
		{ "Comment", "/**\n\x09 * Do not apply body state to bones if confidence is lower than this value. Confidence is in range [0,1].\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRBodyTrackingComponent.h" },
		{ "ToolTip", "Do not apply body state to bones if confidence is lower than this value. Confidence is in range [0,1]." },
		{ "UIMax", "1" },
		{ "UIMin", "0" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_BodyTrackingMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BodyTrackingMode;
	static const UECodeGen_Private::FNamePropertyParams NewProp_BoneNames_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BoneNames_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BoneNames_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_BoneNames;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ConfidenceThreshold;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOculusXRBodyTrackingComponent_ResetAllBoneTransforms, "ResetAllBoneTransforms" }, // 4179914195
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRBodyTrackingComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::NewProp_BodyTrackingMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::NewProp_BodyTrackingMode = { "BodyTrackingMode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRBodyTrackingComponent, BodyTrackingMode), Z_Construct_UEnum_OculusXRMovement_EOculusXRBodyTrackingMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BodyTrackingMode_MetaData), NewProp_BodyTrackingMode_MetaData) }; // 3493275299
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::NewProp_BoneNames_ValueProp = { "BoneNames", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::NewProp_BoneNames_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::NewProp_BoneNames_Key_KeyProp = { "BoneNames_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_OculusXRMovement_EOculusXRBoneID, METADATA_PARAMS(0, nullptr) }; // 1177430570
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::NewProp_BoneNames = { "BoneNames", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRBodyTrackingComponent, BoneNames), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneNames_MetaData), NewProp_BoneNames_MetaData) }; // 1177430570
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::NewProp_ConfidenceThreshold = { "ConfidenceThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRBodyTrackingComponent, ConfidenceThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ConfidenceThreshold_MetaData), NewProp_ConfidenceThreshold_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::NewProp_BodyTrackingMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::NewProp_BodyTrackingMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::NewProp_BoneNames_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::NewProp_BoneNames_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::NewProp_BoneNames_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::NewProp_BoneNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::NewProp_ConfidenceThreshold,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPoseableMeshComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRMovement,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::ClassParams = {
	&UOculusXRBodyTrackingComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::PropPointers),
	0,
	0x00B010A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRBodyTrackingComponent()
{
	if (!Z_Registration_Info_UClass_UOculusXRBodyTrackingComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRBodyTrackingComponent.OuterSingleton, Z_Construct_UClass_UOculusXRBodyTrackingComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRBodyTrackingComponent.OuterSingleton;
}
template<> OCULUSXRMOVEMENT_API UClass* StaticClass<UOculusXRBodyTrackingComponent>()
{
	return UOculusXRBodyTrackingComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRBodyTrackingComponent);
UOculusXRBodyTrackingComponent::~UOculusXRBodyTrackingComponent() {}
// End Class UOculusXRBodyTrackingComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRBodyTrackingComponent_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOculusXRBodyTrackingMode_StaticEnum, TEXT("EOculusXRBodyTrackingMode"), &Z_Registration_Info_UEnum_EOculusXRBodyTrackingMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3493275299U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRBodyTrackingComponent, UOculusXRBodyTrackingComponent::StaticClass, TEXT("UOculusXRBodyTrackingComponent"), &Z_Registration_Info_UClass_UOculusXRBodyTrackingComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRBodyTrackingComponent), 452331888U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRBodyTrackingComponent_h_1432778047(TEXT("/Script/OculusXRMovement"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRBodyTrackingComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRBodyTrackingComponent_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRBodyTrackingComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRBodyTrackingComponent_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
