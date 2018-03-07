#pragma once

#include "stdafx.h"
#include "GameContext.h"
#include "EventHandler.h"

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}


void EventHandler::PollEvents() {

	if (!GameContext::instance->window.hasFocus()) return;

	for (GameEntity* entity : GameContext::instance->GameEntities) entity->OnTick();



	while (GameContext::instance->window.pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			GameContext::instance->window.close();
			break;
		case sf::Event::MouseButtonReleased:
			GameContext::instance->MainPlayer->OnSingleMouseClick(this->event);
			break;
		default:
			break;
		}
	}
}