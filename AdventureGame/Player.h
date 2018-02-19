#pragma once


#include "Character.h"
#include "NPC.h"

class Character;


class Player : public  Character
{
public:
	Player(bool AddToDrawQueue = true);
	~Player();

	void HandleInput();

	NPC* conversationWith;

	void OnSingleMouseClick(sf::Event e);

	void StartConversation(NPC* npc);

	void EndConversation();

};

