#include "stdafx.h"
#include "IceManNPC.h"
#include "Item.h"
#include "GameContext.h"

IceManNPC::IceManNPC()
{
	Health = 16;
	MaxHealth = 16;
	Attack = 3;
	Defence = 2;
	Name = "Roek, The Iceman";
	sf::Texture* CharacterTexture = new sf::Texture();
	CharacterTexture->loadFromFile("Graphics/dg_monster232.png", sf::IntRect(160, 128, 32, 32));
	Body = sf::Sprite(*CharacterTexture);
	Body.setPosition(24 * 32, 4 * 32);
	Inventory.push_back(new Item(Item::Sword, false));
}


IceManNPC::~IceManNPC()
{
}

void IceManNPC::Speak(int newStage)
{
	if (newStage != NULL) {
		GameContext::instance->gameInfoPanel.ClearButtons();
		ConversationStage = newStage;
	}

	switch (ConversationStage)
	{
	case 0:
		GameContext::instance->gameInfoPanel.AddText("What are you doing here!", Name);
		GameContext::instance->gameInfoPanel.AddText("You are not supposed to come here!", Name);

		GameContext::instance->gameInfoPanel.AddButton("I want that stone", 1);
		GameContext::instance->gameInfoPanel.AddButton("I can trade for that stone", 2);
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);
		break;
	case 1:
		GameContext::instance->MainPlayer->EndConversation(false);
		GameContext::instance->MainPlayer->StartFight(this, false);
		GameContext::instance->gameInfoPanel.AddText("You have to fight me if you want it", Name);
		break;
	default:
		break;
	}
}

int IceManNPC::TakeDamage(int damage)
{
	int d = Character::TakeDamage(damage);
	GameContext::instance->gameInfoPanel.UpdateEnemyInfo();
	return d;
}
