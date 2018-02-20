#pragma once

#include "stdafx.h"
#include "GameContext.h"
#include "Character.h"
#include <iostream>
#include "Animator.h"

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

void Player::StartFight(Enemy * enemy)
{
	Animator centerer;
	sf::Vector2f enemypos = enemy->Body.getPosition();
	sf::Vector2f currentcenter = GameContext::instance->mainView.getCenter();
	centerer.AnimateValue<sf::View, float>(&GameContext::instance->mainView, static_cast<void (sf::View::*)(float, float)>(&sf::View::setCenter), currentcenter.x, currentcenter.y, enemypos.x + 32 / 2, enemypos.y + 32 / 2, 500);
	GameContext::instance->mainView.setCenter(enemy->Body.getPosition());
	InBattle = true;
	enemy->InBattle = true;
	GameContext::instance->gameInfoPanel.SetState(GameInfoPanel::Battle);

	Animator a;
	sf::Vector2f size = GameContext::instance->mainView.getSize();
	a.AnimateValue<sf::View, float>(&GameContext::instance->mainView, static_cast<void (sf::View::*)(float, float)>(&sf::View::setSize), size.x, size.y, size.x * ConversationZoom, size.y * ConversationZoom, 500);
}

void Player::StartConversation(NPC * npc)
{
	Animator centerer;
	sf::Vector2f npcpos = npc->Body.getPosition();
	sf::Vector2f currentcenter = GameContext::instance->mainView.getCenter();
	centerer.AnimateValue<sf::View, float>(&GameContext::instance->mainView, static_cast<void (sf::View::*)(float, float)>(&sf::View::setCenter), currentcenter.x, currentcenter.y,npcpos.x + 32 / 2, npcpos.y + 32 / 2, 500);
	GameContext::instance->mainView.setCenter(npc->Body.getPosition());
	Speaking = true;
	npc->Speaking = true;
	GameContext::instance->gameInfoPanel.SetState(GameInfoPanel::Chat);
	npc->Speak();
	this->conversationWith = npc;
	Animator a; 
	sf::Vector2f size = GameContext::instance->mainView.getSize();
	a.AnimateValue<sf::View, float>(&GameContext::instance->mainView, static_cast<void (sf::View::*)(float,float)>(&sf::View::setSize), size.x, size.y, size.x * ConversationZoom, size.y * ConversationZoom, 500);
}

void Player::EndConversation()
{
	GameContext::instance->gameInfoPanel.SetState(GameInfoPanel::World);
	Animator a;
	sf::Vector2f size = GameContext::instance->mainView.getSize();
	a.AnimateValue<sf::View, float>(&GameContext::instance->mainView, static_cast<void (sf::View::*)(float, float)>(&sf::View::setSize), size.x, size.y, size.x / ConversationZoom, size.y / ConversationZoom, 500);

	Animator centerer;
	sf::Vector2f playerpos = this->Body.getPosition();
	sf::Vector2f currentcenter = GameContext::instance->mainView.getCenter();
	centerer.AnimateValue<sf::View, float>(&GameContext::instance->mainView, static_cast<void (sf::View::*)(float, float)>(&sf::View::setCenter), currentcenter.x, currentcenter.y, playerpos.x + 32 / 2, playerpos.y + 32 / 2, 500, [] {
		GameContext::instance->MainPlayer->Speaking = false;
	});
	conversationWith->Speaking = false;
	conversationWith = NULL;
}
