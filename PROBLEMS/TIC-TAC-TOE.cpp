#include <bits/stdc++.h>
using namespace std;

class TicTacToe;

enum PieceTypeT
{
    cNone,
    cX,
    cO
} PieceTypeT;

class Player
{
    public:
        PieceTypeT mPieceType{cNone};
        string mName{""};

    public:
        Player (std::string aName)
        {
            mName = aName;
        }
};

class Board
{
    public:
        static Board* getBoard ()
        {
            if (nullptr != instance)
            {
                instance = new Board ();
            }
            else
            {
                return instance;
            }
        }

        bool resetBoard ()
        {
            for (int i =0; i < 3; i++)
            {
                for (int j =0; j<3 ;j++)
                {
                    BoardStatus[i][j] = cNone;
                }
            }
        }

        Board (const Board&) = delete;
        Board& operator=(const Board) = delete;

    private:
        Board ();
        ~Board ();

    private:
        vector<vector<PieceTypeT>> BoardStatus;
        static Board* instance = nullptr;
};

class Player
{
    public:
        PieceTypeT mPieceType{cNone};
};

class TicTacInterface
{
    static TicTacInterface* CreateTicTacToe ();
    virtual bool StartGame () = 0;
    virtual bool PauseGame () = 0;
    virtual bool PlayGame () = 0;
    virtual bool Reset () = 0;
};

TicTacInterface* TicTacInterface::CreateTicTacToe ()
{
    TicTacToe* game = new TicTacInterface ();

    if (game->Start() != false)
    {
        return game;
    }

    std::cout << " Failed to Create Game " << std::endl;
    return nullptr;
}

class TicTacToe : public TicTacInterface
{
    private:
        Board* mBoard;
        std::vector <Player*> mPlayerList;

    bool Start ()
    {
        mBoard = Board::getBoard ();
        mBoard->resetBoard ();

        std::string playerName;
        std::cout << "Enter Player1 Name: ";
        std::cin  >> playerName;

        Player* P1 = new Player (playerName);
        mPlayerList.push_back(P1);

        std::cout << "Enter Player2 Name: ";
        std::cin  >> playerName;
        Player* P1 = new Player (playerName);
        mPlayerList.push_back(P1);
    }

    bool Pause ()
    {
        
    }

    bool Undo ()
    {

    }

    bool Play ()
    {

    }

    bool Reset ()
    {
        mBoard->resetBoard();
    }
};

int main ()
{
    TicTacToe* game = TicTacInterface::CreateTicTacToe ();

    if (!game)
    {
        if (game->StartGame())
        {

        }
    }

    return 0;
}
