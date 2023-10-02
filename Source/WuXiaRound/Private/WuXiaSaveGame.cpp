// Fill out your copyright notice in the Description page of Project Settings.


#include "WuXiaSaveGame.h"

void UWuXiaSaveGame::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	if(Ar.IsLoading() && SavedDataVersion != EWuXiaSaveGameVersion::LatestVersion)
	{
		if(SavedDataVersion < EWuXiaSaveGameVersion::AddedItemData)
		{
			for(const FPrimaryAssetId& ItemId:InventoryItems_DEPRECATED)
			{
				//将弃用的道具加入到存储数据
				InventoryData.Add(ItemId,FWuXiaItemData(1,1));
			}
			InventoryItems_DEPRECATED.Empty();
		}
		SavedDataVersion=EWuXiaSaveGameVersion::LatestVersion;
	}
}
