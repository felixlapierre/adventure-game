#pragma once
#include "Screen.h"
#include "Player.h"
#include "VisibleGameObject.h"
#include "Player.h"
#include "Enemy.h"
/*
The Overworld class handles the behavior of the actual game
An instance of the Overworld class contains the player and all elements of their environment
The GameLoop function makes all of these elements move and interact
*/

class Overworld : public Screen
{
public:
	~Overworld();

	enum OverworldResult {
		ExitGame,
		MainMenu
	};
	Screen * Show(sf::RenderWindow& window);

private:
	OverworldResult GameLoop(sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);
	void UpdateOffset(sf::RenderWindow& window);

	sf::Clock _timer;
	float _elapsedTimeSeconds;

	enum GameState
	{
		Playing,
		GameOver,
		Exiting
	};

	GameState _state;
	Player *  _player;

	sf::Vector2f _offset;

	std::vector<GameObject> _obstacles;
	std::vector<VisibleGameObject> _visibles;
	std::vector<Enemy *> _enemies;
	
};