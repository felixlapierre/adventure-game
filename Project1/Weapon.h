#pragma once
#include "MovingObject.h"

class Creature;
class Weapon : public MovingObject {
public:
	Weapon(int frameWidth, int frameHeight, Creature * user);
	virtual ~Weapon();
	virtual void Update(float elapsedTime, bool inUse);
	virtual void Rotate(float angle) = 0;
	virtual void CheckForHit(Creature * creature) = 0;
	virtual void Draw(sf::RenderWindow& window);
	virtual float GetDamage() = 0;
	virtual float GetKnockback() = 0;
	virtual sf::Vector2f GetAttackOrigin() = 0;
protected:
	Creature * user;
private:
	sf::Sprite _icon;
};