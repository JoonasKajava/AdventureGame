#include "stdafx.h"
#include "ShopKeeperNPC.h"
#include "GameContext.h"


ShopKeeperNPC::ShopKeeperNPC()
{
	Health = 16;
	MaxHealth = 16;
	Attack = 1;
	Defence = 2;
	MovementSpeed = 0.00005;
	Name = "Beorn, The Shopkeeper";
	sf::Texture* CharacterTexture = new sf::Texture();
	CharacterTexture->loadFromFile("Graphics/dg_uniques32.png", sf::IntRect(160, 0, 32, 32));
	Body = sf::Sprite(*CharacterTexture);
	Body.setPosition(5 * 32, 33 * 32);
	Inventory.push_back(new Item(Item::Shovel, false));
}


ShopKeeperNPC::~ShopKeeperNPC()
{
}

void ShopKeeperNPC::Speak(int newStage)
{
	if (newStage != NULL) {
		GameContext::instance->gameInfoPanel.ClearButtons();
		ConversationStage = newStage;
	}
	switch (ConversationStage)
	{
	case 0:
		GameContext::instance->gameInfoPanel.AddText("Hello customer!", Name);
		GameContext::instance->gameInfoPanel.AddText("I have this nice shovel for sale", Name);
		GameContext::instance->gameInfoPanel.AddText("It's only 40 gold coins!", Name);
		GameContext::instance->gameInfoPanel.AddText("I will also tell some secrects if you buy it", Name);

		GameContext::instance->gameInfoPanel.AddButton("I will buy it", 1);
		GameContext::instance->gameInfoPanel.AddButton("I'm not interested", 2);

		break;
	case 1: {
		int PlayerMoney = GameContext::instance->MainPlayer->GetMoneyCount();
		if (PlayerMoney < 40) {
			GameContext::instance->gameInfoPanel.AddText("It seems you are " + std::to_string(40 - PlayerMoney) + " gold coins short");
			GameContext::instance->gameInfoPanel.AddButton("I will came back", 100);
		}
		else {
			GameContext::instance->gameInfoPanel.AddText("Thank you for purchasing the shovel");
			GameContext::instance->gameInfoPanel.AddText("I noticed strange hole in the desert");
			GameContext::instance->gameInfoPanel.AddText("I think it might have something buried in it");
			GameContext::instance->MainPlayer->SetMoney(PlayerMoney - 40);
			GameContext::instance->gameInfoPanel.AddButton("Thank you!", 100);

			for (int i = 0; i < Inventory.size(); i++) {
				if (Inventory[i]->type == Item::Shovel) {
					GameContext::instance->MainPlayer->Inventory.push_back(Inventory[i]);
					Inventory.erase(Inventory.begin() + i);
				}
			}
			GameContext::instance->gameInfoPanel.RecalculateInventory();

		}



		break;
	}
	case 2:
		GameContext::instance->gameInfoPanel.AddText("Welcome back if you change your mind", Name);

		GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);
		break;
	case 3:
		GameContext::instance->gameInfoPanel.AddText("Welcome back!");
		if (HasShovel()) {
		GameContext::instance->gameInfoPanel.AddText("Do you want to purchace the shovel?");
		GameContext::instance->gameInfoPanel.AddText("It's only 40 gold coins!");

		GameContext::instance->gameInfoPanel.AddButton("No", 100);
		GameContext::instance->gameInfoPanel.AddButton("Yes", 1);
		}
		else {
			GameContext::instance->gameInfoPanel.AddText("Did you find anything yet?");
			GameContext::instance->gameInfoPanel.AddButton("Here should i dig?", 100);
			GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);
		}
		break;
	case 4:
		GameContext::instance->gameInfoPanel.AddText("Try digging from desert");
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);
		break;
	default:
		GameContext::instance->MainPlayer->EndConversation();
		ConversationStage = 3;
		break;
	}
}

bool ShopKeeperNPC::HasShovel()
{
	for (Item* item : Inventory) {
		if (item->type == Item::Shovel) {
			return true;
		}
	}

	return false;
}