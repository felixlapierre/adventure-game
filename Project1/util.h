#pragma once
#include "SFML/Graphics.hpp"
namespace util {
	sf::FloatRect overlap(sf::FloatRect rect1, sf::FloatRect rect2);
	float max(float a, float b);
	float min(float a, float b);
	float toRad(float angleAsDeg);
	float toDeg(float angleAsRad);
	sf::Vector2f normalize(sf::Vector2f input);
}