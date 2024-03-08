#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <atomic>
#include <thread>

class Sensor {
public:
    Sensor(const std::string& name);
    virtual ~Sensor();

    void start();
    void stop(); 
    virtual int getData() = 0; // Make getData() a pure virtual function
    std::string getName() const;

protected:
    virtual void generateData() = 0; // Make generateData() a pure virtual function
    std::atomic<bool> active;
    std::atomic<int> data{-1};
    std::thread workerThread;
    std::string name;
};

#endif // SENSOR_H
