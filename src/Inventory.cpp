#include "Inventory.hpp"

#include "jam-engine/Core/Game.hpp"

#include <iostream>

namespace orca
{

Inventory::Inventory (World *world, const sf::Vector2i &dimensions, const sf::Vector2i &offset)
	: Entity(world, "Inventory", sf::Vector2f(0, 0), sf::Vector2i(32*dimensions.x, 32*dimensions.y), offset),
	dimensions (dimensions),
	controller (world->getGame().getInput()),
	capacity (0),
	open (false)
{
	depth = -50;
	itemList = new Item** [dimensions.x];
	selectionList = new bool* [dimensions.x];
	for (int i = 0; i < dimensions.x; ++i)
	{
		itemList[i] = new Item* [dimensions.y];
		selectionList[i] = new bool [dimensions.y];
		for (int j = 0; j < dimensions.y; ++j)
		{
			itemList[i][j] = nullptr;
			selectionList[i][j] = false;
		}
	}

	controller.setKeybinds ("select slot", {je::Controller::Bind (sf::Mouse::Button::Left)});
	controller.setKeybinds ("move slot", {je::Controller::Bind (sf::Mouse::Button::Left)});
}

bool Inventory::add (Item *item)
{
	/*if (capacity >= width*height)
	{
		return false;
	}

	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			if (!itemList[i][j])
			{
				itemList[i][j] = item;
			}
		}
	}

	capacity++;*/
	return true;
}

void Inventory::draw (sf::RenderTarget& target, const sf::RenderStates &states /*= sf::RenderStates::Default*/) const
{
	if (open)
	{
		// TODO: adapt to je::Camera stuff
		sf::Vector2f topLeft;// = level->getCameraPosition();
		sf::Vector2i translation = this->getOffset();
		topLeft.x += translation.x;
		topLeft.y += translation.y;
		sf::RectangleShape invBox (sf::Vector2f (32, 32));
		invBox.setOutlineThickness (-2);
		invBox.setFillColor (sf::Color (200, 200, 200));
		invBox.setOutlineColor (sf::Color (100, 100, 100));

		for (int i = 0; i < dimensions.x; ++i)
		{
			for (int j = 0; j < dimensions.y; ++j)
			{
				invBox.setPosition (topLeft.x + 32*i, topLeft.y + 32*j);
				if (selectionList[i][j])
				{
					invBox.setOutlineColor (sf::Color (200, 200, 000));
					target.draw (invBox, states);
					invBox.setOutlineColor (sf::Color (100, 100, 100));
				}
				else
					target.draw (invBox, states);
			}
		}
	}
}

void Inventory::onUpdate()
{
	if (open)
	{
		if (controller.isActionPressed ("select slot"))
		{
			// TODO: adapt to je::Camera stuff
			sf::IntRect bounds;// = level->getCameraBounds();
			sf::Vector2i translation = getOffset();
			sf::Vector2i pixelDimensions (32*dimensions.x, 32*dimensions.y);
			sf::FloatRect boundingBox (bounds.left + translation.x, bounds.top + translation.y, pixelDimensions.x, pixelDimensions.y);
			sf::Vector2f cursorPosition = level->getCursorPos ();
			//std::cout << "bounding box x: " << boundingBox.left << "bounding box y: " << boundingBox.top << "\n";

			if (boundingBox.contains(cursorPosition))
			{
				int relativex = cursorPosition.x - boundingBox.left;
				int relativey = cursorPosition.y - boundingBox.top;
				int i = relativex/32;
				int j = relativey/32;
				if (selectionList[i][j])
					selectionList[i][j] = false;
				else
					selectionList[i][j] = true;
				std::cout << "test\n";
			}
		}
	}
}

void Inventory::toggle ()
{
	if (open)
		open = false;
	else
		open = true;
}

}
