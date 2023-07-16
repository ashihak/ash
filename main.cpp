#include <iostream>
#include <string>

class WeatherReport {
public:
    virtual std::string getWeatherDescription() const = 0;
};

class SunnyReport : public WeatherReport {
public:
    std::string getWeatherDescription() const override {
        return "Sunny";
    }
};

class CloudyReport : public WeatherReport {
public:
    std::string getWeatherDescription() const override {
        return "Cloudy";
    }
};

class RainyReport : public WeatherReport {
public:
    std::string getWeatherDescription() const override {
        return "Rainy";
    }
};

int main() 
{
    std::string name;
    std::string college;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << "Enter your college name: ";
    std::getline(std::cin, college);

    WeatherReport* weekReport[7];
    weekReport[0] = new SunnyReport();
    weekReport[1] = new CloudyReport();
    weekReport[2] = new RainyReport();
    weekReport[3] = new CloudyReport();
    weekReport[4] = new SunnyReport();
    weekReport[5] = new RainyReport();
    weekReport[6] = new CloudyReport();

    std::cout << "Weather report for the past week:\n";
    for (int i = 0; i < 7; i++)
    {
        std::cout << "Day " << (i + 1) << ": " << weekReport[i]->getWeatherDescription() << "\n";
    }

    // Cleanup
    for (int i = 0; i < 7; i++) 
    {
        delete weekReport[i];
    }

return 0;
}