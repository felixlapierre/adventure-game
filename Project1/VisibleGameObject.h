#pragma once
#include "GameObject.h"
class VisibleGameObject : public GameObject
{
public:
	//Constructor
	//Give the width and height of a single animation frame
	VisibleGameObject(int frameWidth, int frameHeight);
	virtual ~VisibleGameObject();

	virtual void Load(std::string filename);
	virtual void Load(sf::Texture * texture);
	virtual void Draw(sf::RenderWindow& window);
	
	virtual sf::FloatRect GetRectangle() { return GetCollisionBox(); }
	float GetLeft() { return GetRectangle().left; }
	float GetRight() { return GetRectangle().left + GetRectangle().width; }
	float GetTop() { return GetRectangle().top; }
	float GetBottom() { return GetRectangle().top + GetRectangle().height; }

	int getFrameWidth() { return _frameWidth; }
	int getFrameHeight() { return _frameHeight; }

	bool IsLoaded() { return _isLoaded; }

	bool Intersects(VisibleGameObject other);

	virtual void SetCenter(float x, float y);
	sf::Vector2f GetCenter() { return _sprite.getPosition(); };
	
	virtual void SetRotation(float angle);
	virtual void Flip();
	void SetTextureRect(sf::IntRect rect) { _sprite.setTextureRect(rect); }
	bool _visible;
private:
	sf::Sprite _sprite;
	sf::Texture * _texture;
	std::string _fileName;
	int _frameWidth;
	int _frameHeight;
	bool _isLoaded;
};