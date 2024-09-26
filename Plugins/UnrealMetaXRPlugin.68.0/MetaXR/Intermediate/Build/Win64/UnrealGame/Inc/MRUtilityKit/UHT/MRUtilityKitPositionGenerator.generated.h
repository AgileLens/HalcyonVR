// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MRUtilityKitPositionGenerator.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AMRUKRoom;
#ifdef MRUTILITYKIT_MRUtilityKitPositionGenerator_generated_h
#error "MRUtilityKitPositionGenerator.generated.h already included, missing '#pragma once' in MRUtilityKitPositionGenerator.h"
#endif
#define MRUTILITYKIT_MRUtilityKitPositionGenerator_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_13_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMRUKRandomSpawnSettings_Statics; \
	MRUTILITYKIT_API static class UScriptStruct* StaticStruct();


template<> MRUTILITYKIT_API UScriptStruct* StaticStruct<struct FMRUKRandomSpawnSettings>();

#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_87_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSceneLoaded); \
	DECLARE_FUNCTION(execGenerateRandomPositionsOnSurfaceInRoom); \
	DECLARE_FUNCTION(execGenerateRandomPositionsOnSurface);


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_87_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMRUtilityKitPositionGenerator(); \
	friend struct Z_Construct_UClass_AMRUtilityKitPositionGenerator_Statics; \
public: \
	DECLARE_CLASS(AMRUtilityKitPositionGenerator, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MRUtilityKit"), NO_API) \
	DECLARE_SERIALIZER(AMRUtilityKitPositionGenerator)


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_87_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMRUtilityKitPositionGenerator(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMRUtilityKitPositionGenerator(AMRUtilityKitPositionGenerator&&); \
	AMRUtilityKitPositionGenerator(const AMRUtilityKitPositionGenerator&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMRUtilityKitPositionGenerator); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMRUtilityKitPositionGenerator); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMRUtilityKitPositionGenerator) \
	NO_API virtual ~AMRUtilityKitPositionGenerator();


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_84_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_87_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_87_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_87_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h_87_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MRUTILITYKIT_API UClass* StaticClass<class AMRUtilityKitPositionGenerator>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitPositionGenerator_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
