// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerRelated/PlayerClass.h"
#include "Components/InputComponent.h"

/**
 * 
 */
class DEMONPLATFORMER_API Player_State
{
protected:
	class APlayerClass *player;
public:
	Player_State();
	~Player_State();

	//metoda pt intrarea in claa, in general schimba sprite-u
	virtual void Enter(APlayerClass &);

	//metoda care se ocupa de input
	virtual Player_State* handleInput(APlayerClass &, class UInputComponent* PlayerInputComponent);
};
