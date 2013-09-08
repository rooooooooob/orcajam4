#ifndef BOAR_HPP_INCLUDED
#define BOAR_HPP_INCLUDED

#include "Entity.hpp"
#include "Animation.hpp"

namespace orca
{

class World;
class Player;

class Boar: public je::Entity
{
public:
    Boar (World * world, const sf::Vector2f& pos, Player *player);
    void draw(sf::RenderTarget& target) const override;
	void update() override;
	void attack();

private:
    je::Animation run;
    //je::Animation attack;
    Player* target;
    int health;

};
}


#endif // BOAR_HPP_INCLUDED
