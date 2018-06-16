#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>


#include "PlayerClass.h"
#include "Components/InputComponent.h"
#include "PlayerRelated/FSM_player/Player_Idle.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "CoreUObject.h"

APlayerClass::APlayerClass() : AControllable::AControllable()
{
	// initializez animatiile de walking si idle in constructor
	flip_walking = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Sprites/Player/mcwalk_flip"), NULL, LOAD_None, NULL);
	flip_idle = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Sprites/Player/mcidle_flip"), NULL, LOAD_None, NULL);
	flip_jump = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Sprites/Player/mcjump_flip"), NULL, LOAD_None, NULL);
	flip_fall = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Sprites/Player/mcfall_flip"), NULL, LOAD_None, NULL);

	_state = new Player_Idle();
	states.push(_state);
	states.top()->Enter(*this);
}

void APlayerClass::Tick(float DeltaTime)
{
	AControllable::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerClass::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	AControllable::SetupPlayerInputComponent(PlayerInputComponent);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("SetupPlayerInputComponent CALLED"));

	PlayerInputComponent->BindTouch(IE_Pressed, this, &APlayerClass::OnTouch);
	PlayerInputComponent->BindTouch(IE_Released, this, &APlayerClass::ReleasedTouch);
}

void APlayerClass::MoveRight(float value)
{
	// !!! asta poate ar trebui mutata in functia Enter de la Player_Walking dar nu stiu sigur cum ar fi mai bine !!!
	AControllable::MoveRight(value);

	changeState(MOVE);
}

void APlayerClass::OnTouch(ETouchIndex::Type FingerIndex, FVector Location)
{
	changeState(TOUCH);
}

void APlayerClass::ReleasedTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	changeState(RELEASE_TOUCH);
}

void APlayerClass::changeState(int type)
{
	Player_State* state = states.top()->handleInput(*this, type);
	if (state)
	{
		states.push(state);
		states.top()->Enter(*this);
	}
}


