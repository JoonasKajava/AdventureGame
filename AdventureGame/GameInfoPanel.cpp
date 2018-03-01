#include "stdafx.h"
#include "GameContext.h"
#include "GameInfoPanel.h"
#include <math.h>


GameInfoPanel::GameInfoPanel()
{
	ChatFont.loadFromFile("Fonts/wcp.ttf");
	PlayerInfo.setFont(ChatFont);
	EnemyInfo.setFont(ChatFont);

	EnemyInfo.setOutlineColor(sf::Color::Black);
	EnemyInfo.setOutlineThickness(2);
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
	int maxSize = Buttons.size() > 0 || state != World ? 5 : 6;

	if (this->CurrentInfo->size() > maxSize) {
		this->CurrentInfo->erase(this->CurrentInfo->begin());
	}

}

void GameInfoPanel::Initialize()
{
	sf::FloatRect bounds = PlayerInfo.getGlobalBounds();
	sf::Vector2u windowsize = GameContext::instance->window.getSize();
	PlayerInfo.setPosition(windowsize.x - (bounds.width + 100), windowsize.y - (bounds.height + 30));
}

void GameInfoPanel::UpdatePlayerInfo()
{
	char buffer[400];
	snprintf(buffer, sizeof(buffer), PlayerInfoFormat.c_str(), GameContext::instance->MainPlayer->Health, GameContext::instance->MainPlayer->MaxHealth, GameContext::instance->MainPlayer->Attack);
	PlayerInfo.setString(buffer);
}

void GameInfoPanel::UpdateEnemyInfo()
{
	char buffer[400];
	snprintf(buffer, sizeof(buffer), EnemyInfoFormat.c_str(), GameContext::instance->MainPlayer->fightingWith->Health, GameContext::instance->MainPlayer->fightingWith->MaxHealth, GameContext::instance->MainPlayer->fightingWith->Attack);
	EnemyInfo.setString(buffer);
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
	ClearButtons();
	state = s;
	switch (s)
	{
	case GameInfoPanel::Battle: 
	{

		BattleInfo.clear();
		buffer = &BattleInfo;
		sf::Vector2u windowsize = GameContext::instance->window.getSize();

		sf::Vector2f pos = sf::Vector2f(windowsize.x / 2 - 90, windowsize.y / 2 - 70);
		EnemyInfo.setPosition(pos);
	}
		
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

void GameInfoPanel::RecalculateInventory()
{
	std::vector<Item*> items = GameContext::instance->MainPlayer->Inventory;
	for (int i = 0; i < items.size(); i++) {
		int offset = i % 4;
		int row = floor(i / 4);
		items[i]->Body.setPosition(GameContext::instance->window.getSize().x - 300 + 64 * offset, GameContext::instance->window.getSize().y * 0.7 + 10 + (64 * row));
		items[i]->Body.setScale(sf::Vector2f(2, 2));
	}
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
	target.draw(PlayerInfo);

	if(state == Battle)
	target.draw(EnemyInfo);

	std::vector<Item*> items = GameContext::instance->MainPlayer->Inventory;

	for (int i = 0; i < items.size(); i++) {
		target.draw(*items[i]);
	}
}