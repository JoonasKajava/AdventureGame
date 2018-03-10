#include "stdafx.h"
#include "IceManNPC.h"
#include "Item.h"
#include "GameContext.h"

IceManNPC::IceManNPC()
{
	Satisfied = false;
	Health = 16;
	MaxHealth = 16;
	Attack = 1;
	Defence = 2;
	MovementSpeed = 0.00005;
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
		ConversationStage = 4;
		break;
	case 2:
		GameContext::instance->gameInfoPanel.AddText("I lost my pickaxe", Name);
		GameContext::instance->gameInfoPanel.AddText("I lost it somewhere at the desert", Name);
		GameContext::instance->gameInfoPanel.AddText("Bring it back to me and the stone is yours", Name);

		if (PlayerHasPickaxe()) {
			GameContext::instance->gameInfoPanel.AddButton("I found your pickaxe", 3);
		}
		GameContext::instance->gameInfoPanel.AddButton("I want that stone now", 1);
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);
		break;
	case 3: {
		GameContext::instance->gameInfoPanel.AddText("Thank you for finding my pickaxe!", Name);
		GameContext::instance->gameInfoPanel.AddText("I will let you take my stone", Name);
		GameContext::instance->gameInfoPanel.AddText("You can also have this", Name);

		GameContext::instance->MainPlayer->Inventory.push_back(Inventory[0]);
		Inventory.erase(Inventory.begin());
		GameContext::instance->gameInfoPanel.AddButton("Thank you!", 100);
		Satisfied = true;
		for (int i = 0; i < GameContext::instance->MainPlayer->Inventory.size(); i++) {
			if (GameContext::instance->MainPlayer->Inventory[i]->type == Item::Pickaxe) {
				delete GameContext::instance->MainPlayer->Inventory[i];
				GameContext::instance->MainPlayer->Inventory.erase(GameContext::instance->MainPlayer->Inventory.begin() + i);
			}
		}
		GameContext::instance->gameInfoPanel.RecalculateInventory();
		GameContext::instance->gameInfoPanel.UpdatePlayerInfo();

		sf::Vector2f c_pos = this->Body.getPosition();
		this->TryMoveTo(sf::Vector2f(c_pos.x, c_pos.y - 64));
		break;
	}
	case 4:
		if (PlayerHasPickaxe()) {
			Speak(3);
			break;
		}
		else {
			GameContext::instance->gameInfoPanel.AddText("Came back when you find the pickaxe", Name);
		}
		GameContext::instance->gameInfoPanel.AddButton("I want that stone now", 1);
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);
		break;
	case 5:
		GameContext::instance->gameInfoPanel.AddText("I can't live without my pickaxe", Name);
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);
		break;
	default:
		GameContext::instance->MainPlayer->EndConversation();

		this->ConversationStage = Satisfied ? 5 : 4;
		break;
	}
}

int IceManNPC::TakeDamage(int damage)
{
	int d = Character::TakeDamage(damage);
	GameContext::instance->gameInfoPanel.UpdateEnemyInfo();
	return d;
}

bool IceManNPC::PlayerHasPickaxe()
{
	for (Item* item : GameContext::instance->MainPlayer->Inventory) {
		if (item->type == Item::Pickaxe) {
			return true;
		}
	}
	return false;
}
