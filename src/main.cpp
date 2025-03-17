#include <iostream>
#include <SDL.h>
#include "game.h"

int main(int argc, char* argv[]) 
{
    Game game;
    game.init();
    game.run();
    game.quit(); 
    return 0;
}