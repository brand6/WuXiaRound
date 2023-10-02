// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WuXiaRound.h"
#include "Engine/AssetManager.h"
#include "WuXiaAssetManager.generated.h"

class UWuXiaItem;

/**
 * 需要在DefaultEngine.ini中设置AssetManagerClassName
 */
UCLASS()
class WUXIAROUND_API UWuXiaAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	UWuXiaAssetManager(){}
	
	// 道具的类型
	static const FPrimaryAssetType ZhuangBeiItem;
	static const FPrimaryAssetType WuXueItem;
	static const FPrimaryAssetType HuoBiItem;
	static const FPrimaryAssetType DanYaoItem;

	//加载资产和全局数据
	virtual void StartInitialLoading() override;
	
	//强制同步加载道具，比较慢且可能失败
	UWuXiaItem* ForceLoadItem(const FPrimaryAssetId& PrimaryAssetId, bool bLogWarning = true);

	static UWuXiaAssetManager& Get();
};
