#/bin/bash

chmod u=x r.sh

rm *.o
rm *.out

gcc -c -Wall -m64 -no-pie *.c -o main.o -std=c17

gcc -m64 -no-pie *.o -lm -o main.out -std=c17

chmod u+x *.out

rm *.o

chmod u+x main.out

echo "Program Start:"
./main.out