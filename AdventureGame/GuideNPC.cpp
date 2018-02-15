#include "stdafx.h"
#include "GuideNPC.h"
#include <SFML\Graphics.hpp>

GuideNPC::GuideNPC() : Character()
{
	sf::Texture* CharacterTexture = new sf::Texture();
	CharacterTexture->loadFromFile("Graphics/dg_monster232.png", sf::IntRect(32, 0, 32, 32));
	Body = sf::Sprite(*CharacterTexture);
}


GuideNPC::~GuideNPC()
{
}
