#pragma once

#include "stdafx.h"
#include "Character.h"
#include "GameContext.h"
#include "GameEntity.h"

#include <iostream>


Character::Character( bool AddToDrawQueue) : GameEntity( AddToDrawQueue)
{

}

Character::~Character()
{
}

bool Character::Move(Direction direction)
{
	sf::Vector2f normalposition = Body.getPosition(), position = Body.getPosition();

	position.x = position.x / 32;
	position.y = position.y / 32;

	int rightTile = GameContext::instance->environment.map.terrain[int(position.y + 0.5)][int(position.x + 0.5 + 1)];
	int LeftTile = GameContext::instance->environment.map.terrain[int(position.y + 0.5)][int(position.x + 0.5 - 1)];
	int UpTile = GameContext::instance->environment.map.terrain[int(position.y + 0.5 - 1)][int(position.x + 0.5)];
	int DownTile = GameContext::instance->environment.map.terrain[int(position.y + 0.5 + 1)][int(position.x + 0.5)];

	int blockedTilesSize = sizeof(GameContext::instance->environment.map.blockedtiles) / sizeof(GameContext::instance->environment.map.blockedtiles[0]);


	bool BlockRight = false, BlockLeft = false, BlockUp = false, BlockDown = false;

	for (int i = 0; i < blockedTilesSize; i++) {
		int tile = GameContext::instance->environment.map.blockedtiles[i];


		if (rightTile == tile && (int(position.x + 0.5) * 32 - normalposition.x) < 1) {
			BlockRight = true;
		}
		if (LeftTile == tile && (normalposition.x - int(position.x + 0.5) * 32) < 1) {
			BlockLeft = true;
		}
		if (UpTile == tile && (normalposition.y - int(position.y + 0.5) * 32) < 1) {
			BlockUp = true;
		}
		if (DownTile == tile && (int(position.y + 0.5) * 32 - normalposition.y) < 1) {
			BlockDown = true;
		}

	}

	switch (direction)
	{
	case Right:
		if (!BlockRight) {
			Body.move(GameContext::instance->deltaTime * MovementSpeed, 0);
			return true;
		}
		break;
	case Left:
		if (!BlockLeft) {
			Body.move(-GameContext::instance->deltaTime * MovementSpeed, 0);
			return true;
		}
		break;
	case Up:
		if (!BlockUp) {
			Body.move(0, -GameContext::instance->deltaTime * MovementSpeed);
			return true;
		}
		break;
	case Down:
		if (!BlockDown) {
			Body.move(0, GameContext::instance->deltaTime * MovementSpeed);
			return true;
		}
		break;
	default:
		break;
	}

	return false;
}
