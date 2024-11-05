#include <stdlib.h>
#include <stdio.h>

#include "student.h"

extern struct Student* get(FILE*, long long);
extern fpos_t* search(FILE*, unsigned int);
extern int showData(struct Student**, int);

int find(FILE* file, unsigned int match)
{
    fpos_t* save;
    fpos_t* pos;
    struct Student* s;

    fgetpos(file, save);
    pos = search(file, match);

    if (pos < 0) 
    {
        printf("Record can not be found.\n");
        fsetpos(file, save);
        return 0;
    }

    s = get(file, pos);
    showData(&s, 1);

    fsetpos(file, save);
    return 0;
}