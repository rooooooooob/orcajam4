#ifndef JE_SOLIDTERRAIN_HPP
#define JE_SOLIDTERRAIN_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include "jam-engine/Core/Entity.hpp"

namespace orca
{

class World;

class SolidTerrain : public je::Entity
{
public:
	SolidTerrain(World * world, const sf::Vector2f& pos, const std::string& name);

	void onUpdate() override;

	void draw(sf::RenderTarget& target, const sf::RenderStates &states = sf::RenderStates::Default) const override;

private:

	sf::Sprite sprite;
};

}

#endif // JE_TREE_HPP
