#include <iostream>

class Image
{
    public:
        virtual void display () = 0;
        virtual ~Image () = default;
};

class RealImage : public Image
{
    public:
        RealImage (std::string aFileName) : mFileName(aFileName)
        {
            std::cout << "Loading Image: " << mFileName;
        }

        void display () override
        {
            std::cout << "Displaying Image : " << mFileName << std::endl;
        }

    private:
        std::string mFileName{""};
};

class ImageProxy : public Image
{
    private:
        std::string      mFileName;
        RealImage*       mRealImage{nullptr};

    public:
        ImageProxy (std::string aFileName) : mFileName(aFileName)
        {

        }

        void display () override
        {
            if (mRealImage == nullptr)
            {
                mRealImage = new RealImage(mFileName);
            }

            mRealImage->display();
        }
};

int main (int argv, char** argc)
{
    Image* image = new ImageProxy ("/in/vrtime/abhsah58.txt");

    image->display();
    image->display();
    return 0;
}