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
    std::cout << std::endl;
    for (int index = 0; index < mRows; ++index)
    {
        for (int mColIndex = 0; mColIndex < mCols; ++mColIndex)
        {
            std::cout << mMatrix[index][mColIndex];
            if (mColIndex < mCols - 1)
                std::cout << "  |";
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
    bool win = true;
    for (int row = 0; row < mRows; ++row)
    {
        win = true;
        for (int col = 0; col < mCols; ++col)
        {
            if (mMatrix[row][col] != aMark)
            {
                win = false;
                break;
            }
        }
        if (win)
            break;
    }
    
    if (!win)
    {
        for (int col = 0; col < mCols; ++col)
        {
            win = true;
            for (int row = 0; row < mRows; ++row)
            {
                if (mMatrix[row][col] != aMark)
                {
                    win = false;
                    break;
                }
            }
            if (win)
                break;
        }
    }

    if (!win)
    {
        win = true;
        for (int col = 0; col < mCols; ++col)
        {
            if (mMatrix[col][col] != aMark)
            {
                win = false;
                break;
            }
        }
    }

    if (!win)
    {
        win = true;
        for (int col = 0; col < mCols; ++col)
        {
            if (mMatrix[col][mCols - col - 1] != aMark)
            {
                win = false;
                break;
            }
        }
    }
    return win;
}

bool Board::IsFull() const
{
    bool isFull = false;
    for (const auto& row : mMatrix)
    {
        for (const auto& cell : row)
        {
            if (cell == ' ')
            {
                isFull = false;
                break;
            }
        }
    }
    return isFull;
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