#ifndef ORCA_PLAYER_HPP
#define ORCA_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Controller.hpp"
#include "Animation.hpp"

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
	enum class State
	{
		Walking,
		Attacking,
		Stunned,
		Rafting,
		Drowning
	};

	World * world;
	sf::Sprite stunned;
	je::Controller controller;
	je::Animation legs;
	je::Animation walking;
	je::Animation attacking;
	je::Animation drowning;
	float speed;
	State state;
	int timer;
};

}

#endif // ORCA_PLAYER_HPP
