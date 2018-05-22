#pragma once
#include "Creature.h"
#include "Flail.h"
#include <memory>
class Flail;
class Player : 
	public Creature
{
public:
	Player(sf::RenderWindow * window);
	~Player();
	virtual void Update(float elapsedTime);
	virtual void Attack(Creature * c);
	void setDesiredVelocity(sf::Vector2f desiredVelocity);
	void Rotate();
	void setWeapon(Flail * item);
	Flail * getWeapon() { return _flail; }
	void Draw(sf::RenderWindow& window);
	bool keysPressed [4];
private:
	sf::RenderWindow * _window;
	const float _speed = 350.0f;

	Flail * _flail;
};