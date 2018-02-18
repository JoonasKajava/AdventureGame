#pragma once
#include <SFML\Graphics.hpp>


class Button : public sf::Drawable {

public:
	sf::RectangleShape box;
	sf::Text text;


	Button(std::string Text, sf::Font& font);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
		target.draw(box);
		target.draw(text);
	}
};