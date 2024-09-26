// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MRUtilityKitBPLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AMRUKAnchor;
class UMRUKLoadFromDevice;
class UObject;
class UProceduralMeshComponent;
class USceneComponent;
class UTexture2D;
class UTextureRenderTarget2D;
struct FLinearColor;
struct FOculusXRUInt64;
struct FOculusXRUUID;
#ifdef MRUTILITYKIT_MRUtilityKitBPLibrary_generated_h
#error "MRUtilityKitBPLibrary.generated.h already included, missing '#pragma once' in MRUtilityKitBPLibrary.h"
#endif
#define MRUTILITYKIT_MRUtilityKitBPLibrary_generated_h

#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_17_DELEGATE \
static void FMRUKLoaded_DelegateWrapper(const FMulticastScriptDelegate& MRUKLoaded);


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnSceneLoaded); \
	DECLARE_FUNCTION(execLoadSceneFromDeviceAsync);


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMRUKLoadFromDevice(); \
	friend struct Z_Construct_UClass_UMRUKLoadFromDevice_Statics; \
public: \
	DECLARE_CLASS(UMRUKLoadFromDevice, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MRUtilityKit"), NO_API) \
	DECLARE_SERIALIZER(UMRUKLoadFromDevice)


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMRUKLoadFromDevice(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMRUKLoadFromDevice(UMRUKLoadFromDevice&&); \
	UMRUKLoadFromDevice(const UMRUKLoadFromDevice&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMRUKLoadFromDevice); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMRUKLoadFromDevice); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMRUKLoadFromDevice) \
	NO_API virtual ~UMRUKLoadFromDevice();


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_12_PROLOG
#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_15_INCLASS_NO_PURE_DECLS \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MRUTILITYKIT_API UClass* StaticClass<class UMRUKLoadFromDevice>();

#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetMatrixColumn); \
	DECLARE_FUNCTION(execConstructTexture2D); \
	DECLARE_FUNCTION(execComputeDirectionAwayFromClosestWall); \
	DECLARE_FUNCTION(execSetScaleRecursivelyAdjustingForRotation); \
	DECLARE_FUNCTION(execComputeCentroid); \
	DECLARE_FUNCTION(execIsUnrealEngineMetaFork); \
	DECLARE_FUNCTION(execRecalculateProceduralMeshAndTangents); \
	DECLARE_FUNCTION(execLoadGlobalMeshFromJsonString); \
	DECLARE_FUNCTION(execLoadGlobalMeshFromDevice);


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_42_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMRUKBPLibrary(); \
	friend struct Z_Construct_UClass_UMRUKBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UMRUKBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MRUtilityKit"), NO_API) \
	DECLARE_SERIALIZER(UMRUKBPLibrary)


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_42_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMRUKBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMRUKBPLibrary(UMRUKBPLibrary&&); \
	UMRUKBPLibrary(const UMRUKBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMRUKBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMRUKBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMRUKBPLibrary) \
	NO_API virtual ~UMRUKBPLibrary();


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_39_PROLOG
#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_42_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_42_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_42_INCLASS_NO_PURE_DECLS \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h_42_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MRUTILITYKIT_API UClass* StaticClass<class UMRUKBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
