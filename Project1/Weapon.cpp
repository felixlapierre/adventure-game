#pragma once
#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(int frameWidth, int frameHeight) : AnimatedObject(frameWidth, frameHeight) {

}

Weapon::~Weapon() {

}


void Weapon::Update(float elapsedTime, bool inUse, sf::Vector2f ownerLocation) {
	AnimatedObject::Update(elapsedTime);
}

void Weapon::Draw(sf::RenderWindow & window)
{
	AnimatedObject::Draw(window);
}
