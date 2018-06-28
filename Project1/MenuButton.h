#pragma once
#include "stdafx.h"

class MenuButton {
public:
	MenuButton(float centerX, float centerY, float width, float height);
	bool Contains(float x, float y);
protected:
	sf::FloatRect area;
};
