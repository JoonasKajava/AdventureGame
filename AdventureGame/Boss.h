#pragma once
#include "Enemy.h"


class Boss : public Enemy
{
public:
	Boss();
	~Boss();

	void virtual Die() override;
};

