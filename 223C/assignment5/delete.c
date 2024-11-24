#include <stdlib.h>
#include <stdio.h>

#include "student.h"

extern int search(FILE*, unsigned int, fpos_t*);

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