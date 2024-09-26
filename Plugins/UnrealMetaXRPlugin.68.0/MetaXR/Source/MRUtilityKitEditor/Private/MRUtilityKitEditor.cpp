// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "MRUtilityKitEditor.h"

#include "MRUtilityKitGridSliceResizer.h"
#include "MRUtilityKitGridSliceResizerVisualization.h"
#include "MRUtilityKitTelemetry.h"
#include "UnrealEdGlobals.h"
#include "Editor/UnrealEdEngine.h"

#define LOCTEXT_NAMESPACE "FMRUKEditorModule"

DEFINE_LOG_CATEGORY(LogMRUKEditor);

void FMRUKEditorModule::StartupModule()
{
	OculusXRTelemetry::IfActiveThen([]() {
		MRUKTelemetry::FLoadPluginMarker().Start().End(OculusXRTelemetry::EAction::Success);
	});

	if (GUnrealEd)
	{
		const auto ResizerVisualizer = MakeShared<FMRUKGridSliceResizerVisualizer>();
		GUnrealEd->RegisterComponentVisualizer(UMRUKGridSliceResizerComponent::StaticClass()->GetFName(), ResizerVisualizer);
		ResizerVisualizer->OnRegister();
	}
}

void FMRUKEditorModule::ShutdownModule()
{
	if (GUnrealEd)
	{
		GUnrealEd->UnregisterComponentVisualizer(UMRUKGridSliceResizerComponent::StaticClass()->GetFName());
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMRUKEditorModule, MRUtilityKit)
