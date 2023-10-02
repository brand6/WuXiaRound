// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability\WuXiaASC.h"
#include "Ability\WuXiaGA.h"
#include "AbilitySystemGlobals.h"

void UWuXiaASC::GetActiveAbilitiesWithTags(const FGameplayTagContainer& TagContainer,TArray<UWuXiaGA*>& ActiveAbilities)
{
	TArray<FGameplayAbilitySpec*> ActiveAbilitySpecs;
	GetActivatableGameplayAbilitySpecsByAllMatchingTags(TagContainer,ActiveAbilitySpecs,false);

	for(FGameplayAbilitySpec* Spec : ActiveAbilitySpecs)
	{
		TArray<UGameplayAbility*> AbilityInstances = Spec->GetAbilityInstances();
		for(UGameplayAbility* Ability : AbilityInstances)
		{
			ActiveAbilities.Add(Cast<UWuXiaGA>(Ability));
		}
	}
}

int32 UWuXiaASC::GetDefaultAbilityLevel() const
{
	return 1;
}

UWuXiaASC* UWuXiaASC::GetASCFromActor(const AActor* Actor, bool LookForComponent)
{
	return Cast<UWuXiaASC>(UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor,LookForComponent));
}
