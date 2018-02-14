#include "stdafx.h"
#include <iostream>
#include "Map.h"

Map::Map()
{
	this->TerrainTexture.loadFromFile("Graphics/terrain.png");

	this->Misc1.loadFromFile("Graphics/house.png");
	this->Misc2.loadFromFile("Graphics/dg_edging232.png");
	this->Misc3.loadFromFile("Graphics/dg_edging132.png");
	this->Misc4.loadFromFile("Graphics/dg_edging332.png");

	SpriteMap[1] = new sf::Sprite(TerrainTexture, sf::IntRect(0, 416, 32, 32));
	SpriteMap[2] = new sf::Sprite(TerrainTexture, sf::IntRect(0, 32, 32, 32));
	SpriteMap[3] = new sf::Sprite(TerrainTexture, sf::IntRect(0, 192, 32, 32));
	SpriteMap[4] = new sf::Sprite(Misc3, sf::IntRect(160, 448, 32, 32));
	SpriteMap[5] = new sf::Sprite(Misc4, sf::IntRect(128, 288, 32, 32));
	SpriteMap[6] = new sf::Sprite(TerrainTexture, sf::IntRect(0, 64, 32, 32));
	SpriteMap[7] = new sf::Sprite(TerrainTexture, sf::IntRect(96, 64, 32, 32));
	SpriteMap[8] = new sf::Sprite(TerrainTexture, sf::IntRect(32, 128, 32, 32));
	SpriteMap[9] = new sf::Sprite(TerrainTexture, sf::IntRect(96, 288, 32, 32));
	SpriteMap[10] = new sf::Sprite(TerrainTexture, sf::IntRect(0, 320, 32, 32));
	SpriteMap[11] = new sf::Sprite(TerrainTexture, sf::IntRect(192, 288, 32, 32));
	SpriteMap[12] = new sf::Sprite(TerrainTexture, sf::IntRect(0, 224, 32, 32));
	SpriteMap[13] = new sf::Sprite(TerrainTexture, sf::IntRect(160, 160, 32, 32));
	SpriteMap[14] = new sf::Sprite(Misc1, sf::IntRect(64, 0, 32, 32));
	SpriteMap[15] = new sf::Sprite(Misc2, sf::IntRect(0, 96, 32, 32));
	SpriteMap[16] = new sf::Sprite(Misc2, sf::IntRect(0, 128, 32, 32));
	SpriteMap[17] = new sf::Sprite(Misc2, sf::IntRect(0, 160, 32, 32));
	SpriteMap[18] = new sf::Sprite(Misc2, sf::IntRect(32, 160, 32, 32));
	SpriteMap[19] = new sf::Sprite(Misc2, sf::IntRect(64, 160, 32, 32));
	SpriteMap[20] = new sf::Sprite(Misc2, sf::IntRect(64, 128, 32, 32));
	SpriteMap[21] = new sf::Sprite(Misc2, sf::IntRect(64, 96, 32, 32));
	SpriteMap[22] = new sf::Sprite(Misc2, sf::IntRect(32, 96, 32, 32));
	SpriteMap[23] = new sf::Sprite(Misc3, sf::IntRect(224, 448, 32, 32));
	SpriteMap[24] = new sf::Sprite(Misc4, sf::IntRect(128, 224, 32, 32));
	SpriteMap[25] = new sf::Sprite(Misc3, sf::IntRect(160, 416, 32, 32));
}

Map::~Map()
{
}
