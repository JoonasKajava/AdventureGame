#pragma once

#include <SFML\Graphics.hpp>

class GameEntity
{

public:
	GameEntity();
	virtual ~GameEntity();

	sf::Sprite Body;

	// Entity Attributes
	std::string Name;

	static GameEntity* IsColliding(sf::FloatRect rect);


	void virtual OnTick() {};

};