#pragma once
#include "stdafx.h"
#include "Game.h"
#include <iostream>

using namespace sf;

int main(int argc, char** argv)
{
	Game::Start();
	return 0;
	
	//The rest of the code will never run and i'm keeping it there just incase 
	//I want to look at it again later

	//Create the game window
	RenderWindow renderWindow(sf::VideoMode(640, 480), "Hello SFML");

	//Window will only throw one event when a key is held down
	renderWindow.setKeyRepeatEnabled(false);

	Event event; //to hold the Events that occur in the window

	Clock clock; //A clock starts counting as soon as it's created

	sf::Texture player1Texture;
	player1Texture.loadFromFile("images/PlayerSprite1.png");
	IntRect playerRect(0, 0, 50, 50);
	sf::Sprite playerSprite(player1Texture, playerRect);
	srand((unsigned int)time(NULL));

	playerSprite.setPosition(300.0f, 300.0f);
	sf::Color backgroundColor(Color::Red);

	//Loop until the window is closed
	while (renderWindow.isOpen()) {
		//Check for all the events that occurred since the last frame
		//pollEvent returns false when no more events exists
		//Events occur for things like mouse and keyboard actions
		while (renderWindow.pollEvent(event))
		{
			//Handle all events here
			if (event.type == Event::EventType::Closed) {
				renderWindow.close();
			}

			//Respond to key pressed events
			if (event.type == sf::Event::EventType::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					playerSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y - 50);
				}
				if (event.key.code == sf::Keyboard::S)
				{
					playerSprite.setPosition(playerSprite.getPosition().x, playerSprite.getPosition().y + 50);
				}
			}


		}

		//Print the elapsed time
		//std::cout << "Elapsed time since previous frame: " << clock.getElapsedTime().asMilliseconds() << std::endl;
		if (clock.getElapsedTime().asSeconds() > 0.2f)
		{
			if (playerRect.left == 200)
				playerRect.left = 0;
			else
				playerRect.left += 50;
			playerSprite.setTextureRect(playerRect);
			clock.restart();
		}



		//Clear the window back to a black screen
		renderWindow.clear(backgroundColor);

		renderWindow.draw(playerSprite);
		//Show the window
		renderWindow.display();

	}
	return 0;
}