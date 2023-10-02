// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WuXiaRound.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BattleAttributeSet.generated.h"

/**
 * Attribute只能在AttributeSet头文件中定义，
 * 宏会自动为每个Attribute生成getter和setter函数
 */
#define ATTRIBUTE_ACCESSORS(ClassName,PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName,PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class WUXIAROUND_API UBattleAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UBattleAttributeSet();

	//在属性修改前触发，可用于限制属性的CurrentValue变化范围，此处用于处理属性最大值变化时，当前值发生响应的变化
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	//仅在instantGE对属性的BaseValue修改之后触发，这里是处理多个属性效果的合适位置
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadOnly, Category="ShengMing", ReplicatedUsing=OnRep_ShengMing)
	FGameplayAttributeData ShengMing;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, ShengMing)

	UPROPERTY(BlueprintReadOnly, Category="ShengMing", ReplicatedUsing=OnRep_MaxShengMing)
	FGameplayAttributeData MaxShengMing;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, MaxShengMing)

	UPROPERTY(BlueprintReadOnly, Category="NeiLi", ReplicatedUsing=OnRep_NeiLi)
	FGameplayAttributeData NeiLi;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, NeiLi)

	UPROPERTY(BlueprintReadOnly, Category="NeiLi", ReplicatedUsing=OnRep_MaxNeiLi)
	FGameplayAttributeData MaxNeiLi;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, MaxNeiLi)

	UPROPERTY(BlueprintReadOnly, Category="NeiLi", ReplicatedUsing=OnRep_NeiLiShuXing)
	FGameplayAttributeData NeiLiShuXing;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, NeiLiShuXing)

	UPROPERTY(BlueprintReadOnly, Category="GongJi", ReplicatedUsing=OnRep_GongJi)
	FGameplayAttributeData GongJi;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, GongJi)

	UPROPERTY(BlueprintReadOnly, Category="GongJi", ReplicatedUsing=OnRep_RouJing)
	FGameplayAttributeData RouJing;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, RouJing)

	UPROPERTY(BlueprintReadOnly, Category="GongJi", ReplicatedUsing=OnRep_GangJing)
	FGameplayAttributeData GangJing;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, GangJing)

	UPROPERTY(BlueprintReadOnly, Category="GongJi", ReplicatedUsing=OnRep_SuDu)
	FGameplayAttributeData SuDu;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, SuDu)

	UPROPERTY(BlueprintReadOnly, Category="GongJi", ReplicatedUsing=OnRep_BaoJi)
	FGameplayAttributeData BaoJi;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, BaoJi)

	UPROPERTY(BlueprintReadOnly, Category="GongJi", ReplicatedUsing=OnRep_BaoShang)
	FGameplayAttributeData BaoShang;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, BaoShang)

	UPROPERTY(BlueprintReadOnly, Category="GongJi", ReplicatedUsing=OnRep_LianJi)
	FGameplayAttributeData LianJi;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, LianJi)

	UPROPERTY(BlueprintReadOnly, Category="GongJi", ReplicatedUsing=OnRep_FanJi)
	FGameplayAttributeData FanJi;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, FanJi)

	UPROPERTY(BlueprintReadOnly, Category="GongJi", ReplicatedUsing=OnRep_FanJi)
	FGameplayAttributeData FanShang;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, FanShang)

	UPROPERTY(BlueprintReadOnly, Category="FangYu", ReplicatedUsing=OnRep_FangYu)
	FGameplayAttributeData FangYu;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, FangYu)

	UPROPERTY(BlueprintReadOnly, Category="FangYu", ReplicatedUsing=OnRep_ShanBi)
	FGameplayAttributeData ShanBi;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, ShanBi)

	UPROPERTY(BlueprintReadOnly, Category="JingTong", ReplicatedUsing=OnRep_JianFaJingTong)
	FGameplayAttributeData JianFaJingTong;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, JianFaJingTong)

	UPROPERTY(BlueprintReadOnly, Category="JingTong", ReplicatedUsing=OnRep_DaoFaJingTong)
	FGameplayAttributeData DaoFaJingTong;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, DaoFaJingTong)

	UPROPERTY(BlueprintReadOnly, Category="JingTong", ReplicatedUsing=OnRep_QuanZhangJingTong)
	FGameplayAttributeData QuanZhangJingTong;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, QuanZhangJingTong)

	UPROPERTY(BlueprintReadOnly, Category="JingTong", ReplicatedUsing=OnRep_ZhiZhuaJingTong)
	FGameplayAttributeData ZhiZhuaJingTong;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, ZhiZhuaJingTong)

	UPROPERTY(BlueprintReadOnly, Category="JingTong", ReplicatedUsing=OnRep_QiMengJingTong)
	FGameplayAttributeData QiMengJingTong;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, QiMengJingTong)

	UPROPERTY(BlueprintReadOnly, Category="JingTong", ReplicatedUsing=OnRep_AnQiJingTong)
	FGameplayAttributeData AnQiJingTong;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, AnQiJingTong)

	UPROPERTY(BlueprintReadOnly, Category="ZhuangTai", ReplicatedUsing=OnRep_NeiShang)
	FGameplayAttributeData NeiShang;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, NeiShang)

	UPROPERTY(BlueprintReadOnly, Category="ZhuangTai", ReplicatedUsing=OnRep_ZhongDu)
	FGameplayAttributeData ZhongDu;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, ZhongDu)

	UPROPERTY(BlueprintReadOnly, Category="ZhuangTai", ReplicatedUsing=OnRep_HanDu)
	FGameplayAttributeData HanDu;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, HanDu)

	UPROPERTY(BlueprintReadOnly, Category="ZhuangTai", ReplicatedUsing=OnRep_ZhanYi)
	FGameplayAttributeData ZhanYi;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, ZhanYi)

	UPROPERTY(BlueprintReadOnly, Category="ZhuangTai", ReplicatedUsing=OnRep_NuQi)
	FGameplayAttributeData NuQi;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, NuQi)

	UPROPERTY(BlueprintReadOnly, Category="ZhuangTai", ReplicatedUsing=OnRep_FenXue)
	FGameplayAttributeData FenXue;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, FenXue)

	UPROPERTY(BlueprintReadOnly, Category="ZhuangTai", ReplicatedUsing=OnRep_XingDong)
	FGameplayAttributeData XingDong;
	ATTRIBUTE_ACCESSORS(UBattleAttributeSet, XingDong)

protected:
	// 帮助程序函数，用于在关联最大属性更改时按比例调整属性的值。（即当MaxHealth增加时，生命值增加的量保持与以前相同的百分比）
	void AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute,
	                                 const FGameplayAttributeData& MaxAttribute, float NewMaxValue,
	                                 const FGameplayAttribute& AffectedAttributeProperty);

	//这些 OnRep 函数的存在是为了确保在复制期间正确同步能力系统内部表示形式
	UFUNCTION()
	virtual void OnRep_ShengMing(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaxShengMing(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_NeiLi(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaxNeiLi(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_NeiLiShuXing(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_GongJi(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_RouJing(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_GangJing(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_SuDu(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_BaoJi(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_BaoShang(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_LianJi(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FanJi(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FanShang(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FangYu(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ShanBi(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_JianFaJingTong(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_DaoFaJingTong(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_QuanZhangJingTong(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ZhiZhuaJingTong(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_QiMengJingTong(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_AnQiJingTong(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_NeiShang(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ZhongDu(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_HanDu(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_ZhanYi(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_NuQi(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_FenXue(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_XingDong(const FGameplayAttributeData& OldValue);
};
