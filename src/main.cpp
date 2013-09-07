#include "Game.hpp"
#include "World.hpp"
#include "TexManager.hpp"

int main()
{
	je::TexManager::setPath("orcajam4/img/");
	je::Game game(640, 480, 60);
	game.setLevel(new orca::World(&game));
    return game.execute();
}
