#!/bin/bash

# Find the coverage tool
COVERAGE=$(python3 -m site --user-base)/bin/coverage

$COVERAGE erase

# Execute tests
cd src/ai/tests
$COVERAGE run -m unittest test_AgentInfo.py -v
$COVERAGE run -m unittest test_Commands.py -v
$COVERAGE report -m
cd ../../../

# Check the exit code
if [ $? -eq 0 ]; then
    echo "Exit code is 0."
    exit 0
else
    echo "Exit code is not 0."
    exit 1
fi
