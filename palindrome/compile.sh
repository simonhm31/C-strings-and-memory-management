#!/bin/bash


gcc -Wall -g -o palindrome palindrome.c main.c


if [ $? -eq 0 ]; then
    echo "Compile successful."
else
    echo "Compile failed."
    exit 1
fi