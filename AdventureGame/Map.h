#pragma once
#include <SFML\Graphics.hpp>
#include <tmxlite\Map.hpp>

class Map : public sf::Drawable, public sf::Transformable
{
public:

	std::vector<sf::Vector2i> blockedtiles;


	tmx::Map map;


	Map();
	~Map();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


private:

	sf::VertexArray verticles;

	sf::Texture TerrainTexture;
};