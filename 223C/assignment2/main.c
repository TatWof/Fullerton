/*  INFO
    Name: Billy Leong
    Email: bleong@csu.fullerton.edu
    Course ID: CPSC223C
    Due Date: 00/00/2024 - 23:59:00
    Program Name:
    Purpose:
    OS: Windows 11
*/

#include "stdio.h"
#include "string.h"

extern file2string(char*, int, FILE*);
void tokenize(char*);

int main(int argc, char const *argv[])
{
    FILE* filename;
    int stringSize;

    fseek(filename, 0 ,SEEK_END);
    stringSize = ftell(filename);
    
    char string[stringSize];

    file2string(string, stringSize, filename);




    return 0;
}

