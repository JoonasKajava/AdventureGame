#include "stdafx.h"
#include <iostream>
#include "Map.h"

#include <tmxlite\TileLayer.hpp>

Map::Map()
{

	map.load("./Map.tmx");
	const auto& layers = map.getLayers();
	this->TerrainTexture.loadFromFile("Graphics/terrain.png");

	const auto& tileset = map.getTilesets()[0];

	const auto& tilesettiles = tileset.getTiles();

	int width = map.getBounds().width / map.getTileSize().x;
	int height = map.getBounds().height / map.getTileSize().y;
	int layersCount = layers.size();
	verticles.resize(width * height * 4 * layersCount);

	verticles.setPrimitiveType(sf::Quads);
	int count = 0;
	for (const auto& layerref : layers) {
		const auto& layer = *dynamic_cast<const tmx::TileLayer*>(layerref.get());
		const auto& tiles = layer.getTiles();


		for (int y = 0; y < width; y++)
		{
			for (int x = 0; x < height; x++)
			{
				int tileNumber = tiles[x + y * width].ID - 1;


				for (const auto& tilesettile : tilesettiles) {
					if (tilesettile.ID == tileNumber) {
						const auto& tileproperties = tilesettile.properties;

						for (const auto& property : tileproperties) {
							if (property.getName() == "block" && property.getBoolValue()) {
								blockedtiles.push_back(sf::Vector2i(x, y));
							}
						}
					}
				}



				if (tileNumber < 0) continue;
				int tileXinTexture = tileNumber % (TerrainTexture.getSize().x / 32);
				int tileYinTexture = tileNumber / (TerrainTexture.getSize().x / 32);
				int test = width * height * 4 * count;

				sf::Vertex* quad = &verticles[(width * height * 4 * count) + (x + y * width) * 4];

				quad[0].position = sf::Vector2f(x * 32, y * 32);
				quad[1].position = sf::Vector2f((x + 1) * 32, y * 32);
				quad[2].position = sf::Vector2f((x + 1) * 32, (y + 1) * 32);
				quad[3].position = sf::Vector2f(x * 32, (y + 1) * 32);

				quad[0].texCoords = sf::Vector2f(tileXinTexture * 32, tileYinTexture * 32);
				quad[1].texCoords = sf::Vector2f((tileXinTexture + 1) * 32, tileYinTexture * 32);
				quad[2].texCoords = sf::Vector2f((tileXinTexture + 1) * 32, (tileYinTexture + 1) * 32);
				quad[3].texCoords = sf::Vector2f(tileXinTexture * 32, (tileYinTexture + 1) * 32);
			}
		}
		count++;
	}

}

Map::~Map()
{
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
		states.transform *= getTransform();
		states.texture = &TerrainTexture;

		target.draw(verticles, states);

}
