// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MPTest : ModuleRules
{
	public MPTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput","OnlineSubsystemSteam","OnlineSubsystem" });
	}
}
