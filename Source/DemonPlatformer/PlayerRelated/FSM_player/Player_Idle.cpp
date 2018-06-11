// Fill out your copyright notice in the Description page of Project Settings.

#include "Player_Idle.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"

Player_Idle::Player_Idle()
{
}

Player_Idle::~Player_Idle()
{
}

void Player_Idle::Enter(APlayerClass &p)
{
	
	p._flipbook->SetFlipbook(p.flip_walking);
	p._flipbook->Play();
}

Player_State* Player_Idle::handleInput(APlayerClass &p, UInputComponent* PlayerInputComponent)
{
	player = &p;
	if (PlayerInputComponent->GetAxisValue("MoveRight"))
	{
		return new Player_Walking();
	}

	if(p.GetVelocity().Z < 0)
	{
		return new Player_Falling();
	}

	if (p.touched == true)
	{
		return new Player_Jumping();
	}
	return nullptr;
}