#pragma once
#include "stdafx.h"
#include "Sword.h"

Sword::Sword(Creature * user) : Weapon(56, 66, user) {
	if (_texture->getSize().x == 0) //If texture is unloaded
		_texture->loadFromFile("images/Slash.png");
	Load(_texture);
}

void Sword::Update(float elapsedTime, bool inUse) {
	sf::Vector2f ownerLocation = user->GetCenter();
	_origin = ownerLocation;
	if (inUse && _states.size() == 0) {
		addState(Cooldown, 0.15f);
		addState(Slashing, 0.2f);
		Flip();
		setAnimation(0, 5, 0.04f);
		_visible = true;
	}
	else if (_states.size() > 0) {
		_states.back().lasts -= elapsedTime;
		if (_states.back().lasts <= 0) {
			_states.pop_back();
			if (_states.size() > 0 && _states.back().type == Cooldown)
				_visible = false;
		}
	}
	else {
		_visible = false;
	}

	SetCenter(ownerLocation);

	Weapon::Update(elapsedTime, inUse);
}

void Sword::Rotate(float angle)
{
	//Player passes angle as degree which is what setrotation takes
	//Built-in trig functions use radians, so convert where needed
	//Subtract 90 for reasons still unsure
	int offset = 50;
	SetRotation(angle);
	SetCenter(GetCenter().x + offset * cos(util::toRad(angle - 90)), GetCenter().y + offset * sin(util::toRad(angle - 90)));
}

void Sword::CheckForHit(Creature * c)
{
	//Sword can only hit if it is currently slashing
	if (_states.size() > 0 && _states.back().type == Slashing && c->GetCollisionBox().intersects(GetCollisionBox()))
	{
		c->HitByAttack(this);
	}
}

float Sword::GetDamage()
{
	return _damage;
}

float Sword::GetKnockback()
{
	return _knockback;
}

sf::Vector2f Sword::GetAttackOrigin()
{
	return _origin;
}

void Sword::addState(state_type type, float lasts)
{
	sword_state state;
	state.type = type;
	state.lasts = lasts;
	_states.push_back(state);
}

sf::Texture * Sword::_texture = new sf::Texture();