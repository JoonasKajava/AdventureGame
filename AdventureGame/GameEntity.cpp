#pragma once
#include "stdafx.h"
#include "GameEntity.h"
#include <SFML\Graphics.hpp>

using namespace sf;


GameEntity::GameEntity(const GameContext &context, bool AddToDrawQueue)
{
	//context.DrawQueue.push_back(this);
}

GameEntity::~GameEntity()
{
}

void GameEntity::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(Body);
}
