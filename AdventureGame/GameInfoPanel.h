#pragma once

#include "Button.h"
#include <SFML\Graphics.hpp>

class GameInfoPanel : public sf::Drawable
{
	std::vector<std::string> GameInfo;

	std::vector<std::string> ChatInfo;

	std::vector<std::string> BattleInfo;

	std::vector<std::string>* CurrentInfo;

	sf::Text PlayerInfo;
	std::string PlayerInfoFormat = "Health: %d/%d\nAttack: %d";

	sf::Text EnemyInfo;
	std::string EnemyInfoFormat = "Health: %d/%d\nAttack: %d";


	sf::Text FPS;


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

	void Initialize();

	void UpdatePlayerInfo();

	void UpdateEnemyInfo();

	void UpdateFPS(int fps);

	void AddButton(std::string Text, int id);
	void ClearButtons();

	void SetState(State s);

	void RecalculateInventory();


	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

