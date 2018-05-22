#pragma once
#include "stdafx.h"
#include "Flail.h"
#include <iostream>
Flail::Flail(Creature * user) : Weapon(50, 50, user) {
	if (_texture->getSize().x == 0) //If texture is unloaded
		_texture->loadFromFile("images/Flail.png");
	Load(_texture);
}

void Flail::Update(float elapsedTime, bool inUse) {
	if (inUse &&  _states.size() == 0) {
		/*
		Player is swinging the flail. It must be made to move in the right direction
		at the right speed for the right amount of time.
		It must land exactly opposite its location relative to the player at the time
		of the pull.
		Speed must be higher the further the flail is from the player.		
		*/

		//Get vector from ball to player
		sf::Vector2f chain(user->GetCenter() - GetCenter());

		//Calculate a speed based on the distance and the amount of time it should take
		//for the flail to travel
		float distance = util::length(chain) * 2;
		float speed = distance / _pull_duration;
		float time = _pull_duration;
		//Enforce a speed minimum
		if (speed < _min_speed) {
			speed = _min_speed;
		}

		sf::Vector2f velocity = util::normalize(chain) * speed;
		SetVelocity(velocity);
		
		//DEBUG: Print distance, speed, time
		//std::cout << "Distance: " << distance << " Speed: " << speed << " Time: " << time << std::endl;

		addState(Pulled, time);
	}
	else if (_states.size() > 0) {
		//Flail is currently sailing through the air
		_states.back().lasts -= elapsedTime;
		if (_states.back().lasts <= 0) {
			_states.pop_back();
			SetVelocity(sf::Vector2f(0, 0));
		}
	}
	MovingObject::Update(elapsedTime);
	float distanceToPlayer = util::length(GetCenter() - user->GetCenter());
	if (distanceToPlayer > _chain_length) {
		sf::Vector2f chain = user->GetCenter() - GetCenter();
		SetCenter(GetCenter() + util::normalize(chain) * (distanceToPlayer - _chain_length));
	}
}

void Flail::CheckForHit(Creature * c)
{
	if (_states.size() > 0 && _states.back().type == Pulled
		&& c->GetCollisionBox().intersects(GetCollisionBox())) {
		c->HitByAttack(this);
	}
}

float Flail::GetDamage()
{
	return _damage;
}

float Flail::GetKnockback()
{
	return _knockback;
}

sf::Vector2f Flail::GetAttackOrigin()
{
	return GetCenter();
}

void Flail::Rotate(float angle)
{
}

void Flail::collide(GameObject obstacle)
{
	//Save our current position
	sf::Vector2f previous = GetCenter();

	//Resolve collision with an obstacle
	MovingObject::collide(obstacle);

	//Get the vector of displacement caused by the collision with the obstacle
	sf::Vector2f change = GetCenter() - previous;

	//Change velocity based on colliding with wall
	if (change.x != 0)
		SetVelocity(sf::Vector2f(0, GetVelocity().y));
	else if (change.y != 0)
		SetVelocity(sf::Vector2f(GetVelocity().x, 0));

	user->SetCenter(user->GetCenter() + change);
}

void Flail::addState(state_type type, float lasts)
{
	flail_state state;
	state.type = type;
	state.lasts = lasts;
	_states.push_back(state);
}

void Flail::DrawChain(sf::RenderWindow& window) {
	//Get distance and angle from ball to player
	sf::Vector2f chain = user->GetCenter() - GetCenter();
	float length = util::length(chain);
	sf::RectangleShape line(sf::Vector2f(length, 2));
	line.rotate(util::toDeg(atan2f(chain.y, chain.x)));
	line.setPosition(GetCenter() + (*VisibleGameObject::_offset));
	window.draw(line);
}

bool Flail::IsPulled()
{
	return _states.size() > 0 && _states.back().type == Pulled;
}

sf::Texture * Flail::_texture = new sf::Texture();



