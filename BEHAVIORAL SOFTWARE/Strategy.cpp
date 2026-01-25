/*
    1. The Strategy Pattern is a behavioral design pattern that allows you to define a family of algorithms, put each algorithm in a separate class,
       and make them interchangeable at runtime.
    2. Why do we need Strategy Pattern?
        Because sometimes you want to:
            Change algorithm dynamically
            Avoid large if-else or switch statements
            Follow the Open/Closed Principle
            (add new strategies without modifying existing code)
            Separate behavior from context
*/

#include <iostream>

class SortingStrategy
{
    public:
        virtual void sort (std::vector<int>& aVector) = 0;
};

class BubbleSort : public SortingStrategy
{
    public:
        void sort (std::vector<int>& aVector) override
        {
            // Implementing Bubble sort Algorithm
        }
};

class QuickSort : public SortingStrategy
{
    public:
        void sort (std::vector<int>& aVector) override
        {
            // Implementing Bubble sort Algorithm
        }
};

class SortContext
{
    private:
        std::unique_ptr<SortingStrategy> mStrategy;
    
    public:
        void SetStrategy (SortingStrategy* aStrategy)
        {
            this->mStrategy = aStrategy;
        }

        void executeStrategy (std::vector<int>& aVector)
        {
            mStrategy->sort ();
        }
};

int main (int argv, char* argc)
{
    std::vector<int> aData = {3, 1, 2, 7};

    SortContext context;
    BubbleSort bubbleSort;
    QuickSort quickSort;

    context.SetStrategy(bubbleSort);
    context.executeStrategy(aData);
    
    context.SetStrategy(quickSort);
    context.executeStrategy(aData);


    return 0;
}