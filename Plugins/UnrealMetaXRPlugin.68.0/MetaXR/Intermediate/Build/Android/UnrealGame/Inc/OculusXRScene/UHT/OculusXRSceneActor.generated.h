// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXRSceneActor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FOculusXRRoomLayout;
#ifdef OCULUSXRSCENE_OculusXRSceneActor_generated_h
#error "OculusXRSceneActor.generated.h already included, missing '#pragma once' in OculusXRSceneActor.h"
#endif
#define OCULUSXRSCENE_OculusXRSceneActor_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_36_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRSpawnedSceneAnchorProperties_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OCULUSXRSCENE_API UScriptStruct* StaticStruct<struct FOculusXRSpawnedSceneAnchorProperties>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_73_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetRoomLayouts); \
	DECLARE_FUNCTION(execGetActorsBySemanticLabel); \
	DECLARE_FUNCTION(execSetVisibilityToSceneAnchorsBySemanticLabel); \
	DECLARE_FUNCTION(execSetVisibilityToAllSceneAnchors); \
	DECLARE_FUNCTION(execClearScene); \
	DECLARE_FUNCTION(execPopulateScene); \
	DECLARE_FUNCTION(execIsRoomLayoutValid); \
	DECLARE_FUNCTION(execIsScenePopulated); \
	DECLARE_FUNCTION(execLaunchCaptureFlow);


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_73_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAOculusXRSceneActor(); \
	friend struct Z_Construct_UClass_AOculusXRSceneActor_Statics; \
public: \
	DECLARE_CLASS(AOculusXRSceneActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OculusXRScene"), NO_API) \
	DECLARE_SERIALIZER(AOculusXRSceneActor)


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_73_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AOculusXRSceneActor(AOculusXRSceneActor&&); \
	AOculusXRSceneActor(const AOculusXRSceneActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AOculusXRSceneActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AOculusXRSceneActor); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AOculusXRSceneActor) \
	NO_API virtual ~AOculusXRSceneActor();


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_70_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_73_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_73_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_73_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h_73_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OCULUSXRSCENE_API UClass* StaticClass<class AOculusXRSceneActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneActor_h


#define FOREACH_ENUM_EOCULUSXRLAUNCHCAPTUREFLOWWHENMISSINGSCENE(op) \
	op(NEVER) \
	op(ONCE) \
	op(ALWAYS) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
