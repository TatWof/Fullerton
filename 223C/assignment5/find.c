#include <stdlib.h>
#include <stdio.h>

#include "student.h"

extern struct Student* get(FILE*, fpos_t*);
extern int search(FILE*, unsigned int, fpos_t*);
extern int showData(struct Student**, int);

int find(FILE* file, unsigned int match)
{
    fpos_t save;
    fpos_t pos;
    struct Student* s;

    //fgetpos(file, &save);

    if(search(file, match, &pos))
    {
        printf("Record can not be found.\n");
        fsetpos(file, &save);
        return 0;
    }

    s = get(file, &pos);
    showData(&s, 1);

    //fsetpos(file, &save);
    return 0;
}