// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/WuXiaTargetType.h"


void UWuXiaTargetType::GetTargets_Implementation(AWuXiaCharacterBase* TargetingCharacter, AActor* TargetingActor,
                                                 FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const
{
}

void UWuXiaTargetType_UseOwner::GetTargets_Implementation(AWuXiaCharacterBase* TargetingCharacter,
	AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults,
	TArray<AActor*>& OutActors) const
{
	Super::GetTargets_Implementation(TargetingCharacter, TargetingActor, EventData, OutHitResults, OutActors);
}
