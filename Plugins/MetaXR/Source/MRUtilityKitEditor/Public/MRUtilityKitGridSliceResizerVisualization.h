// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "ComponentVisualizer.h"

class MRUTILITYKITEDITOR_API FMRUKGridSliceResizerVisualizer : public FComponentVisualizer
{
private:
	virtual void DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI) override;
};
