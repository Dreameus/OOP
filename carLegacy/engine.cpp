#include <iostream>
#include "engine.h"

engine::engine(int p, int s, int t, int c, std::string n)
{
    this->power = p;
    this->maxSpeed = s;
    this->torque = t;
    this->cylinders = c;
    this->name = n;
}

int engine::getPower()
{
    return power;
}

int engine::getMaxSpeed()
{
    return maxSpeed;
}

int engine::getTorque()
{
    return torque;
}

int engine::getcylinders()
{
    return cylinders;
}

std::string engine::getName()
{
    return name;
}

void engine::printInfo()
{
    std::cout << "Power is :" << power << std::endl;
    std::cout << "Max speed is :" << maxSpeed << std::endl;
    std::cout << "The count of cylinders :" << cylinders << std::endl;
    std::cout << "Torque :" << torque << std::endl;
    std::cout << "Engine name is :" << name << std::endl;
    if(runing)
    {
        std::cout << "Engine is running" << std::endl;
    }
    else
    {
        std::cout << "Engine stoped" << std::endl;
    }
}

void engine::start()
{
    runing = true;
    std::cout << "Engine :" << name << "is runing" << std::endl;
}

void engine::stop()
{
    runing = false;
    std::cout << "Engine :" << name << "is not running" << std::endl;
}