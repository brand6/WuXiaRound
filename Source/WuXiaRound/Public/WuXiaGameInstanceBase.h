// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WuXiaRound.h"
#include "Engine/GameInstance.h"
#include "WuXiaItemSlotAndData.h"
#include "WuXiaGameInstanceBase.generated.h"


/**
 * 
 */
UCLASS()
class WUXIAROUND_API UWuXiaGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()

public:
	UWuXiaGameInstanceBase();
	
	//用户索引
	UPROPERTY(BlueprintReadWrite,Category=Save)
	int32 SaveUserIndex;
	
	//存档名称
	UPROPERTY(BlueprintReadWrite,Category=Save)
	FString SaveSlotName;

	//新玩家默认获得的物品列表
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Inventory)
	TMap<FPrimaryAssetId,FWuXiaItemData> DefaultInventory;

	//可装备的每种类型的物品数量
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Inventory)
	TMap<FPrimaryAssetType,int32> ItemSlotsPerType;	

	//加载游戏存档时调用的委托
	UPROPERTY(BlueprintAssignable,Category=Inventory)
	FWuXiaOnSaveGameLoaded OnSaveGameLoaded;
	//加载或重置游戏存档时的native版本委托
	FWuXiaOnSaveGameLoadedNative OnSaveGameLoadedNative;
	
	//获取默认清单内的道具
	UFUNCTION(BlueprintCallable,Category=Inventory)
	void GetDefaultItems(UWuXiaSaveGame* SaveGame,bool bRemoveExtra = false);

	//如果这是有效的库存槽，则返回 true
	UFUNCTION(BlueprintCallable,Category=Inventory)
	bool IsValidItemSlot(FWuXiaItemSlot ItemSlot) const;

	//返回当前保存的游戏，以便可用于初始化状态。在调用 WriteSaveGame 之前不会写入更改
	UFUNCTION(BlueprintCallable,Category=Save)
	UWuXiaSaveGame* GetCurrentSaveGame();

	//启用设置而不是保存/加载。如果禁用，它将始终计为新角色
	UFUNCTION(BlueprintCallable,Category=Save)
	void SetSavingEnabled(bool bEnabled);

	//同步加载存档游戏。如果失败，它将为您创建一个新的。如果已加载，则返回 true，如果已创建，则返回 false
	UFUNCTION(BlueprintCallable,Category=Save)
	bool LoadOrCreateSaveGame();

	//处理使用 AsyncLoadGameFromSlot 加载 USaveGame 对象后所需的最终设置。如果已加载，则返回 true，如果已创建，则返回 false。
	UFUNCTION(BlueprintCallable,Category=Save)
	bool HandleSaveGameLoaded(USaveGame* SaveGameObject);

	//获取用于库存保存的保存游戏槽和用户索引，准备传递给 GameplayStatics 保存函数
	UFUNCTION(BlueprintCallable,Category=Save)
	void GetSaveSlotInfo(FString& SlotName,int32& UserIndex) const;

	//将当前保存的游戏对象写入磁盘。保存到磁盘发生在后台线程中
	UFUNCTION(BlueprintCallable,Category=Save)
	bool WriteSaveGame();

	//将当前游戏存档重置为默认值。这将删除玩家数据！这不会保存到磁盘，直到下一个 WriteSaveGame
	UFUNCTION(BlueprintCallable,Category=Save)
	void ResetSaveGame();

protected:
	//当前保存的游戏对象
	UPROPERTY()
	UWuXiaSaveGame* CurrentSaveGame;

	//它是否将尝试实际保存到磁盘
	UPROPERTY()
	bool bSavingEnabled;

	//如果我们正在进行保存，则为真
	UPROPERTY()
	bool bCurrentlySaving;

	//如果在保存期间请求了另一个保存，则为 True
	UPROPERTY()
	bool bPendingSaveRequested;

	//发生异步保存时调用
	virtual void HandleAsyncSave(const FString& SlotName,const int32 UserIndex,bool bSuccess);
};
