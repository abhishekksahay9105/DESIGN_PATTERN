
#include "SnakeLadderGame.h"

int main ()
{
    Game* game = Game::Create ();
    while (game && game->Intialize ())
    {
        game->Start ();SnakeLadderGame.cc
        // game->ShowStats ();
        std::cout << "Want to play again? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y')
            continue;
        else
            break;
    }

    delete game;
    game = nullptr;

    return 0;
}