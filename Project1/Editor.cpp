#include "stdafx.h"
#include "GameObject.h"
#include "VisibleGameObject.h"
#include "Editor.h"

Editor::Editor()
{
}


Editor::~Editor()
{
	
}

Screen * Editor::Show(sf::RenderWindow& window) {
	//Set state to viewing
	_state = Viewing;

	//Load map from file
	util::loadMapData("maps/map.txt", _obstacles, _visibles);

	EditorLoop(window);
	return nullptr;
}

Editor::EditorResult Editor::EditorLoop(sf::RenderWindow& window) {
	sf::Event event;

	while (_state != Exiting) {

		while (window.pollEvent(event)) {
			//Handle all events
			if (event.type == sf::Event::EventType::Closed)
				_state = Exiting;
			if (event.type == sf::Event::EventType::KeyPressed) {
				//if(event.key.cose == sf::Keyboard::Space)
			}
		}

		//Handle regular isKeyPressed

		Draw(window);
	}
	if (_state == Exiting)
		return ExitGame;
	return MainMenu;
}

void Editor::Draw(sf::RenderWindow& window) {
	window.clear(sf::Color::Color(70, 118, 96, 255));

	for (unsigned int i = 0; i < _visibles.size(); i++) {
		_visibles.at(i).Draw(window);
	}
	
	window.display();
}
