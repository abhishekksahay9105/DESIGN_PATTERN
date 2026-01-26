#ifndef __Player_h_
#define __Player_h_

#include <string>
#include <memory>
#include "MoveStrategy.h"
class Board; // Forward declaration
typedef enum PlayerType { Human, AI } PlayerType;

//Player Interface 
class Player
{
    public:
        Player(const std::string& name, char aMark);
        virtual ~Player() = default;

        bool chooseMove (std::unique_ptr<Board>& board, Move& aMove, char aMark);

        bool Move1 (std::unique_ptr<Board>& aBoard);

        bool SetStrategy (PlayerType aType);

        std::string getName() const { return mName; }
        char getMark() const { return mMark; }

        int getScore() const { return mScore; }

        int isAIPlayer () const { return mStrategy->isAIStrategy();}

        void incrementScore() { ++mScore; }
    private:

        std::string                         mName{""};
        char                                mMark{' '};
        int                                 mScore{0};
        std::unique_ptr<MoveContext>        mStrategy;
};

//Factory to create Player objects
class PlayerFactory
{
    public:
        static std::unique_ptr<Player> CreatePlayer(const std::string& aName, char aMark);
};

#endif