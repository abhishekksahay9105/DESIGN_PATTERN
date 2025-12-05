#include <cstdlib>

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