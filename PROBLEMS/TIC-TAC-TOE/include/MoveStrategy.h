#ifndef _MoveStrategy_h_
#define _MoveStrategy_h_

#include "Board.h"
#include <memory>


class MoveStrategy
{
    public:
        virtual ~MoveStrategy() = default;
        virtual bool chooseMove(std::unique_ptr<Board>& board, Move& move, char mark) = 0;
};

class HumanStrategy : public MoveStrategy
{
    public:
        bool chooseMove(std::unique_ptr<Board>& board, Move& move, char mark) override;
};

class AIStrategy : public MoveStrategy
{
    public:
        bool chooseMove(std::unique_ptr<Board>& board, Move& move, char mark) override;
};

class MoveContext
{
    private:
        std::unique_ptr<MoveStrategy> mStrategy;
    
    public:
        void SetStrategy (std::unique_ptr<MoveStrategy> aStrategy)
        {
            this->mStrategy = std::move(aStrategy);
        }

        bool chooseMove (std::unique_ptr<Board>& board, Move& move, char mark)
        {
            return mStrategy->chooseMove(board, move, mark);
        }

        bool isAIStrategy() const
        {
            return dynamic_cast<AIStrategy*>(mStrategy.get()) != nullptr;
        }
};
#endif