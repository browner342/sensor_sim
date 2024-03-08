#include "CLI/CLI.hpp" 
#include "platform/platform.h"
#include "sensor/sensor.h"
#include "sensor/dummy_sensor.h"
#include "config.h"

#include <iostream>
#include <vector>
#include <memory>

int main(int argc, char **argv) {
    CLI::App app{"Sensor Network Simulation"};

    int numSensors = NUMBER_OF_SENSORS;
    int logInterval = LOG_INTERVAL;
    int buffSize = BUFFER_SIZE;
    std::string logFileName = LOG_FILE_NAME;

    // Adding options to the app
    app.add_option("-n,--num", numSensors, "Number of sensors");
    app.add_option("-i,--interval", logInterval, "Logging interval in seconds");
    app.add_option("-f,--file", logFileName, "Log file name");
    app.add_option("-b,--buff_size", buffSize, "Logging buffer size.");

    CLI11_PARSE(app, argc, argv);

    // Now, use the parsed options
    try {
        Platform mainPlatform(buffSize, logInterval, logFileName);

        std::vector<std::shared_ptr<Sensor>> sensors;
        for (int i = 0; i < numSensors; ++i) {
            sensors.push_back(std::make_shared<DummySensor>(SENSOR_NAME_PREFIX + std::to_string(i)));
            sensors.back()->start();
        }

        for (auto& sensor : sensors) {
            mainPlatform.registerSensor(sensor);
        }

        mainPlatform.startSimulation();

        std::cout << "Simulation started. Press enter to stop..." << std::endl;
        std::cin.get();

        mainPlatform.stopSimulation();

        for (auto& sensor : sensors) {
            sensor->stop();
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
