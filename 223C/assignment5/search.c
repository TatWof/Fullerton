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
int search(FILE* file, unsigned int match)
{
    fpos_t save;
    fpos_t record;
    int i;
    unsigned int temp; 

    fgetpos(file, save);

    fseek(file, 0, SEEK_SET);
    for (i = 0; fgetc(file) != EOF; i++)
    {
        fseek(file, -1, SEEK_CUR);
        
        fgetpos(file, record);
        fseek(file, 30, SEEK_CUR);
        temp = fread(&temp, sizeof(int), 1, file);
        if (temp == match)
        {
            fsetpos(file, save);
            return i;
        }
        fsetpos(file, record);
        
        fseek(file, 128, SEEK_CUR);
    }
    
    fsetpos(file, save);
    return -1;
}