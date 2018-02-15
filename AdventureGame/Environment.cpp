#include "stdafx.h"
#include "Environment.h"
#include <SFML\Graphics.hpp>
#include "Map.h"
#include <iostream>
#include "GameContext.h"


Environment::~Environment()
{
}


Environment::Environment(GameContext& gameContext, Map& map) : context(gameContext), map(map)
{
}

float clip(float n, float lower, float upper) {
	return std::max(lower, std::min(n, upper));
}

void Environment::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	sf::Vector2f position = context.MainPlayer.Body.getPosition();

	position.x = position.x / 32;
	position.y = position.y / 32;

	sf::FloatRect viewDimensions = context.mainView.getViewport();

	int ViewDistance =  viewDimensions.width / 2 * 32;

	int YMin = clip(position.x - ViewDistance, 0, 50);
	int YMax = clip(position.x + ViewDistance, 0, 50);

	int XMin = clip(position.y - ViewDistance, 0, 50);
	int XMax = clip(position.y + ViewDistance, 0, 50);

	for (int x = XMin; x < XMax; x++)
	{
		for (int y = YMin; y < YMax; y++) {
			sf::Transform translation;
			translation.translate(y * 32, x * 32);
			states.transform = translation;
			target.draw(*map.SpriteMap.at(map.terrain[x][y]), states);
		}
	}
}
