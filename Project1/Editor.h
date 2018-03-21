#pragma once
class Editor
{
public:
	Editor();
	~Editor();

	int Show(sf::RenderWindow& window);

private:
	int EditorLoop(sf::RenderWindow& window);
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

