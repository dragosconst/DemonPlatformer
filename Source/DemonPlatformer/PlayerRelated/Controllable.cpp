// Fill out your copyright notice in the Description page of Project Settings.

#include "Controllable.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "PaperFlipbookComponent.h"
#include "Components/InputComponent.h"

//Pt a-l mentine constant pe axa x
void AControllable::FreezeAxis()
{
	if (GetActorLocation().X != 0)
		SetActorLocation(FVector(0, GetActorLocation().Y, GetActorLocation().Z), false, nullptr, ETeleportType::None);
}

// Sets default values
AControllable::AControllable()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_flipbook = CreateDefaultSubobject<UPaperFlipbookComponent>("_flip");
	_flipbook->RelativeLocation = FVector(0.0f, 0.0f, 0.0f);
	_camera = CreateDefaultSubobject<UCameraComponent>("_camera");
}

// Called when the game starts or when spawned
void AControllable::BeginPlay()
{
	Super::BeginPlay();
	
}

//Deoarece am ales axy Y-Z din obisnuinta(plus ca e mai ok codu decat la X-Z), MoveRight il misca de fapt pe axa y in loc de axa x
void AControllable::MoveRight(float value)
{
	if (value)
		AddMovementInput(GetActorForwardVector(), value);
}

// Called every frame
void AControllable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FreezeAxis();
}

// Called to bind functionality to input
void AControllable::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveRight", this, &AControllable::MoveRight);
}

