#ifndef ORCA_ITEM_HPP
#define ORCA_ITEM_HPP

#include <string>

namespace orca
{

class Item
{
public:
	

	const std::string& getName() const;
	const std::string& getDescription() const;

private:
	std::string name;
	std::string desc;
};

}

#endif