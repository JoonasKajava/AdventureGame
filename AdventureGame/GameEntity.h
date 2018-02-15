#pragma once

#include <SFML\Graphics.hpp>

class GameEntity : public sf::Drawable
{
public:
	GameEntity(bool AddToDrawQueue = true);
	~GameEntity();

	sf::Sprite Body;

	// Entity Attributes
	std::string Name;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

