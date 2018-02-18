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
	if (this->CanSpeak && !this->Speaking) {
		GameContext::instance->MainPlayer->Speaking = true;
		this->Speaking = true;
		GameContext::instance->gameInfoPanel.SetState(GameInfoPanel::Chat);
		this->Speak();
		GameContext::instance->MainPlayer->conversationWith = this;

	}

}