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
		GameContext::instance->MainPlayer->StartConversation(this);
	}

}