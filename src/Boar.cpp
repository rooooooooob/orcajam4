#include "Boar.hpp"
#include "Player.hpp"
#include "World.hpp"
#include "Game.hpp"
#include "Trig.hpp"
#include <iostream>

namespace orca
{

Boar::Boar (World * world, const sf::Vector2f& pos, Player *player) :
    Entity (world, "Boar", pos, sf::Vector2i(16, 16)),
    run (world->getGame().getTexManager().get("boar.png"), 16, 16, 10),
    target(player), health(10), stareTime (0), state (Roam), chargeTarget (0, 0)
{
    run.apply([](sf::Sprite& sprite){
        sprite.setOrigin(8, 8);
    });
}

void Boar::draw(sf::RenderTarget& target) const
{
    run.draw (target);
}

void Boar::update()
{
    int px = pos.x;
    int py = pos.y;
    run.apply([px, py](sf::Sprite& sprite){
        sprite.setPosition(px, py);
    });

    std::cout << "state: " << state;
    sf::Vector2f playerPos = target->getPos();
    switch (state)
    {
        case Roam:
        {
            if (je::pointDistance (pos, target->getPos()) <= 320)
                state = Follow;
            break;
        }

        case Follow:
        {
            float direction = je::pointDirection(pos, playerPos);

            run.apply ([direction] (sf::Sprite& sprite)
            {
               sprite.setRotation (-direction);
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
            }

            if (je::pointDistance (pos, playerPos) <= 160)
            {
                state = Stare;
                stareTime = 0;
            }
            break;
        }

        case Stare:
        {
            if (stareTime < 100)
            {
                float direction = je::pointDirection(pos, playerPos);

                run.apply ([direction] (sf::Sprite& sprite)
                {
                   sprite.setRotation (-direction);
                });

                ++stareTime;
            }
            else
            {
                state = Charge;
                chargeTarget = playerPos;
            }
            break;
        }

        case Charge:
        {
            sf::Rect<float> boaR (pos, sf::Vector2f (16, 16));
            if (!boaR.contains(playerPos))
            {
                if (pos.x > playerPos.x)
                {
                    pos.x -= 3;
                    run.advanceFrame();
                    run.advanceFrame();
                }
                else if (pos.x < playerPos.x)
                {
                    pos.x += 3;
                    run.advanceFrame();
                    run.advanceFrame();
                }

                if (pos.y > playerPos.y)
                {
                    pos.y -= 3;
                    run.advanceFrame();
                    run.advanceFrame();
                }
                else if (pos.y < playerPos.y)
                {
                    pos.y += 3;
                    run.advanceFrame();
                    run.advanceFrame();
                }
            }
            else
                state = Roam;
            break;
        }
    }


}
}
