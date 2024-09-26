// @lint-ignore-every LICENSELINT
// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "IOculusXRInputModule.h"
#include "IInputDevice.h"
#include "Templates/SharedPointer.h"

#define LOCTEXT_NAMESPACE "OculusXRInput"

//-------------------------------------------------------------------------------------------------
// FOculusXRInputModule
//-------------------------------------------------------------------------------------------------

#if OCULUS_INPUT_SUPPORTED_PLATFORMS

namespace OculusXRInput
{
	class FOculusXRInput;
}

class FOculusXRInputModule : public IOculusXRInputModule
{
	TWeakPtr<OculusXRInput::FOculusXRInput> OculusXRInputDevice;

	// IInputDeviceModule overrides
	virtual void StartupModule() override;
	virtual TSharedPtr<class IInputDevice> CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) override;

	// IOculusXRInputModule overrides
	virtual uint32 GetNumberOfTouchControllers() const override;
	virtual uint32 GetNumberOfHandControllers() const override;
	virtual TSharedPtr<IInputDevice> GetInputDevice() const override;
};

#else //	OCULUS_INPUT_SUPPORTED_PLATFORMS

class FOculusXRInputModule : public FDefaultModuleImpl
{
	virtual uint32 GetNumberOfTouchControllers() const
	{
		return 0;
	};

	virtual uint32 GetNumberOfHandControllers() const
	{
		return 0;
	};
};

#endif // OCULUS_INPUT_SUPPORTED_PLATFORMS

#undef LOCTEXT_NAMESPACE
