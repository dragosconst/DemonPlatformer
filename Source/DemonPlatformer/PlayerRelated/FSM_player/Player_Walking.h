#pragma once

#include "CoreMinimal.h"
#include "PlayerRelated/PlayerClass.h"
#include "PlayerRelated/FSM_player/Player_State.h"
#include "PlayerRelated/FSM_player/Player_Idle.h"
#include "PlayerRelated/FSM_player/Player_Jumping.h"

class DEMONPLATFORMER_API Player_Walking : public Player_State
{
public:
	Player_Walking();
	~Player_Walking();

	//metoda pt intrarea in claa, in general schimba sprite-u
	virtual void Enter(APlayerClass &);

	//metoda care se ocupa de input
	virtual Player_State* handleInput(APlayerClass &, int inputType);
};
