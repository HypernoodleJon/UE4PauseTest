// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PauseTest : ModuleRules
{
	public PauseTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "Slate" });
	}
}
