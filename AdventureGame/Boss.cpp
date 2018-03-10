#include "stdafx.h"
#include "Boss.h"
#include "Enemy.h"
#include "GameContext.h"


Boss::Boss()
{
	Name = "The Dragon";
	sf::Texture* CharacterTexture = new sf::Texture();

	this->Health = 30;
	this->MaxHealth = 30;

	Attack = 6;
	Defence = 3;
	Speed = 2;
	Luck = 0;
	MovementSpeed = 0.00005;
	Luck = 30;

	CharacterTexture->loadFromFile("Graphics/Dragons.png", sf::IntRect(3 * 32, 3 * 32, 32, 32));
	Body = sf::Sprite(*CharacterTexture);
	Body.setPosition(sf::Vector2f(45 * 32, 7 * 32));
}


Boss::~Boss()
{
}

void Boss::Die()
{
	Enemy::Die();
	GameContext::instance->endScreen.SetText(true);
	GameContext::instance->GameOver = true;
	GameContext::instance->audioManager.SetMusic(AudioManager::Win);
}
