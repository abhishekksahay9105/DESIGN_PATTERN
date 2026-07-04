
#include <bits/stdc++.h>
using namespace std;

// ----------------------------- Utilities -----------------------------
struct Move
{
    int r{-1}, c{-1};
    bool isUndo() const { return r == -1 && c == -1; }
};

// Forward declaration
class Board;

// ----------------------------- Observer Pattern -----------------------------
// Observer interface for board updates
class IBoardObserver
{
    public:
        virtual ~IBoardObserver() = default;
        virtual void onBoardChanged(const Board& board) = 0;
};

// Subject (Observable) mixin
class BoardObservable
{
    public:
        void attach(IBoardObserver* obs) { observers.push_back(obs); }
        void detach(IBoardObserver* obs)
        {
            observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
        }

    protected:
        void notify(const Board& b)
        {
            for (auto* obs : observers) obs->onBoardChanged(b);
        }
        
    private:
        vector<IBoardObserver*> observers;
};

// ----------------------------- Board (Model) -----------------------------
class Board : public BoardObservable
{
        // 3x3 char grid: 'X', 'O', or ' '
        array<array<char,3>,3> g{};
    public:
        Board() { reset(); }

        void reset() {
            for (auto& row : g) row.fill(' ');
            notify(*this);
        }

        bool isValid(int r, int c) const {
            return r>=0 && r<3 && c>=0 && c<3 && g[r][c]==' ';
        }

        bool place(int r, int c, char mark) {
            if (!isValid(r,c)) return false;
            g[r][c] = mark;
            notify(*this);
            return true;
        }

        void undo(int r, int c) {
            if (r>=0 && r<3 && c>=0 && c<3) {
                g[r][c] = ' ';
                notify(*this);
            }
        }

        char at(int r, int c) const { return g[r][c]; }

        vector<Move> legalMoves() const {
            vector<Move> mv;
            for (int r=0;r<3;r++)
                for (int c=0;c<3;c++)
                    if (g[r][c]==' ') mv.push_back({r,c});
            return mv;
        }

        bool isFull() const {
            for (auto& row: g)
                for (char ch: row) if (ch==' ') return false;
            return true;
        }

        bool checkWin(char m) const {
            // rows/cols
            for (int i=0;i<3;i++) {
                if (g[i][0]==m && g[i][1]==m && g[i][2]==m) return true;
                if (g[0][i]==m && g[1][i]==m && g[2][i]==m) return true;
            }
            // diagonals
            if (g[0][0]==m && g[1][1]==m && g[2][2]==m) return true;
            if (g[0][2]==m && g[1][1]==m && g[2][0]==m) return true;
            return false;
        }

        bool isTerminal() const {
            return checkWin('X') || checkWin('O') || isFull();
        }

        void print(ostream& os = cout) const
        {
            os << "\n";
            for (int r=0;r<3;r++) {
                for (int c=0;c<3;c++) {
                    os << " " << g[r][c];
                    if (c<2) os << " |";
                }
                os << "\n";
                if (r<2) os << "-----------\n";
            }
            os << "\n";
        }
};

// ----------------------------- Strategy Pattern -----------------------------
class IMoveStrategy
{
    public:
        virtual ~IMoveStrategy() = default;
        virtual Move chooseMove(const Board& board, char mark) = 0;
};

// Human strategy: reads input like "row col" or "U" (undo)
class HumanStrategy : public IMoveStrategy
{
    public:
        Move chooseMove(const Board& board, char mark) override
        {
            while (true)
            {
                cout << "Player " << mark << " - enter move as `row col` (1-3 1-3) or `U` to undo: ";
                string line; 
                if (!getline(cin, line)) { return {-1,-1}; }
                // trim
                auto trim = [](string s)
                {
                    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch){ return !isspace(ch); }));
                    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch){ return !isspace(ch); }).base(), s.end());
                    return s;
                };
                line = trim(line);
                if (line.empty()) continue;
                if (line.size()==1 && (line=="u" || line=="U")) return {-1,-1}; // undo

                istringstream iss(line);
                int r,c; 
                if (iss >> r >> c)
                {
                    r--; c--;
                    if (r>=0 && r<3 && c>=0 && c<3) 
                    {
                        if (board.at(r,c)==' ') return {r,c};
                        cout << "Cell is not empty. Try again.\n";
                    }
                    else
                    {
                        cout << "Out of range. Try again.\n";
                    }
                } 
                else
                {
                    cout << "Invalid input. Try again.\n";
                }
            }
        }
};

// Minimax AI (optimal)
class MinimaxStrategy : public IMoveStrategy
{
    // Evaluate terminal: +10 win (AI), -10 loss, 0 draw. Depth tie-breaker.
    int scoreTerminal(const Board& b, char me, int depth)
    {
        char opp = (me=='X' ? 'O' : 'X');
        if (b.checkWin(me))  return 10 - depth;
        if (b.checkWin(opp)) return depth - 10;
        return 0;
    }

    int minimax(Board& b, char me, char turn, int depth)
    {
        if (b.isTerminal()) return scoreTerminal(b, me, depth);

        char opp = (me=='X' ? 'O' : 'X');
        vector<Move> moves = b.legalMoves();
        if (turn == me) {
            int best = -1000;
            for (auto mv: moves) {
                b.place(mv.r, mv.c, turn);
                best = max(best, minimax(b, me, opp, depth+1));
                b.undo(mv.r, mv.c);
            }
            return best;
        } else {
            int best = 1000;
            for (auto mv: moves) {
                b.place(mv.r, mv.c, turn);
                best = min(best, minimax(b, me, me, depth+1));
                b.undo(mv.r, mv.c);
            }
            return best;
        }
    }

public:
    Move chooseMove(const Board& board, char mark) override {
        Board copy = board; // local copy to simulate
        int bestVal = -1000;
        Move best{-1,-1};
        char opp = (mark=='X' ? 'O' : 'X');

        for (auto mv : copy.legalMoves()) {
            copy.place(mv.r, mv.c, mark);
            int value = minimax(copy, mark, opp, 0);
            copy.undo(mv.r, mv.c);
            if (value > bestVal) {
                bestVal = value;
                best = mv;
            }
        }
        // If first move, center preference (optional heuristic)
        if (best.r==-1 && best.c==-1) {
            auto legal = board.legalMoves();
            if (!legal.empty()) best = legal.front();
        }
        return best;
    }
};

// ----------------------------- Decorator Pattern (for Strategy) -----------------------------
class LoggingStrategy : public IMoveStrategy
{
    public:
        explicit LoggingStrategy(unique_ptr<IMoveStrategy> s) : inner(move(s)) {}

        Move chooseMove(const Board& board, char mark) override
        {
            auto start = chrono::high_resolution_clock::now();
            Move mv = inner->chooseMove(board, mark);
            auto end = chrono::high_resolution_clock::now();
            auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();

            if (!mv.isUndo())
                cout << "[LOG] Player " << mark << " chose (" << (mv.r+1) << "," << (mv.c+1) 
                << ") in " << ms << " ms\n";
            else
                cout << "[LOG] Player " << mark << " requested UNDO in " << ms << " ms\n";
                return mv;
        }

    private:
        unique_ptr<IMoveStrategy> inner;
};

// ----------------------------- Command Pattern -----------------------------
class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual bool execute() = 0;
    virtual void undo() = 0;
};

class MoveCommand : public ICommand
{
    public:
        MoveCommand(Board& b, Move m, char mk) : board(b), mv(m), mark(mk) {}
        bool execute() override
        {
            if (mv.isUndo()) return false;
            return board.place(mv.r, mv.c, mark);
        }

        void undo() override
        {
            if (!mv.isUndo()) board.undo(mv.r, mv.c);
        }

    private:
        Board& board;
        Move mv;
        char mark;
};

// ----------------------------- Factory Pattern -----------------------------
enum class PlayerType { Human, AI };

class Player
{
    public:
        Player(string name, char mark, unique_ptr<IMoveStrategy> s)
            : name_(move(name)), mark_(mark), strategy_(move(s)) {}

        const string& name() const { return name_; }
        char mark() const { return mark_; }

        // returns either a valid move or an undo sentinel (-1,-1)
        Move chooseMove(const Board& b) { return strategy_->chooseMove(b, mark_); }
    
    private:
        string name_;
        char mark_;
        unique_ptr<IMoveStrategy> strategy_;
};

class PlayerFactory
{
    public:
        static unique_ptr<Player> create(PlayerType type, string name, char mark, bool withLogging=true)
        {
            unique_ptr<IMoveStrategy> strat;
            if (type == PlayerType::Human)
            {
                strat = make_unique<HumanStrategy>();
            }
            else
            {
                strat = make_unique<MinimaxStrategy>();
            }
            if (withLogging) strat = make_unique<LoggingStrategy>(move(strat));
            return make_unique<Player>(move(name), mark, move(strat));
        }
};

// ----------------------------- Observer: Console View -----------------------------
class ConsoleBoardView : public IBoardObserver {
public:
    void onBoardChanged(const Board& board) override {
        board.print();
    }
};

// ----------------------------- Template Method: Game Orchestration -----------------------------
class Game 
{
    protected:
        Board board;
        vector<unique_ptr<ICommand>> history;   // move history
        Player* current{nullptr};
        unique_ptr<Player> p1, p2;

        virtual void beforeGame() { /* hook */ }
        virtual void beforeTurn(Player& /*p*/) { /* hook */ }
        virtual void afterTurn(Player& /*p*/) { /* hook */ }
        virtual void afterGame() { /* hook */ }

        bool isOver()
        {
            return board.checkWin('X') || board.checkWin('O') || board.isFull();
        }

        void announceResult()
        {
            if (board.checkWin('X'))      cout << "Player X wins! 🎉\n";
            else if (board.checkWin('O')) cout << "Player O wins! 🎉\n";
            else                          cout << "It's a draw. 🤝\n";
        }

    public:
        virtual ~Game() = default;

        void setPlayers(unique_ptr<Player> a, unique_ptr<Player> b)
        {
            p1 = move(a); p2 = move(b);
            current = p1.get();
        }

        Board& getBoard() { return board; }

        // Template Method
        void run()
        {
            beforeGame();

            while (!isOver())
            {
                beforeTurn(*current);
                Move mv = current->chooseMove(board);

                if (mv.isUndo())
                {
                    // Undo last move if possible
                    if (!history.empty())
                    {
                        history.back()->undo();
                        history.pop_back();
                        // Switch player back to the one who made the undone move
                        current = (current == p1.get()) ? p2.get() : p1.get();
                    }
                    else 
                    {
                        cout << "[WARN] Nothing to undo.\n";
                    }
                    continue; // continue game loop
                }

                auto cmd = make_unique<MoveCommand>(board, mv, current->mark());
                if (!cmd->execute())
                {
                    cout << "[WARN] Invalid move. Try again.\n";
                    continue;
                }
                history.push_back(move(cmd));

                afterTurn(*current);

                // Switch turn
                current = (current == p1.get()) ? p2.get() : p1.get();
            }

            announceResult();
            afterGame();
        }
};

// Concrete game with a console view observer
class TicTacToeGame : public Game
{
    ConsoleBoardView consoleView;

protected:
    void beforeGame() override
    {
        getBoard().attach(&consoleView);
        cout << "=== Tic-Tac-Toe (Strategy + Decorator + Observer + Command + Factory + Template Method) ===\n";
        getBoard().print();
    }

    void afterGame() override
    {
        getBoard().detach(&consoleView);
        cout << "=== Game Over ===\n";
    }
};

// ----------------------------- Main -----------------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    TicTacToeGame game;

    // Player X: Human with logging decorator
    auto x = PlayerFactory::create(PlayerType::Human, "You", 'X', /*withLogging*/true);

    // Player O: AI (Minimax) with logging decorator
    auto o = PlayerFactory::create(PlayerType::AI, "Computer", 'O', /*withLogging*/true);

    game.setPlayers(move(x), move(o));
    game.run();
    return 0;
}
