#pragma once

#include "CoreMinimal.h"
#include "PlayerRelated/PlayerClass.h"
#include "Components/InputComponent.h"

#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>

class DEMONPLATFORMER_API Player_State
{
public:
	Player_State();
	virtual ~Player_State();

	//metoda pt intrarea in claa, in general schimba sprite-u
	virtual void Enter(class APlayerClass&);

	//metoda care se ocupa de input
	virtual Player_State* handleInput(class APlayerClass&, int inputType);
};
