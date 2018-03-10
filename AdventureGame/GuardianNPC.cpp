#include "stdafx.h"
#include "GuardianNPC.h"
#include "GameContext.h"


GuardianNPC::GuardianNPC()
{
	Name = "Freya, The Guardian";
	sf::Texture* CharacterTexture = new sf::Texture();
	CharacterTexture->loadFromFile("Graphics/dg_uniques32.png", sf::IntRect(64, 192, 32, 32));
	Body = sf::Sprite(*CharacterTexture);
	Body.setPosition(40 * 32, 15 * 32);
	MovementSpeed = 0.00005;
}


GuardianNPC::~GuardianNPC()
{
}

void GuardianNPC::Speak(int newStage)
{
	if (newStage != NULL) {
		GameContext::instance->gameInfoPanel.ClearButtons();
		ConversationStage = newStage;
	}

	switch (ConversationStage)
	{
	case 0:
		GameContext::instance->gameInfoPanel.AddText("I can't let you through", Name);
		GameContext::instance->gameInfoPanel.AddText("Too many lives lost already", Name);
		GameContext::instance->gameInfoPanel.AddText("You can show your strength, by", Name);
		GameContext::instance->gameInfoPanel.AddText("finding all the stones in these lands", Name);


		GameContext::instance->gameInfoPanel.AddButton("I have all the stones", 1);
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);
		break;
	case 1: {
		bool HasBlueStone = GameContext::instance->MainPlayer->HasItem(Item::BlueStone);
		bool HasRedStone = GameContext::instance->MainPlayer->HasItem(Item::RedStone);
		bool HasGreenStone = GameContext::instance->MainPlayer->HasItem(Item::GreenStone);
		bool HasPurpleStone = GameContext::instance->MainPlayer->HasItem(Item::PurpleStone);
		if (HasBlueStone && HasRedStone && HasGreenStone && HasPurpleStone) {
			GameContext::instance->gameInfoPanel.AddText("I hope you defeat it", Name);
			sf::Vector2f pos = Body.getPosition();
			TryMoveTo(sf::Vector2f(pos.x + 256, pos.y));
			Satisfied = true;
			GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);
		}
		else {
			GameContext::instance->gameInfoPanel.AddText("You still lack some stones", Name);
			GameContext::instance->gameInfoPanel.AddText("Came back when you find all", Name);
			GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);
		}
		break;
	}
	case 2:
		GameContext::instance->gameInfoPanel.AddText("The Dragon is really strong", Name);
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 100);
		break;
	case 3:
		GameContext::instance->gameInfoPanel.AddText("Did you find all the stones?", Name);
		GameContext::instance->gameInfoPanel.AddButton("Yes", 1);
		GameContext::instance->gameInfoPanel.AddButton("No", 100);
		break;
	default:

		GameContext::instance->MainPlayer->EndConversation();
		ConversationStage = Satisfied ? 2 : 3;
		break;
	}
}
