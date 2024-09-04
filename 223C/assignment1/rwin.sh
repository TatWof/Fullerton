#!/bin/bash

rm *.o
rm *.exe

gcc -c -Wall -m64 -no-pie -o main.o *.c -std=c17

gcc -m64 -no-pie -o main.exe *.o -std=c17

rm *.o