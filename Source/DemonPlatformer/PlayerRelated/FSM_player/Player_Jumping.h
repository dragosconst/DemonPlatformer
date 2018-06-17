#pragma once

#include "CoreMinimal.h"
#include "PlayerRelated/PlayerClass.h"
#include "PlayerRelated/FSM_player/Player_State.h"
#include "PlayerRelated/FSM_player/Player_Idle.h"
#include "PlayerRelated/FSM_player/Player_Falling.h"

class DEMONPLATFORMER_API Player_Jumping : public Player_State
{
public:
	Player_Jumping();
	~Player_Jumping();

	//metoda pt intrarea in claa, in general schimba sprite-u
	virtual void Enter(APlayerClass&);

	//metoda care se ocupa de input
	virtual Player_State* handleInput(APlayerClass&, int inputType, TArray<Player_State*>& states);
};
