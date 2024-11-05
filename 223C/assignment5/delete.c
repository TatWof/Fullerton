#include <stdlib.h>
#include <stdio.h>

#include "student.h"

extern fpos_t* search(FILE*, unsigned int);

int delete(FILE* file, unsigned int match)
{
    fpos_t* save;
    fpos_t* pos;
    int temp = 0;

    fgetpos(file, save);

    pos = search(file, match);
    if (pos == 0) 
    {
        printf("Record can not be found.\n");
        fsetpos(file, save);
        return 0;
    }

    fsetpos(file, pos);
    fseek(file, 30, SEEK_CUR);
    fwrite(&temp, sizeof(int), 1, file);


    fsetpos(file, save);
    return 0;
}