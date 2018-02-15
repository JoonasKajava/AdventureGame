#pragma once

#include "GameEntity.h"

class GameContext;

class Character :
	public GameEntity
{
public:
	Character(GameContext &context, bool AddToDrawQueue = true);
	~Character();

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

