#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include "Player.h"
#include "EventHandler.h"
#include "Environment.h"
#include "GameInfoPanel.h"
#include "NPC.h"
#include "Enemy.h"
#include <thread>

class GameContext
{
public:

	int deltaTime;

	sf::RenderWindow window;
	sf::View mainView = sf::View(sf::FloatRect(0,50,400,400));

    Environment environment;
	EventHandler eventHandler;
	GameInfoPanel gameInfoPanel;


	Player* MainPlayer;

	std::vector<NPC*> NPCs;
	std::vector<Enemy*> Enemies;

	std::vector<Item*> GroundItems;

	static GameContext* CreateInstace();
	static GameContext* instance;
private:
	
	GameContext(Map& map);
	~GameContext();
};