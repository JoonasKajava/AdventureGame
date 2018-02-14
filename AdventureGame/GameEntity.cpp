#pragma once
#include "stdafx.h"
#include "GameEntity.h"
#include "GameContext.h"
#include <SFML\Graphics.hpp>

using namespace sf;


GameEntity::GameEntity(GameContext &context, bool AddToDrawQueue) : gameContext(context)
{
	gameContext.DrawQueue.push_back(this);
}

GameEntity::~GameEntity()
{
}

void GameEntity::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(Body);
}
