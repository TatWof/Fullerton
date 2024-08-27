#/bin/bash

#Program: Simple Time
#Author: F. Holliday
#This bash file is part of the program "Simple Time".
#The program will run in standard mode.

#Delete some un-needed files
rm *.o
rm *.out

echo "Compile current-time.c"
gcc -c -Wall -m64 -no-pie -o current-time.o current-time.c -std=c2x

echo "Link the object files"
gcc -m64 -no-pie -o current.out current-time.o -std=c2x      

#Make sure the executable has permission to execute
chmod u+x current.out

echo "Run the program Simple Time:"
./current.out

echo "The script file will terminate"

