#include "sensor.h"

Sensor::Sensor(const std::string& name) : name(name), active(false), data(-1) {}

Sensor::~Sensor() {
    stop(); 
}

void Sensor::start() {
    active = true;
    workerThread = std::thread(&Sensor::generateData, this); // This will now call the derived class implementation
}

void Sensor::stop() {
    active = false;
    if (workerThread.joinable()) {
        workerThread.join();
    }
}

std::string Sensor::getName() const {
    return name;
}
