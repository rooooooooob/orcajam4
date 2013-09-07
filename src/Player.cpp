#include "Player.hpp"

#include "TexManager.hpp"

#include "World.hpp"
#include "Game.hpp"

namespace orca
{

Player::Player(World * world, const sf::Vector2f& pos)
	:Entity(world, "Player", pos, sf::Vector2i(16, 16))
{
	body.setTexture(world->getGame().getTexManager().get("player.png"));
	bbox.setSize(sf::Vector2f(16, 16));
	bbox.setOutlineColor(sf::Color::Red);
	bbox.setOutlineThickness(1);
	bbox.setFillColor(sf::Color::Transparent);
}

void Player::draw(sf::RenderTarget& target) const
{
	target.draw(body);
	target.draw(bbox);
}

void Player::update()
{
	body.setPosition(pos);
	bbox.setPosition(pos);
	level->setCameraPosition(pos);
}

}
