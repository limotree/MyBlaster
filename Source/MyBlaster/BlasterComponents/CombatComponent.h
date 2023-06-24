﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MYBLASTER_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()
	// 战斗组件用于处理角色战斗

public:
	// Sets default values for this component's properties
	UCombatComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
	// 友元类
	friend class ABlasterCharacter;
	void EquipWeapon(class AWeapon* WeaponToEquip);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
private:
	// 角色
	ABlasterCharacter* Character;
	// 武器
	AWeapon* EquippedWeapon;

public:

};