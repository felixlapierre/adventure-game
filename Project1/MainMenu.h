#pragma once
#include <list>
#include "Menu.h"
#include "Overworld.h"
#include "Editor.h"
#include "MenuButton.h"

class MainMenu : public Menu
{
public:
	MainMenu();
	Screen * Show(sf::RenderWindow& window);

private:
	void HandleClick(int x, int y);
	MenuButton exitGameButton;
	MenuButton startGameButton;
	MenuButton levelEditorButton;
};