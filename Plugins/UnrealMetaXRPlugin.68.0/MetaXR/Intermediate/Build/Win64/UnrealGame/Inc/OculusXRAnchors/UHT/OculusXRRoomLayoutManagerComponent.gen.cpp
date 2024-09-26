// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRAnchors/Public/OculusXRRoomLayoutManagerComponent.h"
#include "OculusXRAnchors/Public/OculusXRAnchorTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRRoomLayoutManagerComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
OCULUSXRANCHORS_API UClass* Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent();
OCULUSXRANCHORS_API UClass* Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_NoRegister();
OCULUSXRANCHORS_API UFunction* Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature();
OCULUSXRANCHORS_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRRoomLayout();
OCULUSXRANCHORS_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRUInt64();
PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_OculusXRAnchors();
// End Cross Module References

// Begin Delegate FOculusXRRoomLayoutSceneCaptureCompleteDelegate
struct Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics
{
	struct OculusXRRoomLayoutManagerComponent_eventOculusXRRoomLayoutSceneCaptureCompleteDelegate_Parms
	{
		FOculusXRUInt64 requestId;
		bool result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OculusXRRoomLayoutManagerComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_requestId;
	static void NewProp_result_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::NewProp_requestId = { "requestId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRRoomLayoutManagerComponent_eventOculusXRRoomLayoutSceneCaptureCompleteDelegate_Parms, requestId), Z_Construct_UScriptStruct_FOculusXRUInt64, METADATA_PARAMS(0, nullptr) }; // 2016766802
void Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::NewProp_result_SetBit(void* Obj)
{
	((OculusXRRoomLayoutManagerComponent_eventOculusXRRoomLayoutSceneCaptureCompleteDelegate_Parms*)Obj)->result = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::NewProp_result = { "result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRRoomLayoutManagerComponent_eventOculusXRRoomLayoutSceneCaptureCompleteDelegate_Parms), &Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::NewProp_result_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::NewProp_requestId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::NewProp_result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent, nullptr, "OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::OculusXRRoomLayoutManagerComponent_eventOculusXRRoomLayoutSceneCaptureCompleteDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::OculusXRRoomLayoutManagerComponent_eventOculusXRRoomLayoutSceneCaptureCompleteDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UOculusXRRoomLayoutManagerComponent::FOculusXRRoomLayoutSceneCaptureCompleteDelegate_DelegateWrapper(const FMulticastScriptDelegate& OculusXRRoomLayoutSceneCaptureCompleteDelegate, FOculusXRUInt64 requestId, bool result)
{
	struct OculusXRRoomLayoutManagerComponent_eventOculusXRRoomLayoutSceneCaptureCompleteDelegate_Parms
	{
		FOculusXRUInt64 requestId;
		bool result;
	};
	OculusXRRoomLayoutManagerComponent_eventOculusXRRoomLayoutSceneCaptureCompleteDelegate_Parms Parms;
	Parms.requestId=requestId;
	Parms.result=result ? true : false;
	OculusXRRoomLayoutSceneCaptureCompleteDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOculusXRRoomLayoutSceneCaptureCompleteDelegate

// Begin Class UOculusXRRoomLayoutManagerComponent Function GetRoomLayout
struct Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics
{
	struct OculusXRRoomLayoutManagerComponent_eventGetRoomLayout_Parms
	{
		FOculusXRUInt64 Space;
		FOculusXRRoomLayout RoomLayoutOut;
		int32 MaxWallsCapacity;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Room Layout Manager" },
		{ "Comment", "// Gets room layout for a specific space\n" },
		{ "CPP_Default_MaxWallsCapacity", "64" },
		{ "ModuleRelativePath", "Public/OculusXRRoomLayoutManagerComponent.h" },
		{ "ToolTip", "Gets room layout for a specific space" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Space;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoomLayoutOut;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxWallsCapacity;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::NewProp_Space = { "Space", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRRoomLayoutManagerComponent_eventGetRoomLayout_Parms, Space), Z_Construct_UScriptStruct_FOculusXRUInt64, METADATA_PARAMS(0, nullptr) }; // 2016766802
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::NewProp_RoomLayoutOut = { "RoomLayoutOut", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRRoomLayoutManagerComponent_eventGetRoomLayout_Parms, RoomLayoutOut), Z_Construct_UScriptStruct_FOculusXRRoomLayout, METADATA_PARAMS(0, nullptr) }; // 3375187172
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::NewProp_MaxWallsCapacity = { "MaxWallsCapacity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRRoomLayoutManagerComponent_eventGetRoomLayout_Parms, MaxWallsCapacity), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRRoomLayoutManagerComponent_eventGetRoomLayout_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRRoomLayoutManagerComponent_eventGetRoomLayout_Parms), &Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::NewProp_Space,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::NewProp_RoomLayoutOut,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::NewProp_MaxWallsCapacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent, nullptr, "GetRoomLayout", nullptr, nullptr, Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::OculusXRRoomLayoutManagerComponent_eventGetRoomLayout_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::OculusXRRoomLayoutManagerComponent_eventGetRoomLayout_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRRoomLayoutManagerComponent::execGetRoomLayout)
{
	P_GET_STRUCT(FOculusXRUInt64,Z_Param_Space);
	P_GET_STRUCT_REF(FOculusXRRoomLayout,Z_Param_Out_RoomLayoutOut);
	P_GET_PROPERTY(FIntProperty,Z_Param_MaxWallsCapacity);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetRoomLayout(Z_Param_Space,Z_Param_Out_RoomLayoutOut,Z_Param_MaxWallsCapacity);
	P_NATIVE_END;
}
// End Class UOculusXRRoomLayoutManagerComponent Function GetRoomLayout

// Begin Class UOculusXRRoomLayoutManagerComponent Function LaunchCaptureFlow
struct Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics
{
	struct OculusXRRoomLayoutManagerComponent_eventLaunchCaptureFlow_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Room Layout Manager" },
		{ "Comment", "// Requests to launch Capture Flow\n" },
		{ "ModuleRelativePath", "Public/OculusXRRoomLayoutManagerComponent.h" },
		{ "ToolTip", "Requests to launch Capture Flow" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRRoomLayoutManagerComponent_eventLaunchCaptureFlow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRRoomLayoutManagerComponent_eventLaunchCaptureFlow_Parms), &Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent, nullptr, "LaunchCaptureFlow", nullptr, nullptr, Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics::OculusXRRoomLayoutManagerComponent_eventLaunchCaptureFlow_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics::OculusXRRoomLayoutManagerComponent_eventLaunchCaptureFlow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRRoomLayoutManagerComponent::execLaunchCaptureFlow)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->LaunchCaptureFlow();
	P_NATIVE_END;
}
// End Class UOculusXRRoomLayoutManagerComponent Function LaunchCaptureFlow

// Begin Class UOculusXRRoomLayoutManagerComponent Function LoadTriangleMesh
struct Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics
{
	struct OculusXRRoomLayoutManagerComponent_eventLoadTriangleMesh_Parms
	{
		FOculusXRUInt64 Space;
		UProceduralMeshComponent* Mesh;
		bool CreateCollision;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Room Layout Manager" },
		{ "Comment", "// Loads mesh data (vertices, indeces) associated with the space into UProceduralMeshComponent\n" },
		{ "ModuleRelativePath", "Public/OculusXRRoomLayoutManagerComponent.h" },
		{ "ToolTip", "Loads mesh data (vertices, indeces) associated with the space into UProceduralMeshComponent" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Space;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static void NewProp_CreateCollision_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_CreateCollision;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::NewProp_Space = { "Space", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRRoomLayoutManagerComponent_eventLoadTriangleMesh_Parms, Space), Z_Construct_UScriptStruct_FOculusXRUInt64, METADATA_PARAMS(0, nullptr) }; // 2016766802
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRRoomLayoutManagerComponent_eventLoadTriangleMesh_Parms, Mesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
void Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::NewProp_CreateCollision_SetBit(void* Obj)
{
	((OculusXRRoomLayoutManagerComponent_eventLoadTriangleMesh_Parms*)Obj)->CreateCollision = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::NewProp_CreateCollision = { "CreateCollision", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRRoomLayoutManagerComponent_eventLoadTriangleMesh_Parms), &Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::NewProp_CreateCollision_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRRoomLayoutManagerComponent_eventLoadTriangleMesh_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRRoomLayoutManagerComponent_eventLoadTriangleMesh_Parms), &Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::NewProp_Space,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::NewProp_CreateCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent, nullptr, "LoadTriangleMesh", nullptr, nullptr, Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::OculusXRRoomLayoutManagerComponent_eventLoadTriangleMesh_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::OculusXRRoomLayoutManagerComponent_eventLoadTriangleMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRRoomLayoutManagerComponent::execLoadTriangleMesh)
{
	P_GET_STRUCT(FOculusXRUInt64,Z_Param_Space);
	P_GET_OBJECT(UProceduralMeshComponent,Z_Param_Mesh);
	P_GET_UBOOL(Z_Param_CreateCollision);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->LoadTriangleMesh(Z_Param_Space,Z_Param_Mesh,Z_Param_CreateCollision);
	P_NATIVE_END;
}
// End Class UOculusXRRoomLayoutManagerComponent Function LoadTriangleMesh

// Begin Class UOculusXRRoomLayoutManagerComponent Function OculusRoomLayoutSceneCaptureComplete_Handler
struct Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics
{
	struct OculusXRRoomLayoutManagerComponent_eventOculusRoomLayoutSceneCaptureComplete_Handler_Parms
	{
		FOculusXRUInt64 RequestId;
		bool bSuccess;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OculusXRRoomLayoutManagerComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RequestId;
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::NewProp_RequestId = { "RequestId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRRoomLayoutManagerComponent_eventOculusRoomLayoutSceneCaptureComplete_Handler_Parms, RequestId), Z_Construct_UScriptStruct_FOculusXRUInt64, METADATA_PARAMS(0, nullptr) }; // 2016766802
void Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((OculusXRRoomLayoutManagerComponent_eventOculusRoomLayoutSceneCaptureComplete_Handler_Parms*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRRoomLayoutManagerComponent_eventOculusRoomLayoutSceneCaptureComplete_Handler_Parms), &Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::NewProp_RequestId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::NewProp_bSuccess,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent, nullptr, "OculusRoomLayoutSceneCaptureComplete_Handler", nullptr, nullptr, Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::OculusXRRoomLayoutManagerComponent_eventOculusRoomLayoutSceneCaptureComplete_Handler_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::OculusXRRoomLayoutManagerComponent_eventOculusRoomLayoutSceneCaptureComplete_Handler_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRRoomLayoutManagerComponent::execOculusRoomLayoutSceneCaptureComplete_Handler)
{
	P_GET_STRUCT(FOculusXRUInt64,Z_Param_RequestId);
	P_GET_UBOOL(Z_Param_bSuccess);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OculusRoomLayoutSceneCaptureComplete_Handler(Z_Param_RequestId,Z_Param_bSuccess);
	P_NATIVE_END;
}
// End Class UOculusXRRoomLayoutManagerComponent Function OculusRoomLayoutSceneCaptureComplete_Handler

// Begin Class UOculusXRRoomLayoutManagerComponent
void UOculusXRRoomLayoutManagerComponent::StaticRegisterNativesUOculusXRRoomLayoutManagerComponent()
{
	UClass* Class = UOculusXRRoomLayoutManagerComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetRoomLayout", &UOculusXRRoomLayoutManagerComponent::execGetRoomLayout },
		{ "LaunchCaptureFlow", &UOculusXRRoomLayoutManagerComponent::execLaunchCaptureFlow },
		{ "LoadTriangleMesh", &UOculusXRRoomLayoutManagerComponent::execLoadTriangleMesh },
		{ "OculusRoomLayoutSceneCaptureComplete_Handler", &UOculusXRRoomLayoutManagerComponent::execOculusRoomLayoutSceneCaptureComplete_Handler },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRRoomLayoutManagerComponent);
UClass* Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_NoRegister()
{
	return UOculusXRRoomLayoutManagerComponent::StaticClass();
}
struct Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "DisplayName", "OculusXR Room Layout Manager Component" },
		{ "IncludePath", "OculusXRRoomLayoutManagerComponent.h" },
		{ "ModuleRelativePath", "Public/OculusXRRoomLayoutManagerComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OculusXRRoomLayoutSceneCaptureComplete_MetaData[] = {
		{ "Category", "OculusXR|Room Layout Manager" },
		{ "ModuleRelativePath", "Public/OculusXRRoomLayoutManagerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityRequestList_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRRoomLayoutManagerComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomLayouts_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRRoomLayoutManagerComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OculusXRRoomLayoutSceneCaptureComplete;
	static const UECodeGen_Private::FUInt64PropertyParams NewProp_EntityRequestList_ElementProp;
	static const UECodeGen_Private::FSetPropertyParams NewProp_EntityRequestList;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoomLayouts_ValueProp;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RoomLayouts_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_RoomLayouts;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_GetRoomLayout, "GetRoomLayout" }, // 2864737165
		{ &Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LaunchCaptureFlow, "LaunchCaptureFlow" }, // 516884857
		{ &Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_LoadTriangleMesh, "LoadTriangleMesh" }, // 2040118535
		{ &Z_Construct_UFunction_UOculusXRRoomLayoutManagerComponent_OculusRoomLayoutSceneCaptureComplete_Handler, "OculusRoomLayoutSceneCaptureComplete_Handler" }, // 2340266864
		{ &Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature, "OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature" }, // 2804515907
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRRoomLayoutManagerComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::NewProp_OculusXRRoomLayoutSceneCaptureComplete = { "OculusXRRoomLayoutSceneCaptureComplete", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRRoomLayoutManagerComponent, OculusXRRoomLayoutSceneCaptureComplete), Z_Construct_UDelegateFunction_UOculusXRRoomLayoutManagerComponent_OculusXRRoomLayoutSceneCaptureCompleteDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OculusXRRoomLayoutSceneCaptureComplete_MetaData), NewProp_OculusXRRoomLayoutSceneCaptureComplete_MetaData) }; // 2804515907
const UECodeGen_Private::FUInt64PropertyParams Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::NewProp_EntityRequestList_ElementProp = { "EntityRequestList", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::UInt64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::NewProp_EntityRequestList = { "EntityRequestList", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRRoomLayoutManagerComponent, EntityRequestList), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityRequestList_MetaData), NewProp_EntityRequestList_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::NewProp_RoomLayouts_ValueProp = { "RoomLayouts", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FOculusXRRoomLayout, METADATA_PARAMS(0, nullptr) }; // 3375187172
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::NewProp_RoomLayouts_Key_KeyProp = { "RoomLayouts_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOculusXRUInt64, METADATA_PARAMS(0, nullptr) }; // 2016766802
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::NewProp_RoomLayouts = { "RoomLayouts", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRRoomLayoutManagerComponent, RoomLayouts), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomLayouts_MetaData), NewProp_RoomLayouts_MetaData) }; // 2016766802 3375187172
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::NewProp_OculusXRRoomLayoutSceneCaptureComplete,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::NewProp_EntityRequestList_ElementProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::NewProp_EntityRequestList,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::NewProp_RoomLayouts_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::NewProp_RoomLayouts_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::NewProp_RoomLayouts,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRAnchors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::ClassParams = {
	&UOculusXRRoomLayoutManagerComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent()
{
	if (!Z_Registration_Info_UClass_UOculusXRRoomLayoutManagerComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRRoomLayoutManagerComponent.OuterSingleton, Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRRoomLayoutManagerComponent.OuterSingleton;
}
template<> OCULUSXRANCHORS_API UClass* StaticClass<UOculusXRRoomLayoutManagerComponent>()
{
	return UOculusXRRoomLayoutManagerComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRRoomLayoutManagerComponent);
UOculusXRRoomLayoutManagerComponent::~UOculusXRRoomLayoutManagerComponent() {}
// End Class UOculusXRRoomLayoutManagerComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRRoomLayoutManagerComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRRoomLayoutManagerComponent, UOculusXRRoomLayoutManagerComponent::StaticClass, TEXT("UOculusXRRoomLayoutManagerComponent"), &Z_Registration_Info_UClass_UOculusXRRoomLayoutManagerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRRoomLayoutManagerComponent), 956462303U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRRoomLayoutManagerComponent_h_3437150632(TEXT("/Script/OculusXRAnchors"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRRoomLayoutManagerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRRoomLayoutManagerComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
