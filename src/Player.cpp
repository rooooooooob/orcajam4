#include "Player.hpp"

#include "TexManager.hpp"

#include "World.hpp"
#include "Game.hpp"
#include "Trig.hpp"
#include "Level.hpp"

namespace orca
{

Player::Player(World * world, const sf::Vector2f& pos)
	:Entity(world, "Player", pos, sf::Vector2i(16, 16))
	,controller(world->getGame().getInput())
	,legs(world->getGame().getTexManager().get("player_legs.png"), 16, 16, 0)
	,walking(world->getGame().getTexManager().get("player_walking.png"), 16, 16, 0)
	,attacking(world->getGame().getTexManager().get("player_attacking.png"), 16, 16, 0)
	,speed(2)
	,state(State::Walking)
{
	legs.apply([](sf::Sprite& sprite){
		sprite.setOrigin(8, 8);
	});
	walking.apply([](sf::Sprite& sprite){
		sprite.setOrigin(8, 8);
	});
	attacking.apply([](sf::Sprite& sprite){
		sprite.setOrigin(8, 8);
	});
	stunned.setTexture(world->getGame().getTexManager().get("player.png"));
	stunned.setOrigin(8, 8);
	controller.setKeybinds("up", {je::Controller::Bind(sf::Keyboard::Up), je::Controller::Bind(sf::Keyboard::W)});
	controller.setKeybinds("left", {je::Controller::Bind(sf::Keyboard::Left), je::Controller::Bind(sf::Keyboard::A)});
	controller.setKeybinds("down", {je::Controller::Bind(sf::Keyboard::Down), je::Controller::Bind(sf::Keyboard::S)});
	controller.setKeybinds("right", {je::Controller::Bind(sf::Keyboard::Right), je::Controller::Bind(sf::Keyboard::D)});
	depth = -10;
}

void Player::draw(sf::RenderTarget& target) const
{
	switch (state)
	{
		case State::Walking:
			walking.draw(target);
			break;
		case State::Attacking:
			attacking.draw(target);
			break;
		case State::Stunned:
			target.draw(stunned);
			break;
		case State::Wading:
			walking.draw(target);
			break;
		case State::Drowning:
			break;
	}
}

void Player::update()
{
	float mouseAim = -je::pointDirection(pos, level->getCursorPos());
	bool isMoving = false;
	sf::Vector2f dir(0, 0);
	if (controller.isActionHeld("left"))
	{
		dir.x -= 1;
		isMoving = true;
	}
	if (controller.isActionHeld("right"))
	{
		dir.x += 1;
		isMoving = true;
	}
	if (controller.isActionHeld("up"))
	{
		dir.y -= 1;
		isMoving = true;
	}
	if (controller.isActionHeld("down"))
	{
		dir.y += 1;
		isMoving = true;
	}
	dir = je::lengthdir(speed, je::pointDirection(sf::Vector2f(0, 0), dir));

	switch (state)
	{
		case State::Walking:
			{
				if (isMoving &&
					!level->testCollision(this, "Tree", dir.x, dir.y) &&
					!level->testCollision(this, "SolidTerrain", dir.x, dir.y))
				{
					pos += dir;
				}
				int px = pos.x;
				int py = pos.y;
				walking.apply([mouseAim, px, py](sf::Sprite& sprite){
					sprite.setPosition(px, py);
					sprite.setRotation(mouseAim);
				});
			}
			break;
		case State::Stunned:
			stunned.setPosition(pos);
			stunned.setRotation(mouseAim);
			break;
		default:
			break;
	}

	level->setCameraPosition(pos);
}

}
