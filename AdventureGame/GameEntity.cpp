#pragma once
#include "stdafx.h"
#include "GameEntity.h"
#include "GameContext.h"
#include <SFML\Graphics.hpp>

using namespace sf;


GameEntity::GameEntity(bool AddToDrawQueue) 
{
	if(AddToDrawQueue)GameContext::instance->DrawQueue.push_back(this);
}

GameEntity::~GameEntity()
{
}

void GameEntity::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(Body);
}
