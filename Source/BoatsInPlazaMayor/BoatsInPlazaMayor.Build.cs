// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class BoatsInPlazaMayor : ModuleRules
{
	public BoatsInPlazaMayor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Niagara" });
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Niagara"));
    }
}
