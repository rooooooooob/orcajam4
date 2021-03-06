#ifndef JE_TREE_HPP
#define JE_TREE_HPP

#include <SFML/Graphics.hpp>

#include "jam-engine/Core/Entity.hpp"
#include "jam-engine/Graphics/Animation.hpp"

namespace orca
{

class World;

class Tree : public je::Entity
{
public:
	Tree(World * world, const sf::Vector2f& pos);

	void onUpdate() override;

	void draw(sf::RenderTarget& target, const sf::RenderStates &states = sf::RenderStates::Default) const override;

	void chop ();

private:

	je::Animation cutting;
	int hp;
};

}

#endif // JE_TREE_HPP
