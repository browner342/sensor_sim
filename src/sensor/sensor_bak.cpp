#include "sensor.h"

#include <chrono>
#include <thread>
#include <random>

Sensor::Sensor(const std::string& name) : name(name) {}

Sensor::~Sensor() {
    stop(); 
}

void Sensor::start() {
    active = true;
    workerThread = std::thread(&Sensor::generateData, this);
}

void Sensor::stop() {
    active = false;
    if (workerThread.joinable()) {
        workerThread.join();
    }
}

int Sensor::getData() {
    return data;
}

std::string Sensor::getName() {
    return name;
}

void Sensor::generateData() {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 99);

    while (active) {
        data = dist(gen);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}