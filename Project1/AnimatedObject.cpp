#pragma once
#include "stdafx.h"
#include "AnimatedObject.h"
#include <iostream>

AnimatedObject::AnimatedObject(int frameWidth, int frameHeight) : VisibleGameObject(frameWidth, frameHeight) {
	_source.width = getFrameWidth();
	_source.height = getFrameHeight();
	_timeSinceLastFrame = 0;
};
AnimatedObject::~AnimatedObject()
{

}

void AnimatedObject::Draw(sf::RenderWindow& window)
{
	if (IsLoaded())
	{
		SetTextureRect(_source);
		VisibleGameObject::Draw(window);
	}
}

void AnimatedObject::setAnimation(int row, int frames, float animationDelay)
{
	this->_frames = frames;
	this->_animationDelay = animationDelay;
	_source.top = getFrameHeight() * row;
	_source.left = 0;
	_timeSinceLastFrame = 0;
}

void AnimatedObject::Update(float elapsedTime)
{
	_timeSinceLastFrame += elapsedTime;

	if (_timeSinceLastFrame > _animationDelay)
	{
		_timeSinceLastFrame = 0;
		_source.left += getFrameWidth();
		//If the edge of the animation has been reached, move the source frame back to the left
		if (_source.left / getFrameWidth() >= _frames)
			_source.left = 0;
	}
}