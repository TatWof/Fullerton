#/bin/bash

chmod u=x r.sh

rm *.o
rm *.out

gcc -c -Wall -m64 -no-pie main.c -o main.o -std=c17

gcc -c -Wall -m64 -no-pie file2string.c -o file2string.o -std=c17

gcc -m64 -no-pie *.o -lm -o main.out -std=c17

echo "Program Start:"

chmod u+x *.out

rm *.o

chmod u+x main.out

./main.out