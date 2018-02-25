#pragma once
#include "stdafx.h"
#include "GameEntity.h"
#include "GameContext.h"
#include <SFML\Graphics.hpp>

using namespace sf;


GameEntity::GameEntity() 
{

}

GameEntity::~GameEntity()
{
}


GameEntity* GameEntity::IsColliding(sf::FloatRect rect)
{

	for ( NPC* npc : GameContext::instance->NPCs) {
		if (npc->Body.getGlobalBounds().intersects(rect)) return npc;
	}

	for (Enemy* enemy : GameContext::instance->Enemies) {
		if (enemy->Body.getGlobalBounds().intersects(rect) && enemy->Alive) return enemy;
	}
	for (Map::Tile* tile : GameContext::instance->environment.map.blockedtiles) {
		if (sqrt(pow(rect.left - tile->pos.x * 32, 2) + pow(rect.top - tile->pos.y * 32, 2)) > 40) continue;

		if (rect.intersects(sf::FloatRect(tile->pos.x * 32, tile->pos.y * 32, 32, 32))) return tile;
	}
	return NULL;
}