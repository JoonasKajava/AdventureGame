#pragma once
#include <SFML\Graphics.hpp>
#include <tmxlite\Map.hpp>
#include "GameEntity.h"

class Map : public sf::Drawable, public sf::Transformable
{
public:

	struct Tile : GameEntity {
		sf::Vector2f pos;
	};
	std::vector<Tile*> blockedtiles;


	tmx::Map map;


	Map();
	~Map();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

	sf::VertexArray verticles;

	sf::Texture TerrainTexture;
};