#pragma once

#include "Character.h"

class NPC : public Character
{
	std::vector<std::string> Speaklog;

public:
	NPC();
	~NPC();
	bool CanSpeak = true;
	int ChatState = 0;

	void OnClick();
};

