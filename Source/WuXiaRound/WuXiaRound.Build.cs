// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class WuXiaRound : ModuleRules
{
	public WuXiaRound(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivatePCHHeaderFile = "Public/WuXiaRound.h";
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "GameplayAbilities"});

		PrivateDependencyModuleNames.AddRange(new string[] {"Slate", "SlateCore", "InputCore", "GameplayAbilities", "GameplayTags", "GameplayTasks", "AIModule" });
        
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
