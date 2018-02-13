#pragma once

#include "GameEntity.h"

class GameContext;

class Character :
	public GameEntity
{
public:
	Character(const GameContext &context, bool AddToDrawQueue = true);
	~Character();


	// Character Attributes
	int Health;
	int MaxHealth;
	int Attack;
	int Defence;
	int Speed;
	int Luck;

	

};

