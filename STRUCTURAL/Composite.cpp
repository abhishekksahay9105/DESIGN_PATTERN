
/*
    1. The Composite Pattern lets you treat individual objects and groups of objects uniformly.
    2. Real-Life Analogy
            A folder structure:

                File (leaf)
                Folder (composite)

                Contains files
                Contains folders

            You can perform actions like:
                delete
                move
                rename
                on both files and folders the same way.

*/
#include <iostream>
#include <vector>

// Abstract Product class
class Product
{
    public:
        virtual int price () const = 0;
        virtual ~Product () = default;
};

class Toy : public Product
{
    public:
        Toy(std::string aName, int aPrice) : mName(aName), mPrice(aPrice)
        {

        }

        int price () const override
        {
            return mPrice;
        }
    
    public:
        std::string mName{""};
        int mPrice{0};
};

class Book : public Product
{
    public:
        Book(std::string aName, int aPrice) : mName(aName), mPrice(aPrice)
        {

        }

        int price () const override
        {
            return mPrice;
        }
    
    public:
        std::string mName{""};
        int mPrice{0};
};

class Box : public Product
{
    public:
        Box(std::string aName) : mName(aName)
        {
        }

        void addToy (Product& aProduct)
        {
            mProductList.push_back(&aProduct);
        }

        void addBooks (Product& aProduct)
        {
            mProductList.push_back(&aProduct);
        }

        int price () const override
        {
            int total_price = 0;

            for (auto x : mProductList)
            {
                total_price += x->price();
            }
            return total_price;
        }
    
    public:
        std::string mName{""};
        std::vector<Product*> mProductList;
};

int main (int argv, char** argc)
{
    Toy toy1("abhsha58", 10);
    Toy toy2("abhsha59", 10);

    Book Book1("sahay", 100);


    Box box("Box1");
    box.addBooks(Book1);
    box.addToy(toy1);
    box.addToy(toy2);

    std::cout << box.price() << std::endl;
    return 0;
}