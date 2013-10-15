#ifndef ORCA_PLAYER_HPP
#define ORCA_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Controller.hpp"
#include "Animation.hpp"
#include "Inventory.hpp"

namespace orca
{

class World;

class Player : public je::Entity
{
public:
	Player(World * world, const sf::Vector2f& pos);

	void draw(sf::RenderTarget& target, const sf::RenderStates &states = sf::RenderStates::Default) const override;

	void onUpdate() override;

	bool damage(float amount, bool stun = false);

	int getHp() const;

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
	sf::Sprite raft;
	je::Controller controller;
	je::Animation legs;
	je::Animation walking;
	je::Animation attacking;
	je::Animation drowning;
	float speed;
	State state;
	int timer;
	float hp;
	float raftDirection;
	float raftVelocity;
	sf::Vector2f prevPos;
    Inventory pockets;
};

}

#endif // ORCA_PLAYER_HPP
