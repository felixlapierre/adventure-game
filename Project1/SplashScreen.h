#pragma once
#include "Menu.h"
#include "MainMenu.h"

class SplashScreen : public Menu
{
public:
	Screen * Show(sf::RenderWindow& window);
protected:
	void HandleClick(int x, int y);
};