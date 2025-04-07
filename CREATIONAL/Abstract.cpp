#include <iostream>
#include <string>


// Abstract Product
class Pizza
{
    public:
        virtual void bake () = 0;
        virtual void cut () = 0;
        virtual void box () = 0;
        virtual ~Pizza () = default;
};

class NewYorkCheesePizza : public Pizza
{
    public:
        void bake () override
        {
            std::cout << "Baking NewYork Cheese Pizza " << std::endl;
        }

        void cut () override
        {
            std::cout << "Cutting NewYork Cheese Pizza " << std::endl;
        }

        void box () override
        {
            std::cout << "Boxed NewYork Cheese Pizza " << std::endl;
        }
};

class NewYorkPepperonPizza : public Pizza
{
    public:
        void bake () override
        {
            std::cout << "Baking NewYork Pepperon Pizza " << std::endl;
        }

        void cut () override
        {
            std::cout << "Cutting NewYork Pepperon Pizza " << std::endl;
        }

        void box () override
        {
            std::cout << "Boxed NewYork Pepperon Pizza " << std::endl;
        }
};

class ChicagoCheesePizza : public Pizza
{
    public:
        void bake () override
        {
            std::cout << "Baking Chicago Cheese Pizza " << std::endl;
        }

        void cut () override
        {
            std::cout << "Cutting Chicago Cheese Pizza " << std::endl;
        }

        void box () override
        {
            std::cout << "Boxed Chicago Cheese Pizza " << std::endl;
        }

};

class ChicagoPepperonPizza : public Pizza
{
    public:
        void bake () override
        {
            std::cout << "Baking Chicago Pepperon Pizza " << std::endl;
        }

        void cut () override
        {
            std::cout << "Cutting Chicago Pepperon Pizza " << std::endl;
        }

        void box () override
        {
            std::cout << "Boxed Chicago Pepperon Pizza " << std::endl;
        }
};

// Abstract Factory Class
class PizzaFactory
{
    public:
        virtual Pizza* createCheesePizza () = 0;
        virtual Pizza* createPepperonPizza () = 0;
};

// Concreate NewYork Pizza Factory
class NewYorkPizzaFactory : public PizzaFactory
{
    public:
        Pizza* createCheesePizza ()
        {
            return new NewYorkCheesePizza ();
        }

        Pizza* createPepperonPizza ()
        {
            return new NewYorkPepperonPizza();
        }
};

// Concreate Chicago Pizza Factory
class ChicagoPizzaFactory : public PizzaFactory
{
    public:
        Pizza* createCheesePizza ()
        {
            return new ChicagoCheesePizza ();
        }

        Pizza* createPepperonPizza ()
        {
            return new ChicagoPepperonPizza ();
        }
};

int main (int argv, char** argc)
{
    PizzaFactory* newYorkPizzaFactory = new NewYorkPizzaFactory (); 
    PizzaFactory* chicagoPizzaFactory = new ChicagoPizzaFactory (); 

    Pizza* newYorkCheesePizza   = newYorkPizzaFactory->createCheesePizza();
    newYorkCheesePizza->bake ();
    newYorkCheesePizza->cut ();
    newYorkCheesePizza->box ();
    std::cout << std::endl;

    Pizza* newYorkPepperonPizza = newYorkPizzaFactory->createPepperonPizza();
    newYorkPepperonPizza->bake();
    newYorkPepperonPizza->cut();
    newYorkPepperonPizza->box();
    std::cout << std::endl;

    Pizza* chicagoCheesePizza   = chicagoPizzaFactory->createCheesePizza();
    chicagoCheesePizza->bake();
    chicagoCheesePizza->cut();
    chicagoCheesePizza->box();
    std::cout << std::endl;

    Pizza* chicagoPepperonPizza = chicagoPizzaFactory->createPepperonPizza();
    chicagoPepperonPizza->bake ();
    chicagoPepperonPizza->cut ();
    chicagoPepperonPizza->box ();

    return 0;
}