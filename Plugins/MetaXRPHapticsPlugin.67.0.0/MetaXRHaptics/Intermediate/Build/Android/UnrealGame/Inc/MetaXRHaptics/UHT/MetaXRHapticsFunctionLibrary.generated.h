// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MetaXRHapticsFunctionLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UMetaXRHapticClip;
class UMetaXRHapticsPlayerComponent;
enum class EMetaXRHapticController : uint8;
#ifdef METAXRHAPTICS_MetaXRHapticsFunctionLibrary_generated_h
#error "MetaXRHapticsFunctionLibrary.generated.h already included, missing '#pragma once' in MetaXRHapticsFunctionLibrary.h"
#endif
#define METAXRHAPTICS_MetaXRHapticsFunctionLibrary_generated_h

#define FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsFunctionLibrary_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSpawnHapticsPlayerComponent);


#define FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsFunctionLibrary_h_31_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMetaXRHapticsFunctionLibrary(); \
	friend struct Z_Construct_UClass_UMetaXRHapticsFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UMetaXRHapticsFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MetaXRHaptics"), NO_API) \
	DECLARE_SERIALIZER(UMetaXRHapticsFunctionLibrary)


#define FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsFunctionLibrary_h_31_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMetaXRHapticsFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMetaXRHapticsFunctionLibrary(UMetaXRHapticsFunctionLibrary&&); \
	UMetaXRHapticsFunctionLibrary(const UMetaXRHapticsFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMetaXRHapticsFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMetaXRHapticsFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMetaXRHapticsFunctionLibrary) \
	NO_API virtual ~UMetaXRHapticsFunctionLibrary();


#define FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsFunctionLibrary_h_28_PROLOG
#define FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsFunctionLibrary_h_31_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsFunctionLibrary_h_31_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsFunctionLibrary_h_31_INCLASS_NO_PURE_DECLS \
	FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsFunctionLibrary_h_31_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> METAXRHAPTICS_API UClass* StaticClass<class UMetaXRHapticsFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_MetaXRHaptics_HostProject_Plugins_MetaXRHaptics_Source_MetaXRHaptics_Public_MetaXRHapticsFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
