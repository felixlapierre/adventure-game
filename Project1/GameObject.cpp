#pragma once
#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(sf::FloatRect collisionBox)
{
	_collisionBox = collisionBox;
}
GameObject::~GameObject()
{

}
sf::FloatRect GameObject::GetCollisionBox() { 
	return _collisionBox; 
}

void GameObject::SetCollisionBox(sf::FloatRect rect)
{
	_collisionBox = rect;
}

void GameObject::SetCollisionBox(float left, float top)
{
	_collisionBox.left = left;
	_collisionBox.top = top;
}
