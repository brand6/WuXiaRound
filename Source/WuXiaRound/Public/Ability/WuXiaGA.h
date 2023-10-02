// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WuXiaRound.h"
#include "Ability/WuXiaGEContainer.h"
#include "Abilities/GameplayAbility.h"
#include "WuXiaGA.generated.h"

/**
 * 使用 GameplayEffectContainers 来允许基于触发标记更轻松地执行游戏效果
 */
UCLASS()
class WUXIAROUND_API UWuXiaGA : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UWuXiaGA(){}

	/** 游戏Tag到GEContainer的映射*/
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category=GameplayEffects)
	TMap<FGameplayTag,FWuXiaGEContainer> TagToGEContainerMap;

	// 根据GEContainer，生成GEContainerSpec
	UFUNCTION(BlueprintCallable,Category=Ability,meta=(AutoCreateRefTerm="EventData"))
	virtual FWuXiaGEContainerSpec MakeGEContainerSpec(const FWuXiaGEContainer& GEContainer,const FGameplayEventData& EventData, int32 GALevel = -1);

	// 使生成的GEContainerSpec生效
	UFUNCTION(BlueprintCallable,Category=Ability)
	virtual TArray<FActiveGameplayEffectHandle> ApplyGEContainerSpec(const FWuXiaGEContainerSpec& GEContainerSpec);

	// 根据Tag索引GEContainer，然后生成GEContainerSpec
	UFUNCTION(BlueprintCallable,Category=Ability,meta=(AutoCreateRefTerm="EventData"))
	virtual FWuXiaGEContainerSpec MakeGEContainerSpecWithTag(FGameplayTag Tag,const FGameplayEventData& EventData, int32 GALevel=-1);
	
	// 根据Tag索引GEContainer，然后生成GEContainerSpec并生效
	UFUNCTION(BlueprintCallable,Category=Ability,meta=(AutoCreateRefTerm="EventData"))
	virtual TArray<FActiveGameplayEffectHandle> ApplyGEContainerSpecWithTag(FGameplayTag Tag,const FGameplayEventData& EventData,int32 GALevel = -1);
};
