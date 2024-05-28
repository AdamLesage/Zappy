#!/bin/bash

# Find the coverage tool
COVERAGE=$(python3 -m site --user-base)/bin/coverage

$COVERAGE erase

# Execute tests
cd src/ai/tests
$COVERAGE run -m unittest test_AgentInfo.py -v
$COVERAGE run -m unittest test_Commands.py -v
REPORT=$($COVERAGE report -m)
echo "$REPORT"
cd ../../../

# Check the exit code
if [ $? -eq 1 ]; then
    exit 1
fi

# If coverage is inferior to 75%, exit with an error
COVERAGE_PERCENTAGE=$(echo "$REPORT" | grep -oP "TOTAL.*" | grep -oP "\d+%" | grep -oP "\d+")

# echo "$COVERAGE_PERCENTAGE"

if [ $COVERAGE_PERCENTAGE -lt 75 ]; then
    echo "Coverage is below 75%: $COVERAGE_PERCENTAGE"
    exit 1
fi
