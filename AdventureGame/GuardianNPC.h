#pragma once
#include "NPC.h"

class GuardianNPC : public NPC
{
public:
	GuardianNPC();
	~GuardianNPC();

	void Speak(int newStage = NULL) override;
private:
	bool Satisfied;
};

