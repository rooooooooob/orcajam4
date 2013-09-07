#include "Player.hpp"

#include "TexManager.hpp"

#include "World.hpp"

namespace orca
{

Player::Player(World * world, const sf::Vector2f& pos)
	:Entity(world, "Player", pos, sf::Vector2i(16, 16))
{
	body.setTexture(je::TexManager::get("player.png"));
}

void Player::draw(sf::RenderTarget& target) const
{
	target.draw(body);
}

void Player::update()
{
	body.setPosition(pos);
}

}
