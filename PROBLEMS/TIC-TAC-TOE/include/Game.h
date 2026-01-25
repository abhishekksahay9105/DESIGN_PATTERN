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

        virtual bool SetupGame ();

        virtual bool Player1Move (std::string& aErrMsg);

        virtual bool Player2Move (std::string& aErrMsg);

        virtual bool StartGame ();

        virtual bool EndGame ();

    protected:
        std::unique_ptr<Board>                      mBoard;
        std::unique_ptr<Player>                     mPlayer1;
        std::unique_ptr<Player>                     mPlayer2;
};
#endif