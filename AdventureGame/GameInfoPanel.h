#pragma once

#include "Button.h"
#include <SFML\Graphics.hpp>

class GameInfoPanel : public sf::Drawable
{
	std::vector<std::string> GameInfo;

	std::vector<std::string> ChatInfo;

	std::vector<std::string> BattleInfo;

	std::vector<std::string>* CurrentInfo;


public:
	sf::Font ChatFont;
	std::map<int, Button*> Buttons;

	enum State {
		Battle,
		Chat,
		World
	};

	GameInfoPanel();
	~GameInfoPanel();

	
	State state = World;

	void AddText(std::string Message);
	void AddText(std::string Message, std::string From);

	void AddButton(std::string Text, int id);
	void ClearButtons();

	void SetState(State s);

	void OnItemDrop();

	void OnItemUse();


	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

