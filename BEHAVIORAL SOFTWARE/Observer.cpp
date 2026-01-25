/*
    1. The Observer Pattern is a behavioral design pattern where one object (Subject) maintains a list of dependent objects (Observers) and
       automatically notifies them whenever its state changes.
    2. Why Observer Pattern?
        We need Observer when:
            ✔ Many objects need to react when one object changes
            ✔ You want to avoid tightly coupling objects
            ✔ You want a clean publisher → subscriber model
            ✔ You want dynamic subscription (attach/detach observers at runtime)
*/

#include <iostream>
#include <vector>

// Observer Interface
class Observer
{
public:
    virtual void update(double aTemperature, double aHumidity, double aPressure) = 0;
};

// Concrete Observer
class Display : public Observer
{
public:
    void update(float temperature, float humidity, float pressure)
    {
        std::cout << "Display: Temperature = " << temperature
                  << "°C, Humidity = " << humidity
                  << "%, Pressure = " << pressure << " hPa"
                  << std::endl;
    }
};

// Subject (WeatherStation) class
class WeatherStation
{
private:
    double mTemperature;
    double mHumidity;
    double mPressure;
    std::vector<Observer *> mObserver;

public:
    void registerObserver(Observer *aObserver)
    {
        mObserver.push_back(aObserver);
    }

    void removeObserver(Observer *aObserver)
    {
        // I can Implement Observer If I need
    }

    void notifyObserver()
    {
        for (auto x : mObserver)
        {
            x->update(mTemperature, mHumidity, mPressure)
        }
    }

    void setMeasurement(double aTemperature, double aHumidity, double aPressure)
    {
        mTemperature = aTemperature;
        mHumidity = aHumidity;
        mPressure = aPressure;
        notifyObserver();
    }
};

int main (int argv, char* argc)
{
    WeatherStation weatherStation;

    Display display1;
    Display display2;

    weatherStation.registerObserver(&display1);
    weatherStation.registerObserver(&display2);

    weatherStation.setMeasurement (1, 2, 3);
    weatherStation.setMeasurement (4, 5, 6);
    return 0;
}
