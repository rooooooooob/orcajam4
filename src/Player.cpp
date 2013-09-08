#include "Player.hpp"

#include "TexManager.hpp"

#include "World.hpp"
#include "Game.hpp"
#include "Trig.hpp"

namespace orca
{

Player::Player(World * world, const sf::Vector2f& pos)
	:Entity(world, "Player", pos, sf::Vector2i(16, 16))
	,controller(world->getGame().getInput())
{
	body.setTexture(world->getGame().getTexManager().get("player.png"));
	body.setOrigin(8, 8);
	bbox.setSize(sf::Vector2f(16, 16));
	bbox.setOutlineColor(sf::Color::Red);
	bbox.setOutlineThickness(1);
	bbox.setFillColor(sf::Color::Transparent);
	controller.setKeybinds("up", {je::Controller::Bind(sf::Keyboard::Up), je::Controller::Bind(sf::Keyboard::W)});
	controller.setKeybinds("left", {je::Controller::Bind(sf::Keyboard::Left), je::Controller::Bind(sf::Keyboard::A)});
	controller.setKeybinds("down", {je::Controller::Bind(sf::Keyboard::Down), je::Controller::Bind(sf::Keyboard::S)});
	controller.setKeybinds("right", {je::Controller::Bind(sf::Keyboard::Right), je::Controller::Bind(sf::Keyboard::D)});
	depth = -10;
}

void Player::draw(sf::RenderTarget& target) const
{
	target.draw(body);
	target.draw(bbox);
}

void Player::update()
{
	if (controller.isActionHeld("left"))
	{
		pos.x -= 4;
	}
	if (controller.isActionHeld("right"))
	{
		pos.x += 4;
	}
	if (controller.isActionHeld("up"))
	{
		pos.y -= 4;
	}
	if (controller.isActionHeld("down"))
	{
		pos.y += 4;
	}

	body.setPosition(pos);
	body.setRotation(-je::pointDirection(pos, controller.getMousePos()));


	bbox.setPosition(pos);

	level->setCameraPosition(pos);
}

}
