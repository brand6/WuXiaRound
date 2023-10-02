// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WuXiaRound.h"
#include "AbilitySystemComponent.h"
#include "WuXiaASC.generated.h"

class UWuXiaGA;
/**
 * 
 */
UCLASS()
class WUXIAROUND_API UWuXiaASC : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UWuXiaASC(){}

	//将与标记匹配的当前激活的能力实例存入ActiveAbilities
	void GetActiveAbilitiesWithTags(const FGameplayTagContainer& TagContainer, OUT TArray<UWuXiaGA*>& ActiveAbilities);

	//返回用于能力激活的默认级别，数据获取自角色
	int32 GetDefaultAbilityLevel() const;

	//使用AbilitySystemGlobals的函数从Actor获取ASC（LookForComponent=false只能从实现IAbilitySystemInterface接口的Actor上获取到ASC）
	static UWuXiaASC* GetASCFromActor(const AActor* Actor,bool LookForComponent = false);
};
