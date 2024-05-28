#!/bin/bash

cd src/ai/tests; python3 test_AgentInfo.py -v; cd ../../../
cd src/ai/tests; python3 test_Commands.py -v; cd ../../../

if [ $? -eq 0 ]; then
    echo "Exit code is 0."
    exit 0
else
    echo "Exit code is not 0."
    exit 1
fi
