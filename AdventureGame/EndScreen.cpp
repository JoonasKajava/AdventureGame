#include "stdafx.h"
#include "EndScreen.h"
#include "GameContext.h"


EndScreen::EndScreen()
{
	sf::Image* img = new sf::Image();

	img->create(10000, 10000, sf::Color(0, 0, 0, 255));
	sf::Texture* t = new sf::Texture();
	t->loadFromImage(*img);
	Background.setTexture(*t);
	Background.setColor(sf::Color(0,0,0, opacity));

	sf::Font* font = new sf::Font();
	font->loadFromFile("Fonts/wcp.ttf");
	EndMessage.setFont(*font);
	EndMessage.setCharacterSize(86);
	EndMessage.setFillColor(sf::Color(255,255, 255, opacity));
}


EndScreen::~EndScreen()
{
}

void EndScreen::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(Background);
	target.draw(EndMessage);
}

void EndScreen::UpdateOpacity()
{
	if (opacity < 255.0f) {
		opacity += GameContext::instance->deltaTime * 0.0001;
		Background.setColor(sf::Color(0, 0,0, opacity));
		EndMessage.setFillColor(sf::Color(255, 255, 255, opacity));
	}
}

void EndScreen::SetText(bool win)
{
	if (win) {
		EndMessage.setString("You Won!");
	}
	else {
		EndMessage.setString("You Died!");
	}
	sf::FloatRect bounds = EndMessage.getGlobalBounds();
	EndMessage.setPosition(1000 / 2 - bounds.width / 2, 900 / 2 - bounds.height / 2 - 200);
}
