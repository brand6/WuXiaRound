// Fill out your copyright notice in the Description page of Project Settings.


#include "WuXiaAssetManager.h"
#include "AbilitySystemGlobals.h"
#include "Engine/Engine.h"
#include "Item/WuXiaItem.h"

const FPrimaryAssetType UWuXiaAssetManager::ZhuangBeiItem = TEXT("ZhuangBei");
const FPrimaryAssetType UWuXiaAssetManager::WuXueItem = TEXT("WuXue");
const FPrimaryAssetType UWuXiaAssetManager::HuoBiItem = TEXT("HuoBi");
const FPrimaryAssetType UWuXiaAssetManager::DanYaoItem = TEXT("DanYao");

void UWuXiaAssetManager::StartInitialLoading()
{
	//启动资产的初始加载
	Super::StartInitialLoading();
	//加载全局数据表和Tag
	UAbilitySystemGlobals::Get().InitGlobalData();
}

UWuXiaItem* UWuXiaAssetManager::ForceLoadItem(const FPrimaryAssetId& PrimaryAssetId, bool bLogWarning)
{
	FSoftObjectPath ItemPath = GetPrimaryAssetPath(PrimaryAssetId);
	//可能会加载失败
	UWuXiaItem* LoadItem = Cast<UWuXiaItem>(ItemPath.TryLoad());
	if(bLogWarning && LoadItem == nullptr)
	{
		UE_LOG(LogWuXia,Warning,TEXT("Failed to load item with PrimaryAssetId %s!"), *PrimaryAssetId.ToString());
	}
	return LoadItem;
}

UWuXiaAssetManager& UWuXiaAssetManager::Get()
{
	UWuXiaAssetManager* This = Cast<UWuXiaAssetManager>(GEngine->AssetManager);
	if(This)
	{
		return *This;
	}
	else
	{
		UE_LOG(LogWuXia, Fatal, TEXT("Invalid AssetManager in DefaultEngine.ini, should be WuXiaAssetManager!"));
		return *NewObject<UWuXiaAssetManager>();
	}
}