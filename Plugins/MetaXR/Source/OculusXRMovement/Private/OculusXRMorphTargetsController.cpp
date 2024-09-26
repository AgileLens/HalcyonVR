// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRMorphTargetsController.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMesh.h"

#include "AnimationRuntime.h"

void FOculusXRMorphTargetsController::ResetMorphTargetCurves(USkinnedMeshComponent* TargetMeshComponent)
{
	if (TargetMeshComponent)
	{
		TargetMeshComponent->ActiveMorphTargets.Reset();

		USkeletalMesh* TargetMesh = Cast<USkeletalMesh>(TargetMeshComponent->GetSkinnedAsset());
		if (TargetMesh != nullptr)
		{
			TargetMeshComponent->MorphTargetWeights.SetNum(TargetMesh->GetMorphTargets().Num());

			// we need this code to ensure the buffer gets cleared whether or not you have morphtarget curve set
			// the case, where you had morphtargets weight on, and when you clear the weight, you want to make sure
			// the buffer gets cleared and resized
			if (TargetMeshComponent->MorphTargetWeights.Num() > 0)
			{
				FMemory::Memzero(TargetMeshComponent->MorphTargetWeights.GetData(), TargetMeshComponent->MorphTargetWeights.GetAllocatedSize());
			}
		}
		else
		{
			TargetMeshComponent->MorphTargetWeights.Reset();
		}
	}
}

void FOculusXRMorphTargetsController::ApplyMorphTargets(USkinnedMeshComponent* TargetMeshComponent)
{
	if (TargetMeshComponent != nullptr)
	{
		const USkeletalMesh* TargetMesh = Cast<USkeletalMesh>(TargetMeshComponent->GetSkinnedAsset());
		if (TargetMesh != nullptr && MorphTargetCurves.Num() > 0)
		{
			FAnimationRuntime::AppendActiveMorphTargets(TargetMesh, MorphTargetCurves, TargetMeshComponent->ActiveMorphTargets, TargetMeshComponent->MorphTargetWeights);
		}
	}
}

void FOculusXRMorphTargetsController::SetMorphTarget(FName MorphTargetName, float Value)
{
	float* CurveValPtr = MorphTargetCurves.Find(MorphTargetName);
	bool bShouldAddToList = FPlatformMath::Abs(Value) > ZERO_ANIMWEIGHT_THRESH;
	if (bShouldAddToList)
	{
		if (CurveValPtr)
		{
			// sum up, in the future we might normalize, but for now this just sums up
			// this won't work well if all of them have full weight - i.e. additive
			*CurveValPtr = Value;
		}
		else
		{
			MorphTargetCurves.Add(MorphTargetName, Value);
		}
	}
	// if less than ZERO_ANIMWEIGHT_THRESH
	// no reason to keep them on the list
	else
	{
		// remove if found
		MorphTargetCurves.Remove(MorphTargetName);
	}
}

float FOculusXRMorphTargetsController::GetMorphTarget(FName MorphTargetName) const
{
	const float* CurveValPtr = MorphTargetCurves.Find(MorphTargetName);

	if (CurveValPtr)
	{
		return *CurveValPtr;
	}
	else
	{
		return 0.0f;
	}
}

void FOculusXRMorphTargetsController::ClearMorphTargets()
{
	MorphTargetCurves.Empty();
}
