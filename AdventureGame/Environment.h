#pragma once

#include <SFML\Graphics.hpp>
#include "Map.h"

class GameContext;

class Environment : public sf::Drawable
{
public:
	Environment( Map& map);
	~Environment();

	const Map& map;


	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

