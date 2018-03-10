#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>

#include "Player.h"
#include "EventHandler.h"
#include "Environment.h"
#include "GameInfoPanel.h"
#include "EndScreen.h"
#include "NPC.h"
#include "Enemy.h"
#include "AudioManager.h"
#include <thread>

class GameContext
{
public:

	int deltaTime;
	std::vector<GameEntity*> GameEntities;

	sf::RenderWindow window;
	sf::View mainView = sf::View(sf::FloatRect(0,50,400,400));

    Environment environment;
	EventHandler eventHandler;
	GameInfoPanel gameInfoPanel;

	AudioManager audioManager;

	EndScreen endScreen;


	Player* MainPlayer;

	std::vector<NPC*> NPCs;
	std::vector<Enemy*> Enemies;

	std::vector<Item*> GroundItems;
	bool GameOver;

	template<class T>
	T* AddEntity(T* entity);


	static GameContext* CreateInstace();
	static GameContext* instance;
private:
	
	GameContext(Map& map);
	~GameContext();
};

template<class T>
inline T * GameContext::AddEntity(T * entity)
{
	this->GameEntities.push_back(entity);
	return entity;
}
