#pragma once

#include "stdafx.h"
#include "GameContext.h"
#include <SFML\Graphics.hpp>

GameContext::GameContext() : MainPlayer(*this)
{
	this->window.create(sf::VideoMode(1000, 900), "Adventure Game");
	this->window.setKeyRepeatEnabled(false);
}


GameContext::~GameContext()
{
}
