#include "Player_Falling.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"

Player_Falling::Player_Falling()
{
}

Player_Falling::~Player_Falling()
{
}

void Player_Falling::Enter(APlayerClass& player)
{
	player.LaunchCharacter(FVector(0, 0, -1500), false, false);

	player._flipbook->SetFlipbook(player.flip_idle);
	player._flipbook->Play();
}

Player_State* Player_Falling::handleInput(APlayerClass& player, int inputType)
{
	UInputComponent* PlayerInputComponent = player.InputComponent;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("FALLING CALLED"));

	if(player.GetVelocity().Z == 0)
		return new Player_Idle();

	return nullptr;
}