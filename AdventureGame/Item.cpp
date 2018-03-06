#include "stdafx.h"
#include "GameContext.h"
#include "Item.h"


Item::Item(ItemType type, bool onground, int value, sf::Vector2f pos)
{
	OnGround = onground;
	sf::Texture* tex = new sf::Texture();
	Body.setPosition(pos);
	Value = value;

	this->type = type;
	switch (type)
	{
	case Item::Sword:
		tex->loadFromFile("Graphics\\dg_weapons32.png", sf::IntRect(256, 0, 32,32));
		Name = "Rusty Sword";
		Attack = 3;
		break;
	case Item::HealingStone:
		tex->loadFromFile("Graphics\\dg_misc32.png", sf::IntRect(64, 224, 32, 32));
		Name = "Healing Stone";
		break;
	case Item::Shovel:
		tex->loadFromFile("Graphics\\dg_misc32.png", sf::IntRect(64, 128, 32, 32));
		Name = "Old Shovel";
		break;
	case Item::PurpleStone:
		tex->loadFromFile("Graphics\\dg_misc32.png", sf::IntRect(192, 32, 32, 32));
		Name = "Purple Stone";
		break;
	case Item::BlueStone:
		tex->loadFromFile("Graphics\\dg_misc32.png", sf::IntRect(0, 64, 32, 32));
		Name = "Blue Stone";
		break;
	case Item::RedStone:
		tex->loadFromFile("Graphics\\dg_misc32.png", sf::IntRect(32, 64, 32, 32));
		Name = "Red Stone";
		break;
	case Item::GreenStone:
		tex->loadFromFile("Graphics\\dg_misc32.png", sf::IntRect(96, 64, 32, 32));
		Name = "Green Stone";
		
		break;
	case Item::Coins:
		tex->loadFromFile("Graphics\\dg_misc32.png", sf::IntRect(64, 32, 32, 32));
		Name = "Gold coins";
		break;
	default:
		break;
	}
	Body.setTexture(*tex);

}


Item::~Item()
{
}

void Item::OnClick()
{
	switch (type)
	{
	case Item::Sword:
		GameContext::instance->gameInfoPanel.AddText("The sword looks old and rusty");
		break;
	case Item::HealingStone:
		GameContext::instance->gameInfoPanel.AddText("It seems to be emitting healing energy");
		break;
	case Item::Shovel:
		GameContext::instance->gameInfoPanel.AddText("The shovel looks very used");
		break;
	case Item::PurpleStone:
		GameContext::instance->gameInfoPanel.AddText("This stone feels alive...");
		break;
	case Item::BlueStone:
		GameContext::instance->gameInfoPanel.AddText("This stone feels really cold");
		break;
	case Item::RedStone:
		GameContext::instance->gameInfoPanel.AddText("This stone feels burning hot");
		break;
	case Item::GreenStone:
		GameContext::instance->gameInfoPanel.AddText("This stone is really slimy");
		break;
	case Item::Coins:
		GameContext::instance->gameInfoPanel.AddText(std::to_string(Value) + " gold coins");
		break;
	default:
		break;
	}

}

void Item::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(Body, states);
}
