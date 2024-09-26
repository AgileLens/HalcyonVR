// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MRUtilityKitDistanceMapGenerator.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AMRUKAnchor;
class AMRUKRoom;
class UCanvasRenderTarget2D;
class UTexture;
struct FMinimalViewInfo;
#ifdef MRUTILITYKIT_MRUtilityKitDistanceMapGenerator_generated_h
#error "MRUtilityKitDistanceMapGenerator.generated.h already included, missing '#pragma once' in MRUtilityKitDistanceMapGenerator.h"
#endif
#define MRUTILITYKIT_MRUtilityKitDistanceMapGenerator_generated_h

#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_49_DELEGATE \
static void FOnReady_DelegateWrapper(const FMulticastScriptDelegate& OnReady);


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUpdateMaskMeshOfAnchor); \
	DECLARE_FUNCTION(execCreateMaskMeshOfAnchor); \
	DECLARE_FUNCTION(execOnRoomCreated); \
	DECLARE_FUNCTION(execGetSceneCaptureView); \
	DECLARE_FUNCTION(execGetDistanceMapRenderTarget); \
	DECLARE_FUNCTION(execGetDistanceMap); \
	DECLARE_FUNCTION(execRemoveMaskMeshesFromRoom); \
	DECLARE_FUNCTION(execCreateMaskMeshesForRoom); \
	DECLARE_FUNCTION(execCaptureDistanceMap);


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_46_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMRUKDistanceMapGenerator(); \
	friend struct Z_Construct_UClass_AMRUKDistanceMapGenerator_Statics; \
public: \
	DECLARE_CLASS(AMRUKDistanceMapGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MRUtilityKit"), NO_API) \
	DECLARE_SERIALIZER(AMRUKDistanceMapGenerator)


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_46_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMRUKDistanceMapGenerator(AMRUKDistanceMapGenerator&&); \
	AMRUKDistanceMapGenerator(const AMRUKDistanceMapGenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMRUKDistanceMapGenerator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMRUKDistanceMapGenerator); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMRUKDistanceMapGenerator) \
	NO_API virtual ~AMRUKDistanceMapGenerator();


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_43_PROLOG
#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_46_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_46_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_46_INCLASS_NO_PURE_DECLS \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h_46_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MRUTILITYKIT_API UClass* StaticClass<class AMRUKDistanceMapGenerator>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitDistanceMapGenerator_h


#define FOREACH_ENUM_EMRUKDISTANCEMAPGENERATIONMODE(op) \
	op(EMRUKDistanceMapGenerationMode::None) \
	op(EMRUKDistanceMapGenerationMode::FreeSpace) \
	op(EMRUKDistanceMapGenerationMode::OccupiedSpace) \
	op(EMRUKDistanceMapGenerationMode::AllSpace) 

enum class EMRUKDistanceMapGenerationMode : uint8;
template<> struct TIsUEnumClass<EMRUKDistanceMapGenerationMode> { enum { Value = true }; };
template<> MRUTILITYKIT_API UEnum* StaticEnum<EMRUKDistanceMapGenerationMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
