#pragma once

#include "stdafx.h"
#include "GameContext.h"
#include <SFML\Graphics.hpp>


GameContext * GameContext::CreateInstace()
{
	if (instance == 0) {
		Map* gamemap = new Map();
		instance = new GameContext(*gamemap);
	}
	return instance;
}

GameContext::GameContext(Map& map) : environment( map)
{
	this->MainPlayer = new Player(false);
	this->window.create(sf::VideoMode(1000, 900), "Adventure Game");

	this->window.setKeyRepeatEnabled(true);
	sf::Vector2f playerpos = this->MainPlayer->Body.getPosition();
	this->mainView.setCenter(playerpos.x + 32 / 2, playerpos.y + 32 / 2);
	this->mainView.setSize(sf::Vector2f(500, 350));
	//this->mainView.zoom(0.5f);
	this->mainView.setViewport(sf::FloatRect(0, 0, 1, 0.7f));

	gameInfoPanel.SetState(GameInfoPanel::World);

	gameInfoPanel.AddText("You find yourself in land filled with monsters");
	gameInfoPanel.AddText("Explore the land and speak with the villagers");
	gameInfoPanel.AddText("They might know secrets about these lands");

	this->window.setView(mainView);
}


GameContext::~GameContext()
{
}