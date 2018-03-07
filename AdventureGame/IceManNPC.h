#pragma once
#include "NPC.h"

class IceManNPC : public NPC
{
public:
	IceManNPC();
	~IceManNPC();

	void Speak(int newStage = NULL) override;

	int TakeDamage(int damage) override;


private:
	bool PlayerHasPickaxe();
	bool Satisfied;
};

