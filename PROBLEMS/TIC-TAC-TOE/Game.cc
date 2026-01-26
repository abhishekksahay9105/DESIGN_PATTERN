#include "Game.h"
#include <iostream>


//======================================================================================================================
// class Game
// File: Game.cc
// Description: Implementation of the Game class using Template Method pattern
//======================================================================================================================

bool Game::RegisterPlayer (std::unique_ptr<Player>& aPlayer, char aMark)
{
    bool status = false;
    if (!aPlayer)
    {
        std::cout << "Enter name for Player (" << aMark << "): ";
        std::string playerName;
        std::cin >> playerName;
        
        aPlayer = PlayerFactory::CreatePlayer(playerName, aMark);
    }

    while (!status)
    {
        std::cout << "Real human or AI for  " << aPlayer->getName() << " ? (h/a): ";
        char playerType;
        std::cin >> playerType;
     
        if (playerType == 'h' || playerType == 'H')
        {
            status = aPlayer->SetStrategy(Human);
        }
        else if (playerType == 'a' || playerType == 'A')
        {
            status = aPlayer->SetStrategy(AI);
        }
        else
        {
            std::cout << "Invalid player type selected." << std::endl;
        }
    }

    return status;
}

bool Game::RegisterPlayers ()
{
    bool status = true;
    // Registration logic for players
    mPlayerList.resize(2);
    status &= RegisterPlayer (mPlayerList[0], 'X');
    status &= RegisterPlayer (mPlayerList[1], 'O');

    return status;
}

bool Game::Run ()
{
    bool status = RegisterPlayers ();
    status &= SetupGame ();
    status &= StartGame ();
    status &= EndGame ();

    return status;
}

bool Game::SetupGame ()
{
    int row = 3;
    int col = 3;
    std::cout << "Setting up a " << row << "x" << col << " board." << std::endl;
    std::cin >> row >> col;
    mBoard = std::make_unique<Board> (row, col);
    return mBoard->Initialize ();
}

bool Game::StartGame ()
{
    std::string retry = "y";
    while (retry == "y" || retry == "Y")
    {
        bool gameOver = false;
        while (!gameOver)
        {
            for (int index = 0; index < int(mPlayerList.size()); ++index)
            {
                mPlayerList[index]->Move1 (mBoard);
                if (mBoard->CheckWin('X'))
                {
                    gameOver = true;
                    std::cout << mPlayerList[index]->getName() << " wins!" << std::endl;
                    break;
                }
                else if (mBoard->IsFull())
                {
                    gameOver = true;
                    std::cout << "It's a draw!" << std::endl;
                    break;
                }
            }
        }

        std::cout << "Play again? (y/n): ";
        std::cin >> retry;
        
        std::cout << "Starting a new game!" << std::endl;
        if (retry == "y" || retry == "Y")
        {
            RegisterPlayers ();
            SetupGame ();
        }
    }

    return true;
}

bool Game::EndGame ()
{
    std::cout << "Game Over!" << std::endl;
    // Announce winner or draw
    return true;
}
