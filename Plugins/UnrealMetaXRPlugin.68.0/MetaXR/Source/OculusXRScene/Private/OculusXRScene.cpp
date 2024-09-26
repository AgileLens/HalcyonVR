// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRScene.h"
#include "OculusXRSceneModule.h"
#include "OculusXRHMDPrivate.h"
#include "OculusXRHMD.h"
#include "OculusXRPluginWrapper.h"

#define LOCTEXT_NAMESPACE "OculusXRScene"

namespace OculusXRScene
{

	// Requests to change the current boundary visibility
	EOculusXRAnchorResult::Type FOculusXRScene::RequestBoundaryVisibility(EOculusXRBoundaryVisibility NewVisibilityRequest)
	{
		ovrpBoundaryVisibility visibility = ovrpBoundaryVisibility_NotSuppressed;

		switch (NewVisibilityRequest)
		{
			case EOculusXRBoundaryVisibility::Suppressed:
				visibility = ovrpBoundaryVisibility_Suppressed;
				break;
			case EOculusXRBoundaryVisibility::NotSuppressed:
				visibility = ovrpBoundaryVisibility_NotSuppressed;
				break;
			default:
				UE_LOG(LogOculusXRScene, Error, TEXT("RequestBoundaryVisibility -- Unknown boundary visibility value! (%d)"), static_cast<int32>(NewVisibilityRequest));
				return EOculusXRAnchorResult::Failure_InvalidParameter;
		}

		UE_LOG(LogOculusXRScene, Log, TEXT("RequestBoundaryVisibility -- New Visibility Requested (%s)"), *UEnum::GetValueAsString(NewVisibilityRequest));

		auto result = FOculusXRHMDModule::GetPluginWrapper().RequestBoundaryVisibility(visibility);
		auto castedResult = static_cast<EOculusXRAnchorResult::Type>(result);

		if (!OVRP_SUCCESS(result))
		{
			UE_LOG(LogOculusXRScene, Error, TEXT("RequestBoundaryVisibility failed -- Result(%s)"), *UEnum::GetValueAsString(castedResult));
		}

		return castedResult;
	}

	EOculusXRAnchorResult::Type FOculusXRScene::GetBoundaryVisibility(EOculusXRBoundaryVisibility& OutVisibility)
	{
		ovrpBoundaryVisibility visibility = {};
		auto result = FOculusXRHMDModule::GetPluginWrapper().GetBoundaryVisibility(&visibility);
		auto castedResult = static_cast<EOculusXRAnchorResult::Type>(result);

		if (OVRP_SUCCESS(result))
		{
			switch (visibility)
			{
				case ovrpBoundaryVisibility_Suppressed:
					OutVisibility = EOculusXRBoundaryVisibility::Suppressed;
					break;
				case ovrpBoundaryVisibility_NotSuppressed:
					OutVisibility = EOculusXRBoundaryVisibility::NotSuppressed;
					break;
				default:
					OutVisibility = EOculusXRBoundaryVisibility::Invalid;
					UE_LOG(LogOculusXRScene, Error, TEXT("GetBoundaryVisibility -- Unknown boundary visibility value! Value(%d)"), visibility);
					break;
			}
		}
		else
		{
			UE_LOG(LogOculusXRScene, Warning, TEXT("GetBoundaryVisibility -- Failed to get boundary visibility. Result(%s)"), *UEnum::GetValueAsString(castedResult));
		}

		return castedResult;
	}
} // namespace OculusXRScene

#undef LOCTEXT_NAMESPACE
