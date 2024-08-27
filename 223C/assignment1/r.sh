rm *.o
rm *.out

gcc -c -Wall -m64 -no-pie -o main.o *.c -std=c17

gcc -m64 -no-pie -o main.out *.o -std=c17

echo "Program Start:"

rm *.o

./main.out