/*  INFO
    Name: Billy Leong
    Email: bleong@csu.fullerton.edu
    Course ID: CPSC223C
    Due Date: 09/22/2024 - 23:59:00
    Program Name:
    Purpose:
    OS: Windows 11
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char* file2string(char* filename)
{
    FILE* file;
    int stringSize;
    char* string;
    int i;
    file = fopen(filename, "r");
    if(file == NULL) 
    {
        printf("File has failed to open or create please restart and try again.\n");
        printf( "Error opening file: %s\n", strerror( errno ) ); 
        return 0;
    }

    fseek(file, 0L , SEEK_END);
    stringSize = ftell(file) + 1;
    string = (char *)malloc(stringSize * sizeof(char));

    fseek(file, 0L , SEEK_SET);

    for (i = 0; i < stringSize - 1; i++)
    {
        string[i] = (char)fgetc(file);
    }
    string[i] = 0;

//    fgets(string, stringSize, file);

    fclose(file);

    return string;
}