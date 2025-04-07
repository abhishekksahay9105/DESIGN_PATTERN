#include <iostream>
#include <vector>

class Circle;
class Square;

// Visitor Interface
class ShapeVisitor
{
public:
    virtual void visit(Circle &aCircle) = 0;
    virtual void visit(Square &aSquare) = 0;
};

// Element Interface
class Shape
{
public:
    virtual void accept(ShapeVisitor &aVisitor) = 0;
};

// Concrete Element : Circle
class Circle : public Shape
{
public:
    void accept(ShapeVisitor &aVisitor) override
    {
        aVisitor.visit(*this);
    }

    void draw()
    {
        std::cout << "Drawing Circle\n"
                  << std::endl;
    }
};

// Concrete Element : Square
class Square : public Shape
{
public:
    void accept(ShapeVisitor &aVisitor) override
    {
        aVisitor.visit(*this);
    }

    void draw()
    {
        std::cout << "Drawing Shape\n"
                  << std::endl;
    }
};

// Concreate Visitor : DrawingVisitor
class DrawingVisitor : public ShapeVisitor
{
    public:
        void visit(Circle &aCircle) override
        {
        }
    
        void visit(Square &aSquare) override
        {
        }
};

// Concreate Visitor : AreaVisitor
class AreaVisitor : public ShapeVisitor
{
public:
    void visit(Circle &aCircle) override
    {
    }

    void visit(Square &aSquare) override
    {
    }
};

class ShapeContanier
