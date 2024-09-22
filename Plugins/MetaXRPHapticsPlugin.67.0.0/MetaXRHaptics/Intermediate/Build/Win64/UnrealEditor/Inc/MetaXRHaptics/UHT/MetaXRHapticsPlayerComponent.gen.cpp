// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MetaXRHaptics/Public/MetaXRHapticsPlayerComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMetaXRHapticsPlayerComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
METAXRHAPTICS_API UClass* Z_Construct_UClass_UMetaXRHapticClip_NoRegister();
METAXRHAPTICS_API UClass* Z_Construct_UClass_UMetaXRHapticsPlayerComponent();
METAXRHAPTICS_API UClass* Z_Construct_UClass_UMetaXRHapticsPlayerComponent_NoRegister();
METAXRHAPTICS_API UEnum* Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController();
UPackage* Z_Construct_UPackage__Script_MetaXRHaptics();
// End Cross Module References

// Begin Enum EMetaXRHapticController
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMetaXRHapticController;
static UEnum* EMetaXRHapticController_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMetaXRHapticController.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMetaXRHapticController.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController, (UObject*)Z_Construct_UPackage__Script_MetaXRHaptics(), TEXT("EMetaXRHapticController"));
	}
	return Z_Registration_Info_UEnum_EMetaXRHapticController.OuterSingleton;
}
template<> METAXRHAPTICS_API UEnum* StaticEnum<EMetaXRHapticController>()
{
	return EMetaXRHapticController_StaticEnum();
}
struct Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Both.DisplayName", "Both controllers" },
		{ "Both.Name", "EMetaXRHapticController::Both" },
		{ "Left.DisplayName", "Left controller" },
		{ "Left.Name", "EMetaXRHapticController::Left" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
		{ "Right.DisplayName", "Right controller" },
		{ "Right.Name", "EMetaXRHapticController::Right" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMetaXRHapticController::Left", (int64)EMetaXRHapticController::Left },
		{ "EMetaXRHapticController::Right", (int64)EMetaXRHapticController::Right },
		{ "EMetaXRHapticController::Both", (int64)EMetaXRHapticController::Both },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MetaXRHaptics,
	nullptr,
	"EMetaXRHapticController",
	"EMetaXRHapticController",
	Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController()
{
	if (!Z_Registration_Info_UEnum_EMetaXRHapticController.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMetaXRHapticController.InnerSingleton, Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMetaXRHapticController.InnerSingleton;
}
// End Enum EMetaXRHapticController

// Begin Class UMetaXRHapticsPlayerComponent Function GetAmplitude
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude_Statics
{
	struct MetaXRHapticsPlayerComponent_eventGetAmplitude_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "MetaXR|Haptics" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventGetAmplitude_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "GetAmplitude", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude_Statics::MetaXRHapticsPlayerComponent_eventGetAmplitude_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude_Statics::MetaXRHapticsPlayerComponent_eventGetAmplitude_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execGetAmplitude)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetAmplitude();
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function GetAmplitude

// Begin Class UMetaXRHapticsPlayerComponent Function GetClipDuration
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration_Statics
{
	struct MetaXRHapticsPlayerComponent_eventGetClipDuration_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR|Haptics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Gets the duration in seconds of the haptic clip.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets the duration in seconds of the haptic clip." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventGetClipDuration_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "GetClipDuration", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration_Statics::MetaXRHapticsPlayerComponent_eventGetClipDuration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration_Statics::MetaXRHapticsPlayerComponent_eventGetClipDuration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execGetClipDuration)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetClipDuration();
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function GetClipDuration

// Begin Class UMetaXRHapticsPlayerComponent Function GetController
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics
{
	struct MetaXRHapticsPlayerComponent_eventGetController_Parms
	{
		EMetaXRHapticController ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "MetaXR|Haptics" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventGetController_Parms, ReturnValue), Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController, METADATA_PARAMS(0, nullptr) }; // 1144069035
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "GetController", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics::MetaXRHapticsPlayerComponent_eventGetController_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics::MetaXRHapticsPlayerComponent_eventGetController_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execGetController)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EMetaXRHapticController*)Z_Param__Result=P_THIS->GetController();
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function GetController

// Begin Class UMetaXRHapticsPlayerComponent Function GetFrequencyShift
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift_Statics
{
	struct MetaXRHapticsPlayerComponent_eventGetFrequencyShift_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "MetaXR|Haptics" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventGetFrequencyShift_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "GetFrequencyShift", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift_Statics::MetaXRHapticsPlayerComponent_eventGetFrequencyShift_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift_Statics::MetaXRHapticsPlayerComponent_eventGetFrequencyShift_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execGetFrequencyShift)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetFrequencyShift();
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function GetFrequencyShift

// Begin Class UMetaXRHapticsPlayerComponent Function GetHapticClip
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip_Statics
{
	struct MetaXRHapticsPlayerComponent_eventGetHapticClip_Parms
	{
		UMetaXRHapticClip* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "MetaXR|Haptics" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventGetHapticClip_Parms, ReturnValue), Z_Construct_UClass_UMetaXRHapticClip_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "GetHapticClip", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip_Statics::MetaXRHapticsPlayerComponent_eventGetHapticClip_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip_Statics::MetaXRHapticsPlayerComponent_eventGetHapticClip_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execGetHapticClip)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UMetaXRHapticClip**)Z_Param__Result=P_THIS->GetHapticClip();
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function GetHapticClip

// Begin Class UMetaXRHapticsPlayerComponent Function GetLooping
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics
{
	struct MetaXRHapticsPlayerComponent_eventGetLooping_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "MetaXR|Haptics" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MetaXRHapticsPlayerComponent_eventGetLooping_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MetaXRHapticsPlayerComponent_eventGetLooping_Parms), &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "GetLooping", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics::MetaXRHapticsPlayerComponent_eventGetLooping_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics::MetaXRHapticsPlayerComponent_eventGetLooping_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execGetLooping)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetLooping();
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function GetLooping

// Begin Class UMetaXRHapticsPlayerComponent Function GetPriority
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority_Statics
{
	struct MetaXRHapticsPlayerComponent_eventGetPriority_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "MetaXR|Haptics" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventGetPriority_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "GetPriority", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority_Statics::MetaXRHapticsPlayerComponent_eventGetPriority_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority_Statics::MetaXRHapticsPlayerComponent_eventGetPriority_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execGetPriority)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetPriority();
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function GetPriority

// Begin Class UMetaXRHapticsPlayerComponent Function Play
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_Play_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR|Haptics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Start playback of the haptic clip set with the HapticClip property.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Start playback of the haptic clip set with the HapticClip property." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_Play_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "Play", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_Play_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_Play_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_Play()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_Play_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execPlay)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Play();
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function Play

// Begin Class UMetaXRHapticsPlayerComponent Function PlayOnController
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics
{
	struct MetaXRHapticsPlayerComponent_eventPlayOnController_Parms
	{
		EMetaXRHapticController InController;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR|Haptics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Start playback of the haptic clip set with the HapticClip property on the specified controller.\n\x09 *\n\x09 * Does not set the HapticController property.\n\x09 *\n\x09 * @param InController Which controller should play the haptic clip.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Start playback of the haptic clip set with the HapticClip property on the specified controller.\n\nDoes not set the HapticController property.\n\n@param InController Which controller should play the haptic clip." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InController_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_InController_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InController;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics::NewProp_InController_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics::NewProp_InController = { "InController", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventPlayOnController_Parms, InController), Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InController_MetaData), NewProp_InController_MetaData) }; // 1144069035
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics::NewProp_InController_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics::NewProp_InController,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "PlayOnController", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics::MetaXRHapticsPlayerComponent_eventPlayOnController_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics::MetaXRHapticsPlayerComponent_eventPlayOnController_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execPlayOnController)
{
	P_GET_ENUM(EMetaXRHapticController,Z_Param_InController);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlayOnController(EMetaXRHapticController(Z_Param_InController));
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function PlayOnController

// Begin Class UMetaXRHapticsPlayerComponent Function PlayWithInputs
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics
{
	struct MetaXRHapticsPlayerComponent_eventPlayWithInputs_Parms
	{
		EMetaXRHapticController InController;
		int32 InPriority;
		float InAmplitude;
		float InFrequencyShift;
		bool bInIsLooping;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR|Haptics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Start playback of the haptic clip with custom inputs.\n\x09 *\n\x09 * This is a convenience method that sets the properties corresponding to the input parameters,\n\x09 * and then starts playback.\n\x09 *\n\x09 * @param InController Which controller should play the haptic clip.\n\x09 * @param InPriority Playback priority, ranging from 0 (low priority) to 1024 (high priority).\n\x09 * @param InAmplitude Amplitude scale, ranging from 0.0 to infinite.\n\x09 * @param InFrequencyShift Frequency shift, ranging from -1.0 to 1.0.\n\x09 * @param bInIsLooping Whether playback should loop\n\x09 */" },
#endif
		{ "CPP_Default_bInIsLooping", "false" },
		{ "CPP_Default_InAmplitude", "1.000000" },
		{ "CPP_Default_InFrequencyShift", "0.000000" },
		{ "CPP_Default_InPriority", "512" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Start playback of the haptic clip with custom inputs.\n\nThis is a convenience method that sets the properties corresponding to the input parameters,\nand then starts playback.\n\n@param InController Which controller should play the haptic clip.\n@param InPriority Playback priority, ranging from 0 (low priority) to 1024 (high priority).\n@param InAmplitude Amplitude scale, ranging from 0.0 to infinite.\n@param InFrequencyShift Frequency shift, ranging from -1.0 to 1.0.\n@param bInIsLooping Whether playback should loop" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InController_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPriority_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InAmplitude_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InFrequencyShift_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInIsLooping_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_InController_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InController;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InPriority;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InAmplitude;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InFrequencyShift;
	static void NewProp_bInIsLooping_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInIsLooping;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::NewProp_InController_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::NewProp_InController = { "InController", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventPlayWithInputs_Parms, InController), Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InController_MetaData), NewProp_InController_MetaData) }; // 1144069035
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::NewProp_InPriority = { "InPriority", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventPlayWithInputs_Parms, InPriority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPriority_MetaData), NewProp_InPriority_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::NewProp_InAmplitude = { "InAmplitude", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventPlayWithInputs_Parms, InAmplitude), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InAmplitude_MetaData), NewProp_InAmplitude_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::NewProp_InFrequencyShift = { "InFrequencyShift", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventPlayWithInputs_Parms, InFrequencyShift), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InFrequencyShift_MetaData), NewProp_InFrequencyShift_MetaData) };
void Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::NewProp_bInIsLooping_SetBit(void* Obj)
{
	((MetaXRHapticsPlayerComponent_eventPlayWithInputs_Parms*)Obj)->bInIsLooping = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::NewProp_bInIsLooping = { "bInIsLooping", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MetaXRHapticsPlayerComponent_eventPlayWithInputs_Parms), &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::NewProp_bInIsLooping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInIsLooping_MetaData), NewProp_bInIsLooping_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::NewProp_InController_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::NewProp_InController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::NewProp_InPriority,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::NewProp_InAmplitude,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::NewProp_InFrequencyShift,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::NewProp_bInIsLooping,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "PlayWithInputs", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::MetaXRHapticsPlayerComponent_eventPlayWithInputs_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::MetaXRHapticsPlayerComponent_eventPlayWithInputs_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execPlayWithInputs)
{
	P_GET_ENUM(EMetaXRHapticController,Z_Param_InController);
	P_GET_PROPERTY(FIntProperty,Z_Param_InPriority);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InAmplitude);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InFrequencyShift);
	P_GET_UBOOL(Z_Param_bInIsLooping);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlayWithInputs(EMetaXRHapticController(Z_Param_InController),Z_Param_InPriority,Z_Param_InAmplitude,Z_Param_InFrequencyShift,Z_Param_bInIsLooping);
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function PlayWithInputs

// Begin Class UMetaXRHapticsPlayerComponent Function SetAmplitude
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude_Statics
{
	struct MetaXRHapticsPlayerComponent_eventSetAmplitude_Parms
	{
		float InAmplitude;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "MetaXR|Haptics" },
		{ "CPP_Default_InAmplitude", "1.000000" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InAmplitude_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InAmplitude;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude_Statics::NewProp_InAmplitude = { "InAmplitude", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventSetAmplitude_Parms, InAmplitude), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InAmplitude_MetaData), NewProp_InAmplitude_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude_Statics::NewProp_InAmplitude,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "SetAmplitude", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude_Statics::MetaXRHapticsPlayerComponent_eventSetAmplitude_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude_Statics::MetaXRHapticsPlayerComponent_eventSetAmplitude_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execSetAmplitude)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InAmplitude);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAmplitude(Z_Param_InAmplitude);
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function SetAmplitude

// Begin Class UMetaXRHapticsPlayerComponent Function SetController
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics
{
	struct MetaXRHapticsPlayerComponent_eventSetController_Parms
	{
		EMetaXRHapticController InController;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "MetaXR|Haptics" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InController_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_InController_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InController;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics::NewProp_InController_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics::NewProp_InController = { "InController", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventSetController_Parms, InController), Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InController_MetaData), NewProp_InController_MetaData) }; // 1144069035
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics::NewProp_InController_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics::NewProp_InController,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "SetController", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics::MetaXRHapticsPlayerComponent_eventSetController_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics::MetaXRHapticsPlayerComponent_eventSetController_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execSetController)
{
	P_GET_ENUM_REF(EMetaXRHapticController,Z_Param_Out_InController);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetController((EMetaXRHapticController&)(Z_Param_Out_InController));
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function SetController

// Begin Class UMetaXRHapticsPlayerComponent Function SetFrequencyShift
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift_Statics
{
	struct MetaXRHapticsPlayerComponent_eventSetFrequencyShift_Parms
	{
		float InFrequencyShift;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "MetaXR|Haptics" },
		{ "CPP_Default_InFrequencyShift", "0.000000" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InFrequencyShift_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InFrequencyShift;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift_Statics::NewProp_InFrequencyShift = { "InFrequencyShift", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventSetFrequencyShift_Parms, InFrequencyShift), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InFrequencyShift_MetaData), NewProp_InFrequencyShift_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift_Statics::NewProp_InFrequencyShift,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "SetFrequencyShift", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift_Statics::MetaXRHapticsPlayerComponent_eventSetFrequencyShift_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift_Statics::MetaXRHapticsPlayerComponent_eventSetFrequencyShift_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execSetFrequencyShift)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InFrequencyShift);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFrequencyShift(Z_Param_InFrequencyShift);
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function SetFrequencyShift

// Begin Class UMetaXRHapticsPlayerComponent Function SetHapticClip
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip_Statics
{
	struct MetaXRHapticsPlayerComponent_eventSetHapticClip_Parms
	{
		UMetaXRHapticClip* InHapticClip;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "MetaXR|Haptics" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InHapticClip;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip_Statics::NewProp_InHapticClip = { "InHapticClip", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventSetHapticClip_Parms, InHapticClip), Z_Construct_UClass_UMetaXRHapticClip_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip_Statics::NewProp_InHapticClip,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "SetHapticClip", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip_Statics::MetaXRHapticsPlayerComponent_eventSetHapticClip_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip_Statics::MetaXRHapticsPlayerComponent_eventSetHapticClip_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execSetHapticClip)
{
	P_GET_OBJECT(UMetaXRHapticClip,Z_Param_InHapticClip);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHapticClip(Z_Param_InHapticClip);
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function SetHapticClip

// Begin Class UMetaXRHapticsPlayerComponent Function SetLooping
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics
{
	struct MetaXRHapticsPlayerComponent_eventSetLooping_Parms
	{
		bool bInIsLooping;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "MetaXR|Haptics" },
		{ "CPP_Default_bInIsLooping", "false" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bInIsLooping_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static void NewProp_bInIsLooping_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInIsLooping;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics::NewProp_bInIsLooping_SetBit(void* Obj)
{
	((MetaXRHapticsPlayerComponent_eventSetLooping_Parms*)Obj)->bInIsLooping = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics::NewProp_bInIsLooping = { "bInIsLooping", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MetaXRHapticsPlayerComponent_eventSetLooping_Parms), &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics::NewProp_bInIsLooping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bInIsLooping_MetaData), NewProp_bInIsLooping_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics::NewProp_bInIsLooping,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "SetLooping", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics::MetaXRHapticsPlayerComponent_eventSetLooping_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics::MetaXRHapticsPlayerComponent_eventSetLooping_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execSetLooping)
{
	P_GET_UBOOL(Z_Param_bInIsLooping);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLooping(Z_Param_bInIsLooping);
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function SetLooping

// Begin Class UMetaXRHapticsPlayerComponent Function SetPriority
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority_Statics
{
	struct MetaXRHapticsPlayerComponent_eventSetPriority_Parms
	{
		int32 InPriority;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
		{ "Category", "MetaXR|Haptics" },
		{ "CPP_Default_InPriority", "512" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPriority_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_InPriority;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority_Statics::NewProp_InPriority = { "InPriority", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MetaXRHapticsPlayerComponent_eventSetPriority_Parms, InPriority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPriority_MetaData), NewProp_InPriority_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority_Statics::NewProp_InPriority,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "SetPriority", nullptr, nullptr, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority_Statics::MetaXRHapticsPlayerComponent_eventSetPriority_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority_Statics::MetaXRHapticsPlayerComponent_eventSetPriority_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execSetPriority)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InPriority);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPriority(Z_Param_InPriority);
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function SetPriority

// Begin Class UMetaXRHapticsPlayerComponent Function Stop
struct Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_Stop_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MetaXR|Haptics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Stops playback.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stops playback." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_Stop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMetaXRHapticsPlayerComponent, nullptr, "Stop", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_Stop_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_Stop_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_Stop()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_Stop_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMetaXRHapticsPlayerComponent::execStop)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Stop();
	P_NATIVE_END;
}
// End Class UMetaXRHapticsPlayerComponent Function Stop

// Begin Class UMetaXRHapticsPlayerComponent
void UMetaXRHapticsPlayerComponent::StaticRegisterNativesUMetaXRHapticsPlayerComponent()
{
	UClass* Class = UMetaXRHapticsPlayerComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetAmplitude", &UMetaXRHapticsPlayerComponent::execGetAmplitude },
		{ "GetClipDuration", &UMetaXRHapticsPlayerComponent::execGetClipDuration },
		{ "GetController", &UMetaXRHapticsPlayerComponent::execGetController },
		{ "GetFrequencyShift", &UMetaXRHapticsPlayerComponent::execGetFrequencyShift },
		{ "GetHapticClip", &UMetaXRHapticsPlayerComponent::execGetHapticClip },
		{ "GetLooping", &UMetaXRHapticsPlayerComponent::execGetLooping },
		{ "GetPriority", &UMetaXRHapticsPlayerComponent::execGetPriority },
		{ "Play", &UMetaXRHapticsPlayerComponent::execPlay },
		{ "PlayOnController", &UMetaXRHapticsPlayerComponent::execPlayOnController },
		{ "PlayWithInputs", &UMetaXRHapticsPlayerComponent::execPlayWithInputs },
		{ "SetAmplitude", &UMetaXRHapticsPlayerComponent::execSetAmplitude },
		{ "SetController", &UMetaXRHapticsPlayerComponent::execSetController },
		{ "SetFrequencyShift", &UMetaXRHapticsPlayerComponent::execSetFrequencyShift },
		{ "SetHapticClip", &UMetaXRHapticsPlayerComponent::execSetHapticClip },
		{ "SetLooping", &UMetaXRHapticsPlayerComponent::execSetLooping },
		{ "SetPriority", &UMetaXRHapticsPlayerComponent::execSetPriority },
		{ "Stop", &UMetaXRHapticsPlayerComponent::execStop },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMetaXRHapticsPlayerComponent);
UClass* Z_Construct_UClass_UMetaXRHapticsPlayerComponent_NoRegister()
{
	return UMetaXRHapticsPlayerComponent::StaticClass();
}
struct Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "MetaXRHaptics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Component for playing back haptic clips.\n *\n * After setting a haptic clip with the HapticClip property, playback can be started with\n * Play() or PlayWithInputs().\n *\n * The properties Amplitude, FrequencyScale, Priority and bIsLooping control playback.\n */" },
#endif
		{ "DisplayName", "MetaXR Haptics Player Component" },
		{ "IncludePath", "MetaXRHapticsPlayerComponent.h" },
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Component for playing back haptic clips.\n\nAfter setting a haptic clip with the HapticClip property, playback can be started with\nPlay() or PlayWithInputs().\n\nThe properties Amplitude, FrequencyScale, Priority and bIsLooping control playback." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HapticClip_MetaData[] = {
		{ "BlueprintGetter", "GetHapticClip" },
		{ "BlueprintSetter", "SetHapticClip" },
		{ "Category", "MetaXR|Haptics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The haptic clip played back with this player.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The haptic clip played back with this player." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Controller_MetaData[] = {
		{ "BlueprintGetter", "GetController" },
		{ "BlueprintSetter", "SetController" },
		{ "Category", "MetaXR|Haptics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The controller on which the haptic clip will be played back.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The controller on which the haptic clip will be played back." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Priority_MetaData[] = {
		{ "BlueprintGetter", "GetPriority" },
		{ "BlueprintSetter", "SetPriority" },
		{ "Category", "MetaXR|Haptics" },
		{ "ClampMax", "1024" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The playback priority of this player.\n\x09 *\n\x09 * When multiple players are playing at the same time on the same controller, only the player\n\x09 * with the highest priority will trigger vibrations.\n\x09 *\n\x09 * If multiple players have the same priority level, then the player that was started most\n\x09 * recently will trigger vibrations.\n\x09 *\n\x09 * The priority can be any integer value between 0 (low priority) and 1024 (high priority). The\n\x09 * default value is 512.\n\x09 *\n\x09 * The player's priority can be changed before and during playback.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The playback priority of this player.\n\nWhen multiple players are playing at the same time on the same controller, only the player\nwith the highest priority will trigger vibrations.\n\nIf multiple players have the same priority level, then the player that was started most\nrecently will trigger vibrations.\n\nThe priority can be any integer value between 0 (low priority) and 1024 (high priority). The\ndefault value is 512.\n\nThe player's priority can be changed before and during playback." },
#endif
		{ "UIMax", "1024" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Amplitude_MetaData[] = {
		{ "BlueprintGetter", "GetAmplitude" },
		{ "BlueprintSetter", "SetAmplitude" },
		{ "Category", "MetaXR|Haptics" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The amplitude scale, controlling the vibration intensity during playback.\n\x09 *\n\x09 * During playback, the individual amplitudes in the clip will be multiplied by the player's\n\x09 * amplitude. This changes how strong the vibration is. Amplitude values in a clip range from 0.0\n\x09 * to 1.0, and the result after applying the amplitude scale will be clipped to that range.\n\x09 *\n\x09 * An amplitude of 0.0 means that no vibration will be triggered, and an amplitude of 0.5 will\n\x09 * result in the clip being played back at half of its amplitude.\n\x09 *\n\x09 * Example: if you apply amplitude of 5.0 to a haptic clip and the following amplitudes are in the\n\x09 * clip: [0.2, 0.5, 0.1], the initial amplitude calculation would produce these values: [1.0, 2.5, 0.5]\n\x09 * which will then be clamped like this: [1.0, 1.0, 0.5]\n\x09 *\n\x09 * The property can be changed during active playback, in which case the amplitude is applied\n\x09 * immediately, with a small delay in the tens of milliseconds.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The amplitude scale, controlling the vibration intensity during playback.\n\nDuring playback, the individual amplitudes in the clip will be multiplied by the player's\namplitude. This changes how strong the vibration is. Amplitude values in a clip range from 0.0\nto 1.0, and the result after applying the amplitude scale will be clipped to that range.\n\nAn amplitude of 0.0 means that no vibration will be triggered, and an amplitude of 0.5 will\nresult in the clip being played back at half of its amplitude.\n\nExample: if you apply amplitude of 5.0 to a haptic clip and the following amplitudes are in the\nclip: [0.2, 0.5, 0.1], the initial amplitude calculation would produce these values: [1.0, 2.5, 0.5]\nwhich will then be clamped like this: [1.0, 1.0, 0.5]\n\nThe property can be changed during active playback, in which case the amplitude is applied\nimmediately, with a small delay in the tens of milliseconds." },
#endif
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrequencyShift_MetaData[] = {
		{ "BlueprintGetter", "GetFrequencyShift" },
		{ "BlueprintSetter", "SetFrequencyShift" },
		{ "Category", "MetaXR|Haptics" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "-1.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * The frequency shift, controlling the vibration frequency during playback.\n\x09 *\n\x09 * During playback, the individual frequencies in the clip will be shifted up or down. The\n\x09 * acceptable range of values is -1.0 to 1.0 inclusive. Once the frequencies in a clip have been\n\x09 * shifted, they will be clamped to the playable range of frequency values, i.e. zero to one.\n\x09 * Setting this property to 0.0 means that the frequencies will not be changed.\n\x09 *\n\x09 * Example: if you apply a frequency shift of 0.8 to a haptic clip and the following frequencies\n\x09 * are in the clip: [0.1, 0.5, 0.0], the initial frequency shift calculation will produce these\n\x09 * frequencies: [0.9, 1.3, 0.8] which will then be clamped like this: [0.9, 1.0, 0.8]\n\x09 *\n\x09 * The property can be changed during active playback, in which case the frequency shift is\n\x09 * applied immediately, with a small delay in the tens of milliseconds.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The frequency shift, controlling the vibration frequency during playback.\n\nDuring playback, the individual frequencies in the clip will be shifted up or down. The\nacceptable range of values is -1.0 to 1.0 inclusive. Once the frequencies in a clip have been\nshifted, they will be clamped to the playable range of frequency values, i.e. zero to one.\nSetting this property to 0.0 means that the frequencies will not be changed.\n\nExample: if you apply a frequency shift of 0.8 to a haptic clip and the following frequencies\nare in the clip: [0.1, 0.5, 0.0], the initial frequency shift calculation will produce these\nfrequencies: [0.9, 1.3, 0.8] which will then be clamped like this: [0.9, 1.0, 0.8]\n\nThe property can be changed during active playback, in which case the frequency shift is\napplied immediately, with a small delay in the tens of milliseconds." },
#endif
		{ "UIMax", "1.0" },
		{ "UIMin", "-1.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsLooping_MetaData[] = {
		{ "BlueprintGetter", "GetLooping" },
		{ "BlueprintSetter", "SetLooping" },
		{ "Category", "MetaXR|Haptics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Whether playback is looped.\n\x09 *\n\x09 * When looping is enabled, clip playback will be repeated indefinitely.\n\x09 *\n\x09 * Looping can be enabled or disabled during playback.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MetaXRHapticsPlayerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether playback is looped.\n\nWhen looping is enabled, clip playback will be repeated indefinitely.\n\nLooping can be enabled or disabled during playback." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HapticClip;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Controller_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Controller;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Priority;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Amplitude;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FrequencyShift;
	static void NewProp_bIsLooping_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsLooping;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetAmplitude, "GetAmplitude" }, // 2284739854
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetClipDuration, "GetClipDuration" }, // 1521393990
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetController, "GetController" }, // 3006008221
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetFrequencyShift, "GetFrequencyShift" }, // 1824934077
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetHapticClip, "GetHapticClip" }, // 447844822
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetLooping, "GetLooping" }, // 2899636756
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_GetPriority, "GetPriority" }, // 2025798329
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_Play, "Play" }, // 1073122997
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayOnController, "PlayOnController" }, // 2558137549
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_PlayWithInputs, "PlayWithInputs" }, // 4065695044
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetAmplitude, "SetAmplitude" }, // 3406348699
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetController, "SetController" }, // 3017946213
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetFrequencyShift, "SetFrequencyShift" }, // 3775637710
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetHapticClip, "SetHapticClip" }, // 483772127
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetLooping, "SetLooping" }, // 3843878799
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_SetPriority, "SetPriority" }, // 2466557945
		{ &Z_Construct_UFunction_UMetaXRHapticsPlayerComponent_Stop, "Stop" }, // 3057226965
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMetaXRHapticsPlayerComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_HapticClip = { "HapticClip", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMetaXRHapticsPlayerComponent, HapticClip), Z_Construct_UClass_UMetaXRHapticClip_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HapticClip_MetaData), NewProp_HapticClip_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_Controller_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMetaXRHapticsPlayerComponent, Controller), Z_Construct_UEnum_MetaXRHaptics_EMetaXRHapticController, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Controller_MetaData), NewProp_Controller_MetaData) }; // 1144069035
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_Priority = { "Priority", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMetaXRHapticsPlayerComponent, Priority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Priority_MetaData), NewProp_Priority_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_Amplitude = { "Amplitude", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMetaXRHapticsPlayerComponent, Amplitude), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Amplitude_MetaData), NewProp_Amplitude_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_FrequencyShift = { "FrequencyShift", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMetaXRHapticsPlayerComponent, FrequencyShift), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrequencyShift_MetaData), NewProp_FrequencyShift_MetaData) };
void Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_bIsLooping_SetBit(void* Obj)
{
	((UMetaXRHapticsPlayerComponent*)Obj)->bIsLooping = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_bIsLooping = { "bIsLooping", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UMetaXRHapticsPlayerComponent), &Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_bIsLooping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsLooping_MetaData), NewProp_bIsLooping_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_HapticClip,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_Controller_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_Controller,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_Priority,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_Amplitude,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_FrequencyShift,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::NewProp_bIsLooping,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_MetaXRHaptics,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::ClassParams = {
	&UMetaXRHapticsPlayerComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMetaXRHapticsPlayerComponent()
{
	if (!Z_Registration_Info_UClass_UMetaXRHapticsPlayerComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMetaXRHapticsPlayerComponent.OuterSingleton, Z_Construct_UClass_UMetaXRHapticsPlayerComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMetaXRHapticsPlayerComponent.OuterSingleton;
}
template<> METAXRHAPTICS_API UClass* StaticClass<UMetaXRHapticsPlayerComponent>()
{
	return UMetaXRHapticsPlayerComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMetaXRHapticsPlayerComponent);
UMetaXRHapticsPlayerComponent::~UMetaXRHapticsPlayerComponent() {}
// End Class UMetaXRHapticsPlayerComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EMetaXRHapticController_StaticEnum, TEXT("EMetaXRHapticController"), &Z_Registration_Info_UEnum_EMetaXRHapticController, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1144069035U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMetaXRHapticsPlayerComponent, UMetaXRHapticsPlayerComponent::StaticClass, TEXT("UMetaXRHapticsPlayerComponent"), &Z_Registration_Info_UClass_UMetaXRHapticsPlayerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMetaXRHapticsPlayerComponent), 1311010511U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h_308761150(TEXT("/Script/MetaXRHaptics"),
	Z_CompiledInDeferFile_FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Nora_Desktop_HalcyonVR_Plugins_MetaXRPHapticsPlugin_67_0_0_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsPlayerComponent_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
