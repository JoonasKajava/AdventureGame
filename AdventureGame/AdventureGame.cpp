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


int main()
{
	Map GameMap;
	GameContext context(GameMap);
	
	sf::Clock DeltaTimer;

	while (context.window.isOpen()) {
		context.deltaTime = DeltaTimer.getElapsedTime().asMilliseconds();
		DeltaTimer.restart();

		context.window.setView(context.mainView);
		context.eventHandler.PollEvents();

		context.window.clear();
		

		
		context.window.draw(context.environment);
		context.window.draw(context.MainPlayer);

		context.window.display();

	}

    return 0;
}

