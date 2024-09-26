// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRHMD/Public/OculusXREventComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXREventComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
OCULUSXRHMD_API UClass* Z_Construct_UClass_UOculusXREventComponent();
OCULUSXRHMD_API UClass* Z_Construct_UClass_UOculusXREventComponent_NoRegister();
OCULUSXRHMD_API UFunction* Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature();
OCULUSXRHMD_API UFunction* Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_OculusXRHMD();
// End Cross Module References

// Begin Delegate FOculusDisplayRefreshRateChangedEventDelegate
struct Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics
{
	struct OculusXREventComponent_eventOculusDisplayRefreshRateChangedEventDelegate_Parms
	{
		float fromRefreshRate;
		float toRefreshRate;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OculusXREventComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_fromRefreshRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_toRefreshRate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics::NewProp_fromRefreshRate = { "fromRefreshRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXREventComponent_eventOculusDisplayRefreshRateChangedEventDelegate_Parms, fromRefreshRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics::NewProp_toRefreshRate = { "toRefreshRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXREventComponent_eventOculusDisplayRefreshRateChangedEventDelegate_Parms, toRefreshRate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics::NewProp_fromRefreshRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics::NewProp_toRefreshRate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXREventComponent, nullptr, "OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics::OculusXREventComponent_eventOculusDisplayRefreshRateChangedEventDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics::OculusXREventComponent_eventOculusDisplayRefreshRateChangedEventDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UOculusXREventComponent::FOculusDisplayRefreshRateChangedEventDelegate_DelegateWrapper(const FMulticastScriptDelegate& OculusDisplayRefreshRateChangedEventDelegate, float fromRefreshRate, float toRefreshRate)
{
	struct OculusXREventComponent_eventOculusDisplayRefreshRateChangedEventDelegate_Parms
	{
		float fromRefreshRate;
		float toRefreshRate;
	};
	OculusXREventComponent_eventOculusDisplayRefreshRateChangedEventDelegate_Parms Parms;
	Parms.fromRefreshRate=fromRefreshRate;
	Parms.toRefreshRate=toRefreshRate;
	OculusDisplayRefreshRateChangedEventDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOculusDisplayRefreshRateChangedEventDelegate

// Begin Delegate FOculusEyeTrackingStateChangedEventDelegate
struct Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics
{
	struct OculusXREventComponent_eventOculusEyeTrackingStateChangedEventDelegate_Parms
	{
		bool bEyeTrackingOn;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OculusXREventComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bEyeTrackingOn_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEyeTrackingOn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics::NewProp_bEyeTrackingOn_SetBit(void* Obj)
{
	((OculusXREventComponent_eventOculusEyeTrackingStateChangedEventDelegate_Parms*)Obj)->bEyeTrackingOn = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics::NewProp_bEyeTrackingOn = { "bEyeTrackingOn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXREventComponent_eventOculusEyeTrackingStateChangedEventDelegate_Parms), &Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics::NewProp_bEyeTrackingOn_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics::NewProp_bEyeTrackingOn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXREventComponent, nullptr, "OculusEyeTrackingStateChangedEventDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics::OculusXREventComponent_eventOculusEyeTrackingStateChangedEventDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics::OculusXREventComponent_eventOculusEyeTrackingStateChangedEventDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UOculusXREventComponent::FOculusEyeTrackingStateChangedEventDelegate_DelegateWrapper(const FMulticastScriptDelegate& OculusEyeTrackingStateChangedEventDelegate, bool bEyeTrackingOn)
{
	struct OculusXREventComponent_eventOculusEyeTrackingStateChangedEventDelegate_Parms
	{
		bool bEyeTrackingOn;
	};
	OculusXREventComponent_eventOculusEyeTrackingStateChangedEventDelegate_Parms Parms;
	Parms.bEyeTrackingOn=bEyeTrackingOn ? true : false;
	OculusEyeTrackingStateChangedEventDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOculusEyeTrackingStateChangedEventDelegate

// Begin Class UOculusXREventComponent
void UOculusXREventComponent::StaticRegisterNativesUOculusXREventComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXREventComponent);
UClass* Z_Construct_UClass_UOculusXREventComponent_NoRegister()
{
	return UOculusXREventComponent::StaticClass();
}
struct Z_Construct_UClass_UOculusXREventComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "OculusXRHMD" },
		{ "IncludePath", "OculusXREventComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OculusXREventComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OculusDisplayRefreshRateChanged_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXREventComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OculusEyeTrackingStateChanged_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXREventComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OculusDisplayRefreshRateChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OculusEyeTrackingStateChanged;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature, "OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature" }, // 1148263
		{ &Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature, "OculusEyeTrackingStateChangedEventDelegate__DelegateSignature" }, // 2675773717
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXREventComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UOculusXREventComponent_Statics::NewProp_OculusDisplayRefreshRateChanged = { "OculusDisplayRefreshRateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXREventComponent, OculusDisplayRefreshRateChanged), Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusDisplayRefreshRateChangedEventDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OculusDisplayRefreshRateChanged_MetaData), NewProp_OculusDisplayRefreshRateChanged_MetaData) }; // 1148263
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UOculusXREventComponent_Statics::NewProp_OculusEyeTrackingStateChanged = { "OculusEyeTrackingStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXREventComponent, OculusEyeTrackingStateChanged), Z_Construct_UDelegateFunction_UOculusXREventComponent_OculusEyeTrackingStateChangedEventDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OculusEyeTrackingStateChanged_MetaData), NewProp_OculusEyeTrackingStateChanged_MetaData) }; // 2675773717
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXREventComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXREventComponent_Statics::NewProp_OculusDisplayRefreshRateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXREventComponent_Statics::NewProp_OculusEyeTrackingStateChanged,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXREventComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXREventComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRHMD,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXREventComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXREventComponent_Statics::ClassParams = {
	&UOculusXREventComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOculusXREventComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXREventComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXREventComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXREventComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXREventComponent()
{
	if (!Z_Registration_Info_UClass_UOculusXREventComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXREventComponent.OuterSingleton, Z_Construct_UClass_UOculusXREventComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXREventComponent.OuterSingleton;
}
template<> OCULUSXRHMD_API UClass* StaticClass<UOculusXREventComponent>()
{
	return UOculusXREventComponent::StaticClass();
}
UOculusXREventComponent::UOculusXREventComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXREventComponent);
UOculusXREventComponent::~UOculusXREventComponent() {}
// End Class UOculusXREventComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXREventComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXREventComponent, UOculusXREventComponent::StaticClass, TEXT("UOculusXREventComponent"), &Z_Registration_Info_UClass_UOculusXREventComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXREventComponent), 2918630791U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXREventComponent_h_3338939363(TEXT("/Script/OculusXRHMD"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXREventComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRHMD_Public_OculusXREventComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
