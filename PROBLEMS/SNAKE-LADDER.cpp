#include <iostream>
using namespace std;

typedef enum
{
    cNormal=0,
    cSnake,
    cLadder
} CellType;
 
class Cell
{
    static Cell Create (CellType aType, int aStart, int aEnd)
    {
        switch (aType)
        {
            case cSnake:
                return Snake(aStart, aEnd);
            case cLadder:
                return Ladder(aStart, aEnd);
            default:
                return Normal(aPosition);
        }
    }

    public:
        virtual int getFinalPosition() = 0;
};

class Ladder : public Cell
{    
    public:
        Ladder(int aStart, int aEnd) : start(aStart), end(aEnd) {}

        int getFinalPosition() override
        {
            return end;
        }

    private:
        int start;
        int end;
};

class Snake : public Cell
{
    public:
        Snake(int aStart, int aEnd) : start(aStart), end(aEnd) {}

        int getFinalPosition() override
        {
            return end;
        }

    private:
        int start;
        int end;
};

class Normal : public Cell
{
    public:
        Normal(int aPosition) : position(aPosition) {}
        
        int getFinalPosition() override
        {
            return position;
        }
    
    private:
        int position;
};

class Board
{

    static Board* CreateBoard (int aRows, int aCols, std::vector<std::pair<int, int>> aSnakes, std::vector<std::pair<int, int>> aLadders)
    {
        // Add snakes and ladders at specific positions
        Board* board = new Board(aRows, aCols);
        board->AddedCell (aSnakes, aLadders);
        return board;

    }

    private:
        Board(int aRows, int aCols) : rows(aRows), cols(aCols)
        {
            Layout.resize(rows, std::vector <Cell*> (cols, nullptr));
        }

    bool AddedCell (std::vector<std::pair<int, int>> aSnakes, std::vector<std::pair<int, int>> aLadders)
    {
        for (auto snake : aSnakes)
        {
            int start = snake.first;
            int end = snake.second;
            // Convert start and end to row and col
            int startRow = start / cols;
            int startCol = start % cols;
            int endRow = end / cols;
            int endCol = end % cols;

            Layout[startRow][startCol] = new Snake(start, end);
        }

        for (auto ladder : aLadders)
        {
            int start = ladder.first;
            int end = ladder.second;
            // Convert start and end to row and col
            int startRow = start / cols;
            int startCol = start % cols;
            int endRow = end / cols;
            int endCol = end % cols;

            Layout[startRow][startCol] = new Ladder(start, end);
        }

        // Fill remaining cells as normal cells
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (Layout[i][j] == nullptr)
                {
                    int position = i * cols + j;
                    Layout[i][j] = new Normal(position);
                }
            }
        }

        return true;
    }

    private:
        std::vector <std::vector <Cell*>> Layout;
};



class Player
{
    public:
        Player(string aName, int aId) : name(aName), id(aId), position(0) {}

        string getName() const
        {
            return name;
        }

        int getId() const
        {
            return id;
        }

    private:
        string name;
        int id;
        int position;
};

class Dice
{
    public:
        int roll()
        {
            return currentValue = (rand() % 6) + 1;
        }
    
        private:
            int currentValue{-1};
};

class Game
{
    public:
    
    static Game* Create ()
    {
        // Create board
        int rows = 10;
        int cols = 10;
        std::vector<std::pair<int, int>> snakes = { {16, 6}, {47, 26}, {49, 11}, {56, 53}, {62, 19}, {64, 60}, {87, 24}, {93, 73}, {95, 75}, {98, 78} };
        std::vector<std::pair<int, int>> ladders = { {4, 14}, {9, 31}, {21, 42}, {28, 84}, {36, 44}, {51, 67}, {71, 91}, {80, 100} };

        Board* board = Board::CreateBoard (rows, cols, snakes, ladders);

        std::cout << "Please enter number of players: ";
        int numPlayers;
        std::cin >> numPlayers;
        for (int i = 0; i < numPlayers; ++i)
        {
            std::cout << "Enter name for player " << (i + 1) << ": ";
            string playerName;
            std::cin >> playerName;
            RegisterPlayer(playerName);
        }
        Game* game = new Game (board, players);
        return game;
    }

    int RegisterPlayer (string aName)
    {
        int id = players.size() + 1;
        Player newPlayer(aName, id);
        players.push_back(newPlayer);
        return true;
    }

    private:
    Game(Board* aBoard, std::vector<Player> aPlayers) : board(aBoard), players(aPlayers) {}
    
    private:
        Board* board;
        std::vector<Player> players;
        Dice dice;
};

int main ()
{
    Game* game = Game::Create ();
    return 0;
}