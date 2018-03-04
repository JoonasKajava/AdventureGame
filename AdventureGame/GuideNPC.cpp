#include "stdafx.h"
#include "GuideNPC.h"
#include "GameContext.h"
#include <SFML\Graphics.hpp>

GuideNPC::GuideNPC() : NPC()
{
	Name = "Eric, The Guide";
	sf::Texture* CharacterTexture = new sf::Texture();
	CharacterTexture->loadFromFile("Graphics/dg_monster232.png", sf::IntRect(32, 0, 32, 32));
	Body = sf::Sprite(*CharacterTexture);
	Body.setPosition(6 * 32, 16 * 32);
	Inventory.push_back(new Item(Item::HealingStone, false));
}


GuideNPC::~GuideNPC()
{
}


void GuideNPC::Speak(int newStage) {
	if (newStage != NULL) {
		GameContext::instance->gameInfoPanel.ClearButtons();
		ConversationStage = newStage;
	}

	switch (ConversationStage)
	{
	case 0:

		GameContext::instance->gameInfoPanel.AddButton("Who are you?", 1);
		GameContext::instance->gameInfoPanel.AddButton("What is this place?", 2);
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 3);

		GameContext::instance->gameInfoPanel.AddText("Hello stranger!", Name);
		GameContext::instance->gameInfoPanel.AddText("What brings you here?", Name);
		break;
	case 1:
		GameContext::instance->gameInfoPanel.AddButton("What is this place?", 2);
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 3);


		GameContext::instance->gameInfoPanel.AddText("I'm guide living in these lands", Name);
		break;
	case 2: {

		bool HealingStoneFound = false;
		for (int i = 0; i < Inventory.size(); i++) {
			if (Inventory[i]->type == Item::HealingStone) {
				HealingStoneFound = true;
				break;
			}
		}
		if (HealingStoneFound) {
			GameContext::instance->gameInfoPanel.AddButton("Yes, please", 5);
			GameContext::instance->gameInfoPanel.AddButton("No, thank you", 6);
		}
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 3);


		GameContext::instance->gameInfoPanel.AddText("This is place called Sarajas", Name);
		GameContext::instance->gameInfoPanel.AddText("Lot's of monsters like to live here", Name);
		GameContext::instance->gameInfoPanel.AddText("As they get protected by the dragon living in the lavazone", Name);
		if (HealingStoneFound) {
			GameContext::instance->gameInfoPanel.AddText("I have something that might help your journey", Name);
			GameContext::instance->gameInfoPanel.AddText("Do you want it?", Name);
		}

		break;
	}
	case 3:
		GameContext::instance->MainPlayer->EndConversation();
		this->ConversationStage = 4;
		break;

	case 4:
		GameContext::instance->gameInfoPanel.AddButton("Who are you?", 1);
		GameContext::instance->gameInfoPanel.AddButton("What is this place?", 2);
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 3);

		GameContext::instance->gameInfoPanel.AddText("Hello Again!", Name);
		GameContext::instance->gameInfoPanel.AddText("Is There anything you want to ask?", Name);
		break;
	case 5: {
		bool HealingStoneFound = false;
		for (int i = 0; i < Inventory.size(); i++) {
			if (Inventory[i]->type == Item::HealingStone) {
				GameContext::instance->gameInfoPanel.AddText(Name + " gave you " + Inventory[i]->Name + "!");
				GameContext::instance->MainPlayer->Inventory.push_back(Inventory[i]);
				GameContext::instance->gameInfoPanel.RecalculateInventory();
				Inventory.erase(Inventory.begin() + i);
				HealingStoneFound = true;
				break;
			}
		}
		if (!HealingStoneFound) {
			GameContext::instance->gameInfoPanel.AddText("I can't seem to find it", Name);
		}
		GameContext::instance->gameInfoPanel.AddButton("Thank you!", 10);
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 3);

		break;
	}
	case 6:
		GameContext::instance->gameInfoPanel.AddText("I can't force you to take it", Name);
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 3);
		break;
	default:
		GameContext::instance->MainPlayer->EndConversation();
		this->ConversationStage = 4;
		break;
	}
}