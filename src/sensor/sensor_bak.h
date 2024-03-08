#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <atomic>
#include <thread>


class Sensor {
public:
    Sensor(const std::string& name);
    ~Sensor();

    void start();
    void stop(); 
    int getData();
    std::string getName();

private:
    void generateData();
    std::atomic<bool> active;
    std::atomic<int> data{-1};
    std::thread workerThread;
    std::string name;
};

#endif // SENSOR_H