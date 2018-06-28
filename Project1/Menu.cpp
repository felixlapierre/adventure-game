#include "Menu.h"

Menu::Menu()
{
	returned = nullptr;
}

Screen * Menu::Show(sf::RenderWindow& window) {
	return GetResponseLoop(window);
}

Screen * Menu::GetResponseLoop(sf::RenderWindow & window)
{
	sf::Event event; //To hold the current event

	while (returned == nullptr) 
		while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::EventType::MouseButtonPressed:
			HandleClick(event.mouseButton.x, event.mouseButton.y);
			break;
		case sf::Event::EventType::Closed:
			return nullptr; //To indicate that there is no next screen
			break;
		}
	}
	return returned;
}
