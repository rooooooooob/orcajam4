#ifndef ORCA_PLAYER_HPP
#define ORCA_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

namespace orca
{

class World;

class Player : public je::Entity
{
public:
	Player(World * world, const sf::Vector2f& pos);

	void draw(sf::RenderTarget& target) const override;

	void update() override;

private:
	sf::Sprite body;
};

}

#endif // ORCA_PLAYER_HPP
