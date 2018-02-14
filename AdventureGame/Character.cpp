#pragma once

#include "stdafx.h"
#include "Character.h"
#include "GameContext.h"
#include "GameEntity.h"


Character::Character(GameContext& context, bool AddToDrawQueue) : GameEntity(context, AddToDrawQueue)
{

}

Character::~Character()
{
}
