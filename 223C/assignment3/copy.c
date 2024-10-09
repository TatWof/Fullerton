#include <stdio.h>
#include <stdlib.h>

/* Copy File to String Array
 * copies the content of a file to an array of char pointers
 * 
 * params:
 * array for the file to be copied into
 * maximum size of the array
 * 
 * returns: numbers of lines read
*/
int copy(char* filename, char** stringArr, int maxsize)
{
    FILE* file;
    char* buffer = malloc(2048 * sizeof(char));
    int charbuffer; 
    int count;
    int i;
    int k = 0;

    file = fopen(filename, "r");

    if(file == NULL) /* if file has failed to open return an null pointer */
    {
        printf("File has failed to open or create please restart and try again.\n");
        free(buffer);
        return NULL;
    }

    while (1)
    {
        charbuffer = fgetc(file);
        buffer[k] = charbuffer;
        ++k;
        if (charbuffer == '\n' || charbuffer == EOF)
        {
            stringArr[count] = malloc(k * sizeof(char));

            for (i = 0; i < k - 1; i++) stringArr[count][i] = buffer[i];
            stringArr[count][i] = 0;

            ++count;
            k = 0;

            if (charbuffer == EOF) break;
        }
    }
    stringArr[count] = 0;

    fclose(file);
    free(buffer);
    
    return count;
}