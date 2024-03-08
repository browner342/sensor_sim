#ifndef DUMMYSENSOR_H
#define DUMMYSENSOR_H

#include "sensor.h"  // Include the base sensor header

class DummySensor : public Sensor {
public:
    DummySensor(const std::string& name);
    ~DummySensor() override;

    int getData() override;
protected:
    void generateData() override;
};

#endif // DUMMYSENSOR_H
