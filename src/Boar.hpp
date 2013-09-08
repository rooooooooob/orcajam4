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
    Boar (World * world, const sf::Vector2f& pos);
    void draw(sf::RenderTarget& target) const override;
	void update() override;
	void attack(Player& target);

private:
    je::Animation run;
    //je::Animation attack;
    int health;
    void find();

};
}


#endif // BOAR_HPP_INCLUDED
