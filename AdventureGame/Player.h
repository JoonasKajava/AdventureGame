#pragma once


#include "Character.h"

class Character;


class Player : public  Character
{
public:
	Player(bool AddToDrawQueue = true);
	~Player();

	void HandleInput();

	void OnSingleMouseClick(sf::Event e);

	bool Speaking;


};

