#pragma once
#include "stdafx.h"
#include "MovingObject.h"
#include <iostream>
#include "util.h"
MovingObject::MovingObject(int frameWidth, int frameHeight) : AnimatedObject(frameWidth, frameHeight)
{
	_velocity = sf::Vector2f(0, 0);
	_acceleration = sf::Vector2f(0, 0);
	_friction = 0.0f;
}
MovingObject::MovingObject(int frameWidth, int frameHeight, sf::Vector2f velocity) : MovingObject(frameWidth, frameHeight)
{
	_velocity = velocity;
	_acceleration = sf::Vector2f(0, 0);
	_friction = 0.0f;
}
MovingObject::MovingObject(int frameWidth, int frameHeight, sf::Vector2f velocity, sf::Vector2f acceleration) : MovingObject(frameWidth, frameHeight, velocity)
{
	_acceleration = acceleration;
	_friction = 0.0f;
}

MovingObject::MovingObject(int frameWidth, int frameHeight, sf::Vector2f velocity, float friction) : MovingObject(frameWidth, frameHeight, velocity)
{
	_friction = friction;
}

MovingObject::~MovingObject()
{
	
}

void MovingObject::Update(float elapsedTime)
{	
	if (elapsedTime > 0.1)
		elapsedTime = 0.1f;
	//Update velocity
	_velocity += _acceleration * elapsedTime;

	//Take into account friction
	_velocity -= _friction * _velocity * elapsedTime;

	//Update position
	SetCenter(GetCenter().x + _velocity.x * elapsedTime, GetCenter().y + _velocity.y * elapsedTime);

	//DEBUG: Position
	//std::cout << GetCenter().x << " " << GetCenter().y << "    " << _acceleration.x <<  std::endl;

	//Rotation
	Rotate();

	AnimatedObject::Update(elapsedTime);
}
void MovingObject::Rotate()
{
	if (_velocity.x != 0 || _velocity.y != 0)
		SetRotation(atan2f(_velocity.y, _velocity.x) / 3.1415926535f * 180 + 90);
}


void MovingObject::collide(GameObject obstacle)
{
	sf::FloatRect collisionBox = GetRectangle();
	sf::FloatRect obstacleBox = obstacle.GetCollisionBox();
	if (obstacleBox.intersects(collisionBox))
	{
		sf::FloatRect overlap = util::overlap(collisionBox, obstacleBox);
		if (overlap.height > overlap.width)
		{
			//Collision from left side
			if (collisionBox.left + collisionBox.width > obstacleBox.left && collisionBox.left < obstacleBox.left)
			{
				collisionBox.left = obstacleBox.left - collisionBox.width;
			}
			//Collision from right side
			else if (collisionBox.left < obstacleBox.left + obstacleBox.width && collisionBox.left + collisionBox.width > obstacleBox.left + obstacleBox.width)
			{
				collisionBox.left = obstacleBox.left + obstacleBox.width;
			}
		}
		else
		{
			//Collision from bottom side
			if (collisionBox.top < obstacleBox.top + obstacleBox.height && collisionBox.top + collisionBox.width > obstacleBox.top + obstacleBox.height)
			{
				collisionBox.top = obstacleBox.top + obstacleBox.height;
			}
			//Collision from top side
			else if (collisionBox.top + collisionBox.height > obstacleBox.top && collisionBox.top < obstacleBox.top)
			{
				collisionBox.top = obstacleBox.top - collisionBox.height;
			}
		}
		SetCenter(collisionBox.left + collisionBox.width / 2, collisionBox.top + collisionBox.height / 2);
	}
}
