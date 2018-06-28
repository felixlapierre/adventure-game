#pragma once
#include "stdafx.h"
#include "Screen.h"

class Menu : public Screen {
public:
	Menu();
	Screen * Show(sf::RenderWindow& window);
protected:
	virtual Screen * GetResponseLoop(sf::RenderWindow& window);
	virtual void HandleClick(int x, int y) = 0;
	Screen * returned;
};