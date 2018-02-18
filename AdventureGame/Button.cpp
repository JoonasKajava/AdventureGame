#include "stdafx.h"

#include "Button.h"
#include "GameInfoPanel.h"
#include "GameContext.h"

Button::Button(std::string Text, sf::Font& font)
{

	sf::Text buttonText(Text, font);

	sf::FloatRect bounds = buttonText.getGlobalBounds();
	float offset = 30.0f;
	for (std::pair<int, Button*> otherbutton : GameContext::instance->gameInfoPanel.Buttons) {
		offset += otherbutton.second->box.getGlobalBounds().width + 15.0f;
	}
	sf::RectangleShape button(sf::Vector2f(bounds.width + 30, 50));

	button.setFillColor(sf::Color::Black);
	button.setOutlineThickness(3);
	button.setOutlineColor(sf::Color::White);

	button.setPosition(sf::Vector2f(offset, GameContext::instance->window.getSize().y - 70));

	buttonText.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.f);
	buttonText.setPosition(offset + (button.getGlobalBounds().width / 2 - 5), GameContext::instance->window.getSize().y - 45);
	buttonText.setFillColor(sf::Color::White);

	box = button;
	text = buttonText;
}
