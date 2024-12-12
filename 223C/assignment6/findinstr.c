#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/* Find in String
 * Finds all instances in a given string and prints out their positions
 * 
 * Params: string to be searched, phrase to be searched in the string
*/
int findinstr(char* buffer, char* word)
{
    long long pos = 0;
    char* posP;
    int wordlen = strlen(word);
    int i = 0;

    if (wordlen == 0)
    {
        printf("invalid query, please try again.\n\n");
        return 1;
    }

    posP = strstr(buffer, word);
    while (1)
    {
        if (posP == NULL) break;

        i++;
        pos = posP - buffer;
        printf("[%d] %lld\n",i , pos);
        posP = strstr(posP + wordlen, word);
    }
    (i == 0) ? printf("no instances found\n\n") : printf("end of instances\n\n");
    
    return 0;
}