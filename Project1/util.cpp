#pragma once
#include "util.h"
#include <fstream>
#include <iostream>
#include "BlockFactory.h"
namespace util {
	sf::FloatRect overlap(sf::FloatRect rect1, sf::FloatRect rect2) {
		return sf::FloatRect(max(rect1.left, rect2.left), 
			max(rect1.top, rect2.top), 
			min(rect1.left + rect1.width, rect2.left + rect2.width) - max(rect1.left, rect2.left),
			min(rect1.top + rect1.height, rect2.top + rect2.height) - max(rect1.top, rect2.top));
	}

	float max(float a, float b) {
		if (a >= b)
			return a;
		return b;
	}

	float min(float a, float b) {
		if (a <= b)
			return a;
		return b;
	}
	float toRad(float angleAsDeg)
	{
		return angleAsDeg / 180 * 3.1415f;
	}
	float toDeg(float angleAsRad)
	{
		return angleAsRad / 3.1415f * 180;
	}
	sf::Vector2f normalize(sf::Vector2f input) {
		float magnitude = sqrtf(input.x * input.x + input.y * input.y);
		input.x /= magnitude;
		input.y /= magnitude;
		return input;
	}
	void loadMapData(std::string filename, std::vector<GameObject>& obstacles, std::vector<VisibleGameObject>& visibles)
	{
		//Create input file stream
		std::ifstream mapfile(filename);
		std::string line;
		if (mapfile.is_open()) {
			int id, x, y, z, w, h, r;
			while (!mapfile.eof()) {
				mapfile >> id >> x >> y >> z >> w >> h >> r;
				if (id < 100) {
					obstacles.push_back(BlockFactory::BuildObstacle(id, x, y, z, w, h, r));
				}
				else {
					visibles.push_back(BlockFactory::BuildVisible(id, x, y, z, w, h, r));
				}
			}
			mapfile.close();
		}
	}
}