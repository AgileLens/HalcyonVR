// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRMovement/Public/OculusXRFaceTrackingComponent.h"
#include "OculusXRMovement/Public/OculusXRMovementTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRFaceTrackingComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_USkinnedMeshComponent_NoRegister();
OCULUSXRMOVEMENT_API UClass* Z_Construct_UClass_UOculusXRFaceTrackingComponent();
OCULUSXRMOVEMENT_API UClass* Z_Construct_UClass_UOculusXRFaceTrackingComponent_NoRegister();
OCULUSXRMOVEMENT_API UEnum* Z_Construct_UEnum_OculusXRMovement_EOculusXRFaceExpression();
OCULUSXRMOVEMENT_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRFaceExpressionModifier();
UPackage* Z_Construct_UPackage__Script_OculusXRMovement();
// End Cross Module References

// Begin Class UOculusXRFaceTrackingComponent Function ClearExpressionValues
struct Z_Construct_UFunction_UOculusXRFaceTrackingComponent_ClearExpressionValues_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Components|OculusXRFaceTracking" },
		{ "Comment", "/**\n\x09 * Clears all face expression values.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRFaceTrackingComponent.h" },
		{ "ToolTip", "Clears all face expression values." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFaceTrackingComponent_ClearExpressionValues_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFaceTrackingComponent, nullptr, "ClearExpressionValues", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFaceTrackingComponent_ClearExpressionValues_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFaceTrackingComponent_ClearExpressionValues_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UOculusXRFaceTrackingComponent_ClearExpressionValues()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFaceTrackingComponent_ClearExpressionValues_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFaceTrackingComponent::execClearExpressionValues)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearExpressionValues();
	P_NATIVE_END;
}
// End Class UOculusXRFaceTrackingComponent Function ClearExpressionValues

// Begin Class UOculusXRFaceTrackingComponent Function GetExpressionValue
struct Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics
{
	struct OculusXRFaceTrackingComponent_eventGetExpressionValue_Parms
	{
		EOculusXRFaceExpression Expression;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Components|OculusXRFaceTracking" },
		{ "Comment", "/**\n\x09 * Get a face expression value given an expression key.\n\x09 *\n\x09 * @param Expression : The expression key that will be queried.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRFaceTrackingComponent.h" },
		{ "ToolTip", "Get a face expression value given an expression key.\n\n@param Expression : The expression key that will be queried." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Expression_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Expression;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::NewProp_Expression_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::NewProp_Expression = { "Expression", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFaceTrackingComponent_eventGetExpressionValue_Parms, Expression), Z_Construct_UEnum_OculusXRMovement_EOculusXRFaceExpression, METADATA_PARAMS(0, nullptr) }; // 44156253
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFaceTrackingComponent_eventGetExpressionValue_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::NewProp_Expression_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::NewProp_Expression,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFaceTrackingComponent, nullptr, "GetExpressionValue", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::OculusXRFaceTrackingComponent_eventGetExpressionValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::OculusXRFaceTrackingComponent_eventGetExpressionValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFaceTrackingComponent::execGetExpressionValue)
{
	P_GET_ENUM(EOculusXRFaceExpression,Z_Param_Expression);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetExpressionValue(EOculusXRFaceExpression(Z_Param_Expression));
	P_NATIVE_END;
}
// End Class UOculusXRFaceTrackingComponent Function GetExpressionValue

// Begin Class UOculusXRFaceTrackingComponent Function SetExpressionValue
struct Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics
{
	struct OculusXRFaceTrackingComponent_eventSetExpressionValue_Parms
	{
		EOculusXRFaceExpression Expression;
		float Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Components|OculusXRFaceTracking" },
		{ "Comment", "/**\n\x09 * Set face expression value with expression key and value(0-1).\n\x09 *\n\x09 * @param Expression : The expression key that will be modified.\n\x09 * @param Value : The new value to assign to the expression, 0 will remove all changes.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRFaceTrackingComponent.h" },
		{ "ToolTip", "Set face expression value with expression key and value(0-1).\n\n@param Expression : The expression key that will be modified.\n@param Value : The new value to assign to the expression, 0 will remove all changes." },
		{ "UnsafeDuringActorConstruction", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Expression_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Expression;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::NewProp_Expression_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::NewProp_Expression = { "Expression", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFaceTrackingComponent_eventSetExpressionValue_Parms, Expression), Z_Construct_UEnum_OculusXRMovement_EOculusXRFaceExpression, METADATA_PARAMS(0, nullptr) }; // 44156253
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRFaceTrackingComponent_eventSetExpressionValue_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::NewProp_Expression_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::NewProp_Expression,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRFaceTrackingComponent, nullptr, "SetExpressionValue", nullptr, nullptr, Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::OculusXRFaceTrackingComponent_eventSetExpressionValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::OculusXRFaceTrackingComponent_eventSetExpressionValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRFaceTrackingComponent::execSetExpressionValue)
{
	P_GET_ENUM(EOculusXRFaceExpression,Z_Param_Expression);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetExpressionValue(EOculusXRFaceExpression(Z_Param_Expression),Z_Param_Value);
	P_NATIVE_END;
}
// End Class UOculusXRFaceTrackingComponent Function SetExpressionValue

// Begin Class UOculusXRFaceTrackingComponent
void UOculusXRFaceTrackingComponent::StaticRegisterNativesUOculusXRFaceTrackingComponent()
{
	UClass* Class = UOculusXRFaceTrackingComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClearExpressionValues", &UOculusXRFaceTrackingComponent::execClearExpressionValues },
		{ "GetExpressionValue", &UOculusXRFaceTrackingComponent::execGetExpressionValue },
		{ "SetExpressionValue", &UOculusXRFaceTrackingComponent::execSetExpressionValue },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRFaceTrackingComponent);
UClass* Z_Construct_UClass_UOculusXRFaceTrackingComponent_NoRegister()
{
	return UOculusXRFaceTrackingComponent::StaticClass();
}
struct Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "OculusXRHMD" },
		{ "DisplayName", "OculusXR Face Tracking Component" },
		{ "IncludePath", "OculusXRFaceTrackingComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/OculusXRFaceTrackingComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetMeshComponentName_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * The name of the skinned mesh component that this component targets for facial expression.\n\x09 * This must be the name of a component on this actor.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRFaceTrackingComponent.h" },
		{ "ToolTip", "The name of the skinned mesh component that this component targets for facial expression.\nThis must be the name of a component on this actor." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InvalidFaceDataResetTime_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * If the face data is invalid for at least this or longer than this time then all face blendshapes/morph targets are reset to zero.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRFaceTrackingComponent.h" },
		{ "ToolTip", "If the face data is invalid for at least this or longer than this time then all face blendshapes/morph targets are reset to zero." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExpressionNames_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * The list of expressions that this component supports.\n\x09 * Names are validated on startup so only valid morph targets on the skeletal mesh will be targeted.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRFaceTrackingComponent.h" },
		{ "ToolTip", "The list of expressions that this component supports.\nNames are validated on startup so only valid morph targets on the skeletal mesh will be targeted." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExpressionModifiers_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * An array of optional expression modifiers that can be applied.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRFaceTrackingComponent.h" },
		{ "ToolTip", "An array of optional expression modifiers that can be applied." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUpdateFace_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * This flag determines if the face should be updated or not during the components tick.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRFaceTrackingComponent.h" },
		{ "ToolTip", "This flag determines if the face should be updated or not during the components tick." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseModifiers_MetaData[] = {
		{ "Category", "OculusXR|Movement" },
		{ "Comment", "/**\n\x09 * This flag determines if the face should be modified with Expression Modifiers or not during the components tick.\n\x09 */" },
		{ "ModuleRelativePath", "Public/OculusXRFaceTrackingComponent.h" },
		{ "ToolTip", "This flag determines if the face should be modified with Expression Modifiers or not during the components tick." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetMeshComponent_MetaData[] = {
		{ "Comment", "// The mesh component targeted for expressions\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OculusXRFaceTrackingComponent.h" },
		{ "ToolTip", "The mesh component targeted for expressions" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_TargetMeshComponentName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InvalidFaceDataResetTime;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ExpressionNames_ValueProp;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ExpressionNames_Key_KeyProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ExpressionNames_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ExpressionNames;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExpressionModifiers_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ExpressionModifiers;
	static void NewProp_bUpdateFace_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUpdateFace;
	static void NewProp_bUseModifiers_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseModifiers;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetMeshComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOculusXRFaceTrackingComponent_ClearExpressionValues, "ClearExpressionValues" }, // 3585529491
		{ &Z_Construct_UFunction_UOculusXRFaceTrackingComponent_GetExpressionValue, "GetExpressionValue" }, // 3875117312
		{ &Z_Construct_UFunction_UOculusXRFaceTrackingComponent_SetExpressionValue, "SetExpressionValue" }, // 330382578
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRFaceTrackingComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_TargetMeshComponentName = { "TargetMeshComponentName", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRFaceTrackingComponent, TargetMeshComponentName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetMeshComponentName_MetaData), NewProp_TargetMeshComponentName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_InvalidFaceDataResetTime = { "InvalidFaceDataResetTime", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRFaceTrackingComponent, InvalidFaceDataResetTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InvalidFaceDataResetTime_MetaData), NewProp_InvalidFaceDataResetTime_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_ExpressionNames_ValueProp = { "ExpressionNames", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_ExpressionNames_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_ExpressionNames_Key_KeyProp = { "ExpressionNames_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_OculusXRMovement_EOculusXRFaceExpression, METADATA_PARAMS(0, nullptr) }; // 44156253
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_ExpressionNames = { "ExpressionNames", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRFaceTrackingComponent, ExpressionNames), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExpressionNames_MetaData), NewProp_ExpressionNames_MetaData) }; // 44156253
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_ExpressionModifiers_Inner = { "ExpressionModifiers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOculusXRFaceExpressionModifier, METADATA_PARAMS(0, nullptr) }; // 1839236931
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_ExpressionModifiers = { "ExpressionModifiers", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRFaceTrackingComponent, ExpressionModifiers), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExpressionModifiers_MetaData), NewProp_ExpressionModifiers_MetaData) }; // 1839236931
void Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_bUpdateFace_SetBit(void* Obj)
{
	((UOculusXRFaceTrackingComponent*)Obj)->bUpdateFace = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_bUpdateFace = { "bUpdateFace", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRFaceTrackingComponent), &Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_bUpdateFace_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUpdateFace_MetaData), NewProp_bUpdateFace_MetaData) };
void Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_bUseModifiers_SetBit(void* Obj)
{
	((UOculusXRFaceTrackingComponent*)Obj)->bUseModifiers = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_bUseModifiers = { "bUseModifiers", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOculusXRFaceTrackingComponent), &Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_bUseModifiers_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseModifiers_MetaData), NewProp_bUseModifiers_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_TargetMeshComponent = { "TargetMeshComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRFaceTrackingComponent, TargetMeshComponent), Z_Construct_UClass_USkinnedMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetMeshComponent_MetaData), NewProp_TargetMeshComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_TargetMeshComponentName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_InvalidFaceDataResetTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_ExpressionNames_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_ExpressionNames_Key_KeyProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_ExpressionNames_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_ExpressionNames,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_ExpressionModifiers_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_ExpressionModifiers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_bUpdateFace,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_bUseModifiers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::NewProp_TargetMeshComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRMovement,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::ClassParams = {
	&UOculusXRFaceTrackingComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRFaceTrackingComponent()
{
	if (!Z_Registration_Info_UClass_UOculusXRFaceTrackingComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRFaceTrackingComponent.OuterSingleton, Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRFaceTrackingComponent.OuterSingleton;
}
template<> OCULUSXRMOVEMENT_API UClass* StaticClass<UOculusXRFaceTrackingComponent>()
{
	return UOculusXRFaceTrackingComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRFaceTrackingComponent);
UOculusXRFaceTrackingComponent::~UOculusXRFaceTrackingComponent() {}
// End Class UOculusXRFaceTrackingComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRFaceTrackingComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRFaceTrackingComponent, UOculusXRFaceTrackingComponent::StaticClass, TEXT("UOculusXRFaceTrackingComponent"), &Z_Registration_Info_UClass_UOculusXRFaceTrackingComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRFaceTrackingComponent), 3619324799U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRFaceTrackingComponent_h_868905094(TEXT("/Script/OculusXRMovement"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRFaceTrackingComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRFaceTrackingComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
