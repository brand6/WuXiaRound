using UnrealBuildTool;

public class WuXiaLoadingScreen : ModuleRules
{
    public WuXiaLoadingScreen(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivatePCHHeaderFile = "Public/WuXiaLoadingScreen.h";
        PCHUsage = ModuleRules.PCHUsageMode.UseSharedPCHs;
        PrivateIncludePaths.Add("WuXiaLoadingScreen/Private");

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Slate",
                "SlateCore", 
                "MoviePlayer",
                "InputCore"
            }
        );
    }
}