#include <iostream>

#include "Game.h"

int main(int argv, char** args)
{
    const char * title = "SecretProject";
	Game game(title);
    if(game.init()) {
        game.startGameLoop();
    }

	return 0;
}