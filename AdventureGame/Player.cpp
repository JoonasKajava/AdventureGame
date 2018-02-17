#pragma once

#include "stdafx.h"
#include "GameContext.h"
#include "Character.h"
#include <iostream>

Player::Player(bool AddToDrawQueue) : Character( AddToDrawQueue)
{
	MovementSpeed = 0.0001;
	sf::Texture* playerTexture = new sf::Texture();
	playerTexture->loadFromFile("Graphics/Characters.png", sf::IntRect(160, 128, 32, 32));
	Body = sf::Sprite(*playerTexture);

	Body.setPosition(128, 128);
	this->Body.setOrigin(this->Body.getLocalBounds().width / 2, 0);
}

Player::~Player()
{
}

void Player::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if(GameContext::instance->MainPlayer->Move(Direction::Right))
			GameContext::instance->mainView.move(GameContext::instance->deltaTime * MovementSpeed, 0);
		this->Body.setOrigin(this->Body.getLocalBounds().width / 2, 0);
		this->Body.setScale(sf::Vector2f(1,1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if(GameContext::instance->MainPlayer->Move(Direction::Left))
			GameContext::instance->mainView.move(-GameContext::instance->deltaTime * MovementSpeed, 0);
		this->Body.setOrigin(this->Body.getLocalBounds().width / 2, 0);
		this->Body.setScale(sf::Vector2f(-1, 1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if(GameContext::instance->MainPlayer->Move(Direction::Down))
			GameContext::instance->mainView.move(0, GameContext::instance->deltaTime * MovementSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if(GameContext::instance->MainPlayer->Move(Direction::Up))
			GameContext::instance->mainView.move(0, -GameContext::instance->deltaTime * MovementSpeed);
	}

}
