// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXRSceneFunctionLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
enum class EOculusXRBoundaryVisibility : uint8;
#ifdef OCULUSXRSCENE_OculusXRSceneFunctionLibrary_generated_h
#error "OculusXRSceneFunctionLibrary.generated.h already included, missing '#pragma once' in OculusXRSceneFunctionLibrary.h"
#endif
#define OCULUSXRSCENE_OculusXRSceneFunctionLibrary_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneFunctionLibrary_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRequestBoundaryVisibility); \
	DECLARE_FUNCTION(execGetRequestedBoundaryVisibility); \
	DECLARE_FUNCTION(execGetBoundaryVisibility);


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneFunctionLibrary_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOculusXRSceneFunctionLibrary(); \
	friend struct Z_Construct_UClass_UOculusXRSceneFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UOculusXRSceneFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OculusXRScene"), NO_API) \
	DECLARE_SERIALIZER(UOculusXRSceneFunctionLibrary)


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneFunctionLibrary_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOculusXRSceneFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOculusXRSceneFunctionLibrary(UOculusXRSceneFunctionLibrary&&); \
	UOculusXRSceneFunctionLibrary(const UOculusXRSceneFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOculusXRSceneFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOculusXRSceneFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOculusXRSceneFunctionLibrary) \
	NO_API virtual ~UOculusXRSceneFunctionLibrary();


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneFunctionLibrary_h_10_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneFunctionLibrary_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneFunctionLibrary_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneFunctionLibrary_h_13_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneFunctionLibrary_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OCULUSXRSCENE_API UClass* StaticClass<class UOculusXRSceneFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_OculusXRScene_Public_OculusXRSceneFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
