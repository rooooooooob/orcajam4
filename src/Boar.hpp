#ifndef BOAR_HPP_INCLUDED
#define BOAR_HPP_INCLUDED

#include "jam-engine/Core/Entity.hpp"
#include "jam-engine/Graphics/Animation.hpp"

namespace orca
{

class World;
class Player;

class Boar: public je::Entity
{

public:
	Boar (World * world, const sf::Vector2f& pos, Player *player);
	void draw(sf::RenderTarget& target, const sf::RenderStates &states = sf::RenderStates::Default) const override;
	void onUpdate() override;
	void chop();

private:
	enum StateType {Roam = 1, Follow = 2, Stare = 3, Charge = 4};
	je::Animation run;
	//je::Animation attack;
	Player* target;
	int health;
	int stareTime;
	StateType state;
	float chargeDir;
	float finalChargeDir;
	int timer;
	bool hasHitPlayerDuringCharge;
	World * world;

};
}


#endif // BOAR_HPP_INCLUDED
