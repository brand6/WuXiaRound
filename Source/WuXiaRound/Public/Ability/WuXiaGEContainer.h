// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WuXiaRound.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "wuxiaGEContainer.generated.h"


class UGameplayEffect;
class UWuXiaTargetType;

/**
 * 包含TArray<GE>和TargetType
 */
USTRUCT(BlueprintType)
struct FWuXiaGEContainer
{
	GENERATED_BODY()

	FWuXiaGEContainer(){}

	//设置目标查找的方式
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=GameplayEffectContainer)
	TSubclassOf<UWuXiaTargetType> TargetType;

	//应用于目标的游戏效果列表
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=GameplayEffectContainer)
	TArray<TSubclassOf<UGameplayEffect>> GEClasses;
};

/**
 * 包含TArray<GESpecHandle>和TargetData
 */
USTRUCT(BlueprintType)
struct FWuXiaGEContainerSpec
{
	GENERATED_BODY()

	FWuXiaGEContainerSpec(){}

	// 目标数据
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=GameplayEffectContainer)
	FGameplayAbilityTargetDataHandle TargetData;

	// 应用于目标的游戏效果列表
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=GameplayEffectContainer)
	TArray<FGameplayEffectSpecHandle> GESpecHandles;

	// 如果这有任何有效的效果Spec，则返回 true
	bool HasValidEffect() const;

	// 如果它有任何有效的目标，则返回 true
	bool HasValidTargets() const;

	// 把命中目标和指定目标添加到TargetData
	void AddTargets(const TArray<FHitResult>& HitResults,const TArray<AActor*>& TargetActors);
};
