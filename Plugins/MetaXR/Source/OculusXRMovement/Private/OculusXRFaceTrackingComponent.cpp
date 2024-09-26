// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRFaceTrackingComponent.h"
#include "OculusXRHMD.h"
#include "OculusXRPluginWrapper.h"
#include "OculusXRMovementFunctionLibrary.h"
#include "OculusXRMovementHelpers.h"
#include "OculusXRMovementLog.h"
#include "OculusXRTelemetryMovementEvents.h"

#include "Engine/SkeletalMesh.h"
#include "Components/SkeletalMeshComponent.h"
#include "Math/UnrealMathUtility.h"

int UOculusXRFaceTrackingComponent::TrackingInstanceCount = 0;

UOculusXRFaceTrackingComponent::UOculusXRFaceTrackingComponent()
	: TargetMeshComponentName(NAME_None)
	, InvalidFaceDataResetTime(2.0f)
	, bUpdateFace(true)
	, TargetMeshComponent(nullptr)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	// Some defaults
	ExpressionNames.Add(EOculusXRFaceExpression::BrowLowererL, "browLowerer_L");
	ExpressionNames.Add(EOculusXRFaceExpression::BrowLowererR, "browLowerer_R");
	ExpressionNames.Add(EOculusXRFaceExpression::CheekPuffL, "cheekPuff_L");
	ExpressionNames.Add(EOculusXRFaceExpression::CheekPuffR, "cheekPuff_R");
	ExpressionNames.Add(EOculusXRFaceExpression::CheekRaiserL, "cheekRaiser_L");
	ExpressionNames.Add(EOculusXRFaceExpression::CheekRaiserR, "cheekRaiser_R");
	ExpressionNames.Add(EOculusXRFaceExpression::CheekSuckL, "cheekSuck_L");
	ExpressionNames.Add(EOculusXRFaceExpression::CheekSuckR, "cheekSuck_R");
	ExpressionNames.Add(EOculusXRFaceExpression::ChinRaiserB, "chinRaiser_B");
	ExpressionNames.Add(EOculusXRFaceExpression::ChinRaiserT, "chinRaiser_T");
	ExpressionNames.Add(EOculusXRFaceExpression::DimplerL, "dimpler_L");
	ExpressionNames.Add(EOculusXRFaceExpression::DimplerR, "dimpler_R");
	ExpressionNames.Add(EOculusXRFaceExpression::EyesClosedL, "eyesClosed_L");
	ExpressionNames.Add(EOculusXRFaceExpression::EyesClosedR, "eyesClosed_R");
	ExpressionNames.Add(EOculusXRFaceExpression::EyesLookDownL, "eyesLookDown_L");
	ExpressionNames.Add(EOculusXRFaceExpression::EyesLookDownR, "eyesLookDown_R");
	ExpressionNames.Add(EOculusXRFaceExpression::EyesLookLeftL, "eyesLookLeft_L");
	ExpressionNames.Add(EOculusXRFaceExpression::EyesLookLeftR, "eyesLookLeft_R");
	ExpressionNames.Add(EOculusXRFaceExpression::EyesLookRightL, "eyesLookRight_L");
	ExpressionNames.Add(EOculusXRFaceExpression::EyesLookRightR, "eyesLookRight_R");
	ExpressionNames.Add(EOculusXRFaceExpression::EyesLookUpL, "eyesLookUp_L");
	ExpressionNames.Add(EOculusXRFaceExpression::EyesLookUpR, "eyesLookUp_R");
	ExpressionNames.Add(EOculusXRFaceExpression::InnerBrowRaiserL, "innerBrowRaiser_L");
	ExpressionNames.Add(EOculusXRFaceExpression::InnerBrowRaiserR, "innerBrowRaiser_R");
	ExpressionNames.Add(EOculusXRFaceExpression::JawDrop, "jawDrop");
	ExpressionNames.Add(EOculusXRFaceExpression::JawSidewaysLeft, "jawSidewaysLeft");
	ExpressionNames.Add(EOculusXRFaceExpression::JawSidewaysRight, "jawSidewaysRight");
	ExpressionNames.Add(EOculusXRFaceExpression::JawThrust, "jawThrust");
	ExpressionNames.Add(EOculusXRFaceExpression::LidTightenerL, "lidTightener_L");
	ExpressionNames.Add(EOculusXRFaceExpression::LidTightenerR, "lidTightener_R");
	ExpressionNames.Add(EOculusXRFaceExpression::LipCornerDepressorL, "lipCornerDepressor_L");
	ExpressionNames.Add(EOculusXRFaceExpression::LipCornerDepressorR, "lipCornerDepressor_R");
	ExpressionNames.Add(EOculusXRFaceExpression::LipCornerPullerL, "lipCornerPuller_L");
	ExpressionNames.Add(EOculusXRFaceExpression::LipCornerPullerR, "lipCornerPuller_R");
	ExpressionNames.Add(EOculusXRFaceExpression::LipFunnelerLB, "lipFunneler_LB");
	ExpressionNames.Add(EOculusXRFaceExpression::LipFunnelerLT, "lipFunneler_LT");
	ExpressionNames.Add(EOculusXRFaceExpression::LipFunnelerRB, "lipFunneler_RB");
	ExpressionNames.Add(EOculusXRFaceExpression::LipFunnelerRT, "lipFunneler_RT");
	ExpressionNames.Add(EOculusXRFaceExpression::LipPressorL, "lipPressor_L");
	ExpressionNames.Add(EOculusXRFaceExpression::LipPressorR, "lipPressor_R");
	ExpressionNames.Add(EOculusXRFaceExpression::LipPuckerL, "lipPucker_L");
	ExpressionNames.Add(EOculusXRFaceExpression::LipPuckerR, "lipPucker_R");
	ExpressionNames.Add(EOculusXRFaceExpression::LipStretcherL, "lipStretcher_L");
	ExpressionNames.Add(EOculusXRFaceExpression::LipStretcherR, "lipStretcher_R");
	ExpressionNames.Add(EOculusXRFaceExpression::LipSuckLB, "lipSuck_LB");
	ExpressionNames.Add(EOculusXRFaceExpression::LipSuckLT, "lipSuck_LT");
	ExpressionNames.Add(EOculusXRFaceExpression::LipSuckRB, "lipSuck_RB");
	ExpressionNames.Add(EOculusXRFaceExpression::LipSuckRT, "lipSuck_RT");
	ExpressionNames.Add(EOculusXRFaceExpression::LipTightenerL, "lipTightener_L");
	ExpressionNames.Add(EOculusXRFaceExpression::LipTightenerR, "lipTightener_R");
	ExpressionNames.Add(EOculusXRFaceExpression::LipsToward, "lipsToward");
	ExpressionNames.Add(EOculusXRFaceExpression::LowerLipDepressorL, "lowerLipDepressor_L");
	ExpressionNames.Add(EOculusXRFaceExpression::LowerLipDepressorR, "lowerLipDepressor_R");
	ExpressionNames.Add(EOculusXRFaceExpression::MouthLeft, "mouthLeft");
	ExpressionNames.Add(EOculusXRFaceExpression::MouthRight, "mouthRight");
	ExpressionNames.Add(EOculusXRFaceExpression::NoseWrinklerL, "noseWrinkler_L");
	ExpressionNames.Add(EOculusXRFaceExpression::NoseWrinklerR, "noseWrinkler_R");
	ExpressionNames.Add(EOculusXRFaceExpression::OuterBrowRaiserL, "outerBrowRaiser_L");
	ExpressionNames.Add(EOculusXRFaceExpression::OuterBrowRaiserR, "outerBrowRaiser_R");
	ExpressionNames.Add(EOculusXRFaceExpression::UpperLidRaiserL, "upperLidRaiser_L");
	ExpressionNames.Add(EOculusXRFaceExpression::UpperLidRaiserR, "upperLidRaiser_R");
	ExpressionNames.Add(EOculusXRFaceExpression::UpperLipRaiserL, "upperLipRaiser_L");
	ExpressionNames.Add(EOculusXRFaceExpression::UpperLipRaiserR, "upperLipRaiser_R");
	ExpressionNames.Add(EOculusXRFaceExpression::TongueTipInterdental, "tongueTipInterdental");
	ExpressionNames.Add(EOculusXRFaceExpression::TongueTipAlveolar, "tongueTipAlveolar");
	ExpressionNames.Add(EOculusXRFaceExpression::TongueFrontDorsalPalate, "tongueFrontDorsalPalate");
	ExpressionNames.Add(EOculusXRFaceExpression::TongueMidDorsalPalate, "tongueMidDorsalPalate");
	ExpressionNames.Add(EOculusXRFaceExpression::TongueBackDorsalVelar, "tongueBackDorsalVelar");
	ExpressionNames.Add(EOculusXRFaceExpression::TongueOut, "tongueOut");

	const int defaultFaceExpressionModifierLength = 33;
	ExpressionModifiers.SetNum(defaultFaceExpressionModifierLength);
	ExpressionModifiers[0].FaceExpressions = { EOculusXRFaceExpression::EyesClosedL, EOculusXRFaceExpression::EyesClosedR };
	ExpressionModifiers[1].FaceExpressions = { EOculusXRFaceExpression::EyesLookDownL, EOculusXRFaceExpression::EyesLookDownR };
	ExpressionModifiers[2].FaceExpressions = { EOculusXRFaceExpression::EyesLookLeftL, EOculusXRFaceExpression::EyesLookLeftR };
	ExpressionModifiers[3].FaceExpressions = { EOculusXRFaceExpression::EyesLookRightL, EOculusXRFaceExpression::EyesLookRightR };
	ExpressionModifiers[4].FaceExpressions = { EOculusXRFaceExpression::EyesLookUpL, EOculusXRFaceExpression::EyesLookUpR };
	ExpressionModifiers[5].FaceExpressions = { EOculusXRFaceExpression::LidTightenerL, EOculusXRFaceExpression::LidTightenerR };
	ExpressionModifiers[6].FaceExpressions = { EOculusXRFaceExpression::UpperLidRaiserL, EOculusXRFaceExpression::UpperLidRaiserR };
	ExpressionModifiers[7].FaceExpressions = { EOculusXRFaceExpression::JawDrop };
	ExpressionModifiers[8].FaceExpressions = { EOculusXRFaceExpression::JawSidewaysLeft, EOculusXRFaceExpression::JawSidewaysRight };
	ExpressionModifiers[9].FaceExpressions = { EOculusXRFaceExpression::JawThrust };
	ExpressionModifiers[10].FaceExpressions = { EOculusXRFaceExpression::LipFunnelerLB, EOculusXRFaceExpression::LipFunnelerLT };
	ExpressionModifiers[11].FaceExpressions = { EOculusXRFaceExpression::LipFunnelerRB, EOculusXRFaceExpression::LipFunnelerRT };
	ExpressionModifiers[12].FaceExpressions = { EOculusXRFaceExpression::LipPuckerL, EOculusXRFaceExpression::LipPuckerR };
	ExpressionModifiers[13].FaceExpressions = { EOculusXRFaceExpression::LipSuckLB, EOculusXRFaceExpression::LipSuckLT };
	ExpressionModifiers[14].FaceExpressions = { EOculusXRFaceExpression::LipSuckRB, EOculusXRFaceExpression::LipSuckRT };
	ExpressionModifiers[15].FaceExpressions = { EOculusXRFaceExpression::LipsToward };
	ExpressionModifiers[16].FaceExpressions = { EOculusXRFaceExpression::LowerLipDepressorL, EOculusXRFaceExpression::LowerLipDepressorR };
	ExpressionModifiers[17].FaceExpressions = { EOculusXRFaceExpression::ChinRaiserB, EOculusXRFaceExpression::ChinRaiserT };
	ExpressionModifiers[18].FaceExpressions = { EOculusXRFaceExpression::LipCornerDepressorL, EOculusXRFaceExpression::LipCornerDepressorR };
	ExpressionModifiers[19].FaceExpressions = { EOculusXRFaceExpression::LipCornerPullerL, EOculusXRFaceExpression::LipCornerPullerR };
	ExpressionModifiers[20].FaceExpressions = { EOculusXRFaceExpression::LipStretcherL, EOculusXRFaceExpression::LipStretcherR };
	ExpressionModifiers[21].FaceExpressions = { EOculusXRFaceExpression::MouthLeft, EOculusXRFaceExpression::MouthRight };
	ExpressionModifiers[22].FaceExpressions = { EOculusXRFaceExpression::LipPressorL, EOculusXRFaceExpression::LipPressorR };
	ExpressionModifiers[23].FaceExpressions = { EOculusXRFaceExpression::LipTightenerL, EOculusXRFaceExpression::LipTightenerR };
	ExpressionModifiers[24].FaceExpressions = { EOculusXRFaceExpression::UpperLipRaiserL, EOculusXRFaceExpression::UpperLipRaiserR };
	ExpressionModifiers[25].FaceExpressions = { EOculusXRFaceExpression::CheekPuffL, EOculusXRFaceExpression::CheekPuffR };
	ExpressionModifiers[26].FaceExpressions = { EOculusXRFaceExpression::CheekRaiserL, EOculusXRFaceExpression::CheekRaiserR };
	ExpressionModifiers[27].FaceExpressions = { EOculusXRFaceExpression::CheekSuckL, EOculusXRFaceExpression::CheekSuckR };
	ExpressionModifiers[28].FaceExpressions = { EOculusXRFaceExpression::DimplerL, EOculusXRFaceExpression::DimplerR };
	ExpressionModifiers[29].FaceExpressions = { EOculusXRFaceExpression::NoseWrinklerL, EOculusXRFaceExpression::NoseWrinklerR };
	ExpressionModifiers[30].FaceExpressions = { EOculusXRFaceExpression::BrowLowererL, EOculusXRFaceExpression::BrowLowererR };
	ExpressionModifiers[31].FaceExpressions = { EOculusXRFaceExpression::InnerBrowRaiserL, EOculusXRFaceExpression::InnerBrowRaiserR };
	ExpressionModifiers[32].FaceExpressions = { EOculusXRFaceExpression::OuterBrowRaiserL, EOculusXRFaceExpression::OuterBrowRaiserR };

	OculusXRTelemetry::TScopedMarker<OculusXRTelemetry::Events::FMovementSDKFaceStart>(static_cast<int>(GetTypeHash(this)));
}

void UOculusXRFaceTrackingComponent::BeginPlay()
{
	Super::BeginPlay();

	if (!UOculusXRMovementFunctionLibrary::IsFaceTrackingSupported())
	{
		// Early exit if face tracking isn't supported
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Face tracking is not supported. (%s:%s)"), *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}

	if (TargetMeshComponentName == NAME_None)
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Invalid mesh component name. (%s:%s)"), *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}

	if (!InitializeFaceTracking())
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Failed to initialize face tracking. (%s:%s)"), *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}

	if (!UOculusXRMovementFunctionLibrary::StartFaceTracking())
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Failed to start face tracking. (%s: %s)"), *GetOwner()->GetName(), *GetName());
		SetComponentTickEnabled(false);
		return;
	}
	++TrackingInstanceCount;
}

void UOculusXRFaceTrackingComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (IsComponentTickEnabled())
	{
		if (--TrackingInstanceCount == 0)
		{
			if (!UOculusXRMovementFunctionLibrary::StopFaceTracking())
			{
				UE_LOG(LogOculusXRMovement, Warning, TEXT("Failed to stop face tracking. (%s: %s)"), *GetOwner()->GetName(), *GetName());
			}
		}
	}

	Super::EndPlay(EndPlayReason);
}

void UOculusXRFaceTrackingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!IsValid(TargetMeshComponent))
	{
		UE_LOG(LogOculusXRMovement, VeryVerbose, TEXT("No target mesh specified. (%s:%s)"), *GetOwner()->GetName(), *GetName());
		return;
	}

	if (UOculusXRMovementFunctionLibrary::TryGetFaceState(FaceState) && bUpdateFace)
	{
		InvalidFaceStateTimer = 0.0f;

		MorphTargets.ResetMorphTargetCurves(TargetMeshComponent);

		for (int32 FaceExpressionIndex = 0; FaceExpressionIndex < static_cast<int32>(EOculusXRFaceExpression::COUNT); ++FaceExpressionIndex)
		{
			if (ExpressionValid[FaceExpressionIndex])
			{
				FName ExpressionName = ExpressionNames[static_cast<EOculusXRFaceExpression>(FaceExpressionIndex)];
				MorphTargets.SetMorphTarget(ExpressionName, FaceState.ExpressionWeights[FaceExpressionIndex]);
			}
		}

		if (bUseModifiers)
		{
			for (int32 FaceExpressionModifierIndex = 0; FaceExpressionModifierIndex < ExpressionModifiers.Num(); ++FaceExpressionModifierIndex)
			{
				for (int32 FaceExpressionIndex = 0; FaceExpressionIndex < ExpressionModifiers[FaceExpressionModifierIndex].FaceExpressions.Num(); ++FaceExpressionIndex)
				{
					auto Expression = ExpressionModifiers[FaceExpressionModifierIndex].FaceExpressions[FaceExpressionIndex];
					if (ExpressionValid[static_cast<int32>(Expression)])
					{
						FName ExpressionName = ExpressionNames[Expression];
						float currentValue = MorphTargets.GetMorphTarget(ExpressionName);

						currentValue = FMath::Clamp(
							currentValue * ExpressionModifiers[FaceExpressionModifierIndex].Multiplier,
							ExpressionModifiers[FaceExpressionModifierIndex].MinValue,
							ExpressionModifiers[FaceExpressionModifierIndex].MaxValue);

						MorphTargets.SetMorphTarget(ExpressionName, currentValue);
					}
				}
			}
		}
	}
	else
	{
		InvalidFaceStateTimer += DeltaTime;
		if (InvalidFaceStateTimer >= InvalidFaceDataResetTime)
		{
			MorphTargets.ResetMorphTargetCurves(TargetMeshComponent);
		}
	}

	MorphTargets.ApplyMorphTargets(TargetMeshComponent);
}

void UOculusXRFaceTrackingComponent::SetExpressionValue(EOculusXRFaceExpression Expression, float Value)
{
	if (Expression >= EOculusXRFaceExpression::COUNT)
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Cannot set expression value with invalid expression index."));
		return;
	}

	if (!ExpressionValid[static_cast<int32>(Expression)])
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Cannot set expression value for an expression with an invalid associated morph target name. Expression name: %s"), *StaticEnum<EOculusXRFaceExpression>()->GetValueAsString(Expression));
		return;
	}

	FName ExpressionName = ExpressionNames[Expression];
	MorphTargets.SetMorphTarget(ExpressionName, Value);
}

float UOculusXRFaceTrackingComponent::GetExpressionValue(EOculusXRFaceExpression Expression) const
{
	if (Expression >= EOculusXRFaceExpression::COUNT)
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Cannot request expression value using an invalid expression index."));
		return 0.0f;
	}

	FName ExpressionName = ExpressionNames[Expression];
	if (ExpressionName == NAME_None)
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Cannot request expression value for an expression with an invalid associated morph target name. Expression name: %s"), *StaticEnum<EOculusXRFaceExpression>()->GetValueAsString(Expression));
		return 0.0f;
	}

	return MorphTargets.GetMorphTarget(ExpressionName);
}

void UOculusXRFaceTrackingComponent::ClearExpressionValues()
{
	MorphTargets.ClearMorphTargets();
}

bool UOculusXRFaceTrackingComponent::InitializeFaceTracking()
{
	TargetMeshComponent = OculusXRUtility::FindComponentByName<USkinnedMeshComponent>(GetOwner(), TargetMeshComponentName);

	if (!IsValid(TargetMeshComponent))
	{
		UE_LOG(LogOculusXRMovement, Warning, TEXT("Could not find skeletal mesh component with name: (%s). (%s:%s)"), *TargetMeshComponentName.ToString(), *GetOwner()->GetName(), *GetName());
		return false;
	}

	if (TargetMeshComponent != nullptr)
	{
		USkeletalMesh* TargetMesh = Cast<USkeletalMesh>(TargetMeshComponent->GetSkinnedAsset());
		if (TargetMesh != nullptr)
		{
			const TMap<FName, int32>& MorphTargetIndexMap = TargetMesh->GetMorphTargetIndexMap();

			for (const auto& it : ExpressionNames)
			{
				ExpressionValid[static_cast<int32>(it.Key)] = MorphTargetIndexMap.Contains(it.Value);
			}

			return true;
		}
	}

	return false;
}
