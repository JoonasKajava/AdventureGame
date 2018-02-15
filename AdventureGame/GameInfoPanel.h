#pragma once

#include <SFML\Graphics.hpp>

class GameInfoPanel : public sf::Drawable
{
	std::vector<std::string> Chat;
	sf::Font ChatFont;
public:
	GameInfoPanel();
	~GameInfoPanel();

	
	bool BattleMode = false;

	void AddText(std::string Message);


	void OnItemDrop();

	void OnItemUse();


	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

