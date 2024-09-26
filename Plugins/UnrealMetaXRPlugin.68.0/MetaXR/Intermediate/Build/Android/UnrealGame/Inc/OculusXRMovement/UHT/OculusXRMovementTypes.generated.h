// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OculusXRMovementTypes.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef OCULUSXRMOVEMENT_OculusXRMovementTypes_generated_h
#error "OculusXRMovementTypes.generated.h already included, missing '#pragma once' in OculusXRMovementTypes.h"
#endif
#define OCULUSXRMOVEMENT_OculusXRMovementTypes_generated_h

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRMovementTypes_h_117_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRBodyJoint_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OCULUSXRMOVEMENT_API UScriptStruct* StaticStruct<struct FOculusXRBodyJoint>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRMovementTypes_h_136_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRBodyState_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OCULUSXRMOVEMENT_API UScriptStruct* StaticStruct<struct FOculusXRBodyState>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRMovementTypes_h_159_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRBodySkeletonBone_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OCULUSXRMOVEMENT_API UScriptStruct* StaticStruct<struct FOculusXRBodySkeletonBone>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRMovementTypes_h_179_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRBodySkeleton_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OCULUSXRMOVEMENT_API UScriptStruct* StaticStruct<struct FOculusXRBodySkeleton>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRMovementTypes_h_193_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRBodySkeletonState_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OCULUSXRMOVEMENT_API UScriptStruct* StaticStruct<struct FOculusXRBodySkeletonState>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRMovementTypes_h_300_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRFaceState_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OCULUSXRMOVEMENT_API UScriptStruct* StaticStruct<struct FOculusXRFaceState>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRMovementTypes_h_326_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXRFaceExpressionModifier_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OCULUSXRMOVEMENT_API UScriptStruct* StaticStruct<struct FOculusXRFaceExpressionModifier>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRMovementTypes_h_354_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXREyeGazeState_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OCULUSXRMOVEMENT_API UScriptStruct* StaticStruct<struct FOculusXREyeGazeState>();

#define FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRMovementTypes_h_374_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOculusXREyeGazesState_Statics; \
	static class UScriptStruct* StaticStruct();


template<> OCULUSXRMOVEMENT_API UScriptStruct* StaticStruct<struct FOculusXREyeGazesState>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_OculusXR_Source_OculusXRMovement_Public_OculusXRMovementTypes_h


#define FOREACH_ENUM_EOCULUSXRBODYJOINTSET(op) \
	op(EOculusXRBodyJointSet::UpperBody) \
	op(EOculusXRBodyJointSet::FullBody) 

enum class EOculusXRBodyJointSet : uint8;
template<> struct TIsUEnumClass<EOculusXRBodyJointSet> { enum { Value = true }; };
template<> OCULUSXRMOVEMENT_API UEnum* StaticEnum<EOculusXRBodyJointSet>();

#define FOREACH_ENUM_EOCULUSXRBODYTRACKINGFIDELITY(op) \
	op(EOculusXRBodyTrackingFidelity::Unset) \
	op(EOculusXRBodyTrackingFidelity::Low) \
	op(EOculusXRBodyTrackingFidelity::High) 

enum class EOculusXRBodyTrackingFidelity : uint8;
template<> struct TIsUEnumClass<EOculusXRBodyTrackingFidelity> { enum { Value = true }; };
template<> OCULUSXRMOVEMENT_API UEnum* StaticEnum<EOculusXRBodyTrackingFidelity>();

#define FOREACH_ENUM_EOCULUSXRBONEID(op) \
	op(EOculusXRBoneID::BodyRoot) \
	op(EOculusXRBoneID::BodyHips) \
	op(EOculusXRBoneID::BodySpineLower) \
	op(EOculusXRBoneID::BodySpineMiddle) \
	op(EOculusXRBoneID::BodySpineUpper) \
	op(EOculusXRBoneID::BodyChest) \
	op(EOculusXRBoneID::BodyNeck) \
	op(EOculusXRBoneID::BodyHead) \
	op(EOculusXRBoneID::BodyLeftShoulder) \
	op(EOculusXRBoneID::BodyLeftScapula) \
	op(EOculusXRBoneID::BodyLeftArmUpper) \
	op(EOculusXRBoneID::BodyLeftArmLower) \
	op(EOculusXRBoneID::BodyLeftHandWristTwist) \
	op(EOculusXRBoneID::BodyRightShoulder) \
	op(EOculusXRBoneID::BodyRightScapula) \
	op(EOculusXRBoneID::BodyRightArmUpper) \
	op(EOculusXRBoneID::BodyRightArmLower) \
	op(EOculusXRBoneID::BodyRightHandWristTwist) \
	op(EOculusXRBoneID::BodyLeftHandPalm) \
	op(EOculusXRBoneID::BodyLeftHandWrist) \
	op(EOculusXRBoneID::BodyLeftHandThumbMetacarpal) \
	op(EOculusXRBoneID::BodyLeftHandThumbProximal) \
	op(EOculusXRBoneID::BodyLeftHandThumbDistal) \
	op(EOculusXRBoneID::BodyLeftHandThumbTip) \
	op(EOculusXRBoneID::BodyLeftHandIndexMetacarpal) \
	op(EOculusXRBoneID::BodyLeftHandIndexProximal) \
	op(EOculusXRBoneID::BodyLeftHandIndexIntermediate) \
	op(EOculusXRBoneID::BodyLeftHandIndexDistal) \
	op(EOculusXRBoneID::BodyLeftHandIndexTip) \
	op(EOculusXRBoneID::BodyLeftHandMiddleMetacarpal) \
	op(EOculusXRBoneID::BodyLeftHandMiddleProximal) \
	op(EOculusXRBoneID::BodyLeftHandMiddleIntermediate) \
	op(EOculusXRBoneID::BodyLeftHandMiddleDistal) \
	op(EOculusXRBoneID::BodyLeftHandMiddleTip) \
	op(EOculusXRBoneID::BodyLeftHandRingMetacarpal) \
	op(EOculusXRBoneID::BodyLeftHandRingProximal) \
	op(EOculusXRBoneID::BodyLeftHandRingIntermediate) \
	op(EOculusXRBoneID::BodyLeftHandRingDistal) \
	op(EOculusXRBoneID::BodyLeftHandRingTip) \
	op(EOculusXRBoneID::BodyLeftHandLittleMetacarpal) \
	op(EOculusXRBoneID::BodyLeftHandLittleProximal) \
	op(EOculusXRBoneID::BodyLeftHandLittleIntermediate) \
	op(EOculusXRBoneID::BodyLeftHandLittleDistal) \
	op(EOculusXRBoneID::BodyLeftHandLittleTip) \
	op(EOculusXRBoneID::BodyRightHandPalm) \
	op(EOculusXRBoneID::BodyRightHandWrist) \
	op(EOculusXRBoneID::BodyRightHandThumbMetacarpal) \
	op(EOculusXRBoneID::BodyRightHandThumbProximal) \
	op(EOculusXRBoneID::BodyRightHandThumbDistal) \
	op(EOculusXRBoneID::BodyRightHandThumbTip) \
	op(EOculusXRBoneID::BodyRightHandIndexMetacarpal) \
	op(EOculusXRBoneID::BodyRightHandIndexProximal) \
	op(EOculusXRBoneID::BodyRightHandIndexIntermediate) \
	op(EOculusXRBoneID::BodyRightHandIndexDistal) \
	op(EOculusXRBoneID::BodyRightHandIndexTip) \
	op(EOculusXRBoneID::BodyRightHandMiddleMetacarpal) \
	op(EOculusXRBoneID::BodyRightHandMiddleProximal) \
	op(EOculusXRBoneID::BodyRightHandMiddleIntermediate) \
	op(EOculusXRBoneID::BodyRightHandMiddleDistal) \
	op(EOculusXRBoneID::BodyRightHandMiddleTip) \
	op(EOculusXRBoneID::BodyRightHandRingMetacarpal) \
	op(EOculusXRBoneID::BodyRightHandRingProximal) \
	op(EOculusXRBoneID::BodyRightHandRingIntermediate) \
	op(EOculusXRBoneID::BodyRightHandRingDistal) \
	op(EOculusXRBoneID::BodyRightHandRingTip) \
	op(EOculusXRBoneID::BodyRightHandLittleMetacarpal) \
	op(EOculusXRBoneID::BodyRightHandLittleProximal) \
	op(EOculusXRBoneID::BodyRightHandLittleIntermediate) \
	op(EOculusXRBoneID::BodyRightHandLittleDistal) \
	op(EOculusXRBoneID::BodyRightHandLittleTip) \
	op(EOculusXRBoneID::BodyLeftUpperLeg) \
	op(EOculusXRBoneID::BodyLeftLowerLeg) \
	op(EOculusXRBoneID::BodyLeftFootAnkleTwist) \
	op(EOculusXRBoneID::BodyLeftFootAnkle) \
	op(EOculusXRBoneID::BodyLeftFootSubtalar) \
	op(EOculusXRBoneID::BodyLeftFootTransverse) \
	op(EOculusXRBoneID::BodyLeftFootBall) \
	op(EOculusXRBoneID::BodyRightUpperLeg) \
	op(EOculusXRBoneID::BodyRightLowerLeg) \
	op(EOculusXRBoneID::BodyRightFootAnkleTwist) \
	op(EOculusXRBoneID::BodyRightFootAnkle) \
	op(EOculusXRBoneID::BodyRightFootSubtalar) \
	op(EOculusXRBoneID::BodyRightFootTransverse) \
	op(EOculusXRBoneID::BodyRightFootBall) \
	op(EOculusXRBoneID::COUNT) \
	op(EOculusXRBoneID::None) 

enum class EOculusXRBoneID : uint8;
template<> struct TIsUEnumClass<EOculusXRBoneID> { enum { Value = true }; };
template<> OCULUSXRMOVEMENT_API UEnum* StaticEnum<EOculusXRBoneID>();

#define FOREACH_ENUM_EFACETRACKINGDATASOURCE(op) \
	op(EFaceTrackingDataSource::Visual) \
	op(EFaceTrackingDataSource::Audio) 

enum class EFaceTrackingDataSource : uint8;
template<> struct TIsUEnumClass<EFaceTrackingDataSource> { enum { Value = true }; };
template<> OCULUSXRMOVEMENT_API UEnum* StaticEnum<EFaceTrackingDataSource>();

#define FOREACH_ENUM_EOCULUSXRFACEEXPRESSION(op) \
	op(EOculusXRFaceExpression::BrowLowererL) \
	op(EOculusXRFaceExpression::BrowLowererR) \
	op(EOculusXRFaceExpression::CheekPuffL) \
	op(EOculusXRFaceExpression::CheekPuffR) \
	op(EOculusXRFaceExpression::CheekRaiserL) \
	op(EOculusXRFaceExpression::CheekRaiserR) \
	op(EOculusXRFaceExpression::CheekSuckL) \
	op(EOculusXRFaceExpression::CheekSuckR) \
	op(EOculusXRFaceExpression::ChinRaiserB) \
	op(EOculusXRFaceExpression::ChinRaiserT) \
	op(EOculusXRFaceExpression::DimplerL) \
	op(EOculusXRFaceExpression::DimplerR) \
	op(EOculusXRFaceExpression::EyesClosedL) \
	op(EOculusXRFaceExpression::EyesClosedR) \
	op(EOculusXRFaceExpression::EyesLookDownL) \
	op(EOculusXRFaceExpression::EyesLookDownR) \
	op(EOculusXRFaceExpression::EyesLookLeftL) \
	op(EOculusXRFaceExpression::EyesLookLeftR) \
	op(EOculusXRFaceExpression::EyesLookRightL) \
	op(EOculusXRFaceExpression::EyesLookRightR) \
	op(EOculusXRFaceExpression::EyesLookUpL) \
	op(EOculusXRFaceExpression::EyesLookUpR) \
	op(EOculusXRFaceExpression::InnerBrowRaiserL) \
	op(EOculusXRFaceExpression::InnerBrowRaiserR) \
	op(EOculusXRFaceExpression::JawDrop) \
	op(EOculusXRFaceExpression::JawSidewaysLeft) \
	op(EOculusXRFaceExpression::JawSidewaysRight) \
	op(EOculusXRFaceExpression::JawThrust) \
	op(EOculusXRFaceExpression::LidTightenerL) \
	op(EOculusXRFaceExpression::LidTightenerR) \
	op(EOculusXRFaceExpression::LipCornerDepressorL) \
	op(EOculusXRFaceExpression::LipCornerDepressorR) \
	op(EOculusXRFaceExpression::LipCornerPullerL) \
	op(EOculusXRFaceExpression::LipCornerPullerR) \
	op(EOculusXRFaceExpression::LipFunnelerLB) \
	op(EOculusXRFaceExpression::LipFunnelerLT) \
	op(EOculusXRFaceExpression::LipFunnelerRB) \
	op(EOculusXRFaceExpression::LipFunnelerRT) \
	op(EOculusXRFaceExpression::LipPressorL) \
	op(EOculusXRFaceExpression::LipPressorR) \
	op(EOculusXRFaceExpression::LipPuckerL) \
	op(EOculusXRFaceExpression::LipPuckerR) \
	op(EOculusXRFaceExpression::LipStretcherL) \
	op(EOculusXRFaceExpression::LipStretcherR) \
	op(EOculusXRFaceExpression::LipSuckLB) \
	op(EOculusXRFaceExpression::LipSuckLT) \
	op(EOculusXRFaceExpression::LipSuckRB) \
	op(EOculusXRFaceExpression::LipSuckRT) \
	op(EOculusXRFaceExpression::LipTightenerL) \
	op(EOculusXRFaceExpression::LipTightenerR) \
	op(EOculusXRFaceExpression::LipsToward) \
	op(EOculusXRFaceExpression::LowerLipDepressorL) \
	op(EOculusXRFaceExpression::LowerLipDepressorR) \
	op(EOculusXRFaceExpression::MouthLeft) \
	op(EOculusXRFaceExpression::MouthRight) \
	op(EOculusXRFaceExpression::NoseWrinklerL) \
	op(EOculusXRFaceExpression::NoseWrinklerR) \
	op(EOculusXRFaceExpression::OuterBrowRaiserL) \
	op(EOculusXRFaceExpression::OuterBrowRaiserR) \
	op(EOculusXRFaceExpression::UpperLidRaiserL) \
	op(EOculusXRFaceExpression::UpperLidRaiserR) \
	op(EOculusXRFaceExpression::UpperLipRaiserL) \
	op(EOculusXRFaceExpression::UpperLipRaiserR) \
	op(EOculusXRFaceExpression::TongueTipInterdental) \
	op(EOculusXRFaceExpression::TongueTipAlveolar) \
	op(EOculusXRFaceExpression::TongueFrontDorsalPalate) \
	op(EOculusXRFaceExpression::TongueMidDorsalPalate) \
	op(EOculusXRFaceExpression::TongueBackDorsalVelar) \
	op(EOculusXRFaceExpression::TongueOut) \
	op(EOculusXRFaceExpression::TongueRetreat) \
	op(EOculusXRFaceExpression::COUNT) 

enum class EOculusXRFaceExpression : uint8;
template<> struct TIsUEnumClass<EOculusXRFaceExpression> { enum { Value = true }; };
template<> OCULUSXRMOVEMENT_API UEnum* StaticEnum<EOculusXRFaceExpression>();

#define FOREACH_ENUM_EOCULUSXRFACECONFIDENCE(op) \
	op(EOculusXRFaceConfidence::Lower) \
	op(EOculusXRFaceConfidence::Upper) \
	op(EOculusXRFaceConfidence::COUNT) 

enum class EOculusXRFaceConfidence : uint8;
template<> struct TIsUEnumClass<EOculusXRFaceConfidence> { enum { Value = true }; };
template<> OCULUSXRMOVEMENT_API UEnum* StaticEnum<EOculusXRFaceConfidence>();

#define FOREACH_ENUM_EOCULUSXREYE(op) \
	op(EOculusXREye::Left) \
	op(EOculusXREye::Right) \
	op(EOculusXREye::COUNT) 

enum class EOculusXREye : uint8;
template<> struct TIsUEnumClass<EOculusXREye> { enum { Value = true }; };
template<> OCULUSXRMOVEMENT_API UEnum* StaticEnum<EOculusXREye>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
