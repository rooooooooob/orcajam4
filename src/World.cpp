#include "World.hpp"

#include "Player.hpp"

namespace orca
{

World::World(je::Game * const game)
	:Level(game, "orcajam4/levels/world.tmx", 0, 0)
{
	this->addEntity(new Player(this, sf::Vector2f(320 - 8, 240 - 8)));
}

void World::onDraw(sf::RenderTarget& target) const
{
}

void World::loadEntities(const std::string& layerName, const std::vector<EntityPrototype>& prototypes)
{
}

}
