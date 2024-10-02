#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pair.h"

void keyMatch(struct Pair**, char**, char*, int, int, int*);

/* String Search
 * searchs for all instances of a given key in an array of strings
 * 
 * dependencies: a pair object to hold row and column information
 * params: string array (as double pointer), string to find matches of
 * returns: an array of pointers to pairs objects that hold the row and column of the instances of match, null terminated
 * if no matches were found, returns null
*/
struct Pair** stringsearch(char** stringArr, char* key)
{
    struct Pair** pairs = malloc(128 * sizeof(struct Pair*)); //allocate memory for the array of pair pointers
    int i = 0;
    int j = 0;
    int count = 0;
    char* match;

    while (stringArr[i] != NULL) // if current address is not a null address, ie the end of the array
    {
        match = strstr(stringArr[i] + j, key);  // returns address of the first match 
        if (match != NULL)                      // null means no matches were found
        {
            j = match - stringArr[i];                           // j = # of char relative to the beginning of the string
            pairs[count] = malloc(1 * sizeof(struct Pair));     // allocate memory for the pair
            pairs[count]->row = i;                              // put in the info
            pairs[count]->col = j;
            ++j;           // update so that the next string starts on the character after this match
            ++count;                                            // update number of matches found
        }
        else        // go to next line
        {
            ++i;
            j = 0;  // reset j to zero
        }
    }
    pairs[count] = 0;   // terminating the pair pointer array
    printf("%d matches have been found\n", count);
    
    if (count > 0) return pairs;        // only return the pointer array if there are matches, else return null
    free(pairs); // deallocate mem
    return NULL;
}