// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MRUtilityKit/Public/MRUtilityKitBPLibrary.h"
#include "OculusXRAnchors/Public/OculusXRAnchorTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMRUtilityKitBPLibrary() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FMatrix();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_AMRUKAnchor_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_UMRUKBPLibrary();
MRUTILITYKIT_API UClass* Z_Construct_UClass_UMRUKBPLibrary_NoRegister();
MRUTILITYKIT_API UClass* Z_Construct_UClass_UMRUKLoadFromDevice();
MRUTILITYKIT_API UClass* Z_Construct_UClass_UMRUKLoadFromDevice_NoRegister();
MRUTILITYKIT_API UFunction* Z_Construct_UDelegateFunction_UMRUKLoadFromDevice_MRUKLoaded__DelegateSignature();
OCULUSXRANCHORS_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRUInt64();
OCULUSXRANCHORS_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRUUID();
PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_MRUtilityKit();
// End Cross Module References

// Begin Delegate FMRUKLoaded
struct Z_Construct_UDelegateFunction_UMRUKLoadFromDevice_MRUKLoaded__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UMRUKLoadFromDevice_MRUKLoaded__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKLoadFromDevice, nullptr, "MRUKLoaded__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UMRUKLoadFromDevice_MRUKLoaded__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UMRUKLoadFromDevice_MRUKLoaded__DelegateSignature_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UDelegateFunction_UMRUKLoadFromDevice_MRUKLoaded__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UMRUKLoadFromDevice_MRUKLoaded__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void UMRUKLoadFromDevice::FMRUKLoaded_DelegateWrapper(const FMulticastScriptDelegate& MRUKLoaded)
{
	MRUKLoaded.ProcessMulticastDelegate<UObject>(NULL);
}
// End Delegate FMRUKLoaded

// Begin Class UMRUKLoadFromDevice Function LoadSceneFromDeviceAsync
struct Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics
{
	struct MRUKLoadFromDevice_eventLoadSceneFromDeviceAsync_Parms
	{
		const UObject* WorldContext;
		UMRUKLoadFromDevice* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "MR Utility Kit" },
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
		{ "WorldContext", "WorldContext" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContext_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics::NewProp_WorldContext = { "WorldContext", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKLoadFromDevice_eventLoadSceneFromDeviceAsync_Parms, WorldContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContext_MetaData), NewProp_WorldContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKLoadFromDevice_eventLoadSceneFromDeviceAsync_Parms, ReturnValue), Z_Construct_UClass_UMRUKLoadFromDevice_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics::NewProp_WorldContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKLoadFromDevice, nullptr, "LoadSceneFromDeviceAsync", nullptr, nullptr, Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics::MRUKLoadFromDevice_eventLoadSceneFromDeviceAsync_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics::MRUKLoadFromDevice_eventLoadSceneFromDeviceAsync_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKLoadFromDevice::execLoadSceneFromDeviceAsync)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContext);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UMRUKLoadFromDevice**)Z_Param__Result=UMRUKLoadFromDevice::LoadSceneFromDeviceAsync(Z_Param_WorldContext);
	P_NATIVE_END;
}
// End Class UMRUKLoadFromDevice Function LoadSceneFromDeviceAsync

// Begin Class UMRUKLoadFromDevice Function OnSceneLoaded
struct Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics
{
	struct MRUKLoadFromDevice_eventOnSceneLoaded_Parms
	{
		bool Succeeded;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
	};
#endif // WITH_METADATA
	static void NewProp_Succeeded_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Succeeded;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics::NewProp_Succeeded_SetBit(void* Obj)
{
	((MRUKLoadFromDevice_eventOnSceneLoaded_Parms*)Obj)->Succeeded = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics::NewProp_Succeeded = { "Succeeded", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUKLoadFromDevice_eventOnSceneLoaded_Parms), &Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics::NewProp_Succeeded_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics::NewProp_Succeeded,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKLoadFromDevice, nullptr, "OnSceneLoaded", nullptr, nullptr, Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics::MRUKLoadFromDevice_eventOnSceneLoaded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics::MRUKLoadFromDevice_eventOnSceneLoaded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKLoadFromDevice::execOnSceneLoaded)
{
	P_GET_UBOOL(Z_Param_Succeeded);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnSceneLoaded(Z_Param_Succeeded);
	P_NATIVE_END;
}
// End Class UMRUKLoadFromDevice Function OnSceneLoaded

// Begin Class UMRUKLoadFromDevice
void UMRUKLoadFromDevice::StaticRegisterNativesUMRUKLoadFromDevice()
{
	UClass* Class = UMRUKLoadFromDevice::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "LoadSceneFromDeviceAsync", &UMRUKLoadFromDevice::execLoadSceneFromDeviceAsync },
		{ "OnSceneLoaded", &UMRUKLoadFromDevice::execOnSceneLoaded },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMRUKLoadFromDevice);
UClass* Z_Construct_UClass_UMRUKLoadFromDevice_NoRegister()
{
	return UMRUKLoadFromDevice::StaticClass();
}
struct Z_Construct_UClass_UMRUKLoadFromDevice_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Load the scene async from device.\n */" },
#endif
		{ "IncludePath", "MRUtilityKitBPLibrary.h" },
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Load the scene async from device." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Success_MetaData[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Failure_MetaData[] = {
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_Success;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_Failure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMRUKLoadFromDevice_LoadSceneFromDeviceAsync, "LoadSceneFromDeviceAsync" }, // 2924817802
		{ &Z_Construct_UDelegateFunction_UMRUKLoadFromDevice_MRUKLoaded__DelegateSignature, "MRUKLoaded__DelegateSignature" }, // 1152659747
		{ &Z_Construct_UFunction_UMRUKLoadFromDevice_OnSceneLoaded, "OnSceneLoaded" }, // 2162190502
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMRUKLoadFromDevice>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UMRUKLoadFromDevice_Statics::NewProp_Success = { "Success", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMRUKLoadFromDevice, Success), Z_Construct_UDelegateFunction_UMRUKLoadFromDevice_MRUKLoaded__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Success_MetaData), NewProp_Success_MetaData) }; // 1152659747
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UMRUKLoadFromDevice_Statics::NewProp_Failure = { "Failure", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMRUKLoadFromDevice, Failure), Z_Construct_UDelegateFunction_UMRUKLoadFromDevice_MRUKLoaded__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Failure_MetaData), NewProp_Failure_MetaData) }; // 1152659747
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMRUKLoadFromDevice_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMRUKLoadFromDevice_Statics::NewProp_Success,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMRUKLoadFromDevice_Statics::NewProp_Failure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMRUKLoadFromDevice_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMRUKLoadFromDevice_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMRUKLoadFromDevice_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMRUKLoadFromDevice_Statics::ClassParams = {
	&UMRUKLoadFromDevice::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UMRUKLoadFromDevice_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMRUKLoadFromDevice_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMRUKLoadFromDevice_Statics::Class_MetaDataParams), Z_Construct_UClass_UMRUKLoadFromDevice_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMRUKLoadFromDevice()
{
	if (!Z_Registration_Info_UClass_UMRUKLoadFromDevice.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMRUKLoadFromDevice.OuterSingleton, Z_Construct_UClass_UMRUKLoadFromDevice_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMRUKLoadFromDevice.OuterSingleton;
}
template<> MRUTILITYKIT_API UClass* StaticClass<UMRUKLoadFromDevice>()
{
	return UMRUKLoadFromDevice::StaticClass();
}
UMRUKLoadFromDevice::UMRUKLoadFromDevice(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMRUKLoadFromDevice);
UMRUKLoadFromDevice::~UMRUKLoadFromDevice() {}
// End Class UMRUKLoadFromDevice

// Begin Class UMRUKBPLibrary Function ComputeCentroid
struct Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics
{
	struct MRUKBPLibrary_eventComputeCentroid_Parms
	{
		TArray<FVector2D> PolygonPoints;
		FVector2D ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 *  Compute the centroid of a polygon that is defined by the points.\n\x09 *  The centroid may be outside of the polygon in case the polygon is non convex.\n\x09 * @param PolygonPoints Points that define the polygon.\n\x09 * @return The centroid.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compute the centroid of a polygon that is defined by the points.\nThe centroid may be outside of the polygon in case the polygon is non convex.\n@param PolygonPoints Points that define the polygon.\n@return The centroid." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PolygonPoints_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PolygonPoints_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PolygonPoints;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::NewProp_PolygonPoints_Inner = { "PolygonPoints", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::NewProp_PolygonPoints = { "PolygonPoints", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventComputeCentroid_Parms, PolygonPoints), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PolygonPoints_MetaData), NewProp_PolygonPoints_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventComputeCentroid_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::NewProp_PolygonPoints_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::NewProp_PolygonPoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKBPLibrary, nullptr, "ComputeCentroid", nullptr, nullptr, Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::MRUKBPLibrary_eventComputeCentroid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::MRUKBPLibrary_eventComputeCentroid_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKBPLibrary::execComputeCentroid)
{
	P_GET_TARRAY_REF(FVector2D,Z_Param_Out_PolygonPoints);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector2D*)Z_Param__Result=UMRUKBPLibrary::ComputeCentroid(Z_Param_Out_PolygonPoints);
	P_NATIVE_END;
}
// End Class UMRUKBPLibrary Function ComputeCentroid

// Begin Class UMRUKBPLibrary Function ComputeDirectionAwayFromClosestWall
struct Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics
{
	struct MRUKBPLibrary_eventComputeDirectionAwayFromClosestWall_Parms
	{
		const AMRUKAnchor* Anchor;
		int32 OutCardinalAxisIndex;
		TArray<int32> ExcludedAxes;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Compute the direction that faces away from the closest wall of the given anchor.\n\x09 * @param Anchor The anchor for which the direction should be computed.\n\x09 * @param OutCardinalAxisIndex The index of the computed cardinal axis. Can be either 0, 1, 2 or 3\n\x09 * @param ExcludedAxes Axes to exclude in the computation. Can contain 0, 1, 2, 3\n\x09 * @return The direction\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Compute the direction that faces away from the closest wall of the given anchor.\n@param Anchor The anchor for which the direction should be computed.\n@param OutCardinalAxisIndex The index of the computed cardinal axis. Can be either 0, 1, 2 or 3\n@param ExcludedAxes Axes to exclude in the computation. Can contain 0, 1, 2, 3\n@return The direction" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Anchor_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExcludedAxes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Anchor;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutCardinalAxisIndex;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ExcludedAxes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ExcludedAxes;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::NewProp_Anchor = { "Anchor", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventComputeDirectionAwayFromClosestWall_Parms, Anchor), Z_Construct_UClass_AMRUKAnchor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Anchor_MetaData), NewProp_Anchor_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::NewProp_OutCardinalAxisIndex = { "OutCardinalAxisIndex", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventComputeDirectionAwayFromClosestWall_Parms, OutCardinalAxisIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::NewProp_ExcludedAxes_Inner = { "ExcludedAxes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::NewProp_ExcludedAxes = { "ExcludedAxes", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventComputeDirectionAwayFromClosestWall_Parms, ExcludedAxes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExcludedAxes_MetaData), NewProp_ExcludedAxes_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventComputeDirectionAwayFromClosestWall_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::NewProp_Anchor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::NewProp_OutCardinalAxisIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::NewProp_ExcludedAxes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::NewProp_ExcludedAxes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKBPLibrary, nullptr, "ComputeDirectionAwayFromClosestWall", nullptr, nullptr, Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::MRUKBPLibrary_eventComputeDirectionAwayFromClosestWall_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::MRUKBPLibrary_eventComputeDirectionAwayFromClosestWall_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKBPLibrary::execComputeDirectionAwayFromClosestWall)
{
	P_GET_OBJECT(AMRUKAnchor,Z_Param_Anchor);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_OutCardinalAxisIndex);
	P_GET_TARRAY(int32,Z_Param_ExcludedAxes);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=UMRUKBPLibrary::ComputeDirectionAwayFromClosestWall(Z_Param_Anchor,Z_Param_Out_OutCardinalAxisIndex,Z_Param_ExcludedAxes);
	P_NATIVE_END;
}
// End Class UMRUKBPLibrary Function ComputeDirectionAwayFromClosestWall

// Begin Class UMRUKBPLibrary Function ConstructTexture2D
struct Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics
{
	struct MRUKBPLibrary_eventConstructTexture2D_Parms
	{
		UTextureRenderTarget2D* RenderTarget2D;
		UObject* Outer;
		FString TexName;
		UTexture2D* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Construct a 2D texture from a render target.\n\x09 * @param RenderTarget2D The render target from which the texture should be created.\n\x09 * @param Outer\x09The (optional) outer object for the created texture.\n\x09 * @param TexName Name for the new texture.\n\x09 * @return The newly created texture.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Construct a 2D texture from a render target.\n@param RenderTarget2D The render target from which the texture should be created.\n@param Outer The (optional) outer object for the created texture.\n@param TexName Name for the new texture.\n@return The newly created texture." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TexName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RenderTarget2D;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Outer;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TexName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::NewProp_RenderTarget2D = { "RenderTarget2D", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventConstructTexture2D_Parms, RenderTarget2D), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::NewProp_Outer = { "Outer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventConstructTexture2D_Parms, Outer), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::NewProp_TexName = { "TexName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventConstructTexture2D_Parms, TexName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TexName_MetaData), NewProp_TexName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventConstructTexture2D_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::NewProp_RenderTarget2D,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::NewProp_Outer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::NewProp_TexName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKBPLibrary, nullptr, "ConstructTexture2D", nullptr, nullptr, Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::MRUKBPLibrary_eventConstructTexture2D_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::MRUKBPLibrary_eventConstructTexture2D_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKBPLibrary::execConstructTexture2D)
{
	P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_RenderTarget2D);
	P_GET_OBJECT(UObject,Z_Param_Outer);
	P_GET_PROPERTY(FStrProperty,Z_Param_TexName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTexture2D**)Z_Param__Result=UMRUKBPLibrary::ConstructTexture2D(Z_Param_RenderTarget2D,Z_Param_Outer,Z_Param_TexName);
	P_NATIVE_END;
}
// End Class UMRUKBPLibrary Function ConstructTexture2D

// Begin Class UMRUKBPLibrary Function GetMatrixColumn
struct Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics
{
	struct FMatrix
	{
		FPlane XPlane;
		FPlane YPlane;
		FPlane ZPlane;
		FPlane WPlane;
	};

	struct MRUKBPLibrary_eventGetMatrixColumn_Parms
	{
		FMatrix Matrix;
		int32 Index;
		FLinearColor ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Extract a column from a matrix.\n\x09 * @param Matrix The matrix to use.\n\x09 * @param Index The column index.\n\x09 * @return The column of the matrix.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Extract a column from a matrix.\n@param Matrix The matrix to use.\n@param Index The column index.\n@return The column of the matrix." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Matrix_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Matrix;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::NewProp_Matrix = { "Matrix", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventGetMatrixColumn_Parms, Matrix), Z_Construct_UScriptStruct_FMatrix, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Matrix_MetaData), NewProp_Matrix_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventGetMatrixColumn_Parms, Index), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventGetMatrixColumn_Parms, ReturnValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::NewProp_Matrix,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::NewProp_Index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKBPLibrary, nullptr, "GetMatrixColumn", nullptr, nullptr, Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::MRUKBPLibrary_eventGetMatrixColumn_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::MRUKBPLibrary_eventGetMatrixColumn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKBPLibrary::execGetMatrixColumn)
{
	P_GET_STRUCT_REF(FMatrix,Z_Param_Out_Matrix);
	P_GET_PROPERTY(FIntProperty,Z_Param_Index);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FLinearColor*)Z_Param__Result=UMRUKBPLibrary::GetMatrixColumn(Z_Param_Out_Matrix,Z_Param_Index);
	P_NATIVE_END;
}
// End Class UMRUKBPLibrary Function GetMatrixColumn

// Begin Class UMRUKBPLibrary Function IsUnrealEngineMetaFork
struct Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics
{
	struct MRUKBPLibrary_eventIsUnrealEngineMetaFork_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if the current Unreal Engine is the fork of Meta.\n\x09 * @return Whether its the fork or not.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if the current Unreal Engine is the fork of Meta.\n@return Whether its the fork or not." },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MRUKBPLibrary_eventIsUnrealEngineMetaFork_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUKBPLibrary_eventIsUnrealEngineMetaFork_Parms), &Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKBPLibrary, nullptr, "IsUnrealEngineMetaFork", nullptr, nullptr, Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics::MRUKBPLibrary_eventIsUnrealEngineMetaFork_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics::MRUKBPLibrary_eventIsUnrealEngineMetaFork_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKBPLibrary::execIsUnrealEngineMetaFork)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UMRUKBPLibrary::IsUnrealEngineMetaFork();
	P_NATIVE_END;
}
// End Class UMRUKBPLibrary Function IsUnrealEngineMetaFork

// Begin Class UMRUKBPLibrary Function LoadGlobalMeshFromDevice
struct Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics
{
	struct MRUKBPLibrary_eventLoadGlobalMeshFromDevice_Parms
	{
		FOculusXRUInt64 SpaceHandle;
		UProceduralMeshComponent* OutProceduralMesh;
		bool LoadCollision;
		const UObject* WorldContext;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Load the global mesh from the device.\n\x09 * @param SpaceHandle       Space handle of the room.\n\x09 * @param OutProceduralMesh Procedural mesh to load the triangle data in.\n\x09 * @param LoadCollision     Whether to generate collision or not.\n\x09 * @param WorldContext      Context of the world.\n\x09 * @return                  Whether the load was successful or not.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Load the global mesh from the device.\n@param SpaceHandle       Space handle of the room.\n@param OutProceduralMesh Procedural mesh to load the triangle data in.\n@param LoadCollision     Whether to generate collision or not.\n@param WorldContext      Context of the world.\n@return                  Whether the load was successful or not." },
#endif
		{ "WorldContext", "WorldContext" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutProceduralMesh_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContext_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpaceHandle;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OutProceduralMesh;
	static void NewProp_LoadCollision_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_LoadCollision;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContext;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::NewProp_SpaceHandle = { "SpaceHandle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventLoadGlobalMeshFromDevice_Parms, SpaceHandle), Z_Construct_UScriptStruct_FOculusXRUInt64, METADATA_PARAMS(0, nullptr) }; // 2016766802
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::NewProp_OutProceduralMesh = { "OutProceduralMesh", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventLoadGlobalMeshFromDevice_Parms, OutProceduralMesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutProceduralMesh_MetaData), NewProp_OutProceduralMesh_MetaData) };
void Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::NewProp_LoadCollision_SetBit(void* Obj)
{
	((MRUKBPLibrary_eventLoadGlobalMeshFromDevice_Parms*)Obj)->LoadCollision = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::NewProp_LoadCollision = { "LoadCollision", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUKBPLibrary_eventLoadGlobalMeshFromDevice_Parms), &Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::NewProp_LoadCollision_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::NewProp_WorldContext = { "WorldContext", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventLoadGlobalMeshFromDevice_Parms, WorldContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContext_MetaData), NewProp_WorldContext_MetaData) };
void Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MRUKBPLibrary_eventLoadGlobalMeshFromDevice_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUKBPLibrary_eventLoadGlobalMeshFromDevice_Parms), &Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::NewProp_SpaceHandle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::NewProp_OutProceduralMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::NewProp_LoadCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::NewProp_WorldContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKBPLibrary, nullptr, "LoadGlobalMeshFromDevice", nullptr, nullptr, Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::MRUKBPLibrary_eventLoadGlobalMeshFromDevice_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::MRUKBPLibrary_eventLoadGlobalMeshFromDevice_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKBPLibrary::execLoadGlobalMeshFromDevice)
{
	P_GET_STRUCT(FOculusXRUInt64,Z_Param_SpaceHandle);
	P_GET_OBJECT(UProceduralMeshComponent,Z_Param_OutProceduralMesh);
	P_GET_UBOOL(Z_Param_LoadCollision);
	P_GET_OBJECT(UObject,Z_Param_WorldContext);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UMRUKBPLibrary::LoadGlobalMeshFromDevice(Z_Param_SpaceHandle,Z_Param_OutProceduralMesh,Z_Param_LoadCollision,Z_Param_WorldContext);
	P_NATIVE_END;
}
// End Class UMRUKBPLibrary Function LoadGlobalMeshFromDevice

// Begin Class UMRUKBPLibrary Function LoadGlobalMeshFromJsonString
struct Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics
{
	struct MRUKBPLibrary_eventLoadGlobalMeshFromJsonString_Parms
	{
		FString JsonString;
		FOculusXRUUID AnchorUUID;
		UProceduralMeshComponent* OutProceduralMesh;
		bool LoadCollision;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Load the global mesh from a JSON string.\n\x09 * @param JsonString        The string containing the JSON.\n\x09 * @param AnchorUUID        Anchor UUID of the room\n\x09 * @param OutProceduralMesh Procedural mesh to load the triangle data in.\n\x09 * @param LoadCollision     Whether to generate collision or not\n\x09 * @return                  Whether the load was successful or not.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Load the global mesh from a JSON string.\n@param JsonString        The string containing the JSON.\n@param AnchorUUID        Anchor UUID of the room\n@param OutProceduralMesh Procedural mesh to load the triangle data in.\n@param LoadCollision     Whether to generate collision or not\n@return                  Whether the load was successful or not." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JsonString_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutProceduralMesh_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_JsonString;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AnchorUUID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OutProceduralMesh;
	static void NewProp_LoadCollision_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_LoadCollision;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::NewProp_JsonString = { "JsonString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventLoadGlobalMeshFromJsonString_Parms, JsonString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JsonString_MetaData), NewProp_JsonString_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::NewProp_AnchorUUID = { "AnchorUUID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventLoadGlobalMeshFromJsonString_Parms, AnchorUUID), Z_Construct_UScriptStruct_FOculusXRUUID, METADATA_PARAMS(0, nullptr) }; // 3529562975
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::NewProp_OutProceduralMesh = { "OutProceduralMesh", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventLoadGlobalMeshFromJsonString_Parms, OutProceduralMesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutProceduralMesh_MetaData), NewProp_OutProceduralMesh_MetaData) };
void Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::NewProp_LoadCollision_SetBit(void* Obj)
{
	((MRUKBPLibrary_eventLoadGlobalMeshFromJsonString_Parms*)Obj)->LoadCollision = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::NewProp_LoadCollision = { "LoadCollision", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUKBPLibrary_eventLoadGlobalMeshFromJsonString_Parms), &Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::NewProp_LoadCollision_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((MRUKBPLibrary_eventLoadGlobalMeshFromJsonString_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MRUKBPLibrary_eventLoadGlobalMeshFromJsonString_Parms), &Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::NewProp_JsonString,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::NewProp_AnchorUUID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::NewProp_OutProceduralMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::NewProp_LoadCollision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKBPLibrary, nullptr, "LoadGlobalMeshFromJsonString", nullptr, nullptr, Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::MRUKBPLibrary_eventLoadGlobalMeshFromJsonString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::MRUKBPLibrary_eventLoadGlobalMeshFromJsonString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKBPLibrary::execLoadGlobalMeshFromJsonString)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_JsonString);
	P_GET_STRUCT(FOculusXRUUID,Z_Param_AnchorUUID);
	P_GET_OBJECT(UProceduralMeshComponent,Z_Param_OutProceduralMesh);
	P_GET_UBOOL(Z_Param_LoadCollision);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UMRUKBPLibrary::LoadGlobalMeshFromJsonString(Z_Param_JsonString,Z_Param_AnchorUUID,Z_Param_OutProceduralMesh,Z_Param_LoadCollision);
	P_NATIVE_END;
}
// End Class UMRUKBPLibrary Function LoadGlobalMeshFromJsonString

// Begin Class UMRUKBPLibrary Function RecalculateProceduralMeshAndTangents
struct Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents_Statics
{
	struct MRUKBPLibrary_eventRecalculateProceduralMeshAndTangents_Parms
	{
		UProceduralMeshComponent* Mesh;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * (Re)Calculate Normals and Tangents of the given procedural mesh.\n\x09 * @param Mesh The procedural mesh.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "(Re)Calculate Normals and Tangents of the given procedural mesh.\n@param Mesh The procedural mesh." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventRecalculateProceduralMeshAndTangents_Parms, Mesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents_Statics::NewProp_Mesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKBPLibrary, nullptr, "RecalculateProceduralMeshAndTangents", nullptr, nullptr, Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents_Statics::MRUKBPLibrary_eventRecalculateProceduralMeshAndTangents_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents_Statics::MRUKBPLibrary_eventRecalculateProceduralMeshAndTangents_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKBPLibrary::execRecalculateProceduralMeshAndTangents)
{
	P_GET_OBJECT(UProceduralMeshComponent,Z_Param_Mesh);
	P_FINISH;
	P_NATIVE_BEGIN;
	UMRUKBPLibrary::RecalculateProceduralMeshAndTangents(Z_Param_Mesh);
	P_NATIVE_END;
}
// End Class UMRUKBPLibrary Function RecalculateProceduralMeshAndTangents

// Begin Class UMRUKBPLibrary Function SetScaleRecursivelyAdjustingForRotation
struct Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics
{
	struct MRUKBPLibrary_eventSetScaleRecursivelyAdjustingForRotation_Parms
	{
		USceneComponent* SceneComponent;
		FVector UnRotatedScale;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MR Utility Kit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * In Unreal Engine, scale is always applied in the local space to avoid any skew.\n\x09 * This means that if you have a component which has a 90 degree rotation and is scaled, or any of its\n\x09 * children are scaled then the scale axes will not be applied as you would expect. This is can make it\n\x09 * very awkward to work with when trying to scale the actors to fit within the scene volumes. To work around\n\x09 * this problem, this function will attempt to adjust the scale axes recursively to match the expected behaviour.\n\x09 * This will only work reliably if the rotations involved are 90 degrees, if they are not then it will pick the closest axis.\n\x09 * @param SceneComponent        The component where the scale should be set\n\x09 * @param UnRotatedScale        The scale you would like to have without considering any rotations\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "In Unreal Engine, scale is always applied in the local space to avoid any skew.\nThis means that if you have a component which has a 90 degree rotation and is scaled, or any of its\nchildren are scaled then the scale axes will not be applied as you would expect. This is can make it\nvery awkward to work with when trying to scale the actors to fit within the scene volumes. To work around\nthis problem, this function will attempt to adjust the scale axes recursively to match the expected behaviour.\nThis will only work reliably if the rotations involved are 90 degrees, if they are not then it will pick the closest axis.\n@param SceneComponent        The component where the scale should be set\n@param UnRotatedScale        The scale you would like to have without considering any rotations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnRotatedScale_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UnRotatedScale;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics::NewProp_SceneComponent = { "SceneComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventSetScaleRecursivelyAdjustingForRotation_Parms, SceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneComponent_MetaData), NewProp_SceneComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics::NewProp_UnRotatedScale = { "UnRotatedScale", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MRUKBPLibrary_eventSetScaleRecursivelyAdjustingForRotation_Parms, UnRotatedScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnRotatedScale_MetaData), NewProp_UnRotatedScale_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics::NewProp_SceneComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics::NewProp_UnRotatedScale,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMRUKBPLibrary, nullptr, "SetScaleRecursivelyAdjustingForRotation", nullptr, nullptr, Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics::MRUKBPLibrary_eventSetScaleRecursivelyAdjustingForRotation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics::MRUKBPLibrary_eventSetScaleRecursivelyAdjustingForRotation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMRUKBPLibrary::execSetScaleRecursivelyAdjustingForRotation)
{
	P_GET_OBJECT(USceneComponent,Z_Param_SceneComponent);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_UnRotatedScale);
	P_FINISH;
	P_NATIVE_BEGIN;
	UMRUKBPLibrary::SetScaleRecursivelyAdjustingForRotation(Z_Param_SceneComponent,Z_Param_Out_UnRotatedScale);
	P_NATIVE_END;
}
// End Class UMRUKBPLibrary Function SetScaleRecursivelyAdjustingForRotation

// Begin Class UMRUKBPLibrary
void UMRUKBPLibrary::StaticRegisterNativesUMRUKBPLibrary()
{
	UClass* Class = UMRUKBPLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ComputeCentroid", &UMRUKBPLibrary::execComputeCentroid },
		{ "ComputeDirectionAwayFromClosestWall", &UMRUKBPLibrary::execComputeDirectionAwayFromClosestWall },
		{ "ConstructTexture2D", &UMRUKBPLibrary::execConstructTexture2D },
		{ "GetMatrixColumn", &UMRUKBPLibrary::execGetMatrixColumn },
		{ "IsUnrealEngineMetaFork", &UMRUKBPLibrary::execIsUnrealEngineMetaFork },
		{ "LoadGlobalMeshFromDevice", &UMRUKBPLibrary::execLoadGlobalMeshFromDevice },
		{ "LoadGlobalMeshFromJsonString", &UMRUKBPLibrary::execLoadGlobalMeshFromJsonString },
		{ "RecalculateProceduralMeshAndTangents", &UMRUKBPLibrary::execRecalculateProceduralMeshAndTangents },
		{ "SetScaleRecursivelyAdjustingForRotation", &UMRUKBPLibrary::execSetScaleRecursivelyAdjustingForRotation },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMRUKBPLibrary);
UClass* Z_Construct_UClass_UMRUKBPLibrary_NoRegister()
{
	return UMRUKBPLibrary::StaticClass();
}
struct Z_Construct_UClass_UMRUKBPLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MRUtilityKitBPLibrary.h" },
		{ "ModuleRelativePath", "Public/MRUtilityKitBPLibrary.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMRUKBPLibrary_ComputeCentroid, "ComputeCentroid" }, // 3759653751
		{ &Z_Construct_UFunction_UMRUKBPLibrary_ComputeDirectionAwayFromClosestWall, "ComputeDirectionAwayFromClosestWall" }, // 2279002095
		{ &Z_Construct_UFunction_UMRUKBPLibrary_ConstructTexture2D, "ConstructTexture2D" }, // 2009923517
		{ &Z_Construct_UFunction_UMRUKBPLibrary_GetMatrixColumn, "GetMatrixColumn" }, // 1179033302
		{ &Z_Construct_UFunction_UMRUKBPLibrary_IsUnrealEngineMetaFork, "IsUnrealEngineMetaFork" }, // 1525563760
		{ &Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromDevice, "LoadGlobalMeshFromDevice" }, // 2820977385
		{ &Z_Construct_UFunction_UMRUKBPLibrary_LoadGlobalMeshFromJsonString, "LoadGlobalMeshFromJsonString" }, // 2674160200
		{ &Z_Construct_UFunction_UMRUKBPLibrary_RecalculateProceduralMeshAndTangents, "RecalculateProceduralMeshAndTangents" }, // 1409334887
		{ &Z_Construct_UFunction_UMRUKBPLibrary_SetScaleRecursivelyAdjustingForRotation, "SetScaleRecursivelyAdjustingForRotation" }, // 2076112577
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMRUKBPLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMRUKBPLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_MRUtilityKit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMRUKBPLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMRUKBPLibrary_Statics::ClassParams = {
	&UMRUKBPLibrary::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMRUKBPLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UMRUKBPLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMRUKBPLibrary()
{
	if (!Z_Registration_Info_UClass_UMRUKBPLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMRUKBPLibrary.OuterSingleton, Z_Construct_UClass_UMRUKBPLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMRUKBPLibrary.OuterSingleton;
}
template<> MRUTILITYKIT_API UClass* StaticClass<UMRUKBPLibrary>()
{
	return UMRUKBPLibrary::StaticClass();
}
UMRUKBPLibrary::UMRUKBPLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMRUKBPLibrary);
UMRUKBPLibrary::~UMRUKBPLibrary() {}
// End Class UMRUKBPLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMRUKLoadFromDevice, UMRUKLoadFromDevice::StaticClass, TEXT("UMRUKLoadFromDevice"), &Z_Registration_Info_UClass_UMRUKLoadFromDevice, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMRUKLoadFromDevice), 3946553630U) },
		{ Z_Construct_UClass_UMRUKBPLibrary, UMRUKBPLibrary::StaticClass, TEXT("UMRUKBPLibrary"), &Z_Registration_Info_UClass_UMRUKBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMRUKBPLibrary), 1344037936U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_1435159669(TEXT("/Script/MRUtilityKit"),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
