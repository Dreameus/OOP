#ifndef ENGINE_H
#define ENGINE_H

class engine
{
private:
    int power;
    int maxSpeed;
    int torque;
    int cylinders;
    std::string name;
    bool runing = false;
public:
    engine(int p, int s, int t, int c, std::string n);
    ~engine() = default;
    int getPower();
    int getMaxSpeed();
    int getTorque();
    int getcylinders();
    std::string getName();
    void printInfo();
    void start();
    void stop();
};

#endif //ENGINE_H