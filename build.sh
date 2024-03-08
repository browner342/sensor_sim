#!/bin/bash

# Exit script if any command fails
set -e

# Define the CLI11 GitHub repo URL
CLI11_REPO="https://github.com/CLIUtils/CLI11.git"
CLI11_DIR="external/CLI11"

# Check if the CLI11 directory already exists
if [ ! -d "${CLI11_DIR}" ]; then
    # Create the directory for CLI11 and clone the repository if it does not exist
    mkdir -p ${CLI11_DIR}
    git clone ${CLI11_REPO} ${CLI11_DIR} --single-branch --branch v2.1.2 --depth 1
else
    echo "CLI11 directory already exists, skipping clone..."
fi

# Create a build directory if it doesn't exist and move into it
mkdir -p build
cd build

# Run CMake to configure the project and then build it
cmake ..
make
