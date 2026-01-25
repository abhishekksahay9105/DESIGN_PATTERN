#ifndef _MoveStrategy_h_
#define _MoveStrategy_h_

#include "Board.h"

class MoveStrategy
{
    public:
        virtual ~MoveStrategy() = default;
        virtual bool chooseMove(const Board& board, Move& move, char mark) = 0;
};

class HumanStrategy : public MoveStrategy
{
    public:
        bool chooseMove(const Board& board, Move& move, char mark) override;
};

class AIStrategy : public MoveStrategy
{
    public:
        bool chooseMove(const Board& board, Move& move, char mark) override;
};

#endif