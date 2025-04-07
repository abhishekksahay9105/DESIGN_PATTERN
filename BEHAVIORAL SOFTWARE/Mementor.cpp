#include <iostream>
#include <string>
#include <vector>

// Originator: The object whose state needs to be shaved  and resotered
class Originator
{
    private:
        std::string mState;

    public:
        void SetState (const std::string& aNewState)
        {
            mState = aNewState;
        }

        std::string GetState () const
        {
            return mState;
        }

        // Memento: Inner class representing the state of the Originator
        class Memento
        {
            private:
                std::string mState;
            
            public:
                Memento (const std::string& aOriginatorState) : mState(aOriginatorState)
                {

                }

                std::string GetSavedState() const ()
                {
                    return mState;
                }
        };

        Memento CreateMemento () const
        {
            return Memento (mState);
        }

        void RestoreState(const Memento& aMemento)
        {
            mState = aMemento.GetSavedState();
        }
};

// CareTaker: Manages the Memento Objects
class CareTaker
{
    private:
        std::vector<Originator::Memento> mMementos;
    
    public:
        void AddMemnto (const Originator::Memento& aMemento)
        {
            mMemntos.push_back(aMemento);
        }

        Originator::Memento GetMemento(int aIndex) const
        {
            if (aIndex >= 0 && aIndex < mMementos.size())
            {
                return mMementos[aIndex];
            }
            throw std::out_of_range("Invalid Memento index");
        }

};

int main (int argv, char* argc)
{
    Originator originator;
    CareTaker  careTaker;

    originator.SetState("State 1");
    careTaker.AddMemnto(originator.CreateMemento());

    originator.SetState("State 2");
    careTaker.AddMemnto(originator.CreateMemento());

    // Restore to the previous State
    originator.RestoreState(careTaker.GetMemento(0));
    std::cout << "Current State: " << originator.GetState() << std::endl;

    originator.RestoreState(careTaker.GetMemento(1));
    std::cout << "Current State: " << originator.GetState () << std::endl;
    return 0;
}