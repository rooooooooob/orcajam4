#include "Player.hpp"

#include "TexManager.hpp"

#include "World.hpp"
#include "Game.hpp"
#include "Trig.hpp"
#include "Level.hpp"

static const int DROWNING_ANIMATION_TIME = 60;

namespace orca
{

Player::Player(World * world, const sf::Vector2f& pos)
	:Entity(world, "Player", pos, sf::Vector2i(16, 16))
	,world(world)
	,controller(world->getGame().getInput())
	,legs(world->getGame().getTexManager().get("player_legs.png"), 16, 16, 5)
	,walking(world->getGame().getTexManager().get("player_walking.png"), 16, 16, 6)
	,attacking(world->getGame().getTexManager().get("player_attacking.png"), 16, 16, 5, false)
	,drowning(world->getGame().getTexManager().get("player_drowning.png"), 16, 16, 8, false)
	,speed(2)
	,state(State::Walking)
	,timer(-1)
	,hp(100)
{
	legs.apply([](sf::Sprite& sprite){
		sprite.setOrigin(8, 8);
	});
	walking.apply([](sf::Sprite& sprite){
		sprite.setOrigin(4, 8);
	});
	attacking.apply([](sf::Sprite& sprite){
		sprite.setOrigin(4, 8);
	});
	drowning.apply([](sf::Sprite& sprite){
		sprite.setOrigin(8, 8);
	});
	stunned.setTexture(world->getGame().getTexManager().get("player.png"));
	stunned.setOrigin(4, 8);
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
			legs.draw(target);
			walking.draw(target);
			break;
		case State::Attacking:
			legs.draw(target);
			attacking.draw(target);
			break;
		case State::Stunned:
			legs.draw(target);
			target.draw(stunned);
			break;
		case State::Rafting:
			break;
		case State::Drowning:
			drowning.draw(target);
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
				int px = pos.x;	//	for lambda
				int py = pos.y;
				int dx = dir.x;
				int dy = dir.y;
				if (isMoving &&
					!level->testCollision(this, "Tree", dir.x, dir.y) &&
					!level->testCollision(this, "SolidTerrain", dir.x, dir.y))
				{
					if (world->getTerrain(pos.x, pos.y) == World::Terrain::ShallowWater)
					{
						pos.x += dir.x / 3;
						pos.y += dir.y / 3;
					}
					else
						pos += dir;
					walking.advanceFrame();
					legs.advanceFrame();
					legs.apply([dx, dy, px, py](sf::Sprite& sprite){
						sprite.setPosition(px, py);
						sprite.setRotation(je::pointDirection(0, 0, dx, dy));
					});
				}
				else
				{
					legs.apply([mouseAim, px, py](sf::Sprite& sprite){
						sprite.setPosition(px, py);
						sprite.setRotation(mouseAim);
					});
				}
				walking.apply([mouseAim, px, py](sf::Sprite& sprite){
					sprite.setPosition(px, py);
					sprite.setRotation(mouseAim);
				});
				if (world->getTerrain(pos.x, pos.y) == World::Terrain::NormalWater)
				{
					timer = DROWNING_ANIMATION_TIME;
					state = State::Drowning;
					drowning.apply([px, py](sf::Sprite& sprite){
						sprite.setPosition(px, py);
					});
				}
			}
			break;
		case State::Stunned:
			stunned.setPosition(pos);
			stunned.setRotation(mouseAim);
			break;
		case State::Drowning:
			drowning.advanceFrame();
			if (timer == 0)
			{
				world->reset();
			}
			break;
		default:
			break;
	}
	if (timer >= 0)
		--timer;
	level->setCameraPosition(pos);
}

}
