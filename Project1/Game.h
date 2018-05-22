#pragma once
class Game
{
public:
	static void Start();
	static const int WindowWidth = 1024;
	static const int WindowHeight = 768;
private:
	static bool IsExiting();
	static void GameLoop();
	
	static void ShowSplashScreen();
	static void ShowMenu();
	static void ShowOverworld();
	static void ShowEditor();

	enum GameState {
		Uninitialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting, LevelEditor
	};

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
};