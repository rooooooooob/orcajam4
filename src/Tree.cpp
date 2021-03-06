#include "Tree.hpp"

#include "jam-engine/Core/Game.hpp"
#include "jam-engine/Utility/Random.hpp"

#include "World.hpp"

#include <iostream>

namespace orca
{

Tree::Tree(World * world, const sf::Vector2f& pos)
	:Entity(world, "Tree", pos, sf::Vector2i(8, 8), sf::Vector2i(-4, -4)),
	cutting(world->getGame().getTexManager().get("palm_tree2.png"), 64, 32, 1, false),
	hp(50)
{
	//this->pos.y -= 16;
	//this->pos.x += 16;

	float px = pos.x;
	float py = pos.y;

	cutting.apply ([px, py] (sf::Sprite& sprite)
	{
	   sprite.setPosition (px, py);
	});

	cutting.apply ([] (sf::Sprite& sprite)
	{
		sprite.setOrigin(16, 16);
	});

	/*cutting.apply ([] (sf::Sprite& sprite)
	{
		sprite.setRotation(je::random(360));
	});*/

	depth = -20;
}

void Tree::onUpdate()
{

}

void Tree::draw(sf::RenderTarget& target, const sf::RenderStates &states /*= sf::RenderStates::Default*/) const
{
	cutting.draw(target, states);
}

void Tree::chop()
{
	hp -= 1;
	if (hp == 49 || hp == 25 || hp == 0)
	{
		cutting.advanceFrame();
	}
}


}
