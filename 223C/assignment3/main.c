/*  INFO
    Name: Billy Leong
    Email: bleong@csu.fullerton.edu
    Course ID: CPSC223C
    Due Date: 00/00/2024 - 23:59:00
    Program Name:
    Purpose:
    OS: Windows 11
*/

#include <stdio.h>
#include <stdlib.h>

#include "pair.h"

extern char** file2array(char*);
extern struct Pair** stringsearch(char**, char*);

int main(int argc, char const *argv[])
{
    char* filename = (char*)malloc(128 * sizeof(char));
    char* key = (char*)malloc(128 * sizeof(char));
    char** stringArr;
    struct Pair** pairs;
    char* buffer = malloc(2048 * sizeof(char));
    int j = 0;
    int i = 0;
    char charbuf;
    
    //Start up
    printf("Welcome to Sub String Searcher brought to you by Billy Leong\n");
    
    // ask for file to be opened
    printf("Please enter the name of the file you wish to search: ");
    scanf("%s", filename);
    scanf("%c", &charbuf);


    stringArr = file2array(filename);   // open and copy file contents
    if(stringArr == NULL)               // if file failed to open
    {
        // deallocate memory
        
        free(filename);
        free(key);
        free(buffer);
        return 0;
    }

    //print file contents
    printf("Here are the contents of the array:\n");
    i = 0;
    while (stringArr[i] != NULL)
    {
        printf("[%d] %s\n", i, stringArr[i]);
        ++i;
    };

    // get key from user
    printf("\n\nPlease enter the string you wish to search: ");
    scanf("%s", key);
    scanf("%c", &charbuf);
    printf("Confirming search key => %s\n", key);


    pairs = stringsearch(stringArr, key);       // search for matches
    if (pairs == NULL)                          // if stringsearch failed to get any matches
    {
        printf("Thank you for using this program.\n");

        //deallocate memory
        for (i = 0; stringArr[i] != 0; i++)
            free(stringArr[i]);
        free(stringArr);
        free(filename);
        free(key);
        free(buffer);
        return 0;
    }



    // print match pairs 
    printf("Showing positions of matches:\n");
    i = 0;
    while (pairs[i] != NULL)
    {
        printf("[match %2d] (%3d, %3d)\n", i, pairs[i]->row, pairs[i]->col);
        ++i;
    }

    //print continued strings
    printf("\nShowing continued strings at key\n");
    i = 0;
    while(pairs[i] != NULL)
    {
        
        for (j = 0; stringArr[pairs[i]->row][pairs[i]->col + j] != 0 ; j++)
        {
            buffer[j] = stringArr[pairs[i]->row][pairs[i]->col + j];
        }
        buffer[j] = 0;
        

        printf("Match %2d begins string %s\n", i, buffer);
        ++i;
    }

    // Goodbye
    printf("Thank you for using this program.\n");


    // deallocate memory
    for (i = 0; stringArr[i] != 0; i++)
        free(stringArr[i]);
    free(stringArr);

    for (i = 0; pairs[i] != 0; i++)
        free(pairs[i]);
    free(pairs);

    free(filename);
    free(key);
    free(buffer);
    return 0;
}
