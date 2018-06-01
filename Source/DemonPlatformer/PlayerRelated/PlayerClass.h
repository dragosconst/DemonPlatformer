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

	//crappy pseduo state machine
	bool _isJumping;
	bool _isWalking;
	bool _isIdle;

protected:
	// trebuie schimbata un pic logica pt animatiile walking si idle
	virtual void MoveRight(float value) override;


	virtual void ReleasedTouch(const ETouchIndex::Type FingerIndex, const FVector Location);

	//handle touch event
	virtual void OnTouch(ETouchIndex::Type FingerIndex, FVector Location);
public:
	APlayerClass();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
