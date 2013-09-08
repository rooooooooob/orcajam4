#include "Boar.hpp"
#include "Player.hpp"
#include "World.hpp"
#include "Game.hpp"
#include "Trig.hpp"

namespace orca
{

Boar::Boar (World * world, const sf::Vector2f& pos, Player *player) :
    Entity (world, "Boar", pos, sf::Vector2i(16, 16)),
    run (world->getGame().getTexManager().get("boar.png"), 16, 16, 10),
    target(player), health(10)
{
}

void Boar::draw(sf::RenderTarget& target) const
{
    run.draw (target);
}

void Boar::update()
{/*
    int px = pos.x;
    int py = pos.y;
    run.apply([px, py](sf::Sprite& sprite){
        sprite.setPosition(px, py);
    });

    sf::Vector2f playerPosition = target->getPos();
    if (je::pointDistance (pos, playerPosition) < 160)//if distance (boar, player) <= angryzone
        attack(playerPosition);//  attack()

*/
}

void Boar::attack(const sf::Vector2f& playerPos)
{
/*
    float endDirection = je::pointDirection(pos, playerPos);

    run.apply ([endDirection] (sf::Sprite& sprite)
    {
       sprite.setRotation (-endDirection);
    });

    if (pos.x > playerPos.x)
    {
        pos.x -= 1;
        run.advanceFrame();
    }
    else if (pos.x < playerPos.x)
    {
        pos.x += 1;
        run.advanceFrame();
    }

    if (pos.y > playerPos.y)
    {
        pos.y -= 1;
        run.advanceFrame();
    }
    else if (pos.y < playerPos.y)
    {
        pos.y += 1;
        run.advanceFrame();
    }*/
}
}
