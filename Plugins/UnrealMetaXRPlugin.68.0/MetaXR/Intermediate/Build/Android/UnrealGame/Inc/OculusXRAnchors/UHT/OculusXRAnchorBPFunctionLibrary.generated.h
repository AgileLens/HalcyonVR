// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXRAnchorBPFunctionLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class APawn;
class UObject;
class UOculusXRBaseAnchorComponent;
enum class EOculusXRSpaceComponentType : uint8;
enum class EOculusXRSpaceStorageLocation : uint8;
enum class ESpawnActorCollisionHandlingMethod : uint8;
struct FOculusXRAnchorLocationFlags;
struct FOculusXRRoomLayout;
struct FOculusXRSpaceQueryResult;
struct FOculusXRUInt64;
struct FOculusXRUUID;
#ifdef OCULUSXRANCHORS_OculusXRAnchorBPFunctionLibrary_generated_h
#error "OculusXRAnchorBPFunctionLibrary.generated.h already included, missing '#pragma once' in OculusXRAnchorBPFunctionLibrary.h"
#endif
#define OCULUSXRANCHORS_OculusXRAnchorBPFunctionLibrary_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRAnchorBPFunctionLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetRoomLayout); \
	DECLARE_FUNCTION(execGetAnchorComponent); \
	DECLARE_FUNCTION(execIsAnchorResultSuccess); \
	DECLARE_FUNCTION(execIsEqual_FOculusXRUUID); \
	DECLARE_FUNCTION(execIsEqual_FOculusXRUInt64); \
	DECLARE_FUNCTION(execStringToAnchorUUID); \
	DECLARE_FUNCTION(execAnchorUUIDToString); \
	DECLARE_FUNCTION(execAnchorHandleToString); \
	DECLARE_FUNCTION(execTryGetAnchorTransformByHandle); \
	DECLARE_FUNCTION(execGetAnchorTransformByHandle); \
	DECLARE_FUNCTION(execGetAnchorComponentStatus); \
	DECLARE_FUNCTION(execSpawnActorWithAnchorQueryResults); \
	DECLARE_FUNCTION(execSpawnActorWithAnchorHandle);


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRAnchorBPFunctionLibrary_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOculusXRAnchorBPFunctionLibrary(); \
	friend struct Z_Construct_UClass_UOculusXRAnchorBPFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UOculusXRAnchorBPFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OculusXRAnchors"), NO_API) \
	DECLARE_SERIALIZER(UOculusXRAnchorBPFunctionLibrary)


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRAnchorBPFunctionLibrary_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOculusXRAnchorBPFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOculusXRAnchorBPFunctionLibrary(UOculusXRAnchorBPFunctionLibrary&&); \
	UOculusXRAnchorBPFunctionLibrary(const UOculusXRAnchorBPFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOculusXRAnchorBPFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOculusXRAnchorBPFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOculusXRAnchorBPFunctionLibrary) \
	NO_API virtual ~UOculusXRAnchorBPFunctionLibrary();


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRAnchorBPFunctionLibrary_h_12_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRAnchorBPFunctionLibrary_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRAnchorBPFunctionLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRAnchorBPFunctionLibrary_h_15_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRAnchorBPFunctionLibrary_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OCULUSXRANCHORS_API UClass* StaticClass<class UOculusXRAnchorBPFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_OculusXRAnchors_Public_OculusXRAnchorBPFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
