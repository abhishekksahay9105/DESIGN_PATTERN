#include <iostream>

// Abstract Product Class
class Shape
{
    public:
        virtual void draw () = 0;
        virtual ~Shape () = default;
};

class Circle : public Shape
{
    public:
        Circle (int aRadius) : mRadius (aRadius)
        {

        }

        void draw () override
        {
            std::cout << "Drawing a Circle having radius of: " << mRadius << std::endl;
        }

    private:
        int mRadius{0};
};

class Square : public Shape
{
      public:
        Square (int aSide) : mSide (aSide)
        {

        }

        void draw () override
        {
            std::cout << "Drawing a Square having side of length: " << mSide << std::endl;
        }

    private:
        int mSide{0};
};

class ShapeFactory
{
    public:
        virtual Shape* createShape (int aLength) = 0;
        virtual ~ShapeFactory () = default;
};


class CircleFactory : public ShapeFactory
{
    public:
        Shape* createShape (int aRadius) override { return new Circle(aRadius);}
};

class SquareFactory : public ShapeFactory
{
    public:
        Shape* createShape (int aSide) override { return new Square(aSide);}
};

int main (int argv, char** argc)
{
    ShapeFactory* circleFact = new CircleFactory ();
    ShapeFactory* squareFact = new SquareFactory ();

    Shape* circle = circleFact->createShape(10);
    Shape* square = squareFact->createShape(5);


    circle->draw ();
    square->draw ();

    delete circleFact;
    delete squareFact;
    delete circle;
    delete square;

    return 0;
}