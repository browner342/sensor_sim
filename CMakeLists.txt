# Minimum CMake version and project name
cmake_minimum_required(VERSION 3.10)
project(SensorNetworkSimulation)

# Set C++ standard requirements
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define source files and headers for each component of the project
# This makes it clear what the components are and where to add new files

set(PLATFORM_SOURCES
    src/platform/platform.cpp
)

set(PLATFORM_HEADERS
    src/platform/platform.h
    src/platform/circular_buffer.h
)

set(SENSOR_SOURCES
    src/sensor/sensor.cpp
    src/sensor/dummy_sensor.cpp
)

set(SENSOR_HEADERS
    src/sensor/sensor.h
    src/sensor/dummy_sensor.h
)

set(UTILS_SOURCES
    src/utils/logger.cpp
)

set(UTILS_HEADERS
    src/utils/logger.h
)

# Aggregate all sources and headers for easier management
set(ALL_SOURCES
    ${PLATFORM_SOURCES}
    ${SENSOR_SOURCES}
    ${UTILS_SOURCES}
    src/main.cpp  # Main program entry point
)

set(ALL_HEADERS
    ${PLATFORM_HEADERS}
    ${SENSOR_HEADERS}
    ${UTILS_HEADERS}
)

# Include directories
# Use one line per include directory for better readability
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/external/CLI11/include
)

# Add the CLI11 library
add_subdirectory(external/CLI11)

# Create the executable
add_executable(SensorSim ${ALL_SOURCES} ${ALL_HEADERS})

# Link the executable with the CLI11 library
target_link_libraries(SensorSim CLI11)

# Optionally, set the output directory for the executable
# This line is commented out by default; uncomment if needed
# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
