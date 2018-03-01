#include "stdafx.h"
#include "Enemy.h"
#include "GameContext.h"

#include <random>

sf::Vector2f Enemy::findFreeSpawnSpot()
{
	bool intersects = false;
	do {
		int x = rand() % 49 + 1;
		int y = rand() % 49 + 1;
		sf::FloatRect CheckPos(x * 32, y * 32, 32, 32);
		intersects = GameEntity::IsColliding(CheckPos);


		if (!intersects) return sf::Vector2f(x * 32, y * 32);

	} while (intersects);
}

void Enemy::SpawnEnemies(int maxEnemies)
{
	while (GameContext::instance->Enemies.size() < maxEnemies)
	{
		GameContext::instance->Enemies.push_back(new Enemy());
	}
}

int Enemy::TakeDamage(int damage)
{
	int d = Character::TakeDamage(damage);
	GameContext::instance->gameInfoPanel.UpdateEnemyInfo();
	return d;
}

Enemy::Enemy()
{
	Name = names[rand() % names->length()];
	sf::Texture* CharacterTexture = new sf::Texture();

	int tempHealth = rand() % 13 + 5;
	this->Health = tempHealth;
	this->MaxHealth = tempHealth;

	Attack = rand() % 2 + 1;
	Defence = rand() % 2 + 1;
	Speed = rand() % 2 + 1;
	Luck = rand() % 30 + 5;


	int x = rand() % 5 + 0;
	int y = rand() % 12 + 0;

	CharacterTexture->loadFromFile("Graphics/dg_monster432.png", sf::IntRect(x * 32, y * 32, 32, 32));
	Body = sf::Sprite(*CharacterTexture);
	Body.setPosition(findFreeSpawnSpot());

}


Enemy::~Enemy()
{
}
