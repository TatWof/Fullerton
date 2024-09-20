#!/bin/bash

rm *.o
rm *.exe

gcc -c -Wall -m64 -no-pie main.c -o main.o -std=c17

gcc -c -Wall -m64 -no-pie file2string.c -o file2string.o -std=c17

gcc -m64 -no-pie -o main.exe *.o -std=c17

rm *.o