#pragma once

#include "stdafx.h"
#include "GameContext.h"
#include "EventHandler.h"

EventHandler::EventHandler(GameContext& context) : gameContext(context)
{
}

EventHandler::~EventHandler()
{
}


void EventHandler::PollEvents() {
	while (gameContext.window.pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			gameContext.window.close();
			break;
		default:
			break;
		}
	}

	gameContext.MainPlayer.HandleInput();
}