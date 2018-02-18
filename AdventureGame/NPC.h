#pragma once

#include "Character.h"

class NPC : public Character
{

public:
	NPC();
	~NPC();
	bool CanSpeak = true;
	int ChatState = 0;

	void OnClick();

	int ConversationStage = 0;

	virtual void Speak(int newStage = NULL) = 0;

};

