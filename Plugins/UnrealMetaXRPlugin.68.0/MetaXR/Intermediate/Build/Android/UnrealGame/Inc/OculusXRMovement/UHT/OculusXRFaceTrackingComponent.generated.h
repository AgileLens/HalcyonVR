// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXRFaceTrackingComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EOculusXRFaceExpression : uint8;
#ifdef OCULUSXRMOVEMENT_OculusXRFaceTrackingComponent_generated_h
#error "OculusXRFaceTrackingComponent.generated.h already included, missing '#pragma once' in OculusXRFaceTrackingComponent.h"
#endif
#define OCULUSXRMOVEMENT_OculusXRFaceTrackingComponent_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRFaceTrackingComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execClearExpressionValues); \
	DECLARE_FUNCTION(execGetExpressionValue); \
	DECLARE_FUNCTION(execSetExpressionValue);


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRFaceTrackingComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOculusXRFaceTrackingComponent(); \
	friend struct Z_Construct_UClass_UOculusXRFaceTrackingComponent_Statics; \
public: \
	DECLARE_CLASS(UOculusXRFaceTrackingComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OculusXRMovement"), NO_API) \
	DECLARE_SERIALIZER(UOculusXRFaceTrackingComponent)


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRFaceTrackingComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UOculusXRFaceTrackingComponent(UOculusXRFaceTrackingComponent&&); \
	UOculusXRFaceTrackingComponent(const UOculusXRFaceTrackingComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOculusXRFaceTrackingComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOculusXRFaceTrackingComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOculusXRFaceTrackingComponent) \
	NO_API virtual ~UOculusXRFaceTrackingComponent();


#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRFaceTrackingComponent_h_12_PROLOG
#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRFaceTrackingComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRFaceTrackingComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRFaceTrackingComponent_h_15_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRFaceTrackingComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> OCULUSXRMOVEMENT_API UClass* StaticClass<class UOculusXRFaceTrackingComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRFaceTrackingComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
