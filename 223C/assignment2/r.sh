#/bin/bash

chmod u=x r.sh

rm *.o
rm *.out

gcc -Wall -m64 -no-pie *.c -o main.out -std=c17

echo "Program Start:"

chmod u+x *.out

rm *.o

chmod u+x main.out

./main.out