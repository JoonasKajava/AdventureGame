#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include "Player.h"

class GameContext
{
public:
	GameContext();
	~GameContext();

	Player MainPlayer;
	sf::RenderWindow window;


	std::vector<sf::Drawable*> DrawQueue;

};