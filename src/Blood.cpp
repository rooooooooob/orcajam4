#include "Blood.hpp"

#include "jam-engine/Core/Game.hpp"
#include "jam-engine/Utility/Random.hpp"

#include "World.hpp"

namespace orca
{

Blood::Blood(World * world, const sf::Vector2f& pos, const sf::Vector2f& velocity)
	:Entity(world, "Blood", pos, sf::Vector2i(4, 4))
	,lifetime(je::random(90) + 30)
	,velocity(velocity)
{
	sprite.setTexture(world->getGame().getTexManager().get("blood.png"));
	int offset = je::random(3) * 4;
	sprite.setTextureRect(sf::IntRect(offset, 0, 4, 4));
	sprite.setPosition(pos);
}

void Blood::onUpdate()
{
	if (lifetime > 45)
	{
		sprite.setPosition(pos);
		pos += velocity;
	}

	if (--lifetime <= 0)
		this->destroy();
}

void Blood::draw(sf::RenderTarget& target, const sf::RenderStates &states /*= sf::RenderStates::Default*/) const
{
	target.draw(sprite);
}

}
