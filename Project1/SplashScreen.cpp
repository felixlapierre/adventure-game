#pragma once
#include "stdafx.h"
#include "SplashScreen.h"

Screen * SplashScreen::Show(sf::RenderWindow & window)
{
	sf::Color splashScreenColor(sf::Color::Blue);

	window.clear(splashScreenColor);
	window.display();

	return Menu::GetResponseLoop(window);
}

void SplashScreen::HandleClick(int x, int y) {
	//Regardless of where you click, progress to the main menu
	returned = new MainMenu();
}