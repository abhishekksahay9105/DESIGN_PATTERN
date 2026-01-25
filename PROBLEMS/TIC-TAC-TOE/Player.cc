#include "Player.h"


//======================================================================================
// Player.cc
//======================================================================================

Player::Player (const std::string& aName, PlayerType aType)
    : mName(aName), mType(aType)
{
    // Initialize strategy based on player type
    if (aType == Human)
    {
        mStrategy = std::make_unique<HumanStrategy> ();
    }
    else // AI
    {
        mStrategy = std::make_unique<AIStrategy> ();
    }
}

bool Player::chooseMove (const Board& board, Move& aMove, char aMark)
{
    // Use strategy to choose move
    return mStrategy->chooseMove(board, aMove, aMark);
}


//======================================================================================
// class PlayerFactory
//======================================================================================
std::unique_ptr<Player> PlayerFactory::CreatePlayer(const std::string& aName, PlayerType aType)
{

    switch (aType)
    {
        case Human:
            return std::make_unique<Player>(aName, Human);
        case AI:
            return std::make_unique<Player>(aName, AI);
        default:
            throw std::invalid_argument("Unknown PlayerType");
    }
}