#pragma once
#include "MovingObject.h"
#include "Weapon.h"
class Creature :
	public MovingObject
{
public:
	//Constructor and destructor
	Creature(int frameWidth, int frameHeight, float health);
	~Creature();

	//Set the velocity at which the creature wants to go.
	//The velocity can not be set directly since factors like knockback
	//may also come into play.
	virtual void setDesiredVelocity(sf::Vector2f vel) { _desiredVelocity = vel; };

	virtual void Update(float elapsedTime);

	//Step acceleration and friction are used
	//to make the character speed up and slow down
	//smoothly when walking
	const float _stepAcceleration = 8.0f;
	const float _friction = 1.0f;
	
	bool HitByAttack(Weapon * wep);

	//This method checks if the given creature is being attacked by this creature
	virtual void Attack(Creature * c) = 0;

	//Returns the health of the creature
	float GetHealth();
private:
	sf::Vector2f _desiredVelocity;
	float _health;
	float _maxHealth;
	bool alive = true;

	//The following are used to handle invincibility frames
	float _immuneLeft = 0;
	const float MAX_IMMUNE = 0.5f;
};
