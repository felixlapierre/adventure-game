#pragma once

class GameObject
{
public:
	GameObject() {};
	GameObject(sf::FloatRect collisionBox);
	virtual ~GameObject();

	sf::FloatRect GetCollisionBox();
	void SetCollisionBox(sf::FloatRect rect);
	void SetCollisionBox(float left, float right);
private:
	sf::FloatRect _collisionBox;
};