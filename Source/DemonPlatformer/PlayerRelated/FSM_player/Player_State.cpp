// Fill out your copyright notice in the Description page of Project Settings.

#include "Player_State.h"
#include "PlayerRelated/FSM_player/Player_Idle.h"

Player_State::Player_State()
{
}

Player_State::~Player_State()
{
}

void Player_State::Enter(APlayerClass &p)
{
	player = &p;
}

Player_State * Player_State::handleInput(APlayerClass &, UInputComponent * PlayerInputComponent)
{
	return new Player_Idle();
}

