/*
    name: Billy Leong
    email: bleong@csu.fullerton.edu
*/

#include <stdlib.h>
#include <stdio.h>

#include "student.h"

extern int search(FILE*, unsigned int, fpos_t*);

/* Delete
 * command for deleting a record on file.
 *
 * params: 
 * file pointer
 * CWID to match
*/
int delete(FILE* file, unsigned int match)
{
    fpos_t pos;
    int temp = 0;

    if (search(file, match, &pos))
    {
        printf("Record can not be found.\n");
        return 0;
    }

    fsetpos(file, &pos);
    fwrite(&temp, sizeof(int), 1, file);

    return 0;
}