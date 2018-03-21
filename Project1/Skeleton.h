#pragma once
#include "Enemy.h"
class Skeleton :
	public Enemy
{
public:
	Skeleton();
	virtual ~Skeleton();
	virtual void Update(float elapsedTime, sf::Vector2f target);
	virtual void Attack(Creature * c);
private:
	static sf::Texture * _texture;
	const float _speed = 200;
};

