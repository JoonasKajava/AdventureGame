#pragma once


#include "Character.h"
#include "NPC.h"
#include "Enemy.h"

class Character;


class Player : public  Character
{
public:
	Player();
	~Player();

	void HandleInput();

	NPC* conversationWith;

	Character* fightingWith;

	void OnSingleMouseClick(sf::Event e);

	void StartFight(Enemy* enemy);

	void EndFight();

	void StartConversation(NPC* npc);

	void EndConversation();

private:
	float ConversationZoom = 0.3f;
};

