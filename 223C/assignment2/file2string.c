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

/*
 * opens a file and copys the contents into a string to return
 * 
 * params: name of the file
 * returns: pointer to string that has the copied contents, if unable to copy returns a nullpointer
*/
char* file2string(char* filename)
{
    FILE* file;
    int stringSize;
    char* string;
    int i;

    // opening the file
    file = fopen(filename, "r");
    if(file == NULL) /* if file has failed to open return an empty char pointer */
    {
        printf("File has failed to open or create please restart and try again.\n");
        return NULL;
    }

    // go to end of file, find out size of file
    fseek(file, 0L , SEEK_END);
    stringSize = ftell(file) + 1; /* extra size for ending null */
    printf("There are %d characters in the file.\n", stringSize);
    string = (char *)malloc(stringSize * sizeof(char)); /* allocate the memory for the string */

    //go to start of file, copy contents one at a time
    fseek(file, 0L , SEEK_SET);

    for (i = 0; i < stringSize - 1; i++)
    {
        string[i] = (char)fgetc(file);
    }
    string[i] = 0; /* null terminator */

    //close the file
    fclose(file);

    return string; /* return the string with contents*/
}