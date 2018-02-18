#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include "Player.h"
#include "EventHandler.h"
#include "Environment.h"
#include "GameInfoPanel.h"
#include "NPC.h"

class GameContext
{
public:

	int deltaTime;

	sf::RenderWindow window;
	sf::View mainView = sf::View(sf::FloatRect(0,50,400,400));

    Environment environment;
	EventHandler eventHandler;
	GameInfoPanel gameInfoPanel;


	std::vector<sf::Drawable*> DrawQueue;


	Player* MainPlayer;

	std::vector<NPC*> NPCs;

	static GameContext* CreateInstace();
	static GameContext* instance;
private:
	
	GameContext(Map& map);
	~GameContext();
};