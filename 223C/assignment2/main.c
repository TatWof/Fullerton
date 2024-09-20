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
#include "stdlib.h"

extern char* file2string(char*);
void tokenize(char*, char*);

int main(int argc, char const *argv[])
{
    char filename[] = "test.txt";
    char* buffer;
    char* token;
    char** tokens;
    int delim = '.';
    int k = 0;
    int i = 0;
    int h = 0;
    int j = 0;

    printf("%s\n", filename);

    buffer = file2string(filename);
    for (j = 0; buffer[j] != 0 ; j++)
    {
        if (buffer[j] == delim)
        {
            token = (char*)malloc(j * sizeof(char));
            
            

            
            printf("%s\n", token);
            tokens[k] = token;
            k++;
        }
    }

    printf("the number of tokens is %d\n", k+1);
    for (i = 0; i < k; i++)
    {
        printf("#%d is %s\n", i, tokens[i]);
    }
    return 0;
}