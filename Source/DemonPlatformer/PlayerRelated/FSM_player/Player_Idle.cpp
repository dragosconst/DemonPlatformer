#include "Player_Idle.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"

Player_Idle::Player_Idle()
{
}

Player_Idle::~Player_Idle()
{
}

void Player_Idle::Enter(APlayerClass& player)
{
	player._flipbook->SetFlipbook(player.flip_idle);
	player._flipbook->Play();
}

Player_State* Player_Idle::handleInput(APlayerClass& player, int inputType)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("IDLE CALLED"));
	UInputComponent* PlayerInputComponent = player.InputComponent;

	if(inputType == MOVE)
	{
		if (PlayerInputComponent->GetAxisValue("MoveRight"))
			return new Player_Walking();

		if(player.GetVelocity().Z < 0)
			return new Player_Falling();
	}

	else if(inputType == TOUCH)
		return new Player_Jumping;

	return nullptr;
}