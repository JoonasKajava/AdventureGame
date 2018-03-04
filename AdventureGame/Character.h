#pragma once

#include "GameEntity.h"
#include "Item.h"


class Character :
	public GameEntity, public sf::Drawable
{
public:
	Character();
	~Character();

	bool Speaking;
	bool InBattle;
	bool Alive = true;


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

	enum AttackType {
		Stab,
		Slash,
		Swing
	};

	std::string AttackNames[3] = {
		"Stab",
		"Slash",
		"Swing"
	};

	std::vector<Item*> Inventory;

	static sf::Texture* deadTexture;

	int AttackCharacter(AttackType type, Character* target);

	void Die();

	int virtual TakeDamage(int damage);
	void PickupItem(Item* item);

	bool Move(Direction direction);

	void LevelUp();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

