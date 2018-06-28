#pragma once
#include "Screen.h"
class Editor : public Screen
{
public:
	Editor();
	~Editor();
	enum EditorResult {
		ExitGame,
		MainMenu
	};
	Screen * Show(sf::RenderWindow& window);

private:
	EditorResult EditorLoop(sf::RenderWindow& window);
	void Draw(sf::RenderWindow& window);

	enum EditorState
	{
		Viewing,
		Placing,
		Exiting
	};

	EditorState _state;

	std::vector<GameObject> _obstacles;
	std::vector<VisibleGameObject> _visibles;
};

