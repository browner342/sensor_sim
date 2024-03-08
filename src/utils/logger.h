#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <mutex>
#include <string>

class Logger {
public:
    Logger(const std::string& fileName);
    ~Logger();

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    void log(const std::string& message);

private:
    std::ofstream outFile;
    std::mutex logMutex;
};

#endif // LOGGER_H
