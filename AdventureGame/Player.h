#pragma once


#include "Character.h"

class GameContext;
class Character;


class Player : public  Character
{
public:
	Player(const GameContext &context, bool AddToDrawQueue = true);
	~Player();
};

