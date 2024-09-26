// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOculusXRPassthrough_init() {}
	OCULUSXRPASSTHROUGH_API UFunction* Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature();
	OCULUSXRPASSTHROUGH_API UFunction* Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_LayerResumed_Single__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_OculusXRPassthrough;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_OculusXRPassthrough()
	{
		if (!Z_Registration_Info_UPackage__Script_OculusXRPassthrough.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_AnyLayerResumed__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_OculusXRPassthrough_OculusXRPassthrough_LayerResumed_Single__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/OculusXRPassthrough",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x2F045F70,
				0x4EEAAF76,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_OculusXRPassthrough.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_OculusXRPassthrough.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_OculusXRPassthrough(Z_Construct_UPackage__Script_OculusXRPassthrough, TEXT("/Script/OculusXRPassthrough"), Z_Registration_Info_UPackage__Script_OculusXRPassthrough, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x2F045F70, 0x4EEAAF76));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
