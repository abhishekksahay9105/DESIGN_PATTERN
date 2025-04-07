#include <bits/stdc++.h>

class Singleton
{
public:
    //static method to access singleton instance
    static Singleton &getInstance()
    {
         // If the instance doesn't exist, create it
        if (!instance)
        {
            instance = new Singleton();
        }
        return *instance;
    }

    //public method to perform some operation
    void SomeOperation()
    {
        std::cout << "Singleton is performing some operation." << std::endl;
    }

    //delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    //private constructor to prevent external instantiation
    Singleton()
    {
        std::cout << "Singleton object is Created." << std::endl;
    }

    //private destructor to prevent external deletion
    ~Singleton ()
    {
        std::cout << "Singleton object is Deleted." << std::endl;
    }

    static Singleton* instance;
};

//Initialize the static instance to nullptr
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton& instance = Singleton::getInstance();

    instance.SomeOperation();

    return 0;
}