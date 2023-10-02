// Fill out your copyright notice in the Description page of Project Settings.

#include "WuXiaGameInstanceBase.h"
#include "WuXiaSaveGame.h"
#include "Kismet/GameplayStatics.h"

UWuXiaGameInstanceBase::UWuXiaGameInstanceBase()
	: SaveUserIndex(0)
	, SaveSlotName(TEXT("SaveGame"))
{}

void UWuXiaGameInstanceBase::GetDefaultItems(UWuXiaSaveGame* SaveGame, bool bRemoveExtra)
{
	// If we want to remove extra, clear out the existing inventory
	if (bRemoveExtra)
	{
		SaveGame->InventoryData.Reset();
	}

	// Now add the default inventory, this only adds if not already in the inventory
	for (const TPair<FPrimaryAssetId, FWuXiaItemData>& Pair : DefaultInventory)
	{
		if (!SaveGame->InventoryData.Contains(Pair.Key))
		{
			SaveGame->InventoryData.Add(Pair.Key, Pair.Value);
		}
	}
}

bool UWuXiaGameInstanceBase::IsValidItemSlot(FWuXiaItemSlot ItemSlot) const
{
	if (ItemSlot.IsValid())
	{
		const int32* FoundCount = ItemSlotsPerType.Find(ItemSlot.ItemType);

		if (FoundCount)
		{
			return ItemSlot.SlotNumber < *FoundCount;
		}
	}
	return false;
}

UWuXiaSaveGame* UWuXiaGameInstanceBase::GetCurrentSaveGame()
{
	return CurrentSaveGame;
}

void UWuXiaGameInstanceBase::SetSavingEnabled(bool bEnabled)
{
	bSavingEnabled = bEnabled;
}

bool UWuXiaGameInstanceBase::LoadOrCreateSaveGame()
{
	UWuXiaSaveGame* LoadedSave = nullptr;

	if (UGameplayStatics::DoesSaveGameExist(SaveSlotName, SaveUserIndex) && bSavingEnabled)
	{
		LoadedSave = Cast<UWuXiaSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, SaveUserIndex));
	}

	return HandleSaveGameLoaded(LoadedSave);
}

bool UWuXiaGameInstanceBase::HandleSaveGameLoaded(USaveGame* SaveGameObject)
{
	bool bLoaded = false;

	if (!bSavingEnabled)
	{
		// If saving is disabled, ignore passed in object
		SaveGameObject = nullptr;
	}

	// Replace current save, old object will GC out
	CurrentSaveGame = Cast<UWuXiaSaveGame>(SaveGameObject);

	if (CurrentSaveGame)
	{
		// Make sure it has any newly added default inventory
		GetDefaultItems(CurrentSaveGame, false);
		bLoaded = true;
	}
	else
	{
		// This creates it on demand
		CurrentSaveGame = Cast<UWuXiaSaveGame>(UGameplayStatics::CreateSaveGameObject(UWuXiaSaveGame::StaticClass()));

		GetDefaultItems(CurrentSaveGame, true);
	}

	OnSaveGameLoaded.Broadcast(CurrentSaveGame);
	OnSaveGameLoadedNative.Broadcast(CurrentSaveGame);

	return bLoaded;
}

void UWuXiaGameInstanceBase::GetSaveSlotInfo(FString& SlotName, int32& UserIndex) const
{
	SlotName = SaveSlotName;
	UserIndex = SaveUserIndex;
}

bool UWuXiaGameInstanceBase::WriteSaveGame()
{
	if (bSavingEnabled)
	{
		if (bCurrentlySaving)
		{
			// Schedule another save to happen after current one finishes. We only queue one save
			bPendingSaveRequested = true;
			return true;
		}

		// Indicate that we're currently doing an async save
		bCurrentlySaving = true;

		// This goes off in the background
		UGameplayStatics::AsyncSaveGameToSlot(GetCurrentSaveGame(), SaveSlotName, SaveUserIndex, FAsyncSaveGameToSlotDelegate::CreateUObject(this, &UWuXiaGameInstanceBase::HandleAsyncSave));
		return true;
	}
	return false;
}

void UWuXiaGameInstanceBase::ResetSaveGame()
{
	// Call handle function with no loaded save, this will reset the data
	HandleSaveGameLoaded(nullptr);
}

void UWuXiaGameInstanceBase::HandleAsyncSave(const FString& SlotName, const int32 UserIndex, bool bSuccess)
{
	ensure(bCurrentlySaving);
	bCurrentlySaving = false;

	if (bPendingSaveRequested)
	{
		// start another save as we got a request while saving
		bPendingSaveRequested = false;
		WriteSaveGame();
	}
}
