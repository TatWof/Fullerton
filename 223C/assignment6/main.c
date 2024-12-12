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

extern char* file2string(char*);
extern int findinstr(char*, char*);

int main(int argc, char const *argv[])
{
    char filename[2048];
    char searchword[2048];
    char* buffer;
    char cbuf;

    printf("Welcome to the Infile Instance Finder\n");

    printf("Please enter the filename to be searched: ");
    scanf("%s", filename);
    scanf("%c", &cbuf);

    buffer = file2string(filename);

    while(1)
    {
        printf("Please enter the phrase to be searched: ");
        scanf("%s", searchword);
        if (searchword[0] == 0) break;
        scanf("%c", &cbuf);

        

        findinstr(buffer, searchword);
    }

    printf("\nThank you for using the program.\nGoodbye.\n");

    free(buffer);
    return 0;
}