// Copyright (c) Meta Platforms, Inc. and affiliates.

#pragma once

#include "CoreMinimal.h"
#include "Templates/RefCounting.h"

namespace OculusXRHMD
{

	class FOculusPassthroughMesh : public FRefCountedObject
	{
	public:
		FOculusPassthroughMesh(const TArray<FVector>& InVertices, const TArray<int32>& InTriangles)
			: Vertices(InVertices)
			, Triangles(InTriangles)
		{
		}

		const TArray<FVector>& GetVertices() const { return Vertices; };
		const TArray<int32>& GetTriangles() const { return Triangles; };

	private:
		TArray<FVector> Vertices;
		TArray<int32> Triangles;
	};

	typedef TRefCountPtr<FOculusPassthroughMesh> FOculusPassthroughMeshRef;

} // namespace OculusXRHMD
