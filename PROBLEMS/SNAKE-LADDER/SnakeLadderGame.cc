#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include "SnakeLadderDice.h"
#include "SnakeLadderPlayer.h"
#include "SnakeLadderBoard.h"
#include "SnakeLadderGame.h"

static Game* Game::Create ()
{
    Game* game = new Game ();
    return game;
}

~Game::Game ()
{
    if (mBoard)
    {
        delete mBoard;
        mBoard = nullptr;
    }
}

bool Game::Intialize ()
{
    bool status = false;
    // Any initialization logic if needed
    if (AddBoard () && AddedPlayer ())
        status = true;
    return status;
}

bool Game::Start ()
{
    // Game loop logic here
    while (true)
    {
        for (int i =0; i < players.size(); i++)
        {
            std::cout << players[i].getName() << " Turn: " << std::endl;
            int diceValue = dice.roll();
            std::cout << "Rolled a " << diceValue << std::endl;
            // Update player position based on dice roll and board cells
            if (mBoard->UpdatePlayerCell(players[i], diceValue))
            {
                std::cout << players[i].getName() << " moved to position " << players[i].getPosition() << std::endl;
                if (mBoard->IsWinningPosition(players[i].getPosition()))
                {
                    std::cout << players[i].getName() << " wins the game!" << std::endl;
                    return true;
                }
            }
            else
                std::cout << players[i].getName() << " cannot move, exceeds board limit." << std::endl;
        }
    }
    
    return true;
}

bool Game::End ()
{
    // Any cleanup logic if needed
    if (mBoard)
    {
        delete mBoard;
        mBoard = nullptr;
    }

    players.clear();
    return true;
}
        
int Game::RegisterPlayer (string aName)
{
    int id = players.size() + 1;
    Player newPlayer(aName, id);
    players.push_back(newPlayer);
    return true;
}

bool Game::AddBoard ()
{
    bool status  = true;
    int rows = 10;
    int cols = 10;
    std::vector<std::pair<int, int>> snakes = { {17, 7}, {54, 34}, {62, 19}, {64, 60}, {87, 24}, {93, 73}, {95, 75}, {98, 79} };
    std::vector<std::pair<int, int>> ladders = { {2, 38}, {4, 14}, {9, 31}, {21, 42}, {28, 84}, {51, 67}, {72, 91}, {80, 100} };

    mBoard = Board::CreateBoard (rows, cols, snakes, ladders);

    if (nullptr == mBoard)
        status = false;
    return status;
}

bool Game::AddedPlayer ()
{
    std::cout << "Please enter number of players: ";
    int numPlayers;
    std::cin >> numPlayers;
    for (int i = 0; i < numPlayers; ++i)
    {
        std::cout << "Enter name for player : ";
        string playerName;
        std::cin >> playerName;
        RegisterPlayer(playerName);
    }
    return true;
}