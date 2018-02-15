#include "stdafx.h"
#include "GameContext.h"
#include "GameInfoPanel.h"


GameInfoPanel::GameInfoPanel(GameContext & context) : gamecontext(context)
{
	this->ChatFont.loadFromFile("Fonts/wcp.ttf");
}

GameInfoPanel::~GameInfoPanel()
{
}

void GameInfoPanel::AddText(std::string Message)
{
	this->Chat.push_back(Message);
	if (this->Chat.size() > 6) {
		Chat.erase(Chat.begin());
	}
}

void GameInfoPanel::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < Chat.size(); i++) {
		if (i > 6) break;
		sf::Text text("> " + Chat[i], ChatFont);
		text.setFillColor(sf::Color::White);
		sf::Transform transform;
		transform.translate(10, gamecontext.window.getSize().y * 0.7 + 10 + (35 * i));
		states.transform = transform;
		target.draw(text, states);
	}

}