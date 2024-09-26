// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "Modules/ModuleManager.h"

/**
 * The public interface to this module.  In most cases, this interface is only public to sibling modules
 * within this plugin.
 */
class IOculusXRMovementModule : public IModuleInterface
{

public:
	/**
	 * Singleton-like access to this module's interface.  This is just for convenience!
	 * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline IOculusXRMovementModule& Get()
	{
		return FModuleManager::GetModuleChecked<IOculusXRMovementModule>("OculusXRMovement");
	}

	/**
	 * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("OculusXRMovement");
	}

	/**
	 * Returns the LiveLinkSource associated with this IOculusXRMovementModule.
	 *
	 * @return Shared pointer to the Meta MovementSDK source.
	 */
	virtual TSharedPtr<class ILiveLinkSource> GetLiveLinkSource() = 0;

	/**
	 * Checks if the LiveLinkSource has been created.
	 *
	 * @return True if the LiveLinkSource has been created with GetLiveLinkSource or AddLiveLinkSource.
	 */
	virtual bool IsLiveLinkSourceValid() const = 0;

	/**
	 * Make sure Meta MovementSDK Live Link source exist.
	 */
	virtual void AddLiveLinkSource() = 0;

	/**
	 * Destroy Meta MovementSDK Live Link source.
	 */
	virtual void RemoveLiveLinkSource() = 0;
};
