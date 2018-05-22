#pragma once
#include "stdafx.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "Editor.h"
#include "Overworld.h"
#include "Game.h"

void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(WindowWidth, WindowHeight, 32), "RPG Game");
	_gameState = Game::ShowingSplash;

	while (!IsExiting())
	{
		GameLoop();
	}

	_mainWindow.close();
}

bool Game::IsExiting() {
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	sf::Event event;
	while (_mainWindow.pollEvent(event))
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
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);

	switch (result)
	{
	case MainMenu::Exit:
		_gameState = Game::Exiting;
		break;
	case MainMenu::Play:
		_gameState = Game::Playing;
		break;
	case MainMenu::Editor:
		_gameState = Game::LevelEditor;
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowOverworld()
{
	Overworld overworld;
	Overworld::OverworldResult result = overworld.Show(_mainWindow);
	if (result == Overworld::OverworldResult::ExitGame)
		_gameState = Exiting;
	else
		_gameState = ShowingMenu;
}

void Game::ShowEditor() {
	Editor editor;
	Editor::EditorResult result = editor.Show(_mainWindow);
	if (result == Editor::EditorResult::ExitGame)
		_gameState = Exiting;
	else
		_gameState = ShowingMenu;
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;