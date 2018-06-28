#pragma once
#include "stdafx.h"
#include "MainMenu.h"

Screen * MainMenu::Show(sf::RenderWindow& window)
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
	playButton.action = &MainMenu::StartGame;

	//Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.rect.top = 383;
	exitButton.rect.height = 560 - 383;
	exitButton.action = &MainMenu::ExitGame;

	MenuItem editorButton;
	editorButton.rect.left = 0;
	editorButton.rect.width = 1023;
	editorButton.rect.top = 560;
	editorButton.rect.height = 235;
	editorButton.action = &MainMenu::StartLevelEditor;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);
	_menuItems.push_back(editorButton);

	window.clear(sf::Color::Green);
	window.draw(sprite);
	window.display();

	return Menu::GetResponseLoop(window);
}

void MainMenu::HandleClick(int x, int y)
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
			//TODO: Make this less ugly cause what the heck
			((*this).*((*it).action))(); //the devil
			return;
		}
	}

	return;//Nothing;
}

void MainMenu::StartGame() {
	returned = new Overworld();
}

void MainMenu::StartLevelEditor() {
	returned = new Editor();
}

void MainMenu::ExitGame() {
	returned = nullptr;
}