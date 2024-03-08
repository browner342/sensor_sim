#include "platform.h"
#include "sensor/sensor.h"

#include <memory>
#include <iostream>

Platform::Platform(int _bufferSize, int _logInterval, const std::string& _logFilename) 
    : simulationRunning(false), loggingActive(false), logInterval(_logInterval) 
    {
        dataBuffer = std::make_unique<CircularBuffer<Data>>(_bufferSize);
        logger = std::make_unique<Logger>(_logFilename);
    }

Platform::~Platform() {
    stopSimulation();
}

void Platform::registerSensor(std::shared_ptr<Sensor> sensor) {
    sensors.push_back(sensor);
}

void Platform::collectDataFromSensors() {
    while (simulationRunning) {
        for (auto& sensor : sensors) {
            Data data;
            data.value = sensor->getData();
            data.name = sensor->getName();

            std::lock_guard<std::mutex> guard(bufferMutex);
            dataBuffer->put(data);
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Platform::logData() {
    while (loggingActive) {
        std::this_thread::sleep_for(std::chrono::seconds(logInterval));
        std::lock_guard<std::mutex> guard(bufferMutex);

        for (const auto& data : dataBuffer->get().value_or(std::vector<Data>{})) {
            std::string msg = data.name + ": " + std::to_string(data.value);
            logger->log(msg);
        }
    }
}

void Platform::startSimulation() {
    simulationRunning = true;
    dataCollectionThread = std::thread(&Platform::collectDataFromSensors, this);

    loggingActive = true;
    loggingThread = std::thread(&Platform::logData, this);
}

void Platform::stopSimulation() {
    simulationRunning = false;
    
    if (dataCollectionThread.joinable()) {
        dataCollectionThread.join();
    }

    loggingActive = false;
    if (loggingThread.joinable()) {
        loggingThread.join();
    }
}
