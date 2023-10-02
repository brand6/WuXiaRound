// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WuXiaRound.h"
#include "GameFramework/SaveGame.h"
#include "WuXiaSaveGame.generated.h"

namespace EWuXiaSaveGameVersion
{
	enum type
	{
		Initial, // 初始版本
		AddedInventory, 
		AddedItemData, // 存储获得的道具数据
		//-----<new versions must be added before this line>-------------------------------------------------
		VersionPlusOne,
		LatestVersion = VersionPlusOne-1
	};
}

/**
 * 使用数据版本写入和读取游戏存档存档的对象
 */
UCLASS(BlueprintType)
class WUXIAROUND_API UWuXiaSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UWuXiaSaveGame()
	{
		SavedDataVersion = EWuXiaSaveGameVersion::LatestVersion;
	}
	
	//背包内的道具和及其数量和等级
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category=SaveGame)
	TMap<FPrimaryAssetId,FWuXiaItemData> InventoryData;

	//槽位内的道具
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category=SaveGame)
	TMap<FWuXiaItemSlot,FPrimaryAssetId> SlottedItems;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category=SaveGame)
	FString UserId;

protected:
	//保存存档时的最新版本
	UPROPERTY()
	int32 SavedDataVersion;

	//存储已弃用的道具列表
	UPROPERTY()
	TArray<FPrimaryAssetId> InventoryItems_DEPRECATED;

	//可以重写它来修正版本相关问题
	virtual void Serialize(FArchive& Ar) override;	
};