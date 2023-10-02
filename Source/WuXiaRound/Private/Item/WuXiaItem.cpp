// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/WuXiaItem.h"

FPrimaryAssetId UWuXiaItem::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(ItemType,GetFName());
}

FString UWuXiaItem::GetIdentifierString() const
{
	return GetPrimaryAssetId().ToString();
}
