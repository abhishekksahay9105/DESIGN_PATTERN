/*
    1. The Adapter Pattern is a structural design pattern used to make incompatible interfaces work together.
*/



#include <bits/stdc++.h>
using namespace std;

class LegacyPrinter
{
public:
    void PrintInUpperCase(std::string &s1)
    {
        std::cout << "Printing in Upper case: " << s1 << std::endl;
    }
};

class PrinterAdapter
{
private:
    LegacyPrinter legacyPrinter;

public:
    void sendCommand(std::string s1)
    {
        for (auto &c : s1)
        {
            c = toupper(c);
        }

        legacyPrinter.PrintInUpperCase(s1);
    }
};

class ModernComputer
{
private:
    PrinterAdapter printAdapter;

public:
    void sendCommand (std::string s1)
    {
        printAdapter.sendCommand(s1);
    }
};

int main ()
{
    string fileName = "abc.txt";
    bool status = false;
    vector<vector<string>> names;
   
    cin >> fileName;
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }
 
    int num;
 
    while (file >> num)
    {
        std::cout << num << " ";
        while (num--)
        {
            std::string s1;
            file >> s1;
            std:: cout << s1 << " ";
        }
    }
    
    return 0;
}