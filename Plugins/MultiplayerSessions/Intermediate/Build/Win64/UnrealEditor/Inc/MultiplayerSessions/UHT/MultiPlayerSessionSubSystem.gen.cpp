// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultiplayerSessions/Public/MultiPlayerSessionSubSystem.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultiPlayerSessionSubSystem() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	MULTIPLAYERSESSIONS_API UClass* Z_Construct_UClass_UMultiPlayerSessionSubSystem();
	MULTIPLAYERSESSIONS_API UClass* Z_Construct_UClass_UMultiPlayerSessionSubSystem_NoRegister();
	MULTIPLAYERSESSIONS_API UFunction* Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_MultiplayerSessions();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics
	{
		struct _Script_MultiplayerSessions_eventMultiplayerOnCreateSessionComplete_Parms
		{
			bool bWasSuccessful;
		};
		static void NewProp_bWasSuccessful_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
	{
		((_Script_MultiplayerSessions_eventMultiplayerOnCreateSessionComplete_Parms*)Obj)->bWasSuccessful = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_MultiplayerSessions_eventMultiplayerOnCreateSessionComplete_Parms), &Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::NewProp_bWasSuccessful,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\n//Declaring our own delegates for the Menu Class to bind callbacks to\n//\n" },
#endif
		{ "ModuleRelativePath", "Public/MultiPlayerSessionSubSystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Declaring our own delegates for the Menu Class to bind callbacks to" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_MultiplayerSessions, nullptr, "MultiplayerOnCreateSessionComplete__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::_Script_MultiplayerSessions_eventMultiplayerOnCreateSessionComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::_Script_MultiplayerSessions_eventMultiplayerOnCreateSessionComplete_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MultiplayerSessions_MultiplayerOnCreateSessionComplete__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FMultiplayerOnCreateSessionComplete_DelegateWrapper(const FMulticastScriptDelegate& MultiplayerOnCreateSessionComplete, bool bWasSuccessful)
{
	struct _Script_MultiplayerSessions_eventMultiplayerOnCreateSessionComplete_Parms
	{
		bool bWasSuccessful;
	};
	_Script_MultiplayerSessions_eventMultiplayerOnCreateSessionComplete_Parms Parms;
	Parms.bWasSuccessful=bWasSuccessful ? true : false;
	MultiplayerOnCreateSessionComplete.ProcessMulticastDelegate<UObject>(&Parms);
}
	void UMultiPlayerSessionSubSystem::StaticRegisterNativesUMultiPlayerSessionSubSystem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMultiPlayerSessionSubSystem);
	UClass* Z_Construct_UClass_UMultiPlayerSessionSubSystem_NoRegister()
	{
		return UMultiPlayerSessionSubSystem::StaticClass();
	}
	struct Z_Construct_UClass_UMultiPlayerSessionSubSystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMultiPlayerSessionSubSystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_MultiplayerSessions,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMultiPlayerSessionSubSystem_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMultiPlayerSessionSubSystem_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MultiPlayerSessionSubSystem.h" },
		{ "ModuleRelativePath", "Public/MultiPlayerSessionSubSystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMultiPlayerSessionSubSystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMultiPlayerSessionSubSystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMultiPlayerSessionSubSystem_Statics::ClassParams = {
		&UMultiPlayerSessionSubSystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMultiPlayerSessionSubSystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UMultiPlayerSessionSubSystem_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UMultiPlayerSessionSubSystem()
	{
		if (!Z_Registration_Info_UClass_UMultiPlayerSessionSubSystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMultiPlayerSessionSubSystem.OuterSingleton, Z_Construct_UClass_UMultiPlayerSessionSubSystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMultiPlayerSessionSubSystem.OuterSingleton;
	}
	template<> MULTIPLAYERSESSIONS_API UClass* StaticClass<UMultiPlayerSessionSubSystem>()
	{
		return UMultiPlayerSessionSubSystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMultiPlayerSessionSubSystem);
	UMultiPlayerSessionSubSystem::~UMultiPlayerSessionSubSystem() {}
	struct Z_CompiledInDeferFile_FID_UE5Games_MPTest_Plugins_MultiplayerSessions_Source_MultiplayerSessions_Public_MultiPlayerSessionSubSystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5Games_MPTest_Plugins_MultiplayerSessions_Source_MultiplayerSessions_Public_MultiPlayerSessionSubSystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMultiPlayerSessionSubSystem, UMultiPlayerSessionSubSystem::StaticClass, TEXT("UMultiPlayerSessionSubSystem"), &Z_Registration_Info_UClass_UMultiPlayerSessionSubSystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMultiPlayerSessionSubSystem), 2553320943U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UE5Games_MPTest_Plugins_MultiplayerSessions_Source_MultiplayerSessions_Public_MultiPlayerSessionSubSystem_h_727844753(TEXT("/Script/MultiplayerSessions"),
		Z_CompiledInDeferFile_FID_UE5Games_MPTest_Plugins_MultiplayerSessions_Source_MultiplayerSessions_Public_MultiPlayerSessionSubSystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UE5Games_MPTest_Plugins_MultiplayerSessions_Source_MultiplayerSessions_Public_MultiPlayerSessionSubSystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
