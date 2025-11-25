#ifndef CAR_H
#define CAR_H

#include "engine.h"

class car
{
private:
    int price;
    int year;
    std::string brend;
    std::string mark;
    std::string color;
    engine motor;
public:
    car(int p, int y, std::string b, std::string m, std::string c, engine& e);
    ~car() = default;
    virtual void start();
    virtual void stop();
    virtual void printInfo();
};

class sedan : public car
{
private:
    int trunkValue;
    bool hasSunroof;
    int seats;
    std::string interior;
public:
    sedan(int p, int y, std::string b, std::string m, std::string c, engine& e, int tV, bool hS, int s, std::string i);
    ~sedan() = default;
    void info();
};

#endif // CAR_H