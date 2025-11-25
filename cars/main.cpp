#include <iostream>
#include <string>

class Engine {
private:
    int horsepower;
    double volume;         // լիտրերով, օրինակ՝ 2.0
    std::string fuelType;  // "Petrol", "Diesel", "Electric"
    int cylinders;
    bool turbo;
    double consumption;    // լ/100կմ

public:
    Engine() = default;

    Engine(int horsepower, double volume,
           std::string fuelType, int cylinders,
           bool turbo, double consumption)
        : horsepower(horsepower),
          volume(volume),
          fuelType(fuelType),
          cylinders(cylinders),
          turbo(turbo),
          consumption(consumption) {}

    void printInfo() const {
        std::cout << "Engine: " << horsepower << " hp, "
                  << volume << " L, "
                  << fuelType << ", "
                  << cylinders << " cyl, "
                  << (turbo ? "Turbo, " : "No turbo, ")
                  << "consumption: " << consumption << " L/100km"
                  << std::endl;
    }
};

class Car {
protected:
    std::string brand;
    std::string model;
    int year;
    std::string color;
    double weight;
    double maxSpeed;
    Engine engine; // Օգտագործում ենք Engine class-ը

public:
    Car() = default;

    Car(std::string brand, std::string model, int year,
        std::string color, double weight, double maxSpeed,
        const Engine& engine)
        : brand(brand),
          model(model),
          year(year),
          color(color),
          weight(weight),
          maxSpeed(maxSpeed),
          engine(engine) {}

    virtual void printInfo() const {
        std::cout << "Car: " << brand << " " << model
                  << " (" << year << "), color: " << color
                  << ", weight: " << weight << " kg, maxSpeed: "
                  << maxSpeed << " km/h" << std::endl;
        engine.printInfo();
    }

    virtual void drive() const = 0; // чисто виртуալ
    virtual ~Car() = default;
};

// 1) Sedan class
class Sedan : public Car {
private:
    int seats;
    double trunkVolume; // լիտրերով
    bool hasIsofix;     // մանկական նստատեղի ամրակ

public:
    Sedan(std::string brand, std::string model, int year,
          std::string color, double weight, double maxSpeed,
          const Engine& engine,
          int seats, double trunkVolume, bool hasIsofix)
        : Car(brand, model, year, color, weight, maxSpeed, engine),
          seats(seats),
          trunkVolume(trunkVolume),
          hasIsofix(hasIsofix) {}

    void printInfo() const override {
        std::cout << "\n[SEDAN]\n";
        Car::printInfo();
        std::cout << "Seats: " << seats
                  << ", trunk volume: " << trunkVolume << " L, "
                  << (hasIsofix ? "has ISOFIX" : "no ISOFIX")
                  << std::endl;
    }

    void drive() const override {
        std::cout << brand << " " << model
                  << " (Sedan) drives comfortably in the city." << std::endl;
    }
};

// 2) SportCar class
class SportCar : public Car {
private:
    bool hasSpoiler;
    double zeroToHundred; // 0–100 km/h վայրկյան
    bool launchControl;

public:
    SportCar(std::string brand, std::string model, int year,
             std::string color, double weight, double maxSpeed,
             const Engine& engine,
             bool hasSpoiler, double zeroToHundred, bool launchControl)
        : Car(brand, model, year, color, weight, maxSpeed, engine),
          hasSpoiler(hasSpoiler),
          zeroToHundred(zeroToHundred),
          launchControl(launchControl) {}

    void printInfo() const override {
        std::cout << "\n[SPORT CAR]\n";
        Car::printInfo();
        std::cout << "Spoiler: " << (hasSpoiler ? "Yes" : "No")
                  << ", 0-100 km/h: " << zeroToHundred << " s, "
                  << (launchControl ? "Launch control ON" : "No launch control")
                  << std::endl;
    }

    void drive() const override {
        std::cout << brand << " " << model
                  << " (SportCar) accelerates very fast!" << std::endl;
    }
};

// 3) Truck class
class Truck : public Car {
private:
    double payload;     // բեռի տարողություն, կգ
    int axles;          // առանցքների քանակ
    bool hasTrailer;    // կցորդ ունի թե ոչ

public:
    Truck(std::string brand, std::string model, int year,
          std::string color, double weight, double maxSpeed,
          const Engine& engine,
          double payload, int axles, bool hasTrailer)
        : Car(brand, model, year, color, weight, maxSpeed, engine),
          payload(payload),
          axles(axles),
          hasTrailer(hasTrailer) {}

    void printInfo() const override {
        std::cout << "\n[TRUCK]\n";
        Car::printInfo();
        std::cout << "Payload: " << payload << " kg, axles: "
                  << axles << ", "
                  << (hasTrailer ? "with trailer" : "no trailer")
                  << std::endl;
    }

    void drive() const override {
        std::cout << brand << " " << model
                  << " (Truck) carries heavy loads slowly but surely." 
                  << std::endl;
    }
};

int main() {
    // Ստեղծում ենք տարբեր շարժիչներ
    Engine cityEngine(110, 1.6, "Petrol", 4, false, 6.5);
    Engine sportEngine(420, 3.0, "Petrol", 6, true, 11.5);
    Engine truckEngine(360, 5.0, "Diesel", 8, true, 18.0);

    // Ստեղծում ենք մեքենաներ
    Sedan sedan("Toyota", "Camry", 2020, "White", 1500, 210,
                cityEngine, 5, 480, true);

    SportCar sport("BMW", "M4", 2022, "Blue", 1600, 280,
                   sportEngine, true, 4.1, true);

    Truck truck("Mercedes", "Actros", 2019, "Red", 8000, 120,
                truckEngine, 20000, 4, true);

    // Պոլիմորֆիզմ՝ բոլորն էլ Car* են
    Car* cars[3];
    cars[0] = &sedan;
    cars[1] = &sport;
    cars[2] = &truck;

    std::cout << "=== Car info and driving ===\n";
    for (int i = 0; i < 3; ++i) {
        cars[i]->printInfo();
        cars[i]->drive();
        std::cout << "------------------------------\n";
    }

    return 0;
}
