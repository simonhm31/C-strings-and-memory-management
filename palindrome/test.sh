#!/bin/bash
g++ -Wall -g -o palindrome_test palindrome.c palindrome_test.cpp -lgtest -pthread -std=c++0x
if [ $? -eq 0 ]; then
    echo "Test compile passed."
else
    echo "Test compile failed."
    exit 1
fi
