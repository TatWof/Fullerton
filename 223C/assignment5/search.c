#include <stdlib.h>
#include <stdio.h>

#include "student.h"


/* Search
 * searchs for a record in the binary file for a matching CWID
 *
 * params:
 * - file pointer
 * - CWID to match
 * 
 * returns:
 * - record position (-1 if not found)
*/
int search(FILE* file, unsigned int match, fpos_t* posP)
{
    fpos_t save;
    fpos_t record;
    int i;
    int temp; 
    int buffer;

    fgetpos(file, &save);
    fseek(file, 0, SEEK_SET);
    buffer = fgetc(file);
    for (i = 0; buffer != EOF; i++)
    {
        fseek(file, -1, SEEK_CUR);
        
        fgetpos(file, &record);
        fseek(file, 30, SEEK_CUR);
        temp = fread(&temp, sizeof(int), 1, file);
        if (temp == match)
        {
            *posP = record;
            fsetpos(file, &save);
            return 0;
        }
        fsetpos(file, &record);
        
        fseek(file, 128, SEEK_CUR);
    }
    
    fsetpos(file, &save);
    return 1;
}