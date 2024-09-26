// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MRUtilityKitAnchorActorSpawner.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AMRUKAnchor;
class AMRUKRoom;
enum class EMRUKAlignMode : uint8;
enum class EMRUKSpawnerScalingMode : uint8;
struct FMRUKSpawnActor;
struct FMRUKSpawnGroup;
struct FRandomStream;
#ifdef MRUTILITYKIT_MRUtilityKitAnchorActorSpawner_generated_h
#error "MRUtilityKitAnchorActorSpawner.generated.h already included, missing '#pragma once' in MRUtilityKitAnchorActorSpawner.h"
#endif
#define MRUTILITYKIT_MRUtilityKitAnchorActorSpawner_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_24_DELEGATE \
static void FOnInteriorSpawned_DelegateWrapper(const FMulticastScriptDelegate& OnInteriorSpawned, AMRUKRoom* Room);


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRemoveActors); \
	DECLARE_FUNCTION(execOnRoomRemoved); \
	DECLARE_FUNCTION(execOnRoomUpdated); \
	DECLARE_FUNCTION(execOnRoomCreated); \
	DECLARE_FUNCTION(execAttachAndFitActorToAnchor); \
	DECLARE_FUNCTION(execSelectSpawnActorFromSpawnGroup); \
	DECLARE_FUNCTION(execSelectSpawnActorRandom); \
	DECLARE_FUNCTION(execSelectSpawnActorClosestSize); \
	DECLARE_FUNCTION(execSpawnProceduralMeshesInRoom); \
	DECLARE_FUNCTION(execSpawnProceduralMeshForAnchorIfNeeded); \
	DECLARE_FUNCTION(execSpawnProceduralMeshOnCeilingIfNoCeilingActorGiven); \
	DECLARE_FUNCTION(execSpawnProceduralMeshOnFloorIfNoFloorActorGiven); \
	DECLARE_FUNCTION(execSpawnProceduralMeshesOnWallsIfNoWallActorGiven); \
	DECLARE_FUNCTION(execShouldSpawnActorForAnchor); \
	DECLARE_FUNCTION(execShouldAnchorFallbackToProceduralMesh); \
	DECLARE_FUNCTION(execComputeCustomAlign); \
	DECLARE_FUNCTION(execSelectSpawnActorCustom); \
	DECLARE_FUNCTION(execComputeCustomScaling); \
	DECLARE_FUNCTION(execSpawnAnchorActor); \
	DECLARE_FUNCTION(execSpawnAnchorActorForLabel); \
	DECLARE_FUNCTION(execSpawnAnchorActorsInRoom); \
	DECLARE_FUNCTION(execGetSpawnedActors); \
	DECLARE_FUNCTION(execGetSpawnedActorsByRoom); \
	DECLARE_FUNCTION(execSpawnActors);


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_21_CALLBACK_WRAPPERS
#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMRUKAnchorActorSpawner(); \
	friend struct Z_Construct_UClass_AMRUKAnchorActorSpawner_Statics; \
public: \
	DECLARE_CLASS(AMRUKAnchorActorSpawner, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MRUtilityKit"), NO_API) \
	DECLARE_SERIALIZER(AMRUKAnchorActorSpawner)


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMRUKAnchorActorSpawner(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMRUKAnchorActorSpawner(AMRUKAnchorActorSpawner&&); \
	AMRUKAnchorActorSpawner(const AMRUKAnchorActorSpawner&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMRUKAnchorActorSpawner); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMRUKAnchorActorSpawner); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMRUKAnchorActorSpawner) \
	NO_API virtual ~AMRUKAnchorActorSpawner();


#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_18_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_21_CALLBACK_WRAPPERS \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_21_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MRUTILITYKIT_API UClass* StaticClass<class AMRUKAnchorActorSpawner>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_MRUtilityKit_Public_MRUtilityKitAnchorActorSpawner_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
