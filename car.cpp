#include <iostream>
#include <thread>
#include <chrono>

class transport {
    private:
    std::string model;
    int capacity;
    int maxSpeed;
    int speed = 0;
    std::string fuelType;
    int fuel;
    std::string weelsName;
    int weelsNumber;
    int rpm = 0;
    std::string oilType;
    double oil = 5;
    int i;

    public:

    transport(std::string model, int capacity, int maxSpeed, std::string fuelType, int fuel, std::string weelsName, int weelsNumber, std::string oilType)
    {
        this->model = model;
        this->capacity = capacity;
        this->speed = speed;
        this->fuelType = fuelType;
        this->fuel = fuel;
        this->weelsName = weelsName;
        this->weelsNumber = weelsNumber;
        this->oilType = oilType;
    }

    void hung()
    {
        std::cout << model << "hung" << std::endl;
    }

    void start()
    {
        std::cout << model << "start" << std::endl;
    }
    void stop()
    {
        std::cout << model << "stop" << std::endl;
    }
    void go()
    {
        std::cout << model << "go" << std::endl;
    }
    void turnLeft()
    {
        std::cout << model << "turnLeft" << std::endl;
    }
    void turnRight()
    {
        std::cout << model << "turnRight" << std::endl;
    }
    void checkMaxsSpeed()
    {
        std::cout << model << "maxSpeed: " << maxSpeed << std::endl;
    }
    void gas()
    {
        i++;
        if (i == 10)
        {
            oil -= 0.1;
            i = 0;
        }
        std::cout << model << "gas" << std::endl;
        std::cout << "fuel: " << fuel << std::endl;
        fuel -= 1;
        std::cout << "fuel: " << fuel << std::endl;
        std::cout << "speed: " << speed << std::endl;
        if (maxSpeed > speed)
        {
            speed += 10;
        }
        rpm += 1000;
        std::cout << "speed: " << speed << std::endl;
        std::cout << "rpm: " << rpm << std::endl;
        std::cout << "oil: " << oil << std::endl;
    }
    void brake()
    {
        std::cout << model << "brake" << std::endl;
        std::cout << "speed: " << speed << std::endl;
        speed -= 10;
        rpm -= 1000;
        std::cout << "speed: " << speed << std::endl;
        std::cout << "rpm: " << rpm << std::endl;
    }
    void fillFuel()
    {
        std::cout << model << "fill Fuel" << std::endl;
        fuel += 10;
    }
    void changeFuelType()
    {
        std::cout << model << "Fuel Type: " << fuelType << std::endl;
        std::cout << "fuel: " << fuel <<std::endl;
        fuel += 100;
        std::cout << "fuel: " << fuel <<std::endl;
    }
    void checkOil()
    {
        std::cout << model << "check Oil" << std::endl;
        std::cout << "oil: " << oil << std::endl;
    }
    void changeOil()
    {
        std::cout << model << "change Oil" << std::endl;
        std::cout << "oil type: " << oilType << std::endl;
        std::cout << "oil: " << oil << std::endl;
        oil = 0;
        std::cout << "oil: " << oil << std::endl;
        oil = 5;
        std::cout << "oil: " << oil << std::endl;
        std::cout << "oil has been changed" << std::endl;
        i = 0;
    }

};

void printFunctions()
{
    std::cout << "methods to use car" << std::endl;
    std::cout << "1. start" << std::endl;
    std::cout << "2. hung" << std::endl;
    std::cout << "3. stop" << std::endl;
    std::cout << "4. go" << std::endl;
    std::cout << "5. turnLeft" << std::endl;
    std::cout << "6. turnRight" << std::endl;
    std::cout << "7. checkMaxsSpeed" << std::endl;
    std::cout << "8. gas" << std::endl;
    std::cout << "9. brake" << std::endl;
    std::cout << "10. fillFuel" << std::endl;
    std::cout << "11. changeFuelType" << std::endl;
    std::cout << "12. checkOil" << std::endl;
    std::cout << "13. changeOil" << std::endl;
    std::cout << "14. exit" << std::endl;
}

int main()
{
    std::string model;
    std::string fuelType;
    std::string weelsName;
    std::string oilType;

    int capacity;
    int fuel;
    int maxSpeed;
    int weelsNumber;

    std::cout << "Enter model: ";
    std::cin >> model;
    std::cout << "Enter fuelType: ";
    std::cin >> fuelType;
    std::cout << "Enter weelsName: ";
    std::cin >> weelsName;
    std::cout << "Enter oilType: ";
    std::cin >> oilType;
    std::cout << "Enter capacity: ";
    std::cin >> capacity;
    std::cout << "Enter fuel: ";
    std::cin >> fuel;
    std::cout << "Enter maxSpeed: ";
    std::cin >> maxSpeed;
    std::cout << "Enter weelsNumber: ";
    std::cin >> weelsNumber;
    transport car(model, capacity, maxSpeed, fuelType, fuel, weelsName, weelsNumber, oilType);

    while (true)
    {
        printFunctions();

        int number;
        std::cout << "Choose method: ";
        std::cin >> number;

        switch (number)
        {
            case 1:
                car.start();
                break;
            case 2:
                car.hung();
                break;
            case 3:
                car.stop();
                break;
            case 4:
                car.go();
                break;
            case 5:
                car.turnLeft();
                break;
            case 6:
                car.turnRight();
                break;
            case 7:
                car.checkMaxsSpeed();
                break;
            case 8:
                car.gas();
                break;
            case 9:
                car.brake();
                break;
            case 10:
                car.fillFuel();
                break;
            case 11:
                car.changeFuelType();
                break;
            case 12:
                car.checkOil();
                break;
            case 13:
                car.changeOil();
                break;
            case 14:
                std::cout << "exit" << std::endl;
                return 0;
                break;
        }
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return 0;
}