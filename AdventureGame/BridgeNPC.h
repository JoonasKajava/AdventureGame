#pragma once

#include "NPC.h"

class BridgeNPC : public NPC
{
public:
	BridgeNPC();
	~BridgeNPC();

	void Speak(int newStage = NULL) override;
};

