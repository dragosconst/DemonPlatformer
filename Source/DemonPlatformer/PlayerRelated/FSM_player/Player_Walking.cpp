#include "Player_Walking.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"

Player_Walking::Player_Walking()
{
}

Player_Walking::~Player_Walking()
{
}

void Player_Walking::Enter(APlayerClass& player)
{
	player._flipbook->SetLooping(true);
	player._flipbook->SetFlipbook(player.flip_walking);
	player._flipbook->Play();
}

Player_State* Player_Walking::handleInput(APlayerClass& player, int inputType)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("WALKING CALLED"));
	UInputComponent* PlayerInputComponent = player.InputComponent;

	if(inputType == MOVE)
	{
		double moveValue = PlayerInputComponent->GetAxisValue("MoveRight"); 
		if (moveValue > 0)
			player._flipbook->SetRelativeRotation(FQuat(0, 0, 0, 0), false, nullptr, ETeleportType::None);
		else if(moveValue < 0)
			player._flipbook->SetRelativeRotation(FQuat(0, 0, 180, 0), false, nullptr, ETeleportType::None);
		else
		{
			//states.Pop();
			return new Player_Idle();
		}
	}
	else if (inputType == TOUCH)
	{
		//states.Pop();
		return new Player_Jumping();
	}

	if (player.GetVelocity().Z < 0)
	{
//		states.Pop();
		return new Player_Falling();
	}
	return nullptr;
}
