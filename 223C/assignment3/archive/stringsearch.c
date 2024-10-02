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

    while (stringArr[i] != NULL) // if current address is not a null address, ie the end of the array
    {
        for (j = 0; stringArr[i][j] != 0 ; j++) // go char by char over the string
        {
            if(stringArr[i][j] == key[0])                         // if the char matches the begining char of the key then 
                keyMatch(pairs, stringArr, key, i, j, &count);    // see if the rest matches
        }
        ++i; // next string
    }
    pairs[count] = 0;   // terminating the pair pointer array
    printf("%d matches have been found\n", count);
    
    if (count > 0) return pairs;        // only return the pointer array if there are matches, else return null
    free(pairs); // deallocate mem
    return NULL;
}

/* Key Match
 * sees if the intial match also leads to a full match of the key
 *  
 * params:
 * - array of pair pointers
 * - string array
 * - the key
 * - row of the string array that caused inital match 
 * - column of the string array that caused inital match
 * - number of current pairs stored (pass by reference)
*/
void keyMatch(struct Pair** pairs, char** stringArr, char* key, int row, int col, int* pairNum)
{
    int i = 0;
    while (stringArr[row][col + i] == key[i]) { ++i; }      // char by char making sure it matches, if not this stops
    if(key[i] == 0)                                         // end of the key reached means that the key was found
    {
        pairs[*pairNum] = malloc(1 * sizeof(struct Pair));  // allocate the space
        pairs[*pairNum]->row = row;                         // putting in the location info
        pairs[*pairNum]->col = col;
        (*pairNum)++;                                       // updating the number of pairs given
    }
    
    return;
}