#pragma once

#include "UObject/PrimaryAssetId.h"
#include "WuXiaItemSlotAndData.generated.h"

class UWuXiaItem;
class UWuXiaSaveGame;

/** 表示物品槽位的结构*/
USTRUCT(BlueprintType)
struct WUXIAROUND_API FWuXiaItemSlot
{
	GENERATED_BODY()

	FWuXiaItemSlot()
		:SlotNumber(-1)
	{}
	
	FWuXiaItemSlot(const FPrimaryAssetType& InItemType,int32 InSlotNumber)
		:ItemType(InItemType),SlotNumber(InSlotNumber)
	{}
	
	//可以放入此插槽的道具类型
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Item)
	FPrimaryAssetType ItemType;

	//此插槽的编号，从0索引
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Item)
	int32 SlotNumber;

	//重载==和！=操作符
	bool operator==(const FWuXiaItemSlot& Other)const
	{
		return ItemType == Other.ItemType && SlotNumber == Other.SlotNumber;
	}
	bool operator!=(const FWuXiaItemSlot& Other) const
	{
		return !(*this==Other);
	}

	friend inline uint32 GetTypeHash(const FWuXiaItemSlot& Key)
	{
		uint32 Hash = 0;
		Hash = HashCombine(Hash,GetTypeHash(Key.ItemType));
		Hash = HashCombine(Hash,(uint32)Key.SlotNumber);
		return Hash;
	}

	//如果插槽有效，则返回 true
	bool IsValid() const
	{
		return ItemType.IsValid() && SlotNumber >=0;
	}
};

/**道具的数量和等级信息*/
USTRUCT(BlueprintType)
struct WUXIAROUND_API FWuXiaItemData
{
	GENERATED_BODY()

	FWuXiaItemData()
		:ItemCount(1),ItemLevel(1)
	{}

	FWuXiaItemData(IN int32 InItemCount,IN int32 InItemLevel)
		:ItemCount(InItemCount),ItemLevel(InItemLevel)
	{}

	//道具在背包中的数量
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Item)
	int32 ItemCount;

	//道具的级别
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Item)
	int32 ItemLevel;

	bool operator==(const FWuXiaItemData& Other) const
	{
		return ItemCount==Other.ItemCount && ItemLevel == Other.ItemLevel;
	}
	bool operator!=(const FWuXiaItemData& Other) const
	{
		return !(*this==Other);
	}

	//如果计数大于 0，则返回 true
	bool IsValid() const
	{
		return ItemCount>0;
	}

	//附加道具数据，这将添加计数并覆盖其他所有内容
	void UpdateItemData(const FWuXiaItemData& Other,int32 MaxCount,int32 MaxLevel)
	{
		if(MaxCount <=0)
		{
			MaxCount = MAX_int32;
		}
		if(MaxLevel<=0)
		{
			MaxLevel = MAX_int32;
		}
		ItemCount = FMath::Clamp(ItemCount + Other.ItemCount,1,MaxCount);
		ItemLevel = FMath::Clamp(Other.ItemLevel,1,MaxLevel);
	}
};

//背包内道具数量更改时调用的委托
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWuXiaOnInventoryItemChanged, bool, bAdded, UWuXiaItem*, Item);
DECLARE_MULTICAST_DELEGATE_TwoParams(FWuXiaOnInventoryItemChangedNative, bool, UWuXiaItem*);

//槽位的内容更改时调用的委托
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWuXiaOnSlottedItemChanged, FWuXiaItemSlot, ItemSlot, UWuXiaItem*, Item);
DECLARE_MULTICAST_DELEGATE_TwoParams(FWuXiaOnSlottedItemChangedNative, FWuXiaItemSlot, UWuXiaItem*);

//加载整个背包时调用的委托
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FWuXiaOnInventoryLoaded);
DECLARE_MULTICAST_DELEGATE(FWuXiaOnInventoryLoadedNative);

//加载/重置游戏存档时调用的委托
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWuXiaOnSaveGameLoaded, UWuXiaSaveGame*, SaveGame);
DECLARE_MULTICAST_DELEGATE_OneParam(FWuXiaOnSaveGameLoadedNative, UWuXiaSaveGame*);