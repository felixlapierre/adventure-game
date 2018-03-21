#pragma once
#include "AnimatedObject.h"
class MovingObject :
	public AnimatedObject
{
public:
	MovingObject(int frameWidth, int frameHeight);
	MovingObject(int frameWidth, int frameHeight, sf::Vector2f velocity);
	MovingObject(int frameWidth, int frameHeight, sf::Vector2f velocity, sf::Vector2f acceleration);
	MovingObject(int frameWidth, int frameHeight, sf::Vector2f velocity, float friction);

	virtual ~MovingObject();

	sf::Vector2f GetVelocity() { return _velocity; };
	void SetVelocity(sf::Vector2f velocity) { _velocity = velocity; };
	void IncreaseVelocity(sf::Vector2f velocity) { _velocity += velocity; };

	sf::Vector2f GetAcceleration() { return _acceleration; }
	void SetAcceleration(sf::Vector2f acceleration) { _acceleration = acceleration; }

	virtual void Update(float elapsedTime);
	virtual void Rotate();

	void collide(GameObject obstacle);


private:
	sf::Vector2f _velocity;
	sf::Vector2f _acceleration;
	float _friction;
};