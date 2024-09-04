#/bin/bash

rm *.o
rm *.exe

gcc -c -Wall -m64 -no-pie -o current-time.o current-time.c -std=c17

gcc -m64 -no-pie -o current.exe current-time.o -std=c17

./current.exe

