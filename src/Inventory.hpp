#ifndef ORCA_INVENTORY_HPP
#define ORCA_INVENTORY_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include "Item.hpp"
#include "Entity.hpp"
#include "World.hpp"
#include "Controller.hpp"

namespace orca
{

class World;

class Inventory : public je::Entity
{
public:
    Inventory (World *world, const sf::Vector2i &dimensions, const sf::Vector2i &offset);
    bool add (Item *item);
    void draw (sf::RenderTarget& target, const sf::RenderStates &states = sf::RenderStates::Default) const;
    void onUpdate() override;
    void toggle();

private:
    sf::Vector2f dimensions;
	je::Controller controller;
    int capacity;
    sf::RectangleShape invBox;
    Item ***itemList;
    bool **selectionList;
    bool open;
	//std::vector<const Item*> contents;
};

}

#endif
