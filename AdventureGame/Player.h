#pragma once


#include "Character.h"

class GameContext;
class Character;


class Player : public  Character
{
public:
	Player(GameContext &context, bool AddToDrawQueue = true);
	~Player();

	void HandleInput();
};

