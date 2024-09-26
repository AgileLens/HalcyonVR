// Copyright (c) Meta Platforms, Inc. and affiliates.

#include "OculusXRMovementModule.h"
#include "OculusXRHMDModule.h"
#include "OculusXRMovementLog.h"

#define LOCTEXT_NAMESPACE "OculusXRMovement"

DEFINE_LOG_CATEGORY(LogOculusXRMovement);

//-------------------------------------------------------------------------------------------------
// FOculusXRMovementModule
//-------------------------------------------------------------------------------------------------

FOculusXRMovementModule::FOculusXRMovementModule()
{
}

void FOculusXRMovementModule::StartupModule()
{
}

void FOculusXRMovementModule::ShutdownModule()
{
}

TSharedPtr<ILiveLinkSource> FOculusXRMovementModule::GetLiveLinkSource()
{
	if (!MovementSource.IsValid())
	{
		AddLiveLinkSource();
	}
	return MovementSource;
}

bool FOculusXRMovementModule::IsLiveLinkSourceValid() const
{
	return MovementSource.IsValid();
}

void FOculusXRMovementModule::AddLiveLinkSource()
{
	if (!MovementSource.IsValid())
	{
		MovementSource = MakeShared<MetaXRMovement::LiveLinkSource>();
	}
}

void FOculusXRMovementModule::RemoveLiveLinkSource()
{
	MovementSource.Reset();
}

IMPLEMENT_MODULE(FOculusXRMovementModule, OculusXRMovement)

#undef LOCTEXT_NAMESPACE
