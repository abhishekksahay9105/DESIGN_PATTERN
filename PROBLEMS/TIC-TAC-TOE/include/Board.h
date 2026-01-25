#ifndef __Board_h_
#define __Board_h_

#include <vector>
#include <string>
#include "DataTypes.h"

// class BoardObserver
// {
//     public:
//         virtual void OnCellChanged(int row, int col, char newValue) = 0;
// };

class Board
{
    public:
        Board(int rows, int cols);

        bool Initialize ();
        
        bool Place (Move aMove, char aMark, std::string& aErrMsg);
        
        bool Print () const;

        bool CheckWin(char aMark) const;

        bool IsFull() const;

    private:
        bool IsValidMove (Move aMove) const;
        
    protected:
        int                              mRows{3};
        int                              mCols{3};
        std::vector<std::vector<char>>   mMatrix;
};
#endif