#include "World.hpp"
#include "Random.hpp"
#include "Player.hpp"
#include <iostream>

namespace orca
{

World::World(je::Game * const game)
	:Level(game, "orcajam4/levels/world.tmx")
{
	this->setCameraBounds(sf::Rect<int>(0, 0, 640, 480));
	this->loadMap("orcajam4/levels/world.tmx");
	this->addEntity(new Player(this, sf::Vector2f(90 * 16 - 8, 200 * 16 - 8)));
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
	    enum TileType { Water = 0, Sand = 10,Grass = 34 };

		for (int x = 0; x < tilesAcross; ++x)
		{
			for (int y = 0; y < tilesAcross; ++y)
			{
                if (untransformed[x][y] == Sand)
                {
                    if ((untransformed[x - 1][y] == Water) && (untransformed[x + 1][y] == Water) && (untransformed[x][y + 1] == Water))
                    {
                        tiles[x][y] = 16;
                    }
                    else if ((untransformed[x - 1][y] == Water) && (untransformed[x + 1][y] == Water) && (untransformed[x][y - 1] == Water))
                    {
                        tiles[x][y] = 15;
                    }
                    else if ((untransformed[x][y - 1] == Water) && (untransformed[x][y + 1] == Water) && (untransformed[x + 1][y] == Water))
                    {
                        tiles[x][y] = 8;
                    }
                    else if ((untransformed[x][y - 1] == Water) && (untransformed[x][y + 1] == Water) && (untransformed[x - 1][y] == Water))
                    {
                        tiles[x][y] = 7;
                    }
                    else if ((untransformed[x - 1][y] == Water) && (untransformed[x][y - 1] == Water))
                    {
                        tiles[x][y] = 1;
                    }
                    else if ((untransformed[x - 1][y] == Water) && (untransformed[x][y + 1] == Water))
                    {
                        tiles[x][y] = 17;
                    }
                    else if ((untransformed[x + 1][y] == Water) && (untransformed[x][y - 1] == Water))
                    {
                        tiles[x][y] = 3;
                    }
                    else if ((untransformed[x + 1][y] == Water) && (untransformed[x][y + 1] == Water))
                    {
                        tiles[x][y] = 19;
                    }
                    else if (untransformed[x + 1][y] == Water)
                    {
                        tiles[x][y] = 11;
                    }
                    else if (untransformed[x - 1][y] == Water)
                    {
                        tiles[x][y] = 9;
                    }
                    else if (untransformed[x][y + 1] == Water)
                    {
                        tiles[x][y] = 18;
                    }
                    else if (untransformed[x][y - 1] == Water)
                    {
                        tiles[x][y] = 2;
                    }
                }
                else if (untransformed[x][y] == Grass)
                {
                    if ((untransformed[x - 1][y] == Sand) && (untransformed[x + 1][y] == Sand) && (untransformed[x][y + 1] == Sand))
                    {
                        tiles[x][y] = 32;
                    }
                    else if ((untransformed[x - 1][y] == Sand) && (untransformed[x + 1][y] == Sand) && (untransformed[x][y - 1] == Sand))
                    {
                        tiles[x][y] = 31;
                    }
                    else if ((untransformed[x][y - 1] == Sand) && (untransformed[x][y + 1] == Sand) && (untransformed[x + 1][y] == Sand))
                    {
                        tiles[x][y] = 24;
                    }
                    else if ((untransformed[x][y - 1] == Sand) && (untransformed[x][y + 1] == Sand) && (untransformed[x - 1][y] == Sand))
                    {
                        tiles[x][y] = 23;
                    }
                    else if ((untransformed[x - 1][y] == Sand) && (untransformed[x][y - 1] == Sand))
                    {
                        tiles[x][y] = 25;
                    }
                    else if ((untransformed[x - 1][y] == Sand) && (untransformed[x][y + 1] == Sand))
                    {
                        tiles[x][y] = 41;
                    }
                    else if ((untransformed[x + 1][y] == Sand) && (untransformed[x][y - 1] == Sand))
                    {
                        tiles[x][y] = 27;
                    }
                    else if ((untransformed[x + 1][y] == Sand) && (untransformed[x][y + 1] == Sand))
                    {
                        tiles[x][y] = 43;
                    }
                    else if (untransformed[x + 1][y] == Sand)
                    {
                        tiles[x][y] = 35;
                    }
                    else if (untransformed[x - 1][y] == Sand)
                    {
                        tiles[x][y] = 33;
                    }
                    else if (untransformed[x][y + 1] == Sand)
                    {
                        tiles[x][y] = 42;
                    }
                    else if (untransformed[x][y - 1] == Sand)
                    {
                        tiles[x][y] = 26;
                    }
                    else if (untransformed[x + 1][y + 1] == Sand)
                    {
                        tiles[x][y] = 28;
                    }
                    else if (untransformed[x + 1][y - 1] == Sand)
                    {
                        tiles[x][y] = 44;
                    }
                    else if (untransformed[x - 1][y + 1] == Sand)
                    {
                        tiles[x][y] = 30;
                    }
                    else if (untransformed[x + 1][y + 1] == Sand)
                    {
                        tiles[x][y] = 46;
                    }
                    else
                    {
                        unsigned short int rand = je::random (20);

                        if (rand == 0)
                        {
                            tiles[x][y] = 5;
                        }
                        else if (rand == 1)
                        {
                            tiles[x][y] = 12;
                        }
                        else if (rand == 2)
                        {
                            tiles[x][y] = 14;
                        }
                        else if (rand == 3)
                        {
                            tiles[x][y] = 21;
                        }
                    }
                }
			}
		}
	}

	for (int i = 0; i < tilesAcross; ++i)
		delete[] untransformed[i];
	delete[] untransformed;
}

}
