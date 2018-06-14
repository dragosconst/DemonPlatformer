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

	player._flipbook->SetLooping(true);
	player._flipbook->SetFlipbook(player.flip_fall);
	player._flipbook->Play();
}

Player_State* Player_Falling::handleInput(APlayerClass& player, int inputType)
{
	UInputComponent* PlayerInputComponent = player.InputComponent;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("FALLING CALLED"));
	if (inputType == MOVE)
	{
		double moveValue = PlayerInputComponent->GetAxisValue("MoveRight");
		if (moveValue > 0)
			player._flipbook->SetRelativeRotation(FQuat(0, 0, 0, 0), false, nullptr, ETeleportType::None);
		else if (moveValue < 0)
			player._flipbook->SetRelativeRotation(FQuat(0, 0, 180, 0), false, nullptr, ETeleportType::None);
	}

	if(player.GetVelocity().Z == 0)
		return new Player_Idle();

	return nullptr;
}