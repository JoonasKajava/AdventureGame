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

	void StartFight(Character* enemy, bool Animate = true);

	void EndFight();

	void StartConversation(NPC* npc);

	void EndConversation(bool Animation = true);

	int TakeDamage(int damage) override;

private:
	float ConversationZoom = 0.3f;
};

