#ifndef ORCA_INVENTORY_HPP
#define ORCA_INVENTORY_HPP

#include <vector>
#include "Item.hpp"

namespace orca
{

class Inventory
{
public:
private:
	std::vector<const Item*> contents;
};

}

#endif