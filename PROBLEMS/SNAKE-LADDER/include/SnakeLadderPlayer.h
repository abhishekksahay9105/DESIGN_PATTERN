#include <string>

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