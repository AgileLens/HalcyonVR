// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRMovementAssetsFactories.h"

#include "AssetToolsModule.h"
#include "IAssetTools.h"
#include "Kismet2/KismetEditorUtilities.h"

#include "OculusXRLiveLinkRetargetFaceAsset.h"
#include "OculusXRLiveLinkRetargetBodyAsset.h"

#define LOCTEXT_NAMESPACE "OculusXRMovementAssetsFactories"

UOculusXRMetahumanRetargetAssetFactory::UOculusXRMetahumanRetargetAssetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UBlueprint::StaticClass();

	bCreateNew = true;
	bEditAfterNew = true;
}

bool UOculusXRMetahumanRetargetAssetFactory::ConfigureProperties()
{
	return true;
}

uint32 UOculusXRMetahumanRetargetAssetFactory::GetMenuCategories() const
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	return AssetTools.RegisterAdvancedAssetCategory("LiveLink", LOCTEXT("AssetCategoryName", "Live Link"));
}

UObject* UOculusXRMetahumanRetargetAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	UBlueprint* RetargetBlueprint = FKismetEditorUtilities::CreateBlueprint(ParentClass, InParent, Name, BlueprintType, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), CallingContext);

	if (const TSubclassOf<UObject> GeneratedClass = RetargetBlueprint->GeneratedClass)
	{
		SetDefaults(GeneratedClass);
	}

	return RetargetBlueprint;
}

UOculusXRMetahumanFaceRetargetAssetFactory::UOculusXRMetahumanFaceRetargetAssetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ParentClass = UOculusXRLiveLinkRetargetFaceAsset::StaticClass();
}

FText UOculusXRMetahumanFaceRetargetAssetFactory::GetDisplayName() const
{
	return LOCTEXT("DisplayNameMetahumanFace", "Face retarget asset for OculusXRMovement and Metahuman");
}

void UOculusXRMetahumanFaceRetargetAssetFactory::SetDefaults(const TSubclassOf<UObject> GeneratedClass) const
{
	if (UOculusXRLiveLinkRetargetFaceAsset* Retargeting = GeneratedClass->GetDefaultObject<UOculusXRLiveLinkRetargetFaceAsset>())
	{
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::BrowLowererL, { "CTRL_expressions_BrowDownL", "CTRL_expressions_BrowLateralL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::BrowLowererR, { "CTRL_expressions_BrowDownR", "CTRL_expressions_BrowLateralR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::CheekPuffL, { "CTRL_expressions_mouthCheekBlowL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::CheekPuffR, { "CTRL_expressions_mouthCheekBlowR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::CheekRaiserL, { "CTRL_expressions_eyeCheekRaiseL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::CheekRaiserR, { "CTRL_expressions_eyeCheekRaiseR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::CheekSuckL, { "CTRL_expressions_mouthCheekSuckL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::CheekSuckR, { "CTRL_expressions_mouthCheekSuckR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::ChinRaiserB, { "CTRL_expressions_jawChinRaiseDL", "CTRL_expressions_jawChinRaiseDR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::ChinRaiserT, { "CTRL_expressions_jawChinRaiseUL", "CTRL_expressions_jawChinRaiseUR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::DimplerL, { "CTRL_expressions_mouthDimpleL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::DimplerR, { "CTRL_expressions_mouthDimpleR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::EyesClosedL, { "CTRL_expressions_eyeBlinkL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::EyesClosedR, { "CTRL_expressions_eyeBlinkR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::EyesLookDownL, { "CTRL_expressions_eyeLookDownL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::EyesLookDownR, { "CTRL_expressions_eyeLookDownR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::EyesLookLeftL, { "CTRL_expressions_eyeLookLeftL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::EyesLookLeftR, { "CTRL_expressions_eyeLookLeftR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::EyesLookRightL, { "CTRL_expressions_eyeLookRightL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::EyesLookRightR, { "CTRL_expressions_eyeLookRightR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::EyesLookUpL, { "CTRL_expressions_eyeLookUpL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::EyesLookUpR, { "CTRL_expressions_eyeLookUpR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::InnerBrowRaiserL, { "CTRL_expressions_browRaiseInL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::InnerBrowRaiserR, { "CTRL_expressions_browRaiseInR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::JawDrop, { "CTRL_expressions_jawOpen" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::JawSidewaysLeft, { "CTRL_expressions_jawLeft" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::JawSidewaysRight, { "CTRL_expressions_jawRight" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::JawThrust, { "CTRL_expressions_jawFwd", "CTRL_expressions_jawBack" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LidTightenerL, { "CTRL_expressions_eyeSquintInnerL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LidTightenerR, { "CTRL_expressions_eyeSquintInnerR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipCornerDepressorL, { "CTRL_expressions_mouthCornerDepressL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipCornerDepressorR, { "CTRL_expressions_mouthCornerDepressR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipCornerPullerL, { "CTRL_expressions_mouthCornerPullL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipCornerPullerR, { "CTRL_expressions_mouthCornerPullR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipFunnelerLB, { "CTRL_expressions_mouthFunnelDL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipFunnelerLT, { "CTRL_expressions_mouthFunnelUL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipFunnelerRB, { "CTRL_expressions_mouthFunnelDR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipFunnelerRT, { "CTRL_expressions_mouthFunnelUR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipPressorL, { "CTRL_expressions_mouthLipsPressL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipPressorR, { "CTRL_expressions_mouthLipsPressR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipPuckerL, { "CTRL_expressions_mouthLipsPurseDL", "CTRL_expressions_mouthLipsPurseUL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipPuckerR, { "CTRL_expressions_mouthLipsPurseDR", "CTRL_expressions_mouthLipsPurseUR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipStretcherL, { "CTRL_expressions_mouthStretchL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipStretcherR, { "CTRL_expressions_mouthStretchR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipSuckLB, { "CTRL_expressions_mouthLowerLipBiteL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipSuckLT, { "CTRL_expressions_mouthUpperLipBiteL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipSuckRB, { "CTRL_expressions_mouthLowerLipBiteR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipSuckRT, { "CTRL_expressions_mouthUpperLipBiteR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipTightenerL, { "CTRL_expressions_mouthLipsTightenDL", "CTRL_expressions_mouthLipsTightenUL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipTightenerR, { "CTRL_expressions_mouthLipsTightenDR", "CTRL_expressions_mouthLipsTightenUR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LipsToward, { "CTRL_expressions_jawChinRaiseDL", "CTRL_expressions_jawChinRaiseDR", "CTRL_expressions_jawChinRaiseUL", "CTRL_expressions_jawChinRaiseUR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LowerLipDepressorL, { "CTRL_expressions_mouthLowerLipDepressL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::LowerLipDepressorR, { "CTRL_expressions_mouthLowerLipDepressR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::MouthLeft, { "CTRL_expressions_mouthLeft" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::MouthRight, { "CTRL_expressions_mouthRight" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::NoseWrinklerL, { "CTRL_expressions_noseWrinkleL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::NoseWrinklerR, { "CTRL_expressions_noseWrinkleR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::OuterBrowRaiserL, { "CTRL_expressions_browRaiseOuterL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::OuterBrowRaiserR, { "CTRL_expressions_browRaiseOuterR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::UpperLidRaiserL, { "CTRL_expressions_eyeUpperLidUpL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::UpperLidRaiserR, { "CTRL_expressions_eyeUpperLidUpR" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::UpperLipRaiserL, { "CTRL_expressions_mouthUpperLipRaiseL" });
		Retargeting->CurveRemapping.Emplace(EOculusXRFaceExpression::UpperLipRaiserR, { "CTRL_expressions_mouthUpperLipRaiseR" });
	}
}

UOculusXRMetahumanBodyRetargetAssetFactory::UOculusXRMetahumanBodyRetargetAssetFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ParentClass = UOculusXRLiveLinkRetargetBodyAsset::StaticClass();
}

FText UOculusXRMetahumanBodyRetargetAssetFactory::GetDisplayName() const
{
	return LOCTEXT("DisplayNameMetahumanBody", "Body retarget asset for OculusXRMovement and Metahuman");
}

void UOculusXRMetahumanBodyRetargetAssetFactory::SetDefaults(const TSubclassOf<UObject> GeneratedClass) const
{
	if (UOculusXRLiveLinkRetargetBodyAsset* Retargeting = GeneratedClass->GetDefaultObject<UOculusXRLiveLinkRetargetBodyAsset>())
	{
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRoot, "root");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyHips, "pelvis");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodySpineLower, "spine_01");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodySpineMiddle, "spine_02");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodySpineUpper, "spine_04");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyChest, "spine_05");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyNeck, "neck_02");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyHead, "head");

		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftShoulder, "clavicle_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftScapula, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftArmUpper, "upperarm_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftArmLower, "lowerarm_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandWristTwist, NAME_None);

		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightShoulder, "clavicle_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightScapula, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightArmUpper, "upperarm_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightArmLower, "lowerarm_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandWristTwist, NAME_None);

		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandPalm, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandWrist, "hand_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandThumbMetacarpal, "thumb_01_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandThumbProximal, "thumb_02_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandThumbDistal, "thumb_03_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandThumbTip, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandIndexMetacarpal, "index_metacarpal_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandIndexProximal, "index_01_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandIndexIntermediate, "index_02_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandIndexDistal, "index_03_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandIndexTip, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandMiddleMetacarpal, "middle_metacarpal_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandMiddleProximal, "middle_01_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandMiddleIntermediate, "middle_02_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandMiddleDistal, "middle_03_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandMiddleTip, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandRingMetacarpal, "ring_metacarpal_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandRingProximal, "ring_01_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandRingIntermediate, "ring_02_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandRingDistal, "ring_03_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandRingTip, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandLittleMetacarpal, "pinky_metacarpal_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandLittleProximal, "pinky_01_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandLittleIntermediate, "pinky_02_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandLittleDistal, "pinky_03_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftHandLittleTip, NAME_None);

		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandPalm, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandWrist, "hand_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandThumbMetacarpal, "thumb_01_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandThumbProximal, "thumb_02_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandThumbDistal, "thumb_03_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandThumbTip, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandIndexMetacarpal, "index_metacarpal_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandIndexProximal, "index_01_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandIndexIntermediate, "index_02_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandIndexDistal, "index_03_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandIndexTip, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandMiddleMetacarpal, "middle_metacarpal_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandMiddleProximal, "middle_01_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandMiddleIntermediate, "middle_02_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandMiddleDistal, "middle_03_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandMiddleTip, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandRingMetacarpal, "ring_metacarpal_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandRingProximal, "ring_01_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandRingIntermediate, "ring_02_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandRingDistal, "ring_03_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandRingTip, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandLittleMetacarpal, "pinky_metacarpal_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandLittleProximal, "pinky_01_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandLittleIntermediate, "pinky_02_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandLittleDistal, "pinky_03_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightHandLittleTip, NAME_None);

		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftUpperLeg, "thigh_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftLowerLeg, "calf_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftFootAnkleTwist, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftFootAnkle, "foot_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftFootSubtalar, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftFootTransverse, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyLeftFootBall, "ball_l");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightUpperLeg, "thigh_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightLowerLeg, "calf_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightFootAnkleTwist, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightFootAnkle, "foot_r");
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightFootSubtalar, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightFootTransverse, NAME_None);
		Retargeting->BoneRemapping.Emplace(EOculusXRBoneID::BodyRightFootBall, "ball_r");

		{
			FOculusXRBoneCorrection FromOculusToUnreal;
			FromOculusToUnreal.RotationOffset.Roll = -90;
			FromOculusToUnreal.RotationOffset.Yaw = -90;
			Retargeting->GlobalCorrection = FromOculusToUnreal;
		}
		{
			FOculusXRBoneCorrectionSet Root;
			Root.Bones.Add(EOculusXRBoneID::BodyRoot);
			Root.BoneCorrection.RotationOffset.Roll = 90;
			Retargeting->LocalCorrections.Add(Root);
		}
		{
			FOculusXRBoneCorrectionSet Hips;
			Hips.Bones.Add(EOculusXRBoneID::BodyHips);
			Hips.BoneCorrection.RotationOffset.Yaw = 5;
			Retargeting->LocalCorrections.Add(Hips);
		}
		{
			FOculusXRBoneCorrectionSet SpineLowerPart;
			SpineLowerPart.Bones.Add(EOculusXRBoneID::BodySpineLower);
			SpineLowerPart.Bones.Add(EOculusXRBoneID::BodySpineMiddle);
			SpineLowerPart.BoneCorrection.RotationOffset.Yaw = 10;
			Retargeting->LocalCorrections.Add(SpineLowerPart);
		}
		{
			FOculusXRBoneCorrectionSet SpineUpperPart;
			SpineUpperPart.Bones.Add(EOculusXRBoneID::BodySpineUpper);
			SpineUpperPart.BoneCorrection.PositionOffset.Y = 3;
			SpineUpperPart.BoneCorrection.RotationOffset.Yaw = -5;
			Retargeting->LocalCorrections.Add(SpineUpperPart);
		}
		{
			FOculusXRBoneCorrectionSet Chest;
			Chest.Bones.Add(EOculusXRBoneID::BodyChest);
			Chest.BoneCorrection.PositionOffset.Y = 3;
			Chest.BoneCorrection.RotationOffset.Yaw = -5;
			Retargeting->LocalCorrections.Add(Chest);
		}
		{
			FOculusXRBoneCorrectionSet Head;
			Head.Bones.Add(EOculusXRBoneID::BodyHead);
			Head.Bones.Add(EOculusXRBoneID::BodyNeck);
			Head.BoneCorrection.PositionOffset.Y = -3;
			Head.BoneCorrection.RotationOffset.Yaw = 5;
			Retargeting->LocalCorrections.Add(Head);
		}
		{
			FOculusXRBoneCorrectionSet LeftShoulder;
			LeftShoulder.Bones.Add(EOculusXRBoneID::BodyLeftShoulder);
			LeftShoulder.BoneCorrection.RotationOffset.Pitch = -5;
			LeftShoulder.BoneCorrection.RotationOffset.Yaw = 30;
			LeftShoulder.BoneCorrection.PositionOffset.X = 5;
			LeftShoulder.BoneCorrection.PositionOffset.Y = -6;
			Retargeting->LocalCorrections.Add(LeftShoulder);
		}
		{
			FOculusXRBoneCorrectionSet RightShoulder;
			RightShoulder.Bones.Add(EOculusXRBoneID::BodyRightShoulder);
			RightShoulder.BoneCorrection.RotationOffset.Pitch = -5;
			RightShoulder.BoneCorrection.RotationOffset.Yaw = 30;
			RightShoulder.BoneCorrection.PositionOffset.X = -6;
			RightShoulder.BoneCorrection.PositionOffset.Y = 5;
			Retargeting->LocalCorrections.Add(RightShoulder);
		}
		{
			FOculusXRBoneCorrectionSet Hands;
			for (uint8 BoneId = static_cast<uint8>(EOculusXRBoneID::BodyLeftHandPalm); BoneId <= static_cast<uint8>(EOculusXRBoneID::BodyRightHandLittleTip); ++BoneId)
			{
				Hands.Bones.Emplace(static_cast<EOculusXRBoneID>(BoneId));
			}
			Hands.BoneCorrection.RotationOffset.Roll = 180;
			Retargeting->LocalCorrections.Add(Hands);
		}
		{
			FOculusXRBoneCorrectionSet Legs;
			Legs.Bones.Add(EOculusXRBoneID::BodyLeftUpperLeg);
			Legs.Bones.Add(EOculusXRBoneID::BodyLeftLowerLeg);
			Legs.Bones.Add(EOculusXRBoneID::BodyRightUpperLeg);
			Legs.Bones.Add(EOculusXRBoneID::BodyRightLowerLeg);
			Legs.BoneCorrection.RotationOffset.Yaw = 180;
			Retargeting->LocalCorrections.Add(Legs);
		}
		{
			FOculusXRBoneCorrectionSet FootAnkles;
			FootAnkles.Bones.Add(EOculusXRBoneID::BodyLeftFootAnkle);
			FootAnkles.Bones.Add(EOculusXRBoneID::BodyRightFootAnkle);
			FootAnkles.BoneCorrection.RotationOffset.Roll = 180;
			FootAnkles.BoneCorrection.RotationOffset.Pitch = 175;
			FootAnkles.BoneCorrection.RotationOffset.Yaw = -80;
			Retargeting->LocalCorrections.Add(FootAnkles);
		}
		{
			FOculusXRBoneCorrectionSet FootBalls;
			FootBalls.Bones.Add(EOculusXRBoneID::BodyLeftFootBall);
			FootBalls.BoneCorrection.RotationOffset.Yaw = 200;
			FootBalls.BoneCorrection.PositionOffset.Y = -5;
			FootBalls.BoneCorrection.PositionOffset.Z = 1;
			Retargeting->LocalCorrections.Add(FootBalls);
		}
		{
			FOculusXRBoneCorrectionSet FootBalls;
			FootBalls.Bones.Add(EOculusXRBoneID::BodyRightFootBall);
			FootBalls.BoneCorrection.RotationOffset.Yaw = 200;
			FootBalls.BoneCorrection.PositionOffset.Y = 5;
			FootBalls.BoneCorrection.PositionOffset.Z = -1;
			Retargeting->LocalCorrections.Add(FootBalls);
		}

		Retargeting->RetargetingMode = EOculusXRRetargetingMode::RotationsPlusHips;
		Retargeting->ForwardMesh = EOculusXRAxis::Y;
	}
}

#undef LOCTEXT_NAMESPACE
