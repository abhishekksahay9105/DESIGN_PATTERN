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
        SortingStrategy* mStrategy;
    
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