/*  INFO
    Name: Billy Leong
    Email: bleong@csu.fullerton.edu
    Course ID: CPSC223C
    Due Date: 10/13/2024 - 23:59:00
    Program Name:
    Purpose:
    OS: Windows 11
*/

#include <stdlib.h>
#include <stdio.h>

extern int copy(char*, char**, int);
extern int show(char**, int);
extern int sort(char**, int);

int main(int argc, char const *argv[])
{
    FILE* file;
    char* filename = "test.txt";
    char* lines[2048];
    int count;


    count = copy(filename, lines, 2048);

    show(lines, count);
    sort(lines, count);
    show(lines, count);
    
    return 0;
}
