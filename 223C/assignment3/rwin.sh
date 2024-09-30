#!/bin/bash

rm *.o
rm *.exe

gcc -c -Wall -m64 -no-pie -o main.o main.c -std=c17
gcc -c -Wall -m64 -no-pie -o file2string.o file2string.c -std=c17
gcc -c -Wall -m64 -no-pie -o stringsearch.o stringsearch.c -std=c17

gcc -m64 -no-pie -o main.exe *.o -std=c17

rm *.o