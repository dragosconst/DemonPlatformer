#pragma once

#include "CoreMinimal.h"
#include "PlayerRelated/FSM_player/Player_State.h"
#include "PlayerRelated/Controllable.h"
#include "PlayerClass.generated.h"

enum InputType
{
	TOUCH,
	RELEASE_TOUCH,
	MOVE
};

UCLASS()
class DEMONPLATFORMER_API APlayerClass : public AControllable
{
	GENERATED_BODY()

	// FSM
	class Player_State* _state;

protected:

	// functii pentru input
	virtual void MoveRight(float value) override;
	virtual void OnTouch(ETouchIndex::Type FingerIndex, FVector Location);
	virtual void ReleasedTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	// se apeleaza la fiecare functie de input
	void changeState(int type);

public:
	class UPaperFlipbook* flip_walking;
	class UPaperFlipbook* flip_idle;
	class UPaperFlipbook* flip_jump;
	class UPaperFlipbook* flip_fall;

	APlayerClass();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
