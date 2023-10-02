// Fill out your copyright notice in the Description page of Project Settings.


#include "WuXiaCharacterBase.h"

// Sets default values
AWuXiaCharacterBase::AWuXiaCharacterBase()
{
}

void AWuXiaCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void AWuXiaCharacterBase::UnPossessed()
{
	Super::UnPossessed();
}

void AWuXiaCharacterBase::OnRep_Controller()
{
	Super::OnRep_Controller();
}

void AWuXiaCharacterBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

UAbilitySystemComponent* AWuXiaCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AWuXiaCharacterBase::SetCharacterLevel(int32 NewLevel)
{
	if (CharacterLevel != NewLevel)
	{
		CharacterLevel = NewLevel;
	}
}

int32 AWuXiaCharacterBase::GetCharacterLevel() const
{
	return CharacterLevel;
}

int32 AWuXiaCharacterBase::GetCharacterExp() const
{
	return CharacterExp;
}

int32 AWuXiaCharacterBase::GetShengMing() const
{
	return AttributeSet->GetShengMing();
}

int32 AWuXiaCharacterBase::GetMaxShengMing() const
{
	return AttributeSet->GetMaxShengMing();
}

int32 AWuXiaCharacterBase::GetNeiLi() const
{
	return AttributeSet->GetNeiLi();
}

int32 AWuXiaCharacterBase::GetMaxNeiLi() const
{
	return AttributeSet->GetMaxNeiLi();
}

int32 AWuXiaCharacterBase::GetNeiLiShuXing() const
{
	return AttributeSet->GetNeiLiShuXing();
}

int32 AWuXiaCharacterBase::GetGongJi() const
{
	return AttributeSet->GetGongJi();
}

int32 AWuXiaCharacterBase::GetRouJing() const
{
	return AttributeSet->GetRouJing();
}

int32 AWuXiaCharacterBase::GetGangJing() const
{
	return AttributeSet->GetGangJing();
}

int32 AWuXiaCharacterBase::GetSuDu() const
{
	return AttributeSet->GetSuDu();
}

int32 AWuXiaCharacterBase::GetBaoJi() const
{
	return AttributeSet->GetBaoJi();
}

int32 AWuXiaCharacterBase::GetBaoShang() const
{
	return AttributeSet->GetBaoShang();
}

int32 AWuXiaCharacterBase::GetLianJi() const
{
	return AttributeSet->GetLianJi();
}

int32 AWuXiaCharacterBase::GetFanJi() const
{
	return AttributeSet->GetFanJi();
}

int32 AWuXiaCharacterBase::GetFangYu() const
{
	return AttributeSet->GetFangYu();
}

int32 AWuXiaCharacterBase::GetShanBi() const
{
	return AttributeSet->GetShanBi();
}

int32 AWuXiaCharacterBase::GetJianFaJingTong() const
{
	return AttributeSet->GetJianFaJingTong();
}

int32 AWuXiaCharacterBase::GetDaoFaJingTong() const
{
	return AttributeSet->GetDaoFaJingTong();
}

int32 AWuXiaCharacterBase::GetQuanZhangJingTong() const
{
	return AttributeSet->GetQuanZhangJingTong();
}

int32 AWuXiaCharacterBase::GetZhiZhuaJingTong() const
{
	return AttributeSet->GetZhiZhuaJingTong();
}

int32 AWuXiaCharacterBase::GetQiMengJingTong() const
{
	return AttributeSet->GetQiMengJingTong();
}

int32 AWuXiaCharacterBase::GetAnQiJingTong() const
{
	return AttributeSet->GetAnQiJingTong();
}

int32 AWuXiaCharacterBase::GetNeiShang() const
{
	return AttributeSet->GetNeiShang();
}

int32 AWuXiaCharacterBase::GetZhongDu() const
{
	return AttributeSet->GetZhongDu();
}

int32 AWuXiaCharacterBase::GetHanDu() const
{
	return AttributeSet->GetHanDu();
}

int32 AWuXiaCharacterBase::GetZhanYi() const
{
	return AttributeSet->GetZhanYi();
}

int32 AWuXiaCharacterBase::GetNuQi() const
{
	return AttributeSet->GetNuQi();
}

int32 AWuXiaCharacterBase::GetFenXue() const
{
	return AttributeSet->GetFenXue();
}

int32 AWuXiaCharacterBase::GetXingDong() const
{
	return AttributeSet->GetXingDong();
}
