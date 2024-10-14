#include <stdlib.h>
#include <stdio.h>


/* Copy One Dimensional
 * copies contents from file into a one dimensional array
 * if the file exceeds the size of the string, it will automatically
 * 
 * Params: filename
 * 
 * Returns: string (null terminated); null pointer if failed to open the file
*/
char* copy_1d(char* filename)
{
    FILE* file = fopen(filename, "r");
    char* string;
    int stringSize;
    int i;

    if (file == NULL)
    {
        printf("File does not exist or failed to open, please restart the program.\n");
        return NULL;
    }

    // go to end of file, find out size of file
    fseek(file, 0L , SEEK_END);
    stringSize = ftell(file) + 1; // extra size for ending null
    string = (char *)malloc(stringSize * sizeof(char)); // allocate the memory for the string

    // reset file pointer position
    fseek(file, 0L , SEEK_SET);

    // copy contents
    for (i = 0; i < stringSize - 1; i++)
    {
        string[i] = (char)fgetc(file);
    }
    string[i] = 0; // null terminator

    return string;
}