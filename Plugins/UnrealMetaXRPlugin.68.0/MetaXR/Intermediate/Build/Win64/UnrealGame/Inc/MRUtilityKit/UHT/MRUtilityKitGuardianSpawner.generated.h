// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MRUtilityKitGuardianSpawner.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AMRUKRoom;
class UMaterialInstance;
#ifdef MRUTILITYKIT_MRUtilityKitGuardianSpawner_generated_h
#error "MRUtilityKitGuardianSpawner.generated.h already included, missing '#pragma once' in MRUtilityKitGuardianSpawner.h"
#endif
#define MRUTILITYKIT_MRUtilityKitGuardianSpawner_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGuardianSpawner_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnRoomRemoved); \
	DECLARE_FUNCTION(execOnRoomUpdated); \
	DECLARE_FUNCTION(execOnRoomCreated); \
	DECLARE_FUNCTION(execDestroyGuardians); \
	DECLARE_FUNCTION(execSetGridDensity); \
	DECLARE_FUNCTION(execSetGuardianMaterial); \
	DECLARE_FUNCTION(execSpawnGuardians);


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGuardianSpawner_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMRUKGuardianSpawner(); \
	friend struct Z_Construct_UClass_AMRUKGuardianSpawner_Statics; \
public: \
	DECLARE_CLASS(AMRUKGuardianSpawner, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MRUtilityKit"), NO_API) \
	DECLARE_SERIALIZER(AMRUKGuardianSpawner)


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGuardianSpawner_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMRUKGuardianSpawner(AMRUKGuardianSpawner&&); \
	AMRUKGuardianSpawner(const AMRUKGuardianSpawner&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMRUKGuardianSpawner); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMRUKGuardianSpawner); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMRUKGuardianSpawner) \
	NO_API virtual ~AMRUKGuardianSpawner();


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGuardianSpawner_h_15_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGuardianSpawner_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGuardianSpawner_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGuardianSpawner_h_18_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGuardianSpawner_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MRUTILITYKIT_API UClass* StaticClass<class AMRUKGuardianSpawner>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitGuardianSpawner_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
