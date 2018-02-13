#pragma once

#include "stdafx.h"
#include "GameContext.h"
#include "Character.h"

Player::Player(const GameContext & context, bool AddToDrawQueue) : Character(context, AddToDrawQueue)
{
}

Player::~Player()
{
}
