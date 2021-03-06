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
#include "BridgeNPC.h"
#include "ShopKeeperNPC.h"
#include "GuardianNPC.h"
#include "Boss.h"
#include <windows.h>
#include <thread>

GameContext* GameContext::instance = 0;
sf::Texture* Character::deadTexture = 0;


int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	srand(time(NULL));
	sf::Clock DeltaTimer;
	sf::Clock FPSCounter;
	GameContext* context = GameContext::CreateInstace();
	context->gameInfoPanel.UpdatePlayerInfo();
	context->gameInfoPanel.Initialize();
	context->gameInfoPanel.RecalculateInventory();

	Character::deadTexture = new sf::Texture();
	Character::deadTexture->loadFromFile("Graphics/dg_misc32.png");

	context->NPCs.push_back(new GuideNPC());
	context->NPCs.push_back(new IceManNPC());
	context->NPCs.push_back(new BridgeNPC());
	context->NPCs.push_back(new ShopKeeperNPC());
	context->NPCs.push_back(new GuardianNPC());

	context->Enemies.push_back(new Boss());


	context->GroundItems.push_back(new Item(Item::BlueStone, true, 0, sf::Vector2f(23 * 32, 32)));

	context->GroundItems.push_back(new Item(Item::GreenStone, true, 0, sf::Vector2f(38 * 32, 31 * 32)));

	context->GroundItems.push_back(new Item(Item::Pickaxe, true, 0, sf::Vector2f(48 * 32, 47 * 32)));

	Enemy::SpawnEnemies(30);


	int fps = 0;
	while (context->window.isOpen()) {
		context->deltaTime = DeltaTimer.getElapsedTime().asMicroseconds();

		if (FPSCounter.getElapsedTime().asSeconds() >= 1) {
			context->gameInfoPanel.UpdateFPS(fps);
			FPSCounter.restart();
			fps = 0;
		}

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
		if (context->GameOver) {
			context->window.draw(context->endScreen);
			context->endScreen.UpdateOpacity();
		}
		context->window.display();
		fps++;
	}

	return 0;
}

