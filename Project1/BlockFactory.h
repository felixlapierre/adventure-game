#pragma once
/*
BlockFactory has static member variables for
each texture used. It has a method that
takes id, location and rotation info and creates
a GameObject or VisibleGameObject from them
*/
#include "GameObject.h"
#include "VisibleGameObject.h"
#include <unordered_map>
class BlockFactory
{
public:
	BlockFactory();
	~BlockFactory();
	static GameObject BuildObstacle(int id, int x, int y, int z, int width, int height, int r);
	static VisibleGameObject BuildVisible(int id, int x, int y, int z, int width, int height, int r);
	static sf::Texture * GetTextureFromId(int id);
private:
	static std::unordered_map<int, sf::Texture *> _textures;
};

