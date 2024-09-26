// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OculusXRInput/Public/OculusXRInputFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRInputFunctionLibrary() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UHapticFeedbackEffect_Buffer_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UHapticFeedbackEffect_Curve_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UHapticFeedbackEffect_SoundWave_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USkinnedMeshComponent_NoRegister();
INPUTCORE_API UEnum* Z_Construct_UEnum_InputCore_EControllerHand();
OCULUSXRINPUT_API UClass* Z_Construct_UClass_UOculusXRInputFunctionLibrary();
OCULUSXRINPUT_API UClass* Z_Construct_UClass_UOculusXRInputFunctionLibrary_NoRegister();
OCULUSXRINPUT_API UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRBone();
OCULUSXRINPUT_API UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRControllerDrivenHandPoseTypes();
OCULUSXRINPUT_API UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRFinger();
OCULUSXRINPUT_API UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRHandHapticsLocation();
OCULUSXRINPUT_API UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRHandType();
OCULUSXRINPUT_API UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRSide();
OCULUSXRINPUT_API UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRTrackingConfidence();
OCULUSXRINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FOculusXRCapsuleCollider();
UPackage* Z_Construct_UPackage__Script_OculusXRInput();
// End Cross Module References

// Begin Enum EOculusXRHandType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRHandType;
static UEnum* EOculusXRHandType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRHandType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRHandType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRInput_EOculusXRHandType, (UObject*)Z_Construct_UPackage__Script_OculusXRInput(), TEXT("EOculusXRHandType"));
	}
	return Z_Registration_Info_UEnum_EOculusXRHandType.OuterSingleton;
}
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRHandType>()
{
	return EOculusXRHandType_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRInput_EOculusXRHandType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HandLeft.Name", "EOculusXRHandType::HandLeft" },
		{ "HandRight.Name", "EOculusXRHandType::HandRight" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
		{ "None.Name", "EOculusXRHandType::None" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRHandType::None", (int64)EOculusXRHandType::None },
		{ "EOculusXRHandType::HandLeft", (int64)EOculusXRHandType::HandLeft },
		{ "EOculusXRHandType::HandRight", (int64)EOculusXRHandType::HandRight },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRInput_EOculusXRHandType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRInput,
	nullptr,
	"EOculusXRHandType",
	"EOculusXRHandType",
	Z_Construct_UEnum_OculusXRInput_EOculusXRHandType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRHandType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRHandType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRInput_EOculusXRHandType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRHandType()
{
	if (!Z_Registration_Info_UEnum_EOculusXRHandType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRHandType.InnerSingleton, Z_Construct_UEnum_OculusXRInput_EOculusXRHandType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRHandType.InnerSingleton;
}
// End Enum EOculusXRHandType

// Begin Enum EOculusXRSide
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRSide;
static UEnum* EOculusXRSide_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRSide.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRSide.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRInput_EOculusXRSide, (UObject*)Z_Construct_UPackage__Script_OculusXRInput(), TEXT("EOculusXRSide"));
	}
	return Z_Registration_Info_UEnum_EOculusXRSide.OuterSingleton;
}
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRSide>()
{
	return EOculusXRSide_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRInput_EOculusXRSide_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Left.Name", "EOculusXRSide::Left" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
		{ "None.Name", "EOculusXRSide::None" },
		{ "Right.Name", "EOculusXRSide::Right" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRSide::None", (int64)EOculusXRSide::None },
		{ "EOculusXRSide::Left", (int64)EOculusXRSide::Left },
		{ "EOculusXRSide::Right", (int64)EOculusXRSide::Right },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRInput_EOculusXRSide_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRInput,
	nullptr,
	"EOculusXRSide",
	"EOculusXRSide",
	Z_Construct_UEnum_OculusXRInput_EOculusXRSide_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRSide_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRSide_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRInput_EOculusXRSide_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRSide()
{
	if (!Z_Registration_Info_UEnum_EOculusXRSide.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRSide.InnerSingleton, Z_Construct_UEnum_OculusXRInput_EOculusXRSide_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRSide.InnerSingleton;
}
// End Enum EOculusXRSide

// Begin Enum EOculusXRTrackingConfidence
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRTrackingConfidence;
static UEnum* EOculusXRTrackingConfidence_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRTrackingConfidence.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRTrackingConfidence.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRInput_EOculusXRTrackingConfidence, (UObject*)Z_Construct_UPackage__Script_OculusXRInput(), TEXT("EOculusXRTrackingConfidence"));
	}
	return Z_Registration_Info_UEnum_EOculusXRTrackingConfidence.OuterSingleton;
}
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRTrackingConfidence>()
{
	return EOculusXRTrackingConfidence_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRInput_EOculusXRTrackingConfidence_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "High.Name", "EOculusXRTrackingConfidence::High" },
		{ "Low.Name", "EOculusXRTrackingConfidence::Low" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRTrackingConfidence::Low", (int64)EOculusXRTrackingConfidence::Low },
		{ "EOculusXRTrackingConfidence::High", (int64)EOculusXRTrackingConfidence::High },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRInput_EOculusXRTrackingConfidence_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRInput,
	nullptr,
	"EOculusXRTrackingConfidence",
	"EOculusXRTrackingConfidence",
	Z_Construct_UEnum_OculusXRInput_EOculusXRTrackingConfidence_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRTrackingConfidence_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRTrackingConfidence_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRInput_EOculusXRTrackingConfidence_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRTrackingConfidence()
{
	if (!Z_Registration_Info_UEnum_EOculusXRTrackingConfidence.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRTrackingConfidence.InnerSingleton, Z_Construct_UEnum_OculusXRInput_EOculusXRTrackingConfidence_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRTrackingConfidence.InnerSingleton;
}
// End Enum EOculusXRTrackingConfidence

// Begin Enum EOculusXRFinger
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRFinger;
static UEnum* EOculusXRFinger_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRFinger.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRFinger.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRInput_EOculusXRFinger, (UObject*)Z_Construct_UPackage__Script_OculusXRInput(), TEXT("EOculusXRFinger"));
	}
	return Z_Registration_Info_UEnum_EOculusXRFinger.OuterSingleton;
}
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRFinger>()
{
	return EOculusXRFinger_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRInput_EOculusXRFinger_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Index.Name", "EOculusXRFinger::Index" },
		{ "Invalid.Name", "EOculusXRFinger::Invalid" },
		{ "Middle.Name", "EOculusXRFinger::Middle" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
		{ "Pinky.Name", "EOculusXRFinger::Pinky" },
		{ "Ring.Name", "EOculusXRFinger::Ring" },
		{ "Thumb.Name", "EOculusXRFinger::Thumb" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRFinger::Thumb", (int64)EOculusXRFinger::Thumb },
		{ "EOculusXRFinger::Index", (int64)EOculusXRFinger::Index },
		{ "EOculusXRFinger::Middle", (int64)EOculusXRFinger::Middle },
		{ "EOculusXRFinger::Ring", (int64)EOculusXRFinger::Ring },
		{ "EOculusXRFinger::Pinky", (int64)EOculusXRFinger::Pinky },
		{ "EOculusXRFinger::Invalid", (int64)EOculusXRFinger::Invalid },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRInput_EOculusXRFinger_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRInput,
	nullptr,
	"EOculusXRFinger",
	"EOculusXRFinger",
	Z_Construct_UEnum_OculusXRInput_EOculusXRFinger_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRFinger_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRFinger_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRInput_EOculusXRFinger_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRFinger()
{
	if (!Z_Registration_Info_UEnum_EOculusXRFinger.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRFinger.InnerSingleton, Z_Construct_UEnum_OculusXRInput_EOculusXRFinger_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRFinger.InnerSingleton;
}
// End Enum EOculusXRFinger

// Begin Enum EOculusXRBone
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRBone;
static UEnum* EOculusXRBone_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRBone.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRBone.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRInput_EOculusXRBone, (UObject*)Z_Construct_UPackage__Script_OculusXRInput(), TEXT("EOculusXRBone"));
	}
	return Z_Registration_Info_UEnum_EOculusXRBone.OuterSingleton;
}
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRBone>()
{
	return EOculusXRBone_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRInput_EOculusXRBone_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Bone_Max.DisplayName", "Hand Max" },
		{ "Bone_Max.Name", "EOculusXRBone::Bone_Max" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * EOculusXRBone is enum representing the Bone Ids that come from the Oculus Runtime.\n */" },
#endif
		{ "Forearm_Stub.DisplayName", "Forearm Stub" },
		{ "Forearm_Stub.Name", "EOculusXRBone::Forearm_Stub" },
		{ "Hand_End.DisplayName", "Hand End" },
		{ "Hand_End.Name", "EOculusXRBone::Hand_End" },
		{ "Hand_Start.DisplayName", "Hand Start" },
		{ "Hand_Start.Name", "EOculusXRBone::Hand_Start" },
		{ "Index_1.DisplayName", "Index1" },
		{ "Index_1.Name", "EOculusXRBone::Index_1" },
		{ "Index_2.DisplayName", "Index2" },
		{ "Index_2.Name", "EOculusXRBone::Index_2" },
		{ "Index_3.DisplayName", "Index3" },
		{ "Index_3.Name", "EOculusXRBone::Index_3" },
		{ "Index_Tip.DisplayName", "Index Tip" },
		{ "Index_Tip.Name", "EOculusXRBone::Index_Tip" },
		{ "Invalid.DisplayName", "Invalid" },
		{ "Invalid.Name", "EOculusXRBone::Invalid" },
		{ "Max_Skinnable.DisplayName", "Max Skinnable" },
		{ "Max_Skinnable.Name", "EOculusXRBone::Max_Skinnable" },
		{ "Middle_1.DisplayName", "Middle1" },
		{ "Middle_1.Name", "EOculusXRBone::Middle_1" },
		{ "Middle_2.DisplayName", "Middle2" },
		{ "Middle_2.Name", "EOculusXRBone::Middle_2" },
		{ "Middle_3.DisplayName", "Middle3" },
		{ "Middle_3.Name", "EOculusXRBone::Middle_3" },
		{ "Middle_Tip.DisplayName", "Middle Tip" },
		{ "Middle_Tip.Name", "EOculusXRBone::Middle_Tip" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
		{ "Pinky_0.DisplayName", "Pinky0" },
		{ "Pinky_0.Name", "EOculusXRBone::Pinky_0" },
		{ "Pinky_1.DisplayName", "Pinky1" },
		{ "Pinky_1.Name", "EOculusXRBone::Pinky_1" },
		{ "Pinky_2.DisplayName", "Pinky2" },
		{ "Pinky_2.Name", "EOculusXRBone::Pinky_2" },
		{ "Pinky_3.DisplayName", "Pinky3" },
		{ "Pinky_3.Name", "EOculusXRBone::Pinky_3" },
		{ "Pinky_Tip.DisplayName", "Pinky Tip" },
		{ "Pinky_Tip.Name", "EOculusXRBone::Pinky_Tip" },
		{ "Ring_1.DisplayName", "Ring1" },
		{ "Ring_1.Name", "EOculusXRBone::Ring_1" },
		{ "Ring_2.DisplayName", "Ring2" },
		{ "Ring_2.Name", "EOculusXRBone::Ring_2" },
		{ "Ring_3.DisplayName", "Ring3" },
		{ "Ring_3.Name", "EOculusXRBone::Ring_3" },
		{ "Ring_Tip.DisplayName", "Ring Tip" },
		{ "Ring_Tip.Name", "EOculusXRBone::Ring_Tip" },
		{ "Thumb_0.DisplayName", "Thumb0" },
		{ "Thumb_0.Name", "EOculusXRBone::Thumb_0" },
		{ "Thumb_1.DisplayName", "Thumb1" },
		{ "Thumb_1.Name", "EOculusXRBone::Thumb_1" },
		{ "Thumb_2.DisplayName", "Thumb2" },
		{ "Thumb_2.Name", "EOculusXRBone::Thumb_2" },
		{ "Thumb_3.DisplayName", "Thumb3" },
		{ "Thumb_3.Name", "EOculusXRBone::Thumb_3" },
		{ "Thumb_Tip.DisplayName", "Thumb Tip" },
		{ "Thumb_Tip.Name", "EOculusXRBone::Thumb_Tip" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "EOculusXRBone is enum representing the Bone Ids that come from the Oculus Runtime." },
#endif
		{ "Wrist_Root.DisplayName", "Wrist Root" },
		{ "Wrist_Root.Name", "EOculusXRBone::Wrist_Root" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRBone::Wrist_Root", (int64)EOculusXRBone::Wrist_Root },
		{ "EOculusXRBone::Hand_Start", (int64)EOculusXRBone::Hand_Start },
		{ "EOculusXRBone::Forearm_Stub", (int64)EOculusXRBone::Forearm_Stub },
		{ "EOculusXRBone::Thumb_0", (int64)EOculusXRBone::Thumb_0 },
		{ "EOculusXRBone::Thumb_1", (int64)EOculusXRBone::Thumb_1 },
		{ "EOculusXRBone::Thumb_2", (int64)EOculusXRBone::Thumb_2 },
		{ "EOculusXRBone::Thumb_3", (int64)EOculusXRBone::Thumb_3 },
		{ "EOculusXRBone::Index_1", (int64)EOculusXRBone::Index_1 },
		{ "EOculusXRBone::Index_2", (int64)EOculusXRBone::Index_2 },
		{ "EOculusXRBone::Index_3", (int64)EOculusXRBone::Index_3 },
		{ "EOculusXRBone::Middle_1", (int64)EOculusXRBone::Middle_1 },
		{ "EOculusXRBone::Middle_2", (int64)EOculusXRBone::Middle_2 },
		{ "EOculusXRBone::Middle_3", (int64)EOculusXRBone::Middle_3 },
		{ "EOculusXRBone::Ring_1", (int64)EOculusXRBone::Ring_1 },
		{ "EOculusXRBone::Ring_2", (int64)EOculusXRBone::Ring_2 },
		{ "EOculusXRBone::Ring_3", (int64)EOculusXRBone::Ring_3 },
		{ "EOculusXRBone::Pinky_0", (int64)EOculusXRBone::Pinky_0 },
		{ "EOculusXRBone::Pinky_1", (int64)EOculusXRBone::Pinky_1 },
		{ "EOculusXRBone::Pinky_2", (int64)EOculusXRBone::Pinky_2 },
		{ "EOculusXRBone::Pinky_3", (int64)EOculusXRBone::Pinky_3 },
		{ "EOculusXRBone::Thumb_Tip", (int64)EOculusXRBone::Thumb_Tip },
		{ "EOculusXRBone::Max_Skinnable", (int64)EOculusXRBone::Max_Skinnable },
		{ "EOculusXRBone::Index_Tip", (int64)EOculusXRBone::Index_Tip },
		{ "EOculusXRBone::Middle_Tip", (int64)EOculusXRBone::Middle_Tip },
		{ "EOculusXRBone::Ring_Tip", (int64)EOculusXRBone::Ring_Tip },
		{ "EOculusXRBone::Pinky_Tip", (int64)EOculusXRBone::Pinky_Tip },
		{ "EOculusXRBone::Hand_End", (int64)EOculusXRBone::Hand_End },
		{ "EOculusXRBone::Bone_Max", (int64)EOculusXRBone::Bone_Max },
		{ "EOculusXRBone::Invalid", (int64)EOculusXRBone::Invalid },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRInput_EOculusXRBone_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRInput,
	nullptr,
	"EOculusXRBone",
	"EOculusXRBone",
	Z_Construct_UEnum_OculusXRInput_EOculusXRBone_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRBone_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRBone_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRInput_EOculusXRBone_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRBone()
{
	if (!Z_Registration_Info_UEnum_EOculusXRBone.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRBone.InnerSingleton, Z_Construct_UEnum_OculusXRInput_EOculusXRBone_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRBone.InnerSingleton;
}
// End Enum EOculusXRBone

// Begin Enum EOculusXRHandHapticsLocation
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRHandHapticsLocation;
static UEnum* EOculusXRHandHapticsLocation_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRHandHapticsLocation.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRHandHapticsLocation.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRInput_EOculusXRHandHapticsLocation, (UObject*)Z_Construct_UPackage__Script_OculusXRInput(), TEXT("EOculusXRHandHapticsLocation"));
	}
	return Z_Registration_Info_UEnum_EOculusXRHandHapticsLocation.OuterSingleton;
}
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRHandHapticsLocation>()
{
	return EOculusXRHandHapticsLocation_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRInput_EOculusXRHandHapticsLocation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Defines the haptics location of controller hands for tracking. */" },
#endif
		{ "Hand.Name", "EOculusXRHandHapticsLocation::Hand" },
		{ "HandHapticsLocation_Count.Comment", "// Haptics is applied to the index finger location\n" },
		{ "HandHapticsLocation_Count.DisplayName", "<INVALID>" },
		{ "HandHapticsLocation_Count.Hidden", "" },
		{ "HandHapticsLocation_Count.Name", "EOculusXRHandHapticsLocation::HandHapticsLocation_Count" },
		{ "HandHapticsLocation_Count.ToolTip", "Haptics is applied to the index finger location" },
		{ "Index.Comment", "// Haptics is applied to the thumb finger location\n" },
		{ "Index.Name", "EOculusXRHandHapticsLocation::Index" },
		{ "Index.ToolTip", "Haptics is applied to the thumb finger location" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
		{ "Thumb.Comment", "// Haptics is applied to the whole controller\n" },
		{ "Thumb.Name", "EOculusXRHandHapticsLocation::Thumb" },
		{ "Thumb.ToolTip", "Haptics is applied to the whole controller" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Defines the haptics location of controller hands for tracking." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRHandHapticsLocation::Hand", (int64)EOculusXRHandHapticsLocation::Hand },
		{ "EOculusXRHandHapticsLocation::Thumb", (int64)EOculusXRHandHapticsLocation::Thumb },
		{ "EOculusXRHandHapticsLocation::Index", (int64)EOculusXRHandHapticsLocation::Index },
		{ "EOculusXRHandHapticsLocation::HandHapticsLocation_Count", (int64)EOculusXRHandHapticsLocation::HandHapticsLocation_Count },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRInput_EOculusXRHandHapticsLocation_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRInput,
	nullptr,
	"EOculusXRHandHapticsLocation",
	"EOculusXRHandHapticsLocation",
	Z_Construct_UEnum_OculusXRInput_EOculusXRHandHapticsLocation_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRHandHapticsLocation_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRHandHapticsLocation_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRInput_EOculusXRHandHapticsLocation_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRHandHapticsLocation()
{
	if (!Z_Registration_Info_UEnum_EOculusXRHandHapticsLocation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRHandHapticsLocation.InnerSingleton, Z_Construct_UEnum_OculusXRInput_EOculusXRHandHapticsLocation_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRHandHapticsLocation.InnerSingleton;
}
// End Enum EOculusXRHandHapticsLocation

// Begin Enum EOculusXRControllerDrivenHandPoseTypes
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOculusXRControllerDrivenHandPoseTypes;
static UEnum* EOculusXRControllerDrivenHandPoseTypes_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOculusXRControllerDrivenHandPoseTypes.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOculusXRControllerDrivenHandPoseTypes.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OculusXRInput_EOculusXRControllerDrivenHandPoseTypes, (UObject*)Z_Construct_UPackage__Script_OculusXRInput(), TEXT("EOculusXRControllerDrivenHandPoseTypes"));
	}
	return Z_Registration_Info_UEnum_EOculusXRControllerDrivenHandPoseTypes.OuterSingleton;
}
template<> OCULUSXRINPUT_API UEnum* StaticEnum<EOculusXRControllerDrivenHandPoseTypes>()
{
	return EOculusXRControllerDrivenHandPoseTypes_StaticEnum();
}
struct Z_Construct_UEnum_OculusXRInput_EOculusXRControllerDrivenHandPoseTypes_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Define how a controllers button touches will be used to generate a hand pose. */" },
#endif
		{ "Controller.Comment", "// Controller button inputs will be used to generate a normal hand pose.\n" },
		{ "Controller.Name", "EOculusXRControllerDrivenHandPoseTypes::Controller" },
		{ "Controller.ToolTip", "Controller button inputs will be used to generate a normal hand pose." },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
		{ "Natural.Comment", "// Controllers do not generate any hand poses.\n" },
		{ "Natural.Name", "EOculusXRControllerDrivenHandPoseTypes::Natural" },
		{ "Natural.ToolTip", "Controllers do not generate any hand poses." },
		{ "None.Name", "EOculusXRControllerDrivenHandPoseTypes::None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Define how a controllers button touches will be used to generate a hand pose." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOculusXRControllerDrivenHandPoseTypes::None", (int64)EOculusXRControllerDrivenHandPoseTypes::None },
		{ "EOculusXRControllerDrivenHandPoseTypes::Natural", (int64)EOculusXRControllerDrivenHandPoseTypes::Natural },
		{ "EOculusXRControllerDrivenHandPoseTypes::Controller", (int64)EOculusXRControllerDrivenHandPoseTypes::Controller },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OculusXRInput_EOculusXRControllerDrivenHandPoseTypes_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_OculusXRInput,
	nullptr,
	"EOculusXRControllerDrivenHandPoseTypes",
	"EOculusXRControllerDrivenHandPoseTypes",
	Z_Construct_UEnum_OculusXRInput_EOculusXRControllerDrivenHandPoseTypes_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRControllerDrivenHandPoseTypes_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OculusXRInput_EOculusXRControllerDrivenHandPoseTypes_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OculusXRInput_EOculusXRControllerDrivenHandPoseTypes_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_OculusXRInput_EOculusXRControllerDrivenHandPoseTypes()
{
	if (!Z_Registration_Info_UEnum_EOculusXRControllerDrivenHandPoseTypes.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOculusXRControllerDrivenHandPoseTypes.InnerSingleton, Z_Construct_UEnum_OculusXRInput_EOculusXRControllerDrivenHandPoseTypes_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOculusXRControllerDrivenHandPoseTypes.InnerSingleton;
}
// End Enum EOculusXRControllerDrivenHandPoseTypes

// Begin ScriptStruct FOculusXRCapsuleCollider
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_OculusXRCapsuleCollider;
class UScriptStruct* FOculusXRCapsuleCollider::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRCapsuleCollider.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_OculusXRCapsuleCollider.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOculusXRCapsuleCollider, (UObject*)Z_Construct_UPackage__Script_OculusXRInput(), TEXT("OculusXRCapsuleCollider"));
	}
	return Z_Registration_Info_UScriptStruct_OculusXRCapsuleCollider.OuterSingleton;
}
template<> OCULUSXRINPUT_API UScriptStruct* StaticStruct<FOculusXRCapsuleCollider>()
{
	return FOculusXRCapsuleCollider::StaticStruct();
}
struct Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * FOculusXRCapsuleCollider is a struct that contains information on the physics/collider capsules created by the runtime for hands.\n *\n * @var Capsule\x09\x09The UCapsuleComponent that is the collision capsule on the bone. Use this to register for overlap/collision events\n * @var BoneIndex\x09The Bone that this collision capsule is parented to. Corresponds to the EOculusXRBone enum.\n *\n */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FOculusXRCapsuleCollider is a struct that contains information on the physics/collider capsules created by the runtime for hands.\n\n@var Capsule                The UCapsuleComponent that is the collision capsule on the bone. Use this to register for overlap/collision events\n@var BoneIndex      The Bone that this collision capsule is parented to. Corresponds to the EOculusXRBone enum." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Capsule_MetaData[] = {
		{ "Category", "OculusLibrary|HandTracking" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneId_MetaData[] = {
		{ "Category", "OculusLibrary|HandTracking" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Capsule;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BoneId_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BoneId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOculusXRCapsuleCollider>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::NewProp_Capsule = { "Capsule", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRCapsuleCollider, Capsule), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Capsule_MetaData), NewProp_Capsule_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::NewProp_BoneId_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::NewProp_BoneId = { "BoneId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOculusXRCapsuleCollider, BoneId), Z_Construct_UEnum_OculusXRInput_EOculusXRBone, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneId_MetaData), NewProp_BoneId_MetaData) }; // 2961258405
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::NewProp_Capsule,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::NewProp_BoneId_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::NewProp_BoneId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRInput,
	nullptr,
	&NewStructOps,
	"OculusXRCapsuleCollider",
	Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::PropPointers),
	sizeof(FOculusXRCapsuleCollider),
	alignof(FOculusXRCapsuleCollider),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000205),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOculusXRCapsuleCollider()
{
	if (!Z_Registration_Info_UScriptStruct_OculusXRCapsuleCollider.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_OculusXRCapsuleCollider.InnerSingleton, Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_OculusXRCapsuleCollider.InnerSingleton;
}
// End ScriptStruct FOculusXRCapsuleCollider

// Begin Class UOculusXRInputFunctionLibrary Function ConvertBoneToFinger
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics
{
	struct OculusXRInputFunctionLibrary_eventConvertBoneToFinger_Parms
	{
		EOculusXRBone Bone;
		EOculusXRFinger ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|HandTracking" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bone_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Bone_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Bone;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::NewProp_Bone_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::NewProp_Bone = { "Bone", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventConvertBoneToFinger_Parms, Bone), Z_Construct_UEnum_OculusXRInput_EOculusXRBone, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bone_MetaData), NewProp_Bone_MetaData) }; // 2961258405
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventConvertBoneToFinger_Parms, ReturnValue), Z_Construct_UEnum_OculusXRInput_EOculusXRFinger, METADATA_PARAMS(0, nullptr) }; // 577514988
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::NewProp_Bone_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::NewProp_Bone,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "ConvertBoneToFinger", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::OculusXRInputFunctionLibrary_eventConvertBoneToFinger_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::OculusXRInputFunctionLibrary_eventConvertBoneToFinger_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execConvertBoneToFinger)
{
	P_GET_ENUM(EOculusXRBone,Z_Param_Bone);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EOculusXRFinger*)Z_Param__Result=UOculusXRInputFunctionLibrary::ConvertBoneToFinger(EOculusXRBone(Z_Param_Bone));
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function ConvertBoneToFinger

// Begin Class UOculusXRInputFunctionLibrary Function GetBoneName
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics
{
	struct OculusXRInputFunctionLibrary_eventGetBoneName_Parms
	{
		EOculusXRBone BoneId;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|HandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the bone name from the bone index\n\x09 *\n\x09 * @param BoneIndex\x09\x09\x09\x09\x09(in) Bone index to get the name of\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the bone name from the bone index\n\n@param BoneIndex                                     (in) Bone index to get the name of" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_BoneId_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BoneId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::NewProp_BoneId_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::NewProp_BoneId = { "BoneId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetBoneName_Parms, BoneId), Z_Construct_UEnum_OculusXRInput_EOculusXRBone, METADATA_PARAMS(0, nullptr) }; // 2961258405
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetBoneName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::NewProp_BoneId_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::NewProp_BoneId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "GetBoneName", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::OculusXRInputFunctionLibrary_eventGetBoneName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::OculusXRInputFunctionLibrary_eventGetBoneName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execGetBoneName)
{
	P_GET_ENUM(EOculusXRBone,Z_Param_BoneId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UOculusXRInputFunctionLibrary::GetBoneName(EOculusXRBone(Z_Param_BoneId));
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function GetBoneName

// Begin Class UOculusXRInputFunctionLibrary Function GetBoneRotation
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics
{
	struct OculusXRInputFunctionLibrary_eventGetBoneRotation_Parms
	{
		EOculusXRHandType DeviceHand;
		EOculusXRBone BoneId;
		int32 ControllerIndex;
		FQuat ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|HandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the rotation of a specific bone\n\x09 *\n\x09 * @param DeviceHand\x09\x09\x09\x09(in) The hand to get the rotations from\n\x09 * @param BoneId\x09\x09\x09\x09\x09(in) The specific bone to get the rotation from\n\x09 * @param ControllerIndex\x09\x09\x09(in) Optional different controller index\n\x09 */" },
#endif
		{ "CPP_Default_ControllerIndex", "0" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the rotation of a specific bone\n\n@param DeviceHand                            (in) The hand to get the rotations from\n@param BoneId                                        (in) The specific bone to get the rotation from\n@param ControllerIndex                       (in) Optional different controller index" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoneId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControllerIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BoneId_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BoneId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ControllerIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetBoneRotation_Parms, DeviceHand), Z_Construct_UEnum_OculusXRInput_EOculusXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceHand_MetaData), NewProp_DeviceHand_MetaData) }; // 1666178145
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_BoneId_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_BoneId = { "BoneId", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetBoneRotation_Parms, BoneId), Z_Construct_UEnum_OculusXRInput_EOculusXRBone, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoneId_MetaData), NewProp_BoneId_MetaData) }; // 2961258405
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_ControllerIndex = { "ControllerIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetBoneRotation_Parms, ControllerIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControllerIndex_MetaData), NewProp_ControllerIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetBoneRotation_Parms, ReturnValue), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_DeviceHand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_DeviceHand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_BoneId_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_BoneId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_ControllerIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "GetBoneRotation", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::OculusXRInputFunctionLibrary_eventGetBoneRotation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::OculusXRInputFunctionLibrary_eventGetBoneRotation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execGetBoneRotation)
{
	P_GET_ENUM(EOculusXRHandType,Z_Param_DeviceHand);
	P_GET_ENUM(EOculusXRBone,Z_Param_BoneId);
	P_GET_PROPERTY(FIntProperty,Z_Param_ControllerIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FQuat*)Z_Param__Result=UOculusXRInputFunctionLibrary::GetBoneRotation(EOculusXRHandType(Z_Param_DeviceHand),EOculusXRBone(Z_Param_BoneId),Z_Param_ControllerIndex);
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function GetBoneRotation

// Begin Class UOculusXRInputFunctionLibrary Function GetControllerDrivenHandPoses
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics
{
	struct OculusXRInputFunctionLibrary_eventGetControllerDrivenHandPoses_Parms
	{
		EOculusXRControllerDrivenHandPoseTypes ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Controller" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get if / how controller inputs are used to build a syntheic hand pose.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get if / how controller inputs are used to build a syntheic hand pose." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetControllerDrivenHandPoses_Parms, ReturnValue), Z_Construct_UEnum_OculusXRInput_EOculusXRControllerDrivenHandPoseTypes, METADATA_PARAMS(0, nullptr) }; // 2462570112
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "GetControllerDrivenHandPoses", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics::OculusXRInputFunctionLibrary_eventGetControllerDrivenHandPoses_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics::OculusXRInputFunctionLibrary_eventGetControllerDrivenHandPoses_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execGetControllerDrivenHandPoses)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EOculusXRControllerDrivenHandPoseTypes*)Z_Param__Result=UOculusXRInputFunctionLibrary::GetControllerDrivenHandPoses();
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function GetControllerDrivenHandPoses

// Begin Class UOculusXRInputFunctionLibrary Function GetControllerSampleRateHz
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics
{
	struct OculusXRInputFunctionLibrary_eventGetControllerSampleRateHz_Parms
	{
		EControllerHand Hand;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Controller" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the controller haptics sample rate.\n\x09 * @param\x09Hand\x09\x09\x09\x09\x09Which hand to play the effect on\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the controller haptics sample rate.\n@param       Hand                                    Which hand to play the effect on" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Hand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Hand;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::NewProp_Hand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::NewProp_Hand = { "Hand", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetControllerSampleRateHz_Parms, Hand), Z_Construct_UEnum_InputCore_EControllerHand, METADATA_PARAMS(0, nullptr) }; // 775183092
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetControllerSampleRateHz_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::NewProp_Hand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::NewProp_Hand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "GetControllerSampleRateHz", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::OculusXRInputFunctionLibrary_eventGetControllerSampleRateHz_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::OculusXRInputFunctionLibrary_eventGetControllerSampleRateHz_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execGetControllerSampleRateHz)
{
	P_GET_ENUM(EControllerHand,Z_Param_Hand);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UOculusXRInputFunctionLibrary::GetControllerSampleRateHz(EControllerHand(Z_Param_Hand));
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function GetControllerSampleRateHz

// Begin Class UOculusXRInputFunctionLibrary Function GetDominantHand
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics
{
	struct OculusXRInputFunctionLibrary_eventGetDominantHand_Parms
	{
		int32 ControllerIndex;
		EOculusXRHandType ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|HandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the user's dominant hand\n\x09 *\n\x09 * @param ControllerIndex\x09\x09\x09(in) Optional different controller index\n\x09 */" },
#endif
		{ "CPP_Default_ControllerIndex", "0" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the user's dominant hand\n\n@param ControllerIndex                       (in) Optional different controller index" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControllerIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ControllerIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::NewProp_ControllerIndex = { "ControllerIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetDominantHand_Parms, ControllerIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControllerIndex_MetaData), NewProp_ControllerIndex_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetDominantHand_Parms, ReturnValue), Z_Construct_UEnum_OculusXRInput_EOculusXRHandType, METADATA_PARAMS(0, nullptr) }; // 1666178145
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::NewProp_ControllerIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "GetDominantHand", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::OculusXRInputFunctionLibrary_eventGetDominantHand_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::OculusXRInputFunctionLibrary_eventGetDominantHand_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execGetDominantHand)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ControllerIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EOculusXRHandType*)Z_Param__Result=UOculusXRInputFunctionLibrary::GetDominantHand(Z_Param_ControllerIndex);
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function GetDominantHand

// Begin Class UOculusXRInputFunctionLibrary Function GetFingerTrackingConfidence
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics
{
	struct OculusXRInputFunctionLibrary_eventGetFingerTrackingConfidence_Parms
	{
		EOculusXRHandType DeviceHand;
		EOculusXRFinger Finger;
		int32 ControllerIndex;
		EOculusXRTrackingConfidence ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|HandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the tracking confidence of a finger\n\x09 *\n\x09 * @param DeviceHand\x09\x09\x09\x09(in) The hand to get tracking confidence of\n\x09 * @param ControllerIndex\x09\x09\x09(in) Optional different controller index\n\x09 * @param Finger\x09\x09\x09(in) The finger to get tracking confidence of\n\x09 */" },
#endif
		{ "CPP_Default_ControllerIndex", "0" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the tracking confidence of a finger\n\n@param DeviceHand                            (in) The hand to get tracking confidence of\n@param ControllerIndex                       (in) Optional different controller index\n@param Finger                        (in) The finger to get tracking confidence of" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Finger_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControllerIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Finger_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Finger;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ControllerIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetFingerTrackingConfidence_Parms, DeviceHand), Z_Construct_UEnum_OculusXRInput_EOculusXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceHand_MetaData), NewProp_DeviceHand_MetaData) }; // 1666178145
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::NewProp_Finger_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::NewProp_Finger = { "Finger", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetFingerTrackingConfidence_Parms, Finger), Z_Construct_UEnum_OculusXRInput_EOculusXRFinger, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Finger_MetaData), NewProp_Finger_MetaData) }; // 577514988
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::NewProp_ControllerIndex = { "ControllerIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetFingerTrackingConfidence_Parms, ControllerIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControllerIndex_MetaData), NewProp_ControllerIndex_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetFingerTrackingConfidence_Parms, ReturnValue), Z_Construct_UEnum_OculusXRInput_EOculusXRTrackingConfidence, METADATA_PARAMS(0, nullptr) }; // 2813100711
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::NewProp_DeviceHand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::NewProp_DeviceHand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::NewProp_Finger_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::NewProp_Finger,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::NewProp_ControllerIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "GetFingerTrackingConfidence", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::OculusXRInputFunctionLibrary_eventGetFingerTrackingConfidence_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::OculusXRInputFunctionLibrary_eventGetFingerTrackingConfidence_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execGetFingerTrackingConfidence)
{
	P_GET_ENUM(EOculusXRHandType,Z_Param_DeviceHand);
	P_GET_ENUM(EOculusXRFinger,Z_Param_Finger);
	P_GET_PROPERTY(FIntProperty,Z_Param_ControllerIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EOculusXRTrackingConfidence*)Z_Param__Result=UOculusXRInputFunctionLibrary::GetFingerTrackingConfidence(EOculusXRHandType(Z_Param_DeviceHand),EOculusXRFinger(Z_Param_Finger),Z_Param_ControllerIndex);
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function GetFingerTrackingConfidence

// Begin Class UOculusXRInputFunctionLibrary Function GetHandScale
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics
{
	struct OculusXRInputFunctionLibrary_eventGetHandScale_Parms
	{
		EOculusXRHandType DeviceHand;
		int32 ControllerIndex;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|HandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the scale of the hand\n\x09 *\n\x09 * @param DeviceHand\x09\x09\x09\x09(in) The hand to get scale of\n\x09 * @param ControllerIndex\x09\x09\x09(in) Optional different controller index\n\x09 */" },
#endif
		{ "CPP_Default_ControllerIndex", "0" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the scale of the hand\n\n@param DeviceHand                            (in) The hand to get scale of\n@param ControllerIndex                       (in) Optional different controller index" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControllerIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ControllerIndex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetHandScale_Parms, DeviceHand), Z_Construct_UEnum_OculusXRInput_EOculusXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceHand_MetaData), NewProp_DeviceHand_MetaData) }; // 1666178145
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::NewProp_ControllerIndex = { "ControllerIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetHandScale_Parms, ControllerIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControllerIndex_MetaData), NewProp_ControllerIndex_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetHandScale_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::NewProp_DeviceHand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::NewProp_DeviceHand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::NewProp_ControllerIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "GetHandScale", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::OculusXRInputFunctionLibrary_eventGetHandScale_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::OculusXRInputFunctionLibrary_eventGetHandScale_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execGetHandScale)
{
	P_GET_ENUM(EOculusXRHandType,Z_Param_DeviceHand);
	P_GET_PROPERTY(FIntProperty,Z_Param_ControllerIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UOculusXRInputFunctionLibrary::GetHandScale(EOculusXRHandType(Z_Param_DeviceHand),Z_Param_ControllerIndex);
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function GetHandScale

// Begin Class UOculusXRInputFunctionLibrary Function GetHandSkeletalMesh
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics
{
	struct OculusXRInputFunctionLibrary_eventGetHandSkeletalMesh_Parms
	{
		USkeletalMesh* HandSkeletalMesh;
		EOculusXRHandType SkeletonType;
		EOculusXRHandType MeshType;
		float WorldToMeters;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|HandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Creates a new runtime hand skeletal mesh.\n\x09 *\n\x09 * @param HandSkeletalMesh\x09\x09\x09(out) Skeletal Mesh object that will be used for the runtime hand mesh\n\x09 * @param SkeletonType\x09\x09\x09\x09(in) The skeleton type that will be used for generating the hand bones\n\x09 * @param MeshType\x09\x09\x09\x09\x09(in) The mesh type that will be used for generating the hand mesh\n\x09 * @param WorldTometers\x09\x09\x09\x09(in) Optional change to the world to meters conversion value\n\x09 */" },
#endif
		{ "CPP_Default_WorldToMeters", "100.000000" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Creates a new runtime hand skeletal mesh.\n\n@param HandSkeletalMesh                      (out) Skeletal Mesh object that will be used for the runtime hand mesh\n@param SkeletonType                          (in) The skeleton type that will be used for generating the hand bones\n@param MeshType                                      (in) The mesh type that will be used for generating the hand mesh\n@param WorldTometers                         (in) Optional change to the world to meters conversion value" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldToMeters_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HandSkeletalMesh;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SkeletonType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SkeletonType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_MeshType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_MeshType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WorldToMeters;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_HandSkeletalMesh = { "HandSkeletalMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetHandSkeletalMesh_Parms, HandSkeletalMesh), Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_SkeletonType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_SkeletonType = { "SkeletonType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetHandSkeletalMesh_Parms, SkeletonType), Z_Construct_UEnum_OculusXRInput_EOculusXRHandType, METADATA_PARAMS(0, nullptr) }; // 1666178145
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_MeshType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_MeshType = { "MeshType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetHandSkeletalMesh_Parms, MeshType), Z_Construct_UEnum_OculusXRInput_EOculusXRHandType, METADATA_PARAMS(0, nullptr) }; // 1666178145
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_WorldToMeters = { "WorldToMeters", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetHandSkeletalMesh_Parms, WorldToMeters), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldToMeters_MetaData), NewProp_WorldToMeters_MetaData) };
void Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRInputFunctionLibrary_eventGetHandSkeletalMesh_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRInputFunctionLibrary_eventGetHandSkeletalMesh_Parms), &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_HandSkeletalMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_SkeletonType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_SkeletonType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_MeshType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_MeshType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_WorldToMeters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "GetHandSkeletalMesh", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::OculusXRInputFunctionLibrary_eventGetHandSkeletalMesh_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::OculusXRInputFunctionLibrary_eventGetHandSkeletalMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execGetHandSkeletalMesh)
{
	P_GET_OBJECT(USkeletalMesh,Z_Param_HandSkeletalMesh);
	P_GET_ENUM(EOculusXRHandType,Z_Param_SkeletonType);
	P_GET_ENUM(EOculusXRHandType,Z_Param_MeshType);
	P_GET_PROPERTY(FFloatProperty,Z_Param_WorldToMeters);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRInputFunctionLibrary::GetHandSkeletalMesh(Z_Param_HandSkeletalMesh,EOculusXRHandType(Z_Param_SkeletonType),EOculusXRHandType(Z_Param_MeshType),Z_Param_WorldToMeters);
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function GetHandSkeletalMesh

// Begin Class UOculusXRInputFunctionLibrary Function GetMaxHapticDuration
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics
{
	struct OculusXRInputFunctionLibrary_eventGetMaxHapticDuration_Parms
	{
		EControllerHand Hand;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Controller" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the maximum duration (in seconds) that the controller haptics can handle each time.\n\x09 * @param\x09Hand\x09\x09\x09\x09\x09Which hand to play the effect on\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the maximum duration (in seconds) that the controller haptics can handle each time.\n@param       Hand                                    Which hand to play the effect on" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Hand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Hand;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::NewProp_Hand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::NewProp_Hand = { "Hand", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetMaxHapticDuration_Parms, Hand), Z_Construct_UEnum_InputCore_EControllerHand, METADATA_PARAMS(0, nullptr) }; // 775183092
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetMaxHapticDuration_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::NewProp_Hand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::NewProp_Hand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "GetMaxHapticDuration", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::OculusXRInputFunctionLibrary_eventGetMaxHapticDuration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::OculusXRInputFunctionLibrary_eventGetMaxHapticDuration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execGetMaxHapticDuration)
{
	P_GET_ENUM(EControllerHand,Z_Param_Hand);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UOculusXRInputFunctionLibrary::GetMaxHapticDuration(EControllerHand(Z_Param_Hand));
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function GetMaxHapticDuration

// Begin Class UOculusXRInputFunctionLibrary Function GetPointerPose
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics
{
	struct OculusXRInputFunctionLibrary_eventGetPointerPose_Parms
	{
		EOculusXRHandType DeviceHand;
		int32 ControllerIndex;
		FTransform ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|HandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the pointer pose\n\x09 *\n\x09 * @param DeviceHand\x09\x09\x09\x09(in) The hand to get the pointer pose from\n\x09 * @param ControllerIndex\x09\x09\x09(in) Optional different controller index\n\x09 */" },
#endif
		{ "CPP_Default_ControllerIndex", "0" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the pointer pose\n\n@param DeviceHand                            (in) The hand to get the pointer pose from\n@param ControllerIndex                       (in) Optional different controller index" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControllerIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ControllerIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetPointerPose_Parms, DeviceHand), Z_Construct_UEnum_OculusXRInput_EOculusXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceHand_MetaData), NewProp_DeviceHand_MetaData) }; // 1666178145
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::NewProp_ControllerIndex = { "ControllerIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetPointerPose_Parms, ControllerIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControllerIndex_MetaData), NewProp_ControllerIndex_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetPointerPose_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::NewProp_DeviceHand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::NewProp_DeviceHand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::NewProp_ControllerIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "GetPointerPose", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::OculusXRInputFunctionLibrary_eventGetPointerPose_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::OculusXRInputFunctionLibrary_eventGetPointerPose_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execGetPointerPose)
{
	P_GET_ENUM(EOculusXRHandType,Z_Param_DeviceHand);
	P_GET_PROPERTY(FIntProperty,Z_Param_ControllerIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTransform*)Z_Param__Result=UOculusXRInputFunctionLibrary::GetPointerPose(EOculusXRHandType(Z_Param_DeviceHand),Z_Param_ControllerIndex);
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function GetPointerPose

// Begin Class UOculusXRInputFunctionLibrary Function GetTrackingConfidence
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics
{
	struct OculusXRInputFunctionLibrary_eventGetTrackingConfidence_Parms
	{
		EOculusXRHandType DeviceHand;
		int32 ControllerIndex;
		EOculusXRTrackingConfidence ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|HandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the tracking confidence of the hand\n\x09 *\n\x09 * @param DeviceHand\x09\x09\x09\x09(in) The hand to get tracking confidence of\n\x09 * @param ControllerIndex\x09\x09\x09(in) Optional different controller index\n\x09 */" },
#endif
		{ "CPP_Default_ControllerIndex", "0" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the tracking confidence of the hand\n\n@param DeviceHand                            (in) The hand to get tracking confidence of\n@param ControllerIndex                       (in) Optional different controller index" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControllerIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ControllerIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetTrackingConfidence_Parms, DeviceHand), Z_Construct_UEnum_OculusXRInput_EOculusXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceHand_MetaData), NewProp_DeviceHand_MetaData) }; // 1666178145
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_ControllerIndex = { "ControllerIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetTrackingConfidence_Parms, ControllerIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControllerIndex_MetaData), NewProp_ControllerIndex_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventGetTrackingConfidence_Parms, ReturnValue), Z_Construct_UEnum_OculusXRInput_EOculusXRTrackingConfidence, METADATA_PARAMS(0, nullptr) }; // 2813100711
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_DeviceHand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_DeviceHand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_ControllerIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "GetTrackingConfidence", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::OculusXRInputFunctionLibrary_eventGetTrackingConfidence_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::OculusXRInputFunctionLibrary_eventGetTrackingConfidence_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execGetTrackingConfidence)
{
	P_GET_ENUM(EOculusXRHandType,Z_Param_DeviceHand);
	P_GET_PROPERTY(FIntProperty,Z_Param_ControllerIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EOculusXRTrackingConfidence*)Z_Param__Result=UOculusXRInputFunctionLibrary::GetTrackingConfidence(EOculusXRHandType(Z_Param_DeviceHand),Z_Param_ControllerIndex);
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function GetTrackingConfidence

// Begin Class UOculusXRInputFunctionLibrary Function InitializeHandPhysics
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics
{
	struct OculusXRInputFunctionLibrary_eventInitializeHandPhysics_Parms
	{
		EOculusXRHandType SkeletonType;
		USkinnedMeshComponent* HandComponent;
		float WorldToMeters;
		TArray<FOculusXRCapsuleCollider> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|HandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initializes physics capsules for collision and physics on the runtime mesh\n\x09 *\n\x09 * @param SkeletonType\x09\x09\x09\x09(in) The skeleton type that will be used to generated the capsules\n\x09 * @param HandComponent\x09\x09\x09\x09(in) The skinned mesh component that the capsules will be attached to\n\x09 * @param WorldTometers\x09\x09\x09\x09(in) Optional change to the world to meters conversion value\n\x09 */" },
#endif
		{ "CPP_Default_WorldToMeters", "100.000000" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initializes physics capsules for collision and physics on the runtime mesh\n\n@param SkeletonType                          (in) The skeleton type that will be used to generated the capsules\n@param HandComponent                         (in) The skinned mesh component that the capsules will be attached to\n@param WorldTometers                         (in) Optional change to the world to meters conversion value" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HandComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldToMeters_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SkeletonType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SkeletonType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HandComponent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WorldToMeters;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::NewProp_SkeletonType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::NewProp_SkeletonType = { "SkeletonType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventInitializeHandPhysics_Parms, SkeletonType), Z_Construct_UEnum_OculusXRInput_EOculusXRHandType, METADATA_PARAMS(0, nullptr) }; // 1666178145
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::NewProp_HandComponent = { "HandComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventInitializeHandPhysics_Parms, HandComponent), Z_Construct_UClass_USkinnedMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HandComponent_MetaData), NewProp_HandComponent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::NewProp_WorldToMeters = { "WorldToMeters", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventInitializeHandPhysics_Parms, WorldToMeters), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldToMeters_MetaData), NewProp_WorldToMeters_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FOculusXRCapsuleCollider, METADATA_PARAMS(0, nullptr) }; // 195539744
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventInitializeHandPhysics_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 195539744
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::NewProp_SkeletonType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::NewProp_SkeletonType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::NewProp_HandComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::NewProp_WorldToMeters,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "InitializeHandPhysics", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::OculusXRInputFunctionLibrary_eventInitializeHandPhysics_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::OculusXRInputFunctionLibrary_eventInitializeHandPhysics_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execInitializeHandPhysics)
{
	P_GET_ENUM(EOculusXRHandType,Z_Param_SkeletonType);
	P_GET_OBJECT(USkinnedMeshComponent,Z_Param_HandComponent);
	P_GET_PROPERTY(FFloatProperty,Z_Param_WorldToMeters);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FOculusXRCapsuleCollider>*)Z_Param__Result=UOculusXRInputFunctionLibrary::InitializeHandPhysics(EOculusXRHandType(Z_Param_SkeletonType),Z_Param_HandComponent,Z_Param_WorldToMeters);
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function InitializeHandPhysics

// Begin Class UOculusXRInputFunctionLibrary Function IsHandPositionValid
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics
{
	struct OculusXRInputFunctionLibrary_eventIsHandPositionValid_Parms
	{
		EOculusXRHandType DeviceHand;
		int32 ControllerIndex;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|HandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if the hand position is valid\n\x09 *\n\x09 * @param DeviceHand\x09\x09\x09\x09(in) The hand to get the position from\n\x09 * @param ControllerIndex\x09\x09\x09(in) Optional different controller index\n\x09 */" },
#endif
		{ "CPP_Default_ControllerIndex", "0" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if the hand position is valid\n\n@param DeviceHand                            (in) The hand to get the position from\n@param ControllerIndex                       (in) Optional different controller index" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControllerIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ControllerIndex;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventIsHandPositionValid_Parms, DeviceHand), Z_Construct_UEnum_OculusXRInput_EOculusXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceHand_MetaData), NewProp_DeviceHand_MetaData) }; // 1666178145
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::NewProp_ControllerIndex = { "ControllerIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventIsHandPositionValid_Parms, ControllerIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControllerIndex_MetaData), NewProp_ControllerIndex_MetaData) };
void Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRInputFunctionLibrary_eventIsHandPositionValid_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRInputFunctionLibrary_eventIsHandPositionValid_Parms), &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::NewProp_DeviceHand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::NewProp_DeviceHand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::NewProp_ControllerIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "IsHandPositionValid", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::OculusXRInputFunctionLibrary_eventIsHandPositionValid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::OculusXRInputFunctionLibrary_eventIsHandPositionValid_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execIsHandPositionValid)
{
	P_GET_ENUM(EOculusXRHandType,Z_Param_DeviceHand);
	P_GET_PROPERTY(FIntProperty,Z_Param_ControllerIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRInputFunctionLibrary::IsHandPositionValid(EOculusXRHandType(Z_Param_DeviceHand),Z_Param_ControllerIndex);
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function IsHandPositionValid

// Begin Class UOculusXRInputFunctionLibrary Function IsHandTrackingEnabled
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics
{
	struct OculusXRInputFunctionLibrary_eventIsHandTrackingEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|HandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if hand tracking is enabled currently\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if hand tracking is enabled currently" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRInputFunctionLibrary_eventIsHandTrackingEnabled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRInputFunctionLibrary_eventIsHandTrackingEnabled_Parms), &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "IsHandTrackingEnabled", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::OculusXRInputFunctionLibrary_eventIsHandTrackingEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::OculusXRInputFunctionLibrary_eventIsHandTrackingEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execIsHandTrackingEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRInputFunctionLibrary::IsHandTrackingEnabled();
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function IsHandTrackingEnabled

// Begin Class UOculusXRInputFunctionLibrary Function IsPointerPoseValid
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics
{
	struct OculusXRInputFunctionLibrary_eventIsPointerPoseValid_Parms
	{
		EOculusXRHandType DeviceHand;
		int32 ControllerIndex;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|HandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if the pointer pose is a valid pose\n\x09 *\n\x09 * @param DeviceHand\x09\x09\x09\x09(in) The hand to get the pointer status from\n\x09 * @param ControllerIndex\x09\x09\x09(in) Optional different controller index\n\x09 */" },
#endif
		{ "CPP_Default_ControllerIndex", "0" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if the pointer pose is a valid pose\n\n@param DeviceHand                            (in) The hand to get the pointer status from\n@param ControllerIndex                       (in) Optional different controller index" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControllerIndex_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ControllerIndex;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventIsPointerPoseValid_Parms, DeviceHand), Z_Construct_UEnum_OculusXRInput_EOculusXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceHand_MetaData), NewProp_DeviceHand_MetaData) }; // 1666178145
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::NewProp_ControllerIndex = { "ControllerIndex", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventIsPointerPoseValid_Parms, ControllerIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControllerIndex_MetaData), NewProp_ControllerIndex_MetaData) };
void Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OculusXRInputFunctionLibrary_eventIsPointerPoseValid_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRInputFunctionLibrary_eventIsPointerPoseValid_Parms), &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::NewProp_DeviceHand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::NewProp_DeviceHand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::NewProp_ControllerIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "IsPointerPoseValid", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::OculusXRInputFunctionLibrary_eventIsPointerPoseValid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::OculusXRInputFunctionLibrary_eventIsPointerPoseValid_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execIsPointerPoseValid)
{
	P_GET_ENUM(EOculusXRHandType,Z_Param_DeviceHand);
	P_GET_PROPERTY(FIntProperty,Z_Param_ControllerIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UOculusXRInputFunctionLibrary::IsPointerPoseValid(EOculusXRHandType(Z_Param_DeviceHand),Z_Param_ControllerIndex);
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function IsPointerPoseValid

// Begin Class UOculusXRInputFunctionLibrary Function PlayAmplitudeEnvelopeHapticEffect
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics
{
	struct OculusXRInputFunctionLibrary_eventPlayAmplitudeEnvelopeHapticEffect_Parms
	{
		UHapticFeedbackEffect_Buffer* HapticEffect;
		EControllerHand Hand;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Controller" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Play a haptic feedback buffer on the player's controller.\n\x09 * All buffer data will be sent to controller together in one frame.\n\x09 * Data duration should be no greater than controller's maximum haptics duration which can be queried with GetMaxHapticDuration.\n\x09 * @param\x09HapticEffect\x09\x09\x09The haptic effect to play\n\x09 * @param\x09Hand\x09\x09\x09\x09\x09Which hand to play the effect on\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Play a haptic feedback buffer on the player's controller.\nAll buffer data will be sent to controller together in one frame.\nData duration should be no greater than controller's maximum haptics duration which can be queried with GetMaxHapticDuration.\n@param       HapticEffect                    The haptic effect to play\n@param       Hand                                    Which hand to play the effect on" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HapticEffect;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Hand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Hand;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::NewProp_HapticEffect = { "HapticEffect", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventPlayAmplitudeEnvelopeHapticEffect_Parms, HapticEffect), Z_Construct_UClass_UHapticFeedbackEffect_Buffer_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::NewProp_Hand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::NewProp_Hand = { "Hand", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventPlayAmplitudeEnvelopeHapticEffect_Parms, Hand), Z_Construct_UEnum_InputCore_EControllerHand, METADATA_PARAMS(0, nullptr) }; // 775183092
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::NewProp_HapticEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::NewProp_Hand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::NewProp_Hand,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "PlayAmplitudeEnvelopeHapticEffect", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::OculusXRInputFunctionLibrary_eventPlayAmplitudeEnvelopeHapticEffect_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::OculusXRInputFunctionLibrary_eventPlayAmplitudeEnvelopeHapticEffect_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execPlayAmplitudeEnvelopeHapticEffect)
{
	P_GET_OBJECT(UHapticFeedbackEffect_Buffer,Z_Param_HapticEffect);
	P_GET_ENUM(EControllerHand,Z_Param_Hand);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRInputFunctionLibrary::PlayAmplitudeEnvelopeHapticEffect(Z_Param_HapticEffect,EControllerHand(Z_Param_Hand));
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function PlayAmplitudeEnvelopeHapticEffect

// Begin Class UOculusXRInputFunctionLibrary Function PlayBufferHapticEffect
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics
{
	struct OculusXRInputFunctionLibrary_eventPlayBufferHapticEffect_Parms
	{
		UHapticFeedbackEffect_Buffer* HapticEffect;
		EControllerHand Hand;
		EOculusXRHandHapticsLocation Location;
		float Scale;
		bool bLoop;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Controller" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Play a haptic feedback buffer on the player's controller with location support.\n\x09 * In each frame, the buffer data will be sampled and the individual sampled data will be sent to controller to vibrate a specific location.\n\x09 * @param\x09HapticEffect\x09\x09\x09The haptic effect to play\n\x09 * @param\x09Hand\x09\x09\x09\x09\x09Which hand to play the effect on\n\x09 * @param\x09Location\x09\x09\x09\x09Which hand location to play the effect on\n\x09 * @param\x09Scale\x09\x09\x09\x09\x09Scale between 0.0 and 1.0 on the intensity of playback\n\x09 */" },
#endif
		{ "CPP_Default_bLoop", "false" },
		{ "CPP_Default_Location", "Hand" },
		{ "CPP_Default_Scale", "1.000000" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Play a haptic feedback buffer on the player's controller with location support.\nIn each frame, the buffer data will be sampled and the individual sampled data will be sent to controller to vibrate a specific location.\n@param       HapticEffect                    The haptic effect to play\n@param       Hand                                    Which hand to play the effect on\n@param       Location                                Which hand location to play the effect on\n@param       Scale                                   Scale between 0.0 and 1.0 on the intensity of playback" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HapticEffect;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Hand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Hand;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Location_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Location;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Scale;
	static void NewProp_bLoop_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLoop;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_HapticEffect = { "HapticEffect", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventPlayBufferHapticEffect_Parms, HapticEffect), Z_Construct_UClass_UHapticFeedbackEffect_Buffer_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_Hand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_Hand = { "Hand", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventPlayBufferHapticEffect_Parms, Hand), Z_Construct_UEnum_InputCore_EControllerHand, METADATA_PARAMS(0, nullptr) }; // 775183092
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_Location_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventPlayBufferHapticEffect_Parms, Location), Z_Construct_UEnum_OculusXRInput_EOculusXRHandHapticsLocation, METADATA_PARAMS(0, nullptr) }; // 761422410
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventPlayBufferHapticEffect_Parms, Scale), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_bLoop_SetBit(void* Obj)
{
	((OculusXRInputFunctionLibrary_eventPlayBufferHapticEffect_Parms*)Obj)->bLoop = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_bLoop = { "bLoop", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRInputFunctionLibrary_eventPlayBufferHapticEffect_Parms), &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_bLoop_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_HapticEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_Hand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_Hand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_Location_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::NewProp_bLoop,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "PlayBufferHapticEffect", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::OculusXRInputFunctionLibrary_eventPlayBufferHapticEffect_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::OculusXRInputFunctionLibrary_eventPlayBufferHapticEffect_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execPlayBufferHapticEffect)
{
	P_GET_OBJECT(UHapticFeedbackEffect_Buffer,Z_Param_HapticEffect);
	P_GET_ENUM(EControllerHand,Z_Param_Hand);
	P_GET_ENUM(EOculusXRHandHapticsLocation,Z_Param_Location);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Scale);
	P_GET_UBOOL(Z_Param_bLoop);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRInputFunctionLibrary::PlayBufferHapticEffect(Z_Param_HapticEffect,EControllerHand(Z_Param_Hand),EOculusXRHandHapticsLocation(Z_Param_Location),Z_Param_Scale,Z_Param_bLoop);
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function PlayBufferHapticEffect

// Begin Class UOculusXRInputFunctionLibrary Function PlayCurveHapticEffect
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics
{
	struct OculusXRInputFunctionLibrary_eventPlayCurveHapticEffect_Parms
	{
		UHapticFeedbackEffect_Curve* HapticEffect;
		EControllerHand Hand;
		EOculusXRHandHapticsLocation Location;
		float Scale;
		bool bLoop;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Controller" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Play a haptic feedback curve on the player's controller with location support.\n\x09 * The curve data will be sampled and sent to controller to vibrate a specific location at each frame.\n\x09 * @param\x09HapticEffect\x09\x09\x09The haptic effect to play\n\x09 * @param\x09Hand\x09\x09\x09\x09\x09Which hand to play the effect on\n\x09 * @param\x09Location\x09\x09\x09\x09Which hand location to play the effect on\n\x09 * @param\x09Scale\x09\x09\x09\x09\x09Scale between 0.0 and 1.0 on the intensity of playback\n\x09 */" },
#endif
		{ "CPP_Default_bLoop", "false" },
		{ "CPP_Default_Location", "Hand" },
		{ "CPP_Default_Scale", "1.000000" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Play a haptic feedback curve on the player's controller with location support.\nThe curve data will be sampled and sent to controller to vibrate a specific location at each frame.\n@param       HapticEffect                    The haptic effect to play\n@param       Hand                                    Which hand to play the effect on\n@param       Location                                Which hand location to play the effect on\n@param       Scale                                   Scale between 0.0 and 1.0 on the intensity of playback" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HapticEffect;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Hand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Hand;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Location_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Location;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Scale;
	static void NewProp_bLoop_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLoop;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_HapticEffect = { "HapticEffect", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventPlayCurveHapticEffect_Parms, HapticEffect), Z_Construct_UClass_UHapticFeedbackEffect_Curve_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_Hand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_Hand = { "Hand", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventPlayCurveHapticEffect_Parms, Hand), Z_Construct_UEnum_InputCore_EControllerHand, METADATA_PARAMS(0, nullptr) }; // 775183092
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_Location_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventPlayCurveHapticEffect_Parms, Location), Z_Construct_UEnum_OculusXRInput_EOculusXRHandHapticsLocation, METADATA_PARAMS(0, nullptr) }; // 761422410
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventPlayCurveHapticEffect_Parms, Scale), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_bLoop_SetBit(void* Obj)
{
	((OculusXRInputFunctionLibrary_eventPlayCurveHapticEffect_Parms*)Obj)->bLoop = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_bLoop = { "bLoop", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRInputFunctionLibrary_eventPlayCurveHapticEffect_Parms), &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_bLoop_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_HapticEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_Hand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_Hand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_Location_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_Location,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::NewProp_bLoop,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "PlayCurveHapticEffect", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::OculusXRInputFunctionLibrary_eventPlayCurveHapticEffect_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::OculusXRInputFunctionLibrary_eventPlayCurveHapticEffect_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execPlayCurveHapticEffect)
{
	P_GET_OBJECT(UHapticFeedbackEffect_Curve,Z_Param_HapticEffect);
	P_GET_ENUM(EControllerHand,Z_Param_Hand);
	P_GET_ENUM(EOculusXRHandHapticsLocation,Z_Param_Location);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Scale);
	P_GET_UBOOL(Z_Param_bLoop);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRInputFunctionLibrary::PlayCurveHapticEffect(Z_Param_HapticEffect,EControllerHand(Z_Param_Hand),EOculusXRHandHapticsLocation(Z_Param_Location),Z_Param_Scale,Z_Param_bLoop);
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function PlayCurveHapticEffect

// Begin Class UOculusXRInputFunctionLibrary Function PlaySoundWaveHapticEffect
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics
{
	struct OculusXRInputFunctionLibrary_eventPlaySoundWaveHapticEffect_Parms
	{
		UHapticFeedbackEffect_SoundWave* HapticEffect;
		EControllerHand Hand;
		bool bAppend;
		float Scale;
		bool bLoop;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Controller" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Play a haptic feedback soundwave on the player's controller.\n\x09 * In each frame, the soundwave data will be split into a batch of data and sent to controller.\n\x09 * The data duration of each frame is equal to controller's maximum haptics duration which can be queried with GetMaxHapticDuration.\n\x09 * @param\x09HapticEffect\x09\x09\x09The haptic effect to play\n\x09 * @param\x09Hand\x09\x09\x09\x09\x09Which hand to play the effect on\n\x09 * @param\x09""bAppend\x09\x09\x09\x09\x09""False: any existing samples will be cleared and a new haptic effect will begin; True: samples will be appended to the currently playing effect\n\x09 * @param\x09Scale\x09\x09\x09\x09\x09Scale between 0.0 and 1.0 on the intensity of playback\n\x09 */" },
#endif
		{ "CPP_Default_bAppend", "false" },
		{ "CPP_Default_bLoop", "false" },
		{ "CPP_Default_Scale", "1.000000" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Play a haptic feedback soundwave on the player's controller.\nIn each frame, the soundwave data will be split into a batch of data and sent to controller.\nThe data duration of each frame is equal to controller's maximum haptics duration which can be queried with GetMaxHapticDuration.\n@param       HapticEffect                    The haptic effect to play\n@param       Hand                                    Which hand to play the effect on\n@param       bAppend                                 False: any existing samples will be cleared and a new haptic effect will begin; True: samples will be appended to the currently playing effect\n@param       Scale                                   Scale between 0.0 and 1.0 on the intensity of playback" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HapticEffect;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Hand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Hand;
	static void NewProp_bAppend_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAppend;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Scale;
	static void NewProp_bLoop_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLoop;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_HapticEffect = { "HapticEffect", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventPlaySoundWaveHapticEffect_Parms, HapticEffect), Z_Construct_UClass_UHapticFeedbackEffect_SoundWave_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_Hand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_Hand = { "Hand", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventPlaySoundWaveHapticEffect_Parms, Hand), Z_Construct_UEnum_InputCore_EControllerHand, METADATA_PARAMS(0, nullptr) }; // 775183092
void Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_bAppend_SetBit(void* Obj)
{
	((OculusXRInputFunctionLibrary_eventPlaySoundWaveHapticEffect_Parms*)Obj)->bAppend = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_bAppend = { "bAppend", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRInputFunctionLibrary_eventPlaySoundWaveHapticEffect_Parms), &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_bAppend_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_Scale = { "Scale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventPlaySoundWaveHapticEffect_Parms, Scale), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_bLoop_SetBit(void* Obj)
{
	((OculusXRInputFunctionLibrary_eventPlaySoundWaveHapticEffect_Parms*)Obj)->bLoop = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_bLoop = { "bLoop", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OculusXRInputFunctionLibrary_eventPlaySoundWaveHapticEffect_Parms), &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_bLoop_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_HapticEffect,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_Hand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_Hand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_bAppend,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_Scale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::NewProp_bLoop,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "PlaySoundWaveHapticEffect", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::OculusXRInputFunctionLibrary_eventPlaySoundWaveHapticEffect_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::OculusXRInputFunctionLibrary_eventPlaySoundWaveHapticEffect_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execPlaySoundWaveHapticEffect)
{
	P_GET_OBJECT(UHapticFeedbackEffect_SoundWave,Z_Param_HapticEffect);
	P_GET_ENUM(EControllerHand,Z_Param_Hand);
	P_GET_UBOOL(Z_Param_bAppend);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Scale);
	P_GET_UBOOL(Z_Param_bLoop);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRInputFunctionLibrary::PlaySoundWaveHapticEffect(Z_Param_HapticEffect,EControllerHand(Z_Param_Hand),Z_Param_bAppend,Z_Param_Scale,Z_Param_bLoop);
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function PlaySoundWaveHapticEffect

// Begin Class UOculusXRInputFunctionLibrary Function SetControllerDrivenHandPoses
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics
{
	struct OculusXRInputFunctionLibrary_eventSetControllerDrivenHandPoses_Parms
	{
		EOculusXRControllerDrivenHandPoseTypes Type;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Controller" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set if / how controller inputs are used to build a syntheic hand pose.\n\x09 * @param\x09Type\x09\x09\x09\x09\x09How the hand should be posed.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set if / how controller inputs are used to build a syntheic hand pose.\n@param       Type                                    How the hand should be posed." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventSetControllerDrivenHandPoses_Parms, Type), Z_Construct_UEnum_OculusXRInput_EOculusXRControllerDrivenHandPoseTypes, METADATA_PARAMS(0, nullptr) }; // 2462570112
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics::NewProp_Type,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "SetControllerDrivenHandPoses", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics::OculusXRInputFunctionLibrary_eventSetControllerDrivenHandPoses_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics::OculusXRInputFunctionLibrary_eventSetControllerDrivenHandPoses_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execSetControllerDrivenHandPoses)
{
	P_GET_ENUM(EOculusXRControllerDrivenHandPoseTypes,Z_Param_Type);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRInputFunctionLibrary::SetControllerDrivenHandPoses(EOculusXRControllerDrivenHandPoseTypes(Z_Param_Type));
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function SetControllerDrivenHandPoses

// Begin Class UOculusXRInputFunctionLibrary Function SetHapticsByValue
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics
{
	struct OculusXRInputFunctionLibrary_eventSetHapticsByValue_Parms
	{
		float Frequency;
		float Amplitude;
		EControllerHand Hand;
		EOculusXRHandHapticsLocation Location;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Controller" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the value of the haptics for the specified hand and location directly, using frequency and amplitude.  NOTE:  If a curve is already\n\x09 * playing for this hand, it will be cancelled in favour of the specified values.\n\x09 *\n\x09 * @param\x09""Frequency\x09\x09\x09\x09The normalized frequency [0.0, 1.0] to play through the haptics system\n\x09 * @param\x09""Amplitude\x09\x09\x09\x09The normalized amplitude [0.0, 1.0] to set the haptic feedback to\n\x09 * @param\x09Hand\x09\x09\x09\x09\x09Which hand to play the effect on\n\x09 * @param\x09Location\x09\x09\x09\x09Which hand location to play the effect on\n\x09 */" },
#endif
		{ "CPP_Default_Location", "Hand" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the value of the haptics for the specified hand and location directly, using frequency and amplitude.  NOTE:  If a curve is already\nplaying for this hand, it will be cancelled in favour of the specified values.\n\n@param       Frequency                               The normalized frequency [0.0, 1.0] to play through the haptics system\n@param       Amplitude                               The normalized amplitude [0.0, 1.0] to set the haptic feedback to\n@param       Hand                                    Which hand to play the effect on\n@param       Location                                Which hand location to play the effect on" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Frequency_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Amplitude_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Frequency;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Amplitude;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Hand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Hand;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Location_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Location;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::NewProp_Frequency = { "Frequency", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventSetHapticsByValue_Parms, Frequency), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Frequency_MetaData), NewProp_Frequency_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::NewProp_Amplitude = { "Amplitude", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventSetHapticsByValue_Parms, Amplitude), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Amplitude_MetaData), NewProp_Amplitude_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::NewProp_Hand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::NewProp_Hand = { "Hand", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventSetHapticsByValue_Parms, Hand), Z_Construct_UEnum_InputCore_EControllerHand, METADATA_PARAMS(0, nullptr) }; // 775183092
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::NewProp_Location_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventSetHapticsByValue_Parms, Location), Z_Construct_UEnum_OculusXRInput_EOculusXRHandHapticsLocation, METADATA_PARAMS(0, nullptr) }; // 761422410
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::NewProp_Frequency,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::NewProp_Amplitude,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::NewProp_Hand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::NewProp_Hand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::NewProp_Location_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::NewProp_Location,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "SetHapticsByValue", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::OculusXRInputFunctionLibrary_eventSetHapticsByValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::OculusXRInputFunctionLibrary_eventSetHapticsByValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execSetHapticsByValue)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Frequency);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Amplitude);
	P_GET_ENUM(EControllerHand,Z_Param_Hand);
	P_GET_ENUM(EOculusXRHandHapticsLocation,Z_Param_Location);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRInputFunctionLibrary::SetHapticsByValue(Z_Param_Frequency,Z_Param_Amplitude,EControllerHand(Z_Param_Hand),EOculusXRHandHapticsLocation(Z_Param_Location));
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function SetHapticsByValue

// Begin Class UOculusXRInputFunctionLibrary Function StopHapticEffect
struct Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics
{
	struct OculusXRInputFunctionLibrary_eventStopHapticEffect_Parms
	{
		EControllerHand Hand;
		EOculusXRHandHapticsLocation Location;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "OculusLibrary|Controller" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Stops a playing haptic feedback curve at a specific location.\n\x09 * @param\x09HapticEffect\x09\x09\x09The haptic effect to stop\n\x09 * @param\x09Hand\x09\x09\x09\x09\x09Which hand to stop the effect for\n\x09 * @param\x09Location\x09\x09\x09\x09Which hand location to play the effect on\n\x09 */" },
#endif
		{ "CPP_Default_Location", "Hand" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stops a playing haptic feedback curve at a specific location.\n@param       HapticEffect                    The haptic effect to stop\n@param       Hand                                    Which hand to stop the effect for\n@param       Location                                Which hand location to play the effect on" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Hand_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Hand;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Location_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Location;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::NewProp_Hand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::NewProp_Hand = { "Hand", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventStopHapticEffect_Parms, Hand), Z_Construct_UEnum_InputCore_EControllerHand, METADATA_PARAMS(0, nullptr) }; // 775183092
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::NewProp_Location_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OculusXRInputFunctionLibrary_eventStopHapticEffect_Parms, Location), Z_Construct_UEnum_OculusXRInput_EOculusXRHandHapticsLocation, METADATA_PARAMS(0, nullptr) }; // 761422410
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::NewProp_Hand_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::NewProp_Hand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::NewProp_Location_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::NewProp_Location,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOculusXRInputFunctionLibrary, nullptr, "StopHapticEffect", nullptr, nullptr, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::OculusXRInputFunctionLibrary_eventStopHapticEffect_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::OculusXRInputFunctionLibrary_eventStopHapticEffect_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOculusXRInputFunctionLibrary::execStopHapticEffect)
{
	P_GET_ENUM(EControllerHand,Z_Param_Hand);
	P_GET_ENUM(EOculusXRHandHapticsLocation,Z_Param_Location);
	P_FINISH;
	P_NATIVE_BEGIN;
	UOculusXRInputFunctionLibrary::StopHapticEffect(EControllerHand(Z_Param_Hand),EOculusXRHandHapticsLocation(Z_Param_Location));
	P_NATIVE_END;
}
// End Class UOculusXRInputFunctionLibrary Function StopHapticEffect

// Begin Class UOculusXRInputFunctionLibrary
void UOculusXRInputFunctionLibrary::StaticRegisterNativesUOculusXRInputFunctionLibrary()
{
	UClass* Class = UOculusXRInputFunctionLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ConvertBoneToFinger", &UOculusXRInputFunctionLibrary::execConvertBoneToFinger },
		{ "GetBoneName", &UOculusXRInputFunctionLibrary::execGetBoneName },
		{ "GetBoneRotation", &UOculusXRInputFunctionLibrary::execGetBoneRotation },
		{ "GetControllerDrivenHandPoses", &UOculusXRInputFunctionLibrary::execGetControllerDrivenHandPoses },
		{ "GetControllerSampleRateHz", &UOculusXRInputFunctionLibrary::execGetControllerSampleRateHz },
		{ "GetDominantHand", &UOculusXRInputFunctionLibrary::execGetDominantHand },
		{ "GetFingerTrackingConfidence", &UOculusXRInputFunctionLibrary::execGetFingerTrackingConfidence },
		{ "GetHandScale", &UOculusXRInputFunctionLibrary::execGetHandScale },
		{ "GetHandSkeletalMesh", &UOculusXRInputFunctionLibrary::execGetHandSkeletalMesh },
		{ "GetMaxHapticDuration", &UOculusXRInputFunctionLibrary::execGetMaxHapticDuration },
		{ "GetPointerPose", &UOculusXRInputFunctionLibrary::execGetPointerPose },
		{ "GetTrackingConfidence", &UOculusXRInputFunctionLibrary::execGetTrackingConfidence },
		{ "InitializeHandPhysics", &UOculusXRInputFunctionLibrary::execInitializeHandPhysics },
		{ "IsHandPositionValid", &UOculusXRInputFunctionLibrary::execIsHandPositionValid },
		{ "IsHandTrackingEnabled", &UOculusXRInputFunctionLibrary::execIsHandTrackingEnabled },
		{ "IsPointerPoseValid", &UOculusXRInputFunctionLibrary::execIsPointerPoseValid },
		{ "PlayAmplitudeEnvelopeHapticEffect", &UOculusXRInputFunctionLibrary::execPlayAmplitudeEnvelopeHapticEffect },
		{ "PlayBufferHapticEffect", &UOculusXRInputFunctionLibrary::execPlayBufferHapticEffect },
		{ "PlayCurveHapticEffect", &UOculusXRInputFunctionLibrary::execPlayCurveHapticEffect },
		{ "PlaySoundWaveHapticEffect", &UOculusXRInputFunctionLibrary::execPlaySoundWaveHapticEffect },
		{ "SetControllerDrivenHandPoses", &UOculusXRInputFunctionLibrary::execSetControllerDrivenHandPoses },
		{ "SetHapticsByValue", &UOculusXRInputFunctionLibrary::execSetHapticsByValue },
		{ "StopHapticEffect", &UOculusXRInputFunctionLibrary::execStopHapticEffect },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOculusXRInputFunctionLibrary);
UClass* Z_Construct_UClass_UOculusXRInputFunctionLibrary_NoRegister()
{
	return UOculusXRInputFunctionLibrary::StaticClass();
}
struct Z_Construct_UClass_UOculusXRInputFunctionLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "OculusXRInputFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/OculusXRInputFunctionLibrary.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_ConvertBoneToFinger, "ConvertBoneToFinger" }, // 2853198903
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneName, "GetBoneName" }, // 139144648
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetBoneRotation, "GetBoneRotation" }, // 304581576
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerDrivenHandPoses, "GetControllerDrivenHandPoses" }, // 2470120968
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetControllerSampleRateHz, "GetControllerSampleRateHz" }, // 1819642089
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetDominantHand, "GetDominantHand" }, // 2484767150
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetFingerTrackingConfidence, "GetFingerTrackingConfidence" }, // 1705038054
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandScale, "GetHandScale" }, // 2488477393
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetHandSkeletalMesh, "GetHandSkeletalMesh" }, // 2635916501
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetMaxHapticDuration, "GetMaxHapticDuration" }, // 1802765159
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetPointerPose, "GetPointerPose" }, // 785853047
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_GetTrackingConfidence, "GetTrackingConfidence" }, // 541214429
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_InitializeHandPhysics, "InitializeHandPhysics" }, // 2265194056
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandPositionValid, "IsHandPositionValid" }, // 2429526194
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsHandTrackingEnabled, "IsHandTrackingEnabled" }, // 4101582236
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_IsPointerPoseValid, "IsPointerPoseValid" }, // 2498700250
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayAmplitudeEnvelopeHapticEffect, "PlayAmplitudeEnvelopeHapticEffect" }, // 4230550658
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayBufferHapticEffect, "PlayBufferHapticEffect" }, // 2976162884
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlayCurveHapticEffect, "PlayCurveHapticEffect" }, // 1129729689
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_PlaySoundWaveHapticEffect, "PlaySoundWaveHapticEffect" }, // 3676759220
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetControllerDrivenHandPoses, "SetControllerDrivenHandPoses" }, // 2174554521
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_SetHapticsByValue, "SetHapticsByValue" }, // 3399618580
		{ &Z_Construct_UFunction_UOculusXRInputFunctionLibrary_StopHapticEffect, "StopHapticEffect" }, // 3639767158
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOculusXRInputFunctionLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UOculusXRInputFunctionLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_OculusXRInput,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRInputFunctionLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOculusXRInputFunctionLibrary_Statics::ClassParams = {
	&UOculusXRInputFunctionLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOculusXRInputFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UOculusXRInputFunctionLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOculusXRInputFunctionLibrary()
{
	if (!Z_Registration_Info_UClass_UOculusXRInputFunctionLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOculusXRInputFunctionLibrary.OuterSingleton, Z_Construct_UClass_UOculusXRInputFunctionLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOculusXRInputFunctionLibrary.OuterSingleton;
}
template<> OCULUSXRINPUT_API UClass* StaticClass<UOculusXRInputFunctionLibrary>()
{
	return UOculusXRInputFunctionLibrary::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOculusXRInputFunctionLibrary);
UOculusXRInputFunctionLibrary::~UOculusXRInputFunctionLibrary() {}
// End Class UOculusXRInputFunctionLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOculusXRHandType_StaticEnum, TEXT("EOculusXRHandType"), &Z_Registration_Info_UEnum_EOculusXRHandType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1666178145U) },
		{ EOculusXRSide_StaticEnum, TEXT("EOculusXRSide"), &Z_Registration_Info_UEnum_EOculusXRSide, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3337296388U) },
		{ EOculusXRTrackingConfidence_StaticEnum, TEXT("EOculusXRTrackingConfidence"), &Z_Registration_Info_UEnum_EOculusXRTrackingConfidence, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2813100711U) },
		{ EOculusXRFinger_StaticEnum, TEXT("EOculusXRFinger"), &Z_Registration_Info_UEnum_EOculusXRFinger, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 577514988U) },
		{ EOculusXRBone_StaticEnum, TEXT("EOculusXRBone"), &Z_Registration_Info_UEnum_EOculusXRBone, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2961258405U) },
		{ EOculusXRHandHapticsLocation_StaticEnum, TEXT("EOculusXRHandHapticsLocation"), &Z_Registration_Info_UEnum_EOculusXRHandHapticsLocation, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 761422410U) },
		{ EOculusXRControllerDrivenHandPoseTypes_StaticEnum, TEXT("EOculusXRControllerDrivenHandPoseTypes"), &Z_Registration_Info_UEnum_EOculusXRControllerDrivenHandPoseTypes, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2462570112U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOculusXRCapsuleCollider::StaticStruct, Z_Construct_UScriptStruct_FOculusXRCapsuleCollider_Statics::NewStructOps, TEXT("OculusXRCapsuleCollider"), &Z_Registration_Info_UScriptStruct_OculusXRCapsuleCollider, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOculusXRCapsuleCollider), 195539744U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOculusXRInputFunctionLibrary, UOculusXRInputFunctionLibrary::StaticClass, TEXT("UOculusXRInputFunctionLibrary"), &Z_Registration_Info_UClass_UOculusXRInputFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOculusXRInputFunctionLibrary), 401724058U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_886771348(TEXT("/Script/OculusXRInput"),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HalcyonVR_Plugins_UnrealMetaXRPlugin_68_0_MetaXR_Source_OculusXRInput_Public_OculusXRInputFunctionLibrary_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
