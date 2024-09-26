// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRAnchors/Public/OculusXRAnchorComponent.h"
#include "OculusXRAnchors/Public/OculusXRAnchorTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRAnchorComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerCameraManager_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
OCULUSXRANCHORS_API UClass* Z_Construct_UClass_UOculusXRAnchorComponent();
OCULUSXRANCHORS_API UClass* Z_Construct_UClass_UOculusXRAnchorComponent_NoRegister();
OCULUSXRANCHORS_API UEnum* Z_Construct_UEnum_OculusXRAnchors_EOculusXRSpaceStorageLocation();
OCULUSXRANCHORS_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRUInt64();
OCULUSXRANCHORS_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRUUID();
UPackage* Z_Construct_UPackage__Script_OculusXRAnchors();
// End Cross Module References

// Begin Class UOculusXRAnchorComponent Function GetHandle
struct Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle_Statics
{
	struct OculusXRAnchorComponent_eventGetHandle_Parms
	{
		FOculusXRUInt64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Anchor" },
		{ "DefaultToSelf", "Target" },
		{ "ModuleRelativePath", "Public/OculusXRAnchorComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRAnchorComponent_eventGetHandle_Parms, ReturnValue), Z_Construct_UScriptStruct_FOculusXRUInt64, METADATA_PARAMS(0, nullptr) }; // 2016766802
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRAnchorComponent, nullptr, "GetHandle", nullptr, nullptr, Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle_Statics::OculusXRAnchorComponent_eventGetHandle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle_Statics::OculusXRAnchorComponent_eventGetHandle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRAnchorComponent::execGetHandle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FOculusXRUInt64*)Z_Param__Result=P_THIS->GetHandle();
	P_NATIVE_END;
}
// End Class UOculusXRAnchorComponent Function GetHandle

// Begin Class UOculusXRAnchorComponent Function GetUUID
struct Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID_Statics
{
	struct OculusXRAnchorComponent_eventGetUUID_Parms
	{
		FOculusXRUUID ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Anchor" },
		{ "DefaultToSelf", "Target" },
		{ "ModuleRelativePath", "Public/OculusXRAnchorComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRAnchorComponent_eventGetUUID_Parms, ReturnValue), Z_Construct_UScriptStruct_FOculusXRUUID, METADATA_PARAMS(0, nullptr) }; // 3529562975
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRAnchorComponent, nullptr, "GetUUID", nullptr, nullptr, Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID_Statics::OculusXRAnchorComponent_eventGetUUID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID_Statics::OculusXRAnchorComponent_eventGetUUID_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRAnchorComponent::execGetUUID)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FOculusXRUUID*)Z_Param__Result=P_THIS->GetUUID();
	P_NATIVE_END;
}
// End Class UOculusXRAnchorComponent Function GetUUID

// Begin Class UOculusXRAnchorComponent Function HasValidHandle
struct Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics
{
	struct OculusXRAnchorComponent_eventHasValidHandle_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Anchor" },
		{ "DefaultToSelf", "Target" },
		{ "ModuleRelativePath", "Public/OculusXRAnchorComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRAnchorComponent_eventHasValidHandle_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRAnchorComponent_eventHasValidHandle_Parms), &Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRAnchorComponent, nullptr, "HasValidHandle", nullptr, nullptr, Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics::OculusXRAnchorComponent_eventHasValidHandle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics::OculusXRAnchorComponent_eventHasValidHandle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRAnchorComponent::execHasValidHandle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasValidHandle();
	P_NATIVE_END;
}
// End Class UOculusXRAnchorComponent Function HasValidHandle

// Begin Class UOculusXRAnchorComponent Function IsSaved
struct Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics
{
	struct OculusXRAnchorComponent_eventIsSaved_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Anchor" },
		{ "DefaultToSelf", "Target" },
		{ "ModuleRelativePath", "Public/OculusXRAnchorComponent.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRAnchorComponent_eventIsSaved_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRAnchorComponent_eventIsSaved_Parms), &Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRAnchorComponent, nullptr, "IsSaved", nullptr, nullptr, Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics::OculusXRAnchorComponent_eventIsSaved_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics::OculusXRAnchorComponent_eventIsSaved_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRAnchorComponent::execIsSaved)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsSaved();
	P_NATIVE_END;
}
// End Class UOculusXRAnchorComponent Function IsSaved

// Begin Class UOculusXRAnchorComponent Function IsStoredAtLocation
struct Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics
{
	struct OculusXRAnchorComponent_eventIsStoredAtLocation_Parms
	{
		EOculusXRSpaceStorageLocation Location;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Anchor" },
		{ "DefaultToSelf", "Target" },
		{ "ModuleRelativePath", "Public/OculusXRAnchorComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Location_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Location;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::NewProp_Location_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRAnchorComponent_eventIsStoredAtLocation_Parms, Location), Z_Construct_UEnum_OculusXRAnchors_EOculusXRSpaceStorageLocation, METADATA_PARAMS(0, nullptr) }; // 3607691446
void Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRAnchorComponent_eventIsStoredAtLocation_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRAnchorComponent_eventIsStoredAtLocation_Parms), &Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::NewProp_Location_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRAnchorComponent, nullptr, "IsStoredAtLocation", nullptr, nullptr, Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::OculusXRAnchorComponent_eventIsStoredAtLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::OculusXRAnchorComponent_eventIsStoredAtLocation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRAnchorComponent::execIsStoredAtLocation)
{
	P_GET_ENUM(EOculusXRSpaceStorageLocation,Z_Param_Location);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsStoredAtLocation(EOculusXRSpaceStorageLocation(Z_Param_Location));
	P_NATIVE_END;
}
// End Class UOculusXRAnchorComponent Function IsStoredAtLocation

// Begin Class UOculusXRAnchorComponent Function SetHandle
struct Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle_Statics
{
	struct OculusXRAnchorComponent_eventSetHandle_Parms
	{
		FOculusXRUInt64 Handle;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusXR|Anchor" },
		{ "DefaultToSelf", "Target" },
		{ "ModuleRelativePath", "Public/OculusXRAnchorComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Handle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle_Statics::NewProp_Handle = { "Handle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRAnchorComponent_eventSetHandle_Parms, Handle), Z_Construct_UScriptStruct_FOculusXRUInt64, METADATA_PARAMS(0, nullptr) }; // 2016766802
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle_Statics::NewProp_Handle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRAnchorComponent, nullptr, "SetHandle", nullptr, nullptr, Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle_Statics::OculusXRAnchorComponent_eventSetHandle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle_Statics::OculusXRAnchorComponent_eventSetHandle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRAnchorComponent::execSetHandle)
{
	P_GET_STRUCT(FOculusXRUInt64,Z_Param_Handle);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHandle(Z_Param_Handle);
	P_NATIVE_END;
}
// End Class UOculusXRAnchorComponent Function SetHandle

// Begin Class UOculusXRAnchorComponent
void UOculusXRAnchorComponent::StaticRegisterNativesUOculusXRAnchorComponent()
{
	UClass* Class = UOculusXRAnchorComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetHandle", &UOculusXRAnchorComponent::execGetHandle },
		{ "GetUUID", &UOculusXRAnchorComponent::execGetUUID },
		{ "HasValidHandle", &UOculusXRAnchorComponent::execHasValidHandle },
		{ "IsSaved", &UOculusXRAnchorComponent::execIsSaved },
		{ "IsStoredAtLocation", &UOculusXRAnchorComponent::execIsStoredAtLocation },
		{ "SetHandle", &UOculusXRAnchorComponent::execSetHandle },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRAnchorComponent);
UClass* Z_Construct_UClass_UOculusXRAnchorComponent_NoRegister()
{
	return UOculusXRAnchorComponent::StaticClass();
}
struct Z_Construct_UClass_UOculusXRAnchorComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "DisplayName", "Oculus Anchor Component" },
		{ "IncludePath", "OculusXRAnchorComponent.h" },
		{ "ModuleRelativePath", "Public/OculusXRAnchorComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerCameraManager_MetaData[] = {
		{ "ModuleRelativePath", "Public/OculusXRAnchorComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerCameraManager;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOculusXRAnchorComponent_GetHandle, "GetHandle" }, // 3868555845
		{ &Z_Construct_UFunction_UOculusXRAnchorComponent_GetUUID, "GetUUID" }, // 3733976078
		{ &Z_Construct_UFunction_UOculusXRAnchorComponent_HasValidHandle, "HasValidHandle" }, // 985538617
		{ &Z_Construct_UFunction_UOculusXRAnchorComponent_IsSaved, "IsSaved" }, // 805611731
		{ &Z_Construct_UFunction_UOculusXRAnchorComponent_IsStoredAtLocation, "IsStoredAtLocation" }, // 3820312105
		{ &Z_Construct_UFunction_UOculusXRAnchorComponent_SetHandle, "SetHandle" }, // 2666011328
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRAnchorComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOculusXRAnchorComponent_Statics::NewProp_PlayerCameraManager = { "PlayerCameraManager", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOculusXRAnchorComponent, PlayerCameraManager), Z_Construct_UClass_APlayerCameraManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerCameraManager_MetaData), NewProp_PlayerCameraManager_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOculusXRAnchorComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOculusXRAnchorComponent_Statics::NewProp_PlayerCameraManager,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRAnchorComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOculusXRAnchorComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRAnchors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRAnchorComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRAnchorComponent_Statics::ClassParams = {
	&UOculusXRAnchorComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOculusXRAnchorComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRAnchorComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRAnchorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRAnchorComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRAnchorComponent()
{
	if (!Z_Registration_Info_UClass_UOculusXRAnchorComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRAnchorComponent.OuterSingleton, Z_Construct_UClass_UOculusXRAnchorComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRAnchorComponent.OuterSingleton;
}
template<> OCULUSXRANCHORS_API UClass* StaticClass<UOculusXRAnchorComponent>()
{
	return UOculusXRAnchorComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRAnchorComponent);
UOculusXRAnchorComponent::~UOculusXRAnchorComponent() {}
// End Class UOculusXRAnchorComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRAnchorComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRAnchorComponent, UOculusXRAnchorComponent::StaticClass, TEXT("UOculusXRAnchorComponent"), &Z_Registration_Info_UClass_UOculusXRAnchorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRAnchorComponent), 2608523871U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRAnchorComponent_h_3054975847(TEXT("/Script/OculusXRAnchors"),
	Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRAnchorComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRAnchorComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
