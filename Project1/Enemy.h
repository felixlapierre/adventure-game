#pragma once
#include "Creature.h"
class Enemy :
	public Creature
{
public:
	Enemy(int frameWidth, int frameHeight, float health);
	virtual ~Enemy();

	virtual void Update(float elapsedTime, sf::Vector2f target) = 0;
};

