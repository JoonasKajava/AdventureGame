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
	GameContext context;

	while (context.window.isOpen()) {


		context.window.clear();




		context.window.display();

	}

    return 0;
}

