#pragma once
#include "stdafx.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "Editor.h"
#include "Overworld.h"
#include "Game.h"

void Game::Start(void)
{
	/* Old game code
	if (_gameState != Uninitialized)
		return;
	_gameState = Game::ShowingSplash;
	*/

	window.create(sf::VideoMode(WindowWidth, WindowHeight, 32), "RPG Game");

	Screen * currentScreen = new SplashScreen();
	Screen * nextScreen;

	while (currentScreen != nullptr)
	{
		nextScreen = currentScreen->Show(window);
		delete currentScreen;
		currentScreen = nextScreen;
	}

	window.close();
}

/* Old game code, not deleting yet just in case
bool Game::IsExiting() {
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (_gameState)
		{
		case Game::ShowingSplash:
		{
			ShowSplashScreen();
			break;
		}
		case Game::ShowingMenu:
		{
			ShowMenu();
			break;
		}
		case Game::Playing:
		{
			ShowOverworld();
			break;
		}
		case Game::LevelEditor:
			ShowEditor();
			break;
		}
	}
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(window);

	switch (result)
	{
	case MainMenu::Exit:
		_gameState = Game::Exiting;
		break;
	case MainMenu::Play:
		_gameState = Game::Playing;
		break;
	case MainMenu::LevelEditor:
		_gameState = Game::LevelEditor;
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(window);
	_gameState = Game::ShowingMenu;
}

void Game::ShowOverworld()
{
	Overworld overworld;
	Overworld::OverworldResult result = overworld.Show(window);
	if (result == Overworld::OverworldResult::ExitGame)
		_gameState = Exiting;
	else
		_gameState = ShowingMenu;
}

void Game::ShowEditor() {
	LevelEditor editor;
	LevelEditor::EditorResult result = editor.Show(window);
	if (result == LevelEditor::EditorResult::ExitGame)
		_gameState = Exiting;
	else
		_gameState = ShowingMenu;
}

Game::GameState Game::_gameState = Uninitialized;
*/
sf::RenderWindow Game::window;