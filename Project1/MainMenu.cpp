#pragma once
#include "stdafx.h"
#include "MainMenu.h"

MainMenu::MainMenu() :
	startGameButton(512, 263, 1024, 235),
	exitGameButton(512, 472, 1024, 235),
	levelEditorButton(512, 678, 1024, 235)
{
	
}

Screen * MainMenu::Show(sf::RenderWindow& window)
{
	//Load menu image from file
	sf::Texture menuTexture;
	menuTexture.loadFromFile("images/MainMenu.png");
	sf::Sprite sprite(menuTexture);
	window.clear(sf::Color::Green);
	window.draw(sprite);
	window.display();

	return Menu::GetResponseLoop(window);
}

void MainMenu::HandleClick(int x, int y)
{
	if (startGameButton.Contains(x, y))
		returned = new Overworld();
	else if (exitGameButton.Contains(x, y))
		returned = nullptr;
	else if (levelEditorButton.Contains(x, y))
		returned = new Editor();
}