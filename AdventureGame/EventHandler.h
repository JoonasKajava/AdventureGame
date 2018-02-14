#pragma once
#include "GameContext.h"

class EventHandler
{
public:
	EventHandler(GameContext& context);
	~EventHandler();

	sf::Event event;

	GameContext& gameContext;

	void PollEvents();
};

