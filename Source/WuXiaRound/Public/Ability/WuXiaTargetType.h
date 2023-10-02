// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WuXiaRound.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "WuXiaTargetType.generated.h"

class AWuXiaCharacterBase;
struct FGameplayEventData;

/**
 * 它可被当作是游戏内找特定目标的基础类
 */
UCLASS(Blueprintable,meta=(ShowWorldContextPin))
class WUXIAROUND_API UWuXiaTargetType : public UObject
{
	GENERATED_BODY()

public:
	UWuXiaTargetType(){}
	
	//调用以确定要应用游戏效果的目标
	UFUNCTION(BlueprintNativeEvent)
	void GetTargets(AWuXiaCharacterBase* TargetingCharacter,AActor* TargetingActor,FGameplayEventData EventData,
		TArray<FHitResult>& OutHitResults,TArray<AActor*>& OutActors) const;
};

/**
 * 技能目标是使用者自己
 */
UCLASS(NotBlueprintable)
class WUXIAROUND_API UWuXiaTargetType_UseOwner:public UWuXiaTargetType
{
	GENERATED_BODY()
	
public:
	UWuXiaTargetType_UseOwner(){}

	virtual void GetTargets_Implementation(AWuXiaCharacterBase* TargetingCharacter, AActor* TargetingActor,
		FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const override;
};
