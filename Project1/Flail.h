#pragma once
#include "Weapon.h"
#include "Creature.h"

class Flail : public Weapon {
public:
	Flail(Creature * user);
	virtual void Update(float elapsedTime, bool inUse);
	
	virtual void CheckForHit(Creature * c);
	virtual float GetDamage();
	virtual float GetKnockback();
	virtual sf::Vector2f GetAttackOrigin();
	virtual void Rotate(float angle);
	void collide(GameObject obstacle);

	void DrawChain(sf::RenderWindow& window);
	bool IsPulled();
private:

	enum state_type {
		Pulled,
		Stopped
	};
	struct flail_state {
		float lasts;
		state_type type;
	};

	static sf::Texture * _texture;

	void addState(state_type type, float lasts);
	std::vector<flail_state> _states;

	const float _damage = 15.0f;
	const float _knockback = 1500.0f;
	const float _min_speed = 50.0f;
	const float _pull_duration = 0.3f;
	const float _chain_length = 200.0f;
};