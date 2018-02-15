#pragma once
#include "GameContext.h"

class EventHandler
{
public:
	EventHandler();
	~EventHandler();

	sf::Event event;

	void PollEvents();
};

