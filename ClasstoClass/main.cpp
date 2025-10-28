#include <iostream>
#include <string>

class Engine
{
private:
    int horsepower;
    std::string type;
    int cylinders;
    std::string oilType;
    int oil;
    std::string fuelType;
    int fuel;

public:
    Engine(int hp, std::string tp, int cl, std::string ot, int ov, std::string ft, int fv)
    {
        this->horsepower = hp;
        this->type = tp;
        this->cylinders = cl;
        this->oilType = ot;
        this->oil = ov;
        this->fuelType = ft;
        this->fuel = fv;
    }

    void start()
    {
        std::cout << "Engine with " << horsepower << " HP started." << std::endl;
    }

    void stop()
    {
        std::cout << "Engine stopped." << std::endl;
    }
    void printOilType()
    {
        std::cout << "Oil type: " << oilType << std::endl;
        std::cout << "Oil current: " << oil << std::endl;
    }
    void printFuelType()
    {
        std::cout << "Fuel type: " << fuelType << std::endl;
        std::cout << "Fuel current: " << fuel << std::endl;
    }
    void addFuel(int amount)
    {
        fuel += amount;
    }
    void addOil(int amount)
    {
        oil += amount;
    }
};

class Car
{
private:
    std::string model;
    std::string color;
    int year;
    Engine* engine;
public:
    Car(std::string m, std::string cl, int yr, Engine* e)
    {
        this->model = m;
        this->color = cl;
        this->year = yr;
        this->engine = e;
    }

    void start()
    {
        std::cout << model << " is starting..." << std::endl;
        engine->start();
    }

    void stop()
    {
        std::cout << model << " is stopping..." << std::endl;
        engine->stop();
    }
    void printColor()
    {
        std::cout << "Color: " << color << std::endl;
    }
    void printYear()
    {
        std::cout << "Year: " << year << std::endl;
    }
    std::string getModel()
    {
        return model;
    }
    void changeColor(std::string c)
    {
        color = c;
    }
    std::string getColor()
    {
        return color;
    }
    void addFuel(int amount)
    {
        engine->addFuel(amount);
    }
    void addOil(int amount)
    {
        engine->addOil(amount);
    }
    void printAll()
    {
        std::cout << "Model: " << model << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Engine: " << std::endl;
        engine->printOilType();
        engine->printFuelType();
    }

};

class Driver
{
private:
    std::string name;
    bool driverLicense;
    Car* car;
public:
    Driver(std::string n, bool lic, Car* c)
    {
        this->name = n;
        this->driverLicense = lic;
        this->car = c;
    }
    void drive()
    {
        std::cout << name << " is driving the " << car->getModel() << "." << std::endl;
        car->start();
    }

    void stopDriving()
    {
        std::cout << name << " stopped driving." << std::endl;
        car->stop();
    }
    void changeCar(Car* c)
    {
        car = c;
    }
    void fillOil(int amount)
    {
        car->addOil(amount);
    }
    void fillFuel(int amount)
    {
        car->addFuel(amount);
    }

};

class parking
{
private:
    int freeSlots;
    int occupiedSlots;
    int totalSlots;
    int pointToPark;
    Car** cars;
public:
    parking(int ts)
    {
        this->totalSlots = ts;
        this->freeSlots = ts;
        this->occupiedSlots = 0;
        this->cars = new Car*[ts];
        for (int i = 0; i < ts; i++)
        {
            cars[i] = nullptr;
        }
    }
    void park(Car* c)
    {
        if (freeSlots > 0)
        {
            cars[pointToPark] = c;
            occupiedSlots++;
            freeSlots--;
            pointToPark++;
            if (pointToPark == totalSlots) {
                pointToPark = 0;
            }
        }
    }
    void unpark(int slot)
    {
        if (slot < occupiedSlots)
        {
            cars[slot] = nullptr;
            occupiedSlots--;
            freeSlots++;
        }
    }
    void printAll()
    {
        for (int i = 0; i < occupiedSlots; i++)
        {
            std::cout << "Slot " << i << ": ";
            cars[i]->printAll();
        }
    }
};

int main()
{
        Engine bmwEngine(250, "V6", 6, "Castrol", 4, "Gasoline", 40);
        Engine toyotaEngine(180, "Inline-4", 4, "Mobil", 3, "Gasoline", 35);
    
        Car bmw("BMW M3", "Black", 2020, &bmwEngine);
        Car toyota("Toyota Camry", "White", 2019, &toyotaEngine);
    
        Driver razz("Razz", true, &bmw);
    
        razz.drive();
        razz.fillFuel(10);
        razz.fillOil(1);
        razz.stopDriving();

        std::cout << std::endl;
    
        razz.changeCar(&toyota);
        razz.drive();
        toyota.changeColor("Silver");
        toyota.printColor();
        toyota.printYear();
        razz.stopDriving();
    
        parking p(3);
        p.park(&bmw);
        p.park(&toyota);
        p.printAll();

        std::cout << "Unpark slot 0" << std::endl;
        p.unpark(0);
        p.printAll();

        std::cout << "Direct car details" << std::endl;
        bmw.printAll();
        std::cout << std::endl;
        toyota.printAll();

    return 0;
}
