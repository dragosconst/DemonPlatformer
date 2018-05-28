// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Controllable.generated.h"

UCLASS()
class DEMONPLATFORMER_API AControllable : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	AControllable();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UPaperFlipbookComponent* _flipbook;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* _camera;

protected:
	//Pt a-l mentine constant pe axa x
	void FreezeAxis();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void MoveRight(float value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
};
