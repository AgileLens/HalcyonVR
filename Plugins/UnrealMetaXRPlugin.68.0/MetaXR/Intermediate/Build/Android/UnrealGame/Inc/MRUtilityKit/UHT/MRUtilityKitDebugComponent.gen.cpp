// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MRUtilityKit/Public/MRUtilityKitDebugComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMRUtilityKitDebugComponent() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
MRUTILITYKIT_API UClass* Z_Construct_UClass_UMRUKDebugComponent();
MRUTILITYKIT_API UClass* Z_Construct_UClass_UMRUKDebugComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_MRUtilityKit();
// End Cross Module References

// Begin Class UMRUKDebugComponent Function HideAnchor
struct Z_Construct_UFunction_UMRUKDebugComponent_HideAnchor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Hide the current anchor. This method needs only to be called to hide the anchor\n\x09 * that was displayed by ShowAnchorAtRayHit().\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDebugComponent.h" },
		{ "ToolTip", "Hide the current anchor. This method needs only to be called to hide the anchor\nthat was displayed by ShowAnchorAtRayHit()." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKDebugComponent_HideAnchor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKDebugComponent, nullptr, "HideAnchor", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKDebugComponent_HideAnchor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKDebugComponent_HideAnchor_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMRUKDebugComponent_HideAnchor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKDebugComponent_HideAnchor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKDebugComponent::execHideAnchor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HideAnchor();
	P_NATIVE_END;
}
// End Class UMRUKDebugComponent Function HideAnchor

// Begin Class UMRUKDebugComponent Function HideAnchorSpace
struct Z_Construct_UFunction_UMRUKDebugComponent_HideAnchorSpace_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Hide the current anchor space actor. This method needs only to be called to hide the\n\x09 * anchor space that was displayed by ShowAnchorAtRayHit().\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDebugComponent.h" },
		{ "ToolTip", "Hide the current anchor space actor. This method needs only to be called to hide the\nanchor space that was displayed by ShowAnchorAtRayHit()." },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKDebugComponent_HideAnchorSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKDebugComponent, nullptr, "HideAnchorSpace", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKDebugComponent_HideAnchorSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKDebugComponent_HideAnchorSpace_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMRUKDebugComponent_HideAnchorSpace()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKDebugComponent_HideAnchorSpace_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKDebugComponent::execHideAnchorSpace)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HideAnchorSpace();
	P_NATIVE_END;
}
// End Class UMRUKDebugComponent Function HideAnchorSpace

// Begin Class UMRUKDebugComponent Function ShowAnchorAtRayHit
struct Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics
{
	struct MRUKDebugComponent_eventShowAnchorAtRayHit_Parms
	{
		FVector Origin;
		FVector Direction;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Shoot a ray and display the anchors coordinate system and labels that was hit by the ray if any.\n\x09 * Call HideAnchor() to get rid of the displayed anchor.\n\x09 * @param Origin The ray origin.\n\x09 * @param Direction The ray direction.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDebugComponent.h" },
		{ "ToolTip", "Shoot a ray and display the anchors coordinate system and labels that was hit by the ray if any.\nCall HideAnchor() to get rid of the displayed anchor.\n@param Origin The ray origin.\n@param Direction The ray direction." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Origin_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Origin;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics::NewProp_Origin = { "Origin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDebugComponent_eventShowAnchorAtRayHit_Parms, Origin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Origin_MetaData), NewProp_Origin_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDebugComponent_eventShowAnchorAtRayHit_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Direction_MetaData), NewProp_Direction_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics::NewProp_Origin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics::NewProp_Direction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKDebugComponent, nullptr, "ShowAnchorAtRayHit", nullptr, nullptr, Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics::MRUKDebugComponent_eventShowAnchorAtRayHit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics::MRUKDebugComponent_eventShowAnchorAtRayHit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKDebugComponent::execShowAnchorAtRayHit)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Origin);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Direction);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowAnchorAtRayHit(Z_Param_Out_Origin,Z_Param_Out_Direction);
	P_NATIVE_END;
}
// End Class UMRUKDebugComponent Function ShowAnchorAtRayHit

// Begin Class UMRUKDebugComponent Function ShowAnchorSpaceAtRayHit
struct Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics
{
	struct MRUKDebugComponent_eventShowAnchorSpaceAtRayHit_Parms
	{
		FVector Origin;
		FVector Direction;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * Shoot a ray and display the anchors space that was hit by the ray if any.\n\x09 * Call HideAnchorSpace() to get rid of the displayed anchor space.\n\x09 * @param Origin The ray origin.\n\x09 * @param Direction The ray direction.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDebugComponent.h" },
		{ "ToolTip", "Shoot a ray and display the anchors space that was hit by the ray if any.\nCall HideAnchorSpace() to get rid of the displayed anchor space.\n@param Origin The ray origin.\n@param Direction The ray direction." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Origin_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Origin;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics::NewProp_Origin = { "Origin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDebugComponent_eventShowAnchorSpaceAtRayHit_Parms, Origin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Origin_MetaData), NewProp_Origin_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKDebugComponent_eventShowAnchorSpaceAtRayHit_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Direction_MetaData), NewProp_Direction_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics::NewProp_Origin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics::NewProp_Direction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKDebugComponent, nullptr, "ShowAnchorSpaceAtRayHit", nullptr, nullptr, Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics::MRUKDebugComponent_eventShowAnchorSpaceAtRayHit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics::MRUKDebugComponent_eventShowAnchorSpaceAtRayHit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKDebugComponent::execShowAnchorSpaceAtRayHit)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Origin);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Direction);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ShowAnchorSpaceAtRayHit(Z_Param_Out_Origin,Z_Param_Out_Direction);
	P_NATIVE_END;
}
// End Class UMRUKDebugComponent Function ShowAnchorSpaceAtRayHit

// Begin Class UMRUKDebugComponent
void UMRUKDebugComponent::StaticRegisterNativesUMRUKDebugComponent()
{
	UClass* Class = UMRUKDebugComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "HideAnchor", &UMRUKDebugComponent::execHideAnchor },
		{ "HideAnchorSpace", &UMRUKDebugComponent::execHideAnchorSpace },
		{ "ShowAnchorAtRayHit", &UMRUKDebugComponent::execShowAnchorAtRayHit },
		{ "ShowAnchorSpaceAtRayHit", &UMRUKDebugComponent::execShowAnchorSpaceAtRayHit },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMRUKDebugComponent);
UClass* Z_Construct_UClass_UMRUKDebugComponent_NoRegister()
{
	return UMRUKDebugComponent::StaticClass();
}
struct Z_Construct_UClass_UMRUKDebugComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "MRUtilityKit" },
		{ "Comment", "/**\n * Various debugging utilities for the scene.\n * This component can for example attached to the player pawn. The various methods can\n * then be called on input from the pawn.\n */" },
		{ "DisplayName", "MR Utility Kit Debug Component" },
		{ "IncludePath", "MRUtilityKitDebugComponent.h" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDebugComponent.h" },
		{ "ToolTip", "Various debugging utilities for the scene.\nThis component can for example attached to the player pawn. The various methods can\nthen be called on input from the pawn." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GizmoActorClass_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * The gizmo to show when visualizing an anchor.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDebugComponent.h" },
		{ "ToolTip", "The gizmo to show when visualizing an anchor." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextActorClass_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * The text to show when visualizing an anchor.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDebugComponent.h" },
		{ "ToolTip", "The text to show when visualizing an anchor." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GizmoScale_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * The scale that should be applied to the gizmo before displaying it.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDebugComponent.h" },
		{ "ToolTip", "The scale that should be applied to the gizmo before displaying it." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextScale_MetaData[] = {
		{ "Category", "MR Utility Kit" },
		{ "Comment", "/**\n\x09 * The scale that should be applied to the text before displaying it.\n\x09 */" },
		{ "ModuleRelativePath", "Public/MRUtilityKitDebugComponent.h" },
		{ "ToolTip", "The scale that should be applied to the text before displaying it." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveGizmoActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveTextActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitDebugComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveAnchorSpaceActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitDebugComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_GizmoActorClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_TextActorClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GizmoScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextScale;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveGizmoActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveTextActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveAnchorSpaceActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMRUKDebugComponent_HideAnchor, "HideAnchor" }, // 974157796
		{ &Z_Construct_UFunction_UMRUKDebugComponent_HideAnchorSpace, "HideAnchorSpace" }, // 3725079319
		{ &Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorAtRayHit, "ShowAnchorAtRayHit" }, // 602881323
		{ &Z_Construct_UFunction_UMRUKDebugComponent_ShowAnchorSpaceAtRayHit, "ShowAnchorSpaceAtRayHit" }, // 492215799
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMRUKDebugComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UMRUKDebugComponent_Statics::NewProp_GizmoActorClass = { "GizmoActorClass", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMRUKDebugComponent, GizmoActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GizmoActorClass_MetaData), NewProp_GizmoActorClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UMRUKDebugComponent_Statics::NewProp_TextActorClass = { "TextActorClass", nullptr, (EPropertyFlags)0x0014000000000015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMRUKDebugComponent, TextActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextActorClass_MetaData), NewProp_TextActorClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UMRUKDebugComponent_Statics::NewProp_GizmoScale = { "GizmoScale", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMRUKDebugComponent, GizmoScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GizmoScale_MetaData), NewProp_GizmoScale_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UMRUKDebugComponent_Statics::NewProp_TextScale = { "TextScale", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMRUKDebugComponent, TextScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextScale_MetaData), NewProp_TextScale_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMRUKDebugComponent_Statics::NewProp_ActiveGizmoActor = { "ActiveGizmoActor", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMRUKDebugComponent, ActiveGizmoActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveGizmoActor_MetaData), NewProp_ActiveGizmoActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMRUKDebugComponent_Statics::NewProp_ActiveTextActor = { "ActiveTextActor", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMRUKDebugComponent, ActiveTextActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveTextActor_MetaData), NewProp_ActiveTextActor_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMRUKDebugComponent_Statics::NewProp_ActiveAnchorSpaceActor = { "ActiveAnchorSpaceActor", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMRUKDebugComponent, ActiveAnchorSpaceActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveAnchorSpaceActor_MetaData), NewProp_ActiveAnchorSpaceActor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMRUKDebugComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMRUKDebugComponent_Statics::NewProp_GizmoActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMRUKDebugComponent_Statics::NewProp_TextActorClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMRUKDebugComponent_Statics::NewProp_GizmoScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMRUKDebugComponent_Statics::NewProp_TextScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMRUKDebugComponent_Statics::NewProp_ActiveGizmoActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMRUKDebugComponent_Statics::NewProp_ActiveTextActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMRUKDebugComponent_Statics::NewProp_ActiveAnchorSpaceActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMRUKDebugComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMRUKDebugComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMRUKDebugComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMRUKDebugComponent_Statics::ClassParams = {
	&UMRUKDebugComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UMRUKDebugComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMRUKDebugComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMRUKDebugComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UMRUKDebugComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMRUKDebugComponent()
{
	if (!Z_Registration_Info_UClass_UMRUKDebugComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMRUKDebugComponent.OuterSingleton, Z_Construct_UClass_UMRUKDebugComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMRUKDebugComponent.OuterSingleton;
}
template<> MRUTILITYKIT_API UClass* StaticClass<UMRUKDebugComponent>()
{
	return UMRUKDebugComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMRUKDebugComponent);
UMRUKDebugComponent::~UMRUKDebugComponent() {}
// End Class UMRUKDebugComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitDebugComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMRUKDebugComponent, UMRUKDebugComponent::StaticClass, TEXT("UMRUKDebugComponent"), &Z_Registration_Info_UClass_UMRUKDebugComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMRUKDebugComponent), 3761451861U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitDebugComponent_h_820475661(TEXT("/Script/MRUtilityKit"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitDebugComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitDebugComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
