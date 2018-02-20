#pragma once

#include "stdafx.h"
#include "Character.h"
#include "GameContext.h"
#include "GameEntity.h"

#include <iostream>
#include <algorithm>
#include <math.h>

Character::Character(bool AddToDrawQueue) : GameEntity(AddToDrawQueue)
{

}

Character::~Character()
{
}

bool Character::Move(Direction direction)
{
	sf::Vector2f position = Body.getPosition();

	position.x = position.x / 32;
	position.y = position.y / 32;


	const std::vector<sf::Vector2i>& blockedtiles = GameContext::instance->environment.map.blockedtiles;

	sf::Vector2i RightTile = sf::Vector2i(position.x + 1, position.y);
	sf::Vector2i LeftTile = sf::Vector2i(position.x - 1, position.y);
	sf::Vector2i TopTile = sf::Vector2i(position.x, position.y - 1);
	sf::Vector2i BottomTile = sf::Vector2i(position.x, position.y + 1);
	sf::FloatRect Bounds = Body.getGlobalBounds();
	double speed = GameContext::instance->deltaTime * MovementSpeed;
	switch (direction) {
	case Right:
		Bounds.left += speed;
		break;
	case Left:
		Bounds.left -= speed;
		break;
	case Up:
		Bounds.top -= speed;
		break;
	case Down:
		Bounds.top += speed;
		break;
	default:
		break;
	}
	Bounds.width = 31;
	Bounds.height = 31;
	for (const sf::Vector2i& tile : blockedtiles) {
		if (Bounds.intersects(sf::FloatRect(tile.x * 32, tile.y * 32, 32, 32))) {
			return false;
		}
	}
	for (const NPC* npc : GameContext::instance->NPCs) {
		if (npc->Body.getGlobalBounds().intersects(Bounds)) return false;
	}

	switch (direction)
	{
	case Right:
			Body.move(speed, 0);
			return true;
		break;
	case Left:
			Body.move(-speed, 0);
			return true;
		break;
	case Up:
			Body.move(0, -speed);
			return true;
		break;
	case Down:
			Body.move(0, speed);
			return true;
		break;
	default:
		break;
	}

	return false;
}
