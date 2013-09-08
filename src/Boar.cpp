#include "Boar.hpp"
#include "World.hpp"
#include "Game.hpp"

namespace orca
{

Boar::Boar (World * world, const sf::Vector2f& pos) :
    Entity (world, "Boar", pos, sf::Vector2i(16, 16)), run (world->getGame().getTexManager().get("boar.png"), 16, 16, 0)
{

}

void Boar::draw(sf::RenderTarget& target) const
{
    //run.draw (target);
}

void Boar::update()
{

}

}
