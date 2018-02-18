#pragma once
#include "NPC.h"

class GuideNPC : public NPC
{
public:
	GuideNPC();
	~GuideNPC();

	 void Speak(int newStage = NULL) override;
};

