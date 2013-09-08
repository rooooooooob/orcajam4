#include "World.hpp"

#include "Player.hpp"
#include <iostream>

namespace orca
{

World::World(je::Game * const game)
	:Level(game, "orcajam4/levels/tiny.tmx")
{
	this->loadMap("orcajam4/levels/tiny.tmx");
	this->addEntity(new Player(this, sf::Vector2f(320, 240)));//186 * 16 - 8, 151 * 16 - 8)));
	this->setCameraBounds(sf::Rect<int>(0, 0, 640, 480));
}

void World::onDraw(sf::RenderTarget& target) const
{
}

void World::loadEntities(const std::string& layerName, const std::vector<EntityPrototype>& prototypes)
{
}

void World::transformTiles(const std::string& layerName, int tilesAcross, int tilesHigh, unsigned **tiles)
{
	std::cout << "World::transformTiles()\n";
	//	make a copy of the tiles to refer to while transforming
	unsigned int **untransformed = new unsigned int*[tilesAcross];
	for (int i = 0; i < tilesAcross; ++i)
	{
		untransformed[i] = new unsigned int[tilesHigh];
		for (int j = 0; j < tilesHigh; ++j)
			untransformed[i][j] = tiles[i][j];
	}
	/**		modify tiles here (this is your job Max)		**/
	if (layerName == "terrain")
	{
		for (int x = 0; x < tilesAcross; ++x)
		{
			for (int y = 0; y < tilesAcross; ++y)
			{

			}
		}
	}

	for (int i = 0; i < tilesAcross; ++i)
		delete[] untransformed[i];
	delete[] untransformed;
}

}
