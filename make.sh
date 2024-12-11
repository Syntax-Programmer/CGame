#!/bin/bash

# Create build directory
mkdir -p build

# Navigate to source directory
cd src || { echo "Source directory not found"; exit 1; }

# Compile the program
gcc -Wall -Wextra -O3 main.c core/game.c core/sdl_handler.c engine/physics.c engine/player.c -lSDL2 -o ../build/main || {
    echo "Compilation failed";
    exit 1;
}

# Return to the project root
cd ..

# Run the executable
./build/main || { echo "Execution failed"; exit 1; }