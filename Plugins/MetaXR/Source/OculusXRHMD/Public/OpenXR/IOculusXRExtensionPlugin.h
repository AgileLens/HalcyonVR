// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once
#include "IOpenXRExtensionPlugin.h"

class IOculusXRExtensionPlugin : public IOpenXRExtensionPlugin
{
public:
	void RegisterOpenXRExtensionPlugin()
	{
#if defined(WITH_OCULUS_BRANCH)
		RegisterOpenXRExtensionModularFeature();
#endif
	}
};
