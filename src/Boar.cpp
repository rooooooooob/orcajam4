#include "Boar.hpp"
#include "Player.hpp"
#include "World.hpp"
#include "Game.hpp"

namespace orca
{

Boar::Boar (World * world, const sf::Vector2f& pos, Player *player) :
    Entity (world, "Boar", pos, sf::Vector2i(16, 16)),
    run (world->getGame().getTexManager().get("boar.png"), 16, 16, 0),
    target(player), health(10)
{

}

void Boar::draw(sf::RenderTarget& target) const
{
    run.draw (target);
}

void Boar::update()
{
    //if distance (boar, player) <= angryzone
    //  attack()
    run.advanceFrame();
}

void Boar::attack()
{
    //move towards player
    //check collision
    //if collision
    //  deal damage
}
}
