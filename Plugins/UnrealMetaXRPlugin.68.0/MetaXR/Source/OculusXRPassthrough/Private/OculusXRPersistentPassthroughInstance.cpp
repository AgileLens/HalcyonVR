// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRPersistentPassthroughInstance.h"
#include "Engine/GameEngine.h"
#include "IStereoLayers.h"
#include "OculusXRPassthroughLayerComponent.h"
#include "TextureResource.h"

void UOculusXRPersistentPassthroughInstance::SetVisible(bool InVisible)
{
	Parameters.bVisible = InVisible;

	UpdateLayer();
}

void UOculusXRPersistentPassthroughInstance::SetPriority(int32 InPriority)
{
	Parameters.Priority = InPriority;

	UpdateLayer();
}

UOculusXRPersistentPassthroughInstance::UOculusXRPersistentPassthroughInstance(const FObjectInitializer& ObjectInitializer)
{
	Parameters.Shape = ObjectInitializer.CreateDefaultSubobject<UOculusXRStereoLayerShapeReconstructed>(this, TEXT("PPT_StereoLayerShapeReconstructed"));
}

void UOculusXRPersistentPassthroughInstance::InitLayer(FOculusXRPersistentPassthroughParameters InParameters)
{
	UpdateParameters(InParameters);
}

void UOculusXRPersistentPassthroughInstance::UpdateParameters(FOculusXRPersistentPassthroughParameters InParameters)
{
#if WITH_EDITOR
	// We need the instance to be the owner of the shape, but in editor the shape still exist and its owner is the BP calling the method.
	// So we clear it to force a new one to be created with LoadShape(this)
	InParameters.Shape = nullptr;
#endif

	if (InParameters.LoadShape(this) == nullptr)
	{
		Parameters.Shape = NewObject<UOculusXRStereoLayerShapeReconstructed>(this, NAME_None, RF_Public);
	}

	Parameters = InParameters;

	UpdateLayer();
}

void UOculusXRPersistentPassthroughInstance::UpdateLayer()
{
	IStereoLayers* StereoLayers;
	if (!GEngine->StereoRenderingDevice.IsValid() || (StereoLayers = GEngine->StereoRenderingDevice->GetStereoLayers()) == nullptr)
	{
		return;
	}

	IStereoLayers::FLayerDesc LayerDesc;
	LayerDesc.Priority = Parameters.Priority;
	LayerDesc.QuadSize = FVector2D(100.f, 100.f);

	LayerDesc.Transform = FTransform::Identity;

	TObjectPtr<class UTexture2D> Texture = GEngine->DefaultTexture;
	if (Texture)
	{
		Texture->SetForceMipLevelsToBeResident(30.0f);
		LayerDesc.Texture = Texture->GetResource()->TextureRHI;
		LayerDesc.Flags |= (Texture->GetMaterialType() == MCT_TextureExternal) ? IStereoLayers::LAYER_FLAG_TEX_EXTERNAL : 0;
	}

	LayerDesc.Flags |= (!Parameters.bVisible) ? IStereoLayers::LAYER_FLAG_HIDDEN : 0;

	LayerDesc.PositionType = IStereoLayers::FaceLocked;

	// Set the correct layer shape and apply any shape-specific properties
	Parameters.Shape->ApplyShape(LayerDesc);

	if (LayerId != IStereoLayers::FLayerDesc::INVALID_LAYER_ID)
	{
		StereoLayers->SetLayerDesc(LayerId, LayerDesc);
	}
	else
	{
		LayerId = StereoLayers->CreateLayer(LayerDesc);
	}

	StereoLayers->MarkTextureForUpdate(LayerId);
}

void UOculusXRPersistentPassthroughInstance::BeginDestroy()
{
	IStereoLayers* StereoLayers;
	if (LayerId != IStereoLayers::FLayerDesc::INVALID_LAYER_ID && GEngine->StereoRenderingDevice.IsValid() && (StereoLayers = GEngine->StereoRenderingDevice->GetStereoLayers()) != nullptr)
	{
		StereoLayers->DestroyLayer(LayerId);
		LayerId = IStereoLayers::FLayerDesc::INVALID_LAYER_ID;
	}

	Super::BeginDestroy();
}

void UOculusXRPersistentPassthroughInstance::OnAnyLayerResumedEvent(int InLayerId)
{
	if (LayerId == InLayerId)
	{
		// Execute all single delegates (added from UOculusXRPassthroughSubsystem::InitializePersistentPassthrough)
		for (const FOculusXRPassthrough_LayerResumed_Single& Delegate : LayerResumedSingleDelegates)
		{
			Delegate.ExecuteIfBound();
		}

		OnLayerResumed.Broadcast();
	}
}

void UOculusXRPersistentPassthroughInstance::AddLayerResumedSingleDelegate(const FOculusXRPassthrough_LayerResumed_Single& Delegate)
{
	if (!Delegate.IsBound())
		return;

	LayerResumedSingleDelegates.Add(Delegate);
}

// Save all of the Shape's properties in temporary properties which can always be serialized
void FOculusXRPersistentPassthroughParameters::ApplyShape()
{
	if (!Shape)
		return;

	TempShape_LayerOrder = Shape->LayerOrder;
	TempShape_TextureOpacityFactor = Shape->TextureOpacityFactor;
	TempShape_bEnableEdgeColor = Shape->bEnableEdgeColor;
	TempShape_EdgeColor = Shape->EdgeColor;
	TempShape_bEnableColorMap = Shape->bEnableColorMap;
	TempShape_ColorMapType = Shape->ColorMapType;
	TempShape_bUseColorMapCurve = Shape->bUseColorMapCurve;
	TempShape_ColorMapCurve = Shape->ColorMapCurve;
	TempShape_Contrast = Shape->Contrast;
	TempShape_Brightness = Shape->Brightness;
	TempShape_Posterize = Shape->Posterize;
	TempShape_Saturation = Shape->Saturation;
	TempShape_LutWeight = Shape->LutWeight;
	TempShape_ColorLUTSource = Shape->ColorLUTSource;
	TempShape_ColorLUTTarget = Shape->ColorLUTTarget;
	TempShape_ColorScale = Shape->ColorScale;
	TempShape_ColorOffset = Shape->ColorOffset;
}

// If Shape doesn't already exists, create a new one and set it up using the temporary properties
UOculusXRStereoLayerShapeReconstructed* FOculusXRPersistentPassthroughParameters::LoadShape(UObject* owner)
{
	if (Shape)
		return Shape;

	UOculusXRStereoLayerShapeReconstructed* NewShape = NewObject<UOculusXRStereoLayerShapeReconstructed>(owner);
	NewShape->LayerOrder = TempShape_LayerOrder;
	NewShape->TextureOpacityFactor = TempShape_TextureOpacityFactor;
	NewShape->bEnableEdgeColor = TempShape_bEnableEdgeColor;
	NewShape->EdgeColor = TempShape_EdgeColor;
	NewShape->bEnableColorMap = TempShape_bEnableColorMap;
	NewShape->ColorMapType = TempShape_ColorMapType;
	NewShape->bUseColorMapCurve = TempShape_bUseColorMapCurve;
	NewShape->ColorMapCurve = TempShape_ColorMapCurve;
	NewShape->Contrast = TempShape_Contrast;
	NewShape->Brightness = TempShape_Brightness;
	NewShape->Posterize = TempShape_Posterize;
	NewShape->Saturation = TempShape_Saturation;
	NewShape->LutWeight = TempShape_LutWeight;
	NewShape->ColorLUTSource = TempShape_ColorLUTSource;
	NewShape->ColorLUTTarget = TempShape_ColorLUTTarget;
	NewShape->ColorScale = TempShape_ColorScale;
	NewShape->ColorOffset = TempShape_ColorOffset;

	Shape = NewShape;

	return Shape;
}
