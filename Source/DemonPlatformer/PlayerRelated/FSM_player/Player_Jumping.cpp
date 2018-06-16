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

void Player_Jumping::Enter(APlayerClass& player)
{
	player._flipbook->SetLooping(false);
	player._flipbook->SetFlipbook(player.flip_jump);
	player._flipbook->Play();

	player.LaunchCharacter(FVector(player.GetVelocity().X, player.GetVelocity().Y, 4000), false, false);
}

Player_State* Player_Jumping::handleInput(APlayerClass& player, int inputType)
{
	UInputComponent* PlayerInputComponent = player.InputComponent;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("JUMPING CALLED"));

	if(inputType == MOVE)
	{
		double moveValue = PlayerInputComponent->GetAxisValue("MoveRight");
		if (moveValue > 0)
			player._flipbook->SetRelativeRotation(FQuat(0, 0, 0, 0), false, nullptr, ETeleportType::None);
		else if(moveValue < 0)
			player._flipbook->SetRelativeRotation(FQuat(0, 0, 180, 0), false, nullptr, ETeleportType::None);
	}
	if (inputType == RELEASE_TOUCH || player.GetVelocity().Z < 0)
	{
		states.pop();
		return new Player_Falling();
	}

	return nullptr;
}
