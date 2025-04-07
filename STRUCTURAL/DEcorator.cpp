#include <iostream>
#include <string>

// Abstract class IceCream
class IceCream
{
    public:
        virtual std::string getDescription () = 0;
        virtual int cost () = 0;
        virtual ~IceCream () = default;
};

class VanillaIceCream : public IceCream
{
    public:
        int mCost{100};
    public:
        std::string getDescription () override
        {
            return "Vanilla Ice Cream ";
        }

        int cost () override
        {
            return mCost;
        }
};

class IceCreamDecorator : public IceCream
{
    protected:
        IceCream* mIceCream{nullptr};
    
    public:
        IceCreamDecorator (IceCream* aIceCream) : mIceCream(aIceCream)
        {

        }

        std::string getDescription () override
        {
            return mIceCream->getDescription();
        }

        int cost () override
        {
            return mIceCream->cost ();
        }
};

class chocolateDecorator : public IceCreamDecorator
{
    public:
        chocolateDecorator (IceCream* aIceCream) : IceCreamDecorator(aIceCream)
        {

        }

        std::string getDescription () override
        {
            return mIceCream->getDescription() + "with chocolate ";
        }

        int cost () override
        {
            return mIceCream->cost () + 100;
        }
};

class CaremalDecorator : public IceCreamDecorator
{
    public:
        CaremalDecorator (IceCream* aIceCream) : IceCreamDecorator(aIceCream)
        {

        }

        std::string getDescription () override
        {
            return mIceCream->getDescription() + "with Caremal ";
        }

        int cost () override
        {
            return mIceCream->cost () + 200;
        }
};

int main (int argv, char** argc)
{
    std::cout << "Abhishek is very Good boy\n";

    IceCream* IceCream1 = new VanillaIceCream();
    std::cout << IceCream1->getDescription() << " " << IceCream1->cost ()<< std::endl;

    IceCream* IceCream2 = new chocolateDecorator (IceCream1);
    std::cout << IceCream2->getDescription() << " " << IceCream2->cost ()<< std::endl;

    delete IceCream1;
    delete IceCream2;

    return 0;
}


