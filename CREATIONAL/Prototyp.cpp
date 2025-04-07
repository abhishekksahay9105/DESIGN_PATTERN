#include <iostream>
#include <string>
#include <vector>

class Shape
{
    public:
        virtual Shape* clone () = 0;
        virtual void draw () = 0;
        virtual ~Shape() = default;
};

class Circle : public Shape
{
    public:
        Circle (int aRadius) : mRadius (aRadius)
        {

        }

        Shape* clone () override
        {
            return new Circle(*this);
        }

        void draw () override
        {
            std::cout << "Circle Radius: " << mRadius << std::endl;
        }
    
    private:
        int mRadius{0};
};

class Rectangle : public Shape
{
    public:
        Rectangle(int aLength, int aBreath) : mLength(aLength), mBreath(aBreath)
        {

        }

        Shape* clone () override
        {
            return new Rectangle(*this);
        }

        void draw () override
        {
            std::cout << "Rectangle Length: " << mLength << " Breath: " << mBreath << std::endl;
        }

    private:
        int mLength{0};
        int mBreath{0};
};

int main (int argv, char** argc)
{
    Circle circle(5);
    Rectangle rect(4,3);

    circle.draw();
    rect.draw();

    Shape* cir2 = circle.clone();
    Shape* rec2 = rect.clone();

    cir2->draw();
    rec2->draw();

    std::cout << "Happy Birthday Abhishek!" << std::endl;
    return 0;
}