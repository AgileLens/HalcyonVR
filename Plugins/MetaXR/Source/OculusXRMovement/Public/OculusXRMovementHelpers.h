// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

namespace OculusXRUtility
{
	template <typename T>
	T* FindComponentByName(AActor* Actor, const FName& ComponentName)
	{
		if (IsValid(Actor) && (ComponentName != NAME_None))
		{
			TArray<T*> ComponentsOfType;
			Actor->GetComponents<T>(ComponentsOfType);
			T** FoundComponent = ComponentsOfType.FindByPredicate([Name = ComponentName.ToString()](T* Component) { return Component->GetName().Equals(Name); });

			if (FoundComponent != nullptr)
			{
				return *FoundComponent;
			}
		}

		return nullptr;
	}
} // namespace OculusXRUtility
