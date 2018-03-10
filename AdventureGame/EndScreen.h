#pragma once

#include <SFML\Graphics.hpp>
class EndScreen : public sf::Drawable
{
public:
	sf::Text EndMessage;
	EndScreen();
	~EndScreen();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	float opacity;

	void UpdateOpacity();

	void SetText(bool win = true);

	sf::Sprite Background;

};

