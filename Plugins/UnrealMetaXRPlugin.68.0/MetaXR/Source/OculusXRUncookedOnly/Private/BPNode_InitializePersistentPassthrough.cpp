// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "BPNode_InitializePersistentPassthrough.h"

#include "OculusXRPassthroughSubsystem.h"
#include "OculusXRPassthroughLayerComponent.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintFunctionNodeSpawner.h"

#define LOCTEXT_NAMESPACE "OculusXRPersistentPassthrough"

// Helper which will store one of the function inputs we excpect BP callable function will have.
struct PPTNode_Helper
{
	static FName ParametersPinName;
};

FName PPTNode_Helper::ParametersPinName(TEXT("Parameters"));

UFunction* UBPNode_InitializePersistentPassthrough::GetFunction() const
{
	return UOculusXRPassthroughSubsystem::StaticClass()->FindFunctionByName(GET_FUNCTION_NAME_CHECKED(UOculusXRPassthroughSubsystem, InitializePersistentPassthrough));
}

UEdGraphPin* UBPNode_InitializePersistentPassthrough::GetParametersPin() const
{
	UEdGraphPin* Pin = FindPin(PPTNode_Helper::ParametersPinName);
	check(Pin == NULL || Pin->Direction == EGPD_Input);
	return Pin;
}

UBPNode_InitializePersistentPassthrough::UBPNode_InitializePersistentPassthrough(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UBPNode_InitializePersistentPassthrough::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	// Post-load validation of the enum type.
	if (Ar.IsLoading() && Ar.IsPersistent() && !Ar.HasAnyPortFlags(PPF_Duplicate | PPF_DuplicateForPIE))
	{
		// If valid, ensure that the shape is loaded.
		if (LayerParameters.Shape != nullptr)
		{
			Ar.Preload(LayerParameters.Shape);
		}
	}
}

void UBPNode_InitializePersistentPassthrough::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	const FName PropertyName = (PropertyChangedEvent.Property ? PropertyChangedEvent.Property->GetFName() : NAME_None);

	// When bShowInputPin changes, reconstruct node to update "Parameters" pin visibility
	if (PropertyName == GET_MEMBER_NAME_CHECKED(UBPNode_InitializePersistentPassthrough, bShowInputPin))
	{
		if (!bShowInputPin)
		{
			UEdGraphPin* TemplatePin = GetParametersPin();
			TemplatePin->BreakAllPinLinks();
		}

		GetSchema()->ReconstructNode(*this);
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void UBPNode_InitializePersistentPassthrough::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
	// We need to manually add this node to the list of blueprint action as the original method is "BlueprintInternalUseOnly"
	UClass* Action = GetClass();
	if (ActionRegistrar.IsOpenForRegistration(Action))
	{
		UBlueprintFunctionNodeSpawner* Spawner = UBlueprintFunctionNodeSpawner::Create(GetClass(), GetFunction());
		check(Spawner != nullptr);

		ActionRegistrar.AddBlueprintAction(Action, Spawner);
	}
}

void UBPNode_InitializePersistentPassthrough::AllocateDefaultPins()
{
	// Initialize Shape so that it's filled at node's creation
	if (!LayerParameters.Shape)
		LayerParameters.Shape = NewObject<UOculusXRStereoLayerShapeReconstructed>(GetBlueprint(), TEXT("PPT_StereoLayerShapeReconstructed"));

	// Set "UOculusXRPassthroughSubsystem::InitializePersistentPassthrough" as the function for this node
	SetFromFunction(GetFunction());

	// Call parent method, which will generate all the pins for the function's parameters (including execute, then & self)
	Super::AllocateDefaultPins();

	// "Parameters" pin visibility depends on bShowInputPin value
	GetParametersPin()->bHidden = !bShowInputPin;
}

void UBPNode_InitializePersistentPassthrough::ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
	ensureAlwaysMsgf(LayerParameters.Shape, TEXT("UBPNode_InitializePersistentPassthrough : Shape is nullptr"));

	// If "bShowInputPin" is set to false, use "LayerParameters" for the pin's default value
	if (!bShowInputPin)
	{
		UScriptStruct* StructType = FOculusXRPersistentPassthroughParameters::StaticStruct();

		// Applies all the shape properties since this node is editor only and LayerParameters.Shape will not available for standalone builds.
		LayerParameters.ApplyShape();

		FString StringValue;
		StructType->ExportText(StringValue, &LayerParameters, nullptr, nullptr, EPropertyPortFlags::PPF_SerializedAsImportText, nullptr);
		GetParametersPin()->GetSchema()->TrySetDefaultValue(*GetParametersPin(), StringValue);
	}

	Super::ExpandNode(CompilerContext, SourceGraph);
}

#undef LOCTEXT_NAMESPACE
