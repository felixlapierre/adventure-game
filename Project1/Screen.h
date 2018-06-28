#pragma once
#include "stdafx.h"
class Screen {
public:
	virtual Screen * Show(sf::RenderWindow& window) = 0;
};