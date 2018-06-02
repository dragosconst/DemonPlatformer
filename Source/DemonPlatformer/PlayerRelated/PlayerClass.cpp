// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerClass.h"
#include "Components/InputComponent.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "CoreUObject.h"

APlayerClass::APlayerClass() : AControllable::AControllable()
{

	//initializare pseudo state machine
	_isIdle = true;
	_isWalking = false;
	_isJumping = false;

	//initializez animatiile de walking si idle in constructor
	flip_walking = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Sprites/Player/mcwalk_flip"), NULL, LOAD_None, NULL);

	flip_idle = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Sprites/Player/mcidle_flip"), NULL, LOAD_None, NULL);

	flip_jump = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Sprites/Player/mcjump_flip"), NULL, LOAD_None, NULL);

	_flipbook->SetFlipbook(flip_idle);
}

void APlayerClass::Tick(float DeltaTime)
{
	AControllable::Tick(DeltaTime);

	//bad practice, dar nu am o idee mai buna momentan, asta e sa-si dea seama daca nu mai sare
	if (_isJumping && GetVelocity().Z == 0)
	{
		_isJumping = false;
		_isIdle = true;
		_isWalking = false;

		_flipbook->SetLooping(true);
		_flipbook->SetFlipbook(flip_idle);
		_flipbook->Play();
	}
}

// Called to bind functionality to input
void APlayerClass::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	AControllable::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindTouch(IE_Pressed, this, &APlayerClass::OnTouch);
	PlayerInputComponent->BindTouch(IE_Released, this, &APlayerClass::ReleasedTouch);
}


//handle touch event
void APlayerClass::OnTouch(ETouchIndex::Type FingerIndex, FVector Location)
{
	//fara double jumping, cel putin pana cand avem un state machine decent
	if (!_isJumping)
	{
		LaunchCharacter(FVector(GetVelocity().X, GetVelocity().Y, 4000), false, false);
		_isJumping = true;
		_isIdle = false;
		_isWalking = false;

		//da play doar odata la animatia de salt
		_flipbook->SetLooping(false);
		_flipbook->SetFlipbook(flip_jump);
		_flipbook->Play();
	}
}

// trebuie schimbata un pic logica pt animatiile walking si idle
void APlayerClass::MoveRight(float value)
{

	AControllable::MoveRight(value);
	if (value)
	{
		//invarte animatia daca merge in stanga
		if (value < 0)
			_flipbook->SetRelativeRotation(FQuat(0, 0, 180, 0), false, nullptr, ETeleportType::None);
		else
			_flipbook->SetRelativeRotation(FQuat(0, 0, 0, 0), false, nullptr, ETeleportType::None);

		//sa nu dea play la animatia de walking cand e in aer
		if (_isIdle && GetVelocity().Z == 0)
		{
			_isWalking = true;
			_isIdle = false;
			_isJumping = false;

			_flipbook->SetLooping(true);
			_flipbook->SetFlipbook(flip_walking);
			_flipbook->Play();
		}
	}
	else
	{
		// cand sta pe loc pe jos
		if (!_isJumping)
		{
			_isWalking = false;
			_isIdle = true;
			_isJumping = false;

			_flipbook->SetLooping(true);
			_flipbook->SetFlipbook(flip_idle);
			_flipbook->Play();
		}
	}
}


void APlayerClass::ReleasedTouch(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	//o mica schema, cand nu mai tine apasat il arunca cu viteza negativa in jos ca sa opreasca saltul
	if (_isJumping)
	{
		LaunchCharacter(FVector(0, 0, -1500), false, false);
	}
}
