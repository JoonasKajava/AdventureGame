#pragma once

#include "GameEntity.h"


class Character :
	public GameEntity, public sf::Drawable
{
public:
	Character(bool AddToDrawQueue = true);
	~Character();

	bool Speaking;
	bool InBattle;

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

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

