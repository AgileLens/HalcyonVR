// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MRUtilityKitLightDispatcher.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef MRUTILITYKIT_MRUtilityKitLightDispatcher_generated_h
#error "MRUtilityKitLightDispatcher.generated.h already included, missing '#pragma once' in MRUtilityKitLightDispatcher.h"
#endif
#define MRUTILITYKIT_MRUtilityKitLightDispatcher_generated_h

#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitLightDispatcher_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execForceUpdateCollection); \
	DECLARE_FUNCTION(execAddAdditionalPointLightActor);


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitLightDispatcher_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMRUKLightDispatcher(); \
	friend struct Z_Construct_UClass_AMRUKLightDispatcher_Statics; \
public: \
	DECLARE_CLASS(AMRUKLightDispatcher, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MRUtilityKit"), NO_API) \
	DECLARE_SERIALIZER(AMRUKLightDispatcher)


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitLightDispatcher_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMRUKLightDispatcher(AMRUKLightDispatcher&&); \
	AMRUKLightDispatcher(const AMRUKLightDispatcher&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMRUKLightDispatcher); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMRUKLightDispatcher); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMRUKLightDispatcher) \
	NO_API virtual ~AMRUKLightDispatcher();


#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitLightDispatcher_h_13_PROLOG
#define FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitLightDispatcher_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitLightDispatcher_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitLightDispatcher_h_16_INCLASS_NO_PURE_DECLS \
	FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitLightDispatcher_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MRUTILITYKIT_API UClass* StaticClass<class AMRUKLightDispatcher>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_MRUtilityKit_Public_MRUtilityKitLightDispatcher_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
