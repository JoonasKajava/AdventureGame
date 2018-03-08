#include "stdafx.h"
#include "BridgeNPC.h"


BridgeNPC::BridgeNPC()
{
	Name = "Ley, The Fisher";
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
}
