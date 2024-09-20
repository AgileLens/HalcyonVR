// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MetaXRHaptics/Public/MetaXRHapticsFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMetaXRHapticsFunctionLibrary() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
METAXRHAPTICS_API UClass* Z_Construct_UClass_UMetaXRHapticClip_NoRegister();
METAXRHAPTICS_API UClass* Z_Construct_UClass_UMetaXRHapticsFunctionLibrary();
METAXRHAPTICS_API UClass* Z_Construct_UClass_UMetaXRHapticsFunctionLibrary_NoRegister();
METAXRHAPTICS_API UClass* Z_Construct_UClass_UMetaXRHapticsPlayerComponent_NoRegister();
METAXRHAPTICS_API UEnum* Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController();
UPackage* Z_Construct_UPackage__Script_MetaXRHaptics();
// End Cross Module References

// Begin Class UMetaXRHapticsFunctionLibrary Function SpawnHapticsPlayerComponent
struct Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics
{
	struct MetaXRHapticsFunctionLibrary_eventSpawnHapticsPlayerComponent_Parms
	{
		AActor* ActorToAttachTo;
		UMetaXRHapticClip* HapticClip;
		EMetaXRHapticController Controller;
		int32 Priority;
		float Amplitude;
		float FrequencyShift;
		bool bIsLooping;
		UMetaXRHapticsPlayerComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "3" },
		{ "Category", "MetaXR|Haptics" },
		{ "Comment", "/**\n\x09 * Spawns a UMetaXRHapticsPlayerComponent and attaches it to an Actor.\n\x09 *\n\x09 * Always spawn new player components with this method, Unreal's built-in \"Add Haptics SDK Player\"\n\x09 * will lead to initialization errors.\n\x09 *\n\x09 * When playback finishes, the component will *not* automatically destroy itself.\n\x09 *\n\x09 * @param ActorToAttachTo Actor to which this component will be attached to.\n\x09 * @param HapticClip Haptic clip to load.\n\x09 * @param Controller Controller used to play haptics.\n\x09 * @param Priority Playback priority, ranging from 0 (low priority) to 1024 (high priority).\n\x09 * @param Amplitude Amplitude scale, ranging from 0.0 to infinite.\n\x09 * @param FrequencyShift Frequency shift, ranging from -1.0 to 1.0.\n\x09 * @param bIsLooping Whether playback should loop.\n\x09 *\n\x09 * @return A UMetaXRHapticsPlayerComponent that plays back the haptic clip, and can be used to\n\x09 *         control playback.\n\x09 */" },
		{ "CPP_Default_Amplitude", "1.000000" },
		{ "CPP_Default_bIsLooping", "false" },
		{ "CPP_Default_FrequencyShift", "0.000000" },
		{ "CPP_Default_Priority", "512" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsFunctionLibrary.h" },
		{ "ToolTip", "Spawns a UMetaXRHapticsPlayerComponent and attaches it to an Actor.\n\nAlways spawn new player components with this method, Unreal's built-in \"Add Haptics SDK Player\"\nwill lead to initialization errors.\n\nWhen playback finishes, the component will *not* automatically destroy itself.\n\n@param ActorToAttachTo Actor to which this component will be attached to.\n@param HapticClip Haptic clip to load.\n@param Controller Controller used to play haptics.\n@param Priority Playback priority, ranging from 0 (low priority) to 1024 (high priority).\n@param Amplitude Amplitude scale, ranging from 0.0 to infinite.\n@param FrequencyShift Frequency shift, ranging from -1.0 to 1.0.\n@param bIsLooping Whether playback should loop.\n\n@return A UMetaXRHapticsPlayerComponent that plays back the haptic clip, and can be used to\n        control playback." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Controller_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Priority_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Amplitude_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrequencyShift_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsLooping_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActorToAttachTo;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HapticClip;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Controller_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Controller;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Priority;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Amplitude;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FrequencyShift;
	static void NewProp_bIsLooping_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsLooping;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_ActorToAttachTo = { "ActorToAttachTo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsFunctionLibrary_eventSpawnHapticsPlayerComponent_Parms, ActorToAttachTo), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_HapticClip = { "HapticClip", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsFunctionLibrary_eventSpawnHapticsPlayerComponent_Parms, HapticClip), Z_Construct_UClass_UMetaXRHapticClip_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_Controller_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsFunctionLibrary_eventSpawnHapticsPlayerComponent_Parms, Controller), Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Controller_MetaData), NewProp_Controller_MetaData) }; // 1144069035
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_Priority = { "Priority", nullptr, (EPropertyFlags)0x0010040000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsFunctionLibrary_eventSpawnHapticsPlayerComponent_Parms, Priority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Priority_MetaData), NewProp_Priority_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_Amplitude = { "Amplitude", nullptr, (EPropertyFlags)0x0010040000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsFunctionLibrary_eventSpawnHapticsPlayerComponent_Parms, Amplitude), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Amplitude_MetaData), NewProp_Amplitude_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_FrequencyShift = { "FrequencyShift", nullptr, (EPropertyFlags)0x0010040000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsFunctionLibrary_eventSpawnHapticsPlayerComponent_Parms, FrequencyShift), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrequencyShift_MetaData), NewProp_FrequencyShift_MetaData) };
void Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_bIsLooping_SetBit(void* Obj)
{
	((MetaXRHapticsFunctionLibrary_eventSpawnHapticsPlayerComponent_Parms*)Obj)->bIsLooping = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_bIsLooping = { "bIsLooping", nullptr, (EPropertyFlags)0x0010040000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MetaXRHapticsFunctionLibrary_eventSpawnHapticsPlayerComponent_Parms), &Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_bIsLooping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsLooping_MetaData), NewProp_bIsLooping_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsFunctionLibrary_eventSpawnHapticsPlayerComponent_Parms, ReturnValue), Z_Construct_UClass_UMetaXRHapticsPlayerComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_ActorToAttachTo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_HapticClip,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_Controller_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_Controller,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_Priority,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_Amplitude,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_FrequencyShift,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_bIsLooping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsFunctionLibrary, nullptr, "SpawnHapticsPlayerComponent", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::MetaXRHapticsFunctionLibrary_eventSpawnHapticsPlayerComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::MetaXRHapticsFunctionLibrary_eventSpawnHapticsPlayerComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsFunctionLibrary::execSpawnHapticsPlayerComponent)
{
	P_GET_OBJECT(AActor,Z_Param_ActorToAttachTo);
	P_GET_OBJECT(UMetaXRHapticClip,Z_Param_HapticClip);
	P_GET_ENUM(EMetaXRHapticController,Z_Param_Controller);
	P_GET_PROPERTY(FIntProperty,Z_Param_Priority);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Amplitude);
	P_GET_PROPERTY(FFloatProperty,Z_Param_FrequencyShift);
	P_GET_UBOOL(Z_Param_bIsLooping);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UMetaXRHapticsPlayerComponent**)Z_Param__Result=UMetaXRHapticsFunctionLibrary::SpawnHapticsPlayerComponent(Z_Param_ActorToAttachTo,Z_Param_HapticClip,EMetaXRHapticController(Z_Param_Controller),Z_Param_Priority,Z_Param_Amplitude,Z_Param_FrequencyShift,Z_Param_bIsLooping);
	P_NATIVE_END;
}
// End Class UMetaXRHapticsFunctionLibrary Function SpawnHapticsPlayerComponent

// Begin Class UMetaXRHapticsFunctionLibrary
void UMetaXRHapticsFunctionLibrary::StaticRegisterNativesUMetaXRHapticsFunctionLibrary()
{
	UClass* Class = UMetaXRHapticsFunctionLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SpawnHapticsPlayerComponent", &UMetaXRHapticsFunctionLibrary::execSpawnHapticsPlayerComponent },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMetaXRHapticsFunctionLibrary);
UClass* Z_Construct_UClass_UMetaXRHapticsFunctionLibrary_NoRegister()
{
	return UMetaXRHapticsFunctionLibrary::StaticClass();
}
struct Z_Construct_UClass_UMetaXRHapticsFunctionLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MetaXRHapticsFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMetaXRHapticsFunctionLibrary_SpawnHapticsPlayerComponent, "SpawnHapticsPlayerComponent" }, // 739752964
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMetaXRHapticsFunctionLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMetaXRHapticsFunctionLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_MetaXRHaptics,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMetaXRHapticsFunctionLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMetaXRHapticsFunctionLibrary_Statics::ClassParams = {
	&UMetaXRHapticsFunctionLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMetaXRHapticsFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UMetaXRHapticsFunctionLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMetaXRHapticsFunctionLibrary()
{
	if (!Z_Registration_Info_UClass_UMetaXRHapticsFunctionLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMetaXRHapticsFunctionLibrary.OuterSingleton, Z_Construct_UClass_UMetaXRHapticsFunctionLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMetaXRHapticsFunctionLibrary.OuterSingleton;
}
template<> METAXRHAPTICS_API UClass* StaticClass<UMetaXRHapticsFunctionLibrary>()
{
	return UMetaXRHapticsFunctionLibrary::StaticClass();
}
UMetaXRHapticsFunctionLibrary::UMetaXRHapticsFunctionLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMetaXRHapticsFunctionLibrary);
UMetaXRHapticsFunctionLibrary::~UMetaXRHapticsFunctionLibrary() {}
// End Class UMetaXRHapticsFunctionLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsFunctionLibrary_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMetaXRHapticsFunctionLibrary, UMetaXRHapticsFunctionLibrary::StaticClass, TEXT("UMetaXRHapticsFunctionLibrary"), &Z_Registration_Info_UClass_UMetaXRHapticsFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMetaXRHapticsFunctionLibrary), 520829975U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsFunctionLibrary_h_1579688681(TEXT("/Script/MetaXRHaptics"),
	Z_CompiledInDeferFile_FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsFunctionLibrary_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
