#!/bin/bash
g++ -Wall -g -o palindrome *.cpp
if [ $? -eq 0 ]; then
    echo "Compile successful."
else
    echo "Compilefailed."
    exit 1
fi
