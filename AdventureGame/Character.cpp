#pragma once

#include "stdafx.h"
#include "Character.h"
#include "GameContext.h"
#include "GameEntity.h"

#include <iostream>
#include <algorithm>
#include <math.h>
#include "Animator.h"

Character::Character() : GameEntity()
{

}

Character::~Character()
{
}

int Character::AttackCharacter(AttackType type, Character * target)
{
	if (!InBattle) return -1;

	int hitchance = this->Luck;
	int damage = this->Attack;

	switch (type)
	{
	case Stab:
		damage += target->Defence;
		hitchance = 75;
		break;
	case Slash:
		damage *= 2;
		hitchance += 50;
		break;
	case Swing:
		hitchance = 100;
		break;
	case 100:

		break;
	default:
		break;
	}

	if ((hitchance) >= (rand() % 100)) {
		return target->TakeDamage(damage);
	}
	else {
		return -1;
	}
}

void Character::Die()
{
	if (!Alive) return;
	Body.setTexture(*Character::deadTexture);
	int random = (rand() % (50 - 44 + 1) + 44);

	int x = random % (224 / 32);
	int y = random / (224 / 32);

	Body.setTextureRect(sf::IntRect(x * 32, y * 32, 32, 32));
	Alive = false;
}

int Character::TakeDamage(int damage)
{
	Health -= damage - Defence;
	if (Health <= 0) Die();
	return damage - Defence;
}

bool Character::Move(Direction direction)
{
	if (Speaking || InBattle) return false;

	sf::FloatRect Bounds = Body.getGlobalBounds();
	double speed = GameContext::instance->deltaTime * MovementSpeed;
	switch (direction) {
	case Right:
		Bounds.left += speed;
		break;
	case Left:
		Bounds.left -= speed;
		break;
	case Up:
		Bounds.top -= speed;
		break;
	case Down:
		Bounds.top += speed;
		break;
	default:
		break;
	}
	Bounds.width = 31;
	Bounds.height = 31;

	GameEntity* collider = GameEntity::IsColliding(Bounds);

	if (collider != NULL) {
		Player* player = dynamic_cast<Player*>(this);
		Enemy* enemy = dynamic_cast<Enemy*>(collider);
		if (player != nullptr && enemy != nullptr) {
			 player->StartFight(enemy);
		}
		return false;

	}

	switch (direction)
	{
	case Right:
		Body.move(speed, 0);
		return true;
		break;
	case Left:
		Body.move(-speed, 0);
		return true;
		break;
	case Up:
		Body.move(0, -speed);
		return true;
		break;
	case Down:
		Body.move(0, speed);
		return true;
		break;
	default:
		break;
	}

	return false;
}

void Character::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(Body);
}
