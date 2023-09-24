#!/bin/bash

# Create bin folder if it doesn't exist
mkdir -p bin

# Compile the C program with necessary libraries
gcc -o bin/getMachines src/main.c src/utils.c src/cJSON.c -lcurl

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run 
    bin/getMachines
else
    echo "Compilation failed."
fi