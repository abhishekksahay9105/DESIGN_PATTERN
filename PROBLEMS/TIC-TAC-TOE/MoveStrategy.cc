#include "MoveStrategy.h"   
#include <iostream>

//========================================================================
// class HumanStrategy
//========================================================================
bool HumanStrategy::chooseMove(std::unique_ptr<Board>& aBoard, Move& aMove, char mark)
{
    std::cout << "HumanStrategy::chooseMove";
    int row, col;
    std::cin >> row >> col;
    aMove.mRow = row;
    aMove.mCol = col;
    std::cout << mark << std::endl;
    return aBoard->IsValidMove (aMove);
}


//========================================================================
// class AIStategy
//========================================================================
bool AIStrategy::chooseMove(std::unique_ptr<Board>& aBoard, Move& aMove, char mark)
{
    std::cout << "AIStrategy::chooseMove";
    int row, col;
    std::cin >> row >> col;
    aMove.mRow = row;
    aMove.mCol = col;
    std::cout << mark << std::endl;
    return aBoard->IsValidMove (aMove);
}