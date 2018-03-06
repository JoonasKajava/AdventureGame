#pragma once

#include "Character.h"

class Enemy : public Character
{
private:
	 const std::string names[20] = {
		 "Rottingling",
		 "Hauntmorph",
		 "Gasstrike",
		 "Dreadbeast",
		 "Soilspawn",
		 "Rotgolem",
		 "Dreamling",
		 "Auratooth",
		 "Tombpest",
		 "Shadowtooth",
		 "Blazeling",
		 "Barbflayer",
		 "Banescreamer",
		 "Wispfreak",
		 "Warpwing",
		 "Thunderscreamer",
		 "Abyssling",
		 "Cavehound",
		 "Fogstrike"
	};
	 sf::Vector2f findFreeSpawnSpot();

	 int nextMoveTime = 0;

public:

	static void SpawnEnemies(int maxEnemies);

	int TakeDamage(int damage) override;

	void virtual OnTick();

	Enemy();
	~Enemy();
};

