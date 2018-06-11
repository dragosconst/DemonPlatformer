// Fill out your copyright notice in the Description page of Project Settings.

#include "Player_Falling.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"

Player_Falling::Player_Falling()
{
}

Player_Falling::~Player_Falling()
{
}

void Player_Falling::Enter(APlayerClass &p)
{

	p.LaunchCharacter(FVector(0, 0, -1500), false, false);

	p._flipbook->SetFlipbook(p.flip_idle);
	p._flipbook->Play();
}
Player_State* Player_Falling::handleInput(APlayerClass &p, UInputComponent* PlayerInputComponent)
{
	player = &p;

	if (p.GetVelocity().Z == 0)
	{
		return new Player_Idle();
	}
	return nullptr;
}