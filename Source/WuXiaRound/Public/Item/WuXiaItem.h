// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WuXiaRound.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "WuXiaItem.generated.h"

class UWuXiaGA;

/**
 * 道具的基类
 */
UCLASS(Abstract,BlueprintType)
class WUXIAROUND_API UWuXiaItem : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UWuXiaItem()
		:Price(0),
		bIsConsumable(false),
		MaxCount(1),
		MaxLevel(1),
		AbilityLevel(1)
	{}

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category=Item)
	FPrimaryAssetType ItemType;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Item)
	FText ItemName;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Item)
	FText ItemDescription;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Item)
	FSlateBrush ItemIcon;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Item)
	int32 Price;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Item)
	bool bIsConsumable;

	//可以在背包中堆叠的最大实例数，<= 0 表示无限
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Max)
	int32 MaxCount;
	
	//道具的最大等级，<= 0 表示无限
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Max)
	int32 MaxLevel;

	//道具授予的能力
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Abilities)
	TSubclassOf<UWuXiaGA> GrantedAbility;

	//道具授予的能力等级，当<=0时表示默认等级
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Abilities)
	int32 AbilityLevel;
	
	//获取道具的资产id，重写以使用保存的类型
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

	//返回道具的逻辑名称，等效于资产id
	UFUNCTION(BlueprintCallable,Category=Item)
	FString GetIdentifierString() const;
};
