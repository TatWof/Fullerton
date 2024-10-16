#include <stdio.h>
#include <stdlib.h>

/* Copy File to String Array
 * copies the content of a file to an array of char pointers
 * 
 * params:
 * - name of the file being taken in
 * - array for the file to be copied into
 * - maximum size of the array
 * 
 * returns: 
 * - numbers of lines read
*/
int copy(char* filename, char** stringArr, int maxsize)
{
    FILE* file;
    char* buffer = malloc(2048 * sizeof(char)); // allocates a temporary buffer to store characters read from the file in 
    int charbuffer; // to grab a single character 
    int count = 0;  // counts number of lines read
    int i, k;       // counter control

    file = fopen(filename, "r");

    if(file == NULL) /* if file has failed to open return an null pointer */
    {
        printf("File has failed to open or create please restart and try again.\n");
        free(buffer);
        return 0;
    }

    k = 0;
    while (1)
    {
        if(count > maxsize) break; /* if ran out of space in the string array then exit the loop*/

        charbuffer = fgetc(file);   // get a single character from file
        buffer[k] = charbuffer;     // put it into the buffer
        ++k;                        // k points to the next available position in the buffer
                                    // also counts the number of characters read since the last line

        if (charbuffer == '\n' || charbuffer == EOF)        // if recent character read was newline or end of file then copy the line into 
        {                                                   // the array
            stringArr[count] = malloc(k * sizeof(char));    // allocate space for the copied line

            for (i = 0; i < k - 1; i++) stringArr[count][i] = buffer[i]; // copy it into the new space
            stringArr[count][i] = 0; // null terminate

            ++count;    // update the number of lines read
            k = 0;      // reset the buffer to "empty"

            if (charbuffer == EOF) break; // if end of file then exit the loop
        }
    }

    fclose(file);
    free(buffer);
    
    return count;
}