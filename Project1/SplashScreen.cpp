#pragma once
#include "stdafx.h"
#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow & renderWindow)
{
	sf::Color splashScreenColor(sf::Color::Blue);

	renderWindow.clear(splashScreenColor);
	renderWindow.display();

	sf::Event event;
	while (renderWindow.isOpen())
	{
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed)
				return;
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();
		}
	}
}