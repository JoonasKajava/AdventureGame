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
	case 2:
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 3);


		GameContext::instance->gameInfoPanel.AddText("This is place called Sarajas", Name);
		GameContext::instance->gameInfoPanel.AddText("Lot's of monsters like to live here", Name);
		GameContext::instance->gameInfoPanel.AddText("As they get protected by the dragon living in the lavazone", Name);
		break;
	case 3:
		this->Speaking = false;
		GameContext::instance->MainPlayer->Speaking = false;
		GameContext::instance->MainPlayer->conversationWith = NULL;
		GameContext::instance->gameInfoPanel.SetState(GameInfoPanel::World);
		this->ConversationStage = 4;
		break;

	case 4:
		GameContext::instance->gameInfoPanel.AddButton("Who are you?", 1);
		GameContext::instance->gameInfoPanel.AddButton("What is this place?", 2);
		GameContext::instance->gameInfoPanel.AddButton("Bye!", 3);

		GameContext::instance->gameInfoPanel.AddText("Hello Again!", Name);
		GameContext::instance->gameInfoPanel.AddText("Is There anything you want to ask?", Name);
		break;
	default:
		break;
	}
}