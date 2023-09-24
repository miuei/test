#!/bin/bash

# Create bin folder if it doesn't exist
mkdir -p bin

# Compile the C program with necessary libraries
gcc -o bin/test test/test.c test/test_suite.c src/utils.c src/cJSON.c -lcunit -lcurl -I/usr/include/CUnit/

# Check if compilation was successful
if [ $? -eq 0 ]; then
    # Run 
    bin/test
else
    echo "Compilation failed."
fi