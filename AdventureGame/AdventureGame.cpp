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

#include <thread>

GameContext* GameContext::instance = 0;
sf::Texture* Character::deadTexture = 0;

void renderingThread(GameContext* context) {
	while (context->window.isOpen()) {
		context->window.setView(context->mainView);
		context->window.clear();



		context->window.draw(context->environment);
		for (Enemy* enemy : context->Enemies) context->window.draw(*enemy);
		context->window.draw(*context->MainPlayer);

		for (NPC* npc : context->NPCs) context->window.draw(*npc);


		context->window.setView(context->window.getDefaultView());
		context->window.draw(context->gameInfoPanel);
		context->window.display();
	}
}

int main()
{
	srand(time(NULL));
	sf::Clock DeltaTimer;
	GameContext* context = GameContext::CreateInstace();

	Character::deadTexture = new sf::Texture();
	Character::deadTexture->loadFromFile("Graphics/dg_misc32.png");

	context->NPCs.push_back(new GuideNPC());

	Enemy::SpawnEnemies(30);
	context->window.setActive(false);

	std::thread renderthread(&renderingThread, context);


	while (context->window.isOpen()) {
		context->deltaTime = DeltaTimer.getElapsedTime().asMicroseconds();
		
		std::cout << context->deltaTime << std::endl;

		//std::cout << (1.0 / context->deltaTime) * 1000000 << std::endl;

		DeltaTimer.restart();
		
		context->eventHandler.PollEvents();



	}
	renderthread.join();
    return 0;
}

