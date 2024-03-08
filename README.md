# Sensor Network Simulation

This project simulates a network of sensors. It utilizes the CLI11 library to parse command-line arguments, demonstrating dynamic interaction with sensor objects through a command-line interface.

## Getting Started

These instructions will guide you on how to get your project running on your local machine for development and testing purposes.

### Prerequisites

Before running the Sensor Network Simulation, make sure you have the following installed:

- CMake (minimum version 3.10)
- A C++ compiler supporting C++17 (e.g., GCC, Clang, MSVC)
- Git (for cloning necessary libraries)

## Installation and Running the Simulation

### Make the build script executable and run it:

On Linux or macOS:

```bash
chmod +x build.sh
./build.sh
```

## Running the Simulation
After building the project, run the simulation using the following command from the project root directory:

```bash
./build/SensorSim
```

You can customize the simulation using the following command-line options:

    -n, --num <NUM>: Specify the number of sensors in the simulation.
    -i, --interval <SECONDS>: Set the logging interval in seconds.
    -f, --file <FILENAME>: Define the filename for log output.
    -b, --buff_size <SIZE>: Set the size of the logging buffer.

For example, to start a simulation with 10 sensors, logging every 2 seconds, and saving logs to output.log with a buffer size of 100, use:

bash
Copy code
./build/SensorSim --num 10 --interval 2 --file output.log --buff_size 100
