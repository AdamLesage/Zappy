#!/bin/bash

# Install the coverage tool
pip3 install --user coverage

# Find the coverage tool
COVERAGE=$(python3 -m site --user-base)/bin/coverage

$COVERAGE erase

rm unit_tests*

cd src/ai/tests

# Define the test files
TEST_FILES=("main_tester.py")

# Execute tests and check coverage for each file
for file in "${TEST_FILES[@]}"
do
    python3 $file -v

    # Check the exit code
    if [ $? -eq 1 ]; then
        exit 1
    fi

    $COVERAGE run -m unittest "$file"
    REPORT=$($COVERAGE report -m)

    # Check if there is a failure
    FAILURES=$(echo "$REPORT" | grep "ERROR\|FAIL")
    echo "Failures: $FAILURES"
    if [ $FAILURES ]; then
        exit 1
    fi

    echo "$REPORT"

    # If coverage is inferior to 75%, exit with an error
    COVERAGE_PERCENTAGE=$(echo "$REPORT" | grep -oP "TOTAL.*" | grep -oP "\d+%" | grep -oP "\d+")

    # if [ $COVERAGE_PERCENTAGE -lt 75 ]; then
    #     echo "Coverage is below 75%: $COVERAGE_PERCENTAGE"
    #     exit 1
    # else
    #     echo "Coverage is above 75%: $COVERAGE_PERCENTAGE"
    # fi
done
