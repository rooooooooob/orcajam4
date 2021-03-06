#ifndef JE_BUSH_HPP
#define JE_BUSH_HPP

#include <SFML/Graphics.hpp>

#include "jam-engine/Core/Entity.hpp"

namespace orca
{

class World;

class Bush : public je::Entity
{
public:
	Bush(World * world, const sf::Vector2f& pos);

	void onUpdate() override;

	void draw(sf::RenderTarget& target, const sf::RenderStates &states = sf::RenderStates::Default) const override;

private:

	sf::Sprite sprite;
	int hp;
};

}

#endif // JE_TREE_HPP
