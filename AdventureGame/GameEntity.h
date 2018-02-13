#pragma once

#include <SFML\Graphics.hpp>

class GameContext;

class GameEntity : public sf::Drawable
{
public:
	GameEntity(const GameContext& context, bool AddToDrawQueue = true);
	~GameEntity();

	sf::Sprite Body;

	GameContext* context;

	// Entity Attributes
	std::string Name;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

