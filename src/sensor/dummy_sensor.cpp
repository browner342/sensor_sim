#include "dummy_sensor.h"

#include <chrono>
#include <random>

DummySensor::DummySensor(const std::string& name) : Sensor(name) {}

DummySensor::~DummySensor() {
    stop(); // Ensure the worker thread is stopped
}

int DummySensor::getData() {
    return data; // Return the data produced by generateData()
}

void DummySensor::generateData() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 99);

    while (active) {
        data = dist(gen); // Generate random data
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate time delay
    }
}
