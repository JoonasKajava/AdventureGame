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

	void virtual OnTick();

	NPC* conversationWith;

	Character* fightingWith;

	sf::Clock RegenerationTimer;

	void OnSingleMouseClick(sf::Event e);

	void StartFight(Enemy* enemy);

	void EndFight();

	void StartConversation(NPC* npc);

	void EndConversation();

	int TakeDamage(int damage) override;

private:
	float ConversationZoom = 0.3f;
};

