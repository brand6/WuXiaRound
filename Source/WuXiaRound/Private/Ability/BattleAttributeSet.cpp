// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/BattleAttributeSet.h"

UBattleAttributeSet::UBattleAttributeSet()
	:ShengMing(0.f),
	MaxShengMing(0.f),
	NeiLi(0.f),
	MaxNeiLi(0.f),
	NeiLiShuXing(0.f),
	GongJi(0.f),
	RouJing(0.f),
	GangJing(0.f),
	SuDu(0.f),
	BaoJi(0.f),
	BaoShang(0.f),
	LianJi(0.f),
	FanJi(0.f),
	FangYu(0.f),
	ShanBi(0.f),
	JianFaJingTong(0.f),
	DaoFaJingTong(0.f),
	QuanZhangJingTong(0.f),
	ZhiZhuaJingTong(0.f),
	QiMengJingTong(0.f),
	AnQiJingTong(0.f),
	NeiShang(0.f),
	ZhongDu(0.f),
	HanDu(0.f),
	ZhanYi(0.f),
	NuQi(0.f),
	FenXue(0.f),
	XingDong(0.f)
{
}

void UBattleAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	//最大生命值变化时，我们希望缩放当前生命以匹配
	if(Attribute == GetMaxShengMingAttribute())
	{
		AdjustAttributeForMaxChange(ShengMing,MaxShengMing,NewValue,GetShengMingAttribute());	
	}

	if(Attribute == GetMaxNeiLiAttribute())
	{
		AdjustAttributeForMaxChange(NeiLi,MaxNeiLi,NewValue,GetNeiLiAttribute());
	}
}

void UBattleAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}


void UBattleAttributeSet::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute,
	const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty)
{
	UAbilitySystemComponent* ASC = GetOwningAbilitySystemComponent();
	const float CurMaxValue = MaxAttribute.GetCurrentValue();
	if (!FMath::IsNearlyEqual(CurMaxValue,NewMaxValue) && ASC)
	{
		const float CurValue = AffectedAttribute.GetCurrentValue();
		float NewDelta = (CurMaxValue > 0.f)?(CurValue*NewMaxValue/CurMaxValue)-CurValue:NewMaxValue;
		ASC->ApplyModToAttributeUnsafe(AffectedAttributeProperty,EGameplayModOp::Additive,NewDelta);
	}
}

void UBattleAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//Attribute需要添加到GetLifetimeReplicatedProps
	DOREPLIFETIME(UBattleAttributeSet,ShengMing);
	DOREPLIFETIME(UBattleAttributeSet,MaxShengMing);
	DOREPLIFETIME(UBattleAttributeSet,NeiLi);
	DOREPLIFETIME(UBattleAttributeSet,MaxNeiLi);
	DOREPLIFETIME(UBattleAttributeSet,NeiLiShuXing);
	DOREPLIFETIME(UBattleAttributeSet,GongJi);
	DOREPLIFETIME(UBattleAttributeSet,RouJing);
	DOREPLIFETIME(UBattleAttributeSet,GangJing);
	DOREPLIFETIME(UBattleAttributeSet,SuDu);
	DOREPLIFETIME(UBattleAttributeSet,BaoJi);
	DOREPLIFETIME(UBattleAttributeSet,BaoShang);
	DOREPLIFETIME(UBattleAttributeSet,LianJi);
	DOREPLIFETIME(UBattleAttributeSet,FanJi);
	DOREPLIFETIME(UBattleAttributeSet,FangYu);
	DOREPLIFETIME(UBattleAttributeSet,ShanBi);
	DOREPLIFETIME(UBattleAttributeSet,JianFaJingTong);
	DOREPLIFETIME(UBattleAttributeSet,DaoFaJingTong);
	DOREPLIFETIME(UBattleAttributeSet,QuanZhangJingTong);
	DOREPLIFETIME(UBattleAttributeSet,ZhiZhuaJingTong);
	DOREPLIFETIME(UBattleAttributeSet,QiMengJingTong);
	DOREPLIFETIME(UBattleAttributeSet,AnQiJingTong);
	DOREPLIFETIME(UBattleAttributeSet,NeiShang);
	DOREPLIFETIME(UBattleAttributeSet,ZhongDu);
	DOREPLIFETIME(UBattleAttributeSet,HanDu);
	DOREPLIFETIME(UBattleAttributeSet,ZhanYi);
	DOREPLIFETIME(UBattleAttributeSet,NuQi);
	DOREPLIFETIME(UBattleAttributeSet,FenXue);
	DOREPLIFETIME(UBattleAttributeSet,XingDong);
}

void UBattleAttributeSet::OnRep_ShengMing(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,ShengMing,OldValue);
}

void UBattleAttributeSet::OnRep_MaxShengMing(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,MaxShengMing,OldValue);
}

void UBattleAttributeSet::OnRep_NeiLi(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,NeiLi,OldValue);
}

void UBattleAttributeSet::OnRep_MaxNeiLi(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,MaxNeiLi,OldValue);
}

void UBattleAttributeSet::OnRep_NeiLiShuXing(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,NeiLiShuXing,OldValue);
}

void UBattleAttributeSet::OnRep_GongJi(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,GongJi,OldValue);
}

void UBattleAttributeSet::OnRep_RouJing(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,RouJing,OldValue);
}

void UBattleAttributeSet::OnRep_GangJing(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,GangJing,OldValue);
}

void UBattleAttributeSet::OnRep_SuDu(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,SuDu,OldValue);
}

void UBattleAttributeSet::OnRep_BaoJi(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,BaoJi,OldValue);
}

void UBattleAttributeSet::OnRep_BaoShang(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,BaoShang,OldValue);
}

void UBattleAttributeSet::OnRep_LianJi(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,LianJi,OldValue);
}

void UBattleAttributeSet::OnRep_FanJi(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,FanJi,OldValue);
}

void UBattleAttributeSet::OnRep_FanShang(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,FanShang,OldValue);
}

void UBattleAttributeSet::OnRep_FangYu(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,FangYu,OldValue);
}

void UBattleAttributeSet::OnRep_ShanBi(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,ShanBi,OldValue);
}

void UBattleAttributeSet::OnRep_JianFaJingTong(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,JianFaJingTong,OldValue);
}

void UBattleAttributeSet::OnRep_DaoFaJingTong(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,DaoFaJingTong,OldValue);
}

void UBattleAttributeSet::OnRep_QuanZhangJingTong(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,QuanZhangJingTong,OldValue);
}

void UBattleAttributeSet::OnRep_ZhiZhuaJingTong(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,ZhiZhuaJingTong,OldValue);
}

void UBattleAttributeSet::OnRep_QiMengJingTong(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,QiMengJingTong,OldValue);
}

void UBattleAttributeSet::OnRep_AnQiJingTong(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,AnQiJingTong,OldValue);
}

void UBattleAttributeSet::OnRep_NeiShang(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,NeiShang,OldValue);
}

void UBattleAttributeSet::OnRep_ZhongDu(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,ZhongDu,OldValue);
}

void UBattleAttributeSet::OnRep_HanDu(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,HanDu,OldValue);
}

void UBattleAttributeSet::OnRep_ZhanYi(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,ZhanYi,OldValue);
}

void UBattleAttributeSet::OnRep_NuQi(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,NuQi,OldValue);
}

void UBattleAttributeSet::OnRep_FenXue(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,FenXue,OldValue);
}

void UBattleAttributeSet::OnRep_XingDong(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBattleAttributeSet,XingDong,OldValue);
}
