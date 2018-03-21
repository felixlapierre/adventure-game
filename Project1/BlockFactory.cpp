#include "stdafx.h"
#include "BlockFactory.h"

BlockFactory::BlockFactory()
{

}


BlockFactory::~BlockFactory()
{

}

GameObject BlockFactory::BuildObstacle(int id, int x, int y, int z, int width, int height, int r) {
	GameObject obj;
	obj.SetCollisionBox(sf::FloatRect(x - width / 2, y - width / 2, width, height));
	return obj;
}

VisibleGameObject BlockFactory::BuildVisible(int id, int x, int y, int z, int width, int height, int r)
{
	VisibleGameObject obj(width, height);
	obj.Load(GetTextureFromId(id));
	obj.SetCenter(x, y);
	return obj;
}
//Should not be called for IDs less than 100 since
//those belong to invisible game objects
sf::Texture * BlockFactory::GetTextureFromId(int id)
{
	//If textures at that id is not null
	if (_textures.find(id) != _textures.end()) {
		return _textures[id];
	}
	std::string filename = "images/";
	switch (id) {
	case 100:
		filename += "block1.png";
		break;
	case 101:
		filename += "stone1.png";
		break;
	case 102:
		filename += "dirt1.png";
		break;
	case 103:
		filename += "gravel1.png";
		break;
	default:
		filename += "block1.png";
		break;
	}
	//Add that texture to the map
	sf::Texture * newTexture = new sf::Texture();
	newTexture->loadFromFile(filename);
	_textures.insert(std::pair<int, sf::Texture *>(id, newTexture));

	//Return the newly created texture
	return _textures[id];
}

std::unordered_map<int, sf::Texture *> BlockFactory::_textures;