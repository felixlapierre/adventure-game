#pragma once
#include "stdafx.h"
//#include "Player.h"
#include "Sword.h"
#include "Skeleton.h"
#include "BlockFactory.h"
#include "Overworld.h"
#include <iostream>
#include <fstream>
#include <vector>

int Overworld::Show(sf::RenderWindow& window) {
	//Set state to playing
	_state = Playing;

	//Create player
	_player = new Player(&window);
	(*_player).Load("images/PlayerSprite1.png");
	(*_player).SetCenter((float)window.getSize().x / 2, (float)window.getSize().y / 2);
	_player->setWeapon1(new Sword());

	//Load map from file
	std::ifstream mapfile("maps/map.txt");
	std::string line;
	if (mapfile.is_open()) {
		int id, x, y, z, w, h, r;
		while (!mapfile.eof()) {
			mapfile >> id >> x >> y >> z >> w >> h >> r;
			if (id < 100) {
				_obstacles.push_back((BlockFactory::BuildObstacle(id, x, y, z, w, h, r)));
			}
			else {
				_visibles.push_back(BlockFactory::BuildVisible(id, x, y, z, w, h, r));
			}

		}
		mapfile.close();
	}

	//Create testing obstacles
	_obstacles.push_back(GameObject(sf::FloatRect(0, 0, 50, 50)));

	//Create testing visible textures
	VisibleGameObject block(50, 50);
	block.Load("images/block1.png");
	block.SetCenter(50 / 2, 50 / 2);
	_visibles.push_back(block);
	
	//Create enemies
	_enemies.push_back(new Skeleton());
	_enemies.at(0)->SetCenter(100, 100);

	return GameLoop(window);
}

int Overworld::GameLoop(sf::RenderWindow& window)
{
	sf::Event event;
	_timer.restart();
	

	while (_state != GameOver && _state != Exiting) {
		//Get the time elapsed since the last update.
		//Then, reset the clock to count until the next update.
		_elapsedTimeSeconds = (float)_timer.getElapsedTime().asMicroseconds() / 1E+6f;
		_timer.restart();


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
				_state = Exiting;
			if (event.type == sf::Event::EventType::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
					(*_player).SetVelocity((*_player).GetVelocity() * 5.0f);
			}
		}
		
		//Determine player's velociy
		sf::Vector2f playerVelocity(0,0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			playerVelocity.y -= 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			playerVelocity.x -= 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			playerVelocity.y += 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			playerVelocity.x += 1;
		(*_player).keysPressed[0] = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		(*_player).keysPressed[1] = sf::Mouse::isButtonPressed(sf::Mouse::Right);

		(*_player).setDesiredVelocity(playerVelocity);
		(*_player).Update(_elapsedTimeSeconds);

		for (unsigned int i = 0; i < _obstacles.size(); i++) {
			(*_player).collide(_obstacles.at(i));
			for (unsigned int j = 0; j < _enemies.size(); j++) {
				_enemies.at(j)->collide(_obstacles.at(i));
			}
		}

		for (unsigned int i = 0; i < _enemies.size(); i++) {
			_enemies.at(i)->Update(_elapsedTimeSeconds, _player->GetCenter());
			_player->Attack(_enemies.at(i));
			_enemies.at(i)->Attack(_player);
		}
		Draw(window);
	}
	return 0;
}

void Overworld::Draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::Color(70,118,96,255));

	for (unsigned int i = 0; i < _visibles.size(); i++) {
		_visibles.at(i).Draw(window);
	}
	for (unsigned int i = 0; i < _enemies.size(); i++) {
		_enemies.at(i)->Draw(window);
	}
	(*_player).Draw(window);
	//Debugging code to display where collision rectangle is
	//sf::RectangleShape testRect(sf::Vector2f(_player.GetCollisionBox().width, _player.GetCollisionBox().height));
	//testRect.setPosition(_player.GetLeft(), _player.GetTop());
	//window.draw(testRect);

	window.display();
}
