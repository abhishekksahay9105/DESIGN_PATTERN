#include <iostream>
#include "Board.h"
//======================================================================================
// Board.cc
// Description: Implementation of the Board class
//======================================================================================

Board::Board (int rows, int cols)
    : mRows(rows), mCols(cols), mMatrix(rows, std::vector<char>(cols, ' ')) 
{
}

bool Board::Initialize ()
{
    for (auto& row : mMatrix)
        std::fill(row.begin(), row.end(), ' ');
    Print ();
    return true;
}

bool Board::Place (Move aMove, char aMark, std::string& aErrMsg)
{
    bool status = true;
    if (IsValidMove(aMove))
    {
        mMatrix[aMove.mRow][aMove.mCol] = aMark;
    }
    else
    {
        aErrMsg = "Invalid Move!";
        status = false;
    }
    return std::move(status);
}

bool Board::Print () const
{
    for (int index = 0; index < mRows; ++index)
    {
        for (int mColIndex = 0; mColIndex < mCols; ++mColIndex)
        {
            std::cout << mMatrix[index][mColIndex];
            if (mColIndex < mCols - 1)
                std::cout << " | ";
        }
        std::cout << "\n";
        if (index < mRows - 1)
        {
            for (int mColIndex = 0; mColIndex < mCols; ++mColIndex)
            {
                std::cout << "---";
                if (mColIndex < mCols - 1)
                    std::cout << "+";
            }
            std::cout << "\n";
        }
    }
    return true;
}

bool Board::CheckWin(char aMark) const
{
    if (aMark == 'X') return true;
    return true;
}

bool Board::IsFull() const
{
    return true;
}

bool Board::IsValidMove (Move aMove) const
{
    if (aMove.mRow >= 0 && aMove.mRow < mRows &&
        aMove.mCol >= 0 && aMove.mCol < mCols &&
        mMatrix[aMove.mRow][aMove.mCol] == ' ')
    {
        return true;
    }
    return false;
}