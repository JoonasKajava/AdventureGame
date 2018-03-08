#pragma once
#include "NPC.h"


class ShopKeeperNPC : public NPC
{
public:
	ShopKeeperNPC();
	~ShopKeeperNPC();

	void Speak(int newStage = NULL) override;
private: 
	bool HasShovel();
};

