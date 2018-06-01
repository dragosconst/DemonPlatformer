// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerClass.h"
#include "Components/InputComponent.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "CoreUObject.h"

APlayerClass::APlayerClass() : AControllable::AControllable()
{
	//initializez animatiile de walking si idle in constructor
	walking = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Sprites/Player/mcwalk_flip"), NULL, LOAD_None, NULL);

	idle = LoadObject<UPaperFlipbook>(NULL, TEXT("/Game/Sprites/Player/mcidle_flip"), NULL, LOAD_None, NULL);

	_flipbook->SetFlipbook(idle);
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

		_flipbook->SetFlipbook(walking);
	}
	else // ca sa schimbe animatia, cred ca e ok asa ( am sters ce era in BP)
		_flipbook->SetFlipbook(idle);
}