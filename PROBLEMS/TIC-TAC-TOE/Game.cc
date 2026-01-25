#include "Game.h"
#include <iostream>


static const std::string cInvalid = "Invalid Move! Re-enter the move.";

//======================================================================================================================
// class Game
// File: Game.cc
// Description: Implementation of the Game class using Template Method pattern
//======================================================================================================================

bool Game::RegisterPlayers ()
{
    // Registration logic for players
    std::string player1Name, player2Name;
    std::cout << "Enter name for Player 1 (X): ";
    std::cin >> player1Name;
    mPlayer1 = PlayerFactory::CreatePlayer(player1Name, Human);

    std::cout << "Real human or AI for Player 2? (h/a): ";
    char player2Type;
    std::cin >> player2Type;

    if (player2Type == 'h' || player2Type == 'H')
    {
        std::cout << "Enter name for Player 2 (O): ";
        std::cin >> player2Name;
        mPlayer2 = PlayerFactory::CreatePlayer(player2Name, Human);
    }
    else
    {
        player2Name = "Computer";
        mPlayer2 = PlayerFactory::CreatePlayer("Computer", AI);
    }

    return true;
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
    mBoard = std::make_unique<Board> (3, 3);
    return mBoard->Initialize ();
}

bool Game::Player1Move (std::string& aErrMsg)
{
    std::cout << mPlayer1->getName() << "'s turn (X): ";

    Move move;
    std::string errMsg;
    while(!(mPlayer1->chooseMove(*mBoard, move, 'X') && mBoard->Place(move, 'X', errMsg)))
    {
        std::cout << cInvalid << std::endl;
        errMsg.clear();
    }
    mBoard->Print ();

    aErrMsg.clear();
    return true;
}

bool Game::Player2Move (std::string& aErrMsg)
{
    std::string errMsg;
    if (mPlayer2->isAIPlayer() == false)
    {
        // Player 2's turn
        std::cout << mPlayer2->getName() << "'s turn (O): ";
        Move move;
        while(!(mPlayer2->chooseMove(*mBoard, move, 'O') && mBoard->Place(move, 'O', errMsg)))
        {
            std::cout << cInvalid << std::endl;
            errMsg.clear();
        }
    }
    else
    {
        Move move;
        mPlayer2->chooseMove(*mBoard, move, 'O');
        {
            mBoard->Place(move, 'O', errMsg);
            // Check for winner or draw here...
        }
    }
    aErrMsg.clear();
    mBoard->Print ();
    return true;
}


bool Game::StartGame ()
{
    std::string retry = "y";
    while (retry == "y" || retry == "Y")
    {

        bool gameOver = false;
        std::cout << "Starting a new game!" << std::endl;
        while (!gameOver)
        {
            std::string errMsg;
        
            Player1Move (errMsg);
        

            if (mBoard->CheckWin('X') || mBoard->IsFull())
            {
                gameOver = true;
                std::cout << mPlayer1->getName() << " wins!" << std::endl;
                break;
            }

            Player2Move (errMsg);

            if (mBoard->CheckWin('O') || mBoard->IsFull())
            {
                gameOver = true;
                std::cout << mPlayer2->getName() << " wins!" << std::endl;
                break;
            }
        }

        std::cout << "Play again? (y/n): ";
        std::cin >> retry;
    }

    return true;
}

bool Game::EndGame ()
{
    std::cout << "Game Over!" << std::endl;
    // Announce winner or draw
    return true;
}
