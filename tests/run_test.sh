#!/bin/bash

cd src/ai/tests && python3 *.py -v && cd ../../../

if [ $? -eq 0 ]; then
    echo "Exit code is 0."
else
    echo "Exit code is not 0."
fi