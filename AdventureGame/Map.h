#pragma once
#include <SFML\Graphics.hpp>
#include <tmxlite\Map.hpp>

class Map : public sf::Drawable, public sf::Transformable
{
public:

	int blockedtiles[11] = { M,6,110,150,160,107,108,109,200,201,202 };

	enum Tiles {
		G = 17, // Grass
		S = 156, // Snow
		ST = 170, // Snowy Tree
		T = 102, // Tree
		M = 221, // Mountain
		D = 541, // Dessert
		C = 548, // Cactus
		P = 543, // Pit
		W = 540, // Water

		// Roads
		RV = 448, // Road Vertical
		RH = 449, // Road Horizontal
		RUL = 463, // Road Up left
		RUR = 465, // Road Up left


		F = 323, // Wooden Floor

		// Roofs
		RFTL = 544
	};
	/*
	18 = Grass
	10G = Tree
	*/
	// 1.Mountain G.Grass 3.Tree 4.Dessert 5.Cactus 6.Water 7.Swamp 8.Lava 9.Snow 10.SnowyTree 11.SnowyMountain 1G.SwampTree 13.Road 14. Wooden Floor 15-GG Roof
	

	tmx::Map map;
	
	int terrain[50][50] = {
	{ M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M, },
	{ M,S,S,S,S,S,S,ST,ST,ST,S,ST,ST,ST,S,S,S,S,S,S,S,11,11,S,11,11,S,S,S,S,S,S,S,S,S,S,S,S,11,8,8,8,8,8,8,8,8,8,8,M, },
	{ M,S,S,S,S,S,S,ST,S,ST,ST,ST,ST,ST,S,S,S,S,S,S,S,11,11,S,11,11,S,S,S,S,S,S,S,S,S,S,S,S,11,8,8,8,8,8,8,8,8,8,8,M, },
	{ M,S,S,S,S,S,S,S,ST,ST,ST,ST,ST,S,S,S,S,S,S,S,S,S,11,S,11,S,S,S,S,S,S,ST,ST,S,S,S,S,S,11,8,8,8,8,8,8,8,8,8,8,M, },
	{ M,S,S,S,S,S,S,S,ST,ST,ST,ST,S,S,ST,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,ST,ST,S,S,S,S,S,11,8,8,8,8,8,8,8,8,8,M, },
	{ M,S,S,S,S,S,S,S,S,ST,ST,ST,ST,S,S,S,G,S,S,S,S,S,ST,S,ST,S,S,S,S,S,S,S,S,S,S,S,S,S,S,S,11,8,8,8,8,8,8,8,8,M, },
	{ M,S,S,S,S,S,S,S,S,T,ST,T,ST,ST,S,G,G,G,S,S,S,S,ST,ST,S,S,G,G,S,S,S,G,G,G,G,S,S,G,S,S,G,11,8,8,8,8,8,8,8,M, },
	{ M,G,S,G,S,G,S,G,G,S,T,T,T,T,T,G,G,G,G,S,S,S,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M,8,8,8,8,8,8,8,8,M, },
	{ M,G,G,G,G,G,G,G,G,G,T,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M,8,8,8,8,8,8,8,8,M, },
	{ M,G,G,G,G,RUL,RH,RH,RH,RH,RUR,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M,8,8,8,8,8,8,8,M, },
	{ M,G,G,G,G,RV,25,G,G,G,RV,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,8,8,8,8,8,8,M, },
	{ M,G,G,RFTL,22,F,22,21,G,G,RV,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M,8,8,8,8,8,8,8,M, },
	{ M,G,G,16,F,F,F,20,G,G,RV,G,G,G,T,T,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M,8,8,8,8,8,8,M, },
	{ M,G,G,16,F,F,F,20,G,G,G,G,T,T,T,T,T,T,T,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M,8,8,8,8,8,8,M, },
	{ M,G,G,17,18,18,18,19,G,G,G,G,G,G,T,T,T,T,T,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,T,T,T,G,G,G,G,M,8,8,8,8,8,M, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,T,T,T,T,T,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,T,G,T,T,G,G,G,G,M,8,8,8,8,8,M, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,T,T,T,G,G,G,G,G,M,8,8,8,8,M, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,T,T,G,G,G,G,G,G,M,8,8,8,8,M, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M,8,8,8,M, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M,8,8,8,M, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M,8,8,M, },
	{ W,W,W,W,W,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M,8,8,M, },
	{ W,W,W,W,W,W,W,W,W,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M,8,M, },
	{ M,G,G,G,G,W,W,W,W,W,W,W,W,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M,M, },
	{ M,G,G,G,G,G,G,G,G,W,W,W,W,W,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,W,W,W,W,W,W,24,W,W,W,W,W,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,W,W,W,W,W,W,W,W,W,W, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,W,W,W,W,W,24,W,W,W,W,W,W,W,W,W,G,G,G,G,G,G,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,G,G,G,G,G,G,G,G,G,M, },
	{ M,G,15,22,22,22,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,W,W,W,W,W,W,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M, },
	{ M,G,16,F,F,20,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,7,7,7,7,G,G,G,G,G,M, },
	{ M,G,16,F,F,F,G,G,G,G,G,G,G,G,G,T,G,G,T,T,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,7,7,7,7,7,7,G,G,G,G,G,M, },
	{ M,G,16,F,F,20,G,G,G,G,G,G,G,G,T,T,T,T,T,T,T,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,7,7,7,7,7,12,7,G,G,G,G,M, },
	{ M,G,17,18,18,19,G,G,G,G,G,G,G,G,G,G,G,G,G,T,T,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,7,12,7,7,7,7,7,7,G,G,G,M, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,T,T,G,G,G,G,T,G,G,G,G,G,G,G,G,G,G,G,G,G,G,7,7,7,G,7,7,12,G,G,G,G,M, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,T,G,G,T,G,T,G,G,G,G,G,G,G,G,G,G,G,G,G,G,7,7,7,7,7,7,G,G,G,G,G,M, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,T,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,7,G,G,7,G,G,G,G,G,G,M, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M, },
	{ M,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,D,D,D,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,M, },
	{ M,D,C,D,G,G,D,D,D,G,D,D,D,G,G,G,G,D,D,D,D,G,G,G,G,G,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,D,M, },
	{ M,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,G,D,C,D,D,D,D,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,M, },
	{ M,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,C,D,D,D,C,D,M, },
	{ M,D,D,C,D,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,M, },
	{ M,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,C,D,D,D,D,D,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,M, },
	{ M,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,D,D,D,C,D,D,D,D,M, },
	{ M,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,M, },
	{ M,D,D,D,D,D,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,P,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,D,D,D,D,M, },
	{ M,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,D,D,D,C,D,D,D,C,D,D,D,D,D,D,D,D,D,D,D,D,M, },
	{ M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,M, },
	};


	Map();
	~Map();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


private:

	sf::VertexArray verticles;

	sf::Texture TerrainTexture;
};