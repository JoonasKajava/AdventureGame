#include "stdafx.h"
#include "Environment.h"
#include <SFML\Graphics.hpp>
#include "Map.h"

Environment::~Environment()
{
}


Environment::Environment(GameContext& gameContext, Map& map) : context(gameContext), map(map)
{
}

void Environment::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int x = 0; x < 50; x++)
	{
		for (int y = 0; y < 50; y++) {
			sf::Transform translation;
			translation.translate(y * 32, x * 32);
			states.transform = translation;
			target.draw(*map.SpriteMap.at(map.terrain[x][y]), states);
		}
	}
}
