#include <iostream>
#include "engine.h"
#include "car.h"

car::car(int p, int y, std::string b, std::string m, std::string c, engine& e) : price(p), year(y), brend(b), mark(m), color(c), motor(e)
{
    // this->price = p;
    // this->year = y;
    // this->brend = b;
    // this->mark = m;
    // this->color = c;
    // this->motor = e;
}

void car::start()
{
    motor.start();
}

void car::stop()
{
    motor.stop();
}

void car::printInfo()
{
    std::cout << "Price is :" << price << std::endl;
    std::cout << "Year is :" << year << std::endl;
    std::cout << "Brend is :" << brend << std::endl;
    std::cout << "Mark is :" << mark << std::endl;
    std::cout << "Color is :" << color << std::endl;
    motor.printInfo();
}

sedan::sedan(int p, int y, std::string b, std::string m, std::string c, const engine& e, int s)
    : car(p, y, b, m, c, e), seats(s)
{

}

void sedan::info()
{
    printInfo();
    std::cout << "Trunk value is : " << trunkValue << std::endl;
    std::cout << "Count of seats is : " << seats << std::endl;
    std::cout << "Interior is : " << interior << std::endl;
    if(hasSunroof)
    {
        std::cout << mark << "has sunroof" << std::endl;
    }
    else
    {
        std::cout << mark << "has not sunroof" << std::endl;
    }
}