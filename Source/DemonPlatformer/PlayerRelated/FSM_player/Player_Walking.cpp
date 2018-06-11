// Fill out your copyright notice in the Description page of Project Settings.

#include "Player_Walking.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"

Player_Walking::Player_Walking()
{
}

Player_Walking::~Player_Walking()
{
}

void Player_Walking::Enter(APlayerClass &p)
{

	p._flipbook->SetLooping(true);
	p._flipbook->SetFlipbook(p.flip_walking);
	p._flipbook->Play();
}

Player_State * Player_Walking::handleInput(APlayerClass &p, UInputComponent * PlayerInputComponent)
{
	player = &p;

	p.AddMovementInput(p.GetActorForwardVector(), PlayerInputComponent->GetAxisValue("MoveRight"));

	if (PlayerInputComponent->GetAxisValue("MoveRight") < 0)
		p._flipbook->SetRelativeRotation(FQuat(0, 0, 180, 0), false, nullptr, ETeleportType::None);
	else
		p._flipbook->SetRelativeRotation(FQuat(0, 0, 0, 0), false, nullptr, ETeleportType::None);

	if (PlayerInputComponent->GetAxisValue("MoveRight") == 0)
	{
		return new Player_Idle();
	}

	if (p.touched == true)
	{
		return new Player_Jumping();
	}
	return nullptr;
}
