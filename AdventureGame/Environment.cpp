#include "stdafx.h"
#include "Environment.h"
#include <SFML\Graphics.hpp>
#include "Map.h"
#include <iostream>
#include "GameContext.h"


Environment::~Environment()
{
}


Environment::Environment(Map& map) : map(map)
{
}

float clip(float n, float lower, float upper) {
	return std::max(lower, std::min(n, upper));
}

void Environment::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(map);
}
