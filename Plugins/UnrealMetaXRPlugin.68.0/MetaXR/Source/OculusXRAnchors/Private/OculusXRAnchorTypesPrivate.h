// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once
#include "OculusXRAnchorTypes.h"
#include "OVR_Plugin_Types.h"

ovrpSpaceComponentType ConvertToOvrpComponentType(const EOculusXRSpaceComponentType ComponentType);
EOculusXRSpaceComponentType ConvertToUEComponentType(const ovrpSpaceComponentType ComponentType);
