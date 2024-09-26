// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MRUtilityKitEditor/Private/TestHelper.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTestHelper() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_AActor();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKAnchor_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKRoom_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_UMRUKGridSliceResizerComponent_NoRegister();
MRUTILITYKITEDITOR_API UClass* Z_Construct_UClass_AMeshResizer();
MRUTILITYKITEDITOR_API UClass* Z_Construct_UClass_AMeshResizer_NoRegister();
MRUTILITYKITEDITOR_API UClass* Z_Construct_UClass_URoomAndAnchorObserver();
MRUTILITYKITEDITOR_API UClass* Z_Construct_UClass_URoomAndAnchorObserver_NoRegister();
UPackage* Z_Construct_UPackage__Script_MRUtilityKitEditor();
// End Cross Module References

// Begin Class URoomAndAnchorObserver Function OnAnchorCreated
struct Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated_Statics
{
	struct RoomAndAnchorObserver_eventOnAnchorCreated_Parms
	{
		AMRUKAnchor* Anchor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(RoomAndAnchorObserver_eventOnAnchorCreated_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated_Statics::NewProp_Anchor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URoomAndAnchorObserver, nullptr, "OnAnchorCreated", nullptr, nullptr, Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated_Statics::PropPointers), sizeof(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated_Statics::RoomAndAnchorObserver_eventOnAnchorCreated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated_Statics::Function_MetaDataParams), Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated_Statics::RoomAndAnchorObserver_eventOnAnchorCreated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(URoomAndAnchorObserver::execOnAnchorCreated)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAnchorCreated(Z_Param_Anchor);
	P_NATIVE_END;
}
// End Class URoomAndAnchorObserver Function OnAnchorCreated

// Begin Class URoomAndAnchorObserver Function OnAnchorRemoved
struct Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved_Statics
{
	struct RoomAndAnchorObserver_eventOnAnchorRemoved_Parms
	{
		AMRUKAnchor* Anchor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(RoomAndAnchorObserver_eventOnAnchorRemoved_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved_Statics::NewProp_Anchor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URoomAndAnchorObserver, nullptr, "OnAnchorRemoved", nullptr, nullptr, Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved_Statics::PropPointers), sizeof(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved_Statics::RoomAndAnchorObserver_eventOnAnchorRemoved_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved_Statics::Function_MetaDataParams), Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved_Statics::RoomAndAnchorObserver_eventOnAnchorRemoved_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(URoomAndAnchorObserver::execOnAnchorRemoved)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAnchorRemoved(Z_Param_Anchor);
	P_NATIVE_END;
}
// End Class URoomAndAnchorObserver Function OnAnchorRemoved

// Begin Class URoomAndAnchorObserver Function OnAnchorUpdated
struct Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated_Statics
{
	struct RoomAndAnchorObserver_eventOnAnchorUpdated_Parms
	{
		AMRUKAnchor* Anchor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(RoomAndAnchorObserver_eventOnAnchorUpdated_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated_Statics::NewProp_Anchor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URoomAndAnchorObserver, nullptr, "OnAnchorUpdated", nullptr, nullptr, Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated_Statics::PropPointers), sizeof(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated_Statics::RoomAndAnchorObserver_eventOnAnchorUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated_Statics::Function_MetaDataParams), Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated_Statics::RoomAndAnchorObserver_eventOnAnchorUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(URoomAndAnchorObserver::execOnAnchorUpdated)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAnchorUpdated(Z_Param_Anchor);
	P_NATIVE_END;
}
// End Class URoomAndAnchorObserver Function OnAnchorUpdated

// Begin Class URoomAndAnchorObserver Function OnRoomCreated
struct Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated_Statics
{
	struct RoomAndAnchorObserver_eventOnRoomCreated_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(RoomAndAnchorObserver_eventOnRoomCreated_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URoomAndAnchorObserver, nullptr, "OnRoomCreated", nullptr, nullptr, Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated_Statics::PropPointers), sizeof(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated_Statics::RoomAndAnchorObserver_eventOnRoomCreated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated_Statics::Function_MetaDataParams), Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated_Statics::RoomAndAnchorObserver_eventOnRoomCreated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(URoomAndAnchorObserver::execOnRoomCreated)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRoomCreated(Z_Param_Room);
	P_NATIVE_END;
}
// End Class URoomAndAnchorObserver Function OnRoomCreated

// Begin Class URoomAndAnchorObserver Function OnRoomRemoved
struct Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved_Statics
{
	struct RoomAndAnchorObserver_eventOnRoomRemoved_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(RoomAndAnchorObserver_eventOnRoomRemoved_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URoomAndAnchorObserver, nullptr, "OnRoomRemoved", nullptr, nullptr, Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved_Statics::PropPointers), sizeof(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved_Statics::RoomAndAnchorObserver_eventOnRoomRemoved_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved_Statics::Function_MetaDataParams), Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved_Statics::RoomAndAnchorObserver_eventOnRoomRemoved_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(URoomAndAnchorObserver::execOnRoomRemoved)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRoomRemoved(Z_Param_Room);
	P_NATIVE_END;
}
// End Class URoomAndAnchorObserver Function OnRoomRemoved

// Begin Class URoomAndAnchorObserver Function OnRoomUpdated
struct Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated_Statics
{
	struct RoomAndAnchorObserver_eventOnRoomUpdated_Parms
	{
		AMRUKRoom* Room;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(RoomAndAnchorObserver_eventOnRoomUpdated_Parms, Room), Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated_Statics::NewProp_Room,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_URoomAndAnchorObserver, nullptr, "OnRoomUpdated", nullptr, nullptr, Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated_Statics::PropPointers), sizeof(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated_Statics::RoomAndAnchorObserver_eventOnRoomUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated_Statics::Function_MetaDataParams), Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated_Statics::RoomAndAnchorObserver_eventOnRoomUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(URoomAndAnchorObserver::execOnRoomUpdated)
{
	P_GET_OBJECT(AMRUKRoom,Z_Param_Room);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRoomUpdated(Z_Param_Room);
	P_NATIVE_END;
}
// End Class URoomAndAnchorObserver Function OnRoomUpdated

// Begin Class URoomAndAnchorObserver
void URoomAndAnchorObserver::StaticRegisterNativesURoomAndAnchorObserver()
{
	UClass* Class = URoomAndAnchorObserver::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnAnchorCreated", &URoomAndAnchorObserver::execOnAnchorCreated },
		{ "OnAnchorRemoved", &URoomAndAnchorObserver::execOnAnchorRemoved },
		{ "OnAnchorUpdated", &URoomAndAnchorObserver::execOnAnchorUpdated },
		{ "OnRoomCreated", &URoomAndAnchorObserver::execOnRoomCreated },
		{ "OnRoomRemoved", &URoomAndAnchorObserver::execOnRoomRemoved },
		{ "OnRoomUpdated", &URoomAndAnchorObserver::execOnRoomUpdated },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URoomAndAnchorObserver);
UClass* Z_Construct_UClass_URoomAndAnchorObserver_NoRegister()
{
	return URoomAndAnchorObserver::StaticClass();
}
struct Z_Construct_UClass_URoomAndAnchorObserver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "TestHelper.h" },
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnchorsCreated_MetaData[] = {
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnchorsUpdated_MetaData[] = {
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnchorsRemoved_MetaData[] = {
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomsCreated_MetaData[] = {
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomsUpdated_MetaData[] = {
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomsRemoved_MetaData[] = {
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AnchorsCreated_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AnchorsCreated;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AnchorsUpdated_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AnchorsUpdated;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AnchorsRemoved_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AnchorsRemoved;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RoomsCreated_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RoomsCreated;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RoomsUpdated_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RoomsUpdated;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RoomsRemoved_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RoomsRemoved;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorCreated, "OnAnchorCreated" }, // 3038495956
		{ &Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorRemoved, "OnAnchorRemoved" }, // 3211308212
		{ &Z_Construct_UFunction_URoomAndAnchorObserver_OnAnchorUpdated, "OnAnchorUpdated" }, // 2930018975
		{ &Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomCreated, "OnRoomCreated" }, // 2136808219
		{ &Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomRemoved, "OnRoomRemoved" }, // 1833182805
		{ &Z_Construct_UFunction_URoomAndAnchorObserver_OnRoomUpdated, "OnRoomUpdated" }, // 4261736527
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URoomAndAnchorObserver>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_AnchorsCreated_Inner = { "AnchorsCreated", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_AnchorsCreated = { "AnchorsCreated", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URoomAndAnchorObserver, AnchorsCreated), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnchorsCreated_MetaData), NewProp_AnchorsCreated_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_AnchorsUpdated_Inner = { "AnchorsUpdated", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_AnchorsUpdated = { "AnchorsUpdated", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URoomAndAnchorObserver, AnchorsUpdated), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnchorsUpdated_MetaData), NewProp_AnchorsUpdated_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_AnchorsRemoved_Inner = { "AnchorsRemoved", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_AnchorsRemoved = { "AnchorsRemoved", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URoomAndAnchorObserver, AnchorsRemoved), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnchorsRemoved_MetaData), NewProp_AnchorsRemoved_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_RoomsCreated_Inner = { "RoomsCreated", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_RoomsCreated = { "RoomsCreated", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URoomAndAnchorObserver, RoomsCreated), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomsCreated_MetaData), NewProp_RoomsCreated_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_RoomsUpdated_Inner = { "RoomsUpdated", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_RoomsUpdated = { "RoomsUpdated", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URoomAndAnchorObserver, RoomsUpdated), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomsUpdated_MetaData), NewProp_RoomsUpdated_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_RoomsRemoved_Inner = { "RoomsRemoved", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AMRUKRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_RoomsRemoved = { "RoomsRemoved", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URoomAndAnchorObserver, RoomsRemoved), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomsRemoved_MetaData), NewProp_RoomsRemoved_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URoomAndAnchorObserver_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_AnchorsCreated_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_AnchorsCreated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_AnchorsUpdated_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_AnchorsUpdated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_AnchorsRemoved_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_AnchorsRemoved,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_RoomsCreated_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_RoomsCreated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_RoomsUpdated_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_RoomsUpdated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_RoomsRemoved_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URoomAndAnchorObserver_Statics::NewProp_RoomsRemoved,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URoomAndAnchorObserver_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_URoomAndAnchorObserver_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKitEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URoomAndAnchorObserver_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_URoomAndAnchorObserver_Statics::ClassParams = {
	&URoomAndAnchorObserver::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_URoomAndAnchorObserver_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_URoomAndAnchorObserver_Statics::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URoomAndAnchorObserver_Statics::Class_MetaDataParams), Z_Construct_UClass_URoomAndAnchorObserver_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_URoomAndAnchorObserver()
{
	if (!Z_Registration_Info_UClass_URoomAndAnchorObserver.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URoomAndAnchorObserver.OuterSingleton, Z_Construct_UClass_URoomAndAnchorObserver_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_URoomAndAnchorObserver.OuterSingleton;
}
template<> MRUTILITYKITEDITOR_API UClass* StaticClass<URoomAndAnchorObserver>()
{
	return URoomAndAnchorObserver::StaticClass();
}
URoomAndAnchorObserver::URoomAndAnchorObserver(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(URoomAndAnchorObserver);
URoomAndAnchorObserver::~URoomAndAnchorObserver() {}
// End Class URoomAndAnchorObserver

// Begin Class AMeshResizer
void AMeshResizer::StaticRegisterNativesAMeshResizer()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMeshResizer);
UClass* Z_Construct_UClass_AMeshResizer_NoRegister()
{
	return AMeshResizer::StaticClass();
}
struct Z_Construct_UClass_AMeshResizer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "TestHelper.h" },
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GridSliceResizerComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/TestHelper.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GridSliceResizerComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMeshResizer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMeshResizer_Statics::NewProp_GridSliceResizerComponent = { "GridSliceResizerComponent", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMeshResizer, GridSliceResizerComponent), Z_Construct_UClass_UMRUKGridSliceResizerComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GridSliceResizerComponent_MetaData), NewProp_GridSliceResizerComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMeshResizer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMeshResizer_Statics::NewProp_GridSliceResizerComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMeshResizer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMeshResizer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKitEditor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMeshResizer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMeshResizer_Statics::ClassParams = {
	&AMeshResizer::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AMeshResizer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AMeshResizer_Statics::PropPointers),
	0,
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMeshResizer_Statics::Class_MetaDataParams), Z_Construct_UClass_AMeshResizer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMeshResizer()
{
	if (!Z_Registration_Info_UClass_AMeshResizer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMeshResizer.OuterSingleton, Z_Construct_UClass_AMeshResizer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMeshResizer.OuterSingleton;
}
template<> MRUTILITYKITEDITOR_API UClass* StaticClass<AMeshResizer>()
{
	return AMeshResizer::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMeshResizer);
AMeshResizer::~AMeshResizer() {}
// End Class AMeshResizer

// Begin Registration
struct Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKitEditor_Private_TestHelper_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_URoomAndAnchorObserver, URoomAndAnchorObserver::StaticClass, TEXT("URoomAndAnchorObserver"), &Z_Registration_Info_UClass_URoomAndAnchorObserver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URoomAndAnchorObserver), 2745220983U) },
		{ Z_Construct_UClass_AMeshResizer, AMeshResizer::StaticClass, TEXT("AMeshResizer"), &Z_Registration_Info_UClass_AMeshResizer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMeshResizer), 414489247U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKitEditor_Private_TestHelper_h_1017448955(TEXT("/Script/MRUtilityKitEditor"),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKitEditor_Private_TestHelper_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKitEditor_Private_TestHelper_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
