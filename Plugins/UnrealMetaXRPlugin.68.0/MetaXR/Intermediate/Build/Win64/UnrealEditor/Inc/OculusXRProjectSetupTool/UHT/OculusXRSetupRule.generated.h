// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXRSetupRule.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OCULUSXRPROJECTSETUPTOOL_OculusXRSetupRule_generated_h
#error "OculusXRSetupRule.generated.h already included, missing '#pragma once' in OculusXRSetupRule.h"
#endif
#define OCULUSXRPROJECTSETUPTOOL_OculusXRSetupRule_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRProjectSetupTool_Public_OculusXRSetupRule_h


#define FOREACH_ENUM_ESETUPRULEPLATFORM(op) \
	op(ESetupRulePlatform::None) \
	op(ESetupRulePlatform::MetaLink) \
	op(ESetupRulePlatform::MetaQuest_2) \
	op(ESetupRulePlatform::MetaQuest_3) \
	op(ESetupRulePlatform::MetaQuest_Pro) 

enum class ESetupRulePlatform : uint32;
template<> struct TIsUEnumClass<ESetupRulePlatform> { enum { Value = true }; };
template<> OCULUSXRPROJECTSETUPTOOL_API UEnum* StaticEnum<ESetupRulePlatform>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
