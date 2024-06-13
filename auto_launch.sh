#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 4 ]; then
    echo "Usage: $0 <number_of_times> <machine> <port> <teamName>"
    exit 84
fi

# Check if the first argument is a positive integer
if ! [[ "$1" =~ ^[0-9]+$ ]]; then
    echo "Error: The first argument must be a positive integer."
    exit 84
fi

# Assign the arguments to variables
nTime=$1
machine=$2
port=$3
teamName=$4

# Loop to execute the zappy_ai program
for ((i=1; i<=nTime; i++))
do
    echo "Execution $i:"
    ./zappy_ai -p $port -n $teamName -h $machine &
    echo "-------------------"
done

echo "Completed $nTime executions."
