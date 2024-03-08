#include "logger.h"

Logger::Logger(const std::string& fileName) {
    outFile.open(fileName, std::ios::out | std::ios::app);
}

Logger::~Logger() {
    if (outFile.is_open()) {
        outFile.close();
    }
}

void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> guard(logMutex);
    std::cout << message << std::endl;
    if (outFile.is_open()) {
        outFile << message << std::endl;
    } else {
        std::cerr << "Unable to log message: " << message << std::endl;
    }
}
