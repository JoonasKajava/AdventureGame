#pragma once

#include "stdafx.h"
#include "GameContext.h"
#include <SFML\Graphics.hpp>

GameContext::GameContext(Map& map) : MainPlayer(*this), eventHandler(*this), environment(*this, map)
{
	this->window.create(sf::VideoMode(1000, 900), "Adventure Game");
	this->window.setKeyRepeatEnabled(false);
	this->mainView.setCenter(this->MainPlayer.Body.getPosition());
	this->mainView.setViewport(sf::FloatRect(0, 0, 1, 0.7f));
	this->window.setView(mainView);
}


GameContext::~GameContext()
{
}