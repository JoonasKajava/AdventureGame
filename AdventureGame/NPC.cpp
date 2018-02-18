#include "stdafx.h"
#include "NPC.h"
#include "GameContext.h"

#include <iostream>
NPC::NPC()
{
}


NPC::~NPC()
{
}

void NPC::OnClick()
{
	if (this->CanSpeak) {
		GameContext::instance->MainPlayer->Speaking = true;
	}
	std::cout << "test";
}
