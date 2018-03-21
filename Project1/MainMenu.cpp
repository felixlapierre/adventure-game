#pragma once
#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
	//Load menu image from file
	sf::Texture menuTexture;
	menuTexture.loadFromFile("images/MainMenu.png");
	sf::Sprite sprite(menuTexture);

	//Setup clickable regions

	//Play menu item coordinates
	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.height = 380 - 145;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.action = Play;

	//Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.rect.top = 383;
	exitButton.rect.height = 560 - 383;
	exitButton.action = Exit;

	MenuItem editorButton;
	editorButton.rect.left = 0;
	editorButton.rect.width = 1023;
	editorButton.rect.top = 560;
	editorButton.rect.height = 235;
	editorButton.action = Editor;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	window.clear(sf::Color::Green);
	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.top + menuItemRect.height > y
			&& menuItemRect.top < y
			&& menuItemRect.left < x
			&& menuItemRect.left + menuItemRect.width > x)
		{
			return (*it).action;
		}
	}

	return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event event;

	while (true)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::MouseButtonPressed)
				return HandleClick(event.mouseButton.x, event.mouseButton.y);
		}
		if (event.type == sf::Event::EventType::MouseButtonPressed )
		{
			return Exit;
		}
	}
}