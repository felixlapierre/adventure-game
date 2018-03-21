#pragma once
#include "VisibleGameObject.h"
class AnimatedObject : 
	public VisibleGameObject
{
public:
	AnimatedObject(int frameWidth, int frameHeight);
	virtual ~AnimatedObject();
	virtual void Update(float elapsedTime);
	virtual void Draw(sf::RenderWindow& window);
	void setAnimation(int row, int frames, float animationDelay);
	sf::IntRect GetSource() { return _source; }
private:
	float _animationDelay = 1000;
	float _timeSinceLastFrame;
	sf::IntRect _source;
	
	int _frames = 1;
};
