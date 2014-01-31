#include "jam-engine/Core/Game.hpp"

#include "World.hpp"

int main()
{
	je::Game game(640, 480, 60);
	game.getTexManager().setPath("orcajam4/img/");
	game.setLevel(new orca::World(&game));
	return game.execute();
}