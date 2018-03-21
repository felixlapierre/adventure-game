#pragma once
#include "MovingObject.h"
#include "Weapon.h"
class Creature :
	public MovingObject
{
public:
	Creature(int frameWidth, int frameHeight, float health);
	~Creature();
	virtual void setDesiredVelocity(sf::Vector2f vel) { _desiredVelocity = vel; };
	virtual void Update(float elapsedTime);

	const float _stepAcceleration = 8.0f;
	const float _friction = 1.0f;
	
	bool HitByAttack(Weapon * wep);
	virtual void Attack(Creature * c) = 0;
	float GetHealth();
private:
	sf::Vector2f _desiredVelocity;
	float _health;
	float _maxHealth;
	float _immuneLeft = 0;
	const float MAX_IMMUNE = 0.5f;
	bool alive = true;
};
