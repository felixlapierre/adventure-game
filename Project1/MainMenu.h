#pragma once
#include <list>
#include "Menu.h"
#include "Overworld.h"
#include "Editor.h"

class MainMenu : public Menu
{
public:
	//TODO: Get rid of MenuItem and MenuResult in favor of Buttons
	enum MenuResult { Nothing, Exit, Play, LevelEditor };

	typedef void (MainMenu::* MenuMemberFn)(void);

	struct MenuItem
	{
	public:
		sf::Rect<int> rect;
		MainMenu::MenuMemberFn action;
	};

	Screen * Show(sf::RenderWindow& window);

protected:
	void HandleClick(int x, int y);
	std::list<MenuItem> _menuItems;

	void ExitGame();
	void StartGame();
	void StartLevelEditor();
};