#include <iostream>

class VehicleTemplate
{
    void buildVehicle()
    {
        assembleBody ();
        installEngine ();
        addWheels ();
        std::cout << "Vehicle is ready!\n";
    }

    //Abstract methods to implemented by concreate classes
    virtual void assembleBody () = 0;
    virtual void installEngine () = 0;
    virtual void addWheels () = 0;
};

class Car :: public VehicleTemplate
{
    void assembleBody ()
    {
        std::cout << "Assembling Car body!\n";
    }

    void installEngine ()
    {
        std::cout << "Installing Car Engine!\n";
    }

    void addWheels ()
    {
        std::cout << "Add Car Wheels!\n";
    }
};

class MotorCycle :: public VehicleTemplate
{
    void assembleBody ()
    {
        std::cout << "Assembling MotorCycle body!\n";
    }

    void installEngine ()
    {
        std::cout << "Installing MotorCycle Engine!\n";
    }

    void addWheels ()
    {
        std::cout << "Add MotorCycle Wheels!\n";
    }
};

int main (int argv, char* argc)
{
    std::cout << "Building a Car!\n";
    Car car;
    car.buildVehicle();

    std::cout << "Building a MotorCycle!\n";
    MotorCycle motor;
    motor.buildVehicle();

    return 0;
}