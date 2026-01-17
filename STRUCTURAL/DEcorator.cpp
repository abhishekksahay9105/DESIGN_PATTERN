/*
    1. The Decorator Design Pattern is a structural pattern used to add new behavior or responsibilities
       to an object dynamically, without modifying its original class.
    2. Real‑Life Analogy
        Imagine you buy a plain coffee.
        Then you tell the barista to add:

        Milk
        Sugar
        Whipped cream

        You don’t change the coffee machine itself.
        You just wrap the coffee with extra additions.
        This is the decorator pattern.

    3. When to Use Decorator Pattern
            Use it when:
                You want to add features to objects dynamically.
                You want to avoid huge inheritance hierarchies.
                You don’t want to modify existing code.

            Don’t use it when:
                You need to change behavior for all objects (use inheritance instead).

 */


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


