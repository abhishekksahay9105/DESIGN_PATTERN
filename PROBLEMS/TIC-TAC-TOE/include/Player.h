#ifndef __Player_h_
#define __Player_h_

#include <string>
#include <memory>
#include "MoveStrategy.h"
// #include "DataTypes.h"
class Board; // Forward declaration


typedef enum PlayerType { Human, AI } PlayerType;

//Player Interface 
class Player
{
    public:
        Player(const std::string& name, PlayerType type = Human);
        virtual ~Player() = default;

        bool chooseMove (const Board& board, Move& aMove, char aMark);

        std::string getName() const { return mName; }

        int getScore() const { return mScore; }

        int isAIPlayer () const { return mType == AI; }

        void incrementScore() { ++mScore; }
    private:
        std::string                         mName{""};
        PlayerType                          mType{Human};
        int                                 mScore{0};
        char                                mMark{' '};
        std::unique_ptr<MoveStrategy>       mStrategy;
};

//Factory to create Player objects
class PlayerFactory
{
    public:
        static std::unique_ptr<Player> CreatePlayer(const std::string& aName, PlayerType aType);
};

#endif