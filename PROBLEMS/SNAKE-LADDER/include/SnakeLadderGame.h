

#include "SnakeLadderBoard.h"
#include "Player.h"

class Player
{
    public:
        Player(std::string aName, int aId) : mPlayerName(aName), mId(aId), mPosition(0) {}

        std::string getName() const { return mPlayerName;}

        int getId() const {return mId;}

        int getPosition() const {return mPosition;}

        void setPosition(int aPosition) { mPosition = aPosition;}

    private:
        std::string                     mPlayerName{""};
        int                             mId{-1};
        int                             mPosition{1};
};

class Dice
{
    public:
        Dice () = default;

        ~Dice() = default;

        int roll() { return currentValue = (rand() % 6) + 1;}
    
        int getCurrentValue() const { return currentValue;}

    private:
            int currentValue{-1};
};

class Game
{
    public:
        static Game* Create ();

        bool Intialize ();

        bool Start ();

        bool End ();
    
    private:
        Game();

        int RegisterPlayer (string aName);

        bool AddBoard ();

        bool AddedPlayer ();
    
    private:
        Board*                      mBoard{nullptr};
        std::vector<Player>         mPlayers;
        Dice                        mDice;
};