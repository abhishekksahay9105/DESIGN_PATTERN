#include "MoveStrategy.h"   
#include <iostream>

//========================================================================
// class HumanStrategy
//========================================================================
bool HumanStrategy::chooseMove(const Board& board, Move& move, char mark)
{
    int row, col;
    std::cin >> row >> col;
    move.mRow = row;
    move.mCol = col;
    std::cout << &board << mark;
    return true;
}


//========================================================================
// class AIStategy
//========================================================================
bool AIStrategy::chooseMove(const Board& board, Move& move, char mark)
{
    std::cout << &board << mark;
    move.mRow = 0;
    move.mCol = 0;
    return false;
}