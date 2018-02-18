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

void test() {
	std::cout << "t";
}
int main()
{
	sf::Clock DeltaTimer;
	GameContext* context = GameContext::CreateInstace();

	context->NPCs.push_back(new GuideNPC());
	while (context->window.isOpen()) {
		context->deltaTime = DeltaTimer.getElapsedTime().asMicroseconds();
		
		//std::cout << (1.0 / context->deltaTime) * 1000000 << std::endl;

		DeltaTimer.restart();



		
		context->eventHandler.PollEvents();

		context->window.setView(context->mainView);
		context->window.clear();
		

		
		context->window.draw(context->environment);
		context->window.draw(*context->MainPlayer);

		for(NPC* npc : context->NPCs) 
		context->window.draw(*npc);

		context->window.setView(context->window.getDefaultView());
		context->window.draw(context->gameInfoPanel);
		context->window.display();

	}

    return 0;
}

