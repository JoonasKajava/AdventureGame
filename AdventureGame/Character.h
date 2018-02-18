#pragma once

#include "GameEntity.h"


class Character :
	public GameEntity
{
public:
	Character(bool AddToDrawQueue = true);
	~Character();

	bool Speaking;

	double MovementSpeed;

	// Character Attributes
	int Health;
	int MaxHealth;
	int Attack;
	int Defence;
	int Speed;
	int Luck;

	enum Direction
	{
		Up,
		Right,
		Down,
		Left
	};

	bool Move(Direction direction);

};

