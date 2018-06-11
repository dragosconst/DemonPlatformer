// Fill out your copyright notice in the Description page of Project Settings.

#include "Player_Jumping.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"

Player_Jumping::Player_Jumping()
{
}

Player_Jumping::~Player_Jumping()
{
}

void Player_Jumping::Enter(APlayerClass &p)
{
	Player_State::Enter(p);

	p.LaunchCharacter(FVector(player->GetVelocity().X, player->GetVelocity().Y, 4000), false, false);

	p._flipbook->SetLooping(false);
	p._flipbook->SetFlipbook(p.flip_idle);
	p._flipbook->Play();
}

Player_State * Player_Jumping::handleInput(APlayerClass &p, UInputComponent * PlayerInputComponent)
{
	player = &p;

	p.AddMovementInput(p.GetActorForwardVector(), PlayerInputComponent->GetAxisValue("MoveRight"));

	if (PlayerInputComponent->GetAxisValue("MoveRight") < 0)
		p._flipbook->SetRelativeRotation(FQuat(0, 0, 180, 0), false, nullptr, ETeleportType::None);
	else
		p._flipbook->SetRelativeRotation(FQuat(0, 0, 0, 0), false, nullptr, ETeleportType::None);

	if (p.GetVelocity().Z == 0)
	{
		return new Player_Idle();
	}
	if (p.touched == false || p.GetVelocity().Z < 0)
	{
		return new Player_Falling();
	}
	return nullptr;
}
