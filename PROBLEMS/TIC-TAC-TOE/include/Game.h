#ifndef __Game_h_
#define __Game_h_

#include <memory>
#include "Player.h"
#include "Board.h"

class Player;
class Board;
class Game
{
    public:
        virtual bool RegisterPlayers ();
        
        virtual bool Run ();

    protected:

        bool RegisterPlayer (std::unique_ptr<Player>& aPlayer, char aMark);

        virtual bool SetupGame ();

        virtual bool StartGame ();

        virtual bool EndGame ();

    protected:
        std::unique_ptr<Board>                      mBoard;
        std::vector<std::unique_ptr<Player>>        mPlayerList;
};
#endif