// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
// #include "EdGraph/EdGraphNode.h"
// #include "K2Node.h"
#include "K2Node_CallFunction.h"
#include "OculusXRPersistentPassthroughInstance.h"

#include "BPNode_InitializePersistentPassthrough.generated.h"

class FBlueprintActionDatabaseRegistrar;

UCLASS(BlueprintType, Blueprintable)
class OCULUSXRUNCOOKEDONLY_API UBPNode_InitializePersistentPassthrough : public UK2Node_CallFunction
{
	GENERATED_UCLASS_BODY()

	UBPNode_InitializePersistentPassthrough();

	//~ Begin UObject Interface
	virtual void Serialize(FArchive& Ar) override;
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	//~ End UObject Interface

	// Begin UEdGraphNode interface.
	virtual void AllocateDefaultPins() override;
	virtual void ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
	// End UEdGraphNode interface.

	// Begin UK2Node interface
	void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual bool ShouldShowNodeProperties() const override { return true; }
	// End UK2Node interface.

	UFunction* GetFunction() const;
	UEdGraphPin* GetParametersPin() const;

	UPROPERTY(EditAnywhere, Category = "Parameters")
	bool bShowInputPin = false;
	UPROPERTY(EditAnywhere, Category = "Parameters", meta = (EditCondition = "!bShowInputPin"))
	FOculusXRPersistentPassthroughParameters LayerParameters;

protected:
};
