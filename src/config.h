#ifndef CONFIG_H
#define CONFIG_H

#include <string>

// Consts for platform
constexpr int BUFFER_SIZE = 20;
constexpr int NUMBER_OF_SENSORS = 5;
constexpr int LOG_INTERVAL = 1;

// Consts for logging
const std::string SENSOR_NAME_PREFIX = "Sensor";
const std::string LOG_FILE_NAME = "sensor_log.txt";

#endif // CONFIG_H
