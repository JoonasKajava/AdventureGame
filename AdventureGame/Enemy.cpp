#include "stdafx.h"
#include "Enemy.h"
#include "GameContext.h"

#include <random>

bool Enemy::PurpleStoneDropped = false;

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

int Enemy::GetAliveEnemyCount()
{
	int AliveEnemies = 0;
	for (Enemy* e : GameContext::instance->Enemies) {
		if (e->Alive) {
			AliveEnemies++;
		}
	}
	return AliveEnemies;
}

void Enemy::SpawnEnemies(int maxEnemies)
{

	while (GetAliveEnemyCount() < maxEnemies)
	{
		GameContext::instance->Enemies.push_back(GameContext::instance->AddEntity(new Enemy()));
	}
}

int Enemy::TakeDamage(int damage)
{
	int d = Character::TakeDamage(damage);
	GameContext::instance->gameInfoPanel.UpdateEnemyInfo();
	return d;
}

void Enemy::OnTick()
{
	sf::Vector2f c_pos = this->Body.getPosition();
	sf::Vector2f playerpos = GameContext::instance->MainPlayer->Body.getPosition();
	float distanceFromPlayer =  sqrt(pow(playerpos.x - c_pos.x, 2) + pow(playerpos.y - c_pos.y, 2));
	if (this->Alive && !GameContext::instance->MainPlayer->InBattle && !GameContext::instance->MainPlayer->Speaking && !this->Moving && this->LastTimeMoved.getElapsedTime().asSeconds() > nextMoveTime && distanceFromPlayer < 250) {

		this->TryMoveTo(sf::Vector2f(c_pos.x + (rand() % 65 + (-32)), c_pos.y + (rand() % 65 + (-32))));
		nextMoveTime = rand() % 4 + 1;
	}
}

void Enemy::Die()
{
	Character::Die();
	if (!Enemy::PurpleStoneDropped) {
		if (rand() % 10 <= 1) {
			GameContext::instance->GroundItems.push_back(new Item(Item::PurpleStone, true, 0, Body.getPosition()));
			Enemy::PurpleStoneDropped = true;
		}
	}
	Enemy::SpawnEnemies(30);
}

Enemy::Enemy()
{
	Name = names[rand() % names->length()];
	sf::Texture* CharacterTexture = new sf::Texture();

	int tempHealth = rand() % (13 - 5 + 1) + 5;
	this->Health = tempHealth;
	this->MaxHealth = tempHealth;

	Attack = rand() % 2 + 1;
	Defence = rand() % 2 + 1;
	Speed = rand() % 2 + 1;
	Luck = 0;
	MovementSpeed = 0.00005;

	int x = rand() % 5 + 0;
	int y = rand() % 12 + 0;
	Inventory.push_back(new Item(Item::Coins, false, rand() % 10 + 1));

	CharacterTexture->loadFromFile("Graphics/dg_monster432.png", sf::IntRect(x * 32, y * 32, 32, 32));
	Body = sf::Sprite(*CharacterTexture);
	Body.setPosition(findFreeSpawnSpot());

}


Enemy::~Enemy()
{
}
