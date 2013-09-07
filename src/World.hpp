#ifndef ORCA_WORLD_HPP
#define ORCA_WORLD_HPP

#include "Level.hpp"

namespace orca
{

class World : public je::Level
{
public:
	World(je::Game * const game);
private:
	void onDraw(sf::RenderTarget& target) const;
	void loadEntities(const std::string& layerName, const std::vector<EntityPrototype>& prototypes);
	void transformTiles(const std::string& layerName, int tilesAcross, int tilesHigh, unsigned  **tiles) override;
};

}

#endif
