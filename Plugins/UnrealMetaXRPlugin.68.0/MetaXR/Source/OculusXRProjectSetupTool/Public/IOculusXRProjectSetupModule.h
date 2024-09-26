// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once
#include "Modules/ModuleManager.h"

//-------------------------------------------------------------------------------------------------
// IOculusXRProjectSetupToolModule
//-------------------------------------------------------------------------------------------------

/**
 * The public interface to this module.
 */
class IOculusXRProjectSetupToolModule : public IModuleInterface
{
public:
	/**
	 * Singleton-like access to this module's interface.  This is just for convenience!
	 * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline IOculusXRProjectSetupToolModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IOculusXRProjectSetupToolModule>("OculusXRProjectSetupTool");
	}

	/** Show the project setup tool window */
	virtual void ShowProjectSetupTool(const FString& Origin) = 0;
};
