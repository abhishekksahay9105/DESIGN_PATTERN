#include <iostream>
#include <unordered_map>

// Flywieght class
class Character
{
public:
    Character(char aChar) : mChar(aChar)
    {
    }

    void draw(int aExtrinsicState)
    {
        std::cout << "Drawing character at position " << aExtrinsicState << std::endl;
    }

    private:
        char mChar;
};

// Flyweight Factory
class CharactorFactory
{
    public:
        Character* getCharacter (char key)
        {
            if (mCharMap.find(key) != mCharMap.end())
            {
                return mCharMap[key];
            }
        }

    private:
        std::unordered_map<char, Character*> mCharMap;
};

int main (int argv, char** argc)
{
    CharactorFactory charFactory;

    int position = 0;
 
    charFactory.getCharacter('A')->draw(position++);
    charFactory.getCharacter('B')->draw(position++);
    charFactory.getCharacter('C')->draw(position++);

    return 0;
}