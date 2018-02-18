#include "stdafx.h"
#include "GameContext.h"
#include "GameInfoPanel.h"


GameInfoPanel::GameInfoPanel()
{
	ChatFont.loadFromFile("Fonts/wcp.ttf");
}

GameInfoPanel::~GameInfoPanel()
{
}

void GameInfoPanel::AddText(std::string Message)
{
	AddText(Message, "");
}

void GameInfoPanel::AddText(std::string Message, std::string From)
{
	this->CurrentInfo->push_back(From + " > " + Message);
	int maxSize = Buttons.size() > 0 ? 5 : 6;

	if (this->CurrentInfo->size() > maxSize) {
		this->CurrentInfo->erase(this->CurrentInfo->begin());
	}

}

void GameInfoPanel::AddButton(std::string Text, int id)
{
	Buttons[id] = new Button(Text, ChatFont);
}

void GameInfoPanel::ClearButtons()
{
	for (std::pair<int, Button*> b : Buttons) {
		delete b.second;
		b.second = NULL;
	}
	Buttons.clear();
}

void GameInfoPanel::SetState(State s)
{
	std::vector<std::string>* buffer;
	state = s;
	ClearButtons();
	switch (s)
	{
	case GameInfoPanel::Battle:
		BattleInfo.clear();
		buffer = &BattleInfo;
		break;
	case GameInfoPanel::Chat:
		ChatInfo.clear();
		buffer = &ChatInfo;
		break;
	case GameInfoPanel::World:
		buffer = &GameInfo;
		break;
	default:
		buffer = &GameInfo;
		break;
	}
	this->CurrentInfo = buffer;

}

void GameInfoPanel::draw(sf::RenderTarget & target, sf::RenderStates states) const
{


	for (int i = 0; i < this->CurrentInfo->size(); i++) {
		if (i > 6) break;
		sf::Text text((*this->CurrentInfo)[i], ChatFont);
		text.setFillColor(sf::Color::White);
		sf::Transform transform;
		transform.translate(10, GameContext::instance->window.getSize().y * 0.7 + 10 + (35 * i));
		states.transform = transform;
		target.draw(text, states);
	}

	for (std::pair<int, Button*> b : Buttons) {
		target.draw(*b.second);
	}

}