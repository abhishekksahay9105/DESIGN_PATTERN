#include <bits/stdc++.h>
using namespace std;

// Product class
class Pizza
{
    public:
        void setDough(const std::string &dough)
        {
            this->dough = dough;
        }

        void setSauce(const std::string &sauce)
        {
            this->sauce = sauce;
        }

        void setTopping(const std::string &topping)
        {
            this->topping = topping;
        }

    private:
        std::string dough;
        std::string sauce;
        std::string topping;
};

// Abstract Builder class
class Pizzabuilder
{
    public:
        virtual void buildDough() = 0;
        virtual void buildSauce() = 0;
        virtual void buildTopping() = 0;
        virtual Pizza getPizza() const = 0;
};

// Concreate builder for  a specific type of pizza
class HawaiianPizzaBuilder : public Pizzabuilder
{
    public:
        void buildDough() override
        {
            pizza.setDough ("Hawaiian Dough");
        }

        void buildSauce() override
        {
            pizza.setSauce ("Hawaiian Sauce");
        }

        void buildTopping() override
        {
            pizza.setTopping("Hawaiian Topping");
        }

        Pizza getPizza() override
        {
            return pizza;
        }
    private:
        Pizza pizza;
};

// Concreate builder for anotehr type of pizza
class SpicyPizzaBuilder : public Pizzabuilder
{
    public:
        void buildDough() override
        {
            pizza.setDough("Spicy Dough")
        }

        void buildSauce() override
        {
            pizza.setSauce ("Spicy Dough");
        }

        void buildTopping() override
        {
            pizza.setTopping ("Spicy Topping");
        }

        Pizza getPizza() override
        {
            return pizza;
        }

    private:
        Pizza pizza;
};

class Cook
{
    public:
        void  makePizza(Pizzabuilder& builder)
        {
            builder.buildDough();
            builder.buildSauce();
            builder.buildTopping();
        }
};

int main()
{
    Cook cook;

    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    SpicyPizzaBuilder spicyPizzaBuilder;

    cook.makePizza(hawaiianPizzaBuilder);
    cook.makePizza(spicyPizzaBuilder);

    Pizza hawaiianPizza = hawaiianPizzaBuilder.getPizza();
    Pizza spicyPizza = spicyPizzaBuilder.getPizza();

    return 0;
}
