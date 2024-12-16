/*
    name: Billy Leong
    email: bleong@csu.fullerton.edu
*/

#include <stdlib.h>
#include <stdio.h>

#include "student.h"


/* Search
 * searchs for a record in the binary file for a matching CWID
 *
 * params:
 * - file pointer
 * - CWID to match
 * - file position pointer (used to return position on a successful search)
 * 
 * returns:
 * - 0 on success
 * - 1 on fail
*/
int search(FILE* file, unsigned int match, fpos_t* fposP)
{
    fpos_t record;
    int i;
    int temp; 
    int buffer;

    fseek(file, 0, SEEK_SET);
    buffer = fgetc(file);
    for (i = 0; buffer != EOF; i++)
    {
        fseek(file, -1, SEEK_CUR);
        
        fgetpos(file, &record);

        fread(&temp, sizeof(int), 1, file);
        if (temp == match)
        {
            *fposP = record;
            return 0;
        }
        fsetpos(file, &record);
        
        fseek(file, 128, SEEK_CUR);
        buffer = fgetc(file);
    }
    
    return 1;
}