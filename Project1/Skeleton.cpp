#pragma once
#include "stdafx.h"
#include "Skeleton.h"
#include "util.h"
#include <iostream>
Skeleton::Skeleton() : Enemy(50, 50, 50)
{
	if (_texture->getSize().x == 0)
		_texture->loadFromFile("images/Skeleton.png");
	Load(_texture);
}

Skeleton::~Skeleton()
{

}

void Skeleton::Update(float elapsedTime, sf::Vector2f target)
{
	sf::Vector2f toPlayer(target.x - GetCenter().x, target.y - GetCenter().y);
	//TODO: Normalize toPlayer and multiply by speed
	setDesiredVelocity(util::normalize(toPlayer) * _speed);
	Creature::Update(elapsedTime);
	//std::cout << (int)GetVelocity().x << " " << (int)GetVelocity().y << std::endl;
}

void Skeleton::Attack(Creature * c)
{
	//Do nothing for now
}

sf::Texture * Skeleton::_texture = new sf::Texture();