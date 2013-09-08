#include "Tree.hpp"

#include "Random.hpp"
#include "World.hpp"
#include "Game.hpp"

namespace orca
{

Tree::Tree(World * world, const sf::Vector2f& pos)
	:Entity(world, "Tree", pos, sf::Vector2i(16, 16), sf::Vector2i(8, 8))
	,hp(10)
{
	this->pos.y -= 16;
	this->pos.x += 16;
	sprite.setTexture(world->getGame().getTexManager().get("palm_tree.png"));
	sprite.setPosition(this->pos);
	sprite.setOrigin(16, 16);
	sprite.setRotation(je::random(360));
}

void Tree::update()
{

}

void Tree::draw(sf::RenderTarget& target) const
{

	target.draw(sprite);
}

}
