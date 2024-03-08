#ifndef PLATFORM_H
#define PLATFORM_H

#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <string>
#include "circular_buffer.h"
#include "sensor/sensor.h"
#include "utils/logger.h"

struct Data {
    std::string name;
    int value{-1};
};

class Platform {
public:
    Platform(int bufferSize, int logInterval, const std::string& logFilename);
    ~Platform();

    Platform(const Platform&) = delete;
    Platform& operator=(const Platform&) = delete;

    void registerSensor(std::shared_ptr<Sensor> sensor);
    void startSimulation();
    void stopSimulation();

private:
    void collectDataFromSensors();
    void logData();

    std::vector<std::shared_ptr<Sensor>> sensors;
    std::shared_ptr<CircularBuffer<Data>> dataBuffer;
    std::thread dataCollectionThread;
    bool simulationRunning;
    std::mutex bufferMutex;

    std::thread loggingThread;
    std::atomic<bool> loggingActive;
    std::shared_ptr<Logger> logger;
    int logInterval; // Log interval in seconds
};

#endif // PLATFORM_H
