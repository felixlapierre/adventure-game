#pragma once
#include "Creature.h"
#include <memory>
class Weapon;
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
	void setWeapon1(Weapon * item);
	void Draw(sf::RenderWindow& window);
	bool keysPressed [4];
private:
	sf::RenderWindow * _window;
	const float _speed = 350.0f;
	std::unique_ptr<Weapon> _weapon1;
};