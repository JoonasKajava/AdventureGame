#pragma once

#include "stdafx.h"
#include "GameContext.h"
#include "Character.h"
#include <iostream>

Player::Player(GameContext & context, bool AddToDrawQueue) : Character(context, AddToDrawQueue)
{
	MovementSpeed = 0.15;
	sf::Texture* playerTexture = new sf::Texture();
	playerTexture->loadFromFile("Graphics/Characters.png", sf::IntRect(160, 128, 32, 32));
	Body = sf::Sprite(*playerTexture);

	Body.setPosition(30, 30);

}

Player::~Player()
{
}



void Player::HandleInput()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

		gameContext.MainPlayer.Body.move(gameContext.deltaTime * MovementSpeed, 0);
		gameContext.mainView.move(gameContext.deltaTime * MovementSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		gameContext.MainPlayer.Body.move(-gameContext.deltaTime * MovementSpeed, 0);
		gameContext.mainView.move(-gameContext.deltaTime * MovementSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		gameContext.MainPlayer.Body.move(0, gameContext.deltaTime * MovementSpeed);
		gameContext.mainView.move(0, gameContext.deltaTime * MovementSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		gameContext.MainPlayer.Body.move(0, -gameContext.deltaTime * MovementSpeed);
		gameContext.mainView.move(0, -gameContext.deltaTime * MovementSpeed);
	}

}
