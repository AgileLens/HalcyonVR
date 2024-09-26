// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "Components/SkinnedMeshComponent.h"

/*
 * Struct that allows applying morph targets data to an arbitrary skinned mesh component
 * instead of relying on the skeletal mesh component.
 *
 * Usage - In a tick method of your choosing:
 * 1) ResetMorphTargetCurves(Component) at the start of the update.
 * 2) SetMorphTarget(...) as many times as needed based on your data set.
 * 3) ApplyMorphTargets(Component) at the end of the update to apply the morph targets to the anim runtime.
 */
struct OCULUSXRMOVEMENT_API FOculusXRMorphTargetsController
{
public:
	// Clears active morph targets
	void ResetMorphTargetCurves(USkinnedMeshComponent* TargetMeshComponent);

	// Will apply morph target data to the underlying runtime skeletal mesh
	void ApplyMorphTargets(USkinnedMeshComponent* TargetMeshComponent);

	// Sets a specific morph target value
	void SetMorphTarget(FName MorphTargetName, float Value);

	// Gets a specific morph target value
	float GetMorphTarget(FName MorphTargetName) const;

	// Clears all morph target curves data
	void ClearMorphTargets();

	// List of morph targets on this controller
	TMap<FName, float> MorphTargetCurves;
};
