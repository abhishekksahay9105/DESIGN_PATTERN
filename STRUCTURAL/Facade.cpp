#include <iostream>
#include <string>

// Subsystem 1
class Engine
{
    public:
        void Start ()
        {
            std::cout << "Engine Started ----->";
        }

        void Stop ()
        {
            std::cout << "Engine Stoped ------>";
        }
};

// Subsystem 2
class Light
{
    public:
        void TurnOn ()
        {
            std::cout << "Light Turned On ---->";
        }

        void TurnOff ()
        {
            std::cout << "Light Turned Off ---->";
        }
};

// Facade
class Car
{
    private:
        Engine mEngine;
        Light mLight;
    
    public:
        void StartCar ()
        {
            mEngine.Start();
            mLight.TurnOn();
            std::cout << " Car Started :" << std::endl;
        }

        void StopCar ()
        {
            mEngine.Stop();
            mLight.TurnOff();
            std::cout << " Car Stoped :" << std::endl;
        }
};

int main (int argv, char** argc)
{
    Car aCar;
    aCar.StartCar();
    aCar.StopCar();

    return 0;
}