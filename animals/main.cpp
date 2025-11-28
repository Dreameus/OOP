#include <iostream>

class animal {
protected:
    int age;
    std::string name;
    std::string color;
    int weight;
    int height;
    int legCount;
public:
    animal() = default;
    animal(int age, std::string name, std::string color, int weight, int height, int legCount) {
        this->age = age;
        this->name = name;
        this->color = color;
        this->weight = weight;
        this->height = height;
        this->legCount = legCount;
    }
public:
    virtual void makeSound() const = 0;
    virtual ~animal() = default;
    animal(animal&& other)
    {
        age = other.age;
        name = other.name;
        color = other.color;
        weight = other.weight;
        height = other.height;
        legCount = other.legCount;
        other.age = 0;
        other.name = "";
        other.color = "";
        other.weight = 0;
        other.height = 0;
        other.legCount = 0;
    }
    animal& operator=(animal&& other)
    {
        if (this != &other)
        {
            age = other.age;
            name = other.name;
            color = other.color;
            weight = other.weight;
            height = other.height;
            legCount = other.legCount;
            other.age = 0;
            other.name = "";
            other.color = "";
            other.weight = 0;
            return *this;
        }
        return *this;
    }

    bool operator==(const animal& other) const
    {
        return weight == other.weight;
    }

    bool operator>(const animal& other) const
    {
        return weight > other.weight;
    }

    bool operator<(const animal& other) const
    {
        return weight < other.weight;
    }

    bool operator>=(const animal& other) const
    {
        return weight >= other.weight;
    }

    bool operator<=(const animal& other) const
    {
        return weight <= other.weight;
    }

    bool operator!=(const animal& other) const
    {
        return weight != other.weight;
    }
};

class dog : public animal {
private:
    std::string breed;
    int energyLevel;
    bool trained;
    std::string favoriteToy;
    std::string favoriteFood;
    int barkVolume;

public:
    dog(int age, std::string name, std::string color, int weight, int height, int legCount, std::string breed, int energyLevel, bool trained, std::string favoriteToy, std::string favoriteFood, int barkVolume) : animal(age, name, color, weight, height, legCount) {
        this->breed = breed;
        this->energyLevel = energyLevel;
        this->trained = trained;
        this->favoriteToy = favoriteToy;
        this->favoriteFood = favoriteFood;
        this->barkVolume = barkVolume;
    }
    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class cat : public animal {
private:
    std::string furColor;
    int purrVolume;
    bool lovesCats;
    std::string favoriteToy;
    std::string favoriteFood;
    int meowVolume;

public:
    cat(int age, std::string name, std::string color, int weight, int height, int legCount,
        std::string furColor, int purrVolume, bool lovesCats,
        std::string favoriteToy, std::string favoriteFood, int meowVolume)
        : animal(age, name, color, weight, height, legCount)
    {
        this->furColor = furColor;
        this->purrVolume = purrVolume;
        this->lovesCats = lovesCats;
        this->favoriteToy = favoriteToy;
        this->favoriteFood = favoriteFood;
        this->meowVolume = meowVolume;
    }

    void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

class bird : public animal {
private:
    std::string featherColor;
    int wingSpan;
    bool lovesBirds;
    std::string favoriteToy;
    std::string favoriteFood;
    int chirpVolume;
public:
    bird(int age, std::string name, std::string color, int weight, int height, int legCount, std::string featherColor, int wingSpan, bool lovesBirds, std::string favoriteToy, std::string favoriteFood, int chirpVolume) : animal(age, name, color, weight, height, legCount) {
        this->featherColor = featherColor;
        this->wingSpan = wingSpan;
        this->lovesBirds = lovesBirds;
        this->favoriteToy = favoriteToy;
        this->favoriteFood = favoriteFood;
        this->chirpVolume = chirpVolume;
    }
    void makeSound() const override {
        std::cout << "Chirp!" << std::endl;
    }
};

class fish : public animal {
private:
    std::string bodyColor;
    int size;
    bool lovesFish;
    std::string favoriteToy;
    std::string favoriteFood;
    int swimVolume;
public:
    fish(int age, std::string name, std::string color, int weight, int height, int legCount, std::string bodyColor, int size, bool lovesFish, std::string favoriteToy, std::string favoriteFood, int swimVolume) : animal(age, name, color, weight, height, legCount) {
        this->bodyColor = bodyColor;
        this->size = size;
        this->lovesFish = lovesFish;
        this->favoriteToy = favoriteToy;
        this->favoriteFood = favoriteFood;
        this->swimVolume = swimVolume;
    }
    void makeSound() const override {
        std::cout << "Blt!" << std::endl;
    }
};

class horse : public animal {
private:
    int tailLength;
    bool lovesHorses;
    std::string favoriteToy;
    std::string favoriteFood;
    int gallopVolume;
    std::string maneColor;

public:
    horse(int age, std::string name, std::string color, int weight, int height, int legCount,
          int tailLength, bool lovesHorses, std::string favoriteToy,
          std::string favoriteFood, int gallopVolume, std::string maneColor)
        : animal(age, name, color, weight, height, legCount)
    {
        this->tailLength = tailLength;
        this->lovesHorses = lovesHorses;
        this->favoriteToy = favoriteToy;
        this->favoriteFood = favoriteFood;
        this->gallopVolume = gallopVolume;
        this->maneColor = maneColor;
    }

    void makeSound() const override {
        std::cout << "Neigh!" << std::endl;
    }
};

class snake : public animal {
private:
    int tailLength;
    bool lovesSnakes;
    std::string favoriteToy;
    std::string favoriteFood;
    int hissVolume;
public:
    snake(int age, std::string name, std::string color, int weight, int height, int legCount, int tailLength, bool lovesSnakes, std::string favoriteToy, std::string favoriteFood, int hissVolume) : animal(age, name, color, weight, height, legCount) {
        this->tailLength = tailLength;
        this->lovesSnakes = lovesSnakes;
        this->favoriteToy = favoriteToy;
        this->favoriteFood = favoriteFood;
        this->hissVolume = hissVolume;
    }
    void makeSound() const override {
        std::cout << "sss!" << std::endl;
    }
};

class turtle : public animal {
private:
    std::string shellColor;
    int shellSize;
    bool lovesTurtles;
    std::string favoriteToy;
    std::string favoriteFood;
    int turtleVolume;
public:
    turtle(int age, std::string name, std::string color, int weight, int height, int legCount, std::string shellColor, int shellSize, bool lovesTurtles, std::string favoriteToy, std::string favoriteFood, int turtleVolume) : animal(age, name, color, weight, height, legCount) {
        this->shellColor = shellColor;
        this->shellSize = shellSize;
        this->lovesTurtles = lovesTurtles;
        this->favoriteToy = favoriteToy;
        this->favoriteFood = favoriteFood;
        this->turtleVolume = turtleVolume;
    }
    void makeSound() const override {
        std::cout << "sss!" << std::endl;
    }
};

class animals {
private:
    int capacity;
    int animalsCount = 0;
    animal** zoo = nullptr;
public:
    animals(int c)
    {
        this -> capacity = c;
        zoo = new animal*[capacity];
    }

    ~animals()
    {
        delete[] zoo;
    }

    animals(const animals& other)
    {
        this -> capacity = other.capacity;
        this -> animalsCount = other.animalsCount;
        zoo = new animal*[capacity];
        for (int i = 0; i < animalsCount; i++)
        {
            zoo[i] = other.zoo[i];
        }
    }

    animals& operator=(const animals& other) {
        if (this != &other) {
            delete[] zoo;
            capacity = other.capacity;
            animalsCount = other.animalsCount;
            zoo = new animal*[capacity];
            for (int i = 0; i < animalsCount; i++)
            {
                zoo[i] = other.zoo[i];
            }
            return *this;
        }
        return *this;
    }
    animals(animals&& other) noexcept
    {
        this -> capacity = other.capacity;
        this -> animalsCount = other.animalsCount;
        zoo = other.zoo;
        other.capacity = 0;
        other.animalsCount = 0;
        other.zoo = nullptr;
    }

    animals& operator=(animals&& other) noexcept
    {
        this -> capacity = other.capacity;
        this -> animalsCount = other.animalsCount;
        this -> zoo = std::move(other.zoo);
        other.capacity = 0;
        other.animalsCount = 0;
        other.zoo = nullptr;
        return *this;
    }

    void addAnimal(animal* a)
    {
        if (animalsCount < capacity)
        {
            zoo[animalsCount++] = a;
        }
    }

    void printAnimals()
    {
        for (int i = 0; i < animalsCount; i++)
        {
            zoo[i]->makeSound();
        }
    }

    int getCapacity() const { return capacity; }

    int getAnimalsCount() const { return animalsCount; }

};

int main() {
    dog d(3, "Rex", "Brown", 20, 40, 4, "German Shepherd",
          80, true, "Ball", "Meat", 10);

    cat c(2, "Murka", "White", 5, 25, 4,
          "White", 5, true, "Mouse Toy", "Milk", 3);

    bird b(1, "Koko", "Green", 1, 10, 2,
           "Green", 20, true, "Bell", "Seeds", 5);

    fish f(1, "Nemo", "Orange", 1, 5, 0,
           "Orange", 10, false, "Bubbles", "Flakes", 1);

    horse h(5, "Spirit", "Brown", 200, 150, 4,
            80, true, "Apple Toy", "Hay", 12, "Black");

    snake s(2, "Slither", "Green", 3, 2, 0,
            30, true, "Stick", "Mice", 7);

    turtle t(10, "Leo", "Green", 10, 20, 4,
             "Dark Green", 20, true, "Rock", "Veggies", 2);

    animals zoo(10);

    zoo.addAnimal(&d);
    zoo.addAnimal(&c);
    zoo.addAnimal(&b);
    zoo.addAnimal(&f);
    zoo.addAnimal(&h);
    zoo.addAnimal(&s);
    zoo.addAnimal(&t);

    zoo.printAnimals();

    std::cout << (d < c) << std::endl;
    std::cout << (d > c) << std::endl;
    std::cout << (d <= c) << std::endl;
    std::cout << (d >= c) << std::endl;
    std::cout << (d == c) << std::endl;
    std::cout << (d != c) << std::endl;

    return 0;
}
