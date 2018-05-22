#pragma once
#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(int frameWidth, int frameHeight, Creature * user) : MovingObject(frameWidth, frameHeight) {
	this->user = user;
}

Weapon::~Weapon() {

}


void Weapon::Update(float elapsedTime, bool inUse) {
	MovingObject::Update(elapsedTime);
}

void Weapon::Draw(sf::RenderWindow & window)
{
	MovingObject::Draw(window);
}
