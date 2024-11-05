/*  INFO
    Name: Billy Leong
    Email: bleong@csu.fullerton.edu
    Course ID: CPSC223C
    Due Date: 00/00/2024 - 23:59:00
    Program Name:
    Purpose:
    OS: Windows 11
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char* filename = "academic.bin";
    FILE* file = fopen(filename, "rwb");

    

    
    fclose(file);
    return 0;
}
