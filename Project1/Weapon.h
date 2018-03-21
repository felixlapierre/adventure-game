#pragma once
#include "AnimatedObject.h"

class Creature;
class Weapon : public AnimatedObject {
public:
	Weapon(int frameWidth, int frameHeight);
	virtual ~Weapon();
	virtual void Update(float elapsedTime, bool inUse, sf::Vector2f ownerLocation);
	virtual void Rotate(float angle) = 0;
	virtual void CheckForHit(Creature * creature) = 0;
	virtual void Draw(sf::RenderWindow& window);
	virtual float GetDamage() = 0;
	virtual float GetKnockback() = 0;
	virtual sf::Vector2f GetAttackOrigin() = 0;
private:
	sf::Sprite _icon;
};