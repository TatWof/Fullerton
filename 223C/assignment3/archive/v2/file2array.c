#include <stdio.h>
#include <stdlib.h>


/* File to Array
 * converts multiple lines in a file into an array of strings
 * array is terminated by a null address
 * 
 * params: filename
 * returns: array of strings as a char double pointer (pointer to an array of pointers), null terminated
 * if file is unable to be opened, returns null
*/
char** file2array(char* filename) // tested
{
    FILE* file;
    char** stringArr = malloc(128 * sizeof(char*)); // array of pointers, maximum 100. Consider convert to dynamically sized?
    char* buffer = malloc(2048 * sizeof(char));     // buffer to place the character into before assigning a more compact string
    int charbuffer;                                 // single character buffer, used for checks
    int i = 0;                                      // control variables
    int j = 0;
    int k = 0;
    int count = 0;                                  // total count of characters

    file = fopen(filename, "r");
    
    if(file == NULL) /* if file has failed to open return an null pointer */
    {
        printf("File has failed to open or create please restart and try again.\n");
        free(buffer);
        free(stringArr);
        return NULL;
    }

    while (1)
    {
        charbuffer = fgetc(file);       // read a character from the file
        buffer[k] = (char)charbuffer;   // put it into the buffer
        ++count;
        ++k;
        if (charbuffer == '\n' || charbuffer == EOF)    // if new line or end of file
        {
            stringArr[i] = malloc((k) * sizeof(char));  // assign memory for the string

            for (j = 0; j < k - 1; j++) stringArr[i][j] = buffer[j]; // move everything from the buffer into the new string
            
            stringArr[i][j] = 0; // null terminate the string

            ++i;                 // next place in the address 
            k = 0;               // reset character count and buffer pointer
            
            if (charbuffer == EOF) break;   // end of file reached
        }
    }
    stringArr[i] = 0;

    printf("This file contains %d bytes. It has been successfully copied into an array\n", count);

    fclose(file);
    free(buffer);

    return stringArr;
}