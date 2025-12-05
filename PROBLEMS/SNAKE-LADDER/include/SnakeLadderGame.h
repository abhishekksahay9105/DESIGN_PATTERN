#include <vector>

class Dice;
class Player;
class Board;

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