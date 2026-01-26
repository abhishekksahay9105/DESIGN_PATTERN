#include "Player.h"
#include <iostream>

static const std::string cInvalid = "Invalid Move! Re-enter the move.";

//======================================================================================
// Player.cc
//======================================================================================

Player::Player (const std::string& aName, char aMark)
    : mName(aName), mMark(aMark)  
{
    // Initialize strategy based on player type
    mStrategy = std::make_unique<MoveContext> ();
}

bool Player::SetStrategy (PlayerType aType)
{
    // Initialize strategy based on player type
    if (aType == Human)
    {
        mStrategy->SetStrategy(std::make_unique<HumanStrategy>());
    }
    else // AI
    {
        mStrategy->SetStrategy(std::make_unique<AIStrategy>());
    }
    return true;
}

bool Player::chooseMove (std::unique_ptr<Board>& board, Move& aMove, char aMark)
{
    // Use strategy to choose move
    return mStrategy->chooseMove(board, aMove, aMark);
}

bool Player::Move1 (std::unique_ptr<Board>& aBoard)
{
    std::string errMsg;
    if (!isAIPlayer())
    {
        std::cout << getName() << "'s turn (" << mMark << "): ";
        Move move;
        while(!(chooseMove(aBoard, move, mMark) && aBoard->Place(move, mMark, errMsg)))
        {
            std::cout << cInvalid << std::endl;
            errMsg.clear();
        }
    }
    else
    {
        Move move;
        chooseMove(aBoard, move, mMark);
        aBoard->Place(move, mMark, errMsg);
        // Check for winner or draw here...
    }
    aBoard->Print ();
    return true;
}


//======================================================================================
// class PlayerFactory
//======================================================================================
std::unique_ptr<Player> PlayerFactory::CreatePlayer(const std::string& aName, char aMark)
{
    return std::make_unique<Player>(aName, aMark);
}