// Fill out your copyright notice in the Description page of Project Settings.

#include "Player_State.h"
#include "PlayerRelated/FSM_player/Player_Idle.h"

Player_State::Player_State()
{
}

Player_State::~Player_State()
{
}

void Player_State::Enter(APlayerClass& player)
{
}

Player_State* Player_State::handleInput(APlayerClass &, int inputType)
{
	return nullptr;
}
