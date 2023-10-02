#pragma once

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class IWuXiaLoadingScreenModule : public IModuleInterface
{
public:
    /** Loads the module so it can be turned on */
    static inline IWuXiaLoadingScreenModule& Get()
    {
        return FModuleManager::LoadModuleChecked<IWuXiaLoadingScreenModule>("WuXiaLoadingScreen");
    }

    /** Kicks off the loading screen for in game loading (not startup) */
    virtual void StartInGameLoadingScreen(bool bPlayUntilStopped, float PlayTime) = 0;

    /** Stops the loading screen */
    virtual void StopInGameLoadingScreen() = 0;
};
