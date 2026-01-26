#include <iostream>
#include <memory>
#include <fstream>

class Logger
{
    public:
        static Logger* getInstance()
        {
            if (mInstance == nullptr)
            {
                mInstance = std::unique_ptr<Logger>(new Logger());
            }   
            return mInstance;
        }

        void LOG (const char* aMessage)
        {
            // Implementation of logging the message
            std::cout << "Log: " << aMessage << std::endl;
        }

    private:
        Logger() // Private constructor
        {

        }

        std::unique_ptr<Logger>     mInstance;
        mutable std::ofstream        mLogFile;
};