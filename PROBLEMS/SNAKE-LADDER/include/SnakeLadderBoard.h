#include <vector>
#include "SnakeLadderBoard.h"
#include "DataTypes.h"


class Player; // Forward declaration
//--------------------------------------------------------------------------------------------------
// Base Cell class
//--------------------------------------------------------------------------------------------------
class Cell
{
    public:
        static Cell Create (CellType aType, int aStart, int aEnd)
        {
            switch (aType)
            {
                case cSnake:
                    return Snake(aStart, aEnd);
                case cLadder:
                    return Ladder(aStart, aEnd);
                default:
                    return Normal(aPosition);
            }
        }
    
        virtual int getFinalPosition() = 0;

        virtual bool isSnake () {return false;}

        virtual bool isLadder () {return false;}

        virtual bool isNormal () {return false;}

};

class Ladder : public Cell
{    
    public:
        Ladder(int aStart, int aEnd) : mStart(aStart), mEnd(aEnd) {}

        int getFinalPosition() override { return mEnd;}

        int getStartPosition() { return mStart;}

        bool isLadder () {return true;}

    private:
        int mStart;
        int mEnd;
};

class Snake : public Cell
{
    public:
        Snake(int aStart, int aEnd) : mStart(aStart), mEnd(aEnd) {}

        int getFinalPosition() override { return mEnd;}

        int getStartPosition() { return mStart;}

        bool isSnake () {return true;}

    private:
        int mStart;
        int mEnd;
};

class Normal : public Cell
{
    public:
        Normal(int aPosition) : position(aPosition) {}
        
        int getFinalPosition() override { return mPosition;}

        int getStartPosition() { return mPosition;}

        bool isNormal () {return true;}
    
    private:
        int mPosition;
};
    
//--------------------------------------------------------------------------------------------------
// Board class
//--------------------------------------------------------------------------------------------------
class Board
{
    public:
        static Board* CreateBoard (int aRows, int aCols, std::vector<std::pair<int, int>> aSnakes, std::vector<std::pair<int, int>> aLadders);

        ~Board();

    private:
        Board(int aRows, int aCols);

        bool AddedCell (std::vector<std::pair<int, int>> aSnakes, std::vector<std::pair<int, int>> aLadders);

        bool UpdatePlayerCell (Player& aPlayer, int aDiceValue);

    private:
        std::vector <std::vector <Cell*>>           mLayout;
        int                                         mRows;
        int                                         mCols;
};