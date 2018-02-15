#pragma once

#include "stdafx.h"
#include "GameContext.h"
#include <SFML\Graphics.hpp>

GameContext::GameContext(Map& map) : MainPlayer(*this), eventHandler(*this), environment(*this, map), gameInfoPanel(*this)
{
	this->window.create(sf::VideoMode(1000, 900), "Adventure Game");

	this->window.setKeyRepeatEnabled(true);
	this->mainView.setCenter(this->MainPlayer.Body.getPosition());
	this->mainView.setSize(sf::Vector2f(1000, 700));
	this->mainView.zoom(0.5f);
	this->mainView.setViewport(sf::FloatRect(0, 0, 1, 0.7f));

	gameInfoPanel.AddText("test");
	gameInfoPanel.AddText("lol");
	gameInfoPanel.AddText("435");
	gameInfoPanel.AddText("sdfgsdf");
	gameInfoPanel.AddText("fghdf");


	this->window.setView(mainView);
}


GameContext::~GameContext()
{
}