// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerRelated/Controllable.h"
#include "PlayerClass.generated.h"

/**
 * 
 */
UCLASS()
class DEMONPLATFORMER_API APlayerClass : public AControllable
{
	GENERATED_BODY()

	class UPaperFlipbook* walking;
	class UPaperFlipbook* idle;

protected:
	// trebuie schimbata un pic logica pt animatiile walking si idle
	virtual void MoveRight(float value) override;

	//pt a schimba animatia in _idle!!!APARENT NU MERGE
	virtual void ReleasedTouch(const ETouchIndex::Type FingerIndex, const FVector Location);

public:
	APlayerClass();
	
};
