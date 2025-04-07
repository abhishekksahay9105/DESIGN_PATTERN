#include <iostream>


//Reciever: Electronic Device
class ElectronicDevice
{
    private:
        std::string mName = "";
    public:
        ElectronicDevice (std::string aDeviceName)
        {
            mName = aDeviceName;
        }

        void turnOn ()
        {
            std::cout << mName << " is Turn ON now." << std::endl;
        }

        void turnOff ()
        {
            std::cout << mName << " is Turn OFF now." << std::endl;
        }
};

//Command Interface
class Command
{
    public:
        void execute () = 0;
};

//Concreate Command: Turn On
class TurnOnCommand : public Command
{
    private:
        ElectronicDevice& mDevice;

    public:
        TurnOnCommand (ElectronicDevice& aDevice) : mDevice(aDevice)
        {
        }

        void execute () {mDevice.turnOn();}
};

//Concreate Command: Turn Off
class TurnOffCommand : public Command
{
    private:
        ElectronicDevice& mDevice;
 
    public:
        TurnOffCommand (ElectronicDevice& aDevice) : mDevice(aDevice)
        {
        }

        void execute () {mDevice.turnOff();}
};

//Invoker: Remote Control
class RemoteControl
{
    private:
        std::vector<Command* > mCommandVec;

    public:
        void addCommand (Command* aCmd)
        {
            mCommandVec.push_back(aCmd);
        } 

        void pressButton (int aSlot)
        {
            if (aSlot >= 0 && aSlot < int(mCommandVec.size()))
            {
                mCommandVec[aSlot]->execute();
            }
        }
};

int main()
{
    // Create electronic devices
    ElectronicDevice tv("TV");
    ElectronicDevice lights("LIGHT");

    // Creates command for turning devices on and off
    TurnOnCommand turnOnTv ("TV");
    TurnOffCommand turnOffTv ("TV");
    TurnOnCommand turnOnLight ("LIGHT");
    TurnOffCommand turnOffLight ("LIGHT");

    // Create Remote control
    RemoteControl remote;

    // Set commands for remote control
    remote.addCommand(&turnOnTv);       //Button 0      
    remote.addCommand(&turnOffTv);      //Button 1
    remote.addCommand(&turnOnLight);    //Button 2    
    remote.addCommand(&turnOffLight);   //Button 3

    remote.pressButton(0);   
    remote.pressButton(1);   
    remote.pressButton(2);   
    remote.pressButton(3);   

    return 0;
}