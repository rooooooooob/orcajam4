#ifndef ORCA_RAFT_HPP
#define ORCA_RAFT_HPP

#include "jam-engine/Core/Entity.hpp"

namespace orca
{

class World;

class Raft : public je::Entity
{
public:
	Raft(World * world, const sf::Vector2f& pos, float angle);

private:
	void onUpdate() override;
	void draw(sf::RenderTarget& target, const sf::RenderStates &states = sf::RenderStates::Default) const override;

	sf::Sprite sprite;
};

}

#endif // ORCA_RAFT_HPP
