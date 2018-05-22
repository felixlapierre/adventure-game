#pragma once
#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(int frameWidth, int frameHeight) : MovingObject(frameWidth, frameHeight) {

}

Weapon::~Weapon() {

}


void Weapon::Update(float elapsedTime, bool inUse, Creature * c) {
	MovingObject::Update(elapsedTime);
}

void Weapon::Draw(sf::RenderWindow & window)
{
	MovingObject::Draw(window);
}
