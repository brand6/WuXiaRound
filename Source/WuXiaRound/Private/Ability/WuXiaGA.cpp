// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability\WuXiaGA.h"
#include "Ability/WuXiaTargetType.h"
#include "WuXiaCharacterBase.h"
#include "Ability\WuXiaGEContainer.h"
#include "Ability/WuXiaASC.h"

FWuXiaGEContainerSpec UWuXiaGA::MakeGEContainerSpec(const FWuXiaGEContainer& GEContainer,const FGameplayEventData& EventData, int32 GALevel)
{
	FWuXiaGEContainerSpec GEContainerSpec;
	
	AActor* OwningActor = GetOwningActorFromActorInfo();
	AWuXiaCharacterBase* OwningCharacter = Cast<AWuXiaCharacterBase>(OwningActor);
	UWuXiaASC* OwningASC = UWuXiaASC::GetASCFromActor(OwningActor);

	if(OwningASC)
	{
		if(GEContainer.TargetType.Get())
		{
			
		}
	}
	return GEContainerSpec;
}

TArray<FActiveGameplayEffectHandle> UWuXiaGA::ApplyGEContainerSpec(const FWuXiaGEContainerSpec& GEContainerSpec)
{
	TArray<FActiveGameplayEffectHandle> ActiveGEHandles;
	for(const FGameplayEffectSpecHandle& GESpecHandle : GEContainerSpec.GESpecHandles)
	{
		ActiveGEHandles.Append(K2_ApplyGameplayEffectSpecToTarget(GESpecHandle,GEContainerSpec.TargetData));
	}
	return ActiveGEHandles;
}

FWuXiaGEContainerSpec UWuXiaGA::MakeGEContainerSpecWithTag(FGameplayTag Tag, const FGameplayEventData& EventData,
	int32 GALevel)
{
	FWuXiaGEContainer* GEContainer = TagToGEContainerMap.Find(Tag);
	if (GEContainer)
	{
		return MakeGEContainerSpec(*GEContainer,EventData,GALevel);
	}
	return FWuXiaGEContainerSpec();
}

TArray<FActiveGameplayEffectHandle> UWuXiaGA::ApplyGEContainerSpecWithTag(FGameplayTag Tag,const FGameplayEventData& EventData, int32 GALevel)
{
	FWuXiaGEContainerSpec GEContainerSpec = MakeGEContainerSpecWithTag(Tag,EventData,GALevel);
	return ApplyGEContainerSpec(GEContainerSpec);
}
