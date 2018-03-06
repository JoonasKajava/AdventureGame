// AdventureGame.cpp : Defines the entry point for the console application.
//
#pragma once

#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "GameContext.h"
#include "GameEntity.h"
#include "Character.h"
#include "Player.h"
#include "GuideNPC.h"
#include "IceManNPC.h"

#include <thread>

GameContext* GameContext::instance = 0;
sf::Texture* Character::deadTexture = 0;

void renderingThread(GameContext* context) {
	while (context->window.isOpen()) {

	}
}

int main()
{
	srand(time(NULL));
	sf::Clock DeltaTimer;
	GameContext* context = GameContext::CreateInstace();
	context->gameInfoPanel.UpdatePlayerInfo();
	context->gameInfoPanel.Initialize();
	context->gameInfoPanel.RecalculateInventory();
	Character::deadTexture = new sf::Texture();
	Character::deadTexture->loadFromFile("Graphics/dg_misc32.png");

	context->NPCs.push_back(new GuideNPC());
	context->NPCs.push_back(new IceManNPC());


	context->GroundItems.push_back(new Item(Item::BlueStone, true, 0, sf::Vector2f(24 * 32, 32)));

	Enemy::SpawnEnemies(30);
	//context->window.setActive(false);

	//std::thread renderthread(&renderingThread, context);


	while (context->window.isOpen()) {
		context->deltaTime = DeltaTimer.getElapsedTime().asMicroseconds();
		
		//std::cout << context->deltaTime << std::endl;

		std::cout << (1.0 / context->deltaTime) * 1000000 << std::endl;

		DeltaTimer.restart();
		
		context->eventHandler.PollEvents();
		context->window.setView(context->mainView);
		context->window.clear();



		context->window.draw(context->environment);
		for (Enemy* enemy : context->Enemies) context->window.draw(*enemy);
		for (Item* item : context->GroundItems) context->window.draw(*item);
		for (NPC* npc : context->NPCs) context->window.draw(*npc);

		context->window.draw(*context->MainPlayer);

		context->window.setView(context->window.getDefaultView());
		context->window.draw(context->gameInfoPanel);
		context->window.display();


	}
	//renderthread.join();
    return 0;
}

