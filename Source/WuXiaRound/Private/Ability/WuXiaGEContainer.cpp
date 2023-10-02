// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/WuXiaGEContainer.h"



bool FWuXiaGEContainerSpec::HasValidEffect() const
{
	return GESpecHandles.Num()>0;
}

bool FWuXiaGEContainerSpec::HasValidTargets() const
{
	return TargetData.Num()>0;
}

void FWuXiaGEContainerSpec::AddTargets(const TArray<FHitResult>& HitResults, const TArray<AActor*>& TargetActors)
{
	
}
