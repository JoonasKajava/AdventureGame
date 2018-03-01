#pragma once

#include "GameEntity.h"

#include <SFML\Graphics.hpp>

class Item : public GameEntity, public sf::Drawable
{
public:
	enum ItemType {
		Sword,
		HealingStone,
		Shovel,
		PurpleStone,
		BlueStone,
		RedStone,
		GreenStone,
		Coins
	};

	Item(ItemType type, bool onground = true, sf::Vector2f pos = sf::Vector2f(0,0));
	~Item();

	bool OnGround = true;

	int Value;
	int Attack;

	void OnClick();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	ItemType type;
};

