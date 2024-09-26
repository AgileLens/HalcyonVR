// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreTypes.h"
#include "OculusXRAnchorTypes.h"
#include "OculusXRSceneTypes.h"
#include "Delegates/Delegate.h"

class OCULUSXRSCENE_API FOculusXRSceneEventDelegates
{
public:

	DECLARE_MULTICAST_DELEGATE_OneParam(FOculusXRBoundaryVisibilityChanged, EOculusXRBoundaryVisibility /*Visibility*/);
	static FOculusXRBoundaryVisibilityChanged OculusBoundaryVisibilityChanged;
};
