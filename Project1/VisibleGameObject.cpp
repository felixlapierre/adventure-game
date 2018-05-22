#pragma once
#include "stdafx.h"
#include "VisibleGameObject.h"
#include <iostream>

VisibleGameObject::VisibleGameObject(int frameWidth, int frameHeight)
{
	_isLoaded = false;
	_visible = false;
	_frameWidth = frameWidth;
	_frameHeight = frameHeight;
	_location = sf::Vector2f();
}

VisibleGameObject::~VisibleGameObject()
{

}

void VisibleGameObject::SetOffsetPointer(sf::Vector2f * offset)
{
	_offset = offset;
}

void VisibleGameObject::Load(std::string filename)
{
	_texture = new sf::Texture();
	if (_texture->loadFromFile(filename) == false)
	{
		_fileName = "";
		_isLoaded = false;
		_visible = false;
		//std::cout << "Failed to load file: " + filename + "." << std::endl;
	}
	else
	{
		Load(_texture);
	}
}

void VisibleGameObject::Load(sf::Texture * texture)
{
	_isLoaded = true;
	_visible = true;
	_texture = texture;
	_sprite.setTexture((*_texture));
	_sprite.setOrigin((float)_frameWidth / 2, (float)_frameHeight / 2);
	SetCollisionBox(sf::FloatRect(0.0f, 0.0f, (float)_frameWidth, (float)_frameHeight));

}

void VisibleGameObject::Draw(sf::RenderWindow& renderWindow)
{
	if (_isLoaded && _visible)
	{
		_sprite.setPosition(_location + (*_offset));
		renderWindow.draw(_sprite);
	}
}

void VisibleGameObject::SetCenter(float x, float y)
{
	if (_isLoaded)
	{
		_location.x = x;
		_location.y = y;
		SetCollisionBox(x - _frameWidth / 2, y - _frameHeight / 2);
	}
}

void VisibleGameObject::SetCenter(sf::Vector2f loc) {
	SetCenter(loc.x, loc.y);
}

sf::Vector2f VisibleGameObject::GetCenter()
{
	return _location;
}

void VisibleGameObject::SetRotation(float angle)
{
	if (_isLoaded)
	{
		_sprite.setRotation(angle);
	}
}

void VisibleGameObject::Flip()
{
	if (_isLoaded)
		_sprite.scale(-1.0f, 1.0f);
}

bool VisibleGameObject::Intersects(VisibleGameObject other)
{
	return GetRectangle().intersects(other.GetRectangle());
}

sf::Vector2f * VisibleGameObject::_offset;