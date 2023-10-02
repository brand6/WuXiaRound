// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WuXiaRound.h"
#include "AbilitySystemInterface.h"
#include "GenericTeamAgentInterface.h"
#include "Ability/BattleAttributeSet.h"
#include "Ability/WuXiaASC.h"
#include "GameFramework/Character.h"
#include "WuXiaCharacterBase.generated.h"

class UWuXiaGameplayAbility;
class UGameplayEffect;

/**
 * 
 */
UCLASS()
class WUXIAROUND_API AWuXiaCharacterBase : public ACharacter,public IAbilitySystemInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	AWuXiaCharacterBase();

	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
	virtual void OnRep_Controller() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	UFUNCTION(BlueprintCallable)
	virtual void SetCharacterLevel(int32 NewLevel) ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetCharacterLevel() const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetCharacterExp() const ;
	
	UFUNCTION(BlueprintCallable)
	virtual int32 GetShengMing()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetMaxShengMing()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetNeiLi()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetMaxNeiLi()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetNeiLiShuXing()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetGongJi()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetRouJing()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetGangJing()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetSuDu()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetBaoJi()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetBaoShang()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetLianJi()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetFanJi()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetFangYu()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetShanBi()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetJianFaJingTong()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetDaoFaJingTong()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetQuanZhangJingTong()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetZhiZhuaJingTong()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetQiMengJingTong()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetAnQiJingTong()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetNeiShang()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetZhongDu()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetHanDu()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetZhanYi()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetNuQi()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetFenXue()const ;

	UFUNCTION(BlueprintCallable)
	virtual int32 GetXingDong()const ;

protected:
	UPROPERTY(EditAnywhere,Replicated,Category=Abilities)
	int32 CharacterLevel;

	UPROPERTY(EditAnywhere,Replicated,Category=Abilities)
	int32 CharacterExp;

	UPROPERTY()
	UBattleAttributeSet* AttributeSet;

	UPROPERTY()
	UWuXiaASC* AbilitySystemComponent;
};
