#include "SnakeLadderBoard.h"
#include "SnakeLadderPlayer.h"

//--------------------------------------------------------------------------------------------------
// Board class
//--------------------------------------------------------------------------------------------------
static Board* Board::CreateBoard (int aRows, int aCols, std::vector<std::pair<int, int>> aSnakes, std::vector<std::pair<int, int>> aLadders)
{
    // Add snakes and ladders at specific positions
    Board* board = new Board(aRows, aCols);
    board->AddedCell (aSnakes, aLadders);
    return board;
}

Board::Board(int aRows, int aCols) : mRows(aRows), mCols(aCols)
{
    mLayout.resize(mRows, std::vector <Cell*> (mCols, nullptr));
}

Board::~Board()
{
    for (int i = 0; i < mRows; ++i)
    {
        for (int j = 0; j < mCols; ++j)
        {
            delete mLayout[i][j];
        }
    }
}

bool Board::AddedCell (std::vector<std::pair<int, int>> aSnakes, std::vector<std::pair<int, int>> aLadders)
{
    for (auto snake : aSnakes)
    {
        int start = snake.first;
        int end = snake.second;
        // Convert start and end to row and col
        int startRow = start / cols;
        int startCol = start % cols;
        int endRow = end / cols;
        int endCol = end % cols;
        Layout[startRow][startCol] = new Snake(start, end);
    }

    for (auto ladder : aLadders)
    {
        int start = ladder.first;
        int end = ladder.second;
        // Convert start and end to row and col
        int startRow = start / cols;
        int startCol = start % cols;
        int endRow = end / cols;
        int endCol = end % cols;
        Layout[startRow][startCol] = new Ladder(start, end);
    }

    // Fill remaining cells as normal cells
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (Layout[i][j] == nullptr)
            {
                int position = i * cols + j;
                Layout[i][j] = new Normal(position);
            }
        }
    }

    return true;
}

bool Board::UpdatePlayerCell (Player& aPlayer, int aDiceValue)
{
    int currentPosition = aPlayer.getPosition();
    int newPosition = currentPosition + aDiceValue;

    if (newPosition > mRows * mCols)
    {
        // Exceeds board limit
        return false;
    }

    int row = newPosition / mCols;
    int col = newPosition % mCols;

    Cell* cell = mLayout[row][col];
    int finalPosition = cell->getFinalPosition();

    // Update player position
    aPlayer.setPosition(finalPosition);

    return true;
}