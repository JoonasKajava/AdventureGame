#include "stdafx.h"
#include "GameContext.h"
#include "GameInfoPanel.h"


GameInfoPanel::GameInfoPanel()
{
	this->ChatFont.loadFromFile("Fonts/wcp.ttf");
}

GameInfoPanel::~GameInfoPanel()
{
}

void GameInfoPanel::AddText(std::string Message)
{


	this->CurrentInfo->push_back(Message);
	if (this->CurrentInfo->size() > 6) {
		this->CurrentInfo->erase(this->CurrentInfo->begin());
	}
}

void GameInfoPanel::SetState(State s)
{
	std::vector<std::string>* buffer;
	switch (s)
	{
	case GameInfoPanel::Battle:
		buffer = &BattleInfo;
		break;
	case GameInfoPanel::Chat:
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
		sf::Text text("> " + (*this->CurrentInfo)[i], ChatFont);
		text.setFillColor(sf::Color::White);
		sf::Transform transform;
		transform.translate(10, GameContext::instance->window.getSize().y * 0.7 + 10 + (35 * i));
		states.transform = transform;
		target.draw(text, states);
	}

}