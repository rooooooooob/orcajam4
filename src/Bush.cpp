#include "Bush.hpp"

#include "Random.hpp"
#include "World.hpp"
#include "Game.hpp"

namespace orca
{

Bush::Bush(World * world, const sf::Vector2f& pos)
	:Entity(world, "Bush", pos, sf::Vector2i(16, 16), sf::Vector2i(-8, -8))
	,hp(10)
{
	this->pos.y -= 32;
	sprite.setTexture(world->getGame().getTexManager().get("bush.png"));
	sprite.setPosition(this->pos);
	sprite.setOrigin(16, 16);
	sprite.setRotation(je::random(360));
	depth = -15;
}

void Bush::onUpdate()
{

}

void Bush::draw(sf::RenderTarget& target, const sf::RenderStates &states /*= sf::RenderStates::Default*/) const
{
	target.draw(sprite, states);
}

}
