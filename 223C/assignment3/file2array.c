#include <stdio.h>
#include <stdlib.h>

char** file2array(char* filename)
{
    FILE* file;
    char** stringArr = malloc(100 * sizeof(char*));
    char* buffer = malloc(2048 * sizeof(char));
    int i = 0;
    int j;
    int k = 0;
    int count;
    int charbuffer;

    file = fopen(filename, "r");
    
    if(file == NULL) /* if file has failed to open return an null pointer */
    {
        printf("File has failed to open or create please restart and try again.\n");
        return NULL;
    }

    while (1)
    {
        charbuffer = fgetc(file);
        buffer[k] = (char)charbuffer;
        count++;
        k++;
        if (charbuffer == '\n' || charbuffer == EOF)
        {
            stringArr[i] = malloc((k) * sizeof(char));

            for (j = 0; j < k; j++) stringArr[i][j] = buffer[j];
            
            stringArr[i][k] = 0;

            i++;
            k = 0;
            if (charbuffer == EOF) break;
        }
    }
    stringArr[i] = 0;

    fclose(file);

    return stringArr;
}