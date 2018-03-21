#pragma once
#include "stdafx.h"
#include "Creature.h"

Creature::Creature(int frameWidth, int frameHeight, float health) : MovingObject(frameWidth, frameHeight, sf::Vector2f(0,0), 8.0f)
{
	_health = health;
	_maxHealth = health;
	_desiredVelocity = sf::Vector2f(0.0f, 0.0f);
}

Creature::~Creature()
{

}

void Creature::Update(float elapsedTime)
{
	if (_health < 0)
		return;
	sf::Vector2f vel = GetVelocity();
	if (sqrt(vel.x * vel.x + vel .y * vel.y) > 10.0f)
	{
		if (GetSource().top != 50)
			setAnimation(1, 4, 0.2f);
	}
	else
		setAnimation(0, 1, 1000.0f);
	
	IncreaseVelocity(_desiredVelocity * _stepAcceleration * elapsedTime);

	if (_immuneLeft > 0)
		_immuneLeft -= elapsedTime;

	MovingObject::Update(elapsedTime);
}

//return true if the creature was hit successfully
bool Creature::HitByAttack(Weapon * wep)
{
	if (_immuneLeft > 0)
		return false;
	else {
		_immuneLeft = MAX_IMMUNE;
		_health -= wep->GetDamage();
		sf::Vector2f knockbackVector(GetCenter() - wep->GetAttackOrigin());
		knockbackVector = util::normalize(knockbackVector);
		knockbackVector *= wep->GetKnockback();
		IncreaseVelocity(knockbackVector);
		//std::cout << (int)knockbackVector.x << " " << (int)knockbackVector.y << std::endl;
		if (_health < 0)
			alive = false;
		return true;
	}
}

float Creature::GetHealth()
{
	return _health;
}
