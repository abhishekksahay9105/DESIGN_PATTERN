#include "Game.h"

#include <iostream>
#include <memory>

// int main (int argc, char* argv[])
int main ()
{
    
    Game game;
    if (!game.Run ())
    {
        std::cout << "Game encountered an error and will exit." << std::endl;
        exit(1);
    }
    exit(0);
}