#include <iostream>

//Abstraction : shape
class shape
{
    public:
        virtual void draw () = 0;
};

class Renderer
{
    public:
        virtual void render () = 0;
};

class VectorRenderer : public Renderer
{
    public:
        void render ()
        {
            std::cout << "Render as a Vector\n";
        }
};

class RasterRenderer : public Renderer
{
    public:
        void render ()
        {
            std::cout << "Render as a Raster\n";
        }
};

class Circle : public shape
{
    Circle (Renderer& aRenderer): mRenderer(aRenderer)
    {

    }

    void draw ()
    {
        std::cout << "Drawing a Circle\n";
        mRenderer.render();
    }

    public:
        Renderer& mRenderer;
};

class Square : public shape
{
    Shape (Renderer& aRenderer): mRenderer(aRenderer)
    {

    }

    void draw ()
    {
        std::cout << "Drawing a Square\n";
        mRenderer.render();
    }

    public:
        Renderer& mRenderer;
};

int main ()
{
    VectorRenderer vectorRenderer;
    RasterRenderer rasterRenderer;

    Circle cirle(vectorRenderer);
    Square square(rasterRenderer);

    circle.draw();
    square.draw();

    return 0;
}
