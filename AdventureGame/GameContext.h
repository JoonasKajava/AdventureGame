#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include "Player.h"
#include "EventHandler.h"
#include "Environment.h"

class GameContext
{
public:
	GameContext(Map& map);
	~GameContext();

	int deltaTime;

	Player MainPlayer;


	sf::RenderWindow window;
	sf::View mainView = sf::View(sf::FloatRect(0,50,400,400));

    Environment environment;
	EventHandler eventHandler;

	std::vector<sf::Drawable*> DrawQueue;

};