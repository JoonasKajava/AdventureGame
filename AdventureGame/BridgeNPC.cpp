#include "stdafx.h"
#include "BridgeNPC.h"
#include "GameContext.h"


BridgeNPC::BridgeNPC()
{


	Name = "Ley, The Fisher";
	MovementSpeed = 0.00005;
	sf::Texture* CharacterTexture = new sf::Texture();
	CharacterTexture->loadFromFile("Graphics/dg_uniques32.png", sf::IntRect(128, 160, 32, 32));
	Body = sf::Sprite(*CharacterTexture);
	Body.setPosition(24 * 32, 25 * 32);
}


BridgeNPC::~BridgeNPC()
{
}

void BridgeNPC::Speak(int newStage)
{
	if (newStage != NULL) {
		GameContext::instance->gameInfoPanel.ClearButtons();
		ConversationStage = newStage;
	}

	switch (ConversationStage)
	{
	case 0:
		GameContext::instance->gameInfoPanel.AddText("Hello, I need your help", Name);
		GameContext::instance->gameInfoPanel.AddText("I need 35 gold coins for", Name);
		GameContext::instance->gameInfoPanel.AddText("Repairing my fishing pole", Name);

		GameContext::instance->gameInfoPanel.AddButton("I have the money", 1);
		GameContext::instance->gameInfoPanel.AddButton("I need to find more money", 2);

		break;
	case 1: {
		int moneycount = GameContext::instance->MainPlayer->GetMoneyCount();
		if (moneycount >= 35) {
			sf::Vector2f pos = Body.getPosition();
			TryMoveTo(sf::Vector2f(pos.x - 48, pos.y));
			GameContext::instance->gameInfoPanel.AddText("Thank you! I will let you pass", Name);
			GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);

			GameContext::instance->MainPlayer->SetMoney(moneycount - 35);
			Satisfied = true;
		}
		else {
			GameContext::instance->gameInfoPanel.AddText("Came back when you find the money", Name);
			GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);
		}

		break;
	}
	case 4:
		GameContext::instance->gameInfoPanel.AddText("Thank you!", Name);
		GameContext::instance->gameInfoPanel.AddText("My fishing pole is good as new", Name);
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);
		GameContext::instance->gameInfoPanel.AddButton("Can you move a bit?", 5);
		break;
	case 5: {
		sf::Vector2f pos = Body.getPosition();
		GameContext::instance->gameInfoPanel.AddText("Yes of course!", Name);
		TryMoveTo(sf::Vector2f(pos.x + 256, pos.y - 128));
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);
		break;
	}
	default:

		GameContext::instance->MainPlayer->EndConversation();
		this->ConversationStage = Satisfied ? 4 : 1;

		break;
	}
}