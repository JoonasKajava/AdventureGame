#pragma once

#include "stdafx.h"
#include "GameContext.h"
#include "Character.h"
#include <iostream>

Player::Player(bool AddToDrawQueue) : Character(AddToDrawQueue)
{
	MovementSpeed = 0.0001;
	sf::Texture* playerTexture = new sf::Texture();
	playerTexture->loadFromFile("Graphics/Characters.png", sf::IntRect(160, 128, 32, 32));
	Body = sf::Sprite(*playerTexture);

	Body.setPosition(128, 128);
}

Player::~Player()
{
}

void Player::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !Speaking) {
		if (GameContext::instance->MainPlayer->Move(Direction::Right))
			GameContext::instance->mainView.move(GameContext::instance->deltaTime * MovementSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !Speaking) {
		if (GameContext::instance->MainPlayer->Move(Direction::Left))
			GameContext::instance->mainView.move(-GameContext::instance->deltaTime * MovementSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !Speaking) {
		if (GameContext::instance->MainPlayer->Move(Direction::Down))
			GameContext::instance->mainView.move(0, GameContext::instance->deltaTime * MovementSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !Speaking) {
		if (GameContext::instance->MainPlayer->Move(Direction::Up))
			GameContext::instance->mainView.move(0, -GameContext::instance->deltaTime * MovementSpeed);
	}



}

void Player::OnSingleMouseClick(sf::Event e)
{

	if (e.mouseButton.button == sf::Mouse::Button::Left && Speaking && GameContext::instance->gameInfoPanel.Buttons.size() > 0) {
		sf::Vector2i pos = sf::Mouse::getPosition(GameContext::instance->window);
		for (std::pair<int, Button*> b : GameContext::instance->gameInfoPanel.Buttons) {
			if (b.second->box.getGlobalBounds().contains(pos.x, pos.y)) {
				if (GameContext::instance->MainPlayer->conversationWith != NULL)GameContext::instance->MainPlayer->conversationWith->Speak(b.first);
				break;
			}
		}
	}


	if (e.mouseButton.button == sf::Mouse::Button::Left) {

		
		for (NPC* npc : GameContext::instance->NPCs) {
			sf::Vector2i pos = sf::Mouse::getPosition(GameContext::instance->window);
			sf::FloatRect hitbox = npc->Body.getGlobalBounds();
			sf::Vector2i location = GameContext::instance->window.mapCoordsToPixel(sf::Vector2f(hitbox.left, hitbox.top), GameContext::instance->mainView);
			hitbox = sf::FloatRect(location.x, location.y, 64, 64);
			if (hitbox.contains(pos.x, pos.y)) {
				sf::Vector2f playercenter = GameContext::instance->MainPlayer->Body.getPosition();
				playercenter.x += 16;
				playercenter.y += 16;

				sf::Vector2f npccenter = npc->Body.getPosition();
				npccenter.x += 16;
				npccenter.y += 16;

				if (sqrt(pow(playercenter.x - npccenter.x, 2) + pow(playercenter.y - npccenter.y, 2)) < 40) npc->OnClick();


			}

		}
	}
}
