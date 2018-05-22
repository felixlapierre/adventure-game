#pragma once
#include "stdafx.h"
#include "util.h"
#include "Weapon.h"
#include "Player.h"
#include <iostream>

Player::Player(sf::RenderWindow* window) : Creature(50, 50, 100.0f) {
	_window = window;
}

Player::~Player()
{
	delete _flail;
}

void Player::Update(float elapsedTime)
{
	_flail->Update(elapsedTime, keysPressed[0]);
	Creature::Update(elapsedTime);
}

void Player::Attack(Creature * c)
{
	_flail->CheckForHit(c);
}

void Player::setDesiredVelocity(sf::Vector2f desiredVelocity)
{
	//Normalize desired velocity
	//To avoid divide by zero error, manually set desired velocity to zero if the passed vector is 0
	if (desiredVelocity.x == 0 && desiredVelocity.y == 0)
		Creature::setDesiredVelocity(desiredVelocity);
	else
	{
		float magnitude = sqrtf(desiredVelocity.x * desiredVelocity.x + desiredVelocity.y * desiredVelocity.y);
		desiredVelocity = desiredVelocity * _speed / magnitude;
		Creature::setDesiredVelocity(desiredVelocity);
	}
}

void Player::Rotate()
{
	sf::Vector2f direction(GetCenter().x - sf::Mouse::getPosition(*_window).x, GetCenter().y - sf::Mouse::getPosition(*_window).y);
	direction /= sqrtf(direction.x * direction.x + direction.y * direction.y);
	float angle = util::toDeg(atan2f(direction.y, direction.x)) + 270;
	if (direction.x != 0 || direction.y != 0)
		SetRotation(angle);
	//Removed rotation of weapon since flail does not need to rotate
}


void Player::setWeapon(Flail * item) {
	_flail = item;
}

void Player::Draw(sf::RenderWindow & window)
{
	(*_flail).DrawChain(window);
	_flail->DrawChain(window);
	if (_flail->IsPulled()) {
		AnimatedObject::Draw(window);
		_flail->Draw(window);
	}
	else {
		_flail->Draw(window);
		AnimatedObject::Draw(window);
	}
}
