#pragma once
#include "Weapon.h"
#include "Creature.h"
class Sword : public Weapon {
public:
	Sword();
	virtual void Update(float elapsedTime, bool inUse, sf::Vector2f ownerLocation);
	virtual void Rotate(float angle);
	virtual void CheckForHit(Creature * c);
	virtual float GetDamage();
	virtual float GetKnockback();
	virtual sf::Vector2f GetAttackOrigin();

private:
	enum state_type {
		Slashing,
		Cooldown
	};
	struct sword_state {
		float lasts;
		state_type type;
	};

	static sf::Texture * _texture;

	const float _damage = 15;
	const float _knockback = 1500.0f;
	sf::Vector2f _origin;
	void addState(state_type type, float lasts);
	std::vector<sword_state> _states;
};